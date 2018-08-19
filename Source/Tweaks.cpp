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
	else if (name == "UseWindows7VolumeUI") {
		if (EnableOrDisable == 'e') {

			UseWindows7VolumeUI('e');

		}
		else {

			UseWindows7VolumeUI('d');

		}
	}

	else if (name == "EnableHiddenSettingsMenu") {

		if (EnableOrDisable == 'e') {

			EnableHiddenSettingsMenu('e');

		}
		else {

			EnableHiddenSettingsMenu('d');

		}
	}
	else if (name == "RemoveOnedriveFromExplorer") {

		if (EnableOrDisable == 'e') {

			RemoveOnedriveFromExplorer('e');

		}
		else {

			RemoveOnedriveFromExplorer('d');

		}
	}

	else if (name == "PaintDesktopVersion") {

		if (EnableOrDisable == 'e') {

			PaintDesktopVersion('e');

		}
		else {

			PaintDesktopVersion('d');

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

		
		WXT::ReloadExplorer();

	}

	else if (options == 'd') {

		RegKey key{
			HKEY_CURRENT_USER,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced)" };

		key.SetDwordValue(L"ShowSecondsInSystemClock", 0);

		
		WXT::ReloadExplorer();
		
	}
	
}

//Makes the Taskbar more transparent
void Tweaks::UseOLEDTaskbarTransparency(char options){

	if (options == 'e') {

		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced)" };

		key.SetDwordValue(L"UseOLEDTaskbarTransparency", 1);
		
		WXT::ReloadExplorer();

	}

	else if (options == 'd') {

		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced)" };

		key.SetDwordValue(L"UseOLEDTaskbarTransparency", 0);
		
		
		WXT::ReloadExplorer();

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

		
		WXT::ReloadExplorer();
	}

	else if (options == 'd') {

		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Icons)"
		};

		key.DeleteValue(L"29");
		
		
		WXT::ReloadExplorer();
	}

}

void Tweaks::UseWindows7VolumeUI(char options){
	if(options == 'e') {

		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Microsoft\Windows NT\CurrentVersion\MTCUVC)" };

		key.SetDwordValue(L"EnableMtcUvc", 0);

	}

	else if (options == 'd') {

	RegKey key{
		HKEY_LOCAL_MACHINE,
		LR"(SOFTWARE\Microsoft\Windows NT\CurrentVersion\MTCUVC)" };

	key.SetDwordValue(L"EnableMtcUvc", 1);

	}
}

void Tweaks::EnableHiddenSettingsMenu(char options){

	if (options == 'e') {

		RegKey key{
			HKEY_CURRENT_USER,
			LR"(Control Panel)" };

		key.SetDwordValue(L"EnableSamplesPage", 1);

	}

	else if (options == 'd') {

		RegKey key{
			HKEY_CURRENT_USER,
			LR"(Control Panel)" };

		key.SetDwordValue(L"EnableSamplesPage", 0);

	}
}

void Tweaks::RemoveOnedriveFromExplorer(char options){
	if (options == 'e') {

		RegKey key{
			HKEY_CLASSES_ROOT,
			LR"(CLSID\{018D5C66-4533-4307-9B53-224DE2ED1FE6})" };

		key.SetDwordValue(L"System.IsPinnedToNameSpaceTree", 0);

	}

	else if (options == 'd') {

		RegKey key{
			HKEY_CLASSES_ROOT,
			LR"(CLSID\{018D5C66-4533-4307-9B53-224DE2ED1FE6})" };

		key.SetDwordValue(L"System.IsPinnedToNameSpaceTree", 1);

	}
}

void Tweaks::PaintDesktopVersion(char options){

	if (options == 'e') {

		RegKey key{
			HKEY_CURRENT_USER,
			LR"(Control Panel\Desktop)" };

		key.SetDwordValue(L"PaintDesktopVersion", 1);

		WXT::ReloadExplorer();

	}

	else if (options == 'd') {

		RegKey key{
			HKEY_CURRENT_USER,
			LR"(Control Panel\Desktop)"};

		key.SetDwordValue(L"PaintDesktopVersion", 0);

		WXT::ReloadExplorer();

	}
}
