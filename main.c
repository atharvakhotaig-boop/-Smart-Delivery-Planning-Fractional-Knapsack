/*
 * PBLE 1: Smart Delivery Planning - Fractional Knapsack
 * Subject: Analysis of Algorithms
 *
 * Greedy strategy:
 * 1. Calculate value/weight ratio for every package.
 * 2. Sort packages in decreasing order of ratio.
 * 3. Select complete packages while they fit.
 * 4. If the next package does not completely fit, select the required fraction.
 *
 * Time Complexity: O(n^2) using selection sort for n packages.
 * Space Complexity: O(n) for the package array.
 */

#include <stdio.h>

#define MAX 100

typedef struct {
    int id;
    float value;
    float weight;
    float ratio;
    float quantity;
} Package;

void enterDetails(Package p[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("\nPackage %d\n", p[i].id);

        do {
            printf("Enter value/profit: ");
            scanf("%f", &p[i].value);
            if (p[i].value < 0)
                printf("Value cannot be negative.\n");
        } while (p[i].value < 0);

        do {
            printf("Enter weight: ");
            scanf("%f", &p[i].weight);
            if (p[i].weight <= 0)
                printf("Weight must be greater than 0.\n");
        } while (p[i].weight <= 0);

        p[i].ratio = 0.0f;
        p[i].quantity = 0.0f;
    }
}

void displayDetails(Package p[], int n) {
    int i;

    printf("\n%-10s %-12s %-12s %-15s\n",
           "Package", "Value", "Weight", "Value/Weight");
    printf("----------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-12.2f %-12.2f %-15.2f\n",
               p[i].id, p[i].value, p[i].weight, p[i].ratio);
    }
}

void calculateRatios(Package p[], int n) {
    int i;

    for (i = 0; i < n; i++)
        p[i].ratio = p[i].value / p[i].weight;

    printf("\nValue/Weight ratios calculated successfully.\n");
}

void sortByRatio(Package p[], int n) {
    int i, j, maxIndex;
    Package temp;

    /* Selection sort: decreasing order of value/weight ratio */
    for (i = 0; i < n - 1; i++) {
        maxIndex = i;

        for (j = i + 1; j < n; j++) {
            if (p[j].ratio > p[maxIndex].ratio)
                maxIndex = j;
        }

        if (maxIndex != i) {
            temp = p[i];
            p[i] = p[maxIndex];
            p[maxIndex] = temp;
        }
    }

    printf("\nPackages sorted in decreasing order of Value/Weight ratio.\n");
}

float findMaximumValue(Package p[], int n, float capacity) {
    int i;
    float remaining = capacity;
    float totalValue = 0.0f;

    for (i = 0; i < n; i++)
        p[i].quantity = 0.0f;

    for (i = 0; i < n && remaining > 0.0f; i++) {
        if (p[i].weight <= remaining) {
            /* Complete package */
            p[i].quantity = 1.0f;
            remaining -= p[i].weight;
            totalValue += p[i].value;
        } else {
            /* Fractional package */
            p[i].quantity = remaining / p[i].weight;
            totalValue += p[i].value * p[i].quantity;
            remaining = 0.0f;
        }
    }

    return totalValue;
}

void displaySelectedPackages(Package p[], int n) {
    int i;
    float totalWeight = 0.0f;
    float totalValue = 0.0f;

    printf("\nSelected Packages\n");
    printf("%-10s %-12s %-12s %-15s\n",
           "Package", "Fraction", "Weight Used", "Value Gained");
    printf("------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        if (p[i].quantity > 0.0f) {
            float usedWeight = p[i].weight * p[i].quantity;
            float gainedValue = p[i].value * p[i].quantity;

            printf("%-10d %-12.2f %-12.2f %-15.2f\n",
                   p[i].id, p[i].quantity, usedWeight, gainedValue);

            totalWeight += usedWeight;
            totalValue += gainedValue;
        }
    }

    printf("------------------------------------------------------\n");
    printf("Total weight used : %.2f\n", totalWeight);
    printf("Maximum value     : %.2f\n", totalValue);
}

int main(void) {
    Package packages[MAX];
    int n = 0;
    int choice;
    float capacity = 0.0f;
    float maximumValue = 0.0f;
    int detailsEntered = 0;
    int ratiosCalculated = 0;
    int sorted = 0;
    int valueCalculated = 0;

    do {
        printf("\n========== SMART DELIVERY PLANNING ==========\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("\nEnter number of packages (1-%d): ", MAX);
                    scanf("%d", &n);
                    if (n < 1 || n > MAX)
                        printf("Please enter a valid number.\n");
                } while (n < 1 || n > MAX);

                do {
                    printf("Enter vehicle capacity: ");
                    scanf("%f", &capacity);
                    if (capacity <= 0)
                        printf("Capacity must be greater than 0.\n");
                } while (capacity <= 0);

                enterDetails(packages, n);
                detailsEntered = 1;
                ratiosCalculated = 0;
                sorted = 0;
                valueCalculated = 0;
                printf("\nPackage details entered successfully.\n");
                break;

            case 2:
                if (!detailsEntered) {
                    printf("\nPlease enter package details first.\n");
                } else {
                    displayDetails(packages, n);
                    printf("Vehicle capacity: %.2f\n", capacity);
                }
                break;

            case 3:
                if (!detailsEntered) {
                    printf("\nPlease enter package details first.\n");
                } else {
                    calculateRatios(packages, n);
                    ratiosCalculated = 1;
                }
                break;

            case 4:
                if (!detailsEntered) {
                    printf("\nPlease enter package details first.\n");
                } else {
                    if (!ratiosCalculated)
                        calculateRatios(packages, n);

                    sortByRatio(packages, n);
                    sorted = 1;
                }
                break;

            case 5:
                if (!detailsEntered) {
                    printf("\nPlease enter package details first.\n");
                } else {
                    if (!ratiosCalculated)
                        calculateRatios(packages, n);

                    if (!sorted)
                        sortByRatio(packages, n);

                    maximumValue = findMaximumValue(packages, n, capacity);
                    valueCalculated = 1;

                    printf("\nMaximum achievable value = %.2f\n", maximumValue);
                }
                break;

            case 6:
                if (!valueCalculated) {
                    printf("\nPlease calculate the maximum value first.\n");
                } else {
                    displaySelectedPackages(packages, n);
                }
                break;

            case 7:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
