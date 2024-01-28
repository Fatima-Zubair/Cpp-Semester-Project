#include<iostream> 
#include<conio.h>
#include<iomanip>
#include<windows.h>
#include<string>
using namespace std;

const int maxrow=10;
string PatName[maxrow]={};
int AppNo[maxrow]={};
int PatAge[maxrow]={};
string PatTest[maxrow]={};
int PatFee[maxrow]={};

 void setclr(int y){
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),y);
 }
 
class appointment{
	private:
	char pname[50];
	int pcount=0; //password count(attempts)
    int pflag;
    char name [50];
    string password="mypassword";  // the set password
    string passkey;                //user entered password
    int max=5;
	int age;
	int fee;
	int input;
	int appno=0; //variable for patient appointments
	int test;
	string type;

public:
	
void uname(){
	cin.ignore();
	cout<<"\n\n\t\t\t\t\tPlease enter your name : ";
	cin.getline(name,50);                 //user name
	system("cls");
	
	 for(int i=0; i<50; i++)
	 {
	 	if (i==0){
	 		name[i]=toupper(name[i]);
		 }
		 else{
		 
		 name[i]=tolower(name[i]);
	     }
	 }	
	 
	cout<<"\n\n\n\n\n\t\t\t\t\tWarm regards to "<<name<<" from our team ";
	cout<<"\n\n\t\t\t\t\tPlease select option from menu below "<<endl;
	menu();}
	void welcome(){
		setclr(3);
	cout<<"\n\n\n\n\n\n\n ";
	cout<<"\t\t     __      __      __     ___________     __              __________        __________      ______      ______     ___________"
	  <<"\n\t\t    |  |    /  \\    |  |   |  _________|   |  |            /   ________\\    /   ______  \\    |   _  \\    /  _   |   |  _________|"
	  <<"\n\t\t    |  |   /    \\   |  |   |  |____        |  |            |  |             |  |      |  |   |  | \\  \\  /  / |  |   |  |____   "
	  <<"\n\t\t    |  |  /  /\\  \\  |  |   |   ____|       |  |            |  |             |  |      |  |   |  |  \\  \\/  /  |  |   |   ____|"
	  <<"\n\t\t    |  |_/  /  \\  \\_|  |   |  |________    |  |________    |  |________     |  |______|  |   |  |   \\    /   |  |   |  |________"
      <<"\n\t\t    |______/    \\______|   |___________|   |___________|   \\___________/    \\____________/   |__|    \\__/    |__|   |___________|";
    
   // cout<<"\n\n\n\t\t\t\t\t ___________________________________________________________________________________";
   //cout<<"\n\n\n\t\t\t\t\t ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
   cout<<"\n\n\n\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<"\n\t\t\t\t\t| THIS IS APPOINTMENT MANAGEMENT SYSTEM OF MEDICAL IMAGING AND DIAGNOSTICS LABORATORY |";
    cout<<"\n\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    //cout<<"\n\t\t\t\t\t ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
    
    cout<<"\n\n\t\t\t\t\t Press any key to continue . . . ";
    getch();
	system("cls");
	
	cout<<"\n\n\n\n\n\t\t\t\t\tPlease enter password to get into the program ";
	cout<<"\n\n\t\t\t\t\tYou have 3 attempts to enter the correct password\n\n";
	int temp=0;
	 for(int j=pcount; j<3 ; j++){
	 
		cin>>passkey;	
      	if (passkey==password)
      	{
      		pflag=1;
		  }
		  else
		{
			pflag=0;
			
		}
		if(pflag==0){
	  	cout<<"\n\n\t\t\t\t\tYour password is incorrect ";
	  	cout<<"\n\n\t\t\t\t\tTry again ";
	  	cout<<"\n\n\t\t\t\t\tThis is your "<<pcount+1<<"attempt";
	  	cout<<"\n\n\t\t\t\t\tTries left : "<<2-pcount;
	  	pcount++;
	  	if(pcount==3)
	  	{cout<<"\n\n\t\t\t\t\tSorry you have failed to enter the correct password";
	  	cout<<"\n\n\t\t\t\t\tWe can't give you access to this program";
	  	break;}
	  }
	  else if (pflag==1){
	        uname();}
	  }
//	  if(pflag==1)
//	  uname();
//	  else
//	  cout<<" .... ";
	}
void details(){
	system("cls");
cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t"<<setw(18)<<"DETAILS";
cout<<"\n\t\t\t\t\t"<<setfill('~')<<setw(20)<<"";
cout<<"\n\n\t\t\t\t\t 1>> Maximum no. of appointments of a day are "<<max;
cout<<"\n\n\t\t\t\t\t 2>> We are providing you four types of imaging tests for which you can set your appointments";
cout<<"\n\n\t\t\t\t\t     (i) Ultrasound (ii) X-ray (iii) CT-Scan (iv) MRI ";
cout<<"\n\n\t\t\t\t\t 3>> Fee for each test is given below ";
cout<<"\n\n\t\t\t\t\t      TEST\t\tFEES";
cout<<"\n\n\t\t\t\t\t    Ultrasound\t\t2000 ";
cout<<"\n\n\t\t\t\t\t    X-ray\t\t800 ";
cout<<"\n\n\t\t\t\t\t    CT-Scan\t\t600 ";
cout<<"\n\n\t\t\t\t\t    MRI\t\t\t300 ";
cout<<"\n\n\n\t\t\t\t\tPress any key to continue ... ";
getch();
 	
}

void getdata(){
system("cls");
   
	appno++;
        if(appno>max){
        	cout<<endl<<" Now all appointments are booked. Please come tomorrow ";
			}
			else
			{
        cout<<endl<<" Please enter the details of new appointment "<<endl<<endl;
		cout<<endl<<" Appointment No: "<<appno<<endl;
       cin.ignore();
		cout<<endl<<" Patient Name : ";
		cin.getline(pname,50);
		cout<<endl<<" Patient age : ";
		cin>>age;
		cin.ignore();
		cout<<endl<<" Select the test: \n1. ULTRASOUND\n2. X-RAY\n3. CT-SCAN\n4. MRI  ";
		cin>>test;
		if(test==1)
		type="ULTRASOUND";
		else if (test==2)
		type="X-RAY";
		else if (test==3)
		type="CT-SCAN";
		else if (test==4)
		type="MRI";
		if(test==1)
		 {
		 fee=2000;
		 cout<<" Your fees for ULTRASOUND is : "<<fee<<endl<<endl;}	
			else if(test==2)
		 {
		 fee=800;
		 cout<<" Your fees for X-RAY is : "<<fee<<endl<<endl;	}
		 	else if(test==3)
		 {
		 fee=600;
		 cout<<" Your fees for CT-SCAN is : "<<fee<<endl<<endl;	}
		 	else if(test==4)
        {
		 fee=300;
		 cout<<" Your fees for MRI is : "<<fee<<endl<<endl; }
		 else
		 cout<<" Invalid input "<<endl<<endl;
		 cin.ignore();
		 	for(int i=0; i<maxrow; i++){
			if (AppNo[i]=='\0'){
				AppNo[i]=appno;
				PatName[i]= pname;
				PatAge[i]= age;
				PatTest[i]= type;
				PatFee[i]= fee;
				break;
			}
		}
		 getche();
		 system("cls");
		 menu();
		 }
	}

void showdata(){
	system("cls");
	cout<<"\n\n\t\t\t\t\tCurrent appointment(s) ";
	cout<<"\n\t\t\t\t------------------------------";
	int counter=0;
	for(int i=0; i<maxrow; i++){
		if(AppNo[i]!='\0'){
		
	counter++;
	cout<<endl<<" Appointment No: "<<AppNo[i]<<endl;
	cout<<endl<<" Patient Name  : "<<PatName[i]<<endl;
	cout<<endl<<" Patient age   : "<<PatAge[i]<<endl;
	cout<<endl<<" Test type     : "<<PatTest[i]<<endl;
	cout<<endl<<" Fees          : "<<PatFee[i]<<endl;
}
}
if (counter==0){
	cout<<endl<<" No record found "<<endl;
}
cout<<endl<<" Press any key to continue ... "<<endl;
getch();
}

void searchdata( int search){
system("cls");
	cout<<"\n\n\t\t\t\t\tAPPOINTMENT ";
	cout<<"\n\t\t\t\t------------------------------";
	int counter=0;
	for(int i=0; i<maxrow; i++){
		if(AppNo[i]==search){
		
	counter++;
	cout<<endl<<" Appointment No: "<<AppNo[i]<<endl;
	cout<<endl<<" Patient Name  : "<<PatName[i]<<endl;
	cout<<endl<<" Patient age   : "<<PatAge[i]<<endl;
	cout<<endl<<" Test type     : "<<PatTest[i]<<endl;
	cout<<endl<<" Fees          : "<<PatFee[i]<<endl;
	break;
}
}
if (counter==0){
	cout<<endl<<" No record found...!"<<endl;
}
cout<<endl<<" Press any key to continue ... "<<endl;
getch();

}

void deletedata( int search){
int counter=0;
	for(int i=0; i<maxrow; i++){
		if(AppNo[i]==search){
		
	counter++;
	AppNo[i]=0;
	PatName[i]="---";
	PatAge[i]=0;
	PatTest[i]="---";
	PatFee[i]=0;
	cout<<endl<<" Appointment deleted successfully...!"<<endl;
	break;
}
}
if (counter==0){
	cout<<endl<<" No appointment found...!"<<endl;
}
cout<<endl<<" Press any key to continue ... "<<endl;
getch();

	
}

void menu(){
	int count; // this will take the input of appno to be displayed
	
	do{
cout<<"\n\n\n\t\t\t\t\t"<<setfill('~')<<setw(40)<<"";
cout<<"\n\t\t\t\t\t"<<setw(18)<<"MENU";
cout<<"\n\t\t\t\t\t"<<setfill('~')<<setw(40)<<"";
cout<<"\n\n\t\t\t\t\t 1>>See details of appointments of a day";
cout<<"\n\n\t\t\t\t\t 2>>Set data for new appointments ";
cout<<"\n\n\t\t\t\t\t 3>>Show details of appointments entered";
cout<<"\n\n\t\t\t\t\t 4>>Search appointment ";
cout<<"\n\n\t\t\t\t\t 5>>Delete details ";
cout<<"\n\n\t\t\t\t\t 6>>Exit";
cout<<"\n\n\t\t\t\t Enter your Choice ";
cin>>input;
switch(input){

case 1:
{
	
details();
system("cls");
break;}

case 2:
{
getdata();
break;}

case 3:{
	showdata();
	system("cls");
	break;
}

case 4:{
	 system("cls");
	cout<<endl<<" Search by appointment number ";
	cin>>count;
	searchdata(count);
	system("cls");
	break;}
	
case 5:{
	system("cls");
	cout<<endl<<" Enter appointment number of which you want to delete details ";
	cin>>count;
	deletedata(count);
	break;
}
case 6:{
	system("cls");
	cout<<"\n\n***PROGRAM ENDS***";
	exit(0);
	break;
}
}
}
while(input!=6);
}
};
int main(){
	appointment a;
	a.welcome();
	//cout<<"\n\n\t\t***PROGRAM ENDS***";
}
