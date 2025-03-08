#include "ast_node/expr_node/pratt_parser.hpp"
#include "ast_node/expr_node/binary_expr.hpp"
#include "ast_node/expr_node/group_expr_node.hpp"
#include "ast_node/expr_node/ident_expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/expr_node/unary_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include "token/operator_type.hpp"
#include <stdexcept>

namespace mycompiler {

PrattParser::PrattParser(std::shared_ptr<Lexer> lexer) : lexer_(lexer) {
    initPrecedences();
}

void PrattParser::initPrecedences() {
    // 设置各种操作符的优先级
    precedences_[TokenType::OPERATOR] = Precedence::LOWEST; // 默认优先级，会根据具体操作符覆盖
    
    // 注册解析函数
    // 前缀表达式解析函数
    registerPrefix(TokenType::IDENT, [](PrattParser* parser) -> std::shared_ptr<ExprNode> {
        auto identNode = std::make_shared<IdentifierExprNode>(parser->getLexer());
        identNode->Parse();
        return identNode;
    });
    
    registerPrefix(TokenType::CONSTANT, [](PrattParser* parser) -> std::shared_ptr<ExprNode> {
        // 创建一个LiteralExprNode来包装TerminalValueLiteral
        auto literalExprNode = std::make_shared<LiteralExprNode>(parser->getLexer());
        auto valueNode = std::make_shared<TerminalValueLiteral>(parser->getLexer());
        valueNode->Parse();
        literalExprNode->add_terminalvalue_node(valueNode);
        return literalExprNode;
    });
    
    registerPrefix(TokenType::OPERATOR, [](PrattParser* parser) -> std::shared_ptr<ExprNode> {
        auto opNode = std::make_shared<TerminalOperator>(parser->getLexer());
        opNode->Parse();
        
        parser->nextToken();
        auto rightExpr = parser->parseExpression(Precedence::UNARY);
        
        auto unaryExpr = std::make_shared<UnaryExprNode>(opNode, rightExpr);
        return unaryExpr;
    });
    
    registerPrefix(TokenType::SEPARATOR, [](PrattParser* parser) -> std::shared_ptr<ExprNode> {
        // 处理括号表达式
        Token token = parser->currentToken();
        if (get_separator_type_from_token_class(token) == "(") {
            parser->nextToken(); // 跳过左括号
            auto expr = parser->parseExpression();
            
            // 确保下一个token是右括号
            Token peekTok = parser->peekToken();
            if (peekTok.get_token_type() != TokenType::SEPARATOR || 
                get_separator_type_from_token_class(peekTok) != ")") {
                throw std::runtime_error("Expected closing parenthesis");
            }
            
            parser->nextToken(); // 跳过右括号
            return expr;
        }
        throw std::runtime_error("Unexpected separator in prefix position");
    });
    
    // 中缀表达式解析函数
    registerInfix(TokenType::OPERATOR, [](PrattParser* parser, std::shared_ptr<ExprNode> left) -> std::shared_ptr<ExprNode> {
        auto precedence = parser->currentPrecedence();
        auto opNode = std::make_shared<TerminalOperator>(parser->getLexer());
        opNode->Parse();
        
        parser->nextToken();
        auto right = parser->parseExpression(precedence);
        
        return std::make_shared<BinaryExprNode>(left, opNode, right);
    });
}

std::shared_ptr<ExprNode> PrattParser::parseExpression(Precedence precedence) {
    // 获取前缀解析函数
    Token token = currentToken();
    auto prefixFn = prefixParseFns_[token.get_token_type()];
    if (!prefixFn) {
        throw std::runtime_error("No prefix parse function for " + 
                                std::to_string(static_cast<int>(token.get_token_type())));
    }
    
    auto leftExp = prefixFn(this);
    
    // 处理中缀表达式，直到遇到优先级更低的操作符
    Token peekTok = peekToken();
    while (peekTok.get_token_type() != TokenType::ILLEGAL_OR_EOF && 
           precedence < peekPrecedence()) {
        auto infixFn = infixParseFns_[peekTok.get_token_type()];
        if (!infixFn) {
            return leftExp;
        }
        
        nextToken();
        leftExp = infixFn(this, leftExp);
        peekTok = peekToken();
    }
    
    return leftExp;
}

void PrattParser::registerPrefix(TokenType tokenType, PrefixParseFn fn) {
    prefixParseFns_[tokenType] = fn;
}

void PrattParser::registerInfix(TokenType tokenType, InfixParseFn fn) {
    infixParseFns_[tokenType] = fn;
}

Token PrattParser::currentToken() {
    return lexer_->getCurrentToken();
}

Token PrattParser::peekToken() {
    return lexer_->peekNextToken();
}

void PrattParser::nextToken() {
    lexer_->getNextToken();
}

Precedence PrattParser::currentPrecedence() {
    Token token = currentToken();
    if (precedences_.find(token.get_token_type()) != precedences_.end()) {
        // 对于操作符，需要根据具体操作符类型确定优先级
        if (token.get_token_type() == TokenType::OPERATOR) {
            int priority = get_operator_priority(token);
            switch (priority) {
                case 1: return Precedence::TERM;
                case 2: return Precedence::FACTOR;
                case 3: return Precedence::UNARY;
                default: return Precedence::LOWEST;
            }
        }
        return precedences_[token.get_token_type()];
    }
    return Precedence::LOWEST;
}

Precedence PrattParser::peekPrecedence() {
    Token token = peekToken();
    if (precedences_.find(token.get_token_type()) != precedences_.end()) {
        // 对于操作符，需要根据具体操作符类型确定优先级
        if (token.get_token_type() == TokenType::OPERATOR) {
            int priority = get_operator_priority(token);
            switch (priority) {
                case 1: return Precedence::TERM;
                case 2: return Precedence::FACTOR;
                case 3: return Precedence::UNARY;
                default: return Precedence::LOWEST;
            }
        }
        return precedences_[token.get_token_type()];
    }
    return Precedence::LOWEST;
}

} // namespace mycompiler 