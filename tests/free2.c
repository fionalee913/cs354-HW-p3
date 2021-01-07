/* a few allocations in multiples of 4 bytes followed by frees */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   void* ptr[4];

   ptr[0] = Alloc_Mem(4);
   ptr[1] = Alloc_Mem(8);
   printf("%p", ptr[1]);
   assert(Free_Mem(ptr[0]) == 0);
   printf("%s", "free 4\n");
   assert(Free_Mem(ptr[1]) == 0);
   printf("%s", "free 8\n");

   ptr[2] = Alloc_Mem(16);
   ptr[3] = Alloc_Mem(4);
   assert(Free_Mem(ptr[2]) == 0);
   assert(Free_Mem(ptr[3]) == 0);

   exit(0);
}
