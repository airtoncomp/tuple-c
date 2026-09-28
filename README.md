## About Tuple-C

Tuple-C is a small personal project that lets C functions return two
values together: data and a status code. The data is the value requested
by the caller, while the code can represent success or a specific error.

It is a lightweight utility and may not fit every use case. The downside
of this simple library is that it adds a layer of struct wrapping the 
actual user data, but using with care i think it can be useful at some point.

Unlike other languages wich natively functions can return a tuple, C functions
cannot do it. But the library actually allow user code to implement a struct
during pre-compilation phase which contains the data and code fields.

```
cc -DDEBUG -std=c17 -Wall -Wpedantic -Wextra -Werror -g -o tuple_c main.c && ./tuple_c
```

## Usage examples

1) First thing we need to do is to define our tuple with types:

```
DEF_TUPLE_C(int, int);
```

This definition will implement a struct of type: tuple_c.

2) Later, we define function that return this tuple:

```
tuple_c f()
{
    /* some code here */

    return (tuple_c) {
        .data = 25,
        .code = -1
    };
}
```

3) Call the function:

```
tuple_c t = f();

printf("\naccessing data fields\n");

printf("data: %d\n", t.data);
printf("code: %d\n", t.code);

printf("\nusing unwrap macros\n");

printf("data: %d\n", tuple_data(t));
printf("code: %d\n", tuple_code(t));
```

### Implement custom tuple type name

Custom tuple type names can be defined with the DEF_CUSTOM_TUPLE_C macro.
This allows multiple tuple types to coexist without type name conflicts.

```
DEF_CUSTOM_TUPLE_C(int, int, my_tuple_t);

my_tuple_t g()
{
    return (my_tuple_t) {
        .data = 32,
        .code = 0
    };
}
```

### The data field of tuple_c can also be struct

The data field of a tuple can hold any valid C type, including a struct.
The accessor macros can still be used normally to retrieve both the data
and the status code.

```
struct person {
    const char *first_name;
    const char *last_name;
};
DEF_CUSTOM_TUPLE_C(struct person, int, tuple_person_t);

struct person ceo;
ceo.first_name = "Tony";
ceo.last_name = "Stark";

tuple_person_t tp = (tuple_person_t) {
    .data = ceo,
    .code = 0
};

printf("name: %s %s\n", tuple_data(tp).first_name, tuple_data(tp).last_name);
printf("code: %d\n", tuple_code(tp));
```
