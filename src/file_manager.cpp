#include <filesystem>
#include <fstream>

#include <file_manager.hpp>

namespace fs {

class FileManager::Impl {
public:
    explicit Impl(const std::string& path) : filepath(path) { openFile(); }

    ~Impl() { closeFile(); }

    std::string readLine() {
        if (!file.is_open()) {
            throw std::runtime_error("File is not open for reading");
        }

        std::string line;
        if (!std::getline(file, line)) {
            if (file.eof()) {
                throw std::runtime_error("End of file reached");
            }
            throw std::runtime_error("Failed to read line from file");
        }
        return line;
    }

    void writeLine(const std::string& line) {
        if (!file.is_open()) {
            throw std::runtime_error("File is not open for writing");
        }

        file << line << std::endl;
        if (!file) {
            throw std::runtime_error("Failed to write line to file");
        }

        file.clear();
        file.seekg(0, std::ios::beg);
    }
private:
    std::filesystem::path filepath;
    std::fstream file;

    void openFile() {
        if (filepath.has_parent_path()) {
            std::filesystem::create_directories(filepath.parent_path());
        }

        file.open(filepath, std::ios::in | std::ios::out | std::ios::app);
        if (!file.is_open()) {
            throw std::runtime_error(
                "Failed to open file: " + filepath.string()
            );
        }
    }

    void closeFile() {
        if (file.is_open()) {
            file.close();
        }
    }
};

FileManager::FileManager(const std::string& filepath)
    : m_pImpl(std::make_unique<Impl>(filepath)) {}

FileManager::~FileManager() = default;

FileManager::FileManager(FileManager&& other) = default;
FileManager& FileManager::operator=(FileManager&& other) = default;

std::string FileManager::readLine() { return m_pImpl->readLine(); }

void FileManager::writeLine(const std::string& line) {
    m_pImpl->writeLine(line);
}

}
