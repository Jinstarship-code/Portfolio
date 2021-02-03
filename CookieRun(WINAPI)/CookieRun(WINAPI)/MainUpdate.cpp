#include "MainUpdate.h"
#include "SoundManager.h"
#include "InputManager.h"
#include "SceneManager.h"

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
	//그림을 그릴 dc를 window에서 받아옴.
	m_hdc = GetDC(g_hWnd);

	//사운드 디바이스 생성 및 초기화
	SoundManager::GetInstance()->Initialize();

	//사운드 추가
	SoundManager::GetInstance()->AddSound("../Resource/Music/MenuBackMusic.mp3", "MenuBackMusic");
	SoundManager::GetInstance()->AddSound("../Resource/Music/StageBackMusic.mp3", "StageBackMusic");
	
	//타임값 초기화.
	srand((int)GetTickCount64());
	
	//scene이 logo부터 시작되게.
	SceneManager::GetInstance()->SetScene(SCENE_LOGO);
}

void MainUpdate::Progress(void)
{
	//매 프레임마다 키 입력 확인
	InputManager::GetInstance()->UpdateKey();

	//재생중인 사운드가 종료되기 전인지 확인
	//SoundManager::GetInstance()->StreamingUpdate();

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
