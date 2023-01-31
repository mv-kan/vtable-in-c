#include <stdio.h>
#include "ventry.h"
#include "vtbl.h"

int mymax(int a, int b) {
    return a > b ? a : b;
}

int main() {
    vtbl_t*vtable = vtbl_create();

    vtbl_add(vtable, "max", (anyfn_t)mymax);
    anyfn_t fn = vtbl_get_fn(vtable, "max");

    int a = (*((int(*)(int, int))fn))(100, 1);

    printf("%d\n", a);
    vtbl_delete(vtable);
}