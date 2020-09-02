#include<iostream>
#include<string>
using namespace std;

class bank_account
{
    string Name_of_Depositor;
    int Account_Number;
    string Account_Type;
    int Balance;
    public:
    void initial_values()
    {
        cout << "Enter Name Of Depositor : ";
        cin >> Name_of_Depositor;
        cout << "Enter The Account Number : ";
        cin >> Account_Number;
        cout << "Enter The Account Type : ";
        cin >> Account_Type;
        cout << "Enter The Balance : ";
        cin >> Balance;
    }
    void Deposit()
    {
        int amount;
        cout << "Enter The Amount You Want To Add : ";
        cin >> amount;
        Balance += amount;
    }

    void Withdraw()
    {
        int amount;
        cout << "Enter The Amount You Want To Withdraw : ";
        cin >> amount;
        if( Balance < amount )
        {
            cout << "Insufficient Balance" << endl;
        }
        else{
            Balance -= amount;
        }
    }

    void Display()
    {
        cout << "Name : " << Name_of_Depositor << endl << "Balance" << Balance << endl;
    }
 
    int check(int acc,int i)
    {
        if( Account_Number == acc )
        {
            return i;
        }
        else{
            return -1;
        }
    } 
};

void menu(class bank_account []);

int main()
{
    int n,index;
    bank_account s[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter Detail For "<< i+1 << " Customer" << endl;
        s[i].initial_values();
    }
    menu(s);
    return 0;
}

void menu(class bank_account s[])
{
    int n,account_no,index = -1;
    cout << " 1 . Deposit Amount." << endl << " 2 . Withdraw Amount." << endl << " 3 . Show Balnace." << endl << " 4 . Exit" << endl;
    cin >> n;
    switch (n)
    {
    case(1):
        cout << "Enter Your Account_No : ";
        cin >> account_no;
        for( int i = 0; i < 10; i++ )
        {
            index = s[i].check(account_no,i);
            if( index != -1 )
            {
                i = 10;
            }
        }
        if(index == -1)
        {
            cout << "InValid Account Number" << endl;
        }
        else{
            s[index].Deposit();
        }
        menu(s);
    case(2):
        cout << "Enter Your Account_No : ";
        cin >> account_no;
        for( int i = 0; i < 10; i++ )
        {
            index = s[i].check(account_no,i);
            if( index != -1 )
            {
                i = 10;
            }
        }
        if(index == -1)
        {
            cout << "InValid Account Number" << endl;
        }
        else{
            s[index].Withdraw();
        }
        menu(s);
    case(3):
        cout << "Enter Your Account_No : ";
        cin >> account_no;
        for( int i = 0; i < 10; i++ )
        {
            index = s[i].check(account_no,i);
            if( index != -1 )
            {
                i = 10;
            }
        }
        if(index == -1)
        {
            cout << "InValid Account Number" << endl;
        }
        else{
            s[index].Display();
        }
        menu(s);
    case(4):
        exit(0);
    default:
        cout << "Invalid Call" << endl;
        menu(s);
    }
}