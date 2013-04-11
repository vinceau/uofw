/* Copyright (C) 2011, 2012, 2013 The uOFW team
   See the file COPYING for copying permission.
*/

#ifndef COMMON_INCLUDED
# error "Only include common_imp.h or common_header.h!"
#endif

/* Segment base addresses and sizes */
#define KU0_BASE                        0x00000000  /* cached - user/supervisor/kernel */
#define KU1_BASE                        0x40000000  /* uncached - user/supervisor/kernel */

#define K0_BASE                         0x80000000  /* cached - kernel */
#define K0_SIZE                         0x20000000  /* 512 MB */
#define K1_BASE                         0xA0000000  /* uncached - kernel */
#define K1_SIZE                         0x20000000  /* 512 MB */
#define K2_BASE                         0xC0000000  /* cached - supervisor/kernel */
#define K2_SIZE                         0x20000000  /* 512 MB */
#define K3_BASE                         0xE0000000  /* cached - kernel */
#define K3_SIZE                         0x20000000  /* 512 MB */

/* Scratchpad segment base address and size */
#define SCE_SCRATCHPAD_ADDR				0x00010000  /* Physical memory */
#define SCE_SCRATCHPAD_ADDR_KU0         0x00010000	/* KU segment 0 (cached) */
#define SCE_SCRATCHPAD_ADDR_KU1         0x40010000	/* KU segment 1 (uncached) */
#define SCE_SCRATCHPAD_ADDR_K0          0x80010000  /* K0 segment (cached) */
#define SCE_SCRATCHPAD_SIZE				0x00004000	/* 16 KB */

#define REBOOT_BASE                     0x88600000  /* K0 segment (cached) */

#define UCACHED(ptr) (void *)((u32)(void *)(ptr) & 0x1FFFFFFF) /* KU0 - cached. */
#define KCACHED(ptr) (void *)((u32)(void *)(ptr) | K0_BASE) /* K0 - cached */
#define KUNCACHED(ptr) (void *)(K1_BASE | ((u32)(void *)(ptr) & 0x1FFFFFFF)) /* K1 - uncached */
#define UUNCACHED(ptr) (void *)(KU1_BASE | ((u32)(void *)(ptr) & 0x1FFFFFFF)) /* KU1 - uncached */

/* Alignment */
#define UPALIGN256(v) (((v) + 0xFF) & 0xFFFFFF00)
#define UPALIGN64(v) (((v) + 0x3F) & 0xFFFFFFC0)
#define UPALIGN4(v)     (((v) + 0x3) & 0xFFFFFFFC)   