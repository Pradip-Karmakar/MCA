#include<iostream>
#include<string>
using namespace std;

class student{
	int rno;
	string name;
	int age;
	float marks[3] = {35,35,35};
	
	public:
	void addstd()
	{
		cout << endl << "Enter Student Roll No : " << endl;
		cin >> rno;
		cout << endl << "Enter Student Name : " << endl;
		cin >> name;
		cout << endl << "Enter Student Age : " << endl;
		cin >> age;
	}
	
	int check(int roll,int i)
	{
		if(roll == rno)
		{
			return i;
		}
		else 
		{
			return -1;
		}
	}

	void edit()
	{
		cout << endl << "Enter Marks For Subject 1  :" << endl;
		cin	>> marks[0];
		cout << endl << "Enter Marks For Subject 2  :" << endl;
		cin	>> marks[1];
		cout << endl << "Enter Marks For Subject 3  :" << endl;
		cin	>> marks[2];
	}

	void display()
	{
		cout << endl << "Name : " << name << endl;
		cout << endl << "Roll No : " << rno << endl;
		cout << endl << "Age : " << age <<endl;
		cout << endl << "Subject 1 : " << marks[0] << endl;
		cout << endl << "Subject 2 : " << marks[1] << endl;
		cout << endl << "Subject 3 : " << marks[2] << endl; 
	}
};

void menu(class student []);

int main()
{
	student std[10];
	menu(std);
	return 0;
}

void menu(class student std[])
{
	int index = 0,n,i,checkroll = 0,editindex = -1;
	do{
		cout << " 1 . Add Student." << endl << " 2 . Edit Student Details." << endl << " 3 . Show Details of Student." << endl << " 4 . Exit" << endl;
    	cin >> n;
		
		if( n == 1){
			std[index].addstd();
			cout << endl << "Student Added Sucessfully With Default Marks." << endl;
		}
		else if( n == 2)
		{
			cout << endl << "Enter Student Roll No" << endl;
			cin >> checkroll;
			for( i = 0; i <= index; i++ )
			{
				editindex = std[i].check(checkroll,i);
				if( editindex != -1 )
				{
					i = index+1;
				}	
			}
			if( editindex == -1 )
			{
				cout << endl << "Invalid Roll No." << endl;
			}
			else{
				std[editindex].edit();
				cout << endl << "Student Marks Updated Sucessfully." << endl;
			}
		}
		else if( n == 3 )
		{
			cout << endl << "Enter Student Roll No" << endl;
			cin >> checkroll;
			for( i = 0; i <= index; i++ )
			{
				editindex = std[i].check(checkroll,i);
				if( editindex != -1 )
				{
					i = index+1;
				}	
			}
			if( editindex == -1 )
			{
				cout << endl << "Invalid Roll No." << endl;
			}
			else{
				std[editindex].display();
			}
		}
		else{
			exit(0);
		}
	}while(n < 4);	
}