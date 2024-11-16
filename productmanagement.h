#ifndef PRODUCTMANAGEMENT_H
#define PRODUCTMANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usermanagement.h"

#define TABLE_SIZE 100

typedef struct Product {
    int id;
    char name[50];
    float price;
    struct Product* next;
} Product;

typedef struct History {
    int productId;
    struct History* next;
} History;

typedef struct HashTable {
    Product* productTable[TABLE_SIZE];
    user* userTable[TABLE_SIZE];
} HashTable;

unsigned int hash(int id);
HashTable* createHashTable();
void addProduct(HashTable* hashTable, int id, const char* name, float price);
Product* getProduct(HashTable* hashTable, int id);
void updateProduct(HashTable* hashTable, int id, const char* name, float price);
void addUser(HashTable* hashTable, int id, const char* name);
user* getUser(HashTable* hashTable, int id);
void trackHistory(HashTable* hashTable, int userId, int productId);
void generateRecommendations(HashTable* hashTable, int userId);
void freeProductList(Product* product);
void freeHistory(History* history);
void freeUserList(user* user);
void freeHashTable(HashTable* hashTable);

#endif