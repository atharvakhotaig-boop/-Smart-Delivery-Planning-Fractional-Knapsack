Smart Delivery Planning – Fractional Knapsack
A menu-driven C implementation of the Fractional Knapsack Problem using the Greedy Algorithm. The program calculates the value/weight ratio of each package, sorts packages by ratio, and selects complete or fractional packages to maximize total value within the vehicle's carrying capacity.
Features
- Enter package details
- Calculate Value/Weight ratios
- Sort packages by decreasing ratio
- Select complete packages whenever possible
- Select a fraction of a package when required
- Calculate maximum achievable value
- Display selected packages and total weight
- Menu-driven interface
- Input validation
Algorithm
The program follows the Greedy approach:
1. Calculate Value / Weight for every package.
2. Sort packages in decreasing order of the ratio.
3. Select the package with the highest ratio first.
4. Continue selecting complete packages while they fit.
5. If the next package cannot completely fit, select the required fraction.
6. Stop when the vehicle capacity is full.
Example
Package	Value	Weight	Ratio
1	40	5	8
2	30	10	3
3	50	5	10
4	20	4	5


Vehicle Capacity: 15
Sorted order:
Package 3 → Package 1 → Package 4 → Package 2
The algorithm selects Packages 3, 1, and 4 completely, then takes a fraction of Package 2.
Maximum Value = 113
Complexity
- Sorting: O(n²) using Selection Sort
- Greedy Selection: O(n)
- Overall Time Complexity: O(n²)
- Space Complexity: O(n)
Technologies Used
- Language: C
- Concept: Greedy Algorithm
- Problem: Fractional Knapsack
- Data Structures: Arrays and Structures
How to Run
GCC
gcc fractional_knapsack_pble.c -o fractional_knapsack
./fractional_knapsack

Windows
gcc fractional_knapsack_pble.c -o fractional_knapsack.exe
fractional_knapsack.exe

Menu
1. Enter Package Details
2. Display Package Details
3. Calculate Value/Weight Ratio
4. Sort Packages by Ratio
5. Find Maximum Value
6. Display Selected Packages
7. Exit

Project Objective
To demonstrate the application of the Greedy Method to solve the Fractional Knapsack problem and maximize the total value carried within a fixed vehicle capacity.
