# CSARCH2-x86-64-to-c programming
Group 9 - S14
Members: Charlize Villaflores, Katarina Milcah Valdez

**Execution Time and Analysis**
This contains a short analysis and records of the execution time for the array size inputs: *width* * *height*= {10 * 10, 100 * 100, and  1000 * 1000}.
| 10 * 10 | 100 * 100 | 1000 * 1000 |
| :---: | :---: | :---: | 
| 301 | 283 | 290 |

Specifications: 

**Introduction**

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
