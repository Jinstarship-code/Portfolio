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
	m_hdc = GetDC(g_hWnd);

	srand((int)GetTickCount64());

	SceneManager::GetInstance()->SetScene(SCENE_LOGO);

	//���� ����̽� ���� �� �ʱ�ȭ
	SoundManager::GetInstance()->Initialize();

	//���� �߰�
	SoundManager::GetInstance()->AddSound("../Resource/Music/MenuBackMusic.mp3", "MenuBackMusic");
	SoundManager::GetInstance()->AddSound("../Resource/Music/StageBackMusic.mp3", "StageBackMusic");
	
	//���� ��� �� ä�� ����
	SoundManager::GetInstance()->OnPlaySound("MenuBackMusic", SOUND_CHANNEL_ID_MENUBACKGROUND);
}

void MainUpdate::Progress(void)
{
	//�� �����Ӹ��� Ű �Է� Ȯ��
	InputManager::GetInstance()->UpdateKey();

	//������� ���尡 ����Ǳ� ������ Ȯ��
	SoundManager::GetInstance()->StreamingUpdate();

	SceneManager::GetInstance()->Progress();
}

void MainUpdate::Render(void)
{
	Rectangle(m_hdc, 0, 0, WINSIZEX, WINSIZEY);  // �ϴ� ������ ũ��� ��������.

	SceneManager::GetInstance()->Render(m_hdc);
}

void MainUpdate::Release(void)
{
	ReleaseDC(g_hWnd, m_hdc);
}
