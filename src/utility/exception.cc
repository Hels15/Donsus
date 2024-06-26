#include "exception.h"
#include "../../Include/Internal/build_context.h"
#include <string>

void DonsusParserError::syntax_error_normal(unsigned int column,
                                            unsigned int line,
                                            const std::string &message,
                                            const std::string &full_path) {
  std::string message_c =
      "(" + std::to_string(line) + ":" + std::to_string(column) + ") ";

  const std::string &line_c = message;
  if (has_ansi_colours()) {
    error_out_coloured(full_path, rang::fg::reset);
    error_out_coloured(message_c, rang::fg::green);
    error_out_coloured(" SYNTAX ERROR: ");
    error_out_coloured(line_c, rang::fg::reset);
    error_out_coloured("\n");
  } else {
    error(full_path);
    error(" SYNTAX ERROR: ");
    error(message_c);
    error(line_c);
    error("\n");
  }
}

// Todo: make use of this function here
void DonsusParserError::type_error_normal(unsigned int column,
                                          unsigned int line,
                                          const std::string &message,
                                          const std::string &full_path) {
  std::string message_c =
      "(" + std::to_string(line) + ":" + std::to_string(column) + ") ";

  const std::string &line_c = message;
  if (has_ansi_colours()) {
    error_out_coloured(full_path, rang::fg::reset);
    error_out_coloured(message_c, rang::fg::green);
    error_out_coloured(" TYPE ERROR: ");
    error_out_coloured(line_c, rang::fg::reset);
    error_out_coloured("\n");
  } else {
    error(full_path);
    error(" TYPE ERROR : ");
    error(message_c);
    error(line_c);
    error("\n");
  }
}
void DonsusParserError::error_out_coloured(const std::string &message,
                                           rang::fg colour) {
  std::cerr << rang::style::bold << colour << message << rang::style::reset
            << rang::fg::reset;
}

void DonsusParserError::error_out_empty() { error(" "); }

void DonsusParserError::error(const std::string &message) {
  std::cout << message;
}

// windows | osx support
// Support other systems might need to be done in a completely another file
bool DonsusParserError::has_ansi_colours() {

  return DonsusBuildContext::has_ansi_colours();
}
