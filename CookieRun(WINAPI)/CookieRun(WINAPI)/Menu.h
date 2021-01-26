#pragma once
#include "Scene.h"
class Menu :
    public Scene
{
public:
    Menu();
    virtual ~Menu();

public:
    virtual void Initialize(void)override;
    virtual void Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};

