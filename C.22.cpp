#include<stdio.h>
#include<string.h>
int main(){
	char s[100],c[100],a[100];
	printf("请输入特定序列：\n");
	gets(s);
	printf("请输入出栈序列：\n");
	gets(c);
	int i=0,j,n=strlen(c),k,l,f=0;
	while(i<n){
		k=0;
		for(j=i+1;j<n;j++){
			if(c[j]<c[i]){
				a[k]=c[j];k++;
			}
		}
		l=0;
		while(l<k){
			if(a[l]<a[l+1])
				f=1;break;
		}
		if(f==1){
			printf("不是合法的出栈序列\n"); break;
		}else{
			i++;
		}
	}
	if(f==0) printf("是合法的出栈序列\n");
	return 0;
}
