#include<stdio.h>
void erba(int n,int c){
	if(n<c) printf("%d",n);
	else{
		int a=n%c;
		n/=c;
		erba(n,c);
		printf("%d",a);
	}	
}


void shiliu(int n) {
	if (n == 0)
	return;
	shiliu(n/16);
	if (n % 16 > 9)
	printf ("%c",(n % 16) - 10 + 'A');
	else 
	printf ("%d",n % 16);
}

int main(){
	int n;
	printf("������һ��ʮ��������\n");
	scanf("%d",&n);
	printf("�����ơ�");
	erba(n,2);
	printf("����");
	printf("�˽��ơ�");
	erba(n,8);
	printf("����");
	printf("ʮ�����ơ�");
	shiliu(n);
	printf("����");
	return 0;
}
