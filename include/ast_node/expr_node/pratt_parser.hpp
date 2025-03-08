#ifndef PRATT_PARSER_HPP
#define PRATT_PARSER_HPP

#include "ast_node/basic_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "lexer/lexer.hpp"
#include "token/token.hpp"
#include "token/token_helper_functions.hpp"
#include <functional>
#include <map>
#include <memory>

namespace mycompiler {

// 前向声明
class PrattParser;

// 定义解析函数类型
using PrefixParseFn = std::function<std::shared_ptr<ExprNode>(PrattParser*)>;
using InfixParseFn = std::function<std::shared_ptr<ExprNode>(PrattParser*, std::shared_ptr<ExprNode>)>;

// 操作符优先级枚举
enum class Precedence {
    LOWEST = 0,
    ASSIGNMENT,  // =
    CONDITIONAL, // ?:
    LOGICAL_OR,  // ||
    LOGICAL_AND, // &&
    EQUALITY,    // == !=
    COMPARISON,  // > >= < <=
    TERM,        // + -
    FACTOR,      // * /
    UNARY,       // -x !x
    CALL,        // myFunction(x)
    PRIMARY      // 字面量
};

class PrattParser {
public:
    PrattParser(std::shared_ptr<Lexer> lexer);
    
    // 解析表达式
    std::shared_ptr<ExprNode> parseExpression(Precedence precedence = Precedence::LOWEST);
    
    // 注册前缀和中缀解析函数
    void registerPrefix(TokenType tokenType, PrefixParseFn fn);
    void registerInfix(TokenType tokenType, InfixParseFn fn);
    
    // 获取当前和下一个Token
    Token currentToken();
    Token peekToken();
    
    // 前进到下一个Token
    void nextToken();
    
    // 获取当前Token的优先级
    Precedence currentPrecedence();
    
    // 获取下一个Token的优先级
    Precedence peekPrecedence();
    
    // 获取词法分析器
    std::shared_ptr<Lexer> getLexer() { return lexer_; }

private:
    std::shared_ptr<Lexer> lexer_;
    std::map<TokenType, PrefixParseFn> prefixParseFns_;
    std::map<TokenType, InfixParseFn> infixParseFns_;
    std::map<TokenType, Precedence> precedences_;
    
    // 初始化优先级表
    void initPrecedences();
};

} // namespace mycompiler

#endif // PRATT_PARSER_HPP 