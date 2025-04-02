#pragma once
#include <stddef.h>

typedef struct String String;

struct String 
{
    void (*print)(const String* self);
    void (*replace)(String* self, size_t index, char c);
    void (*free)(String* self);
    size_t(*length)(const String* self);

    void* _internal;
};

String string_create(const char* str);