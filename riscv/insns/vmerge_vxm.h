// vmerge.vxm vd, vs2, rs1
require(insn.rd() != 0);
VI_CHECK_SSS(false);
VI_VVXI_MERGE_LOOP
({
  int midx = (P.VU.vmlen * i) / 64;
  int mpos = (P.VU.vmlen * i) % 64;
  bool use_first = (P.VU.elt<uint64_t>(0, midx) >> mpos) & 0x1;

  vd = use_first ? rs1 : vs2;
})
