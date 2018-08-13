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
};