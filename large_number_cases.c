#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate non-trivial input data
void generate_input_data(int num_datasets, int max_books[], int max_pages) {
    srand(time(0));
    for (int i = 0; i < num_datasets; i++) {
        int num_books = max_books[i];
        printf("Data Set %d: ", i + 1);
        for (int j = 0; j < num_books; j++) {
            int pages = rand() % max_pages + 1;
            printf("%d ", pages);
        }
        printf("\n");
    }
}

int main() {
    int num_datasets = 10;
    int max_books[] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000, 100000000}; // Varying lengths
    int max_pages = 1000; // Maximum number of pages for a book
    generate_input_data(num_datasets, max_books, max_pages);
    return 0;
}
