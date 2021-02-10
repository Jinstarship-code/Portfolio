#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Bitmap.h"
#include "BitmapManager.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Initialize(void)
{
	m_hdc = GetDC(g_hWnd);

	srand((int)GetTickCount64());

	SceneManager::GetInstance()->SetScene(SCENE_STAGE);
}

void MainUpdate::Progress(void)
{

	InputManager::GetInstance()->UpdateKey();
	SceneManager::GetInstance()->Progress();
}

void MainUpdate::Render(void)
{
	
	SceneManager::GetInstance()->Render(m_hdc);
}

void MainUpdate::Release(void)
{
	ReleaseDC(g_hWnd, m_hdc);
}
