#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//function for converting from float to int pixels
void Cfunc(int row, int col, float** p, int** intp){
    for(int k=0; k < row; k++){
        for(int l=0; l < col; l++){
            intp[k][l] = p[k][l] * 255;
        }
    }
}


int main(){

    int height = 0; 
    int width = 0;
    float** pixels;
    int** int_pixels;


    printf("Input height: ");
    scanf("%d", &height);

    printf("Input width: ");
    scanf("%d", &width);

    // allocate memory for rows
    pixels = (float**)malloc(height * sizeof(float*));
    int_pixels = (int**)malloc(height * sizeof(int*));

    // Allocate memory for columns in each row
    for (int i = 0; i < height; i++) {
        pixels[i] = (float*)malloc(width * sizeof(float));
        int_pixels[i] = (int*)malloc(width * sizeof(int));
    }

    // Read the elements of the 2D array
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%f", &pixels[i][j]);
        }
    }

    Cfunc(height, width, pixels, int_pixels);

    //Print the array
    printf("\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", int_pixels[i][j]);
        }
        printf("\n");
    }

    return 0;
}