#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include "spash.h"
#define ENTER 13
#define BACKSPACE 8
	FILE *file;
	FILE *temp;
	struct student{
		char stid[5];
		char name[30];
		char grade[10];
		char roll[10];
		char phone[11];
		char address[30];
		char status;
	};

	struct student s;

	void date(){
		struct date today;
		getdate(&today);
		printf("\t\t\t\t\t\t\t\tDate:%d /%d /%d",today.da_day,today.da_mon,today.da_year);
	}
	int flag=1;
	void login(){
		char adminid[20];
		char pass[20];
		printf("\n\n\n\n\n\n\n\t\t\tEnter admin id: ");
		scanf("%s",adminid);
		printf("\t\t\tEnter your password: ");
		char  ch[15];
		for(int i=0;i<15;i++){
			ch[i]=getch();

			if(ch[i]!=ENTER && ch[i]!=BACKSPACE){
				printf("*");
			}
			if(ch[i]==ENTER){
				ch[i]=NULL;
				break;
			}
			if(ch[i]==BACKSPACE){
				if(i<=0){
					i<=0;
				}else{
					i=i-2;
					clrscr();
					date();
					printf("\n\n\n\n\n\n\t\t\tEnter admin ird: admin101");
					printf("\n\t\t\tEnter your password: ");

					for(int j=0;j<i+1;j++){
						printf("*");
					}
				}
			}
		}
		if(strcmp(adminid,"admin101")==0){
			if(strcmp(ch,"dharan")==0){
				flag=0;
			}

		}
	}
	void null_check_std(){
		if(file==NULL){
			printf("Error 404: File not found");
			delay(2000);
			exit(0);
		}
	}
	char stid[5];
	char fname[30];
	char lname[30];
	char grade[10];
	char roll[10];
	char phone[11];
	char address[30];
	char status;
	void student_data_entry(){
		clrscr();
		file=fopen("..\\students.txt","r");
			while(!feof(file)){
				fscanf(file,"%s %s %s %s %s %s %s %c",stid,fname,lname,grade,roll,phone,address,&status);
				if(feof(file)){
					printf("Last ID: %s\n",stid);
					break;
				}
			}
		fclose(file);
		date();
		printf("Enter the following details: ");
		printf("\n\nID: ");
		scanf("%s",s.stid);
		printf("\nName: ");
		fflush(stdin);
		scanf("%[^\n]s",s.name);
		printf("\nGrade: ");
		scanf("%s",s.grade);
		printf("\nRoll no: ");
		scanf("%s",s.roll);
		printf("\nAddress: ");
		scanf("%s",s.address);
		printf("\nPhone: ");
		scanf("%s",s.phone);
		s.status='A';
		printf("\nStatus: %c\n",s.status);

		file=fopen("..\\students.txt","a");
		fprintf(file,"%s   %s   %s  %s  %s  %s  %c\n",s.stid,s.name,s.grade,s.roll,s.phone,s.address,s.status);
		fclose(file);
	}
	void student_data_read(){
		int i;
		clrscr();
		date();
		file=fopen("..\\students.txt","r");
		null_check_std();

		for(i=0;i<80;i++){
			printf("-");

		}
		printf("ID    Name \t\t  Grade  Roll no:  Phone:\tAddress:  Status:\n");

			for(i=0;i<80;i++){
		printf("-");

		}
		file=fopen("..\\students.txt","r");
		while(!feof(file)){
			fscanf(file,"%s %s %s %s %s %s %s %c",stid,fname,lname,grade,roll,phone,address,&status);
			if(feof(file)){
				break;
			}
			printf("%s   %s %s\t  %s\t  %s\t   %s   %s\t    %c\n",stid,fname,lname,grade,roll,phone,address,status);
		}
		fclose(file);
	}

	FILE *book;
	struct books {
		char bk_id[10];
		char title[30];
		char author[30];
		int quantity;
	};

	struct books bk;

	void null_check_book(){
		if(book==NULL){
			printf("Error 404: File not found");
			delay(2000);
			exit(0);
		}
	}
	int xc=1,yc=4;

	char ch;
	void  entry_books(){
			gotoxy(xc,yc);
			scanf("%s",bk.bk_id);
			xc=6;
			gotoxy(xc,yc);
			fflush(stdin);
			scanf("%[^\n]s",bk.title);
			xc=25;
			gotoxy(xc,yc);
			fflush(stdin);
			scanf("%[^\n]s",bk.author);
			xc=41;
			gotoxy(xc,yc);
			fflush(stdin);
			scanf("%d",&bk.quantity);
			yc++;
			xc=1;
			book=fopen("..\\books.txt","a");
			null_check_book();
			fprintf(book,"%s   %s  %s   %d\n",bk.bk_id,bk.title,bk.author,bk.quantity);
			fclose(book);
		}

	char bk_id[5];
	char ftitle[20];
	char ltitle[20];
	char fauthor[20];
	char lauthor[20];
	int quantity;
	void view_book(){
		clrscr();
		printf("ID   Title\t\tAuthor\tQuantity\n");
		book=fopen("..\\books.txt","r");
		while(!feof(book)){
			fscanf(book,"%s %s %s %s %s %d",bk_id,ftitle,ltitle,fauthor,lauthor,&quantity);
			if(feof(book)){
				break;
			}
			printf("%s  %s %s   %s %s  %d\n",bk_id,ftitle,ltitle,fauthor,lauthor,quantity);
		}
		fclose(book);
	}
	int add;
	char search_bk[5];
	char fititle[15];
	char latitle[15];
	void add_existing_books(){
		clrscr();
		printf("Enter book ID: ");
		scanf("%s",search_bk);

		book=fopen("..\\books.txt","r");
		while(!feof(book)){
			fscanf(book,"%s %s %s %s %s %d",bk_id,ftitle,ltitle,fauthor,lauthor,quantity);
			if(strcmp(bk_id,search_bk)==0){
				printf("\nBook Title: %s %s",ftitle,ltitle);
				flag=1;
				break;
			}
			if(feof(book)){
				break;
			}
		}
		fclose(book);

		if(flag==1){
			printf("\nAdditional Books: ");
			scanf("%d",&add);

			book=fopen("..\\books.txt","r");
			temp=fopen("..\\temp.txt","a");
			while(!feof(book)){
				fscanf(book,"%s %s %s %s %s %d",bk_id,ftitle,ltitle,fauthor,lauthor,&quantity);
				if(feof(book)){

				}
				fprintf(temp,"%s  %s %s  %s %s  %d\n",bk_id,ftitle,ltitle,fauthor,lauthor,quantity);
			}
			fclose(temp);
			fclose(book);

			book=fopen("..\\books.txt","w");
			fclose(book);

			temp=fopen("..\\temp.txt","r");
			book=fopen("..\\books.txt","a");
			while(!feof(temp)){
				fscanf(temp,"%s %s %s %s %s %d",bk_id,ftitle,ltitle,fauthor,lauthor,&quantity);
				if(strcmp(bk_id,search_bk)==0){
					quantity=quantity+add;
					fprintf(book,"%s  %s %s  %s %s  %d\n",bk_id,ftitle,ltitle,fauthor,lauthor,quantity);
				}else{
					fprintf(book,"%s  %s %s  %s %s  %d\n",bk_id,ftitle,ltitle,fauthor,lauthor,quantity);
				}

			}
			fclose(book);
			fclose(temp);

			temp=fopen("..\\temp.txt","w");
			fclose(temp);
		}
	}

	int n;
	char search[5];
	int snake=1;
	void search_record(){
		clrscr();
		printf("What do you want to search for? \n");
		printf("1.Student Info\n");
		printf("2.Book Info\n");
		printf("\n\n\nChoose any one: ");
		scanf("%d",&n);

		switch(n){
			case 1:
				//student search
				clrscr();
				printf("Enter the Students ID: ");
				scanf("%s",search);
				printf("ID    Name \t\t  Grade  Roll no:  Phone:\tAddress:  Status:\n");
				file=fopen("..\\students.txt","r");
				while(!feof(file)){
					fscanf(file,"%s %s %s %s %s %s %s %c",stid,fname,lname,grade,roll,phone,address,&status);
					if(strcmp(stid,search)==0){
						printf("%s   %s %s\t  %s\t  %s\t   %s   %s\t    %c\n",stid,fname,lname,grade,roll,phone,address,status);
						snake=0;
						break;
					}
					if(feof(file)){
						break;
					}
				}
				fclose(file);
				if(snake==1){
					clrscr();
					printf("Sorry student info not found");
					break;
				}
				break;
			case 2:
				//book search
				clrscr();
				printf("Enter the Book ID: ");
				scanf("%s",search);

				clrscr();
				printf("ID   Title\t\tAuthor\t\tQuantity\n");
				book=fopen("..\\books.txt","r");
				while(!feof(book)){
					fscanf(book,"%s %s %s %s %s %s %d",bk_id,ftitle,ltitle,fauthor,lauthor,&quantity);
					if(strcmp(search,bk_id)==0){
						printf("%s   %s %s\t%s %s\t%d",bk_id,ftitle,ltitle,fauthor,lauthor,quantity);
						snake=0;
						break;
					}
				}
				if(snake==1){
					printf("Sorry Book info not found");
					break;
				}
				fclose(book);


		}
	}


	FILE *issue;
	struct i_books{
		char stid[5];
		char bkid[5];
		int dd;
		int mm;
		int yy;
	};

	struct i_books ib;

	char pstatus;
	FILE *tempb;
	void issue_books(){
		clrscr();
		date();
		printf("Enter the folowing info: ");
		printf("\n\nStudent ID: ");
		scanf("%s",ib.stid);
		file=fopen("..\\students.txt","r");
		null_check_std();
		while(!feof(file)){
			fscanf(file,"%s %s %s %s %s %s %s %c",stid,fname,lname,grade,roll,phone,address,&status);
			if(strcmp(stid,ib.stid)==0){
				if(status=='A'){
					printf("\nName: %s %s\n",fname,lname);
					break;
				}else{
					printf("\nPlease return previous books");
				}
			}
		}
		fclose(file);
		printf("\nBook ID: ");
		scanf("%s",ib.bkid);

		book=fopen("..\\books.txt","r");
		while(!feof(book)){
			fscanf(book,"%s %s %s %s %s %d",bk_id,ftitle,ltitle,fauthor,lauthor,&quantity);
		       if(strcmp(bk_id,ib.bkid)==0){
				printf("\nTitle: %s %s\n",ftitle,ltitle);
				break;
		       }
		}
		fclose(book);
		book=fopen("..\\books.txt","r");
		tempb=fopen("..\\tempb.txt","a");
		while(!feof(book)){
			fscanf(book,"%s %s %s %s %s %d",bk_id,ftitle,ltitle,fauthor,lauthor,&quantity);
			if(feof(book)){
				break;
			}
			fprintf(tempb,"%s  %s %s  %s %s  %d\n",bk_id,ftitle,ltitle,fauthor,lauthor,quantity);
		}
		fclose(tempb);
		fclose(book);

		book=fopen("..\\books.txt","w");
		fclose(book);

		tempb=fopen("..\\tempb.txt","r");
		book=fopen("..\\books.txt","a");
		while(!feof(tempb)){
			fscanf(tempb,"%s %s %s %s %s %d",bk_id,ftitle,ltitle,fauthor,lauthor,&quantity);
			if(feof(tempb)){
				break;
			}
			if(strcmp(bk_id,ib.bkid)==0){
				quantity=quantity-1;
				fprintf(book,"%s  %s %s  %s %s  %d\n",bk_id,ftitle,ltitle,fauthor,lauthor,quantity);
			}else{
				fprintf(book,"%s  %s %s  %s %s  %d\n",bk_id,ftitle,ltitle,fauthor,lauthor,quantity);
			}
		}
		fclose(book);
		fclose(tempb);
		tempb=fopen("..\\tempb.txt","w");
		fclose(tempb);
		printf("\nDate (DD/MM/YY): ");
		scanf("%d",&ib.dd);
		gotoxy(22,12);
		scanf("%d",&ib.mm);
		gotoxy(25,12);
		scanf("%d",&ib.yy);

		issue=fopen("..\\issue.txt","a");
		fprintf(issue,"%s  %s  Date: %d/ %d/ %d\n",ib.stid,ib.bkid,ib.dd,ib.mm,ib.yy);
		fclose(issue);

		file=fopen("..\\students.txt","r");
		temp=fopen("..\\temp.txt","a");
		while(!feof(file)){
			fscanf(file,"%s %s %s %s %s %s %s %c",stid,fname,lname,grade,roll,phone,address,status);
			if(feof(file)){
				break;
			}
			fprintf(temp,"%s  %s %s  %s  %s  %s  %s  %c\n",stid,fname,lname,grade,roll,phone,address,status);
		}
		fclose(temp);
		fclose(file);

		file=fopen("..\\students.txt","w");
		fclose(file);

		temp=fopen("..\\temp.txt","r");
		file=fopen("..\\students.txt","a");
		while(!feof(temp)){
			fscanf(temp,"%s %s %s %s %s %s %s %c",stid,fname,lname,grade,roll,phone,address,status);
			if(feof(temp)){
				break;
			}
			pstatus=status;
			if(strcmp(ib.stid,stid)==0){
				status='B';
				fprintf(file,"%s  %s %s  %s  %s  %s  %s  %c\n",stid,fname,lname,grade,roll,phone,address,status);
			}else{
				status=pstatus;
				fprintf(file,"%s  %s %s  %s  %s  %s  %s  %c\n",stid,fname,lname,grade,roll,phone,address,status);
			}
		}
		fclose(file);
		fclose(temp);
		temp=fopen("..\\temp.txt","w");
		fclose(temp);
	}

	FILE *ret;
	struct ret_book{
		char stid[5];
		char bkid[5];
		int dd;
		int mm;
		int yy;
	};

	struct ret_book rb;
	void return_book(){
		clrscr();
		date();
		printf("Enter the folowing info: ");
		printf("\n\nStudent ID: ");
		scanf("%s",rb.stid);
		file=fopen("..\\students.txt","r");
		null_check_std();
		while(!feof(file)){
			fscanf(file,"%s %s %s %s %s %s %s %c",stid,fname,lname,grade,roll,phone,address,&status);
			if(strcmp(stid,rb.stid)==0){
				printf("\nName: %s %s\n",fname,lname);
				break;
			}
		}
		fclose(file);

		file=fopen("..\\students.txt","r");
		temp=fopen("..\\temp.txt","a");
		while(!feof(file)){
			fscanf(file,"%s %s %s %s %s %s %s %c",stid,fname,lname,grade,roll,phone,address,&status);
			if(feof(file)){
				break;
			}
			fprintf(temp,"%s  %s %s  %s  %s  %s  %s  %c\n",stid,fname,lname,grade,roll,phone,address,status);
		}
		fclose(temp);
		fclose(file);

		file=fopen("..\\students.txt","w");
		fclose(file);

		temp=fopen("..\\temp.txt","r");
		file=fopen("...\\students.txt","a");
		while(!feof(temp)){
			fscanf(temp,"%s %s %s %s %s %s %s %c",stid,fname,lname,grade,roll,phone,address,&status);
			if(feof(temp)){
				break;
			}
			pstatus=status;
			if(strcmp(stid,rb.stid)==0){
				status='A';
				fprintf(file,"%s  %s %s  %s  %s  %s  %s  %c\n",stid,fname,lname,grade,roll,phone,address,status);
			}else{
				status=pstatus;
				fprintf(file,"%s  %s %s  %s  %s  %s  %s  %c\n",stid,fname,lname,grade,roll,phone,address,status);
			}
		}
		fclose(file);
		fclose(temp);

		temp=fopen("..\\temp.txt","w");
		fclose(temp);

		printf("\nBook ID: ");
		scanf("%s",rb.bkid);

		book=fopen("..\\books.txt","r");
		while(!feof(book)){
			fscanf(book,"%s %s %s %s %s %d",bk_id,ftitle,ltitle,fauthor,lauthor,&quantity);
			if(strcmp(bk_id,rb.bkid)==0){
				printf("\nTitle: %s %s\n",ftitle,ltitle);
				break;
		       }
		}
		fclose(book);

		book=fopen("..\\books.txt","r");
		tempb=fopen("..\\tempb.txt","a");
		while(!feof(book)){
			fscanf(book,"%s %s %s %s %s %d",bk_id,ftitle,ltitle,fauthor,lauthor,&quantity);
			if(feof(book)){
				break;
			}
			fprintf(tempb,"%s  %s %s  %s %s  %d\n",bk_id,ftitle,ltitle,fauthor,lauthor,quantity);
		}
		fclose(tempb);
		fclose(book);

		book=fopen("..\\books.txt","w");
		fclose(book);

		tempb=fopen("..\\tempb.txt","r");
		book=fopen("..\\books.txt","a");
		while(!feof(tempb)){
			fscanf(tempb,"%s %s %s %s %s %d",bk_id,ftitle,ltitle,fauthor,lauthor,&quantity);
			if(feof(tempb)){
				break;
			}
			if(strcmp(bk_id,rb.bkid)==0){
				quantity=quantity+1;
				fprintf(book,"%s  %s %s  %s %s  %d\n",bk_id,ftitle,ltitle,fauthor,lauthor,quantity);
			}else{
				fprintf(book,"%s  %s %s  %s %s  %d\n",bk_id,ftitle,ltitle,fauthor,lauthor,quantity);
			}
		}
		fclose(book);
		fclose(tempb);

		printf("\nDate (DD/MM/YY): ");
		scanf("%d",&rb.dd);
		gotoxy(22,12);
		scanf("%d",&rb.mm);
		gotoxy(25,12);
		scanf("%d",&rb.yy);

		ret=fopen("..\\return.txt","a");
		fprintf(ret,"%s  %s  Date: %d/ %d/ %d\n",rb.stid,rb.bkid,rb.dd,rb.mm,rb.yy);
		fclose(ret);
	}

int main(){
	clrscr();
	char ch,x;
	int i,menu;
	char adminid[20];
	int z;
	char pass[20];
	char save;
 //		splashScreen();		//Login page
	date();

	login();
	clrscr();
	if(flag==0){
		printf("\nLogin successful");
	}else{
		printf("\nYou are a looser;)");
		delay(5000);
		exit(0);
	}

	delay(2000);
	printf("\nPlease wait while your screen is loading......\n");
	for(z=0;z<=15;z++){
		printf("** ");
		delay(100);
	}
	here:
	clrscr();

	for(i=0;i<80;i++){
		printf("-");

		}
			//Main menu
	printf("\t\t\t**********MAIN MENU**********\n");

	for(i=0;i<80;i++){
		printf("-");

		}
	printf("\n\t\t\t\t1.Add students\n");
	printf("\t\t\t\t2.View student records\n");
	printf("\t\t\t\t3.Add new books\n");
	printf("\t\t\t\t4.Add existing books\n");
	printf("\t\t\t\t5.View available books\n");
	printf("\t\t\t\t6.Issue books\n");
	printf("\t\t\t\t7.Return books\n");
	printf("\t\t\t\t8.Search\n");
	printf("\t\t\t\t9.Exit\n");

	for(i=0;i<80;i++){
		printf("-");

		}

	printf("\n\nChoose any operation: ");
	scanf("%d",&menu);

	switch(menu){
		case 1:
			//student data entry code
			while(1){
				student_data_entry();
				printf("Do you want to continue?(y/n)");
				ch=getch();
				if(ch=='n' || ch=='N'){
					goto here;
				}
			}
		case 2:
			//student data reading code
			student_data_read();
			ch=getch();
			break;
		case 3:
			//books data entry code
			clrscr();
			printf("Enter the following info: ");
			printf("\n\nID   Title\t\tAuthor\t\tQuantity\n");
			while(1){
				entry_books();
				ch=getch();
				if(ch==27){
					printf("Do you want to save the records?(y/n)");
					save=getch();
					if(save=='y' || save=='Y'){
						printf("\n\t\tRECORD SAVED");
						delay(1000);
						goto here;
					}else{
						goto here;
					}
				}
			}
		case 4:
			//adding existing books
			add_existing_books();
			break;
		case 5:
			//books data reading code
			view_book();
			ch=getch();
			break;
		case 6:
			//books issue code
			issue_books();
			ch=getch();
			break;
		case 7:
			//books returned code
			return_book();
			ch=getch();
			break;
		case 8:
			//search code
			search_record();
			ch=getch();
			break;
		case 9:
			//Exit
			clrscr();
			printf("Thanks for using our program");
			delay(2000);
			exit(0);

	}

	goto here;
	getch();
	return 0;
}
