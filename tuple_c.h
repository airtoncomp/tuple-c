/**
 * Copyright 2026, Airton Ishimori
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the “Software”), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _TUPLE_C_H
#define _TUPLE_C_H

/**
 * Define the tuple-c type used by the library.
 * The first argument specifies the data type and the second specifies
 * the status code type. This macro defines a struct named tuple_c
 * containing both values.
 */
#define DEF_TUPLE_C(data_t, code_t)     \
typedef struct {                        \
    data_t      data;                   \
    code_t      code;                   \
} tuple_c

/**
 * Define a tuple-c type with a custom name.
 * Unlike DEF_TUPLE_C, this macro allows the caller to specify the
 * resulting typedef name through name_t.
 */
#define DEF_CUSTOM_TUPLE_C(data_t, code_t, name_t)      \
typedef struct {                                        \
    data_t      data;                                   \
    code_t      code;                                   \
} name_t

/**
 * When accesing tuple fields you can use direct access
 * as any other struct or via unwrapper macros to extract
 * data and code parts.
 */
#define tuple_data(t) (t.data)
#define tuple_code(t) (t.code)

#endif
