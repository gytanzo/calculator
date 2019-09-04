#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isinteger(char *str);

int parseint(char *str);

int main(int argc, char *argv[]) {
    char *array="11231";
    printf("%d \n", isinteger(array));
    return 0;
}

bool isinteger(char *str){
    int i;
    if (str[0] == '-'){
        for(i = 1; str[i] != '\0'; i++){
            if (isdigit(str[i])){
                ;
            }
            else{
                return false;
            }
        }
    }
    else{
        for (i=0; str[i] != '\0'; i++){
            if (isdigit(str[i])){
                ;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int parseint(char *str){
    
}
