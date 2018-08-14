////////////////////////////
//Header Files & Libraries//
////////////////////////////
#include "stdafx.h"
#include "Header_Files/Tweaks.h"
#include "Header_Files/WXT.h"
//Thanks to Giovanni Dicanio for his library!
#include "Library/WinReg.hpp"
#include <iostream>
#include <Windows.h>
#include <string>

////////////////////////
//    Namespaces      //
///////////////////////
using namespace std;
using namespace winreg;


/////////////////
//Tweak Handler//
/////////////////

void Tweaks::Tweak_Handler(string name,char EnableOrDisable) {
	
    
	//switch is not possible on a string :'(

	//Calls the SecondsInSystemClock tweak
	if (name == "Toggle_Seconds_System_Clock") {

		//Check if it needs to enable or disable the tweak
		if (EnableOrDisable == 'e') {

			Toggle_Seconds_System_Clock('e');
		}
		else {

			Toggle_Seconds_System_Clock('d');
		}
		
	}

	//Increase taskbar transparency
	else if (name == "UseOLEDTaskbarTransparency") {

		if (EnableOrDisable == 'e') {

			UseOLEDTaskbarTransparency('e');

		}
		else {

			UseOLEDTaskbarTransparency('d');
		}
	}
	
	//Change LockScreenImage to a solid color
	else if (name == "LockScreen_Solid_Background") {

		if (EnableOrDisable == 'e') {

			LockScreen_Solid_Background('e');

		}
		else {

			LockScreen_Solid_Background('d');

		}
	}
	
	//Disables the shortcut arrow in Desktop Shortcuts
	else if (name == "No_Shortcut_Arrows") {

		if (EnableOrDisable == 'e') {

			No_Shortcut_Arrows('e');

		}
		else {

			No_Shortcut_Arrows('d');

		}
	}
}







///////////////////////////////////////
////            Tweaks              ///
///////////////////////////////////////

//Shows seconds in the system clock

void Tweaks::Toggle_Seconds_System_Clock(char options)
{

	if (options == 'e') {

		RegKey key{
			HKEY_CURRENT_USER,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced)" };

		key.SetDwordValue(L"ShowSecondsInSystemClock", 1);

		system("taskkill /IM explorer.exe /F && explorer.exe");

	}

	else if (options == 'd') {

		RegKey key{
			HKEY_CURRENT_USER,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced)" };

		key.SetDwordValue(L"ShowSecondsInSystemClock", 0);

		system("taskkill /IM explorer.exe /F && explorer.exe");
		
	}
	
}

//Makes the Taskbar more transparent
void Tweaks::UseOLEDTaskbarTransparency(char options){

	if (options == 'e') {

		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced)" };

		key.SetDwordValue(L"UseOLEDTaskbarTransparency", 1);
		
		system("taskkill /IM explorer.exe /F && explorer.exe");

	}

	else if (options == 'd') {

		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced)" };

		key.SetDwordValue(L"UseOLEDTaskbarTransparency", 0);
		
		system("taskkill /IM explorer.exe /F && explorer.exe");

	}
}

//Changes the Lockscreen background to a solid color(system color)
void Tweaks::LockScreen_Solid_Background(char options) {

	if (options == 'e') {

		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Policies\Microsoft\Windows\System)" };

		key.SetDwordValue(L"DisableLogonBackgroundImage", 1);

	}

	else if (options == 'd') {

		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Policies\Microsoft\Windows\System)" };

		key.SetDwordValue(L"DisableLogonBackgroundImage", 0);

	}
}

//Disables the arrow icon on a desktop shortcut
void Tweaks::No_Shortcut_Arrows(char options){

	if (options == 'e') {
		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Icons)"
		};

		key.SetStringValue(L"29", L"");

		system("taskkill /IM explorer.exe /F && explorer.exe");
	}

	else if (options == 'd') {

		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Icons)"
		};

		key.DeleteValue(L"29");
		
		system("taskkill /IM explorer.exe /F && explorer.exe");
	}

}
