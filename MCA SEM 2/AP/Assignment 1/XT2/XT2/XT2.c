#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
union Game{
	struct football{
		char coachname[15];
		int played,wins,lose,draw,goals;
	}football;

	struct baseball{
		char coachname[15];
		int played,wins,lose,draw,homeruns;
	}baseball;
}games;


struct league{
	int Game_Id;
	char Team_Name[20];
	char city[15];
	union Game games;
};

int getData(struct league[]);
void setPrint(struct league[],int);
void menudriven(struct league[],int);

void main()
{
	struct league game[15];
	int i,j,n;
	n = getData(game);
	/*printf("")*/
	setPrint(game,n);
	menudriven(game,n);
}

int getData(struct league p[])
{
	int i,j,total_league;
	printf("Enter Total Leagues : ");
	scanf("%d",&total_league);
	for( i = 0;i < total_league; i++ )
	{
		printf("\n\nPress 1 For Football \n\nPress 2 For Baseball\n\n");
		scanf("%d",&p[i].Game_Id);
		
		if(p[i].Game_Id == 1)
		{
			printf("\nEnter Team Name : ");
			scanf("%s",p[i].Team_Name);
			printf("\nEnter City : ");
			scanf("%s",p[i].city);
			printf("\nEnter Coach Name : ");
			scanf("%s",p[i].games.football.coachname);
			printf("\nEnter Total Numbers of Matches Played : ");
			scanf("%d",&p[i].games.football.played);
			printf("\nEnter Total Numbers of Wins : ");
			scanf("%d",&p[i].games.football.wins);
			printf("\nEnter Total Numbers of Loses : ");
			scanf("%d",&p[i].games.football.lose);
			printf("\nEnter Total Numbers of Goals : ");
			scanf("%d",&p[i].games.football.goals);
			p[i].games.football.draw = p[i].games.football.played-p[i].games.football.wins-p[i].games.football.lose;
			printf("______________________________________________________");
		}
		else if(p[i].Game_Id == 2)
		{
			printf("\nEnter Team Name : ");
			scanf("%s",p[i].Team_Name);
			printf("\nEnter City : ");
			scanf("%s",p[i].city);
			printf("\nEnter Coach Name : ");
			scanf("%s",p[i].games.baseball.coachname);
			printf("\nEnter Total Numbers of Matches Played : ");
			scanf("%d",&p[i].games.baseball.played);
			printf("\nEnter Total Numbers of Wins : ");
			scanf("%d",&p[i].games.baseball.wins);
			printf("\nEnter Total Numbers of Loses : ");
			scanf("%d",&p[i].games.baseball.lose);
			printf("\nEnter Total Numbers of Homeruns : ");
			scanf("%d",&p[i].games.baseball.homeruns);
			p[i].games.baseball.draw = p[i].games.baseball.played-p[i].games.baseball.wins-p[i].games.baseball.lose;
			printf("__________________________________________________________");
		}
		else
		{
			printf("\nPlease Select Proper Options\n");
			--i;
		}
	}
	return total_league;
}

void setPrint(struct league p[], int n)
{
	int i;
	for( i = 0; i < n; i++ )
	{
		if(p[i].Game_Id == 1)
		{
			printf("\n\n\tLeague : Football\n\tTeam Name : %s\n\tCity : %s\n\tCoach : %s\n\tMatch Played : %d\n\tWins : %d\n\tLoses : %d\n\tDraws : %d\n\tTotal Goals : %d\n\n______________________________________________________________________________",p[i].Team_Name,p[i].city,p[i].games.football.coachname,p[i].games.football.played,p[i].games.football.wins,p[i].games.football.lose,p[i].games.football.draw,p[i].games.football.goals);
		}
		else{
			printf("\n\n\tLeague : Baseball\n\tTeam Name : %s\n\tCity : %s\n\tCoach : %s\n\tMatch Played : %d\n\tWins : %d\n\tLoses : %d\n\tDraws : %d\n\tTotal Goals : %d\n\n______________________________________________________________________________",p[i].Team_Name,p[i].city,p[i].games.baseball.coachname,p[i].games.baseball.played,p[i].games.baseball.wins,p[i].games.baseball.lose,p[i].games.baseball.draw,p[i].games.baseball.homeruns);
		}
	}
}

void menudriven(struct league p[],int n)
{
	int i,j,option = 0;
	struct league temp;
	printf("\n\nPress 1 To Display Data in Win Wise. \n\nPress 2 To Display Data in Lose Wise. \n\nPress 3 To Display Data in Draw Wise. \n\nPress 4 To Exit Program.\n\n");\
	scanf("%d",&option);
	if(option == 1)
	{
		for( i = 0; i < n; i++ )
		{
			for( j = 0; j < n-i-1; j++ )
			{
				if(p[j].games.football.wins < p[j+1].games.football.wins ||  p[j].games.football.wins < p[j+1].games.baseball.wins || p[j].games.baseball.wins < p[j+1].games.baseball.wins || p[j].games.baseball.wins < p[j+1].games.football.wins)
				{
					temp = p[j];
					p[j] = p[j+1];
					p[j+1] = temp;
				}
			}
		}
		setPrint(p,n);
		menudriven(p,n);
	}
	else if(option == 2)
	{
		for( i = 0; i < n; i++ )
		{
			for( j = 0; j < n-i-1; j++ )
			{
				if(p[j].games.football.lose < p[j+1].games.football.lose ||  p[j].games.football.lose < p[j+1].games.baseball.lose || p[j].games.baseball.lose < p[j+1].games.baseball.lose || p[j].games.baseball.lose < p[j+1].games.football.lose)
				{
					temp = p[j];
					p[j] = p[j+1];
					p[j+1] = temp;
				}
			}
		}
		setPrint(p,n);
		menudriven(p,n);
	}
	else if(option == 3)
	{
		for( i = 0; i < n; i++ )
		{
			for( j = 0; j < n-i-1; j++ )
			{
				if(p[j].games.football.draw < p[j+1].games.football.draw ||  p[j].games.football.draw < p[j+1].games.baseball.draw || p[j].games.baseball.draw < p[j+1].games.baseball.draw || p[j].games.baseball.draw < p[j+1].games.football.draw)
				{
					temp = p[j];
					p[j] = p[j+1];
					p[j+1] = temp;
				}
			}
		}
		setPrint(p,n);
		menudriven(p,n);
	}
	else if(option == 4)
	{
		exit(0);
	}
	else
	{
		printf("Please Select Proper Option.");
		menudriven(p,n);
	}
	
}