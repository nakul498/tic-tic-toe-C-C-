#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void winani(int arr[])
{
	if (arr[0] == arr[1] && arr[1] == arr[2])
	{   
		setcolor(RED);
		line(0, 50, 300, 50);
		setcolor(WHITE);
	}
	else if (arr[3] == arr[4] && arr[4] == arr[5])
	{
		setcolor(RED);
		line(0, 150, 300, 150);
		setcolor(WHITE);
	}
	else if (arr[6] == arr[7] && arr[7] == arr[8])
	{
		setcolor(RED);
		line(0, 250, 300, 250);
		setcolor(WHITE);
	}
	else if (arr[0] == arr[3] && arr[3] == arr[6])
	{
		setcolor(RED);
		line(50, 0, 50, 300);
		setcolor(WHITE);
	}
	else if (arr[1] == arr[4] && arr[4] == arr[7])
	{
		setcolor(RED);
		line(150, 0, 150, 300);
		setcolor(WHITE);
	}
	else if (arr[2] == arr[5] && arr[5] == arr[8])
	{
		setcolor(RED);
		line(250, 0, 250, 300);
		setcolor(WHITE);
	}
	else if (arr[0] == arr[4] && arr[4] == arr[8])
	{
		setcolor(RED);
		line(0, 0, 300, 300);
		setcolor(WHITE);
	}
	else if (arr[2] == arr[4] && arr[4] == arr[6])
	{
		setcolor(RED);
		line(300, 0, 0, 300);
		setcolor(WHITE);
	}
}
int main(void)
{
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;
	int counter, i, turn;
	char player1;
	int arr[8] = {0};
	void winani(int arr[]);

	/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

	/* read result of initialization */
	errorcode = graphresult();
	/* an error occurred */
	if (errorcode != grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}

	/* draw a diagonal line */
	rectangle(0, 0, 300, 300);

	//	line(100,0,100,300);

	//	line(200,0,200,300);

	line(0, 100, 300, 100);
	line(0, 200, 300, 200);
	line(100, 0, 100, 300);
	line(200, 0, 200, 300);
	outtextxy(90, 90, "1");
	outtextxy(190, 90, "2");
	outtextxy(290, 90, "3");
	outtextxy(90, 190, "4");
	outtextxy(190, 190, "5");
	outtextxy(290, 190, "6");
	outtextxy(90, 290, "7");
	outtextxy(190, 290, "8");
	outtextxy(290, 290, "9");

	outtextxy(390, 10, "What do you want to select??");
	outtextxy(390, 20, "Player 1");
	circle(410, 60, 22);
	line(440, 40, 480, 80);
	line(480, 40, 440, 80);
	outtextxy(390, 100, "Enter X or O ");
	scanf("%c", &player1);

	if (player1 == 'x' || player1 == 'X')
	{
		counter = 1;
	}
	else
	{
		counter = 0;
	}

	for (i = 0; i < 9; i++)
	{
		if (counter % 2 == 1)
		{
			//removing previous
			setcolor(BLACK);
			outtextxy(390, 120, "Circle's turn");
			setcolor(WHITE);
			//

			outtextxy(390, 120, "Cross's turn");
		ab:
			scanf("%d", &turn);
			turn--;
			if (arr[turn] == 1 || arr[turn] == 5 || turn > 8 || turn < 0)
			{
				outtextxy(400, 200, "Not a valid move...");
				delay(1000);
				setcolor(BLACK);
				outtextxy(400, 200, "Not a valid move...");
				setcolor(WHITE);
				goto ab;
			}
			switch (turn)
			{
			case 0:
			{
				line(100, 100, 0, 0);
				line(100, 0, 0, 100);
				counter++;
				arr[turn] = 5;
				break;
			}
			case 1:
			{
				line(100, 100, 200, 0);
				line(200, 100, 100, 0);
				counter++;
				arr[turn] = 5;
				break;
			}
			case 2:
			{
				line(300, 100, 200, 0);
				line(200, 100, 300, 0);
				counter++;
				arr[turn] = 5;
				break;
			}
			case 3:
			{
				line(100, 200, 0, 100);
				line(100, 100, 0, 200);
				counter++;
				arr[turn] = 5;
				break;
			}
			case 4:
			{

				line(100, 200, 200, 100);
				line(100, 100, 200, 200);
				counter++;
				arr[turn] = 5;
				break;
			}
			case 5:
			{
				line(200, 200, 300, 100);
				line(300, 200, 200, 100);
				counter++;
				arr[turn] = 5;
				break;
			}
			case 6:
			{
				line(100, 200, 0, 300);
				line(100, 300, 0, 200);
				counter++;
				arr[turn] = 5;
				break;
			}
			case 7:
			{
				line(100, 200, 200, 300);
				line(200, 200, 100, 300);
				counter++;
				arr[turn] = 5;
				break;
			}
			case 8:
			{
				line(200, 200, 300, 300);
				line(200, 300, 300, 200);
				counter++;
				arr[turn] = 5;
				break;
			}
			}

			if (((arr[0] + arr[1] + arr[2]) == 15) || ((arr[3] + arr[4] + arr[5]) == 15) || ((arr[6] + arr[7] + arr[8]) == 15) || ((arr[0] + arr[3] + arr[6]) == 15) || ((arr[1] + arr[4] + arr[7]) == 15) || ((arr[2] + arr[5] + arr[8]) == 15) || ((arr[0] + arr[4] + arr[8]) == 15) || ((arr[2] + arr[4] + arr[6]) == 15))
			{
				winani(arr);
				outtextxy(400, 200, "Cross Wins...");
				delay(5000);
				outtextxy(400, 220, "Press Any Key to exit....");
				break;
			}
		}
		else
		{

			rectangle(385, 115, 500, 135);
			//removing previous
			setcolor(BLACK);
			outtextxy(390, 120, "Cross's turn");
			setcolor(WHITE);
			//
			outtextxy(390, 120, "Circle's turn");

		xy:
			scanf("%d", &turn);
			turn--;
			if (arr[turn] == 1 || arr[turn] == 5 || turn > 8 || turn < 0)
			{
				outtextxy(400, 200, "Not a valid move...");
				delay(1000);
				setcolor(BLACK);
				outtextxy(400, 200, "Not a valid move...");
				setcolor(WHITE);
				goto xy;
			}
			switch (turn)
			{
			case 0:
			{
				circle(50, 50, 50);
				counter++;
				arr[turn] = 1;
				break;
			}
			case 1:
			{
				circle(150, 50, 50);
				counter++;
				arr[turn] = 1;
				break;
			}
			case 2:
			{
				circle(250, 50, 50);
				counter++;
				arr[turn] = 1;
				break;
			}
			case 3:
			{
				circle(50, 150, 50);
				counter++;
				arr[turn] = 1;
				break;
			}
			case 4:
			{
				circle(150, 150, 50);
				counter++;
				arr[turn] = 1;
				break;
			}
			case 5:
			{
				circle(250, 150, 50);
				counter++;
				arr[turn] = 1;
				break;
			}
			case 6:
			{
				circle(50, 250, 50);
				counter++;
				arr[turn] = 1;
				break;
			}
			case 7:
			{
				circle(150, 250, 50);
				counter++;
				arr[turn] = 1;
				break;
			}
			case 8:
			{
				circle(250, 250, 50);
				counter++;
				arr[turn] = 1;
				break;
			}
			}

			if (((arr[0] + arr[1] + arr[2]) == 3) || ((arr[3] + arr[4] + arr[5]) == 3) || ((arr[6] + arr[7] + arr[8]) == 3) || ((arr[0] + arr[3] + arr[6]) == 3) || ((arr[1] + arr[4] + arr[7]) == 3) || ((arr[2] + arr[5] + arr[8]) == 3) || ((arr[0] + arr[4] + arr[8]) == 3) || ((arr[2] + arr[4] + arr[6]) == 3))
			{
				winani(arr);
				outtextxy(400, 200, "Circle Wins...");
				delay(5000);
				cleardevice();
				outtextxy(400, 220, "Press Any Key to exit....");

				break;
			}
		}
	}

	getch();
	return 0;
}