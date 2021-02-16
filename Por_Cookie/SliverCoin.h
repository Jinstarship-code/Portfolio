#pragma once
#include "Object.h"
class SliverCoin :
    public Object
{
public:
    SliverCoin();
    virtual ~SliverCoin();

private:
   

public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};

