#pragma once
#include <iostream>
#include <string>

using namespace std;

class Tweaks {
public:

	//Tweak Handler
	void Tweak_Handler(string name,char EnableOrDisable);

	//Enable/Disable Seconds in System Clock
	void Toggle_Seconds_System_Clock(char options = 'e');

	//Increase taskbar transparency
	void UseOLEDTaskbarTransparency(char options = 'e');

	//Makes the lockscreen image a solid color
	void LockScreen_Solid_Background(char options = 'e');

	//Removes the little arrow from shortcuts
	void No_Shortcut_Arrows(char options = 'e');

	//Restores Windows 7 Volume Control UI
	void UseWindows7VolumeUI(char options = 'e');
    
	//Enabels hidden page in Setting
	void EnableHiddenSettingsMenu(char options = 'e');

	//Removes Onedrive from Explorer
	void RemoveOnedriveFromExplorer(char options = 'e');

	//Paints Windows Version on the desktop
	void PaintDesktopVersion(char options = 'e');
};