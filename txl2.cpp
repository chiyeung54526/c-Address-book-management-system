#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

typedef struct student      
{
    char Sname[20];			
    char Sno[15];			
    char Ssex[5];			
    char Sage[5];			
	char Shome[10];			
    char Sphonenum[20];     
    char Semail[20];        
    struct student *next;   
}
student;
student *head;

void copyright()
{	int i;
	char s[150]={"\t\t Design by chiyeung~\n\t\t    2019  WUST\n\n"};
	for(i=0;s[i]!=NULL;i++)
	{
	Sleep(30);
	printf("%c",s[i]);
	}
}

void menu()					
{   
	//system("clear");
    printf("---------------------------------------------------------\n");
    printf("*********************************************************\n\n");
    printf("\t\tAddress book management system\n");
    printf("\n");
    printf("\t 1. Input Data");
    printf("\t 2. Show All\n\n");
    printf("\t 3. Delete Data");
    printf("\t 4. Look for \n\n");
    printf("\t 5. Modify Data");
    printf("\t 6. Save\n\n");
    printf("\t 7. Menu");
	printf("\t 8. Exit\n\n");
    printf("*********************************************************\n");    
    printf("---------------------------------------------------------\n");
	copyright();
}


void input(student *p1)   
{
    printf("Name:");
    scanf("%s",&p1->Sname);
    printf("Student Number:");
    scanf("%s",&p1->Sno);
    printf("Gender:");
    scanf("%s",&p1->Ssex);
    printf("Age:");
    scanf("%s",&p1->Sage);
    printf("Adress:");
    scanf("%s",&p1->Shome);
    printf("Phone Number:");
    scanf("%s",&p1->Sphonenum);
    printf("E-mail:");
    scanf("%s",&p1->Semail);
}


student * printdata(student *p1)     //Show All
{
    printf("\n\t\t\tShow All\n");
    printf("---------------------------------------------------------\n");
    while(p1!=NULL)
    {
        printf("Name:%s\n",p1->Sname);
        printf("Student Number:%s\t",p1->Sno);
        printf("Gender:%s\t",p1->Ssex);
        printf("Age:%s\t",p1->Sage);
        printf("Adress:%s\t",p1->Shome);
        printf("Phone Number:%s\t",p1->Sphonenum);
        printf("E-mail:%s\n",p1->Semail);
        printf("---------------------------------------------------------\n");
        p1=p1->next;
    }
    return p1;
}


void insertdata()			//Input Data
{
    int i;
    student *p1,*p2,*p3;
    p1=head;
    p3=(student *)malloc(sizeof(student));
    p3->next=NULL;
    printf("\n\t\t\tInput Data\n");
    printf("---------------------------------------------------------\n");
    printf("Please input data:\n");
    input(p3);
    printf("\nInput to...\n");
    printf("1.First line\t2.Last line\n");
    printf("Input 1 or 2:");
	loop:scanf("%d",&i);
	        if(i<1||i>2)
        {
            printf("Wrong Inupt! Please input 1 or 2 :");
            goto loop;
        }
    switch(i)
    {
    case 1:p3->next=p1;
        head=p3;
        break;
    case 2:while(p1->next!=NULL)
           {
               p2=p1;
               p1=p1->next;
           }
        p1->next=p3;
        break;
	}
    printf("Sucess!\n");
    printf("=========================================================\n");
    return;
}

void Ddata()				//Delete Data
{
    student *p1,*p2;
    char Dname[20]; 
    printf("\n\t\t\tDelete Data\n");
    printf("---------------------------------------------------------\n");
    printf("Please input the Name you want to DELETE:");
    scanf("%s",Dname);
    p1=head;
    if(head==NULL)
    {
    printf("No such NAME !\n");
    printf("=========================================================\n");
    return;
    }
    if(strcmp(Dname,p1->Sname)==0)
    {
    head=p1->next;
    printf("Sucess!\n");
    printf("=========================================================\n");
    return;
    }
    while(p1!=NULL&&(strcmp(Dname,p1->Sname)!=0))
    {
    p2=p1;
    p1=p1->next;
    }
    if(p1==NULL)
    {
    printf("No such NAME!\n");
    printf("=========================================================\n");
    return;
    }
    if(p1->next!=NULL)
    {
    p1=p1->next;
    p2->next=p1;
    printf("Sucess!\n");
    printf("=========================================================\n");
    return;
    }
    else
    {
    p2->next=NULL;
    printf("Sucess!\n");
    printf("=========================================================\n");
    return;
    }
}


void finddata(student *p2)        //Look for 
{
    char Sname[20];
    int b=0;
    printf("\n\t\t\tLook for \n");
    printf("---------------------------------------------------------\n");
    printf("Please input the Name you want to Find:/n");
    scanf("%s",Sname);
    while(p2!=NULL)
    {
        if(strcmp(Sname,p2->Sname)==0)
        {
            printf("Result£º\n");
            printf("Name:%s\t",p2->Sname);
            printf("Student Number:%s\t",p2->Sno);
            printf("Gender:%s\t",p2->Ssex);
            printf("Age:%s\t",p2->Sage);
            printf("Adress:%s\t",p2->Shome);
            printf("Phone Number:%s\t",p2->Sphonenum);
            printf("E-mail:%s\n",p2->Semail);
            printf("=========================================================\n");
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("\nNo such Name!\n");
		printf("=========================================================\n");
    }
}


void updatedata(student *p2)		//Modify Data
{
    char Sname[20];
    int b=0,i;
    printf("\n\t\t\tModify Data\n");
    printf("---------------------------------------------------------\n");
    printf("Please input the Name you want to MODIFY:");
    scanf("%s",Sname);
    while(p2!=NULL)
    {
        if(strcmp(Sname,p2->Sname)==0)
        {
            printf("Current info:\n");
            printf("Name:%s\n",p2->Sname);
            printf("Student Number:%s\t",p2->Sno);
            printf("Gender:%s\t",p2->Ssex);
            printf("Age:%s\t",p2->Sage);
            printf("Adress:%s\t",p2->Shome);
            printf("Phone Number:%s\t",p2->Sphonenum);
            printf("E-mail:%s\n",p2->Semail);
            printf("\nPlease Choose :\n");
            printf("\t1.Name\t2.Student Number\t3.Gender\t4.Age\n\t5.Adress\t6.Phone Number\t7.E-mail\n");
            printf("\nYour choice is (1~7):");
            scanf("%d",&i);
            printf("Modified info:\n");
            switch(i)
            {
            case 1:printf("Name:");
                scanf("%s",&p2->Sname);
                break;
            case 2:printf("Student Number:");
                scanf("%s",&p2->Sno);
                break;
            case 3:printf("Gender:");
                scanf("%s",&p2->Ssex);
                break;
            case 4:printf("Age:");
                scanf("%s",&p2->Sage);
                break;
            case 5:printf("Adress:");
                scanf("%s",&p2->Shome);
                break;
            case 6:printf("Phone Number:");
                scanf("%s",&p2->Sphonenum);
                break;
            case 7:printf("E-mail:");
                scanf("%d",&p2->Semail);
                break;
            }
            printf("\nSucess!\n");
            printf("=========================================================\n");
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("No such Name!\n");
    }
}


void savedata(student *p2)			//Save
{
    FILE *fp;
    char file[15];
    printf("\n\t\t\tSave\n");
    printf("---------------------------------------------------------\n");
    printf("Save as:");
    scanf("%s",file);
    if((fp=fopen(file,"w"))==NULL)
    {
        printf("cannot open this file\n");
        exit(0);
    }
    fprintf(fp,"Name\tStudent Number\tGender\tAge\tAdress\tPhone Number\tE-mail\n");
    while(p2!=NULL)
    {
        fprintf(fp,"%s\t",p2->Sname);
        fprintf(fp,"%s\t",p2->Sno);
        fprintf(fp,"%s\t",p2->Ssex);
        fprintf(fp,"%s\t",p2->Sage);
        fprintf(fp,"%s\t",p2->Shome);
        fprintf(fp,"%s\t",p2->Sphonenum);
        fprintf(fp,"%s\n",p2->Semail);
        p2=p2->next;
    }
    printf("\nSucess!\n");
    printf("=========================================================\n");
    fclose(fp);
}




int main()							 //main
{
    int i;
    system("color E0");	
    menu();
    while(1)
    {
        printf("\nPlease input your choice(1~8,7 for display Menu):");
        loop:scanf("%d",&i);
        if(i<1||i>8)
        {
            printf("Wrong input! Please input number 1~8:");
            goto loop;
        }
        switch(i)
        {
        case 1:
            insertdata();
            break;
        case 2:
            printdata(head);
            break;
        case 3:
             Ddata();
            break;
        case 4:
            finddata(head);
            break;
        case 5:
            updatedata(head);
            break;
        case 6:
            savedata(head);
            break;
        case 7:
            menu();
            break;
        case 8:
            exit(-1);
            break;
        }
    }
}