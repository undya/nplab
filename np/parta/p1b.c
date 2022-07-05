#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sender();
void receiver(int *message, int l2);

int main()
{
    sender();
    return 0;
}

void sender()
{
    int i, j, count = 0, n, l1, onecounter = 0, zero = 0;
    int msg[100];
    int result[100];

    printf("enter the number of bits to send : ");
    scanf("%d", &n);
    printf("\n enter the bits : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &msg[i]);
    }

    result[0] = 0;
    result[1] = 1;
    result[2] = 1;
    result[3] = 1;
    result[4] = 1;
    result[5] = 1;
    result[6] = 1;
    result[7] = 0;
    j = 8;
    for (int i = 0; i < n; i++)
    {
        if (count == 5 && zero == 1)
        {
            result[j++] = 0;
            count = 0;
            onecounter++;
        }
        if (msg[i] == 0)
        {
            result[j++] = msg[i];
            count = 0;
            zero = 1;
        }
        else
        {
            result[j++] = msg[i];
            count++;
        }
    }

    if (count == 5)
    {
        result[j++] = 0;
        onecounter++;
        count = 0;
    }

    result[j++] = 0;
    result[j++] = 1;
    result[j++] = 1;
    result[j++] = 1;
    result[j++] = 1;
    result[j++] = 1;
    result[j++] = 1;
    result[j++] = 0;

    l1 = n + onecounter + 16;
    for (i = 0; i < l1; i++)
    {
        printf("%d", result[i]);
    }
    receiver(result, l1);
}

void receiver(int *result, int l2)
{
    int i, j = 0, l3, count = 0;
    int mesg[100];

    l3 = l2 - 8;

    for (i = 8; i < l3; i++)
    {
        if (count == 5)
        {
            i++;
            count = 0;
        }
        if (result[i] == 0)
        {
            mesg[j++] = result[i];
            count = 0;
        }
        else
        {
            mesg[j++] = result[i];
            count++;
        }
    }

    printf("receiver side message : ");
    for (i = 0; i < j; i++)
    {
        printf("%d", mesg[i]);
    }
}