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
	m_tTransPos.Position = Vector2(464.f, 464.f);
	m_tTransPos.Rotation = Vector2(0.f, 0.f);
	m_tTransPos.Scale = Vector2(0.f, 0.f);

	m_fSpeed = 5.f;
	m_strKey = "Ground";
}

int Ground::Progress(void)
{
	return 0;
}

void Ground::Render(HDC _hdc)
{
	Rectangle(_hdc, 0,464,WINSIZEX,WINSIZEY);
}

void Ground::Release(void)
{
}
