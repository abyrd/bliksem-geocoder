/* http://zaemis.blogspot.nl/2011/06/reading-unicode-utf-8-by-hand-in-c.html */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utf8.h"
#include "mapping.h"

#define U_MAX_BYTES 4

unsigned short u_getc(FILE *stream, char *bytes) {
    /* mask values for bit pattern of first byte in multi-byte
     UTF-8 sequences: 
       192 - 110xxxxx - for U+0080 to U+07FF 
       224 - 1110xxxx - for U+0800 to U+FFFF 
       240 - 11110xxx - for U+010000 to U+1FFFFF */
    static unsigned short mask[] = {192, 224, 240}; 

    unsigned short i, j; 

    /* initialize buffer */
    memset(bytes, 0, U_MAX_BYTES + 1); 

    /* read first byte into buffer */
    bytes[0] = getc(stream);
    if (bytes[0] == EOF) { 
        return 0; 
    } 

    /* check how many more bytes need to be read for
     character */
    i = 0;
    if ((bytes[0] & mask[0]) == mask[0]) i++;
    if ((bytes[0] & mask[1]) == mask[1]) i++;
    if ((bytes[0] & mask[2]) == mask[2]) i++;

    /* read subsequent character bytes */
    j = 0;
    while (j < i) {
        j++;
        bytes[j] = getc(stream);
    }

    /* return number of bytes read into buffer */
    return i + 1;
}

int main(int argc, char **argv) {
    /* allocating +1 for null gives ability to print character
     as string */
    char *bytes = (char*)calloc(U_MAX_BYTES + 1, sizeof(char)); 
    int sz;
    u_int32_t *dest = calloc(U_MAX_BYTES, sizeof(u_int32_t));

    /* read and print until end of file */
    while ((sz = u_getc(stdin, bytes))) { 
        int sz_conv = u8_toucs(dest, 4, bytes, sz);
        char c = ucs_toupper(dest, sz_conv);
        printf("%d %d %d %d %d %s -> %c\n", sz, dest[0], dest[1], dest[2], dest[3], bytes, c);
    }

    return 0; 
}
