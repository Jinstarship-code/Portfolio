#pragma once

#define WINSIZEX 1280
#define WINSIZEY 720

#define PI 3.141592f;

extern HWND g_hWnd;

const DWORD KEY_JUMP	= 0x00001;	//점프키, 
const DWORD KEY_SLIDE	= 0x00002;	//슬라이드키
const DWORD KEY_ESC		= 0x00004;  //메뉴키 
const DWORD KEY_LBUTTON	= 0x00008;  //마우스 왼클릭