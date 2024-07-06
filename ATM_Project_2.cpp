#include<conio.h>
#include<iostream>
#include<string>
using namespace std;
class atm
{
	private:
		long long int Account_No;
		string Name;
		int PIN;
        long double Balance;
		string Mobile_No;
	public:
	    void SetData(long long int Account_No_a,string Name_a,int PIN_a,long double Balance_a,string Mobile_No_a)
		{
			Account_No=Account_No_a;
			Name=Name_a;
			PIN=PIN_a;
			Balance=Balance_a;
			Mobile_No=Mobile_No_a;
		}
		 long long int GetAccountNo()
		{
			return Account_No;
		}
		string GetName()
		{
			return Name;
		}
		int GetPIN()
		{
			return PIN;
	    } 	
	     long double GetBalance()
		{
			return Balance;
		}	
		string GetMobileNo()
		{
			return Mobile_No;
		}
		void SetMobile(string Mob_prev,string Mob_new)
		{
			if(Mob_prev==Mobile_No)
			{
				Mobile_No=Mob_new;
				cout<<endl<<"Successfully Updated Mobile No";
				_getch();
			}
			else
			{
				cout<<endl<<"Incorrect Mobile No!!!";
				_getch();
			}
		}
		void CashWithDraw(int Amount_a)
		{
			if((Amount_a>0) && (Amount_a<Balance))
			{
				Balance=Balance-Amount_a;
				cout<<endl<<"Please Collect Your Cash"<<endl;
				cout<<endl<<"Available Balance"<<endl<<"="<<Balance;
                _getch();
			}
			else
			{
				cout<<endl<<"Invalid Input Insufficient Balance!!!";
				_getch();
			}
		}
		void CashDeposit(int amount_b)
		{
			Balance=Balance+amount_b;
			cout<<endl<<"Cash Deposit Successfylly!!!"<<endl;
			cout<<endl<<"Available Balance"<<endl<<"-->"<<Balance;
			_getch();
		}
		void SetPIN(int PIN_prev,int PIN_new)
		{
			if(PIN_prev==PIN)
			{
				PIN=PIN_new;
				cout<<endl<<"Successfully Updated PIN No";
				_getch();
			}
			else
			{
				cout<<endl<<"Incorrect PIN No!!!";
				_getch();
			}
		}
				
};
int main()
{
	int choice=0,enterPIN;
	long int enterAccountNo;
	system("cls");
	atm user1;
	user1.SetData(918273645,"Souhardya Banerjee",2092,100000.00,"7872206060");
	do
	{
		system("cls");
		cout<<endl<<"***WELCOME TO ATM***"<<endl;
		cout<<endl<<"Enter Your Account No"<<endl;
		cout<<"-->";
		cin>>enterAccountNo;
		cout<<endl<<"Enter Your PIN"<<endl;
		cout<<"-->";
		cin>>enterPIN;
		if((enterAccountNo==user1.GetAccountNo())&&(enterPIN==user1.GetPIN()))
		{
		   do
		   {
		   	    int amount=0;
		   	    string OldMobileNo,NewMobileNo;
		   	    int OldPINNo,NewPINNo;
		   	    system("cls");
		   	    cout<<endl<<"***WELCOME TO ATM***"<<endl;
		   	    cout<<endl<<"Select Options";
		   	    cout<<endl<<"1.Check Balance";
		   	    cout<<endl<<"2.Cash With Draw";
		   	    cout<<endl<<"3.User Details";
		   	    cout<<endl<<"4.Update Mobile No";
		   	    cout<<endl<<"5.Cash Deposit";
		   	    cout<<endl<<"6.PIN Update";
		   	    cout<<endl<<"7.Exit"<<endl;
		   	    cout<<endl<<"Please Enter Your Choice"<<endl;
		   	    cout<<"-->";
		   	    cin>>choice;
		   	    switch(choice)
		   	    {
		   	    	case 1:
		   	    		cout<<endl<<"Your Balance is"<<endl<<"-->"<<user1.GetBalance();
		   	    		getch();
		   	    		break;
		   	    	case 2:
				 	    cout<<endl<<"Enter the Amount"<<endl;
				 	    cout<<"-->";
				 	    cin>>amount;
				 	    user1.CashWithDraw(amount);
				 	    break;
					case 3:
					 	cout<<endl<<"***User Details are***";
					 	cout<<endl<<"->Account No:"<<user1.GetAccountNo();
					 	cout<<endl<<"->Name:"<<user1.GetName();
					 	cout<<endl<<"->Balance:"<<user1.GetBalance();
					 	cout<<endl<<"->Mobile No:"<<user1.GetMobileNo();
					 	cout<<endl<<"->PIN No:"<<user1.GetPIN();
					 	getch();
					 	break;
					case 4:
				 	    cout<<endl<<"Enter Old Mobile No:";
				 	    cin>>OldMobileNo;
				 	    cout<<endl<<"Enter New Mobile No:";
				 	    cin>>NewMobileNo;
				 	    user1.SetMobile(OldMobileNo,NewMobileNo);
				 	    break;
				 	case 5:
					    cout<<endl<<"Enter the Amount"<<endl;
				 	    cout<<"-->";
				 	    cin>>amount;
				 	    user1.CashDeposit(amount);
				 	    break;   
				 	case 6:
				 		cout<<endl<<"Enter Old PIN No:";
				 		cin>>OldPINNo;
				 		cout<<endl<<"Enter New PIN No:";
				 		cin>>NewPINNo;
				 		user1.SetPIN(OldPINNo,NewPINNo);
				 		break;
				 	case 7:	
				 	    exit(0);
				 	    break;
				 	default:
				 	    cout<<endl<<"Enter Valid Choice!!!";
						break;	    
				}
		   }while(1);
	    _getch();	
		}
		else
		{
			cout<<endl<<"User Details Invalid!!!";
			_getch();
		}
	}while(1);
	return 0;
}

