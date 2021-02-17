#pragma once
#include "Object.h"

class BearJelly :
    public Object
{

public:
    BearJelly();
    virtual ~BearJelly();

private:
    // RECT rc;

public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;



};

