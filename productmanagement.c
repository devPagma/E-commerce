#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Product {
    int id;
    char name[50];
    float price;
    struct Product* next;
} Product;

typedef struct User {
    int id;
    char name[50];
    char email[50];
    struct User* next;
    struct History* history;
} User;

typedef struct History {
    int productId;
    struct History* next;
} History;

typedef struct HashTable {
    Product* productTable[TABLE_SIZE];
    User* userTable[TABLE_SIZE];
} HashTable;

// Hash function
unsigned int hash(int id) {
    return id % TABLE_SIZE;
}

// Initialize hash table
HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->productTable[i] = NULL;
        hashTable->userTable[i] = NULL;
    }
    return hashTable;
}

// Add product
void addProduct(HashTable* hashTable, int id, const char* name, float price) {
    unsigned int index = hash(id);
    Product* newProduct = (Product*)malloc(sizeof(Product));
    newProduct->id = id;
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->next = hashTable->productTable[index];
    hashTable->productTable[index] = newProduct;
}

// Retrieve product information
Product* getProduct(HashTable* hashTable, int id) {
    unsigned int index = hash(id);
    Product* product = hashTable->productTable[index];
    while (product != NULL && product->id != id) {
        product = product->next;
    }
    return product;
}

// Update product information
void updateProduct(HashTable* hashTable, int id, const char* name, float price) {
    Product* product = getProduct(hashTable, id);
    if (product != NULL) {
        strcpy(product->name, name);
        product->price = price;
    }
}

// Add user
void addUser(HashTable* hashTable, int id, const char* name) {
    unsigned int index = hash(id);
    User* newUser = (User*)malloc(sizeof(User));
    newUser->id = id;
    strcpy(newUser->name, name);
    newUser->next = hashTable->userTable[index];
    newUser->history = NULL;
    hashTable->userTable[index] = newUser;
}

// Retrieve user information
User* getUser(HashTable* hashTable, int id) {
    unsigned int index = hash(id);
    User* user = hashTable->userTable[index];
    while (user != NULL && user->id != id) {
        user = user->next;
    }
    return user;
}

// Track browsing and purchase history
void trackHistory(HashTable* hashTable, int userId, int productId) {
    User* user = getUser(hashTable, userId);
    if (user != NULL) {
        History* newHistory = (History*)malloc(sizeof(History));
        newHistory->productId = productId;
        newHistory->next = user->history;
        user->history = newHistory;
    }
}

// Generate recommendations based on user history
void generateRecommendations(HashTable* hashTable, int userId) {
    User* user = getUser(hashTable, userId);
    if (user != NULL) {
        printf("Recommendations for user %s:\n", user->name);
        History* history = user->history;
        while (history != NULL) {
            Product* product = getProduct(hashTable, history->productId);
            if (product != NULL) {
                printf("Product ID: %d, Name: %s, Price: %.2f\n", product->id, product->name, product->price);
            }
            history = history->next;
        }
    }
}

// Free product list
void freeProductList(Product* product) {
    while (product != NULL) {
        Product* temp = product;
        product = product->next;
        free(temp);
    }
}

// Free user history
void freeHistory(History* history) {
    while (history != NULL) {
        History* temp = history;
        history = history->next;
        free(temp);
    }
}

// Free user list
void freeUserList(User* user) {
    while (user != NULL) {
        User* temp = user;
        freeHistory(user->history);
        user = user->next;
        free(temp);
    }
}

// Free hash table
void freeHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        freeProductList(hashTable->productTable[i]);
        freeUserList(hashTable->userTable[i]);
    }
    free(hashTable);
}

// int main() {
//     HashTable* hashTable = createHashTable();

//     addProduct(hashTable, 101, "Laptop", 999.99);
//     addProduct(hashTable, 102, "Smartphone", 499.99);
//     addProduct(hashTable, 103, "Headphones", 79.99);
//     addProduct(hashTable, 104, "Keyboard", 29.99);

//     addUser(hashTable, 1, "Alice");
//     addUser(hashTable, 2, "Bob");

//     trackHistory(hashTable, 1, 101);
//     trackHistory(hashTable, 1, 103);
//     trackHistory(hashTable, 2, 102);
//     trackHistory(hashTable, 2, 104);

//     printf("=== Recommendations ===\n");
//     generateRecommendations(hashTable, 1);
//     printf("\n");
//     generateRecommendations(hashTable, 2);

//     freeHashTable(hashTable);

//     return 0;
// }