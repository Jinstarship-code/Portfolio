#pragma once
#include "Object.h"
class Ground :
    public Object
{
public:
    Ground();
    virtual ~Ground();

public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};

