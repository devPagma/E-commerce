# E-commerce Platform with Recommendation System

## Overview

This project implements an e-commerce platform with a robust recommendation system. The goal is to suggest products to users based on their browsing and purchase history, thereby enhancing the user experience and promoting relevant products. The system efficiently handles large amounts of data and provides personalized recommendations.

## Requirements

- Personalized product recommendations based on user browsing and purchase history.
- Provide relevant product suggestions.
- Use at least two different data structures, including at least one non-linear data structure.

## Data Structures Used

- **Hash Tables**: For fast lookups of user and product data.
- **Graphs**: For managing the recommendation logic and relationships between products and users.

## System Components

1. **User Management**: Handle user registration, login, and profile management.
2. **Product Management**: Manage product information, categories, and inventory.
3. **Browsing History Tracker**: Track and store user browsing history.
4. **Purchase History Tracker**: Track and store user purchase history.
5. **Recommendation Engine**: Analyze browsing and purchase data to generate personalized recommendations.

## Operations Supported

- **Add User**: Register a new user.
- **Add Product**: Add a new product to the catalog.
- **Track Browsing History**: Record user interactions with products.
- **Track Purchase History**: Record user purchases.
- **Generate Recommendations**: Suggest products to users based on their history.
- **Retrieve User Data**: Access user data for personalized experiences.
- **Retrieve Product Data**: Access product data for displaying recommendations.

## Development Plan

### User Management

**Data Structure**: Hash Table

**Operations**:
- Add user
- Retrieve user information
- Update user information

### Product Management

**Data Structure**: Hash Table

**Operations**:
- Add product
- Retrieve product information
- Update product information

### Browsing and Purchase History Tracking

**Data Structure**: Graph

**Operations**:
- Record browsing history
- Record purchase history
- Retrieve history for analysis

### Recommendation Engine

**Data Structure**: Graph

**Operations**:
- Analyze user data to identify patterns
- Generate personalized recommendations based on identified patterns

## Implementation

### User Management Module

- Implement a hash table to store user data.
- Provide functions for adding, retrieving, and updating user information.

### Browsing and Purchase History Module

- Implement a graph to track user interactions with products.
- Record each browsing and purchase event in the data structure.
- Provide functions to retrieve and analyze the history data.

### Recommendation Engine

- Implement algorithms to analyze the browsing and purchase history data.
- Use the graph structure to identify patterns and relationships between users and products.
- Generate a list of recommended products for each user based on the analysis.

## Language Used

The implementation is done in **C**.

## How to Run

1. Compile the code using a C compiler:
   ``` 
   gcc -o ecommerce ecommerce.c
   ``` 
2. Run the executable:
   ```
   ./ecommerce
   ```
## Files
  ecommerce.c: Main implementation file containing all the modules and functions.

## Authors
  Amogh Sunil @devPagma 

## License
  This project is licensed under the MIT License - see the LICENSE file for details.
