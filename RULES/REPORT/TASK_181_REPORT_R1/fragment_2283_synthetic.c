/* TASK_181 static Ghidra C-like for *synthetic fragment only*.
 * Original export: x264_8_deblock_h_luma_intra_neon at ELF VA 0x658fe8.
 * Original-byte fragment: 0x659200..0x6592c4; 200/736 bytes.
 * Synthetic entry registers are undefined outside original preceding context.
 * This is not the whole original function or behavior/pixel-equivalence evidence.
 */


long TASK_181_fragment_2283
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined1 param_5 [16],undefined1 param_6 [16],
               undefined1 param_7 [16],undefined1 param_8 [16],long param_9,long param_10)

{
  undefined4 uVar1;
  undefined6 uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [12];
  undefined1 auVar6 [12];
  undefined1 auVar7 [12];
  undefined1 auVar8 [12];
  undefined1 auVar9 [12];
  undefined1 auVar10 [12];
  undefined1 *puVar11;
  undefined8 *puVar12;
  undefined2 uVar13;
  undefined1 uVar14;
  ushort uVar15;
  ushort uVar16;
  undefined1 uVar17;
  undefined1 uVar19;
  ushort uVar18;
  undefined1 uVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  undefined1 auVar24 [16];
  undefined1 auVar28 [16];
  undefined1 auVar32 [16];
  undefined1 auVar40 [16];
  undefined1 auVar44 [16];
  undefined1 auVar47 [16];
  undefined1 auVar51 [16];
  byte bVar53;
  undefined1 uVar54;
  undefined1 auVar57 [16];
  undefined1 auVar65 [16];
  undefined1 auVar70 [16];
  undefined1 auVar78 [16];
  undefined1 auVar82 [16];
  undefined1 auVar86 [16];
  undefined1 auVar94 [16];
  undefined1 auVar98 [16];
  undefined1 in_q17 [16];
  undefined1 in_q18 [16];
  undefined1 in_q19 [16];
  undefined1 in_q20 [16];
  undefined1 in_b21;
  undefined1 in_register_000052a1;
  undefined1 in_register_000052a2;
  undefined1 in_register_000052a3;
  undefined1 in_register_000052a4;
  undefined1 in_register_000052a5;
  undefined1 in_register_000052a6;
  undefined1 in_register_000052a7;
  undefined1 in_register_000052a8;
  undefined1 in_register_000052a9;
  undefined1 in_register_000052aa;
  undefined1 in_register_000052ab;
  undefined1 in_register_000052ac;
  undefined1 in_register_000052ad;
  undefined1 in_register_000052ae;
  undefined1 in_register_000052af;
  undefined1 in_q22 [16];
  undefined1 in_b23;
  undefined1 in_register_000052e1;
  undefined1 in_register_000052e2;
  undefined1 in_register_000052e3;
  undefined1 in_register_000052e4;
  undefined1 in_register_000052e5;
  undefined1 in_register_000052e6;
  undefined1 in_register_000052e7;
  undefined1 in_register_000052e8;
  undefined1 in_register_000052e9;
  undefined1 in_register_000052ea;
  undefined1 in_register_000052eb;
  undefined1 in_register_000052ec;
  undefined1 in_register_000052ed;
  undefined1 in_register_000052ee;
  undefined1 in_register_000052ef;
  undefined1 in_q24 [16];
  undefined1 in_q25 [16];
  undefined1 in_q26 [16];
  undefined1 in_q30 [16];
  undefined1 in_q31 [16];
  undefined1 auVar23 [12];
  undefined1 auVar26 [16];
  undefined1 auVar25 [16];
  undefined1 auVar29 [16];
  undefined1 auVar27 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar30 [12];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar42 [16];
  undefined1 auVar41 [16];
  undefined1 auVar45 [16];
  undefined1 auVar31 [14];
  undefined1 auVar38 [16];
  undefined1 auVar37 [16];
  undefined1 auVar43 [16];
  undefined1 auVar39 [16];
  undefined1 auVar46 [12];
  undefined1 auVar49 [16];
  undefined1 auVar48 [16];
  undefined1 auVar52 [16];
  undefined1 auVar50 [16];
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar55 [12];
  undefined1 auVar61 [16];
  undefined1 auVar60 [16];
  undefined1 auVar66 [16];
  undefined1 auVar56 [14];
  undefined1 auVar63 [16];
  undefined1 auVar62 [16];
  undefined1 auVar64 [16];
  undefined1 auVar71 [16];
  undefined1 auVar72 [16];
  undefined1 auVar68 [12];
  undefined1 auVar67 [12];
  undefined1 auVar74 [16];
  undefined1 auVar73 [16];
  undefined1 auVar80 [16];
  undefined1 auVar79 [16];
  undefined1 auVar83 [16];
  undefined1 auVar69 [14];
  undefined1 auVar76 [16];
  undefined1 auVar75 [16];
  undefined1 auVar81 [16];
  undefined1 auVar77 [16];
  undefined1 auVar87 [16];
  undefined1 auVar88 [16];
  undefined1 auVar84 [12];
  undefined1 auVar89 [16];
  undefined1 auVar90 [16];
  undefined1 auVar96 [16];
  undefined1 auVar95 [16];
  undefined1 auVar99 [16];
  undefined1 auVar85 [14];
  undefined1 auVar92 [16];
  undefined1 auVar91 [16];
  undefined1 auVar97 [16];
  undefined1 auVar93 [16];
  
  uVar54 = param_4[7];
  bVar53 = param_4[6];
  param_8 = param_8 ^ (param_8 ^ in_q24) & in_q30;
  param_1 = param_1 ^ (param_1 ^ in_q25) & in_q31;
  param_8 = param_8 ^ (param_8 ^ in_q20) & in_q17;
  auVar3[1] = in_register_000052a1;
  auVar3[0] = in_b21;
  auVar3[2] = in_register_000052a2;
  auVar3[3] = in_register_000052a3;
  auVar3[4] = in_register_000052a4;
  auVar3[5] = in_register_000052a5;
  auVar3[6] = in_register_000052a6;
  auVar3[7] = in_register_000052a7;
  auVar3[8] = in_register_000052a8;
  auVar3[9] = in_register_000052a9;
  auVar3[10] = in_register_000052aa;
  auVar3[0xb] = in_register_000052ab;
  auVar3[0xc] = in_register_000052ac;
  auVar3[0xd] = in_register_000052ad;
  auVar3[0xe] = in_register_000052ae;
  auVar3[0xf] = in_register_000052af;
  param_7 = param_7 ^ (param_7 ^ auVar3) & in_q17;
  param_6 = param_6 ^ (param_6 ^ in_q19) & in_q17;
  param_1 = param_1 ^ (param_1 ^ in_q22) & in_q18;
  auVar4[1] = in_register_000052e1;
  auVar4[0] = in_b23;
  auVar4[2] = in_register_000052e2;
  auVar4[3] = in_register_000052e3;
  auVar4[4] = in_register_000052e4;
  auVar4[5] = in_register_000052e5;
  auVar4[6] = in_register_000052e6;
  auVar4[7] = in_register_000052e7;
  auVar4[8] = in_register_000052e8;
  auVar4[9] = in_register_000052e9;
  auVar4[10] = in_register_000052ea;
  auVar4[0xb] = in_register_000052eb;
  auVar4[0xc] = in_register_000052ec;
  auVar4[0xd] = in_register_000052ed;
  auVar4[0xe] = in_register_000052ee;
  auVar4[0xf] = in_register_000052ef;
  param_2 = param_2 ^ (param_2 ^ auVar4) & in_q18;
  param_3 = param_3 ^ (param_3 ^ in_q26) & in_q18;
  auVar57._0_8_ = param_6._7_8_ << 0x38;
  auVar57._9_7_ = param_6._9_7_;
  auVar57[8] = param_7[8];
  auVar59._11_5_ = param_6._11_5_;
  auVar59._0_10_ = auVar57._0_10_;
  auVar59[10] = param_7[10];
  auVar61._13_3_ = param_6._13_3_;
  auVar61._0_12_ = auVar59._0_12_;
  auVar61[0xc] = param_7[0xc];
  auVar63._0_14_ = auVar61._0_14_;
  auVar63[0xe] = param_7[0xe];
  auVar63[0xf] = param_6[0xf];
  uVar17 = param_8[6];
  auVar58._10_6_ = auVar63._10_6_;
  auVar58._0_10_ = CONCAT19(param_8[8],CONCAT81(auVar63._8_8_,uVar17) << 0x38);
  uVar21 = param_8[10];
  auVar60._12_4_ = auVar63._12_4_;
  auVar55._0_11_ = auVar58._0_11_;
  auVar55[0xb] = uVar21;
  auVar60._0_12_ = auVar55;
  auVar62._14_2_ = auVar63._14_2_;
  auVar56._0_13_ = auVar60._0_13_;
  auVar56[0xd] = param_8[0xc];
  auVar62._0_14_ = auVar56;
  auVar64._0_15_ = auVar62._0_15_;
  auVar64[0xf] = param_8[0xe];
  auVar86._0_8_ = param_8._7_8_ << 0x38;
  auVar86._9_7_ = param_8._9_7_;
  auVar86[8] = param_7[9];
  auVar88._11_5_ = param_8._11_5_;
  auVar88._0_10_ = auVar86._0_10_;
  auVar88[10] = param_7[0xb];
  auVar90._13_3_ = param_8._13_3_;
  auVar90._0_12_ = auVar88._0_12_;
  auVar90[0xc] = param_7[0xd];
  uVar14 = param_7[0xf];
  auVar92[0xf] = param_8[0xf];
  auVar92._0_14_ = auVar90._0_14_;
  auVar92[0xe] = uVar14;
  uVar19 = param_8[7];
  auVar87._10_6_ = auVar92._10_6_;
  auVar87._0_10_ = CONCAT19(param_8[9],CONCAT81(auVar92._8_8_,uVar19) << 0x38);
  uVar22 = param_8[0xb];
  auVar89._12_4_ = auVar92._12_4_;
  auVar89._0_11_ = auVar87._0_11_;
  auVar89[0xb] = uVar22;
  auVar91._14_2_ = auVar92._14_2_;
  auVar85._0_13_ = auVar89._0_13_;
  auVar85[0xd] = param_8[0xd];
  auVar91._0_14_ = auVar85;
  auVar93._0_15_ = auVar91._0_15_;
  auVar93[0xf] = auVar92[0xf];
  uVar20 = param_2[8];
  auVar32._0_8_ = param_2._7_8_ << 0x38;
  auVar32._9_7_ = param_2._9_7_;
  auVar32[8] = param_1[9];
  auVar34._11_5_ = param_2._11_5_;
  auVar34._0_10_ = auVar32._0_10_;
  auVar34[10] = param_1[0xb];
  auVar36._13_3_ = param_2._13_3_;
  auVar36._0_12_ = auVar34._0_12_;
  auVar36[0xc] = param_1[0xd];
  auVar38[0xf] = param_2[0xf];
  auVar38._0_14_ = auVar36._0_14_;
  auVar38[0xe] = param_1[0xf];
  auVar33._10_6_ = auVar38._10_6_;
  auVar33._0_10_ = CONCAT19(param_2[9],CONCAT81(auVar38._8_8_,param_2[7]) << 0x38);
  auVar35._12_4_ = auVar38._12_4_;
  auVar35._0_11_ = auVar33._0_11_;
  auVar35[0xb] = param_2[0xb];
  auVar37._14_2_ = auVar38._14_2_;
  auVar31._0_13_ = auVar35._0_13_;
  auVar31[0xd] = param_2[0xd];
  auVar37._0_14_ = auVar31;
  auVar39._0_15_ = auVar37._0_15_;
  auVar39[0xf] = auVar38[0xf];
  auVar70._0_8_ = param_7._7_8_ << 0x38;
  auVar70._9_7_ = param_7._9_7_;
  auVar70[8] = param_3[8];
  auVar72._11_5_ = param_7._11_5_;
  auVar72._0_10_ = auVar70._0_10_;
  auVar72[10] = param_3[10];
  auVar74._13_3_ = param_7._13_3_;
  auVar74._0_12_ = auVar72._0_12_;
  auVar74[0xc] = param_3[0xc];
  auVar76._0_14_ = auVar74._0_14_;
  auVar76[0xe] = param_3[0xe];
  auVar76[0xf] = uVar14;
  auVar71._10_6_ = auVar76._10_6_;
  auVar71._0_10_ = CONCAT19(param_4[8],CONCAT81(auVar76._8_8_,bVar53) << 0x38);
  auVar73._12_4_ = auVar76._12_4_;
  auVar67._0_11_ = auVar71._0_11_;
  auVar67[0xb] = param_4[10];
  auVar73._0_12_ = auVar67;
  auVar75._14_2_ = auVar76._14_2_;
  auVar69._0_13_ = auVar73._0_13_;
  auVar69[0xd] = param_4[0xc];
  auVar75._0_14_ = auVar69;
  auVar77._0_15_ = auVar75._0_15_;
  auVar77[0xf] = param_4[0xe];
  auVar26[0xd] = param_2[0xc];
  auVar26[0xc] = param_1[0xc];
  auVar24._0_8_ = param_1._6_8_ << 0x30;
  auVar24._10_6_ = param_1._10_6_;
  auVar24._8_2_ = (short)(CONCAT12(uVar20,CONCAT11(param_1[8],param_2[6])) >> 8);
  auVar26._14_2_ = param_1._14_2_;
  auVar26._0_12_ = auVar24._0_12_;
  uVar15 = (ushort)(((uint6)param_4[4] << 0x28) >> 0x20);
  auVar23._0_10_ = CONCAT82(auVar26._8_8_,uVar15) << 0x30;
  auVar25._12_4_ = auVar26._12_4_;
  auVar23._10_2_ = (short)((unkuint10)auVar71._0_10_ >> 0x40);
  auVar25._0_12_ = auVar23;
  auVar27._0_14_ = auVar25._0_14_;
  auVar27._14_2_ = auVar69._12_2_;
  auVar80[0xd] = param_2[0xe];
  auVar80[0xc] = param_1[0xe];
  auVar78._0_8_ = auVar69._6_8_ << 0x30;
  auVar78._10_6_ = auVar77._10_6_;
  auVar78._8_2_ = (short)(CONCAT12(param_2[10],CONCAT11(param_1[10],uVar20)) >> 8);
  auVar80._14_2_ = auVar77._14_2_;
  auVar80._0_12_ = auVar78._0_12_;
  uVar18 = (ushort)(((ulong)bVar53 << 0x38) >> 0x30);
  auVar68._0_10_ = CONCAT82(auVar80._8_8_,uVar18) << 0x30;
  auVar79._12_4_ = auVar80._12_4_;
  auVar68._10_2_ = auVar67._10_2_;
  auVar79._0_12_ = auVar68;
  auVar81._0_14_ = auVar79._0_14_;
  auVar81._14_2_ = auVar80._14_2_;
  auVar8[1] = param_4[1];
  auVar8[0] = param_3[1];
  auVar50[0xf] = param_4[0xd];
  auVar50[0xe] = param_3[0xd];
  auVar47._0_8_ = param_3._6_8_ << 0x30;
  auVar47._10_6_ = param_3._10_6_;
  auVar47._8_2_ = (short)((unkuint10)auVar33._0_10_ >> 0x40);
  auVar49._14_2_ = param_3._14_2_;
  auVar49._0_12_ = auVar47._0_12_;
  auVar49._12_2_ = auVar31._12_2_;
  uVar16 = (ushort)(((uint6)param_4[5] << 0x28) >> 0x20);
  auVar46._0_10_ = CONCAT82(auVar49._8_8_,uVar16) << 0x30;
  auVar48._12_4_ = auVar49._12_4_;
  auVar46._10_2_ = (short)(CONCAT12(param_4[9],CONCAT11(param_3[9],uVar54)) >> 8);
  auVar48._0_12_ = auVar46;
  auVar50._0_14_ = auVar48._0_14_;
  auVar42[0xd] = param_6[0xd];
  auVar42[0xc] = param_5[0xd];
  auVar40._0_8_ = auVar31._6_8_ << 0x30;
  auVar40._10_6_ = auVar39._10_6_;
  auVar40._8_2_ = (short)(CONCAT12(param_6[9],CONCAT11(param_5[9],param_6[7])) >> 8);
  auVar42._14_2_ = auVar39._14_2_;
  auVar42._0_12_ = auVar40._0_12_;
  auVar30._0_10_ = CONCAT82(auVar42._8_8_,(short)(((uint6)param_8[5] << 0x28) >> 0x20)) << 0x30;
  auVar41._12_4_ = auVar42._12_4_;
  auVar30._10_2_ = (short)((unkuint10)auVar87._0_10_ >> 0x40);
  auVar41._0_12_ = auVar30;
  auVar43._0_14_ = auVar41._0_14_;
  auVar43._14_2_ = auVar85._12_2_;
  auVar96[0xd] = param_6[0xc];
  auVar96[0xc] = param_5[0xc];
  auVar94._0_8_ = auVar85._6_8_ << 0x30;
  uVar13 = (undefined2)(CONCAT12(param_6[8],CONCAT11(param_5[8],param_6[6])) >> 8);
  auVar94._10_6_ = auVar93._10_6_;
  auVar94._8_2_ = uVar13;
  auVar96._14_2_ = auVar93._14_2_;
  auVar96._0_12_ = auVar94._0_12_;
  auVar84._0_10_ = CONCAT82(auVar96._8_8_,(short)(((uint6)param_8[4] << 0x28) >> 0x20)) << 0x30;
  auVar95._12_4_ = auVar96._12_4_;
  auVar84._10_2_ = (short)((unkuint10)auVar58._0_10_ >> 0x40);
  auVar95._0_12_ = auVar84;
  auVar97._0_14_ = auVar95._0_14_;
  auVar97._14_2_ = auVar56._12_2_;
  auVar28._0_8_ = auVar23._4_8_ << 0x20;
  auVar28._12_4_ = auVar27._12_4_;
  auVar28._8_4_ = auVar97._12_4_;
  auVar5._4_8_ = auVar28._8_8_;
  auVar5._0_4_ = (int)(((ulong)uVar15 << 0x30) >> 0x20);
  auVar29._0_12_ = auVar5 << 0x20;
  auVar29._12_4_ = auVar28._12_4_;
  auVar65._0_8_ = auVar55._4_8_ << 0x20;
  auVar65._12_4_ = auVar64._12_4_;
  auVar65._8_4_ = auVar30._8_4_;
  auVar8._2_8_ = auVar65._8_8_;
  auVar8._10_2_ = 0;
  auVar66._0_12_ = auVar8 << 0x30;
  auVar66._12_4_ = auVar46._8_4_;
  auVar44._0_8_ = auVar30._4_8_ << 0x20;
  auVar44._8_4_ = auVar43._12_4_;
  auVar44._12_4_ = auVar43._12_4_;
  auVar6._4_8_ = auVar44._8_8_;
  auVar6._0_4_ = (int)(((ulong)uVar16 << 0x30) >> 0x20);
  auVar45._0_12_ = auVar6 << 0x20;
  auVar45._12_4_ = auVar50._12_4_;
  auVar51._0_8_ = auVar46._4_8_ << 0x20;
  auVar51._8_4_ =
       (int)(CONCAT14(param_8[0xe],
                      CONCAT13(param_7[0xe],CONCAT12(param_6[0xe],CONCAT11(param_5[0xe],uVar21))))
            >> 8);
  auVar51._12_4_ = auVar50._12_4_;
  auVar7._4_8_ = auVar51._8_8_;
  auVar7._0_4_ = (int)(((ulong)uVar18 << 0x30) >> 0x20);
  auVar52._0_12_ = auVar7 << 0x20;
  auVar52._12_4_ = auVar81._12_4_;
  auVar82._0_8_ = auVar68._4_8_ << 0x20;
  auVar82._8_4_ =
       (int)(CONCAT14(uVar21,CONCAT13(param_7[10],CONCAT12(param_6[10],CONCAT11(param_5[10],uVar17))
                                     )) >> 8);
  auVar82._12_4_ = auVar81._12_4_;
  auVar10._1_8_ = auVar82._8_8_;
  auVar10[0] = param_4[2];
  auVar10._9_3_ = 0;
  auVar83._0_12_ = auVar10 << 0x38;
  auVar83._12_4_ = auVar68._8_4_;
  auVar98._0_8_ = auVar84._4_8_ << 0x20;
  auVar98._8_4_ =
       (int)(CONCAT14(uVar22,CONCAT13(param_7[0xb],
                                      CONCAT12(param_6[0xb],CONCAT11(param_5[0xb],uVar19)))) >> 8);
  auVar98._12_4_ = auVar97._12_4_;
  auVar9._1_8_ = auVar98._8_8_;
  auVar9[0] = param_4[3];
  auVar9._9_3_ = 0;
  auVar99._0_12_ = auVar9 << 0x38;
  auVar99._12_4_ =
       (int)(CONCAT14(param_4[0xb],
                      CONCAT13(param_3[0xb],CONCAT12(param_2[0xb],CONCAT11(param_1[0xb],uVar54))))
            >> 8);
  puVar11 = (undefined1 *)(param_9 + param_10 * -0x10);
  *puVar11 = param_5[0];
  puVar11[1] = param_6[0];
  puVar11[2] = param_7[0];
  puVar11[3] = param_8[0];
  puVar11[4] = param_1[0];
  puVar11[5] = param_2[0];
  puVar11[6] = param_3[0];
  puVar11[7] = param_4[0];
  puVar11 = puVar11 + param_10;
  *puVar11 = param_5[1];
  puVar11[1] = param_6[1];
  puVar11[2] = param_7[1];
  puVar11[3] = param_8[1];
  puVar11[4] = param_1[1];
  puVar11[5] = param_2[1];
  puVar11[6] = param_3[1];
  puVar11[7] = param_4[1];
  puVar11 = puVar11 + param_10;
  *puVar11 = param_5[2];
  puVar11[1] = param_6[2];
  puVar11[2] = param_7[2];
  puVar11[3] = param_8[2];
  puVar11[4] = param_1[2];
  puVar11[5] = param_2[2];
  puVar11[6] = param_3[2];
  puVar11[7] = param_4[2];
  puVar11 = puVar11 + param_10;
  *puVar11 = param_5[3];
  puVar11[1] = param_6[3];
  puVar11[2] = param_7[3];
  puVar11[3] = param_8[3];
  puVar11[4] = param_1[3];
  puVar11[5] = param_2[3];
  puVar11[6] = param_3[3];
  puVar11[7] = param_4[3];
  puVar11 = puVar11 + param_10;
  *puVar11 = param_5[4];
  puVar11[1] = param_6[4];
  puVar11[2] = param_7[4];
  puVar11[3] = param_8[4];
  puVar11[4] = param_1[4];
  puVar11[5] = param_2[4];
  puVar11[6] = param_3[4];
  puVar11[7] = param_4[4];
  puVar11 = puVar11 + param_10;
  *puVar11 = param_5[5];
  puVar11[1] = param_6[5];
  puVar11[2] = param_7[5];
  puVar11[3] = param_8[5];
  puVar11[4] = param_1[5];
  puVar11[5] = param_2[5];
  puVar11[6] = param_3[5];
  puVar11[7] = param_4[5];
  puVar11 = puVar11 + param_10;
  *puVar11 = param_5[6];
  puVar11[1] = param_6[6];
  puVar11[2] = param_7[6];
  puVar11[3] = uVar17;
  puVar11[4] = param_1[6];
  puVar11[5] = param_2[6];
  puVar11[6] = param_3[6];
  puVar11[7] = bVar53;
  puVar11 = puVar11 + param_10;
  *puVar11 = param_5[7];
  puVar11[1] = param_6[7];
  puVar11[2] = param_7[7];
  puVar11[3] = uVar19;
  puVar11[4] = param_1[7];
  puVar11[5] = param_2[7];
  puVar11[6] = param_3[7];
  puVar11[7] = uVar54;
  *(ulong *)(puVar11 + param_10) =
       CONCAT17(param_4[8],
                CONCAT16(param_3[8],
                         CONCAT15(uVar20,CONCAT14(param_1[8],
                                                  CONCAT13(param_8[8],CONCAT12(param_7[8],uVar13))))
                        ));
  puVar12 = (undefined8 *)((long)(puVar11 + param_10) + param_10);
  *puVar12 = auVar66._8_8_;
  puVar12 = (undefined8 *)((long)puVar12 + param_10);
  *puVar12 = auVar83._8_8_;
  puVar12 = (undefined8 *)((long)puVar12 + param_10);
  *puVar12 = auVar99._8_8_;
  puVar12 = (undefined8 *)((long)puVar12 + param_10);
  *puVar12 = auVar29._8_8_;
  puVar12 = (undefined8 *)((long)puVar12 + param_10);
  *puVar12 = auVar45._8_8_;
  puVar12 = (undefined8 *)((long)puVar12 + param_10);
  *puVar12 = auVar52._8_8_;
  puVar12 = (undefined8 *)((long)puVar12 + param_10);
  uVar1 = CONCAT13(auVar92[0xf],
                   CONCAT12(uVar14,(short)(CONCAT12(param_6[0xf],CONCAT11(param_5[0xf],uVar22)) >> 8
                                          )));
  uVar2 = CONCAT15(auVar38[0xf],CONCAT14(param_1[0xf],uVar1));
  *puVar12 = CONCAT17(param_4[0xf],CONCAT16(param_3[0xf],uVar2));
  return (long)puVar12 + param_10;
}

