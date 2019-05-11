#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include"a.cpp"
#include"b.cpp"

int main(){
	FILE *fp;
	int choose;
	Acc *acc=NULL;
	bool sign_in=false;	
	while(1){
		system("cls");
		PrintAcc(acc);
		choose=list();
		switch(choose){
			case 1:
				system("cls");
				acc=Sign_in();
				break;
			case 2:
				system("cls");
				if(acc==NULL){
					printf("請先登入帳號(按任意鍵繼續)");
				    char temp;
				    temp=getch();
				}
				else{
					list2(acc->acc);
				}
				break;
			case 3:
				system("cls");
				EndExe();
				return 0;
				break;
			case 4:
				system("cls");
				Register();
				break;
			default:
				printf("NO");
		}
	}
	return 0;
} 
