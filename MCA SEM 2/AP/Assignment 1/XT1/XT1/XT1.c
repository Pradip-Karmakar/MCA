#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct player{
	char Player_name[15];
	float Batting_average;
}players;

struct teams{
	int total_players;
	char Team_name[15];
	struct player players[50];
};

int getnplayer();
struct teams getData();
void getSort(struct teams[],int);
void setPrint(struct teams[],int);
void menudriven(struct teams[],int);
void main()
{
	int i,j,team_count;
	struct teams s[10];

	team_count = getnteam();
	for( i = 0; i < team_count; i++ )
	{
		s[i] = getData();
	}

	printf("\n\nBefore Sorting List \n");
	setPrint(s,team_count);
	getSort(s,team_count);
	printf("\n\nAfter Sorting List \n");
	setPrint(s,team_count);
	menudriven(s,team_count);
	getch();
}



struct teams getData()
{
	int i,player_count;
	struct teams g;
	printf("\nEnter Team Name : ");
	scanf("%s",g.Team_name);
	player_count = getnplayer();
	g.total_players = player_count;
	for( i = 0; i < player_count; i++)
	{
		printf("\nEnter Player Name : ");
		scanf("%s",g.players[i].Player_name);
		printf("\nEnter Batting Average : ");
		scanf("%f",&g.players[i].Batting_average);
	}
	printf("\n_______________________________________________________\n");
	return g;
}

int getnteam()
{
	int x;
	printf("\nEnter The Number of Teams : ");
	scanf("%d",&x);
	return x;
}

int getnplayer()
{
	int y;
	printf("\nEnter The Number of Players : ");
	scanf("%d",&y);
	return y;
}

void getSort(struct teams s[],int n)
{
	int i,j,k,l,Check;
	struct teams temp;
	struct player p;
	for( i = 0; i < n; i++ )
	{
		for( j = 0; j < s[i].total_players; j++)
		{
			for( k = 0; k < s[i].total_players - j -1; k++)
			{
				if(s[i].players[k].Batting_average < s[i].players[k+1].Batting_average )
				{
					p = s[i].players[k];
					s[i].players[k] = s[i].players[k+1];
					s[i].players[k+1] = p;
				}
			}
		}
	}
	for( i = 0; i < n; i++ )
	{
		for( j = 0; j < n - i -1; j++ )
		{
			Check = strcmp(s[j].Team_name,s[j+1].Team_name);
			if(Check > 0)
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
}

void setPrint(struct teams p[],int n)
{
	int i,j;
	for( i = 0; i < n; i++ )
	{
		printf("\nTEAM NAME = %s\n*************************************\n",p[i].Team_name);
		for( j = 0; j < p[i].total_players; j++ )
		{
			printf("\n\tPLAYER NAME = %s \n\tBATTING AVERAGE = %.2f\n*************************************\n",p[i].players[j].Player_name,p[i].players[j].Batting_average);
		}
	}
}

void menudriven(struct teams p[],int n)
{
	int val,i,j,Check;
	char player[15];
	printf("\n\nPress 1 To Search Player Detail ");
	printf("\n\nPress 2 To Exit The Program\n");
	scanf("%d",&val);
	if(val == 1)
	{
		printf("\n\nEnter Player Name : ");
		scanf("%s",player);
		
		for( i = 0; i < n; i++ )
		{
			for( j = 0; j < p[i].total_players; j++ )
			{
				Check = strcmp(p[i].players[j].Player_name,player);
				if(Check == 0)
				{
					printf("\nPLAYER NAME = %s \nTEAM NAME = %s \nBATTING AVERAGE = %.2f\n*************************************\n",p[i].players[j].Player_name,p[i].Team_name,p[i].players[j].Batting_average);
					menudriven(p,n);
				}
			}
		}
	}
	else if(val == 2)
	{
		exit(0);
	}
	else{
		printf("\n\nPlease Select Proper Options.\n");
		menudriven(p,n);
	}
	printf("\n\nPlayer Detail Not Found\n");
	menudriven(p,n);
}