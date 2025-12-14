Dynamic Function Loading in C++ with dlfcn

This repository demonstrates how to load a shared library at runtime in C++ and call its functions without linking against the library at build time.

The example uses dlopen to load a .so file dynamically and dlsym to resolve a function symbol by name, which is then cast to a function pointer and invoked like a regular C++ function. The function implementation lives entirely in a separate shared object and is only accessed when the program runs.

This approach is commonly used for plugin systems, optional dependencies, and modular architectures where flexibility and late binding are important.

Project Structure
.
├── mylib.cpp    # Shared library implementation
├── main.cpp     # Runtime loader using dlopen / dlsym
├── README.md

Build Instructions
Build the shared library
g++ -fPIC -shared mylib.cpp -o libmylib.so

Build the executable
g++ main.cpp -o main -ldl

Run
./main

Key Idea

Instead of resolving symbols at link time, the program loads the shared object dynamically and looks up function addresses at runtime. This allows the main binary to remain independent of the library until execution.

Platform Notes

This example uses the POSIX dlfcn API and works on Linux and other Unix-like systems.
