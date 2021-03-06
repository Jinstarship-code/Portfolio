#pragma once
#include "Include.h"

class InputManager
{
private:
	InputManager();
public:
	~InputManager();

private:
	static InputManager* m_pInstance;
public:
	static InputManager* GetInstance()
	{
		if (m_pInstance == NULL)	m_pInstance = new InputManager;

		return m_pInstance;
	}

private:
	DWORD m_dwKey;
public:
	DWORD GetKey() { return m_dwKey; }
	void UpdateKey();
};

