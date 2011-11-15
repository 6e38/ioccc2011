#include <stdio.h>

int main(int argc, char *argv[])
{
   FILE *f;
   char c;
   int count = 0;
   int p = 0;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <file>\n", argv[0]);
      return 1;
   }

   f = fopen(argv[1], "r");

   if (f == NULL)
   {
      fprintf(stderr, "Unable to open file: %s\n", argv[1]);
      return 1;
   }

   while (fread(&c, 1, 1, f))
   {
      switch (c)
      {
         case EOF:
            printf("yessir\n");
         case ' ':
         case '\t':
         case '\n':
            if (p)
               count--;
            p = 0;
            break;

         case ';':
         case '{':
         case '}':
            p = 1;
            count++;
            break;

         default:
            p = 0;
            count++;
            break;
      }
   }
   printf("%d\n", count);
   return 0;
}

