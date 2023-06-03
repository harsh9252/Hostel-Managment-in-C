
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Main Menu
void menu()
{
    clrscr();
    printf("\n\t\t<---Select Option--->");
    printf("\n\t--------------------------");
    printf("\n\t\t1.)Room Section");
    printf("\n\t\t2.)Student Section");
    printf("\n\t\t3.)Facitly Section");
    printf("\n\t\t4.)Mess Section");
    printf("\n\t\t5.)Bill Section");
    printf("\n\t\t6.)Exit");
    printf("\n\t----------------------");
    printf("\n\n\t\tSelect Choice :");
    getch();
}
void mess()
{
    clrscr();
    printf("\n\t\t<------Mess Weekly Menu------>");
    printf("\n\t\t-------------------------------");
    printf("\n\t\t BreakFast        |    Lunch           |   Dinner");
    printf("\n\tTime\t (8am to 9am)     |  (1pm to 2 pm)     | (8pm to 9pm)");
    printf("\n\tMonday\t    Tea/Poha      |  Roti/Gobi/Salad   | Rice and Dal");
    printf("\n\tTuesday\t    Tea/Itly      |  Roti/Aloo/Salad   | Rice and Rajma");
    printf("\n\tWednesday   Tea/Dosa      |  Aloo Pratha/Salad | Rice and Kadi");
    printf("\n\tThursday    Tea/Upma      |  Roti/Bhindi/Salad | Veg Briyani");
    printf("\n\tFriday\t    Tea/Chowmin   |  Roti/Mix Veg/Salad| Chole Rice");
    printf("\n\tSaturday    Tea/Paratha   |  Roti/Aloo Matter  | Rice and Rajma");
    printf("\n\tSunday\t    Tea/Meggie    |  Roti/Panner/Salad | Chiken Briyani");
    printf("\n\t-----------------------------------------------------------------------");
    getch();
}
//Room Section Section
//Room Structer
typedef struct
 {
    int room_no;
    char type[20];
}Room;
void room_menu()
{
    clrscr();
    printf("\n\t\t<---Select Option--->");
    printf("\n\t--------------------------");
    printf("\n\t\t1.)Add Room");
    printf("\n\t\t2.)Total Room");
    printf("\n\t\t3.)Back to Main Menu");
    printf("\n\t----------------------");
    printf("\n\n\t\tSelect Choice :");
    getch();
}
//Add_Room
void add_room(Room room_total[], int *total)
{

    int res,res2;
    clrscr();
    printf("\n\tEnter Room Number :");
    scanf("%d",&room_total[*total].room_no);
    if(room_total[*total].room_no>99&&room_total[*total].room_no<1000)
    {

	printf("\n\tRoom Type \tAc\t\tNon-Ac");
	printf("\n\tEnter Room Type :");
	scanf("%s",room_total[*total].type);
	res=strcmp(room_total[*total].type,"Ac");
	res2=strcmp(room_total[*total].type,"Non-Ac");
	if(res==0||res2==0)
	{
	    (*total)++;
	    printf("\n\tRoom is Added..!!");
	    getch();
	}
	else
	{
	    printf("\n\tPlease Input Valid Room Type..!!");
	    getch();
	}
    }
    else
    {

	printf("\n\tPlease input three Digit Room_No");
	getch();
	exit(0);
    }


}
//Room list
void room_list(Room room_total[], int total)
{
	int i,p=1;

    clrscr();
    printf("\n\t Sr_No \t Room_no \t Room-Type  ");
    for(i=0;i<total;i++)
    {
	printf("\n\t %d|  \t%d   |\t%s   |",p,room_total[i].room_no,room_total[i].type);
    p++;
    }
 printf("\n\n\tTotal %d  Room  in your Hostel ",total);
 getch();

}

//Student Section
//Student Structer
typedef struct
 {
    char name[50];
    long int number;
    char gender[10];
     char course[50];
    int roomNumber;
} Student;
//student menu
void student_menu()
{
    clrscr();
    printf("\n\t\t<---Select Option--->");
    printf("\n\t--------------------------");
    printf("\n\t\t1.)Add Student");
    printf("\n\t\t2.)Student List");
    printf("\n\t\t3.)Seacrh Student");
    printf("\n\t\t4.)Back To Main Menu ");
    printf("\n\t----------------------");
    printf("\n\n\t\tSelect Choice :");
}
//add_Student
void add_student(Student hostel[], int *count,Room room_total[], int total)
{
    int i;
    clrscr();
     printf("\n\tEnter student name: ");
    scanf("%s", hostel[*count].name);
    printf("\n\tEnter Student Phone Number :");
    scanf("%ld", &hostel[*count].number);
    printf("\n\tEnter Student Gender :");
    scanf("%s",hostel[*count].gender);
    printf("\n\tEnter Student Course Name :");
    scanf("%s", hostel[*count].course);
    printf("\n\tEnter room number: ");
    scanf("%d", &hostel[*count].roomNumber);
     if(hostel[*count].roomNumber>99&&hostel[*count].roomNumber<1000)
    {
	for(i=0;i<total;i++)
	{
	    if(room_total[i].room_no==hostel[*count].roomNumber)
	    {
	      printf("\n\tStudent is Added");
		 getch();
		(*count)++;
	    }

	    else
	    {
		printf("\n\tRoom-..-Not Found");
		getch();
	    }
	}
    }

    else
    {
	printf("\n\tRoom Not Found");
	getch();
    }
}
void list(Student hostel[], int count)
 {
    int i,p=1;
    clrscr();
   printf("\n\tCount \t Name \t Number \t Gender \t Course \t Room_No ");
   for(i=0;i<count;i++)
   {
	printf("\n\t%d  |\t%s |\t%ld |\t%s |\t%s |\t%d |",p,hostel[i].name,hostel[i].number,hostel[i].gender,hostel[i].course,hostel[i].roomNumber);
	p++;
   }
   printf("\n\n\tTotal %d  Student   in your Hostel ",count);
	getch();
}
//Search Student
void search(Student hostel[] ,int count)
{
    int i,room;
     clrscr();
    printf("\n\tEnter Room no :");
    scanf("%d",&room);
    printf("\n\tCount \t Name \t Number \t Gender \t Course \t Room_No ");
    for(i=0;i<count;i++)
    {
	if(room==hostel[i].roomNumber)
	{
		 printf("\n\t%d  |\t%s |\t%ld |\t%s |\t%s |\t%d |",count,hostel[i].name,hostel[i].number,hostel[i].gender,hostel[i].course,hostel[i].roomNumber);
		  getch();
	}

    else
    {
	    printf("\n\tStudent Not Found..!!");
	    getch();
    }
    }

}
void facitly()
{
    clrscr();
    printf("\n\t<-----Facitily------>");
    printf("\n\t-------------------------");

    printf("\n\t*) Attach Washroom & Bathroom");
    printf("\n\t*) AC/Non-Ac  and Television");
    printf("\n\t*) 24 X 7 Light");
    printf("\n\t*) Fully Wifi Campus");
    printf("\n\t*) Anti-Ragging Squad");
    printf("\n\t*) Indoor Games");
    printf("\n\t*) Indoor GYM");
    printf("\n\t*) 24X7 Water Supply with Water Cooler");
    getch();

}
void welcome()
{
	clrscr();
	printf("\n\n\n\t|-------------------------------------------------------|");
	printf("\n\t|\t**************************************** \t|");
	printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t*\t\tWELCOME\t\t\t*\t|");
    printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t*\t\tSTAR HOSTEL\t\t*\t|");
	printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t*\t\t\t\t\t*\t|");
	printf("\n\t|\t**************************************** \t|");
	printf("\n\t|-------------------------------------------------------|");

	getch();

}
void bill(Student hostel[],int count,Room room_total[], int total)
{
    int num;
    int i,j;
    int bill=0;
    int res;
    int month;
    clrscr();

     printf("\n\n\t<------BILL - GENERATOR------>");
	printf("\n\t-------------------------------");
    printf("\n\tEnter Room-No : ");
    scanf("%d",&num);
    printf("\n\tEnter Total Months for Billing :");
    scanf("%d",&month);
    for(i=0;i<count;i++)
    {
        if(num==hostel[i].roomNumber)
        {
            for(j=0;j<total;j++)
            {
                res=strcmp(room_total[j].type,"Ac");
                if(res==0)
                {
                    bill=2000;
                    printf("\n\tPer Month Ac Room Charge is : 2000");
                    printf("\n\t-----------------------------------------------------------------------");
                }
                else
                {
                    bill=1000;
		    printf("\n\tPer Month Non-Ac Room Charge is : 1000");
                    printf("\n\t-----------------------------------------------------------------------");
                }
            }
           
            printf("\n\t-----------------------------------------------------------------------");
            printf("\n\n\tPer Month Facility Charge is : 2000");
            printf("\n\t-----------------------------------------------------------------------");
            printf("\n\n\tPer Month Mess Charge is : 3000");
            bill+=(2000+3000)*month;
            printf("\n\t-----------------------------------------------------------------------");
	    printf("\n\tYour Total Bill is %d",bill);
	    getch();


        }
        else
        {
            printf("\n\tStudent Not Found..!!");
            getch();
        }


    }
}



//Void Main
void main()
{
    Room room_total[100];
    Student hostel[100];
    int count = 0;
    int total =0;
    int choice ,student,room_cho;
    clrscr();
    welcome();
   Main: while (1)
    {
       menu();
       scanf("%d",&choice);
    switch (choice)
    {
	case 1 :
	   room_loop:  while (1)
	   {
		room_menu();
		scanf("%d",&room_cho);
		switch (room_cho)
		{
		    case 1 :
			add_room(room_total, &total);
		    break;
		     case 2 :
		      room_list(room_total,  total);
		    break;
		     case 3 :
			printf("\n\tThanks For Visiting ...!!!");
			 getch();
			goto Main ;
		    break;

		    default:
			printf("\n\tInValid Choice..!!");
			    getch();
			goto Main ;
		    break;
		}
	   }



	break;
	case 2 :
	     student_loop : while(1)
		{

			student_menu();
			scanf("%d",&student);

			    switch (student)
			    {
			    case 1:
				add_student(hostel, &count ,room_total,total);
			    break;
			    case 2:
			    list(hostel, count);
			    break;
			     case 3:
				search( hostel , count);
			     break;
			     case 4:
                        printf("\n\tThanks For Visiting..!!!");
			            getch();
                        goto Main ;
		             break;
			     break;
			    
                    default:
		                printf("\n\tInValid Choice..!!");
		                getch();
                        goto Main ;

		}
	       }
        break;
        case 3 :
            facitly();
        break;
        case 4 :
            mess();
        break;
        case 5 :
        bill(hostel, count ,room_total,total);
        break;
        case 6 :
            printf("\n\tThanks For Visiting ...!!!");
            getch();
            exit(0);
        break;
         default:
            printf("\n\tInValid Choice..!!");
	        getch();
	        exit(0);
        break;
    }
    }
    
}