#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <windows.h>

#define NUM_RUNS 10 
#define ARRAY_SIZE 1000000

//funciones externas
extern void asm_function(int* arr, int left, int right);
extern int partition(int* arr, int left, int right);

void quicksort(int* arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right); //partition the array and get piivot index
        quicksort(arr, left, pivot - 1); //sort left partition
        quicksort(arr, pivot + 1, right); //sort right partition
    }
}

// arrange elements around a pivot
int partition(int* arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1; 
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //swap the pivot element with the element at i + 1
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return i + 1;
}

int is_sorted(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            return 0;
        }
    }
    return 1;
}

void copy_array(int* src, int* dest, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Function to get current time in seconds using Windows API
double get_time() {
    LARGE_INTEGER frequency, time;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&time);
    return (double)time.QuadPart / (double)frequency.QuadPart;
}

int main() {
    srand(time(NULL));
    int n = ARRAY_SIZE;
    int* original_array = malloc(n * sizeof(int));
    int* array_c = malloc(n * sizeof(int));
    int* array_asm = malloc(n * sizeof(int));

    if (!original_array || !array_c || !array_asm) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        original_array[i] = rand() % 1000000;
    }

    double total_time_c = 0.0;
    double total_time_asm = 0.0;

    for (int run = 0; run < NUM_RUNS; run++) {
        copy_array(original_array, array_c, n);
        copy_array(original_array, array_asm, n);

        double start_time = get_time();
        quicksort(array_c, 0, n - 1);
        double end_time = get_time();
        total_time_c += end_time - start_time;

        if (!is_sorted(array_c, n)) {
            printf("Error: C QuickSort did not sort the array correctly\n");
            return 1;
        }

        start_time = get_time();
        asm_function(array_asm, 0, n - 1);
        end_time = get_time();
        total_time_asm += end_time - start_time;

        if (!is_sorted(array_asm, n)) {
            printf("Error: Assembly QuickSort did not sort the array correctly\n");
            return 1;
        }
    }

    printf("Average C QuickSort time: %f seconds\n", total_time_c / NUM_RUNS);
    printf("Average Assembly QuickSort time: %f seconds\n", total_time_asm / NUM_RUNS);

    free(original_array);
    free(array_c);
    free(array_asm);

    return 0;
}
