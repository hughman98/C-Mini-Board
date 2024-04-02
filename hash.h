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


void expand_users(User** users, int size); //covers double pointers and dynamic memory

bool check_reqs_fixed_size(char* pass); // Checks Password requirments (e.g. correct length, contains a number)
                                  // User needs to impliment a version
                                  // of this that is not fixed length.
                                  // Covers Null bytes for strings, and function prototyping

// Initial version does not contain Users, and the test taker
// is expected to edit the function so that a pointer is passed, and access it's member with '->'
// Tester should also explain why passing a pointer is necessary, e.g. what happens on the heap when a function is called.
// Also, make the new user structs not be dynamically allocated at first.
// checks '->' vs '.' and call stack stuff.
int add_user(UserArray* arr, char* name, char* password);

char * hash_function(char* password, int salt); // Not to be implemented by tester

bool check_pass(UserArray* arr, char* username, char* password); // Maybe the user should impliment this? It should be pretty straightforward.

void free_users(UserArray* arr);

