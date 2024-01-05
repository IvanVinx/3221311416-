#include<stdio.h>
#include<string.h>
int main(){
	int i,j,n1,n2,f=1;
	char s[100],p[100];
	scanf("%s %s",s,p);
	n1=strlen(s);
	n2=strlen(p);
	if(n1>n2){
		printf("false");
	}else{
		for(i=0;i<n1&&f!=0;i++){
			switch(p[i]){
				case '.':{
					f=1;break;
					}
				case '*':{
					if(p[i-1]==s[i]||p[i-1]=='.') f=1;
					else f=0;
					break;
					}
				default :{
					if(s[i]==p[i]) {
						f=1;break;
					}else{
						f=0;break;
					}
			    }
			}	
		}
		if(f==0) printf("false");
		else printf("ture");
	}
	return 0;
}
