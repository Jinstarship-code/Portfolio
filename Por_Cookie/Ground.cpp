#include "Ground.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

Ground::Ground()
{
}

Ground::~Ground()
{
}

void Ground::Initialize(void)
{
	m_tTransPos.Position = Vector2(0.f, 626.f);
	m_tTransPos.Rotation = Vector2(0.f, 0.f);
	m_tTransPos.Scale = Vector2(5097.f,94.f);

	m_fSpeed = 5.f;
	m_strKey = "Ground";
}

int Ground::Progress(void)
{
    /****************
     �� �����̰� ����.
    *****************/
    m_tTransPos.Position.fX -= m_fSpeed;

    /*if (m_tTransPos.Position.fX<-5216 )
        m_tTransPos.Position.fX = 0; */
	return 0;
}

void Ground::Render(HDC _hdc)
{
	//Rectangle(_hdc, 0,500,WINSIZEX,WINSIZEY);

     //** Menu ��׶��� �̹����� ���ۿ� �����.
    TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
        m_tTransPos.Position.fX,	// ������ ���� ������ X
        m_tTransPos.Position.fY, 	// ������ ���� ������ Y
        /*m_tTransPos.Position.fX*/ +m_tTransPos.Scale.fX,	// ������ ���� ���κ� X
        /*m_tTransPos.Position.fY*/ + m_tTransPos.Scale.fY, // ������ ���� ���κ� Y
        (*m_ImageList)[m_strKey]->GetMemDC(),	// ������ �̹��� (������)
        (int)0 * m_tTransPos.Scale.fX,		// ������ ������ X
        (int)0 * m_tTransPos.Scale.fY,		// ������ ������ Y
        (int)m_tTransPos.Scale.fX, 		// ����� �̹����� ũ�� ��ŭ X
        (int)m_tTransPos.Scale.fY,		// ����� �̹����� ũ�� ��ŭ Y
        RGB(255, 0, 255));		// �ش� ������ ����

}

void Ground::Release(void)
{
}
