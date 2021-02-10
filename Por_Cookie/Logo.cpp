#include "Logo.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "Bitmap.h"
#include "BitmapManager.h"
#include "SceneManager.h"
#include "BackGround.h"
#include "InputManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
	Release();
}

void Logo::Initialize(void)
{
	
}

int Logo::Progress(void)
{
	return 0;
}

void Logo::Render(HDC _hdc)
{
}


/*
BitBlt( _In_ HDC hdc,		사본 DC
_In_ int x, _In_ int y,		사본 비트맵에 원본 그림이 복사될 시작좌표
_In_ int cx, _In_ int cy,   width,heighm
_In_opt_ HDC hdcSrc,		원본 DC
_In_ int x1, _In_ int y1,	원본 그림에서 복사를 시작할 좌표
_In_ DWORD rop);			그림을 복사하는 방법을 설정 SRCCOPY(원본 그대로)
*/
void Logo::Release(void)
{
	
}
