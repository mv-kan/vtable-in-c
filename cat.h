#if !defined(CAT_H)
#define CAT_H

#include "animal.h"

vtbl_t* cat_get_vtable();

struct cat_s {
    // inherit traits from animal
    animal_t animal;
    size_t age;
};
typedef struct cat_s cat_t;
cat_t *cat_create(char *name, size_t age);
void cat_string(cat_t *cat, char *str);
void cat_delete(cat_t*cat);

#endif // CAT_H
