////////////////////////////
//Header files & Libraries//
////////////////////////////

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


//////////////
//Namespaces//
//////////////

using namespace std;
using namespace winreg;

////////////////
//Allows color//
////////////////

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


////////////////////////
//Special Functions   //
////////////////////////

//Ctor starts Startupinterface
CI::CI() {
	StartupInterface();
}




///////////////////////////////////////
//            Interfaces             //
///////////////////////////////////////

void CI::StartupInterface()
{
	//Visible part//
	
	//Color's the output
	SetConsoleTextAttribute(hConsole, 4);

	cout << "///////////////////////////////////////////////////" << endl;
	cout << "// WinXTweaker" << endl << "//" << endl;
	cout << "// Version 0.2 " << endl << "//" << endl;
	cout << "// Licence: MIT" << endl << "//" << endl;
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

		//Exit's the application 
		exit(0);

		break;


	case 1:

		//Displays the UI Tweaks Menu
		UIInterface();

		break;
	}
	

}


void CI::UIInterface() {
	
	//Does what it says
	system("CLS");

	//Visible part//

	SetConsoleTextAttribute(hConsole, 4);

	cout << "///////////////////////////////////////////////////" << endl;
	cout << "// WinXTweaker" << endl << "//" << endl;
	cout << "// Version 0.2" << endl << "//" << endl;
	cout << "// Licence: MIT" << endl << "//" << endl;
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
	cout << "| 4: Remove arrows from shortcuts                                 |" << endl;
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

		//Calls the main menu
		StartupInterface();

		break;

	case '1':
	{
		//Show Seconds In System Clock

		//Opens the key
		RegKey key{
			HKEY_CURRENT_USER,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced)"
		};

		//Gets the value of the DWORD "ShowSecondsInSystemClock"
		DWORD dwor = key.GetDwordValue(L"ShowSecondsInSystemClock");

		//Creates the DWORD if it doesn't already exists
		if (dwor == 2) {

			//Creates a new DWORD called "ShowSecondsInSystemClock and set's it value to 0
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
		

		//Calls GTweakInterface without extra comments
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

		//Gets the value of the DWORD "Use OLEDTaskbarTransparency,if exists
		DWORD dwor = key.GetDwordValue(L"UseOLEDTaskbarTransparency");
		
		//Creates the value if it doesn't already exist
		if (dwor == 2) {

			//Creates a new DWORD called Use OLED TaskbarTransparency and sets it's value to 0
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
		

		//Calls GTweakInterface
		GTweakInterface("UseOLEDTaskbarTransparency", Tweak_Status);

		break;
	}

	case '3':
	{
		//Sets Windows Logon Screen Image to a solid color

		//Opens the needded key
		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Policies\Microsoft\Windows\System)"
		};

		//Gets the value of the DWORD DisableLogonBackgroundImage
		DWORD dwor = key.GetDwordValue(L"DisableLogonBackgroundImage");

		//Creates a new DWORD if it doesn't already exist
		if (dwor == 2) {

			//Creates a new key called DisableLogonBackgroundImage if it doesn't already exist
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
		

		//Calls GTweakInterface with comments
		GTweakInterface("LockScreen_Solid_Background", Tweak_Status,'y',"Changes the LockScreen image(only at the screen were you put your password in) to the system color.");

		break;
	}
	case '4':
		//Remove arrows from shortcuts

		//Opens the needded key
		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer)"
		};

		//Creates a new key

		key.Create(HKEY_LOCAL_MACHINE, LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Icons)", KEY_ALL_ACCESS);

		//Reading from a string is different
		RegKey key1{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Icons)"
		};

		//Get's the value of the string
		wstring wstr = key1.GetStringValue(L"29");

		//Code runs if string doesn't exist
		if (wstr == L"ERROR") {
			wstr = L"NOT";
         }

		if (wstr == L"") {
			Tweak_Status = "Enabled";
			
		}
		else{
			Tweak_Status = "Disabled";
		}
		
		GTweakInterface("No_Shortcut_Arrows", Tweak_Status);
		break;
		
	}
}

//A lot of parameters eh ;-),but I assure you it's handy!
void CI::GTweakInterface(string name,string status,char EnabelExtraComments,string ExtraComments)
{
	
	//Visible Stuff
	system("CLS");

	SetConsoleTextAttribute(hConsole, 4);

	cout << "///////////////////////////////////////////////////" << endl;
	cout << "// WinXTweaker" << endl << "//" << endl;
	cout << "// Version 0.2" << endl << "//" << endl;
	cout << "// Licence: MIT" << endl << "//" << endl;
	cout << "///////////////////////////////////////////////////" << endl << endl << endl;
	
	SetConsoleTextAttribute(hConsole, 6);

	cout << "|----------------------------------------|" << endl;;
	cout << "|    " << name << endl;
	cout << "|----------------------------------------|" << endl;;
	
	SetConsoleTextAttribute(hConsole, 11);

	cout << "|Status:";

	//Colors status
	if (status == "Enabled") {
		
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
	if (status == "Enabled") {

		cout << endl << "|Do you want to disable the " << name << " tweak?" << endl;
	}
	else if (status == "Disabled") {

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
		if (status == "Enabled") {

			Tweaks Tweaks;
			Tweaks.Tweak_Handler(name, 'd');

			system("CLS");

			UIInterface();

			break;
		}
		else {

			Tweaks Tweaks;
			Tweaks.Tweak_Handler(name, 'e');

			system("CLS");
			UIInterface();

			break;
		}

	case 'n':

		UIInterface();

		break;
	}
	
}


