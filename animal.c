#include "animal.h"
#include <stdio.h>
#include <stdlib.h>

void animal_string(animal_t *animal, char *str)
{
    sprintf(str, "<class=animal, name=%s>", animal->name);
}

void animal_delete(animal_t*animal) 
{
    static int i = 0;
    printf("So sad that %s has died!!! Number of dead souls = %d\n", animal->name, ++i);
}

// inits vtable of animal class
vtbl_t *animal_get_vtable()
{
    static vtbl_t *result = NULL;
    // run only once 
    if (!result) {
        result = vtbl_create();
        vtbl_add(result, "obj_string_virt", (anyfn_t)animal_string);
        vtbl_add(result, "obj_delete_virt", (anyfn_t)animal_delete);
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