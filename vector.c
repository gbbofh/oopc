#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VECTOR_INIT (8)

static char* _create_string(vector* obj);

/**
 * Virtual method table for vector
 */
static struct vector_vmt vmt = {

        _create_string
};

/**
 * Constructor for vector
 */
vector* vector_init(vector* self, int esize)
{
        object_init((object*)self);

        self->vmt = (struct vector_vmt*)self->base.vmt;

        if(self != NULL) {

                self->vmt = &vmt;
        }

        self->esize = esize;
        self->nelem = 0;
        self->melem = 0;
        self->data = NULL;

        return self;
}

/**
 * Destructor for vector
 */
void vector_term(vector* self)
{
        object_term((object*)self);

        self->vmt = NULL;

        free(self->data);
        self->data = NULL;
        self->melem = 0;
        self->nelem = 0;
        self->esize = 0;
}


void vector_append(vector* self, void* data)
{
        if(self->nelem == self->melem) {

                void* tmp;

                self->melem = self->melem == 0 ? VECTOR_INIT : 2 * self->melem;
                tmp = realloc(self->data, self->melem * self->esize);

                if(!tmp) goto vector_realloc_failed;

                self->data = tmp;
        }

        memcpy(self->data + self->nelem * self->esize, data, self->esize);
        self->nelem++;

vector_realloc_failed:
        return;
}


void vector_pop(vector* self, void* dest)
{
        if(self->data && self->nelem > 0) {

                memcpy(dest, self->data +
                                (self->nelem - 1) * self->esize, self->esize);
        }

        self->nelem = self->nelem > 0 ? self->nelem - 1 : self->nelem;
}


int vector_is_empty(vector* self)
{
        return !(self->nelem > 0);
}

/**
 * Constructs and returns a string for printing
 * Should be freed by the user
 */
static char* _create_string(vector* vec)
{
        char buf[512];
        char* vec_fmt = "<vector@%p esize=%u nelem=%u melem=%u/>";

        char* result;

        size_t len;

        len = snprintf(buf, 512, vec_fmt, vec,
                        vec->esize, vec->nelem, vec->melem);

        result = malloc((len + 1) * sizeof(char));
        strncpy(result, buf, len);
}

