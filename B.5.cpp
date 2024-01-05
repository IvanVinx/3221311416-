#include<stdio.h>
#include<stdlib.h>

typedef struct Tree{
	int data;				
 	struct Tree *lchild;		
 	struct Tree *rchild;		
}Tree;

Tree *create()
{
	int data,temp;
	Tree *T;
	scanf("%d",&data);		
	temp=getchar();			
	if(data == -1){			
		return NULL;
	}else{
		T = (Tree*)malloc(sizeof(Tree));			
		T->data = data;							
		printf("������%d��������: ",data);		
		T->lchild = create();				
		printf("������%d��������: ",data);			
		T->rchild = create();				
		return T;						
	}	
	
}
void xianxu(Tree *T)		
{
	if(T==NULL)	return;			
	printf("%d ",T->data);
	xianxu(T->lchild);		
	xianxu(T->rchild);		
}

void zhongxu(Tree *T)		
{
	if(T==NULL)	 return;					
	zhongxu(T->lchild);		
	printf("%d ",T->data);
	zhongxu(T->rchild);		
	
}

void houxu(Tree *T)		
{
	if(T==NULL)	return;				
	houxu(T->lchild);		
	houxu(T->rchild);		
	printf("%d ",T->data);
}


int main()
{
	Tree *S;
	printf("�������һ���ڵ������:\n");
	S = create();		
	printf("����������: \n");
	xianxu(S);			
	printf("\n����������: \n");
	zhongxu(S);			
	printf("\n����������: \n");
	houxu(S);			
	return 0;	
} 	


