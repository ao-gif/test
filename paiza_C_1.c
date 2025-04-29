#include <stdio.h>
#include <stdlib.h>

void ft_free(char **arr)
{
    for(int i = 0;arr[i];i++){
        free(arr[i]);
    }
    free(arr);
}

int main(void)
{
    int N;
    if(!scanf("%d",&N))
        return 0;
    char **arr;
    arr = (char **)malloc(sizeof(char *) * N);
    if(!arr)
        return 0;
    for(int i = 0;i < N;i++){
        arr[i] = (char *)malloc(sizeof(char) * 50);
        if(!arr[i])
            return 0;
    }

    for(int i = 0;i < N;i++){
        if(!scanf("%s",arr[i]))
            return 0;
    }

    char tmp = arr[0][0];
    for(int i = 0;i < N;i++){
        if(tmp != arr[i][0]){
            printf("%c %c\n",tmp,arr[i][0]);
            ft_free(arr);
            return 0;
        }
        for(int j = 0;arr[i][j];j++){
            if(!arr[i][j + 1])
                tmp = arr[i][j];
        }
    }
    printf("Yes\n");
    ft_free(arr);
    return 0;
}