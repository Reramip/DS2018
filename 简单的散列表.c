#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TABLE_LENGTH 43
#define NAME_LENGTH 20
#define PHONE_LENGTH 10
/*小写20位姓名，10位数字号码，未异常处理*/
typedef struct Node {
    char* name;
    char* phone;
    struct Node* next;
}node;

typedef struct HashTable {
    node* hash_node[TABLE_LENGTH];
}table;

void listInit(node** list);
void listInsert(char* name, char* phone,node** list);
_Bool listDelete(char* name, node** list);
_Bool listChange(char* name, char* phone, node** list);
node* listFind(char* name, node** list);
int hash(char* name);
void tableInit(table** t);

int main(void) {
    char input = 1;
    char name[NAME_LENGTH + 1];
    char phone[PHONE_LENGTH + 1];
    int hash_num;
    _Bool flag;
    node* find_res;
    table* t;
    tableInit(&t);
    printf("按1查找，按2添加，按3修改，按4删除，按q退出\n姓名小写20位，号码10位，姓名、号码间有回车\n");
    while (input != 'q') {
        input = getchar();
        switch (input) {
        case '1':
            getchar();
            fgets(name, NAME_LENGTH + 1, stdin);
            hash_num = hash(name);
            find_res = listFind(name, &(t->hash_node[hash_num]));
            if (find_res != NULL) {
                puts(find_res->phone);
            }
            else {
                puts("Not found.");
            }
            break;
        case '2':
            getchar();
            fgets(name, NAME_LENGTH + 1, stdin);
            fgets(phone, PHONE_LENGTH + 1, stdin);
            hash_num = hash(name);
            listInsert(name, phone, &(t->hash_node[hash_num]));
            break;
        case '3':
            getchar();
            fgets(name, NAME_LENGTH + 1, stdin);
            fgets(phone, PHONE_LENGTH + 1, stdin);
            hash_num = hash(name);
            flag = listChange(name, phone, &t->hash_node[hash_num]);
            if (!flag) {
                puts("Not found.");
            }
            break;
        case '4':
            getchar();
            fgets(name, NAME_LENGTH + 1, stdin);
            hash_num = hash(name);
            flag = listDelete(name, &(t->hash_node[hash_num]));
            if (!flag) {
                puts("Not found.");
            }
            break;
        default:break;
        }
    }

    return 0;
}

void listInit(node** list) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->name = NULL;
    new_node->phone = NULL;
    new_node->next = NULL;
    (*list) = new_node;
}

void listInsert(char* name, char* phone,node** list) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->name = (char*)malloc(sizeof(char)*(NAME_LENGTH + 1));
    new_node->phone = (char*)malloc(sizeof(char)*(PHONE_LENGTH + 1));
    strcpy(new_node->name, name);
    strcpy(new_node->phone, phone);
    new_node->next = (*list)->next;
    (*list)->next = new_node;
}

_Bool listChange(char* name, char* phone, node** list) {
    node* p = (*list)->next;
    while (p != NULL) {
        if (strcmp(name, p->name) == 0) {
            strcpy(p->phone, phone);
            return 1;
        }
        p = p->next;
    }
    return 0;
}

_Bool listDelete(char* name, node** list) {
    node* p = *list;
    node* q = (*list)->next;
    while (q != NULL) {
        if (strcmp(name, q->name) == 0) {
            p->next = q->next;
            free(q);
            return 1;
        }
        q = q->next;
        p = p->next;
    }
    return 0;
}

node* listFind(char* name, node** list) {
    node* p = (*list)->next;
    while (p != NULL) {
        if (strcmp(name, p->name) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int hash(char* name) {
    char* p = name;
    int sum = 0;
    while (*p != '\0' && *p != '\n') {
        sum += *p - 'a';
        ++p;
    }
    return sum%TABLE_LENGTH;
}

void tableInit(table** t) {
    table* new_table = (table*)malloc(sizeof(table));
    (*t) = new_table;
    int i;
    for (i = 0; i < TABLE_LENGTH; i++) {
        listInit(&((*t)->hash_node[i]));
    }
}
