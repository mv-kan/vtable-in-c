#include "animal.h"
#include <stdio.h>
#include <stdlib.h>

void animal_string(char *str, animal_t*obj)
{
    animal_t *animal = (animal_t *)obj;
    sprintf(str, "<class=animal, name=%s>", animal->name);
}

// inits vtable of animal class
vtbl_t *animal_get_vtable()
{
    static vtbl_t *result = NULL;
    // run only once 
    if (!result) {
        result = vtbl_create();
        vtbl_add(result, "obj_string_virt", (anyfn_t)animal_string);
    }
    return result;
}

animal_t* animal_create(char*name)
{
    animal_t*animal = malloc(sizeof(animal_t));
    // set vptr to our const vtable 
    animal->obj.vptr = animal_get_vtable();
    
    strncpy(animal->name, name, ANIMAL_MAX_NAME);
    
    return animal;
}