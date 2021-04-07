#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <sys/time.h>

struct timeval t[500];
int delay[500];

void Retracer(POINT* mousePos, int noOfSaves)
{
	std::cout << "DO NOT MOVE/CLICK THE MOUSE NOW!\nStarting after 2 seconds...\n" << std::endl;
	Sleep(2000);

	for (int i = 0; i < noOfSaves; i++)
	{
		delay[i] = t[i + 1].tv_sec * 1000 + t[i + 1].tv_usec / 1000 - t[i].tv_sec * 1000 - t[i].tv_usec / 1000;
		SetCursorPos(mousePos[i].x, mousePos[i].y);

		mouse_event(MOUSEEVENTF_LEFTDOWN, mousePos[i].x, mousePos[i].y, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, mousePos[i].x, mousePos[i].y, 0, 0);

		std::cout << i + 1 << "th save clicked!\n";
		Sleep(delay[i]);
	}
}

int Saver(POINT* mousePos)
{
	std::cout << "Hover the mouse to the desired location and \n press 'k' to start saving mouse positions.\n";
	std::cout << "\nPress 'k' to start saving mouse locations and 'q' to STOP!" << std::endl;

	bool quit = true;
	int noOfSaves = 0;
	int i = 0;

	while (quit)
	{
		if (_kbhit())
		{
			char kbKey = _getch();
			if (kbKey == 'k')
			{
    			gettimeofday(&t[i], NULL);
				i++;
				GetCursorPos(&mousePos[noOfSaves]);
				std::cout << noOfSaves + 1 << " positions saved...\n";
				noOfSaves++;
			}
			if (kbKey == 'q')
				quit = false;
		}
	}
	t[i] = t[i - 1];

	return noOfSaves;
}

int main(int argc, char* argv[])
{	
	char repeat;

	while (true)
	{
		POINT mousePos[500];

		Retracer(mousePos, Saver(mousePos));

		std::cout << "\n\nDo this again? (y/n)\n";
		std::cin >> repeat;

		switch (repeat)
		{
		case 'y':
			system("cls");
			break;
		case 'Y':
			system("cls");
			break;
		default:
			return 0;
		}
	}


	return 0;
}