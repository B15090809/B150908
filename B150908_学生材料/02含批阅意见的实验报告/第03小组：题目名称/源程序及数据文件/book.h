/* ①book.h文件的完整内容 */
#ifndef _BOOK			/*条件编译，防止重复包含的错误*/
#define _BOOK
#include <string.h>
#define NUM 20                /*定义图书种类数常量，此处可以根据实际需要修改常量值*/
typedef struct Book		/*图书记录的数据域*/
{
	char    ISBN[20];					//ISBN
	char    name[20];					//书名
	char    press[10];					//出版社
	char    author[10];					//作者
	float   price_out;					//售价
	float   price_in;					//进价
	int     sale;						//销量
	int     number;						//余量
	float   profit;						//利润
} Book ;

#define sizeBook sizeof(Book)						/*一个图书记录所需要的内存空间大小*/

void printHead  ( );
int  readBook   (Book b[],int n);					/*读入图书记录值，ISBN为0或读满规定条数记录时停止*/
void printBook  (Book *b, int n);					/*输出所有图书记录的值*/
int  equal      (Book b1, Book b2, int condition);			/*根据condition条件判断两个Book类型数据相等否*/
int  larger     (Book b1, Book b2, int condition);			/*根据condition比较Book类型数据大小*/
void reverse    (Book b[], int n);					/*图书记录数组元素逆置*/
void calcuProfit(Book b[],int n);					/*求出各图书利润*/
int  calcuTotal (Book b[], int n);					/*若有多条图书信息，将其整合为一条*/
void sortBook   (Book b[],int n,int condition);		/*选择法从小到大排序，按condition所规定的条件*/
int  searchBook (Book b[],int n,Book b1,int condition,int f[]);	/*根据条件找数组中与b1相等的各元素*/
     /*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/

void addBook    (Book b[],int pos, int aim);            /*同一图书信息相加*/
int  insertBook  (Book b[],int n,Book b1);				/*向数组中插入一个元素按ISBN有序*/
int  deleteBook  (Book b[],int n,Book b1);				/*从数组中删除一个指定图书元素*/
#endif
