#include<stdio.h>
#include<stdlib.h>
typedef struct link{
	int d;
	struct link *next;
}ss;

ss *create(ss *L){
	int n;
	ss *p,*q=L;printf("请输入待拆分链表元素,以-1结尾：\n");
	while(1){
		
		scanf("%d",&n);
		if(n==-1) break;
		p=(ss *)malloc(sizeof(ss));
		p->d=n;
		p->next=NULL;
		if(L==NULL){
			L=p;
		}else{
			q->next=p;
		}
		q=p;
		}
	return L;
}

void print(ss *L){
	ss *p=L->next;
	while(p){
		printf("%d",p->d);
		p=p->next;
		if(p!=NULL)
			printf("->");
	}
	printf("\n");
}

ss *chaifen(ss *L){
	ss *L1,*L2;
	L1=(ss *)malloc(sizeof(ss));
	L2=(ss *)malloc(sizeof(ss));
	ss *p=L,*q=L->next,*r1=L1,*r2=L2;
	int c=1;
	while(q){
		if(c%2==1){
			r1->next=p;
			r1=p;
			r1->next=NULL;
		}else{
			r2->next=p;
			r2=p;
			r2->next=NULL;
		}
		p=q;
		q=q->next;
		c++;
	}
	if(c%2==1) r1->next=p;
	else r2->next=p;
	printf("L1:");
	print(L1);
	printf("L2:");
	print(L2);
}

int main(){
	int n;
	ss *p,*L=NULL,*L1=NULL;
	L=create(L);
	chaifen(L);
	
}
