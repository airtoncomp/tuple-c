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

DEF_CUSTOM_TUPLE_C(int, int, my_tuple_type_a);

my_tuple_type_a g()
{
    return (my_tuple_type_a) {
        .data = 1,
        .code = 0
    };
}

DEF_CUSTOM_TUPLE_C(double, int, my_tuple_type_b);

my_tuple_type_b h()
{
    return (my_tuple_type_b) {
        .data = 98.23,
        .code = -2
    };
}

struct person {
    const char *first_name;
    const char *last_name;
};
DEF_CUSTOM_TUPLE_C(struct person, int, tuple_person_t);

int main ()
{
    tuple_c t = f();

    printf("\naccessing data fields\n");

    printf("data: %d\n", t.data);
    printf("code: %d\n", t.code);

    printf("\nusing unwrap macros\n");

    printf("data: %d\n", tuple_data(t));
    printf("code: %d\n", tuple_code(t));

    printf("\n-----------------------------\n");

    my_tuple_type_a myt_a = g();

    printf("\naccessing data fields\n");

    printf("data: %d\n", myt_a.data);
    printf("code: %d\n", myt_a.code);

    printf("\nusing unwrap macros\n");

    printf("data: %d\n", tuple_data(myt_a));
    printf("code: %d\n", tuple_code(myt_a));

    printf("\n-----------------------------\n");

    my_tuple_type_b myt_b = h();

    printf("\naccessing data fields\n");

    printf("data: %lf\n", myt_b.data);
    printf("code: %d\n", myt_b.code);

    printf("\nusing unwrap macros\n");

    printf("data: %lf\n", tuple_data(myt_b));
    printf("code: %d\n", tuple_code(myt_b));

    printf("\n-----------------------------\n");

    struct person ceo;
    ceo.first_name = "Tony";
    ceo.last_name = "Stark";

    tuple_person_t tp = (tuple_person_t) {
        .data = ceo,
        .code = 0
    };

    printf("name: %s %s\n", tuple_data(tp).first_name, tuple_data(tp).last_name);
    printf("code: %d\n", tuple_code(tp));

    return 0;
}
