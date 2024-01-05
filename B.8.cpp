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
        // 初始化visited数组
        for (int j = 0; j < n; j++) {
            visited[j] = 0;
        }
        // 从第i个顶点开始深度优先搜索
        DFS(i, n);
        // 如果存在未被访问的顶点，则返回false
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

   printf("输入顶点数: ");
   scanf("%d", &n);

   printf("输入边数: ");
   scanf("%d", &edges);

   for (i = 0; i < n; i++) {
       for (j = 0; j < n; j++) {
           graph[i][j] = 0;
       }
   }

   printf("输入从u点到v点:\n");
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
