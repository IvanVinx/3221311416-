#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[1000],b[1000],c[1000];
 
//�������߽ϴ�ֵ 
int max(int a,int b){
	if(a>b)return a;
	else return b;
}

//����������Ϊ0 
int setZero(int*num,int len){
	for(int i=0;i<len;i++)
		num[i]=0;
}

//�Ƚ�����������ʽ���ִ�С 
int compare(int*num1,int*num2){
	int i,j;
	for(i=999;num1[i]==0;i--);
	for(j=999;num2[j]==0;j--);
	if(i<j)return -1;
	else if(i>j)return 1;
	else{
		for(;i>=0;i--){
			if(num1[i]>num2[i])
				return 1;
			else if(num1[i]<num2[i])
				return -1;
		}
		return 0;
	}
}

//��һ�����鸳����һ������ 
int copy(int*num1,int*num2){
	int i,j;
	for(i=0;i<1000;i++)
		num1[i]=0;
	for(i=999;num2[i]==0;i--);
	for(j=0;j<=i;j++)
		num1[j]=num2[j];
	return i+1;
}

//�����ӷ� 
void add(char*str1,char*str2){
	setZero(a,1000);
	setZero(b,1000);
	setZero(c,1000);
	printf("�ӷ���"); 
	printf("%s + %s = ",str1,str2);
		
	int i,carry=0;
	int len1=strlen(str1),len2=strlen(str2),len=max(len1,len2);
	for(i=0;i<len1;i++)
		a[i]=str1[len1-1-i]-'0';
	for(i=0;i<len2;i++)
		b[i]=str2[len2-1-i]-'0';
	for(i=0;i<len;i++){
		c[i]=(a[i]+b[i]+carry)%10;
		carry=(a[i]+b[i]+carry)/10;
	}
	

	if(carry!=0)
		c[len++]=1;
	for(i=len-1;i>=0;i--)
		printf("%d",c[i]);
	printf("\n");
}

//�������� 
void sub(char*str1,char*str2){
	setZero(a,1000);
	setZero(b,1000);
	setZero(c,1000);
	printf("������"); 
	printf("%s - %s = ",str1,str2);
	
	int i,borrow=0;
	int len1=strlen(str1),len2=strlen(str2),len=max(len1,len2);
	for(i=0;i<len1;i++)
		a[i]=str1[len1-1-i]-'0';
	for(i=0;i<len2;i++)
		b[i]=str2[len2-1-i]-'0';	
	
	//��������λ���ж�������С	
	if(len2>len1){ 
		printf("-");
		for(i=0;i<len;i++){
			c[i]=b[i]-a[i]-borrow;
			if(c[i]<0){
				borrow=1;
				c[i]+=10;
			}
			else
				borrow=0;
		}
	}
	else{
		for(i=0;i<len;i++){
			c[i]=a[i]-b[i]-borrow;
			if(c[i]<0&&i+1<len){
				borrow=1;
				c[i]+=10;
			}
			else
				borrow=0;
		}
	}
	//������ֱ�����С�ڼ����������¼��㣬�ü�����ȥ��������������� 
	if(c[len-1]<0){
		printf("-");
		for(i=0;i<len;i++){
			c[i]=b[i]-a[i]-borrow;
			if(c[i]<0&&i+1<len){
				borrow=1;
				c[i]+=10;
			}
			else
				borrow=0;
		}
	}
	
	
	while(c[len-1]==0&&len>1)
		len--;
	for(i=len-1;i>=0;i--)
		printf("%d",c[i]);
	printf("\n");
}

//�����˷� 
void mul(char*str1,char*str2) {
	setZero(a,1000);
	setZero(b,1000);
	setZero(c,1000);
	printf("�˷���"); 
	printf("%s * %s = ",str1,str2);
	
	int i,j,k,carry=0,tmp; 
	int len1=strlen(str1),len2=strlen(str2);
	for(i=0;i<len1;i++)
		a[i]=str1[len1-1-i]-'0';
	for(i=0;i<len2;i++)
		b[i]=str2[len2-1-i]-'0';
	
	for(i=0;i<len1;i++){
		for(k=i,j=0;j<len2;j++,k++){
			c[k]+=a[i]*b[j];
		}
	}
	for(i=0;i<=k;i++) {
		c[i]+=carry;
		tmp=c[i];
		c[i]=tmp%10;
		carry=tmp/10;
	}
	
	for(i=k;c[i]==0;i--);
	for(;i>=0;i--)
		printf("%d",c[i]);
	printf("\n");
}

int main() {
	printf("��������12345678901234567890��98765432109876543210\n"); 
	add("12345678901234567890","98765432109876543210");
	sub("12345678901234567890","98765432109876543210");
	mul("12345678901234567890","98765432109876543210");
	printf("��������11223344556677889900��99887766554433221100\n"); 
	add("11223344556677889900","99887766554433221100");
	sub("11223344556677889900","99887766554433221100");
	mul("11223344556677889900","99887766554433221100");
}

