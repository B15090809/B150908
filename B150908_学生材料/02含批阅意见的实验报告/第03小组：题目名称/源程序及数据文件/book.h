/* ��book.h�ļ����������� */
#ifndef _BOOK			/*�������룬��ֹ�ظ������Ĵ���*/
#define _BOOK
#include <string.h>
#define NUM 20                /*����ͼ���������������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
typedef struct Book		/*ͼ���¼��������*/
{
	char    ISBN[20];					//ISBN
	char    name[20];					//����
	char    press[10];					//������
	char    author[10];					//����
	float   price_out;					//�ۼ�
	float   price_in;					//����
	int     sale;						//����
	int     number;						//����
	float   profit;						//����
} Book ;

#define sizeBook sizeof(Book)						/*һ��ͼ���¼����Ҫ���ڴ�ռ��С*/

void printHead  ( );
int  readBook   (Book b[],int n);					/*����ͼ���¼ֵ��ISBNΪ0������涨������¼ʱֹͣ*/
void printBook  (Book *b, int n);					/*�������ͼ���¼��ֵ*/
int  equal      (Book b1, Book b2, int condition);			/*����condition�����ж�����Book����������ȷ�*/
int  larger     (Book b1, Book b2, int condition);			/*����condition�Ƚ�Book�������ݴ�С*/
void reverse    (Book b[], int n);					/*ͼ���¼����Ԫ������*/
void calcuProfit(Book b[],int n);					/*�����ͼ������*/
int  calcuTotal (Book b[], int n);					/*���ж���ͼ����Ϣ����������Ϊһ��*/
void sortBook   (Book b[],int n,int condition);		/*ѡ�񷨴�С�������򣬰�condition���涨������*/
int  searchBook (Book b[],int n,Book b1,int condition,int f[]);	/*������������������b1��ȵĸ�Ԫ��*/
     /*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/

void addBook    (Book b[],int pos, int aim);            /*ͬһͼ����Ϣ���*/
int  insertBook  (Book b[],int n,Book b1);				/*�������в���һ��Ԫ�ذ�ISBN����*/
int  deleteBook  (Book b[],int n,Book b1);				/*��������ɾ��һ��ָ��ͼ��Ԫ��*/
#endif
