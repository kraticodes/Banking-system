#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

//class
class Bank {
	private:
		int acno;
		char name[30];
		long balance;
	
	public:
		void OpenAccount()
		{
			cout << "Enter Account Number: ";
			cin >> acno;
			cout << "Enter Name: ";
			cin >> name;
			cout << "Enter Balance: ";
			cin >> balance;
		}
		void ShowAccount()
		{
			cout <<"Account Number: " << acno << endl;
			cout <<"Name: " << name << endl;
			cout <<"Balance: "<< balance << endl;
		}
		void Deposit()
		{
			long amt;
			cout << "Enter Amount You Want To Deposit? ";
			cin >> amt;
			balance = balance + amt;
		}
		void Withdrawal() 
		{
			long amt;
			cout << "Enter Amount You Want To Withdraw? ";
			cin >> amt;
			if (amt <= balance)
			    balance = balance - amt ;
			else
			    cout << "You Don't Have Enough Balance!"<< endl;		
		} 
		int Search(int);	
};

int Bank::Search(int a)
{
	if (acno == a){
		ShowAccount();
		return (1);
	}
	return(0);
}

//main code
int main()
{
	Bank C[3];
	
	int found = 0,a,ch,i; 
	for (i=0; i<= 2; i++){
		C[i].OpenAccount();
	}
	
	do {
		//display options
		cout <<"\n\n 1: Display All \n 2: Check Balance \n 3: Deposit Amount \n 4: Withdraw Amount \n 5: Exit" <<endl;
		
		//user input
		cout<<"Please input your choice (1-5): ";
		cin>>ch;
		
		switch (ch) {
		case 1: //displaying account info
		    for (i=0;i<=2; i++)	{
		    	C[i].ShowAccount();
			}
			break;
		case 2: //searching records to check balance
		    cout<<"Account Number? ";
			cin>> a;
			for (i=0;i<=2;i++){
				found = C[i].Search(a);
				if (found)
				break;
			}	
			if (!found)
			    cout<<"Record Not Found"<<endl;
		    break;
		case 3: //deposit operation
		    cout<<"Enter Account Number To Deposit Ammount: ";
		    cin>> a;
		    for (i=0;i<=2;i++){
		    	found = C[i].Search(a);
		    	if (found){
		    		C[i].Deposit();
					break;			
				}
			}
			if (!found)
			    cout<<"Record Not Found"<<endl;
			break;
		case 4: // withdraw operation
            cout << "Account Number To Withdraw Amount? ";
            cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found) {
                    C[i].Withdrawal();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
            break;
        case 5: // exit
            cout << "Have a nice day" << endl;
            break;
        default:
            cout << "Wrong Option" << endl;
			
		}
	}while (ch != 5);
	return 0;
}

































