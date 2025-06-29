#include <file_manager.hpp>

namespace fs {

FileManager::FileManager(const std::filesystem::path& filepath)
    : m_filepath(filepath) {
    openFile();
}

FileManager::~FileManager() { closeFile(); }

std::string FileManager::readLine() {
    if (!m_file.is_open()) {
        throw std::runtime_error("File is not open for reading");
    }

    std::string line;
    if (!std::getline(m_file, line)) {
        if (m_file.eof()) {
            throw std::runtime_error("End of file reached");
        }
        throw std::runtime_error("Failed to read line from file");
    }
    return line;
}

void FileManager::writeLine(const std::string& line) {
    if (!m_file.is_open()) {
        throw std::runtime_error("File is not open for writing");
    }

    m_file << line << std::endl;
    if (!m_file) {
        throw std::runtime_error("Failed to write line to file");
    }

    m_file.clear();
    m_file.seekg(0, std::ios::beg);
}

void FileManager::openFile() {
    if (m_filepath.has_parent_path()) {
        std::filesystem::create_directories(m_filepath.parent_path());
    }

    m_file.open(m_filepath, std::ios::in | std::ios::out | std::ios::app);
    if (!m_file.is_open()) {
        throw std::runtime_error("Failed to open file: " + m_filepath.string());
    }
}

void FileManager::closeFile() {
    if (m_file.is_open()) {
        m_file.close();
    }
}

}
