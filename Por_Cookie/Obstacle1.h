#pragma once
#include "Object.h"

class Obstacle1 :
    public Object
{
public:
    Obstacle1();
    virtual ~Obstacle1();

private:
    RECT rc;

public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};


/****

Obstacle1 :  바닥에 피클이 꽂혀있는 장애물


***/