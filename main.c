#include <stdio.h>
#include <stdlib.h>

#include "tuple_c.h"

DEF_TUPLE_C(int, int);

tuple_c f()
{
    return (tuple_c) {
        .data = 1,
        .code = 0
    };
}

int main ()
{
    tuple_c t = f();

    printf("data: %d\n", t.data);
    printf("code: %d\n", t.code);

    return 0;
}
