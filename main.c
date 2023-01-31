#include <stdio.h>
#include "animal.h"
#include "obj.h"
int main()
{
    animal_t* animal = animal_create("haha");

    char buf[100];
    obj_string_virt(buf, (obj_t*)animal);

    printf("%s\n", buf);
}