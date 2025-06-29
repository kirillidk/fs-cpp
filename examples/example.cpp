#include <file_manager.hpp>
#include <iostream>
#include <string>

int main() {
    try {
        fs::FileManager file("data/example.txt");

        file.writeLine("Hello, World!");
        std::string line = file.readLine();

    } catch (const std::exception& e) {
        std::cerr << "std::exception: " << e.what() << '\n';
        return 1;
    }

    return 0;
}