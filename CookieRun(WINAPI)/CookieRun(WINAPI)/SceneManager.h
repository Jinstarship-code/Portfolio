#pragma once
#include "Include.h"
#include "Scene.h"

class SceneManager
{
private:
	SceneManager();
public:
	~SceneManager();

private:
	static SceneManager* m_pInstance;
public:
	static SceneManager* GetInstance()
	{
		if (m_pInstance == NULL)	m_pInstance = new SceneManager;

		return m_pInstance;
	}

private:
	Scene* m_SceneState;

public:
	void SetScene(SCENES _state);
	void Progress();
	void Render(HDC _hdc);

};
