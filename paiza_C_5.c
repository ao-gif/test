#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    if(!scanf("%d",&N)) return 1;
    char **user_id = malloc(sizeof(char *) * N);
    if(!user_id)    return 1;
    for(int i = 0;i < N;i++){
        user_id[i] = malloc(sizeof(char) * 20000);
        if(!user_id[i])     return 1;
        if(!scanf("%s",user_id[i]))    return 1;
    }
    int id_num[N];
    for(int i = 0;i < N;i++){
        // char *tmp = malloc(sizeof(char) * 10000);
        char tmp[10000];
        int j = 0;
        int n = 0;
        while(user_id[i][j]){
            if('0' <= user_id[i][j] && user_id[i][j] <= '9'){
                tmp[n] = user_id[i][j];
                n++;
            }
            j++;
        }
        tmp[n] = '\0';
        id_num[i] = 0;
        for(int j = 0;j < n;j++){
            id_num[i] *= 10;
            id_num[i] += tmp[j] - '0';
        }
        // printf("%d\n",id_num[i]);
    }

    for(int i = 0;i < N - 1;i++){
        for(int j = 0;j < N - i - 1;j++){
            if(id_num[j] > id_num[j + 1]){
                int int_tmp = id_num[j];
                id_num[j] = id_num[j + 1];
                id_num[j + 1] = int_tmp;

                char *char_tmp = user_id[j];
                user_id[j] = user_id[j + 1];
                user_id[j + 1] = char_tmp;
            }
        }
    }

    // for(int i = 0;i < N;i++)
    //     printf("%d\n",id_num[i]);

    for(int i = 0;i < N;i++){
        printf("%s\n",user_id[i]);
        free(user_id[i]);
    }
    free(user_id);
    
    return 0;
}