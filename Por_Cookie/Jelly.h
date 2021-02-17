#pragma once
#include "Object.h"

class BaseJelly :
    public Object
{
public:
    BaseJelly();
    virtual ~BaseJelly();

private:
   // RECT rc;

public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;

public:

};

