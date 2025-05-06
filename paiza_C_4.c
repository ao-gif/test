#include <stdio.h>

int main(void)
{
    int N;
    if(!scanf("%d",&N)) return 1;
    int ball[N];
    for(int i = 0;i < N;i++)
        if(!scanf("%d",&ball[i]))   return 1;
    int M;
    if(!scanf("%d",&M)) return 1;
    int giver[M];
    int taker[M];
    int take_ball[M];
    for(int i = 0;i < M;i++){
        if(!scanf("%d",&giver[i]))  return 1;
        if(!scanf("%d",&taker[i]))  return 1;
        if(!scanf("%d",&take_ball[i]))  return 1;

        if(ball[giver[i] - 1] >= take_ball[i]){
            ball[giver[i] - 1] -= take_ball[i];
            ball[taker[i] - 1] += take_ball[i];
        }else{
            ball[taker[i] - 1] += ball[giver[i] - 1];
            ball[giver[i] - 1] = 0;
        }

        // for(int i = 0;i < N;i++)
        //     printf("%d ",ball[i]);
        // printf("\n");

    }

    for(int i = 0;i < N;i++)
        printf("%d\n",ball[i]);

    return 0;

}