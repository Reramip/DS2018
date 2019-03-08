#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000
#define SECMAX 10000//4位一组

typedef struct Node {
    int data;
    struct Node* next;
}node;

void ListInit(node** l);//初始化链表
void ListInsert(int num, node** l);//链表插入（前插）
int ListLength(node* l);//获取长度
void Save(char* str, node** l);//将输入数字存入链表
void Plus(node* l1, node* l2, node** ans);//加
void Minus(node* l1, node* l2, node** ans);//减
void Multi(node* l1, node* l2, node** ans);//乘
void Div(node* l1, node* l2, node** ans);//大除以小（小于10000，除法未完全实现）
void ShowAnswer(node* ans);//显示结果

int main(void) {
    node* l1, *l2, *ans;
    char* num = (char*)malloc(sizeof(char)*MAX);
    char ch;
    ListInit(&l1);
    ListInit(&l2);
    ListInit(&ans);
    printf("****WARNING:The divisor must be lower than 10000.****\n");
    printf("Select the operator(+,-,*,/):");
    ch = getchar();
    getchar();
    printf("Input the first positive integer:");
    gets_s(num,MAX);
    Save(num, &l1);
    printf("Input the second positive integer:");
    gets_s(num,MAX);
    Save(num, &l2);
    free(num);
    switch (ch) {
    case '+':Plus(l1, l2, &ans); break;
    case '-':Minus(l1, l2, &ans); break;
    case '*':Multi(l1, l2, &ans); break;
    case '/':Div(l1, l2, &ans); break;
    default: printf("Operator error.\n"); system("pause>nul echo"); return 1;
    }
    ShowAnswer(ans);

    getchar();
    return 0;
}

void ListInit(node** l) {
    node* p = (node*)malloc(sizeof(node));
    if (!p) {
        printf("\nOut of memory.\n");
        system("pause>nul echo");
        exit(1);
    }
    p->next = NULL;
    *l = p;
}

void ListInsert(int num, node** l) {
    node* p = *l;
    node* q = (node*)malloc(sizeof(node));
    if (!q) {
        printf("\nOut of memory.\n");
        system("pause>nul echo");
        exit(1);
    }
    q->data = num;
    q->next = p->next;
    p->next = q;
}

int ListLength(node* l) {
    node* p = l;
    int len = 0;
    while (p) {
        p = p->next;
        len++;
    }
    return len;
}

void Save(char* str, node** l) {
    int len = strlen(str);
    int front = len % 4;
    int num, cnt;
    num = cnt = 0;
    switch (front) {
    case 1:
        num = (str[0] - '0');
        ListInsert(num, l); break;
    case 2:
        num = (str[0] - '0') * 10 + (str[1] - '0');
        ListInsert(num, l); break;
    case 3:
        num = (str[0] - '0') * 100 + (str[1] - '0') * 10 + (str[2] - '0');
        ListInsert(num, l); break;
    default:break;
    }//先处理前front位，front为数字长度除以4的余数
    str += front;
    while (*str != '\0') {
        num = 0;
        num += (*str - '0') * 1000;
        str++;
        num += (*str - '0') * 100;
        str++;
        num += (*str - '0') * 10;
        str++;
        num += (*str - '0');
        str++;
        ListInsert(num, l);
    }//"1234"=1*1000+2*100+3*10+4
}

void Plus(node* l1, node* l2, node** ans) {
    node* p1 = l1->next;
    node* p2 = l2->next;
    int carry = 0;
    int tmp = 0;
    while (p1&&p2) {
        tmp = p1->data + p2->data + carry;
        if (tmp >= SECMAX) {
            carry = 1;
            tmp %= SECMAX;
            ListInsert(tmp, ans);
        }
        else {
            carry = 0;
            ListInsert(tmp, ans);
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p1) {
        tmp = p1->data + carry;
        if (tmp >= SECMAX) {
            carry = 1;
            tmp %= SECMAX;
            ListInsert(tmp, ans);
        }
        else {
            carry = 0;
            ListInsert(tmp, ans);
        }
        p1 = p1->next;
    }
    while (p2) {
        tmp = p2->data + carry;
        if (tmp >= SECMAX) {
            carry = 1;
            tmp %= SECMAX;
            ListInsert(tmp, ans);
        }
        else {
            carry = 0;
            ListInsert(tmp, ans);
        }
        p2 = p2->next;
    }
    if (carry) {
        ListInsert(carry, ans);
    }
}

void Minus(node* l1, node* l2, node** ans) {
    node* p1 = l1->next;
    node* p2 = l2->next;
    int decomp = 0;
    int tmp = 0;
    while (p1&&p2) {
        tmp = p1->data - p2->data - decomp;
        if (tmp<0) {
            tmp += SECMAX;
            decomp = 1;
            ListInsert(tmp, ans);
        }
        else {
            decomp = 0;
            ListInsert(tmp, ans);
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p1) {
        tmp = p1->data - decomp;
        if (tmp<0) {
            tmp += SECMAX;
            decomp = 1;
            ListInsert(tmp, ans);
        }
        else {
            decomp = 0;
            ListInsert(tmp, ans);
        }
        p1 = p1->next;
    }
    while (p2) {
        tmp = 0 - p2->data - decomp;
        if (tmp<0) {
            tmp += SECMAX;
            decomp = 1;
            ListInsert(tmp, ans);
        }
        else {
            decomp = 0;
            ListInsert(tmp, ans);
        }
        p2 = p2->next;
    }
    /*若为负数，大减小*/
    if (decomp) {
        p1 = l1->next;
        p2 = l2->next;
        decomp = tmp = 0;
        free((*ans)->next);
        (*ans)->next = NULL;
        while (p1&&p2) {
            tmp = p2->data - p1->data - decomp;
            if (tmp<0) {
                tmp += SECMAX;
                decomp = 1;
                ListInsert(tmp, ans);
            }
            else {
                decomp = 0;
                ListInsert(tmp, ans);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p2) {
            tmp = p2->data - decomp;
            if (tmp<0) {
                tmp += SECMAX;
                decomp = 1;
                ListInsert(tmp, ans);
            }
            else {
                decomp = 0;
                ListInsert(tmp, ans);
            }
            p2 = p2->next;
        }
        printf("-");
    }
}

void Multi(node* l1, node* l2, node** ans) {
    int len1, len2, lena, cnt1, cnt2, cnta, cnt, tmp1, tmp2, tmp, carry;
    node* p1, *p2, *pa, *p0;
    node* ansReverse;
    ListInit(&ansReverse);
    p1 = l1->next; p2 = l2->next;
    carry = 0;
    cnt1 = cnt2 = cnta = 1;
    cnt = cnt1 + cnt2;
    len1 = ListLength(p1);
    len2 = ListLength(p2);
    lena = len1 + len2;
    for (register int i = 0; i<lena; i++) {
        ListInsert(0, &ansReverse);
    }
    pa = ansReverse->next; p0 = pa->next;
    while (p2) {
        cnt1 = 1;
        cnt = cnt1 + cnt2;
        pa = ansReverse->next;
        for (cnta = 1; cnta<cnt - 1; cnta++) {
            pa = pa->next;
        }
        p0 = pa->next;
        p1 = l1->next;
        while (p1) {
            tmp = p1->data*p2->data;
            tmp1 = tmp / SECMAX;
            tmp2 = tmp % SECMAX;
            pa->data += tmp2;
            p0->data += tmp1;
            pa = pa->next;
            p0 = pa->next;
            p1 = p1->next;
            cnt1++;
        }
        p2 = p2->next;
        cnt2++;
    }
    pa = ansReverse->next;
    while (pa) {
        tmp = pa->data + carry;
        if (tmp >= SECMAX) {
            pa->data = tmp % SECMAX;
            carry = tmp / SECMAX;
        }
        else {
            pa->data = tmp;
            carry = 0;
        }
        pa = pa->next;
    }//此时ans表头为低位
    pa = ansReverse->next;
    while (pa != NULL) {
        ListInsert(pa->data, ans);
        pa = pa->next;
    }
}

void Div(node* l1, node* l2, node** ans) {
    int divisor = l2->next->data;
    int remainder = 0;
    int devidend = 0;
    int temp = 0;
    node* p = l1->next;
    node* l1Reverse;
    node* ansReverse;
    ListInit(&l1Reverse);
    ListInit(&ansReverse);
    while (p != NULL) {
        ListInsert(p->data, &l1Reverse);
        p = p->next;
    }
    p = l1Reverse->next;
    while (p != NULL) {
        devidend = remainder*SECMAX + p->data;
        temp = devidend / divisor;
        remainder = devidend % divisor;
        ListInsert(temp, &ansReverse);
        p = p->next;
    }
    p = ansReverse->next;
    while (p != NULL) {
        ListInsert(p->data, ans);
        p = p->next;
    }
    printf("\nRemainder: %d\n", remainder);
}

void ShowAnswer(node* ans) {
    node* p = ans->next;
    int flag = 0;//判断是否舍0
    printf("\nThe answer is: ");
    if (p->next == NULL) {
        printf("%d", p->data);
        return;
    }//只有一个数
    while (p->data == 0 && p->next) {
        p = p->next;
    }//略过多余的0
    while (p) {
        if (flag == 1) {
            printf("%04d,", p->data);
        }
        else if (p->data != 0) {
            printf("%d,", p->data);
            flag = 1;
        }
        p = p->next;
    }
    printf("\b \b");
}
