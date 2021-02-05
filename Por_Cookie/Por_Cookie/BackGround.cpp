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
    //** Menu ��׶��� �̹����� ���ۿ� �����.
    TransparentBlt(_hdc,	  // ������ ���� �׸��� ?!
        m_tTransPos.Position.fX,	// ������ ���� ������ X
        m_tTransPos.Position.fY, 	// ������ ���� ������ Y
        /*m_tTransPos.Position.fX*/ + m_tTransPos.Scale.fX,	// ������ ���� ���κ� X
        m_tTransPos.Position.fY + m_tTransPos.Scale.fY, // ������ ���� ���κ� Y
        (*m_ImageList)[m_strKey]->GetMemDC(),	// ������ �̹��� (������)
        (int)0 * m_tTransPos.Scale.fX,		// ������ ������ X
        (int)0 * m_tTransPos.Scale.fY,		// ������ ������ Y
        (int)m_tTransPos.Scale.fX, 		// ����� �̹����� ũ�� ��ŭ X
        (int)m_tTransPos.Scale.fY,		// ����� �̹����� ũ�� ��ŭ Y
        RGB(255, 0, 255));		// �ش� ������ ����


    
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
