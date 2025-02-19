
; float _hypot (float left, float right) __z88dk_callee

SECTION code_clib
SECTION code_math

PUBLIC asm_hypot

EXTERN m32_fshypot_callee

    ; find the hypotenuse of two sccz80 floats
    ;
    ; enter : stack = sccz80_float left, ret
    ;          DEHL = sccz80_float right
    ;
    ; exit  :  DEHL = sccz80_float(left+right)
    ;
    ; uses  : af, bc, de, hl, af', bc', de', hl'

DEFC  asm_hypot = m32_fshypot_callee    ; enter stack = d32_float left
                                        ;        DEHL = d32_float right
                                        ; return DEHL = d32_float
