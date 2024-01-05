#include<stdio.h>
#include<stdlib.h>
typedef struct a{
	int d;
	struct a *next;
	struct a *front;
}ss;

int min(int x,int y){
	return x<y?x:y;
}

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

void jiaoji(ss *A,ss *B,int min){
	ss *p=A,*q=B;
	int a[min],i=0;
	while(p){
		q=B;
		while(q){
			if(q->d==p->d){
				a[i]=q->d;
				i++;
				break;
			}
			q=q->next;
		}
		p=p->next;
	}
	if(i!=0){
		printf("\n交集是：\n");
		for(int j=0;j<i;j++) printf("%d ",a[j]);
	}else{
		printf("\n两个序列没有交集\n");
	}
}

void bingji(ss *A,ss *B,int n,int m){
	ss *p=A,*q=B;
	int a[n+m],i=0,j=0,c=0,f;
	while(p&&q){
		f=1;
		if(p->d<q->d){
			for(i=0;i<c;i++){
				if(p->d==a[i]) f=0;
			}
			if(f==1) {
				a[c]=p->d;c++;
			}
			p=p->next;
		}else{
			for(i=0;i<c;i++){
				if(q->d==a[i]) f=0;
			}
			if(f==1) {
				a[c]=q->d;c++;
			}
			q=q->next;
		}
		
	}
	if(p==NULL){
		while(q){
			a[c]=q->d;
			c++;
			q=q->next;
		}
	}else{
		while(p){
			a[c]=p->d;
			c++;
			p=p->next;
		}
	}
	printf("\n并集是：\n");
	for(i=0;i<c;i++)
		printf("%d ",a[i]);
}

int main(){
	ss *h=NULL;
	int m,n,mi;
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
	mi=min(n,m);
	jiaoji(A,B,mi);
	bingji(A,B,n,m);
	return 0;
}
