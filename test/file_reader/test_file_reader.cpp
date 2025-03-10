#include "file_reader/reader.hpp"
#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>

// 创建临时测试文件
class FileReaderTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 创建临时测试文件
        testFilePath = "test_file.txt";
        std::ofstream file(testFilePath);
        file << "Line 1\n";
        file << "Line 2\n";
        file << "Line 3\n";
        file << "Line 4\n";
        file << "Line 5\n";
        file.close();
    }

    void TearDown() override {
        // 删除临时测试文件
        if (std::filesystem::exists(testFilePath)) {
            std::filesystem::remove(testFilePath);
        }
    }

    std::string testFilePath;
};

// 测试构造函数
TEST_F(FileReaderTest, Constructor) {
    mycompiler::FileReader reader(testFilePath);
    EXPECT_EQ(reader.getFilePath(), testFilePath);
}

// 测试读取整个文件
TEST_F(FileReaderTest, ReadFile) {
    mycompiler::FileReader reader(testFilePath);
    std::string content = reader.readFile();
    EXPECT_EQ(content, "Line 1\nLine 2\nLine 3\nLine 4\nLine 5\n");
}

// 测试读取特定行
TEST_F(FileReaderTest, ReadLine) {
    mycompiler::FileReader reader(testFilePath);
    EXPECT_EQ(reader.readLine(1), "Line 1");
    EXPECT_EQ(reader.readLine(3), "Line 3");
    EXPECT_EQ(reader.readLine(5), "Line 5");
}

// 测试读取特定行范围
TEST_F(FileReaderTest, ReadLines) {
    mycompiler::FileReader reader(testFilePath);
    EXPECT_EQ(reader.readLines(2, 4), "Line 2\nLine 3\nLine 4");
    EXPECT_EQ(reader.readLines(1, 2), "Line 1\nLine 2");
    EXPECT_EQ(reader.readLines(4, 5), "Line 4\nLine 5");
}

// 测试获取行数
TEST_F(FileReaderTest, GetLineCount) {
    mycompiler::FileReader reader(testFilePath);
    EXPECT_EQ(reader.getLineCount(), 5);
}

// 测试文件是否存在
TEST_F(FileReaderTest, FileExists) {
    mycompiler::FileReader reader(testFilePath);
    EXPECT_TRUE(reader.fileExists());
    
    mycompiler::FileReader nonExistentReader("non_existent_file.txt");
    EXPECT_FALSE(nonExistentReader.fileExists());
}

// 测试获取文件大小
TEST_F(FileReaderTest, GetFileSize) {
    mycompiler::FileReader reader(testFilePath);
    EXPECT_GT(reader.getFileSize(), 0);
}

// 测试获取文件行列表
TEST_F(FileReaderTest, GetLines) {
    mycompiler::FileReader reader(testFilePath);
    std::vector<std::string> lines = reader.getLines();
    EXPECT_EQ(lines.size(), 5);
    EXPECT_EQ(lines[0], "Line 1");
    EXPECT_EQ(lines[2], "Line 3");
    EXPECT_EQ(lines[4], "Line 5");
}

// 测试异常情况
TEST_F(FileReaderTest, Exceptions) {
    mycompiler::FileReader reader("non_existent_file.txt");
    
    // 测试读取不存在的文件
    EXPECT_THROW(reader.readFile(), std::runtime_error);
    
    // 测试读取超出范围的行
    mycompiler::FileReader validReader(testFilePath);
    EXPECT_THROW(validReader.readLine(10), std::runtime_error);
    
    // 测试读取无效的行范围
    EXPECT_THROW(validReader.readLines(10, 15), std::runtime_error);
    EXPECT_THROW(validReader.readLines(5, 3), std::runtime_error);
    
    // 测试获取不存在文件的大小
    EXPECT_THROW(reader.getFileSize(), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 