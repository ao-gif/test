#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    if(!scanf("%d",&N)) return 0;

    char **char_in_time = malloc(sizeof(char *) * N);
    char **char_out_time = malloc(sizeof(char *) * N);
    if(!char_in_time || !char_out_time)
        return 1;
    for(int i = 0;i < N;i++){
        char_in_time[i] = malloc(6);
        char_out_time[i] = malloc(6);
        if(!char_in_time[i] || !char_out_time[i]){
            for(int j = 0;j < i;j++){
                free(char_in_time[j]);
                free(char_out_time[j]);
            }
            free(char_in_time);
            free(char_out_time);
            return 1;
        }

        if(!scanf("%s",char_in_time[i]))   return 0;
        if(!scanf("%s",char_out_time[i]))  return 0;
    }

    int in_hour[N];
    int out_hour[N];
    int in_minute[N];
    int out_minute[N];
    for(int i = 0;i < N;i++){
        in_hour[i] = (char_in_time[i][0] - '0') * 10 + (char_in_time[i][1] - '0');
        out_hour[i] = (char_out_time[i][0] - '0') * 10 + (char_out_time[i][1] - '0');
        in_minute[i] = (char_in_time[i][3] - '0') * 10 + (char_in_time[i][4] - '0');
        out_minute[i] = (char_out_time[i][3] - '0') * 10 + (char_out_time[i][4] - '0');

        free(char_in_time[i]);
        free(char_out_time[i]);
    }
    free(char_in_time);
    free(char_out_time);

    int in_all_minute[N];
    int out_all_minute[N];
    for(int i = 0;i < N;i++){
        in_all_minute[i] = in_hour[i] * 60 + in_minute[i];
        out_all_minute[i] = out_hour[i] * 60 + out_minute[i];
    }

    int diff[N];
    for(int i = 0;i < N;i++){
        diff[i] = out_all_minute[i] - in_all_minute[i];
    }

    int all_minute = 0;
    for(int i = 0;i < N;i++)
        all_minute += diff[i];
    
    int hour = 0,minute = 0;
    hour = all_minute / 60;
    minute = all_minute % 60;
    printf("%d %d\n",hour,minute);
}