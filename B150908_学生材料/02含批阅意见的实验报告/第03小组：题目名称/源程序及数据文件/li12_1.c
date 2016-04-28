/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"book.h"

void printHead( )      /*��ӡͼ����Ϣ�ı�ͷ*/
{
printf("%-20s%-21s%-22s%-17s%-11s%-11s%-10s%-11s%-10s\n","ISBN","����","������","����","�ۼ�","����","����","����","����");
}

void menu( )         	/*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ͼ���������� ********\n");
		printf("******** 4. ͼ������ͳ�� ********\n");
		printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�       ********\n");
}

void menuBase( )     /*������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ����ͼ���¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ��ͼ���¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸�ͼ���¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuSale( )     /*ͼ����������˵�����*/
{
		printf("@@@@@@@@ 1. ����ͼ������ @@@@@@@@\n");
		printf("@@@@@@@@ 2. ������������ @@@@@@@@\n");
        printf("@@@@@@@@ 3. ������������ @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuProfit( )    /*ͼ������ͳ�Ʋ˵�����*/
{
        printf("&&&&&&&& 1. ���ͼ������ &&&&&&&&\n");
		printf("&&&&&&&& 2. ���������� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*����������ѯ�˵�����*/
{
		printf("######## 1. ��ISBN��ѯ  ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		printf("######## 3. �����߲�ѯ   ########\n");
		printf("######## 4. ���������ѯ ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Book b[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
{  
	int choice,t,find[NUM];
	char judge1='n',judge2='n';
	Book b1;
	do
	{   
		menuBase( );					/*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:");
		scanf("%d",&choice);	        /*����ѡ��*/
		switch(choice)
		{
			case 1:	 readBook(&b1,1);   /*����һ���������ͼ����Ϣ*/
				n=insertBook(b,n,b1);   /*���ú�������ͼ����Ϣ*/
				break;
			case 2:  printf("Input the ISBN deleted\n");
				scanf("%s",b1.ISBN);    	/*����һ����ɾ��ͼ���ISBN*/
				n=deleteBook(b,n,b1);   	/*���ú���ɾ��ָ��ISBN��ͼ���¼*/
				break;
			case 3:
                do
				{
					printf("Input the ISBN you want search: \n");
					scanf("%s",b1.ISBN);    /*����һ��������ͼ���ISBN*/
                    getchar();
					t=searchBook(b,n,b1,1,find) ; /*���ú�������ָ��ISBN��ͼ���¼*/
					if (t)                  /*�����ISBN�ļ�¼����*/
					{
						printf("change this information? (y/n)\n");
						scanf("%c",&judge2);
						if (judge2 == 'y')   /*�ж��Ƿ��޸ĸ�����Ϣ*/
						{
							readBook(&b1,1); /*����һ��������ͼ���¼��Ϣ*/
							b[find[0]]=b1;   /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/
						}
					}					 
					else                     /*���ISBN�ļ�¼������*/
					{
						printf("this book is not in.\ninput again? (y/n)\n"); /*�����ʾ��Ϣ*/
						scanf("%c",&judge1);
					}
				} while (judge1 == 'y');
				break;
			case 0: 
                break;
        }
    } while (choice);
	return n;                               /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

int saleManage(Book b[],int n)				/*�ú������ͼ������������*/
{  
	int choice;
	do
	{
		menuSale( );                       	/*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:");
		scanf("%d",&choice);                /*�������ѡ��*/
		switch(choice)
		{
			case 1: n=calcuTotal(b,n);        /*������ͼ�������*/
                printBook(b, n);
				break;
			case 2: sortBook(b,n,5);        /*����ͼ����������*/
                printBook(b, n);
				break;
            case 3: reverse(b, n);
                printBook(b, n);
                break;
            case 0:
				break;
		}
	}while(choice);
    return n;
}

void profitManage(Book b[],int n)       /*�ú����������ͳ�ƹ���*/
{
    int choice;
    getchar();
    do
    {
        menuProfit();                   /*��ʾ��Ӧ�Ķ����˵�*/
        printf("choose one operation you want to do:\n");
        scanf("%d",&choice);
        switch(choice)
        {
                case 1:
                    n=calcuTotal(b,n);
                    calcuProfit(b,n);					/*���ú������ͼ������*/
                    sortBook(b, n, 3);
                    printBook(b,n);
                    break;
                case 2:
                    reverse(b, n);
                    printBook(b, n);
                    break;
                case 0:
                    break;
                default:
                    printf("Choice error!\n");
                    break;
        }
    } while (choice);
}

void searchManage(Book b[],int n)            /*�ú�����ɸ���������ѯ����*/
{
    Book b1;
	int i,choice,findnum,f[NUM];
	do
	{
		menuSearch( );                       /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:   printf("Input a book\'s ISBN will be searched:\n");
			    scanf("%s",b1.ISBN);         /*�������ͼ���ISBN*/
				break;
			case 2:   printf("Input a book\'s name will be searched:\n");
				 scanf("%s",b1.name);	     /*�������ͼ������*/
				 break;   
			case 3:   printf("Input an author  will be searched:\n");
				 scanf("%s",b1.author);      /*�������ͼ�������*/
				 break;
			case 4:   printf("Input a press  will be searched:\n");
				  scanf("%s",b1.press);      /*�������ͼ��ĳ�����*/
				  break;
            case 0:
				  break;
		}
		if (choice>=1 && choice<=4)
		{ 
			findnum=searchBook(b,n,b1,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
			if (findnum)                            /*������ҳɹ�*/
			{
				for (i=0;i<findnum;i++)       /*ѭ������f������±�*/
	      		printBook(&b[f[i]],1);        /*ÿ�����һ����¼*/
			}
		    else
			    printf("this record does not exist!\n\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		 }
	}while (choice);
}

int runMain(Book b[],int n,int choice)        /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1:                           /* 1. ��ʾ������Ϣ*/
				 sortBook(b,n,1);             /*��ISBN��С�����˳�������¼*/
				 printBook(b,n);              /*��ISBN��С�����˳��������м�¼*/
				 break;
			case 2: n=baseManage(b,n);        /* 2. ������Ϣ����*/
			   	     break;
			case 3: n=saleManage(b,n);        /* 3. ͼ����������*/
				break;
			case 4: profitManage(b,n);        /* 4. ͼ������ͳ��*/
				break;
			case 5: searchManage(b,n);        /* 5. ����������ѯ*/
				break;
			case 0: 
				break;
		}
		return n;
}

int main( )
{
	 Book b[NUM];                 /*����ʵ��һά����洢ͼ���¼*/
     int choice,n=0;              /*n��ֵ0*/
	 printf("Input information from a file or keyboard? [1(file)/2(keyboard)]\n"); /*ѯ����Ϣ���뷽ʽ*/
	 scanf("%d",&choice);         /*����ѡ��*/
	 if (choice == 1)
		n=readFile(b);            /*��ȡ�ļ�����¼�������ظ�ֵ��n*/
	 else if (choice == 2)
	 {
		 printf("\nInput an integer to indicate how many pieces of information to be input: \n");
		 scanf("%d",&n);
		 n=readBook(b,n);
	 }
	 else
     {
		 printf("choice error!\n");      /*�����1��2���ְ�Ĭ�Ϸ�ʽִ�У����ļ���ȡ*/
         printf("Execute by default��\n");
     }
	 if (!n)                     /*���ԭ�����ļ�Ϊ��*/
	 {
         // printf("Target file is empty!\n");
		 n=createFile(b);        /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
	 }	 	 
	 do
	 {
	     menu();                 /*��ʾ�˵�*/
	     printf("Please input your choice: ");
	     scanf("%d",&choice);
	     if (choice>=0 && choice<=5)
			n=runMain(b,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	     else 
		    printf("Error input,please input your choice again!\n");
	} while (choice);
	sortBook(b,n,1);                  /*�����ļ�ǰ��ISBN��С��������*/
	saveFile(b,n);                    /*����������ļ�*/
    return 0;
}