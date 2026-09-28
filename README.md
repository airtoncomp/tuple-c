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
