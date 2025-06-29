# fs-cpp

A simple C++ RAII file system library.

## Usage

```cpp
#include <iostream>
#include <exception>
#include <string>

#include <file_manager.hpp>

int main() {
    try {
        fs::FileManager file("data/example.txt");

        file.writeLine("Hello, World!");
        std::string line = file.readLine();

        std::cout << line << '\n';  // Hello, World!

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
```

## How to build

```bash
cmake -S . -B build && cmake --build build
```

```bash
build/example
```
