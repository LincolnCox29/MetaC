#pragma once
#include <stddef.h>

typedef struct MCString MCString;

struct MCString 
{
    void* _internal;
};

void MCString_print(const MCString* self);
void MCString_replace(MCString* self, const size_t index, const char c);
void MCString_delete(MCString* self, const size_t index);
void MCString_push_back(MCString* self, const char value);
char MCString_at(MCString* self, const size_t index);
size_t MCString_length(const MCString* self);
void MCString_free(MCString* self);
MCString MCString_create(const char* str);