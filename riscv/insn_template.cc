// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

#define DECODE_MACRO_USAGE_LOGGED 0

#include "insns/NAME.h"

#define PROLOGUE \
  reg_t npc = sext_xlen(pc + insn_length(OPCODE))

#define EPILOGUE \
  trace_opcode(p, OPCODE, insn); \
  return npc


#if defined(RTYPE_INSN)
insn_type_t NAME_insn_type = RTYPE;
#include "rtype_decode_macros.h"
#elif defined(ITYPE_INSN)
insn_type_t NAME_insn_type = ITYPE;
#include "itype_decode_macros.h"
#elif defined(UTYPE_INSN)
insn_type_t NAME_insn_type = UTYPE;
#include "utype_decode_macros.h"
#elif defined(SBTYPE_INSN)
insn_type_t NAME_insn_type = SBTYPE;
#include "sbtype_decode_macros.h"
#elif defined(UJTYPE_INSN)
insn_type_t NAME_insn_type = UJTYPE;
#include "ujtype_decode_macros.h"
#else
insn_type_t NAME_insn_type = GENERIC;
#endif


reg_t fast_rv32i_NAME(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  PROLOGUE;
  #define BODY
  #include "insns/NAME.h"
  #undef BODY
  EPILOGUE;
  #undef xlen
}

reg_t fast_rv64i_NAME(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  PROLOGUE;
  #define BODY
  #include "insns/NAME.h"
  #undef BODY
  EPILOGUE;
  #undef xlen
}

#undef DECODE_MACRO_USAGE_LOGGED
#define DECODE_MACRO_USAGE_LOGGED 1

reg_t logged_rv32i_NAME(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  PROLOGUE;
  #define BODY
  #include "insns/NAME.h"
  #undef BODY
  EPILOGUE;
  #undef xlen
}

reg_t logged_rv64i_NAME(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  PROLOGUE;
  #define BODY
  #include "insns/NAME.h"
  #undef BODY
  EPILOGUE;
  #undef xlen
}

#undef CHECK_REG
#define CHECK_REG(reg) require((reg) < 16)

#undef DECODE_MACRO_USAGE_LOGGED
#define DECODE_MACRO_USAGE_LOGGED 0

reg_t fast_rv32e_NAME(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  PROLOGUE;
  #define BODY
  #include "insns/NAME.h"
  #undef BODY
  EPILOGUE;
  #undef xlen
}

reg_t fast_rv64e_NAME(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  PROLOGUE;
  #define BODY
  #include "insns/NAME.h"
  #undef BODY
  EPILOGUE;
  #undef xlen
}

#undef DECODE_MACRO_USAGE_LOGGED
#define DECODE_MACRO_USAGE_LOGGED 1

reg_t logged_rv32e_NAME(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  PROLOGUE;
  #define BODY
  #include "insns/NAME.h"
  #undef BODY
  EPILOGUE;
  #undef xlen
}

reg_t logged_rv64e_NAME(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  PROLOGUE;
  #define BODY
  #include "insns/NAME.h"
  #undef BODY
  EPILOGUE;
  #undef xlen
}
