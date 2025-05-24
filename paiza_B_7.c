#include <stdio.h>
#include <stdlib.h>

void ft_filling(int **grid,int *hit_num,int times,int N)
{
    for(int i = 0;i < times;i++){
        for(int high = 0;high < N;high++){
            for(int wide = 0;wide < N;wide++){
                if(grid[high][wide] == hit_num[i])
                    grid[high][wide] = 0;
            }
        }
    }
}

int ft_side_count(int **grid,int N)
{
    int count = 0;
    for(int high = 0;high < N;high++){
        int check = 0;
        for(int wide = 0;wide < N;wide++){
            if(grid[high][wide])
                check = 1;
        }
        if(!check)  count++;
    }
    return count;
}

int ft_vertical_count(int **grid,int N)
{
    int count = 0;
    for(int wide = 0;wide < N;wide++){
        int check = 0;
        for(int high = 0;high < N;high++){
            if(grid[high][wide])
                check = 1;
        }
        if(!check)  count++;
    }
    return count;
}

int ft_diagonal_count(int **grid,int N)
{
    int count = 0;
    int check = 0;
    for(int i = 0;i < N;i++)
        if(grid[i][i])  check = 1;
    if(!check)  count++;
    check = 0;
    for(int i = 0;i < N;i++)
        if(grid[i][N - i - 1])  check = 1;
    if(!check)  count++;
    return count;
}

int main(void)
{
    int N,times;
    if(!scanf("%d %d",&N,&times))   return 1;
    int **grid = (int **)malloc(sizeof(int *) * N);
    if(!grid)   return 1;
    for(int high = 0;high < N;high++){
        grid[high] = (int *)malloc(sizeof(int) * N);
        if(!grid[high]){
            for(int j = 0;j < high;j++)
                free(grid[j]);
            return 1;
        }
        for(int wide = 0;wide < N;wide++)
            if(!scanf("%d",&grid[high][wide]))  return 1;
    }
    int *hit_num = (int *)malloc(sizeof(int) * times);
    if(!hit_num)    return 1;
    for(int i = 0;i < times;i++)
        if(!scanf("%d",&hit_num[i]))    return 1;

    ft_filling(grid,hit_num,times,N);
    int side_count = ft_side_count(grid,N);
    int ver_count = ft_vertical_count(grid,N);
    int diag_count = ft_diagonal_count(grid,N);
    int count = side_count + ver_count + diag_count;
    // printf("side : %d\nvert : %d\ndiag : %d\n",side_count,ver_count,diag_count);
    printf("%d\n",count);
    for(int i = 0;i < N;i++)
        free(grid[i]);
    free(grid);
    free(hit_num);
    return 0;
}