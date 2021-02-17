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
	//** Menu 백그라운드 이미지를 버퍼에 출력함.
	TransparentBlt(_hdc,					// 복사해 넣을 그림판 ?!
		m_tTransPos.Position.fX,			// 복사할 영역 시작점 X
		m_tTransPos.Position.fY, 			// 복사할 영역 시작점 Y
		/*m_tTransPos.Position.fX+*/m_tTransPos.Scale.fX,	// 복사할 영역 끝부분 X
		/*m_tTransPos.Position.fY+*/m_tTransPos.Scale.fY,   // 복사할 영역 끝부분 Y
		(*m_ImageList)[m_strKey]->GetMemDC(),				// 복사할 이미지 (복사대상)
		(int)0 * m_tTransPos.Scale.fX,		// 복사할 시작점 X
		(int)0 * m_tTransPos.Scale.fY,		// 복사할 시작점 Y
		(int)m_tTransPos.Scale.fX, 			// 출력할 이미지의 크기 만큼 X
		(int)m_tTransPos.Scale.fY,			// 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));					// 해당 색상을 제외
}

void BearJelly::Release(void)
{
}
