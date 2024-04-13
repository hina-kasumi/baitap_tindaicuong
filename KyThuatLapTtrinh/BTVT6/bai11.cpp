#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define endl printf("\n")
#define endll printf("\n\n")

char **ToArray (char *str){
    int n = strlen(str);
    
    char **arrString = (char**) malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
        *(arrString + i) = (char*) malloc(n * sizeof(char));;
    
    int soTu = 0;
    char *ptr = str;
    while (*ptr != '\0')
    {
        int i = ptr - str;
        int j = 0;
        while (str[i] != ' ' && str[i] != '\0')
        {
            arrString[soTu][j] = str[i];
            
            ptr = str + i;
            j ++;
            i ++;
            continue;
        }
        if (*ptr == ' ')
            soTu++;
        ptr++;
    }
    soTu++;
    

    for (int i = 0; i < soTu; i++)
    {
        printf("%s\n" , arrString[i]);
    }
    
}


int main()
{
    char str[100];
    printf("nhap xau: ");
    gets (str);

    ToArray(str);
    return 0;
}
