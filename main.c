#include "hash.h"
#include <string.h>

#define MAX_FILE_PATH 256

int main() {
    UserArray arr;
    arr.users = malloc(sizeof(User)); // Allocate memory for 1 user. We keep this small so that we can test the expand_user function
    arr.length = 0;
    arr.max_length = 1;

    if (add_user(&arr, "bob", "P4ssword") != 0){
        printf("Adding user failed!\n");
    }

    add_user(&arr, "bob2", "P4ssword");
    add_user(&arr, "bob3", "P4ssword");
    add_user(&arr, "bob4", "P4ssword12");

    if (add_user(&arr, "bob5", "P4ss") != 1){
        printf("User added with too short password!\n");
    }

    if (arr.length != 4 && arr.max_length != 5){
        printf("Incorrect length in array!\n");
    }

    if (check_pass("bob4", "NotCorrect")){
        printf("Incorrect Password Accepted!\n");
    }

    if (!check_pass("bob4", "P4ssword12")){
        printf("Correct Password Not Accepted!\n");
    }

    free_users(&arr);

    return 0;


}