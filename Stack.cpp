#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define OK 1
#define FALSE 0
#define MAXSIZE 20
//********************************
// ���巵��ֵ(�������������Ƿ�ɹ�)
typedef int Status;
// ����˳��洢�ṹʵ�ֵ�ջ 
typedef struct Stack{
	int data[MAXSIZE];
	int top;
}Stack,*StackPoint;
/* ��ʼ��ջ */
Status init(Stack *S);
/* ��ջ */
Status push(Stack *S,int e);
/* ��ջ */
Status pop(Stack *S,int *e);
/* ����ջ */
Status destroy(Stack *S);
/* �ж�ջ�Ƿ�Ϊ�� */
int empty(Stack S);
/* ȡջ�� */
Status getTop(Stack S, int *e);
/* ȡջ�ĳ��� */
int length(Stack S); 
/* �������� */
void instruct(); 
/* ���ջ */
Status printStack(Stack S); 
//********************************


int main(){
	instruct();
	printf("���������ѡ��\n"); 
	int choice;
	scanf("%d",&choice);
	StackPoint stack;
	stack = (StackPoint)malloc(sizeof(Stack));
	stack -> top = -1;
	while(choice != 6){
		switch(choice){
			case 1 :{
				int result = init(stack);
				if(result){
					printf("��ʼ���ɹ�\n"); 
				}else{
					printf("��ʼ��ʧ��\n"); 	
				}
				break;
			}
			case 2 :{
				printf("�������ջ������\n"); 
				int e;
				scanf("%d",&e);
				int result = push(stack,e);
				if(result){
					printf("��ջ�ɹ�\n"); 
					printStack(*stack);
				}else{
					printf("��ջʧ��\n"); 	
				}
				break;
			}
			case 3 :{
				int e;
				int result = pop(stack,&e);
				if(result){
					printf("��ջ�ɹ�\n"); 
					printf("��ջ��Ԫ��Ϊ%d\n",e); 
					printStack(*stack);
				}else{
					printf("��ջʧ��\n"); 	
				}
				break;
			}
			case 4 :{
				int e;
				int result = pop(stack,&e);
				if(result){
					printf("ջ��Ԫ��Ϊ%d\n",e); 
				}else{
					printf("��ȡջ��Ԫ��ʧ��\n"); 	
				}
				break;
				break;
			}
			case 5 :{
				int l = length(*stack);
				printf("ջ�ĳ���Ϊ%d\n",l); 
				break;
			}
		}
		printf("���������ѡ��\n"); 
		scanf("%d",&choice);
	} 
	 
}
/*
  �������� 
*/
void instruct()
{
    printf("*****************˳��ջ********************\n");
	printf("\t\t1.��ʼ��ջ\n"); 
	printf("\t\t2.��ջ\n"); 
	printf("\t\t3.��ջ\n"); 
	printf("\t\t4.ȡջ��\n"); 
	printf("\t\t5.ȡջ�ĳ���\n");  
	printf("\t\t6.�˳�\n");
	printf("******************************************\n");
}
Status printStack(Stack S){
	if(!(&S)){
		return FALSE;
	}
	for(int i = 0; i <= S.top; i++){
		printf("%d,",S.data[i]);
	}
	printf("\n����ջ��Ϊ%d,ջ��Ϊ%d\n",S.data[S.top],S.data[0]);
	return OK;
}
/* 
  ��ʼ������ 
*/
Status init(Stack *S){
	if(S){
		free(S);	
	}
	S = (StackPoint)malloc(sizeof(Stack));
	S -> top = -1;
	if(!S)
		return FALSE;
	return OK;	
}
/* 
  ��ջ 
*/
Status push(Stack *S,int e){
	if(!S){
		init(S);
	}
	if(S->top >= MAXSIZE - 1){
		printf("ջ�Ѿ����ˣ������ٷŶ�����\n");
		return FALSE;
	}
	S->top++;
	S->data[S->top] = e;
	return OK;
}
/* 
  ��ջ 
*/
Status pop(Stack *S,int *e){
	if(!S){
		init(S);
	}
	if(S -> top == -1){
		printf("ջ�ǿ�ջ��û��ջ��Ŷ\n");	
		return FALSE; 
	} 
	*e = S->data[S->top];
	S->top--;
	return OK;	
}
/* 
  ����ջ 
*/
Status destroy(Stack *S){
	free(S);	
}
/* 
  ���ջ 
*/
Status clear(Stack *S){
	if(S){
		free(S);	
	}
	S = (StackPoint)malloc(sizeof(Stack));
	S -> top = -1;
	return 1;	
}
/*
  �ж�ջ�Ƿ�Ϊ�� 
*/
int empty(Stack S){
	if(!(&S)){
		init(&S);
	}
	if(S.top == -1){
		return 1;	
	}
	return 0;
}
/* 
  ȡջ�� 
*/
Status getTop(Stack S,int *e){
	if(!(&S)){
		init(&S);
	}
	if(S.top == -1){
		printf("ջ�Ѿ����ˣ�����ȡ������\n");	
		return FALSE; 
	} 
	*e = S.data[S.top];
	return OK;
}
/* 
  ȡջ�ĳ��� 
*/
int length(Stack S){
	if(!(&S)){
		init(&S);
	}
	return S.top + 1;	
}
