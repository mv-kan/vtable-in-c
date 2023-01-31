#if !defined(VENTRY_H)
#define VENTRY_H

#include <string.h>
#include <assert.h>

#define VENTRY_MAX_SYMBOL_LEN 100

typedef void (*anyfn_t)(void);

struct ventry_s
{
    // symbol of function like "get_stats" or "name"
    char symbol[VENTRY_MAX_SYMBOL_LEN];

    // one any function pointer
    anyfn_t fn;
};

typedef struct ventry_s ventry_t;

// create ventry for vtbl (vtable)
ventry_t*ventry_create(char *symbol, anyfn_t fn);

void ventry_delete(ventry_t* ventry);

#endif // VENTRY_H
