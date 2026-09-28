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
