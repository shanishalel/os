#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* 1. Where is allocated?- uninitialized data section*/
int primes[] = { 2, 3, 5, 7 };  /* 2. Where is allocated? - initialize data section*/

static int
square(int x)                   /* 3. Where is allocated?- text(code) section */
{
    int result;                 /* 4. Where is allocated? -stack */

    result = x * x;
    return result;              /* 5. How the return value is passed?- by register */
}

static void
doCalc(int val)                 /* 6. Where is allocated?- text (code) section */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7. Where is allocated? - stack*/

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /* 8.Where is allocated? - text (code) section */
{
    static int key = 9973;      /* 9.Where is allocated? - initialize data section */
    static char mbuf[10240000]; /* 10.Where is allocated? - unitialized data section (known as BSS)*/
    char* p;                    /* 11.Where is allocated? - stack */


    doCalc(key);

    exit(EXIT_SUCCESS);
}
