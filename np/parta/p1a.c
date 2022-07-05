#include <stdio.h>
#include <string.h>

char frames[100];
char sendingframes[1000];

int main()
{

    char I[100];
    int n;
    printf("enter the number of frames : ");
    scanf("%d", &n);

    int len;

    for (int i = 0; i < n; i++)
    {
        printf("enter the frame %d : ", i + 1);
        scanf("%s", frames);
        len = strlen(frames);
        sprintf(I, "%d", len);
        strcat(I, frames);
        strcat(sendingframes, I);
    }

    printf("sending frames : %s", sendingframes);

    printf("received frames \n");
    for (int i = 0; i < strlen(sendingframes); i++)
    {
        len = sendingframes[i] - '0';
        for (int j = i + 1; j <= i + len; j++)
        {
            printf("%c", sendingframes[j]);
        }
        printf("\n");
        i = i + len;
    }

    return 0;
}