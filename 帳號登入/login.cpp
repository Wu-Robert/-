#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

typedef struct account{
	char name[12];
	char acc[12];
	char code[12];
}Acc;

void gotoxy(int x, int  y){            //移動游標 
        COORD point;
        point.X = x, point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
bool CheckAcc2(char *ac){
	FILE *fp;
	char name[12];
	char acc[12];
	char code[12];
	if((fp=fopen("list.txt","r"))!=NULL){
		while(!feof(fp)){
			fscanf(fp,"%s %s %s\n",name,acc,code);
			if(strcmp(acc,ac)==0){
				fclose(fp);
				return true;
			}
		}
	}
	else{
		printf("error1");
		system("pause");
	}
	fclose(fp);
	return false;
}
void AddAcc(Acc *accc){
	FILE *fp;
	fp=fopen("list.txt","a");
	fprintf(fp,"%s %s %s\n",accc->name,accc->acc,accc->code);
	fclose(fp);
}
void Register(){
	char name[12]={0};
	char acc[12]={0};
	char code[12]={0};
	char checkcode[12]={0};
	printf("請輸入驗證碼:");
	scanf(" %s",checkcode);
	if(strcmp(checkcode,"fcu_iecs")==0){
		system("cls");
		int time=0;
		while(1){
			printf("輸入姓名:");
			printf("%s\n",name);
			printf("輸入帳號:");
			printf("%s\n",acc);
		    printf("輸入密碼:");
		    printf("%s\n",code);
		    if(time==0){
		    	gotoxy(9,0);
		    	scanf("%s",name);
		    	fflush(stdin);
			}
			else if(time==1){
				gotoxy(9,1);
				scanf("%s",acc);
				fflush(stdin);
			}
			else if(time==2){
				gotoxy(9,2);
				scanf("%s",code);
				fflush(stdin);	
			}
			else{
				if(CheckAcc2(acc)){
					strcpy(name,"");
					strcpy(acc,"");
					strcpy(code,"");
					time=0;
					system("cls");
					gotoxy(0,10);
					printf("--此帳號已有人使用--\n重新輸入請按任意鍵(按b返回選單)");
					gotoxy(0,0);
					char temp;
					temp=getch();
					if(temp=='b'||temp=='B')return;
					continue;
			    }
			    else{
			    	Acc *accc=(Acc *)malloc(sizeof(Acc));
			    	strcpy(accc->acc,acc);
			    	strcpy(accc->code,code);
					strcpy(accc->name,name);
					AddAcc(accc);
					FILE *fp;
					char fileName[20]={0};
					strcpy(fileName,accc->acc);
					strcat(fileName,".txt");
					fp=fopen(fileName,"w");
					fprintf(fp,"----- -----\n");
					fprintf(fp,"----- -----\n");
					fclose(fp);
				}
				break;
			}
			time++;
			system("cls");
		}	
	}
	else{
		printf("\n\n錯誤的驗證碼，輸入任意鍵返回選單");
		char temp;
		temp=getch();
	} 
}
Acc* CheckAcc(char *ac,char *co){      //帳密驗證 
	FILE *fp;
	char name[12];
	char acc[12];
	char code[12];
	if((fp=fopen("list.txt","r"))!=NULL){
		while(!feof(fp)){
			fscanf(fp,"%s %s %s\n",name,acc,code);
			if(strcmp(acc,ac)==0&&strcmp(code,co)==0){
				Acc *accc=(Acc*)malloc(sizeof(Acc));
				strcpy(accc->name,name);
				strcpy(accc->acc,acc);
				strcpy(accc->code,code);
				fclose(fp);
				return accc;
			}
		}
	}
	else{
		printf("error2");
		system("pause");
	}
	fclose(fp);
	return NULL;                  //有找到回傳帳密 否則回傳NULL 
}
Acc* Sign_in(){                   //登入 
	int time=0;
	char acc[12]={0};
	char code[12]={0};
	char choose;
	
	while(1){	
		printf("帳號:");
		printf("%s\n",acc);
		printf("密碼:");
		printf("%s\n",code);
		if(time==0){
			gotoxy(5,0);
			scanf("%s",acc);
			fflush(stdin);
		}
		else if(time==1){
			gotoxy(5,1);
			scanf("%s",code);
			fflush(stdin);
		}
		else if(time==2){
			if(CheckAcc(acc,code)!=NULL){
				Acc *ac=(Acc*)malloc(sizeof(Acc));
				ac=CheckAcc(acc,code);
				printf("\n登入成功\，按任意鍵返回選單");
				char temp;
				temp=getch();
				return ac;
			}
			else{
				printf("\n密碼或帳號錯誤，重新輸入請按任意鍵(按b返回選單)");
				char temp;
				temp=getch();
				strcpy(acc,"");
				strcpy(code,"");
				if(temp=='b'||temp=='B'){
					return NULL;
				} 
				time=-1;
			}
		}
		time++;
		system("cls");
	}
	return NULL;             //登入成功回傳帳密 否則回傳NULL 
}
void PrintAcc(Acc *acc){   //
	if(acc==NULL){
		return;
	}
	else{
		printf("Account:%s\n",acc->acc);
	}
}
int list(){                   //選單 
	int choose;
	while(1){
		printf("-----選單-----");
     	printf("\n(1)登入帳號");
	    printf("\n(2)進入程式");
	    printf("\n(3)退出");
	    printf("\n(4)註冊\n");
	    printf("Ans:");
		scanf(" %d",&choose);
		fflush(stdin);
		if(choose==1||choose==2||choose==3||choose==4){
			return choose;
		}
		else{
			char temp;
			printf("\n錯誤選項\n按任意鍵繼續");
			temp=getch();
			system("cls");
		}                       //回傳選擇 
	}
}  
void EndExe(){
	printf("--結束程式--");
} 
