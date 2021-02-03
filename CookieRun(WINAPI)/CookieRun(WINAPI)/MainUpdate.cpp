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
	//�׸��� �׸� dc�� window���� �޾ƿ�.
	m_hdc = GetDC(g_hWnd);

	//���� ����̽� ���� �� �ʱ�ȭ
	SoundManager::GetInstance()->Initialize();

	//���� �߰�
	SoundManager::GetInstance()->AddSound("../Resource/Music/MenuBackMusic.mp3", "MenuBackMusic");
	SoundManager::GetInstance()->AddSound("../Resource/Music/StageBackMusic.mp3", "StageBackMusic");
	
	//Ÿ�Ӱ� �ʱ�ȭ.
	srand((int)GetTickCount64());
	
	//scene�� logo���� ���۵ǰ�.
	SceneManager::GetInstance()->SetScene(SCENE_LOGO);
}

void MainUpdate::Progress(void)
{
	//�� �����Ӹ��� Ű �Է� Ȯ��
	InputManager::GetInstance()->UpdateKey();

	//������� ���尡 ����Ǳ� ������ Ȯ��
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
