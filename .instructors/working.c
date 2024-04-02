#include "hash.h"

char * hash_function(char* password, int salt){
    char * hex = calloc(SHA256_HEX_SIZE, sizeof(char));

    char salted_pass[50];

    sprintf(salted_pass, "%d", salt);
    strcat(salted_pass, password);

    sha256_hex(salted_pass, strlen(salted_pass), hex);

    return hex;
}

// Checks Password requirments (e.g. correct length, contains a number)
// User needs to impliment a versionof this that is not fixed length.
// Covers Null bytes for strings, and function prototyping
bool check_reqs_fixed_size(char* pass){
    bool has_number = false;
    bool has_upper = false;
    bool has_lower = false;

    for (int i=0; i<8; i++){
        if (65 <= pass[i] && pass[i] <= 90){
            has_upper = true;
        }
        else if (48 <= pass[i] && pass[i] <= 57){
            has_number = true;
        }
        else if (97 <= pass[i] && pass[i] <= 122){
            has_lower = true;
        }
    }

    return (has_number && has_upper && has_lower);
}

bool check_reqs(char* pass){
    bool has_number = false;
    bool has_upper = false;
    bool has_lower = false;

    int i = 0;

    while (true){
        if (pass[i] == 0){
            break;
        }

        if (65 <= pass[i] && pass[i] <= 90){
            has_upper = true;
        }
        else if (48 <= pass[i] && pass[i] <= 57){
            has_number = true;
        }
        else if (97 <= pass[i] && pass[i] <= 122){
            has_lower = true;
        }

        i += 1;
    }

    return (has_number && has_upper && has_lower && i >= 8);
}


// Covers double pointers and dynamic memory
// This one should be implemented by the student
void expand_users(User** users, int size){
    *users = realloc(*users, sizeof(User)*size);
} 

// Initial version does not use a pointer, and the test taker
// is expected to edit the function so that a pointer is passed, and access it's member with '->'
// Tester should also explain why passing a pointer is necessary, e.g. what happens on the heap when a function is called.
// Also, make the new user structs not be dynamically allocated at first.
// checks '->' vs '.' and call stack stuff.
int add_user(UserArray* arr, char* name, char* password){
    if (check_reqs(password)){
        if (arr->length == arr->max_length){
            arr->max_length += 1;
            expand_users(&arr->users, arr->max_length);
        }
        arr->users[arr->length].username = calloc(20, 1);
        strcpy(arr->users[arr->length].username, name);

        int salt = rand() % 1000;
        arr->users[arr->length].password.salt = salt;
        arr->users[arr->length].password.hash = hash_function(password, salt);

        arr->length++;
        return 0;
    }
    else return 1;
}

void free_users(UserArray* arr){
    for (int i=0; i<arr->length; i++){
        free(arr->users[i].username);
        free(arr->users[i].password.hash);
    }

    free(arr->users);
}

bool check_pass(UserArray* arr, char* username, char* password){
    for (int i=0; i < arr->length; i++){
        if (strcmp(username, arr->users[i].username) == 0){
            char * test_hash = hash_function(password, arr->users[i].password.salt);
            int result = strcmp(test_hash, arr->users[i].password.hash);
            free(test_hash);
            if (result == 0){
                return true;
            }
            else{
                return false;
            }
                
        }
    }
    return false;
}