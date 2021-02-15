#include "HPBar.h"

HPBar::HPBar()
{
}

HPBar::~HPBar()
{
    Release();
}

void HPBar::Initialize(void)
{
    m_tTransPos.Position = Vector2(150.f, 10.f);
    m_tTransPos.Rotation = Vector2(0.f, 0.f);
    m_tTransPos.Scale = Vector2(798, 52);

    m_fMaxHP = m_tTransPos.Scale.fX;
    m_fCurHP = 0.f;
    m_fSpeed = 0.f;
    
    m_strKey = "HPBar";

    m_dwFrameTime = GetTickCount64();

}

int HPBar::Progress(void)
{
    m_fSpeed = 0.01f;
    
    
    //while (m_tTransPos.Scale.fX > m_tTransPos.Position.fX)
    //{
    //        m_fCurHP = m_tTransPos.Scale.fX - m_fSpeed;

    //        //���� ������.
    //        if (m_fCurHP == m_tTransPos.Position.fX)
    //            break;
    //        else
    //        m_fSpeed+=0.01f;
    //        /****
    //        ���� ������, ��Ű�� �������� �ִϸ��̼��� �����ְ� ���ӿ��� ȭ���� ����Ѵ�.
    //        ****/
    //}

    
    return 0;
}

void HPBar::Render(HDC _hdc)
{
        //Rectangle(_hdc, m_tTransPos.Position.fX, m_tTransPos.Position.fY, m_tTransPos.Scale.fX, m_tTransPos.Scale.fY);
   

    //** Menu ��׶��� �̹����� ���ۿ� �����.
    TransparentBlt(_hdc,					// ������ ���� �׸��� ?!
        m_tTransPos.Position.fX,			// ������ ���� ������ X
        m_tTransPos.Position.fY, 			// ������ ���� ������ Y
        /*m_tTransPos.Position.fX +*/m_tTransPos.Scale.fX,	// ������ ���� ���κ� X
        /*m_tTransPos.Position.fY+*/ m_tTransPos.Scale.fY,  // ������ ���� ���κ� Y
        (*m_ImageList)[m_strKey]->GetMemDC(),				// ������ �̹��� (������)
        (int)0 * m_tTransPos.Scale.fX,		// ������ ������ X
        (int)0 * m_tTransPos.Scale.fY,		// ������ ������ Y
        (int)m_tTransPos.Scale.fX, 			// ����� �̹����� ũ�� ��ŭ X
        (int)m_tTransPos.Scale.fY,			// ����� �̹����� ũ�� ��ŭ Y
        RGB(255, 0, 255));					// �ش� ������ ����


}

void HPBar::Release(void)
{
}
