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
BitBlt( _In_ HDC hdc,		�纻 DC
_In_ int x, _In_ int y,		�纻 ��Ʈ�ʿ� ���� �׸��� ����� ������ǥ
_In_ int cx, _In_ int cy,   width,heighm
_In_opt_ HDC hdcSrc,		���� DC
_In_ int x1, _In_ int y1,	���� �׸����� ���縦 ������ ��ǥ
_In_ DWORD rop);			�׸��� �����ϴ� ����� ���� SRCCOPY(���� �״��)
*/
void Logo::Release(void)
{
	
}
