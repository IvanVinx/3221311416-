#include <stdio.h>
#define max 100

int length(int *a, int n) {
    if (n<=1) {
        return n;
    }
    int pre=a[1]-a[0];
    int c,i,diff;
    if(pre!=0) c=2;
    else c=1;
    for (i = 2; i < n; i++) {
        diff = a[i] - a[i - 1];
        if ((diff > 0 && pre <= 0) || (diff < 0 && pre >= 0)) {
            c++;
            pre = diff;
        }
    }
    return c;
}

int main() {
    int n,i;
    printf("����������Ԫ�ظ�����\n");
    scanf("%d",&n);
	int a[n];
	printf("���������У�\n");
	for(i=0;i<n;i++)
    	scanf("%d",&a[i]);
    n=sizeof(a) / sizeof(a[0]);
    int l=length(a, n);
    if (l==n) {
		printf("�ǰڶ����С�\n");
    } else {
        printf("�ǰڶ����У���Ҫɾ�� %d ��Ԫ�ء�\n", n-l);
    }
    
    return 0;
}
