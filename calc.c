#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isinteger(char *str);

int parseint(char *str);

int main(int argc, char *argv[]) {
    char array[100]="-2147483647";

    printf("%d \n", isinteger(array));
    return 0;
}

bool isinteger(char *str){
    if (str[0] == '-')
        
    else
        
}
