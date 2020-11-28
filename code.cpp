#include<iostream>
#include<conio.h>
#include <cstdio>
#include <string>
#include<string.h>
#include<ctype.h>
#include <fstream>
#include <cstdio>
#include<stdio.h>

#include<stdlib.h>
#include<math.h>

using namespace std;



class donor
{
 private:
   long int donorid;
   char donorname[40];
   char bloodgroup2[20];
   int age;
   char gender[20],nationality[50];
   char prehistory;
   char detailsofprehistory[100];

 public:
  donor()
  { donorid=1003;}
   void enterddetails();
   void displayspedonor();
   char *retbloodgroup2()
    {
      return bloodgroup2;
    }
   long retdonorid()
    {
      return donorid;
    }
   void displaydonor()
    {

      cout<<"     ";
      cout<<donorid;
      cout<<"     ";

      cout<<donorname;
      cout<<endl;
   }
   
 };
void donor::displayspedonor()
   {

      cout<<"       DONOR DETAILS";
cout<<endl;
      cout<<"DONOR ID   : ";
      cout<<donorid;
cout<<endl;
      cout<<"DONOR NAME : ";
      cout<<donorname;
cout<<endl;
cout<<"DONOR BLOODGROUP : ";

      cout<<bloodgroup2;
      cout<<endl;

   }

    


void donor::enterddetails()
   {

     cout<<"ENTER ID : ";
     cin>>donorid;
cout<<endl;
     cout<<"ENTER THE FULLNAME : ";
     cin>>donorname;
cout<<endl;
     cout<<"ENTER THE GENDER : ";
     cin>>gender;
     cout<<endl;

     cout<<"ENTER THE AGE : ";
     cin>>age;
     cout<<endl;


     cout<<"ENTER THE BLOODGROUP : ";
     cin>>bloodgroup2;
     //int* x=stock( bloodgroup2);
     
     cout<<endl;
cout<<"In case you are a patient of cancer,artheritis,diabetes,epilepsy, asthma or heart disease"<<endl;
	 cout<<"please mention and submit an approval from physician is required"<<endl;
	 cout<<endl;
     cout<<"ENTER y FOR PREVIOUS MEDICAL HISTORY ELSE ENTER n : ";
     cin>>prehistory;
     if(prehistory=='y')
       {


	 cout<<"ENTER THE HISTORY DETAILS-"<<endl;
	 cin.get(detailsofprehistory,100);
       }

  }

void adddonor()
   {
        cout<<endl;
cout<< "        *     *     *     *     *     *     *     *     *"<<endl;
     cout<<"       ADDING DONOR MENU";
     cout<<endl;
cout<< "Please enter the following details to check the eligibility for donation:" <<endl;
     cout<<endl;
     int weight;
     char option;
     int res=0;
     cout<< "Enter weight:  ";
     cin>>weight;
     if (weight<=50)
        {option= 'y';
        res=1;}
     cout<<endl;
     cout<<"Are you pregnant: (y/n)"<<endl;
     cin>>option;
     if (option=='y')
        res=1;
     cout<<"Are you allergic: (y/n)"<<endl;
     cin>>option;
      if (option=='y')
        res=1;
     cout<<"Have you donated plasma previously in last 72 hours: (y/n)" <<endl;
     cin>>option;
      if (option=='y')
        res=1;
     cout<<"Have you consumed alcohol in the last 24 hours (y/n)"<<endl;
     cin>>option;
      if (option=='y')
        res=1;
cout<<endl;
if (res==0)
{cout<<"You successfully meet the required criteria for plasma donation,please fill in the required details "<<endl;
cout<<endl;

     fstream x;
     x.open("donor.dat",ios::app|ios::binary);
     donor d;
     d.enterddetails();
     x.write((char *)&d,sizeof(d));
     x.close();
}
else {cout<<"Sorry, you do not meet the required criteria for plasma donation. Returning to Main Menu."<<endl;
cout<<endl;}
cout<< "        *     *     *     *     *     *     *     *     *"<<endl;
   
   }
void displayalldonors()
   {
     cout<<"DONOR ID  ";
     

     cout<<"DONOR NAME";
     cout<<endl;
     fstream x;
     x.open("donor.dat",ios::in|ios::binary);
     donor d;
     
     while(x.read((char *)&d,sizeof(d)))
       {
	  d.displaydonor();
	  
       }
     x.close();
     cout<< "        *     *     *     *     *     *     *     *     *"<<endl;
  }
void displaydonorid()
  {

    fstream x;
    int di;

    cout<<"\n Enter the donor id to be displayed";
    cin>>di;
    cout<<endl;
    x.open("donor.dat",ios::in|ios::binary);
    donor d;
    while(x.read((char *)&d,sizeof(d)))
      {if(di==d.retdonorid())
	     d.displayspedonor();
      }
    x.close();
    cout<< "        *     *     *     *     *     *     *     *     *"<<endl;
  }
void deletedonor()
  {

    long id;
    ifstream x;
    ofstream y;
    x.open("donor.dat",ios::binary);
    y.open("temp.dat",ios::binary);


    cout<<"DELETING THE RECORD";
cout<<endl;

    cout<<"ENTER THE ID TO BE DELETED";
    cin>>id;
    cout<<endl;
    donor d;
    long r=0;
    char b[50];
    while(x.read((char*)&d,sizeof(d)))
    
     {r=d.retdonorid();
         
       if(id!=d.retdonorid())
	 {
	    y.write((char*)&d,sizeof(d));
	 }
	 //else removestock(d.retbloodgroup2(),x);
	 
     }
    remove("donor.dat");
    rename("temp.dat","donor.dat");
    x.close();
    y.close();
   cout<< "        *     *     *     *     *     *     *     *     *"<<endl;
  }
  
class patient
{
 private:
   long  patientid;
   char patientname[40];
   char bloodgroup1[20];
   int  age;
   char gender[20];

 public:
   void enterddetails();

   char *retbloodgroup1()
    {
      return bloodgroup1;
    }
   long retpatientid()
    {
      return patientid;
    }

   void displaypatient( )
    {

    cout<<"     ";
      cout<<patientid;
      cout<<"     ";

      cout<<patientname;
      cout<<endl;
   }
   void displayspepatient()
    {

      cout<<"    PATIENT DETAILS    ";
cout<< endl;
      cout<<"PATIENT ID   : ";
      cout<<patientid;
cout<<endl;
      cout<<"PATIENT NAME : ";

      cout<<patientname;
cout<<endl;
    cout<<"PATIENT BLOODGROUP : ";

      cout<<bloodgroup1;
      cout<<endl;
   }
  
};
void patient::enterddetails()
   {
      cout<<"ENTER ID : ";
     cin>>patientid;

     cout<<"ENTER THE FULLNAME : ";
     cin>>patientname;
    cout<<endl;
     cout<<"ENTER THE GENDER : ";
     cin>>gender;
     cout<<endl;

     cout<<"ENTER THE AGE : ";
     cin>>age;
     cout<<endl;

     cout<<"ENTER THE BLOODGROUP required : ";
     cin>>bloodgroup1;
     cout<<endl;



}

void addpatient()
   {



cout<< "        *     *     *     *     *     *     *     *     *"<<endl;
     cout<<"  ADDING PATIENT MENU  ";
     cout<<endl;
     fstream x;
     x.open("patient.dat",ios::app|ios::binary);
     patient p;
     p.enterddetails();
     x.write((char *)&p,sizeof(p));
      x.close();
      int f=0;
     cout<<" The patient has been recorded\n";
     cout<<"\n";
     cout<<"Cucrrent Avalibilty status:\n";
       ifstream y;
     y.open("donor.dat",ios::binary);
     
     donor d;
     string b= p.retbloodgroup1();
     
     string c;
      while(y.read((char *)&d,sizeof(d)))
      {
          c= d.retbloodgroup2();
      
          if((b.compare(c)) == 0)
          {
            cout<<" This blood group is avalaible"<<endl;
            f=1;
            
          }
          if (f==1)
          break;
	

      }
      if (f==0)
      cout<<"This blood group is not avalaible"<<endl;
    
     y.close();
     
     
     cout<< "        *     *     *     *     *     *     *     *     *"<<endl;
     
     
   }
void displayallpatients()
   {

     cout<<"PATIENT ID : ";


     cout<<"PATIENT NAME : ";
     cout<<endl;
     fstream x;
     x.open("patient.dat",ios::in|ios::binary);
     patient p;

     while(x.read((char *)&p,sizeof(p)))
      {
	p.displaypatient();

      }
     x.close();
     cout<< "        *     *     *     *     *     *     *     *     *"<<endl;
   }
void displaypatientid()
   {


     cout<<"   DISPLAY MENU   ";
     cout<<endl;
     fstream x;
     long di;

     cout<<"\n Enter the patient id to be displayed : ";
     cin>>di;
     cout<<endl;
     x.open("patient.dat",ios::in|ios::binary);
     patient p;
     while(x.read((char *)&p,sizeof(p)))
       {if(di==p.retpatientid())
	 p.displayspepatient();
       }
     x.close();
     cout<< "        *     *     *     *     *     *     *     *     *"<<endl;
   }

void deletepatient()
  { 
     long n;
     patient p;
     ofstream y;
     ifstream x;
     x.open("patient.dat",ios::binary);
     y.open("temp.dat",ios::binary);
      cout<<"DELETING THE RECORD";
cout<<endl;

    cout<<"ENTER THE ID TO BE DELETED";
    cin>>n;
    cout<<endl;
     long r=0;
    
     while(x.read((char*)&p,sizeof(p)))
      {r=p.retpatientid();
       if(p.retpatientid()!=n)
       y.write((char*)&p,sizeof(p));
      }
      remove("patient.dat");
     rename("temp.dat","patient.dat") ;
     x.close();
     y.close();
     
     cout<< "        *     *     *     *     *     *     *     *     *"<<endl;
     
     
  } 



int main()
  {
    int ch1=0,ch2=0,ch3=0;
    do
     {

cout<< "PLASMA DONATION CENTER"<<endl;
       cout<<"        MAIN MENU       ";

       cout<<"1. Donor Menu ";

       cout<<"2. Patient Menu ";

       cout<<"3. EXIT ";
       cout<<endl;
       cout<<"Enter your choice : ";
       cin>>ch1;
       cout<<endl;
       cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;

       switch(ch1)
	 {
	   case 1:
	   do
	    {

	       cout<<"   PLASMA DONATION CENTER: DONOR MENU   "<<endl;

	       cout<<"1. ADD A DONOR ";

	       cout<<"2. DISPLAY DONOR LIST ";

	       cout<<"3. DISPLAY DONORS DETAILS";


	       cout<<"4. DELETE A DONOR RECORD ";

	       cout<<"5.EXIT ";
           cout<<endl;
	       cout<<" ENTER YOUR CHOICE ";
	       cin>>ch2;
	       switch(ch2)
		{
		 case 1:adddonor();
			break;
		 case 2:displayalldonors();
			break;
		 case 3:displaydonorid();
			break;


		 case 4:deletedonor();
			break;
		 case 5:exit(0);
		}
	    } while(ch2<=6);
	       break;
	   case 2:
	   do
	    {



	       cout<<"  PLASMA DONATION CENTER: PATIENT MENU   "<<endl;;

	       cout<<"1. add a patient";

	       cout<<"2. display patients list";

	       cout<<"3. display patient details";


	       cout<<"4.delete a patient";

	       cout<<"5.exit";
           cout<<endl;
	       cout<<"enter your choice ";
	       cin>>ch3;
	       
	       switch(ch3)
		 {
		  case 1:addpatient();
			 break;
		  case 2:displayallpatients();
			 break;
		  case 3:displaypatientid();
			 break;


		  case 4:deletepatient();
			 break;
		 
		  case 5:exit(0);
		  }
	    }while(ch3<=7);
	      break;
	   case 3:exit(0);
	 }
       }while(ch1<=3);
return 0;
  }

