#ifndef EOF_OR_ILLEGAL_TYPE_HPP
#define EOF_OR_ILLEGAL_TYPE_HPP

namespace mycompiler {

// EOF或非法类型枚举
enum class EofOrIllegalType {
  EOF_,    // 文件结束
  ILLEGAL  // 非法字符
};

// EOF或非法类
class EofOrIllegal {
public:
  EofOrIllegal() = delete;
  EofOrIllegal(EofOrIllegalType eofOrIllegalType) : eofOrIllegalType_(eofOrIllegalType) {}

  EofOrIllegalType eofOrIllegalType_;
};

} // namespace mycompiler

#endif // !EOF_OR_ILLEGAL_TYPE_HPP
