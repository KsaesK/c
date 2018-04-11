#include <iostream>
#include "math.h"
#include "string.h"
#include "stdio.h"

# define PI 3.1415926  //�޲κ� 
# define S(a) (PI*(a)*(a))  //�вκ� ����ͨ��������������,�Ա������ 
// �������� 
//************************************************** 
//	���Ի������͵ĳ��Ⱥ����ֵ��Сֵ 
void counter_size();
//  ����getchar() �� putchar()
void getCharTest();
// ����scanf() �� print() ��ʽ���������  
void scanAndPrintTest();
//	�����Զ�����ת��  
void transTest();
// �����߼�������Ķ�·���
void shortTest(); 
// �����ַ������Ƿ�һ����'\0' 
void stringTest();
// ����ָ���Ӧ�� 
void pointerTest();
// ����ָ�������
void pointerAndArrayTest();
// ����ָ��Ͷ�ά���� (ָ��ָ���ά���飩 
void pointerAndTwoArrayTest2();
// ����ָ��Ͷ�ά���� (ָ��ָ��һά���飩 
void pointerAndTwoArrayTest();
//************************************************** 

int main(int argc, char** argv) {
//	counter_size(); 
//	getCharTest();
//	scanAndPrintTest();
//	transTest();		
//	shortTest();
//	stringTest();
//	pointerTest();
//	pointerAndArrayTest();
	pointerAndTwoArrayTest();
//	pointerAndTwoArrayTest2();
	return 1;
}

/* 
	����ָ��Ͷ�ά���� (ָ��ָ���ά���飩 
*/
void pointerAndTwoArrayTest2(){
	int *p;
	int a[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};
	p = a[0];
	for(int i = 0; i < 3; i ++){
		for(int j = 0; j < 4; j++){
			printf("a[%d][%d] = %d\t",i,j,*p++);			
		} 
		printf("\n");
	} 
}

/* 
	����ָ��Ͷ�ά���� (ָ��ָ��һά���飩 
*/
void pointerAndTwoArrayTest(){
	int (*p)[4];
	int a[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};
	p = a;
	for(int i = 0; i < 3; i ++){
		for(int j = 0; j < 4; j++){
			printf("a[%d][%d] = %d\t",i,j,*((*p)+j));			
		} 
		printf("\n");
		p++;
	} 
}

/* 
	����ָ������� 
*/
void pointerAndArrayTest(){
	int *p;
	int a[] = {1,2,3,4,5,6};
	p = a;
	for(int i = 0; i < 6; i ++){
		printf("a[%d] = %d\n",i,*(p++));  //Ҳ����д��(p+i); 
	} 
}

/* 
	����ָ���Ӧ�� 
*/
void pointerTest(){
	int *p;
	int a = 10;
	p = &a;
	printf("*p = %d, a = %d",*p,*&a); 
}

/* 
	�����ַ������Ƿ�һ����'\0'
*/
void stringTest(){
	char c[10];
	char s[] = "hello";
	c[0] = '3';
	printf("%c",c[0]);
	printf("%s",s);
	
	
} 

/* 
	�����߼�������Ķ�·��� 
*/
void shortTest(){
	int i = 1, j = 2, k = 3;
	if(i && j++ || k++){
		//����Ľ��Ϊ k = 3 ���Դ����߼���·����� 
		printf("i = %d, j = %d, k = %d",i,j,k);  
	} 
} 

/*
	�����Զ�����ת�� 
*/
void transTest(){
	int a = 13 * 11.2;
	printf("%d",a);
}

/*
	����getchar() �� putchar()  
*/ 
void getCharTest(){
	char c1 = getchar();
	char c2 = getchar();
	char c3 = getchar();
	putchar(c1);
	putchar(c2);
	putchar(c3);
}

/*
	����scanf() �� print() ��ʽ��������� 
*/ 
void scanAndPrintTest(){ 
	int a,b;
	float c = 23.346;
	double d = 12.45644731693446;
	scanf("%d,%d",&a,&b); 
	printf("a=%2d,\n%d\n",a,b);
	printf("b=%5.2f\n",c);
	printf("%5.2f\n",d); //%lf�÷��ȼ���%f 
}

/*
	���Ի������͵ĳ��Ⱥ����ֵ��Сֵ 
*/
void counter_size(){
	printf("char�ĳ���Ϊ��%d\n",sizeof(char));
	printf("int�ĳ���Ϊ��%d\n",sizeof(int));
	printf("long�ĳ���Ϊ��%d\n",sizeof(long));
	printf("int�����ֵΪ��%d\n",INT_MAX);
	printf("int����СֵΪ��%d\n",INT_MIN);
	
}
