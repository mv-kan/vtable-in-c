#include "cat.h"
#include <stdlib.h>
#include <stdio.h>

void cat_string(cat_t *cat, char *str)
{
    sprintf(str, "<class=cat, name=%s age=%zu>", cat->animal.name, cat->age);
}
// unfortunately in this demo we have to manually create vtables for each class
vtbl_t *cat_get_vtable()
{
    static vtbl_t *result = NULL;
    // run only once
    if (!result)
    {
        result = vtbl_create();
        vtbl_add(result, "obj_string_virt", (anyfn_t)cat_string);
        vtbl_add(result, "obj_delete_virt", (anyfn_t)animal_delete);
    }
    return result;
}

cat_t *cat_create(char *name, size_t age)
{
    cat_t *cat = malloc(sizeof(cat_t));
    // I could implement feature of calling parent constructor here
    // but it s not needed
    strncpy(cat->animal.name, name, ANIMAL_MAX_NAME);

    // set vptr to our const vtable, this is ugly I know
    cat->animal.obj.vptr = cat_get_vtable();
    cat->age = age;

    return cat;
}
