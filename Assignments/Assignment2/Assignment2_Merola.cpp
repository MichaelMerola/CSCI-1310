#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;


void playGame()
{
	int input;
	int winChance;

	while (input != 3)
	{
		cout<<("Adventure! Choose an option: \n1. Fight the Dragon \n2. Save the Princess \n3. Go Home")<<endl;
        cin>>input;

		if (input == 1)
		{
            winChance = rand()%2+1 ;
            if (winChance == 1)
                cout<<"You win!"<<endl;
            else if (winChance == 2)
            {
                cout<<"You lost!"<<endl;
                input = 3;
            }

		}
		else if (input == 2)
			cout<<"You saved the princess!"<<endl;

		else if (input == 3)
			cout<<"Wimp!"<<endl;
	}

    cout<<endl;
	cout<<"Game Over"<<endl;
}


void convertSeconds(int cTime)
{
	int minutes;
	int hours;
	int seconds;
	int rem;

	hours = cTime/3600;
	rem = cTime%3600;

	if (rem >= 60){
		minutes = rem/60;
		seconds = rem%60;
	}
	else
		seconds = rem;

	cout<<"The time is " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds!"<<endl;

    cout<<endl;
}

void solveMaze(int maze[4][4])
{
    int posX = 0;
    int posY = 3;

    int appX = 3;
    int appY = 0;

    while (maze[posY][posX] != 2)
    {
        if ((posY != appY) && (maze[(posY - 1)][posX] != 1))
        {
            cout << "Move up"<<endl ;
            posY -= 1 ;
        }
        else if ((posX != appX) && (maze[posY][(posX + 1)] != 1))
        {
            cout << "Move right"<<endl ;
            posX += 1 ;
        }
    }

     cout << "The horse gets the yummy apple!"<<endl;
}


int main()
{
    int currentTime ;

	cout<<("Enter time in seconds between 0 and 86400")<<endl;
	cin>>currentTime ;
	cin.ignore();

	convertSeconds(currentTime);

	playGame();

	cout<<endl;

    int maze[4][4] =
    {

    {1,1,0,2},
    {0,0,0,1},
    {0,1,0,1},
    {0,0,0,1}

    };

 solveMaze(maze);

    return 0;
}



