#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    if(!scanf("%d",&N))     return 1;
    int **grid = malloc(sizeof(int *) * N);
    int **arrange = malloc(sizeof(int *) * N);
    if(!grid || !arrange)   return 1;
    for(int i = 0;i < N;i++){
        grid[i] = malloc(sizeof(int) * N);
        arrange[i] = malloc(sizeof(int) * N);
        if(!grid[i] || !arrange[i]){
            for(int j = 0;j < i - 1;j++){
                free(grid[j]);
                free(arrange[j]);
            }
            free(grid);
            free(arrange);
            return 1;
        }

        for(int j = 0;j < N;j++)
            if(!scanf("%d",&grid[i][j]))    return 1;
    }

    for(int i = 0;i < N / 2 + 1;i++){
        for(int j = 0;j < N / 2 + 1;j++){
            if(j < i){
                arrange[i][j] = j + 1;
            }
            else
                arrange[i][j] = i + 1;

            arrange[i][N - j - 1] = arrange[i][j];
            arrange[N - i - 1][j] = arrange[i][j];
            arrange[N - i - 1][N - j - 1] = arrange[i][j];
        }
    }

    printf("\n");
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++)
            printf("%d ",arrange[i][j]);
        printf("\n");
    }

    int diff = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++)
            diff += grid[i][j] - arrange[i][j];
    }

    for(int i = 0;i < N;i++){
        free(grid[i]);
        free(arrange[i]);
    }
    free(grid);
    free(arrange);

    printf("%d\n",diff);
    return 0;
}