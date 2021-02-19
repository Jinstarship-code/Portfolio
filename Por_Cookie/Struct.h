#pragma once

typedef struct tagVector2
{
	float fX, fY;
	tagVector2() {};
	tagVector2(float _fx, float _fy) : fX(_fx), fY(_fy) {};
	
}Vector2;

typedef struct tagTransform
{
	Vector2 Position;
	Vector2 Rotation;
	Vector2 Scale;
}Transform;


typedef struct tagFrame
{
	int StartFrame;
	int Count;
	int LastFrame;
	int Scene;
	DWORD FrameTime;

	tagFrame() {};

	tagFrame(int _StartFrame,
		int _Count,
		int _LastFrame,
		int _Scene,
		DWORD _FrameTime)
		: StartFrame(_StartFrame),
		Count(_Count),
		LastFrame(_LastFrame),
		Scene(_Scene),
		FrameTime(_FrameTime) {};

}Frame;

/*
Frame(int _StartFrame, 출력을 시작할 이미지 시작점.
int _Count,				시작점부터 끝지점까지 순차적으로 출력지점을 이동시켜줌
int _LastFrame,			출력할 이미지의 마지막 지점
int _SceneFrame,		점프, 이동, 공경 등의 장면을 변경 시킴
DWORD _FrameTime)

DWORD _FrameTime = 	장면마다 출력해야할 이미지 개수가 다르다.
	수량에 비례하여 출력되기 때문에
	애니매이션이 끝나는 지점을 맞춰주기 위함.

	몬스터의 공격프 이미지가 5장이고
	플레이어의 공격 이미지가 10 장이라 한다면
	우리가 출력하는 이미지는 매 프레임마다 1장의 이미지가 출력되기 때문에
	몬스터가 2번의 공격을 할때 플레이어는 한번의 공격을 하게된다.

	이런 문제를 해결하기위해 이미지 전체가 출력되는 시간을 정해놓고 출력해야 한다. (초당 공격력으로 환산된다.)
*/