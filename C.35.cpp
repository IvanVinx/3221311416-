#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GF  G->adjlist[i].firstarc  
#define INFINITY 32767			// ֵ�������ǵ���int��Ϊ2�ֽ�
const int max=8;		// ��󶥵����
typedef struct {
	int arcs[max][max];		// �ڽӾ�������
	int n,e; 										// ͼ�ĵ�ǰ�������ͻ���
} MGraph;
void CreateMat(MGraph &g, int A[][max], int n, int e){ //����ͼ���ڽӾ���
	g.n=n,g.e=e;
	for(int i=0; i<max; i++)
		for(int j=0; j<max; j++) {
			g.arcs[i][j]=A[i][j];
		}
}
void DispMatrix(MGraph g){ //����ڽӾ���g
	for(int i=0; i<max; i++) {
		for(int j=0; j<max; j++) {
			printf("  %d",g.arcs[i][j]);
		}
		printf("\n");
	}

}

typedef struct ArcNode {	// ������
	int adjvex; 			// �û���ָ��Ķ����λ��
	//int weight; 			// ����Ȩֵָ��
	ArcNode *nextarc; 		// ָ����һ������ָ��
} ArcNode;

typedef struct {
	//VertexType name; 		// ������Ϣ
	ArcNode *firstarc; 		// ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ��
} VNode;

typedef struct  {
	VNode adjlist[max];    	//adjacency List
	int n, e; // ͼ�ĵ�ǰ�������ͻ���
} ALGraph;


int init(ALGraph *&G){
	G=(ALGraph*)malloc(sizeof(ALGraph));
	for(int i=0; i<max; i++) {
		GF=(ArcNode*)malloc(sizeof(ArcNode));
		if(!GF) return 0;//����ʧ��
		GF->nextarc=NULL;
	}
}

int DestroyAdj (ALGraph *&G){ //����ͼ���ڽӱ�
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

void CreateAdj (ALGraph *&G, int A[][max], int n, int e){   //����ͼ���ڽӱ�
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

void DispAdj_List(ALGraph *G) {  //����ڽӱ�G
	ArcNode *p;
	printf("ͼ G ���ڽӱ�: \n");
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


//************************�ڽӱ��ڽӾ�����໥ת��*******************************************//
void MatrixToList(MGraph g, ALGraph *&G){ //���ڽӾ���g ת�����ڽӱ�G
	printf("��gת��Ϊ�ڽӱ� G \n");
	init(G);
	CreateAdj (G,g.arcs,8,9);
}

void ListToMatrix(ALGraph *G, MGraph &g){ //���ڽӱ�G ת�����ڽӾ���g
	printf("��Gת�����ڽӾ���g\n");
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
	MGraph  g;//�ڽӾ���
	ALGraph *G;//�ڽӱ�
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
	//1.����������ڽӾ���g 
	CreateMat(g,m,8,9);
	printf("ͼG���ڽӾ���:\n");
	DispMatrix(g);

	//2.�ڽӾ���gת�����ڽӱ�G
	ALGraph *G1;//Ϊ����ת������һ���ڽӱ�G1
	MatrixToList(g,G1);
	DispAdj_List(G1);
	DestroyAdj(G1);
 
	//3.����������ڽӱ�G 
	CreateAdj(G,m,8,9);
	DispAdj_List(G);
	
	//4.���ڽӱ�Gת�����ڽӾ���g
	MGraph  g1;//Ϊ����ת������һ���ڽӾ���g1
	ListToMatrix(G,g1);
	DispMatrix(g);
	
	//5.�����ڽӱ�G,G1 
	DestroyAdj(G);
	DestroyAdj(G1);
}



