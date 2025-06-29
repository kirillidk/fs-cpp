#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <stdexcept>

namespace fs {

class FileManager {
public:
    explicit FileManager(const std::filesystem::path& filepath);
    ~FileManager();

    FileManager(const FileManager&) = delete;
    FileManager& operator=(const FileManager&) = delete;

    FileManager(FileManager&& other) = default;
    FileManager& operator=(FileManager&& other) = default;

    std::string readLine();
    void writeLine(const std::string& line);
private:
    std::filesystem::path m_filepath;
    std::fstream m_file;

    void openFile();
    void closeFile();
};

}
