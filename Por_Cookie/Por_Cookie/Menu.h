#pragma once
#include "Scene.h"

class Object;
class Menu :
    public Scene
{
public:
    Menu();
    virtual ~Menu();
private:
    Object* m_pBackGround;
    vector<Object*> m_pButtonList;
public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};

