section .data
var dd 255.0  ; Define the scaling factor 255.0

section .text
bits 64
default rel
global imgCvtGrayFloatToInt

imgCvtGrayFloatToInt:
    movss xmm1, [var]
    mulss xmm0, xmm1
    cvttss2si eax, xmm0
    ret