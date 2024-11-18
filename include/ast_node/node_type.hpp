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
  CHANGE_VAR_STAT,
  BLOCK_STAT,
  SWITCH_STAT,
  PARAMETER_LIST_STAT,
  PARAMETER_STAT,
  VOID_STAT,
  SELF_CHANGE_STAT,

  STAT_LIST,

  BINNARY_EXPR,
  UNARY_EXPR,
  LITERAL_EXPR,
  IDENTIFIER_EXPR,
  GROUPING_EXPR,
  TENARY_EXPR,
  FUNCTION_CALL_EXPR,
  COMPARE_EXPR,

  // terminal
  FUNC,
  LET,
  IF,
  EQUAL,
  IDENT_LITERAL,
  VALUE_LITERAL,
  TERMINAL_SEPARATOR,
  RETURN,
  FOR,
};

}

#endif
