
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10 // ɢ�б��С

typedef struct {
    char phone[20];
    char name[20];
    char address[50];
} UserInfo;

typedef struct {
    char phone[20]; // �ؼ���
    UserInfo user; // ֵ
} HashNode;

// ��ϣ��ṹ
typedef struct {
    HashNode nodes[SIZE];
} HashTable;

HashTable table;

// ��ϣ����2
int hash2(char* key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i] * (i + 1);
    }
    return sum % SIZE;
}

// ��ɢ�б��в���ڵ�
void insertNode(HashTable *table, char *phone, char *name, char *address) {
    int index;
    HashNode *node =(HashNode *) malloc(sizeof(HashNode));
    strcpy(node->phone, phone);
    strcpy(node->user.name, name);
    strcpy(node->user.address, address);
    
    // ʹ������̽�ⷨ�����ͻ
     index = hash2(phone);
     while (strcmp(table->nodes[index].phone, "") != 0) {
         index++;
         index %= SIZE;
     }
    
    table->nodes[index] = *node;
}

int collisionCount = 0; // ��ͻ���������ڼ����ͻ��

void linearProbeInsert(char* key, UserInfo user) {
    int index = hash2(key);
    while (table.nodes[index].phone[0] != '\0') {
        index = (index + 1) % SIZE;
        collisionCount++;
    }
    strcpy(table.nodes[index].phone, key);
    table.nodes[index].user = user;
}

int search(char* key) {
    int index = hash2(key);
    int count = 0;

    if (strcmp(table.nodes[index].phone, key) == 0)
        return 1;

    while (table.nodes[index].phone[0] != '\0' && strcmp(table.nodes[index].phone, key) != 0) {
        index = (index + 1) % SIZE;
        count++;
    }

    return count;
}

// ���ݵ绰������ҽڵ�
UserInfo *searchNode(HashTable *table, char *phone) {
    int index;
    index = hash2(phone);
    int i = 0;
    while (strcmp(table->nodes[(index + i) % SIZE].phone, phone) != 0) {
        i++;
        if (i >= SIZE) {
            return NULL;
        }
    }
    return &(table->nodes[(index + i) % SIZE].user);
}



int main() {
    
    for (int i = 0; i < SIZE; i++) {
        strcpy(table.nodes[i].phone, "");
    }
    
    insertNode(&table, "12345678", "����", "������");
    insertNode(&table, "87654321", "����", "�Ϻ���");
    insertNode(&table, "98765432", "����", "������");
    
    linearProbeInsert(table.nodes[1].phone, table.nodes[1].user);
    linearProbeInsert(table.nodes[2].phone, table.nodes[2].user);
    linearProbeInsert(table.nodes[3].phone, table.nodes[3].user);
    
    printf("��������Ҫ���ҵĵ绰���룺\n");
    char c[20];
    gets(c);
    UserInfo *user = searchNode(&table, c);
    if (user != NULL) {
        printf("�绰���룺%s\n", c);
        printf("������%s\n", user->name);
        printf("��ַ��%s\n", user->address);
        printf("Collision Rate: %.2f%%\n", (float)collisionCount / SIZE * 100);
		printf("Average Search Length: %d\n\n", search(c));
    } else {
        printf("δ�ҵ�����û���Ϣ��\n");
    }
    
    
    return 0;
}
