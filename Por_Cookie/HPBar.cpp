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
    m_tTransPos.Scale = Vector2(950, 50);

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

    //        //게임 오버시.
    //        if (m_fCurHP == m_tTransPos.Position.fX)
    //            break;
    //        else
    //        m_fSpeed+=0.01f;
    //        /****
    //        게임 오버시, 쿠키가 쓰러지는 애니메이션을 보여주고 게임오버 화면을 출력한다.
    //        ****/
    //}

    
    return 0;
}

void HPBar::Render(HDC _hdc)
{
   
       
        Rectangle(_hdc, m_tTransPos.Position.fX, m_tTransPos.Position.fY, m_tTransPos.Scale.fX, m_tTransPos.Scale.fY);
    

}

void HPBar::Release(void)
{
}
