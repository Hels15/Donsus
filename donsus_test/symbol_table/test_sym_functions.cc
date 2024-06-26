#include <gtest/gtest.h>

#include "../Include/Internal/type.h"
#include "../Include/sema.h"
#include "../Include/symbol_table.h"
#include "../src/ast/tree.h"

/*
 Check for nested functions and examine the child-parent behaviour between
 the symbol tables
 * */
TEST(SymbolTableCheckNestedFunctions, SymbolTableCheckFunction) {
  std::string a = R"(
    def func() -> int{
      def a() -> int {
        return 5;
        }
    return 5;
    }
)";

  DonsusAstFile file;
  DonsusParser parser = Du_Parse(a, file);
  DonsusParser::end_result parse_result = parser.donsus_parse();

  utility::handle<DonsusSymTable> sym_global = new DonsusSymTable();
  utility::handle<DonsusSymTable> sym_global2 = new DonsusSymTable();

  utility::handle<DonsusSymTable> nested_1 = sym_global2->add_sym_table("func");
  nested_1->add_sym_table("a");

  DonsusSema sema(file, parse_result);
  sema.start_traverse(sym_global);

  EXPECT_EQ(sym_global, sym_global2);
  EXPECT_EQ(file.error_count, 0);
}

//TODO: Fix this comparison
/*
 Check for nested functions and examine the child-parent behaviour between
 the symbol tables
 * */
/*
TEST(SymbolTableCheckDifferentTableStructures, SymbolTableCheckFunction) {
  std::string a = R"(
    def func() -> int{
    return 5;
    }

  a() ->int;
)";

  DonsusAstFile file;
  DonsusParser parser = Du_Parse(a, file);
  DonsusParser::end_result parse_result = parser.donsus_parse();

  utility::handle<DonsusSymTable> sym_global = new DonsusSymTable();
  utility::handle<DonsusSymTable> sym_global2 = new DonsusSymTable();

  utility::handle<DonsusSymTable> nested_1 = sym_global2->add_sym_table("func");
  std::vector<DONSUS_TYPE> types;
  types.push_back(
      {.type_un = DONSUS_TYPE::TYPE_BASIC_INT}); // return type of a is a vector

  std::string value =
      sym_global2->add("a", types); // I need to specify the type here
  DonsusSema sema(file, parse_result);
  sema.start_traverse(sym_global);

  EXPECT_EQ(sym_global, sym_global2);
}*/
