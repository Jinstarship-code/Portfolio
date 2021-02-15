#include "Jelly.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "Player.h"
#include "CollisionManager.h"

Jelly::Jelly()
{
}

Jelly::~Jelly()
{
}

void Jelly::Initialize(void)
{
    m_tTransPos.Position = Vector2(500.f,400.f);
    m_tTransPos.Rotation = Vector2(0.f, 0.f);
    m_tTransPos.Scale = Vector2(53.f, 50.f);
	m_fSpeed = 0.f;
    m_strKey = "Jelly";

	rc = { (LONG)m_tTransPos.Position.fX,
		(LONG)m_tTransPos.Position.fY,
		(LONG)(m_tTransPos.Position.fX+m_tTransPos.Scale.fX),
		(LONG)(m_tTransPos.Position.fY+m_tTransPos.Scale.fY) };
	
}

int Jelly::Progress(void)
{
	m_fSpeed = 3.f;

	//m_tTransPos.Position.fX -= m_fSpeed;

	rc.left -= m_fSpeed;
	rc.right -= m_fSpeed;
    return 0;
}

void Jelly::Render(HDC _hdc)
{
	
	////** Menu ��׶��� �̹����� ���ۿ� �����.
	//TransparentBlt(_hdc,					// ������ ���� �׸��� ?!
	//	m_tTransPos.Position.fX,			// ������ ���� ������ X
	//	m_tTransPos.Position.fY, 			// ������ ���� ������ Y
	//	/*m_tTransPos.Position.fX +*/m_tTransPos.Scale.fX,	// ������ ���� ���κ� X
	//	/*m_tTransPos.Position.fY+*/ m_tTransPos.Scale.fY,  // ������ ���� ���κ� Y
	//	(*m_ImageList)[m_strKey]->GetMemDC(),				// ������ �̹��� (������)
	//	(int)0 * m_tTransPos.Scale.fX,		// ������ ������ X
	//	(int)0 * m_tTransPos.Scale.fY,		// ������ ������ Y
	//	(int)m_tTransPos.Scale.fX, 			// ����� �̹����� ũ�� ��ŭ X
	//	(int)m_tTransPos.Scale.fY,			// ����� �̹����� ũ�� ��ŭ Y
	//	RGB(255, 0, 255));					// �ش� ������ ����
	
		
	Rectangle(_hdc, rc.left, rc.top, rc.right, rc.bottom);
		
}

void Jelly::Release(void)
{
	
}
