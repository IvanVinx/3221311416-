#include <stdio.h>
#include <stdbool.h>
#define max 100

int graph[max][max];
bool visited[max];
int stack[max];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

bool empty() {
    return top == -1;
}

void DFS(int v, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(i, n);
        }
    }
}

bool isStronglyConnected(int n) {
    for (int i = 0; i < n; i++) {
        // ��ʼ��visited����
        for (int j = 0; j < n; j++) {
            visited[j] = 0;
        }
        // �ӵ�i�����㿪ʼ�����������
        DFS(i, n);
        // �������δ�����ʵĶ��㣬�򷵻�false
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
   int n, edges,i,j,u, v;

   printf("���붥����: ");
   scanf("%d", &n);

   printf("�������: ");
   scanf("%d", &edges);

   for (i = 0; i < n; i++) {
       for (j = 0; j < n; j++) {
           graph[i][j] = 0;
       }
   }

   printf("�����u�㵽v��:\n");
   for (int i = 0; i < edges; i++) {
       scanf("%d%d", &u, &v);
       graph[u][v] = 1;
   }

   if (isStronglyConnected(n)) {
       printf("yes.\n");
   } else {
       printf("no.\n");
   }

   return 0;
}
