#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void shell(int a[],int n){
	int i,j,d,t;
	for(d=n/2;d>0;d/=2){
		for(i=d;i<n;i++){
			t=a[i];
			for(j=i;j>=d&&a[j-d]>t;j-=d){
				a[j]=a[j-d];
			}
			a[j]=t;
		}
	}
}//

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int a[],int start,int end) {
    // ѡ���һ��λ�õ�Ԫ����Ϊ��׼Ԫ��
    int pivot = a[start];
    int left = start;
    int right = end;
    int index = start;

    // ��ѭ��������ָ���غϻ��߽����ʱ�����
    while (right > left) {
        // rightָ�����������бȽ�
        while (right > left) {
            if (a[right] < pivot) {
                a[left] = a[right];
                index = right;
                left++;
                break;
            }
            right--;
        }
        // leftָ��������ҽ��бȽ�
        while (right > left) {
            if (a[left] > pivot) {
                a[right] = a[left];
                index = left;
                right--;
                break;
            }
            left++;
        }
    }
    a[index] = pivot;
    return index;
}
void sort(int a[], int start,int end) {
    // �ݹ����������start���ڵ���end��ʱ��
    if (start >= end) {
        return;
    }
    // �õ���׼Ԫ�ص�λ��
    int pivotIndex = partition(a, start, end);
    sort(a, start, pivotIndex - 1);
    sort(a, pivotIndex + 1, end);
}//

//��ȫ������ÿ��Ľڵ�������ϲ������
void heapify(int a[],int n,int i){
	int large=i;
	int b=2*i+1;
	int c=2*i+2;
	if(b<n&&a[b]>a[large])
		large=b;
	if(c<n&&a[c]>a[large])
		large=c;
	if(large!=i){
		swap(&a[i],&a[large]);
		heapify(a,n,large);
	}
}

void heap(int a[],int n){
	for(int i=n/2-1;i>=0;i--)
		heapify(a,n,i);
	for(int i=n-1;i>=0;i--){
		swap(&a[0],&a[i]);
		heapify(a,i,0);
	}
}//

void heapify1(int a[],int n,int i){
	int small=i;
	int b=2*i+1;
	int c=2*i+2;
	if(b<n&&a[b]<a[small])
		small=b;
	if(c<n&&a[c]<a[small])
		small=c;
	if(small!=i){
		swap(&a[i],&a[small]);
		heapify(a,n,small);
	}
}

void heap1(int a[],int n){
	for(int i=n/2-1;i>=0;i--)
		heapify1(a,n,i);
	for(int i=n-1;i>=0;i--){
		swap(&a[0],&a[i]);
		heapify1(a,i,0);
	}
}//

void mer(int a[],int l,int m,int h){
	int i,j,k;
	int n1=m-l+1;
	int n2=h-m;
	int b[n1],c[n2];
	for(i=0;i<n1;i++)
		b[i]=a[l+i];
	for(j=0;j<n2;j++)
		c[j]=a[m+1+j];
	i=j=0;
	k=l;
	while(i<n1&&j<n2){
		if(b[i]<=c[j]){
			a[k]=b[i];i++;
		}else{
			a[k]=c[j];j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=b[i];i++;k++;
	}
	while(j<n2){
		a[k]=c[j];j++;k++;
	}
}

void merge(int a[],int l,int h){
	if(l<h){
		int m=l+(h-l)/2;
		merge(a,l,m);
		merge(a,m+1,h);
		mer(a,l,m,h);
	}
}//

void counting(int a[],int n){
	int out[n+1];
	int max=a[0];
	int i;
	for(i=1;i<n;i++)
		if(a[i]>max) max=a[i];
	int count[max+1];
	for(i=0;i<=max;i++)
		count[i]=0;
	for(i=0;i<n;i++)
		count[a[i]]++;
	for(i=1;i<=max;i++)
		count[i]+=count[i-1];
	for(i=0;i<n;i++){
		out[count[a[i]]-1]=a[i];
		count[a[i]]--;
	}
	for(i=0;i<n;i++)
		a[i]=out[i];
}

void printaay(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
}//

int main(){
	int a[]={6,12,458,5,4,28,19,1230,9,47};
	int n=10;
	printf("ϣ������\n");
	shell(a,n);
	printaay(a,n);
	printf("��������\n");
	sort(a,0,n-1);
	printaay(a,n);
	printf("���������\n");
	heap(a,n);
	printaay(a,n);
	printf("С��������\n");
	heap1(a,n);
	printaay(a,n);
	printf("�鲢����\n");
	merge(a,0,n-1);
	printaay(a,n);
	printf("��������\n");
	counting(a,n);
	printaay(a,n);
	return 0;
}
