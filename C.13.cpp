#include<stdio.h>
int coin(int n,int c){
	int a=0;
	while(n>=c){
		n-=c;
		a++;
	}
	return a;
}
int main(){
	int n,c;
	printf("������������Ӳ��������\n"); 
	scanf("%d",&n);
	c=coin(n,25);
	n-=25*c;
	if(c>0) printf("%d��25��Ӳ��",c);
	if(n>0) printf("��");
	c=coin(n,10);
	n-=10*c;
	if(c>0) printf("%d��10��Ӳ��",c);
	if(n>0) printf("��");
	c=coin(n,5);
	n-=5*c;
	if(c>0) printf("%d��5��Ӳ��",c);
	if(n>0) printf("��");
	if(n>0) printf("%d��1��Ӳ��",n);
	return 0;
}
