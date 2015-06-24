/*
 * Author: RN Alex
 * TUT104
 * Reverse the words in a sentence.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char test_str[]=" This is a test string - Alice loves Bob";

void
reverse_str(char *str, int len)
{
        int i=0,j=len;
        for(i=0,j=len-1;i<j;++i,--j) {
                char temp;
                temp = str[i];
                str[i]=str[j];
                str[j]=temp;
        }
}

void
reverse_sentence(char *str, int len)
{
        int i,j=0,plen=0;
        for(i=0; i<len; ++i) {
                if (str[i]==' ' || i == (len -1)) {
                        plen = i-j;
                        if(str[j] != ' ') {
                                //printf("[\n%c - %c - %d]",str[j],str[j+plen-1],plen);
                                reverse_str(str+j,plen);
                        }
                        j=i+1;
                        continue;
                };
        }
        reverse_str(str,len-1);
}

int
main(int argc, char **argv)
{
        printf("\n Actual ==> %s ", test_str);
        reverse_sentence(test_str,sizeof(test_str));
        printf("\n Reversed ==> %s ]", test_str);
}

