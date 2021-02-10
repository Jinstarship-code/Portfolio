#pragma once
#include "Object.h"

class BackGround :
    public Object
{
public:
    BackGround();
    virtual ~BackGround();

public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};

