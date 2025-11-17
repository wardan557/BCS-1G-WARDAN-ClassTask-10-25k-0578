#include <stdio.h>
#include <string.h>
int main() {
    char *categories[3] = {"Appetizers", "Main Course", "Desserts"};
    char *items[3][3] = {
        {"Spring Rolls", "Garlic Bread", "Nachos"},
        {"Grilled Chicken", "Pasta Alfredo", "Veggie Burger"},
        {"Chocolate Cake", "Ice Cream Sundae", "Fruit Salad"}
    };
    float prices[3][3] = {
        {6.50, 4.00, 8.75},
        {14.99, 12.50, 9.50},
        {7.25, 5.50, 6.00}
    };
    printf("========== RESTAURANT MENU ==========\n\n");
    int i,j;
    for (i = 0; i < 3; i++) {
        printf("--- %s ---\n", categories[i]);
        for (j = 0; j < 3; j++) {
            printf("%-20s $ %.2f\n", items[i][j], prices[i][j]);
        }
        printf("\n");
    }
    printf("===== Budget-Friendly Items (Under $10) =====\n\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (prices[i][j] < 10.0) {
                printf("%-20s $ %.2f   (%s)\n", items[i][j], prices[i][j], categories[i]);
            }
        }
    }

    return 0;
}
