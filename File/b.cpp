#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
typedef struct list{
	char link[70];
	list *next;
	char title[70];
}List;
void gotoxy2(int x, int  y){            //���ʴ�� 
        COORD point;
        point.X = x, point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
void line(List *whead,List *fhead,char *acc){
	char fileName[20]={0};
	char wName[70]={0};
	char fName[70]={0};
	char tName[70]={0};
	List *ptr=fhead;
	List *ptr2=whead;
	strcpy(fileName,"D:/a/File/");
	strcat(fileName,acc);
	strcat(fileName,".txt");
	FILE *fp;
	if((fp=fopen(fileName,"r"))!=NULL){
		while(!feof(fp)){
		    fscanf(fp,"%s %s\n",tName,wName);
	        if(strcmp(tName,"-----")==0){
				break;
			}
		}
		while(!feof(fp)){
			strcpy(fName,"");
			strcpy(tName,"");
			fscanf(fp,"%s %s\n",tName,fName);
			if(strcmp(fName,"")==0){
				break;
			}
			else if(strcmp(tName,"-----")==0){
				break;
			}
			List *temp=(List *)malloc(sizeof(List));
			temp->next=NULL;
			strcpy(temp->link,fName);
			strcpy(temp->title,tName);
			ptr->next=temp;
			ptr=ptr->next;
		}

		while(!feof(fp)){
			strcpy(wName,"");
			strcpy(tName,"");
			fscanf(fp,"%s %s\n",tName,wName);
			if(strcmp(wName,"")==0){
				break;
			}
			List *temp=(List *)malloc(sizeof(List));
			temp->next=NULL;
			strcpy(temp->link,wName);
			strcpy(temp->title,tName);
			ptr2->next=temp;
			ptr2=ptr2->next;
			
		}
	}
    else printf("File is not open");
}
void DeleteNode(List *list){
	system("cls");
	List *ptr=list;
	printf("�n�R��������:");
	char chose;
	chose=getch();
	int choose=chose-48;
	int count=0;
	while(ptr->next!=NULL){
		count++;
		if(ptr->next==NULL){
			printf("�L���`�I!");
			break;
		}
		if(count==choose){
			ptr->next=ptr->next->next;
			printf("�`�I�w�R��!");
			break;
		}
		ptr=ptr->next;
	}
}
void WriteBack(List *fhead,List *whead,char *acc){
	FILE *fp;
	char fileName[20]={0};
	strcpy(fileName,"D:/a/File/");
	strcat(fileName,acc);
	strcat(fileName,".txt");
	fp=fopen(fileName,"w");
	fprintf(fp,"----- -----\n");
	while(fhead->next!=NULL){
		fhead=fhead->next;
		fprintf(fp,"%s %s\n",fhead->title,fhead->link);
	}
	fprintf(fp,"----- -----\n");
	while(whead->next!=NULL){
		whead=whead->next;
		fprintf(fp,"%s %s\n",whead->title,whead->link);
	}
	fclose(fp);
}
void AddNode(List *head){
	system("cls");
	int time=0;
	char title[70]={0};
	char link[70]={0};
	List *ptr=head;
	List *temp=(List *)malloc(sizeof(List));
	temp->next=NULL;
    while(1){
		printf("��J�W��:");
		printf("%s\n",title);
		printf("��J�s��:");
		printf("%s\n",link);
		if(time==0){
			gotoxy2(9,0);
			scanf("%s",title);
			fflush(stdin);
			}
		else if(time==1){
			gotoxy2(9,1);
			scanf("%s",link);
			fflush(stdin);
			}
		else if(time==2){
			char tem[70]={0};
			printf("\n�T�w�O�_�n�x�s(Y):");
			char ch;
			ch=getche();
			if(ch=='y'||ch=='Y'){
				strcpy(temp->title,title);
				strcpy(temp->link,link);
				while(ptr->next!=NULL){
					ptr=ptr->next;
				}
				ptr->next=temp;
				break;
			}
			else{
				strcpy(title,"");
				strcpy(link,"");
				time=-1;
			}
		}
		time++;
		system("cls");
	}
}
void Show(List *list){
	List *ptr=list;
	int i=1;
	gotoxy2(0,2);
	while(ptr->next!=NULL){
		ptr=ptr->next;
		printf("%-2d %s\n",i,ptr->title);
		i++;
	}
	printf("---------------------------\n");
	printf("a ���}���\n");
	printf("b �R�����\n");
	printf("c �s�W���");
	gotoxy2(0,1);
}
void exe(char *link){
	char linker[70]={0};
	strcat(linker,"START ");
	strcat(linker,link);
	system(linker);
}
void Check_exe(List *head,int num){
	List *ptr=head;
	int i=0;
	while(ptr->next!=NULL){
		ptr=ptr->next;
		i++;
		if(i==num){
			exe(ptr->link);
			return;
		}
	}
	printf("�L���ﶵ");
}
void chose(List *head,int mode,List *ohead,char *acc){
	while(1){
		system("cls");
		if(mode==1)printf("--���--");
		else if(mode==2)printf("--����--");
		Show(head);
	    int temp;
	    temp=getch();
	    if(temp=='a'){
	    	break;
		}
		else if(temp=='b'){
			DeleteNode(head);
			if(mode==1){
				WriteBack(head,ohead,acc);
			}
			else WriteBack(ohead,head,acc);
		}
		else if(temp=='c'){
			AddNode(head);
			if(mode==1){
				WriteBack(head,ohead,acc);
			}
			else WriteBack(ohead,head,acc);
		}
	    temp-=48;
	    Check_exe(head,temp);	
	}
}
void list2(char *acc){
	char choose;
	List *whead=(List *)malloc(sizeof(List));
	whead->next=NULL;
	List *fhead=(List *)malloc(sizeof(List));
	fhead->next=NULL;
	line(whead,fhead,acc);
	while(1){
		system("cls");
		printf("----�M��----\n");
	    printf("(a)���\n");
	    printf("(b)����\n");
	    choose=getch();
	    fflush(stdin);
	    switch(choose){
	    	case 'A':
	    	case 'a':
	    		chose(fhead,1,whead,acc);
	    		break;
	    	case 'B':
	    	case 'b':
	    		chose(whead,2,fhead,acc);
	    		break;
	    	default:
	    		;
	    }
	}
}
