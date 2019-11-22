#include "obj.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* _create_string(object* obj);

/**
 * Virtual method table for object
 */
static struct object_vmt vmt = {

        _create_string
};

/**
 * Constructor for object
 */
object* object_init(object* self)
{
        if(self != NULL) {

                self->vmt = &vmt;
        }

        return self;
}

/**
 * Destructor for object
 */
void object_term(object* self)
{
        self->vmt = NULL;
}

/**
 * Constructs and returns a string for printing
 * Should be freed by the user
 */
static char* _create_string(object* obj)
{
        char buf[512];
        char* obj_fmt = "<object@%p/>";

        char* result;

        size_t len;

        len = snprintf(buf, 512, obj_fmt, obj);

        result = malloc((len + 1) * sizeof(char));
        strncpy(result, buf, len);
}

