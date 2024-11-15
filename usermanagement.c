#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//USER SRUCTURE
typedef struct User{
    int id;
    char name[50];
    char email[50];
    char password[50];
    struct User *next;
}user;

//HASHTABLE STRUCTURE
typedef struct{
    user *user_table[MAX];
    int login_check;
}user_hashtable;

//HASH FUNCTION
int hash_func(int id){
    return id%MAX;
}

//INITIALIZING HASHTABLE
void init_user_table(user_hashtable *hashTable){
    for(int i=0; i<MAX; i++)
    {
        hashTable->user_table[i]=NULL;
    }
}

//FUNCTION TO ADD USER
void add_user(user_hashtable *hashTable, int id, char *name, char *email, char *password){
    int index=hash_func(id);
    user *newUser=(user*)malloc(sizeof(user));
    newUser->id=id;
    strcpy(newUser->name, name);
    strcpy(newUser->email, email);
    strcpy(newUser->password, password);
    newUser->next=hashTable->user_table[index];
    hashTable->user_table[index]=newUser;
    printf("User successfully added!\n\n");
}

//FUNCTION TO RETRIEVE USER DETAILS
user* get_user(user_hashtable *hashTable, int id){
    int index=hash_func(id);
    user *temp=hashTable->user_table[index];
    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

//FUNCTION TO UPDATE USERNAME AND USER EMAIL
void update_user(user_hashtable *hashTable, int id, char *newName, char *newEmail){
    user *cur=get_user(hashTable, id);
    if(cur!=NULL)
    {
        strcpy(cur->email, newEmail);
        strcpy(cur->name, newName);
        printf("User details successfully updated!\n\n");
    }
    else
    {
        printf("User not found!\n\n");
    }
}

//FUNCTION TO SHOW USER DETAILS
void show_user(user_hashtable *hashTable, int id){
    user *cur=get_user(hashTable, id);
    if(cur!=NULL)
    {
        printf("Username: %s\nUser email: %s\n\n",cur->name, cur->email);
    }
    else
    {
        printf("User not found!\n\n");
    }
}

//USER SIGN-UP FUNCTION
void sign_up(user_hashtable *hashTable, int id, char *name, char *email, char *password){
    if(get_user(hashTable, id)!=NULL)
    {
        printf("UserID already exists!\n\n");
        return;
    }
    add_user(hashTable, id, name, email, password);
}

//USER LOGIN FUNCTION
user* login(user_hashtable *hashTable, int id, char *password){
    user *cur=get_user(hashTable, id);
    if(cur!=NULL && strcmp(cur->password, password)==0)
    {
        printf("Login successful! Welcome, %s\n\n", cur->name);
        hashTable->login_check=1;
        return cur;
    }
    else
    {
        printf("Invalid userID or password!\n\n");
        return NULL;
    }
}

//USER LOGOUT FUNCTION
void logout(user_hashtable *hashTable, user **loggedInUser){
    if(*loggedInUser!=NULL)
    {
        printf("User %s is logged out!\n\n", (*loggedInUser)->name);
        hashTable->login_check=0;
        *loggedInUser=NULL;
    }
    else
    {
        printf("No user is currently logged in.\n\n");
    }
}

int main(){
    user_hashtable hashTable;
    init_user_table(&hashTable);
    hashTable.login_check=0;
    user *loggedInUser=NULL;
    int choice, id;
    char name[50], email[50], password[50];

    while (1) {
        printf("========== User Management System ==========\n");
        printf("1.Add User\n");
        printf("2.Login\n");
        printf("3.Show User Details\n");
        printf("4.Update User\n");
        printf("5.Logout\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter User ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Email: ");
                scanf("%s", email);
                printf("Enter Password: ");
                scanf("%s", password);
                sign_up(&hashTable, id, name, email, password);
                break;

            case 2:
                if(hashTable.login_check == 1)
                {
                    printf("A user is already logged in. Logout first.\n\n");
                    break;
                }
                printf("Enter User ID: ");
                scanf("%d", &id);
                printf("Enter Password: ");
                scanf("%s", password);
                loggedInUser=login(&hashTable, id, password);
                break;

            case 3:
                printf("Enter User ID to view details: ");
                scanf("%d", &id);
                show_user(&hashTable, id);
                break;

            case 4:
                if (hashTable.login_check == 0)
                {
                    printf("Please log in to update details.\n\n");
                    break;
                }
                printf("Enter User ID to update: ");
                scanf("%d", &id);
                printf("Enter New Name: ");
                scanf("%s", name);
                printf("Enter New Email: ");
                scanf("%s", email);
                update_user(&hashTable, id, name, email);
                break;

            case 5:
                logout(&hashTable, &loggedInUser);
                break;

            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}
