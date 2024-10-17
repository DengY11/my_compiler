#ifndef READER_HPP
#define READER_HPP
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace mycompiler {

class FileReader {

public:
  explicit FileReader(const std::string &filepath);

  auto readFile() const -> std::string;

private:
  std::string filePath_;
};

} // namespace mycompiler

#endif
