/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"book.h"

void printHead( )      /*打印图书信息的表头*/
{
printf("%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n","ISBN","书名","出版社","作者","售价","进价","销量","余量","利润");
}

void menu( )         	/*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 图书销量管理 ********\n");
		printf("******** 4. 图书利润统计 ********\n");
		printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出       ********\n");
}

void menuBase( )     /*基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入图书记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除图书记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 查改图书记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuSale( )     /*图书销量管理菜单函数*/
{
		printf("@@@@@@@@ 1. 计算图书销量 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 根据销量排序 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuProfit( )    /*图书利润统计菜单函数*/
{
		printf("&&&&&&&& 1. 求利润最大图书 &&&&&&&&\n");
		printf("&&&&&&&& 2. 求利润最小图书 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    /*根据条件查询菜单函数*/
{
		printf("######## 1. 按ISBN查询   ########\n");
		printf("######## 2. 按书名查询   ########\n");
		printf("######## 3. 按作者查询   ########\n");
		printf("######## 3. 按出版社查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage(Book b[],int n)    	     /*该函数完成基本信息管理*/
{  
	int choice,t,find[NUM];
	char judge1='n',judge2='n';
	Book b1;
	do
	{   
		menuBase( );					/*显示对应的二级菜单*/
		printf("choose one operation you want to do:");
		scanf("%d",&choice);	        /*读入选项*/
		switch(choice)
		{
			case 1:	 readBook(&b1,1);   /*读入一条待插入的图书信息*/
				n=insertBook(b,n,b1);   /*调用函数插入图书信息*/
				break;
			case 2:  printf("Input the number deleted\n");
				scanf("%s",b1.ISBN);    	/*读入一个待删除图书的ISBN*/
				n=deleteBook(b,n,b1);   	/*调用函数删除指定ISBN的图书记录*/
				break;
			case 3:  do
				{
					printf("Input the ISBN you want search: \n");
					scanf("%s",b1.ISBN);    /*读入一个待查找图书的ISBN*/
					t=searchBook(b,n,b1,1,find) ; /*调用函数查找指定ISBN的图书记录*/
					if (t)                  /*如果该ISBN的记录存在*/
					{
						printf("change this information? (y/n)");
						scanf("%c",&judge2);
						if (judge2 == 'y')   /*判断是否修改该条信息*/
						{
							readBook(&b1,1); /*读入一条完整的图书记录信息*/
							b[find[0]]=b1;   /*将刚读入的记录赋值给需要修改的数组记录*/
						}
					}					 
					else                     /*如果ISBN的记录不存在*/
					{
						printf("this book is not in.\ninput again? (y/n)  "); /*输出提示信息*/
						scanf("%c",&judge1);
					}
				} while (judge1 == 'y');
				break;
			case 0: 
                break;
		    }
    } while (choice);
	return n;                               /*返回当前操作结束后的实际记录条数*/
}

void saleManage(Book b[],int n)				/*该函数完成图书销量管理功能*/
{  
	int choice;
	do
	{
		menuSale( );                       	/*显示对应的二级菜单*/
		printf("choose one operation you want to do:");
		scanf("%d",&choice);                /*读入二级选项*/
		switch(choice)
		{
			case 1: calcuTotal(b,n);        /*求所有图书的销量*/
                printBook(b, n);
				break;
			case 2: sortBook(b,n,5);        /*根据图书销量排序*/
                printBook(b, n);
				break;
			case 0: 
				break;
		}
	}while(choice);
}

void profitManage(Book b[],int n)       /*该函数完成利润统计功能*/
{
    int choice;
    char judge='n';                     /*定义judge默认为‘n’(no)*/
    menuProfit( );                      /*显示对应的二级菜单*/
    calcuProfit(b,n);					/*调用函数求各图书利润*/
    sortBook(b, n, 3);
    printBook(b,n);
    printf("Do you need to reverse the form? (y\n)\n");
    scanf("%c",&judge);
    if (judge == 'y')
    {
        reverse(b,n);
        printBook(b,n);
    }
    printf("choose one operation you want to do:\n");
    scanf("%d",&choice);
}

void searchManage(Book b[],int n)            /*该函数完成根据条件查询功能*/
{
    Book b1;
	int i,choice,findnum,f[NUM];
	do
	{
		menuSearch( );                       /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:   printf("Input a book\'s ISBN will be searched:\n");
			    scanf("%s",b->ISBN);         /*输入待查图书的ISBN*/
				break;
			case 2:   printf("Input a book\'s name will be searched:\n");
				 scanf("%s",b->name);	     /*输入待查图书书名*/
				 break;   
			case 3:   printf("Input an author  will be searched:\n");
				 scanf("%s",b->author);      /*输入待查图书的作者*/
				 break;
			case 4:   printf("Input a press  will be searched:\n");
				  scanf("%s",b->press);      /*输入待查图书的出版社*/
				  break;
				case 0:   
				  break;
		}
		if (choice>=1 && choice<=4)
		{ 
			findnum=searchBook(b,n,b1,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
			if (findnum)                            /*如果查找成功*/
			{
				printHead( );                 /*打印表头*/
				for (i=0;i<findnum;i++)       /*循环控制f数组的下标*/
	      		printBook(&b[f[i]],1);        /*每次输出一条记录*/
			}
		    else
			    printf("this record does not exist!\n\n"); /*如果查找不到元素，则输出提示信息*/
		 }
	}while (choice);
}

int runMain(Book b[],int n,int choice)        /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead();              /* 1. 显示基本信息*/
				 sortBook(b,n,1);             /*按ISBN由小到大的顺序排序记录*/
				 printBook(b,n);              /*按ISBN由小到大的顺序输出所有记录*/
				 break;
			case 2: n=baseManage(b,n);        /* 2. 基本信息管理*/
			   	     break;
			case 3: saleManage(b,n);          /* 3. 图书销量管理*/
				break;
			case 4: profitManage(b,n);        /* 4. 图书利润统计*/
				break;
			case 5: searchManage(b,n);        /* 5. 根据条件查询*/
				break;
			case 0: 
				break;
		}
		return n;
}

int main( )
{
	 Book b[NUM];                 /*定义实参一维数组存储图书记录*/
     int choice,n=0;              /*n赋值0*/
	 printf("Input information from a file or keyboard? [1(file)/2(keyboard)]\n"); /*询问信息输入方式*/
	 scanf("%d",&choice);         /*读入选择*/
	 if (choice == 1)
		n=readFile(b);            /*读取文件，记录条数返回赋值给n*/
	 else if (choice == 2)
	 {
		 printf("\nInput an integer to indicate how many pieces of information to be input: \n");
		 scanf("%d",&n);
		 n=readBook(b,n);
	 }
	 else
     {
		 printf("choice error!\n");      /*输入非1、2数字按默认方式执行，从文件读取*/
         printf("Execute by default：\n");
     }
	 if (!n)                     /*如果原来的文件为空*/
	 {
         printf("Target file is empty!\n");
		 n=createFile(b);        /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
	 }	 	 
	 do
	 {
	     menu();                 /*显示菜单*/
	     printf("Please input your choice: ");
	     scanf("%d",&choice);
	     if (choice>=0 && choice<=5)
			n=runMain(b,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	     else 
		    printf("Error input,please input your choice again!\n");
	} while (choice);
	sortBook(b,n,1);                  /*存入文件前按ISBN由小到大排序*/
	saveFile(b,n);                    /*将结果存入文件*/
    return 0;
}
