#include "MenuBack.h"

MenuBack::MenuBack()
{
}

MenuBack::~MenuBack()
{
}

void MenuBack::Initialize(void)
{
	m_tTransPos.Position = Vector2(0, 0);
	m_tTransPos.Rotation = Vector2(0.f, 0.f);
	m_tTransPos.Scale = Vector2(1280, 720);

	m_strKey = "BackGround_";

	m_strKey.push_back(48 + (rand() & 4 + 1));
}

void MenuBack::Progress(void)
{
}

void MenuBack::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		0, 0,
		WINSIZEX, WINSIZEY,
		(*m_ImageList)[m_strKey]->GetMemDC(),
		(int)m_tTransPos.Position.fX,
		(int)m_tTransPos.Position.fY,
		(int)m_tTransPos.Scale.fX,
		(int)m_tTransPos.Scale.fY,
		RGB(255, 0, 255));
}

void MenuBack::Release(void)
{
}
