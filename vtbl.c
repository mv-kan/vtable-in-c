#include "vtbl.h"
#include <assert.h>
#include <stdlib.h>
vtbl_t *vtbl_create()
{
    vtbl_t *vtable = malloc(sizeof(vtbl_t));
    vtable->len = 0;
    return vtable;
}

void vtbl_delete(vtbl_t *vtable)
{
    assert(vtable != NULL);
    for (size_t i = 0; i < vtable->len; i++)
    {
        ventry_delete(vtable->entrs[i]);
    }
    free(vtable);    
}

void vtbl_add(vtbl_t *vtable, char *symbol, anyfn_t fn)
{
    assert(vtable != NULL);
    assert(vtable->len < VTBL_MAX_VENTRIES);
    ventry_t *ventr = ventry_create(symbol, fn);

    vtable->entrs[vtable->len] = ventr;
    vtable->len++;
}

anyfn_t vtbl_get_fn(vtbl_t *vtable, char *symbol)
{
    for (size_t i = 0; i < vtable->len; i++)
    {
        if (!strcmp(vtable->entrs[i]->symbol, symbol))
        {
            return vtable->entrs[i]->fn;
        }
    }
    // this may be handled somewhere but I don't want to shoot in my leg that bad that I will throw an error everytime we didn't find the symbol
    assert(0);
    return NULL;
}