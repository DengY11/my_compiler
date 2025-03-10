#ifndef READER_HPP
#define READER_HPP
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace mycompiler {

/**
 * @brief 文件读取器类，负责读取源代码文件
 */
class FileReader {

public:
  /**
   * @brief 构造函数
   * @param filepath 文件路径
   */
  explicit FileReader(const std::string &filepath);

  /**
   * @brief 读取整个文件内容
   * @return 文件内容字符串
   * @throws std::runtime_error 如果文件无法打开
   */
  auto readFile() const -> std::string;

  /**
   * @brief 读取文件的特定行
   * @param lineNumber 行号（从1开始）
   * @return 指定行的内容
   * @throws std::runtime_error 如果文件无法打开或行号无效
   */
  auto readLine(std::size_t lineNumber) const -> std::string;

  /**
   * @brief 读取文件的多行
   * @param startLine 起始行号（从1开始）
   * @param endLine 结束行号（包含）
   * @return 指定行范围的内容
   * @throws std::runtime_error 如果文件无法打开或行号无效
   */
  auto readLines(std::size_t startLine, std::size_t endLine) const -> std::string;

  /**
   * @brief 获取文件的总行数
   * @return 文件的总行数
   * @throws std::runtime_error 如果文件无法打开
   */
  auto getLineCount() const -> std::size_t;

  /**
   * @brief 检查文件是否存在
   * @return 如果文件存在，则返回true；否则返回false
   */
  auto fileExists() const -> bool;

  /**
   * @brief 获取文件大小（字节）
   * @return 文件大小
   * @throws std::runtime_error 如果文件无法打开
   */
  auto getFileSize() const -> std::size_t;

  /**
   * @brief 获取文件路径
   * @return 文件路径
   */
  auto getFilePath() const -> std::string;

  /**
   * @brief 将文件内容按行分割
   * @return 文件内容的行列表
   * @throws std::runtime_error 如果文件无法打开
   */
  auto getLines() const -> std::vector<std::string>;

private:
  std::string filePath_;  // 文件路径
};

} // namespace mycompiler

#endif
