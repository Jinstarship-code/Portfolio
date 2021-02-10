#pragma once
#include "Scene.h"

class Object;
class Stage :
    public Scene
{
public:
    Stage();
    virtual ~Stage();
private:
    Object* m_pBackGround[2];
public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};

