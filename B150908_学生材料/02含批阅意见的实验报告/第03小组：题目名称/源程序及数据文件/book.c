/*②book.c文件的完整内容*/
#include "book.h"
#include <stdio.h>

int readBook(Book  *b , int n)          /*读入图书记录值，ISBN读满规定条数记录时停止*/
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
        b[i].profit=0;                  /*利润需要计算求得，初值置为0*/
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
	return i;                           /*返回实际读入的记录条数*/
}

void printBook ( Book  *b , int n)      /*输出所有图书记录的值*/
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

int equal(Book b1,Book b2,int condition)  /*如何判断两个Book记录相等*/
{
	if (condition==1)                     /*如果参数condition的值为1，则比较ISBN*/
	{
		if (strcmp(b1.ISBN,b2.ISBN)==0)
			return 1;
		else 
			return 0;
	}
	else if (condition==2)                /*如果参数condition的值为2，则比较书名*/
	{
		if (strcmp(b1.name,b2.name)==0)
			return 1;
		else 
			return 0;
	}
	else if (condition==3)                /*如果参数condition的值为3，则比较作者*/
	{
		if (strcmp(b1.author,b2.author)==0)
			return 1;
		else 
			return 0;
	}
	else if (condition==4)                /*如果参数condition的值为4，则比较出版社*/
	{
		if (strcmp(b1.press,b2.press)==0)
			return 1;
		else 
			return 0;
	}
	else if (condition==5)                /*如果参数condition的值为5，则比较销量*/
		return b1.sale==b2.sale;
	else if (condition==6)                /*如果参数condition的值为6，则比较利润*/
		return b1.profit==b2.profit;
	else return 1;                        /*其余情况返回1*/
} 

int larger(Book b1, Book b2, int condition)  /*根据condition条件比较两个Book记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较ISBN*/
		return b1.ISBN>b2.ISBN;
	if (condition==2)                    /*如果参数condition的值为2，则比较销量*/
		return b1.sale>b2.sale;	
	if (condition==3)                    /*如果参数condition的值为3，则比较利润*/
		return b1.profit>b2.profit;
	else return 1;                            /*其余情况返回1*/
}

void reverse(Book b[],int n)                  /*数组元素逆置*/
{
	int i;
	Book temp;
	for (i=0;i<n/2;i++)                       /*循环次数为元素数量的一半*/
	{
		temp=b[i];
		b[i]=b[n-1-i];
		b[n-1-i]=temp;
	}
}

void calcuProfit(Book b[],int n)              /*计算所有图书的利润*/
{
	int i;
	for (i=0;i<n;i++)                         /*循环控制所有图书记录*/
	b[i].profit = (b[i].price_out - b[i].price_in)*b[i].sale;		/*计算利润*/
}

int calcuTotal(Book b[], int n)              /*若有多条图书信息，将其整合为一条*/
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
			if (equal(b[i],b[j],1))           /*如果存在两条同一书本的信息，销量利润相加并删去其中一条信息*/
			{
				addBook(b,i,j);
                n=deleteBook(b,n,b[j]);
			}
    return n;
}

void sortBook(Book b[],int n,int condition)   /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                           /*minpos用来存储本趟最小元素所在的下标*/
	Book t;
	for (i=0;i<n-1;i++)                       /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)                   /*寻找本趟最小元素所在的下标*/
			if (larger(b[minpos],b[j],condition))
				minpos=j;
		if (i!=minpos)                        /*保证本趟最小元素到达下标为i的位置*/
		{
			t=b[i];
			b[i]=b[minpos];
			b[minpos]=t;
		}
	}
}

int searchBook(Book b[],int n,Book b1,int condition,int f[ ])  /*在b数组中依condition条件查找*/
/*与b1相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                         /*待查找的元素*/
		if (equal(b[i],b1,condition))  
		{
			f[j++]=i;                         /*找到了相等的元素，将其下标放到f数组中*/
			find++;                           /*统计找到的元素个数*/
		}
	 return find;                             /*返回find，其值为0则表示没找到*/
}

void addBook (Book b[], int pos, int aim)     /*同一图书信息相加*/
{
    b[pos].sale += b[aim].sale;               /*销量相加*/
    b[pos].profit+= b[aim].profit;            /*利润相加*/
    if (b[pos].number > b[aim].number)        /*取两个余量小者为最终余量*/
        b[pos].number = b[aim].number;
}

int insertBook(Book b[],int n,Book b1)        /*向b数组中依学号递增插入一个元素s*/
{
    b[n++]=b1;
    sortBook(b, n, 1);
	//printBook(b, n);
	return n;                                 /*返回现有元素个数*/
}

int deleteBook(Book b[],int n,Book b1)        /*从数组中删除指定销量的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(b[i],b1,1) && equal(b[i],b1,5))
            break;                              /*如果找到相等元素则退出循环*/
	if (i==n)									/*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                      /*此处隐含条件为i<n且equal(b[i],b1,1)成立*/ 
		b[j]=b[j+1];					       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少1*/
	return n;                                 /*返回现有个数*/
}
