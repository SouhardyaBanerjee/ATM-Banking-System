/*               -:ATM Banking Ststem(Project):-
Program Showing Automated Teller Machine(ATM) Function Using OPPS
1.Check Balance
2.Cash Withdraw
3.User Details
4.Update Mobile No
5.Cash Deposit            
6.PIN Update
7.Exit */
//Header Files
#include<conio.h>
#include<iostream>
#include<string>
using namespace std;                //Standard built in classes and declared Function
class atm                          //ATM class properties
{
	private:                      //Members are not accessible outside the class
		long long int Account_No;
		string Name;
		int PIN;
        long double Balance;
		string Mobile_No;
	public:                     //Members are accessible ouside the class
	    void SetData(long long int Account_No_a,string Name_a,int PIN_a,long double Balance_a,string Mobile_No_a)
		{
			Account_No=Account_No_a;     //Data
			Name=Name_a;
			PIN=PIN_a;
			Balance=Balance_a;
			Mobile_No=Mobile_No_a;
		}
		//to get Account No
		 long long int GetAccountNo()
		{
			return Account_No;
		}
		//to get Name of the account holder
		string GetName()
		{
			return Name;
		}
		//to get PIN of the account
		int GetPIN()
		{
			return PIN;
	    } 	
	    //to get Balance of the account
	     long double GetBalance()
		{
			return Balance;
		}
		//to get the attached Mobile No of the account	
		string GetMobileNo()
		{
			return Mobile_No;
		}
		//This is the method to Update the Mobile No of the Account
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
		//This is the method to withdraw the Cash
		void CashWithDraw(int Amount_a)
		{
			if((Amount_a>0) && (Amount_a<Balance))
			{
				Balance=Balance-Amount_a;
				cout<<endl<<"Please Collect Your Cash"<<endl;
				cout<<endl<<"Available Balance"<<endl<<"-->"<<Balance;
                _getch();
			}
			else
			{
				cout<<endl<<"Invalid Input Insufficient Balance!!!";
				_getch();
			}
		}
		//This is the method to deposite Cash
		void CashDeposit(int amount_b)
		{
			Balance=Balance+amount_b;
			cout<<endl<<"Cash Deposit Successfully!!!"<<endl;
			cout<<endl<<"Available Balance"<<endl<<"-->"<<Balance;
			_getch();
		}
		//This is the mothod to Update the pin of the acoount
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
int main()                            //main function(the code runs start from here)
{
	int choice=0,enterPIN;
	long int enterAccountNo;
	system("cls");                    //to clrae the screen 
	atm user1;                        //to creat an Object
	//import the data to this ATM Object
	user1.SetData(918273645,"Souhardya Banerjee",2092,100000.00,"7872206060");
	do                                   //to hold the loop
	{
		system("cls");
		//Interface(1)
		cout<<endl<<"***WELCOME TO ATM***"<<endl;   
		cout<<endl<<"Enter Your Account No"<<endl;    
		cout<<"-->";
		cin>>enterAccountNo;                              //Confidencial data(1)
		cout<<endl<<"Enter Your PIN"<<endl;
		cout<<"-->";
		cin>>enterPIN;                                    //confidencial data(2)
		//to check wheather the given input is valid or not
		if((enterAccountNo==user1.GetAccountNo())&&(enterPIN==user1.GetPIN()))
		{
		   do
		   {
		   	    int amount=0;
		   	    string OldMobileNo,NewMobileNo;
		   	    int OldPINNo,NewPINNo;
		   	    system("cls");
		   	    //Interface(2)
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
		   	    cin>>choice;                                      //to give the valid choice by the user
		   	    switch(choice)
		   	    {
		   	    	//Check Balance
		   	    	case 1:
		   	    		cout<<endl<<"Your Balance is"<<endl<<"-->"<<user1.GetBalance();
		   	    		getch();
		   	    		break;
		   	    	//Cash Withdraw	
		   	    	case 2:
				 	    cout<<endl<<"Enter the Amount"<<endl;
				 	    cout<<"-->";
				 	    cin>>amount;
				 	    user1.CashWithDraw(amount);
				 	    break;
				 	//User Details
					case 3:
					 	cout<<endl<<"***User Details are***";
					 	cout<<endl<<"->Account No:"<<user1.GetAccountNo();
					 	cout<<endl<<"->Name:"<<user1.GetName();
					 	cout<<endl<<"->Balance:"<<user1.GetBalance();
					 	cout<<endl<<"->Mobile No:"<<user1.GetMobileNo();
					 	cout<<endl<<"->PIN No:"<<user1.GetPIN();
					 	getch();
					 	break;
					//Update Mobile No
					case 4:
				 	    cout<<endl<<"Enter Old Mobile No:";
				 	    cin>>OldMobileNo;
				 	    cout<<endl<<"Enter New Mobile No:";
				 	    cin>>NewMobileNo;
				 	    user1.SetMobile(OldMobileNo,NewMobileNo);
				 	    break;
				 	//Cash Deposit
				 	case 5:
					    cout<<endl<<"Enter the Amount"<<endl;
				 	    cout<<"-->";
				 	    cin>>amount;
				 	    user1.CashDeposit(amount);
				 	    break; 
					//Update PIN No  
				 	case 6:
				 		cout<<endl<<"Enter Old PIN No:";
				 		cin>>OldPINNo;
				 		cout<<endl<<"Enter New PIN No:";
				 		cin>>NewPINNo;
				 		user1.SetPIN(OldPINNo,NewPINNo);
				 		break;
				 	//to exit the program
				 	case 7:	
				 	    exit(0);
				 	    break;
				 	//Default statement
				 	default:
				 	    if(choice!=7)
						 {
						 	cout<<endl<<"Please Enter Correct Choice!!!"<<endl;
						 	_getch();
						 }
						 break;	    
				}
		   }while(1);
	    _getch();	
		}
		else                               //Invalid Data
		{
			cout<<endl<<"User Details Invalid!!!";
			_getch();
		}
	}while(1);
	return 0;
}

