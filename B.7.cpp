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
    // 选择第一个位置的元素作为基准元素
    int pivot = a[start];
    int left = start;
    int right = end;
    int index = start;

    // 外循环在左右指针重合或者交错的时候结束
    while (right > left) {
        // right指针从右向左进行比较
        while (right > left) {
            if (a[right] < pivot) {
                a[left] = a[right];
                index = right;
                left++;
                break;
            }
            right--;
        }
        // left指针从左向右进行比较
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
    // 递归结束条件：start大于等于end的时候
    if (start <end) {
        // 得到基准元素的位置
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
	printf("使用冒泡排序快：%d",c1);
	else
	printf("使用快速排序快：%d",c2);
	return 0;
}
