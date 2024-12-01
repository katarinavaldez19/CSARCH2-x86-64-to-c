# CSARCH2-x86-64-to-c programming
Group 9 - S14

Members: Charlize Villaflores, Katarina Milcah Valdez

***Final file is found on Main Branch***


**Execution Time and Analysis**

This contains a short analysis and records of the average execution time for the array size inputs: *width* * *height*= {10 * 10, 100 * 100, and  1000 * 1000}.
| 10 * 10 | 100 * 100 | 1000 * 1000 |
| :---: | :---: | :---: | 
| 0.000000 | 0.033333 | 2.800000 |

Based on the table given, these are the runtimes taken during the run of assembly function. From the table, we can see that 10 x 10 matrices are the fastest considering that they only take less than 1 nanosecond, while the other two, reasonable for their size, takes more than the aforementioned matrix size. 100 x 100 takes a longer time than the 10 x 10 matrix, however it is still fast considering that we are processing over 10000 float values and it does not take more than a second. Meanwhile, for the last matrix, it takes more than a second to process the function due to the array having 1 million float values, each having taken up 32-bit storage in the memory.


**Correctness Check**

For the first case, we used the test case presented in the specifications. Below is a screenshot of our command prompt containing the input and output, encircled in red.
![LBYARCH images (1)](https://github.com/user-attachments/assets/05ea557c-8955-4ebe-b70a-c13839075d10)


Below is another random test case we did. To show the correctness of the output, we also included a snapshot of the calculator to show that the output was correctly calculated.
![LBYARCH images](https://github.com/user-attachments/assets/f4668003-8f35-4018-a775-b44e4688d59f)



**Video Presentation Google Drive Link:** https://drive.google.com/file/d/1naScTiWXJT7wM-79l37zZXr8q3JVJ1E-/view?usp=sharing


-----------------------------------------------------------------------------


**Specifications:**

Introduction

A grayscale image is internally represented as a 2 dimensional array. Size is defined by the number of pixels in a row (width), and number of pixels in a column (height). Each cell represents the pixel value. Pixel values in grayscale are represented as white, black, and shades of gray using different numerical data type representation depending on the library used. 

Some Image Processing Libraries represent grayscale images as having single float based pixel values between 0 to 1: 0 for black, 1 for white, 0.25 lighter gray, 0.75 darker gray, and all other gray values in between.

Image = 

0.25, 0.35, 0.45, 0.33

0.55, 0.65, 0.75, 0.33

0.85, 0.95, 0.15, 0.33

Some Libraries represent using 8 bit unsigned integer. 0 for black, 255 for white, 64 lighter gray, 191 darker gray, and all other gray values in between.

Image = 

64,  89,  114, 84

140, 166, 191, 84

216, 242, 38,  84

To enable using different image processing libraries simultaneously, conversion from one format to the other has to be done. Perform Mapping from single precision float based grayscale to uint8 based integer representation. Each pixel is calculated using ratio and proportion equation

f/i = 1/255

Where f is the float based pixel value and i is the integer based pixel value

**Task**

Implement a program that converts the grayscale image representation from float based to integer based using C and x86 assembly language. Implement the function imgCvtGrayFloatToInt().

*Required to use functional scalar SIMD registers

*Required to use functional scalar SIMD floating-point instructions

Input: height, width, single float pixel values

Example.

3 4

0.25 0.35 0.45 0.33

0.55 0.65 0.75 0.33

0.85 0.95 0.15 0.33


Output: Integer pixel values

Example.

64,  89,  114, 84

140, 166, 191, 84

216, 242, 38,  84
