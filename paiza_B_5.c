#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    if(!scanf("%d",&N))
        return 0;
    int **tmp;
    tmp = (int **)malloc(sizeof(int *) * N);
    if(!tmp)
        return 0;
    for(int i = 0;i < N;i++){
        tmp[i] = (int *)malloc(sizeof(int) * N);
        if(!tmp[i])
            return 0;
        for(int j = 0;j < N;j++){
            if(!scanf("%d",&tmp[i][j]))
                return 0;
        }
    }
    // for(int i = 0;i < N;i++){
    //     for(int j = 0;j < N;j++){
    //         printf("tmp[%d][%d] = %d\n",i,j,tmp[i][j]);
    //     }
    // }

    int arr[N * N];
    int p = 0;
    int h = 0,w= 0;
    for(int i = 0;i < N * N;i++){
        if(p == 0){
            arr[i] = tmp[h][w];
            tmp[h][w] = '\0';
            if(w != N - 1 && tmp[h][w + 1])
                w++;
            else{
                p = 1;
                h++;
            }
        }else if(p == 1){
            arr[i] = tmp[h][w];
            tmp[h][w] = '\0';
            if(h != N - 1 && tmp[h + 1][w])
                h++;
            else{
                p = 2;
                w--;
            }
        }else if(p == 2){
            arr[i] = tmp[h][w];
            tmp[h][w] = '\0';
            if(w != 0 && tmp[h][w - 1])
                w--;
            else{
                p = 3;
                h--;
            }
        }else if(p == 3){
            arr[i] = tmp[h][w];
            tmp[h][w] = '\0';
            if(h != 0 && tmp[h - 1][w])
                h--;
            else{
                p = 0;
                w++;
            }
        }
    }


    int index[4];
    for(int i = 0;i < 4;i++){
        if(i == 0){
            if(!((N * N) / 4))
                index[i] = (N * N) / 4;
            else
                index[i] = (N * N) / 4 - 1;
        }else{
            if(!((N * N) / 4))
                index[i] = index[i - 1] + (N * N) / 4 + 1;
            else
                index[i] = index[i - 1] + (N * N) / 4;
        }
    }
    // for(int i = 0;i < 4;i++){
    //     printf("index[%d] = %d\n",i,index[i]);
    // }

    int time = 0;
    int j = 0;
    for(int n = 0;n < 4;n++){
        while(j <= index[n]){
            time += arr[j];
            j++;
        }
        printf("%d\n",time);
    }
}