#if !defined(VTBL_H)
#define VTBL_H

#include "ventry.h"

#define VTBL_MAX_VENTRIES 100

struct vtbl_s
{
    ventry_t*entrs[VTBL_MAX_VENTRIES];
    size_t len;
};

typedef struct vtbl_s vtbl_t;

// creates vtable
vtbl_t*vtbl_create();

void vtbl_delete(vtbl_t* vtable);

// add to entries another function, also increments len
void vtbl_add(vtbl_t *vtable, char *symbol, anyfn_t fn);

// get anyfn pointer by symbol
anyfn_t vtbl_get_fn(vtbl_t *vtable, char *symbol);

#endif // VTBL_H
