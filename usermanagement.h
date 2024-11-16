#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct User {
    int id;
    char name[50];
    char email[50];
    char password[50];
    struct User *next;
    struct History *history;
} user;

typedef struct {
    user *user_table[MAX];
    int login_check;
} user_hashtable;

int hash_func(int id);
void init_user_table(user_hashtable *hashTable);
void add_user(user_hashtable *hashTable, int id, char *name, char *email, char *password);
user* get_user(user_hashtable *hashTable, int id);
void update_user(user_hashtable *hashTable, int id, char *newName, char *newEmail);
void show_user(user_hashtable *hashTable, int id);
void sign_up(user_hashtable *hashTable, int id, char *name, char *email, char *password);
user* login(user_hashtable *hashTable, int id, char *password);
void logout(user_hashtable *hashTable, user **loggedInUser);

#endif