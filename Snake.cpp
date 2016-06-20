#include <iostream>
#include <conio.h>
using namespace std;
bool gameover;
const int width=20;
const int height=20;
int tailX[1000];
int tailY[1000];
int nTail;
tailX[0]=x;
tailY[0]=y;
int x,y,fruitX,fruitY,score;
enum eDirectIon {STOP=0, LEFT ,RIGHT,UP, DOWN };
eDirectIon dir;
void setup()
	{
	gameover=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitX=rand()%width; 
	fruitY=rand()%height;
	}
void draw()
	{
		system("clear");
	for (int i = 0; i < width+2; ++i)
		{
			cout<<"#";
		}
	cout<<endl;
		for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width; ++j)
					{
						if (j==0)
							{
								cout<<"#";
							}
						if (i==y&&j==x)
						{
							cout<<char(254);
						}
						else if (i==fruitY&&j==fruitX)
						{
							cout<<"@";
						}
						else{
							bool print=false;
							for (int k = 0; k < nTail; ++k)
							{	
								
								if (tailX[k]==j&&tailY[k]==i)
									{
										print=true;
										cout<<char(254);						
									}	
							}
									if(!print)
											{
												cout<<" ";
											}

						cout<<endl;		
						if (j==width-1)
							{
								cout<<"#";
							}
						cout<<endl;

					}
			}
			for (int i = 0; i < width+2; ++i)
		{
			cout<<"#";
		}
	cout<<endl;
	cout<<"Score:"<<score<<endl;
	}
void input()
	{
	if (_kbhit())
	{
		switch(_getch())
		{
			case 'a':
			dir=LEFT;
			break;

			case 's':
			dir=DOWN;
			break;

			case 'w':
			dir=UP;
			break;

			case 'd':
			dir=RIGHT;
			break;

			case 'x':
			gameover=true;
			break;
		}
	}
	}
void logic()
{
	int prevx=tailX[0];
	int prevy=tailY[0];
	int prev2x,prev2y;
	for (int i = 1; i < nTail; ++i)
	{
		prev2x=tailX[i];
		prev2y=tailY[i];
		tailY[i]=prev2y;
		tailX[i]=prev2x;
		prevx=prev2x;
		prevy=prev2y;
	}
	switch(dir)
		{
			case LEFT:
				x--;
				break;
			case RIGHT:
				x++;
				break;
			case UP:
				y--;
				break;
			case DOWN:
				y++;
				break;
			default:
				break;
		}
	if (x>width||x<0||y>height||y<0)
		{
			gameover=true;
		}
	if (x==fruitX&&y==fruitY)
		{
			nTail++;
			score+=10;
			fruitX=rand()%width; 
			fruitY=rand()%height;
		}
} 

int main()
{
	setup();
	while(!gameover){
		draw();
		input();
		logic();
	}
	return 0;
}
