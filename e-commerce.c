#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usermanagement.h"
#include "productmanagement.h"
#include "browse-purchase.h"
#include "recommendation.h"

int main(){
    HashTable* hashTable = createHashTable();

    int choice;
    while(1)
    {
        printf("1. Add User\n");
        printf("2. Display User Details\n");
        printf("3. Add Product\n");
        printf("4. Display Product Details\n");
        printf("5. Update Product\n");
        printf("6. Track Browsing/Purchase History\n");
        printf("7. Generate Recommendations\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int id, userId, productId;
        char name[50], email[50];
        float price;

        switch (choice) {
            case 1: // Add User
                printf("Enter User ID: ");
                scanf("%d", &id);
                printf("Enter User Name: ");
                scanf("%49s", name);
                addUser(hashTable, id, name);
                printf("User added successfully.\n");
                break;

            case 2: // Display User Details
                printf("Enter User ID: ");
                scanf("%d", &id);
                user* user = getUser(hashTable, id);
                if (user) {
                    printf("User ID: %d\nName: %s\n", user->id, user->name);
                    printf("Browsing History:\n");
                    History* history = user->history;
                    while (history) {
                        printf("  - Product ID: %d\n", history->productId);
                        history = history->next;
                    }
                } else {
                    printf("User not found.\n");
                }
                break;

            case 3: // Add Product
                printf("Enter Product ID: ");
                scanf("%d", &id);
                printf("Enter Product Name: ");
                scanf("%49s", name);
                printf("Enter Product Price: ");
                scanf("%f", &price);
                addProduct(hashTable, id, name, price);
                printf("Product added successfully.\n");
                break;

            case 4: // Display Product Details
                printf("Enter Product ID: ");
                scanf("%d", &id);
                Product* product = getProduct(hashTable, id);
                if (product) {
                    printf("Product ID: %d\nName: %s\nPrice: %.2f\n", product->id, product->name, product->price);
                } else {
                    printf("Product not found.\n");
                }
                break;

            case 5: // Update Product
                printf("Enter Product ID to update: ");
                scanf("%d", &id);
                printf("Enter New Product Name: ");
                scanf("%49s", name);
                printf("Enter New Product Price: ");
                scanf("%f", &price);
                updateProduct(hashTable, id, name, price);
                printf("Product updated successfully.\n");
                break;

            case 6: // Track Browsing/Purchase History
                printf("Enter User ID: ");
                scanf("%d", &userId);
                printf("Enter Product ID: ");
                scanf("%d", &productId);
                trackHistory(hashTable, userId, productId);
                printf("History tracked successfully.\n");
                break;

            case 7: // Generate Recommendations
                printf("Enter User ID for Recommendations: ");
                scanf("%d", &userId);
                generateRecommendations(hashTable, userId);
                break;

            case 8: // Exit
                printf("Exiting program. Goodbye!\n");
                freeHashTable(hashTable);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
