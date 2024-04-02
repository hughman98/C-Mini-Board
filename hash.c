#include "hash.h"

// This function takes a password and salt and returns a hash.
char* hash_function(char* password, int salt){
    char* hex = calloc(SHA256_HEX_SIZE, sizeof(char));

    char salted_pass[50];

    sprintf(salted_pass, "%d", salt);
    strcat(salted_pass, password);

    sha256_hex(salted_pass, strlen(salted_pass), hex);

    return hex;
}


// This functions takes a 8-character string containing a potential password as input.
// It evaluates whether or not that strin contains a number, an uppercase letter, and a lowercase letter.
// If the string contains all of those, it returns true. Otherwise, it returns false.

// TODO: Create a new function called check_reqs(). This function should be largely identical to check_reqs_fixed_size(), however it should take a string
// of any size as it's input. Furhtermore, it should return false if the potential password is less than 8 characters long, in addition to the other requirements.
// As an additional challenge, do not use any of the "string" functions such as strlen() when creating check_reqs().
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


// This function takes a pointer to an array of Users and a new integer, size, as input
// It dynamically reassigns the users array so that it has a new length.

// TODO: Implement this. Be sure that no exisitng User is erased while resizing the array.
void expand_users(User** users, int size){
    return;
} 

// This function takes a UserArray, name, and password as input.
// It updates the UserArray to add a new user with the provided name and password.
// It returns 0 if it is successful, and 1 if there is an error.

// TODO: There is a serious issue with this function that prevents it from working as intended. Identify and fix it. 
// This may require updating the functions arguments.
int add_user(UserArray arr, char* name, char* password){
    if (check_reqs(password)){
        if (arr.length == arr.max_length){
            arr.max_length += 1;
            expand_users(&arr.users, arr.max_length);
        }
        arr.users[arr.length].username = calloc(20, 1);
        strcpy(arr.users[arr.length].username, name);

        int salt = rand() % 1000;
        arr.users[arr.length].password.salt = salt;
        arr.users[arr.length].password.hash = hash_function(password, salt);

        arr.length++;
        return 0;
    }
    else return 1;
}


// This function should free all dynamically allocated memory within the UserArray.
// TODO: Implement this.
void free_users(UserArray* arr){
    return;
}

// This function should check if a username is present in the UserArray. If the user is present, and the provided password is correct, return true.
// Otherwise, return false.
// TODO: Implement this. Use the provided hash_function() function to compute the user's hash.
bool check_pass(UserArray* arr, char* username, char* password){
    return false;
}