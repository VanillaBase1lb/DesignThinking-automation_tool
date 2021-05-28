#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <sys/time.h>
#include <winuser.h>

struct timeval t[1000];
int delay;
int noOfRuns;
int noOfSaves;

void Retracer(POINT* mousePos, int noOfSaves)
{
	for (int i = 0; i < noOfSaves; i++)
	{
        if(GetKeyState(VK_F8) & 0x8000) // check if F8 is pressed
        {
            exit(0);
        }
        SetCursorPos(mousePos[i].x, mousePos[i].y);

		mouse_event(MOUSEEVENTF_LEFTDOWN, mousePos[i].x, mousePos[i].y, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, mousePos[i].x, mousePos[i].y, 0, 0);

		std::cout << i + 1 << "th save clicked!\n";
		Sleep(delay);
	}
}

int Saver(POINT* mousePos)
{
    if (RegisterHotKey(NULL, 1, 0, 0xC0) && RegisterHotKey(NULL, 2, 0, 0x76))
    // 0xC0 = `
    // 0x76 = F7
    {
	    std::cout << "Hover the mouse to the desired location and \n press ~ (tilde button below Esc) to start saving mouse positions.\n";
	    std::cout << "\nPress ~ to start saving mouse locations and 'F7' to STOP!" << std::endl;
    }
    
	bool quit = true;
	int noOfSaves = 0;
	int i = 0;
    MSG msg = {0};

    while (quit)
	{
        if (GetMessage(&msg, NULL, 0, 0) == 0)
        {
            std::cout << "get message error" << std::endl;
        }
        if (msg.message == WM_HOTKEY && msg.wParam == 1)
		{
    		gettimeofday(&t[i], NULL);
			i++;
			GetCursorPos(&mousePos[noOfSaves]);
			std::cout << noOfSaves + 1 << " positions saved...\n";
			noOfSaves++;
		}
		if (msg.message == WM_HOTKEY && msg.wParam == 2)
		{
			quit = false;
			gettimeofday(&t[i], NULL);
			i++;
		}
	}
	t[i] = t[i - 1];

	return noOfSaves;
}

int main(int argc, char* argv[])
{	

	std::cout << "Enter the number of cycles to execute \n";
	std::cin >> noOfRuns;
    
    std::cout << "Enter the time between 2 clicks in miliseconds \n";
	std::cin >> delay;
	
	POINT mousePos[1000];
	int noOfSaves = Saver(mousePos);
	
	std::cout << "DO NOT MOVE/CLICK THE MOUSE NOW!\nStarting after 2 seconds...\n" << std::endl;
	Sleep(2000);
	
	for (int i = 0; i < noOfRuns; i++)
	{
		Retracer(mousePos, noOfSaves);
		std::cout << i + 1 << "th cycle completed\n\n";
	}


	return 0;
}