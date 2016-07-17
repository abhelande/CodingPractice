//
//  main.cpp
//  C_Array_Practice
//
//  Created by abhelande on 7/13/16.
//  Copyright © 2016 apple. All rights reserved.
//

#include <iostream>
#include <assert.h>

class ArrayIp
{
    const uint32_t size;
    uint32_t* array;
    
    ArrayIp(uint32_t size);
};

uint32_t* incrementArray(uint32_t *inArray, uint32_t inSize, uint32_t &outSize)
{
    outSize = inSize;
    uint32_t *outArray = (uint32_t*)malloc(sizeof(uint32_t)*outSize);
    uint8_t carry = 1;
    int32_t iter = inSize;
    
    while(iter && carry)
    {
        if(inArray[iter-1] == 9)
        {
            outArray[iter-1] = 0;
        }
        else
        {
            outArray[iter-1] = inArray[iter-1] + 1;
            carry = 0;
            
        }
        
        iter--;
    }
    
    // if carry is still set, then we have a spill and need and extra digit to store as 1
    if(carry)
    {
        free(outArray);
        outSize = inSize+1;
        outArray = (uint32_t*)calloc(sizeof(uint32_t), outSize);
        outArray[0] = 1;
    }
    else
    {
        memcpy(outArray, inArray, sizeof(uint32_t)*(iter));
    }
    
    return outArray;
}

void printArray(uint32_t* inArray, uint32_t inSize)
{
    printf("\n{ ");
    for(uint32_t idx = 0; idx < inSize; idx++)
    {
        printf("%u, ", inArray[idx]);
    }
    printf("}\n");
}

int main(int argc, const char * argv[]) {
    
    {
        uint32_t ip[] = {2, 1, 8, 9};
        uint32_t ip_sz = static_cast<uint32_t>(sizeof(ip)/sizeof(ip[0]));
        uint32_t op_sz = 0;
        uint32_t *op = incrementArray(ip, ip_sz, op_sz);
        printf("\nIp = ");
        printArray(ip, ip_sz);
        printf("\nOp = ");
        printArray(op, op_sz);
        free(op);
    }
    
    {
        uint32_t ip[] = {9, 9, 9};
        uint32_t ip_sz = static_cast<uint32_t>(sizeof(ip)/sizeof(ip[0]));
        uint32_t op_sz = 0;
        uint32_t *op = incrementArray(ip, ip_sz, op_sz);
        printf("\nIp = ");
        printArray(ip, ip_sz);
        printf("\nOp = ");
        printArray(op, op_sz);
        free(op);
    }
    
    {
        uint32_t ip[] = {1, 9, 0};
        uint32_t ip_sz = static_cast<uint32_t>(sizeof(ip)/sizeof(ip[0]));
        uint32_t op_sz = 0;
        uint32_t *op = incrementArray(ip, ip_sz, op_sz);
        printf("\nIp = ");
        printArray(ip, ip_sz);
        printf("\nOp = ");
        printArray(op, op_sz);
        free(op);
    }
    
    {
        uint32_t ip[] = {3, 3};
        uint32_t ip_sz = static_cast<uint32_t>(sizeof(ip)/sizeof(ip[0]));
        uint32_t op_sz = 0;
        uint32_t *op = incrementArray(ip, ip_sz, op_sz);
        printf("\nIp = ");
        printArray(ip, ip_sz);
        printf("\nOp = ");
        printArray(op, op_sz);
        free(op);
    }
    
    {
        uint32_t ip[] = {9};
        uint32_t ip_sz = static_cast<uint32_t>(sizeof(ip)/sizeof(ip[0]));
        uint32_t op_sz = 0;
        uint32_t *op = incrementArray(ip, ip_sz, op_sz);
        printf("\nIp = ");
        printArray(ip, ip_sz);
        printf("\nOp = ");
        printArray(op, op_sz);
        free(op);
    }
    
    {
        uint32_t ip[] = {1};
        uint32_t ip_sz = static_cast<uint32_t>(sizeof(ip)/sizeof(ip[0]));
        uint32_t op_sz = 0;
        uint32_t *op = incrementArray(ip, ip_sz, op_sz);
        printf("\nIp = ");
        printArray(ip, ip_sz);
        printf("\nOp = ");
        printArray(op, op_sz);
        free(op);
    }
    
    
    return 0;
}

