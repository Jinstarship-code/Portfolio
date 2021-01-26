#include "InputManager.h"

InputManager* InputManager::m_pInstance = NULL;

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::UpdateKey()
{
	m_dwKey = 0;  

	if (GetAsyncKeyState(VK_UP))	//점프키
	{
		m_dwKey |= KEY_JUMP;
	}
	if (GetAsyncKeyState(VK_DOWN))	//슬라이드키
	{
		m_dwKey |= KEY_SLIDE;
	}
	if (GetAsyncKeyState(VK_ESCAPE))	//ESC 키 누르면 PAUSE 창 띄우기
	{
		m_dwKey |= KEY_ESC;
	}
	if (GetAsyncKeyState(VK_LBUTTON)) //왼클릭
	{
		m_dwKey |= KEY_LBUTTON;
	}
}