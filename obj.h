#if !defined(OBJ_H)
#define OBJ_H

#include "vtbl.h"
// no need vtable for obj class because we cannot create obj instances
struct obj_s {
    vtbl_t* vptr;
};

typedef struct obj_s obj_t;

// pure virtual function
// symbol: "obj_delete_virt"
// fn ptr type: void(*)(obj_t*)
void obj_delete_virt(obj_t*obj);

// pure virtual function
// symbol: "obj_string_virt"
void obj_string_virt(char*str, obj_t *obj);

#endif // OBJ_H
