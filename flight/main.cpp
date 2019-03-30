#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string>
#include<windows.h>
#include<ctime>
#include<fstream>
#include<math.h>

using namespace std;
const char ESC ='27';
char l_destination[10][30]={"BANGALORE","HYDERABAD","MUMBAI","DELHI","CHENNAI"};
char i_destination[15][30]={"LONDON","BERLIN","DUBAI","NEW YORK","BEIJING","PARIS","CAPE TOWN","TOKYO","LOS ANGELES","SYDNEY" };
string flights[]={"64E","68EF","83A","ME35","34A7","FD54","9E47","GR03"};
int b_seat=2;
int e_seat=40;
int b1_seat=30;
int e1_seat=40;
class passenger
{
public:
    virtual void getdata()
 {
 }
virtual void show()
 {
 }
};
class booking:public passenger
{
protected:
 int num;
 char ch;
 char firstname[60];
 char lastname[60];
 char address[60];
 char c_loc[30];
 char dest[30];
 char passport_no[60];
 char ph_no[20];
 int option;
public:
 void getdata()
 {
  cout<<setw(40)<<"\n\n        ::Please enter the required information for passenger number::"<<endl;
  cout<<"\n\n\nEnter the firstname of passenger: ";
   gets(firstname);
   cout<<endl;
   cout<<"Enter the lastname of passenger: ";
   gets(lastname);
   cout<<endl<<endl;
   cout<<"Enter address of passenger:  ";
   gets(address);
   cout<<endl;
   cout<<"Enter phone no. of passenger:  ";
   gets(ph_no);
   cout<<endl;
   cout<<"Enter the Passport No.: ";
   gets(passport_no);
   cout<<endl;
loop:
    cout<<"Enter the current location of passenger(IN CAPITAL LETTERS ONLY):  ";
    gets(c_loc);
    cout<<endl<<endl;
    cout<<"Enter the destination of passenger(IN CAPITAL LETTERS ONLY):  ";
    gets(dest);
 int a=strcmp(c_loc,dest);
 if(a==0)
 {
   cout<<"location and destination cannot be same!!"<<endl;
    goto loop;
 }
    cout<<endl<<endl;
   system("CLS");
 }
 void show()
 {
     time_t now=time(0);
 char* dt =ctime(&now);
 tm *ltm =localtime(&now);
   int a = rand()%7;
   int b = rand()%4;
   cout<<setw(40)<<"Your E-Ticket is :"<<endl;
   int t=1;
   int r=12345;
  cout<<"                           AIRLINE TICKET                                 "<<endl;
  cout<<"|Ticket No."<<t<<"                                Reference No."<<r<<"\t  "<<endl;
  cout<<"|_________________________________________________________________________"<<endl;
  cout<<"|Passport No. :"<<passport_no<<"                                     "<<endl;
  cout<<"|__________________________________________________________________________"<<endl;
  cout<<"|Passenger Information :                                                  "<<endl;
  cout<<"|Name :"<<lastname<<"/"<<firstname<<"                                     "<<endl;
  cout<<"|                                                                         "<<endl;
  cout<<"|Address :"<<address<<"                                                   "<<endl;
  cout<<"|Phone No. :"<<ph_no<<"                                                   "<<endl;
  cout<<"|_________________________________________________________________________"<<endl;
  cout<<"|Departure Time(hh:mm): "<<1+ltm->tm_hour<<":"<<ltm->tm_min<<"hrs                       "<<endl;
  cout<<"|Arrival Time(hh:mm): "<<b+ltm->tm_hour<<":"<<ltm->tm_min<<"hrs                       "<<endl;
  cout<<"|Depart :"<<c_loc<<"                                                      "<<endl;
  cout<<"|Arrive :"<<dest<<"                                                       "<<endl;
  cout<<"|Flight No. : "<<flights[a]<<endl;
  cout<<"|_________________________________________________________________________"<<endl;
  cout<<"|*BAGGAGE allowed 25 Kilos                                                "<<endl<<endl;
  cout<<"|*contact Airline to Confirm baggage allowance                            "<<endl;
  cout<<"|                                                                         "<<endl;
  cout<<"|"<<dt<<"                                                                 "<<endl;
  cout<<"|_________________________________________________________________________"<<endl;


ofstream outfile("E:\\E_ticket.txt");
        outfile<<"                           AIRLINE TICKET                                 "<<endl<<
   "|Ticket No."<<t<<"                                Reference No."<<r<<"\t  "<<endl<<
      "|_________________________________________________________________________"<<endl<<
   "|Passport No. :"<<passport_no<<"                                      "<<endl<<
   "|__________________________________________________________________________"<<endl<<
      "|Passenger Information :                                                  "<<endl<<
      "|Name :"<<lastname<<"/"<<firstname<<"                                     "<<endl<<
      "|                                                                         "<<endl<<
      "|Address :"<<address<<"                                                   "<<endl<<
      "|Phone No. :"<<ph_no<<"                                                   "<<endl<<
      "|_________________________________________________________________________"<<endl<<
      "|                                                                         "<<endl<<
      "|Departure Time: "<<1+ltm->tm_hour<<":"<<1+ltm->tm_min<<"hrs                       "<<endl<<
      "|Arrival Time: "<<b+ltm->tm_hour<<":"<<b+ltm->tm_min<<"hrs                       "<<endl<<
      "|Depart :"<<c_loc<<"                                                      "<<endl<<
      "|Arrive :"<<dest<<"                                                       "<<endl<<
      "|Flight No. : "<<flights[a]                                                          <<endl<<
      "|_________________________________________________________________________"<<endl<<
      "|*BAGGAGE allowed 25 Kilos                                                "<<endl<<
      "|*contact Airline to Confirm baggage allowance                            "<<endl<<
      "|                                                                         "<<endl<<
      "|"<<dt<<
      "|_________________________________________________________________________"<<endl;


      fstream file;
        file.open("E:\\db.txt", ios::out|ios::app);
        file<<"\n\n                           AIRLINE TICKET                                 "<<endl;
  file<<"|_________________________________________________________________________"<<endl;
  file<<"|Passport No. :"<<passport_no<<"                                     "<<endl;
  file<<"|__________________________________________________________________________"<<endl;
  file<<"|Passenger Information :                                                  "<<endl;
  file<<"|Name :"<<lastname<<"/"<<firstname<<"                                     "<<endl;
  file<<"|                                                                         "<<endl;
  file<<"|Address :"<<address<<"                                                   "<<endl;
  file<<"|Phone No. :"<<ph_no<<"                                                   "<<endl;
  file<<"|_________________________________________________________________________"<<endl;
  file<<"|Departure Time: "<<1+ltm->tm_hour<<":"<<ltm->tm_min<<"hrs                  "<<endl;
  file<<"|Arrival Time: "<<b+ltm->tm_hour<<":"<<ltm->tm_min<<"hrs                 "<<endl;
  file<<"|Depart :"<<c_loc<<"                                                      "<<endl;
  file<<"|Arrive :"<<dest<<"                                                       "<<endl;
  file<<"|Flight No. : "<<flights[a]<<endl;
  file<<"|_________________________________________________________________________"<<endl;
file.close();
t=t+1;
r=r+1;
 }
};

class local: public booking
{
protected:
 int e_seat;
 int ch;
 int k;
 int p;
 int option;

public:
 void getdata()
 {
l:
  k=0;
  p=0;
  cout<<"In which AIRLINE you want to travel"<<endl<<endl;
  cout<<"1)AIR INDIA"<<endl;
  cout<<"2)INDIGO"<<endl;
  cout<<"3)ARAB EMIRATES"<<endl;
  cout<<"4)SPICE JET"<<endl;
  cout<<"enter your choice"<<endl;;
  cin>>option;
  system ("cls");
  switch(option)
  {
  case 1:
   if (option==1)
    cout<<setw(40)<<"\n\n\n                                WELCOME TO AIR INDIA"<<endl;
   break;
  case 2:
   if(option==2)
    cout<<setw(40)<<"\n\n\n                                WELCOME TO INDIGO"<<endl;
   break;
  case 3:
   if(option==3)
    cout<<setw(40)<<"\n\n\n                                WELCOME TO ARAB EMIRATES"<<endl;
   break;
  case 4:
   if(option==4)
    cout<<setw(40)<<"\n\n\n                                WELCOME TO SPICE JET"<<endl;
   break;
  }
  cout<<setw(40)<<"\nTHESE ARE THE LOCAL PLACES AVAILABLE\n\n\n"<<endl;
  cin.ignore();
  for(int i=0;i<5;i++)
  {
   cout<<l_destination[i]<<endl;
  }
  booking::getdata();
  for(int j=0;j<5;j++)
  {
   if(strcmp(l_destination[j],c_loc)==0)
   {
    k++;
   }
  }
  for( int i=0;i<5;i++)
  {
   if(strcmp(l_destination[i],dest)==0)
   {
    p++;
   }
  }
  if(k==1&&p==1)
  {
   cout<<" FLIGHT AVAILABLE ON THIS ROUTE"<<endl;
   cout<<"In which class you want to travel?"<<endl;
   cout<<"Make your choice"<<endl<<endl;
   cout<<"\n\n\n\n\n\n";
   cout<<setw(60)<<"     Press 1 for buisness class    "<<endl;
   cout<<setw(60)<<"\n\t\t\t     Press 2 for economy class     "<<endl;
   cout<<"Enter your choice"<<endl;
   cin>>ch;
   cout<<endl;
   switch(ch)
   {
   case 1:
    b_seat--;
    if(b_seat<=0)
{
     cout<<"SORRY NO SEAT AVAILABLE"<<endl;
     cout<<"try another airlines!"<<endl;
     getch();
     system("CLS");
     goto l;
}
    else
     cout<<"SEAT AVAILABLE"<<endl;
     getch();
    break;
   case 2:
    e_seat--;
    if(e_seat<=0)
   {
       cout<<"SORRY NO SEAT AVAILABLE"<<endl;
     cout<<"try another airlines!"<<endl;
     getch();
     system("CLS");
     goto l;
   }
    else
     cout<<"SEAT AVAILABLE"<<endl;
     getch();
    break;
   }
   system("CLS");
   booking::show();
   if(ch==1)
  {
    cout<<"|                                                                         "<<endl;
    cout<<"|Ticket Information:                                                      "<<endl;
    cout<<"|BUISNESS CLASS                                                           "<<endl;

    ofstream outfile;
    outfile.open("E:\\E_ticket.txt",ios::app);
    outfile<<"|                                                                         "<<endl<<
             "|Ticket Information:                                                      "<<endl<<
             "|BUISNESS CLASS                                                           "<<endl;

   }
   if(ch==2)
   {
    cout<<"|                                                                         "<<endl;
    cout<<"|Ticket Information:                                                      "<<endl;
    cout<<"|ECONOMY CLASS                                                            "<<endl;

    ofstream outfile;
    outfile.open("E:\\E_ticket.txt",ios::app);
    outfile<<"|                                                                         "<<endl<<
             "|Ticket Information:                                                      "<<endl<<
             "|ECONOMY CLASS                                                           "<<endl;
   }

       cout<<"|Status: confirmed                                                        "<<endl;

    ofstream outfile;
    outfile.open("E:\\E_ticket.txt",ios::app);
    outfile<<"|Status: confirmed                                                        "<<endl;
  }
  else
  {
     cout<<"__________________________________________________________________________"<<endl;
     cout<<"|     SORRY NO FLIGHT AVAILABLE ON THIS ROUTE RIGHT NOW  !!                 "<<endl;
     cout<<"__________________________________________________________________________"<<endl;
  }
}
 };

 class international:public booking
 {
 protected:
  int choice;
  int c;
  int b;
  int v;
  char g;
 public:

  void getdata()
  {
      l:
   b=0;
   v=0;
  cout<<"In which AIRLINE you want to travel"<<endl<<endl;
  cout<<"1)AIR INDIA"<<endl;
  cout<<"2)INDIGO"<<endl;
  cout<<"3)ARAB EMIRATES"<<endl;
  cout<<"4)SPICE JET"<<endl;
  cout<<"enter your choice"<<endl;;
  cin>>option;
  system ("cls");
  switch(option)
  {
  case 1:
   if (option==1)
    cout<<setw(40)<<"\n\n\n                                WELCOME TO AIR INDIA"<<endl;
   break;
  case 2:
   if(option==2)
    cout<<setw(40)<<"\n\n\n                                WELCOME TO INDIGO"<<endl;
   break;
  case 3:
   if(option==3)
    cout<<setw(40)<<"\n\n\n                                WELCOME TO ARAB EMIRATES"<<endl;
   break;
  case 4:
   if(option==4)
    cout<<setw(40)<<"\n\n\n                                WELCOME TO SPICE JET"<<endl;
   break;
  }
   cout<<"\n\nTHESE ARE THE INTERNATIONAL PLACES AVAILABLE"<<endl<<endl;
   cin.ignore();
   for(int i=0;i<10;i++)
   {
    cout<<i_destination[i]<<endl;
   }
   booking::getdata();
   for(int j=0;j<10;j++)
   {
    if(strcmp(i_destination[j],dest)==0)
    {
     v++;
    }
   }
   for( int i=0;i<5;i++)
   {
    if(strcmp(l_destination[i],c_loc)==0)
    {
     b++;
    }
   }
   if(b==1&&v==1)
   {
    cout<<" FLIGHT AVAILABLE ON THIS ROUTE"<<endl;
    b1_seat=30;
    e1_seat=40;
    cout<<"In which class you want to travel?"<<endl;
    cout<<"Make your choice"<<endl<<endl;
    cout<<"\n\n\n\n\n\n";
    cout<<setw(60)<<"     Press 1 for buisness class    "<<endl;
    cout<<setw(60)<<"\n\t\t\t     Press 2 for economy class     "<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    cout<<endl;
  switch(choice)
  {

  case 1:
   b1_seat--;
   if(b1_seat<=0)
   {
     cout<<"* SORRY NO SEAT AVAILABLE!"<<endl;
     cout<<"try another airlines!"<<endl;
    getch();
   }

   else
   {
       cout<<"* SEAT AVAILABLE"<<endl;
    getch();

   }

   break;

  case 2:
   e1_seat--;
   if(e1_seat<=0)
  {
       cout<<"SORRY NO SEAT AVAILABLE"<<endl;
     cout<<"try another airlines!"<<endl;
     getch();
     system("CLS");
     goto l;
   }
    else
     cout<<"SEAT AVAILABLE"<<endl;
     getch();
    break;
   }
  system("CLS");
  booking::show();
  if(choice==1)
  {
    cout<<"|                                                                         "<<endl;
    cout<<"|Ticket Information:                                                      "<<endl;
    cout<<"|BUISNESS CLASS                                                           "<<endl;
    ofstream outfile;
    outfile.open("E:\\E_ticket.txt",ios::app);
    outfile<<"|                                                                         "<<endl<<
             "|Ticket Information:                                                      "<<endl<<
             "|BUSINESS CLASS                                                           "<<endl;

  }

  if(choice==2)
  {
    cout<<"|                                                                         "<<endl;
    cout<<"|Ticket Information:                                                      "<<endl;
    cout<<"|ECONOMY CLASS                                                           "<<endl;

    ofstream outfile;
    outfile.open("E:\\E_ticket.txt",ios::app);
    outfile<<"|                                                                         "<<endl<<
             "|Ticket Information:                                                      "<<endl<<
             "|ECONOMY CLASS                                                           "<<endl;

  }

  cout<<"|Status: confirmed                                                        "<<endl;

  ofstream outfile;
    outfile.open("E:\\E_ticket.txt",ios::app);
    outfile<<"|Status: confirmed                                                        "<<endl;
   }
   else

   {
    cout<<"__________________________________________________________________________"<<endl;
     cout<<"|     SORRY NO FLIGHT AVAILABLE ON THIS ROUTE RIGHT NOW !!                  "<<endl;
   cout<<"__________________________________________________________________________"<<endl;

   }
}
 };


class database
{
public:
void display_members()
{
    string getcontent;
    ifstream openfile ("E:\\db.txt");
    if(openfile.is_open())
    {
      streampos current = openfile.tellg();
openfile.seekg (0, openfile.end);
bool empty = !openfile.tellg(); // true if empty file
openfile.seekg (current, openfile.beg);
       if(empty==1)
        cout<<"\n\n\n\t\t\t\t DATABASE EMPTY!!";
       else

        while(! openfile.eof())
        {
            getline(openfile, getcontent);
            cout << getcontent << endl;
        }
    }
    openfile.close();
}
void clear_dt(){
    ifstream openfile ("E:\\db.txt", ios::out |ios::trunc);
    cout<< "\n\n\n\t\t\t\t  DATABASE DELETED !!";
}
};
 class main1
 {
 private:
  char f;
  int menu_choice;
  char a;
 public:

void getdata()
{
m:
   cout<<"\n\n\n\n\n\n";
   cout<<setw(75)<<"          \t     AIRWAYS RESERVATION SYSTEM       "<<endl;
   cout<<setw(80)<<"\n\t\t\t\t\t           MAIN MENU             "<<endl;
   cout<<setw(80)<<"\n\t\t\t\t\t   PRESS 1 FOR LOCAL BOOKING       "<<endl;
   cout<<setw(80)<<"\n\t\t\t\t\t PRESS 2 FOR INTERNATIONAL BOOKING "<<endl;
   cout<<setw(80)<<"\n\t\t\t\t\t   PRESS 3 FOR DISPLAY DATABASE   "<<endl;
   cout<<setw(80)<<"\n\t\t\t\t        PRESS 4 FOR DELETE DATABASE   "<<endl;
   cout<<setw(80)<<"\n\t\t\t\t\t          PRESS 5 FOR EXIT   "<<endl;
   cout<<setw(80)<<"\n\t\t\t\t\t        ENTER YOUR CHOICE:      "<<endl;
   cin>>menu_choice;
  system("cls");
   passenger* p1;
   booking b1;
   international i1;
   local l1;
   database s;
   char back;
   switch(menu_choice)
   {
   case 1:
    p1=&l1;
    p1->getdata();
    cout<<"To Go To Main Menu Press ESC"<<endl;
    back=getch();
    system("CLS");
    if (back==27)
    {
     goto m;
    }
    else
    {
     cout<<"\n\n\n\n\n\n";
     cout<<setw(40)<<"Closing airline reservation system!";
    }
    break;

   case 2:
    p1=&i1;
    p1->getdata();
   cout<<"To Go To Main Menu Press ESC"<<endl;

    back=getch();


    system("CLS");

    if (back==27)

    {

     goto m;

    }

    else

    {

     cout<<"\n\n\n\n\n\n";

     cout<<setw(40)<<"Closing airline reservation system!";

    }

    break;
     case 3:

    s.display_members();

    cout<<"To Go To Main Menu Press ESC"<<endl;

    back=getch();


    system("CLS");

    if (back==27)

    {

     goto m;

    }

    else

    {

     cout<<"\n\n\n\n\n\n";

     cout<<setw(40)<<"Closing airline reservation system!";

    }

    break;
    case 4:

    s.clear_dt();

    cout<<"To Go To Main Menu Press ESC"<<endl;

   back=getch();


    system("CLS");

    if (back==27)

    {

     goto m;

    }

    else

    {

     cout<<"\n\n\n\n\n\n";

     cout<<setw(40)<<"Closing airline reservation system!";

    }

    break;

    case 5:
        cout<<"\n\n\n\n\n\n";

     cout<<setw(40)<<"Closing airline reservation system!";
        exit(0);
    default:
        cout<<"\n\n\n\n\n\n invalid choice! press any key!";
        getch();
        system("CLS");
        goto m;
}
}
};


int main()
{
 cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t        AIRWAYS RESERVATION SYSTEM";
 cout<<"\n\n\n\n\n\n\n\t\t\t\t          Project by :";

  cout<<"\t   Prajwal";

 system("cls");
 main1 m1;
 m1.getdata();
 return 0;
}



