
; float __fsdiv_callee (float left, float right)

SECTION code_clib
SECTION code_math

PUBLIC cm32_sccz80_fsdiv_callee

EXTERN m32_fsdiv_callee

    ; divide sccz80 float by sccz80 float
    ;
    ; enter : stack = sccz80_float left, ret
    ;          DEHL = sccz80_float right
    ;
    ; exit  :  DEHL = sccz80_float(left/right)
    ;
    ; uses  : af, bc, de, hl, af', bc', de', hl'

DEFC  cm32_sccz80_fsdiv_callee = m32_fsdiv_callee   ; enter stack = d32_float left
                                                    ;        DEHL = d32_float right
                                                    ; return DEHL = d32_float
