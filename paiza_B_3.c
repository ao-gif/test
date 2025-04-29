#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int H,W,N;
    if(scanf("%d %d %d",&H,&W,&N) != 3)
        return 0;
    char ***stamp;
    stamp = (char ***)malloc(sizeof(char **) * N);
    if(!stamp)
        return 0;
    for(int i = 0;i < N;i++){
        stamp[i] = (char **)malloc(sizeof(char *) * H);
        if(!stamp[i])
            return 0;
        for(int j = 0;j <H;j++){
            stamp[i][j] = (char *)malloc(sizeof(char) * W);
            if(!stamp[i][j])
                return 0;
        }
    }

    for(int i = 0;i < N;i++){
        for(int j = 0;j < H;j++){
            if(!scanf("%s",stamp[i][j]))
                return 0;
        }
    }

    int R,C;
    if(scanf("%d %d",&R,&C) != 2)
        return 0;
    int art[R * C];
    int n = 0;
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++){
            if(!scanf("%d",&art[n]))
                return 0;
            n++;
        }
    }

    int k = 0;
    int tmp = 0;
    for(int i = 0;i < R;i++){
        for(int n = 0;n < H;n++){
            k = tmp;
            for(int j = 0;j < C;j++){
                printf("%s",stamp[art[k] - 1][n]);
                k++;
            }
            printf("\n");
        }
        tmp += C;
    }

    for(int i = 0;i < N;i++){
        for(int j = 0;j < H;j++){
            free(stamp[i][j]);
        }
    }
    free(stamp);
    return 0;
}



// 2 3 2
// abc
// def
// ghi
// jkl
// 3 3
// 1 2 1
// 2 1 2
// 1 2 1