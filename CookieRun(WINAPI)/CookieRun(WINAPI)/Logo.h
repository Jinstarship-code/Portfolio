#pragma once
#include "Scene.h"
class Logo :
    public Scene
{
public:
    Logo();
    virtual ~Logo();

public:
    virtual void Initialize(void)override;
    virtual void Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};

