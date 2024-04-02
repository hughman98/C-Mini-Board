#include "sha256.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Salted_Hash {
    char* hash;
    int salt;
} Salted_Hash;

typedef struct User {
    Salted_Hash password;
    char* username;
} User;

typedef struct UserArray {
    User* users;
    int length;
    int max_length;
} UserArray;


void expand_users(User** users, int size); 

bool check_reqs_fixed_size(char* pass); 


int add_user(UserArray arr, char* name, char* password);

char * hash_function(char* password, int salt); 

bool check_pass(UserArray* arr, char* username, char* password); 

void free_users(UserArray* arr);

