#ifndef OBJ_H
#define OBJ_H

#define object_create() object_init(malloc(sizeof(struct object)))
#define object_delete(o) do { object_term(o); free(o); } while(0)

struct object;

struct object_vmt {

        char* (*to_cstring)(struct object* self);
};

typedef struct object {

        struct object_vmt* vmt;

} object;


object* object_init(object* self);
void object_term(object* self);

#endif

