#include "BackGround.h"


BackGround::BackGround()
{
}

BackGround::~BackGround()
{
}

void BackGround::Initialize(void)
{
    m_tTransPos.Position = Vector2(0.f, 0.f);
    m_tTransPos.Rotation = Vector2(0.f, 0.f);
    m_tTransPos.Scale = Vector2(WINSIZEX, WINSIZEY);

    m_fAngle = 0.f;
    m_fSpeed = 3.f;
    m_strKey = "BackGround_1";
}

int BackGround::Progress(void)
{
    m_tTransPos.Position.fX -= m_fSpeed;

    if (m_tTransPos.Position.fX+WINSIZEX <= 0)
        m_tTransPos.Position.fX = WINSIZEX;
    return 0;
}

void BackGround::Render(HDC _hdc)
{
    //** Menu 백그라운드 이미지를 버퍼에 출력함.
    TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
        m_tTransPos.Position.fX,	// 복사할 영역 시작점 X
        m_tTransPos.Position.fY, 	// 복사할 영역 시작점 Y
        /*m_tTransPos.Position.fX*/ + m_tTransPos.Scale.fX,	// 복사할 영역 끝부분 X
        m_tTransPos.Position.fY + m_tTransPos.Scale.fY, // 복사할 영역 끝부분 Y
        (*m_ImageList)[m_strKey]->GetMemDC(),	// 복사할 이미지 (복사대상)
        (int)0 * m_tTransPos.Scale.fX,		// 복사할 시작점 X
        (int)0 * m_tTransPos.Scale.fY,		// 복사할 시작점 Y
        (int)m_tTransPos.Scale.fX, 		// 출력할 이미지의 크기 만큼 X
        (int)m_tTransPos.Scale.fY,		// 출력할 이미지의 크기 만큼 Y
        RGB(255, 0, 255));		// 해당 색상을 제외


    
}
/*
WINGDIAPI BOOL WINAPI TransparentBlt(
    _In_ HDC hdcDest,                           이미지를 출력할 위치의 핸들
    _In_ int xoriginDest, _In_ int yoriginDest, 이미지를 출력할 위치의 x,y 좌표
    _In_ int wDest, _In_ int hDest,             출력할 이미지의 너비 높이
    _In_ HDC hdcSrc,                            이미지의 핸들
    _In_ int xoriginSrc, _In_ int yoriginSrc,   가져올 이미지의 시작지점 좌표
    _In_ int wSrc, _In_ int hSrc,               원본 이미지로부터 해당 크기만큼 잘라낼 이미지의 너비 높이
    _In_ UINT crTransparent);                   투명하게 할 rgb 색상
*/
void BackGround::Release(void)
{
}
