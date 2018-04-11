#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
// **************************************
/* 
	�����ڵ�ṹ�� 
*/ 
typedef struct Node{
	int date;
	struct Node *next;
}Node;
// ��Node���� *LinkList �򻯽������� 
typedef struct Node *LinkList;
// �� Status ����int 
typedef int Status;
//  ������Ĳ��� 
Status ListInsert(LinkList L, int i, int e); 
// �������ɾ�� 
Status ListDelete(LinkList L, int i, int *e);
/*	������Ĳ��� */
Status ListFind(LinkList L,int i, int *e);
/*	��������������(ͷ�巨��  */
Status ListInitBefore(LinkList L,int i);
/*	��������������(β�巨��  */
Status ListInitAfter(LinkList L,int i);
//	������ĳ�ʼ��
LinkList ListInit();
//  ������ɾ������ 
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

//  ������Ĳ���	
//	result = ListInsert(l0,5,3);

//  �������ɾ�� 
//	int t = 50;
//	result = ListDelete(l0,2,&t);
//	printf("t = %d\n",t);	

//  ������Ĳ��� 
//	int t = 50;
//	result = ListFind(l0,5,&t);
	
//  ��������������(ͷ�巨�� 
//	result = ListInitBefore(l0,10);	
//	for(int i = 0; i < 10; i++){
//		l0 = l0->next;
//		printf("L���еĵ�%d��Ԫ�� = %d\n",i,l0->date);
//	}

//  ��������������(β�巨�� 	
//	result = ListInitAfter(l0,10);
//	for(int i = 0; i < 10; i++){
//		l0 = l0->next;
//		printf("L���еĵ�%d��Ԫ�� = %d\n",i,l0->date);
//	}
	
//	������ĳ�ʼ��
//	LinkList L = ListInit(); 
//	printf("%d",L->date);

// ������ɾ������ 
//	result = ListDelAll(l0);
//	printf("%d",l0->next->date);
//	printf("%d",result);
	return 1;
}

/*
	������ɾ������ 
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
	������ĳ�ʼ�� 
*/ 
LinkList ListInit(){
	LinkList l0;
	l0 = (LinkList)malloc(sizeof(Node));
	l0 -> next = NULL;
	l0 -> date = 111111;
	return l0; 
} 

/*
	��������������(ͷ�巨�� 
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
	��������������(ͷ�巨�� 
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
	������Ĳ��� 
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
	���Ե�����Ĳ��� 
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
	�������ɾ�� 
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

