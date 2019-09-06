#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isinteger(char *str);

int parseint(char *str);

bool testSign(char *str);

int main(int argc, char *argv[]) {
    printf("%s \n", argv[2]);
    if (argc == 2){
        if (isinteger(argv[1])){
            int parsed = parseint(argv[1]);
            printf("%d \n", parsed);
            return 0;
        }
        else {
            printf("Error: Invalid input \n");
            return 1;
        }
    }
    else if (argc == 4){
        if (strchr(argv[2], '/')){
            if (strchr(argv[3], '0')){
                printf("Error: Divide by zero \n");
                return 1;
            }
        }
        else if (isinteger(argv[1]) && isinteger(argv[3])){
            if (strchr(argv[2], '+')){
                return 0;
            }
            else if (strchr(argv[2], '-')){
                return 0;
            }
            else if (strchr(argv[2], '/')){
                return 0;
            }
            else if (strchr(argv[2], 'x')){
                return 0;
            }
            else {
                printf("Error: Invalid operator \n");
                return 1;
            }
        }
        else {
            printf("Error: Invalid input \n");
            return 1;
        }
    }
    else if (argc <= 1 || argc == 3){
        printf("Error: Too few arguments \n");
        return 1;
    }
    else if (argc > 4){
        printf("Error: Too many arguments \n");
        return 1;
    }
}

bool isinteger(char *str){
    int i;
    if (testSign(str) == true){
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
    int i, a;
    int maxPow = 1;
    int len;
    int finalVal = 0;
    len = strlen(str);
    if (testSign(str) == true){
        for(i = 2; str[i] != '\0'; i++){ 
           maxPow = maxPow * 10;
        }
        a = len;
        while (a >= 2){
            a--;
            int location = len - a;
            int val = str[location] - '0';
            finalVal = finalVal + val * maxPow;
            maxPow = maxPow / 10;
        }
        finalVal = finalVal * -1;
    }
    else {
        for(i = 1; str[i] != '\0'; i++){ 
           maxPow = maxPow * 10;
        }
        a = len;
        while (a >= 1){
            a--;
            int location = len - a - 1;
            int val = str[location] - '0';
            finalVal = finalVal + val * maxPow;
            maxPow = maxPow / 10;
        }
    }
    return finalVal;
}

bool testSign(char *str){
    if (str[0] == '-'){
        return true;
    }
    else {
        return false;
    }
}
