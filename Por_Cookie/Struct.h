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

