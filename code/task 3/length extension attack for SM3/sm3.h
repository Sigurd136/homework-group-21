#pragma once
#ifndef _SM3_H_
#define _SM3_H_

#define SM3_HASH_SIZE 32 

typedef struct SM3Context
{
	unsigned int intermediateHash[SM3_HASH_SIZE / 4];
	unsigned char messageBlock[64];
} SM3Context;

unsigned char* SM3Calc(const unsigned char* message,
	unsigned int messageLen, unsigned char digest[SM3_HASH_SIZE]);

#endif 
