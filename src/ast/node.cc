//===----------------------------------------------------------------------===//
//
//  Helper API for working with Ast nodes.
//===----------------------------------------------------------------------===//

#include "node.h"

using namespace donsus_ast;

DONSUS_TYPE node::assume_type() {

  DONSUS_TYPE type_l;
  switch (type.type) {
  case donsus_node_type::DONSUS_NUMBER_EXPRESSION: {
    type_l.type_un = DONSUS_TYPE::TYPE_I32;
    break;
  }
  case donsus_node_type::DONSUS_FLOAT_EXPRESSION: {
    type_l.type_un = DONSUS_TYPE::TYPE_F32;
    break;
  }
  case donsus_node_type::DONSUS_STRING_EXPRESSION: {
    type_l.type_un = DONSUS_TYPE::TYPE_STRING;
    break;
  }

  case donsus_node_type::DONSUS_EXPRESSION: {
    return children[0]->assume_type();
  }
  default: {
    // handle error here
  }
  }
  real_type = type_l;
  return type_l;
}
donsus_node_type::donsus_node_type(underlying type) : type(type) {}

bool donsus_node_type::pre_match(DONSUS_TYPE AType) const {
  switch (type) {
  case DONSUS_NUMBER_EXPRESSION:
    return AType.is_integer();
  case DONSUS_STRING_EXPRESSION:
    return AType.is_string();
  case DONSUS_FLOAT_EXPRESSION:
    return AType.is_float();
  case DONSUS_BOOL_EXPRESSION:
    return AType.is_bool();
  // So that recursion can happem
  // Let's say an expression getting it's type
  //
  case DONSUS_EXPRESSION: {
    return true;
  }
  default: {
    return false;
  }
  }
}
auto donsus_node_type::to_string() const -> std::string {
  switch (type) {
  case DONSUS_VARIABLE_DECLARATION:
    return "DONSUS_VARIABLE_DECLARATION";
  case DONSUS_NUMBER_EXPRESSION:
    return "DONSUS_NUMBER_EXPRESSION";
  case DONSUS_VARIABLE_DEFINITION:
    return "DONSUS_VARIABLE_DEFINITION";
  case DONSUS_FUNCTION_DECL:
    return "DONSUS_FUNCTION_DECLARATION";
  case DONSUS_FUNCTION_DEF:
    return "DONSUS_FUNCTION_DEFINITION";
  case DONSUS_ASSIGNMENT:
    return "DONSUS_ASSIGMENT";
  case DONSUS_IDENTIFIER:
    return "DONSUS_IDENTIFIER";
  case DONSUS_IF_STATEMENT:
    return "DONSUS_IF_STATEMENT";
  case DONSUS_EXPRESSION:
    return "DONSUS_EXPRESSION";
  case DONSUS_ELSE_STATEMENT:
    return "DONSUS_ELSE_STATEMENT";
  case DONSUS_FUNCTION_CALL:
    return "DONSUS_FUNCTION_CALL";
  case DONSUS_RETURN_STATEMENT:
    return "DONSUS_RETURN_STATEMENT";
  case DONSUS_STRING_EXPRESSION:
    return "DONSUS_STRING_EXPRESSION";
  case DONSUS_UNARY_EXPRESSION:
    return "DONSUS_UNARY_EXPRESSION";
  case DONSUS_BOOL_EXPRESSION:
    return "DONSUS_BOOL_EXPRESSION";
  case DONSUS_PRINT_EXPRESSION:
    return "DONSUS_PRINT_EXPRESSION";
  case DONSUS_ARRAY_DECLARATION:
    return "DONSUS_ARRAY_DECLARATION";
  case DONSUS_ARRAY_DEFINITION:
    return "DONSUS_ARRAY_DEFINITION";
  case DONSUS_FLOAT_EXPRESSION:
    return "DONSUS_FLOAT_EXPRESSION";
  case DONSUS_ARRAY_ACCESS:
    return "DONSUS_ARRAY_ACCESS";
  case DONSUS_FUNCTION_ARG:
    return "DONSUS_FUNCTION_ARG";
  case DONSUS_WHILE_LOOP:
    return "DONSUS_WHILE_LOOP";
  case DONSUS_FOR_LOOP:
    return "DONSUS_FOR_LOOP";
  case DONSUS_RANGE_EXPRESSION:
    return "DONSUS_RANGE_EXPRESSION";
  default: {
    return "";
  }
  }
}

std::string
donsus_ast::de_get_from_donsus_node_type(donsus_ast::donsus_node_type type) {
  switch (type.type) {
  case donsus_node_type::DONSUS_VARIABLE_DECLARATION: {
    return "DONSUS_VARIABLE_DECLARATION";
  }
  case donsus_node_type::DONSUS_NUMBER_EXPRESSION: {
    return "DONSUS_NUMBER_EXPRESSION";
  }
  case donsus_node_type::DONSUS_VARIABLE_DEFINITION: {
    return "DONSUS_VARIABLE_DEFINITION";
  }
  case donsus_node_type::DONSUS_FUNCTION_DECL: {
    return "DONSUS_FUNCTION_DECLARATION";
  }
  case donsus_node_type::DONSUS_FUNCTION_DEF: {
    return "DONSUS_FUNCTION_DEFINITION";
  }
  case donsus_node_type::DONSUS_IF_STATEMENT: {
    return "DONSUS_IF_STATEMENT";
  }
  case donsus_node_type::DONSUS_IDENTIFIER: {
    return "DONSUS_IDENTIFIER";
  }
  case donsus_node_type::DONSUS_ASSIGNMENT: {
    return "DONSUS_ASSIGNMENT";
  }
  case donsus_node_type::DONSUS_EXPRESSION: {
    return "DONSUS_EXPRESSION";
  }

  case donsus_node_type::DONSUS_ELSE_STATEMENT: {
    return "DONSUS_ELSE_STATEMENT";
  }

  case donsus_node_type::DONSUS_FUNCTION_CALL: {
    return "DONSUS_FUNCTION_CALL";
  }

  case donsus_node_type::DONSUS_RETURN_STATEMENT: {
    return "DONSUS_RETURN_STATEMENT";
  }
  case donsus_node_type::DONSUS_STRING_EXPRESSION: {
    return "DONSUS_STRING_EXPRESSION";
  }

  case donsus_node_type::DONSUS_UNARY_EXPRESSION: {
    return "DONSUS_UNARY_EXPRESSION";
  }

  case donsus_node_type::DONSUS_BOOL_EXPRESSION: {
    return "DONSUS_BOOL_EXPRESSION";
  }

  case donsus_node_type::DONSUS_PRINT_EXPRESSION: {
    return "DONSUS_PRINT_EXPRESSION";
  }

  case donsus_node_type::DONSUS_FLOAT_EXPRESSION: {
    return "DONSUS_FLOAT_EXPRESSION";

  case donsus_node_type::DONSUS_FUNCTION_ARG: {
    return "DONSUS_FUNCTION_ARG";
  }

  case donsus_node_type::DONSUS_ARRAY_DECLARATION: {
    return "DONSUS_ARRAY_DECLARATION";
  }

  case donsus_node_type::DONSUS_ARRAY_DEFINITION: {
    return "DONSUS_ARRAY_DEFINITION";
  }

  case donsus_node_type::DONSUS_ARRAY_ACCESS: {
    return "DONSUS_ARRAY_ACCESS";
  }

  case donsus_node_type::DONSUS_WHILE_LOOP: {
    return "DONSUS_WHILE_LOOP";
  }

  case donsus_node_type::DONSUS_FOR_LOOP: {
    return "DONSUS_FOR_LOOP";
  }

  case donsus_node_type::DONSUS_RANGE_EXPRESSION: {
    return "DONSUS_RANGE_EXPRESSION";
  }

  default: {
    return "";
  }
  }
  }
}
