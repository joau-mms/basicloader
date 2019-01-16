// Copyright (C) 2016-2019 Semtech (International) AG. All rights reserved.
//
// This file is subject to the terms and conditions defined in file 'LICENSE',
// which is part of this source code package.

#ifndef _boottab_h_
#define _boottab_h_

#include "bootloader.h"

// Bootloader information table on STM32

typedef struct {
    uint32_t version;                                   // version of boot loader (values below 256 are reserved for legacy bootloaders)
    __attribute__((noreturn))
        void (*panic) (uint32_t reason, uint32_t addr); // bootloader panic function
    uint32_t (*update) (void* ptr, hash32* hash);       // function to set firmware update pointer

    uint32_t (*crc32) (void* buf, uint32_t nwords);     // calculate CRC32
    void (*wr_flash) (uint32_t* dst, uint32_t* src,     // write flash
            uint32_t nwords, bool erase);
} boot_boottab;

#endif
