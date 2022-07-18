#include "pch.h"
#include "jni.h"
#include "cn_xgl_demo_JniHash.h"
#include <iostream>


using namespace std;

unsigned long long crypt_table[0x500];


void ngx_ulog_prepare_crypt_table()
{
    long long seed = 0x00100001, index1 = 0, index2 = 0, i;

    for (index1 = 0; index1 < 0x100; index1++)
    {
        for (index2 = index1, i = 0; i < 5; i++, index2 += 0x100)
        {
            long long temp1, temp2;

            seed = (seed * 125 + 3) % 0x2AAAAB;
            temp1 = (seed & 0xFFFF) << 0x10;

            seed = (seed * 125 + 3) % 0x2AAAAB;
            temp2 = (seed & 0xFFFF);

            crypt_table[index2] = (temp1 | temp2);
        }
    }
}

//函数HashString以下函数计算lpszFileName 字符串的hash值，其中dwHashType 为hash的类型，  
long long HashString(const char* lpszkeyName, long dwHashType)
{
    unsigned char* key = (unsigned char*)lpszkeyName;
    long long seed1 = 0x7FED7FED;
    long long seed2 = 0xEEEEEEEE;
    int ch;

    dwHashType = (NULL == key) ? dwHashType : (*key % 3);

    while (*key != 0)
    {
        ch = *key++;
        seed1 = crypt_table[(dwHashType << 8) + ch] ^ (seed1 + seed2);
        seed2 = ch + seed1 + seed2 + (seed2 << 5) + 3;
    }
    return seed1;
}

JNIEXPORT jlong JNICALL Java_cn_xgl_demo_JniHash_hashString
(JNIEnv* env, jclass, jstring str) {
    ngx_ulog_prepare_crypt_table();
    const char* dname = NULL;
    dname = env->GetStringUTFChars(str, 0);
    long long data = HashString(dname, 1);
    return data;
}