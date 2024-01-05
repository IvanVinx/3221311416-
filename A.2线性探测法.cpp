
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10 // 散列表大小

typedef struct {
    char phone[20];
    char name[20];
    char address[50];
} UserInfo;

typedef struct {
    char phone[20]; // 关键字
    UserInfo user; // 值
} HashNode;

// 哈希表结构
typedef struct {
    HashNode nodes[SIZE];
} HashTable;

HashTable table;

// 哈希函数2
int hash2(char* key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i] * (i + 1);
    }
    return sum % SIZE;
}

// 在散列表中插入节点
void insertNode(HashTable *table, char *phone, char *name, char *address) {
    int index;
    HashNode *node =(HashNode *) malloc(sizeof(HashNode));
    strcpy(node->phone, phone);
    strcpy(node->user.name, name);
    strcpy(node->user.address, address);
    
    // 使用线性探测法处理冲突
     index = hash2(phone);
     while (strcmp(table->nodes[index].phone, "") != 0) {
         index++;
         index %= SIZE;
     }
    
    table->nodes[index] = *node;
}

int collisionCount = 0; // 冲突计数，用于计算冲突率

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

// 根据电话号码查找节点
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
    
    insertNode(&table, "12345678", "张三", "北京市");
    insertNode(&table, "87654321", "李四", "上海市");
    insertNode(&table, "98765432", "王五", "广州市");
    
    linearProbeInsert(table.nodes[1].phone, table.nodes[1].user);
    linearProbeInsert(table.nodes[2].phone, table.nodes[2].user);
    linearProbeInsert(table.nodes[3].phone, table.nodes[3].user);
    
    printf("请输入需要查找的电话号码：\n");
    char c[20];
    gets(c);
    UserInfo *user = searchNode(&table, c);
    if (user != NULL) {
        printf("电话号码：%s\n", c);
        printf("姓名：%s\n", user->name);
        printf("地址：%s\n", user->address);
        printf("Collision Rate: %.2f%%\n", (float)collisionCount / SIZE * 100);
		printf("Average Search Length: %d\n\n", search(c));
    } else {
        printf("未找到相关用户信息。\n");
    }
    
    
    return 0;
}
