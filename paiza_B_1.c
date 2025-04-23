#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int H,W;
    if(scanf("%d %d", &H, &W) != 2)
        return 0;
    char **mount;
    mount = (char **)malloc(sizeof(char *) * H);
    if(!mount)
        return 0;
    for(int i = 0;i < H;i++){
        mount[i] = (char *)malloc(sizeof(char) * W);
        if(!mount[i])
            return 0;
        if(!scanf("%s",mount[i]))
            return 0;
    }

    int index = 1;
    int count = 0;
    for(int i = 0;i < W;i++){
        if(index == 0 && mount[H - 1][i] == '0'){
            count++;
            index = 1;
        }
        if(index == 1 && mount[H - 1][i] == '1')
            index = 0;
        if(i == W - 1 && mount[H - 1][i] == '1')
            count++;
    }

    int num[count];
    for(int i = 0;i < count;i++)
        num[i] = 0;
    int n = 0;
    for(int j = 0;j < W;j++){
        for(int i = 0;i < H;i++){
            if(mount[i][j] == '1')
                (num[n])++;
            if(n < count && i == H - 1 && mount[i][j - 1] != '0' && mount[i][j] == '0')
                n++;
        }
    }

    int tmp = 0;
    for(int i = 0;i < count;i++){
        if(num[i] > tmp)
            tmp = num[i];
    }
    printf("%d\n",tmp);

    for(int i = 0;i < H;i++)
        free(mount[i]);
    free(mount);
    return 0;
}