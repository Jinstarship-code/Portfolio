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
	가상의 pause_button 만한 크기의 원을 만들고 ,
	esc 키를 누르면 게임이 잠시 멈추고 

	초기화 할껀지 지금 상태에서 계속 진행할 껀지를 선택할 수 있는 버튼 2개.
	***************************************************/
	if (m_bPause)
	{
		m_tTransPos.Scale = Vector2(0.f, 0.f);
	}
	
	
    return 0;
}

void Pause_Button::Render(HDC _hdc)
{
	//** Menu 백그라운드 이미지를 버퍼에 출력함.
	TransparentBlt(_hdc,					// 복사해 넣을 그림판 ?!
		m_tTransPos.Position.fX,			// 복사할 영역 시작점 X
		m_tTransPos.Position.fY, 			// 복사할 영역 시작점 Y
		/*m_tTransPos.Position.fX+*/m_tTransPos.Scale.fX,	// 복사할 영역 끝부분 X
		/*m_tTransPos.Position.fY+*/m_tTransPos.Scale.fY,   // 복사할 영역 끝부분 Y
		(*m_ImageList)[m_strKey]->GetMemDC(),				// 복사할 이미지 (복사대상)
		(int)0 * m_tTransPos.Scale.fX,		// 복사할 시작점 X
		(int)0 * m_tTransPos.Scale.fY,		// 복사할 시작점 Y
		(int)m_tTransPos.Scale.fX, 			// 출력할 이미지의 크기 만큼 X
		(int)m_tTransPos.Scale.fY,			// 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));					// 해당 색상을 제외
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
