
/* WARNING: Removing unreachable block (ram,0x00275b28) */
/* WARNING: Removing unreachable block (ram,0x00274d58) */
/* WARNING: Removing unreachable block (ram,0x00274c68) */
/* WARNING: Removing unreachable block (ram,0x002753e4) */
/* WARNING: Removing unreachable block (ram,0x00275dec) */
/* WARNING: Removing unreachable block (ram,0x002755a8) */
/* WARNING: Type propagation algorithm not settling */
/* MTFilterKernel::MTOnlinePlistParser::parseOldFilterConfig(MTFilterKernel::FilterPart&,
   std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char> >,
   int, int) */

uint MTFilterKernel::MTOnlinePlistParser::parseOldFilterConfig
               (long param_1,basic_string *param_2,int param_3,int param_4)

{
  DynamicFilterParam *pDVar1;
  short *psVar2;
  byte bVar3;
  DynamicFilterParam DVar4;
  long lVar5;
  undefined8 *puVar6;
  ulong *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  ulong *puVar10;
  bool bVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  ulong *puVar17;
  DynamicFilterParam *this;
  long *plVar18;
  long *plVar19;
  long *plVar20;
  long *plVar21;
  MTPugiDict *pMVar22;
  long *plVar23;
  char *pcVar24;
  size_t sVar25;
  size_t sVar26;
  char *pcVar27;
  void *pvVar28;
  DynamicFilterParam *pDVar29;
  DynamicFilterParam *pDVar30;
  DynamicFilterParam *pDVar31;
  long *plVar32;
  long *plVar33;
  int *piVar34;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *pbVar35;
  UniformValue *pUVar36;
  InputTexture *pIVar37;
  DynamicFilterParam *pDVar38;
  void *pvVar39;
  char *pcVar40;
  long lVar41;
  byte bVar42;
  basic_string *pbVar43;
  ulong uVar44;
  ulong uVar45;
  long lVar46;
  undefined8 *puVar47;
  ulong *puVar48;
  ulong uVar49;
  undefined8 *puVar50;
  undefined8 *puVar51;
  undefined8 *puVar52;
  ulong *puVar53;
  undefined8 *puVar54;
  undefined8 *puVar55;
  int *piVar56;
  ulong uVar57;
  ulong *puVar58;
  ulong *puVar59;
  undefined4 *puVar60;
  undefined4 *puVar61;
  float fVar62;
  undefined4 uVar63;
  float fVar64;
  float fVar65;
  float fVar66;
  undefined8 uVar67;
  undefined8 uVar68;
  undefined8 uVar69;
  undefined4 local_171c;
  ulong local_16e0;
  size_t sStack_16d8;
  char *local_16d0;
  ulong local_16c8;
  size_t sStack_16c0;
  char *local_16b8;
  ulong local_16b0;
  size_t sStack_16a8;
  char *local_16a0;
  ulong local_1690;
  size_t sStack_1688;
  char *local_1680;
  byte local_1678;
  undefined4 local_1677;
  undefined1 local_1673;
  void *local_1668;
  byte local_1660;
  undefined4 local_165f;
  void *local_1650;
  ushort local_1648;
  undefined1 local_1646;
  void *local_1638;
  byte local_1630;
  char local_162f [8];
  undefined2 local_1627;
  void *local_1620;
  byte local_1618;
  undefined4 local_1617;
  undefined3 uStack_1613;
  undefined1 local_1610;
  void *local_1608;
  ushort local_1600;
  undefined1 local_15fe;
  void *local_15f0;
  MTPugiDict aMStack_15e8 [8];
  undefined8 local_15e0;
  undefined8 uStack_15d8;
  __tree<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>,std::__ndk1::__map_value_compare<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>,std::__ndk1::less<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,true>,std::__ndk1::allocator<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>>>
  a_Stack_15d0 [24];
  byte local_15b8;
  char local_15b7 [8];
  undefined7 uStack_15af;
  undefined1 uStack_15a8;
  undefined2 uStack_15a7;
  undefined5 uStack_15a5;
  ushort local_15a0 [8];
  void *local_1590;
  ulong *local_1588;
  ulong *local_1580;
  ulong *local_1578;
  ulong *local_1570;
  ulong *local_1568;
  ulong *local_1560;
  ulong *local_1558;
  ulong *local_1550;
  ulong *local_1548;
  ulong *local_1540;
  ulong *local_1538;
  ulong *local_1530;
  ulong *local_1528;
  ulong *local_1520;
  ulong *local_1518;
  ulong *local_1510;
  ulong *local_1508;
  ulong *local_1500;
  undefined4 *local_14f8;
  undefined4 *local_14f0;
  undefined4 *local_14e8;
  ulong local_14e0;
  size_t sStack_14d8;
  void *local_14d0;
  ushort local_14c0;
  undefined1 local_14be;
  void *local_14b0;
  undefined4 local_14a8 [2];
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> local_14a0 [16];
  void *local_1490;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> local_1488 [16];
  void *local_1478;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> local_1470 [16];
  void *local_1460;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> local_1458 [16];
  void *local_1448;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> local_1440 [16];
  void *local_1430;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> local_1428 [16];
  void *local_1418;
  int local_1410;
  undefined4 local_1408;
  undefined1 local_13fc;
  undefined4 local_13f8 [2];
  byte local_13f0 [16];
  void *local_13e0;
  byte local_13d8;
  void *local_13c8;
  byte local_13c0;
  void *local_13b0;
  byte local_13a8;
  void *local_1398;
  byte local_1390;
  void *local_1380;
  byte local_1378;
  void *local_1368;
  undefined4 local_1360;
  undefined8 local_1348;
  undefined2 local_1340;
  ulong local_1338;
  ulong uStack_1330;
  char *local_1328;
  undefined4 local_1320;
  undefined8 local_131c;
  undefined8 uStack_1314;
  undefined8 local_130c;
  undefined8 uStack_1304;
  undefined8 local_12fc;
  undefined8 uStack_12f4;
  undefined8 local_12ec;
  undefined8 uStack_12e4;
  undefined8 local_12dc;
  undefined8 uStack_12d4;
  undefined8 local_12cc;
  undefined8 uStack_12c4;
  undefined8 local_12bc;
  undefined8 uStack_12b4;
  undefined8 local_12ac;
  undefined8 uStack_12a4;
  undefined8 local_111c;
  undefined8 local_1110;
  undefined2 local_1108;
  ulong local_1100;
  ulong uStack_10f8;
  char *local_10f0;
  undefined4 local_10e8;
  undefined8 local_10e4;
  undefined8 uStack_10dc;
  undefined8 local_10d4;
  undefined8 uStack_10cc;
  undefined8 local_10c4;
  undefined8 uStack_10bc;
  undefined8 local_10b4;
  undefined8 uStack_10ac;
  undefined8 local_10a4;
  undefined8 uStack_109c;
  undefined8 local_1094;
  undefined8 uStack_108c;
  undefined8 local_1084;
  undefined8 uStack_107c;
  undefined8 local_1074;
  undefined8 uStack_106c;
  undefined8 local_ee4;
  ulong local_ed8;
  ulong uStack_ed0;
  char *local_ec8;
  undefined4 local_ec0;
  undefined8 local_ebc;
  undefined8 uStack_eb4;
  undefined8 local_eac;
  undefined8 uStack_ea4;
  undefined8 local_e9c;
  undefined8 uStack_e94;
  undefined8 local_e8c;
  undefined8 uStack_e84;
  undefined8 local_e7c;
  undefined8 uStack_e74;
  undefined8 local_e6c;
  undefined8 uStack_e64;
  undefined8 local_e5c;
  undefined8 uStack_e54;
  undefined8 local_e4c;
  undefined8 uStack_e44;
  undefined8 local_cbc;
  ulong local_cb0;
  ulong uStack_ca8;
  char *local_ca0;
  undefined4 local_c98;
  undefined8 local_c94;
  undefined8 uStack_c8c;
  undefined8 local_c84;
  undefined8 uStack_c7c;
  undefined8 local_c74;
  undefined8 uStack_c6c;
  undefined8 local_c64;
  undefined8 uStack_c5c;
  undefined8 local_c54;
  undefined8 uStack_c4c;
  undefined8 local_c44;
  undefined8 uStack_c3c;
  undefined8 local_c34;
  undefined8 uStack_c2c;
  undefined8 local_c24;
  undefined8 uStack_c1c;
  undefined8 local_a94;
  ulong local_a88;
  ulong uStack_a80;
  char *local_a78;
  undefined4 local_a70;
  undefined8 local_a6c;
  undefined8 uStack_a64;
  undefined8 local_a5c;
  undefined8 uStack_a54;
  undefined8 local_a4c;
  undefined8 uStack_a44;
  undefined8 local_a3c;
  undefined8 uStack_a34;
  undefined8 local_a2c;
  undefined8 uStack_a24;
  undefined8 local_a1c;
  undefined8 uStack_a14;
  undefined8 local_a0c;
  undefined8 uStack_a04;
  undefined8 local_9fc;
  undefined8 uStack_9f4;
  undefined8 local_86c;
  ulong local_860;
  ulong uStack_858;
  char *local_850;
  undefined4 local_848;
  undefined8 local_844;
  undefined8 uStack_83c;
  undefined8 local_834;
  undefined8 uStack_82c;
  undefined8 local_824;
  undefined8 uStack_81c;
  undefined8 local_814;
  undefined8 uStack_80c;
  undefined8 local_804;
  undefined8 uStack_7fc;
  undefined8 local_7f4;
  undefined8 uStack_7ec;
  undefined8 local_7e4;
  undefined8 uStack_7dc;
  undefined8 local_7d4;
  undefined8 uStack_7cc;
  undefined8 local_644;
  ulong local_638;
  ulong uStack_630;
  char *local_628;
  undefined4 local_620;
  undefined8 local_61c;
  undefined8 uStack_614;
  undefined8 local_60c;
  undefined8 uStack_604;
  undefined8 local_5fc;
  undefined8 uStack_5f4;
  undefined8 local_5ec;
  undefined8 uStack_5e4;
  undefined8 local_5dc;
  undefined8 uStack_5d4;
  undefined8 local_5cc;
  undefined8 uStack_5c4;
  undefined8 local_5bc;
  undefined8 uStack_5b4;
  undefined8 local_5ac;
  undefined8 uStack_5a4;
  undefined8 local_41c;
  ulong local_410;
  ulong uStack_408;
  int *local_400;
  undefined4 local_3f8;
  undefined8 local_3f4;
  undefined8 uStack_3ec;
  undefined8 local_3e4;
  undefined8 uStack_3dc;
  undefined8 local_3d4;
  undefined8 uStack_3cc;
  undefined8 local_3c4;
  undefined8 uStack_3bc;
  undefined8 local_3b4;
  undefined8 uStack_3ac;
  undefined8 local_3a4;
  undefined8 uStack_39c;
  undefined8 local_394;
  undefined8 uStack_38c;
  undefined8 local_384;
  undefined8 uStack_37c;
  undefined8 local_1f4;
  MTPugiPlist aMStack_1e8 [320];
  long local_a8;
  
  lVar5 = tpidr_el0;
  local_a8 = *(long *)(lVar5 + 0x28);
  MTPugiPlist::MTPugiPlist(aMStack_1e8);
  pbVar43 = *(basic_string **)(param_2 + 0x10);
  if (((byte)*param_2 & 1) == 0) {
    pbVar43 = param_2 + 1;
  }
  uVar12 = MTPugiPlist::Load(aMStack_1e8,(char *)pbVar43);
  if ((uVar12 & 1) == 0) {
    iVar13 = MTRTFILTERKERNEL_GetLogLevel();
    if (iVar13 < 6) {
      pbVar43 = param_2 + 1;
      if (((byte)*param_2 & 1) != 0) {
        pbVar43 = *(basic_string **)(param_2 + 0x10);
      }
      __android_log_print(6,"FilterKernel","load %s faile!",pbVar43);
    }
  }
  else {
    local_14c0 = 0x2f02;
    local_14be = 0;
    if (-1 < param_3) {
      MathHelper::intToString(param_3);
      puVar17 = (ulong *)std::__ndk1::
                         basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         ::append((char *)&local_638);
      local_400 = (int *)puVar17[2];
      uStack_408 = puVar17[1];
      local_410 = *puVar17;
      puVar17[1] = 0;
      puVar17[2] = 0;
      *puVar17 = 0;
      piVar56 = (int *)((ulong)&local_410 | 1);
      if ((local_410 & 1) != 0) {
        piVar56 = local_400;
      }
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      append((char *)&local_14c0,(ulong)piVar56);
      if ((local_410 & 1) != 0) {
        operator_delete(local_400);
      }
      if ((local_638 & 1) != 0) {
        operator_delete(local_628);
      }
    }
    *(int *)(param_1 + 0x30) = param_3;
    *(int *)(param_1 + 0x3c) = param_4;
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
              (param_1 + 0x18),param_2);
    uVar44 = (ulong)((byte)*param_2 >> 1);
    pbVar43 = param_2 + 1;
    uVar57 = uVar44;
    if (((byte)*param_2 & 1) != 0) {
      uVar44 = *(ulong *)(param_2 + 8);
      pbVar43 = *(basic_string **)(param_2 + 0x10);
      uVar57 = *(ulong *)(param_2 + 8);
    }
    do {
      if (uVar44 == 0) {
        uVar45 = 0xffffffffffffffff;
        break;
      }
      uVar45 = uVar44 - 1;
      lVar46 = uVar44 - 1;
      uVar44 = uVar45;
    } while (pbVar43[lVar46] != (basic_string)0x2f);
    if ((ulong)(long)(int)uVar45 <= uVar57) {
      uVar57 = (long)(int)uVar45;
    }
    if (0xffffffffffffffef < uVar57) {
      if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
        FUN_001c3100(&local_410);
      }
      goto LAB_002793d4;
    }
    if (uVar57 < 0x17) {
      piVar56 = (int *)((ulong)&local_410 | 1);
      local_410 = CONCAT71(local_410._1_7_,(char)((int)uVar57 << 1));
      if (uVar57 != 0) goto LAB_00274410;
    }
    else {
      uVar44 = (uVar57 | 0xf) + 1;
      piVar56 = operator_new(uVar44);
      local_410 = uVar44 | 1;
      uStack_408 = uVar57;
      local_400 = piVar56;
LAB_00274410:
      memmove(piVar56,pbVar43,uVar57);
    }
    *(undefined1 *)((long)piVar56 + uVar57) = 0;
    pvVar39 = (void *)((ulong)&local_14c0 | 1);
    if ((local_14c0 & 1) != 0) {
      pvVar39 = local_14b0;
    }
    puVar17 = (ulong *)std::__ndk1::
                       basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                       ::append((char *)&local_410,(ulong)pvVar39);
    local_14d0 = (void *)puVar17[2];
    sStack_14d8 = puVar17[1];
    local_14e0 = *puVar17;
    *puVar17 = 0;
    puVar17[1] = 0;
    puVar17[2] = 0;
    if ((local_410 & 1) != 0) {
      operator_delete(local_400);
    }
    this = operator_new(0x80);
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0x74) = 0;
    *(undefined4 *)(this + 0x78) = 0;
    local_14f0 = (undefined4 *)0x0;
    pDVar38 = this + 0x10;
    *(undefined8 *)(this + 0x18) = 0;
    *(undefined8 *)pDVar38 = 0;
    *(undefined8 *)(this + 0x28) = 0;
    *(undefined8 *)(this + 0x20) = 0;
    *(undefined8 *)(this + 0x38) = 0;
    *(undefined8 *)(this + 0x30) = 0;
    *(undefined8 *)(this + 0x48) = 0;
    *(undefined8 *)(this + 0x40) = 0;
    *(undefined8 *)(this + 0x58) = 0;
    *(undefined8 *)(this + 0x50) = 0;
    *(undefined8 *)(this + 0x68) = 0;
    *(undefined8 *)(this + 0x60) = 0;
    local_15b8 = 0x22;
    *(undefined8 *)this = 1000;
    local_14f8 = (undefined4 *)0x0;
    local_14e8 = (undefined4 *)0x0;
    local_1508 = (ulong *)0x0;
    local_1510 = (ulong *)0x0;
    local_1500 = (ulong *)0x0;
    local_1520 = (ulong *)0x0;
    local_1528 = (ulong *)0x0;
    local_1518 = (ulong *)0x0;
    local_1538 = (ulong *)0x0;
    local_1540 = (ulong *)0x0;
    local_1530 = (ulong *)0x0;
    local_1558 = (ulong *)0x0;
    local_1550 = (ulong *)0x0;
    local_1548 = (ulong *)0x0;
    local_1570 = (ulong *)0x0;
    local_1568 = (ulong *)0x0;
    local_1560 = (ulong *)0x0;
    local_1588 = (ulong *)0x0;
    local_1580 = (ulong *)0x0;
    local_1578 = (ulong *)0x0;
    local_15a0[0] = 0;
    uStack_15a7 = 0x67;
    uStack_15af = 0x702e303031796c;
    uStack_15a8 = 0x6e;
    builtin_strncpy(local_15b7,"PSMultip",8);
    MTPugiDict::MTPugiDict(aMStack_15e8);
    if (param_3 < 0) {
      pMVar22 = (MTPugiDict *)MTPugiPlist::GetRootDict(aMStack_1e8);
      uStack_15d8 = *(undefined8 *)(pMVar22 + 0x10);
      local_15e0 = *(undefined8 *)(pMVar22 + 8);
      if (aMStack_15e8 != pMVar22) {
        std::__ndk1::
        __tree<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>,std::__ndk1::__map_value_compare<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>,std::__ndk1::less<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,true>,std::__ndk1::allocator<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>>>
        ::
        __assign_multi<std::__ndk1::__tree_const_iterator<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>,std::__ndk1::__tree_node<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>,void*>*,long>>
                  (a_Stack_15d0,*(undefined8 *)(pMVar22 + 0x18),pMVar22 + 0x20);
      }
    }
    else {
      plVar18 = (long *)MTPugiPlist::GetRootArray(aMStack_1e8);
      for (iVar13 = 0; iVar14 = (**(code **)(*plVar18 + 0x90))(plVar18), iVar13 < iVar14;
          iVar13 = iVar13 + 1) {
        plVar19 = (long *)(**(code **)(*plVar18 + 0x60))(plVar18,iVar13);
        plVar20 = (long *)(**(code **)(*plVar19 + 0x80))();
        while (plVar21 = (long *)(**(code **)(*plVar19 + 0x88))(plVar19), plVar20 != plVar21) {
          bVar42 = *(byte *)(plVar20 + 4);
          uVar57 = (ulong)(bVar42 >> 1);
          if ((bVar42 & 1) != 0) {
            uVar57 = plVar20[5];
          }
          if (uVar57 == 2) {
            psVar2 = (short *)((long)plVar20 + 0x21);
            if ((bVar42 & 1) != 0) {
              psVar2 = (short *)plVar20[6];
            }
            if ((*psVar2 == 0x4449) &&
               (iVar14 = MTPugiAny::GetInteger((MTPugiAny *)(plVar20 + 7)), iVar14 == param_3)) {
              pMVar22 = (MTPugiDict *)(**(code **)(*plVar18 + 0x60))(plVar18,iVar13);
              uStack_15d8 = *(undefined8 *)(pMVar22 + 0x10);
              local_15e0 = *(undefined8 *)(pMVar22 + 8);
              if (aMStack_15e8 != pMVar22) {
                std::__ndk1::
                __tree<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>,std::__ndk1::__map_value_compare<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>,std::__ndk1::less<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,true>,std::__ndk1::allocator<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>>>
                ::
                __assign_multi<std::__ndk1::__tree_const_iterator<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>,std::__ndk1::__tree_node<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,MTFilterKernel::MTPugiAny>,void*>*,long>>
                          (a_Stack_15d0,*(undefined8 *)(pMVar22 + 0x18),pMVar22 + 0x20);
              }
            }
          }
          plVar21 = (long *)plVar20[1];
          plVar23 = plVar20;
          if ((long *)plVar20[1] == (long *)0x0) {
            do {
              plVar20 = (long *)plVar23[2];
              bVar11 = (long *)*plVar20 != plVar23;
              plVar23 = plVar20;
            } while (bVar11);
          }
          else {
            do {
              plVar20 = plVar21;
              plVar21 = (long *)*plVar20;
            } while ((long *)*plVar20 != (long *)0x0);
          }
        }
      }
    }
    plVar18 = (long *)MTPugiDict::Begin(aMStack_15e8);
    fVar64 = 0.0;
    fVar62 = 0.0;
    fVar66 = 0.0;
    uVar63 = 0x3f800000;
    piVar56 = (int *)((ulong)&local_410 | 1);
    fVar65 = 1.0;
    pvVar39 = (void *)((ulong)&local_14e0 | 1);
    local_171c = 0;
    pcVar40 = (char *)((ulong)&local_638 | 1);
    while (plVar19 = (long *)MTPugiDict::End(aMStack_15e8), plVar18 != plVar19) {
      bVar42 = *(byte *)(plVar18 + 4);
      uVar45 = plVar18[5];
      uVar44 = (ulong)(bVar42 >> 1);
      uVar57 = uVar44;
      if ((bVar42 & 1) != 0) {
        uVar57 = uVar45;
      }
      if (uVar57 == 10) {
        plVar19 = (long *)((long)plVar18 + 0x21);
        if ((bVar42 & 1) != 0) {
          plVar19 = (long *)plVar18[6];
        }
        if (*plVar19 != 0x61507265746c6946 || (short)plVar19[1] != 0x7472) goto LAB_00274754;
        plVar19 = (long *)MTPugiAny::GetArray((MTPugiAny *)(plVar18 + 7));
        for (iVar13 = 0; iVar14 = (**(code **)(*plVar19 + 0x90))(plVar19), iVar13 < iVar14;
            iVar13 = iVar13 + 1) {
          plVar20 = (long *)(**(code **)(*plVar19 + 0x68))(plVar19,iVar13);
          plVar21 = (long *)(**(code **)(*plVar20 + 0x80))();
          while (plVar23 = (long *)(**(code **)(*plVar20 + 0x88))(plVar20), plVar21 != plVar23) {
            bVar42 = *(byte *)(plVar21 + 4);
            uVar45 = plVar21[5];
            uVar44 = (ulong)(bVar42 >> 1);
            uVar57 = uVar44;
            if ((bVar42 & 1) != 0) {
              uVar57 = uVar45;
            }
            if (uVar57 == 6) {
              piVar34 = (int *)((long)plVar21 + 0x21);
              if ((bVar42 & 1) != 0) {
                piVar34 = (int *)plVar21[6];
              }
              if (*piVar34 != 0x61505356 || (short)piVar34[1] != 0x6874) goto LAB_00274bc0;
              pcVar24 = (char *)MTPugiAny::GetString((MTPugiAny *)(plVar21 + 7));
              uVar57 = local_14e0;
              sVar26 = local_14e0 >> 1 & 0x7f;
              if ((local_14e0 & 1) != 0) {
                sVar26 = sStack_14d8;
              }
              sVar25 = strlen(pcVar24);
              uVar44 = sVar26 + sVar25;
              if (0xffffffffffffffef < uVar44) {
                if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                  FUN_001c3100(&local_410);
                }
                goto LAB_002793d4;
              }
              if (uVar44 < 0x17) {
                uStack_408 = 0;
                local_400 = (int *)0x0;
                local_410 = (ulong)(byte)(((uint)uVar44 & 0xff) << 1);
                piVar34 = piVar56;
              }
              else {
                uVar45 = (uVar44 | 0xf) + 1;
                local_400 = operator_new(uVar45);
                local_410 = uVar45 | 1;
                uStack_408 = uVar44;
                piVar34 = local_400;
              }
              if (sVar26 != 0) {
                pvVar28 = pvVar39;
                if ((uVar57 & 1) != 0) {
                  pvVar28 = local_14d0;
                }
                memmove(piVar34,pvVar28,sVar26);
              }
              if (sVar25 != 0) {
                memmove((undefined1 *)((long)piVar34 + sVar26),pcVar24,sVar25);
              }
              ((undefined1 *)((long)piVar34 + sVar26))[sVar25] = 0;
              if (((byte)this[0x28] & 1) != 0) {
                operator_delete(*(void **)(this + 0x38));
              }
              *(ulong *)(this + 0x30) = uStack_408;
              *(ulong *)(this + 0x28) = local_410;
              *(int **)(this + 0x38) = local_400;
              bVar42 = *(byte *)(plVar21 + 4);
              uVar45 = plVar21[5];
              uVar44 = (ulong)(bVar42 >> 1);
              uVar57 = uVar44;
              if ((bVar42 & 1) != 0) {
                uVar57 = uVar45;
              }
            }
            else {
LAB_00274bc0:
              uVar57 = uVar44;
              if ((bVar42 & 1) != 0) {
                uVar57 = uVar45;
              }
            }
            bVar42 = bVar42 & 1;
            if (uVar57 == 6) {
              piVar34 = (int *)((long)plVar21 + 0x21);
              if (bVar42 != 0) {
                piVar34 = (int *)plVar21[6];
              }
              if (*piVar34 == 0x61505346 && (short)piVar34[1] == 0x6874) {
                pcVar24 = (char *)MTPugiAny::GetString((MTPugiAny *)(plVar21 + 7));
                uVar57 = local_14e0;
                sVar26 = local_14e0 >> 1 & 0x7f;
                if ((local_14e0 & 1) != 0) {
                  sVar26 = sStack_14d8;
                }
                sVar25 = strlen(pcVar24);
                uVar44 = sVar26 + sVar25;
                if (0xffffffffffffffef < uVar44) {
                  if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                    FUN_001c3100(&local_410);
                  }
                  goto LAB_002793d4;
                }
                if (uVar44 < 0x17) {
                  uStack_408 = 0;
                  local_400 = (int *)0x0;
                  local_410 = (ulong)(byte)(((uint)uVar44 & 0xff) << 1);
                  piVar34 = piVar56;
                }
                else {
                  uVar45 = (uVar44 | 0xf) + 1;
                  local_400 = operator_new(uVar45);
                  local_410 = uVar45 | 1;
                  uStack_408 = uVar44;
                  piVar34 = local_400;
                }
                if (sVar26 != 0) {
                  pvVar28 = pvVar39;
                  if ((uVar57 & 1) != 0) {
                    pvVar28 = local_14d0;
                  }
                  memmove(piVar34,pvVar28,sVar26);
                }
                if (sVar25 != 0) {
                  memmove((undefined1 *)((long)piVar34 + sVar26),pcVar24,sVar25);
                }
                ((undefined1 *)((long)piVar34 + sVar26))[sVar25] = 0;
                if (((byte)*pDVar38 & 1) != 0) {
                  operator_delete(*(void **)(this + 0x20));
                }
                *(ulong *)(this + 0x18) = uStack_408;
                *(ulong *)pDVar38 = local_410;
                *(int **)(this + 0x20) = local_400;
                uVar45 = plVar21[5];
                uVar44 = (ulong)(*(byte *)(plVar21 + 4) >> 1);
                bVar42 = *(byte *)(plVar21 + 4) & 1;
              }
            }
            uVar57 = uVar44;
            if (bVar42 != 0) {
              uVar57 = uVar45;
            }
            if (uVar57 == 5) {
              piVar34 = (int *)((long)plVar21 + 0x21);
              if (bVar42 != 0) {
                piVar34 = (int *)plVar21[6];
              }
              if (*piVar34 != 0x68706c41 || (char)piVar34[1] != 'a') goto LAB_00274e24;
              fVar65 = (float)MTPugiAny::GetFloat((MTPugiAny *)(plVar21 + 7));
              bVar3 = *(byte *)(plVar21 + 4);
              uVar45 = plVar21[5];
              uVar44 = (ulong)(bVar3 >> 1);
              bVar42 = bVar3 & 1;
              uVar57 = uVar44;
              if ((bVar3 & 1) != 0) {
                uVar57 = uVar45;
              }
            }
            else {
LAB_00274e24:
              uVar57 = uVar44;
              if (bVar42 != 0) {
                uVar57 = uVar45;
              }
            }
            if (uVar57 == 4) {
              piVar34 = (int *)((long)plVar21 + 0x21);
              if (bVar42 != 0) {
                piVar34 = (int *)plVar21[6];
              }
              if (*piVar34 == 0x657a6953) {
                uVar16 = MTPugiAny::GetInteger((MTPugiAny *)(plVar21 + 7));
                *(undefined4 *)(this + 0x74) = uVar16;
                uVar45 = plVar21[5];
                uVar44 = (ulong)(*(byte *)(plVar21 + 4) >> 1);
                bVar42 = *(byte *)(plVar21 + 4) & 1;
              }
            }
            if (bVar42 != 0) {
              uVar44 = uVar45;
            }
            if (uVar44 == 7) {
              piVar34 = (int *)((long)plVar21 + 0x21);
              if (bVar42 != 0) {
                piVar34 = (int *)plVar21[6];
              }
              if (*piVar34 == 0x5074754c && *(int *)((long)piVar34 + 3) == 0x68746150) {
                pcVar24 = (char *)MTPugiAny::GetString((MTPugiAny *)(plVar21 + 7));
                sVar26 = strlen(pcVar24);
                if (0xffffffffffffffef < sVar26) {
                  if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                    FUN_001c3100(&local_410);
                  }
                  goto LAB_002793d4;
                }
                if (sVar26 < 0x17) {
                  local_410 = CONCAT71(local_410._1_7_,(char)((int)sVar26 << 1));
                  piVar34 = piVar56;
                  if (sVar26 != 0) goto LAB_00274ffc;
                  *(undefined1 *)piVar56 = 0;
                  if (local_1500 <= local_1508) goto LAB_00275020;
LAB_00274f3c:
                  puVar58 = local_1508 + 3;
                  local_1508[2] = (ulong)local_400;
                  local_1508[1] = uStack_408;
                  *local_1508 = local_410;
                  local_400 = (int *)0x0;
                  uStack_408 = 0;
                  local_410 = 0;
                }
                else {
                  uVar57 = (sVar26 | 0xf) + 1;
                  piVar34 = operator_new(uVar57);
                  local_410 = uVar57 | 1;
                  uStack_408 = sVar26;
                  local_400 = piVar34;
LAB_00274ffc:
                  memmove(piVar34,pcVar24,sVar26);
                  *(undefined1 *)((long)piVar34 + sVar26) = 0;
                  if (local_1508 < local_1500) goto LAB_00274f3c;
LAB_00275020:
                  puVar53 = local_1508;
                  puVar17 = local_1510;
                  lVar46 = (long)local_1508 - (long)local_1510 >> 3;
                  uVar57 = lVar46 * -0x5555555555555555 + 1;
                  if (0xaaaaaaaaaaaaaaa < uVar57) {
                    if (*(long *)(lVar5 + 0x28) != local_a8) goto LAB_002793d4;
                    FUN_001c8a80(&local_1510);
                    goto LAB_00278990;
                  }
                  lVar41 = (long)local_1500 - (long)local_1510 >> 3;
                  uVar44 = lVar41 * 0x5555555555555556;
                  if (uVar44 < uVar57 || uVar44 - uVar57 == 0) {
                    uVar44 = uVar57;
                  }
                  if (0x555555555555554 < (ulong)(lVar41 * -0x5555555555555555)) {
                    uVar44 = 0xaaaaaaaaaaaaaaa;
                  }
                  if (uVar44 == 0) {
                    pvVar28 = (void *)0x0;
                  }
                  else {
                    if (0xaaaaaaaaaaaaaaa < uVar44) {
                      if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                        FUN_001c8a94();
                      }
                      goto LAB_002793d4;
                    }
                    pvVar28 = operator_new(uVar44 * 0x18);
                  }
                  piVar34 = local_400;
                  uVar45 = uStack_408;
                  uVar57 = local_410;
                  puVar7 = local_1510;
                  local_1510 = (ulong *)((long)pvVar28 + lVar46 * 8);
                  local_400 = (int *)0x0;
                  local_410 = 0;
                  local_1500 = (ulong *)((long)pvVar28 + uVar44 * 0x18);
                  uStack_408 = 0;
                  puVar58 = local_1510 + 3;
                  local_1510[1] = uVar45;
                  *local_1510 = uVar57;
                  local_1510[2] = (ulong)piVar34;
                  puVar10 = puVar58;
                  if (puVar53 != puVar17) {
                    do {
                      uVar44 = puVar53[-2];
                      uVar57 = puVar53[-3];
                      local_1510[-1] = puVar53[-1];
                      puVar48 = puVar53 + -3;
                      local_1510[-2] = uVar44;
                      local_1510[-3] = uVar57;
                      local_1510 = local_1510 + -3;
                      puVar53[-2] = 0;
                      puVar53[-1] = 0;
                      puVar53[-3] = 0;
                      puVar53 = puVar48;
                      puVar59 = local_1508;
                    } while (puVar48 != puVar17);
                    while (puVar17 = puVar59, local_1508 = puVar10, puVar53 = puVar7,
                          puVar10 = local_1508, puVar17 != puVar7) {
                      puVar59 = puVar17 + -3;
                      if ((*puVar59 & 1) != 0) {
                        operator_delete((void *)puVar17[-1]);
                        puVar10 = local_1508;
                      }
                    }
                  }
                  local_1508 = puVar10;
                  if (puVar53 != (ulong *)0x0) {
                    operator_delete(puVar53);
                  }
                }
                local_1508 = puVar58;
                if ((local_410 & 1) != 0) {
                  operator_delete(local_400);
                }
              }
            }
            plVar23 = (long *)plVar21[1];
            plVar32 = plVar21;
            if ((long *)plVar21[1] == (long *)0x0) {
              do {
                plVar21 = (long *)plVar32[2];
                bVar11 = (long *)*plVar21 != plVar32;
                plVar32 = plVar21;
              } while (bVar11);
            }
            else {
              do {
                plVar21 = plVar23;
                plVar23 = (long *)*plVar21;
              } while ((long *)*plVar21 != (long *)0x0);
            }
          }
        }
        bVar42 = *(byte *)(plVar18 + 4);
        uVar45 = plVar18[5];
        uVar44 = (ulong)(bVar42 >> 1);
        uVar57 = uVar44;
        if ((bVar42 & 1) != 0) {
          uVar57 = uVar45;
        }
      }
      else {
LAB_00274754:
        uVar57 = uVar44;
        if ((bVar42 & 1) != 0) {
          uVar57 = uVar45;
        }
      }
      bVar42 = bVar42 & 1;
      if (uVar57 == 8) {
        plVar19 = (long *)((long)plVar18 + 0x21);
        if (bVar42 != 0) {
          plVar19 = (long *)plVar18[6];
        }
        if (*plVar19 == 0x746369446b726164) {
          plVar19 = (long *)MTPugiAny::GetDict((MTPugiAny *)(plVar18 + 7));
          plVar20 = (long *)(**(code **)(*plVar19 + 0x80))();
          while (plVar21 = (long *)(**(code **)(*plVar19 + 0x88))(plVar19), plVar20 != plVar21) {
            bVar42 = *(byte *)(plVar20 + 4);
            uVar45 = plVar20[5];
            uVar44 = (ulong)(bVar42 >> 1);
            uVar57 = uVar44;
            if ((bVar42 & 1) != 0) {
              uVar57 = uVar45;
            }
            if (uVar57 == 0x12) {
              plVar21 = (long *)((long)plVar20 + 0x21);
              if ((bVar42 & 1) != 0) {
                plVar21 = (long *)plVar20[6];
              }
              if ((*plVar21 != 0x6e656c426b726144 || plVar21[1] != 0x6169726574616d64) ||
                  (short)plVar21[2] != 0x736c) goto LAB_0027482c;
              MTPugiAny::GetString((MTPugiAny *)(plVar20 + 7));
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::assign
                        ((char *)local_15a0);
              bVar42 = *(byte *)(plVar20 + 4);
              uVar45 = plVar20[5];
              uVar44 = (ulong)(bVar42 >> 1);
              uVar57 = uVar44;
              if ((bVar42 & 1) != 0) {
                uVar57 = uVar45;
              }
            }
            else {
LAB_0027482c:
              uVar57 = uVar44;
              if ((bVar42 & 1) != 0) {
                uVar57 = uVar45;
              }
            }
            bVar42 = bVar42 & 1;
            if (uVar57 == 0xe) {
              plVar21 = (long *)((long)plVar20 + 0x21);
              if (bVar42 != 0) {
                plVar21 = (long *)plVar20[6];
              }
              if (*plVar21 == 0x6e656c426b726144 &&
                  *(long *)((long)plVar21 + 6) == 0x656c797473646e65) {
                MTPugiAny::GetString((MTPugiAny *)(plVar20 + 7));
                std::__ndk1::
                basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
                assign((char *)&local_15b8);
                uVar45 = plVar20[5];
                uVar44 = (ulong)(*(byte *)(plVar20 + 4) >> 1);
                bVar42 = *(byte *)(plVar20 + 4) & 1;
              }
            }
            uVar57 = uVar44;
            if (bVar42 != 0) {
              uVar57 = uVar45;
            }
            if (uVar57 == 0xe) {
              plVar21 = (long *)((long)plVar20 + 0x21);
              if (bVar42 != 0) {
                plVar21 = (long *)plVar20[6];
              }
              if (*plVar21 != 0x6e656c426b726144 ||
                  *(long *)((long)plVar21 + 6) != 0x6168706c61646e65) goto LAB_00274930;
              uVar63 = MTPugiAny::GetFloat((MTPugiAny *)(plVar20 + 7));
              bVar3 = *(byte *)(plVar20 + 4);
              uVar45 = plVar20[5];
              uVar44 = (ulong)(bVar3 >> 1);
              bVar42 = bVar3 & 1;
              uVar57 = uVar44;
              if ((bVar3 & 1) != 0) {
                uVar57 = uVar45;
              }
            }
            else {
LAB_00274930:
              uVar57 = uVar44;
              if (bVar42 != 0) {
                uVar57 = uVar45;
              }
            }
            if (uVar57 == 0x13) {
              plVar21 = (long *)((long)plVar20 + 0x21);
              if (bVar42 != 0) {
                plVar21 = (long *)plVar20[6];
              }
              if ((*plVar21 == 0x657466416b726144 && plVar21[1] == 0x7453646e656c4272) &&
                  *(long *)((long)plVar21 + 0xb) == 0x6574617453646e65) {
                fVar62 = (float)MTPugiAny::GetFloat((MTPugiAny *)(plVar20 + 7));
                uVar45 = plVar20[5];
                uVar44 = (ulong)(*(byte *)(plVar20 + 4) >> 1);
                bVar42 = *(byte *)(plVar20 + 4) & 1;
              }
            }
            uVar57 = uVar44;
            if (bVar42 != 0) {
              uVar57 = uVar45;
            }
            if (uVar57 == 0xe) {
              plVar21 = (long *)((long)plVar20 + 0x21);
              if (bVar42 != 0) {
                plVar21 = (long *)plVar20[6];
              }
              if (*plVar21 != 0x6e656c426b726144 ||
                  *(long *)((long)plVar21 + 6) != 0x6574617473646e65) goto LAB_00274a38;
              fVar62 = (float)MTPugiAny::GetFloat((MTPugiAny *)(plVar20 + 7));
              bVar3 = *(byte *)(plVar20 + 4);
              bVar42 = bVar3 & 1;
              uVar44 = (ulong)(bVar3 >> 1);
              if ((bVar3 & 1) != 0) {
                uVar44 = plVar20[5];
              }
            }
            else {
LAB_00274a38:
              if (bVar42 != 0) {
                uVar44 = uVar45;
              }
            }
            if (uVar44 == 9) {
              plVar21 = (long *)((long)plVar20 + 0x21);
              if (bVar42 != 0) {
                plVar21 = (long *)plVar20[6];
              }
              if (*plVar21 == 0x657466416b726144 && (char)plVar21[1] == 'r') {
                fVar64 = (float)MTPugiAny::GetFloat((MTPugiAny *)(plVar20 + 7));
              }
            }
            plVar21 = (long *)plVar20[1];
            plVar23 = plVar20;
            if ((long *)plVar20[1] == (long *)0x0) {
              do {
                plVar20 = (long *)plVar23[2];
                bVar11 = (long *)*plVar20 != plVar23;
                plVar23 = plVar20;
              } while (bVar11);
            }
            else {
              do {
                plVar20 = plVar21;
                plVar21 = (long *)*plVar20;
              } while ((long *)*plVar20 != (long *)0x0);
            }
          }
          uVar45 = plVar18[5];
          uVar44 = (ulong)(*(byte *)(plVar18 + 4) >> 1);
          bVar42 = *(byte *)(plVar18 + 4) & 1;
        }
      }
      uVar57 = uVar44;
      if (bVar42 != 0) {
        uVar57 = uVar45;
      }
      if (uVar57 == 10) {
        plVar19 = (long *)((long)plVar18 + 0x21);
        if (bVar42 != 0) {
          plVar19 = (long *)plVar18[6];
        }
        if (*plVar19 != 0x6944656e696c6e6f || (short)plVar19[1] != 0x7463) goto LAB_0027522c;
        plVar19 = (long *)MTPugiAny::GetArray((MTPugiAny *)(plVar18 + 7));
        for (iVar13 = 0; iVar14 = (**(code **)(*plVar19 + 0x90))(), iVar13 < iVar14;
            iVar13 = iVar13 + 1) {
          if (iVar13 == param_4) {
            plVar20 = (long *)(**(code **)(*plVar19 + 0x68))();
            plVar21 = (long *)(**(code **)(*plVar20 + 0x80))();
            while (plVar23 = (long *)(**(code **)(*plVar20 + 0x88))(), plVar21 != plVar23) {
              bVar42 = *(byte *)(plVar21 + 4);
              uVar45 = plVar21[5];
              uVar44 = (ulong)(bVar42 >> 1);
              uVar57 = uVar44;
              if ((bVar42 & 1) != 0) {
                uVar57 = uVar45;
              }
              if (uVar57 == 9) {
                plVar23 = (long *)((long)plVar21 + 0x21);
                if ((bVar42 & 1) != 0) {
                  plVar23 = (long *)plVar21[6];
                }
                if (*plVar23 != 0x707954656c616353 || (char)plVar23[1] != 'e') goto LAB_00275a84;
                plVar32 = (long *)MTPugiAny::GetArray((MTPugiAny *)(plVar21 + 7));
                plVar23 = (long *)(**(code **)(*plVar32 + 0x80))();
                for (; plVar33 = (long *)(**(code **)(*plVar32 + 0x88))(plVar32), plVar23 != plVar33
                    ; plVar23 = plVar23 + 3) {
                  uVar16 = (**(code **)(*plVar23 + 0x40))(plVar23);
                  puVar9 = local_14f0;
                  puVar8 = local_14f8;
                  if (local_14f0 < local_14e8) {
                    puVar61 = local_14f0 + 1;
                    *local_14f0 = uVar16;
                  }
                  else {
                    lVar46 = (long)local_14f0 - (long)local_14f8;
                    lVar41 = lVar46 >> 2;
                    uVar57 = lVar41 + 1;
                    if (uVar57 >> 0x3e != 0) {
                      if (*(long *)(lVar5 + 0x28) != local_a8) goto LAB_002793d4;
                      FUN_001ef718(&local_14f8);
                      goto LAB_0027874c;
                    }
                    uVar44 = (long)local_14e8 - (long)local_14f8 >> 1;
                    if (uVar44 <= uVar57) {
                      uVar44 = uVar57;
                    }
                    if (0x7ffffffffffffffb < (ulong)((long)local_14e8 - (long)local_14f8)) {
                      uVar44 = 0x3fffffffffffffff;
                    }
                    if (uVar44 == 0) {
                      pvVar28 = (void *)0x0;
                      local_14f8 = (undefined4 *)(lVar41 * 4);
                      *local_14f8 = uVar16;
                    }
                    else {
                      if (uVar44 >> 0x3e != 0) goto LAB_002787f4;
                      pvVar28 = operator_new(uVar44 << 2);
                      local_14f8 = (undefined4 *)((long)pvVar28 + lVar41 * 4);
                      *local_14f8 = uVar16;
                    }
                    puVar61 = local_14f8 + 1;
                    if ((long)puVar9 - (long)puVar8 != 0) {
                      uVar57 = ((long)puVar9 - (long)puVar8) - 4;
                      puVar60 = puVar9;
                      if ((0x1b < uVar57) &&
                         (0x1f < (ulong)((long)puVar9 + (-lVar46 - (long)pvVar28)))) {
                        uVar57 = (uVar57 >> 2) + 1;
                        uVar49 = uVar57 & 0x7ffffffffffffff8;
                        puVar60 = puVar9 + -uVar49;
                        local_14f8 = local_14f8 + -uVar49;
                        puVar50 = (undefined8 *)((long)pvVar28 + lVar46 + -0x10);
                        puVar54 = (undefined8 *)(puVar9 + -4);
                        uVar45 = uVar49;
                        do {
                          puVar47 = puVar54 + -1;
                          uVar69 = puVar54[-2];
                          uVar68 = puVar54[1];
                          uVar67 = *puVar54;
                          uVar45 = uVar45 - 8;
                          puVar54 = puVar54 + -4;
                          puVar50[-1] = *puVar47;
                          puVar50[-2] = uVar69;
                          puVar50[1] = uVar68;
                          *puVar50 = uVar67;
                          puVar50 = puVar50 + -4;
                        } while (uVar45 != 0);
                        if (uVar57 == uVar49) goto LAB_00275d0c;
                      }
                      do {
                        puVar60 = puVar60 + -1;
                        local_14f8 = local_14f8 + -1;
                        *local_14f8 = *puVar60;
                      } while (puVar60 != puVar8);
                    }
LAB_00275d0c:
                    local_14e8 = (undefined4 *)((long)pvVar28 + uVar44 * 4);
                    if (puVar8 != (undefined4 *)0x0) {
                      local_14f0 = puVar61;
                      operator_delete(puVar8);
                    }
                  }
                  local_14f0 = puVar61;
                }
                bVar42 = *(byte *)(plVar21 + 4);
                uVar45 = plVar21[5];
                uVar44 = (ulong)(bVar42 >> 1);
                uVar57 = uVar44;
                if ((bVar42 & 1) != 0) {
                  uVar57 = uVar45;
                }
              }
              else {
LAB_00275a84:
                uVar57 = uVar44;
                if ((bVar42 & 1) != 0) {
                  uVar57 = uVar45;
                }
              }
              bVar42 = bVar42 & 1;
              if (uVar57 == 6) {
                piVar34 = (int *)((long)plVar21 + 0x21);
                if (bVar42 != 0) {
                  piVar34 = (int *)plVar21[6];
                }
                if (*piVar34 == 0x61505356 && (short)piVar34[1] == 0x6874) {
                  pcVar24 = (char *)MTPugiAny::GetString((MTPugiAny *)(plVar21 + 7));
                  uVar57 = local_14e0;
                  sVar26 = local_14e0 >> 1 & 0x7f;
                  if ((local_14e0 & 1) != 0) {
                    sVar26 = sStack_14d8;
                  }
                  sVar25 = strlen(pcVar24);
                  uVar44 = sVar26 + sVar25;
                  if (0xffffffffffffffef < uVar44) {
                    if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                      FUN_001c3100(&local_410);
                    }
                    goto LAB_002793d4;
                  }
                  if (uVar44 < 0x17) {
                    uStack_408 = 0;
                    local_400 = (int *)0x0;
                    local_410 = (ulong)(byte)(((uint)uVar44 & 0xff) << 1);
                    piVar34 = piVar56;
                  }
                  else {
                    uVar45 = (uVar44 | 0xf) + 1;
                    local_400 = operator_new(uVar45);
                    local_410 = uVar45 | 1;
                    uStack_408 = uVar44;
                    piVar34 = local_400;
                  }
                  if (sVar26 != 0) {
                    pvVar28 = pvVar39;
                    if ((uVar57 & 1) != 0) {
                      pvVar28 = local_14d0;
                    }
                    memmove(piVar34,pvVar28,sVar26);
                  }
                  if (sVar25 != 0) {
                    memmove((undefined1 *)((long)piVar34 + sVar26),pcVar24,sVar25);
                  }
                  ((undefined1 *)((long)piVar34 + sVar26))[sVar25] = 0;
                  if (((byte)this[0x28] & 1) != 0) {
                    operator_delete(*(void **)(this + 0x38));
                  }
                  *(ulong *)(this + 0x30) = uStack_408;
                  *(ulong *)(this + 0x28) = local_410;
                  *(int **)(this + 0x38) = local_400;
                  uVar45 = plVar21[5];
                  uVar44 = (ulong)(*(byte *)(plVar21 + 4) >> 1);
                  bVar42 = *(byte *)(plVar21 + 4) & 1;
                }
              }
              if (bVar42 != 0) {
                uVar44 = uVar45;
              }
              if (uVar44 == 6) {
                piVar34 = (int *)((long)plVar21 + 0x21);
                if (bVar42 != 0) {
                  piVar34 = (int *)plVar21[6];
                }
                if (*piVar34 == 0x61505346 && (short)piVar34[1] == 0x6874) {
                  pcVar24 = (char *)MTPugiAny::GetString((MTPugiAny *)(plVar21 + 7));
                  uVar57 = local_14e0;
                  sVar26 = local_14e0 >> 1 & 0x7f;
                  if ((local_14e0 & 1) != 0) {
                    sVar26 = sStack_14d8;
                  }
                  sVar25 = strlen(pcVar24);
                  uVar44 = sVar26 + sVar25;
                  if (0xffffffffffffffef < uVar44) goto LAB_002789ac;
                  if (uVar44 < 0x17) {
                    uStack_408 = 0;
                    local_400 = (int *)0x0;
                    local_410 = (ulong)(byte)(((uint)uVar44 & 0xff) << 1);
                    piVar34 = piVar56;
                  }
                  else {
                    uVar45 = (uVar44 | 0xf) + 1;
                    local_400 = operator_new(uVar45);
                    local_410 = uVar45 | 1;
                    uStack_408 = uVar44;
                    piVar34 = local_400;
                  }
                  if (sVar26 != 0) {
                    pvVar28 = pvVar39;
                    if ((uVar57 & 1) != 0) {
                      pvVar28 = local_14d0;
                    }
                    memmove(piVar34,pvVar28,sVar26);
                  }
                  if (sVar25 != 0) {
                    memmove((undefined1 *)((long)piVar34 + sVar26),pcVar24,sVar25);
                  }
                  ((undefined1 *)((long)piVar34 + sVar26))[sVar25] = 0;
                  if (((byte)*pDVar38 & 1) != 0) {
                    operator_delete(*(void **)(this + 0x20));
                  }
                  *(ulong *)(this + 0x18) = uStack_408;
                  *(ulong *)pDVar38 = local_410;
                  *(int **)(this + 0x20) = local_400;
                  DVar4 = this[0x10];
                  uVar57 = (ulong)((byte)DVar4 >> 1);
                  if (((byte)DVar4 & 1) != 0) {
                    uVar57 = *(ulong *)(this + 0x18);
                  }
                  if (uVar57 != 0) {
                    pDVar31 = this + 0x11;
                    if (((byte)DVar4 & 1) != 0) {
                      pDVar31 = *(DynamicFilterParam **)(this + 0x20);
                    }
                    pDVar1 = pDVar31 + uVar57;
                    iVar14 = (int)pDVar31;
                    pDVar29 = pDVar31;
                    uVar44 = uVar57;
                    if ((long)uVar57 < 4) {
                      *(undefined1 *)(param_1 + 0xa0) = 0;
                      pDVar30 = pDVar1;
LAB_00275fc4:
                      *(bool *)(param_1 + 0xa1) = pDVar30 != pDVar1 && -1 < (int)pDVar30 - iVar14;
                      while (((pDVar29 = pDVar1, 3 < (long)uVar57 &&
                              (pDVar31 = memchr(pDVar31,0x48,uVar57 - 3),
                              pDVar31 != (DynamicFilterParam *)0x0)) &&
                             (pDVar29 = pDVar31, *(int *)pDVar31 != 0x72696148))) {
                        pDVar31 = pDVar31 + 1;
                        uVar57 = (long)pDVar1 - (long)pDVar31;
                      }
                    }
                    else {
                      do {
                        pDVar29 = memchr(pDVar29,0x46,uVar44 - 3);
                        pDVar30 = pDVar1;
                        if ((pDVar29 == (DynamicFilterParam *)0x0) ||
                           (pDVar30 = pDVar29, *(int *)pDVar29 == 0x65636146)) break;
                        uVar44 = (long)pDVar1 - (long)(pDVar29 + 1);
                        pDVar29 = pDVar29 + 1;
                        pDVar30 = pDVar1;
                      } while (3 < (long)uVar44);
                      *(bool *)(param_1 + 0xa0) = pDVar30 != pDVar1 && -1 < (int)pDVar30 - iVar14;
                      pDVar29 = pDVar31;
                      uVar44 = uVar57;
                      if (3 < (long)uVar57) {
                        do {
                          pDVar29 = memchr(pDVar29,0x42,uVar44 - 3);
                          pDVar30 = pDVar1;
                          if ((pDVar29 == (DynamicFilterParam *)0x0) ||
                             (pDVar30 = pDVar29, *(int *)pDVar29 == 0x79646f42)) break;
                          uVar44 = (long)pDVar1 - (long)(pDVar29 + 1);
                          pDVar29 = pDVar29 + 1;
                          pDVar30 = pDVar1;
                        } while (3 < (long)uVar44);
                        goto LAB_00275fc4;
                      }
                      *(undefined1 *)(param_1 + 0xa1) = 0;
                      pDVar29 = pDVar1;
                    }
                    *(bool *)(param_1 + 0xa3) = pDVar29 != pDVar1 && -1 < (int)pDVar29 - iVar14;
                  }
                }
              }
              bVar42 = *(byte *)(plVar21 + 4);
              uVar45 = plVar21[5];
              uVar44 = (ulong)(bVar42 >> 1);
              uVar57 = uVar44;
              if ((bVar42 & 1) != 0) {
                uVar57 = uVar45;
              }
              if (uVar57 == 10) {
                plVar23 = (long *)((long)plVar21 + 0x21);
                if ((bVar42 & 1) != 0) {
                  plVar23 = (long *)plVar21[6];
                }
                if (*plVar23 != 0x706c61646e656c42 || (short)plVar23[1] != 0x6168)
                goto LAB_00276088;
                fVar65 = (float)MTPugiAny::GetFloat((MTPugiAny *)(plVar21 + 7));
                bVar42 = *(byte *)(plVar21 + 4);
                uVar45 = plVar21[5];
                uVar44 = (ulong)(bVar42 >> 1);
                uVar57 = uVar44;
                if ((bVar42 & 1) != 0) {
                  uVar57 = uVar45;
                }
              }
              else {
LAB_00276088:
                uVar57 = uVar44;
                if ((bVar42 & 1) != 0) {
                  uVar57 = uVar45;
                }
              }
              bVar42 = bVar42 & 1;
              if (uVar57 == 6) {
                piVar34 = (int *)((long)plVar21 + 0x21);
                if (bVar42 != 0) {
                  piVar34 = (int *)plVar21[6];
                }
                if (*piVar34 == 0x72676564 && (short)piVar34[1] == 0x6565) {
                  fVar66 = (float)MTPugiAny::GetFloat((MTPugiAny *)(plVar21 + 7));
                  uVar45 = plVar21[5];
                  uVar44 = (ulong)(*(byte *)(plVar21 + 4) >> 1);
                  bVar42 = *(byte *)(plVar21 + 4) & 1;
                }
              }
              if (bVar42 != 0) {
                uVar44 = uVar45;
              }
              if (uVar44 == 10) {
                plVar23 = (long *)((long)plVar21 + 0x21);
                if (bVar42 != 0) {
                  plVar23 = (long *)plVar21[6];
                }
                if ((*plVar23 == 0x797453646e656c42 && (short)plVar23[1] == 0x656c) &&
                   (iVar14 = MTPugiAny::GetInteger((MTPugiAny *)(plVar21 + 7)), 10 < iVar14)) {
                  *(undefined1 *)(param_1 + 0xa0) = 1;
                }
              }
              bVar3 = *(byte *)(plVar21 + 4);
              uVar45 = plVar21[5];
              uVar44 = (ulong)(bVar3 >> 1);
              bVar42 = bVar3 & 1;
              uVar57 = uVar44;
              if ((bVar3 & 1) != 0) {
                uVar57 = uVar45;
              }
              if (uVar57 == 0x15) {
                plVar23 = (long *)((long)plVar21 + 0x21);
                if ((bVar3 & 1) != 0) {
                  plVar23 = (long *)plVar21[6];
                }
                if ((*plVar23 != 0x656d69546c616552 || plVar23[1] != 0x65704f6563726f46) ||
                    *(long *)((long)plVar23 + 0xd) != 0x72756c426e65704f) goto LAB_002761ec;
                local_171c = MTPugiAny::GetInteger((MTPugiAny *)(plVar21 + 7));
                bVar3 = *(byte *)(plVar21 + 4);
                uVar45 = plVar21[5];
                uVar44 = (ulong)(bVar3 >> 1);
                bVar42 = bVar3 & 1;
                uVar57 = uVar44;
                if ((bVar3 & 1) != 0) {
                  uVar57 = uVar45;
                }
                if (uVar57 == 8) goto LAB_002761fc;
LAB_002764ac:
                uVar57 = uVar44;
                if (bVar42 != 0) {
                  uVar57 = uVar45;
                }
                if (uVar57 != 0xc) goto LAB_00276770;
LAB_002764bc:
                plVar23 = (long *)((long)plVar21 + 0x21);
                if (bVar42 != 0) {
                  plVar23 = (long *)plVar21[6];
                }
                if (*plVar23 != 0x687461506b73614d || (int)plVar23[1] != 0x3936315f)
                goto LAB_00276770;
                plVar32 = (long *)MTPugiAny::GetArray((MTPugiAny *)(plVar21 + 7));
                for (plVar23 = (long *)(**(code **)(*plVar32 + 0x80))();
                    plVar33 = (long *)(**(code **)(*plVar32 + 0x88))(plVar32), plVar23 != plVar33;
                    plVar23 = plVar23 + 3) {
                  pcVar24 = (char *)(**(code **)(*plVar23 + 0x38))(plVar23);
                  sVar26 = strlen(pcVar24);
                  if (0xffffffffffffffef < sVar26) {
                    if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                      FUN_001c3100(&local_410);
                    }
                    goto LAB_002793d4;
                  }
                  if (sVar26 < 0x17) {
                    local_410 = CONCAT71(local_410._1_7_,(char)((int)sVar26 << 1));
                    piVar34 = piVar56;
                    if (sVar26 != 0) goto LAB_002765d0;
                    *(undefined1 *)piVar56 = 0;
                    if (local_1518 <= local_1520) goto LAB_002765f4;
LAB_00276584:
                    puVar58 = local_1520 + 3;
                    local_1520[2] = (ulong)local_400;
                    local_1520[1] = uStack_408;
                    *local_1520 = local_410;
                    local_400 = (int *)0x0;
                    uStack_408 = 0;
                    local_410 = 0;
                  }
                  else {
                    uVar57 = (sVar26 | 0xf) + 1;
                    piVar34 = operator_new(uVar57);
                    local_410 = uVar57 | 1;
                    uStack_408 = sVar26;
                    local_400 = piVar34;
LAB_002765d0:
                    memmove(piVar34,pcVar24,sVar26);
                    *(undefined1 *)((long)piVar34 + sVar26) = 0;
                    if (local_1520 < local_1518) goto LAB_00276584;
LAB_002765f4:
                    puVar53 = local_1520;
                    puVar17 = local_1528;
                    lVar46 = (long)local_1520 - (long)local_1528 >> 3;
                    uVar57 = lVar46 * -0x5555555555555555 + 1;
                    if (0xaaaaaaaaaaaaaaa < uVar57) goto LAB_00278768;
                    lVar41 = (long)local_1518 - (long)local_1528 >> 3;
                    uVar44 = lVar41 * 0x5555555555555556;
                    if (uVar44 < uVar57 || uVar44 - uVar57 == 0) {
                      uVar44 = uVar57;
                    }
                    if (0x555555555555554 < (ulong)(lVar41 * -0x5555555555555555)) {
                      uVar44 = 0xaaaaaaaaaaaaaaa;
                    }
                    if (uVar44 == 0) {
                      pvVar28 = (void *)0x0;
                    }
                    else {
                      if (0xaaaaaaaaaaaaaaa < uVar44) {
                        if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                          FUN_001c8a94();
                        }
                        goto LAB_002793d4;
                      }
                      pvVar28 = operator_new(uVar44 * 0x18);
                    }
                    piVar34 = local_400;
                    uVar45 = uStack_408;
                    uVar57 = local_410;
                    puVar7 = local_1528;
                    local_1528 = (ulong *)((long)pvVar28 + lVar46 * 8);
                    local_400 = (int *)0x0;
                    local_410 = 0;
                    local_1518 = (ulong *)((long)pvVar28 + uVar44 * 0x18);
                    uStack_408 = 0;
                    puVar58 = local_1528 + 3;
                    local_1528[1] = uVar45;
                    *local_1528 = uVar57;
                    local_1528[2] = (ulong)piVar34;
                    puVar10 = puVar58;
                    if (puVar53 != puVar17) {
                      do {
                        uVar44 = puVar53[-2];
                        uVar57 = puVar53[-3];
                        local_1528[-1] = puVar53[-1];
                        puVar48 = puVar53 + -3;
                        local_1528[-2] = uVar44;
                        local_1528[-3] = uVar57;
                        local_1528 = local_1528 + -3;
                        puVar53[-2] = 0;
                        puVar53[-1] = 0;
                        puVar53[-3] = 0;
                        puVar53 = puVar48;
                        puVar59 = local_1520;
                      } while (puVar48 != puVar17);
                      while (puVar17 = puVar59, local_1520 = puVar10, puVar53 = puVar7,
                            puVar10 = local_1520, puVar17 != puVar7) {
                        puVar59 = puVar17 + -3;
                        if ((*puVar59 & 1) != 0) {
                          operator_delete((void *)puVar17[-1]);
                          puVar10 = local_1520;
                        }
                      }
                    }
                    local_1520 = puVar10;
                    if (puVar53 != (ulong *)0x0) {
                      operator_delete(puVar53);
                    }
                  }
                  local_1520 = puVar58;
                  if ((local_410 & 1) != 0) {
                    operator_delete(local_400);
                  }
                }
                bVar3 = *(byte *)(plVar21 + 4);
                uVar45 = plVar21[5];
                uVar44 = (ulong)(bVar3 >> 1);
                bVar42 = bVar3 & 1;
                uVar57 = uVar44;
                if ((bVar3 & 1) != 0) {
                  uVar57 = uVar45;
                }
                if (uVar57 == 0xb) goto LAB_00276780;
LAB_00276a3c:
                uVar57 = uVar44;
                if (bVar42 != 0) {
                  uVar57 = uVar45;
                }
                if (uVar57 != 10) goto LAB_00276cf0;
LAB_00276a4c:
                plVar23 = (long *)((long)plVar21 + 0x21);
                if (bVar42 != 0) {
                  plVar23 = (long *)plVar21[6];
                }
                if (*plVar23 != 0x687461506b73614d || (short)plVar23[1] != 0x485f)
                goto LAB_00276cf0;
                plVar32 = (long *)MTPugiAny::GetArray((MTPugiAny *)(plVar21 + 7));
                for (plVar23 = (long *)(**(code **)(*plVar32 + 0x80))();
                    plVar33 = (long *)(**(code **)(*plVar32 + 0x88))(plVar32), plVar23 != plVar33;
                    plVar23 = plVar23 + 3) {
                  pcVar24 = (char *)(**(code **)(*plVar23 + 0x38))(plVar23);
                  sVar26 = strlen(pcVar24);
                  if (0xffffffffffffffef < sVar26) {
                    if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                      FUN_001c3100(&local_410);
                    }
                    goto LAB_002793d4;
                  }
                  if (sVar26 < 0x17) {
                    local_410 = CONCAT71(local_410._1_7_,(char)((int)sVar26 << 1));
                    piVar34 = piVar56;
                    if (sVar26 != 0) goto LAB_00276b5c;
                    *(undefined1 *)piVar56 = 0;
                    if (local_1548 <= local_1550) goto LAB_00276b80;
LAB_00276b10:
                    puVar58 = local_1550 + 3;
                    local_1550[2] = (ulong)local_400;
                    local_1550[1] = uStack_408;
                    *local_1550 = local_410;
                    local_400 = (int *)0x0;
                    uStack_408 = 0;
                    local_410 = 0;
                  }
                  else {
                    uVar57 = (sVar26 | 0xf) + 1;
                    piVar34 = operator_new(uVar57);
                    local_410 = uVar57 | 1;
                    uStack_408 = sVar26;
                    local_400 = piVar34;
LAB_00276b5c:
                    memmove(piVar34,pcVar24,sVar26);
                    *(undefined1 *)((long)piVar34 + sVar26) = 0;
                    if (local_1550 < local_1548) goto LAB_00276b10;
LAB_00276b80:
                    puVar53 = local_1550;
                    puVar17 = local_1558;
                    lVar46 = (long)local_1550 - (long)local_1558 >> 3;
                    uVar57 = lVar46 * -0x5555555555555555 + 1;
                    if (0xaaaaaaaaaaaaaaa < uVar57) goto LAB_002787a0;
                    lVar41 = (long)local_1548 - (long)local_1558 >> 3;
                    uVar44 = lVar41 * 0x5555555555555556;
                    if (uVar44 < uVar57 || uVar44 - uVar57 == 0) {
                      uVar44 = uVar57;
                    }
                    if (0x555555555555554 < (ulong)(lVar41 * -0x5555555555555555)) {
                      uVar44 = 0xaaaaaaaaaaaaaaa;
                    }
                    if (uVar44 == 0) {
                      pvVar28 = (void *)0x0;
                    }
                    else {
                      if (0xaaaaaaaaaaaaaaa < uVar44) {
                        if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                          FUN_001c8a94();
                        }
                        goto LAB_002793d4;
                      }
                      pvVar28 = operator_new(uVar44 * 0x18);
                    }
                    piVar34 = local_400;
                    uVar45 = uStack_408;
                    uVar57 = local_410;
                    puVar7 = local_1558;
                    local_1558 = (ulong *)((long)pvVar28 + lVar46 * 8);
                    local_400 = (int *)0x0;
                    local_410 = 0;
                    local_1548 = (ulong *)((long)pvVar28 + uVar44 * 0x18);
                    uStack_408 = 0;
                    puVar58 = local_1558 + 3;
                    local_1558[1] = uVar45;
                    *local_1558 = uVar57;
                    local_1558[2] = (ulong)piVar34;
                    puVar10 = puVar58;
                    if (puVar53 != puVar17) {
                      do {
                        uVar44 = puVar53[-2];
                        uVar57 = puVar53[-3];
                        local_1558[-1] = puVar53[-1];
                        puVar48 = puVar53 + -3;
                        local_1558[-2] = uVar44;
                        local_1558[-3] = uVar57;
                        local_1558 = local_1558 + -3;
                        puVar53[-2] = 0;
                        puVar53[-1] = 0;
                        puVar53[-3] = 0;
                        puVar53 = puVar48;
                        puVar59 = local_1550;
                      } while (puVar48 != puVar17);
                      while (puVar17 = puVar59, local_1550 = puVar10, puVar53 = puVar7,
                            puVar10 = local_1550, puVar17 != puVar7) {
                        puVar59 = puVar17 + -3;
                        if ((*puVar59 & 1) != 0) {
                          operator_delete((void *)puVar17[-1]);
                          puVar10 = local_1550;
                        }
                      }
                    }
                    local_1550 = puVar10;
                    if (puVar53 != (ulong *)0x0) {
                      operator_delete(puVar53);
                    }
                  }
                  local_1550 = puVar58;
                  if ((local_410 & 1) != 0) {
                    operator_delete(local_400);
                  }
                }
                bVar3 = *(byte *)(plVar21 + 4);
                uVar45 = plVar21[5];
                uVar44 = (ulong)(bVar3 >> 1);
                bVar42 = bVar3 & 1;
                uVar57 = uVar44;
                if ((bVar3 & 1) != 0) {
                  uVar57 = uVar45;
                }
                if (uVar57 == 0xe) goto LAB_00276d00;
LAB_00276fa8:
                if (bVar42 != 0) {
                  uVar44 = uVar45;
                }
              }
              else {
LAB_002761ec:
                uVar57 = uVar44;
                if ((bVar3 & 1) != 0) {
                  uVar57 = uVar45;
                }
                if (uVar57 != 8) goto LAB_002764ac;
LAB_002761fc:
                plVar23 = (long *)((long)plVar21 + 0x21);
                if (bVar42 != 0) {
                  plVar23 = (long *)plVar21[6];
                }
                if (*plVar23 != 0x687461506b73614d) goto LAB_002764ac;
                plVar32 = (long *)MTPugiAny::GetArray((MTPugiAny *)(plVar21 + 7));
                for (plVar23 = (long *)(**(code **)(*plVar32 + 0x80))();
                    plVar33 = (long *)(**(code **)(*plVar32 + 0x88))(plVar32), plVar23 != plVar33;
                    plVar23 = plVar23 + 3) {
                  pcVar24 = (char *)(**(code **)(*plVar23 + 0x38))(plVar23);
                  sVar26 = strlen(pcVar24);
                  if (0xffffffffffffffef < sVar26) {
                    if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                      FUN_001c3100(&local_410);
                    }
                    goto LAB_002793d4;
                  }
                  if (sVar26 < 0x17) {
                    local_410 = CONCAT71(local_410._1_7_,(char)((int)sVar26 << 1));
                    piVar34 = piVar56;
                    if (sVar26 != 0) goto LAB_00276300;
                    *(undefined1 *)piVar56 = 0;
                    if (local_1500 <= local_1508) goto LAB_00276324;
LAB_002762b4:
                    puVar58 = local_1508 + 3;
                    local_1508[2] = (ulong)local_400;
                    local_1508[1] = uStack_408;
                    *local_1508 = local_410;
                    local_400 = (int *)0x0;
                    uStack_408 = 0;
                    local_410 = 0;
                  }
                  else {
                    uVar57 = (sVar26 | 0xf) + 1;
                    piVar34 = operator_new(uVar57);
                    local_410 = uVar57 | 1;
                    uStack_408 = sVar26;
                    local_400 = piVar34;
LAB_00276300:
                    memmove(piVar34,pcVar24,sVar26);
                    *(undefined1 *)((long)piVar34 + sVar26) = 0;
                    if (local_1508 < local_1500) goto LAB_002762b4;
LAB_00276324:
                    puVar53 = local_1508;
                    puVar17 = local_1510;
                    lVar46 = (long)local_1508 - (long)local_1510 >> 3;
                    uVar57 = lVar46 * -0x5555555555555555 + 1;
                    if (0xaaaaaaaaaaaaaaa < uVar57) goto LAB_0027874c;
                    lVar41 = (long)local_1500 - (long)local_1510 >> 3;
                    uVar44 = lVar41 * 0x5555555555555556;
                    if (uVar44 < uVar57 || uVar44 - uVar57 == 0) {
                      uVar44 = uVar57;
                    }
                    if (0x555555555555554 < (ulong)(lVar41 * -0x5555555555555555)) {
                      uVar44 = 0xaaaaaaaaaaaaaaa;
                    }
                    if (uVar44 == 0) {
                      pvVar28 = (void *)0x0;
                    }
                    else {
                      if (0xaaaaaaaaaaaaaaa < uVar44) {
                        if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                          FUN_001c8a94();
                        }
                        goto LAB_002793d4;
                      }
                      pvVar28 = operator_new(uVar44 * 0x18);
                    }
                    piVar34 = local_400;
                    uVar45 = uStack_408;
                    uVar57 = local_410;
                    puVar7 = local_1510;
                    local_1510 = (ulong *)((long)pvVar28 + lVar46 * 8);
                    local_400 = (int *)0x0;
                    local_410 = 0;
                    local_1500 = (ulong *)((long)pvVar28 + uVar44 * 0x18);
                    uStack_408 = 0;
                    puVar58 = local_1510 + 3;
                    local_1510[1] = uVar45;
                    *local_1510 = uVar57;
                    local_1510[2] = (ulong)piVar34;
                    puVar10 = puVar58;
                    if (puVar53 != puVar17) {
                      do {
                        uVar44 = puVar53[-2];
                        uVar57 = puVar53[-3];
                        local_1510[-1] = puVar53[-1];
                        puVar48 = puVar53 + -3;
                        local_1510[-2] = uVar44;
                        local_1510[-3] = uVar57;
                        local_1510 = local_1510 + -3;
                        puVar53[-2] = 0;
                        puVar53[-1] = 0;
                        puVar53[-3] = 0;
                        puVar53 = puVar48;
                        puVar59 = local_1508;
                      } while (puVar48 != puVar17);
                      while (puVar17 = puVar59, local_1508 = puVar10, puVar53 = puVar7,
                            puVar10 = local_1508, puVar17 != puVar7) {
                        puVar59 = puVar17 + -3;
                        if ((*puVar59 & 1) != 0) {
                          operator_delete((void *)puVar17[-1]);
                          puVar10 = local_1508;
                        }
                      }
                    }
                    local_1508 = puVar10;
                    if (puVar53 != (ulong *)0x0) {
                      operator_delete(puVar53);
                    }
                  }
                  local_1508 = puVar58;
                  if ((local_410 & 1) != 0) {
                    operator_delete(local_400);
                  }
                }
                bVar3 = *(byte *)(plVar21 + 4);
                uVar45 = plVar21[5];
                uVar44 = (ulong)(bVar3 >> 1);
                bVar42 = bVar3 & 1;
                uVar57 = uVar44;
                if ((bVar3 & 1) != 0) {
                  uVar57 = uVar45;
                }
                if (uVar57 == 0xc) goto LAB_002764bc;
LAB_00276770:
                uVar57 = uVar44;
                if (bVar42 != 0) {
                  uVar57 = uVar45;
                }
                if (uVar57 != 0xb) goto LAB_00276a3c;
LAB_00276780:
                plVar23 = (long *)((long)plVar21 + 0x21);
                if (bVar42 != 0) {
                  plVar23 = (long *)plVar21[6];
                }
                if (*plVar23 != 0x687461506b73614d ||
                    *(long *)((long)plVar23 + 3) != 0x31315f687461506b) goto LAB_00276a3c;
                plVar32 = (long *)MTPugiAny::GetArray((MTPugiAny *)(plVar21 + 7));
                for (plVar23 = (long *)(**(code **)(*plVar32 + 0x80))();
                    plVar33 = (long *)(**(code **)(*plVar32 + 0x88))(plVar32), plVar23 != plVar33;
                    plVar23 = plVar23 + 3) {
                  pcVar24 = (char *)(**(code **)(*plVar23 + 0x38))(plVar23);
                  sVar26 = strlen(pcVar24);
                  if (0xffffffffffffffef < sVar26) {
                    if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                      FUN_001c3100(&local_410);
                    }
                    goto LAB_002793d4;
                  }
                  if (sVar26 < 0x17) {
                    local_410 = CONCAT71(local_410._1_7_,(char)((int)sVar26 << 1));
                    piVar34 = piVar56;
                    if (sVar26 != 0) goto LAB_0027689c;
                    *(undefined1 *)piVar56 = 0;
                    if (local_1530 <= local_1538) goto LAB_002768c0;
LAB_00276850:
                    puVar58 = local_1538 + 3;
                    local_1538[2] = (ulong)local_400;
                    local_1538[1] = uStack_408;
                    *local_1538 = local_410;
                    local_400 = (int *)0x0;
                    uStack_408 = 0;
                    local_410 = 0;
                  }
                  else {
                    uVar57 = (sVar26 | 0xf) + 1;
                    piVar34 = operator_new(uVar57);
                    local_410 = uVar57 | 1;
                    uStack_408 = sVar26;
                    local_400 = piVar34;
LAB_0027689c:
                    memmove(piVar34,pcVar24,sVar26);
                    *(undefined1 *)((long)piVar34 + sVar26) = 0;
                    if (local_1538 < local_1530) goto LAB_00276850;
LAB_002768c0:
                    puVar53 = local_1538;
                    puVar17 = local_1540;
                    lVar46 = (long)local_1538 - (long)local_1540 >> 3;
                    uVar57 = lVar46 * -0x5555555555555555 + 1;
                    if (0xaaaaaaaaaaaaaaa < uVar57) goto LAB_00278784;
                    lVar41 = (long)local_1530 - (long)local_1540 >> 3;
                    uVar44 = lVar41 * 0x5555555555555556;
                    if (uVar44 < uVar57 || uVar44 - uVar57 == 0) {
                      uVar44 = uVar57;
                    }
                    if (0x555555555555554 < (ulong)(lVar41 * -0x5555555555555555)) {
                      uVar44 = 0xaaaaaaaaaaaaaaa;
                    }
                    if (uVar44 == 0) {
                      pvVar28 = (void *)0x0;
                    }
                    else {
                      if (0xaaaaaaaaaaaaaaa < uVar44) {
                        if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                          FUN_001c8a94();
                        }
                        goto LAB_002793d4;
                      }
                      pvVar28 = operator_new(uVar44 * 0x18);
                    }
                    piVar34 = local_400;
                    uVar45 = uStack_408;
                    uVar57 = local_410;
                    puVar7 = local_1540;
                    local_1540 = (ulong *)((long)pvVar28 + lVar46 * 8);
                    local_400 = (int *)0x0;
                    local_410 = 0;
                    local_1530 = (ulong *)((long)pvVar28 + uVar44 * 0x18);
                    uStack_408 = 0;
                    puVar58 = local_1540 + 3;
                    local_1540[1] = uVar45;
                    *local_1540 = uVar57;
                    local_1540[2] = (ulong)piVar34;
                    puVar10 = puVar58;
                    if (puVar53 != puVar17) {
                      do {
                        uVar44 = puVar53[-2];
                        uVar57 = puVar53[-3];
                        local_1540[-1] = puVar53[-1];
                        puVar48 = puVar53 + -3;
                        local_1540[-2] = uVar44;
                        local_1540[-3] = uVar57;
                        local_1540 = local_1540 + -3;
                        puVar53[-2] = 0;
                        puVar53[-1] = 0;
                        puVar53[-3] = 0;
                        puVar53 = puVar48;
                        puVar59 = local_1538;
                      } while (puVar48 != puVar17);
                      while (puVar17 = puVar59, local_1538 = puVar10, puVar53 = puVar7,
                            puVar10 = local_1538, puVar17 != puVar7) {
                        puVar59 = puVar17 + -3;
                        if ((*puVar59 & 1) != 0) {
                          operator_delete((void *)puVar17[-1]);
                          puVar10 = local_1538;
                        }
                      }
                    }
                    local_1538 = puVar10;
                    if (puVar53 != (ulong *)0x0) {
                      operator_delete(puVar53);
                    }
                  }
                  local_1538 = puVar58;
                  if ((local_410 & 1) != 0) {
                    operator_delete(local_400);
                  }
                }
                bVar3 = *(byte *)(plVar21 + 4);
                uVar45 = plVar21[5];
                uVar44 = (ulong)(bVar3 >> 1);
                bVar42 = bVar3 & 1;
                uVar57 = uVar44;
                if ((bVar3 & 1) != 0) {
                  uVar57 = uVar45;
                }
                if (uVar57 == 10) goto LAB_00276a4c;
LAB_00276cf0:
                uVar57 = uVar44;
                if (bVar42 != 0) {
                  uVar57 = uVar45;
                }
                if (uVar57 != 0xe) goto LAB_00276fa8;
LAB_00276d00:
                plVar23 = (long *)((long)plVar21 + 0x21);
                if (bVar42 != 0) {
                  plVar23 = (long *)plVar21[6];
                }
                if (*plVar23 != 0x687461506b73614d ||
                    *(long *)((long)plVar23 + 6) != 0x485f3936315f6874) goto LAB_00276fa8;
                plVar32 = (long *)MTPugiAny::GetArray((MTPugiAny *)(plVar21 + 7));
                for (plVar23 = (long *)(**(code **)(*plVar32 + 0x80))();
                    plVar33 = (long *)(**(code **)(*plVar32 + 0x88))(plVar32), plVar23 != plVar33;
                    plVar23 = plVar23 + 3) {
                  pcVar24 = (char *)(**(code **)(*plVar23 + 0x38))(plVar23);
                  sVar26 = strlen(pcVar24);
                  if (0xffffffffffffffef < sVar26) {
                    if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                      FUN_001c3100(&local_410);
                    }
                    goto LAB_002793d4;
                  }
                  if (sVar26 < 0x17) {
                    local_410 = CONCAT71(local_410._1_7_,(char)((int)sVar26 << 1));
                    piVar34 = piVar56;
                    if (sVar26 != 0) goto LAB_00276e18;
                    *(undefined1 *)piVar56 = 0;
                    if (local_1560 <= local_1568) goto LAB_00276e38;
LAB_00276dcc:
                    puVar58 = local_1568 + 3;
                    local_1568[2] = (ulong)local_400;
                    local_1568[1] = uStack_408;
                    *local_1568 = local_410;
                    local_400 = (int *)0x0;
                    uStack_408 = 0;
                    local_410 = 0;
                  }
                  else {
                    uVar57 = (sVar26 | 0xf) + 1;
                    piVar34 = operator_new(uVar57);
                    local_410 = uVar57 | 1;
                    uStack_408 = sVar26;
                    local_400 = piVar34;
LAB_00276e18:
                    memmove(piVar34,pcVar24,sVar26);
                    *(undefined1 *)((long)piVar34 + sVar26) = 0;
                    if (local_1568 < local_1560) goto LAB_00276dcc;
LAB_00276e38:
                    puVar53 = local_1568;
                    puVar17 = local_1570;
                    lVar46 = (long)local_1568 - (long)local_1570 >> 3;
                    uVar57 = lVar46 * -0x5555555555555555 + 1;
                    if (0xaaaaaaaaaaaaaaa < uVar57) goto LAB_002787bc;
                    lVar41 = (long)local_1560 - (long)local_1570 >> 3;
                    uVar44 = lVar41 * 0x5555555555555556;
                    if (uVar44 < uVar57 || uVar44 - uVar57 == 0) {
                      uVar44 = uVar57;
                    }
                    if (0x555555555555554 < (ulong)(lVar41 * -0x5555555555555555)) {
                      uVar44 = 0xaaaaaaaaaaaaaaa;
                    }
                    if (uVar44 == 0) {
                      pvVar28 = (void *)0x0;
                    }
                    else {
                      if (0xaaaaaaaaaaaaaaa < uVar44) {
                        if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                          FUN_001c8a94();
                        }
                        goto LAB_002793d4;
                      }
                      pvVar28 = operator_new(uVar44 * 0x18);
                    }
                    piVar34 = local_400;
                    uVar45 = uStack_408;
                    uVar57 = local_410;
                    puVar7 = local_1570;
                    local_1570 = (ulong *)((long)pvVar28 + lVar46 * 8);
                    local_400 = (int *)0x0;
                    local_410 = 0;
                    local_1560 = (ulong *)((long)pvVar28 + uVar44 * 0x18);
                    uStack_408 = 0;
                    puVar58 = local_1570 + 3;
                    local_1570[1] = uVar45;
                    *local_1570 = uVar57;
                    local_1570[2] = (ulong)piVar34;
                    puVar10 = puVar58;
                    if (puVar53 != puVar17) {
                      do {
                        uVar44 = puVar53[-2];
                        uVar57 = puVar53[-3];
                        local_1570[-1] = puVar53[-1];
                        puVar48 = puVar53 + -3;
                        local_1570[-2] = uVar44;
                        local_1570[-3] = uVar57;
                        local_1570 = local_1570 + -3;
                        puVar53[-2] = 0;
                        puVar53[-1] = 0;
                        puVar53[-3] = 0;
                        puVar53 = puVar48;
                        puVar59 = local_1568;
                      } while (puVar48 != puVar17);
                      while (puVar17 = puVar59, local_1568 = puVar10, puVar53 = puVar7,
                            puVar10 = local_1568, puVar17 != puVar7) {
                        puVar59 = puVar17 + -3;
                        if ((*puVar59 & 1) != 0) {
                          operator_delete((void *)puVar17[-1]);
                          puVar10 = local_1568;
                        }
                      }
                    }
                    local_1568 = puVar10;
                    if (puVar53 != (ulong *)0x0) {
                      operator_delete(puVar53);
                    }
                  }
                  local_1568 = puVar58;
                  if ((local_410 & 1) != 0) {
                    operator_delete(local_400);
                  }
                }
                bVar3 = *(byte *)(plVar21 + 4);
                bVar42 = bVar3 & 1;
                uVar44 = (ulong)(bVar3 >> 1);
                if ((bVar3 & 1) != 0) {
                  uVar44 = plVar21[5];
                }
              }
              if (uVar44 == 0xd) {
                plVar23 = (long *)((long)plVar21 + 0x21);
                if (bVar42 != 0) {
                  plVar23 = (long *)plVar21[6];
                }
                if (*plVar23 == 0x687461506b73614d &&
                    *(long *)((long)plVar23 + 5) == 0x485f31315f687461) {
                  plVar32 = (long *)MTPugiAny::GetArray((MTPugiAny *)(plVar21 + 7));
                  for (plVar23 = (long *)(**(code **)(*plVar32 + 0x80))();
                      plVar33 = (long *)(**(code **)(*plVar32 + 0x88))(plVar32), plVar23 != plVar33;
                      plVar23 = plVar23 + 3) {
                    pcVar24 = (char *)(**(code **)(*plVar23 + 0x38))(plVar23);
                    sVar26 = strlen(pcVar24);
                    if (0xffffffffffffffef < sVar26) {
                      if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                        FUN_001c3100(&local_410);
                      }
                      goto LAB_002793d4;
                    }
                    if (sVar26 < 0x17) {
                      local_410 = CONCAT71(local_410._1_7_,(char)((int)sVar26 << 1));
                      piVar34 = piVar56;
                      if (sVar26 != 0) goto LAB_002770d0;
                      *(undefined1 *)piVar56 = 0;
                      if (local_1578 <= local_1580) goto LAB_002770f0;
LAB_00277084:
                      puVar58 = local_1580 + 3;
                      local_1580[2] = (ulong)local_400;
                      local_1580[1] = uStack_408;
                      *local_1580 = local_410;
                      local_400 = (int *)0x0;
                      uStack_408 = 0;
                      local_410 = 0;
                    }
                    else {
                      uVar57 = (sVar26 | 0xf) + 1;
                      piVar34 = operator_new(uVar57);
                      local_410 = uVar57 | 1;
                      uStack_408 = sVar26;
                      local_400 = piVar34;
LAB_002770d0:
                      memmove(piVar34,pcVar24,sVar26);
                      *(undefined1 *)((long)piVar34 + sVar26) = 0;
                      if (local_1580 < local_1578) goto LAB_00277084;
LAB_002770f0:
                      puVar53 = local_1580;
                      puVar17 = local_1588;
                      lVar46 = (long)local_1580 - (long)local_1588 >> 3;
                      uVar57 = lVar46 * -0x5555555555555555 + 1;
                      if (0xaaaaaaaaaaaaaaa < uVar57) goto LAB_002787d8;
                      lVar41 = (long)local_1578 - (long)local_1588 >> 3;
                      uVar44 = lVar41 * 0x5555555555555556;
                      if (uVar44 < uVar57 || uVar44 - uVar57 == 0) {
                        uVar44 = uVar57;
                      }
                      if (0x555555555555554 < (ulong)(lVar41 * -0x5555555555555555)) {
                        uVar44 = 0xaaaaaaaaaaaaaaa;
                      }
                      if (uVar44 == 0) {
                        pvVar28 = (void *)0x0;
                      }
                      else {
                        if (0xaaaaaaaaaaaaaaa < uVar44) {
                          if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                            FUN_001c8a94();
                          }
                          goto LAB_002793d4;
                        }
                        pvVar28 = operator_new(uVar44 * 0x18);
                      }
                      piVar34 = local_400;
                      uVar45 = uStack_408;
                      uVar57 = local_410;
                      puVar7 = local_1588;
                      local_1588 = (ulong *)((long)pvVar28 + lVar46 * 8);
                      local_400 = (int *)0x0;
                      local_410 = 0;
                      local_1578 = (ulong *)((long)pvVar28 + uVar44 * 0x18);
                      uStack_408 = 0;
                      puVar58 = local_1588 + 3;
                      local_1588[1] = uVar45;
                      *local_1588 = uVar57;
                      local_1588[2] = (ulong)piVar34;
                      puVar10 = puVar58;
                      if (puVar53 != puVar17) {
                        do {
                          uVar44 = puVar53[-2];
                          uVar57 = puVar53[-3];
                          local_1588[-1] = puVar53[-1];
                          puVar48 = puVar53 + -3;
                          local_1588[-2] = uVar44;
                          local_1588[-3] = uVar57;
                          local_1588 = local_1588 + -3;
                          puVar53[-2] = 0;
                          puVar53[-1] = 0;
                          puVar53[-3] = 0;
                          puVar53 = puVar48;
                          puVar59 = local_1580;
                        } while (puVar48 != puVar17);
                        while (puVar17 = puVar59, local_1580 = puVar10, puVar53 = puVar7,
                              puVar10 = local_1580, puVar17 != puVar7) {
                          puVar59 = puVar17 + -3;
                          if ((*puVar59 & 1) != 0) {
                            operator_delete((void *)puVar17[-1]);
                            puVar10 = local_1580;
                          }
                        }
                      }
                      local_1580 = puVar10;
                      if (puVar53 != (ulong *)0x0) {
                        operator_delete(puVar53);
                      }
                    }
                    local_1580 = puVar58;
                    if ((local_410 & 1) != 0) {
                      operator_delete(local_400);
                    }
                  }
                }
              }
              plVar23 = (long *)plVar21[1];
              plVar32 = plVar21;
              if ((long *)plVar21[1] == (long *)0x0) {
                do {
                  plVar21 = (long *)plVar32[2];
                  bVar11 = (long *)*plVar21 != plVar32;
                  plVar32 = plVar21;
                } while (bVar11);
              }
              else {
                do {
                  plVar21 = plVar23;
                  plVar23 = (long *)*plVar21;
                } while ((long *)*plVar21 != (long *)0x0);
              }
            }
          }
        }
        bVar3 = *(byte *)(plVar18 + 4);
        bVar42 = bVar3 & 1;
        uVar57 = (ulong)(bVar3 >> 1);
        if ((bVar3 & 1) != 0) {
          uVar57 = plVar18[5];
        }
        if (uVar57 == 10) goto LAB_0027523c;
LAB_00277328:
        plVar19 = (long *)plVar18[1];
        if ((long *)plVar18[1] != (long *)0x0) goto LAB_00277330;
LAB_00277378:
        do {
          plVar19 = (long *)plVar18[2];
          bVar11 = (long *)*plVar19 != plVar18;
          plVar18 = plVar19;
        } while (bVar11);
      }
      else {
LAB_0027522c:
        if (bVar42 != 0) {
          uVar44 = uVar45;
        }
        if (uVar44 != 10) goto LAB_00277328;
LAB_0027523c:
        plVar19 = (long *)((long)plVar18 + 0x21);
        if (bVar42 != 0) {
          plVar19 = (long *)plVar18[6];
        }
        if (*plVar19 != 0x61507265746c6946 || (short)plVar19[1] != 0x7472) goto LAB_00277328;
        local_410 = local_410 & 0xffffffffffff0000;
        plVar19 = (long *)MTPugiAny::GetArray((MTPugiAny *)(plVar18 + 7));
        iVar14 = 0;
        for (iVar13 = 0; iVar15 = (**(code **)(*plVar19 + 0x90))(plVar19), iVar13 < iVar15;
            iVar13 = iVar13 + 1) {
          plVar20 = (long *)(**(code **)(*plVar19 + 0x68))(plVar19,iVar13);
          plVar21 = (long *)(**(code **)(*plVar20 + 0x80))();
          while (plVar23 = (long *)(**(code **)(*plVar20 + 0x88))(plVar20), plVar21 != plVar23) {
            bVar42 = *(byte *)(plVar21 + 4);
            uVar45 = plVar21[5];
            uVar44 = (ulong)(bVar42 >> 1);
            uVar57 = uVar44;
            if ((bVar42 & 1) != 0) {
              uVar57 = uVar45;
            }
            if (uVar57 == 4) {
              piVar34 = (int *)((long)plVar21 + 0x21);
              if ((bVar42 & 1) != 0) {
                piVar34 = (int *)plVar21[6];
              }
              if (*piVar34 != 0x65707954) goto LAB_0027533c;
              MTPugiAny::GetString((MTPugiAny *)(plVar21 + 7));
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::assign
                        ((char *)&local_410);
              bVar42 = *(byte *)(plVar21 + 4);
              uVar45 = plVar21[5];
              uVar44 = (ulong)(bVar42 >> 1);
              uVar57 = uVar44;
              if ((bVar42 & 1) != 0) {
                uVar57 = uVar45;
              }
            }
            else {
LAB_0027533c:
              uVar57 = uVar44;
              if ((bVar42 & 1) != 0) {
                uVar57 = uVar45;
              }
            }
            bVar42 = bVar42 & 1;
            if (uVar57 == 6) {
              piVar34 = (int *)((long)plVar21 + 0x21);
              if (bVar42 != 0) {
                piVar34 = (int *)plVar21[6];
              }
              if (*piVar34 == 0x61505356 && (short)piVar34[1] == 0x6874) {
                pcVar24 = (char *)MTPugiAny::GetString((MTPugiAny *)(plVar21 + 7));
                uVar57 = local_14e0;
                sVar26 = local_14e0 >> 1 & 0x7f;
                if ((local_14e0 & 1) != 0) {
                  sVar26 = sStack_14d8;
                }
                sVar25 = strlen(pcVar24);
                uVar44 = sVar26 + sVar25;
                if (0xffffffffffffffef < uVar44) {
                  if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                    FUN_001c3100(&local_638);
                  }
                  goto LAB_002793d4;
                }
                if (uVar44 < 0x17) {
                  uStack_630 = 0;
                  local_628 = (char *)0x0;
                  local_638 = (ulong)(byte)(((uint)uVar44 & 0xff) << 1);
                  pcVar27 = pcVar40;
                }
                else {
                  uVar45 = (uVar44 | 0xf) + 1;
                  local_628 = operator_new(uVar45);
                  local_638 = uVar45 | 1;
                  uStack_630 = uVar44;
                  pcVar27 = local_628;
                }
                if (sVar26 != 0) {
                  pvVar28 = pvVar39;
                  if ((uVar57 & 1) != 0) {
                    pvVar28 = local_14d0;
                  }
                  memmove(pcVar27,pvVar28,sVar26);
                }
                if (sVar25 != 0) {
                  memmove(pcVar27 + sVar26,pcVar24,sVar25);
                }
                (pcVar27 + sVar26)[sVar25] = '\0';
                if (((byte)this[0x28] & 1) != 0) {
                  operator_delete(*(void **)(this + 0x38));
                }
                *(ulong *)(this + 0x30) = uStack_630;
                *(ulong *)(this + 0x28) = local_638;
                *(char **)(this + 0x38) = local_628;
                uVar45 = plVar21[5];
                uVar44 = (ulong)(*(byte *)(plVar21 + 4) >> 1);
                bVar42 = *(byte *)(plVar21 + 4) & 1;
              }
            }
            uVar57 = uVar44;
            if (bVar42 != 0) {
              uVar57 = uVar45;
            }
            if (uVar57 == 6) {
              piVar34 = (int *)((long)plVar21 + 0x21);
              if (bVar42 != 0) {
                piVar34 = (int *)plVar21[6];
              }
              if (*piVar34 != 0x61505346 || (short)piVar34[1] != 0x6874) goto LAB_002754e0;
              pcVar24 = (char *)MTPugiAny::GetString((MTPugiAny *)(plVar21 + 7));
              uVar57 = local_14e0;
              sVar26 = local_14e0 >> 1 & 0x7f;
              if ((local_14e0 & 1) != 0) {
                sVar26 = sStack_14d8;
              }
              sVar25 = strlen(pcVar24);
              uVar44 = sVar26 + sVar25;
              if (0xffffffffffffffef < uVar44) {
                if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                  FUN_001c3100(&local_638);
                }
                goto LAB_002793d4;
              }
              if (uVar44 < 0x17) {
                uStack_630 = 0;
                local_628 = (char *)0x0;
                local_638 = (ulong)(byte)(((uint)uVar44 & 0xff) << 1);
                pcVar27 = pcVar40;
              }
              else {
                uVar45 = (uVar44 | 0xf) + 1;
                local_628 = operator_new(uVar45);
                local_638 = uVar45 | 1;
                uStack_630 = uVar44;
                pcVar27 = local_628;
              }
              if (sVar26 != 0) {
                pvVar28 = pvVar39;
                if ((uVar57 & 1) != 0) {
                  pvVar28 = local_14d0;
                }
                memmove(pcVar27,pvVar28,sVar26);
              }
              if (sVar25 != 0) {
                memmove(pcVar27 + sVar26,pcVar24,sVar25);
              }
              (pcVar27 + sVar26)[sVar25] = '\0';
              if (((byte)*pDVar38 & 1) != 0) {
                operator_delete(*(void **)(this + 0x20));
              }
              *(ulong *)(this + 0x18) = uStack_630;
              *(ulong *)pDVar38 = local_638;
              *(char **)(this + 0x20) = local_628;
              bVar3 = *(byte *)(plVar21 + 4);
              uVar45 = plVar21[5];
              uVar44 = (ulong)(bVar3 >> 1);
              bVar42 = bVar3 & 1;
              uVar57 = uVar44;
              if ((bVar3 & 1) != 0) {
                uVar57 = uVar45;
              }
            }
            else {
LAB_002754e0:
              uVar57 = uVar44;
              if (bVar42 != 0) {
                uVar57 = uVar45;
              }
            }
            if (uVar57 == 5) {
              piVar34 = (int *)((long)plVar21 + 0x21);
              if (bVar42 != 0) {
                piVar34 = (int *)plVar21[6];
              }
              if (*piVar34 == 0x68706c41 && (char)piVar34[1] == 'a') {
                fVar65 = (float)MTPugiAny::GetFloat((MTPugiAny *)(plVar21 + 7));
                uVar45 = plVar21[5];
                uVar44 = (ulong)(*(byte *)(plVar21 + 4) >> 1);
                bVar42 = *(byte *)(plVar21 + 4) & 1;
              }
            }
            uVar57 = uVar44;
            if (bVar42 != 0) {
              uVar57 = uVar45;
            }
            if (uVar57 == 7) {
              piVar34 = (int *)((long)plVar21 + 0x21);
              if (bVar42 != 0) {
                piVar34 = (int *)plVar21[6];
              }
              if (*piVar34 != 0x5074754c || *(int *)((long)piVar34 + 3) != 0x68746150)
              goto LAB_00275684;
              pcVar24 = (char *)MTPugiAny::GetString((MTPugiAny *)(plVar21 + 7));
              sVar26 = strlen(pcVar24);
              if (0xffffffffffffffef < sVar26) {
                if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                  FUN_001c3100(&local_638);
                }
                goto LAB_002793d4;
              }
              if (sVar26 < 0x17) {
                local_638 = CONCAT71(local_638._1_7_,(char)((int)sVar26 << 1));
                pcVar27 = pcVar40;
                if (sVar26 != 0) goto LAB_002757d8;
                *pcVar40 = '\0';
                if (local_1500 <= local_1508) goto LAB_002757fc;
LAB_00275718:
                puVar58 = local_1508 + 3;
                local_1508[2] = (ulong)local_628;
                local_1508[1] = uStack_630;
                *local_1508 = local_638;
                local_628 = (char *)0x0;
                uStack_630 = 0;
                local_638 = 0;
              }
              else {
                uVar57 = (sVar26 | 0xf) + 1;
                pcVar27 = operator_new(uVar57);
                local_638 = uVar57 | 1;
                uStack_630 = sVar26;
                local_628 = pcVar27;
LAB_002757d8:
                memmove(pcVar27,pcVar24,sVar26);
                pcVar27[sVar26] = '\0';
                if (local_1508 < local_1500) goto LAB_00275718;
LAB_002757fc:
                puVar53 = local_1508;
                puVar17 = local_1510;
                lVar46 = (long)local_1508 - (long)local_1510 >> 3;
                uVar57 = lVar46 * -0x5555555555555555 + 1;
                if (0xaaaaaaaaaaaaaaa < uVar57) goto LAB_00278990;
                lVar41 = (long)local_1500 - (long)local_1510 >> 3;
                uVar44 = lVar41 * 0x5555555555555556;
                if (uVar44 < uVar57 || uVar44 - uVar57 == 0) {
                  uVar44 = uVar57;
                }
                if (0x555555555555554 < (ulong)(lVar41 * -0x5555555555555555)) {
                  uVar44 = 0xaaaaaaaaaaaaaaa;
                }
                if (uVar44 == 0) {
                  pvVar28 = (void *)0x0;
                }
                else {
                  if (0xaaaaaaaaaaaaaaa < uVar44) {
                    if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                      FUN_001c8a94();
                    }
                    goto LAB_002793d4;
                  }
                  pvVar28 = operator_new(uVar44 * 0x18);
                }
                pcVar24 = local_628;
                uVar45 = uStack_630;
                uVar57 = local_638;
                puVar7 = local_1510;
                local_1510 = (ulong *)((long)pvVar28 + lVar46 * 8);
                local_628 = (char *)0x0;
                local_638 = 0;
                local_1500 = (ulong *)((long)pvVar28 + uVar44 * 0x18);
                uStack_630 = 0;
                puVar58 = local_1510 + 3;
                local_1510[1] = uVar45;
                *local_1510 = uVar57;
                local_1510[2] = (ulong)pcVar24;
                puVar10 = puVar58;
                if (puVar53 != puVar17) {
                  do {
                    uVar44 = puVar53[-2];
                    uVar57 = puVar53[-3];
                    local_1510[-1] = puVar53[-1];
                    puVar48 = puVar53 + -3;
                    local_1510[-2] = uVar44;
                    local_1510[-3] = uVar57;
                    local_1510 = local_1510 + -3;
                    puVar53[-2] = 0;
                    puVar53[-1] = 0;
                    puVar53[-3] = 0;
                    puVar53 = puVar48;
                    puVar59 = local_1508;
                  } while (puVar48 != puVar17);
                  while (puVar17 = puVar59, local_1508 = puVar10, puVar53 = puVar7,
                        puVar10 = local_1508, puVar17 != puVar7) {
                    puVar59 = puVar17 + -3;
                    if ((*puVar59 & 1) != 0) {
                      operator_delete((void *)puVar17[-1]);
                      puVar10 = local_1508;
                    }
                  }
                }
                local_1508 = puVar10;
                if (puVar53 != (ulong *)0x0) {
                  operator_delete(puVar53);
                }
              }
              local_1508 = puVar58;
              if ((local_638 & 1) != 0) {
                operator_delete(local_628);
              }
              bVar3 = *(byte *)(plVar21 + 4);
              bVar42 = bVar3 & 1;
              uVar44 = (ulong)(bVar3 >> 1);
              if ((bVar3 & 1) != 0) {
                uVar44 = plVar21[5];
              }
            }
            else {
LAB_00275684:
              if (bVar42 != 0) {
                uVar44 = uVar45;
              }
            }
            if (uVar44 == 4) {
              piVar34 = (int *)((long)plVar21 + 0x21);
              if (bVar42 != 0) {
                piVar34 = (int *)plVar21[6];
              }
              if (*piVar34 == 0x657a6953) {
                iVar14 = MTPugiAny::GetInteger((MTPugiAny *)(plVar21 + 7));
              }
            }
            plVar23 = (long *)plVar21[1];
            plVar32 = plVar21;
            if ((long *)plVar21[1] == (long *)0x0) {
              do {
                plVar21 = (long *)plVar32[2];
                bVar11 = (long *)*plVar21 != plVar32;
                plVar32 = plVar21;
              } while (bVar11);
            }
            else {
              do {
                plVar21 = plVar23;
                plVar23 = (long *)*plVar21;
              } while ((long *)*plVar21 != (long *)0x0);
            }
          }
        }
        uVar57 = local_410 >> 1 & 0x7f;
        if ((local_410 & 1) != 0) {
          uVar57 = uStack_408;
        }
        if (uVar57 == 4) {
          piVar34 = piVar56;
          if ((local_410 & 1) != 0) {
            piVar34 = local_400;
          }
          if ((*piVar34 == 0x7970614d) &&
             (((std::__ndk1::
                basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
                assign((char *)(this + 0x28)), iVar14 == 0x10 || (iVar14 == 0x40)) ||
              (iVar14 == 0x20)))) {
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::assign
                      ((char *)pDVar38);
          }
        }
        if ((local_410 & 1) != 0) {
          operator_delete(local_400);
        }
        plVar19 = (long *)plVar18[1];
        if ((long *)plVar18[1] == (long *)0x0) goto LAB_00277378;
LAB_00277330:
        do {
          plVar18 = plVar19;
          plVar19 = (long *)*plVar18;
        } while ((long *)*plVar18 != (long *)0x0);
      }
    }
    if (*(int *)this == 0) {
      DynamicFilterParam::~DynamicFilterParam(this);
      operator_delete(this);
      MTPugiDict::~MTPugiDict(aMStack_15e8);
    }
    else {
      *(undefined4 *)(this + 8) = 1;
      InputTexture::InputTexture((InputTexture *)local_13f8);
      local_13f8[0] = 0;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)local_13f0);
      pIVar37 = *(InputTexture **)(this + 0x48);
      local_1360 = 0;
      if (pIVar37 < *(InputTexture **)(this + 0x50)) {
        InputTexture::InputTexture(pIVar37,(InputTexture *)local_13f8);
        pIVar37 = pIVar37 + 0xb0;
        *(InputTexture **)(this + 0x48) = pIVar37;
      }
      else {
        pIVar37 = std::__ndk1::
                  vector<MTFilterKernel::InputTexture,std::__ndk1::allocator<MTFilterKernel::InputTexture>>
                  ::__push_back_slow_path<MTFilterKernel::InputTexture_const&>
                            ((vector<MTFilterKernel::InputTexture,std::__ndk1::allocator<MTFilterKernel::InputTexture>>
                              *)(this + 0x40),(InputTexture *)local_13f8);
      }
      *(InputTexture **)(this + 0x48) = pIVar37;
      uStack_408 = 0;
      local_410 = 0;
      local_400 = (int *)0x0;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_410);
      local_1f4 = 0x100000000;
      uStack_3ec = 0;
      local_3f4 = 0;
      uStack_3dc = 0;
      local_3e4 = 0;
      uStack_3cc = 0;
      local_3d4 = 0;
      uStack_3bc = 0;
      local_3c4 = 0;
      uStack_3ac = 0;
      local_3b4 = 0;
      uStack_39c = 0;
      local_3a4 = 0;
      uStack_38c = 0;
      local_394 = 0;
      uStack_37c = 0;
      local_384 = 0;
      local_3f8 = 1;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_410);
      local_15fe = 0;
      local_1600 = 0x3002;
      uVar16 = parseUniformValue(&local_3f4,&local_1600);
      local_1f4 = CONCAT44(local_1f4._4_4_,uVar16);
      if ((local_1600 & 1) != 0) {
        operator_delete(local_15f0);
      }
      pbVar35 = *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
                 (this + 0x60);
      if (pbVar35 < *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      **)(this + 0x68)) {
        if ((local_410 & 1) == 0) {
          *(int **)(pbVar35 + 0x10) = local_400;
          *(ulong *)(pbVar35 + 8) = uStack_408;
          *(ulong *)pbVar35 = local_410;
        }
        else {
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          __init_copy_ctor_external(pbVar35,(char *)local_400,uStack_408);
        }
        memcpy(pbVar35 + 0x18,&local_3f8,0x20c);
        pbVar35 = pbVar35 + 0x228;
        *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
         (this + 0x60) = pbVar35;
      }
      else {
        pbVar35 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  std::__ndk1::
                  vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                  ::__push_back_slow_path<MTFilterKernel::UniformValue_const&>
                            ((vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                              *)(this + 0x58),(UniformValue *)&local_410);
      }
      *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
       (this + 0x60) = pbVar35;
      uStack_630 = 0;
      local_638 = 0;
      local_628 = (char *)0x0;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_638);
      local_41c = 0x100000000;
      local_620 = 0x20;
      uStack_614 = 0;
      local_61c = 0;
      uStack_604 = 0;
      local_60c = 0;
      uStack_5f4 = 0;
      local_5fc = 0;
      uStack_5e4 = 0;
      local_5ec = 0;
      uStack_5d4 = 0;
      local_5dc = 0;
      uStack_5c4 = 0;
      local_5cc = 0;
      uStack_5b4 = 0;
      local_5bc = 0;
      uStack_5a4 = 0;
      local_5ac = 0;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_638);
      local_1618 = 0xe;
      local_1617 = 0x2c352e30;
      uStack_1613 = 0x352e30;
      local_1610 = 0;
      uVar16 = parseUniformValue(&local_61c,&local_1618);
      local_41c = CONCAT44(local_41c._4_4_,uVar16);
      if ((local_1618 & 1) != 0) {
        operator_delete(local_1608);
      }
      pbVar35 = *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
                 (this + 0x60);
      if (pbVar35 < *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      **)(this + 0x68)) {
        if ((local_638 & 1) == 0) {
          *(char **)(pbVar35 + 0x10) = local_628;
          *(ulong *)(pbVar35 + 8) = uStack_630;
          *(ulong *)pbVar35 = local_638;
        }
        else {
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          __init_copy_ctor_external(pbVar35,local_628,uStack_630);
        }
        memcpy(pbVar35 + 0x18,&local_620,0x20c);
        pbVar35 = pbVar35 + 0x228;
        *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
         (this + 0x60) = pbVar35;
      }
      else {
        pbVar35 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  std::__ndk1::
                  vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                  ::__push_back_slow_path<MTFilterKernel::UniformValue_const&>
                            ((vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                              *)(this + 0x58),(UniformValue *)&local_638);
      }
      *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
       (this + 0x60) = pbVar35;
      uStack_858 = 0;
      local_860 = 0;
      local_850 = (char *)0x0;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_860);
      local_644 = 0x100000000;
      uStack_83c = 0;
      local_844 = 0;
      uStack_82c = 0;
      local_834 = 0;
      uStack_81c = 0;
      local_824 = 0;
      uStack_80c = 0;
      local_814 = 0;
      uStack_7fc = 0;
      local_804 = 0;
      uStack_7ec = 0;
      local_7f4 = 0;
      uStack_7dc = 0;
      local_7e4 = 0;
      uStack_7cc = 0;
      local_7d4 = 0;
      local_848 = 0x20;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_860);
      local_1630 = 0x12;
      local_1627 = 0x35;
      builtin_strncpy(local_162f,"1.0,0.68",8);
      uVar16 = parseUniformValue(&local_844,&local_1630);
      local_644 = CONCAT44(local_644._4_4_,uVar16);
      if ((local_1630 & 1) != 0) {
        operator_delete(local_1620);
      }
      pbVar35 = *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
                 (this + 0x60);
      if (pbVar35 < *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      **)(this + 0x68)) {
        if ((local_860 & 1) == 0) {
          *(char **)(pbVar35 + 0x10) = local_850;
          *(ulong *)(pbVar35 + 8) = uStack_858;
          *(ulong *)pbVar35 = local_860;
        }
        else {
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          __init_copy_ctor_external(pbVar35,local_850,uStack_858);
        }
        memcpy(pbVar35 + 0x18,&local_848,0x20c);
        pbVar35 = pbVar35 + 0x228;
        *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
         (this + 0x60) = pbVar35;
      }
      else {
        pbVar35 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  std::__ndk1::
                  vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                  ::__push_back_slow_path<MTFilterKernel::UniformValue_const&>
                            ((vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                              *)(this + 0x58),(UniformValue *)&local_860);
      }
      *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
       (this + 0x60) = pbVar35;
      uStack_a80 = 0;
      local_a88 = 0;
      local_a78 = (char *)0x0;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_a88);
      local_86c = 0x100000000;
      uStack_a64 = 0;
      local_a6c = 0;
      uStack_a54 = 0;
      local_a5c = 0;
      uStack_a44 = 0;
      local_a4c = 0;
      uStack_a34 = 0;
      local_a3c = 0;
      uStack_a24 = 0;
      local_a2c = 0;
      uStack_a14 = 0;
      local_a1c = 0;
      uStack_a04 = 0;
      local_a0c = 0;
      uStack_9f4 = 0;
      local_9fc = 0;
      local_a70 = 1;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_a88);
      local_1646 = 0;
      local_1648 = 0x3102;
      uVar16 = parseUniformValue(&local_a6c,&local_1648);
      local_86c = CONCAT44(local_86c._4_4_,uVar16);
      if ((local_1648 & 1) != 0) {
        operator_delete(local_1638);
      }
      pbVar35 = *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
                 (this + 0x60);
      if (pbVar35 < *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      **)(this + 0x68)) {
        if ((local_a88 & 1) == 0) {
          *(char **)(pbVar35 + 0x10) = local_a78;
          *(ulong *)(pbVar35 + 8) = uStack_a80;
          *(ulong *)pbVar35 = local_a88;
        }
        else {
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          __init_copy_ctor_external(pbVar35,local_a78,uStack_a80);
        }
        memcpy(pbVar35 + 0x18,&local_a70,0x20c);
        pbVar35 = pbVar35 + 0x228;
        *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
         (this + 0x60) = pbVar35;
      }
      else {
        pbVar35 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  std::__ndk1::
                  vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                  ::__push_back_slow_path<MTFilterKernel::UniformValue_const&>
                            ((vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                              *)(this + 0x58),(UniformValue *)&local_a88);
      }
      *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
       (this + 0x60) = pbVar35;
      uStack_ca8 = 0;
      local_cb0 = 0;
      local_ca0 = (char *)0x0;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_cb0);
      local_a94 = 0x100000000;
      uStack_c8c = 0;
      local_c94 = 0;
      uStack_c7c = 0;
      local_c84 = 0;
      uStack_c6c = 0;
      local_c74 = 0;
      uStack_c5c = 0;
      local_c64 = 0;
      uStack_c4c = 0;
      local_c54 = 0;
      uStack_c3c = 0;
      local_c44 = 0;
      uStack_c2c = 0;
      local_c34 = 0;
      uStack_c1c = 0;
      local_c24 = 0;
      local_c98 = 1;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_cb0);
      local_1660 = 6;
      local_165f = 0x332e30;
      uVar16 = parseUniformValue(&local_c94,&local_1660);
      local_a94 = CONCAT44(local_a94._4_4_,uVar16);
      if ((local_1660 & 1) != 0) {
        operator_delete(local_1650);
      }
      pbVar35 = *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
                 (this + 0x60);
      if (pbVar35 < *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      **)(this + 0x68)) {
        if ((local_cb0 & 1) == 0) {
          *(char **)(pbVar35 + 0x10) = local_ca0;
          *(ulong *)(pbVar35 + 8) = uStack_ca8;
          *(ulong *)pbVar35 = local_cb0;
        }
        else {
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          __init_copy_ctor_external(pbVar35,local_ca0,uStack_ca8);
        }
        memcpy(pbVar35 + 0x18,&local_c98,0x20c);
        pbVar35 = pbVar35 + 0x228;
        *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
         (this + 0x60) = pbVar35;
      }
      else {
        pbVar35 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  std::__ndk1::
                  vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                  ::__push_back_slow_path<MTFilterKernel::UniformValue_const&>
                            ((vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                              *)(this + 0x58),(UniformValue *)&local_cb0);
      }
      *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
       (this + 0x60) = pbVar35;
      uStack_ed0 = 0;
      local_ed8 = 0;
      local_ec8 = (char *)0x0;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_ed8);
      local_cbc = 0x100000000;
      local_ec0 = 1;
      uStack_eb4 = 0;
      local_ebc = 0;
      uStack_ea4 = 0;
      local_eac = 0;
      uStack_e94 = 0;
      local_e9c = 0;
      uStack_e84 = 0;
      local_e8c = 0;
      uStack_e74 = 0;
      local_e7c = 0;
      uStack_e64 = 0;
      local_e6c = 0;
      uStack_e54 = 0;
      local_e5c = 0;
      uStack_e44 = 0;
      local_e4c = 0;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_ed8);
      local_1673 = 0;
      local_1678 = 8;
      local_1677 = 0x35332e30;
      uVar16 = parseUniformValue(&local_ebc,&local_1678);
      local_cbc = CONCAT44(local_cbc._4_4_,uVar16);
      if ((local_1678 & 1) != 0) {
        operator_delete(local_1668);
      }
      pbVar35 = *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
                 (this + 0x60);
      if (pbVar35 < *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      **)(this + 0x68)) {
        if ((local_ed8 & 1) == 0) {
          *(char **)(pbVar35 + 0x10) = local_ec8;
          *(ulong *)(pbVar35 + 8) = uStack_ed0;
          *(ulong *)pbVar35 = local_ed8;
        }
        else {
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          __init_copy_ctor_external(pbVar35,local_ec8,uStack_ed0);
        }
        memcpy(pbVar35 + 0x18,&local_ec0,0x20c);
        pbVar35 = pbVar35 + 0x228;
        *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
         (this + 0x60) = pbVar35;
      }
      else {
        pbVar35 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  std::__ndk1::
                  vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                  ::__push_back_slow_path<MTFilterKernel::UniformValue_const&>
                            ((vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                              *)(this + 0x58),(UniformValue *)&local_ed8);
      }
      *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
       (this + 0x60) = pbVar35;
      uStack_10f8 = 0;
      local_1100 = 0;
      local_10f0 = (char *)0x0;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_1100);
      local_ee4 = 0x100000000;
      uStack_10dc = 0;
      local_10e4 = 0;
      uStack_10cc = 0;
      local_10d4 = 0;
      uStack_10bc = 0;
      local_10c4 = 0;
      uStack_10ac = 0;
      local_10b4 = 0;
      uStack_109c = 0;
      local_10a4 = 0;
      uStack_108c = 0;
      local_1094 = 0;
      uStack_107c = 0;
      local_1084 = 0;
      uStack_106c = 0;
      local_1074 = 0;
      local_10e8 = 1;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_1100);
      local_1108 = 0;
      local_1110 = 0;
      FUN_002793d8((double)fVar65,&local_1110);
      sVar26 = strlen((char *)&local_1110);
      if (0xffffffffffffffef < sVar26) {
        if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
          FUN_001c3100(&local_1690);
        }
        goto LAB_002793d4;
      }
      if (sVar26 < 0x17) {
        pcVar40 = (char *)((ulong)&local_1690 | 1);
        local_1690 = CONCAT71(local_1690._1_7_,(char)((int)sVar26 << 1));
        if (sVar26 != 0) goto LAB_00277cd4;
        *pcVar40 = '\0';
LAB_00277ca0:
        sStack_16a8 = sStack_1688;
        local_16b0 = local_1690;
        local_16a0 = local_1680;
      }
      else {
        uVar57 = (sVar26 | 0xf) + 1;
        pcVar40 = operator_new(uVar57);
        local_1690 = uVar57 | 1;
        sStack_1688 = sVar26;
        local_1680 = pcVar40;
LAB_00277cd4:
        memcpy(pcVar40,&local_1110,sVar26);
        pcVar40[sVar26] = '\0';
        if ((local_1690 & 1) == 0) goto LAB_00277ca0;
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::__init_copy_ctor_external
                  ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *
                   )&local_16b0,local_1680,sStack_1688);
      }
      uVar16 = parseUniformValue(&local_10e4,&local_16b0);
      local_ee4 = CONCAT44(local_ee4._4_4_,uVar16);
      if ((local_16b0 & 1) != 0) {
        operator_delete(local_16a0);
      }
      pbVar35 = *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
                 (this + 0x60);
      if (pbVar35 < *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      **)(this + 0x68)) {
        if ((local_1100 & 1) == 0) {
          *(char **)(pbVar35 + 0x10) = local_10f0;
          *(ulong *)(pbVar35 + 8) = uStack_10f8;
          *(ulong *)pbVar35 = local_1100;
        }
        else {
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          __init_copy_ctor_external(pbVar35,local_10f0,uStack_10f8);
        }
        memcpy(pbVar35 + 0x18,&local_10e8,0x20c);
        pbVar35 = pbVar35 + 0x228;
        *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
         (this + 0x60) = pbVar35;
      }
      else {
        pbVar35 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  std::__ndk1::
                  vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                  ::__push_back_slow_path<MTFilterKernel::UniformValue_const&>
                            ((vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                              *)(this + 0x58),(UniformValue *)&local_1100);
      }
      *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
       (this + 0x60) = pbVar35;
      uStack_1330 = 0;
      local_1338 = 0;
      local_1328 = (char *)0x0;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_1338);
      local_111c = 0x100000000;
      uStack_1314 = 0;
      local_131c = 0;
      uStack_1304 = 0;
      local_130c = 0;
      uStack_12f4 = 0;
      local_12fc = 0;
      uStack_12e4 = 0;
      local_12ec = 0;
      uStack_12d4 = 0;
      local_12dc = 0;
      uStack_12c4 = 0;
      local_12cc = 0;
      uStack_12b4 = 0;
      local_12bc = 0;
      uStack_12a4 = 0;
      local_12ac = 0;
      local_1320 = 1;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      assign((char *)&local_1338);
      local_1340 = 0;
      local_1348 = 0;
      FUN_002793d8((double)fVar66,&local_1348);
      sVar26 = strlen((char *)&local_1348);
      if (0xffffffffffffffef < sVar26) {
        if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
          FUN_001c3100(&local_16c8);
        }
        goto LAB_002793d4;
      }
      if (sVar26 < 0x17) {
        pcVar40 = (char *)((ulong)&local_16c8 | 1);
        local_16c8 = CONCAT71(local_16c8._1_7_,(char)((int)sVar26 << 1));
        if (sVar26 != 0) goto LAB_00277e80;
        *pcVar40 = '\0';
LAB_00277e4c:
        sStack_16d8 = sStack_16c0;
        local_16e0 = local_16c8;
        local_16d0 = local_16b8;
      }
      else {
        uVar57 = (sVar26 | 0xf) + 1;
        pcVar40 = operator_new(uVar57);
        local_16c8 = uVar57 | 1;
        sStack_16c0 = sVar26;
        local_16b8 = pcVar40;
LAB_00277e80:
        memcpy(pcVar40,&local_1348,sVar26);
        pcVar40[sVar26] = '\0';
        if ((local_16c8 & 1) == 0) goto LAB_00277e4c;
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::__init_copy_ctor_external
                  ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *
                   )&local_16e0,local_16b8,sStack_16c0);
      }
      uVar16 = parseUniformValue(&local_131c,&local_16e0);
      local_111c = CONCAT44(local_111c._4_4_,uVar16);
      if ((local_16e0 & 1) != 0) {
        operator_delete(local_16d0);
      }
      pbVar35 = *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
                 (this + 0x60);
      if (pbVar35 < *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      **)(this + 0x68)) {
        if ((local_1338 & 1) == 0) {
          *(char **)(pbVar35 + 0x10) = local_1328;
          *(ulong *)(pbVar35 + 8) = uStack_1330;
          *(ulong *)pbVar35 = local_1338;
        }
        else {
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          __init_copy_ctor_external(pbVar35,local_1328,uStack_1330);
        }
        memcpy(pbVar35 + 0x18,&local_1320,0x20c);
        *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
         (this + 0x60) = pbVar35 + 0x228;
        *(basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> **)
         (this + 0x60) = pbVar35 + 0x228;
        if (local_1508 != local_1510) {
LAB_00277f5c:
          lVar46 = 0;
          uVar57 = 0;
          do {
            InputTexture::InputTexture((InputTexture *)local_14a8);
            local_14a8[0] = 2;
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            operator=(local_14a0,(basic_string *)((long)local_1510 + lVar46));
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            operator=(local_1488,(basic_string *)((long)local_1510 + lVar46));
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            operator=(local_1470,(basic_string *)((long)local_1510 + lVar46));
            uVar44 = ((long)local_1520 - (long)local_1528 >> 3) * -0x5555555555555555;
            puVar17 = local_1528;
            if (uVar44 < uVar57 || uVar44 - uVar57 == 0) {
              puVar17 = local_1510;
            }
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            operator=(local_1488,(basic_string *)((long)puVar17 + lVar46));
            uVar44 = ((long)local_1538 - (long)local_1540 >> 3) * -0x5555555555555555;
            puVar17 = local_1540;
            if (uVar44 < uVar57 || uVar44 - uVar57 == 0) {
              puVar17 = local_1510;
            }
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            operator=(local_1470,(basic_string *)((long)puVar17 + lVar46));
            if (local_1550 != local_1558) {
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              operator=(local_1458,(basic_string *)((long)local_1558 + lVar46));
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              operator=(local_1440,(basic_string *)((long)local_1558 + lVar46));
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              operator=(local_1428,(basic_string *)((long)local_1558 + lVar46));
              uVar44 = ((long)local_1520 - (long)local_1528 >> 3) * -0x5555555555555555;
              if (uVar57 <= uVar44 && uVar44 - uVar57 != 0) {
                std::__ndk1::
                basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
                operator=(local_1440,(basic_string *)((long)local_1570 + lVar46));
              }
              uVar44 = ((long)local_1538 - (long)local_1540 >> 3) * -0x5555555555555555;
              if (uVar57 <= uVar44 && uVar44 - uVar57 != 0) {
                std::__ndk1::
                basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
                operator=(local_1428,(basic_string *)((long)local_1588 + lVar46));
              }
            }
            local_1410 = (int)uVar57 + 1;
            local_13fc = 1;
            if (((long)local_14f0 - (long)local_14f8 == 0) ||
               (uVar44 = uVar57 >> 1 & 0x7fffffff,
               (ulong)((long)local_14f0 - (long)local_14f8 >> 2) <= uVar44)) {
              uVar16 = 0;
            }
            else {
              uVar16 = local_14f8[uVar44];
            }
            local_1408 = 0;
            if ((uVar57 & 1) != 0) {
              local_1408 = uVar16;
            }
            pIVar37 = *(InputTexture **)(this + 0x48);
            if (pIVar37 < *(InputTexture **)(this + 0x50)) {
              InputTexture::InputTexture(pIVar37,(InputTexture *)local_14a8);
              *(InputTexture **)(this + 0x48) = pIVar37 + 0xb0;
              *(InputTexture **)(this + 0x48) = pIVar37 + 0xb0;
            }
            else {
              pIVar37 = std::__ndk1::
                        vector<MTFilterKernel::InputTexture,std::__ndk1::allocator<MTFilterKernel::InputTexture>>
                        ::__push_back_slow_path<MTFilterKernel::InputTexture_const&>
                                  ((vector<MTFilterKernel::InputTexture,std::__ndk1::allocator<MTFilterKernel::InputTexture>>
                                    *)(this + 0x40),(InputTexture *)local_14a8);
              *(InputTexture **)(this + 0x48) = pIVar37;
            }
            if (((byte)local_1428[0] & 1) != 0) {
              operator_delete(local_1418);
            }
            if (((byte)local_1440[0] & 1) != 0) {
              operator_delete(local_1430);
            }
            if (((byte)local_1458[0] & 1) != 0) {
              operator_delete(local_1448);
            }
            if (((byte)local_1470[0] & 1) != 0) {
              operator_delete(local_1460);
            }
            if (((byte)local_1488[0] & 1) != 0) {
              operator_delete(local_1478);
            }
            if (((byte)local_14a0[0] & 1) != 0) {
              operator_delete(local_1490);
            }
            uVar57 = uVar57 + 1;
            lVar46 = lVar46 + 0x18;
            uVar44 = ((long)local_1508 - (long)local_1510 >> 3) * -0x5555555555555555;
          } while (uVar57 <= uVar44 && uVar44 - uVar57 != 0);
        }
      }
      else {
        pUVar36 = std::__ndk1::
                  vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                  ::__push_back_slow_path<MTFilterKernel::UniformValue_const&>
                            ((vector<MTFilterKernel::UniformValue,std::__ndk1::allocator<MTFilterKernel::UniformValue>>
                              *)(this + 0x58),(UniformValue *)&local_1338);
        *(UniformValue **)(this + 0x60) = pUVar36;
        if (local_1508 != local_1510) goto LAB_00277f5c;
      }
      puVar50 = *(undefined8 **)(param_1 + 0x90);
      if (puVar50 < *(undefined8 **)(param_1 + 0x98)) {
        puVar55 = puVar50 + 1;
        *puVar50 = this;
      }
      else {
        puVar54 = *(undefined8 **)(param_1 + 0x88);
        lVar46 = (long)puVar50 - (long)puVar54;
        uVar57 = (lVar46 >> 3) + 1;
        if (uVar57 >> 0x3d != 0) {
          if (*(long *)(lVar5 + 0x28) != local_a8) goto LAB_002793d4;
          FUN_0026e240(param_1 + 0x88);
LAB_00278a94:
          if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
            FUN_001c8a94();
          }
          goto LAB_002793d4;
        }
        uVar45 = (long)*(undefined8 **)(param_1 + 0x98) - (long)puVar54;
        uVar44 = (long)uVar45 >> 2;
        if (uVar44 <= uVar57) {
          uVar44 = uVar57;
        }
        if (0x7ffffffffffffff7 < uVar45) {
          uVar44 = 0x1fffffffffffffff;
        }
        if (uVar44 == 0) {
          pvVar39 = (void *)0x0;
        }
        else {
          if (uVar44 >> 0x3d != 0) goto LAB_00278a94;
          pvVar39 = operator_new(uVar44 << 3);
        }
        puVar47 = (undefined8 *)((long)pvVar39 + (lVar46 >> 3) * 8);
        pvVar28 = (void *)((long)pvVar39 + uVar44 * 8);
        puVar55 = puVar47 + 1;
        *puVar47 = this;
        if ((long)puVar50 - (long)puVar54 == 0) {
          *(undefined8 **)(param_1 + 0x88) = puVar47;
          *(undefined8 **)(param_1 + 0x90) = puVar55;
          *(void **)(param_1 + 0x98) = pvVar28;
        }
        else {
          uVar57 = ((long)puVar50 - (long)puVar54) - 8;
          puVar52 = puVar50;
          if ((uVar57 < 0x38) || ((ulong)((long)puVar50 + (-lVar46 - (long)pvVar39)) < 0x20)) {
LAB_002782d0:
            do {
              puVar52 = puVar52 + -1;
              puVar47 = puVar47 + -1;
              *puVar47 = *puVar52;
            } while (puVar52 != puVar54);
          }
          else {
            uVar57 = (uVar57 >> 3) + 1;
            uVar45 = uVar57 & 0x3ffffffffffffffc;
            puVar52 = puVar50 + -uVar45;
            puVar47 = puVar47 + -uVar45;
            puVar51 = (undefined8 *)((long)pvVar39 + lVar46 + -0x10);
            puVar50 = puVar50 + -2;
            uVar44 = uVar45;
            do {
              puVar6 = puVar50 + -1;
              uVar69 = puVar50[-2];
              uVar68 = puVar50[1];
              uVar67 = *puVar50;
              uVar44 = uVar44 - 4;
              puVar50 = puVar50 + -4;
              puVar51[-1] = *puVar6;
              puVar51[-2] = uVar69;
              puVar51[1] = uVar68;
              *puVar51 = uVar67;
              puVar51 = puVar51 + -4;
            } while (uVar44 != 0);
            if (uVar57 != uVar45) goto LAB_002782d0;
          }
          puVar50 = *(undefined8 **)(param_1 + 0x88);
          *(undefined8 **)(param_1 + 0x88) = puVar47;
          *(undefined8 **)(param_1 + 0x90) = puVar55;
          *(void **)(param_1 + 0x98) = pvVar28;
        }
        if (puVar50 != (undefined8 *)0x0) {
          operator_delete(puVar50);
        }
      }
      *(undefined8 **)(param_1 + 0x90) = puVar55;
      *(float *)(param_1 + 0x40) = fVar65;
      *(undefined4 *)(param_1 + 0x44) = uVar63;
      *(float *)(param_1 + 0x48) = fVar66;
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                (param_1 + 0x50),(basic_string *)local_15a0);
      *(int *)(param_1 + 0x68) = (int)fVar64;
      *(int *)(param_1 + 0x6c) = (int)fVar62;
      *(undefined4 *)(param_1 + 0x80) = local_171c;
      if ((local_16c8 & 1) != 0) {
        operator_delete(local_16b8);
      }
      if ((local_1338 & 1) != 0) {
        operator_delete(local_1328);
      }
      if ((local_1690 & 1) != 0) {
        operator_delete(local_1680);
      }
      if ((local_1100 & 1) != 0) {
        operator_delete(local_10f0);
      }
      if ((local_ed8 & 1) != 0) {
        operator_delete(local_ec8);
      }
      if ((local_cb0 & 1) != 0) {
        operator_delete(local_ca0);
      }
      if ((local_a88 & 1) != 0) {
        operator_delete(local_a78);
      }
      if ((local_860 & 1) != 0) {
        operator_delete(local_850);
      }
      if ((local_638 & 1) != 0) {
        operator_delete(local_628);
      }
      if ((local_410 & 1) != 0) {
        operator_delete(local_400);
      }
      if ((local_1378 & 1) != 0) {
        operator_delete(local_1368);
      }
      if ((local_1390 & 1) != 0) {
        operator_delete(local_1380);
      }
      if ((local_13a8 & 1) != 0) {
        operator_delete(local_1398);
      }
      if ((local_13c0 & 1) != 0) {
        operator_delete(local_13b0);
      }
      if ((local_13d8 & 1) != 0) {
        operator_delete(local_13c8);
      }
      if ((local_13f0[0] & 1) == 0) {
        MTPugiDict::~MTPugiDict(aMStack_15e8);
      }
      else {
        operator_delete(local_13e0);
        MTPugiDict::~MTPugiDict(aMStack_15e8);
      }
    }
    if ((local_15b8 & 1) != 0) {
      operator_delete((void *)CONCAT53(uStack_15a5,CONCAT21(uStack_15a7,uStack_15a8)));
    }
    puVar17 = local_1588;
    if ((local_15a0[0] & 1) != 0) {
      operator_delete(local_1590);
      puVar17 = local_1588;
    }
    local_1588 = puVar17;
    puVar58 = local_1580;
    puVar53 = local_1570;
    if (puVar17 != (ulong *)0x0) {
      while (puVar53 = puVar58, puVar53 != puVar17) {
        puVar58 = puVar53 + -3;
        if ((*puVar58 & 1) != 0) {
          operator_delete((void *)puVar53[-1]);
        }
      }
      local_1580 = puVar17;
      operator_delete(local_1588);
      puVar53 = local_1570;
    }
    local_1570 = puVar53;
    puVar58 = local_1568;
    puVar17 = local_1558;
    if (puVar53 != (ulong *)0x0) {
      while (puVar17 = puVar58, puVar17 != puVar53) {
        puVar58 = puVar17 + -3;
        if ((*puVar58 & 1) != 0) {
          operator_delete((void *)puVar17[-1]);
        }
      }
      local_1568 = puVar53;
      operator_delete(local_1570);
      puVar17 = local_1558;
    }
    local_1558 = puVar17;
    puVar58 = local_1550;
    puVar53 = local_1540;
    if (puVar17 != (ulong *)0x0) {
      while (puVar53 = puVar58, puVar53 != puVar17) {
        puVar58 = puVar53 + -3;
        if ((*puVar58 & 1) != 0) {
          operator_delete((void *)puVar53[-1]);
        }
      }
      local_1550 = puVar17;
      operator_delete(local_1558);
      puVar53 = local_1540;
    }
    local_1540 = puVar53;
    puVar58 = local_1538;
    puVar17 = local_1528;
    if (puVar53 != (ulong *)0x0) {
      while (puVar17 = puVar58, puVar17 != puVar53) {
        puVar58 = puVar17 + -3;
        if ((*puVar58 & 1) != 0) {
          operator_delete((void *)puVar17[-1]);
        }
      }
      local_1538 = puVar53;
      operator_delete(local_1540);
      puVar17 = local_1528;
    }
    local_1528 = puVar17;
    puVar58 = local_1520;
    puVar53 = local_1510;
    if (puVar17 != (ulong *)0x0) {
      while (puVar53 = puVar58, puVar53 != puVar17) {
        puVar58 = puVar53 + -3;
        if ((*puVar58 & 1) != 0) {
          operator_delete((void *)puVar53[-1]);
        }
      }
      local_1520 = puVar17;
      operator_delete(local_1528);
      puVar53 = local_1510;
    }
    local_1510 = puVar53;
    puVar17 = local_1508;
    if (puVar53 != (ulong *)0x0) {
      while (puVar58 = puVar17, puVar58 != puVar53) {
        puVar17 = puVar58 + -3;
        if ((*puVar17 & 1) != 0) {
          operator_delete((void *)puVar58[-1]);
        }
      }
      local_1508 = puVar53;
      operator_delete(local_1510);
    }
    if (local_14f8 != (undefined4 *)0x0) {
      local_14f0 = local_14f8;
      operator_delete(local_14f8);
    }
    if ((local_14e0 & 1) != 0) {
      operator_delete(local_14d0);
    }
    if ((local_14c0 & 1) != 0) {
      operator_delete(local_14b0);
    }
  }
  MTPugiPlist::~MTPugiPlist(aMStack_1e8);
  if (*(long *)(lVar5 + 0x28) == local_a8) {
    return uVar12 & 1;
  }
  goto LAB_002793d4;
LAB_0027874c:
  if (*(long *)(lVar5 + 0x28) == local_a8) {
    FUN_001c8a80(&local_1510);
LAB_00278768:
    if (*(long *)(lVar5 + 0x28) == local_a8) {
      FUN_001c8a80(&local_1528);
LAB_00278784:
      if (*(long *)(lVar5 + 0x28) == local_a8) {
        FUN_001c8a80(&local_1540);
LAB_002787a0:
        if (*(long *)(lVar5 + 0x28) == local_a8) {
          FUN_001c8a80(&local_1558);
LAB_002787bc:
          if (*(long *)(lVar5 + 0x28) == local_a8) {
            FUN_001c8a80(&local_1570);
LAB_002787d8:
            if (*(long *)(lVar5 + 0x28) == local_a8) {
              FUN_001c8a80(&local_1588);
LAB_002787f4:
              if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
                FUN_001c8a94();
              }
            }
          }
        }
      }
    }
  }
  goto LAB_002793d4;
LAB_00278990:
  if (*(long *)(lVar5 + 0x28) == local_a8) {
    FUN_001c8a80(&local_1510);
LAB_002789ac:
    if (*(long *)(lVar5 + 0x28) == local_a8) {
                    /* WARNING: Subroutine does not return */
      FUN_001c3100(&local_410);
    }
  }
LAB_002793d4:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

