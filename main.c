#include <stdio.h>
#include <stdlib.h>

// Function to distribute books among three partitions
// The three partitions represent the three employees
void distribute_books(int books[], int n, int partition1[], int *size1, int partition2[], int *size2, int partition3[], int *size3) {
    int sum1 = 0, sum2 = 0, sum3 = 0; // Initialize sums for each partition

    // Initialize sizes for each partition
    *size1 = 0;
    *size2 = 0;
    *size3 = 0;

    // Iterate over each book
    for (int i = 0; i < n; i++) {
        // Add the book to the partition with the smallest sum
        if (sum1 <= sum2 && sum1 <= sum3) {
            partition1[(*size1)++] = books[i];
            sum1 += books[i];
        } else if (sum2 <= sum1 && sum2 <= sum3) {
            partition2[(*size2)++] = books[i];
            sum2 += books[i];
        } else {
            partition3[(*size3)++] = books[i];
            sum3 += books[i];
        }
    }
}

int main() {
    // Example list of books with their page counts
    // Can always be changed to give different results
    int books[] = {100, 200, 300, 400, 500, 600, 700, 800, 900};
    int n = sizeof(books) / sizeof(books[0]); // Number of books

    // Handle edge case where there are no books
    if (n == 0) {
        printf("No books to distribute.\n");
        return 0;
    }

    // Allocate memory for the three partitions
    int *partition1 = malloc(n * sizeof(int));
    int *partition2 = malloc(n * sizeof(int));
    int *partition3 = malloc(n * sizeof(int));
    int size1, size2, size3; // Sizes of the partitions

    // Distribute the books among the partitions
    distribute_books(books, n, partition1, &size1, partition2, &size2, partition3, &size3);

    // Print the contents of partition 1
    printf("Partition 1: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", partition1[i]);
    }
    printf("\n");

    // Print the contents of partition 2
    printf("Partition 2: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", partition2[i]);
    }
    printf("\n");

    // Print the contents of partition 3
    printf("Partition 3: ");
    for (int i = 0; i < size3; i++) {
        printf("%d ", partition3[i]);
    }
    printf("\n");

    // Free the allocated memory for the partitions
    free(partition1);
    free(partition2);
    free(partition3);

    return 0;
}
