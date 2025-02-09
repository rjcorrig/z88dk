/*-------------------------------------------------------------------------
   float.h - ANSI functions forward declarations

   Copyright (C) 1998, Sandeep Dutta . sandeep.dutta@usa.net

   This library is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License 
   along with this library; see the file COPYING. If not, write to the
   Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.

   As a special exception, if you link this library with other files,
   some of which are compiled with SDCC, to produce an executable,
   this library does not by itself cause the resulting executable to
   be covered by the GNU General Public License. This exception does
   not however invalidate any other reasons why the executable file
   might be covered by the GNU General Public License.
-------------------------------------------------------------------------*/

#ifndef _INC_FLOAT_H
#define _INC_FLOAT_H

#define FLT_RADIX       2
#define FLT_MANT_DIG    24
#define FLT_EPSILON     1.192092896E-07F
#define FLT_DIG         6
#define FLT_MIN_EXP     (-125)
#define FLT_MIN         1.175494351E-38F
#define FLT_MIN_10_EXP  (-37)
#define FLT_MAX_EXP     (+128)
#define FLT_MAX         3.402823466E+38F
#define FLT_MAX_10_EXP  (+38)

/* the following deal with IEEE single-precision numbers */
#define EXCESS          126
#define SIGNBIT         ((unsigned long)0x80000000)
#define __INFINITY      ((unsigned long)0x7F800000)
#define HIDDEN          (unsigned long)(1ul << 23)
#define SIGN(fp)        (((unsigned long)(fp) >> (8*sizeof(fp)-1)) & 1)
#define EXP(fp)         (((unsigned long)(fp) >> 23) & (unsigned int) 0x00FF)
#define MANT(fp)        (((fp) & (unsigned long)0x007FFFFF) | HIDDEN)
#define NORM            0xff000000
#define PACK(s,e,m)     ((s) | ((unsigned long)(e) << 23) | (m))

float __uchar2fs (unsigned char) __z88dk_fastcall;
float __schar2fs (signed char) __z88dk_fastcall;
float __uint2fs (unsigned int) __z88dk_fastcall;
float __sint2fs (signed int) __z88dk_fastcall;
float __ulong2fs (unsigned long) __z88dk_fastcall;
float __slong2fs (signed long) __z88dk_fastcall;
unsigned char __fs2uchar (float) __z88dk_fastcall;
signed char __fs2schar (float) __z88dk_fastcall;
unsigned int __fs2uint (float) __z88dk_fastcall;
signed int __fs2sint (float) __z88dk_fastcall;
unsigned long __fs2ulong (float) __z88dk_fastcall;
signed long __fs2slong (float) __z88dk_fastcall;

float __fsadd (float, float) __z88dk_callee;
float __fssub (float, float) __z88dk_callee;
float __fsmul (float, float) __z88dk_callee;
float __fsdiv (float, float) __z88dk_callee;

char __fslt (float, float) __z88dk_callee;
char __fsgt (float, float) __z88dk_callee;
char __fseq (float, float) __z88dk_callee;
char __fsneq (float, float) __z88dk_callee;

#endif    /* _INC_FLOAT_H */
