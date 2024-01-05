#include<stdio.h>
#include<stdlib.h>
typedef struct link{
	int d;
	struct link *next;
}ss;

ss *create(int n){
	ss *h=NULL,*p=NULL,*q=NULL;
	int i;
	for(i=1;i<=n;i++){
		p=(ss *)malloc(sizeof(ss));
		p->d=i;
		if(h==NULL){
			h=p;
		}else{
			q->next=p;
		}
		q=p;	
	}
	q->next=h;	
	return q;
}

void yuesefu(ss *t,int n,int m,int a[]){
	int c=0,s=0,i=0;
	ss *p=t->next,*q=t;
	while(s<n-1){
		c++;
		if(c==m){
			q->next=p->next;
			a[i]=p->d;
			free(p);
			p=q->next;
			c=0;
			s++;
			i++;
		}else{
			q=p;
			p=p->next;
		}
	}
	a[i]=p->d;
	free(p);
}

int main(){
	int m,n,i;
	printf("请输入总人数和报数间隔：\n");
	scanf("%d%d",&n,&m);
	int a[n];
	ss *t=create(n);//尾指针
	yuesefu(t,n,m,a); 
	printf("被淘汰的人顺序：");
	for(i=0;i<n-1;i++){
		printf("%d ",a[i]);
	}
	printf("\n最后剩下的人："); 
	printf("%d",a[n-1]);
	return 0;
}
