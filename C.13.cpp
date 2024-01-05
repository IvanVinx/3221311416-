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
	printf("请输入待找零的硬币数量：\n"); 
	scanf("%d",&n);
	c=coin(n,25);
	n-=25*c;
	if(c>0) printf("%d个25分硬币",c);
	if(n>0) printf("和");
	c=coin(n,10);
	n-=10*c;
	if(c>0) printf("%d个10分硬币",c);
	if(n>0) printf("和");
	c=coin(n,5);
	n-=5*c;
	if(c>0) printf("%d个5分硬币",c);
	if(n>0) printf("和");
	if(n>0) printf("%d个1分硬币",n);
	return 0;
}
