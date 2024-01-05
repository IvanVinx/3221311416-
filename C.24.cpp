#include<stdio.h>
#include<string.h>
#define max 100

void Next(char T[],int next[])
{
	int j=0,k=-1;
	next[j]=k;
	while(T[j]!='\0')
	{
		if(k==-1||T[j]==T[k])
		{
			j++;
			k++;
			next[j]=k;
		}
		else k=next[k];
	}
}


int kmp(char s[],char t[]){
	int i=0,j=0,ls,lt;
	ls=strlen(s);
	lt=strlen(t);
	int next[max];
	Next(t,next);
	while(i<ls&&j<lt){
		if(j==-1||s[i]==t[j]){
			i++;j++;
		}else{
			j=next[j];
		}
	}
	if(j==lt){
		printf("ƥ��ɹ�\n");
		return i-j;
	}else{
		printf("ƥ��ʧ��\n");
		return -1;
	}
}

int main(){
	char s[max],t[max];
	int pos;
	printf("������Ŀ�괮��\n");
	gets(s);
	printf("�������Ӵ���\n");
	gets(t);
	pos=kmp(s,t);
	printf("λ����%d\n",pos);
	return 0;
}
