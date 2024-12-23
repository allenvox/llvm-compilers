/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Token Kind and Keyword Filter Implementation Fragment                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TOKEN_FLAGS
#undef GET_TOKEN_FLAGS
BOOLSUPPORT = 0x20,
CHAR8SUPPORT = 0x8000,
HALFSUPPORT = 0x4000,
KEYALL = 0x1ffe7ff,
KEYALLCXX = 0x200006,
KEYALTIVEC = 0x40,
KEYBORLAND = 0x100,
KEYC11 = 0x400,
KEYC99 = 0x1,
KEYCONCEPTS = 0x10000,
KEYCOROUTINES = 0x80000,
KEYCXX = 0x2,
KEYCXX11 = 0x4,
KEYCXX20 = 0x200000,
KEYGNU = 0x8,
KEYMODULES = 0x100000,
KEYMS = 0x10,
KEYMSCOMPAT = 0x800000,
KEYNOCXX = 0x80,
KEYNOMS18 = 0x800,
KEYNOOPENCL = 0x1000,
KEYOBJC = 0x20000,
KEYOPENCLC = 0x200,
KEYOPENCLCXX = 0x400000,
KEYSYCL = 0x1000000,
KEYZVECTOR = 0x40000,
WCHARSUPPORT = 0x2000,
#endif
#ifdef GET_TOKEN_KIND_DECLARATION
#undef GET_TOKEN_KIND_DECLARATION
namespace tok {
  enum TokenKind : unsigned short {
    unknown,
    eof,
    comment,
    plus,
    minus,
    kw_auto,
    kw_char,
    kw_const,
    kw_continue,
    kw_default,
    kw_do,
    kw_double,
    kw_else,
    kw_enum,
    kw_extern,
    kw_float,
    kw_for,
    kw_goto,
    kw_if,
    kw_inline,
    kw_int,
    kw_long,
    kw_register,
    kw_restrict,
    kw_return,
    kw_short,
    kw_signed,
    NUM_TOKENS
  };
  const char *getTokenName(TokenKind Kind) LLVM_READNONE;
  const char *getPunctuatorSpelling(TokenKind Kind) LLVM_READNONE;
  const char *getKeywordSpelling(TokenKind Kind) LLVM_READNONE;
}
#endif
#ifdef GET_TOKEN_KIND_DEFINITION
#undef GET_TOKEN_KIND_DEFINITION
static const char * const TokNames[] = {
  "unknown",
  "eof",
  "comment",
  "plus",
  "minus",
  "auto",
  "char",
  "const",
  "continue",
  "default",
  "do",
  "double",
  "else",
  "enum",
  "extern",
  "float",
  "for",
  "goto",
  "if",
  "inline",
  "int",
  "long",
  "register",
  "restrict",
  "return",
  "short",
  "signed",
};

const char *tok::getTokenName(TokenKind Kind) {
  if (Kind <= tok::NUM_TOKENS)
    return TokNames[Kind];
  llvm_unreachable("unknown TokenKind");
  return nullptr;
};

const char *tok::getPunctuatorSpelling(TokenKind Kind) {
  switch (Kind) {
    plus: return "+";
    minus: return "-";
    default: break;
  }
  return nullptr;
};

const char *tok::getKeywordSpelling(TokenKind Kind) {
  switch (Kind) {
    kw_auto: return "auto";
    kw_char: return "char";
    kw_const: return "const";
    kw_continue: return "continue";
    kw_default: return "default";
    kw_do: return "do";
    kw_double: return "double";
    kw_else: return "else";
    kw_enum: return "enum";
    kw_extern: return "extern";
    kw_float: return "float";
    kw_for: return "for";
    kw_goto: return "goto";
    kw_if: return "if";
    kw_inline: return "inline";
    kw_int: return "int";
    kw_long: return "long";
    kw_register: return "register";
    kw_restrict: return "restrict";
    kw_return: return "return";
    kw_short: return "short";
    kw_signed: return "signed";
    default: break;
  }
  return nullptr;
};

#endif
#ifdef GET_KEYWORD_FILTER
#undef GET_KEYWORD_FILTER
bool lookupKeyword(llvm::StringRef Keyword, unsigned &Value) {
  struct Entry {
    unsigned Value;
    llvm::StringRef Keyword;
  };
static const Entry Table[22] = {
    { 33548287, llvm::StringRef("auto", 4) },
    { 33548287, llvm::StringRef("char", 4) },
    { 33548287, llvm::StringRef("const", 5) },
    { 33548287, llvm::StringRef("continue", 8) },
    { 33548287, llvm::StringRef("default", 7) },
    { 33548287, llvm::StringRef("do", 2) },
    { 33548287, llvm::StringRef("double", 6) },
    { 33548287, llvm::StringRef("else", 4) },
    { 33548287, llvm::StringRef("enum", 4) },
    { 33548287, llvm::StringRef("extern", 6) },
    { 33548287, llvm::StringRef("float", 5) },
    { 33548287, llvm::StringRef("for", 3) },
    { 33548287, llvm::StringRef("goto", 4) },
    { 33548287, llvm::StringRef("if", 2) },
    { 11, llvm::StringRef("inline", 6) },
    { 33548287, llvm::StringRef("int", 3) },
    { 33548287, llvm::StringRef("long", 4) },
    { 33548287, llvm::StringRef("register", 8) },
    { 1, llvm::StringRef("restrict", 8) },
    { 33548287, llvm::StringRef("return", 6) },
    { 33548287, llvm::StringRef("short", 5) },
    { 33548287, llvm::StringRef("signed", 6) },
  };

  const Entry *E = std::lower_bound(&Table[0], &Table[22], Keyword, [](const Entry &A, const StringRef &B) {
    return A.Keyword < B;
  });
  if (E != &Table[22]) {
    Value = E->Value;
    return true;
  }
  return false;
}

#ifdef SELFCHECK
void selfcheck() {
  auto Check = [](StringRef Key, unsigned ExpVal) {
    unsigned Val;
    if (!lookupKeyword(Key, Val)) { llvm::dbgs() << "Failed to find: " << Key << "\n"; exit(1); }
    if (Val != ExpVal) { llvm::dbgs() << Key << "Wrong value\n"; exit(1); }
  };
  Check("auto", 33548287);
  Check("char", 33548287);
  Check("const", 33548287);
  Check("continue", 33548287);
  Check("default", 33548287);
  Check("do", 33548287);
  Check("double", 33548287);
  Check("else", 33548287);
  Check("enum", 33548287);
  Check("extern", 33548287);
  Check("float", 33548287);
  Check("for", 33548287);
  Check("goto", 33548287);
  Check("if", 33548287);
  Check("inline", 11);
  Check("int", 33548287);
  Check("long", 33548287);
  Check("register", 33548287);
  Check("restrict", 1);
  Check("return", 33548287);
  Check("short", 33548287);
  Check("signed", 33548287);
  llvm::dbgs() << "Selfcheck done\n";
}

#endif // SELFCHECK
#endif
