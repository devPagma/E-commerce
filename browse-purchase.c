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

void browsing(UI* a[], int user_id, int product_id) 
{
    UI* temp = malloc(sizeof(UI));
    temp->user = user_id;
    temp->product = product_id;
    temp->action = 'b';  
    temp->flag=0;
    temp->link = a[user_id];
    a[user_id] = temp;
}
void purchacing(UI* a[], int user_id, int product_id, char login) 
{
    UI* temp = malloc(sizeof(UI));
    if(login=='y')
        temp->flag=1;
    else
        temp->flag=0;
    temp->user = user_id;
    temp->product = product_id;
    temp->action = 'p'; 
    temp->link = a[user_id];
    a[user_id] = temp;
}
void display(UI* a[], int id) 
{
    UI* cur = a[id];
    while (cur != NULL) 
    {
        if(cur->action=='b')
            printf("User browsed product '%d'\n", cur->product);
        else if(cur->action=='p' && cur->flag==1)
            printf("User purchased product '%d'\n", cur->product);
        cur = cur->link;
    }
}

int main() 
{
    UI* a[MAX_USERS] = {0};  
    int ui, pi;
    char c, login;
    while(1)
    {
        printf("1. Record browsing\n2. Record a purchase\n3. Display user history\n");
        scanf("%d", &c);
        switch(c)
        {
            case 1: printf("Enter the User ID and the Product ID - Browse: ");
                scanf("%d %d", &ui, &pi);
                browsing(a, ui, pi);
                break;
            case 2: printf("Enter the User ID, Product ID and login(y/n) - Purchase: ");
                scanf("%d %d %c", &ui, &pi, &login);
                purchacing(a, ui, pi, login);
                break;
            case 3: printf("The User Id to check User History: ");
                scanf("%d", &ui);
                printf("-----------------\nUser History: \n");
                display(a, ui);
        }
    }
    return 0;
}