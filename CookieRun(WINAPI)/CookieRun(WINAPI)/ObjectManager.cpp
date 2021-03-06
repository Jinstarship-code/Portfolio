#include "ObjectManager.h"
#include "CollisionManager.h"
#include "Player.h"
#include "SceneManager.h"

ObjectManager* ObjectManager::m_pInstance = NULL;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::AddObject(string _strKey, Object* _pObject)
{
	map < string, list<Object*>>::iterator iter = m_mapObjectList.find(_strKey);

	if (iter == m_mapObjectList.end())
	{
		list<Object*> TempList;
		TempList.push_back(_pObject);

		m_mapObjectList.insert(make_pair(_strKey, TempList));
	}
	else
		iter->second.push_back(_pObject);
}

void ObjectManager::Progress(void)
{
	for (map<string, list<Object*>>::iterator iter = m_mapObjectList.begin();
		iter != m_mapObjectList.end(); iter++)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); iter2++)
		{
			(*iter2)->Progress();
		}
	}

	map<string, list<Object*>>::iterator iterPlayer = m_mapObjectList.find("Player");
	map<string, list<Object*>>::iterator iterObstacle = m_mapObjectList.find("Obstacle");

	for (list<Object*>::iterator iter = iterObstacle->second.begin();
		iter != iterObstacle->second.end();)
	{
		if (CollisionManager::CollRect(iterPlayer->second.front(),(*iter)))
		{
			iter=iterObstacle->second.erase(iter);
			Object* pObj = iterPlayer->second.front();
		}
		else
			++iter;
	}
}

void ObjectManager::Render(HDC _hdc)
{
	for (map<string, list<Object*>>::iterator iter = m_mapObjectList.begin();
		iter != m_mapObjectList.end(); iter++)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); iter2++)
		{
			(*iter2)->Render(_hdc);
		}
	}
}

void ObjectManager::Release(void)
{
	for (map<string, list<Object*>>::iterator iter = m_mapObjectList.begin();
		iter != m_mapObjectList.end(); iter++)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); iter2++)
		{
			delete (*iter2);
			(*iter2) = NULL;
		}
		iter->second.clear();
	}
	m_mapObjectList.clear();
}
