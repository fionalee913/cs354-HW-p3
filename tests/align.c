/* first pointer returned is 8-byte aligned */
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   int* ptr = (int*) Alloc_Mem(sizeof(int));
   assert(ptr != NULL);
   printf("%s", "alloc int\n");
   assert(((int)ptr) % 8 == 0);
   printf("%s", "addr mod 8");
   exit(0);
}
