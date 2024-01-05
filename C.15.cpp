#include<stdio.h>
#include<stdlib.h>
typedef struct a{
	int d;
	struct a *next;
	struct a *front;
}ss;

ss *create(int arr[],int size){
	ss *h=NULL,*p=NULL,*q;
	int i;
	for(i=0;i<size;i++){
		q=(ss *)malloc(sizeof(ss));
		q->d=arr[i];
		q->front=p;
		q->next=NULL;
		if(p!=NULL) 
			p->next=q;
		p=q;
		if(h==NULL)
			h=q;
	}
	return h;
}

int panduan(ss *A,ss *B){
	if(A==NULL) return 0;
	if(B==NULL) return 1;
	if(A->d==B->d){
		return panduan(A->next,B->next);
	}else{
		return panduan(A->next,B);
	}
}

int main(){
	ss *h=NULL;
	int m,n,f;
	printf("请输入序列A、B的元素个数\n");
	scanf("%d%d",&n,&m);
	int a[n],b[m],i;
	printf("请输入序列A、B\n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<m;i++) scanf("%d",&b[i]);
	int n1=sizeof(a)/sizeof(a[0]);
	int n2=sizeof(b)/sizeof(b[0]);
	ss *A,*B;
	A=create(a,n1);
	B=create(b,n2);
	f=panduan(A,B);
	if(f==1){
		printf("是子序列\n");
	}else{
		printf("\n不是子序列\n");
	}
	return 0;
}
