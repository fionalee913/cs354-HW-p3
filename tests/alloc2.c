/*a few allocations in multiples of 4 bytes*/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   assert(Alloc_Mem(4) != NULL);
   printf("%s", "alloc 4 -> 8\n");
   assert(Alloc_Mem(8) != NULL);
   printf("%s", "8 -> 8\n");
   assert(Alloc_Mem(16) != NULL);
   printf("%s", "16 -> 16\n");
   assert(Alloc_Mem(24) != NULL);
   printf("%s", "24 -> 24\n");
   exit(0);
}
