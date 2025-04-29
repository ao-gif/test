#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ft_change_int(char *str,int num)
{
    int *name_int;
    name_int = (int *)malloc(sizeof(int) * num);
    if(!name_int)
        return 0;
    int i = 0;
    while(*str){
        name_int[i] = *str - ('a' - 1);
        str++;
        i++;
    }
    return name_int;
}

char *ft_concatenation(char *s1,char *s2,int num)
{
    char *name;
    name = (char *)malloc(sizeof(char) * num);
    int i = 0;
    while(*s1){
        name[i] = *s1;
        i++;
        s1++;
    }
    while(*s2){
        name[i] = *s2;
        i++;
        s2++;
    }
    return name;
}

int ft_sum_arr(int *name_int,int name_count)
{
    int *tmp = name_int;
    for(int i = name_count;i > 0;i--){
        int arr[i - 1];
        for(int j = 0;j < i - 1;j++){
            arr[j] = tmp[j] + tmp[j + 1];
            if(arr[j] > 101)
                arr[j] -= 101;
        }
        for(int j = 0;j < i - 1;j++)
            tmp[j] = arr[j];
    }
    return *tmp;
}

int main(void)
{
    char name1[1000];
    char name2[1000];
    if(!scanf("%s %s",name1,name2))
        return 0;
    int name1_count = strlen(name1);
    int name2_count = strlen(name2);
    int name_count = name1_count + name2_count;
    char *str1_name = ft_concatenation(name1,name2,name_count);
    char *str2_name = ft_concatenation(name2,name1,name_count);

    int *name_int = ft_change_int(str1_name,name_count);
    int result1 = ft_sum_arr(name_int,name_count);

    name_int = ft_change_int(str2_name,name_count);
    int result2 = ft_sum_arr(name_int,name_count);

    if(result1 > result2)
        printf("%d\n",result1);
    else
        printf("%d\n",result2);

}