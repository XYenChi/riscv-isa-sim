#ifdef BODY
if (sreg_t(RS1) >= sreg_t(RS2))
  set_pc(BRANCH_TARGET);

#endif

#define SBTYPE_INSN
