#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

int userType;
char username[25],pwd[25];

struct credentials{
	char usName[25];
	char passW[25];
	int flag;

};
struct user{
	char name[20];
	int age;
	char address[100];
	char gender;
	char qualification[30];
	char programmingLanguage[35];
	char talents[50];
	char userName[20];
	char passWord[20];
	int flag;
};
struct adminQueue{
	char userName[20];
	struct adminQueue * next;
};
typedef struct credentials cred;
typedef struct user user;
typedef struct adminQueue adminQ;

adminQ * front = NULL;
adminQ * rear = NULL;
adminQ * temp;
user newUser;
user existingUser;
cred obj1;
user Users[10];
user Users1[10];

void signUpNewUser();
void login();
void mainMenu(int usrType);
void loadRequest();
void enqueue(char usName[]);
void dispQueue();
void dispUserRecords();

void main(){
	int ch;
	while(ch!=3){
		printf("\n\t\t\tWelcome To MYST\t\t\t");
		printf("\n\t_______________________________________________\n\n");
		printf("\n\t1. Login \n\t2. SignUp\n\t3. Exit\n\tSelect your required service...\n\t");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				login();
				break;
			case 2:
				signUpNewUser();
				break;
			case 3:
				break;
			case 4:
//				 adminView();
				break;
			default:
				system("cls");
				break;
		}
	}
}

void dispUserRecords(){
	int i,j;
	FILE *fp;
	fp= fopen("userRecords.txt","r");
	if(fp==NULL){
		printf("\nCannot Open File!");
		getchar();
		system("cls");
	}
	else{
		char str[300];
		i=-1;
		while(fgets(str,300,fp)){

			char * token=strtok(str, "|");
			i++;
			strcpy(Users1[i].userName,token);
			token = strtok(NULL, "|");				
			strcpy(Users1[i].name,token);
			token = strtok(NULL, "|");				
			Users1[i].age=atoi(token);
			token = strtok(NULL, "|");				
			strcpy(Users1[i].address,token);
			token = strtok(NULL, "|");				
			Users1[i].gender=token;
			token = strtok(NULL, "|");				
			strcpy(Users1[i].qualification,token);
			token = strtok(NULL, "|");				
			strcpy(Users1[i].programmingLanguage,token);
			token = strtok(NULL, "|");				
			strcpy(Users1[i].talents,token);
			token = strtok(NULL, "|");	
		}
	fclose(fp);
	
	for(j=0;j<=i;j++){
		printf("\n\t**************************************");
		printf("\n\tName: %s",Users1[j].name);
		printf("\n\tAge: %d",Users1[j].age);
		printf("\n\tAddress: %s",Users1[j].address);
//		printf("\n\tGender: %c",Users1[j].gender);
		printf("\n\tQualification: %s",Users1[j].qualification);
		printf("\n\tProgramming Languages: %s",Users1[j].programmingLanguage);
		printf("\n\tTalents: %s",Users1[j].talents);
	}
	
	printf("\nClick enter for Main Menu");
	getchar();
	getchar();
}

}

void dispQueue(){
	temp=front;
	int i,j;
	FILE *fp;
	fp= fopen("userRecords.txt","r");
	if(fp==NULL){
		printf("\nCannot Open File!");
		getchar();
		system("cls");
	}
	else{
		char str[300];
		i=-1;
		while(fgets(str,300,fp)){

			char * token=strtok(str, "|");
			i++;
			strcpy(Users[i].userName,token);
			token = strtok(NULL, "|");				
			strcpy(Users[i].name,token);
			token = strtok(NULL, "|");				
			Users[i].age=atoi(token);
			token = strtok(NULL, "|");				
			strcpy(Users[i].address,token);
			token = strtok(NULL, "|");				
			Users[i].gender=token;
			token = strtok(NULL, "|");				
			strcpy(Users[i].qualification,token);
			token = strtok(NULL, "|");				
			strcpy(Users[i].programmingLanguage,token);
			token = strtok(NULL, "|");				
			strcpy(Users[i].talents,token);
			token = strtok(NULL, "|");	
		}
	fclose(fp);
	
	while(temp!=NULL){
		for(j=0;j<=i;j++){
//				printf("\n\t %s",temp->userName);
//				printf("\n\t %s",Users[j].userName);
				if(strcmp(temp->userName,Users[j].userName)==0)
				{
					printf("\n\t**************************************");
					printf("\n\tName: %s",Users[j].name);
					printf("\n\tQualification: %s",Users[j].qualification);
					printf("\n\tProgramming Languages: %s",Users[j].programmingLanguage);
					printf("\n\tTalents: %s",Users[j].talents);
					break;
				}	
		}
		temp=temp->next;
		//printf("\ntemp=temp->next");
	}	
	}
	
}
void enqueue(char usName[]){
	temp=(adminQ *)malloc(sizeof(adminQ));
	strcpy(temp->userName,usName);
	temp->next=NULL;
	if(front==NULL){
		front=temp;
		rear=temp;
	}
	else{
		rear->next=temp;
		rear=rear->next;
	}
}
void loadRequest(){
	int i=0;
	FILE *fp;
	fp= fopen("credentials.txt","r");
	if(fp==NULL){
		printf("\nCannot Open File!");
		getchar();
		system("cls");
	}
	else{
		char str[300];
			i=-1;
			while(fgets(str,300,fp)){		
				char *token = strtok(str, "|");		
				i++;
				strcpy(obj1.usName,token);	
				token = strtok(NULL, "|");				
				strcpy(obj1.passW,token);
				token = strtok(NULL, "|");				
				obj1.flag =atoi(token);
				token = strtok(NULL, "|");
				if(obj1.flag==0){
					enqueue(obj1.usName);
				}
			}
	}
	fclose(fp);
	dispQueue();

	printf("\nClick enter for Main Menu");
	getchar();
	getchar();
	front=NULL;
	rear=NULL;

}
void mainMenu(int usrType){
	int ch;
	if(usrType==1){
		do{
		system("cls");
		printf("\n\t\t\tWelcome To MYST\t\t\t");
		printf("\n\t_______________________________________________\n\n");
		printf("\n\t 1. View pending request\n\t 2. View MYST users\n\t 3. Logout\n\t Select\n\t ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				loadRequest();
				break;
			case 2:
				dispUserRecords();
				break;
			case 3:
				system("cls");
				main();
			break;	
		}
		}while(ch!=3);
			sleep(5);
	}
	else if(usrType==2){
		FILE * fp;
		char fileName[30];
		sprintf(fileName,"%s.txt",username);
		printf("\n\t%s",fileName);
		fopen(fileName,"r");
		if(fp==NULL){
			printf("\nCannot Open File!");	
		}
		else{
		
		char str[300];
		while(fgets(str,300,fp)){
//		fgets(str,300,fp);
			printf("iNSIDE WHIILE");
			printf("%s",str);
			char *token = strtok(str, "|");
			printf("%s",token);
			printf("\n\tUName: %s",token);
			token = strtok(NULL, "|");
			printf("\n\tName: %s",token);
			token = strtok(NULL, "|");
			printf("\n\tAge: %s",token);
			token = strtok(NULL, "|");
			printf("\n\tAddress: %s",token);
			token = strtok(NULL, "|");
			printf("\n\tGender: %s",token);
			token = strtok(NULL, "|");
			printf("\n\tSpecialization: %s",token);
			token = strtok(NULL, "|");
			printf("\n\tProgramming Languages: %s",token);
			token = strtok(NULL, "|");
			printf("\n\tTalent: %s",token);	
			token = strtok(NULL, "|");
		}
																			
		fclose(fp);

	}
	printf("\nClick enter for Logout");
	getchar();
	sleep(5);	
	}
}
void login(){
	cred cred[25];
	int i=0,j;
	
	char ch;
		fflush(stdin);
		system("cls");
		printf("\n\t\t\tWelcome To MYST\t\t\t");
		printf("\n\t_______________________________________________\n\n");
		printf("\n\tEnter the UserName: ");
		gets(username);
		printf("\n\tEnter the Password: ");
		while(1){
        ch = getch();
        if(ch == ENTER || ch == TAB){
            pwd[i] = '\0';
            break;
        }
		else if(ch == BCKSPC){
            if(i>0){
                i--;
                printf("\b \b");
            }
        }
		else
		{
            pwd[i++] = ch;
            printf("* \b");
        }
    	}
    if(strcmp(username,"admin")==0 && strcmp(pwd,"admin")==0){
		system("cls");
		printf("\n\t\t\tWelcome To MYST\t\t\t");
		printf("\n\t_______________________________________________\n\n");
		printf("\n\tWelcome Admin");
		userType=1;
		mainMenu(userType);
	}
	else{
	
		FILE *fp;
		fp= fopen("credentials.txt","r");
		if(fp==NULL){
			printf("\nCannot Open File!");
			getchar();
			system("cls");	
		}
		else{
			char str[300];
			i=-1;
			while(fgets(str,300,fp)){		//to read the file and fetch cred details
				char *token = strtok(str, "|");		//to split the line using |
				i++;
				strcpy(cred[i].usName,token);		//assinging the 1st character to structure
				token = strtok(NULL, "|");
				strcpy(cred[i].passW,token);
				token = strtok(NULL, "|");
				cred[i].flag=atoi(token);
			}
			fclose(fp);
			for(j=0;j<=i;j++){
				if(strcmp(cred[j].usName,username)==0 && strcmp(cred[j].passW,pwd)==0){
						system("cls");					
						printf("\n\t\t\tWelcome To MYST\t\t\t");
						printf("\n\t_______________________________________________\n\n");
						printf("\n\tWelcome User %s",cred[j].usName);
						userType=2;
						mainMenu(userType);
				}
			}
		}
	}
}
void signUpNewUser(){
	system("cls");
	printf("\n\t\t\tWelcome To MYST\t\t\t");
	printf("\n\t_______________________________________________\n\n");
	getchar();
	printf("\n\t Name                       :");
	gets(newUser.name);
	printf("\n\t Age                        :");
	scanf("%d",&newUser.age);
	getchar();
	printf("\n\t Address                    :");
	gets(newUser.address);
	printf("\n\t Gender(F/M)                :");
	scanf("%c",&newUser.gender);
	getchar();
	printf("\n\t Qualification              :");
	gets(newUser.qualification);
	printf("\n\t Programming Language Known :");
	gets(newUser.programmingLanguage);
	printf("\n\t Mention Your Talents       :");
	gets(newUser.talents);
	printf("\n\t User Name                  :");
	gets(newUser.userName);
	printf("\n\t Password                   :");
	gets(newUser.passWord);
	newUser.flag=0;
	
	FILE * fp;
	char fileName[30];
	sprintf(fileName,"%s.txt",newUser.userName);
	
	// Individual file creation
	fp=fopen(fileName,"w");
	if(fp==NULL){
		printf("\nCannot Open File!");	
	}
	else{
		fprintf(fp,"%s",newUser.userName);
		fprintf(fp,"|");
		fprintf(fp,"%s",newUser.name);
		fprintf(fp,"|");
		fprintf(fp,"%d",newUser.age);
		fprintf(fp,"|");
		fprintf(fp,"%s",newUser.address);
		fprintf(fp,"|");
		fprintf(fp,"%c",newUser.gender);
		fprintf(fp,"|");
		fprintf(fp,"%s",newUser.qualification);
		fprintf(fp,"|");
		fprintf(fp,"%s",newUser.programmingLanguage);
		fprintf(fp,"|");
		fprintf(fp,"%s",newUser.talents);
	}
	fclose(fp);
	
	//grouped data for admin 
	fp=fopen("userRecords.txt","a+");
	if(fp==NULL){
		printf("\nCannot Open File!");	
	}
	else{
		fprintf(fp,"\n");
		fprintf(fp,"%s",newUser.userName);
		fprintf(fp,"|");
		fprintf(fp,"%s",newUser.name);
		fprintf(fp,"|");
		fprintf(fp,"%d",newUser.age);
		fprintf(fp,"|");
		fprintf(fp,"%s",newUser.address);
		fprintf(fp,"|");
		fprintf(fp,"%c",newUser.gender);
		fprintf(fp,"|");
		fprintf(fp,"%s",newUser.qualification);
		fprintf(fp,"|");
		fprintf(fp,"%s",newUser.programmingLanguage);
		fprintf(fp,"|");
		fprintf(fp,"%s",newUser.talents);
	}
	fclose(fp);
	
	//password file
	fp= fopen("credentials.txt","a+");
	if(fp==NULL){
		printf("\nCannot Open File!");	
	}
	else{
		fprintf(fp,"\n");
		fprintf(fp,"%s",newUser.userName);
	  	fprintf(fp,"|");
	  	fprintf(fp,"%s",newUser.passWord);
	  	fprintf(fp,"|");
	  	fprintf(fp,"%d",newUser.flag);
	}
	fclose(fp);
	
	system("cls");
	printf("\n\t\t\tWelcome To MYST\t\t\t");
	printf("\n\t_______________________________________________\n\n");
	printf("\n\n\t New user is created sucessfuly. Please wait for Admin Approval and try login with your username and password..");
	getchar();
	system("cls");
	
	
	
}

