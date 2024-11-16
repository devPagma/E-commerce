#ifndef BROWSE_PURCHASE_H
#define BROWSE_PURCHASE_H

#include<stdio.h>
#include<stdlib.h>

#define MAX_USERS 100
#define MAX_PRODUCTS 100

typedef struct graph
{
    int user;
    int product;
    int flag;
    char action; 
    struct UI* link;
} UI;

void browsing(UI* a[], int user_id, int product_id);
void purchacing(UI* a[], int user_id, int product_id, char login);
void display(UI* a[], int id);

#endif