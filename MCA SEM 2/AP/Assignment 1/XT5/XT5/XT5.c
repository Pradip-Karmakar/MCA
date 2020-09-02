#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	float mileage;
	char type[10];
}two;

typedef struct{
	float mileage;
	char transmission[10],type[10];
	int Eng_no;
}four;

typedef struct{
	int vehi_type;
	char vehi_name[15];
	float price;
	union{
		two t;
		four f;
	};
}vehicle;

vehicle getData();

void setPrint(vehicle[],int,int);

void menudriven(vehicle[],int);

void main()
{
	vehicle v[50];
	int i,total_vehicles;
	printf("Enter Total Number of Vehicles : ");
	scanf("%d",&total_vehicles);
	for( i = 0; i < total_vehicles; i++ )
	{
		v[i] = getData();
	}

	menudriven(v,total_vehicles);
}

vehicle getData()
{
	vehicle b;
	printf("\nPress 1 for 2 Wheelers \nPress 2 for 4 Wheelers\n");
	scanf("%d",&b.vehi_type);
	if(b.vehi_type == 1)
	{
		printf("\nEnter Vehicle Name : ");
		scanf("%s",b.vehi_name);
		printf("\nEnter Vehicle Price : ");
		scanf("%f",&b.price);
		printf("\nEnter Vehicle Mileage : ");
		scanf("%f",&b.t.mileage);
		printf("\nEnter Vehicle Type(Gear/Gearless) : ");
		scanf("%s",b.t.type);
	}
	else if(b.vehi_type == 2){
		printf("\nEnter Vehicle Name : ");
		scanf("%s",b.vehi_name);
		printf("\nEnter Vehicle Price : ");
		scanf("%f",&b.price);
		printf("\nEnter Vehicle Engine Number : ");
		scanf("%d",&b.f.Eng_no);
		printf("\nEnter Vehicle Mileage : ");
		scanf("%f",&b.f.mileage);
		printf("\nEnter Vehicle Transmission Type : ");
		scanf("%s",b.f.transmission);
		printf("\nEnter Vehicle Type (Heavy/Light) : ");
		scanf("%s",b.f.type);
	}
	return b;
}

void setPrint(vehicle b[], int tv, int v_type)
{
	int i;
	for( i = 0; i < tv; i++ )
	{
		if( b[i].vehi_type == v_type )
		{
			if( v_type == 1 )
			{
				printf("\n\n\tVehicle Type = Two Wheeler \n\tVehicle Name = %s \n\tVehicle Price = %.2f \n\tMileage = %.2f \n\tGear Type = %s\n________________________________________________________",b[i].vehi_name,b[i].price,b[i].t.mileage,b[i].t.type);
			}
			else{
				printf("\n\n\tVehicle Type = Four Wheeler \n\tVehicle Name = %s \n\tVehicle Price = %.2f \n\tMileage = %.2f \n\tTransmission Type = %s \n\t Type = %s \n\tEngine No = %d\n________________________________________________________",b[i].vehi_name,b[i].price,b[i].f.mileage,b[i].f.transmission,b[i].f.type,b[i].f.Eng_no);
			}
		}
	}
}

void menudriven(vehicle b[],int tv)
{
	int i,j,option;
	
	printf("\n\n\tPress 1 To Display All Vehicles. \n\n\tPress 2 To Display Two Wheelers \n\n\tPress 3 To Display Four Wheelers \n\n\tPress 4 For Exit\n");
	scanf("%d",&option);
	if(option == 1)
	{
		printf("\n+++++++++++++++++++++Two Wheelers+++++++++++++++++++++");
		setPrint(b,tv,1);
		printf("\n+++++++++++++++++++++Four Wheelers+++++++++++++++++++++");
		setPrint(b,tv,2);
		menudriven(b,tv);
	}
	else if(option == 2)
	{
		printf("\n+++++++++++++++++++++Two Wheelers+++++++++++++++++++++");
		setPrint(b,tv,1);
		menudriven(b,tv);
	}
	else if(option == 3)
	{
		printf("\n+++++++++++++++++++++Four Wheelers+++++++++++++++++++++");
		setPrint(b,tv,2);
		menudriven(b,tv);
	}
	else if(option == 4)
	{
		exit(0);
	}
	else
	{
		printf("\nPlease Select Proper Options\n");
		menudriven(b,tv);
	}
}