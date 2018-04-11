#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define OK 1
#define FALSE 0
#define MAXSIZE 20
//********************************
// 定义返回值(用于描述操作是否成功)
typedef int Status;
// 定义顺序存储结构实现的栈 
typedef struct Stack{
	int data[MAXSIZE];
	int top;
}Stack,*StackPoint;
/* 初始化栈 */
Status init(Stack *S);
/* 进栈 */
Status push(Stack *S,int e);
/* 出栈 */
Status pop(Stack *S,int *e);
/* 销毁栈 */
Status destroy(Stack *S);
/* 判断栈是否为空 */
int empty(Stack S);
/* 取栈顶 */
Status getTop(Stack S, int *e);
/* 取栈的长度 */
int length(Stack S); 
/* 操作描述 */
void instruct(); 
/* 输出栈 */
Status printStack(Stack S); 
//********************************


int main(){
	instruct();
	printf("请输入你的选择\n"); 
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
					printf("初始化成功\n"); 
				}else{
					printf("初始化失败\n"); 	
				}
				break;
			}
			case 2 :{
				printf("请输入进栈的整数\n"); 
				int e;
				scanf("%d",&e);
				int result = push(stack,e);
				if(result){
					printf("进栈成功\n"); 
					printStack(*stack);
				}else{
					printf("进栈失败\n"); 	
				}
				break;
			}
			case 3 :{
				int e;
				int result = pop(stack,&e);
				if(result){
					printf("出栈成功\n"); 
					printf("出栈的元素为%d\n",e); 
					printStack(*stack);
				}else{
					printf("出栈失败\n"); 	
				}
				break;
			}
			case 4 :{
				int e;
				int result = pop(stack,&e);
				if(result){
					printf("栈顶元素为%d\n",e); 
				}else{
					printf("获取栈顶元素失败\n"); 	
				}
				break;
				break;
			}
			case 5 :{
				int l = length(*stack);
				printf("栈的长度为%d\n",l); 
				break;
			}
		}
		printf("请输入你的选择\n"); 
		scanf("%d",&choice);
	} 
	 
}
/*
  操作描述 
*/
void instruct()
{
    printf("*****************顺序栈********************\n");
	printf("\t\t1.初始化栈\n"); 
	printf("\t\t2.进栈\n"); 
	printf("\t\t3.出栈\n"); 
	printf("\t\t4.取栈顶\n"); 
	printf("\t\t5.取栈的长度\n");  
	printf("\t\t6.退出\n");
	printf("******************************************\n");
}
Status printStack(Stack S){
	if(!(&S)){
		return FALSE;
	}
	for(int i = 0; i <= S.top; i++){
		printf("%d,",S.data[i]);
	}
	printf("\n其中栈顶为%d,栈底为%d\n",S.data[S.top],S.data[0]);
	return OK;
}
/* 
  初始化方法 
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
  进栈 
*/
Status push(Stack *S,int e){
	if(!S){
		init(S);
	}
	if(S->top >= MAXSIZE - 1){
		printf("栈已经满了，不能再放东西了\n");
		return FALSE;
	}
	S->top++;
	S->data[S->top] = e;
	return OK;
}
/* 
  出栈 
*/
Status pop(Stack *S,int *e){
	if(!S){
		init(S);
	}
	if(S -> top == -1){
		printf("栈是空栈，没有栈顶哦\n");	
		return FALSE; 
	} 
	*e = S->data[S->top];
	S->top--;
	return OK;	
}
/* 
  销毁栈 
*/
Status destroy(Stack *S){
	free(S);	
}
/* 
  清空栈 
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
  判断栈是否为空 
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
  取栈顶 
*/
Status getTop(Stack S,int *e){
	if(!(&S)){
		init(&S);
	}
	if(S.top == -1){
		printf("栈已经空了，不能取东西了\n");	
		return FALSE; 
	} 
	*e = S.data[S.top];
	return OK;
}
/* 
  取栈的长度 
*/
int length(Stack S){
	if(!(&S)){
		init(&S);
	}
	return S.top + 1;	
}
