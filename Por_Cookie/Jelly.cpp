#include "Jelly.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"


Jelly::Jelly()
{
}

Jelly::~Jelly()
{
}

void Jelly::Initialize(void)
{
    m_tTransPos.Position = Vector2(0.f, 0.f);
    m_tTransPos.Rotation = Vector2(0.f, 0.f);
    m_tTransPos.Scale = Vector2(67.f, 64.f);

    m_strKey = "Jelly";


}

int Jelly::Progress(void)
{
    return 0;
}

void Jelly::Render(HDC _hdc)
{
}

void Jelly::Release(void)
{
}
