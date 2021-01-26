#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::m_pInstance = NULL;

SceneManager::SceneManager()	:
	m_SceneState(NULL)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::SetScene(SCENES _state)
{
	if (m_SceneState != NULL)
	{
		delete m_SceneState;
		m_SceneState = NULL;
	}

	switch (_state)
	{
	case SCENE_LOGO:
		m_SceneState = new Logo;
		break;
	case SCENE_MENU:
		m_SceneState = new Menu;
		break;
	case SCENE_STAGE:
		m_SceneState = new Stage;
		break;
	case SCENE_EXIT:
		break;
	}
	m_SceneState->Initialize();
}

void SceneManager::Progress()
{
}

void SceneManager::Render(HDC _hdc)
{
}
