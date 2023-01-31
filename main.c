#include <stdio.h>
#include "animal.h"
#include "obj.h"

void test1()
{
    obj_t *animal = (obj_t *)animal_create("Murzik");

    char buf[100];
    obj_string_virt(animal, buf);
    printf("%s\n", buf);

    obj_delete_virt(animal);
}

#define SIZE 3
void test2()
{
    obj_t *animal[SIZE] = {(obj_t *)animal_create("Murzik"),
                           (obj_t *)animal_create("Chernysh"),
                           (obj_t *)animal_create("Kot")};
    char buf[100];
    for (size_t i = 0; i < SIZE; i++)
    {
        obj_string_virt(animal[i], buf);
        printf("animal#%zu: %s\n", i, buf);
    }

    // destroy all
    for (size_t i = 0; i < SIZE; i++)
    {
        obj_delete_virt(animal[i]);
    }
}

int main()
{
    test2();
}