
//============================================
//	PROJECT ON HOTEL
//============================================


//============================================
//	HEADER FILE USED IN THIS PROJECT
//============================================


#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iomanip.h>
#include<stdlib.h>

//============================================
//	HEADER FILE ENDS HERE
//============================================


//============================================
//	CLASSES USED IN THE PROJECT
//============================================


class room
	{	int room_no;
		char type[10];
		int capacity;
		int rent;
		int pcharges;
		int scharges;
		char vacancy[10];

public:

void create_room()
	{       cout<<"\n\n\t\t\t"<<"|||||| CREATING ROOM |||||||\n\n";
		cout<<"Enter room no. ";
		cin>>room_no;
		cout<<"\nEnter room type ";
		gets(type);
		cout<<"\nEnter capacity of room ";
		cin>>capacity;
		cout<<"\nEnter rent of room ";
		cin>>rent;
		cout<<"\nEnter per day charges ";
		cin>>pcharges;
		cout<<"\nEnter service charges ";
		cin>>scharges;
		strcpy(vacancy,"vacant");
	}

void modify()
	{	cout<<"\n\n\t\t********** MODIFYING ROOM **************\n\n";
		cout<<"Room No. "<<room_no;
		cout<<"\nEnter room type ";
		gets(type);
		cout<<"\nEnter capacity of room ";
		cin>>capacity;
		cout<<"\nEnter rent of room ";
		cin>>rent;
		cout<<"\nEnter per day charges ";
		cin>>pcharges;
		cout<<"\nEnter service charges ";
		cin>>scharges;
		strcpy(vacancy,"vacant");
	}


void show_room_head()
	{	cout<<"\n\n\t\t\t"<<"||||||| SHOWING ROOM |||||||\n\n";
		cout<<"\tZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
		cout<<"\n\t"<<setw(2)<<"ROOM NO."<<setw(7)<<"TYPE"<<setw(13)<<"CAPACITY"<<setw(12)<<"CHARGES"<<setw(15)<<"AVAILABILITY";
		cout<<"\n\tZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
	}

void room_details()
	{	cout<<"\n\tRoom No. "<<room_no<<"\tType "<<type<<"\tCapacity "<<capacity;
		cout<<"\n\nCharges.....";
		cout<<"\n\tRoom "<<rent<<"\tper day "<<pcharges<<"\tservice "<<scharges;
	}


void show_room()
	{	cout<<"\n\t"<<setw(2)<<room_no<<setw(13)<<type<<setw(8)<<capacity<<setw(16)<<rent<<setw(12)<<vacancy;
	}

void show_avail()
	{
		cout<<"\n\t\t"<<setw(2)<<room_no<<setw(15)<<type<<setw(10)<<capacity<<setw(13)<<rent;
	}

void registration()
	{
		strcpy(vacancy,"Busy");
	}

void de_allot()
	{	strcpy(vacancy,"vacant");
	}

char* retvacancy()
	{	return vacancy;
	}

int retroom_no()
	{	return room_no;
	}

int retrent()
	{	return rent;
	}
int retpcharge()
	{	return pcharges;
	}
int retscharge()
	{	return scharges;
	}
	};

class guest
	{	char gname[20];
		char p_no[20];
		char gender[10];
		int room_no;
		int charges;

public:

void create_guest()
	{	cout<<"\n\nEnter Guest Details...........";
		cout<<"\n\n\tEnter the room no. ";
		cin>>room_no;
		cout<<"\n\tEnter name of guest ";
		gets(gname);
		cout<<"\n\tEnter gender of guest ";
		gets(gender);
		cout<<"\n\tEnter phone no. ";
		gets(p_no);
		charges=0;
	}


void show_guest()
	{       cout<<"\n\t"<<setw(5)<<room_no<<setw(20)<<gname<<setw(20)<<p_no;
	}


int retroom()
	{	return room_no;
	}
char* retgname()
	{	return gname;
	}
	};

//============================================
//	CLASS ENDS HERE
//============================================


//============================================
//GLOBAL DECLARATION FOR STREAM OBJECT, OBJECT
//============================================

room rm;
guest gt;
fstream fr,fr2,fr3;

//============================================
//     FUCTIONS USED IN THE PROGRAM
//============================================


//============================================
//	FUCTION TO CREATE ROOM
//============================================


void write_room()
	{	char ch='y';
		fr.open("ROOM.DAT",ios::app);
		while(ch=='y'||ch=='Y')
		{       clrscr();
			fr.eof();
			rm.create_room();
			fr.write((char*)&rm,sizeof(room));
			cout<<"\nDo you want to add more rooms(y/n) ";
				cin>>ch;
		}
		fr.close();
	}

//============================================
//	FUNCTION TO SHOW ROOM
//============================================

void show_room()
	{	clrscr();
		fr.open("ROOM.dat",ios::in);
		if(!fr)
		cout<<"\n\nFILE DOES NOT EXIST !!!";
		else
		rm.show_room_head();
		while(fr.read((char*)&rm,sizeof(room)))
		{	rm.show_room();
		}
		fr.close();
		getch();
	 }


//============================================
//    FUNCTION TO CHECK THE AVAILABILITY
//============================================


void avail()
	{	clrscr();
		int aroom;
		char ch='Y';
		if(!fr)
		cout<<"\n\nFILE DOES NOT EXIST !!!";
		else
		{
		cout<<"\n\n\t\t\t!!!!!!!SHOWING AVAILABILITY!!!!!!!\n\n";
		cout<<"\tZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
		cout<<"\n\t\t"<<setw(2)<<"ROOM NO."<<setw(7)<<"TYPE"<<setw(15)<<"CAPACITY"<<setw(10)<<"CHARGES";
		cout<<"\n\tZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
		fr.open("ROOM.DAT",ios::in);
		while(fr.read((char*)&rm,sizeof(room)))
		{	if(strcmp(rm.retvacancy(),"vacant")==0)
			rm.show_avail();
		}
		fr.close();
		}
		cout<<"\n\nDo you want to get details of room(y/n) ";
		cin>>ch;
		while(ch=='y'||ch=='Y')
	      {	cout<<"Enter room no ";
		cin>>aroom;
		fr2.open("ROOM.DAT",ios::in);
		while(fr2.read((char*)&rm,sizeof(room)))
		{	if(aroom==rm.retroom_no())
			rm.room_details();
		}
		fr2.close();
		cout<<"\n\n\nDo you want to check another room(y/n) ";
		cin>>ch;
	      }
	}


//============================================
//	FUNCTION TO DELETE ROOM
//============================================


void del_room()
	{	clrscr();
		int droom_no,tag=0;
		fr.open("ROOM.DAT",ios::in||ios::out);
		if(!fr)
		cout<<"\n\nFILE DOES NOT EXIST !!!";
		else
		{
		cout<<"\nEnter the room no. you want to delete ";
		cin>>droom_no;
		fr2.open("temp.dat",ios::out);
		while(fr.read((char*)&rm,sizeof(room)))
		{	if(rm.retroom_no()!=droom_no)
				fr2.write((char*)&rm,sizeof(room));
			else
				tag=1;
		}
		if(tag==1)
			cout<<"\n\nRecord Deleted........";
		else
			cout<<"\n\nRecord Not Exist........";
		fr.close();
		fr2.close();
		remove("ROOM.DAT");
		rename("temp.dat","ROOM.DAT");
		}
		getch();
	}


//============================================
//	FUNCTION TO MODIFY ROOM
//============================================


void modify_room()
	{	clrscr();
		int mroom_no,found=0;
		fr.open("ROOM.DAT",ios::in|ios::out);
		if(!fr)
		cout<<"\n\nFILE DOES NOT EXIST !!!";
		else
		{
		cout<<"Enter the room no. you want to modify ";
		cin>>mroom_no;
		while(fr.read((char*)&rm,sizeof(room)) && found==0)
		{
			if(rm.retroom_no()==mroom_no)
			{

				rm.modify();
				int pos=-1*sizeof(rm);
				fr.seekp(pos,ios::cur);
				fr.write((char*)&rm,sizeof(room));
				found=1;
			}

		}
		fr.close();
		if(found==0)
			cout<<"\n\nRecord Not Exist..........";
		else
			cout<<"\n\nRecord Modified...........";
		}
		getch();
	}


//============================================
//	FUNCTION TO REGISTER ROOM
//============================================


void registration()
	{	clrscr();
		int aroom;
		if(!fr)
		cout<<"\n\nFILE DOES NOT EXIST !!!";
		else
		{
		cout<<"\n\n\t\t\t!!!!!!!SHOWING AVAILABILITY!!!!!!!\n\n";
		cout<<"\tZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
		cout<<"\n\t\t"<<setw(2)<<"ROOM NO."<<setw(7)<<"TYPE"<<setw(15)<<"CAPACITY"<<setw(10)<<"CHARGES";
		cout<<"\n\tZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
		fr.open("ROOM.DAT",ios::in);
		while(fr.read((char*)&rm,sizeof(room)))
		{	if(strcmp(rm.retvacancy(),"vacant")==0)
			rm.show_avail();
		}
		fr.close();
		}
		int rroom_no, flag=0;
		cout<<"\n\nEnter the room no. you want to register ";
		cin>>rroom_no;
		fr.open("ROOM.DAT",ios::in);
		fr2.open("temp.DAT",ios::out);
		while(fr.read((char*)&rm,sizeof(room)))
		{    	if(rm.retroom_no()==rroom_no)
		     {	rm.registration();
			fr2.write((char*)&rm,sizeof(room));
			flag=1;
		     }
			else
			fr2.write((char*)&rm,sizeof(room));

		}

		fr.close();
		fr2.close();
		remove("ROOM.DAT");
		rename("temp.DAT","ROOM.DAT");
		if(flag==1)
		{	fr3.open("Guest.DAT",ios::app);
			gt.create_guest();
			fr3.write((char*)&gt,sizeof(guest));
			fr3.close();
			cout<<"\n\nRoom Registered.............";
		}
		else
		cout<<"\n\nRoom Not Exist..............";
		getch();
	}


//============================================
//	FUNCTION TO SHOW GUEST DETAILS
//============================================


void show_guest()
	{	clrscr();
		fr.open("Guest.DAT",ios::in);
		if (!fr)
		cout<<"\n\nReecord Not Exist.................";
		else
	     {	cout<<"\n\t!!.........Guest Details.........!!";
		cout<<"\n\n\tZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
		cout<<"\n\t"<<setw(5)<<"Room No."<<setw(17)<<"Guest Name"<<setw(17)<<"Phone No.";
		cout<<"\n\tZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
		while(fr.read((char*)&gt,sizeof(guest)))
		gt.show_guest();
	     }	fr.close();
		getch();
	}


//============================================
//	FUNCTION TO CHECK OUT THE ROOM
//============================================


void check_out()
	{	clrscr();
		show_guest();
		char d[20];
		int droom,flag,nod;
		cout<<"\n\nEnter the room no you want to check out the room ";
		cin>>droom;
		fr.open("ROOM.DAT",ios::in);
		fr2.open("temp.DAT",ios::out);
		while(fr.read((char*)&rm,sizeof(room)))
		{	if(droom==rm.retroom_no())
		      {	rm.de_allot();
			fr2.write((char*)&rm,sizeof(room));
		      } else
			fr2.write((char*)&rm,sizeof(room));
		}
		fr.close();
		fr2.close();
		remove("ROOM.DAT");
		rename("temp.DAT","ROOM.DAT");
		fr.open("Guest.DAT",ios::in);
		fr2.open("temp.DAT",ios::out);
		while(fr.read((char*)&gt,sizeof(guest)))
		{	if(droom==gt.retroom())
			{flag=1;
			strcpy(d,gt.retgname());
			}
			else
			fr2.write((char*)&gt,sizeof(guest));
		}
		fr.close();
		fr2.close();
		remove("Guest.DAT");
		rename("temp.DAT","Guest.DAT");
		int a,b=0,c=0,tot;
		fr.open("ROOM.DAT",ios::in);
		while(fr.read((char*)&rm,sizeof(room)))
		if(droom==rm.retroom_no())
		{  cout<<"\nEnter no. of days the room was occupied ";
		   cin>>nod;
		   if(nod<=3)
		      {	a=rm.retrent();
			tot=a;
		      }
		   else
		      {	a=rm.retrent();
			b=(nod-3)*rm.retpcharge();
			c=(nod-3)*rm.retscharge();
			tot=a+b+c;
		      }
		   }
		fr.close();
		if(flag==1)
		cout<<"\n\nRoom is vacant now...............";
		else
		cout<<"Record not exist....................";
		getch();

//============================================
//	BILL TO BE PAID AFTER CHECK OUT
//============================================


		clrscr();
		cout<<"\n\n\t\t=======================================";
		cout<<"\n\t\t**************************************";
		cout<<"\n\t\t"<<setw(30)<<"DELHI TECHNICAL CAMPUS"<<setw(12);
		cout<<"\n\t\t**************************************";
		cout<<"\n\t\t               PAY BILL                ";
		cout<<"\n\n\t\t\t"<<"Name of guest "<<d;
		cout<<"\n\n\t\t"<<setw(14)<<"Room No. "<<droom<<setw(15)<<"No. of days "<<nod;
		cout<<"\n\t\t"<<setw(20)<<"Room rent "<<a;
		cout<<"\n\t\t"<<setw(20)<<"Per day Charge "<<b;
		cout<<"\n\t\t"<<setw(20)<<"Service Charge "<<c;
		cout<<"\n\n\t\t"<<setw(32)<<"Total= "<<tot;
		cout<<"\n\n\t\t        Thanks for coming          ";
		cout<<"\n\t\t=======================================";
		getch();
		}


//============================================
//	FUNTION TO SHOW INTRODUCTION
//============================================


void intro()
	{       clrscr();
		cout<<"\n\n\t\tPROJECT ON HOTEL MANAGEMENT SYSTEM\n\n\n";
		cout<<"\n\tMADE BY :- VAIBHAV JHA\n";
		cout<<"\n\t43518002816 ECE 6th Semester\n";
		cout<<"\n\tDelhi Technical Campus";
		getch();
	}


//============================================
//	FUNCTION TO SHOW MAIN MENU
//============================================



void menu()
	{       start:
		clrscr();
		int ch;
		cout<<"\n\n\t\t!!.......DELHI TECHNICAL CAMPUS.......!!\n\n";
		cout<<"\tHOTEL MENU\n";
		cout<<"\n\t1:- TO SHOW ROOM DETAILS";
		cout<<"\n\t2:- TO CHECK AVAILABILITY";
		cout<<"\n\t3:- TO REGISTER";
		cout<<"\n\t4:- TO SHOW GUEST DETAILS";
		cout<<"\n\t5:- TO CHECK OUT THE ROOM";
		cout<<"\n\t6:- ADMINISTRATION MENU";
		cout<<"\n\t7:- EXIT";
		cout<<"\nEnter your decision(1-7) ";
		cin>>ch;
		switch(ch)
		{ case 1: show_room();
			  break;
		  case 2: avail();
			  getch();
			  break;
		  case 3: registration();
			  break;
		  case 4: show_guest();
			  break;
		  case 5: check_out();
			  break;
		  case 6: top:
			  clrscr();
			  int OP;
			  cout<<"\n\n\t\t!!.......DELHI TECHNICAL CAMPUS.......!!";
			  cout<<"\n\n\t!!!!!!!!!ADMINISTRATION MENU!!!!!!!!\n\n";
			  cout<<"\n\n\t1:- TO CREATE ROOM";
			  cout<<"\n\t2:- TO DELETE ROOM";
			  cout<<"\n\t3:- TO MODIFY ROOM";
			  cout<<"\n\t4:- GO BACK TO PREVIOUS MENU";
			  cout<<"\n\t5:- EXIT";
			  cout<<"\n\nEnter your choice(1-5) ";
			  cin>>OP;
			  switch(OP)
				{  	case 1: write_room();
						break;
					case 2: del_room();
						break;
					case 3: modify_room();
						break;
					case 4: goto start;
					case 5: exit(0);
				}
			  goto top;

		  case 7: exit(0);
		}
		goto start;
	}


//============================================
//	MAIN WINDOW OF THE PROGRAM
//============================================

void main()
	{
		intro();
		menu();
		getch();
	}


//============================================
//	END OF THE PROJECT
//============================================









