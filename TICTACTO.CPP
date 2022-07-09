# include <iostream.h>
# include <stdio.h>
# include <conio.h>

char pos[9];
//char p[10],pnm1[10],pnm2[10];
int p=1;

void upd(int c);
void prnt();
void check();
void gameover();
void main()
{
	int choice,i;
	clrscr();

	/*cout << "Player 1: ";
	cin >> pnm1;
	cout << "Player 2: ";
	cin >> pnm2;   */

	p = 1;

	do
	{       clrscr();

		prnt();
		check();

		cout << "Enter choice-\n\n\tP - " << p << ": ";
		cin >> choice;

		if(choice >= 1 && choice <= 9)
		{   	upd(choice-1);
		}
		else if(choice == 0)
		     {		break;
		     }
		     else
		     {		cout << "\n\tInvalid choice !!!";
				getch();
		     }
	}
	while(choice != 0);

}

void prnt()
{
	cout << "\t\tTic Tac Toi\n\n\t";
	cout << "P - " << "1" << "(x)  :  P - " << "2" << "(0)\n\n\n\n\t\t\t";

	cout << "    |     |   \n\t\t\t";
	cout << " " << pos[0] << "  |  " << pos[1] <<  "  |  "<< pos[2] << " \n\t\t\t";
	cout << " -  |  -  |  - \n\t\t\t";

	cout << " " << pos[3] << "  |  " << pos[4] <<  "  |  "<< pos[5] << " \n\t\t\t";
	cout << " -  |  -  |  - \n\t\t\t";

	cout << " " << pos[6] << "  |  " << pos[7] <<  "  |  "<< pos[8] << " \n\t\t\t";
	cout << "    |     |    \n\n\n";
}

void upd(int c)
{       char val;
	if(pos[c] != NULL)
	{	cout << "Choice is filled out!";
		getch();
	}
	else
	{       val=(p==1) ?'x' :'0';
		pos[c] = val;
		p=(p==1) ?2 :1;
	}
}

void check()
{       if(pos[0]==pos[1] && pos[1] == pos[2] && pos[2] != NULL)
		gameover();

	else if(pos[3]==pos[4] && pos[4] == pos[5] && pos[5] != NULL)
		gameover();

	else if(pos[6]==pos[7] && pos[7] == pos[8] && pos[8] != NULL)
		gameover();

	else if(pos[0]==pos[3] && pos[3] == pos[6] && pos[6] != NULL)
		gameover();

	else if(pos[1]==pos[4] && pos[4] == pos[7] && pos[7] != NULL)
		gameover();

	else if(pos[2]==pos[5] && pos[5] == pos[8] && pos[8] != NULL)
		gameover();

	else if(pos[0]==pos[4] && pos[4] == pos[8] && pos[8] != NULL)
		gameover();

	else if(pos[2]==pos[4] && pos[4] == pos[6] && pos[6] != NULL)
		gameover();
}

void gameover()
{       int i;
	p=(p==1) ?2 :1;
	cout << "Game over:\n\n\n\t\t ..... Player " << p << " Won .....";
	getch();
	clrscr();
	for(i=0;i<9;i++)
		pos[i] = NULL;
	prnt();
	p=1;
}
