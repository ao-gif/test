#include <stdio.h>

int main(void)
{
    int N;
    if(!scanf("%d",&N))
        return 0;
    char sort[N];
    for(int i = 0;i < N;i++){
        if(!scanf(" %c",&sort[i]))
            return 0;
    }
    int count = 0;
    int index;
    for(int i = 0;i < N;i++){
        index = 0;
        for(int j = 0;j < i;j++){
            if(sort[i] == sort[j])
                index = 1;
        }
        if(index == 0)
            count++;
    }
    printf("%d\n",count);
    return 0;
}