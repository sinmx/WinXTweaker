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

	SetConsoleTitle(L"WinXTweaker 0.2");
	Start();
}

//This func is automatically called by Ctor and start the App(consoleinterface)
void WXT::Start() {

	CI CI("StartupInterface");
}

//Reloads the Windows UI(Explorer.exe) to enable tweaks without restarting the whole computer
void WXT::ReloadExplorer(){
	
	system("taskkill /f /im explorer.exe");
	system("start explorer.exe");
	CI ci("UITweaksInterface");
	
}








