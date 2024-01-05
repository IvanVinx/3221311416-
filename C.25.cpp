#include<stdio.h>
#include<string.h>
int main(){
	char c[100];
	gets(c);
	int i=0,j=0,n=strlen(c);
	while(c[i]==' ') 
		i++;
	while(i<n){
		if(c[i]==' '&&c[i+1]==' '){
			while(c[i]==' '){
				i++;
			}
			printf(" ");j++;
		}else{
			printf("%c",c[i]);i++;
		}
	}
	return 0;
}
