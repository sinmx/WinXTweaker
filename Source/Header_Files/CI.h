#pragma once
#include "Library/WinReg.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace winreg;

class CI {
private: 
	
	string Tweak_Status;
	DWORD dwor;
public:
	CI();
	
	void StartupInterface();
	void UIInterface();
	void GTweakInterface(string name, string status,char EnableComments ='n', string ExtraComments ="null");

	//Special Interfaces
	
};