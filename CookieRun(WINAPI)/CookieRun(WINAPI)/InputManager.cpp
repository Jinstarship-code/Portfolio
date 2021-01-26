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

	if (GetAsyncKeyState(VK_UP))	//����Ű
	{
		m_dwKey |= KEY_JUMP;
	}
	if (GetAsyncKeyState(VK_DOWN))	//�����̵�Ű
	{
		m_dwKey |= KEY_SLIDE;
	}
	if (GetAsyncKeyState(VK_ESCAPE))	//ESC Ű ������ PAUSE â ����
	{
		m_dwKey |= KEY_ESC;
	}
	if (GetAsyncKeyState(VK_LBUTTON)) //��Ŭ��
	{
		m_dwKey |= KEY_LBUTTON;
	}
}