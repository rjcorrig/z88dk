
; float __fsneg (float number)

SECTION code_clib
SECTION code_math

PUBLIC cm32_sccz80_fsneg

EXTERN m32_fsneg_fastcall

    ; negate sccz80 floats
    ;
    ; enter : stack = ret
    ;          DEHL = sccz80_float number
    ;
    ; exit  :  DEHL = sccz80_float(-number)
    ;
    ; uses  : af, bc, de, hl

DEFC  cm32_sccz80_fsneg = m32_fsneg_fastcall    ; enter stack = ret
                                                ;        DEHL = d32_float
                                                ; return DEHL = d32_float
