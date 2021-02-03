#pragma once
#include "Object.h"

class MenuBack : public Object
{
public:
	MenuBack();
    virtual ~MenuBack();

public:
    virtual void Initialize(void)override;
    virtual void Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};

