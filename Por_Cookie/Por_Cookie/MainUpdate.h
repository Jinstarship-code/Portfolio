#pragma once
#include "Include.h"

class MainUpdate
{
public:
	MainUpdate();
	~MainUpdate();
private:
	HDC m_hdc;
public:
	void Initialize(void);
	void Progress(void);
	void Render(void);
	void Release(void);
};

