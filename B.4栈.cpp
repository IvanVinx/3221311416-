#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//�������״̬����
#define OK 1
#define ERROR 0
#define OVERFLOW -1

#define N 8
int num;
typedef int Status;
typedef int ElemType;
//ջ��˳��洢��ʾ
#define max 10
#define STACKINCREMENT 5
typedef struct{
	ElemType *base;//��ַ����ջ����֮ǰ������֮��base��ֵΪNULL 
	ElemType *top;//ջ��ָ�� 
	int stacksize;//��ǰ�ѷ���Ĵ洢�ռ� 
}SqStack; 
//����һ����ջS
Status InitStack(SqStack *S)
{
	(*S).base=(ElemType *)malloc(max*sizeof(ElemType));
	if(!(*S).base) exit(OVERFLOW);
	(*S).top=(*S).base;
	(*S).stacksize=max;
	return OK;
} 
//��ջ������Ԫ��eΪ�µ�ջ��Ԫ�أ���ǰ��S����
Status Push(SqStack *S,ElemType e)
{
	if((*S).top-(*S).base>=(*S).stacksize)
	{
		(*S).base=(ElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!(*S).base) exit(OVERFLOW);
		(*S).top=(*S).base+(*S).stacksize;
		(*S).stacksize+=STACKINCREMENT;
	}
	*((*S).top++)=e;
	return OK;
}
//��ջ����ջ���գ�ɾ��ջ��Ԫ�أ�����e������ֵ����ǰ��S����
Status Pop(SqStack *S,ElemType *e)
{
	if((*S).top==(*S).base) return ERROR;
	*e=*(--(*S).top);
	return OK;
}
//˳��ջ�ı�����ջ��ÿ������Ԫ�ش洢���ǻʺ��λ����Ϣ���ö�ά������� 
Status StackTraverse(SqStack S)
{
    int array[N][N];
	int j,k;
	for(j=0;j<N;j++)
	{
	    for(k=0;k<N;k++)
	    	array[j][k]=0;
	}
	int row=0,col;
	while(row<S.top-S.base)
	{
		col=*(S.base+row);
		array[row][col]=1;
		row++;
	}
	for(j=0;j<N;j++)
	{
		for(k=0;k<N;k++){
			if(array[j][k]==1){
				printf("(%d,%d)",j,k);
			} 
		}
	}printf("\n");
	return OK;
}
int Judge(SqStack S,int row,int col)
{
	int row2=0;
	int col2;
	while(row2<S.top-S.base)
	{
		col2=*(S.base+row2);
		if(col2==col||(row-row2)==(col2-col)||(row-row2)==(col-col2))
			return 0;
		row2++;
	}
	return 1;
}
void Queen(SqStack *S,int row)
{
	int col;
	int e;
	for(col=0;col<N;col++)
	{
		if(Judge(*S,row,col))
		{
			Push(&(*S),col);
			row++;
		}
		else{
			continue;
		}
		if(row==N)
		{
			num++;
			printf("%d��",num);
	        StackTraverse(*S);
	        Pop(&(*S),&e);
		    row--;
	    }
	    else
	    {
		    Queen(&(*S),row);
		    Pop(&(*S),&e);
		    row--;
		}
	}	
}
int main()
{
	SqStack S;
	InitStack(&S);
	num=0;
	Queen(&S,0);
	return 0;
}

