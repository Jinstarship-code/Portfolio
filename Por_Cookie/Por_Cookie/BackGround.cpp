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
    m_fSpeed = 5.f;
    //m_strKey = "BackGround_1";
}

int BackGround::Progress(void)
{
   /* m_tTransPos.Position.fY += m_fSpeed;

    if (m_tTransPos.Position.fY >= WINSIZEY)
        m_tTransPos.Position.fY = (-WINSIZEY);
   */ return 0;
}

void BackGround::Render(HDC _hdc)
{
    /*TransparentBlt(_hdc,
        m_tTransPos.Position.fX,
        m_tTransPos.Position.fY,
        m_tTransPos.Position.fX + m_tTransPos.Scale.fX,
        m_tTransPos.Position.fY + m_tTransPos.Scale.fY,
        (*m_ImageList)[m_strKey]->GetMemDC(),
        (int)0 * m_tTransPos.Position.fX,
        (int)0 * m_tTransPos.Position.fY,
        (int)m_tTransPos.Scale.fX,
        (int)m_tTransPos.Scale.fY,
        RGB(255, 0, 255));*/

    Rectangle(_hdc, 464, 464, WINSIZEX, WINSIZEY);
}
/*
WINGDIAPI BOOL WINAPI TransparentBlt(
    _In_ HDC hdcDest,                           �̹����� ����� ��ġ�� �ڵ�
    _In_ int xoriginDest, _In_ int yoriginDest, �̹����� ����� ��ġ�� x,y ��ǥ
    _In_ int wDest, _In_ int hDest,             ����� �̹����� �ʺ� ����
    _In_ HDC hdcSrc,                            �̹����� �ڵ�
    _In_ int xoriginSrc, _In_ int yoriginSrc,   ������ �̹����� �������� ��ǥ
    _In_ int wSrc, _In_ int hSrc,               ���� �̹����κ��� �ش� ũ�⸸ŭ �߶� �̹����� �ʺ� ����
    _In_ UINT crTransparent);                   �����ϰ� �� rgb ����
*/
void BackGround::Release(void)
{
}
