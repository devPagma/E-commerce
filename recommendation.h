#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH 100
#define MAX 100

typedef struct prod {
    int prod_id;
    char name[50];
    char category[50];
    float price;
    struct prod* next;
} PROD;

typedef struct pr {
    int prod_id;
    char action;
    struct pr* next;
} PR;

typedef struct user {
    int user_id;
    char name[50];
    char email[50];
    PR* interact;
} USER;

typedef struct {
    PROD* products[HASH];
} PRM;

int prod_id(int prod_id);
void add_user_to_recommendation(USER* users, int id,  char* name, const char* email);
PROD* get(PRM* mgr, int product_id);
void add(PRM* mgr, int product_id, const char* name, const char* category, float price);
void record(USER* users, int user_id, int product_id, char action);
void recommend(USER* users, int user_id, PRM* mgr);

#endif