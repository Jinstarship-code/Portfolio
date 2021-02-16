#pragma once
#include "Object.h"
class Jelly :
    public Object
{
public:
    Jelly();
    virtual ~Jelly();

private:
   // RECT rc;

public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;

public:

};

