/*��book.c�ļ�����������*/
#include "book.h"
#include <stdio.h>

int readBook(Book  *b , int n)          /*����ͼ���¼ֵ��ISBN�����涨������¼ʱֹͣ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input a book\'s information\n");
		printf(" ISBN:  ");
		scanf("%s", b[i].ISBN);
		printf(" name: ");
		scanf("%s",b[i].name);
		printf(" press:  ");
		scanf("%s",b[i].press);
        b[i].profit=0;                  /*������Ҫ������ã���ֵ��Ϊ0*/
		printf(" author:  ");
		scanf("%s",b[i].author);
		printf(" price_out:  ");
		scanf("%f",&b[i].price_out);
		printf(" price_in:  ");
		scanf("%f",&b[i].price_in);
		printf(" sale:  ");
		scanf("%d",&b[i].sale);
		printf(" number:  ");
		scanf("%d",&b[i].number);
        printf("\n");
	}
	return i;                           /*����ʵ�ʶ���ļ�¼����*/
}

void printBook ( Book  *b , int n)      /*�������ͼ���¼��ֵ*/
{
	int i;
    printHead();
	for (i=0;i<n;i++)
	{
		printf("%-20s", b[i].ISBN);
		printf("%-18s", b[i].name);
		printf("%-18s", b[i].press);
		printf("%-15s", b[i].author);
	    	printf("%-8.2lf", b[i].price_out);
		printf("%-8.2lf", b[i].price_in);
		printf("%-8d", b[i].sale);
		printf("%-8d", b[i].number);
	    	printf("%-10.2lf\n", b[i].profit);
	}
}

int equal(Book b1,Book b2,int condition)  /*����ж�����Book��¼���*/
{
	if (condition==1)                     /*�������condition��ֵΪ1����Ƚ�ISBN*/
	{
		if (strcmp(b1.ISBN,b2.ISBN)==0)
			return 1;
		else 
			return 0;
	}
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
	{
		if (strcmp(b1.name,b2.name)==0)
			return 1;
		else 
			return 0;
	}
	else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
	{
		if (strcmp(b1.author,b2.author)==0)
			return 1;
		else 
			return 0;
	}
	else if (condition==4)                /*�������condition��ֵΪ4����Ƚϳ�����*/
	{
		if (strcmp(b1.press,b2.press)==0)
			return 1;
		else 
			return 0;
	}
	else if (condition==5)                /*�������condition��ֵΪ5����Ƚ�����*/
		return b1.sale==b2.sale;
	else if (condition==6)                /*�������condition��ֵΪ6����Ƚ�����*/
		return b1.profit==b2.profit;
	else return 1;                        /*�����������1*/
} 

int larger(Book b1, Book b2, int condition)  /*����condition�����Ƚ�����Book��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ISBN*/
		return b1.ISBN>b2.ISBN;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ�����*/
		return b1.sale>b2.sale;	
	if (condition==3)                    /*�������condition��ֵΪ3����Ƚ�����*/
		return b1.profit>b2.profit;
	else return 1;                            /*�����������1*/
}

void reverse(Book b[],int n)                  /*����Ԫ������*/
{
	int i;
	Book temp;
	for (i=0;i<n/2;i++)                       /*ѭ������ΪԪ��������һ��*/
	{
		temp=b[i];
		b[i]=b[n-1-i];
		b[n-1-i]=temp;
	}
}

void calcuProfit(Book b[],int n)              /*��������ͼ�������*/
{
	int i;
	for (i=0;i<n;i++)                         /*ѭ����������ͼ���¼*/
	b[i].profit = (b[i].price_out - b[i].price_in)*b[i].sale;		/*��������*/
}

int calcuTotal(Book b[], int n)              /*���ж���ͼ����Ϣ����������Ϊһ��*/
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
			if (equal(b[i],b[j],1))           /*�����������ͬһ�鱾����Ϣ������������Ӳ�ɾȥ����һ����Ϣ*/
			{
				addBook(b,i,j);
                n=deleteBook(b,n,b[j]);
			}
    return n;
}

void sortBook(Book b[],int n,int condition)   /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                           /*minpos�����洢������СԪ�����ڵ��±�*/
	Book t;
	for (i=0;i<n-1;i++)                       /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)                   /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(b[minpos],b[j],condition))
				minpos=j;
		if (i!=minpos)                        /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=b[i];
			b[i]=b[minpos];
			b[minpos]=t;
		}
	}
}

int searchBook(Book b[],int n,Book b1,int condition,int f[ ])  /*��b��������condition��������*/
/*��b1��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                         /*�����ҵ�Ԫ��*/
		if (equal(b[i],b1,condition))  
		{
			f[j++]=i;                         /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;                           /*ͳ���ҵ���Ԫ�ظ���*/
		}
	 return find;                             /*����find����ֵΪ0���ʾû�ҵ�*/
}

void addBook (Book b[], int pos, int aim)     /*ͬһͼ����Ϣ���*/
{
    b[pos].sale += b[aim].sale;               /*�������*/
    b[pos].profit+= b[aim].profit;            /*�������*/
    if (b[pos].number > b[aim].number)        /*ȡ��������С��Ϊ��������*/
        b[pos].number = b[aim].number;
}

int insertBook(Book b[],int n,Book b1)        /*��b��������ѧ�ŵ�������һ��Ԫ��s*/
{
    b[n++]=b1;
    sortBook(b, n, 1);
	//printBook(b, n);
	return n;                                 /*��������Ԫ�ظ���*/
}

int deleteBook(Book b[],int n,Book b1)        /*��������ɾ��ָ��������һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(b[i],b1,1) && equal(b[i],b1,5))
            break;                              /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)									/*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                      /*�˴���������Ϊi<n��equal(b[i],b1,1)����*/ 
		b[j]=b[j+1];					       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ�������1*/
	return n;                                 /*�������и���*/
}
