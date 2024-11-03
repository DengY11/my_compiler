#include "file_reader/reader.hpp"
#include <fstream>
#include <stdexcept>

namespace mycompiler {

FileReader::FileReader(const std::string &filePath) : filePath_(filePath) {}

auto FileReader::readFile() const -> std::string {
  std::ifstream file(filePath_, std::ios::binary);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filePath_);
  }
  std::stringstream buffer;
  buffer << file.rdbuf();

  std::string content = buffer.str();
  file.close();

  return content;
}

} // namespace mycompiler
