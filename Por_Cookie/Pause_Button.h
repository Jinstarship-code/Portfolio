#pragma once
#include "Object.h"
class Pause_Button :
    public Object
{
public:
    Pause_Button();
    virtual ~Pause_Button();

private:
    // RECT rc;
    bool m_bPause;
public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;

public:
    void CheckPause(void);
};

