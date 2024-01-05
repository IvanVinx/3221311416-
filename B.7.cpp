#include<stdio.h>
int c1=0;
int bubble(int a[],int n){
	int i,j,t;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				t=a[i];a[i]=a[j];a[j]=t;c1++;
			}
		}
	}
	return c1;
}

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
int c2=0;
int sort(int a[], int start,int end) {
	c2++;
    // �ݹ����������start���ڵ���end��ʱ��
    if (start <end) {
        // �õ���׼Ԫ�ص�λ��
    int pivotIndex = partition(a, start, end);
    sort(a, start, pivotIndex - 1);
    sort(a, pivotIndex + 1, end);
    }
    return c2;
}
int main(){
	int n,a[100],i,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	c1=bubble(a,n);
	c2=sort(a,0,n-1);
	if(c1<c2)
	printf("ʹ��ð������죺%d",c1);
	else
	printf("ʹ�ÿ�������죺%d",c2);
	return 0;
}
