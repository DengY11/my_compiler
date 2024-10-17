#ifndef EOF_OR_ILLEGAL_TYPE_HPP
#define EOF_OR_ILLEGAL_TYPE_HPP

namespace mycompiler {

enum class EOF_OR_ILLEGAL_TYPE { EOF_, ILLEGAL };

class EOF_OR_ILLEGAL {

public:
  EOF_OR_ILLEGAL() = delete;
  EOF_OR_ILLEGAL(EOF_OR_ILLEGAL_TYPE eof_or_illegal_type)
      : eof_or_illegal_type_(eof_or_illegal_type) {}

  EOF_OR_ILLEGAL_TYPE eof_or_illegal_type_;
};

} // namespace mycompiler

#endif // !EOF_OR_ILLEGAL_TYPE_HPP
