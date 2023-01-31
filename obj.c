#include "obj.h"

void obj_delete_virt(obj_t *obj)
{
    assert(obj != NULL);
    // search in vtable for symbol delete
    anyfn_t anyfn = vtbl_get_fn(obj->vptr, "delete");
    // cast anyfn to obj_delete func type 
    void (*delete_fn)(obj_t *) = (void (*)(obj_t *)) anyfn;
    // call this func
    (*delete_fn)(obj);
}