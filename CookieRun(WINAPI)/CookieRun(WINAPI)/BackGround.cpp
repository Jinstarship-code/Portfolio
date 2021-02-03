#include "BackGround.h"

BackGround::BackGround()
{
}

BackGround::~BackGround()
{
}

void BackGround::Initialize(void)
{
	m_tTransPos.Position = Vector2(0, 0);
	m_tTransPos.Rotation = Vector2(0.f, 0.f);
	m_tTransPos.Scale = Vector2(WINSIZEX, WINSIZEY);

	m_fAngle = 0.5;
	m_fSpeed = 5.f;

	m_strKey = "BackGround_1";
	m_strKey.push_back(48 + (rand() % 4 + 1));
}

void BackGround::Progress(void)
{
}

void BackGround::Render(HDC _hdc)
{

	//** Menu ��׶��� �̹����� ���ۿ� �����.
	TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
		0,	// ������ ���� ������ X
		0, 	// ������ ���� ������ Y
		WINSIZEX,	// ������ ���� ���κ� X
		WINSIZEY, 	// ������ ���� ���κ� Y
		(*m_ImageList)[m_strKey]->GetMemDC(),	// ������ �̹��� (������)
		(int)m_tTransPos.Position.fX,		// ������ ������ X
		(int)m_tTransPos.Position.fY,		// ������ ������ Y
		(int)m_tTransPos.Scale.fX, 		// ����� �̹����� ũ�� ��ŭ X
		(int)m_tTransPos.Scale.fY,		// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));		// �ش� ������
}

void BackGround::Release(void)
{
}