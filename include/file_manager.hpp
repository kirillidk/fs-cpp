#pragma once

#include <string>
#include <memory>  // std::unique_ptr

namespace fs {

class FileManager {
public:
    explicit FileManager(const std::string& filepath);
    ~FileManager();

    FileManager(const FileManager&) = delete;
    FileManager& operator=(const FileManager&) = delete;

    FileManager(FileManager&& other);
    FileManager& operator=(FileManager&& other);

    std::string readLine();
    void writeLine(const std::string& line);
private:
    class Impl;
    std::unique_ptr<Impl> m_pImpl;
};

}
