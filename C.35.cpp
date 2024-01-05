#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GF  G->adjlist[i].firstarc  
#define INFINITY 32767			// 值∞这里是当作int型为2字节
const int max=8;		// 最大顶点个数
typedef struct {
	int arcs[max][max];		// 邻接矩阵数组
	int n,e; 										// 图的当前顶点数和弧数
} MGraph;
void CreateMat(MGraph &g, int A[][max], int n, int e){ //创建图的邻接矩阵
	g.n=n,g.e=e;
	for(int i=0; i<max; i++)
		for(int j=0; j<max; j++) {
			g.arcs[i][j]=A[i][j];
		}
}
void DispMatrix(MGraph g){ //输出邻接矩阵g
	for(int i=0; i<max; i++) {
		for(int j=0; j<max; j++) {
			printf("  %d",g.arcs[i][j]);
		}
		printf("\n");
	}

}

typedef struct ArcNode {	// 链表结点
	int adjvex; 			// 该弧所指向的顶点的位置
	//int weight; 			// 网的权值指针
	ArcNode *nextarc; 		// 指向下一条弧的指针
} ArcNode;

typedef struct {
	//VertexType name; 		// 顶点信息
	ArcNode *firstarc; 		// 第一个表结点的地址,指向第一条依附该顶点的弧的指针
} VNode;

typedef struct  {
	VNode adjlist[max];    	//adjacency List
	int n, e; // 图的当前顶点数和弧数
} ALGraph;


int init(ALGraph *&G){
	G=(ALGraph*)malloc(sizeof(ALGraph));
	for(int i=0; i<max; i++) {
		GF=(ArcNode*)malloc(sizeof(ArcNode));
		if(!GF) return 0;//创建失败
		GF->nextarc=NULL;
	}
}

int DestroyAdj (ALGraph *&G){ //销毁图的邻接表
	ArcNode*p;
	for(int i=0; i<max; i++) {
		p=GF;
		while(GF) {
			p=GF->nextarc;
			free(GF);
			GF=p;
		}
	}
	free(G);
	return 1;
}

void CreateAdj (ALGraph *&G, int A[][max], int n, int e){   //创建图的邻接表
	init(G);
	G->n=n;
	G->e=e;
	for(int i=0; i<n; i++)
		for(int j=n-1; j>=0; j--) {
			if(A[i][j]!=0) {
				ArcNode* p=(ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->nextarc=GF->nextarc;
				GF->nextarc=p;
			}
		}
}

void DispAdj_List(ALGraph *G) {  //输出邻接表G
	ArcNode *p;
	printf("图 G 的邻接表: \n");
	for(int i=0; i<max; i++) {
		printf(" %d:",i);
		p=GF->nextarc;
		for(int j=0; j<max; j++) {
			if(p->adjvex==j) {
				printf("%d",p->adjvex);
				if(p->nextarc!=NULL) {
					printf("->");
					p=p->nextarc;
				} else
					printf("\n");
			}
		}
	}

}


//************************邻接表邻接矩阵的相互转化*******************************************//
void MatrixToList(MGraph g, ALGraph *&G){ //将邻接矩阵g 转换成邻接表G
	printf("将g转换为邻接表 G \n");
	init(G);
	CreateAdj (G,g.arcs,8,9);
}

void ListToMatrix(ALGraph *G, MGraph &g){ //将邻接表G 转换成邻接矩阵g
	printf("将G转换成邻接矩阵g\n");
	g.n=G->n;
	g.e=G->e;
	ArcNode *p;
	memset(g.arcs,0,sizeof(g.arcs));
	for(int i=0; i<max; i++)
		for(int j=0; j<max; j++) {
			p=GF->nextarc;
			if(j==p->adjvex){
				g.arcs[i][j]=1;
				p=p->nextarc;
			}			
		}
}

int main(){
	MGraph  g;//邻接矩阵
	ALGraph *G;//邻接表
	int m[8][8]= {
		{0,1,1,0,0,0,0,0},
		{1,0,0,1,1,0,0,0},
		{1,0,0,0,0,1,1,0},
		{0,1,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,1},
		{0,0,1,0,0,0,1,0},
		{0,0,1,0,0,1,0,0},
		{0,0,0,1,1,0,0,0}
	};
	//1.创建并输出邻接矩阵g 
	CreateMat(g,m,8,9);
	printf("图G的邻接矩阵:\n");
	DispMatrix(g);

	//2.邻接矩阵g转换成邻接表G
	ALGraph *G1;//为测试转化另设一个邻接表G1
	MatrixToList(g,G1);
	DispAdj_List(G1);
	DestroyAdj(G1);
 
	//3.创建并输出邻接表G 
	CreateAdj(G,m,8,9);
	DispAdj_List(G);
	
	//4.将邻接表G转换成邻接矩阵g
	MGraph  g1;//为测试转化另设一个邻接矩阵g1
	ListToMatrix(G,g1);
	DispMatrix(g);
	
	//5.销毁邻接表G,G1 
	DestroyAdj(G);
	DestroyAdj(G1);
}



