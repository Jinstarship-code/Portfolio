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
   void Bear(float x, float y);
   void SCoin(float x, float y);
   void GCoin(float x, float y);
   void Cherry(float x, float y);
   void Obs1(float x, float y);
   void Obs2(float x, float y);
   void Obs3(float x, float y);

public:
    virtual void Initialize(void)override;
    virtual int Progress(void)override;
    virtual void Render(HDC _hdc)override;
    virtual void Release(void)override;
};

