#ifndef VECTOR_H
#define VECTOR_H

#include "obj.h"

struct vector;

struct vector_vmt {

        char* (*to_cstring)(struct vector* self);
};

typedef struct vector {

        struct object base;

        struct vector_vmt* vmt;

        int nelem;
        int melem;
        int esize;
        void* data;

} vector;

vector* vector_init(vector* self, int esize);
void vector_term(vector* self);

void vector_append(vector* self, void* data);
void vector_pop(vector* self, void* dest);

int vector_is_empty(vector* self);

#endif

