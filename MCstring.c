#include "MCstring.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INTERNAL (struct StringData*)self->_internal

struct StringData 
{
    char* buffer;
    size_t length;
};

static void _print(const String* self) 
{
    struct StringData* data = INTERNAL;
    if (data && data->buffer)
        printf("%s\n", data->buffer);
}

static void _replace(String* self, size_t index, char c) 
{
    struct StringData* data = INTERNAL;
    if (data && data->buffer && index < data->length)
        data->buffer[index] = c;
}

static void _free(String* self)
{
    if (!self) return;

    struct StringData* data = (struct StringData*)self->_internal;
    if (data)
    {
        free(data->buffer);
        data->buffer = NULL;
        data->length = 0;
        free(data);
        self->_internal = NULL;
    }
}

static size_t _length(const String* self) 
{
    struct StringData* data = INTERNAL;
    return data ? data->length : 0;
}

String string_create(const char* str) 
{
    struct StringData* internal = malloc(sizeof(struct StringData));
    internal->length = str ? strlen(str) : 0;
    internal->buffer = malloc(internal->length + 1);
    if (str) 
        memcpy(internal->buffer, str, internal->length + 1);

    return (String) 
    {
        .print = _print,
        .replace = _replace,
        .length = _length,
        .free = _free,
        ._internal = internal
    };
}