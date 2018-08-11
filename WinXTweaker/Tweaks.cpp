#include "stdafx.h"
#include "Tweaks.h"
//Thanks to Giovanni Dicanio for his library!
#include "Library/WinReg.hpp"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
using namespace winreg;

//Tweak Handler!IMPORTANT!,Info in README
//The EnableOrDisable char can have these values('e'=enabel,'d'=disabel)
void Tweaks::Tweak_Handler(string name,char EnableOrDisable) {
	//I had a strange error, so I added this line
	
    
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
	//Put here your if - else statements
	//else if
}











//Tweaks
void Tweaks::Toggle_Seconds_System_Clock(char options)
{
	if (options == 'e') {
		RegKey key{
			HKEY_CURRENT_USER,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced)" };
		key.SetDwordValue(L"ShowSecondsInSystemClock", 1);
	}
	else if (options == 'd') {
		RegKey key{
			HKEY_CURRENT_USER,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced)" };
		key.SetDwordValue(L"ShowSecondsInSystemClock", 0);
	}
	
}

