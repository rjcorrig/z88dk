
; float __fshypot (float left, float right)

SECTION code_clib
SECTION code_math

PUBLIC cm32_sdcc_fshypot

EXTERN cm32_sdcc_fsreadr, m32_fshypot

.cm32_sdcc_fshypot

    ; find the hypotenuse of two sdcc floats
    ;
    ; enter : stack = sdcc_float right, sdcc_float left, ret
    ;
    ; exit  : DEHL = sdcc_float(left+right)
    ;
    ; uses  : af, bc, de, hl, af', bc', de', hl'

    call cm32_sdcc_fsreadr

    jp m32_fshypot          ; enter stack = sdcc_float right, sdcc_float left, ret
                            ;        DEHL = sdcc_float right
                            ; return DEHL = sdcc_float
