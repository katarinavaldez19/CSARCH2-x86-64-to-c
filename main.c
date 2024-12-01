#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void imgCvtGrayFloatToInt(unsigned long long int size, float* p, int* final_p);

int main() {
    int height = 0;
    int width = 0;
    unsigned long long int initial_size = 0;

    clock_t start, end;
    double time_taken;

    printf("Input height: ");
    scanf_s("%d", &height);

    printf("Input width: ");
    scanf_s("%d", &width);

    initial_size = height * width;

    // Allocate memory for the arrays
    float* pixels1d = malloc(initial_size * sizeof(float));
    int* int_pixels1d = malloc(initial_size * sizeof(int));

    // Allocate memory for rows of 2D arrays
    float** pixels2d = (float**)malloc(height * sizeof(float*));
    int** int_pixels2d = (int**)malloc(height * sizeof(int*));

    // Allocate memory for columns in each row
    for (int i = 0; i < height; i++) {
        pixels2d[i] = (float*)malloc(width * sizeof(float));
        int_pixels2d[i] = (int*)malloc(width * sizeof(int));
    }

    //random number generator for 1000 x 1000
    if (height == 1000 && width == 1000) {
        srand(time(NULL));

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                pixels2d[i][j] = ((float)rand() / RAND_MAX) * 0.99;
            }
        }
    }

    else {
        // Read the elements of the image array
        printf("Input image array:\n");
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                scanf_s("%f", &pixels2d[i][j]);
            }
        }
    }

    // Transferring from 2D array to 1D array
    int k = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels1d[k++] = pixels2d[i][j];
        }
    }

    int iterations = 30;
    double total_time = 0;
    for (int i = 0; i < iterations; i++) {
        start = clock();
        imgCvtGrayFloatToInt(initial_size, pixels1d, int_pixels1d);
        end = clock();

        time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
        printf("Time for this iteration: %lfms\n", time_taken);
        total_time += time_taken;
    }
    
    double average_time_taken = total_time / iterations;    
    printf("Sanity check, average time: %lfs\n", average_time_taken);

    // Transferring from 1D array to 2D array
    k = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int_pixels2d[i][j] = int_pixels1d[k++];
        }
    }

    //printing if number is not too big
    if (height != 1000 && width != 1000) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                printf("%d ", int_pixels2d[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
