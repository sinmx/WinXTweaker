#include "stdafx.h"
#include "Header_Files/WXT.h"
#include "Header_Files/CI.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

//Ctor:Sets up WinAxeTweaker
WXT::WXT()
{
	SetConsoleTitle(L"WinXTweaker 0.1 ALPHA");
	Start();
}

//This func is automatically called by Ctor and start the App(consoleinterface)
void WXT::Start() {
	CI CI;
}


