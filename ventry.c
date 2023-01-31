#include "ventry.h"
#include <stdlib.h>

ventry_t *ventry_create(char *symbol, anyfn_t fn)
{
    // max symbol len is set to 100
    const size_t max_symbol_len = VENTRY_MAX_SYMBOL_LEN;
    assert(fn != NULL);
    assert(strlen(symbol) < max_symbol_len);

    ventry_t *ventr = malloc(sizeof(ventry_t));
    ventr->fn = NULL;
    strncpy(ventr->symbol, symbol, max_symbol_len);

    ventr->fn = fn;
    return ventr;
}

void ventry_delete(ventry_t *ventry)
{
    // this is demonstration of vtables in c 
    // so we don't need proper error handling
    assert(ventry != NULL);
    free(ventry);
}
