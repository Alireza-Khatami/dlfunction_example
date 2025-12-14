#include <iostream>
#include <dlfcn.h>

int main() {
    void* handle = dlopen("./libmylib.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "dlopen error: " << dlerror() << "\n";
        return 1;
    }
    dlerror(); // clear previous errors
    using hello_fn = void(*)(const char*);
    hello_fn hello = reinterpret_cast<hello_fn>(dlsym(handle, "hello"));
    const char* err = dlerror();
    if (err) {
        std::cerr << "dlsym error: " << err << "\n";
        dlclose(handle);
        return 1;
    }
    hello("Alireza");
    dlclose(handle);
    return 0;
}
