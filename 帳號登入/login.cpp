#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

typedef struct account{
	char name[12];
	char acc[12];
	char code[12];
}Acc;

void gotoxy(int x, int  y){            //���ʴ�� 
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
	printf("�п�J���ҽX:");
	scanf(" %s",checkcode);
	if(strcmp(checkcode,"fcu_iecs")==0){
		system("cls");
		int time=0;
		while(1){
			printf("��J�m�W:");
			printf("%s\n",name);
			printf("��J�b��:");
			printf("%s\n",acc);
		    printf("��J�K�X:");
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
					printf("--���b���w���H�ϥ�--\n���s��J�Ы����N��(��b��^���)");
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
		printf("\n\n���~�����ҽX�A��J���N���^���");
		char temp;
		temp=getch();
	} 
}
Acc* CheckAcc(char *ac,char *co){      //�b�K���� 
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
	return NULL;                  //�����^�Ǳb�K �_�h�^��NULL 
}
Acc* Sign_in(){                   //�n�J 
	int time=0;
	char acc[12]={0};
	char code[12]={0};
	char choose;
	
	while(1){	
		printf("�b��:");
		printf("%s\n",acc);
		printf("�K�X:");
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
				printf("\n�n�J���\\�A�����N���^���");
				char temp;
				temp=getch();
				return ac;
			}
			else{
				printf("\n�K�X�αb�����~�A���s��J�Ы����N��(��b��^���)");
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
	return NULL;             //�n�J���\�^�Ǳb�K �_�h�^��NULL 
}
void PrintAcc(Acc *acc){   //
	if(acc==NULL){
		return;
	}
	else{
		printf("Account:%s\n",acc->acc);
	}
}
int list(){                   //��� 
	int choose;
	while(1){
		printf("-----���-----");
     	printf("\n(1)�n�J�b��");
	    printf("\n(2)�i�J�{��");
	    printf("\n(3)�h�X");
	    printf("\n(4)���U\n");
	    printf("Ans:");
		scanf(" %d",&choose);
		fflush(stdin);
		if(choose==1||choose==2||choose==3||choose==4){
			return choose;
		}
		else{
			char temp;
			printf("\n���~�ﶵ\n�����N���~��");
			temp=getch();
			system("cls");
		}                       //�^�ǿ�� 
	}
}  
void EndExe(){
	printf("--�����{��--");
} 
