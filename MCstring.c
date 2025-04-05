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

void MCString_print(const MCString* self)
{
    struct StringData* data = INTERNAL;
    if (data && data->buffer)
        printf("%s\n", data->buffer);
}

void MCString_replace(MCString* self, const size_t index, const char c)
{
    struct StringData* data = INTERNAL;
    if (data && data->buffer && index < data->length)
        data->buffer[index] = c;
}

void MCString_delete(MCString* self, const size_t index)
{
    struct StringData* data = INTERNAL;
    if (data || data->buffer || index <= data->length)
    {
        for (size_t i = index; i < data->length - 1; i++)
            data->buffer[i] = data->buffer[i + 1];
        data->length--;
        data->buffer[data->length] = '\0';
        char* newBuffer = realloc(data->buffer, data->length + 1);
        if (newBuffer)
            data->buffer = newBuffer;
    }
}

void MCString_push_back(MCString* self, const char value)
{
    struct StringData* data = INTERNAL;
    if (data && data->buffer)
    {
        char* newBuffer = realloc(data->buffer, data->length + 2);
        if (newBuffer)
        {
            data->buffer = newBuffer;
            data->buffer[data->length] = value;
            data->buffer[data->length + 1] = '\0';
            data->length++;
        }
    }
}

size_t MCString_length(const MCString* self)
{
    struct StringData* data = INTERNAL;
    return data ? data->length : 0;
}

void MCString_free(MCString* self)
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

MCString MCString_create(const char* str)
{
    struct StringData* internal = malloc(sizeof(struct StringData));
    internal->length = str ? strlen(str) : 0;
    internal->buffer = malloc(internal->length + 1);
    if (str) 
        memcpy(internal->buffer, str, internal->length + 1);

    return (MCString)
    {
        ._internal = internal
    };
}