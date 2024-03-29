/* check for coalesce free space */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "mem.h"

int main() {
   assert(Init_Mem(4096) == 0);
   void * ptr[4];

   ptr[0] = Alloc_Mem(800);
   assert(ptr[0] != NULL);

   ptr[1] = Alloc_Mem(800);
   assert(ptr[1] != NULL);

   ptr[2] = Alloc_Mem(800);
   assert(ptr[2] != NULL);

   ptr[3] = Alloc_Mem(800);
   assert(ptr[3] != NULL);

   while (Alloc_Mem(800) != NULL)
     ;

   printf("%s", "before free\n");
   assert(Free_Mem(ptr[1]) == 0);
   assert(Free_Mem(ptr[2]) == 0);

   printf("%s", "after free, before realloc\n");
   ptr[2] = Alloc_Mem(1600);
   printf("%p", ptr[2]);
   assert(ptr[2] != NULL);

   exit(0);
}
