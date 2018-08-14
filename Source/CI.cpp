#include "stdafx.h"
#include "Header_Files/CI.h"
#include "Header_Files/WXT.h"
#include "Header_Files/Tweaks.h"
#include "Library/WinReg.hpp"
#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <cstdarg>
#include <winreg.h>

using namespace std;
using namespace winreg;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//Ctor starts Startupinterface
CI::CI() {
	StartupInterface();
}
void CI::ClearScreen()
{
	system("CLS");
}

//Interfaces

void CI::StartupInterface()
{
	//Visible part

	/*Colors the text*/SetConsoleTextAttribute(hConsole, 4);
	cout << "///////////////////////////////////////////////////" << endl;
	cout << "// WinXTweaker" << endl << "//" << endl;
	cout << "// Version 0.1 ALPHA" << endl << "//" << endl;
	cout << "// Licence: GPL" << endl << "//" << endl;
	cout << "///////////////////////////////////////////////////" << endl << endl << endl;

	SetConsoleTextAttribute(hConsole, 6);
	cout << "-----------------------------------------" << endl;
	cout << "|               Main Menu               |"<< endl;
	cout << "-----------------------------------------" << endl;
	cout << "| 0: Exit                               |" << endl;
    cout << "| 1: UI Tweaks                          |" << endl;
	cout << "|---------------------------------------|" << endl << endl;

	//Integer to store choice
	int Choice;

	//Gets choice 
	
	cout << "|Please enter your choice:";
	
	cin >> Choice;
	
	cout << endl;

	//Handles choice
	switch (Choice) {
		//Triggers if user wants to exit
	case 0:
		//stdlib.h
		exit(0);
		break;
	case 1:
		//Calls UI Tweaks Menu
		UIInterface();
		break;
	}
	

}

void CI::UIInterface() {
	//First of all we are gonna clear the screen
	//Yeah I know system() is sh*t but I like to make my code readable 
	system("CLS");

	//Visible part
	SetConsoleTextAttribute(hConsole, 4);
	cout << "///////////////////////////////////////////////////" << endl;
	cout << "// WinXTweaker" << endl << "//" << endl;
	cout << "// Version 0.1 ALPHA" << endl << "//" << endl;
	cout << "// Licence: GPL" << endl << "//" << endl;
	cout << "///////////////////////////////////////////////////" << endl << endl << endl;


	SetConsoleTextAttribute(hConsole, 6);
	cout << "-------------------------------------------------------------------" << endl;
	cout << "|                         UI Tweaks                               |" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "| E: Exit WXT                                                     |" << endl;
	cout << "| 0: Return to Main Menu                                          |" << endl;
	cout << "| 1: View or Hide seconds in System clock                         |" << endl;
	cout << "| 2: Increase Taskbar Transparency Level                          |" << endl;
	cout << "| 3: Change the Windows 10 logon screen to a solid color          |" << endl;
	cout << "|-----------------------------------------------------------------|" << endl << endl;

	//Integer to store choice
	char Choice;

	//Get choice
	cout << "|Please enter your choice:";
	cin >> Choice;
	cout << endl;

	//Handles Choice
	switch (Choice) {
	case 'E':
		exit(0);
		break;

	case '0':
		system("CLS");
		StartupInterface();
		break;

	case '1':
	{
		//Show Seconds In System Clock
		//Check if tweak is already enabled(getting the DWORD value from the registry),Winreg library <3

		RegKey key{
			HKEY_CURRENT_USER,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced)"
		};
		DWORD dwor = key.GetDwordValue(L"ShowSecondsInSystemClock");

		//Creates the value if it doesn't already exists
		if (dwor == 2) {
			key.SetDwordValue(L"ShowSecondsInSystemClock", 0);
			dwor = 0;
		}



		//Sets status according to the DWORD(dw) value
		if (dwor == 0) {
			Tweak_Status = "Disabled";
		}
		else if (dwor == 1) {
			Tweak_Status = "Enabled";
		}
		else {
			throw "An error occured while reading the registry key.";
		}

		//Calls GTweakInterface,extra comments are not required so not given
		GTweakInterface("Toggle_Seconds_System_Clock", Tweak_Status);
	}
	break;

	case '2':
	{
		//Increase Taskbar transparency
		//Check if tweak is already enabled(getting the DWORD value from the registry),Winreg library <3

		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced)"
		};

		DWORD dwor = key.GetDwordValue(L"UseOLEDTaskbarTransparency");
		
		//Creates the value if it doesn't already exist
		if (dwor == 2) {
			key.SetDwordValue(L"UseOLEDTaskbarTransparency", 0);
			dwor = 0;
		}



		//Sets status according to the DWORD(dw) value
		if (dwor == 0) {
			Tweak_Status = "Disabled";
		}
		else if (dwor == 1) {
			Tweak_Status = "Enabled";
		}
		else {
			throw "An error occured while reading the registry key.";
		}

		//Calls GTweakInterface,extra comments are not required so not given
		GTweakInterface("UseOLEDTaskbarTransparency", Tweak_Status);
		break;
	}
	case '3':
	{
		//Sets Windows Logon Screen Image to a solid color
		//Check if tweak is already enabled(getting the DWORD value from the registry),Winreg library <3

		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Policies\Microsoft\Windows\System)"
		};

		DWORD dwor = key.GetDwordValue(L"DisableLogonBackgroundImage");
		cout << dwor;
		if (dwor == 2) {
			key.SetDwordValue(L"DisableLogonBackgroundImage", 0);
			dwor = 0;
		}



		//Sets status according to the DWORD(dw) value
		if (dwor == 0) {
			Tweak_Status = "Disabled";
		}
		else if (dwor == 1) {
			Tweak_Status = "Enabled";
		}
		else {
			throw "An error occured while reading the registry key.";
		}

		//Calls GTweakInterface,extra comments are not required so not given
		GTweakInterface("LockScreen_Solid_Background", Tweak_Status,'y',"Changes the LockScreen image(only at the screen were you put your password in) to the system color.");
		break;
	}

	}
}

//A lot of parameters eh ;-),but I assure you it's handy!
void CI::GTweakInterface(string name,string status,char EnabelExtraComments,string ExtraComments)
{
	//Convert status to new string
	string TweakInterfaceStatus = status;
	//Visible Stuff
	system("CLS");

	SetConsoleTextAttribute(hConsole, 4);
	cout << "///////////////////////////////////////////////////" << endl;
	cout << "// WinXTweaker" << endl << "//" << endl;
	cout << "// Version 0.1 ALPHA" << endl << "//" << endl;
	cout << "// Licence: GPL" << endl << "//" << endl;
	cout << "///////////////////////////////////////////////////" << endl << endl << endl;
	
	SetConsoleTextAttribute(hConsole, 6);
	cout << "|----------------------------------------|" << endl;;
	cout << "|    " << name << endl;
	cout << "|----------------------------------------|" << endl;;
	
	SetConsoleTextAttribute(hConsole, 11);
	cout << "|Status:";
	//Colors status
	if (status == "Enabled") {
		//green
		SetConsoleTextAttribute(hConsole, 10);
		cout << status << endl;
		SetConsoleTextAttribute(hConsole, 11);
	}
	else {
		SetConsoleTextAttribute(hConsole, 12);
			cout << status << endl;
		SetConsoleTextAttribute(hConsole, 11);
	}

	if (EnabelExtraComments == 'y'){
		SetConsoleTextAttribute(hConsole, 12);
		cout << endl << "|ExtraComments:" << endl;
		cout << ExtraComments << endl;
		SetConsoleTextAttribute(hConsole, 11);
	}
	if (TweakInterfaceStatus == "Enabled") {
		cout << endl << "|Do you want to disable the " << name << " tweak?" << endl;
	}
	else if (TweakInterfaceStatus == "Disabled") {
		cout << endl << "|Do you want to enable the " << name << " tweak?" << endl;
	}
	

	//char to store choice
	char choice;
	
	//Asks choice
	cout << "|Please enter your choice(y,n):";
	cin >> choice;
	cout << endl;

	//Handles choice
	switch (choice) {
	case 'y':
		if (TweakInterfaceStatus == "Enabled") {
			Tweaks Tweaks;
			Tweaks.Tweak_Handler(name, 'd');
			UIInterface();
			break;
		}
		else {
			Tweaks Tweaks;
			Tweaks.Tweak_Handler(name, 'e');
			UIInterface();
			break;
		}
	case 'n':
		UIInterface();
		break;
	}
	
}


