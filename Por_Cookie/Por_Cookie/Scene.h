#pragma once
#include "Include.h"

class Bitmap;
class Scene
{
protected:
	map<string, Bitmap*>* m_pImageList;
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Initialize()PURE;
	virtual int Progress()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;

};

