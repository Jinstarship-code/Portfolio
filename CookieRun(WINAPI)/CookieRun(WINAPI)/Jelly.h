#pragma once
#include "Object.h"

class Jelly :
    public Object
{
public:
    Jelly();
    virtual ~Jelly();

public:
    virtual void Initialize(void)override;
    virtual void Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};

