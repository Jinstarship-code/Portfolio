#include "MainUpdate.h"
#include "SoundManager.h"
#include "InputManager.h"

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

	//사운드 디바이스 생성 및 초기화
	SoundManager::GetInstance()->Initialize();

	//사운드 추가
	SoundManager::GetInstance()->AddSound("../Resource/Music/StageBackMusic.mp3", "StageBackMusic");

	//사운드 재생 및 채널 설정
	SoundManager::GetInstance()->OnPlaySound("StageBackMusic", SOUND_CHANNEL_ID_BACKGROUND);
}

void MainUpdate::Progress(void)
{
	//매 프레임마다 키 입력 확인
	InputManager::GetInstance()->UpdateKey();

	//재생중인 사운드가 종료되기 전인지 확인
	SoundManager::GetInstance()->StreamingUpdate();

	
}

void MainUpdate::Render(void)
{
	Rectangle(m_hdc, 0, 0, WINSIZEX, WINSIZEY);  // 일단 이정도 크기면 괜찮을듯.
}

void MainUpdate::Release(void)
{
	ReleaseDC(g_hWnd, m_hdc);
}
