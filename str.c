#include "obj.h"
#include "str.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* _create_string(string* str);

/**
 * Virtual method table for string
 */
static struct string_vmt vmt = {

        _create_string
};

/**
 * Constructor for string
 */
string* string_init(string* self, const char* str)
{
        object_init((object*)self);

        /**
         * Caveat: Needs to match the order of the parent vmt
         */
        self->vmt = (struct string_vmt*)self->base.vmt;

        if(self != NULL) {

                self->vmt = &vmt;
        }

        self->length = strlen(str) + 1;
        self->data = malloc(self->length);
        strncpy(self->data, str, self->length);

        return self;
}

/**
 * Destructor for string
 */
void string_term(string* self)
{
        object_term((object*)self);
        self->vmt = NULL;
        free(self->data);

        self->data = NULL;
        self->length = 0;
}

/**
 * Constructs and returns a string for printing
 * Should be freed by the user
 */
static char* _create_string(string* str)
{
        char* result;

        result = malloc(str->length * sizeof(char));
        strncpy(result, str->data, str->length);
}

