#include <stdio.h>
#include <stdlib.h>
#include "book.h"        
int  createFile(Book b[])                           /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("/Users/apple/Desktop/dat/book.dat", "wb")) == NULL)    /*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf("can not open file !\n");            /*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);                                    /*Ȼ���˳�*/
    }
    printf("Creat a new file.\n");
    printf("Input an integer to indicate how many pieces of information to be input: ");
    scanf("%d",&n);                                 /*����һ��������ʾҪ���������ͼ����Ϣ*/
	printf("\nInput books\' information:\n\n");
	n=readBook(b,n);                                /*����book.h�еĺ���������*/
	fwrite(b,sizeBook,n,fp);                        /*���ղŶ�������м�¼һ����д���ļ�*/
 	fclose(fp);                                     /*�ر��ļ�*/
	return n;
}

int readFile(Book b[])                              /*���ļ��е����ݶ������ڽṹ������b��*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("/Users/apple/Desktop/dat/book.dat", "rb")) == NULL)    /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf("file does not exist,create it first:\n");    /*�����ʧ�������ʾ��Ϣ*/
	    return 0;									/*Ȼ�󷵻�0*/
	}	 
    fread(&b[i],sizeBook,1,fp);                     /*������һ����¼*/
   	while(!feof(fp))								/*�ļ�δ����ʱѭ��*/
	{
		i++;
        fread(&b[i],sizeBook,1,fp);                 /*�ٶ�����һ����¼*/
     }
	fclose(fp);										/*�ر��ļ�*/
	return i;										/*���ؼ�¼����*/
}

void saveFile(Book b[],int n)						/*���ṹ�����������д���ļ�*/
{   			
  	FILE *fp;	
   	if((fp=fopen("/Users/apple/Desktop/dat/book.dat", "wb")) == NULL)	/*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open file !\n");            /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);							     	/*Ȼ���˳�*/
	}
	fwrite(b,sizeBook,n,fp);        
	fclose(fp);										/*�ر��ļ�*/
}
