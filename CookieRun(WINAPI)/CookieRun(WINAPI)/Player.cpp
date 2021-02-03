#include "Player.h"
#include "InputManager.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"

#include "Bitmap.h"
#include "BitmapManager.h"
#include "SoundManager.h"
Player::Player()
{
}

Player::~Player()
{
	Release();
}

void Player::Initialize(void)
{
	m_ptMouse = { 0,0 };
	m_tTransPos.Position = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	m_tTransPos.Rotation = Vector2(0.f, 0.f);
	m_tTransPos.Scale = Vector2(100, 300);

	//m_tFrame = Frame(0, 0, 7, 0, 150);

	m_TargetPoint = Vector2(0.f, 0.f);
	m_Direction = Vector2(0.f, 0.f);

	m_fTime = 0.f;
	m_fAngle = 0.f;
	m_fSpeed = 3.f;
	m_strKey = "Player";
	m_bMove = false;
	m_bJump = false;

	m_dwFrameTime = GetTickCount64();

}

void Player::Progress(void)
{
	CheckKey();

	m_LinePoint.fX = m_tTransPos.Position.fX + cosf(m_fAngle * PI / 180) * 100;
	m_LinePoint.fY = m_tTransPos.Position.fY + -sinf(m_fAngle * PI / 180) * 100;

	if (m_bJump)
	{
		m_fTime += 0.1f;
		m_tTransPos.Position.fY += -sinf(90 * PI / 180) * 5 + (0.98f * m_fTime * m_fTime) / 2;
	
		if (m_fOldY < m_tTransPos.Position.fY)
		{
			m_fTime = 0.0f;
			m_tTransPos.Position.fY = m_fOldY;
			m_bJump = false;
		}
	}

	//** 출력 프레임을 제어할 시간에 프레임과 프레임 간격의 시간을 더한값보다 현재 시가니 더 크다면
	if (m_dwFrameTime + m_tFrame.FrameTime < GetTickCount64())
	{
		m_dwFrameTime = GetTickCount64();


		//** 현재 프레임 카운트가 마지막 이미지 프레임보다 큰지 확인한다.
		if (m_tFrame.Count > m_tFrame.LastFrame)
		{
			//** 크다면 다시 초기 이미지 값으로 되돌려 출력하게 한다.
			m_tFrame.Count = m_tFrame.StartFrame;
		}
		else
			m_tFrame.Count++;	//** 별일 없다면다음 이미지를 출력하게 한다.
	}


}

void Player::Render(HDC _hdc)
{
	TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
		(int)m_tTransPos.Position.fX,	// 복사할 영역 시작점 X
		(int)m_tTransPos.Position.fY, 	// 복사할 영역 시작점 Y
		(int)m_tTransPos.Scale.fX,	// 복사할 영역 끝부분 X
		(int)m_tTransPos.Scale.fY, 	// 복사할 영역 끝부분 Y
		(*m_ImageList)[m_strKey]->GetMemDC(),	// 복사할 이미지 (복사대상)
		int(m_tFrame.Count * m_tTransPos.Scale.fX),  // 복사할 시작점 X
		int(m_tFrame.Scene * m_tTransPos.Scale.fY),	// 복사할 시작점 Y
		(int)m_tTransPos.Scale.fX, 			// 출력할 이미지의 크기 만큼 X
		(int)m_tTransPos.Scale.fY,			// 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));
}

void Player::Release(void)
{
}

void Player::CheckKey()
{
}
