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

int prod_id(int prod_id) {
    return prod_id % HASH;
}

void add_user_to_recommendation(USER* users, int id,  char* name, const char* email)
 {
    users[id].user_id = id;
    strcpy(users[id].name, name);
    strcpy(users[id].email, email);
    users[id].interact = NULL;
}
PROD* get(PRM* mgr, int product_id) 
{
    int index = prod_id(product_id);
    PROD* cur = mgr->products[index];
    while (cur) {
        if (cur->prod_id == product_id)
            return cur;
        cur = cur->next;
    }
    return NULL;
}
void add(PRM* mgr, int product_id, const char* name, const char* category, float price)
 {
    int index = prod_id(product_id);
    PROD* new_prod = malloc(sizeof(PROD));
    new_prod->prod_id = product_id;
    strcpy(new_prod->name, name);
    strcpy(new_prod->category, category);
    new_prod->price = price;
    new_prod->next = mgr->products[index];
    mgr->products[index] = new_prod;
}
void record(USER* users, int user_id, int product_id, char action) 
{
    PR* newint = malloc(sizeof(PR));
    newint->prod_id = product_id;
    newint->action = action;
    newint->next = users[user_id].interact;
    users[user_id].interact = newint;
}

void recommend(USER* users, int user_id, PRM* mgr) {
    PR* active = users[user_id].interact;

    printf("Recommendations %d:\n", user_id);

    char viewed[HASH][50];
    int count = 0;

    while (active) {
        if (active->action == 'b') {
            PROD* product = get(mgr, active->prod_id);
            if (product) {
                strcpy(viewed[count++], product->category);
            }
        }
        active = active->next;
    }

    for (int i = 0; i < count; i++)
     {
        for (int j = 0; j < HASH; j++) 
        {
            PROD* product = mgr->products[j];
            while (product) {
                if (strcmp(product->category, viewed[i]) == 0) {
                    printf("Recommended Product: %s (ID: %d, Category: %s, Price: %.2f)\n",
                           product->name, product->prod_id, product->category, product->price);
                }
                product = product->next;
            }
        }
    }
}

// int main() 
// {
//     PRM mgr = {0};
//     USER users[MAX] = {0};
//     int choice, user_id, product_id;
//     char name[50], category[50], email[50], action;
//     float price;

//     while (1) 
//     {
//         printf("ENTER A CHOICE\n");
//         printf("1. Add User\n");
//         printf("2. Add Product\n");
//         printf("3. Record activity\n");
//         printf("4. Recommend Products\n");
//         printf("5. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) 
//         {
//             case 1:
//                 printf("Enter user ID: ");
//                 scanf("%d", &user_id);
//                 printf("Enter user name: ");
//                 scanf(" %[^\n]s", name);
//                 printf("Enter user email: ");
//                 scanf(" %[^\n]s", email);
//                 add_user(users, user_id, name, email);
//                 break;

//             case 2:
//                 printf("Enter product ID: ");
//                 scanf("%d", &product_id);
//                 printf("Enter product name: ");
//                 scanf(" %[^\n]s", name);
//                 printf("Enter product category: ");
//                 scanf(" %[^\n]s", category);
//                 printf("Enter product price: ");
//                 scanf("%f", &price);
//                 add(&mgr, product_id, name, category, price);
//                 break;

//             case 3:
//                 printf("Enter user ID: ");
//                 scanf("%d", &user_id);
//                 printf("Enter product ID: ");
//                 scanf("%d", &product_id);
//                 record(users, user_id, product_id, action);
//                 break;

//             case 4:
//                 printf("Enter user ID for recommendations: ");
//                 scanf("%d", &user_id);
//                 recommend(users, user_id, &mgr);
//                 break;

//             case 5:
//                 printf("Exit\n");
//                 return 0;

//             default:
//                 printf("Invalid choice\n");
//         }
//     }
// }