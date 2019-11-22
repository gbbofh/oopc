#ifndef STR_H
#define STR_H

struct string;

struct string_vmt {

        char* (*to_cstring)(struct string* self);
};

typedef struct string {

        struct object base;
        struct string_vmt* vmt;

        int length;
        char* data;

} string;


string* string_init(string* self, const char* str);
void string_term(string* self);

#endif

