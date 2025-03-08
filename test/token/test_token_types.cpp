#include "token/comment_type.hpp"
#include "token/constant_type.hpp"
#include "token/eof_or_illegal_type.hpp"
#include "token/ident_type.hpp"
#include "token/keyword_type.hpp"
#include "token/operator_type.hpp"
#include "token/preprocessor.hpp"
#include "token/separator_type.hpp"
#include "token/token_type.hpp"
#include <gtest/gtest.h>
#include <string>

namespace {

// 测试KeywordType枚举
TEST(TokenTypesTest, KeywordTypeEnum) {
  // 验证KeywordType枚举值
  EXPECT_NE(mycompiler::KeywordType::FUNC, mycompiler::KeywordType::LET);
  EXPECT_NE(mycompiler::KeywordType::IF, mycompiler::KeywordType::ELSE);
  EXPECT_NE(mycompiler::KeywordType::FOR, mycompiler::KeywordType::WHILE);
  EXPECT_NE(mycompiler::KeywordType::RETURN, mycompiler::KeywordType::FUNC);
}

// 测试Keyword类
TEST(TokenTypesTest, KeywordClass) {
  mycompiler::Keyword keyword(mycompiler::KeywordType::IF);
  EXPECT_EQ(keyword.keywordType_, mycompiler::KeywordType::IF);
  
  mycompiler::Keyword forKeyword(mycompiler::KeywordType::FOR);
  EXPECT_EQ(forKeyword.keywordType_, mycompiler::KeywordType::FOR);
}

// 测试OperatorType枚举
TEST(TokenTypesTest, OperatorTypeEnum) {
  // 验证OperatorType枚举值
  EXPECT_NE(mycompiler::OperatorType::PLUS, mycompiler::OperatorType::SUB);
  EXPECT_NE(mycompiler::OperatorType::MUL, mycompiler::OperatorType::DIV);
  EXPECT_NE(mycompiler::OperatorType::EQUAL, mycompiler::OperatorType::DOUBLE_EQUAL);
  EXPECT_NE(mycompiler::OperatorType::NOT_EQUAL, mycompiler::OperatorType::HAT);
  EXPECT_NE(mycompiler::OperatorType::SELF_ADD, mycompiler::OperatorType::SELF_SUB);
  EXPECT_NE(mycompiler::OperatorType::NOT, mycompiler::OperatorType::PLUS);
}

// 测试Operator类
TEST(TokenTypesTest, OperatorClass) {
  mycompiler::Operator op(mycompiler::OperatorType::PLUS);
  EXPECT_EQ(op.operatorType_, mycompiler::OperatorType::PLUS);
  
  mycompiler::Operator mulOp(mycompiler::OperatorType::MUL);
  EXPECT_EQ(mulOp.operatorType_, mycompiler::OperatorType::MUL);
}

// 测试EofOrIllegalType枚举
TEST(TokenTypesTest, EofOrIllegalTypeEnum) {
  // 验证EofOrIllegalType枚举值
  EXPECT_NE(mycompiler::EofOrIllegalType::EOF_, mycompiler::EofOrIllegalType::ILLEGAL);
}

// 测试EofOrIllegal类
TEST(TokenTypesTest, EofOrIllegalClass) {
  mycompiler::EofOrIllegal eof(mycompiler::EofOrIllegalType::EOF_);
  EXPECT_EQ(eof.eofOrIllegalType_, mycompiler::EofOrIllegalType::EOF_);
  
  mycompiler::EofOrIllegal illegal(mycompiler::EofOrIllegalType::ILLEGAL);
  EXPECT_EQ(illegal.eofOrIllegalType_, mycompiler::EofOrIllegalType::ILLEGAL);
}

// 测试Constant类
TEST(TokenTypesTest, ConstantClass) {
  std::string value = "123";
  mycompiler::Constant constant(value);
  EXPECT_EQ(constant.value_, value);
  
  std::string floatValue = "3.14";
  mycompiler::Constant floatConstant(floatValue);
  EXPECT_EQ(floatConstant.value_, floatValue);
}

// 测试Comment类
TEST(TokenTypesTest, CommentClass) {
  std::string value = "// This is a comment";
  mycompiler::Comment comment(value);
  EXPECT_EQ(comment.value_, value);
  
  std::string multilineComment = "/* This is a\nmultiline comment */";
  mycompiler::Comment mlComment(multilineComment);
  EXPECT_EQ(mlComment.value_, multilineComment);
}

// 测试Identifier类
TEST(TokenTypesTest, IdentifierClass) {
  std::string value = "variableName";
  mycompiler::Identifier identifier(value);
  EXPECT_EQ(identifier.value_, value);
  
  std::string funcName = "calculateSum";
  mycompiler::Identifier funcIdentifier(funcName);
  EXPECT_EQ(funcIdentifier.value_, funcName);
}

// 测试Preprocessor类
TEST(TokenTypesTest, PreprocessorClass) {
  std::string value = "#include <iostream>";
  mycompiler::Preprocessor preprocessor(value);
  EXPECT_EQ(preprocessor.value_, value);
  
  std::string define = "#define MAX_SIZE 100";
  mycompiler::Preprocessor definePreprocessor(define);
  EXPECT_EQ(definePreprocessor.value_, define);
}

// 测试Separator类
TEST(TokenTypesTest, SeparatorClass) {
  std::string value = ";";
  mycompiler::Separator separator(value);
  EXPECT_EQ(separator.value_, value);
  
  std::string bracket = "{";
  mycompiler::Separator bracketSeparator(bracket);
  EXPECT_EQ(bracketSeparator.value_, bracket);
}

// 测试TokenType枚举
TEST(TokenTypesTest, TokenTypeEnum) {
  // 验证TokenType枚举值
  EXPECT_NE(mycompiler::TokenType::ILLEGAL_OR_EOF, mycompiler::TokenType::IDENT);
  EXPECT_NE(mycompiler::TokenType::CONSTANT, mycompiler::TokenType::KEYWORD);
  EXPECT_NE(mycompiler::TokenType::OPERATOR, mycompiler::TokenType::SEPARATOR);
  EXPECT_NE(mycompiler::TokenType::COMMENT, mycompiler::TokenType::PREPROCESSOR);
}

} // namespace 