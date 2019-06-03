#include "skunkhash.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sha3/sph_skein.h"
#include "sha3/sph_cubehash.h"
#include "sha3/sph_fugue.h"
#include "sha3/sph_gost.h"


void Skunk_Hash(const char* input, char* output)
{
    sph_skein512_context     ctx_skein;
    sph_cubehash512_context   ctx_cubehash;
    sph_fugue512_context      ctx_fugue;
    sph_gost512_context      ctx_gost;

    //these uint512 in the c++ source of the client are backed by an array of uint32
    uint32_t hashA[16];

    sph_skein512_init(&ctx_skein);
    sph_skein512(&ctx_skein, input, 80);
    sph_skein512_close(&ctx_skein, hashA);

    sph_cubehash512_init(&ctx_cubehash);
    sph_cubehash512(&ctx_cubehash, hashA, 64);
    sph_cubehash512_close(&ctx_cubehash, hashA);

    sph_fugue512_init(&ctx_fugue);
    sph_fugue512(&ctx_fugue, hashA, 64);
    sph_fugue512_close(&ctx_fugue, hashA);
    
    sph_gost512_init(&ctx_gost);
    sph_gost512(&ctx_gost, hashA, 64);
    sph_gost512_close(&ctx_gost, hashA);

    memcpy(output, hashA, 32);

}

