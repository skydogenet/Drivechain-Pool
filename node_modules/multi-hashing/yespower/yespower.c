/*-
 * Copyright 2009 Colin Percival
 * Copyright 2013-2018 Alexander Peslyak
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#include "yespower.h"

 // for YesPoWer-0.9/1.0 (Cryply, Bellcoin)
void yespower_hash(const char* input, char* output)
{
    yespower_params_t params = {
            .version = YESPOWER_1_0,
            .N = 2048,
            .r = 32,
            .pers = NULL,
            .perslen = 0
    };
    yespower_tls((const uint8_t*)input, 80, &params, (yespower_binary_t*)output);
}

// for yescryptR8, yespower-0.5_R8 (BitZeny, BitZeny-Plus)
void yespower_0_5_R8_hash(const char* input, char* output)
{
    yespower_params_t params = {
            .version = YESPOWER_0_5,
            .N = 2048,
            .r = 8,
            .pers = "Client Key",
            .perslen = 10
    };
    yespower_tls((const uint8_t*)input, 80, &params, (yespower_binary_t*)output);
}

// for yescryptR8G, yespower-0.5_R8G (Koto)
void yespower_0_5_R8G_hash(const char* input, size_t inputlen, char* output)
{
    yespower_params_t params = {
            .version = YESPOWER_0_5,
            .N = 2048,
            .r = 8,
            .pers = (const uint8_t*)input,
            .perslen = inputlen
    };
    if (yespower_tls((unsigned char*)input, inputlen, &params, (yespower_binary_t*)output))
        abort();
}

// for yescryptR16, yespower-0.5_R16 (Yenten)
void yespower_0_5_R16_hash(const char* input, char* output)
{
    yespower_params_t params = {
            .version = YESPOWER_0_5,
            .N = 4096,
            .r = 16,
            .pers = "Client Key",
            .perslen = 10
    };
    yespower_tls((const uint8_t*)input, 80, &params, (yespower_binary_t*)output);
}

// for yescryptR24, yespower-0.5_R24 (Jagaricoin-R)
void yespower_0_5_R24_hash(const char* input, char* output)
{
    yespower_params_t params = {
            .version = YESPOWER_0_5,
            .N = 4096,
            .r = 24,
            .pers = "Jagaricoin",
            .perslen = 10
    };
    yespower_tls((const uint8_t*)input, 80, &params, (yespower_binary_t*)output);
}

// for yescryptR32, yespower-0.5_R32 (Wavi)
void yespower_0_5_R32_hash(const char* input, char* output)
{
    yespower_params_t params = {
            .version = YESPOWER_0_5,
            .N = 4096,
            .r = 32,
            .pers = "WaviBanana",
            .perslen = 10
    };
    yespower_tls((const uint8_t*)input, 80, &params, (yespower_binary_t*)output);
}

void yespower_sugar_hash(const char* input, char* output, uint32_t len)
{
    yespower_params_t params = {
            .version = YESPOWER_1_0,
            .N = 2048,
            .r = 32,
            .pers = "Satoshi Nakamoto 31/Oct/2008 Proof-of-work is essentially one-CPU-one-vote",
            .perslen = 74
    };
    yespower_tls((yespower_binary_t*)input, len, &params, (yespower_binary_t*)output);
}

void yespower_ltncg_hash(const char* input, char* output)
{
    yespower_params_t params = {
            .version = YESPOWER_1_0,
            .N = 2048,
            .r = 32,
            .pers = (const uint8_t*)"LTNCGYES",
            .perslen = 8
    };
    yespower_tls((const uint8_t*)input, 80, &params, (yespower_binary_t*)output);
}

// for YespowerR16 (Yenten)
void yespower_r16_hash(const char* input, char* output)
{
    yespower_params_t params = {
            .version = YESPOWER_1_0,
            .N = 4096,
            .r = 16,
            .pers = NULL,
            .perslen = 0
    };
    yespower_tls((const uint8_t*)input, 80, &params, (yespower_binary_t*)output);
}