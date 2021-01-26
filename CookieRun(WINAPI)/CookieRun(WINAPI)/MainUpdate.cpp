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

	//���� ����̽� ���� �� �ʱ�ȭ
	SoundManager::GetInstance()->Initialize();

	//���� �߰�
	SoundManager::GetInstance()->AddSound("../Resource/Music/StageBackMusic.mp3", "StageBackMusic");

	//���� ��� �� ä�� ����
	SoundManager::GetInstance()->OnPlaySound("StageBackMusic", SOUND_CHANNEL_ID_BACKGROUND);
}

void MainUpdate::Progress(void)
{
	//�� �����Ӹ��� Ű �Է� Ȯ��
	InputManager::GetInstance()->UpdateKey();

	//������� ���尡 ����Ǳ� ������ Ȯ��
	SoundManager::GetInstance()->StreamingUpdate();

	
}

void MainUpdate::Render(void)
{
	Rectangle(m_hdc, 0, 0, WINSIZEX, WINSIZEY);  // �ϴ� ������ ũ��� ��������.
}

void MainUpdate::Release(void)
{
	ReleaseDC(g_hWnd, m_hdc);
}
