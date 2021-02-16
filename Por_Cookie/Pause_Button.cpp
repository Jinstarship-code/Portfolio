#include "Pause_Button.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "Object.h"
#include "Player.h"
#include "Jelly.h"
Pause_Button::Pause_Button()
{
}

Pause_Button::~Pause_Button()
{
}

void Pause_Button::Initialize(void)
{
    m_tTransPos.Position = Vector2(WINSIZEX-100.f, 10.f);
    m_tTransPos.Rotation = Vector2(0.f, 0.f);
    m_tTransPos.Scale = Vector2(70.f, 70.f);
    m_fSpeed = 0.f;
	m_bPause = false;
    m_strKey = "Pause_Button";
}

int Pause_Button::Progress(void)
{
	/*************************************************
	������ pause_button ���� ũ���� ���� ����� ,
	esc Ű�� ������ ������ ��� ���߰� 

	�ʱ�ȭ �Ҳ��� ���� ���¿��� ��� ������ ������ ������ �� �ִ� ��ư 2��.
	***************************************************/
	if (m_bPause)
	{
		m_tTransPos.Scale = Vector2(0.f, 0.f);
	}
	
	
    return 0;
}

void Pause_Button::Render(HDC _hdc)
{
	//** Menu ��׶��� �̹����� ���ۿ� �����.
	TransparentBlt(_hdc,					// ������ ���� �׸��� ?!
		m_tTransPos.Position.fX,			// ������ ���� ������ X
		m_tTransPos.Position.fY, 			// ������ ���� ������ Y
		/*m_tTransPos.Position.fX+*/m_tTransPos.Scale.fX,	// ������ ���� ���κ� X
		/*m_tTransPos.Position.fY+*/m_tTransPos.Scale.fY,   // ������ ���� ���κ� Y
		(*m_ImageList)[m_strKey]->GetMemDC(),				// ������ �̹��� (������)
		(int)0 * m_tTransPos.Scale.fX,		// ������ ������ X
		(int)0 * m_tTransPos.Scale.fY,		// ������ ������ Y
		(int)m_tTransPos.Scale.fX, 			// ����� �̹����� ũ�� ��ŭ X
		(int)m_tTransPos.Scale.fY,			// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));					// �ش� ������ ����
}

void Pause_Button::Release(void)
{

}

void Pause_Button::CheckPause(void)
{
	DWORD dwCheckPause = InputManager::GetInstance()->GetKey();

	if (VK_ESCAPE&dwCheckPause)
	{
		m_bPause = true;
	}
	else
		m_bPause =false;

}
