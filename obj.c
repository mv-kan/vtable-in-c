#include "obj.h"

void obj_delete_virt(obj_t *obj)
{
    assert(obj != NULL);
    // search in vtable for symbol delete
    anyfn_t anyfn = vtbl_get_fn(obj->vptr, "obj_delete_virt");
    // cast anyfn to obj_delete func type
    void (*delete_fn)(obj_t *) = (void (*)(obj_t *))anyfn;
    // call this func
    (*delete_fn)(obj);
}

void obj_string_virt(obj_t *obj, char *str)
{
    assert(obj != NULL);
    // search in vtable for symbol delete
    anyfn_t anyfn = vtbl_get_fn(obj->vptr, "obj_string_virt");
    // cast anyfn to obj_delete func type
    char *(*string_fn)(obj_t *, char *) = (char *(*)(obj_t *, char *))anyfn;
    // call this func
    (*string_fn)(obj, str);
}