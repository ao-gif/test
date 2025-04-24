#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N,H,W;
    if(scanf("%d %d %d",&N,&H,&W) != 3)
        return 0;
    int s_y_tmp,s_x_tmp;
    if(scanf("%d %d",&s_y_tmp,&s_x_tmp) != 2)
        return 0;
    int s_y = s_y_tmp - 1,s_x = s_x_tmp - 1;
    char dict[N];
    if(!scanf("%s",dict))
        return 0;
    int **arr;
    arr = (int **)malloc(sizeof(int *) * H);
    if(!arr)
        return 0;
    for(int i = 0;i < H;i++){
        arr[i] = (int *)malloc(sizeof(int) * W);
        if(!arr[i])
            return 0;
    }
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            if(!scanf("%d",&arr[i][j]))
                return 0;
        }
    }
    for(int i = 0;i < N;i++){
        if(dict[i] == 'R'){
            s_x++;
            printf("%d\n",arr[s_y][s_x]);
        }
        if(dict[i] == 'L'){
            s_x--;
            printf("%d\n",arr[s_y][s_x]);
        }
        if(dict[i] == 'F'){
            s_y--;
            printf("%d\n",arr[s_y][s_x]);
        }
        if(dict[i] == 'B'){
            s_y++;
            printf("%d\n",arr[s_y][s_x]);
        }
    }
    for(int i = 0;i < H;i++)
        free(arr[i]);
    free(arr);
    return 0;
}