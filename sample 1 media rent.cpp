#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

void Choice1();
void writeReport();
void readFile();
void Invoice();

//**********************STORE CLASS***********************************************************


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



//*************PURCHASE CLASS ***********************************************************


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

//**************LEND ITEMS CLASS********************************************************


class Lend_Items : public Purchase
{
/*
items lend
when lend
date to return item lend
*/

public:
	float FineCalc()
 
	{ float fine;
	int choice;
	float days;
	float firstFineCharged;
	string returnindY;
	cout<<"Return by"<<endl;
	cin>>returnindY;
	cout<<"Enter the first fine to charge the Consumer in shs: ";
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
			
		break;
	default:
		cout<<"Invalid Choice. Please choose the appropiately" <<endl;
		FineCalc();
		break;
	}
	cout<<"\n\n\tCharge The Client "<<total_bail<<"shs"<<endl;	
	}
	
};


void writeReport()//function for writing to file
{
	//char shopkeeperWords[10000];
	char conti[10000];
	ofstream shopreport;
	shopreport.open("Report.txt");
	shopreport<<"\t\tTodays Report\n"<<endl;
	shopreport<<"\n_______________________"<<endl;
	int x = 10;
	do{
	if(shopreport.is_open())
	
	{
	cin.getline(conti, 10000);
	shopreport<<conti<<endl;
	shopreport<<" "<<conti<<endl;	
	}
	x--;
	}while(x > 0 );
	shopreport.clear();
	shopreport.close();
}


//*************************CLIENT CLASS************************************************


class Client : public Lend_Items, public Purchase, public Store
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
	Store st;
	//float fine;
	
	Purchase ps;
	void display(){
		system("cls");
	//	system("color 3f");
		Choice1();
		//cout<<"Proceed With The Following"<<endl;
	//cout<<"\n[1] Make a Sale\n[2] Make a Report\n[3] Lease Item\n[4] Exit"<<endl;
		
	
	}
	int no_cd;
	int no_dvd;
	int choice;
	
	void No_item_Brwd(){
		
	choice;
	cout<<"Borrow item number: ";
	cin>>choice;
	if(choice = 1)
	{
		no_cd;
		cout<<"Enter the number of CDs that you would want to borrow: ";
		cin>>no_cd;
		st.setCd(no_cd);
		st.getCd();
	}
	else if(choice = 2)
	{
		no_dvd;
		cout<<"Enter the number of DVDs that you would want to borrow: ";
		cin>>no_dvd;
		st.setdVD(no_dvd);
		st.getdVD();
		
	}
	else
	{
		cout<<"Invalid Choice"<<endl;
	}
	
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


//***************SHOPKEEPER CLASS***********************************************************


class Shopkeeper : public Store, public Lend_Items, public Client, public Purchase
{
//reports
private:
	
	//float money_cd[2];
	//float money_dvd[2];
public:
	Store st;
		
	
	//char* header[50];
	

	void No_item_Brwd(){
		
	int choice2;
	cout<<"\n\tClient Wants to Borrow item number: ";
	cin>>choice2;
	if(choice2 == 1)
	{
		int no_cd;
		cout<<"\n\tEnter the number of CDs that the borrows: ";
		cin>>no_cd;
		st.setCd(no_cd);
		st.getCd();
		cout<<endl;
	}
	else if(choice2 == 2)
	{
		int no_dvd;
		cout<<"\n\tEnter the number of DVDs that the borrows:  ";
		cin>>no_dvd;
		st.setdVD(no_dvd);
		st.getdVD();
		cout<<endl;
		
	}
	else if((choice2 !=1) && (choice2 !=2))
	{
		cout<<"\a\n\tInvalid Choice"<<endl;
		No_item_Brwd();
	}
	
	}
	
	
	int myArray()
{
	
	//No_item_Brwd();
	system("cls");
	cout<<"\n\n\tIn the table below Enter the Standing Charges of the items\n\n"<<endl;
	cout<<"Ksh of CD\t|\tKsh of DVD\t|\tKsh To Borrow"<<endl;
	cout<<"--------------------------------------------------------------------"<<endl;
float money_cd[1];
	float money_dvd[2];
	float borrow[1];
	int i,j,k;
	
	for (j= 0; j<=1; j++)
	{
		for(i=0; i<=1;i++)
		{
			for(k=0;k<=1;k++)
			{
			cin>>money_cd[i];
			cout<<"                                                                        ";
			cin>>money_dvd[j];
			cout<<"                                                                        ";
			cin>>borrow[k];
			cout<<endl;
			return 0;
			}
		}
		
		
	}
	
	
		
}
	
	void Lend_Calc(){
	float amount;
	cout<<"Number of Cds ";
	int no_of_it;
	cin>>no_of_it;
	cout<<"\nAmount of One item: ";
	cin>>amount;
	int total = (no_of_it)*(amount);
	st.setCd(total);
	cout<<"Amount payable for Lending "<<st.getCd()<<" is: ";
	//cin>>amount;
	}
};

//******************** MAIN FUNCTION **********************************************


void logScreen();
void Choice1();
int main()
{
	system("cls");
	
	
	system("color 2e");
	Store st;
	Purchase ps;
	Lend_Items le;
	Client cl;

	Shopkeeper sh;
	
	logScreen();
	
	Choice1();
	system("cls");
	cl.display();
	ps.StoreItems();
	sh.myArray();
	sh.No_item_Brwd();
	sh.Lend_Calc();
	le.FineCalc();
	
	
	
	
	
	return 0;
}


//****************************** LOG SCREEN FUNCTION*************************************

void Choice1()
{
	Shopkeeper sh;
	
	cout<<"Proceed With The Following"<<endl;
	cout<<"\n[1] Show Available Items\n[2] Make a Report\n[3] Lease Item\n[4] Exit\n[1/ 2/ 3/ 4]\n\n\
Choose Your Operation"<<endl;
	int nextMove;
	cin>>nextMove;
	switch(nextMove)
	{
		case 1:
			cout<<"\n\n\tThese are the items we have in our store\n\t\t[1] Compact Disks CDs\
\n\t\t[2] Digital Versatile Disks DVDs"<<endl;
			break;
		case 2:
			
			cout<<"Write Your Report Below"<<endl;
			writeReport();
			int view;
			cout<<"View The Report Now? \n1.Yes\n2.No"<<endl;
			cin>>view;
			switch(view)
			{
				case 1:
					readFile();
					break;
				case 2:
					cout<<"Ok, Anyway it The Report was processed successfully"<<endl;
					break;
				default:
					cout<<"Invalid Choice"<<endl;
					break;
				
			}
			
			break;
		case 3:
			sh.No_item_Brwd();
			Invoice();
			break;
		case 4:
			cout<<"Successful Exit"<<endl;
			//waiting(3500);
			logScreen();
			break;
		default:
			cout<<"Invalid Choice"<<endl;
			Choice1();
			break;
		
	}
}

void logScreen()
{
	string password;
	string name3;
	system("cls");
	/*cout<<"\n\n\n\n\t\t\t\xB2\xB2\xB2\xB2              \xB2\xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2\xB2\xB2            \xB2\xB2\xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2 \xB2\xB2          \xB2\xB2 \xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2   \xB2\xB2      \xB2\xB2   \xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2     \xB2\xB2  \xB2\xB2\t   \xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2       \xB2\xB2\t   \xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2\t\t   \xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2\t\t   \xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\xB2\xB2\xB2\xB2\xB2   RENTAL   \xB2\xB2\xB2\xB2\xB2"<<endl;
	cout<<"\t\t\t\tSYSTEM"<<endl;
	
	cout<<"\n\n\t\t      MULTIMEDIA RENTAL SYSTEMS"<<endl;*/
	
	cout<<"\n\n\n\t\t  \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\t\t  \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\n\
\t\t  \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\t         \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\n\
\t\t  \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\t        \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\tMulty Rental Shop\n\
\t\t  \xC5\xC5\xC5\xC5 \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5      \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\n\
\t\t  \xC5\xC5\xC5\xC5  \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5    \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\n\
\t\t  \xC5\xC5\xC5\xC5   \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5  \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\n\
\t\t  \xC5\xC5\xC5\xC5    \xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5\xC5 "<<endl;
cout<<"\n\n\n\n"<<endl;
	
	
	cout<<"\n\n\t\tEnter your Username: ";
	cin>>name3;
	cout<<"                        ";
	
	system("cls");
	cout<<"\n\t\tEnter your Password: ";
	cin>>password;
	
	system("cls");

}
void Invoice()
{
	
	string client;
	cout<<"Enter The name of the Client: ";
	cin>>client;
	cout<<"This is the invoice\n\tName\t|\tItem\t|\tQuantity Leased"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"   "<<client;
}

void readFile()
{
	string line;
	ifstream shopreport("Report.txt");
	if(shopreport.is_open())
	{
		while(getline (shopreport,line))
		{
			cout<<line;
		}
		
		shopreport.close();
		
	}
	else cout<<"Unable to open file"<<endl;
}
