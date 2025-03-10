#include "file_reader/reader.hpp"
#include <fstream>
#include <stdexcept>
#include <filesystem>

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

auto FileReader::readLine(std::size_t lineNumber) const -> std::string {
  std::ifstream file(filePath_);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filePath_);
  }

  std::string line;
  std::size_t currentLine = 0;

  while (std::getline(file, line)) {
    currentLine++;
    if (currentLine == lineNumber) {
      file.close();
      return line;
    }
  }

  file.close();
  throw std::runtime_error("Line number " + std::to_string(lineNumber) + " out of range");
}

auto FileReader::readLines(std::size_t startLine, std::size_t endLine) const -> std::string {
  if (startLine > endLine) {
    throw std::runtime_error("Start line cannot be greater than end line");
  }

  std::ifstream file(filePath_);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filePath_);
  }

  std::string line;
  std::string result;
  std::size_t currentLine = 0;

  while (std::getline(file, line)) {
    currentLine++;
    if (currentLine >= startLine && currentLine <= endLine) {
      result += line;
      if (currentLine < endLine) {
        result += "\n";
      }
    }
    if (currentLine > endLine) {
      break;
    }
  }

  file.close();
  
  if (currentLine < startLine) {
    throw std::runtime_error("Start line " + std::to_string(startLine) + " out of range");
  }

  return result;
}

auto FileReader::getLineCount() const -> std::size_t {
  std::ifstream file(filePath_);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filePath_);
  }

  std::string line;
  std::size_t lineCount = 0;

  while (std::getline(file, line)) {
    lineCount++;
  }

  file.close();
  return lineCount;
}

auto FileReader::fileExists() const -> bool {
  return std::filesystem::exists(filePath_);
}

auto FileReader::getFileSize() const -> std::size_t {
  if (!fileExists()) {
    throw std::runtime_error("File does not exist: " + filePath_);
  }
  
  return std::filesystem::file_size(filePath_);
}

auto FileReader::getFilePath() const -> std::string {
  return filePath_;
}

auto FileReader::getLines() const -> std::vector<std::string> {
  std::ifstream file(filePath_);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filePath_);
  }

  std::vector<std::string> lines;
  std::string line;

  while (std::getline(file, line)) {
    lines.push_back(line);
  }

  file.close();
  return lines;
}

} // namespace mycompiler
