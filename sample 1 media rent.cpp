#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


void logScreen();
void startProg();

class Shopkeeper{
//reports
	
};
class Store{
	protected:
	int Cd;
	int dvd;
	
	public:
		void setCd(int cd)
	{
		Cd = cd;
	}
	
		int getCd()
	{
		return Cd;
	}
	
	void setdVD(int dVd)
	{
		dvd = dVd;
	}
	
		int getdVD()
	{
		return dvd;
	}
	
};
class Purchase : public Store
{
/*include no of puchased items(cds and dvds)
plus remaining items
*/
public:
	Store sr;
	void StoreItems(){
	int newCd = 200;
	int newDvd = 442;
	int addCd;
	int addDvd;
	cout<<"Opening Stock\n\t"<<newCd<<" CDs\n\t"<<newDvd<<" DVDs"<<endl;
	cout<<"\nHow many CDs do you wish to add in the store ";
	cin>>addCd;
	cout<<"\nHow many DVDs do you wish to add in the store ";
	cin>>addDvd;
	newCd +=addCd;
	newDvd += addDvd;
	setCd(newCd);
	setdVD(newDvd);
	cout<<"The current stock\n\t"<<getCd()<<"\nThe DVDs are \n\t"<<getdVD()<<endl;
	}
	

	
	
};
class Lend_Items : public Purchase
{
/*
items lend
when lend
date to return item lend
*/

public:
	float FineCalc(){
	 float fine;
	int choice;
	float days;
	float firstFineCharged;
	cout<<"Enter the first fine to charge the Consumer to be charged: ";
	cin>>firstFineCharged;
	
	cout<<"Is the time period exceeded: \n\t[1] Yes\n\t[2] No"<<endl;
	cin>>choice;
	float total_bail;
	switch(choice)
	{
	case 1:
		
		cout<<"Enter the Numbers of days exceeded with: ";
		cin>>days;
		days = days * 0.2;
		total_bail = (total_bail + firstFineCharged + days);
		cout<<total_bail;
		break;
	case 2:
		cout<<"The system will calculate any other Fine now\n";
		if (firstFineCharged != 0)
		{
			cout<<"The fine is: "<<firstFineCharged<<endl;
			
		}
		cout<<"Go back to Main Menu\n[1]Yes\n[2]No"<<endl;
			int counter;
			cin>>counter;
			switch(counter)
			{
			case 1:
				startProg();
				break;
			case 2:
				system(0);
				break;
			default:
				cout<<"Enter correct value"<<endl;
				break;
			}
			
		break;
	default:
		cout<<"Invalid Choice. Please choose the appropiately" <<endl;
		FineCalc();
		break;
	}	
	}

	
	
	
};
class Client : public Lend_Items, public Purchase
{
/*
borrowed item
pay fee of borrowed item
pay fine when he exceeds time
*/	
private:
	string name1;
	string name2;
protected:
	float fee;
	//float fine;
public:
	//float fine;
	
	Purchase ps;
	void display(){
	cout<<"\n\n\tThese are the items we have in our store\n\t\t[1] Compact Disks CDs\
\n\t\t[2] Digital Versatile Disks DVDs"<<endl;
	}
	void setName1(string n1)
	{
		name1 = n1;
	}
	void setName2(string n2)
	{
		name2 = n2;
	}
	void setFee(float f)
	{
		fee = f;
	}
/*	void setFine(float F)
	{
		fine = F;
	}
	float getFine()
	{
		return fine;
	}*/
	float getFee()
	{
		return fee;
	}
	string getName1()
	{
		return name1;
	}
	string getName2()
	{
		return name2;
	}
};




int main()
{
	startProg();
	return 0;
}

void logScreen()
{
	string password;
	string name3,name4;
	
	cout<<"\n\n\n\n\t\t\t\xB2\xB2\xB2\xB2              \xB2\xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2\xB2\xB2            \xB2\xB2\xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2 \xB2\xB2          \xB2\xB2 \xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2   \xB2\xB2      \xB2\xB2   \xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2     \xB2\xB2  \xB2\xB2\t   \xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2       \xB2\xB2\t   \xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2\t\t   \xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2\t\t   \xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2\xB2\xB2   RENTAL   \xB2\xB2\xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\tSYSTEM"<<endl;
	
	cout<<"\n\n\t\t      MULTIMEDIA RENTAL SYSTEMS"<<endl;
	cout<<"\n\n\t\tEnter your Username: ";
	cin>>name3;
	cout<<"                        ";
	cout<<"\n\n\t\tEnter your Second name: ";
	cin>>name4;
	system("cls");
	cout<<"\n\t\tEnter your Password: ";
	cin>>password;
//	system("cls");
}
void startProg(){
	system("color 2f");
	Purchase ps;
	Shopkeeper sh;
	Lend_Items le;
	Client cl;
	logScreen();
	cl.display();
	
	ps.StoreItems();
	//ps.display();
	le.FineCalc();
}
	