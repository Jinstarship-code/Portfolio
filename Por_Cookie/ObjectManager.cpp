#include "ObjectManager.h"
#include "Player.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include "Jelly.h"
#include "Obstacle1.h"

ObjectManager* ObjectManager::m_pInstance = NULL;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::AddObject(string _strKey, Object* _Object)
{
	map<string, list<Object*>>::iterator iter = m_mapObjectList.find(_strKey);

	if (iter == m_mapObjectList.end())
	{
		list<Object*> TempList;
		TempList.push_back(_Object);

		m_mapObjectList.insert(make_pair(_strKey, TempList));
	}
	else
		iter->second.push_back(_Object);
}

void ObjectManager::Progress(void)
{
	for (map<string, list<Object*>>::iterator iter = m_mapObjectList.begin();
		iter != m_mapObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			//오브젝트들의 progress를 진행 하고
			(*iter2)->Progress();
		}
	}
	// 여기서 충돌 처리를 한다...??
	
	/***********************
	젤리와 플레이어의 충돌처리
	************************/
	map<string, list<Object*>>::iterator iterPlayer = m_mapObjectList.find("Player");
	map<string, list<Object*>>::iterator iterJelly = m_mapObjectList.find("Jelly");

	for (list<Object*>::iterator iter = iterJelly->second.begin();
		iter != iterJelly->second.end(); )
	{
		if (CollisionManager::CollRect(iterPlayer->second.front(), (*iter)))
		{
			iter = iterJelly->second.erase(iter);

			Object* pObj = iterPlayer->second.front();

			//((Player*)pObj)->SetMoveFalse();
		}
		else
			++iter;
	}


	/***************************
	플레이어와 장애물과의 충돌처리
	****************************/





}

void ObjectManager::Render(HDC _hdc)
{
	for (map<string, list<Object*>>::iterator iter = m_mapObjectList.begin();
		iter != m_mapObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render(_hdc);
		}
	}
}

void ObjectManager::Release(void)
{
	for (map<string, list<Object*>>::iterator iter = m_mapObjectList.begin();
		iter != m_mapObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			delete (*iter2);
			(*iter2) = NULL;
		}

		iter->second.clear();
	}

	m_mapObjectList.clear();
}
