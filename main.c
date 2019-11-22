#include <stdio.h>
#include <stdlib.h>

#include "obj.h"
#include "str.h"
#include "vector.h"

int main()
{

        char* obj_str;
        struct object obj;
        struct string str;
        struct vector vec;

        object_init(&obj);

        obj_str = obj.vmt->to_cstring(&obj);
        printf("%s\n", obj_str);
        free(obj_str);

        object_term(&obj);

        string_init(&str, "Hello, World!");

        obj_str = str.vmt->to_cstring(&str);
        printf("%s\n", obj_str);
        free(obj_str);

        vector_init(&vec, sizeof(struct string));

        vector_append(&vec, &str);

        obj_str = vec.vmt->to_cstring(&vec);
        printf("%s\n", obj_str);
        free(obj_str);

        vector_term(&vec);

        string_term(&str);


}

