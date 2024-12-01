section .data
    var dd 255.0        ; for multiplying to 255
section .text
bits 64
default rel
global imgCvtGrayFloatToInt

imgCvtGrayFloatToInt:
    
        movss xmm4, [var]           ; 255
L1:
        movss xmm5, [rdx]           ; transferring float
        mulss xmm5, xmm4            ; xmm5 <-- float * 255
        ;cvttss2si rbx, xmm5        ; truncate
        cvtss2si rbx, xmm5         ; round to nearest integer
        mov [r8], rbx
        
        add rdx, 4
        add r8, 4
    LOOP L1
       
ret      