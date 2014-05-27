
#ifndef _COMPRESS_ZX7_H
#define _COMPRESS_ZX7_H

//////////////////////////////////////////////////////////////
//                ZX7 FAMILY OF DECOMPRESSORS               //
//                 Copyleft (k) Einar Saukas                //
//////////////////////////////////////////////////////////////
//                                                          //
// Further information is available at:                     //
// http://www.worldofspectrum.org/infoseekid.cgi?id=0027996 //
// http://www.worldofspectrum.org/infoseekid.cgi?id=0028048 //
//                                                          //
//////////////////////////////////////////////////////////////
// crts use dzx7_standard() to decompress the data segment  //
//////////////////////////////////////////////////////////////

/*

   ZX7 Decompresses data that was previously compressed using
   a PC utility; it does not provide a z80 compressor.

   Decompression of compressed zx7 data:

   * dzx7_standard()

     The smallest version of the decompressor.
   
   * dzx7_turbo()
   
     The intermediate version of the decompressor, providing
     a balance between speed and size.
   
   * dzx7_mega()
   
     The fastest version of the decompressor.
   
   Decompression of rcs+zx7 data.  rcs is a separate utility
   that re-orders screen graphics to improve compression ratio.
   The mangling only makes sense on the zx spectrum target
   as the re-ordering is a function of the storage format on
   that machine.  The routines are kept available for all targets
   to allow all targets to decompress this sort of data.
   
   * dzx7_smart_rcs()
   
     The smallest version of the integrated zx7+rcs decompressor.
   
   * dzx7_agile_rcs()
   
     The fastest version of the integrated zx7+rcs decompressor.

*/

#ifdef __SDCC

// SDCC

extern void                    dzx7_standard(void *src, void *dst);
extern void                    dzx7_turbo(void *src, void *dst);
extern void                    dzx7_mega(void *src, void *dst);

extern void                    dzx7_smart_rcs(void *src, void *dst);
extern void                    dzx7_agile_rcs(void *src, void *dst);

#else

// SCCZ80

extern void __LIB__            dzx7_standard(void *src, void *dst);
extern void __LIB__            dzx7_turbo(void *src, void *dst);
extern void __LIB__            dzx7_mega(void *src, void *dst);

extern void __LIB__            dzx7_smart_rcs(void *src, void *dst);
extern void __LIB__            dzx7_agile_rcs(void *src, void *dst);

// SCCZ80 CALLEE LINKAGE

extern void __LIB__ __CALLEE__ dzx7_standard_callee(void *src, void *dst);
extern void __LIB__ __CALLEE__ dzx7_turbo_callee(void *src, void *dst);
extern void __LIB__ __CALLEE__ dzx7_mega_callee(void *src, void *dst);

extern void __LIB__ __CALLEE__ dzx7_smart_rcs_callee(void *src, void *dst);
extern void __LIB__ __CALLEE__ dzx7_agile_rcs_callee(void *src, void *dst);

// SCCZ80 MAKE CALLEE LINKAGE THE DEFAULT

#define dzx7_standard(a,b)     dzx7_standard_callee(a,b)
#define dzx7_turbo(a,b)        dzx7_turbo_callee(a,b)
#define dzx7_mega(a,b)         dzx7_mega_callee(a,b)

#define dzx7_smart_rcs(a,b)    dzx7_smart_rcs_callee(a,b)
#define dzx7_agile_rcs(a,b)    dzx7_agile_rcs_callee(a,b)

#endif

#endif
