#include <iostream>
#include "math.h"
#include "string.h"
#include "stdio.h"

# define PI 3.1415926  //无参宏 
# define S(a) (PI*(a)*(a))  //有参宏 参数通常用括号括起来,以避免出错 
// 声明函数 
//************************************************** 
//	测试基本类型的长度和最大值最小值 
void counter_size();
//  测试getchar() 和 putchar()
void getCharTest();
// 测试scanf() 和 print() 格式化输入输出  
void scanAndPrintTest();
//	测试自动类型转换  
void transTest();
// 测试逻辑运算符的短路情况
void shortTest(); 
// 测试字符数组是否一定有'\0' 
void stringTest();
// 测试指针的应用 
void pointerTest();
// 测试指针和数组
void pointerAndArrayTest();
// 测试指针和二维数组 (指针指向二维数组） 
void pointerAndTwoArrayTest2();
// 测试指针和二维数组 (指针指向一维数组） 
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
	测试指针和二维数组 (指针指向二维数组） 
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
	测试指针和二维数组 (指针指向一维数组） 
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
	测试指针和数组 
*/
void pointerAndArrayTest(){
	int *p;
	int a[] = {1,2,3,4,5,6};
	p = a;
	for(int i = 0; i < 6; i ++){
		printf("a[%d] = %d\n",i,*(p++));  //也可以写成(p+i); 
	} 
}

/* 
	测试指针的应用 
*/
void pointerTest(){
	int *p;
	int a = 10;
	p = &a;
	printf("*p = %d, a = %d",*p,*&a); 
}

/* 
	测试字符数组是否一定有'\0'
*/
void stringTest(){
	char c[10];
	char s[] = "hello";
	c[0] = '3';
	printf("%c",c[0]);
	printf("%s",s);
	
	
} 

/* 
	测试逻辑运算符的短路情况 
*/
void shortTest(){
	int i = 1, j = 2, k = 3;
	if(i && j++ || k++){
		//输出的结果为 k = 3 所以存在逻辑短路的情况 
		printf("i = %d, j = %d, k = %d",i,j,k);  
	} 
} 

/*
	测试自动类型转换 
*/
void transTest(){
	int a = 13 * 11.2;
	printf("%d",a);
}

/*
	测试getchar() 和 putchar()  
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
	测试scanf() 和 print() 格式化输入输出 
*/ 
void scanAndPrintTest(){ 
	int a,b;
	float c = 23.346;
	double d = 12.45644731693446;
	scanf("%d,%d",&a,&b); 
	printf("a=%2d,\n%d\n",a,b);
	printf("b=%5.2f\n",c);
	printf("%5.2f\n",d); //%lf用法等价于%f 
}

/*
	测试基本类型的长度和最大值最小值 
*/
void counter_size(){
	printf("char的长度为：%d\n",sizeof(char));
	printf("int的长度为：%d\n",sizeof(int));
	printf("long的长度为：%d\n",sizeof(long));
	printf("int的最大值为：%d\n",INT_MAX);
	printf("int的最小值为：%d\n",INT_MIN);
	
}
