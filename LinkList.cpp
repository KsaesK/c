#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
// **************************************
/* 
	创建节点结构体 
*/ 
typedef struct Node{
	int date;
	struct Node *next;
}Node;
// 用Node代替 *LinkList 简化结点的声明 
typedef struct Node *LinkList;
// 用 Status 代替int 
typedef int Status;
//  单链表的插入 
Status ListInsert(LinkList L, int i, int e); 
// 单链表的删除 
Status ListDelete(LinkList L, int i, int *e);
/*	单链表的查找 */
Status ListFind(LinkList L,int i, int *e);
/*	单链表的随机创建(头插法）  */
Status ListInitBefore(LinkList L,int i);
/*	单链表的随机创建(尾插法）  */
Status ListInitAfter(LinkList L,int i);
//	单链表的初始化
LinkList ListInit();
//  单链表删除整表 
Status ListDelAll(LinkList L);
// **************************************

int main(){
	LinkList l0,l1,l2,l3,l4;
	l0 = (LinkList)malloc(sizeof(Node));
	l1 = (LinkList)malloc(sizeof(Node));
	l2 = (LinkList)malloc(sizeof(Node));
	l3 = (LinkList)malloc(sizeof(Node));
	l4 = (LinkList)malloc(sizeof(Node));
	l0->next = l1;
	l1->date = 1;
	l1->next = l2;
	l2->date = 2;
	l2->next = l3;
	l3->date = 3;
	l3->next = l4;
	l4->date = 4;
	l4->next = NULL;
	int result = 10; 

//  单链表的插入	
//	result = ListInsert(l0,5,3);

//  单链表的删除 
//	int t = 50;
//	result = ListDelete(l0,2,&t);
//	printf("t = %d\n",t);	

//  单链表的查找 
//	int t = 50;
//	result = ListFind(l0,5,&t);
	
//  单链表的随机创建(头插法） 
//	result = ListInitBefore(l0,10);	
//	for(int i = 0; i < 10; i++){
//		l0 = l0->next;
//		printf("L表中的第%d个元素 = %d\n",i,l0->date);
//	}

//  单链表的随机创建(尾插法） 	
//	result = ListInitAfter(l0,10);
//	for(int i = 0; i < 10; i++){
//		l0 = l0->next;
//		printf("L表中的第%d个元素 = %d\n",i,l0->date);
//	}
	
//	单链表的初始化
//	LinkList L = ListInit(); 
//	printf("%d",L->date);

// 单链表删除整表 
//	result = ListDelAll(l0);
//	printf("%d",l0->next->date);
//	printf("%d",result);
	return 1;
}

/*
	单链表删除整表 
*/
Status ListDelAll(LinkList L){
	if(!L || !(L->next)){
		return 0;
	}
	LinkList p,l;
	l = L -> next;
	while(l){
		p = l -> next;
		free(l);
		l = p;
	}
	L -> next = NULL;
	return 1;
} 

/* 
	单链表的初始化 
*/ 
LinkList ListInit(){
	LinkList l0;
	l0 = (LinkList)malloc(sizeof(Node));
	l0 -> next = NULL;
	l0 -> date = 111111;
	return l0; 
} 

/*
	单链表的随机创建(头插法） 
*/
Status ListInitAfter(LinkList L,int length){
	if(length < 0){
		return 0;
	}
	LinkList p,l;
	l = L;
	srand(time(0));
	for(int i = 0; i < length; i++){
		p = (LinkList)malloc(sizeof(Node));
		l -> next = p;
		p->date = rand()%100+1;
		l = l->next;
	}
	return 1;
} 

/*
	单链表的随机创建(头插法） 
*/
Status ListInitBefore(LinkList L,int length){
	if(length < 0){
		return 0;
	}
	LinkList p,q,l;
	l = L;
	q = (LinkList)malloc(sizeof(Node));
	q->date = rand()%100+1;
	l -> next = q;
	srand(time(0));
	for(int i = 0; i < length-1; i++){
		p = (LinkList)malloc(sizeof(Node));
		p -> next = l -> next;
		p->date = rand()%100+1;
		l->next = p;
	}
	return 1;
} 

/*
	单链表的查找 
*/
Status ListFind(LinkList L,int i, int *e){
	int j = 1;
	LinkList p;
	p = L;
	while(p && j < i){
		p = p->next;
		j++;
	}
	if(!(p->next) || j > i)
		return 0;
	*e = p->next->date;
	return 1;
} 

/* 
	测试单链表的插入 
*/

Status ListInsert(LinkList L, int i, int e){
	int j;
	LinkList p,s;
	p = L;
	j = 1;
	while(p && j < i){
		p = p -> next;
		++j;
	}
	if(!(p -> next) || j > i){
		return 0;
	}
	s = (LinkList)malloc(sizeof(Node));
	s -> date = e;
	s -> next = p -> next;
	p -> next = s;
	return 1;
}

/* 
	单链表的删除 
*/
 
Status ListDelete(LinkList L, int i, int *e){
	int j;
	LinkList p, q;
	p = L;
	j= 1;
	while(p -> next && j < i){
		p = p -> next;
		++j;
	}
	if(!(p -> next) || j > i)
		return 0;
	q = p -> next;
	p -> next = q -> next;
	*e = q -> date; 
	free(q);
	return 1;
}

