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
    m_tTransPos.Position = Vector2(0.f,0.f);
    m_tTransPos.Rotation = Vector2(0.f, 0.f);
    m_tTransPos.Scale = Vector2(53.f, 50.f);
	m_fSpeed = 0.f;
    m_strKey = "Jelly";

	
}

int Jelly::Progress(void)
{
	m_fSpeed = 3.f;

	rc.left -= m_fSpeed;
	rc.right -= m_fSpeed;

	if (rc.left==100)
	{
		rc.left = 0;
		rc.right = 0;
		rc.bottom = 0;
		rc.top = 0;
	}

    return 0;
}

void Jelly::Render(HDC _hdc)
{
	TransparentBlt(_hdc,	  // 복사해 넣을 그림판 ?!
		(int)m_tTransPos.Position.fX,	// 복사할 영역 시작점 X
		(int)m_tTransPos.Position.fY, // 복사할 영역 시작점 Y
		(int)m_tTransPos.Scale.fX,	// 복사할 영역 끝부분 X
		(int)m_tTransPos.Scale.fY, 	// 복사할 영역 끝부분 Y
		(*m_ImageList)[m_strKey]->GetMemDC(),		// 복사할 이미지 (복사대상)
		int(m_tFrame.Count * m_tTransPos.Scale.fX),  // 복사할 시작점 X
		int(m_tFrame.Scene * m_tTransPos.Scale.fY),	// 복사할 시작점 Y
		(int)m_tTransPos.Scale.fX, 	// 출력할 이미지의 크기 만큼 X
		(int)m_tTransPos.Scale.fY,	// 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));
		
	//Rectangle(_hdc, rc.left, rc.top, rc.right, rc.bottom);
		
}

void Jelly::Release(void)
{
	
}
