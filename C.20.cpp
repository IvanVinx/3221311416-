#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int i,n,j,k=0;
	double a[100],b[100],c[200];
	printf("��������������Ԫ�ظ�����\n");
	scanf("%d",&n);
	printf("��������A��\n");
	for(i=0;i<n;i++)
		scanf("%lf",&a[i]);
	printf("��������B��\n");
	for(i=0;i<n;i++)
		scanf("%lf",&b[i]);
	i=j=0;
	while(i<n&&j<n){
		if(a[i]>b[j]){
			c[k]=b[j];k++;j++;
		}else{
			c[k]=a[i];k++;i++;
		}
	}
	if(i==n) 
		for(i=j;i<n;i++)
			c[k++]=b[i];
	else
		for(j=i;j<n;j++)
			c[k++]=b[j];
	printf("��λ����%.2f",(c[n-1]+c[n])/2);
	return 0;
}
