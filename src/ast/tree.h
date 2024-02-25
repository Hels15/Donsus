#ifndef DONSUS_TREE_H
#define DONSUS_TREE_H
#include <assert.h>
#include <functional>
#include <iostream>
#include <limits>
#include <stack>
#include <vector>

#include "../utility/handle.h"
#include "../utility/memory_alloc.h"
#include "node.h"
#include "symbol_table.h"

// Holds top level ast nodes
/* (old version)
 * std::vector<std::variant<donsus_math_expr*, donsus_variable_decl*>> body;
 *
 * *\
 */

namespace donsus_ast {
class tree {
public:
  tree();
  // TBD void traverse()
  void add_node(utility::handle<node>);
  auto get_nodes() -> std::vector<utility::handle<node>>;
  auto get_allocator() -> utility::DonsusAllocator;
  void allocate_node_list(uint64_t count);

  // https://en.wikipedia.org/wiki/Tree_traversal
  void traverse(std::function<void(utility::handle<node>,
                                   utility::handle<DonsusSymTable> table)>
                    visit,
                utility::handle<DonsusSymTable> sym)
      const; // implement traverse and use stack

  template <typename extra_type>
  auto create_node(donsus_node_type type, uint64_t child_count)
      -> utility::handle<node> {
    assert(child_count <= std::numeric_limits<uint64_t>::max());
    // Todo: think about this
    const utility::handle node_ptr = allocator.alloc<node>();

    // initialise the node
    allocate_node_list(child_count);
    node_ptr->type = type;
    node_ptr->children =
        {}; // initialise it as an empty vector rather than the nodes
    node_ptr->set_property(allocator.emplace<extra_type>());
    return node_ptr;
  };

private:
  // for AST walking
  void process_node(utility::handle<node> node) const;
  std::vector<utility::handle<node>> nodes;
  utility::DonsusAllocator allocator;
};
} // namespace donsus_ast

#endif // DONSUS_TREE_H