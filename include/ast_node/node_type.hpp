#ifndef NODE_TYPE
#define NODE_TYPE

namespace mycompiler {

enum class AST_NODE_TYPE {

  ROOT,
  BASIC,
  DECL,
  EXPR,
  STAT,

  FUNCTION_DECL,
  LAMBDA_DECL,
  VARIABLE_DECL,

  RETURN_STAT,
  EXPRESSION_STAT,
  IF_STAT,
  WHILE_STAT,
  FOR_STAT,
  BREAK_STAT,
  CONTINUE_STAT,
  BLOCK_STAT,
  SWITCH_STAT,

  BINNARY_EXPR,
  UNARY_EXPR,
  LITERAL_EXPR,
  IDENTIFIER_EXPR,
  GROUPING_EXPR,
  TENARY_EXPR,

  // terminal
  LET,
  EQUAL,
  IDENT_LITERAL,
  VALUE_LITERAL
};

}

#endif
