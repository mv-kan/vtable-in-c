#if !defined(ANIMAL_H)
#define ANIMAL_H

#include "obj.h"

#define ANIMAL_MAX_NAME 100

vtbl_t *animal_get_vtable();

// each class has object field
// technically animal_t is child of obj
struct animal_s
{
    obj_t obj;
    char name[ANIMAL_MAX_NAME];
};
typedef struct animal_s animal_t;

// overloads obj_class_name_virt
void animal_string(animal_t *animal, char *str);

animal_t *animal_create(char *name);

void animal_delete(animal_t*animal);

#endif // ANIMAL_H
