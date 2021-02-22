#include "Player.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Bitmap.h"
#include "BitmapManager.h"
//#include "SoundManager.h"


Player::Player()
{

}

Player::~Player()
{
	Release();
}


void Player::Initialize(void)
{//381
	m_ptMouse = { 0, 0 };
	m_tTransPos.Position = Vector2(0.f,245.f);
	m_tTransPos.Rotation = Vector2(0.f, 0.f);
	m_tTransPos.Scale = Vector2(6496.f/17.f,2294.f/6.f);
	//3520*1920
	//1140*570
	m_iDefaultStartFrame = 0;
	m_iDefaultCount = 0;
	m_iDefaultScene = 1;
	m_iDefaultLastFrame = 5;

	m_tFrame = Frame(m_iDefaultStartFrame, m_iDefaultCount, m_iDefaultLastFrame, m_iDefaultScene, 50);


	m_TargetPoint = Vector2(0.f, 0.f);
	m_Direction = Vector2(0.f, 0.f);

	m_fTime = 0.f;
	m_fDTime = 0.f;
	m_fAngle = 0.f;
	m_fSpeed = 5.f;
	m_strKey = "Player";
	m_bMove = false;
	m_bJump = false;
	m_bDJump = false;
	m_bSlide = false;
	//RecPlayer = { 0,300,150,586 };
	
	//** 출력 프레임을 제어할 시간.
	m_dwFrameTime = GetTickCount64();
}

int Player::Progress(void)
{
	CheckKey();

	/*m_LinePoint.fX = m_tTransPos.Position.fX + cosf(m_fAngle * PI / 180) * 100;
	m_LinePoint.fY = m_tTransPos.Position.fY + -sinf(m_fAngle * PI / 180) * 100;*/
	
	//점프 컨트롤
	if (m_bJump)
	{
		m_fTime += 0.1f;
		
		if (m_bDJump)
		{
			m_fDTime += 0.1f;
			m_tTransPos.Position.fY += -sinf(90 * PI / 180) * 5 + (0.98f * m_fDTime * m_fDTime) / 2.f;
		
			RecPlayer.top += -sinf(90 * PI / 180) * 5 + (0.98f * m_fDTime * m_fDTime) / 2.f;
			RecPlayer.bottom += -sinf(90 * PI / 180) * 5 + (0.98f * m_fDTime * m_fDTime) / 2.f;
			if (m_fDOldY < m_tTransPos.Position.fY)
			{
				m_fDTime = 0.0f;
				m_tTransPos.Position.fY = m_fDOldY;

				m_bDJump = false;
			}
		}

		m_tTransPos.Position.fY += -sinf(90 * PI / 180) * 7 + (0.98f * m_fTime * m_fTime) / 2;

		if (m_fOldY < m_tTransPos.Position.fY)
		{
			m_fTime = 0.0f;
			m_tTransPos.Position.fY = m_fOldY;
			
			m_bJump = false;
		}
	}

	if (m_bSlide)
	{
		m_tFrame.StartFrame = 14;
		m_tFrame.LastFrame = 17;
		m_tFrame.Scene = 0;


	}


	//** 출력 프레임을 제어할 시간에 프레임과 프레임 간격의 시간을 더한값보다 현재 시가니 더 크다면
	if (m_dwFrameTime + m_tFrame.FrameTime < GetTickCount64())
	{
		m_dwFrameTime = GetTickCount64();

		//** 현재 프레임 카운트가 마지막 이미지 프레임보다 큰지 확인한다.
		if (m_tFrame.Count >= m_tFrame.LastFrame)
		{
			//** 크다면 다시 초기 이미지 값으로 되돌려 출력하게 한다.
			m_tFrame.Count = m_tFrame.StartFrame;
		}
		else
			m_tFrame.Count++;	//** 별일 없다면다음 이미지를 출력하게 한다.
	}

	return 0;
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
		RGB(255, 0, 255));		// 해당 색상을 제외
	
	//Rectangle(_hdc, RecPlayer.left, RecPlayer.top, RecPlayer.right, RecPlayer.bottom);
}

void Player::Release(void)
{
	
}


void Player::CheckKey()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (KEY_SPACE & dwKey)
	{
		/*if (m_fTime + 150 < GetTickCount64())
		{
			if (m_bJump && (m_bDJump == false))
			{
				m_bDJump = true;
				m_fDTime = 0.f;
			}
		}*/

		if (!m_bJump)
		{
			m_bJump = true;
			m_fOldY = m_tTransPos.Position.fY;
			
			if (0x0020)
			{
				if (!m_bDJump)
				{
					m_bDJump = true;
					m_fDOldY = m_tTransPos.Position.fY;
				}

			}
		}
	}

	if (KEY_DOWN & dwKey)
	{
		if (!m_bSlide)
		{
			m_bSlide = true;
		}
	}
}
