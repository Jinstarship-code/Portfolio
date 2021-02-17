#include "BearJelly.h"

BearJelly::BearJelly()
{
}

BearJelly::~BearJelly()
{
}

void BearJelly::Initialize(void)
{
    m_tTransPos.Position = Vector2(0.f, 0.f);
    m_tTransPos.Rotation = Vector2(0.f, 0.f);
    m_tTransPos.Scale = Vector2(55.f, 51.f);
    m_fSpeed = 0.f;
    m_strKey = "BearJelly";
}

int BearJelly::Progress(void)
{
    m_fSpeed = 5.f;

    m_tTransPos.Position.fX -= m_fSpeed;
    return 0;
}

void BearJelly::Render(HDC _hdc)
{
	//** Menu ��׶��� �̹����� ���ۿ� �����.
	TransparentBlt(_hdc,					// ������ ���� �׸��� ?!
		m_tTransPos.Position.fX,			// ������ ���� ������ X
		m_tTransPos.Position.fY, 			// ������ ���� ������ Y
		/*m_tTransPos.Position.fX+*/m_tTransPos.Scale.fX,	// ������ ���� ���κ� X
		/*m_tTransPos.Position.fY+*/m_tTransPos.Scale.fY,   // ������ ���� ���κ� Y
		(*m_ImageList)[m_strKey]->GetMemDC(),				// ������ �̹��� (������)
		(int)0 * m_tTransPos.Scale.fX,		// ������ ������ X
		(int)0 * m_tTransPos.Scale.fY,		// ������ ������ Y
		(int)m_tTransPos.Scale.fX, 			// ����� �̹����� ũ�� ��ŭ X
		(int)m_tTransPos.Scale.fY,			// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));					// �ش� ������ ����
}

void BearJelly::Release(void)
{
}
