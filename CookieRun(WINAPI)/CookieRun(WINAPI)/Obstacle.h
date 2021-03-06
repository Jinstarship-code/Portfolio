#pragma once
#include "Object.h"
class Obstacle :
    public Object
{
public:
    Obstacle();
    virtual ~Obstacle();

public:
    virtual void Initialize(void)override;
    virtual void Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};

