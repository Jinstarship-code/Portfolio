#pragma once
#include "Include.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
};

