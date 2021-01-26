#pragma once
#include "Scene.h"
class Stage :
    public Scene
{
public:
    Stage();
    virtual ~Stage();

public:
    virtual void Initialize(void)override;
    virtual void Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};
