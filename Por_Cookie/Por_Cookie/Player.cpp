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
{
	m_ptMouse = { 0, 0 };
	m_tTransPos.Position = Vector2(0.f,300.f);
	m_tTransPos.Rotation = Vector2(0.f, 0.f);
	m_tTransPos.Scale = Vector2(234.f,463.f);


	m_tFrame = Frame(0, 0, 7, 0, 150);

	/*
	Frame(int _StartFrame, ����� ������ �̹��� ������.
	int _Count,				���������� ���������� ���������� ��������� �̵�������
	int _LastFrame,			����� �̹����� ������ ����
	int _SceneFrame,		����, �̵�, ���� ���� ����� ���� ��Ŵ
	DWORD _FrameTime)

	DWORD _FrameTime = 	��鸶�� ����ؾ��� �̹��� ������ �ٸ���.
		������ ����Ͽ� ��µǱ� ������
		�ִϸ��̼��� ������ ������ �����ֱ� ����.

		������ ������ �̹����� 5���̰�
		�÷��̾��� ���� �̹����� 10 ���̶� �Ѵٸ�
		�츮�� ����ϴ� �̹����� �� �����Ӹ��� 1���� �̹����� ��µǱ� ������
		���Ͱ� 2���� ������ �Ҷ� �÷��̾�� �ѹ��� ������ �ϰԵȴ�.

		�̷� ������ �ذ��ϱ����� �̹��� ��ü�� ��µǴ� �ð��� ���س��� ����ؾ� �Ѵ�. (�ʴ� ���ݷ����� ȯ��ȴ�.)
	*/



	m_TargetPoint = Vector2(0.f, 0.f);
	m_Direction = Vector2(0.f, 0.f);

	m_fTime = 0.f;
	m_fAngle = 0.f;
	m_fSpeed = 3.f;
	m_strKey = "Player";
	m_bMove = false;
	m_bJump = false;


	//** ��� �������� ������ �ð�.
	m_dwFrameTime = GetTickCount64();
}

int Player::Progress(void)
{
	CheckKey();

	m_LinePoint.fX = m_tTransPos.Position.fX + cosf(m_fAngle * PI / 180) * 100;
	m_LinePoint.fY = m_tTransPos.Position.fY + -sinf(m_fAngle * PI / 180) * 100;

	if (m_bJump)
	{
		m_fTime += 0.1f;
		m_tTransPos.Position.fY += -sinf(90 * PI / 180) * 5 + (0.98f * m_fTime * m_fTime) / 2;
		m_tTransPos.Scale.fY += -sinf(90 * PI / 180) * 5 + (0.98f * m_fTime * m_fTime) / 2;

		if (m_fOldY < m_tTransPos.Position.fY)
		{
			m_fTime = 0.0f;
			m_tTransPos.Position.fY = m_fOldY;
			
			m_bJump = false;
		}
	}

	//** ��� �������� ������ �ð��� �����Ӱ� ������ ������ �ð��� ���Ѱ����� ���� �ð��� �� ũ�ٸ�
	if (m_dwFrameTime + m_tFrame.FrameTime < GetTickCount64())
	{
		m_dwFrameTime = GetTickCount64();

		//** ���� ������ ī��Ʈ�� ������ �̹��� �����Ӻ��� ū�� Ȯ���Ѵ�.
		if (m_tFrame.Count > m_tFrame.LastFrame)
		{
			//** ũ�ٸ� �ٽ� �ʱ� �̹��� ������ �ǵ��� ����ϰ� �Ѵ�.
			m_tFrame.Count = m_tFrame.StartFrame;
		}
		else
			m_tFrame.Count++;	//** ���� ���ٸ���� �̹����� ����ϰ� �Ѵ�.
	}



	//** ���콺 Ŭ���� ���� �̵�.
	/*
	if (m_bMove)
	{
		//** ������ ���̸� ����.
		float fLength = sqrt((m_Direction.fX * m_Direction.fX) + (m_Direction.fY * m_Direction.fY));

		//** ���� ���̺��� �׻� ū���� ������ ������ ������ ����ȭ ������.
		m_Direction.fX /= fLength;
		m_Direction.fY /= fLength;

		//** ����ȭ�� ���� Speed�� ���Ͽ� ���� �÷��̾��� ��ǥ�� ������.
		m_tTransPos.Position.fX += m_Direction.fX * m_fSpeed;
		m_tTransPos.Position.fY += m_Direction.fY * m_fSpeed;

		//** �����̰��ִ� �÷��̾� ���߱�.
		if (m_TargetPoint.fX + (m_fSpeed / 2.f) > m_tTransPos.Position.fX - (m_fSpeed / 2.f) &&
			 m_TargetPoint.fX - (m_fSpeed / 2.f) < m_tTransPos.Position.fX + (m_fSpeed / 2.f) &&
			 m_TargetPoint.fY + (m_fSpeed / 2.f) > m_tTransPos.Position.fY - (m_fSpeed / 2.f) &&
			 m_TargetPoint.fY - (m_fSpeed / 2.f) < m_tTransPos.Position.fY + (m_fSpeed / 2.f))
		{
			m_bMove = false;
		}
	}
	*/

	return 0;
}

void Player::Render(HDC _hdc)
{
	//TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
	//	(int)m_tTransPos.Position.fX,	// ������ ���� ������ X
	//	(int)m_tTransPos.Position.fY, 	// ������ ���� ������ Y
	//	(int)m_tTransPos.Scale.fX,	// ������ ���� ���κ� X
	//	(int)m_tTransPos.Scale.fY, 	// ������ ���� ���κ� Y
	//	(*m_ImageList)[m_strKey]->GetMemDC(),	// ������ �̹��� (������)
	//	int(m_tFrame.Count * m_tTransPos.Scale.fX),  // ������ ������ X
	//	int(m_tFrame.Scene * m_tTransPos.Scale.fY),	// ������ ������ Y
	//	(int)m_tTransPos.Scale.fX, 			// ����� �̹����� ũ�� ��ŭ X
	//	(int)m_tTransPos.Scale.fY,			// ����� �̹����� ũ�� ��ŭ Y
	//	RGB(255, 0, 255));		// �ش� ������ ����

	Rectangle(_hdc, m_tTransPos.Position.fX, m_tTransPos.Position.fY,
		m_tTransPos.Scale.fX, m_tTransPos.Scale.fY);
}

void Player::Release(void)
{

}


void Player::CheckKey()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (KEY_SPACE & dwKey)
	{
		if (!m_bJump)
		{
			m_bJump = true;
			m_fOldY = m_tTransPos.Position.fY;
		}

		
		/*m_tTransPos.Position.fX +=cosf(m_fAngle *  PI / 180) * m_fSpeed;
		m_tTransPos.Position.fY +=-sinf(m_fAngle *  PI / 180) * m_fSpeed;*/
		
	}


}

//
//template <typename T>
//Object* Player::CreateBullet()
//{
//	Bridge* Bridge = new T;
//
//	((Bullet_Bridge*)Bridge)->SetAngle(m_fAngle);
//
//	Object* pBullet = ObjectFactroy<Bullet>::CreateObject(m_LinePoint.fX, m_LinePoint.fY, Bridge);
//
//	return pBullet;
//}