# What is this?
This is a simple example of implemented some object-oriented design principles
into the development of C applications -- particularly in creation of data
structures. This was mostly done in an effort to better learn how languages like
C++ implement features like polymorphism -- I don't typically go the whole route
of implementing virtual method tables in most of my code, unless it proves
beneficial in some way or another.

# About the repository
Each of the source files in this repository provides an implementation for an
interface which is defined in the corresponding header file. The header files
define two structures, each: One corresponding to the type, and one
corresponding to the virtual method table for that type. With the current
implementation there is a bug in that the virtual method table does not work
correctly when casting to parent structure types. I.e.,

```c
    object* real_str = string_create("Hello, World");
    char* cstr = real_str->vmt->to_cstring();
```

Will invoke `object->vmt->to\_cstring()`. There are several possible fixes for this,
depeding on desired functionality. One such fix would be to overwrite the base
vmt pointer, and require an explicit call to the parent method; this is similar
to what would be expected in real object oriented languaged like C++:

```c
    MyBaseClass::method()
```
