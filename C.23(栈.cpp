#include <stdio.h>   
#include <malloc.h>  
	  
#define MaxSize 100  
	  
typedef int ElemType;  
typedef struct  
{  
	ElemType data[MaxSize];		//存放栈中的数据元素
	int top;					//栈顶指针，即存放栈顶元素在data数组中的下标
}SqStack;  
//初始化栈
void InitStack(SqStack *&s)
{  
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
//判断栈是否为空
bool StackEmpty(SqStack *s)
{
	return (s->top==-1);
}
//进栈
bool Push(SqStack *&s,ElemType &e) 
{  
	if(s->top==MaxSize-1)   
	    return false;    
	else  
	{  
	    s->top++;
		s->data[s->top]=e;
	    return true;  
	}  
}
//出栈
bool Pop(SqStack *&s,ElemType &e)  
{  
	if(s->top == -1)  
		return false;
	else  
	{  
		e=s->data[s->top];
		s->top--;
	    return true;  
	}  
}
//销毁栈
void DestotyStack(SqStack *&s) 
{  
	free(s); 
}
//数值转换 
void Conversion(int a,int b)  
{  
	SqStack *s;  
	int x;
	InitStack(s);  
	while(a > 0)  
	{  
	    x = a%b;  
	    Push(s,x);  
	    a /= b;   
	}
	printf("转换成%d进制为：",b);
	while(!StackEmpty(s))  
	{
		Pop(s,x);
		switch(x)
		{
			case 10:case 11:case 12:case 13:case 14:case 15: x+=87;break;
			default :x+=48;
		}
		printf("%c",x);  
	}
	DestotyStack(s);
	printf("\n");  
}
int main(void)  
{
	 int a,b;  
	 printf("请输入需要数制转换的十进制数：");  
	 scanf("%d",&a);  
	 Conversion(a,2);
	 Conversion(a,8);
	 Conversion(a,16);
	 return 0;  
}

