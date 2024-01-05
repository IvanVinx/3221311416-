#include<stdio.h>
#include<string.h>
#define max 100
int panduan(char c[],int n1,int n2){
	int i,j;
	for(i=n1,j=n2-1;j>=(n1+n2)/2,i<(n1+n2)/2;i++,j--){
			if(c[i]!=c[j]) return -1;
	}
	return 1;
}
void baoli(char c[],int n){
	int i,j,a,n1,n2,n3=0,k,flag=0;
	char d[max];
	n1=0;
	while(n1<n){
		n2=n;
		while(n2>n1+1){
			a=panduan(c,n1,n2);
			if(a==1) break;
			n2--;
		}
		if(a==1) {
			flag=1;
			if(n2-n1>n3){
				k=0;
				n3=n2-n1;
				for(i=n1;i<n2;i++){
					d[k++]=c[i];
				}
			}
		}
		n1++;
	}
	if(flag==1) {
		printf("最长回文子序列：");
		for(i=0;i<k;i++) printf("%c",d[i]);
	}else{
		printf("未找到最长回文序列");
	}
}

int main(){
	char c[max];
	scanf("%s",c);
	int n;
	n=strlen(c);
	//printf("%d",n);
	baoli(c,n);
	return 0;
}
