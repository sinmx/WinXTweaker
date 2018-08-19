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
CI::CI(string redirect) {
	if (redirect == "StartupInterface") {
		StartupInterface();
	}
	else if (redirect == "UITweakInterface") {
		UIInterface();
	}
	
}




///////////////////////////////////////
//            Interfaces             //
///////////////////////////////////////

void CI::StartupInterface()
{
	//Visible part//
	
	//Color's the output
	SetConsoleTextAttribute(hConsole, 4);

	/*Colors the text*/
	SetConsoleTextAttribute(hConsole, 2);
	
	cout <<  "____________________________________________________________________________ " << endl;
	cout << "|                             WinXTweaker                                    |" << endl;
	cout << "|                             Version 0.2                                    |" << endl;
	cout << "|                             Licence: MIT                                   |" << endl;
	cout << "|____________________________________________________________________________|" << endl << endl << endl;

	SetConsoleTextAttribute(hConsole, 3);
	cout << " ________________________________________ " << endl;
	cout << "|               ";

	//changing box title color
	SetConsoleTextAttribute(hConsole, 7);
	cout << "Main Menu";
	
	SetConsoleTextAttribute(hConsole, 3);
	cout << "               |" << endl;
	cout << "| 0: Exit WXT                           |" << endl;
	cout << "| 1: UI Tweaks Menu                     |" << endl;
	cout << "|_______________________________________|" << endl << endl;



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

	//Visible part
	SetConsoleTextAttribute(hConsole, 2);
	
	cout <<  "____________________________________________________________________________" << endl;
	cout << "|                             WinXTweaker                                    |" << endl;
	cout << "|                             Version 0.2                                    |" << endl;
	cout << "|                             Licence: MIT                                   |" << endl;
	cout << "|____________________________________________________________________________|" << endl << endl << endl;


	SetConsoleTextAttribute(hConsole, 3);
	cout << " ____________________________________________________________ " << endl;
	cout << "|                       ";

	//Setting menu title color
	SetConsoleTextAttribute(hConsole, 7);
	cout << "UI Tweaks Menu";

	SetConsoleTextAttribute(hConsole, 3);
	cout << "                      |" << endl;

	cout << "| E: Exit WXT                                               |" << endl;
	cout << "| 0: Return to Main Menu                                    |" << endl;
	cout << "| 1: View or Hide seconds in System clock                   |" << endl;
	cout << "| 2: Increase Taskbar Transparency Level                    |" << endl;
	cout << "| 3: Change the Windows 10 logon screen to a solid color    |" << endl;
	cout << "| 4: Remove Shortcut Arrow                                  |" << endl;
	cout << "| 5: Restore old Windows 7 volume control UI                |" << endl;
	cout << "| 6: Show hidden 'Samples' page in Setings                  |" << endl;
	cout << "| 7: Remove Onedrive from Explorer                          |" << endl;
	cout << "| 8: Paint Windows version on the Desktop                   |" << endl;
	cout << "|___________________________________________________________|" << endl << endl << endl;



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
	case '4':{
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
		else {
			Tweak_Status = "Disabled";
		}

		GTweakInterface("No_Shortcut_Arrows", Tweak_Status);
		break;
	}
	case '5': {
		//Restore Windows 7 Volume control UI

		//Opens needded key
		RegKey key{
			HKEY_LOCAL_MACHINE,
			LR"(SOFTWARE\Microsoft\WindowsNT\CurrentVersion\)"
		};

		//Creates new key
		key.Create(HKEY_LOCAL_MACHINE, LR"(SOFTWARE\Microsoft\Windows NT\CurrentVersion\MTCUVC)", KEY_ALL_ACCESS);

		//Gets the value of the DWORD DisableLogonBackgroundImage
		DWORD dwor = key.GetDwordValue(L"EnableMtcUvc");

		//Creates a new DWORD if it doesn't already exist
		if (dwor == 2) {

			//Creates a new key called EnableMtcUvc if it doesn't already exist
			key.SetDwordValue(L"EnableMtcUvc", 1);

			dwor = 1;
		}



		//Sets status according to the DWORD(dw) value
		if (dwor == 1) {
			Tweak_Status = "Disabled";
		}
		else if (dwor == 0) {
			Tweak_Status = "Enabled";
		}
		GTweakInterface("UseWindows7VolumeUI", Tweak_Status);

		break;
	 }

	case '6':
		//Enable hidden settings page
	{
		//Opens needded key
		RegKey key{
			HKEY_CURRENT_USER,
			LR"(Control Panel)"
		};

		//Gets the value of "EnableSamplesPage"
		DWORD dwor = key.GetDwordValue(L"EnableSamplesPage");
		
		//Creates value if it doesn't already exists
		if (dwor == 2) {
			key.SetDwordValue(L"EnableSamplesPage", 0);
			dwor = 0;
		}

		//Sets Tweak_Status according to the dwor DWORD
		

		if (dwor == 0) {
			Tweak_Status = "Disabled";
		}
		else if (dwor == 1) {
			Tweak_Status = "Enabled";
		}

		
		//Calls GTweakInterface
		GTweakInterface("EnableHiddenSettingsMenu", Tweak_Status);

		break;
	}
	case '7':{

		//Opens needded key
		RegKey key{
			HKEY_CLASSES_ROOT,
			LR"(CLSID\{018D5C66-4533-4307-9B53-224DE2ED1FE6})"
		};

		//Gets the value of "System.IsPinnedToNameSpaceTree"
		DWORD dwor = key.GetDwordValue(L"System.IsPinnedToNameSpaceTree");

		//Sets Tweak_Status according to the dwor DWORD
		if (dwor == 1) {
			Tweak_Status = "Disabled";
		}
		else if (dwor == 0) {
			Tweak_Status = "Enabled";
		}

		//Calls GTweakInterface
		GTweakInterface("RemoveOnedriveFromExplorer", Tweak_Status);

		break;
	}
	case '8': {
		//Opens needded key
		RegKey key{
			HKEY_CURRENT_USER,
			LR"(Control Panel\Desktop)"
		};

		//Gets value of "PaintDesktopVersion"
		DWORD dwor = key.GetDwordValue(L"PaintDesktopVersion");

		//Sets Tweak_Status according to the dwor DWORD
		if (dwor == 0) {
			Tweak_Status = "Disabled";
		}
		else if (dwor == 1) {
			Tweak_Status = "Enabled";
		}

		//Calls GTweakInterface
		GTweakInterface("PaintDesktopVersion", Tweak_Status);

	}


    }
}

//A lot of parameters eh ;-),but I assure you it's handy!
void CI::GTweakInterface(string name,string status,char EnabelExtraComments,string ExtraComments)
{
	
	//Visible Stuff
	system("CLS");

	SetConsoleTextAttribute(hConsole, 2);

	cout << "____________________________________________________________________________ " << endl;
	cout << "|                             WinXTweaker                                    |" << endl;
	cout << "|                             Version 0.2                                    |" << endl;
	cout << "|                             Licence: MIT                                   |" << endl;
	cout << "|____________________________________________________________________________|" << endl << endl << endl;

	SetConsoleTextAttribute(hConsole, 6);

	cout << " ________________________________________ " << endl;;
	cout << "|    " << name << endl;
	cout << "|________________________________________|" << endl;;
	
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
	cout << "|Please enter your choice(y/n):";
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


