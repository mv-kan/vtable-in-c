# vtable in C 

This is simple implementation of vtables in pure C. Also we have here semi-inheritance and polymorphism. And all of that cool stuff in pure C! But to be honest I think this implementation is too complicated to be used anywhere. This is just merely demonstration of what we can do in C. 

## How was implemented?

`vtbl.h` is vtable and `ventry.h` is one entry in the table.

`obj.h` has `vpointer` that points to `vtbl.h`

`obj.h` is parent for `animal.h`. `animal.h` is a parent for `cat.h`. `obj.h` has pure virtual functions, `animal.h` overloads them, and `cat.h` overloads `animal.h` implementation.

`obj.h` present in all "classes" and `obj.h` has `vpointer`, thus each class from animal to cat has vpointer.

Each class (except obj) has its own vtable (one for all instances). You should look into `animal_get_vtable` function in `animal.c` and see how I used it in `animal_create` function. After that a lot of things will become much clearer.

## How to run it? 

You need `gcc` compiler that supports c17 and `make` command on your linux machine.

```
cd <DIRECTORY WHERE MAKEFILE IS>/
make run 
```
