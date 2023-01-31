#if !defined(OBJ_H)
#define OBJ_H

#include "vtbl.h"

// to overload virtual function we need to pass parent object into child implementation
struct obj_s {
    vtbl_t* vptr;
};

typedef struct obj_s obj_t;

// pure virtual function
// symbol: "delete"
// fn ptr type: void(*)(obj_t*)
void obj_delete_virt(obj_t*obj);

#endif // OBJ_H
