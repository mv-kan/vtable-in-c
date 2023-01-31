#include <stdio.h>
#include "animal.h"
#include "obj.h"
int main()
{
    obj_t* animal = (obj_t*)animal_create("Murzik");

    char buf[100];
    obj_string_virt(animal, buf);

    printf("%s\n", buf);
}