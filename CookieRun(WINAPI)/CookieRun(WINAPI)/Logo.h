#pragma once
#include "Scene.h"

class Object;
class Logo :
    public Scene
{
public:
    Logo();
    virtual ~Logo();
private:
    vector<Object*> m_pButtonList;
    Object* m_pBackGround[2];

public:
    virtual void Initialize(void)override;
    virtual void Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};

