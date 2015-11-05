/*
 * TUT107 Given a character string. Push
 * a particualar character to the right end 
 * of the string.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void
swap(char *sch , char *dch)
{
     char tch;
     tch = *sch;
     *sch = *dch;
     *dch = tch;
}

void
herd_char(char *src , int len, char ch)
{
         int e = len;
         int s = 0;
         while (e > s) {
               if( (*(src+s)) == ch) {
                    swap(src+s, src+e);
                    --e;
               }
               else {
                    ++s;
               }
                        
          }
}

char test_string[]="0122230ABCD0GH";
int
main(int argc, char **argv)
{
     printf("\n %s ", test_string);
     herd_char(test_string, sizeof(test_string)-2,'0');
     printf("\n %s ", test_string);
     herd_char(test_string, sizeof(test_string)-2,'2');
     printf("\n %s ", test_string);
}


