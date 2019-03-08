#include<stdio.h>
#include<stdlib.h>

void Move(int n, char start, char destination)
{
    printf("%d:  %c -->> %c\n", n, start, destination);
}

void Hanoi(int n, char start, char destination, char sub)
{
    if (n == 1) Move(n, start, destination);
    else
    {
        Hanoi(n - 1, start, sub, destination);
        Move(n - 1, start, destination);
        Hanoi(n - 1, sub, destination, start);
    }
}


int main(void)
{
    int n = 64;
    char A = 'A';
    char B = 'B';
    char C = 'C';

    Hanoi(n, A, B, C);

    system("pause");
    return 0;
}