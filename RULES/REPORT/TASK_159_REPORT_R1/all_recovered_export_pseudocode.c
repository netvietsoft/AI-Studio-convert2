
/* EXPORT index=1 ELF_VA=0x8e5c size=112 source_sha256=0b52cc6299a2f75655900c6e35a566b972da4952fef8c1d47602fd6de14ed63f */

undefined4 JNI_OnLoad(long *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uStack_28;
  
  uStack_28 = 0;
  uVar2 = 0x10004;
  iVar1 = (**(code **)(*param_1 + 0x30))(param_1,&uStack_28,0x10004);
  if (iVar1 == 0) {
    j___OIIII_lI50S_ll_O__5l5_l__I5II5l_I_OOIIIlI__lIOIS5_();
    j___I050I_IIIII___5SI_50lO__llIIS5OlI_II_l_SOIIIOI_S5_();
    j___0_III__0Il____IOI_O_IIl__IS_l_I550IO0OI_5IIOlIIS5_
              (uStack_28,"com/fort/andJni/JniLib1716343241",0);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


/* EXPORT index=2 ELF_VA=0x8ecc size=8 source_sha256=230c47734cad8ec271cf032de688c8cd1f3b4223d102e892ece196bec64000c1 */

undefined8 j___lOIII_IIOII_III_I_O05S__I_lI0_IO_55IIII_SIII5IIS5_(void)

{
  return 0x29cd;
}


/* EXPORT index=3 ELF_VA=0x8ed4 size=64 source_sha256=5191d877551371c5e40597e63fdb1f0267643fb3a6fd160c73e8efb59bc800b8 */

int j___SllS__I_5l__lIl0I_I_IIl_lI0__5O0OI_l5IO0SIl5S0OS5_(uint param_1)

{
  if (0x7e000000 < param_1) {
    return 0;
  }
  return param_1 + (int)param_1 / 0xff + 0x10;
}


/* EXPORT index=4 ELF_VA=0x8f14 size=8 source_sha256=bf221001ef10c19d32838504b09de27192ed26192cebdf63916c5d8250ef39e6 */

undefined8 j___S5I0S_Il0S0_S_0I0_5OIll_IOII_l5lSIIOSl0_55Il055S5_(void)

{
  return 0x4020;
}


/* EXPORT index=5 ELF_VA=0x8f1c size=312 source_sha256=4353fcd4733f3bdb714288ea22448830b5f756c202aa875526e10f8823696763 */

void j___I__0l_ISS_O_O5lOS_S_I_l_I_SI55IISS5OI50_Ol_Ill5S5_
               (void *param_1,undefined8 param_2,undefined8 param_3,uint param_4,int param_5,
               int param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  
  memset(param_1,0,0x4020);
  iVar4 = 0;
  iVar1 = 1;
  if (0 < param_6) {
    iVar1 = param_6;
  }
  if (param_4 < 0x7e000001) {
    iVar4 = param_4 + (int)param_4 / 0xff + 0x10;
  }
  if (param_5 < iVar4) {
    if ((int)param_4 < 0x1000b) {
      uVar3 = 2;
    }
    else {
      uVar3 = 1;
    }
    uVar2 = 1;
  }
  else {
    if ((int)param_4 < 0x1000b) {
      uVar3 = 2;
    }
    else {
      uVar3 = 1;
    }
    uVar2 = 0;
    param_5 = 0;
  }
  FUN_00109070(param_1,param_2,param_3,param_4,param_5,uVar2,uVar3,0,0,iVar1);
  return;
}


/* EXPORT index=6 ELF_VA=0x9054 size=28 source_sha256=eb89817290c428846083de5bfb493fed176f5e858314445c6879c9ba4b2682e1 */

void j____I_5S_I5I___0ll_I_S0__l_5IISI5lO0I0O0I_OIIIl_50S5_(void *param_1)

{
  memset(param_1,0,0x4020);
  return;
}


/* EXPORT index=7 ELF_VA=0x9a10 size=84 source_sha256=a12aff563d9ead6b972ddac124399dcd9d4925d18a457105e2c7abc5d8158335 */

void j_____l0O_ll5IO_5OOl5_SOlII_I___55IIIIIISISI0SSl_5_S5_
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined1 auStack_4040 [16416];
  
  j___I__0l_ISS_O_O5lOS_S_I_l_I_SI55IISS5OI50_Ol_Ill5S5_
            (auStack_4040,param_1,param_2,param_3,param_4,param_5);
  return;
}


/* EXPORT index=8 ELF_VA=0x9a64 size=80 source_sha256=1d5c9e590c514a36fa7650fc5567c22fd538e504642ec45f23e5b7a08db24da1 */

void j___I_S_I_IIIII_OOIlO__SlI__l5I5Il__l_lI_l5lSS_SSS5S5_
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_4040 [16416];
  
  j___I__0l_ISS_O_O5lOS_S_I_l_I_SI55IISS5OI50_Ol_Ill5S5_
            (auStack_4040,param_1,param_2,param_3,param_4,1);
  return;
}


/* EXPORT index=9 ELF_VA=0x9ab4 size=168 source_sha256=b3d258a82b84c9f97490b9ace16542a0adc3672168d9ee1d2dcb300e8e1f7847 */

void j___Sl_IS_50l_l__IlS__55SI__lOI5OOl_S0lOI__III5O_I_S5_
               (undefined8 param_1,undefined8 param_2,int param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined8 uVar1;
  undefined1 auStack_4060 [16416];
  
  memset(auStack_4060,0,0x4020);
  if (param_3 < 0x1000b) {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  FUN_00109070(auStack_4060,param_1,param_2,param_3,param_4,1,uVar1,0,0,param_5);
  return;
}


/* EXPORT index=10 ELF_VA=0x9b5c size=232 source_sha256=66b839707878ec3fd0955e4c6f054650026ac9fd1cf17a5bf36d9e74e1f71387 */

void j___55lll_l5_Ol_0_llI_OlSII__lI_55_Ol__5IOllSIO_lOIS5_
               (undefined8 param_1,undefined8 param_2,uint *param_3,int param_4)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined1 auStack_4060 [16416];
  
  memset(auStack_4060,0,0x4020);
  uVar1 = *param_3;
  iVar3 = 0;
  if (uVar1 < 0x7e000001) {
    iVar3 = uVar1 + (int)uVar1 / 0xff + 0x10;
  }
  if (param_4 < iVar3) {
    if ((int)uVar1 < 0x1000b) {
      uVar2 = 2;
    }
    else {
      uVar2 = 1;
    }
    FUN_0010aed0(auStack_4060,param_1,param_2,param_3,param_4,uVar2);
  }
  else {
    j___I__0l_ISS_O_O5lOS_S_I_l_I_SI55IISS5OI50_Ol_Ill5S5_
              (auStack_4060,param_1,param_2,uVar1,param_4,1);
  }
  return;
}


/* EXPORT index=11 ELF_VA=0x9c44 size=56 source_sha256=90e3f6e5a92c03e0e22b859ba63215917c58aee714a41b6cd0af9ebb93d34dbb */

void * j___IIl0I_IlSIl_0_llS_05SIl_0II0I50lII_5__llO5__SI5S5_(void)

{
  void *__s;
  
  __s = calloc(8,0x804);
  memset(__s,0,0x4020);
  return __s;
}


/* EXPORT index=12 ELF_VA=0x9c7c size=24 source_sha256=d7de35ebc6dae2b2199a676405359de7530f176c25c29ff9440f7047508542d3 */

undefined8 j___lIIO__0O0___Il0_0_Ol5_O_IS__O5_l_lIIl0_II_50I_IS5_(void *param_1)

{
  free(param_1);
  return 0;
}


/* EXPORT index=13 ELF_VA=0x9c94 size=272 source_sha256=7cbffc726067100ba4741bf1c1f70516c20e3eb9dc3379c27f5b20729094c66a */

int j____I5_I_5_OIO_IlS0__l0lII_l_l5_5I__lOO55__l50__IIS5_(void *param_1,long *param_2,int param_3)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  uint uVar5;
  
  if ((*(int *)((long)param_1 + 0x4004) != 0) ||
     (uVar5 = *(uint *)((long)param_1 + 0x4000), 0x40000000 < uVar5)) {
    memset(param_1,0,0x4020);
    uVar5 = 0;
  }
  if (param_3 < 8) {
    iVar1 = 0;
    *(undefined8 *)((long)param_1 + 0x4008) = 0;
    *(undefined4 *)((long)param_1 + 0x4018) = 0;
  }
  else {
    plVar2 = param_2;
    if (0x10000 < param_3) {
      plVar2 = (long *)((long)param_2 + (long)param_3 + -0x10000);
    }
    *(long **)((long)param_1 + 0x4008) = plVar2;
    iVar1 = ((int)param_2 + param_3) - (int)plVar2;
    param_2 = (long *)((long)param_2 + (long)param_3 + -8);
    *(int *)((long)param_1 + 0x4018) = iVar1;
    *(uint *)((long)param_1 + 0x4000) = iVar1 + uVar5 + 0x10000;
    if (plVar2 <= param_2) {
      plVar3 = plVar2;
      do {
        plVar4 = (long *)((long)plVar3 + 3);
        *(uint *)((long)param_1 + ((ulong)(*plVar3 * 0xcf1bbcdcbb) >> 0x1c & 0xfff) * 4) =
             (int)plVar3 - ((int)plVar2 - (uVar5 + 0x10000));
        plVar3 = plVar4;
      } while (plVar4 <= param_2);
      iVar1 = *(int *)((long)param_1 + 0x4018);
    }
  }
  return iVar1;
}


/* EXPORT index=14 ELF_VA=0x9da4 size=544 source_sha256=88771df377e3c4a706e47c2b82937d1a8d7f8cac8cc98067520bb1d008c00f4a */

undefined8
j_____l0I_Il5lS__ll_I_0__I0_SI_OI5l0III_IIS5_5_0l0OS5_
          (long param_1,ulong param_2,undefined8 param_3,uint param_4,undefined8 param_5,int param_6
          )

{
  ulong uVar1;
  uint *puVar2;
  uint *puVar3;
  ulong uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  long lVar10;
  ulong uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  uint uVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  
  puVar3 = (uint *)(param_1 + 0x4018);
  uVar12 = *puVar3;
  uVar7 = (ulong)uVar12;
  if (*(int *)(param_1 + 0x4004) != 0) {
    return 0;
  }
  uVar8 = *(ulong *)(param_1 + 0x4008);
  puVar2 = (uint *)(param_1 + 0x4000);
  uVar9 = *puVar2;
  uVar4 = uVar8 + uVar7;
  if (uVar9 < 0x80000001) {
    uVar1 = uVar4;
    if (uVar12 == 0 || param_2 <= uVar4) {
      uVar1 = param_2;
    }
    uVar11 = uVar8;
    if (uVar9 <= uVar1) goto LAB_00109e9c;
  }
  lVar10 = 0;
  uVar9 = uVar9 - 0x10000;
  do {
    puVar5 = (undefined8 *)(param_1 + lVar10);
    lVar10 = lVar10 + 0x20;
    uVar12 = (uint)*puVar5;
    iVar28 = -(uint)(uVar12 < uVar9);
    uVar14 = (uint)((ulong)*puVar5 >> 0x20);
    iVar29 = -(uint)(uVar14 < uVar9);
    uVar16 = (uint)puVar5[1];
    iVar30 = -(uint)(uVar16 < uVar9);
    uVar18 = (uint)((ulong)puVar5[1] >> 0x20);
    iVar31 = -(uint)(uVar18 < uVar9);
    uVar20 = (uint)puVar5[2];
    iVar32 = -(uint)(uVar20 < uVar9);
    uVar22 = (uint)((ulong)puVar5[2] >> 0x20);
    iVar33 = -(uint)(uVar22 < uVar9);
    uVar24 = (uint)puVar5[3];
    iVar34 = -(uint)(uVar24 < uVar9);
    uVar26 = (uint)((ulong)puVar5[3] >> 0x20);
    iVar35 = -(uint)(uVar26 < uVar9);
    iVar13 = uVar12 - uVar9;
    iVar15 = uVar14 - uVar9;
    iVar17 = uVar16 - uVar9;
    iVar19 = uVar18 - uVar9;
    iVar21 = uVar20 - uVar9;
    iVar23 = uVar22 - uVar9;
    iVar25 = uVar24 - uVar9;
    iVar27 = uVar26 - uVar9;
    puVar5[1] = CONCAT17((byte)((uint)iVar19 >> 0x18) & ~(byte)((uint)iVar31 >> 0x18),
                         CONCAT16((byte)((uint)iVar19 >> 0x10) & ~(byte)((uint)iVar31 >> 0x10),
                                  CONCAT15((byte)((uint)iVar19 >> 8) & ~(byte)((uint)iVar31 >> 8),
                                           CONCAT14((byte)iVar19 & ~(byte)iVar31,
                                                    CONCAT13((byte)((uint)iVar17 >> 0x18) &
                                                             ~(byte)((uint)iVar30 >> 0x18),
                                                             CONCAT12((byte)((uint)iVar17 >> 0x10) &
                                                                      ~(byte)((uint)iVar30 >> 0x10),
                                                                      CONCAT11((byte)((uint)iVar17
                                                                                     >> 8) &
                                                                               ~(byte)((uint)iVar30
                                                                                      >> 8),
                                                                               (byte)iVar17 &
                                                                               ~(byte)iVar30)))))));
    *puVar5 = CONCAT17((byte)((uint)iVar15 >> 0x18) & ~(byte)((uint)iVar29 >> 0x18),
                       CONCAT16((byte)((uint)iVar15 >> 0x10) & ~(byte)((uint)iVar29 >> 0x10),
                                CONCAT15((byte)((uint)iVar15 >> 8) & ~(byte)((uint)iVar29 >> 8),
                                         CONCAT14((byte)iVar15 & ~(byte)iVar29,
                                                  CONCAT13((byte)((uint)iVar13 >> 0x18) &
                                                           ~(byte)((uint)iVar28 >> 0x18),
                                                           CONCAT12((byte)((uint)iVar13 >> 0x10) &
                                                                    ~(byte)((uint)iVar28 >> 0x10),
                                                                    CONCAT11((byte)((uint)iVar13 >>
                                                                                   8) &
                                                                             ~(byte)((uint)iVar28 >>
                                                                                    8),
                                                                             (byte)iVar13 &
                                                                             ~(byte)iVar28)))))));
    puVar5[3] = CONCAT17((byte)((uint)iVar27 >> 0x18) & ~(byte)((uint)iVar35 >> 0x18),
                         CONCAT16((byte)((uint)iVar27 >> 0x10) & ~(byte)((uint)iVar35 >> 0x10),
                                  CONCAT15((byte)((uint)iVar27 >> 8) & ~(byte)((uint)iVar35 >> 8),
                                           CONCAT14((byte)iVar27 & ~(byte)iVar35,
                                                    CONCAT13((byte)((uint)iVar25 >> 0x18) &
                                                             ~(byte)((uint)iVar34 >> 0x18),
                                                             CONCAT12((byte)((uint)iVar25 >> 0x10) &
                                                                      ~(byte)((uint)iVar34 >> 0x10),
                                                                      CONCAT11((byte)((uint)iVar25
                                                                                     >> 8) &
                                                                               ~(byte)((uint)iVar34
                                                                                      >> 8),
                                                                               (byte)iVar25 &
                                                                               ~(byte)iVar34)))))));
    puVar5[2] = CONCAT17((byte)((uint)iVar23 >> 0x18) & ~(byte)((uint)iVar33 >> 0x18),
                         CONCAT16((byte)((uint)iVar23 >> 0x10) & ~(byte)((uint)iVar33 >> 0x10),
                                  CONCAT15((byte)((uint)iVar23 >> 8) & ~(byte)((uint)iVar33 >> 8),
                                           CONCAT14((byte)iVar23 & ~(byte)iVar33,
                                                    CONCAT13((byte)((uint)iVar21 >> 0x18) &
                                                             ~(byte)((uint)iVar32 >> 0x18),
                                                             CONCAT12((byte)((uint)iVar21 >> 0x10) &
                                                                      ~(byte)((uint)iVar32 >> 0x10),
                                                                      CONCAT11((byte)((uint)iVar21
                                                                                     >> 8) &
                                                                               ~(byte)((uint)iVar32
                                                                                      >> 8),
                                                                               (byte)iVar21 &
                                                                               ~(byte)iVar32)))))));
  } while (lVar10 != 0x4000);
  *puVar2 = 0x10000;
  uVar12 = *puVar3;
  if (0x10000 < uVar12) {
    *puVar3 = 0x10000;
    uVar12 = 0x10000;
  }
  uVar11 = uVar8 + (uVar7 - uVar12);
  *(ulong *)(param_1 + 0x4008) = uVar11;
  uVar9 = 0x10000;
LAB_00109e9c:
  uVar1 = param_2 + (long)(int)param_4;
  iVar13 = 1;
  if (0 < param_6) {
    iVar13 = param_6;
  }
  if ((uVar11 < uVar1) && (uVar1 < uVar4)) {
    uVar12 = (int)uVar4 - (int)uVar1;
    uVar14 = 0x10000;
    if (uVar12 < 0x10001) {
      uVar14 = uVar12;
    }
    uVar12 = 0;
    if (3 < uVar14) {
      uVar12 = uVar14;
    }
    *puVar3 = uVar12;
    *(ulong *)(param_1 + 0x4008) = uVar8 + (uVar7 - uVar12);
  }
  if (uVar4 == param_2) {
    uVar6 = FUN_00109070(param_1,param_2,param_3,param_4,param_5,1,1,1,
                         uVar12 < 0x10000 && uVar12 < uVar9,iVar13);
    *puVar3 = *puVar3 + param_4;
  }
  else {
    uVar6 = FUN_00109070(param_1,param_2,param_3,param_4,param_5,1,1,2,
                         uVar12 < 0x10000 && uVar12 < uVar9,iVar13);
    *(ulong *)(param_1 + 0x4008) = param_2;
    *puVar3 = param_4;
  }
  *puVar2 = *puVar2 + param_4;
  return uVar6;
}


/* EXPORT index=15 ELF_VA=0x9fc4 size=280 source_sha256=96cd6a77fef5498ddb60001099acc005ee98f5ba0323363aeab023c3ae09b7f0 */

void j___IIO0O_0_0S0_OS5IS_OlO5I_lI5SSl_S__SIOlI0II_IO_IS5_
               (long param_1,ulong param_2,undefined8 param_3,uint param_4)

{
  uint *puVar1;
  uint *puVar2;
  ulong uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  long lVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  
  lVar7 = *(long *)(param_1 + 0x4008);
  puVar1 = (uint *)(param_1 + 0x4000);
  puVar2 = (uint *)(param_1 + 0x4018);
  uVar8 = *puVar1;
  uVar6 = *puVar2;
  if (uVar8 < 0x80000001) {
    uVar3 = lVar7 + (ulong)uVar6;
    uVar5 = param_2;
    if (uVar3 <= param_2) {
      uVar5 = uVar3;
    }
    if (uVar8 <= uVar5) goto LAB_0010a084;
  }
  lVar9 = 0;
  uVar8 = uVar8 - 0x10000;
  do {
    puVar4 = (undefined8 *)(param_1 + lVar9);
    lVar9 = lVar9 + 0x20;
    uVar10 = (uint)*puVar4;
    iVar26 = -(uint)(uVar10 < uVar8);
    uVar12 = (uint)((ulong)*puVar4 >> 0x20);
    iVar27 = -(uint)(uVar12 < uVar8);
    uVar14 = (uint)puVar4[1];
    iVar28 = -(uint)(uVar14 < uVar8);
    uVar16 = (uint)((ulong)puVar4[1] >> 0x20);
    iVar29 = -(uint)(uVar16 < uVar8);
    uVar18 = (uint)puVar4[2];
    iVar30 = -(uint)(uVar18 < uVar8);
    uVar20 = (uint)((ulong)puVar4[2] >> 0x20);
    iVar31 = -(uint)(uVar20 < uVar8);
    uVar22 = (uint)puVar4[3];
    iVar32 = -(uint)(uVar22 < uVar8);
    uVar24 = (uint)((ulong)puVar4[3] >> 0x20);
    iVar33 = -(uint)(uVar24 < uVar8);
    iVar11 = uVar10 - uVar8;
    iVar13 = uVar12 - uVar8;
    iVar15 = uVar14 - uVar8;
    iVar17 = uVar16 - uVar8;
    iVar19 = uVar18 - uVar8;
    iVar21 = uVar20 - uVar8;
    iVar23 = uVar22 - uVar8;
    iVar25 = uVar24 - uVar8;
    puVar4[1] = CONCAT17((byte)((uint)iVar17 >> 0x18) & ~(byte)((uint)iVar29 >> 0x18),
                         CONCAT16((byte)((uint)iVar17 >> 0x10) & ~(byte)((uint)iVar29 >> 0x10),
                                  CONCAT15((byte)((uint)iVar17 >> 8) & ~(byte)((uint)iVar29 >> 8),
                                           CONCAT14((byte)iVar17 & ~(byte)iVar29,
                                                    CONCAT13((byte)((uint)iVar15 >> 0x18) &
                                                             ~(byte)((uint)iVar28 >> 0x18),
                                                             CONCAT12((byte)((uint)iVar15 >> 0x10) &
                                                                      ~(byte)((uint)iVar28 >> 0x10),
                                                                      CONCAT11((byte)((uint)iVar15
                                                                                     >> 8) &
                                                                               ~(byte)((uint)iVar28
                                                                                      >> 8),
                                                                               (byte)iVar15 &
                                                                               ~(byte)iVar28)))))));
    *puVar4 = CONCAT17((byte)((uint)iVar13 >> 0x18) & ~(byte)((uint)iVar27 >> 0x18),
                       CONCAT16((byte)((uint)iVar13 >> 0x10) & ~(byte)((uint)iVar27 >> 0x10),
                                CONCAT15((byte)((uint)iVar13 >> 8) & ~(byte)((uint)iVar27 >> 8),
                                         CONCAT14((byte)iVar13 & ~(byte)iVar27,
                                                  CONCAT13((byte)((uint)iVar11 >> 0x18) &
                                                           ~(byte)((uint)iVar26 >> 0x18),
                                                           CONCAT12((byte)((uint)iVar11 >> 0x10) &
                                                                    ~(byte)((uint)iVar26 >> 0x10),
                                                                    CONCAT11((byte)((uint)iVar11 >>
                                                                                   8) &
                                                                             ~(byte)((uint)iVar26 >>
                                                                                    8),
                                                                             (byte)iVar11 &
                                                                             ~(byte)iVar26)))))));
    puVar4[3] = CONCAT17((byte)((uint)iVar25 >> 0x18) & ~(byte)((uint)iVar33 >> 0x18),
                         CONCAT16((byte)((uint)iVar25 >> 0x10) & ~(byte)((uint)iVar33 >> 0x10),
                                  CONCAT15((byte)((uint)iVar25 >> 8) & ~(byte)((uint)iVar33 >> 8),
                                           CONCAT14((byte)iVar25 & ~(byte)iVar33,
                                                    CONCAT13((byte)((uint)iVar23 >> 0x18) &
                                                             ~(byte)((uint)iVar32 >> 0x18),
                                                             CONCAT12((byte)((uint)iVar23 >> 0x10) &
                                                                      ~(byte)((uint)iVar32 >> 0x10),
                                                                      CONCAT11((byte)((uint)iVar23
                                                                                     >> 8) &
                                                                               ~(byte)((uint)iVar32
                                                                                      >> 8),
                                                                               (byte)iVar23 &
                                                                               ~(byte)iVar32)))))));
    puVar4[2] = CONCAT17((byte)((uint)iVar21 >> 0x18) & ~(byte)((uint)iVar31 >> 0x18),
                         CONCAT16((byte)((uint)iVar21 >> 0x10) & ~(byte)((uint)iVar31 >> 0x10),
                                  CONCAT15((byte)((uint)iVar21 >> 8) & ~(byte)((uint)iVar31 >> 8),
                                           CONCAT14((byte)iVar21 & ~(byte)iVar31,
                                                    CONCAT13((byte)((uint)iVar19 >> 0x18) &
                                                             ~(byte)((uint)iVar30 >> 0x18),
                                                             CONCAT12((byte)((uint)iVar19 >> 0x10) &
                                                                      ~(byte)((uint)iVar30 >> 0x10),
                                                                      CONCAT11((byte)((uint)iVar19
                                                                                     >> 8) &
                                                                               ~(byte)((uint)iVar30
                                                                                      >> 8),
                                                                               (byte)iVar19 &
                                                                               ~(byte)iVar30)))))));
  } while (lVar9 != 0x4000);
  *puVar1 = 0x10000;
  uVar8 = *puVar2;
  if (0x10000 < uVar8) {
    *puVar2 = 0x10000;
    uVar8 = 0x10000;
  }
  *(ulong *)(param_1 + 0x4008) = lVar7 + ((ulong)uVar6 - (ulong)uVar8);
LAB_0010a084:
  FUN_00109070(param_1,param_2,param_3,param_4,0,0,1,2,0,1);
  *(ulong *)(param_1 + 0x4008) = param_2;
  *puVar2 = param_4;
  *puVar1 = *puVar1 + param_4;
  return;
}


/* EXPORT index=16 ELF_VA=0xa0dc size=108 source_sha256=20476a918431d74643e45f9625131a1559b4162fb00a5c051056fd0d5e517c6a */

uint j____5I_5__5OI__SIIOI_IS5IS_l_S5Il__SIIIlO_OOOSSSIlS5_(long param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x4018);
  uVar1 = 0x10000;
  if (param_3 < 0x10001) {
    uVar1 = param_3;
  }
  uVar2 = uVar3;
  if (uVar1 <= uVar3) {
    uVar2 = uVar1;
  }
  memmove(param_2,(void *)(*(long *)(param_1 + 0x4008) + ((ulong)uVar3 - (long)(int)uVar2)),
          (long)(int)uVar2);
  *(void **)(param_1 + 0x4008) = param_2;
  *(uint *)(param_1 + 0x4018) = uVar2;
  return uVar2;
}


/* EXPORT index=17 ELF_VA=0xa148 size=52 source_sha256=e6b9bce60bda984f87ced5a38893377bf75006a7aa8a7150608d6aa5c07be6dc */

void j___0_SI0_lI0l__II0lO_l_5_I_l5__I__IIII_l5l_5l5_5llS5_(void)

{
  FUN_0010a17c();
  return;
}


/* EXPORT index=18 ELF_VA=0xa74c size=64 source_sha256=ffd35cc80e7f82013d5289049a8993b12d35c75eff662f0887540b4e9e1c506e */

void j____S_l__l5ISI_I__5O_IS_I5_Il_Il__I__II_lSI_l5l5IlS5_(void)

{
  FUN_0010a17c();
  return;
}


/* EXPORT index=19 ELF_VA=0xa78c size=72 source_sha256=99e2dbae6129a448c0b8464b371f4cd19500bc7ffedc4b8edad4319d9ac2a9c2 */

void j___SIlI__lI_IO_Il0O____O0I_SIII_5II_OI_SIIlSI0I50lS5_
               (undefined8 param_1,long param_2,undefined4 param_3)

{
  FUN_0010a17c(param_1,param_2,0,param_3,0,0,0,1,param_2 + -0x10000,0,0x10000);
  return;
}


/* EXPORT index=20 ELF_VA=0xa7d4 size=12 source_sha256=f72d67937ed78cb4ae228eb018bcddfd86cdba2aedf6713876279e2092719a5d */

void j___0O_II_lI5I5_0I0I__l0III__I5OOOlIlII_5I5__l05lIlS5_(void)

{
  calloc(1,0x20);
  return;
}


/* EXPORT index=21 ELF_VA=0xa7e0 size=24 source_sha256=1f713e8c19b47458ea80cb0b5e687ab1ec9d29b3c727834b42653c3c72477c90 */

undefined8 j____I5Il_IlI0l_l0OIl_0_OII__00llOI5IlllIl0O___I_IlS5_(void *param_1)

{
  free(param_1);
  return 0;
}


/* EXPORT index=22 ELF_VA=0xa7f8 size=32 source_sha256=9e732b04659f466a310f6d2ef01f4569ec8565d17091158af296cbe6fe4260c3 */

undefined8
j___SIllO__Ill____OIO_l5S_S_I0_l_OO5OlIOO5l_lO0_II_S5_(undefined8 *param_1,long param_2,int param_3)

{
  param_1[3] = (long)param_3;
  param_1[1] = 0;
  param_1[2] = param_2 + param_3;
  *param_1 = 0;
  return 1;
}


/* EXPORT index=23 ELF_VA=0xa818 size=224 source_sha256=9f2387e81ff350c5d89a60c943e326fea4159495616e680ae3d27549fa860335 */

void j_____5_l_O_Ill_IllOS_0IlS5_5I_00_SI_I_II___OlIS__0S5_
               (long *param_1,undefined8 param_2,long param_3,undefined4 param_4,undefined4 param_5)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = param_1[3];
  if (param_1[2] == param_3) {
    iVar2 = FUN_0010a17c(param_2,param_3,param_4,param_5,1,0,0,2,param_3 - lVar1,*param_1,param_1[1]
                        );
    if (iVar2 < 1) {
      return;
    }
    param_1[3] = param_1[3] + (long)iVar2;
    param_3 = param_1[2] + (long)iVar2;
  }
  else {
    param_1[1] = lVar1;
    lVar3 = param_1[2] - lVar1;
    *param_1 = lVar3;
    iVar2 = FUN_0010a17c(param_2,param_3,param_4,param_5,1,0,0,2,param_3,lVar3,lVar1);
    if (iVar2 < 1) {
      return;
    }
    param_1[3] = (long)iVar2;
    param_3 = param_3 + iVar2;
  }
  param_1[2] = param_3;
  return;
}


/* EXPORT index=24 ELF_VA=0xa8f8 size=232 source_sha256=6c7294d5c15e8fff0d642fb8366312fef23618b33be0d9c4f49a40fffad24d39 */

void j___I_l5O_SOIll_l5lOS__SIO__Sllll_lIl_SSll5I05lI5IOS5_
               (long *param_1,undefined8 param_2,long param_3,int param_4)

{
  long lVar1;
  int iVar2;
  
  lVar1 = param_1[3];
  if (param_1[2] == param_3) {
    iVar2 = FUN_0010a17c(param_2,param_3,0,param_4,0,0,0,2,param_3 - lVar1,*param_1,param_1[1]);
    if (iVar2 < 1) {
      return;
    }
    param_1[3] = param_1[3] + (long)param_4;
    param_3 = param_1[2] + (long)param_4;
  }
  else {
    param_1[1] = lVar1;
    *param_1 = param_3 - lVar1;
    iVar2 = FUN_0010a17c(param_2,param_3,0,param_4,0,0,0,2,param_3,param_3 - lVar1,lVar1);
    if (iVar2 < 1) {
      return;
    }
    param_1[3] = (long)param_4;
    param_3 = param_3 + param_4;
  }
  param_1[2] = param_3;
  return;
}


/* EXPORT index=25 ELF_VA=0xa9e0 size=24 source_sha256=025e8c7ba0afe6c53258f1528df2b43809bea0af421041005312906d77b82367 */

void j___0I50I_OOISl_llS_l__O_l0_lll0S5ll5l00lI_l5IOISIlS5_(void)

{
  FUN_0010a9f8();
  return;
}


/* EXPORT index=26 ELF_VA=0xaa98 size=36 source_sha256=457e6b44dfc20ae280393638b6a2f9d5efde35cea1afcf0a1839cd3f0f7c7534 */

void j___I5l5__O_ISl_O__lO__ll_S_SlI0_OS0l0I5Il0_ISI_0lIS5_
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined4 param_5)

{
  FUN_0010a9f8(param_1,param_2,0,param_3,0,param_4,param_5);
  return;
}


/* EXPORT index=27 ELF_VA=0xaabc size=56 source_sha256=f77bf60931f4e19a7cb18d6dbe5f48a82edbb7d4f04e4a1a3a3ee5c883c5c07e */

void j___llI_l_5_0lI_llSS0_5OlOI_I_0lll_SISlS_IOl5S0lIIOS5_(void)

{
  FUN_0010a17c();
  return;
}


/* EXPORT index=28 ELF_VA=0xaaf4 size=80 source_sha256=c3e761b3d71b4150efc635a4da6f7b4aba2971b06cb0886cf5dbc1fc151298a5 */

void j____lII5_00Il0_lSI0S_lS_ll__5IO_5l0IOSISlO_I__IIOlS5_
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_4040 [16416];
  
  j___I__0l_ISS_O_O5lOS_S_I_l_I_SI55IISS5OI50_Ol_Ill5S5_
            (auStack_4040,param_1,param_2,param_3,param_4,1);
  return;
}


/* EXPORT index=29 ELF_VA=0xab44 size=132 source_sha256=5d9f60f4657b075f3df2d549b0bd03efa27602b746a2fa6601d46c4dd996d518 */

void j___IS5S5_lI50l___lll_O_lI__ll5IIlS_5O_05lSO_lI__I_S5_
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  undefined1 auStack_4040 [16416];
  
  if (param_3 < 0x7e000001) {
    iVar1 = param_3 + (int)param_3 / 0xff + 0x10;
  }
  else {
    iVar1 = 0;
  }
  j___I__0l_ISS_O_O5lOS_S_I_l_I_SI55IISS5OI50_Ol_Ill5S5_
            (auStack_4040,param_1,param_2,param_3,iVar1,1);
  return;
}


/* EXPORT index=30 ELF_VA=0xabc8 size=8 source_sha256=8d225c3f668dc836f4a4cf063b7d3769dabefc338adb79735c67092cb774f938 */

void j___OIlIS_O_5O0_SIIIl_I_S_l_OSOO0_5_O_05_I_lI_Ol05lS5_(void)

{
  j___I__0l_ISS_O_O5lOS_S_I_l_I_SI55IISS5OI50_Ol_Ill5S5_();
  return;
}


/* EXPORT index=31 ELF_VA=0xabd0 size=68 source_sha256=2779c44a7884eb7859343aba8cedf49ca31c6062f380859e6f46d877b2f7bd06 */

void j___lI5IO_Il0I5__IIO__II5I0__5S5OO50IlIOSSl0_Sll00_S5_(void)

{
  j___I__0l_ISS_O_O5lOS_S_I_l_I_SI55IISS5OI50_Ol_Ill5S5_();
  return;
}


/* EXPORT index=32 ELF_VA=0xac14 size=8 source_sha256=a20a99c2691543324e0440079358db18d1ccf327b2ca0fd432d3aedd1086ef1b */

void j___lII0I__OO5l_Il5Il_OOIl__l5II55ll_l_OIIlOO_05l_5S5_(void)

{
  j_____l0I_Il5lS__ll_I_0__I0_SI_OI5l0III_IIS5_5_0l0OS5_();
  return;
}


/* EXPORT index=33 ELF_VA=0xac1c size=68 source_sha256=e3d2b66f577d3047b5c47cfe5a94b652d3d1d6b076063087a8e7018553112148 */

void j___O0_S__lS_SS_S5II__5I5ll_lI_0IOOOO55_lI_0IlIIlllS5_(void)

{
  j_____l0I_Il5lS__ll_I_0__I0_SI_OI5l0III_IIS5_5_0l0OS5_();
  return;
}


/* EXPORT index=34 ELF_VA=0xac60 size=72 source_sha256=61f94ad0e1c4cba430289177f4657052b078ffa1cff454152fecca6d0b4833a8 */

void j___lO_SI__lI___lIlIl___I0I__Ol5_OI_II_OIlIlI5IIISlS5_
               (undefined8 param_1,long param_2,undefined4 param_3)

{
  FUN_0010a17c(param_1,param_2,0,param_3,0,0,0,1,param_2 + -0x10000,0,0x10000);
  return;
}


/* EXPORT index=35 ELF_VA=0xaca8 size=52 source_sha256=b0f843000b048a8cef5f7d7ff79357326de6ede31cac2f86ea1a91b5d71c5866 */

void j___lSIlI__5II___llSl_0ISII_05SIl_OIO_O05I0l0O0_IIIS5_(void)

{
  FUN_0010a17c();
  return;
}


/* EXPORT index=36 ELF_VA=0xacdc size=8 source_sha256=bf221001ef10c19d32838504b09de27192ed26192cebdf63916c5d8250ef39e6 */

undefined8 j___l00l0_00O5I_0l0l__S__I5_Il_5___IS__I5OOSO0lI_SIS5_(void)

{
  return 0x4020;
}


/* EXPORT index=37 ELF_VA=0xace4 size=72 source_sha256=397b9fcbc9d38656f2b4039df05fc820c4f38556487404bc85c6cc9a88554f4a */

bool j___I5__0_S0III_IIlII_lII00_SO5II5__I_ISl0_O_I_05lIS5_(void *param_1,undefined8 param_2)

{
  bool bVar1;
  
  bVar1 = ((ulong)param_1 & 3) == 0;
  if (bVar1) {
    memset(param_1,0,0x4020);
    *(undefined8 *)((long)param_1 + 0x4010) = param_2;
  }
  return !bVar1;
}


/* EXPORT index=38 ELF_VA=0xad2c size=64 source_sha256=f1a576a3cad73be705926d481ecc1258a2f22d848a4affc5f3a1f516ec72fa39 */

void * j___lIll__lII_0__OIlO_S_II0_I__S0l50_Il_IlIlI5S__IlS5_(undefined8 param_1)

{
  void *__s;
  
  __s = calloc(8,0x804);
  memset(__s,0,0x4020);
  *(undefined8 *)((long)__s + 0x4010) = param_1;
  return __s;
}


/* EXPORT index=39 ELF_VA=0xad6c size=116 source_sha256=7f3bf358255151032ce7222ead955618162ba2334c1c94a0df3c1bfd9d108243 */

long j___S_l5I_lSI_I_l_lII__00OO_5I5IO__ISI_5l0l_55ISO0IS5_(long param_1)

{
  ulong uVar1;
  uint uVar2;
  void *__dest;
  size_t __n;
  
  uVar2 = *(uint *)(param_1 + 0x4018);
  uVar1 = (ulong)uVar2;
  __dest = *(void **)(param_1 + 0x4010);
  if (0xffff < uVar2) {
    uVar2 = 0x10000;
  }
  __n = (size_t)(int)uVar2;
  memmove(__dest,(void *)(*(long *)(param_1 + 0x4008) + (uVar1 - __n)),__n);
  *(void **)(param_1 + 0x4008) = __dest;
  *(uint *)(param_1 + 0x4018) = uVar2;
  return *(long *)(param_1 + 0x4010) + __n;
}


/* EXPORT index=40 ELF_VA=0xade0 size=60 source_sha256=99cc7683d1f9bbd5ebd5b2af8da8631fc4db2bb52313105e0104ca7d88ae6462 */

void j___5II_l__0O_l_Sl_OS__IlOO_IOIS_50I_IlSOIlSISII__OS5_(void)

{
  FUN_0010a17c();
  return;
}


/* EXPORT index=41 ELF_VA=0xae1c size=72 source_sha256=af4695c2dce41af0c7380adf221ceb742ae8cc0d49e3b0210995d7569c2c024d */

void j___OIl_I____5O_I0_Il_0lI05_lS0lS5O05_ISll5IIO5ISl0S5_
               (undefined8 param_1,long param_2,undefined4 param_3)

{
  FUN_0010a17c(param_1,param_2,0,param_3,0,0,0,1,param_2 + -0x10000,0,0x10000);
  return;
}


/* EXPORT index=42 ELF_VA=0xae64 size=96 source_sha256=51b342a1ecb6564d73c67c7a3768eb4630d275669942edccaf5d79cac2b14f48 */

void * j____II5I_0_5ll_IOOIl__lIS5_ISIOllISS5lII_0ISOlIS0_S5_(void)

{
  void *pvVar1;
  
  pvVar1 = malloc(0x291a);
  FUN_0010a17c(&DAT_0018a008,pvVar1,0x118a,0x291a,1,0,0,0,pvVar1,0,0);
  return pvVar1;
}


/* EXPORT index=43 ELF_VA=0xaec4 size=12 source_sha256=c8080d629cd5535a011de0741c60975a30797472f1440ef85da3a0d650a88969 */

undefined * j_____OIl_0_II__l5OO__II0IO_IO____II_l5_5l5_0l0lIlIS5_(void)

{
  return &DAT_0018c928;
}


/* EXPORT index=44 ELF_VA=0xb5e4 size=20 source_sha256=73d9a08e2b48c45043701637c1262a7222927148f43a1f5b98a252f4fe95ce4d */

undefined8 j____l0_l_OIIlI_IS5ll_OO_Il_l5O05550O5l_IO_II_I5O55S5_(int param_1)

{
  return *(undefined8 *)(DAT_0018dc28 + (long)param_1 * 8);
}


/* EXPORT index=45 ELF_VA=0xb5f8 size=20 source_sha256=2b96aac6c69192c793712014fba4d5b6736be7db3a0d56244e5d24dd3bd985c4 */

undefined8 j___05III_lS55I__IlI5_SII0__S_l_I5OSI5ISSOOI5_O0lllS5_(int param_1)

{
  return *(undefined8 *)(DAT_0018dc30 + (long)param_1 * 8);
}


/* EXPORT index=46 ELF_VA=0xb60c size=20 source_sha256=ee919b80fef048996a0da02ffd0691a203fd4cab45945ffdf8ca64716a47dfdd */

undefined8 j___5OISI_IIIII_IlSII_lIIll_lO_Il5II0_00I0IllOIS_5IS5_(int param_1)

{
  return *(undefined8 *)(DAT_0018dc38 + (long)param_1 * 8);
}


/* EXPORT index=47 ELF_VA=0xb620 size=20 source_sha256=90b7a2f832750d6ba0d97f892b88049a52fc73e90b6997b74bd5a0dbfa9b92f0 */

undefined8 j____Il0I_llI0l_SIIII_I_O_l_Ill_O5_IOI5I__S_I0IllOlS5_(int param_1)

{
  return *(undefined8 *)(DAT_0018dc40 + (long)param_1 * 8);
}


/* EXPORT index=48 ELF_VA=0xb634 size=2264 source_sha256=7a01920c257c18f2c723a39c6d1164c39cec3ee908e581cb0783d935c3bbd12f */

void j___I050I_IIIII___5SI_50lO__llIIS5OlI_II_l_SOIIIOI_S5_(void)

{
  uint uVar1;
  bool bVar2;
  undefined8 uVar3;
  void *pvVar4;
  void *pvVar5;
  int iVar6;
  undefined4 *puVar7;
  ulong extraout_x9;
  long lVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  ulong uVar13;
  uint unaff_w24;
  int iVar14;
  uint unaff_w27;
  uint unaff_w28;
  uint uStack_ec;
  ulong uStack_e8;
  ulong uStack_e0;
  ulong uStack_d8;
  ulong uStack_d0;
  int iStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  uint uStack_b4;
  int iStack_b0;
  int iStack_ac;
  int iStack_a8;
  uint uStack_a4;
  undefined4 uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  uint uStack_94;
  uint uStack_90;
  uint uStack_8c;
  undefined1 auStack_88 [8];
  long lStack_80;
  undefined4 uStack_64;
  
  uStack_64 = 0;
  uVar3 = j____II5I_0_5ll_IOOIl__lIS5_ISIOllISS5lII_0ISOlIS0_S5_();
  iVar14 = 0x7410;
  iVar6 = 0x14;
  uStack_e8 = extraout_x9;
  uStack_e0 = extraout_x9;
  uStack_d8 = extraout_x9;
  uStack_d0 = extraout_x9;
switchD_0010b6a4_default:
  switch(iVar6) {
  case 0:
    j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&iStack_a8);
    j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&iStack_ac);
    j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&iStack_b0);
    pvVar4 = malloc(0x20);
    lVar8 = (uStack_d0 & 0xffffffff) * 8;
    *(void **)((long)DAT_0018dc38 + lVar8) = pvVar4;
    **(undefined8 **)((long)DAT_0018dc38 + lVar8) =
         **(undefined8 **)((long)DAT_0018dc48 + (long)iStack_a8 * 8);
    *(undefined8 *)(*(long *)((long)DAT_0018dc38 + lVar8) + 8) =
         **(undefined8 **)((long)DAT_0018dc48 + (long)iStack_ac * 8);
    *(undefined8 *)(*(long *)((long)DAT_0018dc38 + lVar8) + 0x10) =
         **(undefined8 **)((long)DAT_0018dc48 + (long)iStack_b0 * 8);
    iVar6 = 8;
    goto switchD_0010b6a4_default;
  case 1:
    unaff_w27 = unaff_w27 + 1;
    iVar6 = (0x90 - iVar14) + ((uint)(iVar14 * 0xd902) >> 0x17) * 0x97;
    goto switchD_0010b6a4_default;
  case 2:
    lVar8 = (ulong)unaff_w27 * 8;
    *(undefined8 *)(*(long *)((long)DAT_0018dc40 + lVar8) + 0x10) =
         **(undefined8 **)((long)DAT_0018dc48 + (long)iStack_c0 * 8);
    *(undefined8 *)(*(long *)((long)DAT_0018dc40 + lVar8) + 0x18) =
         **(undefined8 **)((long)DAT_0018dc48 + (long)iStack_c4 * 8);
    iVar14 = 0x2e7f;
    *(undefined1 *)(*(long *)((long)DAT_0018dc40 + lVar8) + 0x20) = 0;
    iVar6 = 1;
    goto switchD_0010b6a4_default;
  case 3:
    iVar10 = 0x2e;
    iVar6 = 0x38;
    iVar11 = 0x58f4;
    iVar9 = ((uint)(iVar14 * 0xdd68) >> 0x15) * -0x25;
    bVar2 = uStack_8c <= (uint)uStack_d8;
    break;
  case 4:
    j___lI50I_5I0_5_I_O0S_llII__I_5Ol_lSI_llOISI5_IO5I5S5_(auStack_88,&uStack_98);
    uVar12 = uStack_98;
    uVar13 = (ulong)uStack_98;
    uVar1 = uStack_98 + 1;
    pvVar4 = malloc((ulong)uVar1);
    memset(pvVar4,0,(ulong)uVar1);
    uVar1 = DAT_0018dc20;
    memcpy(pvVar4,(void *)(lStack_80 + (ulong)DAT_0018dc20),uVar13);
    DAT_0018dc20 = uVar1 + uVar12;
    pvVar5 = malloc(0x10);
    lVar8 = (ulong)unaff_w28 * 8;
    *(void **)((long)DAT_0018dc28 + lVar8) = pvVar5;
    **(undefined8 **)((long)DAT_0018dc28 + lVar8) = pvVar4;
    *(uint *)(*(long *)((long)DAT_0018dc28 + lVar8) + 8) = uVar12;
    iVar6 = 5;
    goto switchD_0010b6a4_default;
  case 5:
    *(undefined1 *)(*(long *)((long)DAT_0018dc28 + (ulong)unaff_w28 * 8) + 0xc) = 0;
    iVar6 = 9;
    goto switchD_0010b6a4_default;
  case 6:
    unaff_w24 = unaff_w24 + 1;
    iVar14 = 0x4e0;
    iVar6 = 0x16;
    goto switchD_0010b6a4_default;
  case 7:
    j___OOlIO_0SOl0_I00_O_IlSII_OS_l_500ISSl_OS_IlIlI5IS5_(auStack_88,&uStack_a4);
    uStack_e8 = (ulong)uStack_a4 / 3;
    DAT_0018dc38 = malloc(uStack_e8 << 3);
    uStack_d0 = 0;
    iVar14 = 0x25ab;
    iVar6 = 0x12;
    goto switchD_0010b6a4_default;
  case 8:
    *(undefined1 *)(*(long *)((long)DAT_0018dc38 + (uStack_d0 & 0xffffffff) * 8) + 0x18) = 0;
    iVar6 = 0x10;
    goto switchD_0010b6a4_default;
  case 9:
    unaff_w28 = unaff_w28 + 1;
    iVar6 = 0x11;
    goto switchD_0010b6a4_default;
  case 10:
    CallSupervisor(0);
    iVar14 = 0x31ee;
    iVar6 = 0x12;
    goto switchD_0010b6a4_default;
  case 0xb:
    j___OOlIO_0SOl0_I00_O_IlSII_OS_l_500ISSl_OS_IlIlI5IS5_(auStack_88,&uStack_94);
    DAT_0018dc28 = malloc((ulong)uStack_94 << 3);
    unaff_w28 = 0;
    iVar6 = 0x11;
    goto switchD_0010b6a4_default;
  case 0xc:
    j___5I5IO_I0__I_5IlI5_5OSSI_I0Il_OIlI_55SS_l0I_ISIOS5_(auStack_88,&uStack_a0);
    pvVar4 = malloc(8);
    *(void **)((long)DAT_0018dc30 + (ulong)unaff_w24 * 8) = pvVar4;
    puVar7 = *(undefined4 **)((long)DAT_0018dc30 + (ulong)unaff_w24 * 8);
    *puVar7 = uStack_a0;
    *(undefined1 *)(puVar7 + 1) = 0;
    iVar6 = (9 - iVar14) + ((uint)(iVar14 * 0xba2f) >> 0x13) * 0xb;
    goto switchD_0010b6a4_default;
  case 0xd:
    j___OOlIO_0SOl0_I00_O_IlSII_OS_l_500ISSl_OS_IlIlI5IS5_(auStack_88,&uStack_b4);
    uStack_e0 = (ulong)(uStack_b4 >> 2);
    DAT_0018dc40 = malloc(uStack_e0 << 3);
    unaff_w27 = 0;
    iVar6 = 0x13;
    goto switchD_0010b6a4_default;
  case 0xe:
    j___OOlIO_0SOl0_I00_O_IlSII_OS_l_500ISSl_OS_IlIlI5IS5_(auStack_88,&uStack_9c);
    DAT_0018dc30 = malloc((ulong)uStack_9c << 3);
    unaff_w24 = 0;
    iVar14 = 0x4869;
    iVar6 = 0x16;
    goto switchD_0010b6a4_default;
  case 0xf:
    *(undefined1 *)(*(long *)((long)DAT_0018dc28 + (ulong)unaff_w28 * 8) + 0xc) = 0;
    iVar6 = (0x47 - iVar14) + ((uint)(iVar14 * 0x8ad9) >> 0x15) * 0x3b;
    goto switchD_0010b6a4_default;
  case 0x10:
    uStack_d0 = (ulong)((uint)uStack_d0 + 1);
    iVar6 = 0x17;
    goto switchD_0010b6a4_default;
  case 0x11:
    iVar6 = 4;
    if (uStack_94 <= unaff_w28) {
      iVar6 = 0xe;
    }
    goto switchD_0010b6a4_default;
  case 0x12:
    iVar6 = (0x1e - iVar14) + ((uint)(iVar14 * 0xe071) >> 0x16) * 0x49;
    goto switchD_0010b6a4_default;
  case 0x13:
    iVar6 = 0x1b;
    if ((uint)uStack_e0 <= unaff_w27) {
      iVar6 = 0x1e;
    }
    iVar14 = 0x500;
    goto switchD_0010b6a4_default;
  case 0x14:
    iVar14 = iVar14 + ((uint)(iVar14 * 0xebbe) >> 0x17) * -0x8b;
    j____OIII_llIO__Ill50_IllIO_I_O0I5llllIIlIIlI5lO00IS5_(auStack_88,uVar3,FUN_0010bf88,0);
    j___OOlIO_0SOl0_I00_O_IlSII_OS_l_500ISSl_OS_IlIlI5IS5_(auStack_88,&uStack_8c);
    DAT_0018dc48 = malloc((ulong)uStack_8c << 3);
    uStack_d8 = 0;
    iVar6 = 0x6c - iVar14;
    iVar14 = 0x6705 - iVar14;
    goto switchD_0010b6a4_default;
  case 0x15:
    uStack_ec = (uint)(iVar14 * 0x9f12) >> 0x16;
    j___lI50I_5I0_5_I_O0S_llII__I_5Ol_lSI_llOISI5_IO5I5S5_(auStack_88,&uStack_90);
    uVar12 = uStack_90;
    uVar13 = (ulong)uStack_90;
    uVar1 = uStack_90 + 1;
    pvVar4 = malloc((ulong)uVar1);
    memset(pvVar4,0,(ulong)uVar1);
    uVar1 = DAT_0018dc20;
    memcpy(pvVar4,(void *)(lStack_80 + (ulong)DAT_0018dc20),uVar13);
    DAT_0018dc20 = uVar1 + uVar12;
    pvVar5 = malloc(0x10);
    lVar8 = (uStack_d8 & 0xffffffff) * 8;
    *(void **)((long)DAT_0018dc48 + lVar8) = pvVar5;
    **(undefined8 **)((long)DAT_0018dc48 + lVar8) = pvVar4;
    iVar9 = 0x65;
    lVar8 = *(long *)((long)DAT_0018dc48 + lVar8);
    iVar6 = 0x67;
    goto LAB_0010bd60;
  case 0x16:
    iVar10 = 0xc;
    iVar6 = 0x11;
    iVar11 = 0xb8c;
    iVar9 = ((uint)(iVar14 * 0x90fe) >> 0x16) * -0x71;
    bVar2 = uStack_9c <= unaff_w24;
    break;
  case 0x17:
    iVar6 = 0;
    if ((uint)uStack_e8 <= (uint)uStack_d0) {
      iVar6 = 0xd;
    }
    goto switchD_0010b6a4_default;
  case 0x18:
    iVar14 = 0x1a69;
    *(undefined1 *)(*(long *)((long)DAT_0018dc48 + (uStack_d8 & 0xffffffff) * 8) + 0xc) = 0;
    iVar6 = 0x1d;
    goto switchD_0010b6a4_default;
  case 0x19:
    *(undefined1 *)(*(long *)((long)DAT_0018dc28 + (ulong)unaff_w28 * 8) + 0xc) = 0;
    iVar6 = 0x11;
    goto switchD_0010b6a4_default;
  case 0x1a:
    uStack_ec = (uint)(iVar14 * 0x8ad9) >> 0x15;
    j___lI50I_5I0_5_I_O0S_llII__I_5Ol_lSI_llOISI5_IO5I5S5_(auStack_88,&uStack_98);
    uVar12 = uStack_98;
    uVar13 = (ulong)uStack_98;
    uVar1 = uStack_98 + 1;
    pvVar4 = malloc((ulong)uVar1);
    memset(pvVar4,0,(ulong)uVar1);
    uVar1 = DAT_0018dc20;
    memcpy(pvVar4,(void *)(lStack_80 + (ulong)DAT_0018dc20),uVar13);
    DAT_0018dc20 = uVar1 + uVar12;
    pvVar5 = malloc(0x10);
    lVar8 = (ulong)unaff_w28 * 8;
    *(void **)((long)DAT_0018dc28 + lVar8) = pvVar5;
    **(undefined8 **)((long)DAT_0018dc28 + lVar8) = pvVar4;
    iVar9 = 0x4f;
    lVar8 = *(long *)((long)DAT_0018dc28 + lVar8);
    iVar6 = 0x3b;
LAB_0010bd60:
    *(uint *)(lVar8 + 8) = uVar12;
    iVar6 = (iVar9 - iVar14) + uStack_ec * iVar6;
    goto switchD_0010b6a4_default;
  case 0x1b:
    j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&iStack_b8);
    j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&iStack_c0);
    j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&iStack_bc);
    j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&iStack_c4);
    pvVar4 = malloc(0x28);
    lVar8 = (ulong)unaff_w27 * 8;
    *(void **)((long)DAT_0018dc40 + lVar8) = pvVar4;
    **(undefined8 **)((long)DAT_0018dc40 + lVar8) =
         **(undefined8 **)((long)DAT_0018dc48 + (long)iStack_b8 * 8);
    *(undefined8 *)(*(long *)((long)DAT_0018dc40 + lVar8) + 8) =
         **(undefined8 **)((long)DAT_0018dc48 + (long)iStack_bc * 8);
    iVar6 = 2;
    goto switchD_0010b6a4_default;
  case 0x1c:
    iVar14 = iVar14 + ((uint)(iVar14 * 0x8ad9) >> 0x15) * -0x3b;
    j___lI50I_5I0_5_I_O0S_llII__I_5Ol_lSI_llOISI5_IO5I5S5_(auStack_88,&uStack_98);
    uVar12 = uStack_98;
    uVar13 = (ulong)uStack_98;
    uVar1 = uStack_98 + 1;
    pvVar4 = malloc((ulong)uVar1);
    memset(pvVar4,0,(ulong)uVar1);
    uVar1 = DAT_0018dc20;
    memcpy(pvVar4,(void *)(lStack_80 + (ulong)DAT_0018dc20),uVar13);
    DAT_0018dc20 = uVar1 + uVar12;
    pvVar5 = malloc(0x10);
    lVar8 = (ulong)unaff_w28 * 8;
    *(void **)((long)DAT_0018dc28 + lVar8) = pvVar5;
    **(undefined8 **)((long)DAT_0018dc28 + lVar8) = pvVar4;
    iVar6 = 0x45 - iVar14;
    *(uint *)(*(long *)((long)DAT_0018dc28 + lVar8) + 8) = uVar12;
    iVar14 = 0x6c83 - iVar14;
    goto switchD_0010b6a4_default;
  case 0x1d:
    goto switchD_0010b6a4_caseD_1d;
  case 0x1e:
    goto switchD_0010b6a4_caseD_1e;
  default:
    goto switchD_0010b6a4_default;
  }
  if (bVar2) {
    iVar6 = iVar10;
  }
  iVar6 = iVar6 - (iVar14 + iVar9);
  iVar14 = iVar11 - (iVar14 + iVar9);
  goto switchD_0010b6a4_default;
switchD_0010b6a4_caseD_1d:
  uStack_d8 = (ulong)((uint)uStack_d8 + 1);
  iVar14 = iVar14 + ((uint)(iVar14 * 0xc7cf) >> 0x15) * -0x29;
  iVar6 = 0x28 - iVar14;
  iVar14 = 0x51cc - iVar14;
  goto switchD_0010b6a4_default;
switchD_0010b6a4_caseD_1e:
  return;
}


/* EXPORT index=49 ELF_VA=0xbfd0 size=1156 source_sha256=92ea77dbd81daaa23f79c115e52acdf1c9b14354b3dcc66f90a8484f796c89c1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x000a0714) */

void j____S_II_I0IlS_lO_lI_0lSlI_OS_IO50l05ISI00I5_0IIlOS5_
               (ushort *param_1,ulong param_2,long *param_3,long *param_4)

{
  char cVar1;
  ushort uVar2;
  void *__s;
  int iVar3;
  ulong *puVar4;
  long lVar5;
  double *pdVar6;
  ulong uVar7;
  ulong *puVar8;
  ulong *unaff_x23;
  long *unaff_x24;
  size_t __size;
  uint uVar9;
  char *unaff_x28;
  char *pcVar10;
  undefined8 uStack_70;
  int iStack_68;
  undefined4 uStack_64;
  
  uStack_64 = 0;
  uVar9 = 0x621;
  iStack_68 = 0x14;
  iVar3 = 0x14;
switchD_0010c03c_default:
  do {
    switch(iVar3) {
    case 0:
switchD_0010c03c_caseD_0:
      iVar3 = 8;
      iStack_68 = 8;
      uVar9 = 0x2837;
      break;
    case 1:
switchD_0010c03c_caseD_1:
      iVar3 = 2;
      iStack_68 = 2;
      break;
    case 2:
      iVar3 = (int)param_4[3];
      if ((iVar3 < 0) && (*(int *)(param_4 + 3) = iVar3 + 8, iVar3 + 8 < 1)) {
        puVar4 = (ulong *)(param_4[1] + (long)iVar3);
      }
      else {
        puVar4 = (ulong *)*param_4;
        *param_4 = (long)(puVar4 + 1);
      }
      puVar8 = unaff_x23 + 1;
      *unaff_x23 = *puVar4;
      FUN_0010c4d0(&uStack_70);
      goto LAB_0010c020;
    case 3:
      iVar3 = (int)param_4[3];
      if ((iVar3 < 0) && (*(int *)(param_4 + 3) = iVar3 + 8, iVar3 + 8 < 1)) {
        puVar8 = (ulong *)(param_4[1] + (long)iVar3);
      }
      else {
        puVar8 = (ulong *)*param_4;
        *param_4 = (long)(puVar8 + 1);
      }
      *unaff_x23 = *puVar8;
      FUN_0010c4d0(&uStack_70);
      iStack_68 = (0x65 - uVar9) + (uVar9 / 0xad) * 0xad;
      unaff_x23 = unaff_x23 + 1;
      iVar3 = iStack_68;
      break;
    case 4:
switchD_0010c03c_caseD_4:
      iStack_68 = 10;
      iVar3 = 10;
      break;
    case 5:
      iStack_68 = 0xf;
      iVar3 = 0xf;
      break;
    case 6:
      lVar5 = *(long *)(param_1 + 8);
      unaff_x24[6] = *(long *)(param_1 + 0x10);
      *unaff_x24 = lVar5 + 0x10;
      j___I0_SI_I_lIl_55lI__II0Il_I__IO5II_5_SIl0l5IOlIOlS5_(unaff_x24,param_1,param_3,uStack_70);
      *param_3 = unaff_x24[2];
      free((void *)unaff_x24[1]);
      free(unaff_x24);
      iStack_68 = 7;
      iVar3 = 7;
      break;
    case 7:
      FUN_0010de74(&uStack_70);
      iStack_68 = 0x15;
      iVar3 = 0x15;
      break;
    case 8:
      iVar3 = *(int *)((long)param_4 + 0x1c);
      if ((iVar3 < 0) && (*(int *)((long)param_4 + 0x1c) = iVar3 + 0x10, iVar3 + 0x10 < 1)) {
        pdVar6 = (double *)(param_4[2] + (long)iVar3);
      }
      else {
        pdVar6 = (double *)*param_4;
        *param_4 = (long)(pdVar6 + 1);
      }
      iStack_68 = (0x44 - uVar9) + (uVar9 / 0x6d) * 0x6d;
      uVar7 = (ulong)(uint)(float)*pdVar6;
      goto LAB_0010c290;
    case 9:
      puVar8 = unaff_x23 + 1;
      *unaff_x23 = param_2;
      FUN_0010c4d0(&uStack_70);
      goto LAB_0010c20c;
    case 10:
      iVar3 = (int)param_4[3];
      if ((iVar3 < 0) && (*(int *)(param_4 + 3) = iVar3 + 8, iVar3 + 8 < 1)) {
        puVar8 = (ulong *)(param_4[1] + (long)iVar3);
      }
      else {
        puVar8 = (ulong *)*param_4;
        *param_4 = (long)(puVar8 + 1);
      }
      iStack_68 = 0x13;
      *unaff_x23 = *puVar8;
      goto LAB_0010c350;
    case 0xb:
switchD_0010c03c_caseD_b:
      iStack_68 = 0x10;
      iVar3 = 0x10;
      break;
    case 0xc:
      iStack_68 = 0x11;
      iVar3 = 0x11;
      break;
    case 0xd:
      puVar8 = (ulong *)(unaff_x24[1] + ((ulong)*param_1 - (ulong)param_1[1]) * 8);
      if ((char)param_1[0x14] == '\0') {
        iStack_68 = 9;
        unaff_x23 = puVar8;
        iVar3 = 9;
      }
      else {
LAB_0010c20c:
        iStack_68 = 5;
        unaff_x23 = puVar8;
        iVar3 = 5;
      }
      break;
    case 0xe:
switchD_0010c03c_caseD_e:
      iStack_68 = 0x12;
      uVar9 = 0x6b91;
      iVar3 = 0x12;
      break;
    case 0xf:
      puVar8 = unaff_x23;
      if (iStack_68 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
LAB_0010c020:
      iStack_68 = 0x13;
      unaff_x23 = puVar8;
      iVar3 = 0x13;
      break;
    case 0x10:
      iVar3 = (int)param_4[3];
      if ((iVar3 < 0) && (*(int *)(param_4 + 3) = iVar3 + 8, iVar3 + 8 < 1)) {
        puVar8 = (ulong *)(param_4[1] + (long)iVar3);
      }
      else {
        puVar8 = (ulong *)*param_4;
        *param_4 = (long)(puVar8 + 1);
      }
      uVar7 = *puVar8;
      iStack_68 = 0x13;
LAB_0010c290:
      *unaff_x23 = uVar7;
      unaff_x23 = unaff_x23 + 1;
      iVar3 = iStack_68;
      break;
    case 0x11:
      pcVar10 = unaff_x28 + 1;
      cVar1 = *unaff_x28;
      unaff_x28 = pcVar10;
      switch(cVar1) {
      case 'D':
        goto switchD_0010c03c_caseD_e;
      default:
        goto switchD_0010c03c_caseD_b;
      case 'F':
        goto switchD_0010c03c_caseD_0;
      case 'J':
        goto switchD_0010c03c_caseD_4;
      case 'L':
        goto switchD_0010c03c_caseD_1;
      }
    case 0x12:
      iVar3 = *(int *)((long)param_4 + 0x1c);
      if ((iVar3 < 0) && (*(int *)((long)param_4 + 0x1c) = iVar3 + 0x10, iVar3 + 0x10 < 1)) {
        puVar8 = (ulong *)(param_4[2] + (long)iVar3);
      }
      else {
        puVar8 = (ulong *)*param_4;
        *param_4 = (long)(puVar8 + 1);
      }
      iStack_68 = (0x61 - uVar9) + (uVar9 / 0x71) * 0x71;
      *unaff_x23 = *puVar8;
LAB_0010c350:
      unaff_x23[1] = 0;
      unaff_x23 = unaff_x23 + 2;
      iVar3 = iStack_68;
      break;
    case 0x13:
      if (*unaff_x28 == '\0') {
        iStack_68 = 6;
        iVar3 = 6;
      }
      else {
        iStack_68 = 0xc;
        iVar3 = 0xc;
      }
      break;
    case 0x14:
      goto switchD_0010c03c_caseD_14;
    case 0x15:
      return;
    }
  } while( true );
switchD_0010c03c_caseD_14:
  unaff_x28 = (char *)(*(long *)(param_1 + 4) + 1);
  uStack_70 = 0;
  unaff_x24 = malloc(0x40);
  uVar2 = *param_1;
  __size = (ulong)uVar2 << 3;
  __s = malloc(__size);
  unaff_x24[1] = (long)__s;
  memset(__s,0,__size);
  *(ushort *)(unaff_x24 + 7) = uVar2;
  iStack_68 = (0x35 - uVar9) + (uVar9 / 0x8b) * 0x8b;
  iVar3 = iStack_68;
  goto switchD_0010c03c_default;
}


/* EXPORT index=50 ELF_VA=0xe3c0 size=164 source_sha256=ca7c4405634534fbd0a8cb39c07142ddfec6b54c4d875a9fb2530af43577f5c6 */

void j___S5I___O_0I0_0_IIl_lIl_I__IISSlIOllOIIlSISI__5IlS5_
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  long lVar1;
  undefined1 auStack_a0 [8];
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined1 *puStack_70;
  undefined1 **ppuStack_68;
  undefined1 *puStack_60;
  undefined8 uStack_58;
  
  uStack_98 = param_4;
  uStack_90 = param_5;
  uStack_88 = param_6;
  uStack_80 = param_7;
  uStack_78 = param_8;
  lVar1 = j___lII00_IOOlS__SS0I_OS_0__OISl55II0lOSIlI0IIIISS0S5_(*(undefined4 *)(param_1 + 0x18));
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(lVar1 + 8);
  uStack_58 = 0xffffff80ffffffd8;
  puStack_70 = (undefined1 *)register0x00000008;
  ppuStack_68 = &puStack_70;
  puStack_60 = auStack_a0;
  j____S_II_I0IlS_lO_lI_0lSlI_OS_IO50l05ISI00I5_0IIlOS5_(param_1,param_2,param_3,&puStack_70);
  return;
}


/* EXPORT index=51 ELF_VA=0xe464 size=40 source_sha256=f135fbd38244321710457c68d581eced28d9aba6229efa1e53cf37cf2687e7dc */

bool j___IlSII_IIlIl_OI0SO__0lI__l05O5_I0I5I5_I0__S0_0_lS5_(long *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x6b8))();
  return iVar1 == 0;
}


/* EXPORT index=52 ELF_VA=0xe48c size=980 source_sha256=f47d8de964c1884dd350cb08dbe414dd6ef68ad4c5d41cbc0cf443f2ae6336b0 */

void j___0_III__0Il____IOI_O_IIl__IS_l_I550IO0OI_5IIOlIIS5_
               (long *param_1,char *param_2,long param_3)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  size_t __size;
  
  if (param_2 != (char *)0x0) {
    sVar3 = strlen(param_2);
    __size = (long)((sVar3 << 0x20) + 0x100000000) >> 0x20;
    pcVar4 = malloc(__size);
    DAT_0018e0e8 = pcVar4;
    memset(pcVar4,0,__size);
    strncpy(pcVar4,param_2,(long)(int)sVar3);
  }
  FUN_0010e894(param_1);
  bVar1 = true;
  DAT_0018e7b8 = FUN_00115b4c;
  DAT_0018e7a8 = &DAT_00174068;
  DAT_0018e7b0 = "([Ljava/lang/Object;)V";
  DAT_0018e7d0 = FUN_00115b74;
  DAT_0018e7c0 = &DAT_00174082;
  DAT_0018e7c8 = &DAT_00174085;
  DAT_0018e7e8 = FUN_00115ba0;
  iVar2 = 0x106d;
  DAT_0018e7d8 = &DAT_0017409c;
  iVar5 = 9;
  DAT_0018e7e0 = "([Ljava/lang/Object;)Ljava/lang/Object;";
  DAT_0018e800 = FUN_00115bcc;
  DAT_0018e7f0 = &DAT_001740c7;
  DAT_0018e7f8 = "([Ljava/lang/Object;)S";
  DAT_0018e818 = FUN_00115bf8;
  DAT_0018e808 = &DAT_001740e1;
  DAT_0018e810 = "([Ljava/lang/Object;)C";
  DAT_0018e830 = FUN_00115c24;
  DAT_0018e820 = &DAT_001740fb;
  DAT_0018e828 = "([Ljava/lang/Object;)B";
  DAT_0018e848 = FUN_00115c50;
  DAT_0018e838 = &DAT_00174115;
  DAT_0018e840 = "([Ljava/lang/Object;)J";
  DAT_0018e860 = FUN_00115c7c;
  DAT_0018e850 = &DAT_0017412f;
  DAT_0018e858 = "([Ljava/lang/Object;)Z";
  DAT_0018e878 = FUN_00115ca8;
  DAT_0018e868 = &DAT_00174149;
  DAT_0018e870 = "([Ljava/lang/Object;)F";
  DAT_0018e890 = FUN_00115cd4;
  DAT_0018e880 = &DAT_00174163;
  DAT_0018e888 = "([Ljava/lang/Object;)D";
  pcVar4 = "com/fort/andjni/JniLib";
  if (DAT_0018e0e8 != (char *)0x0) {
    pcVar4 = DAT_0018e0e8;
  }
  do {
    iVar6 = 0xb;
    switch(iVar5) {
    case 0:
    case 1:
    case 10:
    case 0xc:
      return;
    case 2:
      iVar5 = iVar2 + ((uint)(iVar2 * 0xdd68) >> 0x15) * -0x25;
      if (param_3 == 0) {
        param_3 = 0;
        iVar5 = 0xb - iVar5;
      }
      else {
        iVar5 = 6 - iVar5;
      }
      break;
    case 3:
      iVar5 = 7;
      if (!bVar1) {
        iVar5 = 1;
      }
      break;
    case 4:
      iVar5 = 0x96;
      if (!bVar1) {
        iVar5 = 0x8e;
      }
      iVar2 = iVar2 + ((uint)(iVar2 * 0xb50a) >> 0x17) * -0xb5;
      iVar5 = iVar5 - iVar2;
      iVar2 = 0x3d0 - iVar2;
      break;
    case 5:
      iVar2 = (**(code **)(*param_1 + 0x6b8))(param_1,param_3,&DAT_0018e7a8,10);
      iVar5 = 3;
      if (iVar2 == 0) {
        iVar5 = 4;
      }
      iVar2 = 0x2ad;
      break;
    case 6:
      param_3 = (**(code **)(*param_1 + 0x30))(param_1,pcVar4);
      iVar5 = 0;
      bVar1 = true;
      break;
    case 7:
      (**(code **)(*param_1 + 0xb8))(param_1,param_3);
      iVar5 = 1;
      break;
    case 8:
      (**(code **)(*param_1 + 0xb8))(param_1,param_3);
      iVar5 = (0x11 - iVar2) + ((uint)(iVar2 * 0xd795) >> 0x14) * 0x13;
      break;
    case 9:
      bVar1 = false;
      if (param_3 != 0) {
        iVar6 = 2;
      }
      iVar2 = 0x73b;
      iVar5 = iVar6;
      break;
    case 0xb:
      iVar2 = iVar2 + ((uint)(iVar2 * 0xf48a) >> 0x16) * -0x43;
      param_3 = (**(code **)(*param_1 + 0x30))(param_1,pcVar4);
      iVar5 = 0x2c - iVar2;
      iVar2 = 0xa6e - iVar2;
      bVar1 = true;
    }
  } while( true );
}


/* EXPORT index=53 ELF_VA=0x16614 size=124 source_sha256=a92f052ec7251fe44cb9b57f8f7e1cd0f44237270e7f3958b0759c388e4b9bfd */

/* _JNIEnv::CallIntMethod(_jobject*, _jmethodID*, ...) */

void _JNIEnv::CallIntMethod(_jobject *param_1,_jmethodID *param_2,...)

{
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined1 auStack_90 [8];
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined1 *puStack_60;
  undefined1 **ppuStack_58;
  undefined1 *puStack_50;
  undefined8 uStack_48;
  
  puStack_50 = auStack_90;
  ppuStack_58 = &puStack_60;
  uStack_48 = 0xffffff80ffffffd8;
  uStack_88 = in_x3;
  uStack_80 = in_x4;
  uStack_78 = in_x5;
  uStack_70 = in_x6;
  uStack_68 = in_x7;
  puStack_60 = (undefined1 *)register0x00000008;
  (**(code **)(*(long *)param_1 + 400))();
  return;
}


/* EXPORT index=54 ELF_VA=0x16690 size=124 source_sha256=ba708a0f7e53dfa4877245f614d685373df32ea3860ea10ba5c5c78bd289f440 */

/* _JNIEnv::CallBooleanMethod(_jobject*, _jmethodID*, ...) */

void _JNIEnv::CallBooleanMethod(_jobject *param_1,_jmethodID *param_2,...)

{
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined1 auStack_90 [8];
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined1 *puStack_60;
  undefined1 **ppuStack_58;
  undefined1 *puStack_50;
  undefined8 uStack_48;
  
  puStack_50 = auStack_90;
  ppuStack_58 = &puStack_60;
  uStack_48 = 0xffffff80ffffffd8;
  uStack_88 = in_x3;
  uStack_80 = in_x4;
  uStack_78 = in_x5;
  uStack_70 = in_x6;
  uStack_68 = in_x7;
  puStack_60 = (undefined1 *)register0x00000008;
  (**(code **)(*(long *)param_1 + 0x130))();
  return;
}


/* EXPORT index=55 ELF_VA=0x1670c size=124 source_sha256=4b835c4873ef176d3e64620ae360e80088da75dc25e0cb3f75191d979a861156 */

/* _JNIEnv::CallCharMethod(_jobject*, _jmethodID*, ...) */

void _JNIEnv::CallCharMethod(_jobject *param_1,_jmethodID *param_2,...)

{
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined1 auStack_90 [8];
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined1 *puStack_60;
  undefined1 **ppuStack_58;
  undefined1 *puStack_50;
  undefined8 uStack_48;
  
  puStack_50 = auStack_90;
  ppuStack_58 = &puStack_60;
  uStack_48 = 0xffffff80ffffffd8;
  uStack_88 = in_x3;
  uStack_80 = in_x4;
  uStack_78 = in_x5;
  uStack_70 = in_x6;
  uStack_68 = in_x7;
  puStack_60 = (undefined1 *)register0x00000008;
  (**(code **)(*(long *)param_1 + 0x160))();
  return;
}


/* EXPORT index=56 ELF_VA=0x16788 size=124 source_sha256=2b59c4e9bd53263983cf0bcfac53086110d739891964707367dd6286a2f8f4a5 */

/* _JNIEnv::CallDoubleMethod(_jobject*, _jmethodID*, ...) */

void _JNIEnv::CallDoubleMethod(_jobject *param_1,_jmethodID *param_2,...)

{
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined1 auStack_90 [8];
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined1 *puStack_60;
  undefined1 **ppuStack_58;
  undefined1 *puStack_50;
  undefined8 uStack_48;
  
  puStack_50 = auStack_90;
  ppuStack_58 = &puStack_60;
  uStack_48 = 0xffffff80ffffffd8;
  uStack_88 = in_x3;
  uStack_80 = in_x4;
  uStack_78 = in_x5;
  uStack_70 = in_x6;
  uStack_68 = in_x7;
  puStack_60 = (undefined1 *)register0x00000008;
  (**(code **)(*(long *)param_1 + 0x1d8))();
  return;
}


/* EXPORT index=57 ELF_VA=0x16804 size=124 source_sha256=db3ca3a5d53342172365c347d2c3eab41eb91ca54bc1ab82bc64b40110c0aa21 */

/* _JNIEnv::CallLongMethod(_jobject*, _jmethodID*, ...) */

void _JNIEnv::CallLongMethod(_jobject *param_1,_jmethodID *param_2,...)

{
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined1 auStack_90 [8];
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined1 *puStack_60;
  undefined1 **ppuStack_58;
  undefined1 *puStack_50;
  undefined8 uStack_48;
  
  puStack_50 = auStack_90;
  ppuStack_58 = &puStack_60;
  uStack_48 = 0xffffff80ffffffd8;
  uStack_88 = in_x3;
  uStack_80 = in_x4;
  uStack_78 = in_x5;
  uStack_70 = in_x6;
  uStack_68 = in_x7;
  puStack_60 = (undefined1 *)register0x00000008;
  (**(code **)(*(long *)param_1 + 0x1a8))();
  return;
}


/* EXPORT index=58 ELF_VA=0x16880 size=124 source_sha256=21b88b7b4b3af06de865afd2b7d3cd1f937cd05effb72d296153684ba14a3ef7 */

/* _JNIEnv::CallFloatMethod(_jobject*, _jmethodID*, ...) */

void _JNIEnv::CallFloatMethod(_jobject *param_1,_jmethodID *param_2,...)

{
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined1 auStack_90 [8];
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined1 *puStack_60;
  undefined1 **ppuStack_58;
  undefined1 *puStack_50;
  undefined8 uStack_48;
  
  puStack_50 = auStack_90;
  ppuStack_58 = &puStack_60;
  uStack_48 = 0xffffff80ffffffd8;
  uStack_88 = in_x3;
  uStack_80 = in_x4;
  uStack_78 = in_x5;
  uStack_70 = in_x6;
  uStack_68 = in_x7;
  puStack_60 = (undefined1 *)register0x00000008;
  (**(code **)(*(long *)param_1 + 0x1c0))();
  return;
}


/* EXPORT index=59 ELF_VA=0x16f78 size=1304 source_sha256=1886be1540615b787a5756c570bf6451aff2b82fa4ef2a407adb04335d09b9b5 */

/* WARNING: Control flow encountered bad instruction data */

void j___OIIII_lI50S_ll_O__5l5_l__I5II5l_I_OOIIIlI__lIOIS5_(void)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  void *pvVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  ulong unaff_x23;
  int iVar9;
  ulong unaff_x24;
  ulong uVar10;
  int *piStack_c8;
  int *piStack_c0;
  int *piStack_b8;
  int iStack_b0;
  int iStack_ac;
  uint uStack_a8;
  int iStack_a4;
  int iStack_a0;
  undefined4 uStack_9c;
  uint uStack_98;
  uint uStack_94;
  undefined4 uStack_90;
  int iStack_8c;
  undefined1 auStack_88 [8];
  long lStack_80;
  int iStack_68;
  undefined4 uStack_64;
  
  uStack_64 = 0;
  iStack_68 = 0;
  uVar3 = j_____OIl_0_II__l5OO__II0IO_IO____II_l5_5l5_0l0lIlIS5_();
  iVar7 = 0x1531;
  iVar5 = 2;
  iStack_b0 = (int)&iStack_a4;
  piStack_c8 = &iStack_a4;
  piStack_c0 = &iStack_a4;
  piStack_b8 = &iStack_a4;
  do {
    iVar8 = (int)unaff_x23;
    iVar9 = (int)unaff_x24;
    switch(iVar5) {
    case 0:
      j___5I5IO_I0__I_5IlI5_5OSSI_I0Il_OIlI_55SS_l0I_ISIOS5_(auStack_88,&uStack_a8);
      j___5I5IO_I0__I_5IlI5_5OSSI_I0Il_OIlI_55SS_l0I_ISIOS5_(auStack_88,&iStack_ac);
      piStack_b8[uStack_a8] = uStack_a8;
      piStack_c0[uStack_a8] = iStack_ac;
      iVar5 = (0xa4 - iVar7) + ((uint)(iVar7 * 0xc908) >> 0x17) * 0xa3;
      break;
    case 1:
      iVar5 = 0x13;
      if (iStack_68 < 0) {
        func_0x0301c6f4();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      break;
    case 2:
      j____OIII_llIO__Ill50_IllIO_I_O0I5llllIIlIIlI5lO00IS5_(auStack_88,uVar3,FUN_001174e4,0);
      j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&iStack_8c);
      DAT_0018e8a0 = iStack_8c;
      DAT_0018e8a8 = malloc((long)iStack_8c << 3);
      unaff_x24 = 0;
      iVar5 = 0xd;
      break;
    case 3:
      unaff_x23 = (ulong)(iVar8 + 1);
      iVar5 = 6;
      break;
    case 4:
      pvVar4 = malloc(0x18);
      uVar10 = -(unaff_x23 >> 0x1f & 1) & 0xfffffff800000000 | (unaff_x23 & 0xffffffff) << 3;
      *(void **)((long)DAT_0018e8b0 + uVar10) = pvVar4;
      j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&uStack_9c);
      **(undefined4 **)((long)DAT_0018e8b0 + uVar10) = uStack_9c;
      j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&iStack_a0);
      j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&iStack_a4);
      uVar10 = -(ulong)(iStack_a4 + 1U >> 0x1f) & 0xfffffffc00000000 | (ulong)(iStack_a4 + 1U) << 2;
      piStack_b8 = malloc(uVar10);
      piStack_c0 = malloc(uVar10);
      iVar5 = 10;
      break;
    case 5:
      iVar7 = iVar7 + ((uint)(iVar7 * 0x9d8a) >> 0x13) * -0xd;
      iVar5 = 0;
      if (iStack_a0 <= iStack_b0) {
        iVar5 = 0xe;
      }
      iVar5 = iVar5 - iVar7;
      iVar7 = 0x3c8 - iVar7;
      break;
    case 6:
      unaff_x24 = (ulong)(iVar9 + 1);
      iVar5 = 0xd;
      break;
    case 7:
      unaff_x23 = (ulong)(iVar8 + 1);
      iVar5 = 0x11;
      break;
    case 8:
      DAT_0018e8b0 = malloc((long)DAT_0018e8a0 << 3);
      unaff_x23 = 0;
      iVar5 = 4;
      break;
    case 9:
      j___lI50I_5I0_5_I_O0S_llII__I_5Ol_lSI_llOISI5_IO5I5S5_(auStack_88,&uStack_98);
      uVar2 = uStack_98;
      uVar10 = (ulong)uStack_98;
      uVar1 = uStack_98 + 1;
      pvVar4 = malloc((ulong)uVar1);
      memset(pvVar4,0,(ulong)uVar1);
      uVar1 = DAT_0018e8a4;
      memcpy(pvVar4,(void *)(lStack_80 + (ulong)DAT_0018e8a4),uVar10);
      DAT_0018e8a4 = uVar1 + uVar2;
      *(void **)(*(long *)((long)DAT_0018e8a8 + (long)iVar9 * 8) + 0x20) = pvVar4;
      iVar5 = 6;
      break;
    case 10:
      iStack_b0 = 0;
      iVar7 = 0x4bb7;
      iVar5 = 5;
      break;
    case 0xb:
      iStack_b0 = iStack_b0 + 1;
      iVar7 = 0xa9;
      iVar5 = 5;
      break;
    case 0xc:
      j___Il0_5_SII_I_O05I5_II_0___I0IlOIlI5__IIl__II5IllS5_(auStack_88,piStack_c8,uStack_94);
      uVar10 = -(unaff_x24 >> 0x1f & 1) & 0xfffffff800000000 | (unaff_x24 & 0xffffffff) << 3;
      *(int **)(*(long *)((long)DAT_0018e8a8 + uVar10) + 8) = piStack_c8;
      lVar6 = *(long *)((long)DAT_0018e8a8 + uVar10);
      *(uint *)(lVar6 + 4) = uStack_94;
      j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,lVar6 + 0x10);
      j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_
                (auStack_88,*(long *)((long)DAT_0018e8a8 + uVar10) + 0x14);
      j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_
                (auStack_88,*(long *)((long)DAT_0018e8a8 + uVar10) + 0x18);
      j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_
                (auStack_88,*(long *)((long)DAT_0018e8a8 + uVar10) + 0x1c);
      iVar5 = 9;
      break;
    case 0xd:
      iVar5 = 0x12;
      if (iStack_8c <= iVar9) {
        iVar5 = 1;
      }
      break;
    case 0xe:
      uVar10 = -(unaff_x23 >> 0x1f & 1) & 0xfffffff800000000 | (unaff_x23 & 0xffffffff) << 3;
      lVar6 = *(long *)((long)DAT_0018e8b0 + uVar10);
      *(int *)(lVar6 + 4) = iStack_a0;
      *(int **)(lVar6 + 8) = piStack_b8;
      *(int **)(*(long *)((long)DAT_0018e8b0 + uVar10) + 0x10) = piStack_c0;
      iVar5 = 7;
      break;
    case 0xf:
      unaff_x23 = (ulong)(iVar8 + 1);
      iVar5 = 0xe;
      break;
    case 0x10:
      j____OIII_llIO__Ill50_IllIO_I_O0I5llllIIlIIlI5lO00IS5_(auStack_88,uVar3,FUN_001174e4,0);
      j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&iStack_8c);
      DAT_0018e8a0 = iStack_8c;
      DAT_0018e8a8 = malloc((long)iStack_8c << 3);
      unaff_x24 = 0;
      iVar5 = 0x10;
      break;
    case 0x11:
      iVar5 = 4;
      if (iStack_8c <= iVar8) {
        iVar5 = 0x14;
      }
      break;
    case 0x12:
      pvVar4 = malloc(0x28);
      uVar10 = -(unaff_x24 >> 0x1f & 1) & 0xfffffff800000000 | (unaff_x24 & 0xffffffff) << 3;
      *(void **)((long)DAT_0018e8a8 + uVar10) = pvVar4;
      j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(auStack_88,&uStack_90);
      **(undefined4 **)((long)DAT_0018e8a8 + uVar10) = uStack_90;
      uStack_94 = 0;
      j___O_5Ol_ISIO0_0O_lS_I5_SO__IIIl5I_I0O5I0SlIS5I5IIS5_(auStack_88,&uStack_94);
      piStack_c8 = malloc((ulong)uStack_94);
      iVar5 = 0xc;
      break;
    case 0x13:
      DAT_0018e8b0 = malloc((long)DAT_0018e8a0 << 3);
      unaff_x23 = 0;
      iVar5 = 0x11;
      break;
    case 0x14:
      return;
    }
  } while( true );
}


/* EXPORT index=60 ELF_VA=0x17530 size=20 source_sha256=992e0bda0616090d81be1b4a734f409661fd7892d4efd4fcee43c416234ff659 */

undefined8 j___lII00_IOOlS__SS0I_OS_0__OISl55II0lOSIlI0IIIISS0S5_(int param_1)

{
  return *(undefined8 *)(DAT_0018e8a8 + (long)param_1 * 8);
}


/* EXPORT index=61 ELF_VA=0x17544 size=20 source_sha256=cd3220d7ed2e963c9120b1b05c9273d74b72ce618631ebfb756f92b74ccd0d54 */

undefined8 j___l5_00_llII0_5llSl_l_IOl__I05l__ISS5I0_I_S_SIl00S5_(int param_1)

{
  return *(undefined8 *)(DAT_0018e8b0 + (long)param_1 * 8);
}


/* EXPORT index=62 ELF_VA=0x17558 size=16 source_sha256=98f0deec525eb0fa11a1b99221b96340007a23c9f9b42111a61ba71b42f37d20 */

void j____OIII_llIO__Ill50_IllIO_I_O0I5llllIIlIIlI5lO00IS5_
               (undefined1 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  *param_1 = 0;
  *(undefined8 *)(param_1 + 8) = param_2;
  *(undefined8 *)(param_1 + 0x10) = param_3;
  *(undefined8 *)(param_1 + 0x18) = param_4;
  return;
}


/* EXPORT index=63 ELF_VA=0x17568 size=8 source_sha256=f802728c0ea55a9aa26417b52371e0395754efffa1e070034864aa39e6dc4ec6 */

undefined8 j___Sl0Ol_l0_ll_lII_l_l0I_5_IIOIS5Ill0I_I05I_I___IIS5_(void)

{
  return 0xe;
}


/* EXPORT index=64 ELF_VA=0x17570 size=8 source_sha256=94152e462f3e98d8d99662739e87c91ff06eb16d5afefc0047346c214bd99ac8 */

undefined8 j___550l0__l__0_0IOSI_5OI_l_I00l__OO5I_SIISIlIl00I_S5_(void)

{
  return 5;
}


/* EXPORT index=65 ELF_VA=0x17578 size=12 source_sha256=b26504160255da1c698d8243d4b0d93d630011f5967911231818ed97850ec775 */

undefined * j___O0IO0_Il_0S_Il0I0_5_Il5_llIII5_l_I_ll_5II0_S__IS5_(void)

{
  return &DAT_00174e44;
}


/* EXPORT index=66 ELF_VA=0x17584 size=112 source_sha256=1b038fa297e754bc2ad6ab2bb4effb3c112886f0fbf90ae1ba03beb21166c7ee */

undefined4 j___l5II5_5IISl_IO_____S0II_OS_S5_0ISSOOl5I___5llI5S5_(undefined1 *param_1,char param_2)

{
  long lVar1;
  undefined1 uVar2;
  char cStack_21;
  
  if (param_2 < '\0') {
    uVar2 = 5;
  }
  else {
    cStack_21 = param_2;
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&cStack_21,1);
    if (lVar1 == 1) {
      return 1;
    }
    uVar2 = 6;
  }
  *param_1 = uVar2;
  return 0;
}


/* EXPORT index=67 ELF_VA=0x175f4 size=112 source_sha256=226552172329633b2672eb0f2b4041fd3609afb40f566713372f91addc0bcff6 */

undefined4 j___I0III_OIS_S_O_IIl_I00lS_5OIlI__Ol0l5ISlI_IIl0IIS5_(undefined1 *param_1,byte param_2)

{
  long lVar1;
  undefined1 uVar2;
  byte bStack_21;
  
  if (param_2 < 0xe0) {
    uVar2 = 5;
  }
  else {
    bStack_21 = param_2;
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&bStack_21,1);
    if (lVar1 == 1) {
      return 1;
    }
    uVar2 = 6;
  }
  *param_1 = uVar2;
  return 0;
}


/* EXPORT index=68 ELF_VA=0x17664 size=232 source_sha256=186b689dd6428452db241d8cc064a8034cdc6f08b61ee9db4e5343237bd759a0 */

undefined4 j___lII5l_IlSSl_0SI_I___I0I_5_IIl__0__5ISSIIO5__I50S5_(undefined1 *param_1,byte param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  byte *pbVar4;
  undefined1 uVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  byte bStack_22;
  byte bStack_21;
  
  uVar7 = 6;
  if (param_2 < 0xe0) {
    uVar7 = 1;
  }
  uVar2 = 5;
  uVar1 = 0;
  if ((char)param_2 < '\0') {
    uVar1 = 3;
  }
switchD_001176cc_caseD_3:
  uVar8 = uVar2;
  uVar2 = uVar7;
  switch(uVar8) {
  default:
    goto switchD_001176cc_caseD_2;
  case 3:
    goto switchD_001176cc_caseD_3;
  case 5:
    break;
  case 6:
    if (0xdf < param_2) {
      pcVar6 = *(code **)(param_1 + 0x18);
      pbVar4 = &bStack_21;
      bStack_21 = param_2;
      goto LAB_001176e8;
    }
  case 1:
    uVar5 = 5;
LAB_00117734:
    *param_1 = uVar5;
    return 0;
  }
  uVar2 = uVar1;
  if (-1 < (char)param_2) {
    pcVar6 = *(code **)(param_1 + 0x18);
    pbVar4 = &bStack_22;
    bStack_22 = param_2;
LAB_001176e8:
    lVar3 = (*pcVar6)(param_1,pbVar4,1);
    if (lVar3 == 1) {
      return 1;
    }
    uVar5 = 6;
    goto LAB_00117734;
  }
  goto switchD_001176cc_caseD_3;
switchD_001176cc_caseD_2:
  do {
  } while( true );
}


/* EXPORT index=69 ELF_VA=0x17764 size=116 source_sha256=46d8d1a2a88e24b87435aeda08fd2e5b3601d6e42b54e8c8abc20f94c2251281 */

bool j___ll5I0_O05_O_II0ll_S0OO5__S0I0_ll5IS000IIO0SI0S_S5_(undefined1 *param_1,undefined1 param_2)

{
  bool bVar1;
  long lVar2;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  uStack_21 = 0xd0;
  uStack_22 = param_2;
  lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar2 == 1) {
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_22,1);
    bVar1 = lVar2 != 0;
  }
  else {
    bVar1 = false;
    *param_1 = 8;
  }
  return bVar1;
}


/* EXPORT index=70 ELF_VA=0x177d8 size=132 source_sha256=d5f2bd9bccd8b047ec3e50d370df4d9f6db76df2b62dd11ccd79f1cc2f3027ca */

bool j____50___l_S_5_S_lSI_O0_OO_ISl_5OSS_I55I_55llSI0OSS5_(undefined1 *param_1,uint param_2)

{
  bool bVar1;
  long lVar2;
  ushort uStack_24;
  undefined1 uStack_21;
  
  uStack_24 = (ushort)param_2;
  uStack_21 = 0xd1;
  lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar2 == 1) {
    uStack_24 = (ushort)(param_2 >> 8) & 0xff | (ushort)((param_2 & 0xff00ff) << 8);
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_24,2);
    bVar1 = lVar2 != 0;
  }
  else {
    bVar1 = false;
    *param_1 = 8;
  }
  return bVar1;
}


/* EXPORT index=71 ELF_VA=0x1785c size=128 source_sha256=af762dfad338b223a85b3cc5b9c7fa28034c21b65ae586af07cc72dc882ddb91 */

bool j___IIIS__S_I00_55l___IlI___I0ll_5l_I5S5IIl00Ol__I_S5_(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  long lVar3;
  uint uStack_28;
  undefined1 uStack_21;
  
  uStack_21 = 0xd2;
  uStack_28 = param_2;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar3 == 1) {
    uVar1 = (param_2 & 0xff00ff00) >> 8 | (param_2 & 0xff00ff) << 8;
    uStack_28 = uVar1 >> 0x10 | uVar1 << 0x10;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_28,4);
    bVar2 = lVar3 != 0;
  }
  else {
    bVar2 = false;
    *param_1 = 8;
  }
  return bVar2;
}


/* EXPORT index=72 ELF_VA=0x178dc size=128 source_sha256=5c0a9851272ccf035c22160a5267a8026256d1f699c1eb592b400f799b30049a */

bool j___lOIOS__I5l__IIISS__llSl_Illl5_I0_5__0_III0III_lS5_(undefined1 *param_1,ulong param_2)

{
  ulong uVar1;
  bool bVar2;
  long lVar3;
  ulong uStack_30;
  undefined1 uStack_21;
  
  uStack_21 = 0xd3;
  uStack_30 = param_2;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar3 == 1) {
    uVar1 = (param_2 & 0xff00ff00ff00ff00) >> 8 | (param_2 & 0xff00ff00ff00ff) << 8;
    uVar1 = (uVar1 & 0xffff0000ffff0000) >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10;
    uStack_30 = uVar1 >> 0x20 | uVar1 << 0x20;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_30,8);
    bVar2 = lVar3 != 0;
  }
  else {
    bVar2 = false;
    *param_1 = 8;
  }
  return bVar2;
}


/* EXPORT index=73 ELF_VA=0x1795c size=848 source_sha256=9f3fd4e2fdd02a91708355c04865b85c762c98f5ac1ffa40b614d6469d84723d */

/* WARNING: Control flow encountered bad instruction data */

ulong j___lSISI__lI50_5O5IO_IO_II__IIlI5llllI_505I0_I_IlSS5_(undefined1 *param_1,ulong param_2)

{
  undefined1 uVar1;
  ulong uVar2;
  long lVar3;
  ulong *puVar4;
  undefined8 uVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint unaff_w21;
  int iStack_54;
  undefined1 uStack_49;
  ushort uStack_48;
  undefined1 uStack_45;
  uint uStack_44;
  ulong uStack_40;
  undefined1 uStack_31;
  
  iVar9 = 5;
  uVar6 = 0x36f6;
  iStack_54 = 5;
  iVar8 = 4;
  if ((long)param_2 < 0) {
    iVar8 = 1;
  }
  do {
    uVar10 = (uint)param_2;
    uVar1 = (undefined1)param_2;
    switch(iVar9) {
    case 0:
      uStack_31 = 0xd3;
      uStack_40 = param_2;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_31,1);
      if (lVar3 == 1) {
        uVar2 = (param_2 & 0xff00ff00ff00ff00) >> 8 | (param_2 & 0xff00ff00ff00ff) << 8;
        uVar2 = (uVar2 & 0xffff0000ffff0000) >> 0x10 | (uVar2 & 0xffff0000ffff) << 0x10;
        uStack_40 = uVar2 >> 0x20 | uVar2 << 0x20;
        pcVar7 = *(code **)(param_1 + 0x18);
        puVar4 = &uStack_40;
        uVar5 = 8;
LAB_00117c64:
        lVar3 = (*pcVar7)(param_1,puVar4,uVar5);
        unaff_w21 = (uint)(lVar3 != 0);
      }
      else {
LAB_00117c78:
        unaff_w21 = 0;
        *param_1 = 8;
      }
switchD_001179e4_caseD_e:
      return (ulong)(unaff_w21 & 1);
    case 1:
      if ((long)param_2 < -0x20) {
        iStack_54 = 0x13 - uVar6 % 0x65;
        iVar9 = iStack_54;
      }
      else {
        iStack_54 = 0x16 - uVar6 % 0x65;
        iVar9 = iStack_54;
      }
      break;
    case 2:
      uStack_31 = 0xd0;
      uStack_45 = uVar1;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_31,1);
      if (lVar3 != 1) goto LAB_00117c78;
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = (ulong *)&uStack_45;
      uVar5 = 1;
      goto LAB_00117c64;
    case 3:
      uStack_31 = 0xd2;
      uStack_44 = uVar10;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_31,1);
      if (lVar3 != 1) goto LAB_00117c78;
      uVar6 = (uVar10 & 0xff00ff00) >> 8 | (uVar10 & 0xff00ff) << 8;
      uStack_44 = uVar6 >> 0x10 | uVar6 << 0x10;
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = (ulong *)&uStack_44;
      uVar5 = 4;
      goto LAB_00117c64;
    case 4:
      uVar2 = j___Il5lI_l_IOI_Sl5l___Ol_l_5_II0_OSIlII5_OI_IlI_50S5_(param_1,param_2);
      return uVar2;
    case 5:
      uVar6 = 0x64a8;
      iStack_54 = iVar8;
      iVar9 = iVar8;
      break;
    case 6:
      if ((long)param_2 < -0x80) {
        iStack_54 = 10;
        iVar9 = 10;
      }
      else {
        iStack_54 = 2;
        iVar9 = 2;
      }
      break;
    case 7:
      if ((long)param_2 < -0x80000000) {
        iStack_54 = 0;
        iVar9 = 0;
      }
      else {
        iStack_54 = 3;
        iVar9 = 3;
      }
      break;
    case 8:
      uStack_31 = 0xd0;
      uStack_49 = uVar1;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_31,1);
      if (lVar3 != 1) goto LAB_00117c78;
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = (ulong *)&uStack_49;
      uVar5 = 1;
      goto LAB_00117c64;
    case 9:
      if ((uVar10 & 0xff) < 0xe0) {
        unaff_w21 = 0;
        *param_1 = 5;
      }
      else {
        unaff_w21 = 1;
        uStack_31 = uVar1;
        lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_31,1);
        if (lVar3 != 1) {
          unaff_w21 = 0;
          *param_1 = 6;
        }
      }
      goto switchD_001179e4_caseD_e;
    case 10:
      if ((long)param_2 < -0x8000) {
        iStack_54 = 0xd;
        iVar9 = 0xd;
      }
      else {
        iStack_54 = 0xb;
        iVar9 = 0xb;
      }
      break;
    case 0xb:
      iStack_54 = 0xc;
      iVar9 = 0xc;
      break;
    case 0xc:
      uStack_48 = (ushort)param_2;
      uStack_31 = 0xd1;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_31,1);
      if (lVar3 != 1) goto LAB_00117c78;
      uStack_48 = (ushort)(param_2 >> 8) & 0xff | (ushort)((uVar10 & 0xff00ff) << 8);
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = (ulong *)&uStack_48;
      uVar5 = 2;
      goto LAB_00117c64;
    case 0xd:
      if (iStack_54 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      iStack_54 = 7;
      iVar9 = 7;
      break;
    case 0xe:
      goto switchD_001179e4_caseD_e;
    }
  } while( true );
}


/* EXPORT index=74 ELF_VA=0x17ce8 size=564 source_sha256=4b79221240ad8d2eae5b3e9d68d4b0e5730e520da09de9b66e7b07e84968f56d */

bool j___Il5lI_l_IOI_Sl5l___Ol_l_5_II0_OSIlII5_OI_IlI_50S5_(undefined1 *param_1,ulong param_2)

{
  ulong uVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  long lVar5;
  ulong *puVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  code *pcVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  char cStack_33;
  ushort uStack_32;
  ulong uStack_30;
  uint uStack_28;
  char cStack_21;
  
  iVar10 = 6;
  if (0xffff < param_2) {
    iVar10 = 3;
  }
  iVar11 = 5;
  if (0x7f < param_2) {
    iVar11 = 10;
  }
  iVar13 = 2;
  if (0xff < param_2) {
    iVar13 = 7;
  }
  iVar3 = 8;
  while( true ) {
    do {
      do {
        do {
          iVar12 = iVar3;
          iVar3 = (uint)(param_2 >> 0x20 == 0) << 2;
        } while (iVar12 == 3);
        uVar14 = (uint)param_2;
        if (iVar12 == 6) {
          uStack_32 = (ushort)param_2;
          cStack_21 = -0x33;
          lVar5 = (**(code **)(param_1 + 0x18))(param_1,&cStack_21,1);
          if (lVar5 != 1) goto LAB_00117ea8;
          uStack_32 = (ushort)(param_2 >> 8) & 0xff | (ushort)((uVar14 & 0xff00ff) << 8);
          pcVar9 = *(code **)(param_1 + 0x18);
          puVar6 = (ulong *)&uStack_32;
          uVar7 = 2;
          goto LAB_00117e54;
        }
        iVar3 = iVar10;
      } while (iVar12 == 7);
      if (iVar12 == 0) {
        cStack_21 = -0x31;
        uStack_30 = param_2;
        lVar5 = (**(code **)(param_1 + 0x18))(param_1,&cStack_21,1);
        if (lVar5 != 1) goto LAB_00117ea8;
        uVar1 = (param_2 & 0xff00ff00ff00ff00) >> 8 | (param_2 & 0xff00ff00ff00ff) << 8;
        uVar1 = (uVar1 & 0xffff0000ffff0000) >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10;
        uStack_30 = uVar1 >> 0x20 | uVar1 << 0x20;
        pcVar9 = *(code **)(param_1 + 0x18);
        puVar6 = &uStack_30;
        uVar7 = 8;
        goto LAB_00117e54;
      }
      if (iVar12 == 4) {
        cStack_21 = -0x32;
        uStack_28 = uVar14;
        lVar5 = (**(code **)(param_1 + 0x18))(param_1,&cStack_21,1);
        if (lVar5 != 1) goto LAB_00117ea8;
        uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
        uStack_28 = uVar14 >> 0x10 | uVar14 << 0x10;
        pcVar9 = *(code **)(param_1 + 0x18);
        puVar6 = (ulong *)&uStack_28;
        uVar7 = 4;
        goto LAB_00117e54;
      }
      iVar3 = iVar11;
    } while (iVar12 == 8);
    cVar2 = (char)param_2;
    if (iVar12 != 10) break;
    iVar3 = iVar13;
    if (param_2 < 0x100) {
      cStack_21 = -0x34;
      cStack_33 = cVar2;
      lVar5 = (**(code **)(param_1 + 0x18))(param_1,&cStack_21,1);
      if (lVar5 == 1) {
        pcVar9 = *(code **)(param_1 + 0x18);
        puVar6 = (ulong *)&cStack_33;
        uVar7 = 1;
LAB_00117e54:
        lVar5 = (*pcVar9)(param_1,puVar6,uVar7);
        bVar4 = lVar5 != 0;
      }
      else {
LAB_00117ea8:
        uVar8 = 8;
LAB_00117eb0:
        bVar4 = false;
        *param_1 = uVar8;
      }
      return bVar4;
    }
  }
  if (iVar12 != 5) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (cVar2 < '\0') {
    uVar8 = 5;
  }
  else {
    cStack_21 = cVar2;
    lVar5 = (**(code **)(param_1 + 0x18))(param_1,&cStack_21,1);
    if (lVar5 == 1) {
      return true;
    }
    uVar8 = 6;
  }
  goto LAB_00117eb0;
}


/* EXPORT index=75 ELF_VA=0x17f1c size=112 source_sha256=1b038fa297e754bc2ad6ab2bb4effb3c112886f0fbf90ae1ba03beb21166c7ee */

undefined4 j___IllIl_OIOII__I_lI_IlIl5_llOI5l0_lIlIO5OSlIl_IlOS5_(undefined1 *param_1,char param_2)

{
  long lVar1;
  undefined1 uVar2;
  char cStack_21;
  
  if (param_2 < '\0') {
    uVar2 = 5;
  }
  else {
    cStack_21 = param_2;
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&cStack_21,1);
    if (lVar1 == 1) {
      return 1;
    }
    uVar2 = 6;
  }
  *param_1 = uVar2;
  return 0;
}


/* EXPORT index=76 ELF_VA=0x17f8c size=116 source_sha256=1f27b41d6ccb4a8293523e0940899a4599c63f4d5eca8248c4a7b416cec286da */

bool j___SIOSl_Ol0I0_SIOI__O_lI__I5_IlO5_I05550I_0O505IlS5_(undefined1 *param_1,undefined1 param_2)

{
  bool bVar1;
  long lVar2;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  uStack_21 = 0xcc;
  uStack_22 = param_2;
  lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar2 == 1) {
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_22,1);
    bVar1 = lVar2 != 0;
  }
  else {
    bVar1 = false;
    *param_1 = 8;
  }
  return bVar1;
}


/* EXPORT index=77 ELF_VA=0x18000 size=132 source_sha256=00068ebb68841f76c8fec8e58eb214606843bddee3e1fd9b2a3592c302301977 */

bool j____I0II_I0O0l_IlIII_IlS_I_l5l0Sl0S0_IOIlSI_ISS_0IS5_(undefined1 *param_1,uint param_2)

{
  bool bVar1;
  long lVar2;
  ushort uStack_24;
  undefined1 uStack_21;
  
  uStack_24 = (ushort)param_2;
  uStack_21 = 0xcd;
  lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar2 == 1) {
    uStack_24 = (ushort)(param_2 >> 8) & 0xff | (ushort)((param_2 & 0xff00ff) << 8);
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_24,2);
    bVar1 = lVar2 != 0;
  }
  else {
    bVar1 = false;
    *param_1 = 8;
  }
  return bVar1;
}


/* EXPORT index=78 ELF_VA=0x18084 size=128 source_sha256=d897ab9337a9f186e190602a3f903543d15d09cd533a26f4090c232dff9a0b9b */

bool j___l00l__IIIIl_I_5_S_I0I00_I5SI_lll0llI____SIIOlOIS5_(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  long lVar3;
  uint uStack_28;
  undefined1 uStack_21;
  
  uStack_21 = 0xce;
  uStack_28 = param_2;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar3 == 1) {
    uVar1 = (param_2 & 0xff00ff00) >> 8 | (param_2 & 0xff00ff) << 8;
    uStack_28 = uVar1 >> 0x10 | uVar1 << 0x10;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_28,4);
    bVar2 = lVar3 != 0;
  }
  else {
    bVar2 = false;
    *param_1 = 8;
  }
  return bVar2;
}


/* EXPORT index=79 ELF_VA=0x18104 size=128 source_sha256=92274a2a288acd2fd8cfb84d98738848ab6c40b4056e161dfd942b14168e9975 */

bool j___0l_5__S0__O__SI_0_IlI_S_I5ll_l_Il_O_I_lI_SO0_llS5_(undefined1 *param_1,ulong param_2)

{
  ulong uVar1;
  bool bVar2;
  long lVar3;
  ulong uStack_30;
  undefined1 uStack_21;
  
  uStack_21 = 0xcf;
  uStack_30 = param_2;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar3 == 1) {
    uVar1 = (param_2 & 0xff00ff00ff00ff00) >> 8 | (param_2 & 0xff00ff00ff00ff) << 8;
    uVar1 = (uVar1 & 0xffff0000ffff0000) >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10;
    uStack_30 = uVar1 >> 0x20 | uVar1 << 0x20;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_30,8);
    bVar2 = lVar3 != 0;
  }
  else {
    bVar2 = false;
    *param_1 = 8;
  }
  return bVar2;
}


/* EXPORT index=80 ELF_VA=0x18184 size=140 source_sha256=7a8c0af727b3b4826bfae8a4946c493e39bbe48fa394f0b991da63271b88d306 */

bool j___l_OI__I_lll_IIOlO_llIll_ISl_Il_S0O_IlSIlI_5l_0_S5_(uint param_1,undefined1 *param_2)

{
  uint uVar1;
  bool bVar2;
  long lVar3;
  uint uStack_38;
  undefined1 uStack_31;
  
  uStack_31 = 0xca;
  uStack_38 = param_1;
  lVar3 = (**(code **)(param_2 + 0x18))(param_2,&uStack_31,1);
  if (lVar3 == 1) {
    uVar1 = (param_1 & 0xff00ff00) >> 8 | (param_1 & 0xff00ff) << 8;
    uStack_38 = uVar1 >> 0x10 | uVar1 << 0x10;
    lVar3 = (**(code **)(param_2 + 0x18))(param_2,&uStack_38,4);
    bVar2 = lVar3 != 0;
  }
  else {
    bVar2 = false;
    *param_2 = 8;
  }
  return bVar2;
}


/* EXPORT index=81 ELF_VA=0x18210 size=140 source_sha256=c83609e55023744fdbb5648dc5af9e38d780635e7da73e3a659c8ce1f4cdd6a9 */

bool j___SlI5I_l_5_5_0IIlI_ISl00_SIII_55SI_SlIlIOOII5I_lS5_(ulong param_1,undefined1 *param_2)

{
  ulong uVar1;
  bool bVar2;
  long lVar3;
  ulong uStack_40;
  undefined1 uStack_31;
  
  uStack_31 = 0xcb;
  uStack_40 = param_1;
  lVar3 = (**(code **)(param_2 + 0x18))(param_2,&uStack_31,1);
  if (lVar3 == 1) {
    uVar1 = (param_1 & 0xff00ff00ff00ff00) >> 8 | (param_1 & 0xff00ff00ff00ff) << 8;
    uVar1 = (uVar1 & 0xffff0000ffff0000) >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10;
    uStack_40 = uVar1 >> 0x20 | uVar1 << 0x20;
    lVar3 = (**(code **)(param_2 + 0x18))(param_2,&uStack_40,8);
    bVar2 = lVar3 != 0;
  }
  else {
    bVar2 = false;
    *param_2 = 8;
  }
  return bVar2;
}


/* EXPORT index=82 ELF_VA=0x1829c size=228 source_sha256=e912af0a0b2bc7150e3cb0b945d1aba77fa21a8f10a2145247a1d4b425e8b739 */

bool j____0II0_OI5_0_5SI_0_SOS____05_llIS_0II0I_ll_l__l0S5_(double param_1,undefined1 *param_2)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  double *pdVar4;
  undefined8 uVar5;
  code *pcVar6;
  float fVar7;
  float fStack_48;
  undefined1 uStack_41;
  double dStack_40;
  undefined1 uStack_31;
  
  fVar7 = (float)param_1;
  if ((double)fVar7 == param_1) {
    uStack_41 = 0xca;
    fStack_48 = fVar7;
    lVar3 = (**(code **)(param_2 + 0x18))(param_2,&uStack_41,1);
    if (lVar3 != 1) {
LAB_00118360:
      *param_2 = 8;
      return false;
    }
    uVar1 = ((uint)fVar7 & 0xff00ff00) >> 8 | ((uint)fVar7 & 0xff00ff) << 8;
    fStack_48 = (float)(uVar1 >> 0x10 | uVar1 << 0x10);
    pcVar6 = *(code **)(param_2 + 0x18);
    pdVar4 = (double *)&fStack_48;
    uVar5 = 4;
  }
  else {
    uStack_31 = 0xcb;
    dStack_40 = param_1;
    lVar3 = (**(code **)(param_2 + 0x18))(param_2,&uStack_31,1);
    if (lVar3 != 1) goto LAB_00118360;
    uVar2 = ((ulong)param_1 & 0xff00ff00ff00ff00) >> 8 | ((ulong)param_1 & 0xff00ff00ff00ff) << 8;
    uVar2 = (uVar2 & 0xffff0000ffff0000) >> 0x10 | (uVar2 & 0xffff0000ffff) << 0x10;
    dStack_40 = (double)(uVar2 >> 0x20 | uVar2 << 0x20);
    pcVar6 = *(code **)(param_2 + 0x18);
    pdVar4 = &dStack_40;
    uVar5 = 8;
  }
  lVar3 = (*pcVar6)(param_2,pdVar4,uVar5);
  return lVar3 != 0;
}


/* EXPORT index=83 ELF_VA=0x18380 size=88 source_sha256=2b31857a0178048035209702e1eb45ea725d3b5719290266eb2eea20a1387bb3 */

bool j___l0_lI__llSl_IS_lI_SOII__Il0IS_lIIl550II5_IIlllIS5_(undefined1 *param_1)

{
  long lVar1;
  undefined1 uStack_21;
  
  uStack_21 = 0xc0;
  lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar1 != 1) {
    *param_1 = 8;
  }
  return lVar1 == 1;
}


/* EXPORT index=84 ELF_VA=0x183d8 size=88 source_sha256=46be905950def3cf8ca4e2b1fe781254bac7cb482de1e3cc95c7fdb001dda2fd */

bool j___S_O___II5IO_S5SlO_llI5I_lOS555lS_IIIO055I0I5SIIS5_(undefined1 *param_1)

{
  long lVar1;
  undefined1 uStack_21;
  
  uStack_21 = 0xc3;
  lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar1 != 1) {
    *param_1 = 8;
  }
  return lVar1 == 1;
}


/* EXPORT index=85 ELF_VA=0x18430 size=88 source_sha256=d86649694a3f429ed354c5cab0010a76e44a67d10744896d83cad2a23144341b */

bool j___S_llI_5SlII_I_lIl_0__O__IS00l_5l0O5ll0S_ISIS_llS5_(undefined1 *param_1)

{
  long lVar1;
  undefined1 uStack_21;
  
  uStack_21 = 0xc2;
  lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar1 != 1) {
    *param_1 = 8;
  }
  return lVar1 == 1;
}


/* EXPORT index=86 ELF_VA=0x18488 size=116 source_sha256=6cc76195acbbc26dfe9bcd45b84abeee6925e8e6e01d9270a64b0335c2dc48c1 */

bool j_____III_50SIS_l0l___l0S_I_Olll0llOIl__IO__IIOSII5S5_(undefined1 *param_1,ulong param_2)

{
  long lVar1;
  undefined1 *puVar2;
  code *pcVar3;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  if ((param_2 & 1) == 0) {
    uStack_21 = 0xc2;
    pcVar3 = *(code **)(param_1 + 0x18);
    puVar2 = &uStack_21;
  }
  else {
    uStack_22 = 0xc3;
    pcVar3 = *(code **)(param_1 + 0x18);
    puVar2 = &uStack_22;
  }
  lVar1 = (*pcVar3)(param_1,puVar2,1);
  if (lVar1 != 1) {
    *param_1 = 8;
  }
  return lVar1 == 1;
}


/* EXPORT index=87 ELF_VA=0x184fc size=120 source_sha256=ffdf3089f57017fa37ccf81562f79e1ea4bf20565c87ffff923ddab07e12fbe7 */

bool j____IlIO_l_5_I__OS_I_I_lIl__l_ll5lOI0IISII0_O05IOIS5_(undefined1 *param_1,char param_2)

{
  long lVar1;
  undefined1 *puVar2;
  code *pcVar3;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  if (param_2 == '\0') {
    uStack_21 = 0xc2;
    pcVar3 = *(code **)(param_1 + 0x18);
    puVar2 = &uStack_21;
  }
  else {
    uStack_22 = 0xc3;
    pcVar3 = *(code **)(param_1 + 0x18);
    puVar2 = &uStack_22;
  }
  lVar1 = (*pcVar3)(param_1,puVar2,1);
  if (lVar1 != 1) {
    *param_1 = 8;
  }
  return lVar1 == 1;
}


/* EXPORT index=88 ELF_VA=0x18574 size=120 source_sha256=295b0fef9186058ce3b1057e533c2dc6b595239a660ed99b3125825f11626752 */

undefined4 j___l__5I_ISSS__l05lI_I_lIO_III__llI_SI50_l5l0_Il_IS5_(undefined1 *param_1,byte param_2)

{
  long lVar1;
  undefined1 uVar2;
  byte bStack_21;
  
  if (param_2 < 0x20) {
    bStack_21 = param_2 | 0xa0;
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&bStack_21,1);
    if (lVar1 == 1) {
      return 1;
    }
    uVar2 = 6;
  }
  else {
    uVar2 = 5;
  }
  *param_1 = uVar2;
  return 0;
}


/* EXPORT index=89 ELF_VA=0x185ec size=344 source_sha256=4fc2d0c3d10e4174f1dcade150be5cf068ced46ab3f3a924e87bef19178a117d */

undefined8
j___lllII_llISI_I_I0l_OlOII_S__00OS_II_5I0__O0ISI0SS5_
          (undefined1 *param_1,undefined8 param_2,byte param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined1 uVar5;
  int iVar6;
  uint uVar7;
  byte bStack_61;
  
  uVar7 = 0x6cde;
  iVar1 = 0;
  if (param_3 != 0) {
    iVar1 = 7;
  }
  iVar3 = 5;
switchD_00118694_caseD_6:
  iVar6 = iVar3;
  uVar2 = uVar7 % 0x89;
  do {
    uVar7 = 0x3e73;
    iVar3 = iVar1;
    switch(iVar6) {
    case 0:
    case 3:
    case 4:
    case 8:
      return 1;
    case 1:
      *param_1 = 10;
      return 0;
    case 2:
      return 0;
    case 5:
      if (param_3 < 0x20) {
        bStack_61 = param_3 | 0xa0;
        lVar4 = (**(code **)(param_1 + 0x18))(param_1,&bStack_61,1);
        iVar6 = 6;
        if (lVar4 == 1) break;
        uVar5 = 6;
      }
      else {
        uVar5 = 5;
      }
      *param_1 = uVar5;
      iVar6 = 2;
      break;
    case 6:
      goto switchD_00118694_caseD_6;
    case 7:
      lVar4 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3);
      iVar6 = 0x60;
      if (lVar4 != 0) {
        iVar6 = 0x62;
      }
      iVar6 = iVar6 - uVar2;
      if (iVar6 == 8) {
        return 1;
      }
      break;
    default:
      goto switchD_00118694_default;
    }
  } while( true );
switchD_00118694_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* EXPORT index=90 ELF_VA=0x18768 size=128 source_sha256=6f322870e008a283e1951f05bb90d4139c5103fd01fc5c7a8fb88444a4c75eb1 */

undefined4
j___OO0___0I05I___0O__ll5lS__SllSO0lI_IO0I_lIlI5IlOS5_(undefined1 *param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 uVar2;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  uStack_21 = 0xd9;
  uStack_22 = param_2;
  lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar1 == 1) {
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_22,1);
    if (lVar1 != 0) {
      return 1;
    }
    uVar2 = 0xf;
  }
  else {
    uVar2 = 8;
  }
  *param_1 = uVar2;
  return 0;
}


/* EXPORT index=91 ELF_VA=0x187e8 size=300 source_sha256=570492661c20f7748efecb3e4dbf41f92cba074fd591298840ff8dcab2036796 */

undefined8
j_____5Il_I55II_0_l5I_5l5_I_Il_5OOO5l__l___IS0ll_lOS5_
          (undefined1 *param_1,undefined8 param_2,char param_3)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char acStack_62 [2];
  
  uVar5 = 5;
  if (param_3 != '\0') {
    uVar5 = 3;
  }
  uVar1 = 1;
  do {
    uVar4 = uVar1;
    uVar1 = uVar5;
    switch(uVar4) {
    case 0:
      uVar3 = 10;
LAB_001188f0:
      *param_1 = uVar3;
      return 0;
    case 1:
      acStack_62[1] = 0xd9;
      acStack_62[0] = param_3;
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,acStack_62 + 1,1);
      if (lVar2 != 1) {
        uVar3 = 8;
        goto LAB_001188f0;
      }
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,acStack_62,1);
      uVar1 = 6;
      if (lVar2 == 0) {
        uVar3 = 0xf;
        goto LAB_001188f0;
      }
      break;
    default:
      do {
      } while( true );
    case 3:
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3);
      uVar1 = 0;
      if (lVar2 != 0) {
        uVar1 = 4;
      }
      break;
    case 4:
    case 5:
      return 1;
    case 6:
      break;
    }
  } while( true );
}


/* EXPORT index=92 ELF_VA=0x18930 size=144 source_sha256=5bd7fc40574ec5e1fc98a6492f07254df8c70498c6550537eb47c10d82df033c */

undefined8 j___l__ll___I_I_O5O0l__lIl__O_O5_llISO_II0IlI_II5llS5_(undefined1 *param_1,uint param_2)

{
  long lVar1;
  undefined1 uVar2;
  ushort uStack_24;
  undefined1 uStack_21;
  
  uStack_24 = (ushort)param_2;
  uStack_21 = 0xda;
  lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar1 == 1) {
    uStack_24 = (ushort)(param_2 >> 8) & 0xff | (ushort)((param_2 & 0xff00ff) << 8);
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_24,2);
    if (lVar1 != 0) {
      return 1;
    }
    uVar2 = 0xf;
  }
  else {
    uVar2 = 8;
  }
  *param_1 = uVar2;
  return 0;
}


/* EXPORT index=93 ELF_VA=0x189c0 size=312 source_sha256=3940e267f0ad0da2e94082d1d0040815abfb977d1c0d70eea14087e25722596e */

undefined8
j___llSI0_050IS_II_lI_0l55O_lIISIOlISOl_I_I5l_I__llS5_
          (undefined1 *param_1,undefined8 param_2,uint param_3)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ushort uStack_64;
  undefined1 uStack_61;
  
  uVar5 = 3;
  if ((param_3 & 0xffff) != 0) {
    uVar5 = 1;
  }
  uVar1 = 4;
  do {
    uVar4 = uVar1;
    uVar1 = uVar5;
    switch(uVar4) {
    case 0:
      uVar3 = 10;
LAB_00118ad4:
      *param_1 = uVar3;
      return 0;
    case 1:
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3 & 0xffff);
      uVar1 = 0;
      if (lVar2 != 0) {
        uVar1 = 6;
      }
      break;
    default:
      do {
      } while( true );
    case 3:
    case 6:
      return 1;
    case 4:
      uStack_61 = 0xda;
      uStack_64 = (ushort)param_3;
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
      if (lVar2 != 1) {
        uVar3 = 8;
        goto LAB_00118ad4;
      }
      uStack_64 = (ushort)(param_3 >> 8) & 0xff | (ushort)((param_3 & 0xff00ff) << 8);
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_64,2);
      uVar1 = 5;
      if (lVar2 == 0) {
        uVar3 = 0xf;
        goto LAB_00118ad4;
      }
      break;
    case 5:
      break;
    }
  } while( true );
}


/* EXPORT index=94 ELF_VA=0x18b14 size=140 source_sha256=15a1b74c2fea0d32c9be2202756093bd5fb78e7d2866dea96127c7246a220ed8 */

undefined8 j____S5I5_OIIII_55III_II5Il_5_SlS5OI_l0SIlIIl05OSO_S5_(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  undefined1 uVar3;
  uint uStack_28;
  undefined1 uStack_21;
  
  uStack_21 = 0xdb;
  uStack_28 = param_2;
  lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar2 == 1) {
    uVar1 = (param_2 & 0xff00ff00) >> 8 | (param_2 & 0xff00ff) << 8;
    uStack_28 = uVar1 >> 0x10 | uVar1 << 0x10;
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_28,4);
    if (lVar2 != 0) {
      return 1;
    }
    uVar3 = 0xf;
  }
  else {
    uVar3 = 8;
  }
  *param_1 = uVar3;
  return 0;
}


/* EXPORT index=95 ELF_VA=0x18ba0 size=344 source_sha256=d17ff85352c87b7398a65e61081a0e2804c7b317c15af9ff2421d46e4143efb9 */

undefined8
j____Sl0O__0l5I_OlISl_0_I5O_05lSS5Il_5l_ll0O_IOIII0S5_
          (undefined1 *param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint uStack_68;
  undefined1 uStack_61;
  
  uVar1 = (param_3 & 0xff00ff00) >> 8 | (param_3 & 0xff00ff) << 8;
  uVar5 = 3;
  uVar2 = 0;
  if (param_3 != 0) {
    uVar5 = 5;
  }
switchD_00118c4c_caseD_4:
  uVar6 = uVar2;
  uVar2 = uVar5;
  switch(uVar6) {
  case 0:
    uStack_61 = 0xdb;
    uStack_68 = param_3;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
    if (lVar3 == 1) {
      uStack_68 = uVar1 >> 0x10 | uVar1 << 0x10;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_68,4);
      uVar2 = 4;
      if (lVar3 != 0) goto switchD_00118c4c_caseD_4;
      uVar4 = 0xf;
    }
    else {
      uVar4 = 8;
    }
    *param_1 = uVar4;
    uVar2 = 1;
    goto switchD_00118c4c_caseD_4;
  case 1:
    goto switchD_00118c4c_caseD_1;
  case 2:
    *param_1 = 10;
    return 0;
  default:
    if ((uVar6 | 4) != 7) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
switchD_00118c4c_caseD_1:
    return 1;
  case 4:
    goto switchD_00118c4c_caseD_4;
  case 5:
    break;
  case 6:
    goto switchD_00118c4c_caseD_1;
  }
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3);
  uVar2 = 2;
  if (lVar3 != 0) {
    uVar2 = 6;
  }
  goto switchD_00118c4c_caseD_4;
switchD_00118c4c_caseD_1:
  return 0;
}


/* EXPORT index=96 ELF_VA=0x18d14 size=596 source_sha256=61f8bb3595196d11002eb9099401aed55b2900f9b42c736cdcc50241404d6f36 */

uint j____IIIl_IOl_I_SS5l__0Il0I_5O0lI_SIOSl__O0__I55lOIS5_(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  ushort uVar2;
  long lVar3;
  uint *puVar4;
  undefined8 uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint unaff_w21;
  ushort uStack_3c;
  byte bStack_39;
  uint uStack_38;
  ushort uStack_34;
  byte bStack_31;
  
  uVar10 = 0x29e8;
  iVar7 = 1;
  if (0xffff < param_2) {
    iVar7 = 5;
  }
  iVar8 = 2;
  if (param_2 < 0x20) {
    iVar8 = 3;
  }
  iVar11 = 7;
switchD_00118da4_caseD_7:
  uVar1 = uVar10 % 0x49;
  iVar9 = iVar11;
switchD_00118da4_caseD_4:
  iVar12 = iVar9;
  uVar10 = 0xb49;
  bStack_39 = (byte)param_2;
  uVar2 = (ushort)(param_2 >> 8);
  iVar11 = iVar8;
  iVar9 = iVar7;
  switch(iVar12) {
  case 0:
    bStack_31 = 0xda;
    uStack_3c = (short)param_2;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_31,1);
    if (lVar3 != 1) {
LAB_00118f34:
      unaff_w21 = 0;
      *param_1 = 8;
      goto LAB_00118f50;
    }
    uStack_3c = uVar2 & 0xff | (ushort)((param_2 & 0xff00ff) << 8);
    pcVar6 = *(code **)(param_1 + 0x18);
    puVar4 = (uint *)&uStack_3c;
    break;
  case 1:
    bStack_31 = 0xda;
    uStack_34 = (short)param_2;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_31,1);
    if (lVar3 != 1) goto LAB_00118f34;
    uStack_34 = uVar2 & 0xff | (ushort)((param_2 & 0xff00ff) << 8);
    pcVar6 = *(code **)(param_1 + 0x18);
    puVar4 = (uint *)&uStack_34;
    break;
  case 2:
    goto switchD_00118da4_caseD_2;
  case 3:
    if ((param_2 & 0xff) < 0x20) {
      bStack_31 = bStack_39 | 0xa0;
      unaff_w21 = 1;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_31,1);
      if (lVar3 != 1) {
        unaff_w21 = 0;
        *param_1 = 6;
      }
    }
    else {
      unaff_w21 = 0;
      *param_1 = 5;
    }
    goto LAB_00118f50;
  case 4:
    goto switchD_00118da4_caseD_4;
  case 5:
    bStack_31 = 0xdb;
    uStack_38 = param_2;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_31,1);
    if (lVar3 != 1) goto LAB_00118f34;
    uVar10 = (param_2 & 0xff00ff00) >> 8 | (param_2 & 0xff00ff) << 8;
    uStack_38 = uVar10 >> 0x10 | uVar10 << 0x10;
    pcVar6 = *(code **)(param_1 + 0x18);
    puVar4 = &uStack_38;
    uVar5 = 4;
    goto LAB_00118ecc;
  case 6:
    bStack_31 = 0xd9;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_31,1);
    if (lVar3 != 1) goto LAB_00118f34;
    unaff_w21 = 1;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_39,1);
    if (lVar3 != 0) goto LAB_00118f50;
    goto LAB_00118f24;
  case 7:
    goto switchD_00118da4_caseD_7;
  default:
    goto switchD_00118da4_default;
  }
  uVar5 = 2;
LAB_00118ecc:
  lVar3 = (*pcVar6)(param_1,puVar4,uVar5);
  if (lVar3 == 0) {
LAB_00118f24:
    unaff_w21 = 0;
    *param_1 = 0xf;
  }
  else {
    unaff_w21 = 1;
  }
  goto LAB_00118f50;
switchD_00118da4_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_00118da4_caseD_2:
  iVar9 = 0x30;
  if (0xff < param_2) {
    iVar9 = 0x2e;
  }
  iVar9 = iVar9 - uVar1;
  if (iVar9 == 8) {
LAB_00118f50:
    return unaff_w21 & 1;
  }
  goto switchD_00118da4_caseD_4;
}


/* EXPORT index=97 ELF_VA=0x18f88 size=328 source_sha256=b4aa38f7ac0f6bbeefb275ce9c8ec3bfbacc6b1d1991bb5046b2657463fbea1f */

undefined4 j___55550_5OIII_0_0I___5O0l_l0lIl5IlIlI__IIIlOSIOS_S5_(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  undefined1 uVar3;
  byte bStack_2d;
  ushort uStack_2c;
  undefined1 uStack_29;
  uint uStack_28;
  undefined1 uStack_21;
  
  if (param_2 < 0x20) {
    if ((param_2 & 0xff) < 0x20) {
      bStack_2d = (byte)param_2 | 0xa0;
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&bStack_2d,1);
      if (lVar2 == 1) {
        return 1;
      }
      uVar3 = 6;
    }
    else {
      uVar3 = 5;
    }
    goto LAB_001190b8;
  }
  if (param_2 >> 0x10 == 0) {
    uStack_2c = (ushort)param_2;
    uStack_29 = 0xda;
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_29,1);
    if (lVar2 != 1) {
LAB_001190a4:
      uVar3 = 8;
      goto LAB_001190b8;
    }
    uStack_2c = (ushort)(param_2 >> 8) & 0xff | (ushort)((param_2 & 0xff00ff) << 8);
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_2c,2);
    if (lVar2 != 0) {
      return 1;
    }
  }
  else {
    uStack_21 = 0xdb;
    uStack_28 = param_2;
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
    if (lVar2 != 1) goto LAB_001190a4;
    uVar1 = (param_2 & 0xff00ff00) >> 8 | (param_2 & 0xff00ff) << 8;
    uStack_28 = uVar1 >> 0x10 | uVar1 << 0x10;
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_28,4);
    if (lVar2 != 0) {
      return 1;
    }
  }
  uVar3 = 0xf;
LAB_001190b8:
  *param_1 = uVar3;
  return 0;
}


/* EXPORT index=98 ELF_VA=0x190d0 size=1112 source_sha256=e8f713e3f8dbf4a6ce23cf2e73bc5ae82ee3affa25e9ffe7e22dbb41dea11526 */

undefined8
j___llSll__O_Il__0_ll_lII5__0__Il_I_0ISI55OI5IOIl_lS5_
          (undefined1 *param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined1 uVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  uint auStack_78 [3];
  byte abStack_69 [5];
  ushort uStack_64;
  byte bStack_61;
  
  iVar11 = 6;
  if (0x1f < param_3) {
    iVar11 = 3;
  }
  iVar4 = 5;
switchD_0011914c_caseD_5:
  iVar14 = iVar4;
  iVar4 = iVar11;
  switch(iVar14) {
  case 0:
    iVar4 = 1;
    if (param_3 >> 0x10 != 0) {
      uVar1 = (param_3 & 0xff00ff00) >> 8 | (param_3 & 0xff00ff) << 8;
      uVar9 = 3;
      uVar3 = 0;
      if (param_3 != 0) {
        uVar9 = 5;
      }
      goto switchD_001191ec_caseD_4;
    }
    goto switchD_0011914c_caseD_5;
  case 1:
    goto switchD_0011914c_caseD_1;
  default:
    iVar4 = (uint)(param_3 < 0x100) << 2;
    if (iVar14 != 3) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    goto switchD_0011914c_caseD_5;
  case 4:
    auStack_78[2] = 0;
    uVar12 = 5;
    if ((param_3 & 0xff) != 0) {
      uVar12 = 3;
    }
    uVar5 = 1;
    goto switchD_00119394_caseD_6;
  case 5:
    goto switchD_0011914c_caseD_5;
  case 6:
    auStack_78[1] = 0;
    uVar9 = 0x6cde;
    iVar11 = 0;
    if ((param_3 & 0xff) != 0) {
      iVar11 = 7;
    }
    iVar4 = 5;
switchD_00119468_caseD_6:
    iVar14 = iVar4;
    iVar2 = (uVar9 / 0x89) * 0x89 - uVar9;
    do {
      uVar6 = 0;
      uVar9 = 0x3e73;
      iVar4 = iVar11;
      switch(iVar14) {
      case 0:
      case 3:
      case 4:
      case 8:
        goto switchD_00119468_caseD_2;
      case 1:
        goto switchD_00119468_caseD_1;
      case 2:
        goto switchD_00119468_caseD_2;
      case 5:
        if ((param_3 & 0xff) < 0x20) {
          bStack_61 = (byte)param_3 | 0xa0;
          lVar7 = (**(code **)(param_1 + 0x18))(param_1,&bStack_61,1);
          iVar14 = 6;
          if (lVar7 == 1) break;
          uVar8 = 6;
        }
        else {
          uVar8 = 5;
        }
        *param_1 = uVar8;
        iVar14 = 2;
        break;
      case 6:
        goto switchD_00119468_caseD_6;
      case 7:
        lVar7 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3 & 0xff);
        iVar14 = 0x60;
        if (lVar7 != 0) {
          iVar14 = 0x62;
        }
        iVar14 = iVar2 + iVar14;
        if (iVar14 == 8) {
          return 1;
        }
        break;
      default:
        goto switchD_00119468_default;
      }
    } while( true );
  }
switchD_00119468_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_00119394_caseD_6:
  uVar10 = uVar5;
  uVar6 = 1;
  uVar5 = uVar12;
  switch(uVar10) {
  case 0:
    goto switchD_00119468_caseD_1;
  case 1:
    bStack_61 = 0xd9;
    abStack_69[0] = (byte)param_3;
    lVar7 = (**(code **)(param_1 + 0x18))(param_1,&bStack_61,1);
    if (lVar7 != 1) goto LAB_001194fc;
    lVar7 = (**(code **)(param_1 + 0x18))(param_1,abStack_69,1);
    uVar5 = 6;
    if (lVar7 == 0) goto LAB_001193d8;
    goto switchD_00119394_caseD_6;
  default:
    break;
  case 3:
    lVar7 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3 & 0xff);
    uVar5 = 0;
    if (lVar7 != 0) {
      uVar5 = 4;
    }
    goto switchD_00119394_caseD_6;
  case 4:
  case 5:
    goto switchD_00119468_caseD_2;
  case 6:
    goto switchD_00119394_caseD_6;
  }
  do {
  } while( true );
switchD_0011914c_caseD_1:
  abStack_69[1] = 0;
  abStack_69[2] = 0;
  abStack_69[3] = 0;
  abStack_69[4] = 0;
  uVar12 = 3;
  if ((param_3 & 0xffff) != 0) {
    uVar12 = 1;
  }
  uVar5 = 4;
switchD_001192d0_caseD_5:
  uVar10 = uVar5;
  uVar6 = 1;
  uVar5 = uVar12;
  switch(uVar10) {
  case 0:
    goto switchD_00119468_caseD_1;
  case 1:
    lVar7 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3 & 0xffff);
    uVar5 = 0;
    if (lVar7 != 0) {
      uVar5 = 6;
    }
    goto switchD_001192d0_caseD_5;
  default:
    goto switchD_001192d0_caseD_2;
  case 3:
  case 6:
    goto switchD_00119468_caseD_2;
  case 4:
    uStack_64 = (ushort)param_3;
    bStack_61 = 0xda;
    lVar7 = (**(code **)(param_1 + 0x18))(param_1,&bStack_61,1);
    if (lVar7 != 1) break;
    uStack_64 = (ushort)(param_3 >> 8) & 0xff | (ushort)((param_3 & 0xff00ff) << 8);
    lVar7 = (**(code **)(param_1 + 0x18))(param_1,&uStack_64,2);
    uVar5 = 5;
    if (lVar7 == 0) goto LAB_001193d8;
  case 5:
    goto switchD_001192d0_caseD_5;
  }
LAB_001194fc:
  uVar8 = 8;
  goto LAB_00119504;
LAB_001193d8:
  uVar8 = 0xf;
  goto LAB_00119504;
switchD_001192d0_caseD_2:
  do {
  } while( true );
switchD_001191ec_caseD_4:
  uVar13 = uVar3;
  uVar6 = 0;
  uVar3 = uVar9;
  switch(uVar13) {
  case 0:
    bStack_61 = 0xdb;
    auStack_78[0] = param_3;
    lVar7 = (**(code **)(param_1 + 0x18))(param_1,&bStack_61,1);
    if (lVar7 == 1) {
      auStack_78[0] = uVar1 >> 0x10 | uVar1 << 0x10;
      lVar7 = (**(code **)(param_1 + 0x18))(param_1,auStack_78,4);
      uVar3 = 4;
      if (lVar7 != 0) goto switchD_001191ec_caseD_4;
      uVar8 = 0xf;
    }
    else {
      uVar8 = 8;
    }
    *param_1 = uVar8;
    uVar3 = 1;
    goto switchD_001191ec_caseD_4;
  case 1:
    goto switchD_00119468_caseD_2;
  case 2:
    goto switchD_00119468_caseD_1;
  default:
    if ((uVar13 | 4) == 7) {
      return 1;
    }
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  case 4:
    goto switchD_001191ec_caseD_4;
  case 5:
    lVar7 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3);
    uVar3 = 2;
    if (lVar7 != 0) {
      uVar3 = 6;
    }
    goto switchD_001191ec_caseD_4;
  case 6:
    break;
  }
switchD_00119468_caseD_2:
  return 1;
switchD_00119468_caseD_1:
  uVar8 = 10;
LAB_00119504:
  uVar6 = 0;
  *param_1 = uVar8;
switchD_00119468_caseD_2:
  return uVar6;
}


/* EXPORT index=99 ELF_VA=0x195bc size=816 source_sha256=8a68c890c8d24a16d34c2d8f78787953cbccf82be0fbe0f68efc3bffd18fec19 */

undefined8
j___IIOS__lOII0_0I_0l_I_lOI_0OI_I__ll5I_IlIl5Il_l5IS5_
          (undefined1 *param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  ushort auStack_6e [3];
  uint uStack_68;
  byte bStack_61;
  
  if (param_3 < 0x20) {
    uVar10 = 0x6cde;
    iVar1 = 0;
    if ((param_3 & 0xff) != 0) {
      iVar1 = 7;
    }
    iVar4 = 5;
switchD_00119670_caseD_6:
    iVar13 = iVar4;
    iVar2 = (uVar10 / 0x89) * 0x89 - uVar10;
    do {
      uVar6 = 0;
      uVar10 = 0x3e73;
      iVar4 = iVar1;
      switch(iVar13) {
      case 0:
      case 3:
      case 4:
      case 8:
        goto switchD_00119670_caseD_2;
      case 1:
        goto switchD_00119670_caseD_1;
      case 2:
        goto switchD_00119670_caseD_2;
      case 5:
        if ((param_3 & 0xff) < 0x20) {
          bStack_61 = (byte)param_3 | 0xa0;
          lVar7 = (**(code **)(param_1 + 0x18))(param_1,&bStack_61,1);
          iVar13 = 6;
          if (lVar7 == 1) break;
          uVar8 = 6;
        }
        else {
          uVar8 = 5;
        }
        *param_1 = uVar8;
        iVar13 = 2;
        break;
      case 6:
        goto switchD_00119670_caseD_6;
      case 7:
        lVar7 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3 & 0xff);
        iVar13 = 0x60;
        if (lVar7 != 0) {
          iVar13 = 0x62;
        }
        iVar13 = iVar2 + iVar13;
        if (iVar13 == 8) {
          return 1;
        }
        break;
      default:
        goto switchD_00119670_default;
      }
    } while( true );
  }
  if (param_3 >> 0x10 != 0) {
    auStack_6e[1] = 0;
    auStack_6e[2] = 0;
    uVar10 = (param_3 & 0xff00ff00) >> 8 | (param_3 & 0xff00ff) << 8;
    uVar3 = 0;
switchD_00119830_caseD_4:
    uVar12 = uVar3;
    uVar6 = 0;
    uVar3 = 5;
    switch(uVar12) {
    case 0:
      bStack_61 = 0xdb;
      uStack_68 = param_3;
      lVar7 = (**(code **)(param_1 + 0x18))(param_1,&bStack_61,1);
      if (lVar7 == 1) {
        uStack_68 = uVar10 >> 0x10 | uVar10 << 0x10;
        lVar7 = (**(code **)(param_1 + 0x18))(param_1,&uStack_68,4);
        uVar3 = 4;
        if (lVar7 != 0) goto switchD_00119830_caseD_4;
        uVar8 = 0xf;
      }
      else {
        uVar8 = 8;
      }
      *param_1 = uVar8;
      uVar3 = 1;
      goto switchD_00119830_caseD_4;
    case 1:
      goto switchD_00119670_caseD_2;
    case 2:
      goto switchD_00119670_caseD_1;
    default:
      if ((uVar12 | 4) == 7) {
        return 1;
      }
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    case 4:
      goto switchD_00119830_caseD_4;
    case 5:
      lVar7 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3);
      uVar3 = 2;
      if (lVar7 != 0) {
        uVar3 = 6;
      }
      goto switchD_00119830_caseD_4;
    case 6:
      goto switchD_00119670_caseD_2;
    }
  }
  uVar11 = 3;
  if ((param_3 & 0xffff) != 0) {
    uVar11 = 1;
  }
  uVar5 = 4;
  do {
    uVar9 = uVar5;
    uVar6 = 1;
    uVar5 = uVar11;
    switch(uVar9) {
    case 0:
switchD_00119670_caseD_1:
      uVar6 = 0;
      *param_1 = 10;
switchD_00119670_caseD_2:
      return uVar6;
    case 1:
      lVar7 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3 & 0xffff);
      uVar5 = 0;
      if (lVar7 != 0) {
        uVar5 = 6;
      }
      break;
    default:
      goto switchD_00119764_caseD_2;
    case 3:
    case 6:
      goto switchD_00119670_caseD_2;
    case 4:
      auStack_6e[0] = (ushort)param_3;
      bStack_61 = 0xda;
      lVar7 = (**(code **)(param_1 + 0x18))(param_1,&bStack_61,1);
      if (lVar7 != 1) {
        *param_1 = 8;
        return 0;
      }
      auStack_6e[0] = (ushort)(param_3 >> 8) & 0xff | (ushort)((param_3 & 0xff00ff) << 8);
      lVar7 = (**(code **)(param_1 + 0x18))(param_1,auStack_6e,2);
      uVar5 = 5;
      if (lVar7 == 0) {
        *param_1 = 0xf;
        return 0;
      }
      break;
    case 5:
      break;
    }
  } while( true );
switchD_00119670_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_00119764_caseD_2:
  do {
  } while( true );
switchD_00119670_caseD_2:
  return 1;
}


/* EXPORT index=100 ELF_VA=0x19948 size=224 source_sha256=dcf5ee728011a269021a3186b69833459a7dc652e00eaa3b8264e5e76232fa72 */

undefined8
j___0_I_I_l_Ill_II0Sl_lO5I__I_l_O5_0IOIOOI__lIl_IlIS5_(undefined1 *param_1,undefined1 param_2)

{
  long lVar1;
  int iVar2;
  undefined1 uStack_42;
  undefined1 uStack_41;
  
  iVar2 = 2;
  uStack_42 = param_2;
  do {
    while( true ) {
      if (iVar2 == 4) {
        return 0;
      }
      if (iVar2 == 0) break;
      if (iVar2 != 2) {
        if (iVar2 == 3) {
          return 1;
        }
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      uStack_41 = 0xc4;
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_41,1);
      iVar2 = 0;
      if (lVar1 != 1) {
        *param_1 = 8;
        iVar2 = 4;
      }
    }
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_42,1);
    iVar2 = 3;
  } while (lVar1 != 0);
  *param_1 = 0xf;
  return 0;
}


/* EXPORT index=101 ELF_VA=0x19a28 size=296 source_sha256=ea080b3b86569a399e1ffeb5f2fca800ee5246f183773da7087edfc3508ccf39 */

undefined8
j___llllI_lIS_l_0III5_I_II5_OIIOS5I0IlOIIlIO05lllI_S5_
          (undefined1 *param_1,undefined8 param_2,undefined1 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 uStack_52;
  undefined1 uStack_51;
  
  uVar2 = 2;
  uStack_52 = param_3;
  do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch(uVar2) {
    case 0:
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_52,1);
      uVar2 = 3;
      if (lVar1 == 0) {
        *param_1 = 0xf;
switchD_00119a9c_caseD_4:
        return 0;
      }
      break;
    case 2:
      uStack_51 = 0xc4;
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_51,1);
      uVar2 = 0;
      if (lVar1 != 1) {
        *param_1 = 8;
        uVar2 = 4;
      }
      break;
    case 4:
      goto switchD_00119a9c_caseD_4;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=102 ELF_VA=0x19b64 size=244 source_sha256=6b61519d5ebd9276f46db57bc37722d9dce627c63c3337b97605a0336f8541a5 */

undefined8
j___l0__5_lI_OI_IS_lI__IIII__I_S55_lSS_I0I_00OIl5I_S5_(undefined1 *param_1,ushort param_2)

{
  long lVar1;
  int iVar2;
  ushort uStack_44;
  undefined1 uStack_41;
  
  iVar2 = 0;
  uStack_44 = param_2;
  while( true ) {
    while (iVar2 == 5) {
      uStack_44 = uStack_44 >> 8 | uStack_44 << 8;
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_44,2);
      iVar2 = 4;
      if (lVar1 == 0) {
        *param_1 = 0xf;
        return 0;
      }
    }
    if (iVar2 == 4) break;
    if (iVar2 != 0) {
      if (iVar2 == 1) {
        return 0;
      }
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uStack_41 = 0xc5;
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_41,1);
    iVar2 = 5;
    if (lVar1 != 1) {
      *param_1 = 8;
      iVar2 = 1;
    }
  }
  return 1;
}


/* EXPORT index=103 ELF_VA=0x19c58 size=420 source_sha256=7e93782bd23b32b07aff5f939a1cc8fd715bc76bf543b3f19a610a4d3209c0c2 */

undefined8
j___IIllI_I_OI5_0O_l__l_IO0_Ol_IIllI5lI_ISI55_lllIlS5_
          (undefined1 *param_1,undefined8 param_2,ushort param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  ushort uStack_64;
  undefined1 uStack_61;
  
  iVar4 = 7;
  if (param_3 != 0) {
    iVar4 = 5;
  }
  iVar1 = 4;
LAB_00119cdc:
  do {
    while( true ) {
      do {
        iVar5 = iVar1;
        iVar1 = iVar4;
      } while (iVar5 == 6);
      if (iVar5 != 5) break;
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3);
      iVar1 = 2;
      if (lVar2 != 0) {
        iVar1 = 3;
      }
    }
    if (iVar5 == 0) {
      return 0;
    }
    uVar3 = 1;
    switch(iVar5) {
    case 2:
      uVar3 = 0;
      *param_1 = 10;
    case 3:
    case 7:
      return uVar3;
    case 4:
      iVar5 = 0;
      uStack_64 = param_3;
      break;
    default:
      do {
      } while( true );
    }
    do {
      while (iVar5 != 5) {
        if (iVar5 == 4) {
          iVar1 = 6;
          goto LAB_00119cdc;
        }
        if (iVar5 != 0) {
          iVar1 = 0;
          if (iVar5 != 1) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          goto LAB_00119cdc;
        }
        uStack_61 = 0xc5;
        lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
        iVar5 = 5;
        if (lVar2 != 1) {
          *param_1 = 8;
          iVar5 = 1;
        }
      }
      uStack_64 = uStack_64 >> 8 | uStack_64 << 8;
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_64,2);
      iVar5 = 4;
    } while (lVar2 != 0);
    *param_1 = 0xf;
    iVar1 = 0;
  } while( true );
}


/* EXPORT index=104 ELF_VA=0x19e14 size=140 source_sha256=13b124a103ab1f1283c9b1a591bb45086470cf8e8043f39350b0c07fae0ebfd8 */

undefined8 j_____lSI__SO_I_lI_0l_O_lII_OIISI_I_0I__0IO0O55_I0IS5_(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  undefined1 uVar3;
  uint uStack_28;
  undefined1 uStack_21;
  
  uStack_21 = 0xc6;
  uStack_28 = param_2;
  lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar2 == 1) {
    uVar1 = (param_2 & 0xff00ff00) >> 8 | (param_2 & 0xff00ff) << 8;
    uStack_28 = uVar1 >> 0x10 | uVar1 << 0x10;
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_28,4);
    if (lVar2 != 0) {
      return 1;
    }
    uVar3 = 0xf;
  }
  else {
    uVar3 = 8;
  }
  *param_1 = uVar3;
  return 0;
}


/* EXPORT index=105 ELF_VA=0x19ea0 size=424 source_sha256=617e53f2c3d9be34a5f82d3708e0365b31ed397d56686284bee13e011da499e7 */

undefined8
j___III5__II0lI_0__Il_Il_I__ISII55_l000_SI5OlIISOlSS5_
          (undefined1 *param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  uint uStack_68;
  undefined1 uStack_61;
  
  iVar4 = 0;
  uVar1 = (param_3 & 0xff00ff00) >> 8 | (param_3 & 0xff00ff) << 8;
  uVar5 = 0x301c;
  do {
LAB_00119f50:
    while (iVar4 == 4) {
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,param_2,param_3);
      iVar4 = 5;
      if (lVar2 != 0) {
        iVar4 = 2;
      }
    }
    if (iVar4 == 2) goto switchD_00119f80_caseD_6;
    if (iVar4 == 5) {
      *param_1 = 10;
      return 0;
    }
    uVar3 = 0;
    switch(iVar4) {
    case 0:
      uStack_61 = 0xc6;
      uStack_68 = param_3;
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
      if (lVar2 == 1) {
        uStack_68 = uVar1 >> 0x10 | uVar1 << 0x10;
        lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_68,4);
        uVar5 = 0x31ed;
        iVar4 = 3;
        if (lVar2 == 0) {
          *param_1 = 0xf;
          uVar5 = 0x31ed;
          iVar4 = 1;
        }
      }
      else {
        *param_1 = 8;
        uVar5 = 0x31ed;
        iVar4 = 1;
      }
      break;
    case 1:
      goto switchD_00119f80_caseD_1;
    default:
      do {
      } while( true );
    case 3:
      goto switchD_00119f80_caseD_3;
    case 6:
    case 7:
      goto switchD_00119f80_caseD_6;
    }
  } while( true );
switchD_00119f80_caseD_3:
  iVar4 = 0x3d;
  if (param_3 != 0) {
    iVar4 = 0x3b;
  }
  iVar4 = iVar4 - uVar5 % 0x65;
  if (iVar4 == 7) {
switchD_00119f80_caseD_6:
    uVar3 = 1;
switchD_00119f80_caseD_1:
    return uVar3;
  }
  goto LAB_00119f50;
}


/* EXPORT index=106 ELF_VA=0x1a068 size=488 source_sha256=07fea422a6ae27de4970361c9d1a9ec2a00352d2c6574fd7c7e5ac5b676df5e5 */

undefined4 j___5l050_____l_Il5Il__IIIl_lS0OO_IOS___0_lI_5IIIl_S5_(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 uStack_51;
  undefined4 uStack_50;
  ushort uStack_4a;
  uint uStack_48;
  undefined1 uStack_41;
  
  if (param_2 < 0x100) {
    uStack_51 = (undefined1)param_2;
    iVar4 = 2;
    do {
      while (iVar4 != 0) {
        if (iVar4 != 2) {
          if (iVar4 == 3) {
            return 1;
          }
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        uStack_41 = 0xc4;
        lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_41,1);
        iVar4 = 0;
        if (lVar2 != 1) goto LAB_0011a180;
      }
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_51,1);
      iVar4 = 3;
    } while (lVar2 != 0);
  }
  else if (param_2 >> 0x10 == 0) {
    iVar4 = 0;
    uStack_4a = (ushort)param_2;
    uStack_50 = 0;
    do {
      while (iVar4 != 5) {
        if (iVar4 == 4) {
          return 1;
        }
        if (iVar4 != 0) {
          if (iVar4 == 1) {
            return 0;
          }
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        uStack_41 = 0xc5;
        lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_41,1);
        iVar4 = 5;
        if (lVar2 != 1) {
          *param_1 = 8;
          iVar4 = 1;
        }
      }
      uStack_4a = uStack_4a >> 8 | uStack_4a << 8;
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_4a,2);
      iVar4 = 4;
    } while (lVar2 != 0);
  }
  else {
    uStack_41 = 0xc6;
    uStack_48 = param_2;
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_41,1);
    if (lVar2 != 1) {
LAB_0011a180:
      uVar3 = 8;
      goto LAB_0011a208;
    }
    uVar1 = (param_2 & 0xff00ff00) >> 8 | (param_2 & 0xff00ff) << 8;
    uStack_48 = uVar1 >> 0x10 | uVar1 << 0x10;
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_48,4);
    if (lVar2 != 0) {
      return 1;
    }
  }
  uVar3 = 0xf;
LAB_0011a208:
  *param_1 = uVar3;
  return 0;
}


/* EXPORT index=107 ELF_VA=0x1a250 size=472 source_sha256=5cd58fabdca52711ee79312704cb5c002dd1fa50e34a8d16ecb7ef1ea4a24f36 */

undefined8
j___IlSI___lI_I_OO_5I_IIlSS__lOO_lIIIIIOlIIIS__SlOIS5_
          (undefined1 *param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 uStack_52;
  undefined1 uStack_51;
  
  iVar5 = 5;
  if (0xffff < param_3) {
    iVar5 = 3;
  }
  iVar6 = 4;
  iVar1 = 0;
  if (0xff < param_3) {
    iVar6 = 2;
  }
switchD_0011a2d4_caseD_0:
  do {
    iVar4 = iVar1;
    iVar1 = iVar5;
  } while (iVar4 == 2);
  iVar1 = iVar6;
  switch(iVar4) {
  case 0:
    goto switchD_0011a2d4_caseD_0;
  default:
    do {
    } while( true );
  case 3:
    uVar3 = j___III5__II0lI_0__Il_Il_I__ISII55_l000_SI5OlIISOlSS5_(param_1,param_2,param_3);
    return uVar3;
  case 4:
    uStack_52 = (undefined1)param_3;
    uVar3 = 2;
    break;
  case 5:
    uVar3 = j___IIllI_I_OI5_0O_l__l_IO0_Ol_IIllI5lI_ISI55_lllIlS5_(param_1,param_2,param_3);
    return uVar3;
  }
  do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch(uVar3) {
    case 0:
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_52,1);
      uVar3 = 3;
      if (lVar2 == 0) {
        *param_1 = 0xf;
switchD_0011a350_caseD_4:
        return 0;
      }
      break;
    case 2:
      uStack_51 = 0xc4;
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_51,1);
      uVar3 = 0;
      if (lVar2 != 1) {
        *param_1 = 8;
        uVar3 = 4;
      }
      break;
    case 4:
      goto switchD_0011a350_caseD_4;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=108 ELF_VA=0x1a454 size=120 source_sha256=68f330d54b97bacdc8e964035128752022a83902c7595a3650070b9bd6cfeeaf */

undefined4 j____5IO__l_55l__IIO0_05_SS_OSIll__II_I_lIlI5_llSIIS5_(undefined1 *param_1,byte param_2)

{
  long lVar1;
  undefined1 uVar2;
  byte bStack_21;
  
  if (param_2 < 0x10) {
    bStack_21 = param_2 | 0x90;
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&bStack_21,1);
    if (lVar1 == 1) {
      return 1;
    }
    uVar2 = 6;
  }
  else {
    uVar2 = 5;
  }
  *param_1 = uVar2;
  return 0;
}


/* EXPORT index=109 ELF_VA=0x1a4cc size=264 source_sha256=6ea6a623811d5c9e749ab4d538f629fbbfe92ce3e01a510ec762006df051b4e2 */

undefined8
j___ISl____IIll_OSIII__OIlO_I05I0lOlO_SO_l5_SO5lIOIS5_(undefined1 *param_1,ushort param_2)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  ushort uStack_54;
  undefined1 uStack_51;
  
  iVar3 = 2;
  uStack_54 = param_2;
  while( true ) {
    while (iVar3 == 0) {
      uStack_54 = uStack_54 >> 8 | uStack_54 << 8;
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_54,2);
      iVar3 = 1;
      if (lVar1 != 0) {
        iVar3 = 3;
      }
    }
    if (iVar3 == 5) break;
    if (iVar3 != 2) {
      if (iVar3 == 1) {
        uVar2 = 0;
        *param_1 = 0xf;
      }
      else {
        if (iVar3 != 3) {
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        uVar2 = 1;
      }
      return uVar2;
    }
    uStack_51 = 0xdc;
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_51,1);
    iVar3 = 0;
    if (lVar1 != 1) {
      *param_1 = 8;
      iVar3 = 5;
    }
  }
  return 0;
}


/* EXPORT index=110 ELF_VA=0x1a5d4 size=228 source_sha256=9b6d93e1d28eef99c352645bb62ee860b7ac82065230e9970765208f06e6ea07 */

undefined8 j___lIIII_Il_0O_OI__O_IO05I__S0II_5I_I_S5OOIl0I_Il_S5_(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  uint uStack_48;
  undefined1 uStack_41;
  
  uStack_48 = param_2;
  uVar5 = 5;
  do {
    uVar2 = 1;
    switch(uVar5) {
    case 0:
      goto switchD_0011a65c_caseD_0;
    default:
      do {
      } while( true );
    case 3:
      uVar4 = 0xf;
      goto LAB_0011a69c;
    case 4:
      uVar1 = (uStack_48 & 0xff00ff00) >> 8 | (uStack_48 & 0xff00ff) << 8;
      uStack_48 = uVar1 >> 0x10 | uVar1 << 0x10;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_48,4);
      uVar5 = 3;
      if (lVar3 != 0) {
        uVar5 = 0;
      }
      break;
    case 5:
      uStack_41 = 0xdd;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_41,1);
      uVar5 = 4;
      if (lVar3 != 1) {
        uVar4 = 8;
LAB_0011a69c:
        uVar2 = 0;
        *param_1 = uVar4;
switchD_0011a65c_caseD_0:
        return uVar2;
      }
    }
  } while( true );
}


/* EXPORT index=111 ELF_VA=0x1a6d0 size=596 source_sha256=f1ccbb0d5e51770dde6f5b1740aa008378191d65bb67fe1f0cd9b6940c4d2f39 */

undefined4 j___Il_IO_l5_II_5S_SI_O0lIl_lSSSl_lIlOI0_SIl5IlIII5S5_(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  char cVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  char cVar7;
  undefined4 uVar8;
  int iVar9;
  ushort auStack_5e [3];
  uint uStack_58;
  byte bStack_51;
  
  cVar4 = '\x04';
  if (param_2 < 0x10) {
    cVar4 = '\x05';
  }
  cVar2 = '\x03';
LAB_0011a710:
  do {
    cVar7 = cVar2;
    cVar2 = cVar4;
  } while (cVar7 == '\x03');
  if (cVar7 == '\x01') {
    auStack_5e[0] = (ushort)param_2;
    iVar9 = 2;
    while( true ) {
      while (iVar9 == 0) {
        auStack_5e[0] = auStack_5e[0] >> 8 | auStack_5e[0] << 8;
        lVar3 = (**(code **)(param_1 + 0x18))(param_1,auStack_5e,2);
        iVar9 = 1;
        if (lVar3 != 0) {
          iVar9 = 3;
        }
      }
      if (iVar9 == 5) {
        return 0;
      }
      if (iVar9 != 2) break;
      bStack_51 = 0xdc;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_51,1);
      iVar9 = 0;
      if (lVar3 != 1) {
        *param_1 = 8;
        iVar9 = 5;
      }
    }
    if (iVar9 != 1) {
      if (iVar9 == 3) {
        return 1;
      }
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    goto switchD_0011a88c_caseD_3;
  }
  if (cVar7 != '\x05') goto code_r0x0011a730;
  if ((param_2 & 0xff) < 0x10) {
    bStack_51 = (byte)param_2 | 0x90;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_51,1);
    if (lVar3 == 1) {
      return 1;
    }
    uVar5 = 6;
  }
  else {
    uVar5 = 5;
  }
  goto LAB_0011a8cc;
code_r0x0011a730:
  cVar2 = param_2 < 0x10000;
  if (cVar7 != '\x04') goto code_r0x0011a73c;
  goto LAB_0011a710;
code_r0x0011a73c:
  if (cVar7 != '\0') {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  auStack_5e[1] = 0;
  auStack_5e[2] = 0;
  uStack_58 = param_2;
  uVar6 = 5;
LAB_0011a874:
  uVar8 = 1;
  switch(uVar6) {
  case 0:
    goto switchD_0011a88c_caseD_0;
  default:
    goto switchD_0011a88c_caseD_1;
  case 3:
    goto switchD_0011a88c_caseD_3;
  case 4:
    uVar1 = (uStack_58 & 0xff00ff00) >> 8 | (uStack_58 & 0xff00ff) << 8;
    uStack_58 = uVar1 >> 0x10 | uVar1 << 0x10;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_58,4);
    uVar6 = 3;
    if (lVar3 != 0) {
      uVar6 = 0;
    }
    goto LAB_0011a874;
  case 5:
    break;
  }
  bStack_51 = 0xdd;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_51,1);
  uVar6 = 4;
  if (lVar3 != 1) goto code_r0x0011a8b4;
  goto LAB_0011a874;
code_r0x0011a8b4:
  uVar5 = 8;
  goto LAB_0011a8cc;
switchD_0011a88c_caseD_1:
  do {
  } while( true );
switchD_0011a88c_caseD_3:
  uVar5 = 0xf;
LAB_0011a8cc:
  uVar8 = 0;
  *param_1 = uVar5;
switchD_0011a88c_caseD_0:
  return uVar8;
}


/* EXPORT index=112 ELF_VA=0x1a93c size=116 source_sha256=982739a595ee3c9669722afbd66c075b9cea46937c52ab12d6e684bee329306f */

undefined4 j___IIS_l_I_l5l____ll___ISI_550IOlI0ll5O_O0lIISOlS_S5_(undefined1 *param_1,byte param_2)

{
  long lVar1;
  undefined1 uVar2;
  byte bStack_21;
  
  if (param_2 < 0x10) {
    bStack_21 = param_2 | 0x80;
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&bStack_21,1);
    if (lVar1 == 1) {
      return 1;
    }
    uVar2 = 6;
  }
  else {
    uVar2 = 5;
  }
  *param_1 = uVar2;
  return 0;
}


/* EXPORT index=113 ELF_VA=0x1a9b0 size=144 source_sha256=b3d5d44381c52c35662b160c0e1b7906706e912d78395689212a81e34883b746 */

undefined8 j___I5__I_ll05__II__0_I_S0I_I05OS5I__S_0l_IlI_Ill_IS5_(undefined1 *param_1,uint param_2)

{
  long lVar1;
  undefined1 uVar2;
  ushort uStack_24;
  undefined1 uStack_21;
  
  uStack_24 = (ushort)param_2;
  uStack_21 = 0xde;
  lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar1 == 1) {
    uStack_24 = (ushort)(param_2 >> 8) & 0xff | (ushort)((param_2 & 0xff00ff) << 8);
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_24,2);
    if (lVar1 != 0) {
      return 1;
    }
    uVar2 = 0xf;
  }
  else {
    uVar2 = 8;
  }
  *param_1 = uVar2;
  return 0;
}


/* EXPORT index=114 ELF_VA=0x1aa40 size=252 source_sha256=56792fc8aa00e1624fddeb95ac334a03e2b00f6ca7a4c65f29a42ab7b2c4c349 */

undefined8 j___I_l5__I__lI_lSOSO_lIl_S_0llII_5I_llI5S5O50I5I0_S5_(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  uint uStack_48;
  undefined1 uStack_41;
  
  iVar4 = 0;
  uStack_48 = param_2;
  while (iVar4 == 0) {
    uStack_41 = 0xdf;
    iVar4 = 1;
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_41,1);
    if (lVar2 != 1) {
      *param_1 = 8;
      iVar4 = 4;
    }
  }
LAB_0011aaf0:
  uVar3 = 1;
  switch(iVar4) {
  case 1:
    goto switchD_0011ab08_caseD_1;
  default:
    do {
    } while( true );
  case 3:
    break;
  case 4:
    uVar3 = 0;
    break;
  case 5:
    uVar3 = 0;
    *param_1 = 0xf;
  }
  return uVar3;
switchD_0011ab08_caseD_1:
  uVar1 = (uStack_48 & 0xff00ff00) >> 8 | (uStack_48 & 0xff00ff) << 8;
  uStack_48 = uVar1 >> 0x10 | uVar1 << 0x10;
  lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_48,4);
  iVar4 = 5;
  if (lVar2 != 0) {
    iVar4 = 3;
  }
  goto LAB_0011aaf0;
}


/* EXPORT index=115 ELF_VA=0x1ab50 size=420 source_sha256=119c647fd4430376206db10a21add298f2ef224b99313f9bb92a8ce3d0c261ff */

undefined4 j___Il__I_5I_0l_IlOIS_lISlI_IS_0O50l__I0OlOl_IISII_S5_(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bStack_31;
  ushort uStack_30;
  undefined1 uStack_2d;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 uStack_21;
  
  if (param_2 < 0x10) {
    if ((param_2 & 0xff) < 0x10) {
      bStack_31 = (byte)param_2 | 0x80;
      uVar4 = 1;
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&bStack_31,1);
      if (lVar2 != 1) {
        uVar4 = 0;
        *param_1 = 6;
      }
    }
    else {
      uVar4 = 0;
      *param_1 = 5;
    }
  }
  else {
    if (param_2 >> 0x10 != 0) {
      uStack_2c = 0;
      uStack_21 = 0xdf;
      uVar3 = 1;
      uStack_28 = param_2;
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
      if (lVar2 != 1) {
        *param_1 = 8;
        uVar3 = 4;
      }
      do {
        uVar4 = 1;
        switch(uVar3) {
        case 1:
          uVar1 = (uStack_28 & 0xff00ff00) >> 8 | (uStack_28 & 0xff00ff) << 8;
          uStack_28 = uVar1 >> 0x10 | uVar1 << 0x10;
          lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_28,4);
          uVar3 = 5;
          if (lVar2 != 0) {
            uVar3 = 3;
          }
          break;
        default:
          do {
          } while( true );
        case 3:
          goto switchD_0011acb4_caseD_3;
        case 4:
          uVar4 = 0;
          goto switchD_0011acb4_caseD_3;
        case 5:
          goto switchD_0011acb4_caseD_5;
        }
      } while( true );
    }
    uStack_30 = (ushort)param_2;
    uStack_2d = 0xde;
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_2d,1);
    if (lVar2 == 1) {
      uStack_30 = (ushort)(param_2 >> 8) & 0xff | (ushort)((param_2 & 0xff00ff) << 8);
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_30,2);
      if (lVar2 == 0) {
switchD_0011acb4_caseD_5:
        uVar4 = 0;
        *param_1 = 0xf;
      }
      else {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = 0;
      *param_1 = 8;
    }
  }
switchD_0011acb4_caseD_3:
  return uVar4;
}


/* EXPORT index=116 ELF_VA=0x1ad08 size=240 source_sha256=aeb1c9ecc850bb7520d649a9ce1dc48ef10662235772b2fe77831053da8cc02a */

undefined8
j____OO_I_I_0lI_SIOIS__I_ll_O0IISlO0I_SS_I0llI__SSSS5_(undefined1 *param_1,undefined1 param_2)

{
  long lVar1;
  undefined4 uVar2;
  undefined1 uStack_52;
  undefined1 uStack_51;
  
  uVar2 = 0;
  uStack_52 = param_2;
  do {
    switch(uVar2) {
    case 0:
      uStack_51 = 0xd4;
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_51,1);
      uVar2 = 3;
      if (lVar1 != 1) {
        *param_1 = 8;
        uVar2 = 2;
      }
      break;
    case 1:
      return 1;
    case 2:
      return 0;
    case 3:
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_52,1);
      uVar2 = 4;
      if (lVar1 != 0) {
        uVar2 = 1;
      }
      break;
    case 4:
      *param_1 = 0xc;
      return 0;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=117 ELF_VA=0x1ae0c size=288 source_sha256=e354b1e971c5e38eadd7e260ea22e281b3e65ec09ff59c47081a8183c6a9de2a */

undefined4
j___I0IIl_S__S5_0II_5_0I00l_lO_ISl5O_O0llIIlOIlSOllS5_
          (undefined1 *param_1,undefined1 param_2,undefined8 param_3)

{
  long lVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 uStack_62;
  undefined1 uStack_61;
  
  uVar4 = 0;
  uStack_62 = param_2;
  do {
    uVar3 = 0;
    switch(uVar4) {
    case 0:
      uStack_61 = 0xd4;
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
      uVar4 = 3;
      if (lVar1 != 1) {
        *param_1 = 8;
        uVar4 = 2;
      }
      break;
    case 1:
      uVar3 = 1;
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,param_3,1);
      if (lVar1 == 0) {
        uVar2 = 10;
LAB_0011af04:
        uVar3 = 0;
        *param_1 = uVar2;
      }
    case 2:
      return uVar3;
    case 3:
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_62,1);
      uVar4 = 4;
      if (lVar1 != 0) {
        uVar4 = 1;
      }
      break;
    case 4:
      uVar2 = 0xc;
      goto LAB_0011af04;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=118 ELF_VA=0x1af40 size=236 source_sha256=f57ac49989218b6ae8b5b970ec392907565a6533b6cca75fbee095055d6bf942 */

undefined8
j____S5___II_SI_IlS0S__0lI5_OII5l_llO_I00S_IOII_llIS5_(undefined1 *param_1,undefined1 param_2)

{
  long lVar1;
  int iVar2;
  undefined1 uStack_42;
  undefined1 uStack_41;
  
  iVar2 = 4;
  uStack_42 = param_2;
  while( true ) {
    while (iVar2 == 5) {
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_42,1);
      iVar2 = 0;
      if (lVar1 != 0) {
        iVar2 = 2;
      }
    }
    if (iVar2 == 0) {
      *param_1 = 0xc;
      return 0;
    }
    if (iVar2 == 1) {
      return 0;
    }
    if (iVar2 != 4) break;
    uStack_41 = 0xd5;
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_41,1);
    iVar2 = 5;
    if (lVar1 != 1) {
      *param_1 = 8;
      iVar2 = 1;
    }
  }
  if (iVar2 == 2) {
    return 1;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* EXPORT index=119 ELF_VA=0x1b02c size=632 source_sha256=d3d25f94780ebda4e2f6c30269898b072b12d2bb475407f4169346bef9a9a667 */

undefined8
j___lIl_0_5lII____IlI_l5_II_5l__lll___IOSl_O__OSSSIS5_
          (undefined1 *param_1,undefined1 param_2,undefined8 param_3)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 uStack_69;
  undefined4 uStack_68;
  undefined1 uStack_62;
  undefined1 uStack_61;
  
  uVar2 = 0x154e;
  iVar4 = 4;
LAB_0011b0a4:
  do {
    switch(iVar4) {
    case 0:
      *param_1 = 10;
      return 0;
    case 1:
    case 6:
      goto switchD_0011b0c8_caseD_2;
    case 2:
      return 1;
    case 3:
      goto switchD_0011b0c8_caseD_3;
    case 4:
      uStack_68 = 0;
      iVar3 = 4;
      uStack_62 = param_2;
      goto LAB_0011b1b8;
    case 5:
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,param_3,2);
      iVar4 = 0x20;
      if (lVar1 != 0) {
        iVar4 = 0x22;
      }
      iVar4 = iVar4 - uVar2 % 0x95;
      if (iVar4 == 6) {
switchD_0011b0c8_caseD_2:
        return 0;
      }
      break;
    default:
      goto switchD_0011b0c8_default;
    }
  } while( true );
switchD_0011b0c8_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
LAB_0011b1b8:
  while (iVar3 == 5) {
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_62,1);
    iVar3 = 0;
    if (lVar1 != 0) {
      iVar3 = 2;
    }
  }
  if (iVar3 == 0) {
    *param_1 = 0xc;
    uVar2 = 0x5dd5;
    iVar4 = 1;
    goto LAB_0011b0a4;
  }
  if (iVar3 == 1) {
    uVar2 = 0x5dd5;
    iVar4 = 1;
    goto LAB_0011b0a4;
  }
  if (iVar3 == 4) {
    uStack_61 = 0xd5;
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
    iVar3 = 5;
    if (lVar1 != 1) {
      *param_1 = 8;
      iVar3 = 1;
    }
    goto LAB_0011b1b8;
  }
  uVar2 = 0x5dd5;
  iVar4 = 5;
  if (iVar3 != 2) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  goto LAB_0011b0a4;
switchD_0011b0c8_caseD_3:
  iVar3 = 4;
  uStack_69 = param_2;
  while( true ) {
    while (iVar3 == 5) {
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_69,1);
      iVar3 = 0;
      if (lVar1 != 0) {
        iVar3 = 2;
      }
    }
    if (iVar3 == 0) {
      *param_1 = 0xc;
      uVar2 = 0x19bc;
      iVar4 = 5;
      goto LAB_0011b0a4;
    }
    if (iVar3 == 1) {
      uVar2 = 0x19bc;
      iVar4 = 5;
      goto LAB_0011b0a4;
    }
    if (iVar3 != 4) break;
    uStack_61 = 0xd5;
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
    iVar3 = 5;
    if (lVar1 != 1) {
      *param_1 = 8;
      iVar3 = 1;
    }
  }
  iVar4 = 0;
  uVar2 = 0x19bc;
  if (iVar3 != 2) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  goto LAB_0011b0a4;
}


/* EXPORT index=120 ELF_VA=0x1b2c0 size=128 source_sha256=5f00f847bdc1e2077a7c522bae44acf226e04c7b6349b31c47cbb0254f6577dc */

undefined4
j___Il_lS__lI___IlIIO_I_l_I_5_lSO5I_S_O_l_IlO0_llIlS5_(undefined1 *param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 uVar2;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  uStack_21 = 0xd6;
  uStack_22 = param_2;
  lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar1 == 1) {
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_22,1);
    if (lVar1 != 0) {
      return 1;
    }
    uVar2 = 0xc;
  }
  else {
    uVar2 = 8;
  }
  *param_1 = uVar2;
  return 0;
}


/* EXPORT index=121 ELF_VA=0x1b340 size=352 source_sha256=f23ba483882b513a5c1fae56350f05137a8e88674b541c436d8b6de21da30551 */

undefined8
j___IISIl_555OI_IllSS_5_I_I___I50lI_S_I005OlIO_0__lS5_
          (undefined1 *param_1,undefined1 param_2,undefined8 param_3)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined1 uStack_62;
  undefined1 uStack_61;
  
  iVar3 = 3;
  uVar2 = 0x3432;
LAB_0011b3b0:
  do {
    switch(iVar3) {
    case 0:
      *param_1 = 10;
      return 0;
    case 1:
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,param_3,4);
      iVar3 = 6;
      if (lVar1 != 0) {
        iVar3 = 8;
      }
      iVar3 = iVar3 - uVar2 % 0x13;
      if (iVar3 == 5) {
switchD_0011b3d4_caseD_2:
        return 0;
      }
      break;
    case 2:
      return 1;
    case 3:
      goto switchD_0011b3d4_caseD_3;
    case 4:
    case 5:
      goto switchD_0011b3d4_caseD_2;
    default:
      goto switchD_0011b3d4_default;
    }
  } while( true );
switchD_0011b3d4_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_0011b3d4_caseD_3:
  uStack_61 = 0xd6;
  uStack_62 = param_2;
  lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
  if (lVar1 == 1) {
    iVar3 = 1;
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_62,1);
    uVar2 = 0x7c0b;
    if (lVar1 == 0) {
      *param_1 = 0xc;
      iVar3 = 4;
      uVar2 = 0x7c0b;
    }
  }
  else {
    *param_1 = 8;
    iVar3 = 4;
    uVar2 = 0x7c0b;
  }
  goto LAB_0011b3b0;
}


/* EXPORT index=122 ELF_VA=0x1b4b8 size=128 source_sha256=1673029304b900f15861b8350faf6b2e066930ec45904d9e2017dbb29e1d947b */

undefined4
j___S_I___5_I0I__5III_0llIS_l5Il_lS_Ill5IO_O_I0IOI_S5_(undefined1 *param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 uVar2;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  uStack_21 = 0xd7;
  uStack_22 = param_2;
  lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar1 == 1) {
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_22,1);
    if (lVar1 != 0) {
      return 1;
    }
    uVar2 = 0xc;
  }
  else {
    uVar2 = 8;
  }
  *param_1 = uVar2;
  return 0;
}


/* EXPORT index=123 ELF_VA=0x1b538 size=376 source_sha256=bdd968fefc231e22ec24d0422f6d9e8c99a3479497c1943a3beb2cbc7dcf7ddc */

undefined8
j___I5SI__l_0IS_O0IS5__IIll_00I5l_l5lI0llI_lI5_II5_S5_
          (undefined1 *param_1,undefined1 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined1 uStack_62;
  undefined1 uStack_61;
  
  iVar4 = 3;
  iVar3 = 0x3e38;
LAB_0011b594:
  do {
    uVar1 = 0;
    switch(iVar4) {
    case 0:
    case 2:
    case 6:
      goto switchD_0011b5b8_caseD_0;
    case 1:
      goto switchD_0011b5b8_caseD_1;
    case 3:
      goto switchD_0011b5b8_caseD_3;
    case 4:
      *param_1 = 10;
      return 0;
    case 5:
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,param_3,8);
      iVar4 = 0x28;
      if (lVar2 != 0) {
        iVar4 = 0x26;
      }
      iVar4 = iVar4 - (iVar3 + ((uint)(iVar3 * 0xcf65) >> 0x16) * -0x4f);
      if (iVar4 == 6) goto switchD_0011b5b8_caseD_0;
      break;
    default:
      goto switchD_0011b5b8_default;
    }
  } while( true );
switchD_0011b5b8_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_0011b5b8_caseD_3:
  uStack_61 = 0xd7;
  iVar3 = iVar3 + ((uint)(iVar3 * 0xbe83) >> 0x15) * -0x2b;
  uStack_62 = param_2;
  lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
  if (lVar2 == 1) {
    lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_62,1);
    if (lVar2 != 0) {
      iVar4 = 0x17;
      goto LAB_0011b660;
    }
    *param_1 = 0xc;
  }
  else {
    *param_1 = 8;
  }
  iVar4 = 0x13;
LAB_0011b660:
  iVar4 = iVar4 - iVar3;
  iVar3 = 0x5388 - iVar3;
  if (iVar4 == 6) {
switchD_0011b5b8_caseD_0:
    uVar1 = 1;
switchD_0011b5b8_caseD_1:
    return uVar1;
  }
  goto LAB_0011b594;
}


/* EXPORT index=124 ELF_VA=0x1b6cc size=128 source_sha256=c601b17d0740651491beba0fc108a8684f87af31512ce14648320638b623a3ef */

undefined4
j___l5OS0_l0_OI__5S5l_Il_lI__IOlI5Ill5I_I_l05l_OIIlS5_(undefined1 *param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 uVar2;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  uStack_21 = 0xd8;
  uStack_22 = param_2;
  lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_21,1);
  if (lVar1 == 1) {
    lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_22,1);
    if (lVar1 != 0) {
      return 1;
    }
    uVar2 = 0xc;
  }
  else {
    uVar2 = 8;
  }
  *param_1 = uVar2;
  return 0;
}


/* EXPORT index=125 ELF_VA=0x1b74c size=292 source_sha256=fda4cb9222ee22d35dea048c6aa84ef3481957e7cf782bae9057cfc93c3c3603 */

undefined8
j___Ill_S_Oll___OlSSO_II5lI_II5lI5Il5I_Illl5lISS_lOS5_
          (undefined1 *param_1,undefined1 param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 uVar2;
  undefined1 uStack_62;
  undefined1 uStack_61;
  
  uVar2 = 1;
  do {
    switch(uVar2) {
    case 0:
      return 1;
    case 1:
      uStack_61 = 0xd8;
      uStack_62 = param_2;
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
      if (lVar1 == 1) {
        lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_62,1);
        uVar2 = 4;
        if (lVar1 == 0) {
          *param_1 = 0xc;
          uVar2 = 2;
        }
      }
      else {
        *param_1 = 8;
        uVar2 = 2;
      }
      break;
    case 2:
      return 0;
    case 3:
      *param_1 = 10;
      return 0;
    case 4:
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,param_3,0x10);
      uVar2 = 3;
      if (lVar1 != 0) {
        uVar2 = 0;
      }
      break;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=126 ELF_VA=0x1b884 size=328 source_sha256=e27e493774fed6273171f969d7e11461b0e562011e09b747463bba3971418ff3 */

undefined8
j___5lIOl_5_II__50IlI_l_lIl_I_l_IllOOIO__0_50IlSIOIS5_
          (undefined1 *param_1,undefined1 param_2,undefined1 param_3)

{
  long lVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 uStack_63;
  undefined1 uStack_62;
  undefined1 uStack_61;
  
  iVar3 = 7;
  uStack_63 = param_3;
  uStack_62 = param_2;
  while( true ) {
    while (iVar3 == 1) {
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_63,1);
      iVar3 = 5;
      if (lVar1 != 0) {
        iVar3 = 2;
      }
    }
    if (iVar3 == 3) break;
    if (iVar3 == 4) {
      return 1;
    }
    switch(iVar3) {
    case 2:
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_62,1);
      iVar3 = 3;
      if (lVar1 != 0) {
        iVar3 = 4;
      }
      break;
    default:
      do {
      } while( true );
    case 5:
      uVar2 = 0xf;
      goto LAB_0011b994;
    case 6:
      goto switchD_0011b930_caseD_6;
    case 7:
      uStack_61 = 199;
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
      iVar3 = 1;
      if (lVar1 != 1) {
        *param_1 = 8;
        iVar3 = 6;
      }
    }
  }
  uVar2 = 0xc;
LAB_0011b994:
  *param_1 = uVar2;
switchD_0011b930_caseD_6:
  return 0;
}


/* EXPORT index=127 ELF_VA=0x1b9e4 size=344 source_sha256=c3a662a264933e19e6d411a3a02143ab2378a73acd0b812da35efc2fe8c52e63 */

undefined8
j___OlIII_I0O___O0O_l_O5llO__SI_IlII_II5I_50_OS___5S5_
          (undefined1 *param_1,undefined1 param_2,undefined1 param_3,undefined8 param_4)

{
  long lVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined1 uStack_63;
  undefined1 uStack_62;
  undefined1 uStack_61;
  
  uVar3 = 7;
  uStack_63 = param_3;
  uStack_62 = param_2;
  do {
    switch(uVar3) {
    case 1:
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_63,1);
      uVar3 = 5;
      if (lVar1 != 0) {
        uVar3 = 2;
      }
      break;
    case 2:
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_62,1);
      uVar3 = 3;
      if (lVar1 != 0) {
        uVar3 = 4;
      }
      break;
    case 3:
      uVar2 = 0xc;
LAB_0011bb18:
      *param_1 = uVar2;
      return 0;
    case 4:
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,param_4,param_3);
      if (lVar1 != 0) {
        return 1;
      }
      uVar2 = 10;
      goto LAB_0011bb18;
    case 5:
      uVar2 = 0xf;
      goto LAB_0011bb18;
    case 6:
      return 0;
    case 7:
      uStack_61 = 199;
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
      uVar3 = 1;
      if (lVar1 != 1) {
        *param_1 = 8;
        uVar3 = 6;
      }
      break;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=128 ELF_VA=0x1bb58 size=328 source_sha256=ea17ead7808deaab3716ea04613ed8f9d868544e05e56ea202cd6754dc468ff4 */

undefined8
j____I5S5_IIl5l__lIlI____I__lIlS___l0ll_Il55_IIIII_S5_
          (undefined1 *param_1,undefined1 param_2,ushort param_3)

{
  undefined8 uVar1;
  long lVar2;
  undefined1 uVar3;
  int iVar4;
  ushort uStack_64;
  undefined1 uStack_62;
  undefined1 uStack_61;
  
  iVar4 = 1;
  uStack_64 = param_3;
  uStack_62 = param_2;
  while( true ) {
    if (iVar4 == 3) {
      return 0;
    }
    if (iVar4 == 9) break;
    uVar1 = 1;
    switch(iVar4) {
    case 0:
      goto switchD_0011bc0c_caseD_0;
    case 1:
      uStack_61 = 200;
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
      iVar4 = 6;
      if (lVar2 != 1) {
        *param_1 = 8;
        iVar4 = 3;
      }
      break;
    case 2:
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_62,1);
      iVar4 = 0;
      if (lVar2 == 0) {
        uVar3 = 0xc;
LAB_0011bc98:
        uVar1 = 0;
        *param_1 = uVar3;
switchD_0011bc0c_caseD_0:
        return uVar1;
      }
      break;
    default:
      goto switchD_0011bc0c_caseD_3;
    case 6:
      uStack_64 = uStack_64 >> 8 | uStack_64 << 8;
      lVar2 = (**(code **)(param_1 + 0x18))(param_1,&uStack_64,2);
      iVar4 = 9;
      if (lVar2 != 0) {
        iVar4 = 2;
      }
    }
  }
  uVar3 = 0xf;
  goto LAB_0011bc98;
switchD_0011bc0c_caseD_3:
  do {
  } while( true );
}


/* EXPORT index=129 ELF_VA=0x1bcbc size=356 source_sha256=8c74bd9bcf5e5ef201e12be02ba88eb842a398085d849e8a56c7da949e53841c */

undefined8
j___l0O_I_IS_O5_lO5ll__O_Sl_l5IIS_l_IIS00_I_5ISO_I_S5_
          (undefined1 *param_1,undefined1 param_2,ushort param_3,undefined8 param_4)

{
  long lVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  ushort uStack_64;
  undefined1 uStack_62;
  undefined1 uStack_61;
  
  uVar3 = 1;
  uStack_64 = param_3;
  uStack_62 = param_2;
  do {
    switch(uVar3) {
    case 0:
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,param_4,param_3);
      if (lVar1 != 0) {
        return 1;
      }
      uVar2 = 10;
      goto LAB_0011bdfc;
    case 1:
      uStack_61 = 200;
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
      uVar3 = 6;
      if (lVar1 != 1) {
        *param_1 = 8;
        uVar3 = 3;
      }
      break;
    case 2:
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_62,1);
      uVar3 = 0;
      if (lVar1 == 0) {
        uVar2 = 0xc;
LAB_0011bdfc:
        *param_1 = uVar2;
switchD_0011bd68_caseD_3:
        return 0;
      }
      break;
    case 3:
      goto switchD_0011bd68_caseD_3;
    default:
      do {
      } while( true );
    case 6:
      uStack_64 = uStack_64 >> 8 | uStack_64 << 8;
      lVar1 = (**(code **)(param_1 + 0x18))(param_1,&uStack_64,2);
      uVar3 = 9;
      if (lVar1 != 0) {
        uVar3 = 2;
      }
      break;
    case 9:
      uVar2 = 0xf;
      goto LAB_0011bdfc;
    }
  } while( true );
}


/* EXPORT index=130 ELF_VA=0x1be48 size=336 source_sha256=4f56717ab74446711f7a55423b5a602b7a0721dc2d39b2e6106ab0e9a8cab696 */

undefined8
j___00III_lS5SI_I055I__0S_5_IIll05l5SI5_I0lO5II5_I0S5_
          (undefined1 *param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  uint uStack_68;
  undefined1 uStack_62;
  undefined1 uStack_61;
  
  cVar2 = '\x05';
  uStack_68 = param_3;
  uStack_62 = param_2;
LAB_0011bed0:
  while( true ) {
    while (cVar2 == '\x05') {
      uStack_61 = 0xc9;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
      cVar2 = '\x06';
      if (lVar3 != 1) {
        *param_1 = 8;
        cVar2 = '\x03';
      }
    }
    if (cVar2 != '\x06') break;
    uVar1 = (uStack_68 & 0xff00ff00) >> 8 | (uStack_68 & 0xff00ff) << 8;
    uStack_68 = uVar1 >> 0x10 | uVar1 << 0x10;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_68,4);
    cVar2 = '\x02';
    if (lVar3 != 0) {
      cVar2 = '\x04';
    }
  }
  if (cVar2 == '\x03') {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
    switch(cVar2) {
    case '\0':
      goto switchD_0011bf00_caseD_0;
    case '\x01':
      uVar5 = 0xc;
      break;
    case '\x02':
      uVar5 = 0xf;
      break;
    default:
      goto switchD_0011bf00_caseD_3;
    case '\x04':
      goto switchD_0011bf00_caseD_4;
    }
    uVar4 = 0;
    *param_1 = uVar5;
  }
switchD_0011bf00_caseD_0:
  return uVar4;
switchD_0011bf00_caseD_4:
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_62,1);
  cVar2 = lVar3 == 0;
  goto LAB_0011bed0;
switchD_0011bf00_caseD_3:
  do {
  } while( true );
}


/* EXPORT index=131 ELF_VA=0x1bfac size=356 source_sha256=9417b04172e6b8eebf776b93714e43cb523a4ff2319a02ce15b77c6ac31e4791 */

undefined8
j_____I5I_0lllI_50III_IO5_O_0ISIll_I_OI55llOI_IIIS5S5_
          (undefined1 *param_1,undefined1 param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  undefined1 uVar2;
  long lVar3;
  uint uStack_68;
  undefined1 uStack_62;
  undefined1 uStack_61;
  
  uVar2 = 5;
  uStack_68 = param_3;
  uStack_62 = param_2;
  do {
    switch(uVar2) {
    case 0:
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,param_4,param_3);
      if (lVar3 != 0) {
        return 1;
      }
      uVar2 = 10;
LAB_0011c0ec:
      *param_1 = uVar2;
      return 0;
    case 1:
      uVar2 = 0xc;
      goto LAB_0011c0ec;
    case 2:
      uVar2 = 0xf;
      goto LAB_0011c0ec;
    case 3:
      return 0;
    case 4:
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_62,1);
      uVar2 = lVar3 == 0;
      break;
    case 5:
      uStack_61 = 0xc9;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
      uVar2 = 6;
      if (lVar3 != 1) {
        *param_1 = 8;
        uVar2 = 3;
      }
      break;
    case 6:
      uVar1 = (uStack_68 & 0xff00ff00) >> 8 | (uStack_68 & 0xff00ff) << 8;
      uStack_68 = uVar1 >> 0x10 | uVar1 << 0x10;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_68,4);
      uVar2 = 2;
      if (lVar3 != 0) {
        uVar2 = 4;
      }
      break;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=132 ELF_VA=0x1c12c size=2140 source_sha256=88a0172633d178e8cb760a3754cd890887b02e0b679d23cb4adc7b7e521424cc */

/* WARNING: Exceeded maximum restarts with more pending */

undefined4
j___lI0II__SllI_O5OI__l_5_O_I5IIOl_OS_OI0ISSI500llSS5_
          (undefined1 *param_1,undefined1 param_2,uint param_3)

{
  int iVar1;
  char cVar2;
  long lVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  undefined1 uStack_95;
  undefined4 uStack_94;
  uint uStack_90;
  undefined1 uStack_89;
  undefined4 uStack_88;
  undefined1 uStack_82;
  undefined1 uStack_81;
  undefined4 uStack_80;
  undefined1 uStack_7c;
  undefined1 uStack_7b;
  undefined1 uStack_7a;
  undefined1 uStack_79;
  undefined4 uStack_78;
  undefined2 uStack_74;
  undefined1 uStack_72;
  undefined1 uStack_71;
  undefined4 uStack_70;
  undefined1 uStack_6a;
  undefined1 uStack_69;
  undefined4 uStack_68;
  undefined2 uStack_64;
  undefined1 uStack_62;
  undefined1 uStack_61;
  
  iVar5 = 7;
  iVar6 = 0xc;
  uVar14 = 0;
  uVar8 = 0x1cff;
  iVar7 = 4;
  iVar11 = 1;
  if (param_3 != 2) {
    iVar11 = 5;
  }
  if (0xff < param_3) {
    iVar5 = 0xe;
  }
  if (param_3 != 4) {
    iVar6 = 0x11;
  }
  iVar12 = 10;
  iVar1 = 2;
  if (0xffff < param_3) {
    iVar1 = iVar12;
  }
  if (param_3 != 8) {
    iVar12 = 0x10;
  }
  iVar13 = 0x12;
  if (param_3 != 0x10) {
    iVar13 = 0xf;
  }
switchD_0011c200_default:
  uStack_82 = (undefined1)param_3;
  uStack_74 = (undefined2)param_3;
  switch(iVar7) {
  case 0:
    iVar7 = iVar13;
    goto switchD_0011c200_default;
  case 1:
    goto switchD_0011c200_caseD_1;
  case 2:
    uStack_78 = 0;
    iVar11 = 1;
    uStack_72 = param_2;
    goto LAB_0011c7f4;
  case 3:
    uStack_61 = 0xd7;
    uStack_7a = param_2;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
    if (lVar3 != 1) {
LAB_0011c7b8:
      *param_1 = 8;
      return 0;
    }
    pcVar10 = *(code **)(param_1 + 0x18);
    puVar4 = &uStack_7a;
    break;
  case 4:
    if (param_3 == 1) {
      iVar7 = 0x40 - uVar8 % 0x61;
    }
    else {
      iVar7 = 0x3e - uVar8 % 0x61;
    }
    goto switchD_0011c200_default;
  case 5:
    uVar8 = 0x539;
    iVar7 = iVar6;
    goto switchD_0011c200_default;
  case 6:
    iVar7 = iVar12;
    goto switchD_0011c200_default;
  case 7:
    uStack_88 = 0;
    iVar11 = 7;
    uStack_81 = param_2;
    goto LAB_0011c3d0;
  case 8:
    uStack_68 = 0;
    iVar11 = 1;
    uStack_64 = uStack_74;
    uStack_62 = param_2;
    goto LAB_0011c8a0;
  case 9:
    uStack_61 = 0xd7;
    uStack_71 = param_2;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
    if (lVar3 != 1) goto LAB_0011c7b8;
    pcVar10 = *(code **)(param_1 + 0x18);
    puVar4 = &uStack_71;
    break;
  case 10:
    uStack_94 = 0;
    cVar2 = '\x05';
    uStack_90 = param_3;
    uStack_89 = param_2;
    goto LAB_0011c530;
  case 0xb:
    iVar7 = iVar11;
    goto switchD_0011c200_default;
  case 0xc:
    uStack_61 = 0xd6;
    uStack_79 = param_2;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
    if (lVar3 != 1) goto LAB_0011c7b8;
    pcVar10 = *(code **)(param_1 + 0x18);
    puVar4 = &uStack_79;
    break;
  case 0xd:
    uVar9 = 0;
    uStack_70 = 0;
    uStack_6a = param_2;
    goto LAB_0011c63c;
  case 0xe:
    iVar7 = iVar1;
    goto switchD_0011c200_default;
  case 0xf:
    iVar7 = iVar5;
    goto switchD_0011c200_default;
  case 0x10:
    uStack_80 = 0;
    iVar11 = 7;
    uStack_7c = uStack_82;
    uStack_7b = param_2;
    goto LAB_0011c6e4;
  case 0x11:
    goto switchD_0011c200_caseD_11;
  case 0x12:
    uStack_61 = 0xd8;
    uStack_69 = param_2;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
    if (lVar3 != 1) goto LAB_0011c7b8;
    pcVar10 = *(code **)(param_1 + 0x18);
    puVar4 = &uStack_69;
    break;
  case 0x13:
    goto switchD_0011c200_caseD_13;
  default:
    goto switchD_0011c200_default;
  }
  lVar3 = (*pcVar10)(param_1,puVar4,1);
  if (lVar3 != 0) {
    return 1;
  }
  goto switchD_0011c560_caseD_1;
switchD_0011c200_caseD_11:
  if (param_3 == 8) {
    iVar7 = 0x1a - uVar8 % 0x49;
  }
  else {
    iVar7 = 0x17 - uVar8 % 0x49;
  }
  goto switchD_0011c200_default;
LAB_0011c6e4:
  while (iVar11 == 1) {
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_7c,1);
    iVar11 = 5;
    if (lVar3 != 0) {
      iVar11 = 2;
    }
  }
  if (iVar11 == 3) goto switchD_0011c560_caseD_1;
  if (iVar11 == 4) {
    return 1;
  }
  uVar14 = 0;
  switch(iVar11) {
  case 2:
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_7b,1);
    iVar11 = 3;
    if (lVar3 != 0) {
      iVar11 = 4;
    }
    break;
  default:
    do {
    } while( true );
  case 5:
    goto switchD_0011c714_caseD_5;
  case 6:
    goto switchD_0011c200_caseD_13;
  case 7:
    uStack_61 = 199;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
    iVar11 = 1;
    if (lVar3 != 1) {
      *param_1 = 8;
      iVar11 = 6;
    }
  }
  goto LAB_0011c6e4;
LAB_0011c63c:
  switch(uVar9) {
  case 0x11c658:
    break;
  default:
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
                    /* WARNING: This code block may not be properly labeled as switch case */
  uStack_61 = 0xd4;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
  uVar9 = 3;
  if (lVar3 != 1) {
    *param_1 = 8;
    uVar9 = 2;
  }
  goto LAB_0011c63c;
LAB_0011c530:
  while( true ) {
    while (cVar2 == '\x05') {
      uStack_61 = 0xc9;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
      cVar2 = '\x06';
      if (lVar3 != 1) {
        *param_1 = 8;
        cVar2 = '\x03';
      }
    }
    if (cVar2 != '\x06') break;
    uVar8 = (uStack_90 & 0xff00ff00) >> 8 | (uStack_90 & 0xff00ff) << 8;
    uStack_90 = uVar8 >> 0x10 | uVar8 << 0x10;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_90,4);
    cVar2 = '\x02';
    if (lVar3 != 0) {
      cVar2 = '\x04';
    }
  }
  if (cVar2 == '\x03') {
    return 0;
  }
  uVar14 = 1;
  switch(cVar2) {
  case '\0':
    goto switchD_0011c200_caseD_13;
  case '\x01':
    goto switchD_0011c560_caseD_1;
  case '\x02':
    goto switchD_0011c714_caseD_5;
  default:
    break;
  case '\x04':
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_89,1);
    cVar2 = lVar3 == 0;
    goto LAB_0011c530;
  }
  do {
  } while( true );
LAB_0011c8a0:
  if (iVar11 == 3) {
    return 0;
  }
  if (iVar11 != 9) {
    switch(iVar11) {
    case 0x11c8cc:
      goto switchD_0011c8c8_caseD_11c8cc;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  goto switchD_0011c714_caseD_5;
switchD_0011c8c8_caseD_11c8cc:
                    /* WARNING: This code block may not be properly labeled as switch case */
  uStack_61 = 200;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
  iVar11 = 6;
  if (lVar3 != 1) {
    *param_1 = 8;
    iVar11 = 3;
  }
  goto LAB_0011c8a0;
LAB_0011c3d0:
  while (iVar11 == 1) {
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_82,1);
    iVar11 = 5;
    if (lVar3 != 0) {
      iVar11 = 2;
    }
  }
  if (iVar11 == 3) goto switchD_0011c560_caseD_1;
  if (iVar11 == 4) {
    return 1;
  }
  uVar14 = 0;
  switch(iVar11) {
  case 2:
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_81,1);
    iVar11 = 3;
    if (lVar3 != 0) {
      iVar11 = 4;
    }
    break;
  default:
    do {
    } while( true );
  case 5:
    goto switchD_0011c714_caseD_5;
  case 6:
    goto switchD_0011c200_caseD_13;
  case 7:
    uStack_61 = 199;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
    iVar11 = 1;
    if (lVar3 != 1) {
      *param_1 = 8;
      iVar11 = 6;
    }
  }
  goto LAB_0011c3d0;
LAB_0011c7f4:
  if (iVar11 == 3) {
    return 0;
  }
  if (iVar11 != 9) {
    switch(iVar11) {
    case 0x11c820:
      goto switchD_0011c81c_caseD_11c820;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  goto switchD_0011c714_caseD_5;
switchD_0011c81c_caseD_11c820:
                    /* WARNING: This code block may not be properly labeled as switch case */
  uStack_61 = 200;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
  iVar11 = 6;
  if (lVar3 != 1) {
    *param_1 = 8;
    iVar11 = 3;
  }
  goto LAB_0011c7f4;
switchD_0011c714_caseD_5:
  *param_1 = 0xf;
  return 0;
switchD_0011c200_caseD_1:
  iVar11 = 4;
  uStack_95 = param_2;
  while( true ) {
    while (iVar11 == 5) {
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_95,1);
      iVar11 = 0;
      if (lVar3 != 0) {
        iVar11 = 2;
      }
    }
    if (iVar11 == 0) break;
    if (iVar11 == 1) {
      return 0;
    }
    if (iVar11 != 4) {
      if (iVar11 != 2) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      uVar14 = 1;
switchD_0011c200_caseD_13:
      return uVar14;
    }
    uStack_61 = 0xd5;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_61,1);
    iVar11 = 5;
    if (lVar3 != 1) {
      *param_1 = 8;
      iVar11 = 1;
    }
  }
switchD_0011c560_caseD_1:
  *param_1 = 0xc;
  return 0;
}


/* EXPORT index=133 ELF_VA=0x1ca68 size=2936 source_sha256=8cf052d433a3fbf17dd8783be22ff0e4cd2e1937a77a450c5b73bb2b5e1971f6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Exceeded maximum restarts with more pending */

uint j___50_Ol_lI5lI__l5l___IIl5_Il0ISl5l5lOII__lOII0IlIS5_
               (undefined1 *param_1,undefined4 param_2,uint param_3,ulong param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  byte *pbVar8;
  long lVar9;
  int iVar10;
  undefined1 *puVar11;
  ulong uVar12;
  int iVar13;
  undefined8 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  byte *pbVar18;
  uint uVar19;
  uint uVar20;
  uint unaff_w24;
  int iVar21;
  undefined1 auVar22 [16];
  undefined1 uStack_c1;
  undefined4 uStack_c0;
  undefined1 uStack_b9;
  undefined4 uStack_b8;
  undefined1 uStack_b2;
  undefined1 uStack_b1;
  byte abStack_b0 [56];
  undefined1 auStack_78 [16];
  long lStack_68;
  
  lStack_68 = ___stack_chk_guard;
  abStack_b0[0x25] = 0xf;
  abStack_b0[0x26] = 0x5b;
  abStack_b0[0x27] = 100;
  abStack_b0[0x28] = 0x67;
  abStack_b0[0x29] = 0x16;
  abStack_b0[0x2a] = 0xf;
  abStack_b0[0x2b] = 0x4e;
  abStack_b0[0x2c] = 0x14;
  abStack_b0[0x20] = 6;
  abStack_b0[0x21] = 5;
  abStack_b0[0x22] = 0x73;
  abStack_b0[0x23] = 0x5c;
  abStack_b0[0x24] = 0x32;
  abStack_b0[0x18] = 0x38;
  abStack_b0[0x19] = 1;
  abStack_b0[0x1a] = 0x35;
  abStack_b0[0x1b] = 0x34;
  abStack_b0[0x1c] = 0x5a;
  abStack_b0[0x1d] = 0x58;
  abStack_b0[0x1e] = 0x16;
  abStack_b0[0x1f] = 0x44;
  abStack_b0[0x10] = 0x7c;
  abStack_b0[0x11] = 0x4b;
  abStack_b0[0x12] = 0x2b;
  abStack_b0[0x13] = 0x47;
  abStack_b0[0x14] = 0x25;
  abStack_b0[0x15] = 0x15;
  abStack_b0[0x16] = 0x6b;
  abStack_b0[0x17] = 0x3c;
  iVar17 = 7;
  pbVar18 = (byte *)0x1b;
  puVar11 = (undefined1 *)0x14;
  iVar10 = 6;
  uVar20 = 0x77d6;
  iVar21 = 0xb;
  if (param_3 != 2) {
    iVar21 = 0x16;
  }
  iVar3 = 0x16;
  if (param_3 != 1) {
    iVar3 = 0x19;
  }
  iVar15 = 0x17;
  if (param_3 != 1) {
    iVar15 = 0x19;
  }
  iVar16 = 0x13;
  if (param_3 != 4) {
    iVar16 = 0x1a;
  }
  if (0xffff < param_3) {
    iVar17 = 0xd;
  }
  abStack_b0[8] = 99;
  abStack_b0[9] = 0x36;
  abStack_b0[10] = 0x73;
  abStack_b0[0xb] = 0x7b;
  abStack_b0[0xc] = 0x7b;
  abStack_b0[0xd] = 0x77;
  abStack_b0[0xe] = 0x79;
  abStack_b0[0xf] = 0xf;
  abStack_b0[0] = 0x1d;
  abStack_b0[1] = 0x25;
  abStack_b0[2] = 0x10;
  abStack_b0[3] = 0x72;
  abStack_b0[4] = 0x7b;
  abStack_b0[5] = 0x4c;
  abStack_b0[6] = 9;
  abStack_b0[7] = 0x59;
  iVar7 = 0xc;
  if (param_3 != 0x10) {
    iVar7 = 0x1b;
  }
  if (param_3 != 8) {
    iVar10 = 0x14;
  }
  pbVar8 = (byte *)0xc;
  uVar12 = param_4;
  uVar19 = 0x43f092c2;
  iVar13 = 0xe;
  do {
    auVar22._8_8_ = puVar11;
    auVar22._0_8_ = pbVar8;
    bVar6 = (byte)uVar19;
    uVar4 = (undefined1)param_2;
    switch(iVar13) {
    case 0:
      goto switchD_0011cb84_caseD_0;
    case 1:
      puVar11 = (undefined1 *)(ulong)(uVar19 + 0x5cde6296);
      uVar12 = (ulong)(uVar19 + 0x2d725bb1);
      do {
        CallSupervisor(0);
      } while (pbVar18 == (byte *)0xfffffffffffffffc);
      iVar13 = 0x14;
      pbVar8 = pbVar18;
      break;
    case 2:
      iVar13 = uVar19 * uVar19 * 4;
      uVar12 = (ulong)(iVar13 + 0xe79a91b0);
      do {
        puVar11 = auStack_78;
        CallSupervisor(0);
      } while (pbVar18 == (byte *)0xfffffffffffffffc);
      uVar19 = iVar13 + 0xa0f96207;
      iVar13 = 1;
      pbVar8 = pbVar18;
      break;
    case 3:
      auVar22 = j___OlIII_I0O___O0O_l_O5llO__SI_IlII_II5I_50_OS___5S5_
                          (param_1,param_2,param_3,param_4);
      unaff_w24 = auVar22._0_4_;
      goto switchD_0011cb84_caseD_1d;
    case 4:
      abStack_b0[uVar19 ^ 0xdaf46934] = abStack_b0[uVar19 ^ 0xdaf46934] ^ bVar6 + 0x4f;
      uVar1 = uVar19 ^ 0xc3329f92;
      cVar5 = (char)uVar1;
      abStack_b0[uVar19 ^ 0xdaf4690c] = abStack_b0[uVar19 ^ 0xdaf4690c] ^ cVar5 + 0x73U;
      abStack_b0[uVar1 + 0xe6390942] = abStack_b0[uVar1 + 0xe6390942] ^ cVar5 + 0x7bU;
      abStack_b0[uVar19 ^ 0xdaf4693b] = abStack_b0[uVar19 ^ 0xdaf4693b] ^ cVar5 + 0x8dU;
      abStack_b0[uVar1 + 0xe6390954] = abStack_b0[uVar1 + 0xe6390954] ^ cVar5 + 0x74U;
      abStack_b0[uVar1 + 0xe639095f] = bVar6 ^ abStack_b0[uVar1 + 0xe639095f] ^ 0x49;
      iVar13 = 0x12;
      uVar19 = uVar1;
      break;
    case 5:
      iVar13 = iVar3;
      break;
    case 6:
      auVar22 = j___I5SI__l_0IS_O0IS5__IIll_00I5l_l5lI0llI_lI5_II5_S5_(param_1,param_2,param_4);
      unaff_w24 = auVar22._0_4_;
      goto switchD_0011cb84_caseD_1d;
    case 7:
      iVar13 = 0;
      break;
    case 8:
      abStack_b0[uVar19 + 0x112d539f] =
           (byte)(uVar19 + 0x68721e9b) ^ abStack_b0[uVar19 + 0x112d539f] ^ 4;
      uVar19 = (uVar19 + 0x68721e9b) * 2;
      bVar6 = (byte)uVar19;
      abStack_b0[uVar19 + 0x517669fe] = bVar6 ^ abStack_b0[uVar19 + 0x517669fe] ^ 0x2d;
      abStack_b0[uVar19 ^ 0xae89960e] = bVar6 ^ abStack_b0[uVar19 ^ 0xae89960e] ^ 0x68;
      abStack_b0[uVar19 + 0x51766a15] = abStack_b0[uVar19 + 0x51766a15] ^ bVar6 + 0x23;
      uVar12 = (ulong)(uVar19 + 0x28bf0fc4);
      do {
        puVar11 = (undefined1 *)0x0;
        pbVar18 = abStack_b0;
        CallSupervisor(0);
      } while (pbVar18 == (byte *)0xfffffffffffffffc);
      pbVar8 = pbVar18;
      iVar13 = 2;
      break;
    case 9:
      abStack_b0[0x22] = abStack_b0[0x22] ^ 0x39;
      abStack_b0[0x1a] = abStack_b0[0x1a] ^ 1;
      uVar19 = 0xdaf4692c;
      iVar13 = (5 - uVar20) + (uVar20 / 0x2f) * 0x2f;
      break;
    case 10:
      abStack_b0[uVar19 + 0x9bbb0013] = bVar6 ^ abStack_b0[uVar19 + 0x9bbb0013] ^ 0x22;
      abStack_b0[uVar19 + 0x9bbb0017] = abStack_b0[uVar19 + 0x9bbb0017] ^ bVar6 + 0x6b;
      uVar1 = uVar19 + 0x93245625 ^ 0xf7695629;
      abStack_b0[uVar19 + 0x9bbb0004] = abStack_b0[uVar19 + 0x9bbb0004] ^ bVar6 + 0x11;
      abStack_b0[uVar1] = abStack_b0[uVar1] ^ bVar6 + 4;
      abStack_b0[uVar19 + 0x9bbafff6] = abStack_b0[uVar19 + 0x9bbafff6] ^ bVar6 + 0x3b;
      uVar19 = (uVar19 + 0x93245625) * 2;
      iVar13 = 8;
      break;
    case 0xb:
      auVar22 = j___lIl_0_5lII____IlI_l5_II_5l__lll___IOSl_O__OSSSIS5_
                          (param_1,param_2,param_4,uVar12);
      unaff_w24 = auVar22._0_4_;
      goto switchD_0011cb84_caseD_1d;
    case 0xc:
      uStack_c0 = 0;
      uVar14 = 1;
      goto LAB_0011d310;
    case 0xd:
      auVar22 = j_____I5I_0lllI_50III_IO5_O_0ISIll_I_OI55llOI_IIIS5S5_
                          (param_1,param_2,param_3,param_4);
      unaff_w24 = auVar22._0_4_;
      goto switchD_0011cb84_caseD_1d;
    case 0xe:
      iVar13 = iVar15;
      break;
    case 0xf:
      abStack_b0[uVar19 ^ 0x3ebdf0d1] = abStack_b0[uVar19 ^ 0x3ebdf0d1] ^ bVar6 + 0x3a;
      abStack_b0[uVar19 ^ 0x3ebdf0f3] = bVar6 ^ abStack_b0[uVar19 ^ 0x3ebdf0f3] ^ 0xa1;
      abStack_b0[uVar19 + 0xc1420f51] = abStack_b0[uVar19 + 0xc1420f51] ^ bVar6 + 0x27;
      uVar1 = uVar19 + 0x3d8d8db3 & 0x7d7e06bd;
      abStack_b0[uVar19 + 0xc1420f4e] = abStack_b0[uVar19 + 0xc1420f4e] ^ bVar6 + 0x71;
      abStack_b0[uVar1 + 0x83b5f991] = (byte)uVar1 ^ abStack_b0[uVar1 + 0x83b5f991] ^ 0xce;
      uVar19 = uVar1;
      iVar13 = 0x10;
      break;
    case 0x10:
      abStack_b0[uVar19 ^ 0x7c4a06a1] = abStack_b0[uVar19 ^ 0x7c4a06a1] ^ bVar6 + 0x87;
      abStack_b0[uVar19 ^ 0x7c4a06a8] = bVar6 ^ abStack_b0[uVar19 ^ 0x7c4a06a8] ^ 0xac;
      abStack_b0[uVar19 + 0x83b5f980] = bVar6 ^ abStack_b0[uVar19 + 0x83b5f980] ^ 0xce;
      abStack_b0[uVar19 + 0x83b5f97d] = bVar6 ^ abStack_b0[uVar19 + 0x83b5f97d] ^ 0x99;
      abStack_b0[uVar19 + 0x83b5f974] = bVar6 ^ abStack_b0[uVar19 + 0x83b5f974] ^ 0xbf;
      abStack_b0[uVar19 + 0x83b5f997] = abStack_b0[uVar19 + 0x83b5f997] ^ bVar6 + 0x76;
      abStack_b0[uVar19 ^ 0x7c4a069d] = abStack_b0[uVar19 ^ 0x7c4a069d] ^ bVar6 - 0x2d;
      iVar13 = 0x15;
      break;
    case 0x11:
      uVar1 = uVar19 * 2;
      abStack_b0[uVar19 ^ 0x3004501e] = abStack_b0[uVar19 ^ 0x3004501e] ^ bVar6 + 0x60;
      bVar6 = (byte)uVar1;
      abStack_b0[uVar1 + 0x9ff75fe5] = abStack_b0[uVar1 + 0x9ff75fe5] ^ bVar6 - 0x22;
      abStack_b0[uVar1 + 0x9ff75fdb] = abStack_b0[uVar1 + 0x9ff75fdb] ^ bVar6 + 3;
      abStack_b0[uVar1 + 0x9ff75fe0] = bVar6 ^ abStack_b0[uVar1 + 0x9ff75fe0] ^ 0x4d;
      uVar19 = (uVar1 & 0x575efec4) * (uVar1 & 0x575efec4);
      iVar13 = 10;
      break;
    case 0x12:
      uVar19 = uVar19 << 2 ^ 0xdeb5e088;
      bVar6 = (byte)(uVar19 + 0x850fb66a);
      abStack_b0[uVar19 + 0x4651c59f] = bVar6 ^ abStack_b0[uVar19 + 0x4651c59f] ^ 0xeb;
      abStack_b0[uVar19 + 0x4651c593] = abStack_b0[uVar19 + 0x4651c593] ^ (char)uVar19 + 0xb1U;
      abStack_b0[uVar19 + 0x4651c5a9] = bVar6 ^ abStack_b0[uVar19 + 0x4651c5a9] ^ 0xfd;
      uVar19 = uVar19 + 0x850fb66a;
      iVar13 = 0xf;
      break;
    case 0x13:
      iVar21 = 3;
      goto LAB_0011d4c0;
    case 0x14:
      uVar20 = 0x4af5;
      iVar13 = iVar7;
      break;
    case 0x15:
      iVar13 = uVar19 * 2;
      abStack_b0[uVar19 ^ 0x7c4a0683] = bVar6 ^ abStack_b0[uVar19 ^ 0x7c4a0683] ^ 0xa0;
      bVar6 = (byte)iVar13;
      abStack_b0[iVar13 + 0x76bf307U] = bVar6 ^ abStack_b0[iVar13 + 0x76bf307U] ^ 0x7a;
      abStack_b0[iVar13 + 0x76bf30cU] = abStack_b0[iVar13 + 0x76bf30cU] ^ bVar6 + 0x48;
      uVar19 = uVar19 * 4;
      abStack_b0[iVar13 + 0x76bf2fbU] = bVar6 ^ abStack_b0[iVar13 + 0x76bf2fbU] ^ 0x78;
      uVar20 = 0x3e6d;
      abStack_b0[uVar19 + 0xed7e5d8] = (byte)uVar19 ^ abStack_b0[uVar19 + 0xed7e5d8] ^ 0x51;
      iVar13 = 0x18;
      break;
    case 0x16:
      iVar13 = iVar16;
      break;
    case 0x17:
      uVar14 = 0;
      uStack_b8 = 0;
      uStack_b2 = uVar4;
      goto LAB_0011d430;
    case 0x18:
      abStack_b0[uVar19 + 0xed7e5ce] = bVar6 ^ abStack_b0[uVar19 + 0xed7e5ce] ^ 0x37;
      uVar1 = uVar19 * 2 + 0xd655a3d7;
      uVar2 = uVar19 * 2 + 0x1dafcbab;
      uVar19 = uVar1 & 0x730e735b;
      abStack_b0[uVar2] = (byte)uVar1 ^ abStack_b0[uVar2] ^ 0x3c;
      abStack_b0[uVar19 + 0xcffbafec] = (byte)uVar19 ^ abStack_b0[uVar19 + 0xcffbafec] ^ 0x60;
      abStack_b0[uVar19 + 0xcffbb00f] = abStack_b0[uVar19 + 0xcffbb00f] ^ (byte)uVar19 + 0xc;
      iVar13 = (0x12 - uVar20) + (uVar20 / 0x2f) * 0x2f;
      break;
    case 0x19:
      iVar13 = iVar21;
      break;
    case 0x1a:
      iVar13 = iVar10;
      break;
    case 0x1b:
      if (param_3 < 0x100) {
        iVar13 = 0xc - uVar20 % 0x89;
      }
      else {
        iVar13 = 0x25 - uVar20 % 0x89;
      }
      break;
    case 0x1c:
      iVar13 = iVar17;
      break;
    case 0x1d:
      goto switchD_0011cb84_caseD_1d;
    }
  } while( true );
LAB_0011d430:
  switch(uVar14) {
  case 0x11d44c:
    break;
  default:
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
                    /* WARNING: This code block may not be properly labeled as switch case */
  uStack_b1 = 0xd4;
  lVar9 = (**(code **)(param_1 + 0x18))(param_1,&uStack_b1,1);
  uVar14 = 3;
  if (lVar9 != 1) {
    *param_1 = 8;
    uVar14 = 2;
  }
  goto LAB_0011d430;
code_r0x0011d544:
  iVar21 = 1;
  auVar22 = (**(code **)(param_1 + 0x18))(param_1,&uStack_c1,1);
  if (auVar22._0_8_ == 0) {
    *param_1 = 0xc;
LAB_0011d4b8:
    iVar21 = 4;
  }
  goto LAB_0011d4c0;
LAB_0011d310:
  switch(uVar14) {
  case 0x11d32c:
    break;
  default:
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
                    /* WARNING: This code block may not be properly labeled as switch case */
  uStack_b1 = 0xd8;
  uStack_b9 = uVar4;
  lVar9 = (**(code **)(param_1 + 0x18))(param_1,&uStack_b1,1);
  if (lVar9 == 1) {
    lVar9 = (**(code **)(param_1 + 0x18))(param_1,&uStack_b9,1);
    uVar14 = 4;
    if (lVar9 == 0) {
      *param_1 = 0xc;
      uVar14 = 2;
    }
  }
  else {
    *param_1 = 8;
    uVar14 = 2;
  }
  goto LAB_0011d310;
switchD_0011cb84_caseD_0:
  auVar22 = j___l0O_I_IS_O5_lO5ll__O_Sl_l5IIS_l_IIS00_I_5ISO_I_S5_(param_1,param_2,param_3,param_4);
  unaff_w24 = auVar22._0_4_;
  goto switchD_0011cb84_caseD_1d;
LAB_0011d4c0:
  switch(iVar21) {
  case 0x11d518:
                    /* WARNING: This code block may not be properly labeled as switch case */
    uStack_b1 = 0xd6;
    uStack_c1 = uVar4;
    auVar22 = (**(code **)(param_1 + 0x18))(param_1,&uStack_b1,1);
    if (auVar22._0_8_ == 1) goto code_r0x0011d544;
    *param_1 = 8;
    goto LAB_0011d4b8;
  default:
    if (iVar21 != 5) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    unaff_w24 = 0;
  }
switchD_0011cb84_caseD_1d:
  if (___stack_chk_guard != lStack_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(auVar22._0_8_,auVar22._8_8_);
  }
  return unaff_w24 & 1;
}


/* EXPORT index=134 ELF_VA=0x1d694 size=3596 source_sha256=0e843113d7be1109a1f46f8f671fab77f577d7b9af53160c0a81b79ac626d334 */

bool j___O_0SI_IIIlI_l_OIO__OI5l__O_II_I000SIISISI_SlO55S5_(undefined1 *param_1,undefined1 *param_2)

{
  ushort uVar1;
  char cVar2;
  long lVar3;
  ulong *puVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  code *pcVar7;
  undefined4 uVar8;
  bool bVar9;
  ulong uVar10;
  int iVar11;
  uint uVar12;
  undefined1 uStack_fd;
  undefined4 uStack_fc;
  ushort uStack_f6;
  uint auStack_f4 [2];
  undefined1 uStack_ea;
  undefined1 uStack_e9;
  undefined4 uStack_e8;
  ushort uStack_e4;
  undefined1 uStack_e1;
  undefined4 uStack_e0;
  uint uStack_dc;
  undefined1 uStack_d5;
  uint uStack_d4;
  ulong uStack_d0;
  undefined1 uStack_c7;
  ushort uStack_c6;
  uint uStack_c4;
  ulong uStack_c0;
  undefined1 uStack_b7;
  ushort uStack_b6;
  uint uStack_b4;
  ulong uStack_b0;
  undefined4 uStack_a8;
  undefined1 uStack_a1;
  undefined4 uStack_a0;
  undefined1 uStack_9b;
  undefined1 uStack_9a;
  undefined1 uStack_99;
  undefined1 uStack_98;
  undefined1 uStack_97;
  ushort uStack_96;
  uint auStack_94 [2];
  ushort auStack_8a [3];
  uint uStack_84;
  ushort auStack_7e [3];
  uint uStack_78;
  byte bStack_71;
  
  switch(*param_2) {
  case 0:
    bStack_71 = param_2[8];
    if ((char)bStack_71 < '\0') {
LAB_0011e298:
      *param_1 = 5;
      return false;
    }
    goto LAB_0011e264;
  case 1:
    if (0xf < (*(uint *)(param_2 + 8) & 0xff)) goto LAB_0011e298;
    bStack_71 = (byte)*(uint *)(param_2 + 8) | 0x80;
    goto LAB_0011e264;
  case 2:
    if (0xf < (*(uint *)(param_2 + 8) & 0xff)) goto LAB_0011e298;
    bStack_71 = (byte)*(uint *)(param_2 + 8) | 0x90;
    goto LAB_0011e264;
  case 3:
    if (0x1f < (*(uint *)(param_2 + 8) & 0xff)) goto LAB_0011e298;
    bStack_71 = (byte)*(uint *)(param_2 + 8) | 0xa0;
    goto LAB_0011e264;
  case 4:
    bStack_71 = 0xc0;
    goto LAB_0011e320;
  case 5:
    if (param_2[8] == '\0') {
      bStack_71 = 0xc2;
    }
    else {
      bStack_71 = 0xc3;
    }
LAB_0011e320:
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      return true;
    }
    break;
  case 6:
    iVar11 = 2;
    uStack_fd = (undefined1)*(undefined4 *)(param_2 + 8);
    do {
      while (iVar11 == 0) {
        lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_fd,1);
        iVar11 = 3;
        if (lVar3 == 0) goto switchD_0011e250_caseD_5;
      }
      if (iVar11 != 2) {
        if (iVar11 != 3) {
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        return true;
      }
      bStack_71 = 0xc4;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
      iVar11 = 0;
    } while (lVar3 == 1);
    break;
  case 7:
    iVar11 = 0;
    uStack_f6 = (ushort)*(undefined4 *)(param_2 + 8);
    uStack_fc = 0;
    do {
      while (iVar11 != 5) {
        if (iVar11 == 4) {
          return true;
        }
        if (iVar11 != 0) {
          if (iVar11 != 1) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
switchD_0011e250_caseD_3:
          return false;
        }
        bStack_71 = 0xc5;
        lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
        iVar11 = 5;
        if (lVar3 != 1) {
          *param_1 = 8;
          iVar11 = 1;
        }
      }
      uStack_f6 = uStack_f6 >> 8 | uStack_f6 << 8;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_f6,2);
      iVar11 = 4;
    } while (lVar3 != 0);
    goto switchD_0011e250_caseD_5;
  case 8:
    uVar12 = *(uint *)(param_2 + 8);
    bStack_71 = 0xc6;
    auStack_f4[0] = uVar12;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      uVar12 = (uVar12 & 0xff00ff00) >> 8 | (uVar12 & 0xff00ff) << 8;
      auStack_f4[0] = uVar12 >> 0x10 | uVar12 << 0x10;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,auStack_f4,4);
      if (lVar3 != 0) {
        return true;
      }
      goto switchD_0011e250_caseD_5;
    }
    break;
  case 9:
    uStack_e9 = param_2[8];
    uStack_ea = (undefined1)*(undefined4 *)(param_2 + 0xc);
    auStack_f4[1] = 0;
    iVar11 = 7;
    while( true ) {
      while (iVar11 == 1) {
        lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_ea,1);
        iVar11 = 5;
        if (lVar3 != 0) {
          iVar11 = 2;
        }
      }
      if (iVar11 == 3) break;
      if (iVar11 == 4) {
        return true;
      }
      switch(iVar11) {
      case 2:
        lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_e9,1);
        iVar11 = 3;
        if (lVar3 != 0) {
          iVar11 = 4;
        }
        break;
      default:
        do {
        } while( true );
      case 5:
        goto switchD_0011e250_caseD_5;
      case 6:
        return false;
      case 7:
        bStack_71 = 199;
        lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
        iVar11 = 1;
        if (lVar3 != 1) {
          *param_1 = 8;
          iVar11 = 6;
        }
      }
    }
    goto switchD_0011dda0_caseD_4;
  case 10:
    uStack_e1 = param_2[8];
    iVar11 = 1;
    uStack_e4 = (ushort)*(undefined4 *)(param_2 + 0xc);
    uStack_e8 = 0;
LAB_0011e38c:
    if (iVar11 == 3) {
      return false;
    }
    if (iVar11 == 9) goto switchD_0011e250_caseD_5;
    bVar9 = true;
    switch(iVar11) {
    case 0:
      goto switchD_0011e250_caseD_3;
    case 1:
      bStack_71 = 200;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
      iVar11 = 6;
      if (lVar3 != 1) {
        *param_1 = 8;
        iVar11 = 3;
      }
      goto LAB_0011e38c;
    case 2:
      goto switchD_0011e3b4_caseD_2;
    default:
      goto switchD_0011e3b4_caseD_3;
    case 6:
      uStack_e4 = uStack_e4 >> 8 | uStack_e4 << 8;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_e4,2);
      iVar11 = 9;
      if (lVar3 != 0) {
        iVar11 = 2;
      }
      goto LAB_0011e38c;
    }
  case 0xb:
    uStack_d5 = param_2[8];
    uStack_dc = *(uint *)(param_2 + 0xc);
    cVar2 = '\x05';
    uStack_e0 = 0;
LAB_0011d9f8:
    while( true ) {
      while (cVar2 == '\x05') {
        bStack_71 = 0xc9;
        lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
        cVar2 = '\x06';
        if (lVar3 != 1) {
          *param_1 = 8;
          cVar2 = '\x03';
        }
      }
      if (cVar2 != '\x06') break;
      uVar12 = (uStack_dc & 0xff00ff00) >> 8 | (uStack_dc & 0xff00ff) << 8;
      uStack_dc = uVar12 >> 0x10 | uVar12 << 0x10;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_dc,4);
      cVar2 = '\x02';
      if (lVar3 != 0) {
        cVar2 = '\x04';
      }
    }
    if (cVar2 == '\x03') {
      return false;
    }
    bVar9 = true;
    switch(cVar2) {
    case '\0':
      goto switchD_0011e250_caseD_3;
    case '\x01':
      goto switchD_0011dda0_caseD_4;
    case '\x02':
      goto switchD_0011e250_caseD_5;
    default:
      goto switchD_0011da28_caseD_3;
    case '\x04':
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_d5,1);
      cVar2 = lVar3 == 0;
      goto LAB_0011d9f8;
    }
  case 0xc:
    uVar12 = *(uint *)(param_2 + 8);
    bStack_71 = 0xca;
    uStack_d4 = uVar12;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) break;
    uVar12 = (uVar12 & 0xff00ff00) >> 8 | (uVar12 & 0xff00ff) << 8;
    uStack_d4 = uVar12 >> 0x10 | uVar12 << 0x10;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar4 = (ulong *)&uStack_d4;
    uVar6 = 4;
    goto LAB_0011dd20;
  case 0xd:
    uVar10 = *(ulong *)(param_2 + 8);
    bStack_71 = 0xcb;
    uStack_d0 = uVar10;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      uVar10 = (uVar10 & 0xff00ff00ff00ff00) >> 8 | (uVar10 & 0xff00ff00ff00ff) << 8;
      uVar10 = (uVar10 & 0xffff0000ffff0000) >> 0x10 | (uVar10 & 0xffff0000ffff) << 0x10;
      uStack_d0 = uVar10 >> 0x20 | uVar10 << 0x20;
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = &uStack_d0;
      uVar6 = 8;
      goto LAB_0011dd20;
    }
    break;
  case 0xe:
    uStack_c7 = param_2[8];
    bStack_71 = 0xcc;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) break;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar4 = (ulong *)&uStack_c7;
    goto LAB_0011dc4c;
  case 0xf:
    uVar1 = *(ushort *)(param_2 + 8);
    bStack_71 = 0xcd;
    uStack_c6 = uVar1;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      uStack_c6 = uVar1 >> 8 | uVar1 << 8;
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = (ulong *)&uStack_c6;
      uVar6 = 2;
      goto LAB_0011dd20;
    }
    break;
  case 0x10:
    uVar12 = *(uint *)(param_2 + 8);
    bStack_71 = 0xce;
    uStack_c4 = uVar12;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      uVar12 = (uVar12 & 0xff00ff00) >> 8 | (uVar12 & 0xff00ff) << 8;
      uStack_c4 = uVar12 >> 0x10 | uVar12 << 0x10;
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = (ulong *)&uStack_c4;
      uVar6 = 4;
      goto LAB_0011dd20;
    }
    break;
  case 0x11:
    uVar10 = *(ulong *)(param_2 + 8);
    bStack_71 = 0xcf;
    uStack_c0 = uVar10;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      uVar10 = (uVar10 & 0xff00ff00ff00ff00) >> 8 | (uVar10 & 0xff00ff00ff00ff) << 8;
      uVar10 = (uVar10 & 0xffff0000ffff0000) >> 0x10 | (uVar10 & 0xffff0000ffff) << 0x10;
      uStack_c0 = uVar10 >> 0x20 | uVar10 << 0x20;
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = &uStack_c0;
      uVar6 = 8;
      goto LAB_0011dd20;
    }
    break;
  case 0x12:
    uStack_b7 = param_2[8];
    bStack_71 = 0xd0;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) break;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar4 = (ulong *)&uStack_b7;
LAB_0011dc4c:
    uVar6 = 1;
LAB_0011dd20:
    lVar3 = (*pcVar7)(param_1,puVar4,uVar6);
    return lVar3 != 0;
  case 0x13:
    uVar1 = *(ushort *)(param_2 + 8);
    bStack_71 = 0xd1;
    uStack_b6 = uVar1;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      uStack_b6 = uVar1 >> 8 | uVar1 << 8;
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = (ulong *)&uStack_b6;
      uVar6 = 2;
      goto LAB_0011dd20;
    }
    break;
  case 0x14:
    uVar12 = *(uint *)(param_2 + 8);
    bStack_71 = 0xd2;
    uStack_b4 = uVar12;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      uVar12 = (uVar12 & 0xff00ff00) >> 8 | (uVar12 & 0xff00ff) << 8;
      uStack_b4 = uVar12 >> 0x10 | uVar12 << 0x10;
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = (ulong *)&uStack_b4;
      uVar6 = 4;
      goto LAB_0011dd20;
    }
    break;
  case 0x15:
    uVar10 = *(ulong *)(param_2 + 8);
    bStack_71 = 0xd3;
    uStack_b0 = uVar10;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      uVar10 = (uVar10 & 0xff00ff00ff00ff00) >> 8 | (uVar10 & 0xff00ff00ff00ff) << 8;
      uVar10 = (uVar10 & 0xffff0000ffff0000) >> 0x10 | (uVar10 & 0xffff0000ffff) << 0x10;
      uStack_b0 = uVar10 >> 0x20 | uVar10 << 0x20;
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = &uStack_b0;
      uVar6 = 8;
      goto LAB_0011dd20;
    }
    break;
  case 0x16:
    uVar8 = 0;
    uStack_a1 = param_2[8];
    uStack_a8 = 0;
LAB_0011dd88:
    bVar9 = true;
    switch(uVar8) {
    case 0:
      bStack_71 = 0xd4;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
      uVar8 = 3;
      if (lVar3 != 1) {
        *param_1 = 8;
        uVar8 = 2;
      }
      goto LAB_0011dd88;
    case 1:
      goto switchD_0011e250_caseD_3;
    case 2:
      goto switchD_0011e250_caseD_3;
    case 3:
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_a1,1);
      uVar8 = 4;
      if (lVar3 != 0) {
        uVar8 = 1;
      }
      goto LAB_0011dd88;
    case 4:
      goto switchD_0011dda0_caseD_4;
    default:
      goto switchD_0011dda0_default;
    }
  case 0x17:
    uStack_9b = param_2[8];
    iVar11 = 4;
    uStack_a0 = 0;
    while( true ) {
      while (iVar11 == 5) {
        lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_9b,1);
        iVar11 = 0;
        if (lVar3 != 0) {
          iVar11 = 2;
        }
      }
      if (iVar11 == 0) break;
      if (iVar11 == 1) {
        return false;
      }
      if (iVar11 != 4) {
        if (iVar11 != 2) {
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        return true;
      }
      bStack_71 = 0xd5;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
      iVar11 = 5;
      if (lVar3 != 1) {
        *param_1 = 8;
        iVar11 = 1;
      }
    }
    goto switchD_0011dda0_caseD_4;
  case 0x18:
    uStack_9a = param_2[8];
    bStack_71 = 0xd6;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) break;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = &uStack_9a;
    goto LAB_0011df10;
  case 0x19:
    uStack_99 = param_2[8];
    bStack_71 = 0xd7;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) break;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = &uStack_99;
    goto LAB_0011df10;
  case 0x1a:
    uStack_98 = param_2[8];
    bStack_71 = 0xd8;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) break;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = &uStack_98;
LAB_0011df10:
    lVar3 = (*pcVar7)(param_1,puVar5,1);
    if (lVar3 != 0) {
      return true;
    }
switchD_0011dda0_caseD_4:
    *param_1 = 0xc;
    return false;
  case 0x1b:
    uStack_97 = (undefined1)*(undefined4 *)(param_2 + 8);
    bStack_71 = 0xd9;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_97,1);
      if (lVar3 != 0) {
        return true;
      }
      goto switchD_0011e250_caseD_5;
    }
    break;
  case 0x1c:
    uVar12 = *(uint *)(param_2 + 8);
    uStack_96 = (ushort)uVar12;
    bStack_71 = 0xda;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      uStack_96 = (ushort)(uVar12 >> 8) & 0xff | (ushort)((uVar12 & 0xff00ff) << 8);
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_96,2);
      if (lVar3 != 0) {
        return true;
      }
      goto switchD_0011e250_caseD_5;
    }
    break;
  case 0x1d:
    uVar12 = *(uint *)(param_2 + 8);
    bStack_71 = 0xdb;
    auStack_94[0] = uVar12;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      uVar12 = (uVar12 & 0xff00ff00) >> 8 | (uVar12 & 0xff00ff) << 8;
      auStack_94[0] = uVar12 >> 0x10 | uVar12 << 0x10;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,auStack_94,4);
      if (lVar3 != 0) {
        return true;
      }
      goto switchD_0011e250_caseD_5;
    }
    break;
  case 0x1e:
    iVar11 = 2;
    auStack_8a[0] = (ushort)*(undefined4 *)(param_2 + 8);
    auStack_94[1] = 0;
    while( true ) {
      while (iVar11 == 0) {
        auStack_8a[0] = auStack_8a[0] >> 8 | auStack_8a[0] << 8;
        lVar3 = (**(code **)(param_1 + 0x18))(param_1,auStack_8a,2);
        iVar11 = 1;
        if (lVar3 != 0) {
          iVar11 = 3;
        }
      }
      if (iVar11 == 5) {
        return false;
      }
      if (iVar11 != 2) break;
      bStack_71 = 0xdc;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
      iVar11 = 0;
      if (lVar3 != 1) {
        *param_1 = 8;
        iVar11 = 5;
      }
    }
    if (iVar11 != 1) {
      if (iVar11 != 3) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      return true;
    }
switchD_0011e250_caseD_5:
    *param_1 = 0xf;
    return false;
  case 0x1f:
    uStack_84 = *(uint *)(param_2 + 8);
    auStack_8a[1] = 0;
    auStack_8a[2] = 0;
    uVar8 = 5;
LAB_0011e118:
    bVar9 = true;
    switch(uVar8) {
    case 0:
      goto switchD_0011e250_caseD_3;
    default:
      goto switchD_0011e130_caseD_1;
    case 3:
      goto switchD_0011e250_caseD_5;
    case 4:
      uVar12 = (uStack_84 & 0xff00ff00) >> 8 | (uStack_84 & 0xff00ff) << 8;
      uStack_84 = uVar12 >> 0x10 | uVar12 << 0x10;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_84,4);
      uVar8 = 3;
      if (lVar3 != 0) {
        uVar8 = 0;
      }
      goto LAB_0011e118;
    case 5:
      goto switchD_0011e130_caseD_5;
    }
  case 0x20:
    uVar12 = *(uint *)(param_2 + 8);
    auStack_7e[0] = (ushort)uVar12;
    bStack_71 = 0xde;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      auStack_7e[0] = (ushort)(uVar12 >> 8) & 0xff | (ushort)((uVar12 & 0xff00ff) << 8);
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,auStack_7e,2);
      if (lVar3 != 0) {
        return true;
      }
      goto switchD_0011e250_caseD_5;
    }
    break;
  case 0x21:
    uStack_78 = *(uint *)(param_2 + 8);
    auStack_7e[1] = 0;
    auStack_7e[2] = 0;
    bStack_71 = 0xdf;
    uVar8 = 1;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) {
      *param_1 = 8;
      uVar8 = 4;
    }
    do {
      bVar9 = true;
      switch(uVar8) {
      case 1:
        uVar12 = (uStack_78 & 0xff00ff00) >> 8 | (uStack_78 & 0xff00ff) << 8;
        uStack_78 = uVar12 >> 0x10 | uVar12 << 0x10;
        lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_78,4);
        uVar8 = 5;
        if (lVar3 != 0) {
          uVar8 = 3;
        }
        break;
      default:
        do {
        } while( true );
      case 3:
        goto switchD_0011e250_caseD_3;
      case 4:
        goto switchD_0011e250_caseD_3;
      case 5:
        goto switchD_0011e250_caseD_5;
      }
    } while( true );
  case 0x22:
    bStack_71 = param_2[8];
    if (bStack_71 < 0xe0) goto LAB_0011e298;
LAB_0011e264:
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) {
      *param_1 = 6;
      return false;
    }
    return true;
  default:
    *param_1 = 0xd;
    return false;
  }
LAB_0011e344:
  bVar9 = false;
  *param_1 = 8;
switchD_0011e250_caseD_3:
  return bVar9;
switchD_0011e130_caseD_5:
  bStack_71 = 0xdd;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
  uVar8 = 4;
  if (lVar3 != 1) goto LAB_0011e344;
  goto LAB_0011e118;
switchD_0011e130_caseD_1:
  do {
  } while( true );
switchD_0011dda0_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_0011da28_caseD_3:
  do {
  } while( true );
switchD_0011e3b4_caseD_3:
  do {
  } while( true );
switchD_0011e3b4_caseD_2:
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_e1,1);
  iVar11 = 0;
  if (lVar3 == 0) goto switchD_0011dda0_caseD_4;
  goto LAB_0011e38c;
}


/* EXPORT index=135 ELF_VA=0x1e5b4 size=4340 source_sha256=9b9f843f4df9c802a8fe5a683b096a2cf36cb1a477baf3240ec870d6c3b31013 */

/* WARNING: Exceeded maximum restarts with more pending */

byte j___SIS_I_0IIOI_lOS___00O00_0lOIIll_0IS0_lIl_IS__SOS5_(undefined1 *param_1,undefined1 *param_2)

{
  ushort uVar1;
  char cVar2;
  long lVar3;
  undefined1 *puVar4;
  ulong *puVar5;
  undefined8 uVar6;
  code *pcVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  byte unaff_w23;
  uint uVar11;
  ulong uVar12;
  undefined1 uStack_109;
  ulong uStack_108;
  uint uStack_100;
  ushort uStack_fa;
  ulong uStack_f8;
  undefined4 uStack_f0;
  undefined1 uStack_ea;
  undefined1 uStack_e9;
  uint uStack_e8;
  uint auStack_e4 [2];
  ushort auStack_da [3];
  undefined1 uStack_d3;
  undefined1 uStack_d2;
  undefined1 uStack_d1;
  ulong uStack_d0;
  undefined4 uStack_c4;
  uint uStack_c0;
  undefined1 uStack_b9;
  uint uStack_b8;
  undefined1 uStack_b1;
  uint uStack_b0;
  ushort uStack_ac;
  undefined1 uStack_a9;
  undefined4 uStack_a8;
  undefined1 uStack_a2;
  undefined1 uStack_a1;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined1 uStack_98;
  undefined1 uStack_97;
  ushort auStack_96 [3];
  undefined4 uStack_90;
  undefined1 uStack_89;
  undefined4 uStack_88;
  undefined2 uStack_82;
  undefined1 uStack_7f;
  ushort auStack_7e [4];
  ushort uStack_76;
  ushort uStack_74;
  byte bStack_71;
  
  uVar11 = 0x32;
switchD_0011e614_default:
  switch(uVar11) {
  case 0:
    goto switchD_0011e614_caseD_0;
  case 1:
switchD_0011e614_caseD_1:
    uVar11 = 9;
    goto switchD_0011e614_default;
  case 2:
    goto switchD_0011e614_caseD_2;
  case 3:
  case 0x36:
    bStack_71 = 0xc3;
    goto LAB_0011ee9c;
  case 4:
    uVar11 = *(uint *)(param_2 + 8);
    bStack_71 = 0xce;
    uStack_100 = uVar11;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      uVar11 = (uVar11 & 0xff00ff00) >> 8 | (uVar11 & 0xff00ff) << 8;
      uStack_100 = uVar11 >> 0x10 | uVar11 << 0x10;
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar5 = (ulong *)&uStack_100;
      goto LAB_0011ee90;
    }
    goto LAB_0011f444;
  case 5:
switchD_0011e614_caseD_5:
    uVar11 = 0xf;
    goto switchD_0011e614_default;
  case 6:
switchD_0011e614_caseD_6:
    uVar11 = 0x46;
    goto switchD_0011e614_default;
  case 7:
switchD_0011e614_caseD_7:
    uVar11 = 4;
    goto switchD_0011e614_default;
  case 8:
    iVar10 = 0;
    uStack_76 = (ushort)*(undefined4 *)(param_2 + 8);
    auStack_7e[1] = 0;
    auStack_7e[2] = 0;
    goto LAB_0011f514;
  case 9:
    uVar11 = *(uint *)(param_2 + 8);
    bStack_71 = 0xd2;
    uStack_b0 = uVar11;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      uVar11 = (uVar11 & 0xff00ff00) >> 8 | (uVar11 & 0xff00ff) << 8;
      uStack_b0 = uVar11 >> 0x10 | uVar11 << 0x10;
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar5 = (ulong *)&uStack_b0;
      goto LAB_0011ee90;
    }
    goto LAB_0011f444;
  case 10:
    uStack_e9 = param_2[8];
    bStack_71 = 0xd8;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = &uStack_e9;
      goto LAB_0011f244;
    }
    goto LAB_0011f444;
  case 0xb:
    uStack_7f = param_2[8];
    iVar10 = 1;
    uStack_82 = (undefined2)*(undefined4 *)(param_2 + 0xc);
    uStack_88 = 0;
    goto LAB_0011f5b8;
  case 0xc:
    uStack_b1 = param_2[8];
    bStack_71 = 0xd6;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 == 1) {
      pcVar7 = *(code **)(param_1 + 0x18);
      puVar4 = &uStack_b1;
      goto LAB_0011f244;
    }
    goto LAB_0011f444;
  case 0xd:
  case 0x39:
    if (0x1f < (*(uint *)(param_2 + 8) & 0xff)) goto LAB_0011ed94;
    bStack_71 = (byte)*(uint *)(param_2 + 8) | 0xa0;
LAB_0011ed60:
    unaff_w23 = 1;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) {
      unaff_w23 = 0;
      *param_1 = 6;
    }
    goto switchD_0011e614_caseD_51;
  case 0xe:
    uVar1 = *(ushort *)(param_2 + 8);
    bStack_71 = 0xd1;
    auStack_96[0] = uVar1;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    auStack_96[0] = uVar1 >> 8 | uVar1 << 8;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = (ulong *)auStack_96;
    uVar6 = 2;
    break;
  case 0xf:
    iVar10 = 2;
    uStack_109 = (undefined1)*(undefined4 *)(param_2 + 8);
    unaff_w23 = 1;
    goto LAB_0011ea3c;
  case 0x10:
switchD_0011e614_caseD_10:
    uVar8 = 0xb7701da3;
    uVar11 = 0xb7701db7;
    goto LAB_0011e5f4;
  case 0x11:
    uStack_a9 = param_2[8];
    bStack_71 = 0xd0;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = (ulong *)&uStack_a9;
    uVar6 = 1;
    break;
  case 0x12:
switchD_0011e614_caseD_12:
    uVar11 = 0x22;
    goto switchD_0011e614_default;
  case 0x13:
switchD_0011e614_caseD_13:
    uVar11 = 0x4c;
    goto switchD_0011e614_default;
  case 0x14:
    if ((*(uint *)(param_2 + 8) & 0xff) < 0x10) {
      bStack_71 = (byte)*(uint *)(param_2 + 8) | 0x80;
      goto LAB_0011ed60;
    }
    goto LAB_0011ed94;
  case 0x15:
    uStack_89 = param_2[8];
    bStack_71 = 0xd0;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = (ulong *)&uStack_89;
    uVar6 = 1;
    break;
  case 0x16:
switchD_0011e614_caseD_16:
    uVar11 = 0x3c;
    goto switchD_0011e614_default;
  case 0x17:
    bStack_71 = param_2[8];
    if (0xdf < bStack_71) goto LAB_0011ed60;
    goto LAB_0011ed94;
  case 0x18:
switchD_0011e614_caseD_18:
    uVar11 = 0xc;
    goto switchD_0011e614_default;
  case 0x19:
switchD_0011e614_caseD_19:
    uVar11 = 0x49;
    goto switchD_0011e614_default;
  case 0x1a:
switchD_0011e614_caseD_1a:
    uVar8 = 0x1ee7ec85;
    uVar11 = 0x1ee7ec8d;
    goto LAB_0011e5f4;
  case 0x1b:
  case 0x29:
    if ((*(uint *)(param_2 + 8) & 0xff) < 0x10) {
      bStack_71 = (byte)*(uint *)(param_2 + 8) | 0x90;
      goto LAB_0011ed60;
    }
    goto LAB_0011ed94;
  case 0x1c:
switchD_0011e614_caseD_1c:
    uVar11 = 0x20;
    goto switchD_0011e614_default;
  case 0x1d:
    uVar11 = *(uint *)(param_2 + 8);
    uStack_74 = (ushort)uVar11;
    bStack_71 = 0xda;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    uStack_74 = (ushort)(uVar11 >> 8) & 0xff | (ushort)((uVar11 & 0xff00ff) << 8);
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_74,2);
    if (lVar3 == 0) goto switchD_0011f33c_caseD_5;
    unaff_w23 = 1;
    goto switchD_0011e614_caseD_51;
  case 0x1e:
switchD_0011e614_caseD_1e:
    uVar11 = 0x39;
    goto switchD_0011e614_default;
  case 0x1f:
    switch(*param_2) {
    case 0:
      goto switchD_0011e614_caseD_23;
    case 1:
      goto switchD_0011e614_caseD_10;
    case 2:
      goto switchD_0011e614_caseD_42;
    case 3:
      goto switchD_0011e614_caseD_1e;
    case 4:
      goto switchD_0011e614_caseD_4f;
    case 5:
      goto switchD_0011e614_caseD_28;
    case 6:
      goto switchD_0011e614_caseD_5;
    case 7:
      goto switchD_0011e614_caseD_1a;
    case 8:
      goto switchD_0011e614_caseD_2d;
    case 9:
      goto switchD_0011e614_caseD_12;
    case 10:
      goto switchD_0011e614_caseD_3b;
    case 0xb:
      goto switchD_0011e614_caseD_6;
    case 0xc:
      goto switchD_0011e614_caseD_48;
    case 0xd:
      goto switchD_0011e614_caseD_37;
    case 0xe:
      goto switchD_0011e614_caseD_2b;
    case 0xf:
      goto switchD_0011e614_caseD_19;
    case 0x10:
      goto switchD_0011e614_caseD_7;
    case 0x11:
      goto switchD_0011e614_caseD_16;
    case 0x12:
      goto switchD_0011e614_caseD_26;
    case 0x13:
      goto switchD_0011e614_caseD_2c;
    case 0x14:
      goto switchD_0011e614_caseD_1;
    case 0x15:
      goto switchD_0011e614_caseD_33;
    case 0x16:
      goto switchD_0011e614_caseD_3d;
    case 0x17:
      goto switchD_0011e614_caseD_4e;
    case 0x18:
      goto switchD_0011e614_caseD_18;
    case 0x19:
      goto switchD_0011e614_caseD_43;
    case 0x1a:
      goto switchD_0011e614_caseD_40;
    default:
      goto switchD_0011e614_caseD_13;
    case 0x1c:
      goto switchD_0011e614_caseD_27;
    case 0x1d:
      goto switchD_0011e614_caseD_2f;
    case 0x1e:
      goto switchD_0011e614_caseD_34;
    case 0x1f:
      goto switchD_0011e614_caseD_1c;
    case 0x20:
      goto switchD_0011e614_caseD_2e;
    case 0x21:
      goto switchD_0011e614_caseD_0;
    case 0x22:
      goto switchD_0011e614_caseD_38;
    }
  case 0x20:
    uStack_90 = *(undefined4 *)(param_2 + 8);
    uVar6 = 5;
    auStack_96[1] = 0;
    auStack_96[2] = 0;
    goto LAB_0011ebe0;
  case 0x21:
    uVar11 = 0x35;
    if (param_2[8] != '\0') {
      uVar11 = 3;
    }
    goto switchD_0011e614_default;
  case 0x22:
    uStack_a1 = param_2[8];
    uStack_a2 = (undefined1)*(undefined4 *)(param_2 + 0xc);
    uStack_a8 = 0;
    iVar10 = 7;
    goto LAB_0011ec88;
  case 0x23:
switchD_0011e614_caseD_23:
    uVar11 = 0x25;
    goto switchD_0011e614_default;
  case 0x24:
    uStack_98 = param_2[8];
    bStack_71 = 0xcc;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = (ulong *)&uStack_98;
    uVar6 = 1;
    break;
  case 0x25:
    bStack_71 = param_2[8];
    if (-1 < (char)bStack_71) goto LAB_0011ed60;
LAB_0011ed94:
    unaff_w23 = 0;
    *param_1 = 5;
    goto switchD_0011e614_caseD_51;
  case 0x26:
switchD_0011e614_caseD_26:
    uVar11 = 0x45;
    goto switchD_0011e614_default;
  case 0x27:
switchD_0011e614_caseD_27:
    uVar11 = 0x30;
    goto switchD_0011e614_default;
  case 0x28:
switchD_0011e614_caseD_28:
    uVar11 = 0x21;
    goto switchD_0011e614_default;
  case 0x2a:
    uVar11 = *(uint *)(param_2 + 8);
    bStack_71 = 0xdb;
    auStack_e4[0] = uVar11;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    uVar11 = (uVar11 & 0xff00ff00) >> 8 | (uVar11 & 0xff00ff) << 8;
    auStack_e4[0] = uVar11 >> 0x10 | uVar11 << 0x10;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,auStack_e4,4);
    if (lVar3 == 0) goto switchD_0011f33c_caseD_5;
    unaff_w23 = 1;
    goto switchD_0011e614_caseD_51;
  case 0x2b:
switchD_0011e614_caseD_2b:
    uVar11 = 0x4d;
    goto switchD_0011e614_default;
  case 0x2c:
switchD_0011e614_caseD_2c:
    uVar11 = 0xe;
    goto switchD_0011e614_default;
  case 0x2d:
switchD_0011e614_caseD_2d:
    uVar11 = 0x3f;
    goto switchD_0011e614_default;
  case 0x2e:
switchD_0011e614_caseD_2e:
    uVar11 = 0x3a;
    goto switchD_0011e614_default;
  case 0x2f:
switchD_0011e614_caseD_2f:
    uVar11 = 0x2a;
    goto switchD_0011e614_default;
  case 0x30:
    uVar11 = *(uint *)(param_2 + 8);
    uStack_fa = (ushort)uVar11;
    bStack_71 = 0xda;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    uStack_fa = (ushort)(uVar11 >> 8) & 0xff | (ushort)((uVar11 & 0xff00ff) << 8);
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_fa,2);
    if (lVar3 == 0) goto switchD_0011f33c_caseD_5;
    unaff_w23 = 1;
    goto switchD_0011e614_caseD_51;
  case 0x31:
    uVar11 = *(uint *)(param_2 + 8);
    bStack_71 = 0xca;
    uStack_e8 = uVar11;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    uVar11 = (uVar11 & 0xff00ff00) >> 8 | (uVar11 & 0xff00ff) << 8;
    uStack_e8 = uVar11 >> 0x10 | uVar11 << 0x10;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = (ulong *)&uStack_e8;
LAB_0011ee90:
    uVar6 = 4;
    break;
  case 0x32:
    goto switchD_0011e614_caseD_32;
  case 0x33:
switchD_0011e614_caseD_33:
    uVar11 = 0x41;
    goto switchD_0011e614_default;
  case 0x34:
switchD_0011e614_caseD_34:
    uVar11 = 0x3e;
    goto switchD_0011e614_default;
  case 0x35:
    bStack_71 = 0xc2;
    goto LAB_0011ee9c;
  case 0x37:
switchD_0011e614_caseD_37:
    uVar11 = 0x44;
    goto switchD_0011e614_default;
  case 0x38:
switchD_0011e614_caseD_38:
    uVar11 = 0x17;
    goto switchD_0011e614_default;
  case 0x3a:
    uVar11 = *(uint *)(param_2 + 8);
    auStack_7e[0] = (ushort)uVar11;
    bStack_71 = 0xde;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    auStack_7e[0] = (ushort)(uVar11 >> 8) & 0xff | (ushort)((uVar11 & 0xff00ff) << 8);
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,auStack_7e,2);
    if (lVar3 == 0) goto switchD_0011f33c_caseD_5;
    unaff_w23 = 1;
    goto switchD_0011e614_caseD_51;
  case 0x3b:
switchD_0011e614_caseD_3b:
    uVar8 = 0x2bd20a34;
    uVar11 = 0x2bd20a3f;
LAB_0011e5f4:
    uVar11 = uVar11 ^ uVar8;
    goto switchD_0011e614_default;
  case 0x3c:
    uVar12 = *(ulong *)(param_2 + 8);
    bStack_71 = 0xcf;
    uStack_f8 = uVar12;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    uVar12 = (uVar12 & 0xff00ff00ff00ff00) >> 8 | (uVar12 & 0xff00ff00ff00ff) << 8;
    uVar12 = (uVar12 & 0xffff0000ffff0000) >> 0x10 | (uVar12 & 0xffff0000ffff) << 0x10;
    uStack_f8 = uVar12 >> 0x20 | uVar12 << 0x20;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = &uStack_f8;
    uVar6 = 8;
    break;
  case 0x3d:
switchD_0011e614_caseD_3d:
    uVar11 = 0x4b;
    goto switchD_0011e614_default;
  case 0x3e:
    iVar10 = 2;
    auStack_da[0] = (ushort)*(undefined4 *)(param_2 + 8);
    auStack_e4[1] = 0;
    goto LAB_0011efbc;
  case 0x3f:
    uVar11 = *(uint *)(param_2 + 8);
    bStack_71 = 0xc6;
    uStack_b8 = uVar11;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    uVar11 = (uVar11 & 0xff00ff00) >> 8 | (uVar11 & 0xff00ff) << 8;
    uStack_b8 = uVar11 >> 0x10 | uVar11 << 0x10;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_b8,4);
    if (lVar3 == 0) goto switchD_0011f33c_caseD_5;
    unaff_w23 = 1;
    goto switchD_0011e614_caseD_51;
  case 0x40:
switchD_0011e614_caseD_40:
    uVar11 = 10;
    goto switchD_0011e614_default;
  case 0x41:
    uVar12 = *(ulong *)(param_2 + 8);
    bStack_71 = 0xd3;
    uStack_d0 = uVar12;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    uVar12 = (uVar12 & 0xff00ff00ff00ff00) >> 8 | (uVar12 & 0xff00ff00ff00ff) << 8;
    uVar12 = (uVar12 & 0xffff0000ffff0000) >> 0x10 | (uVar12 & 0xffff0000ffff) << 0x10;
    uStack_d0 = uVar12 >> 0x20 | uVar12 << 0x20;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = &uStack_d0;
    uVar6 = 8;
    break;
  case 0x42:
switchD_0011e614_caseD_42:
    uVar11 = 0x29;
    goto switchD_0011e614_default;
  case 0x43:
switchD_0011e614_caseD_43:
    uVar11 = 0x47;
    goto switchD_0011e614_default;
  case 0x44:
    uVar12 = *(ulong *)(param_2 + 8);
    bStack_71 = 0xcb;
    uStack_108 = uVar12;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    uVar12 = (uVar12 & 0xff00ff00ff00ff00) >> 8 | (uVar12 & 0xff00ff00ff00ff) << 8;
    uVar12 = (uVar12 & 0xffff0000ffff0000) >> 0x10 | (uVar12 & 0xffff0000ffff) << 0x10;
    uStack_108 = uVar12 >> 0x20 | uVar12 << 0x20;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = &uStack_108;
    uVar6 = 8;
    break;
  case 0x45:
    uStack_d2 = param_2[8];
    bStack_71 = 0xd0;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = (ulong *)&uStack_d2;
    uVar6 = 1;
    break;
  case 0x46:
    uStack_b9 = param_2[8];
    uStack_c0 = *(uint *)(param_2 + 0xc);
    cVar2 = '\x05';
    uStack_c4 = 0;
    goto LAB_0011f188;
  case 0x47:
    uStack_97 = param_2[8];
    bStack_71 = 0xd7;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar4 = &uStack_97;
LAB_0011f244:
    unaff_w23 = 1;
    lVar3 = (*pcVar7)(param_1,puVar4,1);
    if (lVar3 == 0) goto switchD_0011f1b8_caseD_1;
    goto switchD_0011e614_caseD_51;
  case 0x48:
switchD_0011e614_caseD_48:
    uVar11 = 0x31;
    goto switchD_0011e614_default;
  case 0x49:
    uVar1 = *(ushort *)(param_2 + 8);
    bStack_71 = 0xcd;
    uStack_ac = uVar1;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    uStack_ac = uVar1 >> 8 | uVar1 << 8;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = (ulong *)&uStack_ac;
    uVar6 = 2;
    break;
  case 0x4a:
    uStack_9c = *(uint *)(param_2 + 8);
    uStack_a0 = 0;
    bStack_71 = 0xdf;
    uVar9 = 1;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) {
      *param_1 = 8;
      uVar9 = 4;
    }
    goto LAB_0011f31c;
  case 0x4b:
    uVar6 = 0;
    uStack_ea = param_2[8];
    uStack_f0 = 0;
    goto LAB_0011f398;
  case 0x4c:
    unaff_w23 = 0;
    *param_1 = 0xd;
    goto switchD_0011e614_caseD_51;
  case 0x4d:
    uStack_d1 = param_2[8];
    bStack_71 = 0xcc;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    if (lVar3 != 1) goto LAB_0011f444;
    pcVar7 = *(code **)(param_1 + 0x18);
    puVar5 = (ulong *)&uStack_d1;
    uVar6 = 1;
    break;
  case 0x4e:
switchD_0011e614_caseD_4e:
    uVar11 = 0x50;
    goto switchD_0011e614_default;
  case 0x4f:
switchD_0011e614_caseD_4f:
    uVar11 = 2;
    goto switchD_0011e614_default;
  case 0x50:
    uStack_d3 = param_2[8];
    iVar10 = 4;
    auStack_da[1] = 0;
    auStack_da[2] = 0;
    goto LAB_0011f4c0;
  case 0x51:
    goto switchD_0011e614_caseD_51;
  default:
    goto switchD_0011e614_default;
  }
  lVar3 = (*pcVar7)(param_1,puVar5,uVar6);
  unaff_w23 = lVar3 != 0;
  goto switchD_0011e614_caseD_51;
LAB_0011f4c0:
  while (iVar10 == 5) {
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_d3,1);
    iVar10 = 0;
    if (lVar3 != 0) {
      iVar10 = 2;
    }
  }
  if (iVar10 == 0) goto switchD_0011f1b8_caseD_1;
  if (iVar10 == 1) goto switchD_0011f33c_caseD_4;
  if (iVar10 == 4) {
    bStack_71 = 0xd5;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    iVar10 = 5;
    if (lVar3 != 1) {
      *param_1 = 8;
      iVar10 = 1;
    }
    goto LAB_0011f4c0;
  }
  if (iVar10 != 2) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  unaff_w23 = 1;
  goto switchD_0011e614_caseD_51;
LAB_0011f398:
  switch(uVar6) {
  case 0x11f3b4:
    break;
  default:
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
                    /* WARNING: This code block may not be properly labeled as switch case */
  bStack_71 = 0xd4;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
  uVar6 = 3;
  if (lVar3 != 1) {
    *param_1 = 8;
    uVar6 = 2;
  }
  goto LAB_0011f398;
LAB_0011f31c:
  do {
    unaff_w23 = 1;
    switch(uVar9) {
    case 1:
      uVar11 = (uStack_9c & 0xff00ff00) >> 8 | (uStack_9c & 0xff00ff) << 8;
      uStack_9c = uVar11 >> 0x10 | uVar11 << 0x10;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_9c,4);
      uVar9 = 5;
      if (lVar3 != 0) {
        uVar9 = 3;
      }
      break;
    default:
      do {
      } while( true );
    case 3:
      goto switchD_0011e614_caseD_51;
    case 4:
      goto switchD_0011f33c_caseD_4;
    case 5:
      goto switchD_0011f33c_caseD_5;
    }
  } while( true );
LAB_0011f188:
  while( true ) {
    while (cVar2 == '\x05') {
      bStack_71 = 0xc9;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
      cVar2 = '\x06';
      if (lVar3 != 1) {
        *param_1 = 8;
        cVar2 = '\x03';
      }
    }
    if (cVar2 != '\x06') break;
    uVar11 = (uStack_c0 & 0xff00ff00) >> 8 | (uStack_c0 & 0xff00ff) << 8;
    uStack_c0 = uVar11 >> 0x10 | uVar11 << 0x10;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_c0,4);
    cVar2 = '\x02';
    if (lVar3 != 0) {
      cVar2 = '\x04';
    }
  }
  if (cVar2 == '\x03') goto switchD_0011f33c_caseD_4;
  unaff_w23 = 1;
  switch(cVar2) {
  case '\0':
    goto switchD_0011e614_caseD_51;
  case '\x01':
    goto switchD_0011f1b8_caseD_1;
  case '\x02':
    goto switchD_0011f33c_caseD_5;
  default:
    break;
  case '\x04':
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_b9,1);
    cVar2 = lVar3 == 0;
    goto LAB_0011f188;
  }
  do {
  } while( true );
LAB_0011efbc:
  while (iVar10 == 0) {
    auStack_da[0] = auStack_da[0] >> 8 | auStack_da[0] << 8;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,auStack_da,2);
    iVar10 = 1;
    if (lVar3 != 0) {
      iVar10 = 3;
    }
  }
  if (iVar10 == 5) goto switchD_0011f33c_caseD_4;
  if (iVar10 == 2) {
    bStack_71 = 0xdc;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    iVar10 = 0;
    if (lVar3 != 1) {
      *param_1 = 8;
      iVar10 = 5;
    }
    goto LAB_0011efbc;
  }
  if (iVar10 != 1) {
    if (iVar10 != 3) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    unaff_w23 = 1;
    goto switchD_0011e614_caseD_51;
  }
  goto switchD_0011f33c_caseD_5;
switchD_0011e614_caseD_32:
  uVar11 = 0x1f;
  goto switchD_0011e614_default;
LAB_0011ec88:
  while (iVar10 == 1) {
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_a2,1);
    iVar10 = 5;
    if (lVar3 != 0) {
      iVar10 = 2;
    }
  }
  if (iVar10 == 3) goto switchD_0011f1b8_caseD_1;
  if (iVar10 == 4) {
    unaff_w23 = 1;
    goto switchD_0011e614_caseD_51;
  }
  unaff_w23 = 0;
  switch(iVar10) {
  case 2:
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_a1,1);
    iVar10 = 3;
    if (lVar3 != 0) {
      iVar10 = 4;
    }
    break;
  default:
    do {
    } while( true );
  case 5:
    goto switchD_0011f33c_caseD_5;
  case 6:
    goto switchD_0011e614_caseD_51;
  case 7:
    bStack_71 = 199;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    iVar10 = 1;
    if (lVar3 != 1) {
      *param_1 = 8;
      iVar10 = 6;
    }
  }
  goto LAB_0011ec88;
LAB_0011ebe0:
  switch(uVar6) {
  case 0x11ebfc:
    break;
  default:
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
                    /* WARNING: This code block may not be properly labeled as switch case */
  bStack_71 = 0xdd;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
  uVar6 = 4;
  if (lVar3 != 1) goto LAB_0011f444;
  goto LAB_0011ebe0;
LAB_0011f5b8:
  if (iVar10 != 3) {
    if (iVar10 != 9) {
      switch(iVar10) {
      case 0x11f5e4:
        goto switchD_0011f5e0_caseD_11f5e4;
      default:
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
    }
    goto switchD_0011f33c_caseD_5;
  }
  goto switchD_0011f33c_caseD_4;
switchD_0011f5e0_caseD_11f5e4:
                    /* WARNING: This code block may not be properly labeled as switch case */
  bStack_71 = 200;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
  iVar10 = 6;
  if (lVar3 != 1) {
    *param_1 = 8;
    iVar10 = 3;
  }
  goto LAB_0011f5b8;
switchD_0011f1b8_caseD_1:
  unaff_w23 = 0;
  *param_1 = 0xc;
  goto switchD_0011e614_caseD_51;
  while( true ) {
    uStack_76 = uStack_76 >> 8 | uStack_76 << 8;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_76,2);
    iVar10 = 4;
    if (lVar3 == 0) break;
LAB_0011f514:
    if (iVar10 != 5) {
      if (iVar10 == 4) {
        unaff_w23 = 1;
        goto switchD_0011e614_caseD_51;
      }
      if (iVar10 != 0) {
        if (iVar10 != 1) {
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
switchD_0011f33c_caseD_4:
        unaff_w23 = 0;
        goto switchD_0011e614_caseD_51;
      }
      bStack_71 = 0xc5;
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
      iVar10 = 5;
      if (lVar3 != 1) {
        *param_1 = 8;
        iVar10 = 1;
      }
      goto LAB_0011f514;
    }
  }
switchD_0011f33c_caseD_5:
  unaff_w23 = 0;
  *param_1 = 0xf;
  goto switchD_0011e614_caseD_51;
switchD_0011e614_caseD_2:
  bStack_71 = 0xc0;
LAB_0011ee9c:
  unaff_w23 = 1;
  lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
  if (lVar3 == 1) goto switchD_0011e614_caseD_51;
  goto LAB_0011f444;
switchD_0011e614_caseD_0:
  uVar11 = 0x4a;
  goto switchD_0011e614_default;
  while( true ) {
    if (iVar10 != 2) {
      if (iVar10 != 3) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      goto switchD_0011e614_caseD_51;
    }
    bStack_71 = 0xc4;
    lVar3 = (**(code **)(param_1 + 0x18))(param_1,&bStack_71,1);
    iVar10 = 0;
    if (lVar3 != 1) break;
LAB_0011ea3c:
    if (iVar10 == 0) {
      lVar3 = (**(code **)(param_1 + 0x18))(param_1,&uStack_109,1);
      iVar10 = 3;
      if (lVar3 == 0) goto switchD_0011f33c_caseD_5;
      goto LAB_0011ea3c;
    }
  }
LAB_0011f444:
  unaff_w23 = 0;
  *param_1 = 8;
switchD_0011e614_caseD_51:
  return unaff_w23 & 1;
}


/* EXPORT index=136 ELF_VA=0x1f904 size=96 source_sha256=82220f2efabfc4af72613b5ad994b0f1eb60c97bcdf5886add83a57371c48f82 */

undefined8
j___lS0IS__Ill5__5S5I_0lISI_I_I_l55lO_0l5I_l__IIIlIS5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  char acStack_30 [8];
  undefined1 uStack_28;
  
  uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_30);
  if ((uVar1 & 1) == 0) {
    uVar2 = 0;
  }
  else if (acStack_30[0] == '\0') {
    *param_2 = uStack_28;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    *param_1 = 0xd;
  }
  return uVar2;
}


/* EXPORT index=137 ELF_VA=0x1f964 size=4020 source_sha256=88b9b113044cebc169935b80788ace6d22d485ce4026466da7300389a2731f22 */

undefined8
j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong *puVar1;
  bool bVar2;
  uint uVar3;
  ulong uVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uStack_50;
  undefined1 uStack_4b;
  ushort uStack_4a;
  undefined1 uStack_48;
  undefined1 uStack_47;
  byte bStack_46;
  byte abStack_45 [5];
  
  abStack_45[1] = 0;
  abStack_45[2] = 0;
  abStack_45[3] = 0;
  abStack_45[4] = 0;
  puVar1 = (ulong *)(param_2 + 8);
  iVar7 = 0x3b;
  iVar11 = 0x434d;
  iVar8 = -0x434d;
LAB_0011f9ac:
  switch(iVar7) {
  case 0:
    iVar7 = 0x91;
    if ((char)abStack_45[0] < '\0') {
      iVar7 = 0xc;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 1:
    *param_2 = 0x19;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,1);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 7;
    iVar7 = 0x10;
    break;
  case 2:
    iVar7 = 0x77;
    if (abStack_45[0] != 0xd4) {
      iVar7 = 0x8e;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 3:
    *param_2 = 0;
    goto LAB_0011faec;
  case 4:
    *param_2 = 0x1e;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,2);
    iVar7 = 0x52;
    if ((uVar4 & 1) == 0) {
      iVar7 = 0x88;
    }
    iVar11 = 0x28d9;
    iVar8 = -0x28d9;
    goto LAB_0011f9ac;
  case 5:
  case 0x19:
  case 0x3f:
  case 0x54:
  case 0x78:
  case 0x82:
  case 0x8b:
    *param_1 = 0xe;
    return 0;
  case 6:
    uVar3 = (uStack_50 & 0xff00ff00) >> 8 | (uStack_50 & 0xff00ff) << 8;
    *(uint *)(param_2 + 0xc) = uVar3 >> 0x10 | uVar3 << 0x10;
    uVar5 = uStack_4b;
    goto LAB_0011fce0;
  case 7:
  case 0x23:
  case 0x2b:
  case 0x35:
  case 0x41:
  case 0x4e:
  case 0x50:
  case 0x6f:
  case 0x8f:
    *param_1 = 0xb;
    return 0;
  case 8:
  case 0x24:
  case 0x28:
  case 0x2a:
  case 0x36:
  case 0x3c:
  case 0x3d:
  case 0x46:
  case 0x48:
  case 0x4b:
  case 0x53:
  case 0x69:
  case 0x6e:
  case 0x7c:
  case 0x7d:
  case 0x81:
  case 0x8a:
  case 0x94:
    *param_1 = 9;
    return 0;
  case 9:
    *param_2 = 0x22;
LAB_0011faec:
    param_2[8] = abStack_45[0];
    iVar7 = 0x5d;
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 10:
  case 0x31:
  case 0x37:
  case 0x5c:
  case 0x6a:
  case 0x75:
  case 0x90:
    uVar3 = ((uint)*puVar1 & 0xff00ff00) >> 8 | ((uint)*puVar1 & 0xff00ff) << 8;
    uVar3 = uVar3 >> 0x10 | uVar3 << 0x10;
    goto LAB_0011fa1c;
  case 0xb:
    *param_2 = 6;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,1);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x54;
    iVar7 = 0x21;
    break;
  case 0xc:
    iVar7 = 0x5a;
    if (0x9f < abStack_45[0]) {
      iVar7 = 0x74;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0xd:
    iVar7 = 0x95;
    if (abStack_45[0] != 0xdf) {
      iVar7 = 0x91;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0xe:
    *param_2 = 0x1f;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,4);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x94;
    iVar7 = 0x90;
    break;
  case 0xf:
    *param_2 = 0xc;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,4);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x69;
    iVar7 = 0x5c;
    break;
  case 0x10:
    uVar6 = 8;
    goto LAB_0012028c;
  case 0x11:
    *param_2 = 0xe;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,1);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x53;
    iVar7 = 0x5d;
    break;
  case 0x12:
    iVar7 = 0x84;
    if (abStack_45[0] != 0xd1) {
      iVar7 = 0x60;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x13:
    *param_2 = 0x17;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,1);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x4e;
    iVar7 = 0x15;
    break;
  case 0x14:
  case 0x26:
    *(ushort *)puVar1 = (ushort)*puVar1 >> 8 | (ushort)*puVar1 << 8;
    iVar7 = 0x5d;
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x15:
    uVar6 = 2;
    goto LAB_0012028c;
  case 0x16:
    iVar7 = 3;
    if ((char)abStack_45[0] < '\0') {
      iVar7 = 0x66;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x17:
    iVar7 = 0x5e;
    if (abStack_45[0] != 0xda) {
      iVar7 = 0x65;
    }
    iVar11 = 0x1390;
    iVar8 = -0x1390;
    goto LAB_0011f9ac;
  case 0x18:
    *param_2 = 4;
    param_2[8] = 0;
    iVar7 = iVar8 + ((uint)(iVar11 * 0xef2f) >> 0x17) * 0x89 + 0xa4;
  default:
switchD_0011f9c4_default:
    if (iVar7 == 0x97) {
      return 1;
    }
    goto LAB_0011f9a8;
  case 0x1a:
    iVar7 = 0x77;
    if (abStack_45[0] != 0xcf) {
      iVar7 = 0x44;
    }
    iVar11 = 0x628;
    iVar8 = -0x628;
    goto LAB_0011f9ac;
  case 0x1b:
    uVar6 = 4;
    goto LAB_0012028c;
  case 0x1c:
    *(uint *)(param_2 + 0xc) = (uint)(uStack_4a >> 8) | (uStack_4a & 0xff00ff) << 8;
    uVar5 = uStack_48;
LAB_0011fce0:
    *(undefined1 *)puVar1 = uVar5;
    iVar7 = 0x5d;
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x1d:
    iVar7 = 0x1f;
    if (abStack_45[0] != 0xc6) {
      iVar7 = 0x8e;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x1e:
    return 0;
  case 0x1f:
    *param_2 = 8;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,4);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 5;
    iVar7 = 0x31;
    break;
  case 0x20:
    iVar7 = 0x18;
    if (abStack_45[0] != 0xc0) {
      iVar7 = 0x52;
    }
    iVar11 = 0x1526;
    iVar8 = -0x1526;
    goto LAB_0011f9ac;
  case 0x21:
  case 0x67:
    uVar3 = (uint)(byte)*puVar1;
    goto LAB_0011fa1c;
  case 0x22:
  case 0x39:
  case 0x40:
    uVar3 = (uint)(ushort)((ushort)*puVar1 >> 8) | ((ushort)*puVar1 & 0xff00ff) << 8;
LAB_0011fa1c:
    *(uint *)puVar1 = uVar3;
    iVar7 = 0x5d;
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x25:
    iVar7 = iVar11 + ((uint)(iVar11 * 0xa238) >> 0x16) * -0x65;
    if (abStack_45[0] == 0xcb) {
      iVar7 = 0xac - iVar7;
    }
    else {
      iVar7 = 0x4e - iVar7;
    }
    goto switchD_0011f9c4_default;
  case 0x27:
    iVar7 = 0xf;
    if (abStack_45[0] != 0xca) {
      iVar7 = 0x25;
    }
    iVar11 = 0x2f7d;
    iVar8 = -0x2f7d;
    goto LAB_0011f9ac;
  case 0x29:
    iVar7 = 0x11;
    if (abStack_45[0] != 0xcc) {
      iVar7 = 0x7e;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x2c:
  case 0x68:
  case 0x80:
    uVar4 = (*puVar1 & 0xff00ff00ff00ff00) >> 8 | (*puVar1 & 0xff00ff00ff00ff) << 8;
    uVar4 = (uVar4 & 0xffff0000ffff0000) >> 0x10 | (uVar4 & 0xffff0000ffff) << 0x10;
    *puVar1 = uVar4 >> 0x20 | uVar4 << 0x20;
    iVar7 = 0x5d;
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x2d:
    *param_2 = 10;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,&uStack_4a,2);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x19;
    iVar7 = 0x42;
    break;
  case 0x2e:
    *param_2 = 5;
    param_2[8] = 0;
    iVar7 = 0x5d;
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x2f:
    *(uint *)puVar1 = (uint)(ushort)((ushort)*puVar1 >> 8) | ((ushort)*puVar1 & 0xff00ff) << 8;
    iVar7 = iVar8 + ((uint)(iVar11 * 0xb217) >> 0x14) * 0x17 + 0x71;
    goto switchD_0011f9c4_default;
  case 0x30:
    iVar7 = iVar11 + ((uint)(iVar11 * 0x9a91) >> 0x15) * -0x35;
    if (abStack_45[0] == 0xc4) {
      iVar7 = 0xa8 - iVar7;
    }
    else {
      iVar7 = 0x50 - iVar7;
    }
    goto switchD_0011f9c4_default;
  case 0x32:
    iVar8 = iVar11 + ((uint)(iVar11 * 0xc908) >> 0x17) * -0xa3;
    uVar3 = (**(code **)(param_1 + 0x10))(param_1,&uStack_4b,1);
    if ((uVar3 & 1) == 0) {
      iVar7 = 0x117;
    }
    else {
      iVar7 = 0x8e;
    }
    goto LAB_00120880;
  case 0x33:
    iVar7 = 0x79;
    if (abStack_45[0] != 0xde) {
      iVar7 = 0xd;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x34:
    *param_2 = 9;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,&bStack_46,1);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x3f;
    iVar7 = 0x47;
    break;
  case 0x38:
    *param_2 = 0x12;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,1);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x48;
    iVar7 = 0x5d;
    break;
  case 0x3a:
    *param_2 = 0x15;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,8);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x3d;
    iVar7 = 0x80;
    break;
  case 0x3b:
    abStack_45[0] = 0;
    iVar8 = iVar11 + ((uint)(iVar11 * 0x9f12) >> 0x16) * -0x67;
    uVar3 = (**(code **)(param_1 + 0x10))(param_1,abStack_45,1);
    if ((uVar3 & 1) != 0) {
      iVar7 = 0x32;
      goto LAB_00120880;
    }
    *param_1 = 7;
    iVar7 = 0x3a - iVar8;
    goto switchD_0011f9c4_default;
  case 0x3e:
    iVar7 = 0xe;
    if (abStack_45[0] != 0xdd) {
      iVar7 = 0x33;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x42:
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,&uStack_48,1);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x35;
    iVar7 = 0x1c;
    break;
  case 0x43:
    iVar7 = iVar11 + ((uint)(iVar11 * 0x9a91) >> 0x15) * -0x35;
    if (abStack_45[0] == 0xc4) {
      iVar7 = 0x2d - iVar7;
    }
    else {
      iVar7 = 0x67 - iVar7;
    }
    goto switchD_0011f9c4_default;
  case 0x44:
    iVar7 = iVar11 + ((uint)(iVar11 * 0x9920) >> 0x16) * -0x6b;
    if (abStack_45[0] == 0xd0) {
      iVar7 = 0x86 - iVar7;
    }
    else {
LAB_0012081c:
      iVar7 = 0x60 - iVar7;
    }
    goto switchD_0011f9c4_default;
  case 0x45:
    iVar7 = 0x92;
    if (abStack_45[0] != 0xc5) {
      iVar7 = 0x1d;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x47:
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,&uStack_47,1);
    iVar7 = 0x70;
    if ((uVar4 & 1) == 0) {
      iVar7 = 0x23;
    }
    iVar11 = 0x50e9;
    iVar8 = -0x50e9;
    goto LAB_0011f9ac;
  case 0x49:
    iVar9 = 0x83;
    iVar7 = 0xbb;
    iVar10 = 0x6f72;
    iVar8 = ((uint)(iVar11 * 0xebbe) >> 0x17) * -0x8b;
    bVar2 = abStack_45[0] == 0xd9;
    goto LAB_0012014c;
  case 0x4a:
    *param_2 = 5;
    param_2[8] = 1;
    iVar7 = 0x5d;
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x4c:
    iVar7 = 0x93;
    if (abStack_45[0] != 0xdc) {
      iVar7 = 0x3e;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x4d:
    *param_2 = 0xf;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,2);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 8;
    iVar7 = 0x14;
    break;
  case 0x4f:
    *param_2 = 0x1b;
    iVar8 = iVar11 + ((uint)(iVar11 * 0xae4d) >> 0x15) * -0x2f;
    uVar3 = (**(code **)(param_1 + 0x10))(param_1,puVar1,1);
    if ((uVar3 & 1) == 0) {
      iVar7 = 0x9e;
    }
    else {
      iVar7 = 0x89;
    }
    goto LAB_00120880;
  case 0x51:
    iVar9 = 0x7e;
    iVar7 = 0x6f;
    iVar10 = 0x309d;
    iVar8 = ((uint)(iVar11 * 0xb217) >> 0x14) * -0x17;
    bVar2 = abStack_45[0] == 0xd6;
LAB_0012014c:
    if (!bVar2) {
      iVar7 = iVar9;
    }
    iVar7 = iVar7 - (iVar11 + iVar8);
    iVar11 = iVar10 - (iVar11 + iVar8);
    goto switchD_0011f9c4_default;
  case 0x52:
    iVar7 = 0x2e;
    if (abStack_45[0] != 0xc2) {
      iVar7 = 0x7b;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x55:
    *param_2 = 0x1a;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,1);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x6f;
    iVar7 = 0x5f;
    break;
  case 0x56:
    iVar7 = iVar11 + ((uint)(iVar11 * 0xa238) >> 0x16) * -0x65;
    if (abStack_45[0] == 0xcb) {
      iVar7 = 0x70 - iVar7;
    }
    else {
      iVar7 = 0x35 - iVar7;
    }
    goto switchD_0011f9c4_default;
  case 0x57:
    iVar7 = 0x71;
    if (abStack_45[0] != 0xc9) {
      iVar7 = 0x27;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x58:
    iVar7 = 0x3a;
    if (abStack_45[0] != 0xd3) {
      iVar7 = 0x88;
    }
    iVar11 = 0x6870;
    iVar8 = -0x6870;
    goto LAB_0011f9ac;
  case 0x59:
    iVar7 = 0x2d;
    if (abStack_45[0] != 200) {
      iVar7 = 0x57;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x5a:
    uVar5 = 2;
    goto LAB_00120724;
  case 0x5b:
    *param_2 = 0x10;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,4);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x8a;
    iVar7 = 0x37;
    break;
  case 0x5d:
    return 1;
  case 0x5e:
    *param_2 = 0x1c;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,2);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x2a;
    iVar7 = 0x22;
    break;
  case 0x5f:
    uVar6 = 0x10;
LAB_0012028c:
    *(undefined4 *)(param_2 + 0xc) = uVar6;
    iVar7 = 0x5d;
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x60:
    iVar7 = 0x85;
    if (abStack_45[0] != 0xd2) {
      iVar7 = 0x58;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x61:
    *(undefined4 *)(param_2 + 0xc) = 1;
    iVar7 = 0x89;
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x62:
    iVar7 = 0x13;
    if (abStack_45[0] != 0xd5) {
      iVar7 = 0x51;
    }
    iVar11 = 0x1cfa;
    iVar8 = -0x1cfa;
    goto LAB_0011f9ac;
  case 99:
    *param_2 = 0x18;
    iVar8 = iVar11 + ((uint)(iVar11 * 0xe6c3) >> 0x16) * -0x47;
    uVar3 = (**(code **)(param_1 + 0x10))(param_1,puVar1,1);
    if ((uVar3 & 1) == 0) {
      iVar7 = 0x58;
    }
    else {
      iVar7 = 0x23;
    }
LAB_00120880:
    iVar7 = iVar7 - iVar8;
    goto switchD_0011f9c4_default;
  case 100:
  case 0x7a:
    *param_1 = 0xd;
    return 0;
  case 0x65:
    iVar7 = iVar11 + ((uint)(iVar11 * 0xbe83) >> 0x15) * -0x2b;
    if (abStack_45[0] != 0xdb) goto LAB_0012081c;
    iVar7 = 0xa0 - iVar7;
    goto switchD_0011f9c4_default;
  case 0x66:
    iVar7 = 0x8d;
    if (0x8f < abStack_45[0]) {
      iVar7 = 0xc;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x6b:
    iVar7 = 0x55;
    if (abStack_45[0] != 0xd8) {
      iVar7 = 0x49;
    }
    iVar11 = 0x4c4;
    iVar8 = -0x4c4;
    goto LAB_0011f9ac;
  case 0x6c:
    iVar7 = iVar11 + ((uint)(iVar11 * 0xba2f) >> 0x13) * -0xb;
    if (abStack_45[0] == 0xce) {
      iVar7 = 0x61 - iVar7;
    }
    else {
      iVar7 = 0x20 - iVar7;
    }
    goto switchD_0011f9c4_default;
  case 0x6d:
    *(undefined4 *)(param_2 + 0xc) = 1;
    iVar7 = iVar8 + ((uint)(iVar11 * 0xb710) >> 0x17) * 0xb3 + 0x5e;
    goto switchD_0011f9c4_default;
  case 0x70:
    *(uint *)(param_2 + 0xc) = (uint)bStack_46;
    *(undefined1 *)puVar1 = uStack_47;
    iVar7 = iVar8 + ((uint)(iVar11 * 0xdd68) >> 0x15) * 0x25 + 0x7b;
    goto switchD_0011f9c4_default;
  case 0x71:
    *param_2 = 0xb;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,&uStack_50,4);
    iVar7 = 0x32;
    if ((uVar4 & 1) == 0) {
      iVar7 = 0x78;
    }
    iVar11 = 0x5af2;
    iVar8 = -0x5af2;
    goto LAB_0011f9ac;
  case 0x72:
    iVar7 = 1;
    if (abStack_45[0] != 0xd7) {
      iVar7 = 0x6b;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x73:
    *param_2 = 0x16;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,1);
    iVar7 = 0x6d;
    if ((uVar4 & 1) == 0) {
      iVar7 = 0x2b;
    }
    iVar11 = 0x2b5b;
    iVar8 = -0x2b5b;
    goto LAB_0011f9ac;
  case 0x74:
    iVar7 = 0x83;
    if (0xbf < abStack_45[0]) {
      iVar7 = 0x20;
    }
    iVar11 = 0x2234;
    iVar8 = -0x2234;
    goto LAB_0011f9ac;
  case 0x76:
    iVar7 = iVar11 + ((uint)(iVar11 * 0xd795) >> 0x14) * -0x13;
    if (abStack_45[0] == 200) {
      iVar7 = 0x9c - iVar7;
    }
    else {
      iVar7 = 0x7f - iVar7;
    }
    goto switchD_0011f9c4_default;
  case 0x77:
    *param_2 = 0x11;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,8);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x46;
    iVar7 = 0x68;
    break;
  case 0x79:
    *param_2 = 0x20;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,2);
    iVar7 = 0x2f;
    if ((uVar4 & 1) == 0) {
      iVar7 = 0x6e;
    }
    iVar11 = 0x1337;
    iVar8 = -0x1337;
    goto LAB_0011f9ac;
  case 0x7b:
    iVar7 = 0x4a;
    if (abStack_45[0] != 0xc3) {
      iVar7 = 0x43;
    }
    iVar11 = 0x53c6;
    iVar8 = -0x53c6;
    goto LAB_0011f9ac;
  case 0x7e:
    iVar7 = 0x4d;
    if (abStack_45[0] != 0xcd) {
      iVar7 = 0x6c;
    }
    iVar11 = 0x4a88;
    iVar8 = -0x4a88;
    goto LAB_0011f9ac;
  case 0x7f:
    iVar11 = iVar11 + ((uint)(iVar11 * 0xcccd) >> 0x12) * -5;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,&uStack_48,1);
    iVar7 = 0x76;
    if ((uVar4 & 1) == 0) {
      iVar7 = 0x71;
    }
    iVar7 = iVar7 - iVar11;
    iVar11 = 0x2a7c - iVar11;
    goto switchD_0011f9c4_default;
  case 0x83:
    *param_2 = 3;
    *(uint *)(param_2 + 8) = abStack_45[0] & 0x1f;
    iVar7 = iVar8 + ((uint)(iVar11 * 0xb818) >> 0x16) * 0x59 + 0x7f;
    goto switchD_0011f9c4_default;
  case 0x84:
    *param_2 = 0x13;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,2);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x24;
    iVar7 = 0x26;
    break;
  case 0x85:
    *param_2 = 0x14;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,4);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x36;
    iVar7 = 0x75;
    break;
  case 0x86:
    *(uint *)(param_2 + 0xc) = (uint)bStack_46;
    iVar7 = 0x6d;
    *(undefined1 *)puVar1 = uStack_47;
    iVar11 = 0x373e;
    iVar8 = -0x373e;
    goto LAB_0011f9ac;
  case 0x87:
    *param_2 = 0xd;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,8);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x4b;
    iVar7 = 0x2c;
    break;
  case 0x88:
    iVar7 = iVar11 + ((uint)(iVar11 * 0xe071) >> 0x16) * -0x49;
    if (abStack_45[0] == 0xd4) {
      iVar7 = 0x85 - iVar7;
    }
    else {
      iVar7 = 0x74 - iVar7;
    }
    goto switchD_0011f9c4_default;
  case 0x89:
    iVar7 = 0x18;
    if (abStack_45[0] != 0xdc) {
      iVar7 = 0x8d;
    }
    iVar11 = 0x46eb;
    iVar8 = -0x46eb;
    goto LAB_0011f9ac;
  case 0x8c:
    *param_2 = 0x1d;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,4);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x7d;
    iVar7 = 10;
    break;
  case 0x8d:
    uVar5 = 1;
LAB_00120724:
    *param_2 = uVar5;
    *(uint *)(param_2 + 8) = abStack_45[0] & 0xf;
    iVar7 = 0x5d;
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x8e:
    iVar7 = 0x34;
    if (abStack_45[0] != 199) {
      iVar7 = 0x59;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x91:
    iVar7 = 9;
    if (abStack_45[0] < 0xe0) {
      iVar7 = 0x7a;
    }
    iVar8 = -iVar11;
    goto LAB_0011f9ac;
  case 0x92:
    *param_2 = 7;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,2);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x8b;
    iVar7 = 0x40;
    break;
  case 0x93:
    *param_2 = 0x1e;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,2);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x3c;
    iVar7 = 0x39;
    break;
  case 0x95:
    *param_2 = 0x21;
    uVar4 = (**(code **)(param_1 + 0x10))(param_1,puVar1,4);
    bVar2 = (uVar4 & 1) == 0;
    iVar8 = 0x28;
    iVar7 = 0x6a;
    break;
  case 0x96:
    goto switchD_0011f9c4_caseD_96;
  }
  if (bVar2) {
    iVar7 = iVar8;
  }
LAB_0011f9a8:
  iVar8 = -iVar11;
  goto LAB_0011f9ac;
switchD_0011f9c4_caseD_96:
  iVar7 = 0x7e;
  if (abStack_45[0] != 0xdb) {
    iVar7 = 0xe;
  }
  iVar8 = -iVar11;
  goto LAB_0011f9ac;
}


/* EXPORT index=138 ELF_VA=0x20b74 size=240 source_sha256=c7967b1bfd47354be71915c11568bcf3ec01440f2a1e603aa098dccaffdb22e7 */

/* WARNING: Switch with 1 destination removed at 0x00120c24 */

void j___S_OI____IlS___0ll_OI5lO_5l0I0OlOI_SOOI_IS_5_I5IS5_(undefined8 param_1)

{
  ulong uVar1;
  uint uVar2;
  undefined1 auStack_78 [20];
  undefined4 uStack_64;
  
  uVar2 = 0;
  uStack_64 = 0;
  do {
    do {
      do {
      } while (5 < uVar2);
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,auStack_78);
      uVar2 = 2;
    } while ((uVar1 & 1) != 0);
    uVar2 = 4;
  } while( true );
}


/* EXPORT index=139 ELF_VA=0x20c7c size=104 source_sha256=fe0ef357f0d6c27659f9d9efd50af02eaf8e7f279a7203c7f38b7b288c4908c1 */

undefined8
j___5O0I____lI5_I_0II_lOSI0_SIIlS_I5__II___IllOI5lOS5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  char acStack_30 [8];
  undefined1 uStack_28;
  
  uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_30);
  if ((uVar1 & 1) == 0) {
    uVar2 = 0;
  }
  else if ((acStack_30[0] == '\0') || (acStack_30[0] == '\"')) {
    *param_2 = uStack_28;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    *param_1 = 0xd;
  }
  return uVar2;
}


/* EXPORT index=140 ELF_VA=0x20ce4 size=200 source_sha256=394dfa54a3fe3ee129b1a33343fb11536697cf3ff36f06e18678f78b0570846b */

undefined8
j___OO_S__l__0l_S_lS__I5SIO_ISIOOl5SI_II_SOI55_I5lOS5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  char acStack_68 [8];
  undefined1 uStack_60;
  undefined4 uStack_54;
  
  uStack_54 = 0;
  uVar3 = 0;
LAB_00120d44:
  uVar2 = 0;
  switch(uVar3) {
  case 0:
    uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_68);
    uVar3 = 2;
    if ((uVar1 & 1) == 0) {
      uVar3 = 5;
    }
    goto LAB_00120d44;
  default:
    do {
    } while( true );
  case 2:
    goto switchD_00120d5c_caseD_2;
  case 3:
    uVar2 = 0;
    *param_1 = 0xd;
    break;
  case 4:
    *param_2 = uStack_60;
    uVar2 = 1;
    break;
  case 5:
    break;
  }
  return uVar2;
switchD_00120d5c_caseD_2:
  uVar3 = 3;
  if (acStack_68[0] == '\x12') {
    uVar3 = 4;
  }
  goto LAB_00120d44;
}


/* EXPORT index=141 ELF_VA=0x20dc4 size=236 source_sha256=512532f45b0a004582bb7c31029352f9a346f5356eed09855f466cefa83ce48a */

/* WARNING: Switch with 1 destination removed at 0x00120e70 */

void j___OlI_I_O5l_l_I_ISI__S0l5_SIl055OIISI__5IOI_0lI_SS5_(undefined8 param_1)

{
  ulong uVar1;
  uint uVar2;
  undefined1 auStack_78 [20];
  undefined4 uStack_64;
  
  uStack_64 = 0;
  uVar2 = 2;
  do {
    do {
      do {
      } while (5 < uVar2);
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,auStack_78);
      uVar2 = 3;
    } while ((uVar1 & 1) != 0);
    uVar2 = 0;
  } while( true );
}


/* EXPORT index=142 ELF_VA=0x20ec8 size=100 source_sha256=c2d2bcae2149986cc115b9e68de6408bd223c9465563cdd8af92a713e24562c1 */

undefined8
j____IIIS_I_SO5_l___I_lS_0I_Il_I0O_SI_lOI0Sl_Il55lSS5_(undefined1 *param_1,undefined4 *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  char acStack_30 [8];
  undefined4 uStack_28;
  
  uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_30);
  if ((uVar1 & 1) == 0) {
    uVar2 = 0;
  }
  else if (acStack_30[0] == '\x14') {
    *param_2 = uStack_28;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    *param_1 = 0xd;
  }
  return uVar2;
}


/* EXPORT index=143 ELF_VA=0x20f2c size=188 source_sha256=e70036f6c060f1a7096ad43f309a32446cf7b0e6ecb8ea2e5ebefe113a330335 */

undefined8
j___IlI_0_IIl0O_II_lI_I0__S_5I_5Ol_II_0I5II0Sl_l5SIS5_(undefined1 *param_1,undefined8 *param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  char acStack_58 [8];
  undefined8 uStack_50;
  undefined4 uStack_44;
  
  uStack_44 = 0;
  uVar2 = 4;
  do {
    switch(uVar2) {
    case 0:
      *param_1 = 0xd;
    case 1:
      return 0;
    case 2:
      uVar2 = 3;
      if (acStack_58[0] != '\x15') {
        uVar2 = 0;
      }
      break;
    case 3:
      *param_2 = uStack_50;
      return 1;
    case 4:
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_58);
      uVar2 = 1;
      if ((uVar1 & 1) != 0) {
        uVar2 = 2;
      }
      break;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=144 ELF_VA=0x20ffc size=152 source_sha256=dbc652c5c700b7cf0a9bfacf92ddbdadbd620cf98c0a8270eed96f78cd1ace38 */

undefined8 j___5__II_0IOII__55OI_IIl_0_IlIIl5IIIIlO_lIl_SIO0lIS5_(undefined1 *param_1,char *param_2)

{
  ulong uVar1;
  byte abStack_30 [8];
  char cStack_28;
  
  uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,abStack_30);
  if ((uVar1 & 1) == 0) {
    return 0;
  }
  if (abStack_30[0] < 0x22) {
    if (abStack_30[0] != 0) {
      if (abStack_30[0] == 0xe) {
        if (cStack_28 < '\0') {
LAB_00121078:
          *param_1 = 0xd;
          return 0;
        }
      }
      else if (abStack_30[0] != 0x12) goto LAB_00121078;
    }
  }
  else if (abStack_30[0] != 0x22) goto LAB_00121078;
  *param_2 = cStack_28;
  return 1;
}


/* EXPORT index=145 ELF_VA=0x21094 size=548 source_sha256=ece8c239d9b8e03021cdfd59a0b89fd7e5dbf6dbb5025b1ab3d861abef4a817e */

/* WARNING: Removing unreachable block (ram,0x00121260) */

uint j___I5III_II_II_______lOO_5__OI5_lSOI___I__ll5_S5ISS5_(undefined1 *param_1,ushort *param_2)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte abStack_78 [8];
  ushort uStack_70;
  undefined4 uStack_64;
  
  iVar4 = 0x1787;
  uStack_64 = 0x261c8bc9;
  iVar2 = 4;
switchD_00121138_default:
  uVar3 = 0;
  switch(iVar2) {
  case 0:
    goto switchD_00121138_caseD_0;
  case 1:
    goto switchD_00121138_caseD_1;
  case 2:
    if (abStack_78[0] < 0x22) {
      if (abStack_78[0] < 0xe) {
        if (abStack_78[0] == 0) goto switchD_00121138_caseD_3;
      }
      else {
        switch(abStack_78[0]) {
        case 0xe:
          goto switchD_00121138_caseD_9;
        case 0xf:
          goto switchD_00121138_caseD_f;
        case 0x12:
          goto switchD_00121138_caseD_10;
        case 0x13:
          goto switchD_00121138_caseD_c;
        }
      }
    }
    else if (abStack_78[0] == 0x22) goto switchD_00121138_caseD_a;
  case 0xd:
    iVar2 = 0;
    goto switchD_00121138_default;
  case 3:
switchD_00121138_caseD_3:
    uStack_64 = 0x6f5a25d4;
    iVar2 = 10;
    goto switchD_00121138_default;
  case 4:
    uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,abStack_78);
    iVar2 = 0x11;
    if ((uVar1 & 1) == 0) {
      iVar2 = 1;
    }
    iVar4 = 0x7b9b;
    goto switchD_00121138_default;
  case 5:
    uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,abStack_78);
    iVar2 = 0xc;
    if ((uVar1 & 1) == 0) {
      iVar2 = 10;
    }
    goto switchD_00121138_default;
  case 6:
  case 0xe:
    break;
  case 7:
    uStack_70 = (ushort)(char)uStack_70;
    break;
  case 8:
    iVar2 = 6;
    if ((short)uStack_70 < 0) {
      iVar2 = 0xd;
    }
    goto switchD_00121138_default;
  case 9:
switchD_00121138_caseD_9:
    iVar2 = 0xb;
    goto switchD_00121138_default;
  case 10:
switchD_00121138_caseD_a:
    iVar2 = 0x10;
    goto switchD_00121138_default;
  case 0xb:
    uStack_70 = uStack_70 & 0xff;
    break;
  case 0xc:
switchD_00121138_caseD_c:
    uStack_64 = 0x74fd904b;
    iVar2 = 0xe;
    goto switchD_00121138_default;
  case 0xf:
switchD_00121138_caseD_f:
    iVar2 = 8;
    goto switchD_00121138_default;
  case 0x10:
switchD_00121138_caseD_10:
    iVar2 = 7;
    goto switchD_00121138_default;
  case 0x11:
    goto switchD_00121138_caseD_11;
  case 0x12:
    uVar3 = 0xd16d0af;
    goto switchD_00121138_caseD_1;
  default:
    goto switchD_00121138_default;
  }
  *param_2 = uStack_70;
  uVar3 = 1;
  goto switchD_00121138_caseD_1;
switchD_00121138_caseD_11:
  iVar4 = iVar4 + ((uint)(iVar4 * 0xc566) >> 0x16) * -0x53;
  iVar2 = 0x16 - iVar4;
  iVar4 = 0x64c1 - iVar4;
  goto switchD_00121138_default;
switchD_00121138_caseD_0:
  uVar3 = 0;
  *param_1 = 0xd;
switchD_00121138_caseD_1:
  return uVar3 & 1;
}


/* EXPORT index=146 ELF_VA=0x2131c size=544 source_sha256=4d88e63aca207191b5ff63ece3fef40ecbfb0325be546fd0c4545b493e6339b4 */

undefined8 j___I_I0I_lI0ll_IlI_I_5055O___Ill_I0I_IIl0I__II0lS_S5_(undefined1 *param_1,uint *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte abStack_78 [8];
  uint uStack_70;
  undefined4 uStack_64;
  
  uStack_64 = 0;
  uVar4 = 0x5661;
  iVar3 = 0x14;
switchD_0012139c_default:
  cVar1 = (char)uStack_70;
  switch(iVar3) {
  case 0:
switchD_0012139c_caseD_0:
    iVar3 = 6;
    goto switchD_0012139c_default;
  case 1:
    goto switchD_0012139c_caseD_1;
  case 2:
switchD_0012139c_caseD_2:
    iVar3 = 0;
    goto switchD_0012139c_default;
  case 3:
    if (abStack_78[0] < 0xe) {
      if (abStack_78[0] == 0) goto switchD_0012139c_caseD_2;
    }
    else if (abStack_78[0] < 0x22) {
      switch(abStack_78[0]) {
      case 0xe:
        goto switchD_0012139c_caseD_d;
      case 0xf:
        goto switchD_0012139c_caseD_f;
      case 0x10:
        goto switchD_0012139c_caseD_c;
      case 0x12:
        goto switchD_0012139c_caseD_6;
      case 0x13:
        goto switchD_0012139c_caseD_7;
      case 0x14:
        goto switchD_0012139c_caseD_13;
      }
    }
    else if (abStack_78[0] == 0x22) goto switchD_0012139c_caseD_0;
  case 5:
    iVar3 = 1;
    goto switchD_0012139c_default;
  case 4:
    uStack_70 = (uint)cVar1;
    break;
  case 6:
switchD_0012139c_caseD_6:
    iVar3 = 4;
    goto switchD_0012139c_default;
  case 7:
switchD_0012139c_caseD_7:
    iVar3 = 0x11;
    goto switchD_0012139c_default;
  case 8:
  case 10:
    uStack_70 = uStack_70 & 0xff;
    break;
  case 9:
  case 0x16:
    goto switchD_0012139c_caseD_9;
  case 0xb:
    iVar3 = 3;
    goto switchD_0012139c_default;
  case 0xc:
switchD_0012139c_caseD_c:
    uStack_64 = 0x81777d33;
    iVar3 = 0x12;
    uVar4 = 0x6452;
    goto switchD_0012139c_default;
  case 0xd:
switchD_0012139c_caseD_d:
    iVar3 = 10;
    goto switchD_0012139c_default;
  case 0xe:
  case 0x15:
    break;
  case 0xf:
switchD_0012139c_caseD_f:
    uStack_64 = 0xe1c61519;
    iVar3 = 0x10;
    uVar4 = 0x65e7;
    goto switchD_0012139c_default;
  case 0x10:
    uStack_70 = uStack_70 & 0xffff;
    break;
  case 0x11:
    uStack_70 = (uint)(short)uStack_70;
    break;
  case 0x12:
    if ((int)uStack_70 < 0) {
      iVar3 = 0x16 - uVar4 % 0x3b;
    }
    else {
      iVar3 = 0x1f - uVar4 % 0x3b;
    }
    goto switchD_0012139c_default;
  case 0x13:
switchD_0012139c_caseD_13:
    iVar3 = 0x15;
    goto switchD_0012139c_default;
  case 0x14:
    goto switchD_0012139c_caseD_14;
  default:
    goto switchD_0012139c_default;
  }
  *param_2 = uStack_70;
  return 1;
switchD_0012139c_caseD_14:
  uVar2 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,abStack_78);
  if ((uVar2 & 1) == 0) {
    iVar3 = 0x19 - uVar4 % 0x13;
  }
  else {
    iVar3 = 0x1b - uVar4 % 0x13;
  }
  goto switchD_0012139c_default;
switchD_0012139c_caseD_1:
  *param_1 = 0xd;
switchD_0012139c_caseD_9:
  return 0;
}


/* EXPORT index=147 ELF_VA=0x215b4 size=484 source_sha256=6c83d6b848af10ee763379feee18e6b4414074eb51c695257916abdf4fe1a383 */

undefined8
j___SI0_0_lIOI__lO_S5_5SIIl_5O_O_lI0IlS5I_IOI_Ol__0S5_(undefined1 *param_1,ulong *param_2)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  byte abStack_48 [8];
  byte bStack_40;
  undefined1 uStack_3f;
  undefined2 uStack_3e;
  int iStack_3c;
  undefined4 uStack_34;
  
  uStack_34 = 0;
  uVar3 = 0x2147;
  iVar2 = 8;
switchD_00121608_default:
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(iVar2) {
  case 0:
    goto switchD_00121608_caseD_0;
  case 2:
    if (0xd < abStack_48[0]) {
      switch(abStack_48[0]) {
      case 0xe:
        iVar2 = 0x12;
        break;
      case 0xf:
        goto switchD_00121608_caseD_e;
      case 0x10:
        iVar2 = 0xd;
        break;
      case 0x11:
        uVar3 = 0x1088;
        iVar2 = 6;
        break;
      case 0x12:
        uVar3 = 0x2a77;
        iVar2 = 7;
        break;
      case 0x13:
        goto switchD_00121608_caseD_4;
      case 0x14:
        goto switchD_00121608_caseD_10;
      case 0x15:
        uStack_34 = 0x7663f4cf;
        iVar2 = 0x16;
        break;
      default:
        goto switchD_00121608_caseD_14;
      case 0x22:
        iVar2 = 9;
      }
      goto switchD_00121608_default;
    }
    if (abStack_48[0] == 0) {
      iVar2 = 0x15;
      goto switchD_00121608_default;
    }
  case 0x14:
switchD_00121608_caseD_14:
    iVar2 = 0;
    goto switchD_00121608_default;
  case 4:
switchD_00121608_caseD_4:
    iVar2 = 0x18;
    goto switchD_00121608_default;
  case 6:
    if (iStack_3c < 0) {
      iVar2 = 0x24 - uVar3 % 0x11;
    }
    else {
      iVar2 = 0x23 - uVar3 % 0x11;
    }
    goto switchD_00121608_default;
  case 8:
    uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,abStack_48);
    iVar2 = 10;
    if ((uVar1 & 1) == 0) {
      iVar2 = 0xc;
    }
    goto switchD_00121608_default;
  case 10:
    goto switchD_00121608_caseD_a;
  case 0xc:
    goto switchD_00121608_caseD_c;
  case 0xe:
switchD_00121608_caseD_e:
    uStack_34 = 0x89897c86;
    iVar2 = 0x11;
    uVar3 = 0x728a;
    goto switchD_00121608_default;
  case 0x10:
switchD_00121608_caseD_10:
    iVar2 = 0x1a;
    goto switchD_00121608_default;
  case 0x12:
    uVar1 = (ulong)bStack_40;
    break;
  case 0x16:
    uVar1 = CONCAT44(iStack_3c,CONCAT22(uStack_3e,CONCAT11(uStack_3f,bStack_40)));
    break;
  case 0x18:
    uVar1 = (ulong)CONCAT11(uStack_3f,bStack_40);
    break;
  case 0x1a:
    uVar1 = (ulong)CONCAT22(uStack_3e,CONCAT11(uStack_3f,bStack_40));
    break;
  default:
    goto switchD_00121608_default;
  }
  *param_2 = uVar1;
  return 1;
switchD_00121608_caseD_a:
  iVar2 = 2;
  goto switchD_00121608_default;
switchD_00121608_caseD_0:
  *param_1 = 0xd;
switchD_00121608_caseD_c:
  return 0;
}


/* EXPORT index=148 ELF_VA=0x2185c size=4 source_sha256=34c0df37a92cf94ae73d6b0e22fc7ac04248ad003d02855fae87c4ffc06d838a */

void j___SlO50__55___lI_SS_I_I_O__SS_lOII_l_5O5II0_l_I_SS5_(void)

{
  j___SI0_0_lIOI__lO_S5_5SIIl_5O_O_lI0IlS5I_IOI_Ol__0S5_();
  return;
}


/* EXPORT index=149 ELF_VA=0x21860 size=96 source_sha256=5b46775c94bb1ca88f4520973dd1c75e47db09717a4ac2bfee4f2e0ec401ae7e */

undefined8
j___lIII__05_OI__lIOl_SISIl_5ISOI_ISSS_Il_llIII_S5IS5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  char acStack_30 [8];
  undefined1 uStack_28;
  
  uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_30);
  if ((uVar1 & 1) == 0) {
    uVar2 = 0;
  }
  else if (acStack_30[0] == '\0') {
    *param_2 = uStack_28;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    *param_1 = 0xd;
  }
  return uVar2;
}


/* EXPORT index=150 ELF_VA=0x218c0 size=184 source_sha256=57a7c8c8e69456f3c5b9b198839123005954f14bb73bb595444301ced0741d16 */

undefined8
j_____I_l_5OI00_IOI5I_l5OII_OO05OlI_II_SS5S_I_II55IS5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  char acStack_58 [8];
  undefined1 uStack_50;
  undefined4 uStack_44;
  
  uStack_44 = 0;
  uVar3 = 1;
  do {
    uVar2 = 0;
    switch(uVar3) {
    case 0:
      goto switchD_0012192c_caseD_0;
    case 1:
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_58);
      uVar3 = 4;
      if ((uVar1 & 1) == 0) {
        uVar3 = 0;
      }
      break;
    case 2:
      *param_1 = 0xd;
      return 0;
    default:
      do {
      } while( true );
    case 4:
      uVar3 = 2;
      if (acStack_58[0] == '\x0e') {
        *param_2 = uStack_50;
        uVar2 = 1;
switchD_0012192c_caseD_0:
        return uVar2;
      }
    }
  } while( true );
}


/* EXPORT index=151 ELF_VA=0x2198c size=100 source_sha256=6d55cc5bc1ac213e6bdf035f7c83b1fd63bf1dd71ef0a2230ec2c0389f747888 */

undefined8
j____OOl0_S5OOl_lS05l_OISI0___Oll5lOI5lIIIl_OSI_55IS5_(undefined1 *param_1,undefined2 *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  char acStack_30 [8];
  undefined2 uStack_28;
  
  uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_30);
  if ((uVar1 & 1) == 0) {
    uVar2 = 0;
  }
  else if (acStack_30[0] == '\x0f') {
    *param_2 = uStack_28;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    *param_1 = 0xd;
  }
  return uVar2;
}


/* EXPORT index=152 ELF_VA=0x219f0 size=212 source_sha256=778c1779b5d79b44fd0b18e7b59fa2e92d094b25cc3f5aa567de76ab28277a59 */

undefined8
j___IIlIO___l0O_lI55I_S0lI__ll_lIlS__I0I0Il0SII0II5S5_(undefined1 *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  char acStack_58 [8];
  undefined4 uStack_50;
  undefined4 uStack_44;
  
  uStack_44 = 0;
  iVar2 = 1;
  do {
    while (iVar2 == 1) {
      iVar2 = 3;
    }
  } while (iVar2 != 3);
  uVar1 = 4;
  do {
    switch(uVar1) {
    case 0:
    case 3:
      return 0;
    case 1:
      uVar1 = 2;
      if (acStack_58[0] != '\x10') {
        uVar1 = 5;
      }
      break;
    case 2:
      *param_2 = uStack_50;
      return 1;
    case 4:
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_58);
      uVar1 = uVar1 & 1;
      break;
    case 5:
      *param_1 = 0xd;
      return 0;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=153 ELF_VA=0x21adc size=100 source_sha256=c92b4b11033b16e11c5925806684ba20e1115212281261ff90cd6317f0b37ccd */

undefined8
j___llS5I__IOI__IIl0I_I_lOO_5_0l__IlI5IOO__ll0SOI5IS5_(undefined1 *param_1,undefined8 *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  char acStack_30 [8];
  undefined8 uStack_28;
  
  uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_30);
  if ((uVar1 & 1) == 0) {
    uVar2 = 0;
  }
  else if (acStack_30[0] == '\x11') {
    *param_2 = uStack_28;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    *param_1 = 0xd;
  }
  return uVar2;
}


/* EXPORT index=154 ELF_VA=0x21b40 size=456 source_sha256=d50be796c4740182094d8d35a7a2428f6de5e53b6b911c92730c972ce472c6f2 */

/* WARNING: Removing unreachable block (ram,0x00121cc0) */

undefined4
j___IlIIl___O0l_S_OO__II_l0_5OS_5_IlllOISll_II_lS0OS5_(undefined1 *param_1,undefined1 *param_2)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char acStack_78 [8];
  undefined1 uStack_70;
  undefined4 uStack_64;
  
  uStack_64 = 0x46d72b9a;
  iVar3 = 2;
  uVar5 = 0x322b;
switchD_00121c2c_caseD_7:
  uVar1 = uVar5 % 0x95;
  iVar6 = iVar3;
switchD_00121c2c_caseD_6:
  iVar4 = iVar6;
  iVar3 = 4;
  uVar5 = 0x28e;
  iVar6 = 7;
  switch(iVar4) {
  case 2:
    uVar2 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
    iVar6 = 0x25;
    if ((uVar2 & 1) == 0) {
      iVar6 = 0x20;
    }
    iVar6 = iVar6 - uVar1;
    goto LAB_00121c90;
  case 3:
    return 0;
  case 4:
    *param_2 = uStack_70;
    return 1;
  default:
    goto code_r0x00121c54;
  case 6:
    goto switchD_00121c2c_caseD_6;
  case 7:
    goto switchD_00121c2c_caseD_7;
  }
switchD_00121c64_caseD_2:
  do {
  } while( true );
code_r0x00121c54:
  iVar6 = 0;
  switch(iVar4) {
  case 0:
    iVar3 = 4;
    uVar5 = 0x28e;
    iVar6 = 7;
    if (acStack_78[0] == '\0') goto switchD_00121c2c_caseD_6;
    if (acStack_78[0] == '\x0e') goto switchD_00121c2c_caseD_7;
  case 1:
    uStack_64 = 0x121481fc;
    iVar6 = 5;
LAB_00121c90:
    if (iVar6 != 10) goto switchD_00121c2c_caseD_6;
    break;
  default:
    goto switchD_00121c64_caseD_2;
  case 5:
  case 9:
    *param_1 = 0xd;
    break;
  case 8:
    goto switchD_00121c2c_caseD_6;
  }
  return 0;
}


/* EXPORT index=155 ELF_VA=0x21d48 size=464 source_sha256=56054d03b535c50cba4435a78b314c04ec6b0067fb9c42669854ed92a2eff738 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00121e70) */
/* WARNING: Removing unreachable block (ram,0x00121ed0) */

undefined4
j___5I_l5_Il_IO_Il_5___l5SI_0II_IlllSIOI5III__SSOSlS5_(undefined1 *param_1,ushort *param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char acStack_78 [8];
  ushort uStack_70;
  int iStack_68;
  undefined4 uStack_64;
  
  iStack_68 = 0;
LAB_00121db8:
  if (iStack_68 != 0) {
    if (iStack_68 != 1) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
switchD_00121df0_caseD_9:
    return 0;
  }
  uStack_64 = 0x5710435f;
  uVar1 = 7;
switchD_00121df0_caseD_3:
  uVar4 = uVar1;
  uVar3 = 5;
  uVar1 = 2;
  switch(uVar4) {
  case 1:
switchD_00121df0_caseD_1:
    uVar3 = 6;
  case 8:
    uVar1 = uVar3;
    goto switchD_00121df0_caseD_3;
  case 2:
    if (acStack_78[0] != '\0') {
      if (acStack_78[0] == '\x0e') goto switchD_00121df0_caseD_4;
      if (acStack_78[0] == '\x0f') goto switchD_00121df0_caseD_1;
      uVar1 = 5;
      goto switchD_00121df0_caseD_3;
    }
    break;
  default:
    goto switchD_00121df0_caseD_3;
  case 4:
switchD_00121df0_caseD_4:
    uVar1 = 10;
    goto switchD_00121df0_caseD_3;
  case 5:
    *param_1 = 0xd;
    return 0;
  case 6:
    goto LAB_00121e90;
  case 7:
    goto switchD_00121df0_caseD_7;
  case 9:
    goto switchD_00121df0_caseD_9;
  case 10:
    uStack_70 = uStack_70 & 0xff;
LAB_00121e90:
    *param_2 = uStack_70;
    return 1;
  case 0xb:
    goto switchD_00121df0_caseD_b;
  }
  uVar1 = 4;
  goto switchD_00121df0_caseD_3;
switchD_00121df0_caseD_b:
  iStack_68 = 1;
  goto LAB_00121db8;
switchD_00121df0_caseD_7:
  uVar2 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
  uVar1 = 3;
  if ((uVar2 & 1) == 0) {
    uVar1 = 9;
  }
  goto switchD_00121df0_caseD_3;
}


/* EXPORT index=156 ELF_VA=0x21f48 size=148 source_sha256=726eda66ce3602bc04c8fcbf3a531e68841c2bae44088f0f559c87e141de691b */

undefined8 j___5I5IO_I0__I_5IlI5_5OSSI_I0Il_OIlI_55SS_l0I_ISIOS5_(undefined1 *param_1,uint *param_2)

{
  ulong uVar1;
  byte abStack_30 [8];
  uint uStack_28;
  
  uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,abStack_30);
  if ((uVar1 & 1) == 0) {
    return 0;
  }
  if (abStack_30[0] < 0xe) {
    if (abStack_30[0] != 0) {
LAB_00121fc0:
      *param_1 = 0xd;
      return 0;
    }
  }
  else {
    if (abStack_30[0] == 0x10) goto LAB_00121fb4;
    if (abStack_30[0] == 0xf) {
      uStack_28 = uStack_28 & 0xffff;
      goto LAB_00121fb4;
    }
    if (abStack_30[0] != 0xe) goto LAB_00121fc0;
  }
  uStack_28 = uStack_28 & 0xff;
LAB_00121fb4:
  *param_2 = uStack_28;
  return 1;
}


/* EXPORT index=157 ELF_VA=0x21fdc size=440 source_sha256=361f1dac61d831be8f0cb91e644ed1e7804c03d7b662fb78fee20f7b682ff02d */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00122130) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
j___5Il___5OllI__5I_O_0S0Il_I_lI__SOl_OOllS5O_lO_l0S5_(undefined1 *param_1,ulong *param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  byte abStack_78 [8];
  byte bStack_70;
  undefined1 uStack_6f;
  undefined2 uStack_6e;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  
  uStack_64 = 0;
  uStack_68 = 1;
  uVar3 = 3;
switchD_0012206c_default:
  uVar2 = 0;
  switch(uVar3) {
  case 0:
switchD_0012206c_caseD_0:
    uVar3 = 1;
    goto switchD_0012206c_default;
  case 1:
    goto switchD_0012206c_caseD_1;
  case 2:
    uVar1 = (ulong)CONCAT11(uStack_6f,bStack_70);
    goto LAB_00122114;
  case 3:
    uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,abStack_78);
    uVar3 = 6;
    if ((uVar1 & 1) == 0) {
      uVar3 = 0xb;
    }
    goto switchD_0012206c_default;
  case 4:
switchD_0012206c_caseD_4:
    uStack_64 = 0xa7daa91c;
    uVar3 = 2;
    goto switchD_0012206c_default;
  case 5:
    uVar1 = (ulong)CONCAT22(uStack_6e,CONCAT11(uStack_6f,bStack_70));
    goto LAB_00122114;
  case 6:
    uVar3 = 0xe;
    goto switchD_0012206c_default;
  case 8:
    *param_1 = 0xd;
    return 0;
  case 9:
    uVar1 = CONCAT44(uStack_6c,CONCAT22(uStack_6e,CONCAT11(uStack_6f,bStack_70)));
    goto LAB_00122114;
  case 10:
switchD_0012206c_caseD_a:
    uVar3 = 0;
    goto switchD_0012206c_default;
  case 0xb:
    goto switchD_0012206c_caseD_b;
  case 0xc:
switchD_0012206c_caseD_c:
    uVar3 = 5;
    goto switchD_0012206c_default;
  case 0xd:
    goto switchD_0012206c_caseD_d;
  case 0xe:
    if (abStack_78[0] < 0xe) {
      if (abStack_78[0] == 0) goto switchD_0012206c_caseD_a;
    }
    else {
      switch(abStack_78[0]) {
      case 0xe:
        goto switchD_0012206c_caseD_0;
      case 0xf:
        goto switchD_0012206c_caseD_4;
      case 0x10:
        goto switchD_0012206c_caseD_c;
      case 0x11:
        goto switchD_0012206c_caseD_d;
      }
    }
    break;
  case 0xf:
    return 0;
  default:
    goto switchD_0012206c_default;
  }
  uVar3 = 8;
  goto switchD_0012206c_default;
switchD_0012206c_caseD_d:
  uVar3 = 9;
  goto switchD_0012206c_default;
switchD_0012206c_caseD_1:
  uVar1 = (ulong)bStack_70;
LAB_00122114:
  *param_2 = uVar1;
  uVar2 = 1;
switchD_0012206c_caseD_b:
  return uVar2;
}


/* EXPORT index=158 ELF_VA=0x221e4 size=4 source_sha256=0af3871db92d6fa8f89b9b3dd8630d1ea385d14486da5b611fbf71bf9d27b516 */

void j___5lIll_III0__5_IO___l55l__OIOl550_I_S_S_l_llOI0lS5_(void)

{
  j___5Il___5OllI__5I_O_0S0Il_I_lI__SOl_OOllS5O_lO_l0S5_();
  return;
}


/* EXPORT index=159 ELF_VA=0x221e8 size=188 source_sha256=6d5e1290437127b003e3b1f19be9f23a96ec0883c639189dd992f30d593b2ab0 */

undefined8
j____II_I_IlI0I_S0ll5_l_IOl_OI_0l5IllO5I00I0I_lIIlIS5_(undefined1 *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  ulong uVar2;
  undefined8 uVar3;
  char acStack_58 [8];
  undefined4 uStack_50;
  undefined4 uStack_44;
  
  uStack_44 = 0;
  uVar1 = 3;
  do {
    uVar3 = 0;
    switch(uVar1) {
    case 0:
      *param_1 = 0xd;
      return 0;
    case 1:
      *param_2 = uStack_50;
      uVar3 = 1;
    case 2:
      return uVar3;
    case 3:
      uVar2 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_58);
      uVar1 = 4;
      if ((uVar2 & 1) == 0) {
        uVar1 = 2;
      }
      break;
    case 4:
      uVar1 = acStack_58[0] == '\f';
      break;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=160 ELF_VA=0x222b8 size=100 source_sha256=cc6c9db46dc847c8d16614d1421b3c451712e2a20c65062d9feac345e4240f1b */

undefined8
j___O55SI_I05II__I_IO_55I5S_OI55I5__I5l__IISlI_lIlIS5_(undefined1 *param_1,undefined8 *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  char acStack_30 [8];
  undefined8 uStack_28;
  
  uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_30);
  if ((uVar1 & 1) == 0) {
    uVar2 = 0;
  }
  else if (acStack_30[0] == '\r') {
    *param_2 = uStack_28;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    *param_1 = 0xd;
  }
  return uVar2;
}


/* EXPORT index=161 ELF_VA=0x2231c size=340 source_sha256=a924ffdb4389dc34e910f8681dc8470235f56507aee57972b7d2cedc93feed25 */

undefined8
j___IIlOI__5lI__5llII__lS5I_Il_IO_l_IIOI_O__l_II5IIS5_(undefined1 *param_1,double *param_2)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  char acStack_78 [8];
  float fStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_64;
  
  uStack_64 = 0;
  iVar5 = 2;
  iVar1 = 0x35d5;
switchD_001223f8_caseD_4:
  iVar6 = iVar1;
  iVar2 = iVar5;
switchD_001223f8_caseD_5:
  iVar7 = iVar2;
  uVar4 = 0;
  iVar5 = 6;
  iVar1 = 0x7c0f;
  iVar2 = 3;
  switch(iVar7) {
  case 0:
    if (acStack_78[0] != '\f') {
      iVar2 = 3;
      if (acStack_78[0] == '\r') {
        iVar5 = 6;
        iVar1 = 0x7c0f;
        goto switchD_001223f8_caseD_4;
      }
      goto switchD_001223f8_caseD_5;
    }
    break;
  case 1:
  case 10:
    goto switchD_001223f8_caseD_1;
  case 2:
    goto switchD_001223f8_caseD_2;
  case 3:
    *param_1 = 0xd;
    return 0;
  case 4:
    goto switchD_001223f8_caseD_4;
  default:
    goto switchD_001223f8_caseD_5;
  case 6:
    dVar8 = (double)CONCAT44(uStack_6c,fStack_70);
    goto LAB_00122448;
  case 7:
    goto switchD_001223f8_caseD_7;
  case 8:
    dVar8 = (double)fStack_70;
LAB_00122448:
    *param_2 = dVar8;
    uVar4 = 1;
switchD_001223f8_caseD_1:
    return uVar4;
  }
  iVar2 = 8;
  goto switchD_001223f8_caseD_5;
switchD_001223f8_caseD_7:
  iVar2 = (0x31 - iVar6) + ((uint)(iVar6 * 0x864c) >> 0x15) * 0x3d;
  goto switchD_001223f8_caseD_5;
switchD_001223f8_caseD_2:
  iVar6 = iVar6 + ((uint)(iVar6 * 0xcccd) >> 0x12) * -5;
  uVar3 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
  iVar5 = 8;
  if ((uVar3 & 1) == 0) {
    iVar5 = 2;
  }
  iVar5 = iVar5 - iVar6;
  iVar1 = 0x6d91 - iVar6;
  goto switchD_001223f8_caseD_4;
}


/* EXPORT index=162 ELF_VA=0x2249c size=296 source_sha256=de97cd37467d2922ad34027f3cfd6b9e8cf3c8dd09984c1f95583581d8201e36 */

undefined8 j____II5l_I_055_IOl_5___ll0_OIO_lOIlIl__l___S5_55IOS5_(undefined8 param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  char acStack_78 [20];
  undefined4 uStack_64;
  
  uStack_64 = 0;
  uVar2 = 6;
  do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch(uVar2) {
    case 0:
    case 8:
                    /* WARNING: This code block may not be properly labeled as switch case */
      return 0;
    case 2:
      uVar2 = 1;
      if (acStack_78[0] != '\x04') {
        uVar2 = 7;
      }
      break;
    case 4:
      uVar2 = 7;
      if (acStack_78[0] != '\x04') {
        uVar2 = 3;
      }
      break;
    case 6:
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
      uVar2 = 4;
      if ((uVar1 & 1) == 0) {
        uVar2 = 0;
      }
    }
  } while( true );
}


/* EXPORT index=163 ELF_VA=0x225e8 size=288 source_sha256=a790344aa58fecfcbb3751e40f89c12f905cfad8998d3ade8e128614be270e28 */

undefined8
j___ISIl__l_I0I_l_IOl__O_____ll_O_50S_ISI5_lOSIIll5S5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  char acStack_78 [8];
  char cStack_70;
  undefined4 uStack_64;
  
  uStack_64 = 0;
  uVar3 = 0xd0e;
  iVar4 = 5;
LAB_0012265c:
switchD_001226a4_default:
  uVar2 = 1;
  switch(iVar4) {
  case 1:
    *param_2 = 0;
    iVar4 = 3;
    goto switchD_001226a4_default;
  case 2:
  case 9:
    uVar2 = 0;
    *param_1 = 0xd;
    break;
  case 4:
    iVar4 = 0x56;
    if (cStack_70 != '\0') {
      iVar4 = 0x5b;
    }
    iVar4 = iVar4 - uVar3 % 0x61;
    goto switchD_001226a4_default;
  case 5:
    uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
    iVar4 = 7;
    if ((uVar1 & 1) == 0) {
      iVar4 = 8;
    }
    goto switchD_001226a4_default;
  case 6:
    goto switchD_001226a4_caseD_6;
  case 7:
    goto switchD_001226a4_caseD_7;
  case 8:
  case 10:
    uVar2 = 0;
    break;
  default:
    goto switchD_001226a4_default;
  }
  return uVar2;
switchD_001226a4_caseD_7:
  iVar4 = 4;
  if (acStack_78[0] != '\x05') {
    iVar4 = 2;
  }
  uVar3 = 0x1b9d;
  goto LAB_0012265c;
switchD_001226a4_caseD_6:
  *param_2 = 1;
  iVar4 = 3;
  goto switchD_001226a4_default;
}


/* EXPORT index=164 ELF_VA=0x22734 size=284 source_sha256=ffb7bc7547f94e29a3e136bf6e243971802b5879af835271125a6f59e6ec3a13 */

undefined8
j___S_0OS_00_5I_SlIll__S5OO_5IIll_IOS__I0I5lII_5S_IS5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined1 auStack_78 [20];
  undefined4 uStack_64;
  
  uStack_64 = 0;
  iVar3 = 1;
  do {
    switch(iVar3) {
    case 1:
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,auStack_78);
      iVar3 = 5;
      if ((uVar1 & 1) == 0) {
        iVar3 = 7;
      }
      break;
    default:
      if (iVar3 - 2U < 7) {
                    /* WARNING: Could not recover jumptable at 0x001227f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*(code *)(&UNK_0012286c + *(int *)(&UNK_0012286c + (ulong)(iVar3 - 2U) * 4)))(1);
        return uVar2;
      }
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    case 4:
      *param_2 = 0;
      iVar3 = 3;
      break;
    case 6:
      *param_1 = 0xd;
    case 7:
      return 0;
    }
  } while( true );
}


/* EXPORT index=165 ELF_VA=0x22888 size=1980 source_sha256=09afdc850d4be6a792b2bc11adfb9efb8bc24cec51f26667a1237d654ce515e8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___lI50I_5I0_5_I_O0S_llII__I_5Ol_lSI_llOISI5_IO5I5S5_
               (undefined1 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  ulong uVar5;
  undefined4 uVar6;
  uint uVar7;
  byte abStack_c8 [20];
  undefined4 uStack_b4;
  byte abStack_b0 [72];
  long lStack_68;
  
  uVar7 = 0x4d0e987a;
  uVar6 = 0x12;
  lStack_68 = ___stack_chk_guard;
  uStack_b4 = 0;
  abStack_b0[0x18] = 0x2e;
  abStack_b0[0x19] = 0x12;
  abStack_b0[0x1a] = 0x2d;
  abStack_b0[0x1b] = 0x73;
  abStack_b0[0x1c] = 0x13;
  abStack_b0[0x1d] = 0x4b;
  abStack_b0[0x1e] = 0x2a;
  abStack_b0[0x1f] = 0x2c;
  abStack_b0[0x10] = 0x3b;
  abStack_b0[0x11] = 0x59;
  abStack_b0[0x12] = 0xb;
  abStack_b0[0x13] = 3;
  abStack_b0[0x14] = 0x67;
  abStack_b0[0x15] = 0xb;
  abStack_b0[0x16] = 0x34;
  abStack_b0[0x17] = 7;
  abStack_b0[0x28] = 9;
  abStack_b0[0x29] = 0x7e;
  abStack_b0[0x2a] = 0x28;
  abStack_b0[0x2b] = 0x3a;
  abStack_b0[0x2c] = 0x62;
  abStack_b0[0x2d] = 0x19;
  abStack_b0[0x2e] = 0x32;
  abStack_b0[0x2f] = 0x6e;
  abStack_b0[0x20] = 0x3d;
  abStack_b0[0x21] = 0x27;
  abStack_b0[0x22] = 0x1d;
  abStack_b0[0x23] = 0x42;
  abStack_b0[0x24] = 0x4d;
  abStack_b0[0x25] = 0x1c;
  abStack_b0[0x26] = 0x62;
  abStack_b0[0x27] = 0x31;
  abStack_b0[8] = 0x6c;
  abStack_b0[9] = 0x2b;
  abStack_b0[10] = 0x1f;
  abStack_b0[0xb] = 0x7e;
  abStack_b0[0xc] = 0x7a;
  abStack_b0[0xd] = 0x69;
  abStack_b0[0xe] = 1;
  abStack_b0[0xf] = 0x25;
  abStack_b0[0] = 0x13;
  abStack_b0[1] = 0x7e;
  abStack_b0[2] = 0x47;
  abStack_b0[3] = 0x18;
  abStack_b0[4] = 0x3a;
  abStack_b0[5] = 0x15;
  abStack_b0[6] = 0x75;
  abStack_b0[7] = 0x48;
switchD_00122960_default:
  bVar4 = (byte)uVar7;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(uVar6) {
  case 0:
    uVar6 = 8;
    goto switchD_00122960_default;
  case 2:
    uVar6 = 0x10;
    goto switchD_00122960_default;
  case 4:
    uVar1 = uVar7 + 0x5122253d;
    abStack_b0[uVar7 ^ 0xaedddaee] = abStack_b0[uVar7 ^ 0xaedddaee] ^ bVar4 + 0x1f;
    uVar7 = uVar7 + 0x742b468e ^ 0xc362c649;
    abStack_b0[uVar1] = bVar4 ^ abStack_b0[uVar1] ^ 0x9c;
    cVar3 = (char)uVar7;
    abStack_b0[uVar7 + 0x1f941859] = abStack_b0[uVar7 + 0x1f941859] ^ cVar3 + 0x87U;
    abStack_b0[uVar7 + 0x1f94185c] = abStack_b0[uVar7 + 0x1f94185c] ^ cVar3 + 0x6aU;
    abStack_b0[uVar7 + 0x1f941850] = abStack_b0[uVar7 + 0x1f941850] ^ cVar3 + 0x9fU;
    uVar6 = 0x13;
    goto switchD_00122960_default;
  case 6:
    goto switchD_00122960_caseD_6;
  case 8:
    if (abStack_c8[0] < 0x1b) {
      if (abStack_c8[0] == 3) {
        uVar6 = 0xd;
        goto switchD_00122960_default;
      }
    }
    else {
      if (abStack_c8[0] == 0x1b) {
        uVar6 = 3;
        goto switchD_00122960_default;
      }
      if (abStack_c8[0] == 0x1c) {
        uStack_b4 = 0xadbbcff;
        uVar6 = 9;
        goto switchD_00122960_default;
      }
      if (abStack_c8[0] == 0x1d) {
        uStack_b4 = 0x2aaea379;
        uVar6 = 0xf;
        goto switchD_00122960_default;
      }
    }
    break;
  case 10:
    abStack_b0[uVar7 ^ 0xaedddaec] = abStack_b0[uVar7 ^ 0xaedddaec] ^ bVar4 + 0x75;
    abStack_b0[uVar7 + 0x51222520] = abStack_b0[uVar7 + 0x51222520] ^ bVar4 + 0x5e;
    abStack_b0[uVar7 + 0x5122250f] = abStack_b0[uVar7 + 0x5122250f] ^ bVar4 + 0x76;
    abStack_b0[uVar7 + 0x51222539] = bVar4 ^ abStack_b0[uVar7 + 0x51222539] ^ 0xb4;
    abStack_b0[uVar7 + 0x51222514] = bVar4 ^ abStack_b0[uVar7 + 0x51222514] ^ 0x95;
    abStack_b0[uVar7 + 0x51222528] = bVar4 ^ abStack_b0[uVar7 + 0x51222528] ^ 0xa2;
    abStack_b0[uVar7 + 0x51222522] = abStack_b0[uVar7 + 0x51222522] ^ bVar4 + 0x1f;
    uVar6 = 7;
    goto switchD_00122960_default;
  case 0xc:
    iVar2 = uVar7 * 0x4e7a871a;
    abStack_b0[iVar2 + 0xe9713ec2U] = abStack_b0[iVar2 + 0xe9713ec2U] ^ bVar4 * '\x1a' - 5;
    abStack_b0[iVar2 + 0xe9713ea4U] = abStack_b0[iVar2 + 0xe9713ea4U] ^ bVar4 * '\x1a' + 0x10;
    uVar7 = uVar7 * 0x4e7a871a + 0x984f1986;
    abStack_b0[iVar2 + 0xe9713ec0U] = abStack_b0[iVar2 + 0xe9713ec0U] ^ bVar4 * '\x1a' + 0xa5;
    abStack_b0[uVar7 ^ 0xaedddafb] = (byte)uVar7 ^ abStack_b0[uVar7 ^ 0xaedddafb] ^ 0x9a;
    abStack_b0[iVar2 + 0xe9713ebeU] = abStack_b0[iVar2 + 0xe9713ebeU] ^ bVar4 * '\x1a' - 0x1c;
    uVar6 = 0x14;
    goto switchD_00122960_default;
  case 0x10:
  case 0x16:
    goto switchD_00122960_caseD_10;
  case 0x12:
    uVar5 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_
                      (param_1,abStack_c8,param_3,param_4,0x54dbfb87,0xab240482);
    uVar6 = 0;
    if ((uVar5 & 1) == 0) {
      uVar6 = 2;
    }
    goto switchD_00122960_default;
  case 0x14:
    goto switchD_00122960_caseD_14;
  default:
    goto switchD_00122960_default;
  }
  uVar6 = 6;
  goto switchD_00122960_default;
switchD_00122960_caseD_14:
  abStack_b0[uVar7 + 0x5122251b] = abStack_b0[uVar7 + 0x5122251b] ^ bVar4 + 0x41;
  abStack_b0[uVar7 ^ 0xaedddaf9] = abStack_b0[uVar7 ^ 0xaedddaf9] ^ bVar4 + 0x54;
  abStack_b0[uVar7 + 0x5122251f] = abStack_b0[uVar7 + 0x5122251f] ^ bVar4 + 0x76;
  abStack_b0[uVar7 + 0x51222532] = bVar4 ^ abStack_b0[uVar7 + 0x51222532] ^ 0xe3;
  abStack_b0[uVar7 ^ 0xaedddae4] = bVar4 ^ abStack_b0[uVar7 ^ 0xaedddae4] ^ 0x95;
  abStack_b0[uVar7 + 0x51222526] = bVar4 ^ abStack_b0[uVar7 + 0x51222526] ^ 0x8e;
  abStack_b0[uVar7 + 0x51222536] = abStack_b0[uVar7 + 0x51222536] ^ bVar4 + 0x8a;
  uVar6 = 10;
  goto switchD_00122960_default;
switchD_00122960_caseD_6:
  *param_1 = 0xd;
switchD_00122960_caseD_10:
  if (___stack_chk_guard == lStack_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(0);
}


/* EXPORT index=166 ELF_VA=0x230a0 size=276 source_sha256=cbddab8c629dd0238ebcdd408d643d64fca922272113655716844ed971bf4f5e */

undefined8
j___O0_I0_O_0S__S5Il0_IIl_l_l__0I_I_0IS_OlS50OOSII_S5_
          (undefined1 *param_1,long param_2,uint *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined4 uVar4;
  uint auStack_58 [2];
  
  auStack_58[1] = 0;
  uVar4 = 3;
  do {
    uVar2 = 0;
    switch(uVar4) {
    case 1:
      goto switchD_0012311c_caseD_1;
    case 2:
      *param_1 = 9;
      return 0;
    case 3:
      auStack_58[0] = 0;
      uVar3 = j___lI50I_5I0_5_I_O0S_llII__I_5Ol_lSI_llOISI5_IO5I5S5_(param_1,auStack_58);
      uVar4 = 6;
      if ((uVar3 & 1) == 0) {
        uVar4 = 1;
      }
      break;
    case 4:
      *param_3 = auStack_58[0];
      *param_1 = 1;
      return 0;
    case 5:
      uVar1 = (**(code **)(param_1 + 0x10))(param_1,param_2,auStack_58[0]);
      uVar4 = 2;
      if ((uVar1 & 1) != 0) {
        *(undefined1 *)(param_2 + (ulong)auStack_58[0]) = 0;
        *param_3 = auStack_58[0];
        uVar2 = 1;
switchD_0012311c_caseD_1:
        return uVar2;
      }
      break;
    case 6:
      uVar4 = 4;
      if (auStack_58[0] + 1 <= *param_3) {
        uVar4 = 5;
      }
      break;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=167 ELF_VA=0x231cc size=268 source_sha256=fb79d70d1ff264e8918580a5aecc0cb9205c1bc3d2ad0a766020309b4a01679c */

undefined8
j___O_5Ol_ISIO0_0O_lS_I5_SO__IIIl5I_I0O5I0SlIS5I5IIS5_(undefined1 *param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  undefined4 uVar3;
  char acStack_68 [8];
  undefined4 uStack_60;
  undefined4 uStack_54;
  
  uStack_54 = 0;
  uVar3 = 2;
switchD_0012323c_default:
  do {
    uVar1 = 0;
    switch(uVar3) {
    case 0:
      uVar3 = 5;
      break;
    case 1:
      uVar3 = 4;
      break;
    case 2:
      uVar2 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_68);
      uVar3 = 1;
      if ((uVar2 & 1) == 0) {
        uVar3 = 9;
      }
      break;
    case 3:
      goto switchD_0012323c_caseD_3;
    case 4:
      goto switchD_0012323c_caseD_4;
    case 5:
      goto switchD_0012323c_caseD_5;
    case 6:
      *param_2 = uStack_60;
      uVar1 = 1;
switchD_0012323c_caseD_9:
      return uVar1;
    case 7:
      goto switchD_0012323c_caseD_7;
    case 8:
      *param_1 = 0xd;
      return 0;
    case 9:
    case 10:
      goto switchD_0012323c_caseD_9;
    }
  } while( true );
switchD_0012323c_caseD_4:
  uVar3 = 5;
  if (acStack_68[0] != '\x06') {
    if (acStack_68[0] == '\a') {
switchD_0012323c_caseD_5:
      uVar3 = 7;
    }
    else if (acStack_68[0] == '\b') {
switchD_0012323c_caseD_7:
      uStack_54 = 0x8b8db4b6;
      uVar3 = 6;
    }
    else {
switchD_0012323c_caseD_3:
      uVar3 = 8;
    }
  }
  goto switchD_0012323c_default;
}


/* EXPORT index=168 ELF_VA=0x23304 size=68 source_sha256=7730fa07fd9b1ceac09e5eb53cdbe681b023e8d8372cad061b54545cecaa844e */

bool j___Il0_5_SII_I_O05I5_II_0___I0IlOIlI5__IIl__II5IllS5_
               (undefined1 *param_1,undefined8 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = (**(code **)(param_1 + 0x10))(param_1,param_2,param_3);
  bVar1 = (uVar2 & 1) == 0;
  if (bVar1) {
    *param_1 = 9;
  }
  return !bVar1;
}


/* EXPORT index=169 ELF_VA=0x23348 size=304 source_sha256=32790f97ab7f6dfc40bb3df4bae003c2ce2cfb95cb1debcfbde4dd33fd174685 */

undefined8
j___OOlIO_0SOl0_I00_O_IlSII_OS_l_500ISSl_OS_IlIlI5IS5_(undefined1 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined4 uVar4;
  char acStack_78 [8];
  undefined4 uStack_70;
  undefined4 uStack_64;
  
  uStack_64 = 0;
  uVar1 = 9;
switchD_001233e0_caseD_0:
  uVar4 = uVar1;
  uVar2 = 0;
  uVar1 = 7;
  switch(uVar4) {
  default:
    goto switchD_001233e0_caseD_0;
  case 2:
    goto switchD_001233e0_caseD_2;
  case 3:
  case 7:
    *param_1 = 0xd;
    return 0;
  case 4:
  case 0xb:
    goto switchD_001233e0_caseD_4;
  case 5:
    uVar1 = 6;
    goto switchD_001233e0_caseD_0;
  case 6:
    if (acStack_78[0] == '\x1f') goto switchD_001233e0_caseD_8;
    if (acStack_78[0] == '\x1e') goto switchD_001233e0_caseD_a;
    uVar1 = 7;
    if (acStack_78[0] != '\x02') goto switchD_001233e0_caseD_0;
    break;
  case 8:
switchD_001233e0_caseD_8:
    uStack_64 = 0xcf6f5bd8;
    uVar1 = 2;
    goto switchD_001233e0_caseD_0;
  case 9:
    goto switchD_001233e0_caseD_9;
  case 10:
switchD_001233e0_caseD_a:
    uStack_64 = 0xf66314b1;
    uVar1 = 8;
    goto switchD_001233e0_caseD_0;
  }
  uVar1 = 10;
  goto switchD_001233e0_caseD_0;
switchD_001233e0_caseD_9:
  uVar3 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
  uVar1 = 4;
  if ((uVar3 & 1) != 0) {
    uVar1 = 5;
  }
  goto switchD_001233e0_caseD_0;
switchD_001233e0_caseD_2:
  *param_2 = uStack_70;
  uVar2 = 1;
switchD_001233e0_caseD_4:
  return uVar2;
}


/* EXPORT index=170 ELF_VA=0x234a8 size=560 source_sha256=c3e5156e0b302df8d3ca0521a91d1a939f6c423c96c1479de697fa1b9e367d0f */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00123690) */

uint j___lIIII_lO0S5_lIO00_OSlOS_IIl_IOI_l_5l0I5l_I5Ol_IS5_(undefined1 *param_1,undefined4 *param_2)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char acStack_78 [8];
  undefined4 uStack_70;
  int iStack_68;
  undefined4 uStack_64;
  
  iStack_68 = 0;
  iVar2 = 0x3c4a;
  uStack_64 = 0xa66a55bf;
  iVar3 = 4;
switchD_00123584_default:
  uVar4 = 0;
  switch(iVar3) {
  case 0:
    goto switchD_00123584_caseD_0;
  case 1:
    iVar3 = (0x61 - iVar2) + ((uint)(iVar2 * 0xa238) >> 0x16) * 0x65;
    goto switchD_00123584_default;
  case 3:
    iVar2 = ((uint)(iVar2 * 0x8422) >> 0x14) * -0x1f + iVar2;
    if (iStack_68 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    iVar3 = 0xf - iVar2;
    iVar2 = 0x2bcd - iVar2;
    goto switchD_00123584_default;
  case 4:
    uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
    iVar3 = 3;
    if ((uVar1 & 1) == 0) {
      iVar3 = 0;
    }
    iVar2 = 0x7356;
    goto switchD_00123584_default;
  case 5:
switchD_00123584_caseD_5:
    uStack_64 = 0x934adc96;
    iVar3 = 9;
    goto switchD_00123584_default;
  case 6:
    *param_2 = uStack_70;
    uVar4 = 1;
    goto switchD_00123584_caseD_0;
  case 7:
switchD_00123584_caseD_7:
    iVar3 = 10;
    goto switchD_00123584_default;
  case 8:
    if (acStack_78[0] != '\x01') {
      if (acStack_78[0] == ' ') goto switchD_00123584_caseD_7;
      if (acStack_78[0] == '!') goto switchD_00123584_caseD_a;
      goto switchD_00123584_caseD_5;
    }
    break;
  case 9:
    uVar4 = 0;
    *param_1 = 0xd;
    goto switchD_00123584_caseD_0;
  case 10:
    goto switchD_00123584_caseD_a;
  case 0xb:
    uVar4 = 0xd6662461;
    goto switchD_00123584_caseD_0;
  default:
    goto switchD_00123584_default;
  }
  uStack_64 = 0x4f3ec4b6;
  iVar3 = 7;
  goto switchD_00123584_default;
switchD_00123584_caseD_a:
  iVar2 = 0x40b6;
  iVar3 = 6;
  goto switchD_00123584_default;
switchD_00123584_caseD_0:
  return uVar4 & 1;
}


/* EXPORT index=171 ELF_VA=0x23708 size=200 source_sha256=0523d40667923d3c939823d9177d2a1eb773e105bd177f91211422eebbf100a8 */

undefined8
j_____O___lIIII__l55I_SI_II_O__lI__I_0I55SI_5OI0IllS5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  char acStack_68 [8];
  undefined1 uStack_60;
  undefined4 uStack_54;
  
  uStack_54 = 0;
  uVar2 = 1;
  do {
    switch(uVar2) {
    case 0:
      uVar2 = 5;
      if (acStack_68[0] != '\x16') {
        uVar2 = 3;
      }
      break;
    case 1:
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_68);
      uVar2 = 0;
      if ((uVar1 & 1) == 0) {
        uVar2 = 2;
      }
      break;
    case 2:
      return 0;
    case 3:
      *param_1 = 0xd;
      return 0;
    default:
      do {
      } while( true );
    case 5:
      *param_2 = uStack_60;
      return 1;
    }
  } while( true );
}


/* EXPORT index=172 ELF_VA=0x237e8 size=476 source_sha256=0eac0f804e5868eb84761686ede7faf990fc76bd15989757db7a80bd9f67ef93 */

/* WARNING: Switch with 1 destination removed at 0x00123878 */
/* WARNING: Exceeded maximum restarts with more pending */

undefined8
j___SS_OO_5IIOI__III5_05l___OIIlIlOlI__IS5_l5SI__IlS5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  char acStack_78 [8];
  undefined1 uStack_70;
  undefined4 uStack_64;
  
  iVar2 = 4;
  uVar3 = 1;
  do {
                    /* WARNING: This code block may not be properly labeled as switch case */
    if (iVar2 != 4) {
      if (iVar2 == 1) {
        uVar3 = 0;
      }
      else if (iVar2 != 6) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      return uVar3;
    }
    uStack_64 = 0;
    uVar4 = 1;
LAB_001238f0:
    switch(uVar4) {
    case 0:
      uVar4 = 5;
      if (acStack_78[0] != '\x16') {
        uVar4 = 3;
      }
      goto LAB_001238f0;
    case 1:
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
      uVar4 = 0;
      if ((uVar1 & 1) == 0) {
        uVar4 = 2;
      }
      goto LAB_001238f0;
    case 3:
      *param_1 = 0xd;
    case 2:
      iVar2 = 1;
      break;
    default:
      goto switchD_00123904_caseD_4;
    case 5:
      iVar2 = 0;
      *param_2 = uStack_70;
    }
  } while( true );
switchD_00123904_caseD_4:
  do {
  } while( true );
}


/* EXPORT index=173 ELF_VA=0x239f4 size=1980 source_sha256=f08260a84b104f17c8b9933b9205c7b1d462524d575fb7c7027b78b35fdc3fa4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j____Sl0I_lIS55_II5II_OOISl_I0ll0_lIO05l_SII5O0__S5S5_(undefined1 *param_1,undefined1 *param_2)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  long lVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  undefined1 *extraout_x1;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  uint uVar12;
  uint uVar13;
  char acStack_138 [8];
  undefined1 uStack_130;
  undefined4 uStack_124;
  undefined1 auStack_120 [128];
  undefined7 uStack_a0;
  byte bStack_99;
  ulong uStack_98;
  undefined8 uStack_90;
  undefined7 uStack_88;
  undefined1 uStack_81;
  undefined7 uStack_80;
  ulong uStack_79;
  
  lVar4 = ___stack_chk_guard;
  uVar12 = 0x3c04;
  iVar8 = 8;
  uStack_124 = 0;
  uStack_79 = 0x441e187252562029;
  uStack_80 = 0x39205d0c06047c;
  uStack_98 = 0x7201561c4c68712f;
  uStack_a0 = 0x7f6b344b693a52;
  bStack_99 = 0x2d;
  uStack_88 = 0x6e6b69385f2d51;
  uStack_81 = 0x10;
  uStack_90 = 0x4f0b2a361e480a7d;
  puVar7 = param_2;
  uVar13 = 0x40ba9;
  do {
    uVar6 = 0;
    bVar3 = (byte)uVar13;
    switch(iVar8) {
    case 0:
      uVar13 = uVar13 ^ 0x3b63bbad;
      bVar3 = (char)uVar13 - 7;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x5ade7f9e)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x5ade7f9e)) ^ bVar3;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x5ade7f81)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x5ade7f81)) ^ (char)uVar13 - 0x3dU;
      uVar5 = uVar13 + 0x6c061e92;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x5ade7f83)) =
           (byte)uVar5 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x5ade7f83)) ^ 0x12;
      uVar13 = uVar5 * uVar5;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar5 ^ 0x11279f19)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar5 ^ 0x11279f19)) ^ bVar3;
      iVar8 = (0x31 - uVar12) + (uVar12 / 0x6d) * 0x6d;
      break;
    case 1:
      uVar6 = 0;
      *param_1 = 0xd;
switchD_00123b38_caseD_7:
      if (___stack_chk_guard != lVar4) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(uVar6,puVar7);
      }
      return;
    case 2:
      uVar13 = uVar13 ^ 0x6bf7987e;
      uVar9 = (ulong)(uVar13 * uVar13 + 0xa247bc0c);
      uVar10 = (ulong)(uVar13 * uVar13 + 0xa247bc1e);
      cVar2 = (char)uVar13;
      uVar11 = (ulong)(uVar13 * uVar13 + 0xbd2beab9 ^ 0x1ae42eb6);
      *(byte *)((long)&uStack_a0 + uVar10) =
           *(byte *)((long)&uStack_a0 + uVar10) ^ cVar2 * cVar2 + 10U;
      *(byte *)((long)&uStack_a0 + uVar11) =
           *(byte *)((long)&uStack_a0 + uVar11) ^ cVar2 * cVar2 + 1U;
      uVar13 = uVar13 * uVar13 + 0x511d45bd;
      *(byte *)((long)&uStack_a0 + uVar9) =
           *(byte *)((long)&uStack_a0 + uVar9) ^ cVar2 * cVar2 + 0x74U;
      iVar8 = (0x2e - uVar12) + (uVar12 / 0x6d) * 0x6d;
      break;
    case 3:
      iVar8 = 0xf;
      if (acStack_138[0] != '\x17') {
        iVar8 = 1;
      }
      uVar12 = 0x25e3;
      break;
    case 4:
      uVar1 = (uVar13 & 0x7970f69f) << 1;
      uVar5 = uVar13 + 0xa170f3a4;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0x5e8f0c90)) =
           bVar3 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0x5e8f0c90)) ^ 0xfe;
      uVar13 = uVar1 ^ 0xe15232f7;
      *(byte *)((long)&uStack_a0 + (ulong)uVar5) =
           bVar3 ^ *(byte *)((long)&uStack_a0 + (ulong)uVar5) ^ 0xc2;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xaeadc40c)) =
           (byte)uVar1 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xaeadc40c)) ^ 0x27;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xaeadc406)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xaeadc406)) ^ (char)uVar13 + 0x57U;
      iVar8 = 6;
      break;
    case 5:
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xc030fe64)) =
           ~(bVar3 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xc030fe64)));
      uVar5 = uVar13 + 0x505cb606;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xc030fe48)) =
           bVar3 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xc030fe48)) ^ 0xcd;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xc030fe68)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xc030fe68)) ^ bVar3 + 0x76;
      uVar9 = (ulong)(uVar5 * uVar5 + 0xe1f35fa4);
      *(byte *)((long)&uStack_a0 + (ulong)(uVar5 ^ 0x902bb7a6)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar5 ^ 0x902bb7a6)) ^ bVar3 + 0xac;
      uVar13 = uVar5 * uVar5;
      *(byte *)((long)&uStack_a0 + uVar9) =
           (byte)uVar13 ^ *(byte *)((long)&uStack_a0 + uVar9) ^ 0x80;
      iVar8 = (0x36 - uVar12) + (uVar12 / 0x6d) * 0x6d;
      break;
    case 6:
      do {
        puVar7 = auStack_120;
        CallSupervisor(0);
      } while (&stack0x00000000 == (undefined1 *)0x9c);
      uVar12 = 0x4782;
      iVar8 = 0xf;
      break;
    case 7:
    case 0x12:
      goto switchD_00123b38_caseD_7;
    case 8:
      uVar5 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_138);
      if ((uVar5 & 1) == 0) {
        iVar8 = 0x29;
      }
      else {
        iVar8 = 0x25;
      }
      iVar8 = iVar8 - uVar12 % 0x49;
      puVar7 = extraout_x1;
      break;
    case 9:
      uVar9 = (ulong)(uVar13 * uVar13 + 0x95622a89);
      uVar13 = uVar13 * uVar13 + 0x53a0b969 & 0xea39e1d9;
      *(byte *)((long)&uStack_a0 + uVar9) =
           *(byte *)((long)&uStack_a0 + uVar9) ^ bVar3 * bVar3 + 0xbd;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0xaa3880ca)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0xaa3880ca)) ^ (char)uVar13 + 0x31U;
      iVar8 = 0x10;
      break;
    case 10:
      uVar12 = uVar13 << 3 ^ 0x38af7ca8;
      uVar13 = uVar12 + 0x1e82d484;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0x9e423b30)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0x9e423b30)) ^ (char)uVar12 + 0x70U;
      iVar8 = 0;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar12 + 0x8040997a)) =
           (byte)uVar13 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar12 + 0x8040997a)) ^ 0x58;
      uVar12 = 0x83c;
      break;
    case 0xb:
      *param_2 = uStack_130;
      uVar6 = 1;
      goto switchD_00123b38_caseD_7;
    case 0xc:
      iVar8 = uVar13 * uVar13 * 2;
      uVar9 = (ulong)(iVar8 * iVar8 + 0xa170f3a2);
      cVar2 = (char)iVar8;
      uVar13 = iVar8 * iVar8;
      *(byte *)((long)&uStack_a0 + uVar9) =
           *(byte *)((long)&uStack_a0 + uVar9) ^ cVar2 * cVar2 - 0x2eU;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0x5e8f0c8c)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0x5e8f0c8c)) ^ cVar2 * cVar2 + 0x86U;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0x5e8f0ca0)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0x5e8f0ca0)) ^ cVar2 * cVar2 - 0x1fU;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0x5e8f0c8a)) =
           (byte)uVar13 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0x5e8f0c8a)) ^ 0xe1;
      iVar8 = 4;
      break;
    case 0xd:
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x571dfce7)) =
           bVar3 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x571dfce7)) ^ 0x58;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x571dfce0)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x571dfce0)) ^ bVar3 + 0x3a;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x571dfceb)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x571dfceb)) ^ bVar3 + 0x3a;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x571dfcc6)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x571dfcc6)) ^ bVar3 - 0x28;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x571dfcc0)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x571dfcc0)) ^ bVar3 - 0x11;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0xa8e20343)) =
           bVar3 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0xa8e20343)) ^ 0x25;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x571dfced)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x571dfced)) ^ bVar3 + 0x34;
      iVar8 = (0x2f - uVar12) + (uVar12 / 0x6d) * 0x6d;
      break;
    case 0xe:
      uStack_79 = uStack_79 ^ 0x7a0a0000;
      uStack_98 = uStack_98 ^ 0x440000007a00;
      uVar12 = 0x18d7;
      iVar8 = 5;
      bStack_99 = bStack_99 ^ 0x46;
      uVar13 = 0x3fcf01b9;
      break;
    case 0xf:
      iVar8 = (0x2e - uVar12) + (uVar12 / 0x97) * 0x97;
      break;
    case 0x10:
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x55c77f45)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x55c77f45)) ^ bVar3 + 0xaa;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0xaa3880cb)) =
           bVar3 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar13 ^ 0xaa3880cb)) ^ 0x86;
      uVar5 = uVar13 * 2;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x55c77f5c)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0x55c77f5c)) ^ bVar3 + 0x5f;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar5 + 0xab8efe78)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar5 + 0xab8efe78)) ^ (byte)uVar5 + 0xa4;
      uVar12 = 0x311c;
      uVar13 = uVar13 << 2;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar5 ^ 0x547101b3)) =
           (byte)uVar5 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar5 ^ 0x547101b3)) ^ 0xaa;
      iVar8 = 0xd;
      break;
    case 0x11:
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xe1f35f96)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xe1f35f96)) ^ bVar3 - 0xd;
      uVar5 = uVar13 + 0x39f43a1d;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xe1f35f8f)) =
           bVar3 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xe1f35f8f)) ^ 0xd7;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar5 ^ 0x5800dab0)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar5 ^ 0x5800dab0)) ^ bVar3 - 0x3d;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xe1f35fa2)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xe1f35fa2)) ^ bVar3 - 0x3d;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xe1f35f95)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar13 + 0xe1f35f95)) ^ bVar3 + 0xae;
      uVar12 = 0x5c1d;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar5 ^ 0x5800da8f)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar5 ^ 0x5800da8f)) ^ bVar3 + 0x97;
      iVar8 = 2;
      uVar13 = uVar5;
    }
  } while( true );
}


/* EXPORT index=174 ELF_VA=0x241fc size=256 source_sha256=7b93bfa011c0c2f052f77de40246512cc7d1a7ffc793c218b5ac7d902d5604bb */

undefined8
j___0l5II_5I005_lIIIO___5SI_I_Ol55IIIl5Ill_IlI00lS0S5_
          (undefined1 *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    while( true ) {
      while (iVar3 == 0) {
        uVar2 = j____Sl0I_lIS55_II5II_OOISl_I0ll0_lIO05l_SII5O0__S5S5_(param_1,param_2);
        iVar3 = 5;
        if ((uVar2 & 1) == 0) {
          iVar3 = 2;
        }
      }
      if (iVar3 == 1) {
        return 1;
      }
      if (iVar3 != 3) break;
      uVar2 = (**(code **)(param_1 + 0x10))(param_1,param_3,2);
      iVar3 = 3;
      if ((uVar2 & 1) == 0) {
        iVar3 = 1;
      }
    }
    if (iVar3 != 5) {
      if (iVar3 == 2) {
        return 0;
      }
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uVar1 = (**(code **)(param_1 + 0x10))(param_1,param_3,2);
    iVar3 = 1;
  } while ((uVar1 & 1) != 0);
  *param_1 = 9;
  return 0;
}


/* EXPORT index=175 ELF_VA=0x242fc size=188 source_sha256=bae83ffd8a911d0fc30f5983686cb6073e9140fcd524ee05976be6209a78d305 */

undefined8
j____S_0S__0llS_5ll5I__II_0__IlIIO__lIOlO_50S_I_I_IS5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  char acStack_58 [8];
  undefined1 uStack_50;
  undefined4 uStack_44;
  
  uStack_44 = 0;
  uVar2 = 1;
  do {
    switch(uVar2) {
    case 0:
      *param_2 = uStack_50;
      return 1;
    case 1:
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_58);
      uVar2 = 2;
      if ((uVar1 & 1) == 0) {
        uVar2 = 3;
      }
      break;
    case 2:
      uVar2 = 0;
      if (acStack_58[0] != '\x18') {
        uVar2 = 4;
      }
      break;
    case 3:
      return 0;
    case 4:
      *param_1 = 0xd;
      return 0;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=176 ELF_VA=0x243cc size=400 source_sha256=78c588409b1090ee88707b60eb1257777f29cc2fd0ef448a3856fa279f251ac0 */

/* WARNING: Exceeded maximum restarts with more pending */

undefined8
j____Il55_lI_0S_l__5O_IOSIS__05ll_ISIIl_I_SIlS_l__0S5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char acStack_78 [8];
  undefined1 uStack_70;
  undefined4 uStack_64;
  
  iVar4 = 0x34a;
  iVar2 = 4;
LAB_00124428:
  switch(iVar2) {
  case 0x124480:
                    /* WARNING: This code block may not be properly labeled as switch case */
    uStack_64 = 0;
    iVar4 = iVar4 + ((uint)(iVar4 * 0xd902) >> 0x17) * -0x97;
    uVar3 = 1;
    break;
  default:
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  do {
    iVar2 = 0x5a;
    switch(uVar3) {
    case 0:
      *param_2 = uStack_70;
      iVar2 = 0x59;
      goto switchD_001244cc_caseD_3;
    case 1:
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
      uVar3 = 2;
      if ((uVar1 & 1) == 0) {
        uVar3 = 3;
      }
      break;
    case 2:
      uVar3 = 0;
      if (acStack_78[0] != '\x18') {
        uVar3 = 4;
      }
      break;
    case 3:
      goto switchD_001244cc_caseD_3;
    case 4:
      *param_1 = 0xd;
      iVar2 = 0x5a;
      goto switchD_001244cc_caseD_3;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
switchD_001244cc_caseD_3:
  iVar2 = iVar2 - iVar4;
  iVar4 = 0x42ff - iVar4;
  if (iVar2 == 7) {
    return 1;
  }
  goto LAB_00124428;
}


/* EXPORT index=177 ELF_VA=0x24590 size=188 source_sha256=0f48069cb1101712c881e19f4110b19fb83ba40c14715e8b0c73bb3f3b75c5c0 */

undefined8
j___0IO_O_lOIlS_OI_0__ll_IS_II0lI5I_I5lISOI00Il5I0SS5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  char acStack_58 [8];
  undefined1 uStack_50;
  undefined4 uStack_44;
  
  uStack_44 = 0;
  uVar2 = 4;
  do {
    switch(uVar2) {
    case 0:
      *param_2 = uStack_50;
      return 1;
    default:
      do {
      } while( true );
    case 2:
      return 0;
    case 3:
      uVar2 = 0;
      if (acStack_58[0] != '\x19') {
        uVar2 = 5;
      }
      break;
    case 4:
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_58);
      uVar2 = 2;
      if ((uVar1 & 1) != 0) {
        uVar2 = 3;
      }
      break;
    case 5:
      *param_1 = 0xd;
      return 0;
    }
  } while( true );
}


/* EXPORT index=178 ELF_VA=0x24664 size=312 source_sha256=32c04f173b2dec3ed46dca0066b50f60a6bff145831d080f2d02f40577b554c4 */

/* WARNING: Exceeded maximum restarts with more pending */

undefined8
j____I5OI__S0O__5IlI__llll0__S05O_lISI_I5l5SIII__lOS5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  char acStack_78 [8];
  undefined1 uStack_70;
  undefined4 uStack_64;
  
  uVar2 = 2;
  do {
    switch(uVar2) {
    case 0x1246fc:
                    /* WARNING: This code block may not be properly labeled as switch case */
      uStack_64 = 0;
      uVar2 = 4;
      break;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
LAB_00124720:
    switch(uVar2) {
    case 0:
      *param_2 = uStack_70;
      uVar2 = 4;
      break;
    default:
      goto switchD_00124738_caseD_1;
    case 2:
      return 0;
    case 3:
      uVar2 = 0;
      if (acStack_78[0] != '\x19') {
        uVar2 = 5;
      }
      goto LAB_00124720;
    case 4:
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
      uVar2 = 2;
      if ((uVar1 & 1) != 0) {
        uVar2 = 3;
      }
      goto LAB_00124720;
    case 5:
      *param_1 = 0xd;
      return 0;
    }
  } while( true );
switchD_00124738_caseD_1:
  do {
  } while( true );
}


/* EXPORT index=179 ELF_VA=0x247c4 size=240 source_sha256=50fc498c0a9ec23320cfcb095ab8e1ce814fd24a9a8037be0d7211d63c5f0c3b */

/* WARNING: Switch with 1 destination removed at 0x00124874 */

void j____S_lI_OISl0_SSlIl_I5I5I_55I0I_I_I05_OSIllO0IOSIS5_(undefined8 param_1)

{
  ulong uVar1;
  uint uVar2;
  undefined1 auStack_78 [20];
  undefined4 uStack_64;
  
  uStack_64 = 0;
  uVar2 = 1;
  do {
    do {
      do {
      } while (5 < uVar2);
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,auStack_78);
      uVar2 = 4;
    } while ((uVar1 & 1) != 0);
    uVar2 = 2;
  } while( true );
}


/* EXPORT index=180 ELF_VA=0x248cc size=384 source_sha256=594f32e95d49359d9248937105a85d050870cdb6ced835788b5cab512e0c5221 */

/* WARNING: Exceeded maximum restarts with more pending */

void j___llI0__5_50__OSlII_IIIIO_I_OIOlI_lI_0lIIlS5_05S_S5_(undefined1 *param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char acStack_78 [8];
  undefined1 uStack_70;
  undefined4 uStack_64;
  
  uVar2 = 4;
switchD_001249dc_caseD_2:
  switch(uVar2) {
  case 0x124971:
                    /* WARNING: This code block may not be properly labeled as switch case */
    uStack_64 = 0;
    uVar4 = 0x39c1;
    iVar3 = 1;
    break;
  default:
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
LAB_001249a4:
  iVar5 = 0x51;
  if (acStack_78[0] != '\x1a') {
    iVar5 = 0x4e;
  }
  iVar5 = ((uVar4 / 0xad) * 0xad - uVar4) + iVar5;
  do {
    uVar2 = 2;
    switch(iVar3) {
    case 0:
      *param_1 = 0xd;
      uVar2 = 2;
      goto switchD_001249dc_caseD_2;
    case 1:
      goto switchD_001249dc_caseD_1;
    case 2:
    case 5:
      goto switchD_001249dc_caseD_2;
    case 3:
      *param_2 = uStack_70;
      uVar2 = 1;
      goto switchD_001249dc_caseD_2;
    case 4:
      iVar3 = iVar5;
      if (iVar5 == 5) {
        uVar2 = 2;
        goto switchD_001249dc_caseD_2;
      }
      break;
    default:
      goto switchD_001249dc_default;
    }
  } while( true );
switchD_001249dc_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_001249dc_caseD_1:
  uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
  iVar3 = 4;
  if ((uVar1 & 1) == 0) {
    iVar3 = 2;
  }
  uVar4 = 0x4b51;
  goto LAB_001249a4;
}


/* EXPORT index=181 ELF_VA=0x24a74 size=328 source_sha256=31d5fd8ebb7595ce2ab9549ddac54742a39739facee543036c2e06a8959ce80d */

/* WARNING: Control flow encountered bad instruction data */

undefined8
j___ll_SI_IO_ll_5Ill0_0l_Sl_IS__O____I_IIIlII_IISI_S5_
          (undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  char acStack_68 [16];
  int iStack_58;
  undefined4 uStack_54;
  
  uStack_54 = 0;
  iStack_58 = 0;
  uVar1 = 3;
LAB_00124ae4:
  uVar2 = 0;
  switch(uVar1) {
  case 0:
    goto switchD_00124afc_caseD_0;
  case 1:
    break;
  case 2:
    uVar1 = 5;
    if (acStack_68[0] != '\t') {
      uVar1 = 6;
    }
    goto LAB_00124ae4;
  case 3:
    uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_68);
    uVar1 = ~uVar1 & 1;
    goto LAB_00124ae4;
  case 4:
    uVar3 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_68);
    uVar1 = 3;
    if ((uVar3 & 1) != 0) {
      uVar1 = 4;
    }
    goto LAB_00124ae4;
  case 5:
    *param_2 = (char)acStack_68._8_8_;
    *param_3 = SUB81(acStack_68._8_8_,4);
    uVar2 = 1;
    break;
  case 6:
    uVar2 = 0;
    *param_1 = 0xd;
    break;
  default:
    goto switchD_00124afc_default;
  }
  return uVar2;
switchD_00124afc_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_00124afc_caseD_0:
  uVar1 = 2;
  if (iStack_58 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  goto LAB_00124ae4;
}


/* EXPORT index=182 ELF_VA=0x24bd8 size=1928 source_sha256=35179855fca2bc2b2073cff113ec7b87e54fae69330647c345c5fbf63806873f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___lSSSI_Il0l__IOl___II_Sl_0O5II_IOI_O5IIIIlIOS0IOS5_
               (undefined1 *param_1,undefined1 *param_2,undefined1 *param_3,undefined8 param_4)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  undefined1 *extraout_x1;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auVar9 [16];
  undefined1 auStack_120 [128];
  byte abStack_a0 [32];
  uint uStack_80;
  undefined1 uStack_7c;
  undefined8 uStack_7b;
  long lStack_68;
  
  uVar8 = 0x5fa8;
  iVar6 = 0xf;
  lStack_68 = ___stack_chk_guard;
  uStack_7b = 0x5c115d4e7e011865;
  uStack_80 = 0x21740007;
  uStack_7c = 0x53;
  abStack_a0[8] = 0x6d;
  abStack_a0[9] = 0x49;
  abStack_a0[10] = 0x27;
  abStack_a0[0xb] = 7;
  abStack_a0[0xc] = 7;
  abStack_a0[0xd] = 0xf;
  abStack_a0[0xe] = 0x22;
  abStack_a0[0xf] = 0x75;
  abStack_a0[0] = 0x49;
  abStack_a0[1] = 0x2b;
  abStack_a0[2] = 0x4f;
  abStack_a0[3] = 0x39;
  abStack_a0[4] = 0xf;
  abStack_a0[5] = 0x37;
  abStack_a0[6] = 0xf;
  abStack_a0[7] = 100;
  abStack_a0[0x18] = 0x4b;
  abStack_a0[0x19] = 0xb;
  abStack_a0[0x1a] = 0x26;
  abStack_a0[0x1b] = 99;
  abStack_a0[0x1c] = 0x43;
  abStack_a0[0x1d] = 0x31;
  abStack_a0[0x1e] = 0x27;
  abStack_a0[0x1f] = 0x5e;
  abStack_a0[0x10] = 0x37;
  abStack_a0[0x11] = 0x5b;
  abStack_a0[0x12] = 7;
  abStack_a0[0x13] = 0x6c;
  abStack_a0[0x14] = 0x49;
  abStack_a0[0x15] = 0x4b;
  abStack_a0[0x16] = 0x32;
  abStack_a0[0x17] = 0x21;
  puVar5 = param_2;
  uVar7 = 0x96e91353;
  do {
    uVar4 = 1;
    bVar2 = (byte)uVar7;
    switch(iVar6) {
    case 0:
      abStack_a0[uVar7 + 0x3077cc06] = abStack_a0[uVar7 + 0x3077cc06] ^ bVar2 + 0x7b;
      uVar3 = uVar7 ^ 0xcf88342c;
      abStack_a0[uVar7 + 0x3077cc29] = bVar2 ^ abStack_a0[uVar7 + 0x3077cc29] ^ 0x70;
      uVar1 = uVar7 ^ 0xcf883411;
      uVar7 = uVar7 ^ 0xf231353c;
      abStack_a0[uVar3] = abStack_a0[uVar3] ^ bVar2 + 0x5c;
      abStack_a0[uVar1] = bVar2 ^ abStack_a0[uVar1] ^ 0x43;
      abStack_a0[uVar7 + 0xc246fec8] = abStack_a0[uVar7 + 0xc246fec8] ^ (char)uVar7 + 0x3aU;
      abStack_a0[uVar7 + 0xc246feda] = abStack_a0[uVar7 + 0xc246feda] ^ (char)uVar7 + 0x1eU;
      iVar6 = (0xc - uVar8) + (uVar8 / 0x13) * 0x13;
      break;
    case 1:
      uVar4 = 0;
switchD_00124ccc_caseD_3:
      if (___stack_chk_guard == lStack_68) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(uVar4,puVar5);
    case 2:
      iVar6 = uVar7 * uVar7;
      abStack_a0[uVar7 ^ 0xb349ec7c] = bVar2 ^ abStack_a0[uVar7 ^ 0xb349ec7c] ^ 0x33;
      abStack_a0[iVar6 + 0x17e217c8U] = abStack_a0[iVar6 + 0x17e217c8U] ^ bVar2 * bVar2 + 0x24;
      abStack_a0[iVar6 + 0x17e217beU] = abStack_a0[iVar6 + 0x17e217beU] ^ bVar2 * bVar2 + 3;
      uVar7 = uVar7 * uVar7;
      abStack_a0[iVar6 + 0x17e217c6U] = abStack_a0[iVar6 + 0x17e217c6U] ^ bVar2 * bVar2 - 0x36;
      abStack_a0[uVar7 ^ 0xe81de845] = abStack_a0[uVar7 ^ 0xe81de845] ^ bVar2 * bVar2 + 0x18;
      abStack_a0[iVar6 + 0x17e217b6U] = abStack_a0[iVar6 + 0x17e217b6U] ^ bVar2 * bVar2 + 1;
      iVar6 = 6;
      break;
    case 3:
    case 0x11:
      goto switchD_00124ccc_caseD_3;
    case 4:
      iVar6 = uVar7 * uVar7;
      uVar7 = iVar6 * 0x1b47d280 + 0xf1273e18;
      abStack_a0[uVar7 ^ 0xca038803] =
           abStack_a0[uVar7 ^ 0xca038803] ^ ((byte)(((uint)(iVar6 * -0x392e0b60) >> 5) << 7) | 0x7b)
      ;
      abStack_a0[uVar7 ^ 0xca03883a] = (byte)uVar7 ^ abStack_a0[uVar7 ^ 0xca03883a] ^ 0x6d;
      iVar6 = (0x14 - uVar8) + (uVar8 / 0x13) * 0x13;
      break;
    case 5:
      abStack_a0[uVar7 + 0xc246fedc] = abStack_a0[uVar7 + 0xc246fedc] ^ bVar2 - 0x25;
      abStack_a0[uVar7 + 0xc246fed8] = bVar2 ^ abStack_a0[uVar7 + 0xc246fed8] ^ 0x4c;
      abStack_a0[uVar7 ^ 0x3db9013f] = abStack_a0[uVar7 ^ 0x3db9013f] ^ bVar2 - 0x25;
      abStack_a0[uVar7 + 0xc246fed9] = bVar2 ^ abStack_a0[uVar7 + 0xc246fed9] ^ 0x76;
      uVar3 = uVar7 ^ 0x3db90132;
      abStack_a0[uVar7 ^ 0x3db90118] = abStack_a0[uVar7 ^ 0x3db90118] ^ bVar2 + 0x1e;
      uVar8 = 0x4e08;
      uVar7 = uVar7 + 0x35b80b46;
      abStack_a0[uVar3] = abStack_a0[uVar3] ^ bVar2 + 0x2a;
      iVar6 = 4;
      break;
    case 6:
      uVar3 = uVar7 + 0x17e217c7;
      uVar1 = uVar7 + 0x56b68ed3;
      uVar7 = uVar1 ^ 0xfe983e87;
      abStack_a0[uVar3] = abStack_a0[uVar3] ^ bVar2 - 0x32;
      abStack_a0[uVar1 ^ 0x3ed47704] = abStack_a0[uVar1 ^ 0x3ed47704] ^ (char)uVar7 + 0xa3U;
      abStack_a0[uVar7 + 0x3fb3b662] = abStack_a0[uVar7 + 0x3fb3b662] ^ (char)uVar7 - 0x36U;
      abStack_a0[uVar1 ^ 0x3ed4772c] = (byte)uVar1 ^ abStack_a0[uVar1 ^ 0x3ed4772c] ^ 0x66;
      iVar6 = 0xb;
      break;
    case 7:
      iVar6 = 0;
      abStack_a0[0x1d] = abStack_a0[0x1d] ^ 0x62;
      uVar8 = 0x76a1;
      uStack_80 = uStack_80 ^ 0x66000000;
      uVar7 = 0xcf883400;
      break;
    case 8:
      iVar6 = uVar7 * 2;
      abStack_a0[iVar6 + 0x622ba32aU] = abStack_a0[iVar6 + 0x622ba32aU] ^ (char)iVar6 + 0x43U;
      bVar2 = (byte)(iVar6 + -0x4c888cc8);
      abStack_a0[iVar6 + 0x622ba339U] = bVar2 ^ abStack_a0[iVar6 + 0x622ba339U] ^ 0x6e;
      abStack_a0[iVar6 + 0x622ba329U] = abStack_a0[iVar6 + 0x622ba329U] ^ (char)iVar6 + 0x61U;
      uVar7 = (iVar6 + -0x4c888cc8) * 2;
      abStack_a0[iVar6 + 0x622ba33eU] = bVar2 ^ abStack_a0[iVar6 + 0x622ba33eU] ^ 0x59;
      iVar6 = (0x15 - uVar8) + (uVar8 / 0x13) * 0x13;
      break;
    case 9:
      uVar4 = 0;
      *param_1 = 9;
      goto switchD_00124ccc_caseD_3;
    case 10:
      abStack_a0[uVar7 ^ 0x80989353] = bVar2 ^ abStack_a0[uVar7 ^ 0x80989353] ^ 0x69;
      abStack_a0[uVar7 + 0x7f676cbd] = abStack_a0[uVar7 + 0x7f676cbd] ^ bVar2 - 8;
      abStack_a0[uVar7 + 0x7f676cbc] = abStack_a0[uVar7 + 0x7f676cbc] ^ bVar2 + 0x12;
      uVar8 = 0x5d65;
      uVar3 = uVar7 ^ 0x8098937c;
      uVar7 = uVar7 * 2 * uVar7 * 2 ^ 0x6545ade0;
      abStack_a0[uVar3] = abStack_a0[uVar3] ^ bVar2 - 0xc;
      iVar6 = 8;
      break;
    case 0xb:
      uVar3 = uVar7 + 0x3fb3b661;
      uVar7 = uVar7 * 2;
      abStack_a0[uVar3] = bVar2 ^ abStack_a0[uVar3] ^ 0xd6;
      bVar2 = (byte)uVar7;
      abStack_a0[uVar7 + 0x7f676cb5] = bVar2 ^ abStack_a0[uVar7 + 0x7f676cb5] ^ 0x71;
      iVar6 = 10;
      abStack_a0[uVar7 + 0x7f676cac] = bVar2 ^ abStack_a0[uVar7 + 0x7f676cac] ^ 10;
      abStack_a0[uVar7 + 0x7f676cd5] = abStack_a0[uVar7 + 0x7f676cd5] ^ bVar2 + 4;
      abStack_a0[uVar7 + 0x7f676cc4] = abStack_a0[uVar7 + 0x7f676cc4] ^ bVar2 - 0x17;
      abStack_a0[uVar7 + 0x7f676cba] = abStack_a0[uVar7 + 0x7f676cba] ^ bVar2 + 0x10;
      break;
    case 0xc:
      auVar9 = (**(code **)(param_1 + 0x10))(param_1,param_4,*param_3);
      puVar5 = auVar9._8_8_;
      iVar6 = 0x10;
      if ((auVar9._0_8_ & 1) == 0) {
        iVar6 = 9;
      }
      break;
    case 0xd:
      abStack_a0[uVar7 + 0x35fc780e] = abStack_a0[uVar7 + 0x35fc780e] ^ bVar2 + 0x2b;
      uVar3 = uVar7 * 2 + 0x6bf8efd8;
      uVar1 = uVar7 * 4;
      abStack_a0[uVar3] = (byte)(uVar7 * 2) ^ abStack_a0[uVar3] ^ 0x52;
      abStack_a0[uVar1 + 0xd7f1dfc5] = abStack_a0[uVar1 + 0xd7f1dfc5] ^ (byte)uVar1 + 6;
      uVar7 = uVar1 + 0x8b3bcbfb;
      abStack_a0[uVar1 ^ 0x280e2067] = (byte)uVar1 ^ abStack_a0[uVar1 ^ 0x280e2067] ^ 0x11;
      iVar6 = 2;
      break;
    case 0xe:
      abStack_a0[uVar7 + 0x5d685fd1] = abStack_a0[uVar7 + 0x5d685fd1] ^ bVar2 + 0x2a;
      do {
        puVar5 = auStack_120;
        CallSupervisor(0);
      } while (&stack0x00000000 == (undefined1 *)0x9c);
      iVar6 = 9;
      uVar7 = uVar7 + 0xd9824f9a;
      break;
    case 0xf:
      uVar3 = j___ll_SI_IO_ll_5Ill0_0l_Sl_IS__O____I_IIIlII_IISI_S5_(param_1,param_2,param_3);
      if ((uVar3 & 1) == 0) {
        iVar6 = 3;
      }
      else {
        iVar6 = 0xe;
      }
      iVar6 = iVar6 - uVar8 % 0x35;
      puVar5 = extraout_x1;
      break;
    case 0x10:
      iVar6 = 3;
    }
  } while( true );
}


/* EXPORT index=183 ELF_VA=0x253a8 size=196 source_sha256=f9425ddd18d967cf381b72bb13e7adf1f1cce177c6671f75489ec5e0819e9cc0 */

undefined8
j___ll5ll__SI_I__l_IO_II05__I0SOI5l_I0_IlOl__S_5Il_S5_
          (undefined1 *param_1,undefined1 *param_2,undefined2 *param_3)

{
  ulong uVar1;
  undefined4 uVar2;
  char acStack_58 [20];
  undefined4 uStack_44;
  
  uStack_44 = 0;
  uVar2 = 2;
  do {
    switch(uVar2) {
    case 0:
      uVar2 = 1;
      if (acStack_58[0] != '\n') {
        *param_1 = 0xd;
switchD_00125418_caseD_3:
        return 0;
      }
      break;
    case 1:
      *param_2 = (char)acStack_58._8_8_;
      *param_3 = SUB82(acStack_58._8_8_,4);
      return 1;
    case 2:
      uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_58);
      uVar2 = 0;
      if ((uVar1 & 1) == 0) {
        uVar2 = 3;
      }
      break;
    case 3:
      goto switchD_00125418_caseD_3;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=184 ELF_VA=0x2547c size=324 source_sha256=5ad12fac6723033eb589fb7aa189d98d82ac896e91b302edc9e2bc60039271d2 */

/* WARNING: Exceeded maximum restarts with more pending */

void j___0OSO__lllII_05l55_000___00llSlllS5llI5I50O_ISl_S5_
               (undefined1 *param_1,undefined1 *param_2,undefined2 *param_3)

{
  ulong uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  char acStack_78 [20];
  undefined4 uStack_64;
  
  uVar3 = 5;
switchD_0012554c_caseD_3:
  switch(uVar3) {
  case 0x125510:
                    /* WARNING: This code block may not be properly labeled as switch case */
    uStack_64 = 0;
    uVar2 = 2;
    break;
  default:
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
LAB_00125534:
  uVar3 = 1;
  switch(uVar2) {
  case 0:
    goto switchD_0012554c_caseD_0;
  case 1:
    *param_2 = (char)acStack_78._8_8_;
    *param_3 = SUB82(acStack_78._8_8_,4);
    uVar3 = 4;
    goto switchD_0012554c_caseD_3;
  case 2:
    uVar1 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
    uVar2 = 0;
    if ((uVar1 & 1) == 0) {
      uVar2 = 3;
    }
    goto LAB_00125534;
  case 3:
    goto switchD_0012554c_caseD_3;
  default:
    break;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_0012554c_caseD_0:
  uVar2 = 1;
  if (acStack_78[0] != '\n') goto code_r0x00125560;
  goto LAB_00125534;
code_r0x00125560:
  *param_1 = 0xd;
  uVar3 = 1;
  goto switchD_0012554c_caseD_3;
}


/* EXPORT index=185 ELF_VA=0x255e8 size=208 source_sha256=636a7063bc39d5aaa6181bee341054e63e537005039ea8cbd0875efb8b13b979 */

undefined8
j___I_IIl__I0ll_l00OO_ISOO5_SIO5__lSIll0IIlIS55I55IS5_
          (undefined1 *param_1,undefined1 *param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  ulong uVar2;
  char acStack_68 [20];
  undefined4 uStack_54;
  
  uStack_54 = 0;
  uVar1 = 3;
  do {
    switch(uVar1) {
    case 0:
      *param_2 = (char)acStack_68._8_8_;
      *param_3 = SUB84(acStack_68._8_8_,4);
      return 1;
    case 1:
      *param_1 = 0xd;
      return 0;
    case 2:
      uVar1 = acStack_68[0] != '\v';
      break;
    case 3:
      uVar2 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_68);
      uVar1 = 2;
      if ((uVar2 & 1) == 0) {
        uVar1 = 4;
      }
      break;
    case 4:
      return 0;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=186 ELF_VA=0x256cc size=360 source_sha256=27ef9bed2a21dfe482443b99e783241edf9231b6c4984d77a3fe586d6b0e58c5 */

undefined8
j___5I0lI_I_IIl__IOII_SS_I5_IlSS5lSlOIl5SS_OIII05OlS5_
          (undefined1 *param_1,undefined1 *param_2,undefined4 *param_3,undefined8 param_4)

{
  undefined1 uVar1;
  ulong uVar2;
  int iVar3;
  char acStack_78 [20];
  undefined4 uStack_64;
  
  iVar3 = 4;
  do {
    while (iVar3 == 5) {
      uVar2 = (**(code **)(param_1 + 0x10))(param_1,param_4,*param_3);
      iVar3 = 3;
      if ((uVar2 & 1) == 0) {
        iVar3 = 1;
      }
    }
    if (iVar3 == 0) {
      return 0;
    }
    if (iVar3 == 1) {
      *param_1 = 9;
      return 0;
    }
    if (iVar3 != 4) {
      if (iVar3 == 2) {
        return 0;
      }
      if (iVar3 == 3) {
        return 1;
      }
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uStack_64 = 0;
    uVar1 = 3;
LAB_0012577c:
    iVar3 = 0;
    switch(uVar1) {
    case 0:
      *param_2 = (char)acStack_78._8_8_;
      *param_3 = SUB84(acStack_78._8_8_,4);
      iVar3 = 5;
      break;
    case 1:
      *param_1 = 0xd;
      iVar3 = 0;
      break;
    case 2:
      uVar1 = acStack_78[0] != '\v';
      goto LAB_0012577c;
    case 3:
      uVar2 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,acStack_78);
      uVar1 = 2;
      if ((uVar2 & 1) == 0) {
        uVar1 = 4;
      }
      goto LAB_0012577c;
    case 4:
      break;
    default:
      goto switchD_00125794_default;
    }
  } while( true );
switchD_00125794_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* EXPORT index=187 ELF_VA=0x25848 size=1872 source_sha256=08253c98b57abca4c1e42926d181beae631a195e0e180e6d7ef74c17bbf57e09 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___l5I_l_ll00__S_ll5_____I_Sl_lO5S5O__0_I__IIl_lIIS5_
               (undefined1 *param_1,undefined1 *param_2,undefined4 *param_3)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined1 auVar10 [16];
  byte abStack_b8 [20];
  uint uStack_a4;
  byte abStack_a0 [56];
  long lStack_68;
  
  lStack_68 = ___stack_chk_guard;
  uStack_a4 = 0;
  abStack_a0[0x21] = 0x61;
  abStack_a0[0x22] = 0x6e;
  abStack_a0[0x23] = 0x17;
  abStack_a0[0x24] = 0x3b;
  abStack_a0[0x25] = 5;
  abStack_a0[0x26] = 0x74;
  abStack_a0[0x27] = 0x1e;
  abStack_a0[0x28] = 0x1d;
  abStack_a0[0x20] = 0x60;
  abStack_a0[8] = 99;
  abStack_a0[9] = 0x7e;
  abStack_a0[10] = 0x27;
  abStack_a0[0xb] = 0x38;
  abStack_a0[0xc] = 0x1d;
  abStack_a0[0xd] = 0x75;
  abStack_a0[0xe] = 0xd;
  abStack_a0[0xf] = 0x44;
  abStack_a0[0] = 0x4a;
  abStack_a0[1] = 0x1f;
  abStack_a0[2] = 0x14;
  abStack_a0[3] = 0x3d;
  abStack_a0[4] = 0x52;
  abStack_a0[5] = 0x61;
  abStack_a0[6] = 0x66;
  abStack_a0[7] = 0x2e;
  abStack_a0[0x18] = 0x4b;
  abStack_a0[0x19] = 0x69;
  abStack_a0[0x1a] = 0x5b;
  abStack_a0[0x1b] = 0x75;
  abStack_a0[0x1c] = 0x51;
  abStack_a0[0x1d] = 0x77;
  abStack_a0[0x1e] = 0x11;
  abStack_a0[0x1f] = 0x32;
  abStack_a0[0x10] = 0x46;
  abStack_a0[0x11] = 0x16;
  abStack_a0[0x12] = 0x6b;
  abStack_a0[0x13] = 0x4f;
  abStack_a0[0x14] = 0x12;
  abStack_a0[0x15] = 0x2d;
  abStack_a0[0x16] = 0x59;
  abStack_a0[0x17] = 0x50;
  iVar8 = 0x75e9;
  uVar7 = 8;
  uVar9 = 0x188bffee;
  puVar6 = param_2;
switchD_00125910_default:
  uVar5 = 0;
  bVar3 = (byte)uVar9;
  switch(uVar7) {
  case 0:
    goto switchD_00125910_caseD_0;
  case 1:
  case 0x12:
    goto switchD_00125910_caseD_1;
  case 2:
    uVar7 = (((uint)(iVar8 * 0x8103) >> 0x16) * 0x7f + 0x2e) - iVar8;
    goto switchD_00125910_default;
  case 3:
    iVar1 = uVar9 * 4;
    bVar3 = (char)iVar1 + 0xd;
    abStack_a0[iVar1 + 0x8f6bbe0bU] = abStack_a0[iVar1 + 0x8f6bbe0bU] ^ bVar3;
    uVar7 = iVar1 + 0xf1c7579c;
    abStack_a0[uVar7 ^ 0x625b99b3] = abStack_a0[uVar7 ^ 0x625b99b3] ^ bVar3;
    iVar8 = 0x21e2;
    uVar9 = uVar7 * 2;
    abStack_a0[iVar1 + 0x8f6bbe04U] = (byte)uVar7 ^ abStack_a0[iVar1 + 0x8f6bbe04U] ^ 0xb1;
    uVar7 = 0x1a;
    goto switchD_00125910_default;
  case 4:
    bVar4 = bVar3 - 0x23;
    abStack_a0[uVar9 - 0x8b6033] = abStack_a0[uVar9 - 0x8b6033] ^ bVar3 ^ 5;
    abStack_a0[uVar9 ^ 0x8b6053] = abStack_a0[uVar9 ^ 0x8b6053] ^ bVar3 ^ 0x5d;
    abStack_a0[uVar9 ^ 0x8b6060] = abStack_a0[uVar9 ^ 0x8b6060] ^ bVar4;
    abStack_a0[uVar9 - 0x8b6035] = abStack_a0[uVar9 - 0x8b6035] ^ bVar4;
    abStack_a0[uVar9 ^ 0x8b6061] = abStack_a0[uVar9 ^ 0x8b6061] ^ bVar3 ^ 5;
    abStack_a0[uVar9 - 0x8b6038] = abStack_a0[uVar9 - 0x8b6038] ^ bVar3 ^ 0x5d;
    abStack_a0[uVar9 ^ 0x8b6063] = abStack_a0[uVar9 ^ 0x8b6063] ^ bVar4;
    uVar7 = 0xf;
    goto switchD_00125910_default;
  case 5:
    uVar7 = uVar9 ^ 0x4fae7fbd;
    abStack_a0[uVar9 + 0x270e3284] = bVar3 ^ abStack_a0[uVar9 + 0x270e3284] ^ 200;
    abStack_a0[uVar7 + 0x68a04ded] = abStack_a0[uVar7 + 0x68a04ded] ^ (char)uVar7 + 0x15U;
    abStack_a0[uVar7 + 0x68a04de2] = bVar3 ^ abStack_a0[uVar7 + 0x68a04de2] ^ 0xe7;
    uVar7 = uVar7 * 2;
    uVar9 = uVar7 & 0xd08b684e;
    abStack_a0[uVar7 + 0xd1409bb5] = abStack_a0[uVar7 + 0xd1409bb5] ^ (char)uVar7 - 0x1bU;
    uVar7 = (0x27 - iVar8) + ((uint)(iVar8 * 0xc908) >> 0x17) * 0xa3;
    goto switchD_00125910_default;
  case 6:
switchD_00125910_caseD_6:
    uVar7 = 0xa2eb02a7;
    uStack_a4 = 0xa2eb02aa;
    break;
  case 7:
    abStack_a0[uVar9 + 0xd467b3b6] = abStack_a0[uVar9 + 0xd467b3b6] ^ bVar3 + 6;
    uVar7 = uVar9 + 0xa9f6cf88;
    uVar9 = uVar7 ^ 0x68919d6a;
    bVar3 = (char)uVar9 - 0x1c;
    abStack_a0[uVar9 + 0x42e1797e] = (byte)uVar7 ^ abStack_a0[uVar9 + 0x42e1797e] ^ 0xf1;
    abStack_a0[uVar9 + 0x42e179a0] = abStack_a0[uVar9 + 0x42e179a0] ^ bVar3;
    abStack_a0[uVar7 ^ 0xd58f1bce] = abStack_a0[uVar7 ^ 0xd58f1bce] ^ bVar3;
    do {
      puVar6 = (undefined1 *)0x37;
      CallSupervisor(0);
    } while (&stack0x00000000 == (undefined1 *)0x9c);
    uVar7 = 0xe;
    goto switchD_00125910_default;
  case 8:
    auVar10 = j___IOI5I__I0ll__lS5l_5lI0I__OI_O5_IS_Sl___SlISI_0IS5_(param_1,abStack_b8);
    puVar6 = auVar10._8_8_;
    uVar7 = 0xb;
    if ((auVar10._0_8_ & 1) == 0) {
      uVar7 = 2;
    }
    iVar8 = 0x318;
    goto switchD_00125910_default;
  case 9:
    iVar1 = (uVar9 & 0x7619c219) * 2;
    abStack_a0[uVar9 ^ 0xbe2c7120] = abStack_a0[uVar9 ^ 0xbe2c7120] ^ bVar3 - 10;
    cVar2 = (char)iVar1;
    abStack_a0[iVar1 + 0x93ef8022U] = abStack_a0[iVar1 + 0x93ef8022U] ^ cVar2 + 0x1bU;
    abStack_a0[iVar1 + 0x93ef801cU] = abStack_a0[iVar1 + 0x93ef801cU] ^ cVar2 + 0x68U;
    uVar9 = iVar1 + 0xbf87cc62;
    abStack_a0[iVar1 + 0x93ef7fffU] = abStack_a0[iVar1 + 0x93ef7fffU] ^ cVar2 + 0x43U;
    uVar7 = 7;
    goto switchD_00125910_default;
  case 10:
switchD_00125910_caseD_a:
    uVar7 = 6;
    goto switchD_00125910_default;
  case 0xb:
    uVar7 = 0x15;
    goto switchD_00125910_default;
  case 0xc:
    uVar7 = uVar9 * 2;
    bVar3 = (char)uVar7 + 0x1d;
    abStack_a0[uVar7 ^ 0x45b020f] = abStack_a0[uVar7 ^ 0x45b020f] ^ bVar3;
    abStack_a0[uVar7 + 0xfba4fe18] = abStack_a0[uVar7 + 0xfba4fe18] ^ bVar3;
    uVar9 = uVar7 + 0xb9d16f27;
    abStack_a0[uVar9 ^ 0xbe2c7129] = abStack_a0[uVar9 ^ 0xbe2c7129] ^ (char)uVar7 + 0x6aU;
    abStack_a0[uVar9 ^ 0xbe2c7137] = abStack_a0[uVar9 ^ 0xbe2c7137] ^ bVar3;
    uVar7 = 9;
    goto switchD_00125910_default;
  case 0xd:
switchD_00125910_caseD_d:
    uVar7 = 0x11;
    goto switchD_00125910_default;
  case 0xe:
switchD_00125910_caseD_e:
    uVar7 = 0x1fbb6489;
    uStack_a4 = 0x1fbb649a;
    break;
  case 0xf:
    abStack_a0[uVar9 - 0x8b603d] = abStack_a0[uVar9 - 0x8b603d] ^ bVar3 - 0x23;
    abStack_a0[uVar9 - 0x8b6034] = abStack_a0[uVar9 - 0x8b6034] ^ bVar3 - 0x23;
    uVar7 = uVar9 ^ 0x8b6056;
    uVar9 = uVar9 * 2;
    abStack_a0[uVar7] = bVar3 ^ abStack_a0[uVar7] ^ 0x2a;
    bVar3 = (byte)uVar9;
    abStack_a0[uVar9 + 0xfee93f86] = abStack_a0[uVar9 + 0xfee93f86] ^ bVar3 - 0x16;
    abStack_a0[uVar9 ^ 0x116c0a5] = bVar3 ^ abStack_a0[uVar9 ^ 0x116c0a5] ^ 0xc5;
    abStack_a0[uVar9 ^ 0x116c0a7] = abStack_a0[uVar9 ^ 0x116c0a7] ^ bVar3 + 0x9d;
    uVar7 = 0x14;
    goto switchD_00125910_default;
  case 0x10:
  case 0x1b:
    goto switchD_00125910_caseD_10;
  case 0x11:
switchD_00125910_caseD_11:
    uVar7 = 0xe;
    goto switchD_00125910_default;
  case 0x13:
switchD_00125910_caseD_13:
    uStack_a4 = 0xda4320a1;
    uVar7 = 0x12;
    goto switchD_00125910_default;
  case 0x14:
    abStack_a0[uVar9 ^ 0x116c089] = bVar3 ^ abStack_a0[uVar9 ^ 0x116c089] ^ 0xc5;
    bVar4 = bVar3 + 0x9d;
    abStack_a0[uVar9 + 0xfee93f97] = abStack_a0[uVar9 + 0xfee93f97] ^ bVar4;
    abStack_a0[uVar9 + 0xfee93f80] = abStack_a0[uVar9 + 0xfee93f80] ^ bVar4;
    abStack_a0[uVar9 + 0xfee93fa8] = abStack_a0[uVar9 + 0xfee93fa8] ^ bVar4;
    uVar7 = uVar9 ^ 0x116c085;
    abStack_a0[uVar9 + 0xfee93f9c] = bVar3 ^ abStack_a0[uVar9 + 0xfee93f9c] ^ 0x9d;
    uVar9 = uVar9 << 1;
    abStack_a0[uVar7] = abStack_a0[uVar7] ^ bVar3 - 0x3b;
    uVar7 = 0xc;
    goto switchD_00125910_default;
  case 0x15:
    switch(abStack_b8[0]) {
    case 9:
      goto switchD_00125910_caseD_11;
    case 10:
      goto switchD_00125910_caseD_e;
    case 0xb:
      goto switchD_00125910_caseD_13;
    case 0x16:
      goto switchD_00125910_caseD_19;
    case 0x17:
      goto switchD_00125910_caseD_17;
    case 0x18:
      goto switchD_00125910_caseD_a;
    case 0x19:
      goto switchD_00125910_caseD_6;
    case 0x1a:
      goto switchD_00125910_caseD_d;
    }
switchD_00125910_caseD_0:
    uVar7 = 0x16;
    goto switchD_00125910_default;
  case 0x16:
    uVar5 = 0;
    *param_1 = 0xd;
    goto switchD_00125910_caseD_10;
  case 0x17:
switchD_00125910_caseD_17:
    uVar7 = 0x5e6c6531;
    uStack_a4 = 0x5e6c653b;
    break;
  case 0x18:
    uVar7 = 3;
    uVar9 = 0x9c251084;
    goto switchD_00125910_default;
  case 0x19:
switchD_00125910_caseD_19:
    uVar7 = 0x17;
    goto switchD_00125910_default;
  case 0x1a:
    goto switchD_00125910_caseD_1a;
  default:
    goto switchD_00125910_default;
  }
  uVar7 = uStack_a4 ^ uVar7;
  goto switchD_00125910_default;
switchD_00125910_caseD_1a:
  uVar7 = uVar9 + 0x3b48ccb2;
  iVar1 = (uVar9 + 0x62fe0e91) * (uVar9 + 0x62fe0e91);
  uVar9 = iVar1 * iVar1 ^ 0x683cc0ac;
  abStack_a0[uVar7] = bVar3 ^ abStack_a0[uVar7] ^ 0x32;
  abStack_a0[uVar9 + 0x270e3275] = abStack_a0[uVar9 + 0x270e3275] ^ (char)uVar9 - 0x23U;
  abStack_a0[uVar9 + 0x270e328c] = abStack_a0[uVar9 + 0x270e328c] ^ (char)uVar9 + 0xb8U;
  iVar8 = iVar8 + ((uint)(iVar8 * 0xc908) >> 0x17) * -0xa3;
  uVar7 = 0x28 - iVar8;
  iVar8 = 0x5ddf - iVar8;
  goto switchD_00125910_default;
switchD_00125910_caseD_1:
  *param_2 = (char)abStack_b8._8_8_;
  *param_3 = SUB84(abStack_b8._8_8_,4);
  uVar5 = 1;
switchD_00125910_caseD_10:
  if (___stack_chk_guard == lStack_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar5,puVar6);
}


/* EXPORT index=188 ELF_VA=0x26050 size=280 source_sha256=af4b4a2d294e5d4624d3e86b95b0c559e77991edf45be57b5c1002c4cf17a2c6 */

undefined8
j___ll0ll_lIlI__O0llI__I__l_lS0lllI_IIISI0OSl__IlOSS5_
          (undefined1 *param_1,undefined8 param_2,undefined4 *param_3,undefined8 param_4)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = 0x541f;
  uVar4 = 3;
  while( true ) {
    while( true ) {
      if (uVar4 == 0) {
        *param_1 = 9;
        return 0;
      }
      if (uVar4 == 4) {
        return 0;
      }
      if (uVar4 != 2) break;
      uVar1 = (**(code **)(param_1 + 0x10))(param_1,param_4,*param_3);
      iVar3 = 0x11;
      if ((uVar1 & 1) != 0) {
        iVar3 = 0x12;
      }
      uVar4 = iVar3 - uVar2 % 0xb3;
      if (uVar4 == 5) {
        return 0;
      }
    }
    if (uVar4 == 1) {
      return 1;
    }
    if (uVar4 != 3) break;
    uVar1 = j___l5I_l_ll00__S_ll5_____I_Sl_lO5S5O__0_I__IIl_lIIS5_(param_1,param_2,param_3);
    uVar4 = 2;
    if ((uVar1 & 1) == 0) {
      uVar4 = 4;
    }
    uVar2 = 0x72bd;
  }
  do {
  } while ((uVar4 & 0xfffffffe) != 4);
  return 0;
}


/* EXPORT index=189 ELF_VA=0x26168 size=216 source_sha256=8381b9f38c47fd3f48e1e0f5886c2aac61bc5beb95c660fc3d8590e19be923f3 */

undefined4 j___0_I_l_IlI_0__ISII_l_IO__I5ISO555I5lIIl5_lO005SIS5_(char *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 0xcb7;
  uVar1 = 1;
switchD_001261bc_caseD_2:
  do {
    uVar4 = uVar1;
    uVar2 = 1;
    uVar1 = 4;
    switch(uVar4) {
    case 1:
      iVar3 = iVar3 + ((uint)(iVar3 * 0xe6c3) >> 0x16) * -0x47;
      uVar1 = 0x3c - iVar3;
      iVar3 = 0x1fd - iVar3;
      if (uVar1 == 7) {
        return 1;
      }
      break;
    case 2:
      break;
    case 3:
      goto switchD_001261bc_caseD_3;
    default:
      if (uVar4 == 0) goto LAB_001261d0;
      if (uVar4 == 4) goto LAB_00126198;
      if (uVar4 == 5) {
        uVar2 = 0;
      }
      else {
        do {
        } while ((uVar4 & 0xfffffffe) != 6);
        uVar2 = 1;
      }
    case 6:
      return uVar2;
    }
  } while( true );
LAB_001261d0:
  uVar1 = 4;
  if (*param_1 != '\"') {
    if (*param_1 == '\x12') {
LAB_00126198:
      uVar1 = 6;
    }
    else {
switchD_001261bc_caseD_3:
      uVar1 = 5;
    }
  }
  goto switchD_001261bc_caseD_2;
}


/* EXPORT index=190 ELF_VA=0x26258 size=124 source_sha256=5c38c81b16b4a8ee2601a76edb11d83319408edc91e07ac4bf1f444b0e910ffa */

undefined4 j___SIIII_IllII_Oll0__0_lIO_0lS_I5l05I0III_0IIO5IISS5_(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = 7;
switchD_00126294_caseD_7:
  uVar4 = uVar2;
  uVar3 = 0;
  uVar2 = 6;
  switch(uVar4) {
  case 2:
switchD_00126294_caseD_2:
    uVar3 = 1;
switchD_00126294_caseD_5:
    return uVar3;
  case 3:
    goto switchD_00126294_caseD_3;
  default:
    goto switchD_00126294_caseD_4;
  case 5:
    goto switchD_00126294_caseD_5;
  case 6:
    break;
  case 7:
    goto switchD_00126294_caseD_7;
  }
  cVar1 = *param_1;
  uVar2 = 3;
  if (cVar1 != '\"') {
    if (cVar1 == '\x12') {
switchD_00126294_caseD_3:
      uVar2 = 2;
    }
    else {
      if (cVar1 == '\x13') goto switchD_00126294_caseD_2;
      uVar2 = 5;
    }
  }
  goto switchD_00126294_caseD_7;
switchD_00126294_caseD_4:
  do {
  } while( true );
}


/* EXPORT index=191 ELF_VA=0x262ec size=272 source_sha256=11584e0da6f422119b4a5184ed601619742c17210fe7124b2f0f7db19cba4445 */

undefined4 j___5ISI5_IS_0I__I5II_S5OlO__IISIOO5Il5_l0_Ol_0_l_IS5_(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  iVar3 = 4;
LAB_00126338:
  iVar2 = iVar3;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(iVar2) {
  case 0:
switchD_00126358_caseD_0:
    iVar3 = 1;
    break;
  case 2:
    bVar1 = *param_1;
    if (0x21 < bVar1) {
      if (bVar1 == 0x22) goto switchD_00126358_caseD_6;
      goto switchD_00126358_caseD_0;
    }
    iVar3 = 8;
    if (bVar1 == 0x12) goto LAB_00126338;
    if (bVar1 == 0x13) {
      iVar3 = 7;
      goto LAB_00126338;
    }
    if (bVar1 != 0x14) goto switchD_00126358_caseD_0;
    iVar3 = 3;
    break;
  default:
    goto switchD_00126358_caseD_4;
  case 6:
switchD_00126358_caseD_6:
    iVar3 = 5;
  }
  if (iVar3 == 9) {
    return 1;
  }
  goto LAB_00126338;
switchD_00126358_caseD_4:
  iVar3 = 2;
  if (iVar2 != 4) {
    if (iVar2 == 1) {
      uVar4 = 0;
    }
    else if (iVar2 != 9) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    return uVar4;
  }
  goto LAB_00126338;
}


/* EXPORT index=192 ELF_VA=0x26420 size=220 source_sha256=f50c8ee840e0042cf2083b67427c1d792a863cccd40508f581fd3f3567eb1c47 */

undefined4 j___llll5_55lll_ISI_I_lI__I_I_OlSlI0lSO_ISIIS_lIS0IS5_(byte *param_1)

{
  byte bVar1;
  undefined8 uVar2;
  
  uVar2 = 4;
  do {
    switch(uVar2) {
    case 0:
    case 9:
      return 0;
    case 1:
switchD_00126468_caseD_1:
      uVar2 = 3;
      break;
    case 2:
switchD_00126468_caseD_2:
      uVar2 = 10;
      break;
    case 3:
      return 1;
    case 4:
      uVar2 = 0xb;
      break;
    case 6:
switchD_00126468_caseD_6:
      uVar2 = 1;
      break;
    case 7:
switchD_00126468_caseD_7:
      uVar2 = 0;
      break;
    case 8:
      bVar1 = *param_1;
      if (bVar1 < 0x22) {
        switch(bVar1) {
        case 0x12:
          goto switchD_00126468_caseD_2;
        case 0x13:
          goto switchD_00126468_caseD_a;
        case 0x14:
          goto switchD_00126468_caseD_6;
        case 0x15:
          goto switchD_00126468_caseD_1;
        default:
          goto switchD_00126468_caseD_7;
        }
      }
LAB_001264dc:
      if (bVar1 != 0x22) goto switchD_00126468_caseD_7;
    case 5:
      uVar2 = 2;
      break;
    case 10:
switchD_00126468_caseD_a:
      uVar2 = 6;
      break;
    case 0xb:
      bVar1 = *param_1;
      if (bVar1 < 0x22) {
        switch(bVar1) {
        case 0x12:
          goto switchD_00126468_caseD_2;
        case 0x13:
          goto switchD_00126468_caseD_a;
        case 0x14:
          goto switchD_00126468_caseD_6;
        case 0x15:
          goto switchD_00126468_caseD_1;
        default:
          goto switchD_00126468_caseD_7;
        }
      }
      goto LAB_001264dc;
    }
  } while( true );
}


/* EXPORT index=193 ELF_VA=0x2654c size=220 source_sha256=79fcae0c8f72e536760048f33b37b892ea1942fe407b8ffc150d305d1122c4ed */

undefined4 j_____S0__5II05__IIII_I_IIS_5l5lS5I5IlO_0__O_SI_llIS5_(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = 4;
switchD_00126594_default:
  do {
    uVar2 = 1;
    switch(uVar3) {
    case 0:
    case 9:
      uVar2 = 0;
switchD_00126594_caseD_3:
      return uVar2;
    case 1:
switchD_00126594_caseD_1:
      uVar3 = 3;
      break;
    case 2:
switchD_00126594_caseD_2:
      uVar3 = 10;
      break;
    case 3:
      goto switchD_00126594_caseD_3;
    case 4:
      uVar3 = 0xb;
      break;
    case 6:
switchD_00126594_caseD_6:
      uVar3 = 1;
      break;
    case 7:
switchD_00126594_caseD_7:
      uVar3 = 0;
      break;
    case 8:
      bVar1 = *param_1;
      if (bVar1 < 0x22) {
        switch(bVar1) {
        case 0x12:
          goto switchD_00126594_caseD_2;
        case 0x13:
          goto switchD_00126594_caseD_a;
        case 0x14:
          goto switchD_00126594_caseD_6;
        case 0x15:
          goto switchD_00126594_caseD_1;
        default:
          goto switchD_00126594_caseD_7;
        }
      }
LAB_00126608:
      if (bVar1 != 0x22) goto switchD_00126594_caseD_7;
    case 5:
      uVar3 = 2;
      break;
    case 10:
      goto switchD_00126594_caseD_a;
    case 0xb:
      bVar1 = *param_1;
      if (bVar1 < 0x22) {
        switch(bVar1) {
        case 0x12:
          goto switchD_00126594_caseD_2;
        case 0x13:
          goto switchD_00126594_caseD_a;
        case 0x14:
          goto switchD_00126594_caseD_6;
        case 0x15:
          goto switchD_00126594_caseD_1;
        default:
          goto switchD_00126594_caseD_7;
        }
      }
      goto LAB_00126608;
    }
  } while( true );
switchD_00126594_caseD_a:
  uVar3 = 6;
  goto switchD_00126594_default;
}


/* EXPORT index=194 ELF_VA=0x26678 size=192 source_sha256=aa4ac60838de363433da5e83516898b6f4feb645aa633ceee9cce74806e763c5 */

/* WARNING: Removing unreachable block (ram,0x00126720) */

undefined4 j____0_II_S__O0__50I__5l_ll_0II___I5_III_IIIlOI___lS5_(char *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = 3;
switchD_001266d4_caseD_5:
  do {
    uVar2 = uVar1;
    uVar3 = 0;
    uVar1 = 2;
    switch(uVar2);
  } while( true );
  uVar3 = 1;
  uVar1 = 4;
  switch(uVar2) {
  case 2:
    return uVar3;
  case 3:
    break;
  case 4:
    uVar1 = 2;
    if (*param_1 != '\x0e') {
      if (*param_1 == '\0') {
        uVar1 = 5;
      }
      else {
        uVar1 = 1;
      }
    }
    break;
  default:
    goto switchD_001266f4_caseD_5;
  case 7:
    return 0;
  }
  goto switchD_001266d4_caseD_5;
switchD_001266f4_caseD_5:
  do {
  } while( true );
}


/* EXPORT index=195 ELF_VA=0x2676c size=244 source_sha256=642e6caf0f2b373d69abae7983b4c1d13b1596b4262d7b071c57e7e7b5852589 */

undefined4 j___05l5I_ISSIl__II___II_II_l0l_0O_I0I5___OIlOIl_OIS5_(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = 3;
switchD_001267d0_caseD_3:
  iVar3 = iVar4;
  uVar5 = 0;
  iVar4 = 4;
  switch(iVar3) {
  case 1:
switchD_001267d0_caseD_1:
    iVar4 = 5;
    break;
  case 2:
switchD_001267d0_caseD_2:
    iVar4 = 6;
    break;
  case 3:
    goto switchD_001267d0_caseD_3;
  case 4:
    cVar1 = *param_1;
    iVar4 = 8;
    if (cVar1 != '\x0f') {
      if (cVar1 == '\0') goto switchD_001267d0_caseD_1;
      if (cVar1 != '\x0e') goto switchD_001267d0_caseD_2;
      goto switchD_00126818_caseD_5;
    }
    goto switchD_001267d0_caseD_3;
  default:
    goto code_r0x00126800;
  case 6:
    goto switchD_001267d0_caseD_6;
  }
LAB_00126840:
  if (iVar4 == 9) {
    uVar5 = 0;
    goto switchD_001267d0_caseD_6;
  }
  goto switchD_001267d0_caseD_3;
code_r0x00126800:
  uVar5 = 1;
  iVar4 = 8;
  uVar2 = 0;
  switch(iVar3) {
  case 0:
    goto switchD_001267d0_caseD_3;
  default:
    goto switchD_00126818_caseD_1;
  case 5:
switchD_00126818_caseD_5:
    iVar4 = 7;
    break;
  case 7:
  case 8:
switchD_001267d0_caseD_6:
    uVar2 = uVar5;
switchD_00126818_caseD_9:
    return uVar2;
  case 9:
    goto switchD_00126818_caseD_9;
  }
  goto LAB_00126840;
switchD_00126818_caseD_1:
  do {
  } while( true );
}


/* EXPORT index=196 ELF_VA=0x268a0 size=368 source_sha256=af10f8ae2dc7bbc2a56c4dc188fd609935bd68d2f4e4fd2abef0131d15a2d118 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 j___O_Il__II0SI_lOI_S_l_lI__0IOIIlSOOlIIIOIIO5__Il_S5_(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iStack_8;
  
  uVar3 = 0x5b64;
  iStack_8 = 5;
  iVar4 = 5;
switchD_00126908_default:
  uVar2 = 0;
  switch(iVar4) {
  case 0:
    iStack_8 = 1 - uVar3;
    break;
  case 1:
    bVar1 = *param_1;
    if (bVar1 < 0xe) {
      if (bVar1 == 0) goto switchD_00126908_caseD_8;
    }
    else {
      if (bVar1 == 0xe) goto switchD_00126908_caseD_2;
      if (bVar1 == 0xf) goto switchD_00126908_caseD_9;
      if (bVar1 == 0x10) goto switchD_00126908_caseD_7;
    }
  case 0xb:
    iStack_8 = 4;
    iVar4 = 4;
    goto switchD_00126908_default;
  case 2:
switchD_00126908_caseD_2:
    iStack_8 = 9;
    iVar4 = 9;
    goto switchD_00126908_default;
  case 3:
    goto switchD_00126908_caseD_3;
  case 4:
  case 0xc:
    goto switchD_00126908_caseD_4;
  case 5:
    if (iStack_8 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    iStack_8 = 0;
    uVar3 = 0x2aba;
    iVar4 = 0;
    goto switchD_00126908_default;
  case 6:
    goto switchD_00126908_caseD_6;
  case 7:
switchD_00126908_caseD_7:
    iVar4 = 3;
    iStack_8 = 3;
    goto switchD_00126908_default;
  case 8:
switchD_00126908_caseD_8:
    iVar4 = 2;
    iStack_8 = 2;
    goto switchD_00126908_default;
  case 9:
switchD_00126908_caseD_9:
    iVar4 = 7;
    iStack_8 = 7;
    goto switchD_00126908_default;
  case 10:
    iStack_8 = 6 - uVar3;
    break;
  default:
    goto switchD_00126908_default;
  }
  iStack_8 = iStack_8 + (uVar3 / 3) * 3;
  iVar4 = iStack_8;
  goto switchD_00126908_default;
switchD_00126908_caseD_6:
  iVar4 = 8;
  iStack_8 = 8;
  goto switchD_00126908_default;
switchD_00126908_caseD_3:
  uVar2 = 1;
switchD_00126908_caseD_4:
  return uVar2;
}


/* EXPORT index=197 ELF_VA=0x26a44 size=188 source_sha256=1a0e4f745467d511a2c3d1178d1493f04a7685b8a1be49d20913a7fb1b063f33 */

undefined8 j___5_III_l0I_l__lIOI_IIISl_I_0S0l0lSO00l_Ol0S5llIIS5_(byte *param_1)

{
  byte bVar1;
  undefined8 uVar2;
  
  uVar2 = 2;
switchD_00126a8c_default:
  do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch(uVar2) {
    case 0:
switchD_00126a8c_caseD_0:
      uVar2 = 5;
      break;
    case 2:
      uVar2 = 4;
      break;
    case 4:
      bVar1 = *param_1;
      if (bVar1 < 0xe) {
        if (bVar1 == 0) {
          uVar2 = 3;
          break;
        }
      }
      else {
        switch(bVar1) {
        case 0xe:
          uVar2 = 8;
          goto switchD_00126a8c_default;
        case 0xf:
          goto switchD_00126a8c_caseD_8;
        case 0x10:
          goto switchD_00126a8c_caseD_6;
        case 0x11:
          goto switchD_00126a8c_caseD_0;
        }
      }
      uVar2 = 9;
      break;
    case 6:
switchD_00126a8c_caseD_6:
      uVar2 = 0;
      break;
    case 8:
switchD_00126a8c_caseD_8:
      uVar2 = 6;
      break;
    case 10:
      return 0;
    }
  } while( true );
}


/* EXPORT index=198 ELF_VA=0x26b3c size=188 source_sha256=75331b3ddde32bed41a30a1cd62a6fa96d31037b1257258f5810718d8e4da7ad */

undefined8 j___l0lI5_OIlS0_S5_0I_5_O___OlS0_lI50_O05Il5I_I0IS_S5_(byte *param_1)

{
  byte bVar1;
  undefined8 uVar2;
  
  uVar2 = 2;
switchD_00126b84_default:
  do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch(uVar2) {
    case 0:
switchD_00126b84_caseD_0:
      uVar2 = 5;
      break;
    case 2:
      uVar2 = 4;
      break;
    case 4:
      bVar1 = *param_1;
      if (bVar1 < 0xe) {
        if (bVar1 == 0) {
          uVar2 = 3;
          break;
        }
      }
      else {
        switch(bVar1) {
        case 0xe:
          uVar2 = 8;
          goto switchD_00126b84_default;
        case 0xf:
          goto switchD_00126b84_caseD_8;
        case 0x10:
          goto switchD_00126b84_caseD_6;
        case 0x11:
          goto switchD_00126b84_caseD_0;
        }
      }
      uVar2 = 9;
      break;
    case 6:
switchD_00126b84_caseD_6:
      uVar2 = 0;
      break;
    case 8:
switchD_00126b84_caseD_8:
      uVar2 = 6;
      break;
    case 10:
      return 0;
    }
  } while( true );
}


/* EXPORT index=199 ELF_VA=0x26c34 size=16 source_sha256=640b6c66206c2a4795cdb5bf1b629b9f8c3feb1c7edca57c39661a675a55ae07 */

bool j___I0_l__5_IIl_O_lII__lII5_IIIISl0_lIIl5_III_I5I0SS5_(char *param_1)

{
  return *param_1 == '\f';
}


/* EXPORT index=200 ELF_VA=0x26c44 size=16 source_sha256=86daf8e5229e3edc55db228725271c181de4671608b92493fe1b7974d805a6ac */

bool j___O_IIS_IIIlI_I_I_____S_I_IS_OllSl0___55lIl0_5S_IS5_(char *param_1)

{
  return *param_1 == '\r';
}


/* EXPORT index=201 ELF_VA=0x26c54 size=16 source_sha256=f1f95a09bdc2d1afe9b367a2c4d05f1e5105288b9f542b6ab20bbea25e489fa2 */

bool j______II_OI_lI_lI50I_Ol5Il_lOOl_lI0SlISIlI_I0OlIl5S5_(char *param_1)

{
  return *param_1 == '\x04';
}


/* EXPORT index=202 ELF_VA=0x26c64 size=16 source_sha256=bebd730ba333e9d05089b0b28cead359600a391920c49d3d1188d87052c523f9 */

bool j___lSIl0_l_l_I_0_S_O_IlSII_____I_l5_l5IIlS0OOl5IIlS5_(char *param_1)

{
  return *param_1 == '\x05';
}


/* EXPORT index=203 ELF_VA=0x26c74 size=316 source_sha256=bb9e167b27fd6a312098acf0630acddb95eed7b86ec83856dd9230aa7adb88f3 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00126d18) */

undefined4 j___Il5O__I0I5l__IIll__Il0I_5IlSlllll_IlS_0lOI055_5S5_(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = 8;
switchD_00126cd4_default:
  uVar2 = 1;
  switch(uVar3) {
  case 0:
switchD_00126cd4_caseD_0:
    uVar3 = 10;
    goto switchD_00126cd4_default;
  case 2:
    goto switchD_00126cd4_caseD_2;
  case 3:
switchD_00126cd4_caseD_3:
    uVar3 = 5;
    goto switchD_00126cd4_default;
  case 4:
    bVar1 = *param_1;
    if (bVar1 < 0x1b) {
      if (bVar1 == 3) goto switchD_00126cd4_caseD_6;
    }
    else {
      if (bVar1 == 0x1b) goto switchD_00126cd4_caseD_0;
      if (bVar1 == 0x1c) goto switchD_00126cd4_caseD_a;
      if (bVar1 == 0x1d) goto switchD_00126cd4_caseD_3;
    }
    break;
  case 5:
  case 9:
  case 0xb:
    goto switchD_00126cd4_caseD_5;
  case 6:
switchD_00126cd4_caseD_6:
    uVar3 = 0;
    goto switchD_00126cd4_default;
  case 7:
    uVar3 = 4;
    goto switchD_00126cd4_default;
  case 8:
    goto LAB_00126d50;
  case 10:
switchD_00126cd4_caseD_a:
    uVar3 = 3;
  default:
    goto switchD_00126cd4_default;
  }
  uVar3 = 2;
  goto switchD_00126cd4_default;
LAB_00126d50:
  uVar3 = 7;
  goto switchD_00126cd4_default;
switchD_00126cd4_caseD_2:
  uVar2 = 0;
switchD_00126cd4_caseD_5:
  return uVar2;
}


/* EXPORT index=204 ELF_VA=0x26de0 size=296 source_sha256=79440c56dca15a07707466d8b1ce8182a7b8664228c2fc9d02c43b85ba80beb1 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00126ecc) */
/* WARNING: Removing unreachable block (ram,0x00126e50) */

undefined4 j____IOIS___llI_I_0I0_SlI5I_O0O_SlSIlll_II5III0SlSIS5_(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = 1;
  do {
    uVar3 = 6;
    switch(uVar2) {
    case 1:
      uVar2 = 8;
      break;
    case 2:
switchD_00126e40_caseD_2:
      uVar2 = 0;
      break;
    case 3:
      return 1;
    case 4:
switchD_00126e40_caseD_4:
      uVar2 = 2;
      break;
    case 5:
switchD_00126e40_caseD_5:
      uVar3 = 7;
    case 8:
      uVar2 = uVar3;
      break;
    case 6:
      cVar1 = *param_1;
      if (cVar1 == '\x06') goto switchD_00126e40_caseD_4;
      if (cVar1 != '\b') {
        if (cVar1 != '\a') goto switchD_00126e40_caseD_5;
        goto switchD_00126e40_caseD_2;
      }
    case 0:
      uVar2 = 3;
      break;
    case 7:
    case 9:
      return 0;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=205 ELF_VA=0x26f30 size=256 source_sha256=6b70de0eb6fdd4bb84e4a29074fe432082508290bc33bf0a7abb270da2ec2aa6 */

undefined4 j___IOIl__I_S_l_II_l0__lllI_SOlI05IllSII0I_S_lI__5lS5_(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = 6;
  iVar2 = 0x45e6;
switchD_00126fc8_caseD_5:
  iVar4 = iVar2;
  iVar2 = iVar3;
LAB_00126f78:
  do {
    iVar6 = iVar2;
    iVar3 = 3;
    uVar5 = 1;
    iVar2 = 0;
  } while (iVar6 == 4);
  iVar2 = 0x2458;
  if (iVar6 == 1) goto switchD_00126fc8_caseD_5;
  if (iVar6 == 7) {
switchD_00126fc8_caseD_0:
    return uVar5;
  }
  uVar5 = 0;
  iVar3 = 7;
  iVar2 = 0xcd6;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(iVar6) {
  case 0:
    goto switchD_00126fc8_caseD_0;
  default:
    goto switchD_00126fc8_caseD_1;
  case 2:
switchD_00126fc8_caseD_2:
    iVar2 = 8;
    goto LAB_00126f78;
  case 3:
    break;
  case 5:
    goto switchD_00126fc8_caseD_5;
  case 6:
    iVar4 = iVar4 + ((uint)(iVar4 * 0xa238) >> 0x16) * -0x65;
    iVar3 = 0x14 - iVar4;
    iVar2 = 0x59e7 - iVar4;
    if (iVar3 == 9) {
      return 1;
    }
    goto switchD_00126fc8_caseD_5;
  }
  cVar1 = *param_1;
  if (cVar1 == '\x02') goto switchD_00126fc8_caseD_2;
  if (cVar1 == '\x1e') {
    iVar2 = 5;
    goto LAB_00126f78;
  }
  iVar2 = 0;
  if (cVar1 == '\x1f') goto LAB_00126f60;
  goto LAB_00126f78;
LAB_00126f60:
  iVar3 = 7;
  iVar2 = 0xcd6;
  goto switchD_00126fc8_caseD_5;
switchD_00126fc8_caseD_1:
  do {
  } while( true );
}


/* EXPORT index=206 ELF_VA=0x27058 size=136 source_sha256=d1f56aebbf830e05d3fa6c25ada1e99249288dba781021fa15a0ef07c378ac50 */

undefined4 j___S5__I_OOl_O_l__ll_lIO_0_IlIIllSSIIIO__I5O0III_5S5_(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
LAB_00127070:
  while( true ) {
    iVar3 = iVar2;
    if (iVar3 != 1) goto LAB_001270a4;
    cVar1 = *param_1;
    if (cVar1 == '!') {
      return 1;
    }
    if (cVar1 == ' ') break;
    iVar2 = 6;
    if (cVar1 == '\x01') {
      iVar2 = 4;
    }
  }
  goto LAB_0012706c;
LAB_001270a4:
  if (iVar3 == 6) {
    return 0;
  }
  iVar2 = 1;
  if (iVar3 != 0) {
    if (iVar3 != 4) {
      if (iVar3 == 3) {
        return 1;
      }
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
LAB_0012706c:
    iVar2 = 3;
  }
  goto LAB_00127070;
}


/* EXPORT index=207 ELF_VA=0x270e0 size=1492 source_sha256=ac23e8e5fa5a58e1030d5c1cdc4a4ad7105fd75feb84b125c0838aaf71800edc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___I_5_l_llI_l__0OOl_S5_lO_O_lIl_0IO5lI_OIlI5S00_lS5_
               (undefined1 *param_1,undefined1 *param_2,ulong param_3,ulong param_4)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined8 uVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 auStack_110 [128];
  ulong uStack_90;
  ulong uStack_88;
  ulong uStack_80;
  undefined8 uStack_78;
  long lStack_68;
  
  uVar9 = 0x2ab2;
  iVar5 = 0x11;
  uVar8 = 0xf91a47ba;
  lStack_68 = ___stack_chk_guard;
  uStack_88 = 0x31764060d665142;
  uStack_90 = 0x24255b005a053f7b;
  uStack_78 = 0x2367460872164166;
  uStack_80 = 0x6529005d2f092e7c;
switchD_001271cc_default:
  do {
    uVar4 = 1;
    bVar3 = (byte)uVar8;
    switch(iVar5) {
    case 0:
      uVar4 = 0;
switchD_001271cc_caseD_8:
      if (___stack_chk_guard == lStack_68) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(uVar4,param_2,param_3,param_4);
    case 1:
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x35a2459c)) =
           bVar3 ^ *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x35a2459c)) ^ 0x5c;
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x35a2458e)) =
           bVar3 ^ *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x35a2458e)) ^ 0x3a;
      iVar5 = uVar8 * uVar8;
      uVar6 = (ulong)(iVar5 + 0x5b2fc68b);
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x35a2459e)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x35a2459e)) ^ bVar3 + 0xba;
      uVar8 = uVar8 * uVar8;
      *(byte *)((long)&uStack_90 + uVar6) = (byte)uVar8 ^ *(byte *)((long)&uStack_90 + uVar6) ^ 0x5e
      ;
      uVar6 = (ulong)(iVar5 + 0x5b2fc691);
      *(byte *)((long)&uStack_90 + uVar6) = (byte)uVar8 ^ *(byte *)((long)&uStack_90 + uVar6) ^ 0x14
      ;
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 ^ 0xa4d0397f)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 ^ 0xa4d0397f)) ^ bVar3 * bVar3 - 0x28;
      iVar5 = 0xd;
      break;
    case 2:
switchD_001271cc_caseD_2:
      iVar5 = 9;
      break;
    case 3:
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x7c5a7518)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x7c5a7518)) ^ bVar3 + 0x1c;
      iVar5 = uVar8 * uVar8;
      uVar7 = (ulong)(iVar5 * 0x6a4cc201 ^ 0xbdebbc34);
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x7c5a7512)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x7c5a7512)) ^ bVar3 + 0x61;
      uVar6 = (ulong)(iVar5 * 0x6a4cc201 + 0x421443e9);
      *(byte *)((long)&uStack_90 + uVar7) =
           *(byte *)((long)&uStack_90 + uVar7) ^ (char)iVar5 + 0x21U;
      uVar8 = iVar5 * -0x2b667bfe;
      *(byte *)((long)&uStack_90 + uVar6) =
           (byte)(iVar5 * 0x6a4cc201) ^ *(byte *)((long)&uStack_90 + uVar6) ^ 0x7e;
      iVar5 = 0xf;
      break;
    case 4:
switchD_001271cc_caseD_4:
      iVar5 = 6;
      break;
    case 5:
switchD_001271cc_caseD_5:
      iVar5 = 0;
      break;
    case 6:
switchD_001271cc_caseD_6:
      iVar5 = 0x14;
      break;
    case 7:
switchD_001271cc_caseD_7:
      iVar5 = 0x12;
      break;
    case 8:
    case 0x16:
      goto switchD_001271cc_caseD_8;
    case 9:
switchD_001271cc_caseD_9:
      iVar5 = 0xc;
      break;
    case 10:
      uStack_88 = uStack_88 ^ 0x7e00;
      uStack_80 = uStack_80 ^ 0x7a00000000;
      uVar9 = 0x297f;
      iVar5 = 0xb;
      uStack_90 = uStack_90 ^ 0x680000;
      uVar8 = 0x6acf59c5;
      break;
    case 0xb:
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x9530a63c)) =
           bVar3 ^ *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x9530a63c)) ^ 0xf5;
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x9530a652)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x9530a652)) ^ bVar3 + 0x7a;
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x9530a64b)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x9530a64b)) ^ bVar3 + 0x46;
      uVar1 = uVar8 + 0x9530a653;
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 ^ 0x6acf59de)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 ^ 0x6acf59de)) ^ bVar3 + 0x62;
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x9530a64d)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x9530a64d)) ^ bVar3 + 0x9d;
      uVar8 = uVar8 + 0x5f8e60b0;
      *(byte *)((long)&uStack_90 + (ulong)uVar1) =
           *(byte *)((long)&uStack_90 + (ulong)uVar1) ^ bVar3 + 0x6b;
      iVar5 = (0x69 - uVar9) + (uVar9 / 0x9d) * 0x9d;
      break;
    case 0xc:
switchD_001271cc_caseD_c:
      iVar5 = 7;
      break;
    case 0xd:
      uVar1 = uVar8 + 0x5b2fc68f;
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 ^ 0xa4d03979)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 ^ 0xa4d03979)) ^ bVar3 - 0x3a;
      uVar2 = (uVar8 << 1 ^ 0xbc9bb2c8) + 0xc7002401;
      uVar8 = uVar2 ^ 0x3f9e6f3c;
      *(byte *)((long)&uStack_90 + (ulong)uVar1) =
           *(byte *)((long)&uStack_90 + (ulong)uVar1) ^ bVar3 + 0xaa;
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x7c5a7506)) =
           (byte)uVar2 ^ *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x7c5a7506)) ^ 0x44;
      iVar5 = 3;
      break;
    case 0xe:
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0xa973df9c)) =
           bVar3 ^ *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0xa973df9c)) ^ 0xd2;
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0xa973df9e)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0xa973df9e)) ^ bVar3 - 2;
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0xa973df8b)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0xa973df8b)) ^ bVar3 - 0x2f;
      param_3 = (ulong)(uVar8 + 0x9fb27f74);
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 ^ 0x568c2087)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 ^ 0x568c2087)) ^ bVar3 - 2;
      param_4 = (ulong)(uVar8 ^ 0x47c9900e);
      do {
        param_2 = auStack_110;
        CallSupervisor(0);
      } while (&stack0x00000000 == (undefined1 *)0x8c);
      iVar5 = 0x13;
      break;
    case 0xf:
      iVar5 = uVar8 + 0x34f8d652;
      uVar6 = (ulong)(iVar5 * iVar5 + 0x834dd17f);
      uVar8 = iVar5 * iVar5;
      *(byte *)((long)&uStack_90 + uVar6) = (byte)uVar8 ^ *(byte *)((long)&uStack_90 + uVar6) ^ 0xd8
      ;
      uVar6 = (ulong)(iVar5 * iVar5 + 0x834dd185);
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 ^ 0x7cb22e8d)) =
           (byte)uVar8 ^ *(byte *)((long)&uStack_90 + (ulong)(uVar8 ^ 0x7cb22e8d)) ^ 0xc1;
      uVar8 = uVar8 ^ 0xfc8924c3;
      *(byte *)((long)&uStack_90 + uVar6) =
           *(byte *)((long)&uStack_90 + uVar6) ^ (char)iVar5 * (char)iVar5 + 0x94U;
      *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x7fc4f5c3)) =
           *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0x7fc4f5c3)) ^ (char)uVar8 + 0x1aU;
      iVar5 = 0x15;
      break;
    case 0x10:
      iVar5 = (0x15 - uVar9) + (uVar9 / 0x29) * 0x29;
      break;
    case 0x11:
      uVar9 = 0x245d;
      iVar5 = 0x10;
      break;
    case 0x12:
switchD_001271cc_caseD_12:
      iVar5 = 4;
      break;
    case 0x13:
      switch(*param_1) {
      case 9:
        goto switchD_001271cc_caseD_4;
      case 10:
        goto switchD_001271cc_caseD_6;
      case 0xb:
        goto switchD_001271cc_caseD_14;
      default:
        goto switchD_001271cc_caseD_5;
      case 0x16:
        goto switchD_001271cc_caseD_2;
      case 0x17:
        goto switchD_001271cc_caseD_9;
      case 0x18:
        goto switchD_001271cc_caseD_c;
      case 0x19:
        goto switchD_001271cc_caseD_7;
      case 0x1a:
        goto switchD_001271cc_caseD_12;
      }
    case 0x14:
switchD_001271cc_caseD_14:
      iVar5 = 8;
      break;
    case 0x15:
      goto switchD_001271cc_caseD_15;
    }
  } while( true );
switchD_001271cc_caseD_15:
  uVar8 = uVar8 + 0x38af8856 & 0x49e95632;
  uVar8 = uVar8 * uVar8 + 0x1b63a8aa & 0x56ce20d0;
  *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0xa973df8e)) =
       *(byte *)((long)&uStack_90 + (ulong)(uVar8 + 0xa973df8e)) ^ (char)uVar8 - 0x13U;
  *(byte *)((long)&uStack_90 + (ulong)(uVar8 ^ 0x568c208c)) =
       *(byte *)((long)&uStack_90 + (ulong)(uVar8 ^ 0x568c208c)) ^ (char)uVar8 + 0x86U;
  iVar5 = 0xe;
  goto switchD_001271cc_default;
}


/* EXPORT index=208 ELF_VA=0x27758 size=344 source_sha256=55370fc28326034b92f6e78013cb578eb8f168486e28d26d18a2722fd0adca7b */

undefined4 j____I0O__l0O_l_0_5lS_IOII___5lSIl050IIO_Sl_0II0IIIS5_(byte *param_1,byte *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0x47bc;
  iVar4 = 9;
switchD_001277ec_default:
  uVar2 = 0;
  switch(iVar4) {
  case 0:
    if ((char)param_1[8] < '\0') {
      iVar4 = 8 - uVar3 % 0xb5;
    }
    else {
      iVar4 = 9 - uVar3 % 0xb5;
    }
    goto switchD_001277ec_default;
  case 1:
    bVar1 = *param_1;
    if (0x21 < bVar1) {
      if (bVar1 == 0x22) goto switchD_001277ec_caseD_7;
      goto switchD_001277ec_caseD_2;
    }
    if (bVar1 == 0) goto switchD_001277ec_caseD_6;
    if (bVar1 != 0xe) {
      if (bVar1 != 0x12) goto switchD_001277ec_caseD_2;
      goto switchD_001277ec_caseD_a;
    }
    break;
  case 2:
switchD_001277ec_caseD_2:
    iVar4 = 5;
    goto switchD_001277ec_default;
  case 3:
  case 8:
    goto switchD_001277ec_caseD_3;
  case 5:
  case 0xb:
    goto switchD_001277ec_caseD_5;
  case 6:
switchD_001277ec_caseD_6:
    iVar4 = 7;
    goto switchD_001277ec_default;
  case 7:
switchD_001277ec_caseD_7:
    iVar4 = 10;
    goto switchD_001277ec_default;
  case 9:
    goto switchD_001277ec_caseD_9;
  case 10:
switchD_001277ec_caseD_a:
    iVar4 = 8;
  default:
    goto switchD_001277ec_default;
  }
  iVar4 = 0;
  uVar3 = 0x7783;
  goto switchD_001277ec_default;
switchD_001277ec_caseD_9:
  iVar4 = (0xb - uVar3) + (uVar3 / 0x13) * 0x13;
  goto switchD_001277ec_default;
switchD_001277ec_caseD_3:
  *param_2 = param_1[8];
  uVar2 = 1;
switchD_001277ec_caseD_5:
  return uVar2;
}


/* EXPORT index=209 ELF_VA=0x278e0 size=364 source_sha256=c930aa3e5364f1222d01bc3da9b8f32734f93a4fc8310b8cc951b0b88e3b1da4 */

undefined4 j___I_____OOllI_5SI0__O_0IO_l0lllllS0Il_05l5SlllI_IS5_(byte *param_1,ushort *param_2)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar4 = 0x1a3e;
  iVar2 = 2;
switchD_0012795c_default:
  switch(iVar2) {
  case 0:
  case 0xf:
    goto switchD_0012795c_caseD_0;
  case 1:
    uVar3 = (ushort)param_1[8];
    break;
  case 2:
    uVar4 = 0x3003;
    iVar2 = 7;
    goto switchD_0012795c_default;
  case 3:
    goto switchD_0012795c_caseD_3;
  case 4:
  case 5:
    uVar3 = *(ushort *)(param_1 + 8);
    break;
  case 6:
switchD_0012795c_caseD_6:
    iVar2 = 8;
    goto switchD_0012795c_default;
  case 7:
    bVar1 = *param_1;
    iVar2 = 0;
    if (bVar1 < 0x22) {
      if (bVar1 < 0xe) {
        if (bVar1 == 0) goto switchD_0012795c_caseD_6;
      }
      else {
        switch(bVar1) {
        case 0xe:
          goto switchD_0012795c_caseD_9;
        case 0xf:
          goto switchD_0012795c_caseD_d;
        case 0x12:
          goto switchD_0012795c_caseD_b;
        case 0x13:
switchD_0012795c_caseD_3:
          iVar2 = 5;
        }
      }
    }
    else if (bVar1 == 0x22) goto switchD_0012795c_caseD_8;
    goto switchD_0012795c_default;
  case 8:
switchD_0012795c_caseD_8:
    iVar2 = 0xb;
    goto switchD_0012795c_default;
  case 9:
switchD_0012795c_caseD_9:
    iVar2 = 1;
    goto switchD_0012795c_default;
  case 10:
    iVar2 = 0;
    goto switchD_0012795c_default;
  case 0xb:
switchD_0012795c_caseD_b:
    uVar4 = 0x6d33;
    iVar2 = 0xe;
    goto switchD_0012795c_default;
  case 0xc:
    goto switchD_0012795c_caseD_c;
  case 0xd:
switchD_0012795c_caseD_d:
    iVar2 = 0xc;
    uVar4 = 0x2c08;
    goto switchD_0012795c_default;
  case 0xe:
    uVar3 = (ushort)(char)param_1[8];
    break;
  default:
    goto switchD_0012795c_default;
  }
  *param_2 = uVar3;
  return 1;
switchD_0012795c_caseD_c:
  if (*(short *)(param_1 + 8) < 0) {
    iVar2 = 0x1e - uVar4 % 0x1d;
  }
  else {
    iVar2 = 0x18 - uVar4 % 0x1d;
  }
  goto switchD_0012795c_default;
switchD_0012795c_caseD_0:
  return 0;
}


/* EXPORT index=210 ELF_VA=0x27aa4 size=2164 source_sha256=1e2b8b00766f18533853cf63c8a88ea741384a9cca03a617d4a21b750d63cfca */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___0lSS5_SI_lO_l0_5I_OII5S_l0S5__IOISI_IlIIlI5_l05S5_
               (byte *param_1,uint *param_2,ulong param_3,ulong param_4)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  ulong uStack_80;
  ulong uStack_78;
  undefined8 uStack_70;
  undefined7 uStack_68;
  undefined1 uStack_61;
  undefined7 uStack_60;
  long lStack_48;
  
  lStack_48 = ___stack_chk_guard;
  uStack_60 = 0x7f654e7e556961;
  uStack_78 = 0xc3e0e176b182e5e;
  uStack_80 = 0x2732063e077d735b;
  uStack_68 = 0xd205d4b6d4926;
  uStack_61 = 0x4d;
  uStack_70 = 0x3e193b397d537a49;
  uVar9 = 0x7dc6;
  uVar6 = 5;
  uVar7 = 0x194c42a1;
  puVar5 = param_2;
switchD_00127b54_default:
  uVar4 = 0;
  bVar2 = (byte)uVar7;
  switch(uVar6) {
  case 0:
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0x6b83adb2)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0x6b83adb2)) ^ bVar2 - 0xe;
    uVar6 = uVar7 + 0x6b83adc3;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0x6b83adc7)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0x6b83adc7)) ^ bVar2 + 0x2b;
    uVar7 = (uVar7 * -0x27e0557f & 0x21645160) + 0x3f5892a6 & 0x3748a1a4;
    *(byte *)((long)&uStack_80 + (ulong)uVar6) =
         *(byte *)((long)&uStack_80 + (ulong)uVar6) ^ bVar2 - 0x1b;
    uVar6 = 0x21;
    goto switchD_00127b54_default;
  case 1:
    goto switchD_00127b54_caseD_1;
  case 2:
    uVar7 = uVar7 << 2;
switchD_001282a4_caseD_f:
    uVar6 = 0x1b;
    goto switchD_00127b54_default;
  case 3:
switchD_00127b54_caseD_3:
    uVar6 = 0x20;
    goto switchD_00127b54_default;
  case 4:
    uVar7 = (uint)(char)param_1[8];
    goto LAB_001282e4;
  case 5:
    uVar7 = uVar7 * -0x4bf04fe0;
    uVar6 = 7;
    goto switchD_00127b54_default;
  case 6:
    uVar6 = 0;
    uVar7 = uVar7 << 1 ^ 0xb12c724;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0x72ef11be)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0x72ef11be)) ^ (char)uVar7 + 0x31U;
    uVar7 = uVar7 * 4 + 0x6038992e;
    goto switchD_00127b54_default;
  case 7:
    bVar2 = *param_1;
    if (bVar2 < 0xe) {
joined_r0x00128190:
      if (bVar2 == 0) goto switchD_00127b54_caseD_17;
    }
    else {
      if (bVar2 < 0x22) {
        uVar6 = 0x12;
        switch(bVar2) {
        case 0xe:
          goto switchD_001282a4_caseD_e;
        case 0xf:
          goto switchD_001282a4_caseD_f;
        case 0x10:
          goto switchD_001282a4_caseD_10;
        default:
          goto switchD_001282a4_caseD_11;
        case 0x12:
          goto switchD_001282a4_caseD_12;
        case 0x13:
          goto switchD_00127b54_default;
        case 0x14:
          goto switchD_00127b54_caseD_3;
        }
      }
LAB_001282b0:
      if (bVar2 == 0x22) goto switchD_00127b54_caseD_9;
    }
    break;
  case 8:
    uVar7 = uVar7 << 1;
switchD_001282a4_caseD_12:
    uVar6 = 4;
    goto switchD_00127b54_default;
  case 9:
switchD_00127b54_caseD_9:
    uVar6 = 8;
    goto switchD_00127b54_default;
  case 10:
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xc2092f16)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xc2092f16)) ^ bVar2 + 0x6f;
    uVar6 = uVar7 ^ 0xb680469d;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xc2092f11)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xc2092f11)) ^ bVar2 + 0x6f;
    uVar7 = uVar6 + 0xbd60e039;
    *(byte *)((long)&uStack_80 + (ulong)(uVar6 + 0x74896891)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar6 + 0x74896891)) ^ (char)uVar6 + 0xb3U;
    *(byte *)((long)&uStack_80 + (ulong)(uVar6 + 0x74896898)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar6 + 0x74896898)) ^ (char)uVar6 + 0xa6U;
    uVar6 = (0x47 - uVar9) + (uVar9 / 0x3d) * 0x3d;
    goto switchD_00127b54_default;
  case 0xb:
    uVar6 = uVar7 * 2;
    bVar2 = (byte)uVar6 + 9;
    *(byte *)((long)&uStack_80 + (ulong)(uVar6 + 0x91a8f29b)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar6 + 0x91a8f29b)) ^ bVar2;
    *(byte *)((long)&uStack_80 + (ulong)(uVar6 ^ 0x6e570d6c)) =
         (byte)uVar6 ^ *(byte *)((long)&uStack_80 + (ulong)(uVar6 ^ 0x6e570d6c)) ^ 0xf;
    *(byte *)((long)&uStack_80 + (ulong)(uVar6 + 0x91a8f2af)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar6 + 0x91a8f2af)) ^ bVar2;
    uVar7 = uVar6 + 0x11171635;
    *(byte *)((long)&uStack_80 + (ulong)(uVar6 + 0x91a8f29e)) =
         (byte)uVar7 ^ *(byte *)((long)&uStack_80 + (ulong)(uVar6 + 0x91a8f29e)) ^ 0xbc;
    *(byte *)((long)&uStack_80 + (ulong)(uVar6 + 0x91a8f2a4)) =
         (byte)uVar7 ^ *(byte *)((long)&uStack_80 + (ulong)(uVar6 + 0x91a8f2a4)) ^ 0xe5;
    uVar6 = 0x18;
    goto switchD_00127b54_default;
  case 0xc:
    uVar7 = (uVar7 ^ 0xa5990e12) + 0x941c2e6a;
    uVar6 = 0x12;
    goto switchD_00127b54_default;
  case 0xd:
    uVar7 = uVar7 * 2 + 0xd293b0df;
switchD_001282a4_caseD_e:
    uVar6 = 1;
    goto switchD_00127b54_default;
  case 0xe:
    iVar3 = uVar7 * 2;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0x67beda31)) =
         bVar2 ^ *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0x67beda31)) ^ 0x3b;
    uVar8 = (ulong)(iVar3 + 0x30824bcc);
    uVar7 = uVar7 * 8;
    *(byte *)((long)&uStack_80 + uVar8) = *(byte *)((long)&uStack_80 + uVar8) ^ (char)iVar3 + 0x35U;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xc2092ef1)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xc2092ef1)) ^ (char)uVar7 + 0x69U;
    uVar9 = 0x4089;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0x3df6d119)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0x3df6d119)) ^ (char)uVar7 + 9U;
    uVar6 = 10;
    goto switchD_00127b54_default;
  case 0xf:
    uStack_80 = uStack_80 ^ 0x400000000000;
    uVar6 = (0x44 - uVar9) + (uVar9 / 0x3d) * 0x3d;
    uStack_78 = uStack_78 ^ 0x3300000000;
    uVar7 = 0xeb11d5be;
    goto switchD_00127b54_default;
  case 0x10:
  case 0x22:
    goto switchD_00127b54_caseD_10;
  case 0x11:
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0x14ee2a4f)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0x14ee2a4f)) ^ bVar2 - 0x3f;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0xeb11d5a5)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0xeb11d5a5)) ^ bVar2 + 0x75;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0xeb11d5a4)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0xeb11d5a4)) ^ bVar2 + 0xbb;
    uVar6 = uVar7 + 0x14ee2a51;
    uVar7 = uVar7 & 0x53cb16b6;
    *(byte *)((long)&uStack_80 + (ulong)uVar6) =
         bVar2 ^ *(byte *)((long)&uStack_80 + (ulong)uVar6) ^ 0xfe;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xbcfeeb60)) =
         (byte)uVar7 ^ *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xbcfeeb60)) ^ 0x85;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xbcfeeb54)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xbcfeeb54)) ^ (byte)uVar7 + 0x8a;
    uVar6 = 6;
    goto switchD_00127b54_default;
  case 0x12:
    uVar7 = (uint)*(short *)(param_1 + 8);
    goto LAB_001282e4;
  case 0x13:
    uVar7 = uVar7 + 0xcebd4874;
    break;
  case 0x14:
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xb728885d)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xb728885d)) ^ bVar2 + 0x7a;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xb7288853)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xb7288853)) ^ bVar2 + 0x7a;
    uVar6 = uVar7 + 0xa1b66476;
    uVar1 = uVar6 ^ 0x9e26b26f;
    uVar8 = (ulong)(uVar1 + 0x8b5491cf);
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xb728883d)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xb728883d)) ^ bVar2 + 0xb9;
    uVar7 = uVar1 + 0xb81dbd54;
    *(byte *)((long)&uStack_80 + uVar8) = (byte)uVar6 ^ *(byte *)((long)&uStack_80 + uVar8) ^ 0x25;
    uVar6 = 0x15;
    goto switchD_00127b54_default;
  case 0x15:
    iVar3 = uVar7 * 8;
    uVar7 = iVar3 + 0x754c6624;
    uVar8 = (ulong)(uVar7 ^ 0xdb95c378);
    uVar7 = uVar7 * 2;
    *(byte *)((long)&uStack_80 + uVar8) = *(byte *)((long)&uStack_80 + uVar8) ^ (char)iVar3 + 0x41U;
    uVar6 = 0xb;
    goto switchD_00127b54_default;
  case 0x16:
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0x3108003c)) =
         bVar2 ^ *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0x3108003c)) ^ 0x38;
    do {
      CallSupervisor(0);
    } while (&stack0x00000000 == (undefined1 *)0x7c);
    do {
      CallSupervisor(0);
    } while (&stack0x00000000 == (undefined1 *)0x7c);
    param_3 = (ulong)(uVar7 + 0x70fc96b5);
    param_4 = (ulong)(uVar7 + 0xbf8378d2);
    puVar5 = (uint *)(ulong)(uVar7 + 0xb8ab0fa8 ^ 0xaa99f43b);
    do {
      CallSupervisor(0);
    } while (&stack0x00000000 == (undefined1 *)0x7c);
    uVar7 = (uVar7 + 0xb8ab0fa8) * 2;
    uVar6 = 0xc;
    goto switchD_00127b54_default;
  case 0x17:
switchD_00127b54_caseD_17:
    uVar6 = 9;
    goto switchD_00127b54_default;
  case 0x18:
    iVar3 = uVar7 * 2;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0x8091dc72)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0x8091dc72)) ^ bVar2 - 0x26;
    uVar7 = iVar3 + 0x322c0375U & 0xf19f9561;
    *(byte *)((long)&uStack_80 + (ulong)(iVar3 + 0x123b8be)) =
         *(byte *)((long)&uStack_80 + (ulong)(iVar3 + 0x123b8be)) ^ (char)iVar3 + 0x35U;
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0x31080026)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0x31080026)) ^ ((byte)uVar7 | 0x12);
    *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xcef7ffe3)) =
         *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xcef7ffe3)) ^ (byte)uVar7 - 8;
    uVar6 = 0x16;
    goto switchD_00127b54_default;
  case 0x19:
    uVar7 = uVar7 + 0x87ee9dde;
switchD_001282a4_caseD_10:
    uVar6 = 0x1a;
    goto switchD_00127b54_default;
  case 0x1a:
    uVar6 = *(uint *)(param_1 + 8) >> 0x1e & 2 | 0x1c;
    goto switchD_00127b54_default;
  case 0x1b:
    uVar7 = (uint)*(ushort *)(param_1 + 8);
    goto LAB_001282e4;
  case 0x1c:
  case 0x20:
    uVar7 = *(uint *)(param_1 + 8);
    goto LAB_001282e4;
  case 0x1d:
    bVar2 = *param_1;
    if (bVar2 < 0xe) goto joined_r0x00128190;
    if (0x21 < bVar2) goto LAB_001282b0;
    uVar6 = 0x12;
    switch(bVar2) {
    case 0xe:
      goto switchD_001282a4_caseD_e;
    case 0xf:
      goto switchD_001282a4_caseD_f;
    case 0x10:
      goto switchD_001282a4_caseD_10;
    default:
      break;
    case 0x12:
      goto switchD_001282a4_caseD_12;
    case 0x13:
      goto switchD_00127b54_default;
    case 0x14:
      goto switchD_00127b54_caseD_3;
    }
  case 0x1e:
    uVar6 = 0x13;
    goto switchD_00127b54_default;
  case 0x1f:
    uVar7 = uVar7 * 2 + 0xba54c138;
    uVar6 = 0x12;
    goto switchD_00127b54_default;
  case 0x21:
    goto switchD_00127b54_caseD_21;
  default:
    goto switchD_00127b54_default;
  }
switchD_001282a4_caseD_11:
  uVar6 = 0x10;
  goto switchD_00127b54_default;
switchD_00127b54_caseD_21:
  *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xe8b77e74)) =
       *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xe8b77e74)) ^ bVar2 + 0x75;
  uVar6 = uVar7 + 0xe8b77e6e;
  *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xe8b77e5e)) =
       *(byte *)((long)&uStack_80 + (ulong)(uVar7 + 0xe8b77e5e)) ^ bVar2 + 0x8f;
  uVar7 = uVar7 * -0x714d336a + 0xdfec340a;
  *(byte *)((long)&uStack_80 + (ulong)uVar6) =
       bVar2 ^ *(byte *)((long)&uStack_80 + (ulong)uVar6) ^ 0xdb;
  *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0x67beda02)) =
       *(byte *)((long)&uStack_80 + (ulong)(uVar7 ^ 0x67beda02)) ^ bVar2 * -0x6a + 0x1b;
  uVar6 = 0xe;
  goto switchD_00127b54_default;
switchD_00127b54_caseD_1:
  uVar7 = (uint)param_1[8];
LAB_001282e4:
  *param_2 = uVar7;
  uVar4 = 1;
switchD_00127b54_caseD_10:
  if (___stack_chk_guard != lStack_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4,puVar5,param_3,param_4);
  }
  return;
}


/* EXPORT index=211 ELF_VA=0x283dc size=340 source_sha256=a2fdba0bf0559c9f14f9095247ab69708ae5df9896e72c125cc01c717a3fa2c1 */

undefined8 j____lSS__l05ll_IllII_SIl0I__S5II5005l_IIlI0_IllS00S5_(byte *param_1,ulong *param_2)

{
  byte bVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0x536e;
  iVar4 = 2;
  do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch(iVar4) {
    case 0:
switchD_00128430_caseD_0:
      iVar4 = 0x10;
      break;
    case 2:
      iVar4 = 0x14;
      break;
    case 4:
switchD_00128430_caseD_4:
      iVar4 = 0;
      break;
    case 6:
switchD_00128430_caseD_6:
      iVar4 = 1;
      break;
    case 8:
      uVar2 = (ulong)*(uint *)(param_1 + 8);
LAB_0012851c:
      *param_2 = uVar2;
      return 1;
    case 10:
switchD_00128430_caseD_a:
      iVar4 = 0x15;
      break;
    case 0xc:
switchD_00128430_caseD_c:
      iVar4 = 5;
      break;
    case 0xe:
      if (*(long *)(param_1 + 8) < 0) {
        iVar4 = 0x57 - uVar3 % 0xb3;
      }
      else {
        iVar4 = 0x5f - uVar3 % 0xb3;
      }
      break;
    case 0x10:
switchD_00128430_caseD_10:
      iVar4 = 7;
      break;
    case 0x12:
      uVar2 = *(ulong *)(param_1 + 8);
      goto LAB_0012851c;
    case 0x14:
      bVar1 = *param_1;
      if (bVar1 < 0xe) {
        if (bVar1 != 0) goto switchD_00128430_caseD_a;
        goto switchD_00128430_caseD_4;
      }
      switch(bVar1) {
      case 0xe:
        goto switchD_00128430_caseD_6;
      case 0xf:
        iVar4 = 0x18;
        break;
      case 0x10:
        uVar3 = 0x1ffe;
        iVar4 = 8;
        break;
      case 0x11:
        uVar3 = 0x2290;
        iVar4 = 0xe;
        break;
      case 0x12:
        goto switchD_00128430_caseD_10;
      case 0x13:
        goto switchD_00128430_caseD_c;
      case 0x14:
        iVar4 = 0x16;
        break;
      case 0x15:
        uVar3 = 0x7db4;
        iVar4 = 0xd;
        break;
      default:
        goto switchD_00128430_caseD_a;
      case 0x22:
        goto switchD_00128430_caseD_0;
      }
      break;
    case 0x16:
      uVar2 = (ulong)*(int *)(param_1 + 8);
      goto LAB_0012851c;
    case 0x18:
      uVar2 = (ulong)*(ushort *)(param_1 + 8);
      goto LAB_0012851c;
    }
  } while( true );
}


/* EXPORT index=212 ELF_VA=0x285ec size=4 source_sha256=dc0391a526bbc0f3349e01788a01412070250ffad8953b9cc63794f3c28b4a7e */

void j___llO_S_SIOIS___SIl_55I_I_SS05I__lIISl05IOI0l0I_lS5_(void)

{
  j____lSS__l05ll_IllII_SIl0I__S5II5005l_IIlI0_IllS00S5_();
  return;
}


/* EXPORT index=213 ELF_VA=0x285f0 size=200 source_sha256=21506236a8e79344501783224dfe4a422f999e1e6f60d7af796652b2aef5436e */

/* WARNING: Removing unreachable block (ram,0x00128670) */

undefined4 j___II__I_I_lII_5lll0_IlOOI_lOI0__Il_O_SIlIl__ISlIIS5_(char *param_1,char *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = 6;
switchD_00128644_caseD_3:
  do {
    uVar3 = uVar1;
    uVar2 = 0;
    uVar1 = 1;
    switch(uVar3) {
    case 0:
      goto switchD_00128644_caseD_0;
    case 1:
switchD_00128644_caseD_1:
      uVar1 = 5;
      break;
    case 2:
      uVar1 = 1;
      if (*param_1 != '\0') {
        if (*param_1 == '\x0e') goto switchD_00128644_caseD_1;
        goto switchD_00128690_caseD_4;
      }
      break;
    case 3:
      break;
    default:
      goto code_r0x00128680;
    }
  } while( true );
code_r0x00128680:
  uVar2 = 0;
  uVar1 = 2;
  switch(uVar3) {
  case 4:
switchD_00128690_caseD_4:
    uVar1 = 0;
    break;
  case 5:
    *param_2 = param_1[8];
    uVar2 = 1;
  case 7:
switchD_00128644_caseD_0:
    return uVar2;
  case 6:
    break;
  default:
    goto switchD_00128690_default;
  }
  goto switchD_00128644_caseD_3;
switchD_00128690_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* EXPORT index=214 ELF_VA=0x286d8 size=168 source_sha256=91d65fec50ad87fa2ddec9ce6a580de6eeeb26ae4078ab29907c04e857f31982 */

void j___II5II_0IO55_IIl_O_Ol_ll_0II5l__5IO_Sl_II0IOI_S5S5_(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = 2;
switchD_0012871c_caseD_2:
  uVar4 = uVar2;
  uVar3 = 0;
  uVar2 = 8;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(uVar4) {
  case 0:
switchD_0012871c_caseD_0:
    uVar3 = 7;
    break;
  default:
    goto switchD_0012871c_caseD_2;
  case 4:
    break;
  case 6:
switchD_0012871c_caseD_6:
    uVar3 = 3;
    break;
  case 8:
    cVar1 = *param_1;
    if (cVar1 == '\0') {
      uVar3 = 0;
      break;
    }
    if (cVar1 == '\x0e') goto switchD_0012871c_caseD_0;
    if (cVar1 != '\x0f') goto switchD_0012871c_caseD_6;
    uVar2 = 1;
    goto switchD_0012871c_caseD_2;
  }
  uVar2 = uVar3;
  goto switchD_0012871c_caseD_2;
}


/* EXPORT index=215 ELF_VA=0x287a4 size=196 source_sha256=cec9f8cc41f518b04b770ffa51188485a38584d4120bbca0889832e48b4a07bc */

undefined4 j___ISS0__SII___0__55___SIl_l_ISS_0SIl5_SI_OlI0l05IS5_(byte *param_1,uint *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = 5;
switchD_001287e4_caseD_1:
  iVar4 = iVar2;
  iVar2 = 8;
  switch(iVar4) {
  case 1:
    goto switchD_001287e4_caseD_1;
  case 2:
    goto switchD_001287e4_caseD_2;
  default:
    iVar2 = 10;
    if (iVar4 != 5) {
      if (iVar4 != 3) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      uVar3 = (uint)*(ushort *)(param_1 + 8);
      break;
    }
    goto switchD_001287e4_caseD_1;
  case 8:
    uVar3 = (uint)param_1[8];
    break;
  case 10:
    bVar1 = *param_1;
    if (0xd < bVar1) goto LAB_00128810;
    if (bVar1 != 0) goto LAB_001287c0;
    iVar2 = 1;
    goto switchD_001287e4_caseD_1;
  }
LAB_00128854:
  *param_2 = uVar3;
  return 1;
LAB_00128810:
  iVar2 = 8;
  if (bVar1 == 0xe) goto switchD_001287e4_caseD_1;
  if (bVar1 == 0xf) {
    iVar2 = 3;
    goto switchD_001287e4_caseD_1;
  }
  if (bVar1 != 0x10) {
LAB_001287c0:
    iVar2 = 2;
    goto switchD_001287e4_caseD_1;
  }
  uVar3 = *(uint *)(param_1 + 8);
  goto LAB_00128854;
switchD_001287e4_caseD_2:
  return 0;
}


/* EXPORT index=216 ELF_VA=0x28890 size=248 source_sha256=01ddfd7da6fa616f6af7dcb053135532f3ffa432e126a45f7e607130529dbce9 */

undefined4 j___IOIOI_OIISl_lII00_Il_Il__ISlIlI_O_IIlO5IllOIlI0S5_(byte *param_1,ulong *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  uVar4 = 0xb;
switchD_001288f0_default:
  uVar2 = 0;
  switch(uVar4) {
  case 0:
    goto switchD_001288f0_caseD_0;
  case 1:
    uVar3 = (ulong)*(ushort *)(param_1 + 8);
    goto LAB_00128974;
  case 2:
    uVar3 = *(ulong *)(param_1 + 8);
    goto LAB_00128974;
  case 3:
switchD_001288f0_caseD_3:
    uVar4 = 0;
    goto switchD_001288f0_default;
  case 4:
    uVar3 = (ulong)*(uint *)(param_1 + 8);
    goto LAB_00128974;
  case 5:
switchD_001288f0_caseD_5:
    uVar4 = 2;
    goto switchD_001288f0_default;
  case 6:
switchD_001288f0_caseD_6:
    uVar4 = 4;
    goto switchD_001288f0_default;
  case 8:
    uVar4 = 1;
    goto switchD_001288f0_default;
  case 9:
    bVar1 = *param_1;
    if (bVar1 < 0xe) {
      if (bVar1 == 0) goto switchD_001288f0_caseD_c;
    }
    else {
      uVar4 = 1;
      switch(bVar1) {
      case 0xe:
        goto switchD_001288f0_caseD_3;
      case 0xf:
        goto switchD_001288f0_default;
      case 0x10:
        goto switchD_001288f0_caseD_6;
      case 0x11:
        goto switchD_001288f0_caseD_5;
      }
    }
    break;
  case 10:
  case 0xd:
    goto switchD_001288f0_caseD_a;
  case 0xb:
    goto switchD_001288f0_caseD_b;
  case 0xc:
switchD_001288f0_caseD_c:
    uVar4 = 3;
  default:
    goto switchD_001288f0_default;
  }
  uVar4 = 10;
  goto switchD_001288f0_default;
switchD_001288f0_caseD_b:
  uVar4 = 9;
  goto switchD_001288f0_default;
switchD_001288f0_caseD_0:
  uVar3 = (ulong)param_1[8];
LAB_00128974:
  *param_2 = uVar3;
  uVar2 = 1;
switchD_001288f0_caseD_a:
  return uVar2;
}


/* EXPORT index=217 ELF_VA=0x289d0 size=248 source_sha256=7dea09483335cf3e9c6e958ca5e0d5a8109b61878e17cf85ce755b5bfc6b87e9 */

undefined4 j___IS_S__Il050_S0lIO_IIlI__OOI_l_5IIl__S__5__I_IlIS5_(byte *param_1,ulong *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  uVar4 = 0xb;
switchD_00128a30_default:
  uVar2 = 0;
  switch(uVar4) {
  case 0:
    goto switchD_00128a30_caseD_0;
  case 1:
    uVar3 = (ulong)*(ushort *)(param_1 + 8);
    goto LAB_00128ab4;
  case 2:
    uVar3 = *(ulong *)(param_1 + 8);
    goto LAB_00128ab4;
  case 3:
switchD_00128a30_caseD_3:
    uVar4 = 0;
    goto switchD_00128a30_default;
  case 4:
    uVar3 = (ulong)*(uint *)(param_1 + 8);
    goto LAB_00128ab4;
  case 5:
switchD_00128a30_caseD_5:
    uVar4 = 2;
    goto switchD_00128a30_default;
  case 6:
switchD_00128a30_caseD_6:
    uVar4 = 4;
    goto switchD_00128a30_default;
  case 8:
    uVar4 = 1;
    goto switchD_00128a30_default;
  case 9:
    bVar1 = *param_1;
    if (bVar1 < 0xe) {
      if (bVar1 == 0) goto switchD_00128a30_caseD_c;
    }
    else {
      uVar4 = 1;
      switch(bVar1) {
      case 0xe:
        goto switchD_00128a30_caseD_3;
      case 0xf:
        goto switchD_00128a30_default;
      case 0x10:
        goto switchD_00128a30_caseD_6;
      case 0x11:
        goto switchD_00128a30_caseD_5;
      }
    }
    break;
  case 10:
  case 0xd:
    goto switchD_00128a30_caseD_a;
  case 0xb:
    goto switchD_00128a30_caseD_b;
  case 0xc:
switchD_00128a30_caseD_c:
    uVar4 = 3;
  default:
    goto switchD_00128a30_default;
  }
  uVar4 = 10;
  goto switchD_00128a30_default;
switchD_00128a30_caseD_b:
  uVar4 = 9;
  goto switchD_00128a30_default;
switchD_00128a30_caseD_0:
  uVar3 = (ulong)param_1[8];
LAB_00128ab4:
  *param_2 = uVar3;
  uVar2 = 1;
switchD_00128a30_caseD_a:
  return uVar2;
}


/* EXPORT index=218 ELF_VA=0x28b10 size=36 source_sha256=7bf63e9f432c542e46bf49da186302ec6bdb2c3adf6542c963081bb3924fc3f9 */

undefined8 j___I5SIl_055OS_lS_l__5IOI5_IOI5I5l5I5lOIII00O5IOI0S5_(char *param_1,undefined4 *param_2)

{
  if (*param_1 == '\f') {
    *param_2 = *(undefined4 *)(param_1 + 8);
    return 1;
  }
  return 0;
}


/* EXPORT index=219 ELF_VA=0x28b34 size=36 source_sha256=84901472d24edc0f5d2a333b9903c6562f89e0b0083555f060b562f68d28a250 */

undefined8 j___IOlIl_S_SSl_l__II__IS0S_l0SIl___I__O0Il__5lI_lIS5_(char *param_1,undefined8 *param_2)

{
  if (*param_1 == '\r') {
    *param_2 = *(undefined8 *)(param_1 + 8);
    return 1;
  }
  return 0;
}


/* EXPORT index=220 ELF_VA=0x28b58 size=136 source_sha256=70424d9b1e483133f1176399f9d927506ff7d72944a434ab1fe99d7e82ed01dd */

undefined4 j___O5IlI___lSI_I_I0__IlOIl_lI_I0_II____0ISOO0Il_O_S5_(char *param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  do {
    switch(uVar1) {
    case 0:
      uVar1 = 4;
      if (*param_1 != '\x05') {
        uVar1 = 5;
      }
      break;
    case 1:
      return 1;
    case 2:
      *param_2 = 0;
      uVar1 = 1;
      break;
    case 3:
      uVar1 = 1;
      *param_2 = 1;
      break;
    case 4:
      uVar1 = 2;
      if (param_1[8] != '\0') {
        uVar1 = 3;
      }
      break;
    case 5:
      return 0;
    default:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  } while( true );
}


/* EXPORT index=221 ELF_VA=0x28bf8 size=268 source_sha256=be394730341d72ca79b35751085fdaba739eca34046f79bb90ab0558e84f4bdd */

/* WARNING: Removing unreachable block (ram,0x00128cb8) */

undefined4 j___O_O5l_O_OSI_Il_OS_SlSS5_l0II055_0SIIII5O50OI_IOS5_(byte *param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 3;
switchD_00128c60_caseD_4:
  iVar3 = iVar4;
  uVar2 = 0;
  iVar4 = 2;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(iVar3) {
  case 0:
    bVar1 = *param_1;
    if (bVar1 < 0x1b) {
      if (bVar1 == 3) goto switchD_00128c60_caseD_8;
    }
    else {
      iVar4 = 2;
      if (bVar1 == 0x1d) goto switchD_00128c60_caseD_4;
      if (bVar1 == 0x1b) goto switchD_00128c60_caseD_1;
      if (bVar1 == 0x1c) goto switchD_00128c60_caseD_5;
    }
switchD_00128c60_caseD_7:
    iVar4 = 6;
LAB_00128cd0:
    if (iVar4 == 9) {
      return 0;
    }
    goto switchD_00128c60_caseD_4;
  case 1:
switchD_00128c60_caseD_1:
    iVar4 = 5;
    goto switchD_00128c60_caseD_4;
  case 2:
    goto switchD_00128c60_caseD_2;
  case 3:
    goto switchD_00128c60_caseD_3;
  case 4:
    goto switchD_00128c60_caseD_4;
  case 5:
switchD_00128c60_caseD_5:
    iVar4 = 4;
    goto switchD_00128c60_caseD_4;
  case 6:
  case 9:
    goto switchD_00128c60_caseD_6;
  case 7:
    goto switchD_00128c60_caseD_7;
  case 8:
switchD_00128c60_caseD_8:
                    /* WARNING: This code block may not be properly labeled as switch case */
    iVar4 = 1;
    goto LAB_00128cd0;
  default:
    break;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_00128c60_caseD_3:
  iVar4 = 0;
  goto switchD_00128c60_caseD_4;
switchD_00128c60_caseD_2:
  *param_2 = *(undefined4 *)(param_1 + 8);
  uVar2 = 1;
switchD_00128c60_caseD_6:
                    /* WARNING: This code block may not be properly labeled as switch case */
  return uVar2;
}


/* EXPORT index=222 ELF_VA=0x28d2c size=216 source_sha256=2c90809e6c017b90b503d354734099e7c0c5c8ca25a36181867d00b0fe84f159 */

/* WARNING: Removing unreachable block (ram,0x00128db4) */

undefined4 j___I5O_l_I_ISl_I_Il___0_lO_lII5lO_OlOI_0O_OI_I_l0lS5_(char *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = 0;
switchD_00128dd4_caseD_0:
  while( true ) {
    do {
      do {
        iVar4 = iVar2;
        iVar2 = 1;
      } while (iVar4 == 6);
      if (iVar4 != 3) {
        if (iVar4 == 4) goto LAB_00128da0;
        goto code_r0x00128dc0;
      }
      cVar1 = *param_1;
      iVar2 = 1;
    } while (cVar1 == '\a');
    if (cVar1 != '\x06') break;
LAB_00128da0:
    iVar2 = 6;
  }
  if (cVar1 == '\b') goto switchD_00128dd4_caseD_1;
  goto switchD_00128dd4_caseD_2;
code_r0x00128dc0:
  uVar3 = 0;
  iVar2 = 3;
  switch(iVar4) {
  case 0:
    break;
  case 1:
switchD_00128dd4_caseD_1:
    iVar2 = 5;
    break;
  case 2:
switchD_00128dd4_caseD_2:
    iVar2 = 7;
    break;
  default:
    do {
    } while( true );
  case 5:
    *param_2 = *(undefined4 *)(param_1 + 8);
    uVar3 = 1;
  case 7:
    return uVar3;
  }
  goto switchD_00128dd4_caseD_0;
}


/* EXPORT index=223 ELF_VA=0x28e28 size=204 source_sha256=5505546f03c44e36fc4ea826c3c940a8438d7ac16b583d2de70b6f74585f2633 */

/* WARNING: Removing unreachable block (ram,0x00128ee4) */

undefined4 j___OSlO__ll_l5_ll_O__IS5II_IIIl55IS_IlIlS5III_l00IS5_(char *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = 7;
switchD_00128e7c_caseD_3:
  uVar3 = uVar2;
  uVar2 = 4;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(uVar3) {
  case 0:
    goto switchD_00128e7c_caseD_0;
  case 1:
  case 8:
    goto switchD_00128e7c_caseD_1;
  case 2:
code_r0x00128eb4:
    uVar2 = 1;
  case 3:
    goto switchD_00128e7c_caseD_3;
  case 4:
    *param_2 = *(undefined4 *)(param_1 + 8);
    return 1;
  case 5:
    cVar1 = *param_1;
    uVar2 = 4;
    if (cVar1 == '\x1f') goto switchD_00128e7c_caseD_3;
    if (cVar1 != '\x02') {
      uVar2 = 3;
      if (cVar1 != '\x1e') goto code_r0x00128eb4;
      goto switchD_00128e7c_caseD_3;
    }
switchD_00128e7c_caseD_0:
    uVar2 = 6;
    goto switchD_00128e7c_caseD_3;
  case 6:
    uVar2 = 3;
    goto switchD_00128e7c_caseD_3;
  case 7:
    goto switchD_00128e7c_caseD_7;
  default:
    break;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_00128e7c_caseD_7:
  uVar2 = 5;
  goto switchD_00128e7c_caseD_3;
switchD_00128e7c_caseD_1:
                    /* WARNING: This code block may not be properly labeled as switch case */
  return 0;
}


/* EXPORT index=224 ELF_VA=0x28f18 size=1252 source_sha256=8ac609ddf9829f339e6a8c326c9d4733cc41f6d15ebfc224bb7b9c0aa25f1afa */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___OIlS__llOII_IlIll_lIl55_0_0IS_lI5OIIlI5_lI5I0_0S5_
               (char *param_1,undefined4 *param_2,ulong param_3,ulong param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  byte bVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 auStack_110 [32];
  byte abStack_90 [40];
  long lStack_68;
  
  uVar9 = 0x5081;
  iVar8 = 1;
  uVar10 = 0xf988b7bc;
  lStack_68 = ___stack_chk_guard;
  abStack_90[0x12] = 0x55;
  abStack_90[0x13] = 0x14;
  abStack_90[0x14] = 0x72;
  abStack_90[0x15] = 5;
  abStack_90[0x16] = 0x5c;
  abStack_90[0x17] = 0x7d;
  abStack_90[0x18] = 0x25;
  abStack_90[0x19] = 0x55;
  abStack_90[0x10] = 0x15;
  abStack_90[0x11] = 0x19;
  abStack_90[8] = 0x18;
  abStack_90[9] = 0x5c;
  abStack_90[10] = 0x27;
  abStack_90[0xb] = 99;
  abStack_90[0xc] = 0x73;
  abStack_90[0xd] = 0x4e;
  abStack_90[0xe] = 0x36;
  abStack_90[0xf] = 0x42;
  abStack_90[0] = 0x7d;
  abStack_90[1] = 0x7f;
  abStack_90[2] = 0x5a;
  abStack_90[3] = 6;
  abStack_90[4] = 3;
  abStack_90[5] = 0x3c;
  abStack_90[6] = 0x35;
  abStack_90[7] = 0x67;
  puVar7 = param_2;
switchD_00129018_default:
  uVar6 = 0;
  bVar5 = (byte)uVar10;
  switch(iVar8) {
  case 0:
    uVar10 = uVar10 << 2;
    iVar8 = 0x11;
    goto switchD_00129018_default;
  case 1:
    iVar8 = 0xe;
    goto switchD_00129018_default;
  case 2:
    uVar1 = uVar10 + 0x41c0a79e;
    abStack_90[uVar10 + 0x41c0a7a5] = abStack_90[uVar10 + 0x41c0a7a5] ^ bVar5 + 6;
    abStack_90[uVar10 + 0x41c0a7a1] = abStack_90[uVar10 + 0x41c0a7a1] ^ bVar5 - 0x1c;
    abStack_90[uVar10 + 0x41c0a7aa] = bVar5 ^ abStack_90[uVar10 + 0x41c0a7aa] ^ 0x32;
    abStack_90[uVar10 ^ 0xbe3f5863] = bVar5 ^ abStack_90[uVar10 ^ 0xbe3f5863] ^ 10;
    uVar10 = uVar10 * 2;
    abStack_90[uVar1] = bVar5 ^ abStack_90[uVar1] ^ 0x79;
    abStack_90[uVar10 ^ 0x7c7eb0c9] = abStack_90[uVar10 ^ 0x7c7eb0c9] ^ (char)uVar10 + 0x89U;
    iVar8 = (6 - uVar9) + (uVar9 / 3) * 3;
    goto switchD_00129018_default;
  case 3:
    goto switchD_00129018_caseD_3;
  case 4:
    uVar1 = uVar10 + 0x5153db97;
    abStack_90[uVar10 + 0x5153dbab] = abStack_90[uVar10 + 0x5153dbab] ^ bVar5 - 0x15;
    abStack_90[uVar10 ^ 0xaeac247e] = bVar5 ^ abStack_90[uVar10 ^ 0xaeac247e] ^ 0x7a;
    abStack_90[uVar10 + 0x5153dba3] = bVar5 ^ abStack_90[uVar10 + 0x5153dba3] ^ 0x3b;
    uVar10 = uVar10 * 2;
    abStack_90[uVar1] = bVar5 ^ abStack_90[uVar1] ^ 0x22;
    abStack_90[uVar10 ^ 0x5d5848cd] = abStack_90[uVar10 ^ 0x5d5848cd] ^ (char)uVar10 + 0x46U;
    abStack_90[uVar10 ^ 0x5d5848da] = abStack_90[uVar10 ^ 0x5d5848da] ^ (char)uVar10 + 0x3eU;
    iVar8 = (0xd - uVar9) + (uVar9 / 3) * 3;
    goto switchD_00129018_default;
  case 5:
    uVar1 = uVar10 * 2 + 0x3d21e4c;
    uVar3 = uVar1 * uVar1 & 0xe99575f8;
    uVar2 = uVar3 + 0x36efffca;
    abStack_90[uVar1 ^ 0xfccf7ff1] = abStack_90[uVar1 ^ 0xfccf7ff1] ^ (char)(uVar10 * 2) + 0xb9U;
    uVar10 = uVar3 + 0x6d8869ee;
    abStack_90[uVar2] = (byte)uVar10 ^ abStack_90[uVar2] ^ 0x38;
    iVar8 = 9;
    goto switchD_00129018_default;
  case 7:
  case 0x12:
    goto switchD_00129018_caseD_7;
  case 8:
  case 0xd:
  case 0x11:
    cVar4 = *param_1;
    if (cVar4 == '\x01') goto switchD_00129018_caseD_b;
    if (cVar4 != ' ') {
      if (cVar4 != '!') goto switchD_00129018_caseD_10;
      goto switchD_00129018_caseD_f;
    }
    break;
  case 9:
    abStack_90[uVar10 ^ 0x36986a20] = abStack_90[uVar10 ^ 0x36986a20] ^ bVar5 - 0x2a;
    abStack_90[uVar10 ^ 0x36986a2e] = bVar5 ^ abStack_90[uVar10 ^ 0x36986a2e] ^ 0x65;
    abStack_90[uVar10 + 0xc96795dd] = bVar5 ^ abStack_90[uVar10 + 0xc96795dd] ^ 0x60;
    abStack_90[uVar10 + 0xc96795db] = abStack_90[uVar10 + 0xc96795db] ^ bVar5 + 0x27;
    param_3 = (ulong)(uVar10 ^ 0xb96d6a64);
    abStack_90[uVar10 + 0xc96795ea] = abStack_90[uVar10 + 0xc96795ea] ^ bVar5 + 0x1d;
    param_4 = (ulong)(uVar10 + 0x538af58c);
    abStack_90[uVar10 + 0xc96795d3] = bVar5 ^ abStack_90[uVar10 + 0xc96795d3] ^ 0x7b;
    do {
      puVar7 = auStack_110;
      CallSupervisor(0);
    } while (&stack0x00000000 == (undefined1 *)0x8c);
    iVar8 = 0;
    goto switchD_00129018_default;
  case 10:
    uVar9 = 0x1c45;
    iVar8 = 4;
    uVar10 = 0xaeac246c;
    goto switchD_00129018_default;
  case 0xb:
switchD_00129018_caseD_b:
    iVar8 = 6;
    goto switchD_00129018_default;
  case 0xc:
    abStack_90[uVar10 ^ 0x5d5848de] = abStack_90[uVar10 ^ 0x5d5848de] ^ bVar5 + 0x2c;
    abStack_90[uVar10 ^ 0x5d5848c8] = abStack_90[uVar10 ^ 0x5d5848c8] ^ bVar5 + 0x73;
    abStack_90[uVar10 ^ 0x5d5848d5] = bVar5 ^ abStack_90[uVar10 ^ 0x5d5848d5] ^ 0xc6;
    uVar9 = uVar10 ^ 0x5d5848ce;
    abStack_90[uVar10 + 0xa2a7b73b] = abStack_90[uVar10 + 0xa2a7b73b] ^ bVar5 + 0x76;
    uVar10 = uVar10 ^ 0xe36710bf;
    abStack_90[uVar9] = abStack_90[uVar9] ^ bVar5 + 0x2c;
    uVar9 = 0x512e;
    abStack_90[uVar10 + 0x41c0a7ad] = bVar5 ^ abStack_90[uVar10 + 0x41c0a7ad] ^ 0xb5;
    iVar8 = 2;
    goto switchD_00129018_default;
  case 0xe:
    goto switchD_00129018_caseD_e;
  case 0xf:
switchD_00129018_caseD_f:
    iVar8 = 3;
    goto switchD_00129018_default;
  case 0x10:
switchD_00129018_caseD_10:
    iVar8 = 7;
  default:
    goto switchD_00129018_default;
  }
  iVar8 = 0xf;
  goto switchD_00129018_default;
switchD_00129018_caseD_e:
  iVar8 = 8;
  goto switchD_00129018_default;
switchD_00129018_caseD_3:
  *param_2 = *(undefined4 *)(param_1 + 8);
  uVar6 = 1;
switchD_00129018_caseD_7:
  if (___stack_chk_guard != lStack_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6,puVar7,param_3,param_4);
  }
  return;
}


/* EXPORT index=225 ELF_VA=0x29448 size=196 source_sha256=f0f29e3fb2dadf751cb2b48116ab21f11763aad44e1b3c065af299602793ea8a */

undefined4
j___lSI5S_IIIl5_SO__I_llO5I___S_O__I_IlIlOO0O_SlOIOS5_
          (byte *param_1,byte *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
switchD_001294a0_default:
  uVar1 = 0;
  switch(uVar2) {
  case 1:
    uVar2 = 9;
    goto switchD_001294a0_default;
  case 2:
    uVar2 = 7;
    goto switchD_001294a0_default;
  case 3:
    goto switchD_001294a0_caseD_3;
  case 4:
    uVar2 = 5;
    goto switchD_001294a0_default;
  case 5:
    uVar2 = 10;
    goto switchD_001294a0_default;
  case 6:
    uVar2 = 0xb;
    goto switchD_001294a0_default;
  case 7:
    uVar2 = 6;
    goto switchD_001294a0_default;
  case 8:
    uVar2 = 4;
    goto switchD_001294a0_default;
  case 9:
    if (*param_1 - 9 < 0x12) {
      uVar2 = *(undefined4 *)(&DAT_00174cc0 + (long)(int)(*param_1 - 9) * 4);
      goto switchD_001294a0_default;
    }
    break;
  case 10:
    uVar2 = 2;
    goto switchD_001294a0_default;
  case 0xb:
    goto switchD_001294a0_caseD_b;
  case 0xc:
    goto switchD_001294a0_caseD_c;
  default:
    goto switchD_001294a0_default;
  }
  uVar2 = 0xc;
  goto switchD_001294a0_default;
switchD_001294a0_caseD_b:
  uVar2 = 3;
  goto switchD_001294a0_default;
switchD_001294a0_caseD_3:
  *param_2 = param_1[8];
  *param_3 = *(undefined4 *)(param_1 + 0xc);
  uVar1 = 1;
switchD_001294a0_caseD_c:
  return uVar1;
}


/* EXPORT index=226 ELF_VA=0x29540 size=328 source_sha256=7e569dbbabfad2007f01159027ae4f92cb71e51446b3113eed8c77a5dc99813a */

undefined8
j___I00_0__SS0I__0SII_O__Il_II__llI5llIOISlS_llIl5OS5_
          (undefined1 *param_1,byte *param_2,long param_3,uint param_4)

{
  byte bVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  uint unaff_w28;
  
  uVar5 = 5;
switchD_001295b4_default:
  uVar2 = 0;
  switch(uVar5) {
  case 1:
    uVar3 = (**(code **)(param_1 + 0x10))(param_1,param_3,unaff_w28);
    uVar5 = 9;
    if ((uVar3 & 1) == 0) {
      uVar5 = 4;
    }
    goto switchD_001295b4_default;
  case 2:
switchD_001295b4_caseD_2:
    uVar5 = 0;
    goto switchD_001295b4_default;
  case 3:
  case 9:
    goto switchD_001295b4_caseD_3;
  case 4:
    uVar4 = 9;
    goto LAB_00129664;
  case 5:
    unaff_w28 = 0;
    uVar5 = 0xb;
    goto switchD_001295b4_default;
  case 6:
switchD_001295b4_caseD_6:
    uVar5 = 2;
    goto switchD_001295b4_default;
  case 7:
    unaff_w28 = *(uint *)(param_2 + 8);
    uVar5 = 0xc;
    if (unaff_w28 + 1 <= param_4) {
      uVar5 = 1;
    }
    goto switchD_001295b4_default;
  case 8:
switchD_001295b4_caseD_8:
    uVar5 = 10;
    goto switchD_001295b4_default;
  case 10:
    goto switchD_001295b4_caseD_a;
  case 0xb:
    bVar1 = *param_2;
    if (bVar1 < 0x1b) {
      if (bVar1 == 3) goto switchD_001295b4_caseD_d;
      goto switchD_001295b4_caseD_8;
    }
    if (bVar1 == 0x1b) goto switchD_001295b4_caseD_6;
    if (bVar1 == 0x1c) goto switchD_001295b4_caseD_2;
    if (bVar1 != 0x1d) goto switchD_001295b4_caseD_8;
    break;
  case 0xc:
    uVar4 = 1;
LAB_00129664:
    *param_1 = uVar4;
    return 0;
  case 0xd:
    goto switchD_001295b4_caseD_d;
  default:
    goto switchD_001295b4_default;
  }
  uVar5 = 7;
  goto switchD_001295b4_default;
switchD_001295b4_caseD_d:
  uVar5 = 6;
  goto switchD_001295b4_default;
switchD_001295b4_caseD_3:
  *(undefined1 *)(param_3 + (ulong)unaff_w28) = 0;
  uVar2 = 1;
switchD_001295b4_caseD_a:
  return uVar2;
}


/* EXPORT index=227 ELF_VA=0x296c0 size=316 source_sha256=125b309a8e506cbe630dd091c3856409f17e0dca56a6319943be541c5e977de5 */

undefined8
j___lI5II_OIIOI_lI_l__0_l5__lI0SI_IO05_I05_II0lIOl5S5_
          (undefined1 *param_1,char *param_2,undefined8 param_3,uint param_4)

{
  char cVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined4 uVar4;
  uint unaff_w24;
  
  uVar4 = 5;
switchD_00129738_default:
  uVar2 = 1;
  switch(uVar4) {
  case 0:
    unaff_w24 = *(uint *)(param_2 + 8);
    uVar4 = 9;
    if (unaff_w24 <= param_4) {
      uVar4 = 1;
    }
    goto switchD_00129738_default;
  case 1:
    uVar3 = (**(code **)(param_1 + 0x10))(param_1,param_3,unaff_w24);
    uVar4 = 6;
    if ((uVar3 & 1) != 0) {
      uVar4 = 7;
    }
    goto switchD_00129738_default;
  case 3:
switchD_00129738_caseD_3:
    uVar4 = 0;
    goto switchD_00129738_default;
  case 4:
switchD_00129738_caseD_4:
    uVar4 = 3;
    goto switchD_00129738_default;
  case 5:
    unaff_w24 = 0;
    uVar4 = 8;
    goto switchD_00129738_default;
  case 6:
    goto switchD_00129738_caseD_6;
  case 7:
  case 0xc:
    goto switchD_00129738_caseD_7;
  case 8:
    cVar1 = *param_2;
    if (cVar1 == '\x06') goto switchD_00129738_caseD_b;
    if (cVar1 == '\a') goto switchD_00129738_caseD_4;
    if (cVar1 == '\b') goto switchD_00129738_caseD_3;
    break;
  case 9:
    *param_1 = 2;
    return 0;
  case 10:
    return 0;
  case 0xb:
    goto switchD_00129738_caseD_b;
  default:
    goto switchD_00129738_default;
  }
  uVar4 = 10;
  goto switchD_00129738_default;
switchD_00129738_caseD_b:
  uVar4 = 4;
  goto switchD_00129738_default;
switchD_00129738_caseD_6:
  uVar2 = 0;
  *param_1 = 9;
switchD_00129738_caseD_7:
  return uVar2;
}


/* EXPORT index=228 ELF_VA=0x29830 size=412 source_sha256=598e3156f941b796f9b8d61000bc630cb2f5faa6c93e0db9a9d13950a54d2ebb */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void createNoClassDefFoundError(_jclass *param_1,undefined8 param_2)

{
  _jmethodID *p_Var1;
  undefined8 uVar2;
  undefined8 uVar3;
  char acStack_70 [12];
  uint uStack_64;
  char acStack_60 [24];
  long lStack_48;
  
  lStack_48 = ___stack_chk_guard;
  builtin_strncpy(acStack_70,"Fsxs~H",7);
  uStack_64 = 0;
  do {
    acStack_70[(int)uStack_64] = acStack_70[(int)uStack_64] + -10;
    uStack_64 = uStack_64 + 1;
  } while (uStack_64 < 6);
  acStack_60[0] = '2';
  acStack_60[1] = 'V';
  acStack_60[2] = 't';
  acStack_60[3] = 'k';
  acStack_60[4] = -0x80;
  acStack_60[5] = 'k';
  acStack_60[6] = '9';
  acStack_60[7] = 'v';
  acStack_60[8] = 'k';
  acStack_60[9] = 'x';
  acStack_60[10] = 'q';
  acStack_60[0xb] = '9';
  acStack_60[0xc] = ']';
  acStack_60[0xd] = '~';
  acStack_60[0xe] = '|';
  acStack_60[0xf] = 's';
  acStack_60[0x10] = 'x';
  acStack_60[0x11] = 'q';
  acStack_60[0x12] = 'E';
  acStack_60[0x13] = '3';
  acStack_60[0x14] = '`';
  acStack_60[0x15] = '\0';
  uStack_64 = 0;
  do {
    acStack_60[(int)uStack_64] = acStack_60[(int)uStack_64] + -10;
    uStack_64 = uStack_64 + 1;
  } while (uStack_64 < 0x15);
  uVar2 = (**(code **)(*(long *)param_1 + 0x108))(param_1,DAT_0018dd88,acStack_70,acStack_60);
  p_Var1 = DAT_0018dd88;
  uVar3 = (**(code **)(*(long *)param_1 + 0x538))(param_1,param_2);
  _JNIEnv::NewObject(param_1,p_Var1,uVar2,uVar3);
  if (___stack_chk_guard != lStack_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* EXPORT index=229 ELF_VA=0x299cc size=124 source_sha256=706aecc5f3de24e23e5857282b7de9c1b55dc738ed58d5ffd770e8e95ea34f2e */

/* _JNIEnv::NewObject(_jclass*, _jmethodID*, ...) */

void _JNIEnv::NewObject(_jclass *param_1,_jmethodID *param_2,...)

{
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined1 auStack_90 [8];
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined1 *puStack_60;
  undefined1 **ppuStack_58;
  undefined1 *puStack_50;
  undefined8 uStack_48;
  
  puStack_50 = auStack_90;
  ppuStack_58 = &puStack_60;
  uStack_48 = 0xffffff80ffffffd8;
  uStack_88 = in_x3;
  uStack_80 = in_x4;
  uStack_78 = in_x5;
  uStack_70 = in_x6;
  uStack_68 = in_x7;
  puStack_60 = (undefined1 *)register0x00000008;
  (**(code **)(*(long *)param_1 + 0xe8))();
  return;
}


/* EXPORT index=230 ELF_VA=0x29a48 size=528 source_sha256=7561da85de126a6f856d7c8ae3fb0089e6362a0c13ec63ad51322dbbfc608b52 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void readThrowableMessage(_jobject *param_1,_jmethodID *param_2,char *param_3)

{
  undefined8 uVar1;
  char *__src;
  uint uStack_64;
  undefined1 auStack_60 [24];
  undefined8 uStack_48;
  uint uStack_40;
  long lStack_38;
  
  lStack_38 = ___stack_chk_guard;
  uStack_48 = 0x414255625a484b2c;
  uStack_40 = 0x505352;
  uStack_64 = 0;
  do {
    *(byte *)((long)&uStack_48 + (long)(int)uStack_64 + 1) =
         (char)uStack_64 + 0x2cU ^ *(byte *)((long)&uStack_48 + (long)(int)uStack_64 + 1);
    uStack_64 = uStack_64 + 1;
  } while (uStack_64 < 10);
  uStack_40 = uStack_40 & 0xffffff;
  auStack_60[0] = 0x28;
  auStack_60[1] = 0x29;
  auStack_60[2] = 0x4c;
  auStack_60[3] = 0x6a;
  auStack_60[4] = 0x61;
  auStack_60[5] = 0x76;
  auStack_60[6] = 0x61;
  auStack_60[7] = 0x2f;
  auStack_60[8] = 0x6c;
  auStack_60[9] = 0x61;
  auStack_60[10] = 0x6e;
  auStack_60[0xb] = 0x67;
  auStack_60[0xc] = 0x2f;
  auStack_60[0xd] = 0x53;
  auStack_60[0xe] = 0x74;
  auStack_60[0xf] = 0x72;
  auStack_60[0x10] = 0x69;
  auStack_60[0x11] = 0x6e;
  auStack_60[0x12] = 0x67;
  auStack_60[0x13] = 0x3b;
  auStack_60[0x14] = 0;
  uStack_64 = 0;
  do {
    auStack_60[(int)uStack_64] = auStack_60[(int)uStack_64];
    uStack_64 = uStack_64 + 1;
  } while (uStack_64 < 0x14);
  uVar1 = (**(code **)(*(long *)param_1 + 0x108))
                    (param_1,DAT_0018dd88,(ulong)&uStack_48 | 1,auStack_60);
  uVar1 = _JNIEnv::CallObjectMethod(param_1,param_2,uVar1);
  __src = (char *)(**(code **)(*(long *)param_1 + 0x548))(param_1,uVar1,0);
  strncpy(param_3,__src,100);
  (**(code **)(*(long *)param_1 + 0xb8))(param_1,uVar1);
  if (___stack_chk_guard != lStack_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* EXPORT index=231 ELF_VA=0x29c58 size=124 source_sha256=ed9cf4f2a7a24bea9cf6e324af23ae7dc2e9be61912b236541122fd9f50a3cd1 */

/* _JNIEnv::CallObjectMethod(_jobject*, _jmethodID*, ...) */

void _JNIEnv::CallObjectMethod(_jobject *param_1,_jmethodID *param_2,...)

{
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined1 auStack_90 [8];
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined1 *puStack_60;
  undefined1 **ppuStack_58;
  undefined1 *puStack_50;
  undefined8 uStack_48;
  
  puStack_50 = auStack_90;
  ppuStack_58 = &puStack_60;
  uStack_48 = 0xffffff80ffffffd8;
  uStack_88 = in_x3;
  uStack_80 = in_x4;
  uStack_78 = in_x5;
  uStack_70 = in_x6;
  uStack_68 = in_x7;
  puStack_60 = (undefined1 *)register0x00000008;
  (**(code **)(*(long *)param_1 + 0x118))();
  return;
}


/* EXPORT index=233 ELF_VA=0x670b8 size=124 source_sha256=322db316310c7b0d364c9ea22244949d17cc73016d0f3912ba3588fad9802ebb */

/* _JNIEnv::CallVoidMethod(_jobject*, _jmethodID*, ...) */

void _JNIEnv::CallVoidMethod(_jobject *param_1,_jmethodID *param_2,...)

{
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined1 auStack_90 [8];
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined1 *puStack_60;
  undefined1 **ppuStack_58;
  undefined1 *puStack_50;
  undefined8 uStack_48;
  
  puStack_50 = auStack_90;
  ppuStack_58 = &puStack_60;
  uStack_48 = 0xffffff80ffffffd8;
  uStack_88 = in_x3;
  uStack_80 = in_x4;
  uStack_78 = in_x5;
  uStack_70 = in_x6;
  uStack_68 = in_x7;
  puStack_60 = (undefined1 *)register0x00000008;
  (**(code **)(*(long *)param_1 + 0x1f0))();
  return;
}


/* EXPORT index=234 ELF_VA=0x67b14 size=124 source_sha256=e584f08621f5ba4ec1561e80b8fd4a5902ccb210edc32be72f714a22ad499aae */

/* _JNIEnv::CallStaticBooleanMethod(_jclass*, _jmethodID*, ...) */

void _JNIEnv::CallStaticBooleanMethod(_jclass *param_1,_jmethodID *param_2,...)

{
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined1 auStack_90 [8];
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined1 *puStack_60;
  undefined1 **ppuStack_58;
  undefined1 *puStack_50;
  undefined8 uStack_48;
  
  puStack_50 = auStack_90;
  ppuStack_58 = &puStack_60;
  uStack_48 = 0xffffff80ffffffd8;
  uStack_88 = in_x3;
  uStack_80 = in_x4;
  uStack_78 = in_x5;
  uStack_70 = in_x6;
  uStack_68 = in_x7;
  puStack_60 = (undefined1 *)register0x00000008;
  (**(code **)(*(long *)param_1 + 0x3b0))();
  return;
}


/* EXPORT index=235 ELF_VA=0x67eb0 size=124 source_sha256=812b9a196f5b164d271b7df62f103bf3bfe1b96e0c1ba18bde9c1923a63e95dc */

/* _JNIEnv::CallStaticObjectMethod(_jclass*, _jmethodID*, ...) */

void _JNIEnv::CallStaticObjectMethod(_jclass *param_1,_jmethodID *param_2,...)

{
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined1 auStack_90 [8];
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined1 *puStack_60;
  undefined1 **ppuStack_58;
  undefined1 *puStack_50;
  undefined8 uStack_48;
  
  puStack_50 = auStack_90;
  ppuStack_58 = &puStack_60;
  uStack_48 = 0xffffff80ffffffd8;
  uStack_88 = in_x3;
  uStack_80 = in_x4;
  uStack_78 = in_x5;
  uStack_70 = in_x6;
  uStack_68 = in_x7;
  puStack_60 = (undefined1 *)register0x00000008;
  (**(code **)(*(long *)param_1 + 0x398))();
  return;
}


/* EXPORT index=236 ELF_VA=0x6809c size=1200 source_sha256=13aade2d9d48656041a5b0fcb4a2456f15658c1229c90f29d5398e746226c48e */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff00 : 0x00168518 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* WARNING: Exceeded maximum restarts with more pending */

undefined4
j___l__5S_IOIII_l_l50_5I_SI_Il0I5__I5_OOlIllII_l_O_S5_
          (long *param_1,undefined8 param_2,undefined8 *param_3)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  size_t sVar7;
  size_t sVar8;
  uint uVar9;
  uint uVar10;
  long unaff_x26;
  long unaff_x27;
  char *pcVar11;
  undefined4 uStack_11c;
  long lStack_108;
  int iStack_f4;
  char cStack_e8;
  undefined1 auStack_e7 [135];
  
  lVar3 = ___stack_chk_guard;
  uVar10 = 0x1adb;
  lStack_108 = 0;
  uStack_11c = 0;
  iStack_f4 = 0xb;
  iVar6 = 0xb;
  do {
    switch(iVar6) {
    case 0:
    case 5:
      uStack_11c = 0;
switchD_00168168_caseD_c:
      if (___stack_chk_guard != lVar3) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return uStack_11c;
    case 1:
      lStack_108 = (**(code **)(*param_1 + 0x2f0))(param_1,unaff_x26,param_3[2],param_3[1]);
      if (lStack_108 == 0) {
        lStack_108 = 0;
        iVar6 = 5;
        iStack_f4 = 5;
      }
      else {
        iVar6 = 9;
        iStack_f4 = 9;
      }
      break;
    case 2:
      (**(code **)(*param_1 + 0x88))(param_1);
      if (unaff_x27 == 0) {
        iVar6 = 0;
        unaff_x27 = 0;
        iStack_f4 = 0;
      }
      else {
        iVar6 = 3;
        iStack_f4 = 3;
      }
      break;
    case 3:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      iVar6 = 0;
      iStack_f4 = 0;
      break;
    case 4:
      if (unaff_x27 == 0) {
        unaff_x27 = 0;
        iStack_f4 = 1 - uVar10 % 5;
        iVar6 = iStack_f4;
      }
      else {
        iStack_f4 = 7 - uVar10 % 5;
        iVar6 = iStack_f4;
      }
      break;
    case 6:
      if (iStack_f4 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      iStack_f4 = (0x50 - uVar10) + (uVar10 / 0x61) * 0x61;
      iVar6 = iStack_f4;
      break;
    case 7:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      iStack_f4 = 1;
      iVar6 = 1;
      break;
    case 8:
      memset(&cStack_e8,0,0x80);
      pcVar11 = (char *)param_3[1];
      sVar7 = strlen(pcVar11);
      strncpy(&cStack_e8,pcVar11,sVar7 - 1);
      unaff_x27 = (**(code **)(*param_1 + 0x30))(param_1,auStack_e7);
      cVar5 = (**(code **)(*param_1 + 0x720))(param_1);
      iStack_f4 = 2;
      if (cVar5 != '\x01') {
        iStack_f4 = 4;
      }
      uVar10 = 0x7b4d;
      iVar6 = iStack_f4;
      break;
    case 9:
      uStack_11c = (**(code **)(*param_1 + 0x300))(param_1,param_2,lStack_108);
      iStack_f4 = 6;
      if (unaff_x26 != 0) {
        iStack_f4 = 10;
      }
      uVar10 = 0x521c;
      iVar6 = iStack_f4;
      break;
    case 10:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x26);
      iStack_f4 = 0xc;
      iVar6 = 0xc;
      break;
    case 0xb:
      unaff_x26 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      pcVar11 = (char *)param_3[1];
LAB_00168360:
      do {
        lVar2 = DAT_0018eaf0;
        if (DAT_0018eaf0 == 0) {
          cVar5 = '\x01';
          bVar1 = (bool)ExclusiveMonitorPass(0x18eaf0,0x10);
          if (bVar1) {
            DAT_0018eaf0 = 1;
            cVar5 = ExclusiveMonitorsStatus();
          }
          if (cVar5 != '\0') goto LAB_00168360;
        }
      } while (lVar2 == 1);
      if (lVar2 != 2) {
        DAT_0018ea57 = 0;
        DAT_0018ea56 = 0x4c;
        DAT_0018eaf0 = 2;
      }
      sVar7 = strlen(&DAT_0018ea56);
      iVar6 = strncmp(pcVar11,&DAT_0018ea56,sVar7);
      if (iVar6 == 0) {
        pcVar11 = (char *)param_3[1];
LAB_001683dc:
        do {
          lVar2 = DAT_0018eae8;
          if (DAT_0018eae8 == 0) {
            cVar5 = '\x01';
            bVar1 = (bool)ExclusiveMonitorPass(0x18eae8,0x10);
            if (bVar1) {
              DAT_0018eae8 = 1;
              cVar5 = ExclusiveMonitorsStatus();
            }
            if (cVar5 != '\0') goto LAB_001683dc;
          }
        } while (lVar2 == 1);
        if (lVar2 != 2) {
          DAT_0018ea55 = 0;
          DAT_0018ea54 = 0x3b;
          DAT_0018eae8 = 2;
        }
        uVar4 = 4;
        do {
          uVar9 = uVar4;
          if (4 < uVar9) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          uVar4 = (uint)(pcVar11 != (char *)0x0) << 1;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(uVar9) {
          case 0:
            goto switchD_00168464_caseD_0;
          case 2:
            sVar7 = strlen(pcVar11);
            sVar8 = strlen(&DAT_0018ea54);
            uVar4 = 1;
            if (sVar7 <= sVar8 - 1) goto switchD_00168464_caseD_0;
          }
        } while( true );
      }
switchD_00168464_caseD_0:
      iStack_f4 = 1;
      iVar6 = 1;
      break;
    case 0xc:
    case 0xd:
      goto switchD_00168168_caseD_c;
    }
  } while( true );
}


/* EXPORT index=237 ELF_VA=0x68598 size=1052 source_sha256=8379225bc5de29feb45e615d205f85f0750485185c7bba6a5ca66f1ba0c1057c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___l00ll_00lO____O_I_IIl5__lI5ll_I_O_OIlIIO__SI5lIS5_
               (long *param_1,undefined8 param_2,undefined8 *param_3)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  size_t sVar5;
  size_t sVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  undefined8 uStack_f8;
  
  uVar8 = 0x13d6;
  iVar3 = 8;
  uStack_f8 = 0;
  do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch(iVar3) {
    case 0:
      lVar4 = (**(code **)(*param_1 + 0x2f0))(param_1,uStack_f8,param_3[2],param_3[1]);
      if (lVar4 == 0) {
        iVar3 = 0xb - uVar8 % 0x3b;
      }
      else {
        iVar3 = 4 - uVar8 % 0x3b;
      }
      break;
    case 8:
      uStack_f8 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      pcVar9 = (char *)param_3[1];
LAB_001687dc:
      do {
        lVar4 = DAT_0018eae0;
        if (DAT_0018eae0 == 0) {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(0x18eae0,0x10);
          if (bVar2) {
            DAT_0018eae0 = 1;
            cVar1 = ExclusiveMonitorsStatus();
          }
          if (cVar1 != '\0') goto LAB_001687dc;
        }
      } while (lVar4 == 1);
      if (lVar4 != 2) {
        DAT_0018ea53 = 0;
        DAT_0018ea52 = 0x4c;
        DAT_0018eae0 = 2;
      }
      sVar5 = strlen(&DAT_0018ea52);
      iVar3 = strncmp(pcVar9,&DAT_0018ea52,sVar5);
      if (iVar3 == 0) {
        pcVar9 = (char *)param_3[1];
LAB_00168854:
        do {
          lVar4 = DAT_0018ead8;
          if (DAT_0018ead8 == 0) {
            cVar1 = '\x01';
            bVar2 = (bool)ExclusiveMonitorPass(0x18ead8,0x10);
            if (bVar2) {
              DAT_0018ead8 = 1;
              cVar1 = ExclusiveMonitorsStatus();
            }
            if (cVar1 != '\0') goto LAB_00168854;
          }
        } while (lVar4 == 1);
        if (lVar4 != 2) {
          DAT_0018ea51 = 0;
          DAT_0018ea50 = 0x3b;
          DAT_0018ead8 = 2;
        }
        uVar8 = 4;
        do {
          uVar7 = uVar8;
          if (4 < uVar7) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          uVar8 = (uint)(pcVar9 != (char *)0x0) << 1;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(uVar7) {
          case 0:
            goto switchD_001688d8_caseD_0;
          case 2:
            sVar5 = strlen(pcVar9);
            sVar6 = strlen(&DAT_0018ea50);
            if (sVar5 <= sVar6 - 1) goto switchD_001688d8_caseD_0;
            uVar8 = 1;
          }
        } while( true );
      }
switchD_001688d8_caseD_0:
      iVar3 = 0;
      uVar8 = 0x2bca;
    }
  } while( true );
}


/* EXPORT index=238 ELF_VA=0x689fc size=1028 source_sha256=c0feb571d426cf91565e8db00d5df6425e48823e539b7280e95d2fac5d02e22f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
j___llSIl_lSS55_O5III_l500__III5I50_IOS_S_SO000lOSlS5_
          (long *param_1,undefined8 param_2,undefined8 *param_3)

{
  bool bVar1;
  long lVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  size_t sVar6;
  size_t sVar7;
  uint uVar8;
  char *pcVar9;
  long unaff_x27;
  undefined4 uStack_10c;
  long lStack_108;
  uint uStack_fc;
  long lStack_f8;
  char cStack_e8;
  undefined1 auStack_e7 [127];
  long lStack_68;
  
  uStack_fc = 0x565e;
  iVar5 = 0xb;
  lStack_68 = ___stack_chk_guard;
  lStack_108 = 0;
  uStack_10c = 0;
  lStack_f8 = lStack_108;
  do {
    switch(iVar5) {
    case 0:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      iVar5 = 4;
      break;
    case 1:
      (**(code **)(*param_1 + 0x88))(param_1);
      iVar5 = 0;
      if (unaff_x27 != 0) {
        iVar5 = 2;
      }
      break;
    case 2:
    case 3:
      uStack_10c = 0;
switchD_00168ab8_caseD_c:
      if (___stack_chk_guard != lStack_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return uStack_10c;
    case 4:
      lStack_108 = (**(code **)(*param_1 + 0x2f0))(param_1,lStack_f8,param_3[2],param_3[1]);
      iVar5 = 2;
      if (lStack_108 != 0) {
        iVar5 = 10;
      }
      uStack_fc = 0x2546;
      break;
    case 5:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      iVar5 = 3;
      break;
    case 6:
      (**(code **)(*param_1 + 0xb8))(param_1,lStack_f8);
      iVar5 = 0xc;
      break;
    case 7:
      (**(code **)(*param_1 + 0x88))(param_1);
      iVar5 = 3;
      if (unaff_x27 != 0) {
        iVar5 = 5;
      }
      break;
    case 8:
      memset(&cStack_e8,0,0x80);
      pcVar9 = (char *)param_3[1];
      sVar6 = strlen(pcVar9);
      strncpy(&cStack_e8,pcVar9,sVar6 - 1);
      unaff_x27 = (**(code **)(*param_1 + 0x30))(param_1,auStack_e7);
      cVar4 = (**(code **)(*param_1 + 0x720))(param_1);
      iVar5 = 7;
      if (cVar4 != '\x01') {
        iVar5 = 9;
      }
      break;
    case 9:
      iVar5 = (uint)(unaff_x27 == 0) << 2;
      break;
    case 10:
      uStack_10c = (**(code **)(*param_1 + 0x310))(param_1,param_2,lStack_108);
      if (lStack_f8 == 0) {
        lStack_f8 = 0;
        iVar5 = 0x29 - uStack_fc % 0x97;
      }
      else {
        iVar5 = 0x23 - uStack_fc % 0x97;
      }
      break;
    case 0xb:
      lStack_f8 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      pcVar9 = (char *)param_3[1];
LAB_00168c54:
      do {
        lVar2 = DAT_0018ead0;
        if (DAT_0018ead0 == 0) {
          cVar4 = '\x01';
          bVar1 = (bool)ExclusiveMonitorPass(0x18ead0,0x10);
          if (bVar1) {
            DAT_0018ead0 = 1;
            cVar4 = ExclusiveMonitorsStatus();
          }
          if (cVar4 != '\0') goto LAB_00168c54;
        }
      } while (lVar2 == 1);
      if (lVar2 != 2) {
        DAT_0018ea4e = 0x4c;
        DAT_0018ea4f = 0;
        DAT_0018ead0 = 2;
      }
      sVar6 = strlen(&DAT_0018ea4e);
      iVar5 = strncmp(pcVar9,&DAT_0018ea4e,sVar6);
      if (iVar5 == 0) {
        pcVar9 = (char *)param_3[1];
LAB_00168cc8:
        do {
          lVar2 = DAT_0018eac8;
          if (DAT_0018eac8 == 0) {
            cVar4 = '\x01';
            bVar1 = (bool)ExclusiveMonitorPass(0x18eac8,0x10);
            if (bVar1) {
              DAT_0018eac8 = 1;
              cVar4 = ExclusiveMonitorsStatus();
            }
            if (cVar4 != '\0') goto LAB_00168cc8;
          }
        } while (lVar2 == 1);
        if (lVar2 != 2) {
          DAT_0018ea4d = 0;
          DAT_0018ea4c = 0x3b;
          DAT_0018eac8 = 2;
        }
        uVar3 = 4;
        do {
          uVar8 = uVar3;
          if (4 < uVar8) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          uVar3 = (uint)(pcVar9 != (char *)0x0) << 1;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(uVar8) {
          case 0:
            goto switchD_00168d4c_caseD_0;
          case 2:
            sVar6 = strlen(pcVar9);
            sVar7 = strlen(&DAT_0018ea4c);
            if (sVar6 <= sVar7 - 1) goto switchD_00168d4c_caseD_0;
            uVar3 = 1;
          }
        } while( true );
      }
switchD_00168d4c_caseD_0:
      iVar5 = 4;
      break;
    case 0xc:
    case 0xd:
      goto switchD_00168ab8_caseD_c;
    }
  } while( true );
}


/* EXPORT index=239 ELF_VA=0x68e4c size=1068 source_sha256=8a50cdd60985b2cc35ea8e2f038b1ce36ff636a0d6d667177d8e0c0017e9a59a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j____IOI0_5_III__I5___IO005_O_lISl___ll_5IIIS0SIIISS5_
               (long *param_1,undefined8 param_2,undefined8 *param_3)

{
  bool bVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  size_t sVar6;
  size_t sVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  long unaff_x26;
  char *pcVar11;
  undefined4 uStack_104;
  long lStack_100;
  long lStack_f8;
  char cStack_e8;
  undefined1 auStack_e7 [127];
  long lStack_68;
  
  iVar4 = 0x24d2;
  uVar9 = 9;
  lStack_68 = ___stack_chk_guard;
  lStack_100 = 0;
  uStack_104 = 0;
  lStack_f8 = lStack_100;
  do {
    uVar5 = 0;
    switch(uVar9) {
    case 0:
      uVar5 = uStack_104;
switchD_00168f78_caseD_7:
      if (___stack_chk_guard != lStack_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(uVar5);
      }
      return;
    case 1:
      (**(code **)(*param_1 + 0xb8))(param_1,lStack_f8);
      uVar9 = 0;
      break;
    case 2:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x26);
      uVar9 = (7 - iVar4) + ((uint)(iVar4 * 0xcccd) >> 0x12) * 5;
      break;
    case 3:
      iVar4 = iVar4 + ((uint)(iVar4 * 0xe6c3) >> 0x16) * -0x47;
      (**(code **)(*param_1 + 0x88))(param_1);
      iVar8 = 0x15;
      if (unaff_x26 != 0) {
        iVar8 = 0x10;
      }
      uVar9 = iVar8 - iVar4;
      iVar4 = 0x3a15 - iVar4;
      break;
    case 4:
      uStack_104 = (**(code **)(*param_1 + 0x318))(param_1,param_2,lStack_100);
      uVar9 = (uint)(lStack_f8 != 0);
      break;
    case 5:
      lStack_100 = (**(code **)(*param_1 + 0x2f0))(param_1,lStack_f8,param_3[2],param_3[1]);
      uVar9 = 0xb;
      if (lStack_100 != 0) {
        uVar9 = 4;
      }
      break;
    case 6:
      uVar9 = 5;
      if (unaff_x26 != 0) {
        uVar9 = 8;
      }
      iVar4 = 0x5916;
      break;
    case 7:
    case 0xb:
    case 0xc:
      goto switchD_00168f78_caseD_7;
    case 8:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x26);
      uVar9 = (((uint)(iVar4 * 0x8103) >> 0x16) * 0x7f + 0x4e) - iVar4;
      break;
    case 9:
      lStack_f8 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      pcVar11 = (char *)param_3[1];
LAB_001690d4:
      do {
        lVar2 = DAT_0018eac0;
        if (DAT_0018eac0 == 0) {
          cVar3 = '\x01';
          bVar1 = (bool)ExclusiveMonitorPass(0x18eac0,0x10);
          if (bVar1) {
            DAT_0018eac0 = 1;
            cVar3 = ExclusiveMonitorsStatus();
          }
          if (cVar3 != '\0') goto LAB_001690d4;
        }
      } while (lVar2 == 1);
      if (lVar2 != 2) {
        DAT_0018ea4b = 0;
        DAT_0018ea4a = 0x4c;
        DAT_0018eac0 = 2;
      }
      sVar6 = strlen(&DAT_0018ea4a);
      iVar4 = strncmp(pcVar11,&DAT_0018ea4a,sVar6);
      if (iVar4 == 0) {
        pcVar11 = (char *)param_3[1];
LAB_0016914c:
        do {
          lVar2 = DAT_0018eab8;
          if (DAT_0018eab8 == 0) {
            cVar3 = '\x01';
            bVar1 = (bool)ExclusiveMonitorPass(0x18eab8,0x10);
            if (bVar1) {
              DAT_0018eab8 = 1;
              cVar3 = ExclusiveMonitorsStatus();
            }
            if (cVar3 != '\0') goto LAB_0016914c;
          }
        } while (lVar2 == 1);
        if (lVar2 != 2) {
          DAT_0018ea48 = 0x3b;
          DAT_0018ea49 = 0;
          DAT_0018eab8 = 2;
        }
        uVar9 = 4;
        do {
          uVar10 = uVar9;
          if (4 < uVar10) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          uVar9 = (uint)(pcVar11 != (char *)0x0) << 1;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(uVar10) {
          case 0:
            goto switchD_001691d0_caseD_0;
          case 2:
            sVar6 = strlen(pcVar11);
            sVar7 = strlen(&DAT_0018ea48);
            if (sVar6 <= sVar7 - 1) goto switchD_001691d0_caseD_0;
            uVar9 = 1;
          }
        } while( true );
      }
switchD_001691d0_caseD_0:
      iVar4 = 0x5bea;
      uVar9 = 5;
      break;
    case 10:
      iVar4 = iVar4 + ((uint)(iVar4 * 0xfa24) >> 0x17) * -0x83;
      memset(&cStack_e8,0,0x80);
      pcVar11 = (char *)param_3[1];
      sVar6 = strlen(pcVar11);
      strncpy(&cStack_e8,pcVar11,sVar6 - 1);
      unaff_x26 = (**(code **)(*param_1 + 0x30))(param_1,auStack_e7);
      cVar3 = (**(code **)(*param_1 + 0x720))(param_1);
      iVar8 = 0x54;
      if (cVar3 != '\x01') {
        iVar8 = 0x57;
      }
      uVar9 = iVar8 - iVar4;
      iVar4 = 0x794b - iVar4;
    }
  } while( true );
}


/* EXPORT index=240 ELF_VA=0x692c0 size=948 source_sha256=893b4772e52b7aab2414700cdf8b4ae48c3965f94ee56f8a291281608b0d433f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___I_5_0_SlIII_I5lIO_SI0_l_lIIOIl5O_S_IOOS_OIlI_S5S5_
               (long *param_1,undefined8 param_2,undefined8 *param_3)

{
  bool bVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  long lVar7;
  undefined4 uVar8;
  uint uVar9;
  char *pcVar10;
  long unaff_x27;
  long lStack_108;
  long lStack_100;
  long lStack_f8;
  char cStack_e8;
  undefined1 auStack_e7 [127];
  long lStack_68;
  
  uVar8 = 7;
  lStack_68 = ___stack_chk_guard;
  lStack_108 = 0;
  lStack_100 = lStack_108;
  lStack_f8 = lStack_108;
  do {
    lVar7 = 0;
    switch(uVar8) {
    case 0:
      (**(code **)(*param_1 + 0xb8))(param_1,lStack_f8);
      uVar8 = 9;
      break;
    case 1:
      memset(&cStack_e8,0,0x80);
      pcVar10 = (char *)param_3[1];
      sVar5 = strlen(pcVar10);
      strncpy(&cStack_e8,pcVar10,sVar5 - 1);
      unaff_x27 = (**(code **)(*param_1 + 0x30))(param_1,auStack_e7);
      cVar3 = (**(code **)(*param_1 + 0x720))(param_1);
      uVar8 = 6;
      if (cVar3 != '\x01') {
        uVar8 = 2;
      }
      break;
    case 2:
      uVar8 = 3;
      if (unaff_x27 != 0) {
        uVar8 = 5;
      }
      break;
    case 3:
      lStack_100 = (**(code **)(*param_1 + 0x2f0))(param_1,lStack_f8,param_3[2],param_3[1]);
      uVar8 = 4;
      if (lStack_100 != 0) {
        uVar8 = 8;
      }
      break;
    case 5:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      uVar8 = 3;
      break;
    case 6:
      (**(code **)(*param_1 + 0x88))(param_1);
      uVar8 = 10;
      if (unaff_x27 != 0) {
        uVar8 = 0xb;
      }
      break;
    case 7:
      lStack_f8 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      pcVar10 = (char *)param_3[1];
LAB_00169488:
      do {
        lVar7 = DAT_0018eab0;
        if (DAT_0018eab0 == 0) {
          cVar3 = '\x01';
          bVar1 = (bool)ExclusiveMonitorPass(0x18eab0,0x10);
          if (bVar1) {
            DAT_0018eab0 = 1;
            cVar3 = ExclusiveMonitorsStatus();
          }
          if (cVar3 != '\0') goto LAB_00169488;
        }
      } while (lVar7 == 1);
      if (lVar7 != 2) {
        DAT_0018ea47 = 0;
        DAT_0018ea46 = 0x4c;
        DAT_0018eab0 = 2;
      }
      sVar5 = strlen(&DAT_0018ea46);
      iVar4 = strncmp(pcVar10,&DAT_0018ea46,sVar5);
      if (iVar4 == 0) {
        pcVar10 = (char *)param_3[1];
LAB_00169500:
        do {
          lVar7 = DAT_0018eaa8;
          if (DAT_0018eaa8 == 0) {
            cVar3 = '\x01';
            bVar1 = (bool)ExclusiveMonitorPass(0x18eaa8,0x10);
            if (bVar1) {
              DAT_0018eaa8 = 1;
              cVar3 = ExclusiveMonitorsStatus();
            }
            if (cVar3 != '\0') goto LAB_00169500;
          }
        } while (lVar7 == 1);
        if (lVar7 != 2) {
          DAT_0018ea44 = 0x3b;
          DAT_0018ea45 = 0;
          DAT_0018eaa8 = 2;
        }
        uVar2 = 4;
        do {
          uVar9 = uVar2;
          if (4 < uVar9) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          uVar2 = (uint)(pcVar10 != (char *)0x0) << 1;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(uVar9) {
          case 0:
            goto switchD_00169588_caseD_0;
          case 2:
            sVar5 = strlen(pcVar10);
            sVar6 = strlen(&DAT_0018ea44);
            if (sVar5 <= sVar6 - 1) goto switchD_00169588_caseD_0;
            uVar2 = 1;
          }
        } while( true );
      }
switchD_00169588_caseD_0:
      uVar8 = 3;
      break;
    case 8:
      lStack_108 = (**(code **)(*param_1 + 0x2f8))(param_1,param_2,lStack_100);
      uVar8 = 9;
      if (lStack_f8 != 0) {
        uVar8 = 0;
      }
      break;
    case 9:
      lVar7 = lStack_108;
    case 4:
    case 10:
      if (___stack_chk_guard != lStack_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(lVar7);
      }
      return;
    case 0xb:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      uVar8 = 10;
    }
  } while( true );
}


/* EXPORT index=241 ELF_VA=0x696b8 size=712 source_sha256=08238a987081a75629fd61d2b2946b30d1a52d515ef923a6893be7c18ea955fd */

uint j___5ll___l5__O_lOSI0_ll5_I_I5II_5OllIlI_0IlS5O_IISS5_
               (long *param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long unaff_x22;
  long unaff_x23;
  uint unaff_w24;
  uint uVar7;
  
  iVar4 = 0;
  uVar2 = 0x1252;
  do {
    uVar7 = uVar2;
    iVar6 = 3;
    bVar3 = unaff_x22 != 0;
    iVar1 = 0;
    if (bVar3) {
      iVar6 = 6;
      iVar1 = 7;
    }
switchD_0016978c_default:
    iVar5 = 0xb;
    switch(iVar4) {
    case 0:
      unaff_w24 = uVar7 % 0xb;
      unaff_x22 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      unaff_x23 = (**(code **)(*param_1 + 0x2f0))(param_1,unaff_x22,param_3[2],param_3[1]);
      iVar4 = 7;
      if (unaff_x23 != 0) {
        iVar4 = 5;
      }
      iVar4 = iVar4 - unaff_w24;
      uVar2 = uVar7;
      if (iVar4 == 4) {
switchD_00169928_caseD_7:
        return unaff_w24;
      }
      break;
    case 1:
      goto switchD_0016978c_caseD_1;
    case 2:
      unaff_x22 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      unaff_x23 = (**(code **)(*param_1 + 0x2f0))(param_1,unaff_x22,param_3[2],param_3[1]);
      iVar4 = 0;
      if (unaff_x23 != 0) {
        iVar4 = 2;
      }
      uVar2 = 0x4687;
      if (unaff_x23 != 0) {
        uVar2 = uVar7;
      }
      break;
    case 3:
      goto switchD_0016978c_caseD_3;
    default:
      goto switchD_0016978c_default;
    }
  } while( true );
switchD_0016978c_caseD_1:
  do {
    switch(iVar5) {
    case 0:
      iVar5 = iVar1;
      break;
    case 1:
      goto switchD_0016978c_caseD_3;
    case 2:
      unaff_w24 = (**(code **)(*param_1 + 0x330))(param_1,param_2,unaff_x23);
      uVar7 = 0x556a;
      iVar5 = 10;
      break;
    case 3:
    case 0xc:
      return 0;
    case 4:
      if (bVar3) {
        iVar5 = 0x32 - uVar7 % 0xa7;
      }
      else {
        iVar5 = 0x2d - uVar7 % 0xa7;
      }
      break;
    case 5:
      unaff_w24 = (**(code **)(*param_1 + 800))(param_1,param_2,unaff_x23);
      uVar7 = 0x63cf;
      iVar5 = 10;
      break;
    case 6:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x22);
      iVar5 = 3;
      break;
    case 7:
      goto switchD_00169928_caseD_7;
    case 8:
      iVar5 = iVar6;
      break;
    case 9:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x22);
      iVar5 = 7;
      break;
    case 10:
      if (bVar3) {
        iVar5 = 0x12 - uVar7 % 0xb;
      }
      else {
        iVar5 = 0x10 - uVar7 % 0xb;
      }
      break;
    case 0xb:
      iVar5 = 5;
      if (*(char *)param_3[1] != 'I') {
        iVar5 = 2;
      }
    }
  } while( true );
switchD_0016978c_caseD_3:
  iVar5 = 8;
  goto switchD_0016978c_caseD_1;
}


/* EXPORT index=242 ELF_VA=0x699c4 size=540 source_sha256=da13b54aff41a696e3d1983c8180a4aa9efa478393664a1b6240c6851f0be6e1 */

undefined8
j____lII0_IIO50_OS0I0_IIIOI_III5I5l5_S_5I0O_I_0IIllS5_
          (long *param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  long unaff_x22;
  long unaff_x23;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  
  iVar1 = 0;
  uVar3 = 2;
  do {
    iVar2 = 6;
    if (unaff_x22 != 0) {
      iVar2 = 2;
    }
    do {
      if (iVar1 == 2) goto switchD_00169af8_caseD_1;
      if (iVar1 == 1) {
        uVar4 = 0x2c99;
        iVar1 = 5;
        do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(iVar1) {
          case 0:
            uVar4 = 0x5021;
            iVar1 = iVar2;
            break;
          case 1:
switchD_00169af8_caseD_1:
            iVar1 = 3;
            uVar4 = 0x1119;
            break;
          case 2:
            (**(code **)(*param_1 + 0xb8))(param_1,unaff_x22);
            uVar4 = 0x6b6;
            iVar1 = 6;
            break;
          case 3:
            if (unaff_x22 != 0) {
              iVar1 = 0x18 - uVar4 % 0x6d;
            }
            else {
              iVar1 = 0x19 - uVar4 % 0x6d;
            }
            break;
          case 4:
            uVar3 = (**(code **)(*param_1 + 0x338))(param_1,param_2,unaff_x23);
            iVar1 = 0;
            break;
          case 5:
            iVar1 = 9;
            if (*(char *)param_3[1] != 'J') {
              iVar1 = 4;
            }
            break;
          case 6:
            return uVar3;
          case 7:
            (**(code **)(*param_1 + 0xb8))(param_1,unaff_x22);
            iVar1 = 8;
          }
        } while( true );
      }
    } while (iVar1 != 0);
    unaff_x22 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
    unaff_x23 = (**(code **)(*param_1 + 0x2f0))(param_1,unaff_x22,param_3[2],param_3[1]);
    iVar1 = 1;
    if (unaff_x23 == 0) {
      iVar1 = 2;
    }
  } while( true );
}


/* EXPORT index=243 ELF_VA=0x69c0c size=1220 source_sha256=b6a01dc0b19004c3490c7acc1eff48923550f2c6df0d0182e0f3bb8813676c57 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___SlOSO__I5IO_50SSI_IOSI__5lllIO_S5_O_I5_I0Ol0lIIS5_
               (long *param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4)

{
  bool bVar1;
  long lVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  size_t sVar6;
  size_t sVar7;
  uint uVar8;
  char *pcVar9;
  long unaff_x27;
  uint uVar10;
  long lStack_108;
  long lStack_f8;
  char cStack_e8;
  undefined1 auStack_e7 [127];
  long lStack_68;
  
  uVar10 = 0x6a4f;
  lStack_68 = ___stack_chk_guard;
  lStack_108 = 0;
  iVar5 = 1;
  lStack_f8 = lStack_108;
  do {
    switch(iVar5) {
    case 0:
    case 0xe:
      iVar5 = 3;
      uVar10 = 0x7f08;
      break;
    case 1:
      lStack_f8 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      pcVar9 = (char *)param_3[1];
LAB_00169d1c:
      do {
        lVar2 = DAT_0018eaa0;
        if (DAT_0018eaa0 == 0) {
          cVar4 = '\x01';
          bVar1 = (bool)ExclusiveMonitorPass(0x18eaa0,0x10);
          if (bVar1) {
            DAT_0018eaa0 = 1;
            cVar4 = ExclusiveMonitorsStatus();
          }
          if (cVar4 != '\0') goto LAB_00169d1c;
        }
      } while (lVar2 == 1);
      if (lVar2 != 2) {
        DAT_0018ea42 = 0x4c;
        DAT_0018ea43 = 0;
        DAT_0018eaa0 = 2;
      }
      sVar6 = strlen(&DAT_0018ea42);
      iVar5 = strncmp(pcVar9,&DAT_0018ea42,sVar6);
      if (iVar5 == 0) {
        pcVar9 = (char *)param_3[1];
LAB_00169da0:
        do {
          lVar2 = DAT_0018ea98;
          if (DAT_0018ea98 == 0) {
            cVar4 = '\x01';
            bVar1 = (bool)ExclusiveMonitorPass(0x18ea98,0x10);
            if (bVar1) {
              DAT_0018ea98 = 1;
              cVar4 = ExclusiveMonitorsStatus();
            }
            if (cVar4 != '\0') goto LAB_00169da0;
          }
        } while (lVar2 == 1);
        if (lVar2 != 2) {
          DAT_0018ea41 = 0;
          DAT_0018ea40 = 0x3b;
          DAT_0018ea98 = 2;
        }
        uVar3 = 4;
        do {
          uVar8 = uVar3;
          if (4 < uVar8) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          uVar3 = (uint)(pcVar9 != (char *)0x0) << 1;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(uVar8) {
          case 0:
            goto switchD_00169e2c_caseD_0;
          case 2:
            sVar6 = strlen(pcVar9);
            sVar7 = strlen(&DAT_0018ea40);
            uVar3 = 1;
            if (sVar6 <= sVar7 - 1) goto switchD_00169e2c_caseD_0;
          }
        } while( true );
      }
switchD_00169e2c_caseD_0:
      iVar5 = 0xb;
      break;
    case 2:
      (**(code **)(*param_1 + 0x348))(param_1,param_2,lStack_108,param_4);
      iVar5 = 7;
      break;
    case 3:
      if (lStack_f8 == 0) {
        lStack_f8 = 0;
        iVar5 = 0x8a - uVar10 % 0xa7;
      }
      else {
        iVar5 = 0x86 - uVar10 % 0xa7;
      }
      break;
    case 4:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      iVar5 = 0xb;
      break;
    case 5:
      iVar5 = 0xb;
      if (unaff_x27 != 0) {
        iVar5 = 4;
      }
      break;
    case 6:
    case 0xd:
    case 0x10:
      if (___stack_chk_guard != lStack_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    case 7:
      memset(&cStack_e8,0,0x80);
      pcVar9 = (char *)param_3[1];
      sVar6 = strlen(pcVar9);
      strncpy(&cStack_e8,pcVar9,sVar6 - 1);
      unaff_x27 = (**(code **)(*param_1 + 0x30))(param_1,auStack_e7);
      cVar4 = (**(code **)(*param_1 + 0x720))(param_1);
      iVar5 = 8;
      if (cVar4 != '\x01') {
        iVar5 = 5;
      }
      break;
    case 8:
      (**(code **)(*param_1 + 0x88))(param_1);
      iVar5 = 0xd;
      if (unaff_x27 != 0) {
        iVar5 = 10;
      }
      uVar10 = 0x1403;
      break;
    case 9:
      iVar5 = 5;
      if (unaff_x27 != 0) {
        iVar5 = 10;
      }
      uVar10 = 0x68a5;
      break;
    case 10:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      iVar5 = (0x70 - uVar10) + (uVar10 / 0x9d) * 0x9d;
      break;
    case 0xb:
      lStack_108 = (**(code **)(*param_1 + 0x2f0))(param_1,lStack_f8,param_3[2],param_3[1]);
      iVar5 = 0xe;
      if (lStack_108 != 0) {
        iVar5 = 0xf;
      }
      uVar10 = 0x1687;
      break;
    case 0xc:
      (**(code **)(*param_1 + 0xb8))(param_1,lStack_f8);
      iVar5 = 0x10;
      break;
    case 0xf:
      (**(code **)(*param_1 + 0x348))(param_1,param_2,lStack_108,param_4);
      iVar5 = (1 - uVar10) + (uVar10 / 3) * 3;
    }
  } while( true );
}


/* EXPORT index=244 ELF_VA=0x6a128 size=1192 source_sha256=16330cfd7f632a72f8dba1a5748653a174601c04c7960088858d6544df3db024 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___5l____0OlII__llO__I5SS5_IIl5OlSI5_IIl55_I0l__SIS5_
               (long *param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  size_t sVar6;
  size_t sVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  long unaff_x27;
  long lStack_108;
  long lStack_f8;
  char cStack_e8;
  undefined1 auStack_e7 [127];
  long lStack_68;
  
  iVar5 = 0x2480;
  lStack_68 = ___stack_chk_guard;
  lStack_108 = 0;
  lStack_f8 = lStack_108;
  uVar8 = 0;
  do {
    switch(uVar8) {
    case 0:
      iVar9 = iVar5 + ((uint)(iVar5 * 0xef2f) >> 0x17) * -0x89;
      lStack_f8 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      pcVar11 = (char *)param_3[1];
LAB_0016a210:
      do {
        lVar3 = DAT_0018ea90;
        if (DAT_0018ea90 == 0) {
          cVar4 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(0x18ea90,0x10);
          if (bVar2) {
            DAT_0018ea90 = 1;
            cVar4 = ExclusiveMonitorsStatus();
          }
          if (cVar4 != '\0') goto LAB_0016a210;
        }
      } while (lVar3 == 1);
      if (lVar3 != 2) {
        DAT_0018ea3f = 0;
        DAT_0018ea3e = 0x4c;
        DAT_0018ea90 = 2;
      }
      sVar6 = strlen(&DAT_0018ea3e);
      iVar5 = strncmp(pcVar11,&DAT_0018ea3e,sVar6);
      if (iVar5 == 0) {
        pcVar11 = (char *)param_3[1];
LAB_0016a294:
        do {
          lVar3 = DAT_0018ea88;
          if (DAT_0018ea88 == 0) {
            cVar4 = '\x01';
            bVar2 = (bool)ExclusiveMonitorPass(0x18ea88,0x10);
            if (bVar2) {
              DAT_0018ea88 = 1;
              cVar4 = ExclusiveMonitorsStatus();
            }
            if (cVar4 != '\0') goto LAB_0016a294;
          }
        } while (lVar3 == 1);
        if (lVar3 != 2) {
          DAT_0018ea3c = 0x3b;
          DAT_0018ea3d = 0;
          DAT_0018ea88 = 2;
        }
        uVar8 = 4;
        do {
          uVar10 = uVar8;
          if (4 < uVar10) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          uVar8 = (uint)(pcVar11 != (char *)0x0) << 1;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(uVar10) {
          case 0:
            goto switchD_0016a320_caseD_0;
          case 2:
            sVar6 = strlen(pcVar11);
            sVar7 = strlen(&DAT_0018ea3c);
            uVar8 = 1;
            if (sVar6 <= sVar7 - 1) goto switchD_0016a320_caseD_0;
          }
        } while( true );
      }
switchD_0016a320_caseD_0:
      iVar5 = 0x715d - iVar9;
      uVar8 = 0x1e - iVar9;
      break;
    case 1:
      (**(code **)(*param_1 + 0xb8))(param_1,lStack_f8);
      uVar8 = 0xe;
      break;
    case 2:
      lStack_108 = (**(code **)(*param_1 + 0x2f0))(param_1,lStack_f8,param_3[2],param_3[1]);
      uVar8 = 3;
      if (lStack_108 == 0) {
        uVar8 = 4;
      }
      break;
    case 3:
      (**(code **)(*param_1 + 0x350))(param_1,param_2,lStack_108,param_4);
      uVar8 = 0xd;
      break;
    case 4:
    case 0xd:
      uVar8 = 6;
      break;
    case 5:
    case 0xe:
      if (___stack_chk_guard != lStack_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    case 6:
      uVar8 = 0xe;
      if (lStack_f8 != 0) {
        uVar8 = 1;
      }
      break;
    case 7:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      uVar8 = (0x46 - iVar5) + ((uint)(iVar5 * 0x9920) >> 0x16) * 0x6b;
      break;
    case 8:
      (**(code **)(*param_1 + 0x88))(param_1);
      uVar8 = 5;
      if (unaff_x27 != 0) {
        uVar8 = 9;
      }
      iVar5 = 0x2d84;
      break;
    case 9:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      uVar8 = (0x32 - iVar5) + ((uint)(iVar5 * 0xe071) >> 0x16) * 0x49;
      break;
    case 10:
      iVar1 = iVar5 + ((uint)(iVar5 * 0xe6c3) >> 0x16) * -0x47;
      memset(&cStack_e8,0,0x80);
      pcVar11 = (char *)param_3[1];
      sVar6 = strlen(pcVar11);
      strncpy(&cStack_e8,pcVar11,sVar6 - 1);
      unaff_x27 = (**(code **)(*param_1 + 0x30))(param_1,auStack_e7);
      cVar4 = (**(code **)(*param_1 + 0x720))(param_1);
      iVar9 = 0x21;
      if (cVar4 != '\x01') {
        iVar9 = 0x25;
      }
      iVar5 = 0x127b - iVar1;
      uVar8 = iVar9 - iVar1;
      break;
    case 0xb:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      uVar8 = 2;
      break;
    case 0xc:
      iVar9 = iVar5 + ((uint)(iVar5 * 0xe6c3) >> 0x16) * -0x47;
      if (unaff_x27 == 0) {
        unaff_x27 = 0;
        uVar8 = 0x16 - iVar9;
      }
      else {
        uVar8 = 0x1f - iVar9;
      }
    }
  } while( true );
}


/* EXPORT index=245 ELF_VA=0x6a620 size=1520 source_sha256=87d84486bd3f118697dadeb886655dde70541d29ba7026c6c53248f69a91c90c */

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff00 : 0x0016abe0 */
/* WARNING: Switch with 1 destination removed at 0x0016a830 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* WARNING: Exceeded maximum restarts with more pending */

void j___lI_II_5lI5l_lOI5I_lO_I__lIS5Il05llI_llI__l5IllOS5_
               (long *param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  long lVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  size_t sVar7;
  size_t sVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  char *pcVar12;
  long unaff_x27;
  long lStack_120;
  long lStack_108;
  char cStack_e8;
  undefined1 auStack_e7 [135];
  
  lVar3 = ___stack_chk_guard;
  iVar6 = 0x642b;
  lStack_120 = 0;
  lStack_108 = lStack_120;
  uVar9 = 0xd;
  do {
    switch(uVar9) {
    case 0:
      (**(code **)(*param_1 + 0x88))(param_1);
      uVar9 = 1;
      if (unaff_x27 != 0) {
        uVar9 = 10;
      }
      break;
    case 1:
    case 0xe:
      if (___stack_chk_guard != lVar3) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    case 2:
      lStack_108 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      pcVar12 = (char *)param_3[1];
LAB_0016a720:
      do {
        lVar4 = DAT_0018ea80;
        if (DAT_0018ea80 == 0) {
          cVar5 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(0x18ea80,0x10);
          if (bVar2) {
            DAT_0018ea80 = 1;
            cVar5 = ExclusiveMonitorsStatus();
          }
          if (cVar5 != '\0') goto LAB_0016a720;
        }
      } while (lVar4 == 1);
      if (lVar4 != 2) {
        DAT_0018ea3a = 0x4c;
        DAT_0018ea3b = 0;
        DAT_0018ea80 = 2;
      }
      sVar7 = strlen(&DAT_0018ea3a);
      iVar6 = strncmp(pcVar12,&DAT_0018ea3a,sVar7);
      if (iVar6 == 0) {
        goto LAB_0016a7a4;
      }
      iVar6 = 0x30f3;
      uVar9 = 7;
      break;
    case 3:
    case 4:
      uVar9 = 9;
      break;
    case 5:
      (**(code **)(*param_1 + 0xb8))(param_1,lStack_108);
      uVar9 = 0xe;
      break;
    case 6:
      uVar9 = 7;
      if (unaff_x27 == 0) {
        uVar9 = 8;
      }
      iVar6 = 0x2109;
      break;
    case 7:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      iVar6 = 0x71a9;
      uVar9 = 8;
      break;
    case 8:
      iVar1 = iVar6 + ((uint)(iVar6 * 0xbe83) >> 0x15) * -0x2b;
      lStack_120 = (**(code **)(*param_1 + 0x2f0))(param_1,lStack_108,param_3[2],param_3[1]);
      iVar10 = 0x20;
      if (lStack_120 != 0) {
        iVar10 = 0x29;
      }
      iVar6 = 0x7224 - iVar1;
      uVar9 = iVar10 - iVar1;
      break;
    case 9:
      uVar9 = 0xe;
      if (lStack_108 != 0) {
        uVar9 = 5;
      }
      break;
    case 10:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      uVar9 = 1;
      break;
    case 0xb:
      memset(&cStack_e8,0,0x80);
      pcVar12 = (char *)param_3[1];
      sVar7 = strlen(pcVar12);
      strncpy(&cStack_e8,pcVar12,sVar7 - 1);
      unaff_x27 = (**(code **)(*param_1 + 0x30))(param_1,auStack_e7);
      cVar5 = (**(code **)(*param_1 + 0x720))(param_1);
      uVar9 = 0;
      if (cVar5 != '\x01') {
        uVar9 = 6;
      }
      break;
    case 0xc:
      (**(code **)(*param_1 + 0x358))(param_1,param_2,lStack_120,param_4);
      uVar9 = (6 - iVar6) + ((uint)(iVar6 * 0xf0f1) >> 0x14) * 0x11;
      break;
    case 0xd:
      lStack_108 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      pcVar12 = (char *)param_3[1];
LAB_0016aa10:
      do {
        lVar4 = DAT_0018ea80;
        if (DAT_0018ea80 == 0) {
          cVar5 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(0x18ea80,0x10);
          if (bVar2) {
            DAT_0018ea80 = 1;
            cVar5 = ExclusiveMonitorsStatus();
          }
          if (cVar5 != '\0') goto LAB_0016aa10;
        }
      } while (lVar4 == 1);
      if (lVar4 != 2) {
        DAT_0018ea3a = 0x4c;
        DAT_0018ea3b = 0;
        DAT_0018ea80 = 2;
      }
      sVar7 = strlen(&DAT_0018ea3a);
      iVar6 = strncmp(pcVar12,&DAT_0018ea3a,sVar7);
      if (iVar6 == 0) {
        pcVar12 = (char *)param_3[1];
LAB_0016aa94:
        do {
          lVar4 = DAT_0018ea78;
          if (DAT_0018ea78 == 0) {
            cVar5 = '\x01';
            bVar2 = (bool)ExclusiveMonitorPass(0x18ea78,0x10);
            if (bVar2) {
              DAT_0018ea78 = 1;
              cVar5 = ExclusiveMonitorsStatus();
            }
            if (cVar5 != '\0') goto LAB_0016aa94;
          }
        } while (lVar4 == 1);
        if (lVar4 != 2) {
          DAT_0018ea39 = 0;
          DAT_0018ea38 = 0x3b;
          DAT_0018ea78 = 2;
        }
        uVar9 = 4;
        do {
          uVar11 = uVar9;
          if (4 < uVar11) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          uVar9 = (uint)(pcVar12 != (char *)0x0) << 1;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(uVar11) {
          case 0:
            goto switchD_0016ab20_caseD_0;
          case 2:
            sVar7 = strlen(pcVar12);
            sVar8 = strlen(&DAT_0018ea38);
            uVar9 = 1;
            if (sVar7 <= sVar8 - 1) goto switchD_0016ab20_caseD_0;
          }
        } while( true );
      }
switchD_0016ab20_caseD_0:
      iVar6 = 0x5ba8;
      uVar9 = 8;
    }
  } while( true );
LAB_0016a7a4:
  lVar3 = DAT_0018ea78;
  if (DAT_0018ea78 == 0) {
    cVar5 = '\x01';
    bVar2 = (bool)ExclusiveMonitorPass(0x18ea78,0x10);
    if (bVar2) {
      DAT_0018ea78 = 1;
      cVar5 = ExclusiveMonitorsStatus();
    }
    if (cVar5 != '\0') goto LAB_0016a7a4;
  }
  if (lVar3 != 1) {
    uVar9 = 4;
                    /* WARNING: This code block may not be properly labeled as switch case */
    while (uVar9 < 5) {
      uVar9 = (uint)(param_3[1] != 0) << 1;
    }
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  goto LAB_0016a7a4;
}


/* EXPORT index=246 ELF_VA=0x6ac74 size=1204 source_sha256=f198bfa5dbf5222b64b8e7ad1e67d0d438a6aff8b0ae5104e4ab3ca8d32d5e35 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff00 : 0x0016b0f8 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* WARNING: Exceeded maximum restarts with more pending */

void j___5llSI_SllI__0S0l5_0__Ol__5S_0l__O_IlOI_S_l_5lO_S5_
               (long *param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  size_t sVar7;
  size_t sVar8;
  uint uVar9;
  char *pcVar10;
  long unaff_x20;
  long unaff_x27;
  int iVar11;
  long lStack_118;
  int iStack_f4;
  char cStack_e8;
  undefined1 auStack_e7 [135];
  
  lVar3 = ___stack_chk_guard;
  iStack_f4 = 0xc;
  iVar11 = 0x75d5;
  lStack_118 = 0;
  iVar6 = iStack_f4;
  do {
    switch(iVar6) {
    case 0:
      memset(&cStack_e8,0,0x80);
      pcVar10 = (char *)param_3[1];
      sVar7 = strlen(pcVar10);
      strncpy(&cStack_e8,pcVar10,sVar7 - 1);
      unaff_x27 = (**(code **)(*param_1 + 0x30))(param_1,auStack_e7);
      cVar5 = (**(code **)(*param_1 + 0x720))(param_1);
      if (cVar5 == '\x01') {
        iStack_f4 = 0xe;
      }
      else {
        iStack_f4 = 0x10;
      }
      iStack_f4 = iStack_f4 - (iVar11 + ((uint)(iVar11 * 0xf0f1) >> 0x14) * -0x11);
      iVar6 = iStack_f4;
      break;
    case 1:
    case 10:
      iStack_f4 = 6;
      iVar6 = iStack_f4;
      break;
    case 2:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x20);
      iStack_f4 = (0xe - iVar11) + ((uint)(iVar11 * 0xaaab) >> 0x11) * 3;
      iVar6 = iStack_f4;
      break;
    case 3:
      if (iStack_f4 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      iStack_f4 = 4;
      iVar6 = iStack_f4;
      break;
    case 4:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      iStack_f4 = 8;
      iVar6 = iStack_f4;
      break;
    case 5:
      (**(code **)(*param_1 + 0x88))(param_1);
      if (unaff_x27 == 0) {
        unaff_x27 = 0;
        iStack_f4 = 8;
        iVar6 = iStack_f4;
      }
      else {
        iStack_f4 = 3;
        iVar6 = iStack_f4;
      }
      break;
    case 6:
      iStack_f4 = 0xe;
      if (unaff_x20 != 0) {
        iStack_f4 = 2;
      }
      iVar11 = 0x7ea2;
      iVar6 = iStack_f4;
      break;
    case 7:
      if (unaff_x27 == 0) {
        unaff_x27 = 0;
        iStack_f4 = 0xb;
        iVar6 = iStack_f4;
      }
      else {
        iStack_f4 = 9;
        iVar6 = iStack_f4;
      }
      break;
    case 8:
    case 0xe:
      if (___stack_chk_guard != lVar3) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    case 9:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x27);
      iStack_f4 = 0xb;
      iVar6 = iStack_f4;
      break;
    case 0xb:
      lStack_118 = (**(code **)(*param_1 + 0x2f0))(param_1,unaff_x20,param_3[2],param_3[1]);
      if (lStack_118 == 0) {
        lStack_118 = 0;
        iStack_f4 = 1;
        iVar6 = iStack_f4;
      }
      else {
        iStack_f4 = 0xd;
        iVar6 = iStack_f4;
      }
      break;
    case 0xc:
      iVar11 = ((uint)(iVar11 * 0x8422) >> 0x14) * -0x1f + iVar11;
      unaff_x20 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      pcVar10 = (char *)param_3[1];
LAB_0016ae08:
      do {
        lVar2 = DAT_0018ea70;
        if (DAT_0018ea70 == 0) {
          cVar5 = '\x01';
          bVar1 = (bool)ExclusiveMonitorPass(0x18ea70,0x10);
          if (bVar1) {
            DAT_0018ea70 = 1;
            cVar5 = ExclusiveMonitorsStatus();
          }
          if (cVar5 != '\0') goto LAB_0016ae08;
        }
      } while (lVar2 == 1);
      if (lVar2 != 2) {
        DAT_0018ea36 = 0x4c;
        DAT_0018ea37 = 0;
        DAT_0018ea70 = 2;
      }
      sVar7 = strlen(&DAT_0018ea36);
      iVar6 = strncmp(pcVar10,&DAT_0018ea36,sVar7);
      if (iVar6 == 0) {
        pcVar10 = (char *)param_3[1];
LAB_0016ae84:
        do {
          lVar2 = DAT_0018ea68;
          if (DAT_0018ea68 == 0) {
            cVar5 = '\x01';
            bVar1 = (bool)ExclusiveMonitorPass(0x18ea68,0x10);
            if (bVar1) {
              DAT_0018ea68 = 1;
              cVar5 = ExclusiveMonitorsStatus();
            }
            if (cVar5 != '\0') goto LAB_0016ae84;
          }
        } while (lVar2 == 1);
        if (lVar2 != 2) {
          DAT_0018ea35 = 0;
          DAT_0018ea34 = 0x3b;
          DAT_0018ea68 = 2;
        }
        uVar4 = 4;
        do {
          uVar9 = uVar4;
          if (4 < uVar9) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          uVar4 = (uint)(pcVar10 != (char *)0x0) << 1;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(uVar9) {
          case 0:
            goto switchD_0016af08_caseD_0;
          case 2:
            sVar7 = strlen(pcVar10);
            sVar8 = strlen(&DAT_0018ea34);
            if (sVar7 <= sVar8 - 1) goto switchD_0016af08_caseD_0;
            uVar4 = 1;
          }
        } while( true );
      }
switchD_0016af08_caseD_0:
      iStack_f4 = 0xd - iVar11;
      iVar11 = 0x6cd1 - iVar11;
      iVar6 = iStack_f4;
      break;
    case 0xd:
      (**(code **)(*param_1 + 0x360))(param_1,param_2,lStack_118,param_4);
      iStack_f4 = 10;
      iVar6 = iStack_f4;
    }
  } while( true );
}


/* EXPORT index=247 ELF_VA=0x6b178 size=1280 source_sha256=c5f48cc07b0ef6c90bad97ec8674a7d91fd48da3737b9ea0a06351db95e8087e */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0016b4f8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___5l5IO__OI0I_l_l_0_OOl5O__5_II_Oll0__0Sl_0I5__ISS5_
               (long *param_1,undefined8 param_2,undefined8 *param_3)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  long lVar7;
  undefined8 uVar8;
  uint uVar9;
  long unaff_x25;
  char *pcVar10;
  long unaff_x28;
  
  uVar8 = 8;
  do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch(uVar8) {
    case 0:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x25);
      uVar8 = 0xf;
      break;
    case 2:
      if (unaff_x25 == 0) {
        unaff_x25 = 0;
        uVar8 = 0xf;
      }
      else {
        uVar8 = 0;
      }
      break;
    case 4:
      uVar8 = 9;
      break;
    case 6:
      lVar7 = (**(code **)(*param_1 + 0x2f0))(param_1,unaff_x25,param_3[2],param_3[1]);
      if (lVar7 == 0) {
        uVar8 = 0xc;
      }
      else {
        uVar8 = 5;
      }
      break;
    case 8:
      unaff_x25 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
      pcVar10 = (char *)param_3[1];
LAB_0016b31c:
      do {
        lVar7 = DAT_0018ea60;
        if (DAT_0018ea60 == 0) {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(0x18ea60,0x10);
          if (bVar2) {
            DAT_0018ea60 = 1;
            cVar1 = ExclusiveMonitorsStatus();
          }
          if (cVar1 != '\0') goto LAB_0016b31c;
        }
      } while (lVar7 == 1);
      if (lVar7 != 2) {
        DAT_0018ea33 = 0;
        DAT_0018ea32 = 0x4c;
        DAT_0018ea60 = 2;
      }
      sVar5 = strlen(&DAT_0018ea32);
      iVar4 = strncmp(pcVar10,&DAT_0018ea32,sVar5);
      if (iVar4 == 0) {
        pcVar10 = (char *)param_3[1];
LAB_0016b3a0:
        do {
          lVar7 = DAT_0018ea58;
          if (DAT_0018ea58 == 0) {
            cVar1 = '\x01';
            bVar2 = (bool)ExclusiveMonitorPass(0x18ea58,0x10);
            if (bVar2) {
              DAT_0018ea58 = 1;
              cVar1 = ExclusiveMonitorsStatus();
            }
            if (cVar1 != '\0') goto LAB_0016b3a0;
          }
        } while (lVar7 == 1);
        if (lVar7 != 2) {
          DAT_0018ea31 = 0;
          DAT_0018ea30 = 0x3b;
          DAT_0018ea58 = 2;
        }
        uVar3 = 4;
        do {
          uVar9 = uVar3;
          if (4 < uVar9) {
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          uVar3 = (uint)(pcVar10 != (char *)0x0) << 1;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(uVar9) {
          case 0:
            goto switchD_0016b42c_caseD_0;
          case 2:
            sVar5 = strlen(pcVar10);
            sVar6 = strlen(&DAT_0018ea30);
            if (sVar5 <= sVar6 - 1) goto switchD_0016b42c_caseD_0;
            uVar3 = 1;
          }
        } while( true );
      }
switchD_0016b42c_caseD_0:
      uVar8 = 6;
      break;
    case 10:
      (**(code **)(*param_1 + 0x88))(param_1);
      if (unaff_x28 == 0) {
        unaff_x28 = 0;
        uVar8 = 0xd;
      }
      else {
        uVar8 = 4;
      }
      break;
    case 0xc:
      uVar8 = 2;
      break;
    case 0xe:
      if (unaff_x28 == 0) {
        unaff_x28 = 0;
        uVar8 = 6;
      }
      else {
        uVar8 = 1;
      }
    }
  } while( true );
}


/* EXPORT index=248 ELF_VA=0x6b6cc size=2680 source_sha256=2cbf0c379864a6369bfda566e9f108ce5023b5270641e5daeca1131176e8eec0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___l_I_5_0l0IO_IIO0l_l_ll5_0I5_SO_lIIlllI0ISSI550_S5_
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,long *param_4,
               undefined8 param_5,undefined8 *param_6,undefined4 param_7)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  byte bVar6;
  ulong uVar7;
  long unaff_x23;
  long unaff_x24;
  ulong *unaff_x25;
  uint uVar8;
  uint uVar9;
  undefined1 auVar10 [16];
  int iStack_b8;
  ulong uStack_b0;
  ulong uStack_a8;
  ulong uStack_a0;
  undefined8 uStack_98;
  ulong uStack_90;
  undefined8 uStack_88;
  undefined1 auStack_78 [16];
  long lStack_68;
  
  auVar10._8_8_ = param_5;
  auVar10._0_8_ = param_4;
  lStack_68 = ___stack_chk_guard;
  uStack_88 = 0x6d43490759256345;
  uStack_90 = 0x6264703a0a095942;
  uStack_98 = 0x3f27512c551d507f;
  uStack_a0 = 0x2e6f7c61434b7716;
  uStack_a8 = 0x4f73457c436c6872;
  uStack_b0 = 0x590e19482f3f1671;
  iStack_b8 = 8;
  uVar8 = 0x4f9f;
  uVar9 = 0x5d60cb9b;
  iVar5 = 8;
switchD_0016b778_default:
  bVar6 = (byte)uVar9;
  switch(iVar5) {
  case 0:
    iVar5 = 5;
    iStack_b8 = 5;
    goto switchD_0016b778_default;
  case 1:
    auVar10 = (**(code **)(*param_4 + 0x368))(param_4,param_5,unaff_x23,param_7);
    iVar5 = 0x17;
    iStack_b8 = 0x17;
    goto switchD_0016b778_default;
  case 2:
    uVar9 = uVar9 ^ 0x5863535c;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0xb709cf9d)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0xb709cf9d)) ^ (char)uVar9 + 0xb0U;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0xb709cf7e)) =
         bVar6 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0xb709cf7e)) ^ 0xeb;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0xb709cfa6)) =
         bVar6 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0xb709cfa6)) ^ 0x83;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0xb709cfa9)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0xb709cfa9)) ^ (char)uVar9 - 0x30U;
    do {
      unaff_x25 = &uStack_b0;
      CallSupervisor(0);
    } while (unaff_x25 == (ulong *)0xfffffffffffffffc);
    do {
      auVar10._8_8_ = auStack_78;
      auVar10._0_8_ = unaff_x25;
      CallSupervisor(0);
    } while (unaff_x25 == (ulong *)0xfffffffffffffffc);
    iStack_b8 = (0x2d - uVar8) + (uVar8 / 0x3b) * 0x3b;
    iVar5 = iStack_b8;
    goto switchD_0016b778_default;
  case 3:
    iVar5 = uVar9 * 4;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x10822b)) =
         bVar6 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x10822b)) ^ 0x31;
    uVar9 = iVar5 + 0x14bc7a12U & 0x88f09da8;
    *(byte *)((long)&uStack_b0 + (ulong)(iVar5 - 0x4207f8)) =
         (char)iVar5 + 0x6cU ^ *(byte *)((long)&uStack_b0 + (ulong)(iVar5 - 0x4207f8)) ^ 0x23;
    iStack_b8 = 0x15;
    iVar5 = 0x15;
    goto switchD_0016b778_default;
  case 4:
    iStack_b8 = (0x30 - uVar8) + (uVar8 / 0x3b) * 0x3b;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x1aff017e)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x1aff017e)) ^ bVar6 - 0x1e;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x1aff0141)) =
         bVar6 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x1aff0141)) ^ 100;
    uVar1 = uVar9 + 0xe500fedc;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0xe500feb1)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0xe500feb1)) ^ bVar6 - 0x1c;
    uVar9 = uVar9 << 2 ^ 0xb04ae4ca;
    *(byte *)((long)&uStack_b0 + (ulong)uVar1) =
         bVar6 ^ *(byte *)((long)&uStack_b0 + (ulong)uVar1) ^ 0x34;
    iVar5 = iStack_b8;
    goto switchD_0016b778_default;
  case 5:
    uVar9 = uVar9 * uVar9 * 2 + 0xcfc5d5d;
    break;
  case 6:
    uVar9 = uVar9 + 0xfbfdc6a4;
    auVar10 = (**(code **)(*param_4 + 0xb8))(param_4,unaff_x24);
    goto LAB_0016c0fc;
  case 7:
    if (iStack_b8 < 0) {
                    /* WARNING: Read-only address (ram,0x0016c04c) is written */
      uRam000000000016c04c = param_3;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    iStack_b8 = (2 - uVar8) + (uVar8 / 0x1d) * 0x1d;
    iVar5 = iStack_b8;
    goto switchD_0016b778_default;
  case 8:
    uVar9 = uVar9 & 0x222e8787;
    unaff_x24 = (**(code **)(*param_4 + 0x30))(param_4,*param_6);
    auVar10 = (**(code **)(*param_4 + 0x2f0))(param_4,unaff_x24,param_6[2],param_6[1]);
    unaff_x23 = auVar10._0_8_;
    iStack_b8 = 7;
    if (unaff_x23 != 0) {
      iStack_b8 = 1;
    }
    uVar8 = 0x3319;
    iVar5 = iStack_b8;
    goto switchD_0016b778_default;
  case 9:
    uVar7 = (ulong)(uVar9 * uVar9 + 0x1c8579da);
    *(byte *)((long)&uStack_b0 + uVar7) = *(byte *)((long)&uStack_b0 + uVar7) ^ bVar6 * bVar6 - 0x12
    ;
    uVar1 = uVar9 * uVar9 & 0x4c063622;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar1 + 0xbffdfa0e)) =
         (byte)uVar1 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar1 + 0xbffdfa0e)) ^ 0x32;
    uVar9 = uVar1 * 2;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar1 + 0xbffdfa29)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar1 + 0xbffdfa29)) ^ (byte)uVar1 + 0x3a;
    iStack_b8 = (0x33 - uVar8) + (uVar8 / 0x3b) * 0x3b;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0x7ffbf40d)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0x7ffbf40d)) ^ (char)uVar9 + 0x54U;
    iVar5 = iStack_b8;
    goto switchD_0016b778_default;
  case 10:
    uVar8 = uVar9 + 0xcf23b6ad;
    uVar9 = (uVar9 * 4 + 0xebf891f0 ^ 0x81868190) + 0x6ce7e5b2;
    iStack_b8 = 9;
    *(byte *)((long)&uStack_b0 + (ulong)uVar8) =
         bVar6 ^ *(byte *)((long)&uStack_b0 + (ulong)uVar8) ^ 0x3b;
    uVar8 = 0x7dbc;
    iVar5 = 9;
    goto switchD_0016b778_default;
  case 0xb:
    uVar1 = uVar9 ^ 0x95d72b68;
    uVar7 = (ulong)(uVar1 + 0x79c6d5b8);
    *(byte *)((long)&uStack_b0 + (ulong)(uVar1 + 0x79c6d5d6)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar1 + 0x79c6d5d6)) ^ (char)uVar1 + 0x12U;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar1 + 0x79c6d5c4)) =
         bVar6 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar1 + 0x79c6d5c4)) ^ 0xd;
    uVar9 = uVar1 + 0xce1b7c8c;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar1 + 0x79c6d5d7)) =
         bVar6 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar1 + 0x79c6d5d7)) ^ 0x76;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x5454a6ce)) =
         (byte)uVar9 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x5454a6ce)) ^ 0xfe;
    iStack_b8 = 0x14;
    bVar6 = *(byte *)((long)&uStack_b0 + uVar7) ^ (char)uVar1 - 0x17U;
    goto LAB_0016c098;
  case 0xc:
    uVar9 = (uVar9 * uVar9 * 0x10 ^ 0x3214f97c) + 0x9242768c;
    iStack_b8 = 0x16;
    iVar5 = 0x16;
    goto switchD_0016b778_default;
  case 0xd:
    uVar9 = uVar9 << 1;
    if (unaff_x24 == 0) {
      unaff_x24 = 0;
LAB_0016c0fc:
      iStack_b8 = 0x18;
      iVar5 = 0x18;
    }
    else {
      iStack_b8 = 6;
      iVar5 = 6;
    }
    goto switchD_0016b778_default;
  case 0xe:
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x9cfa7666)) =
         bVar6 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x9cfa7666)) ^ 0x37;
    uVar8 = uVar9 ^ 0x2d8a5ce6;
    uVar9 = uVar8 * 8 + 0x85140f88;
    iStack_b8 = 2;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar8 + 0x4e8fd596)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar8 + 0x4e8fd596)) ^ (char)uVar8 - 0xbU;
    uVar8 = 0x39bf;
    iVar5 = 2;
    goto switchD_0016b778_default;
  case 0xf:
    uVar9 = uVar9 << 1 ^ 0x4a616c02;
    uVar1 = uVar9 + 0xb28f6066;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar1 ^ 0xaf9c0f7c)) =
         (byte)uVar1 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar1 ^ 0xaf9c0f7c)) ^ 3;
    uVar7 = (ulong)(uVar1 ^ 0xaf9c0f78);
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0x2f35107)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0x2f35107)) ^ (char)uVar9 + 0x3eU;
    iStack_b8 = 0x11;
    uVar9 = uVar1 * 2;
    bVar6 = (byte)uVar1 ^ *(byte *)((long)&uStack_b0 + uVar7) ^ 0x75;
    goto LAB_0016be8c;
  case 0x10:
    uVar1 = uVar9 + 0x5bc8dcc7 ^ 0x37c541c2;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x512757fc)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x512757fc)) ^ bVar6 + 0x75;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar1 + 0x64ca8ab0)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar1 + 0x64ca8ab0)) ^ (char)uVar1 - 2U;
    uVar7 = (ulong)(uVar1 * -0x341c0dac + 0x630589ad);
    uVar9 = uVar1 * -0x341c0dac;
    *(byte *)((long)&uStack_b0 + uVar7) =
         *(byte *)((long)&uStack_b0 + uVar7) ^ (char)uVar1 * 'T' - 0x32U;
    iStack_b8 = 0xe;
    iVar5 = 0xe;
    goto switchD_0016b778_default;
  case 0x11:
    iVar5 = uVar9 * 2;
    iVar3 = iVar5 * iVar5;
    cVar4 = (char)iVar5;
    *(byte *)((long)&uStack_b0 + (ulong)(iVar3 + 0x7f03bf18)) =
         *(byte *)((long)&uStack_b0 + (ulong)(iVar3 + 0x7f03bf18)) ^ cVar4 * cVar4 + 0x4fU;
    iStack_b8 = 3;
    *(byte *)((long)&uStack_b0 + (ulong)(iVar3 + 0x7f03bf0f)) =
         *(byte *)((long)&uStack_b0 + (ulong)(iVar3 + 0x7f03bf0f)) ^ cVar4 * cVar4 + 0x6dU;
    uVar7 = (ulong)(iVar3 + 0x7f03bf1b);
    uVar9 = iVar5 * iVar5 * 2 & 0xe4179730;
    bVar6 = (byte)(iVar5 * iVar5) ^ *(byte *)((long)&uStack_b0 + uVar7) ^ 0x31;
LAB_0016be8c:
    *(byte *)((long)&uStack_b0 + uVar7) = bVar6;
    iVar5 = iStack_b8;
    goto switchD_0016b778_default;
  case 0x12:
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0x7ffbf422)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0x7ffbf422)) ^ bVar6 + 0x33;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0x7ffbf403)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0x7ffbf403)) ^ bVar6 + 0x23;
    uVar1 = uVar9 * 2;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x80040c2f)) =
         bVar6 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar9 ^ 0x80040c2f)) ^ 0x6d;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar1 - 0x817f0)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar1 - 0x817f0)) ^ (byte)uVar1 + 0x7f;
    uVar9 = uVar1 ^ 0x13e61939;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar1 - 0x817ee)) =
         (byte)uVar1 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar1 - 0x817ee)) ^ 0x33;
    iStack_b8 = 0xb;
    iVar5 = 0xb;
    goto switchD_0016b778_default;
  case 0x13:
    uStack_a8 = uStack_a8 ^ 0x31000000;
    uStack_90 = uStack_90 ^ 0x23000000;
    uStack_a0 = uStack_a0 ^ 0x6300000900000000;
    iStack_b8 = 10;
    uStack_b0 = uStack_b0 ^ 0x340000000000;
    uVar9 = 0x30dc495f;
    iVar5 = 10;
    goto switchD_0016b778_default;
  case 0x14:
    iVar5 = uVar9 * 4;
    uVar7 = (ulong)(uVar9 * 2 + 0x5756b26c);
    *(byte *)((long)&uStack_b0 + uVar7) =
         *(byte *)((long)&uStack_b0 + uVar7) ^ (char)(uVar9 * 2) + 0xa5U;
    uVar9 = iVar5 + 0xc9ac65dc;
    uVar7 = (ulong)(iVar5 + 0xaead64b1);
    iStack_b8 = 4;
    *(byte *)((long)&uStack_b0 + uVar7) = (byte)uVar9 ^ *(byte *)((long)&uStack_b0 + uVar7) ^ 100;
    uVar8 = 0x16f2;
    iVar5 = 4;
    goto switchD_0016b778_default;
  case 0x15:
    uVar2 = uVar9 << 1;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 - 0xf07fea)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar9 - 0xf07fea)) ^ bVar6 + 0x5f;
    uVar1 = uVar9 - 0xf07fe4;
    uVar9 = uVar2 ^ 0x50c657e6;
    *(byte *)((long)&uStack_b0 + (ulong)uVar1) =
         *(byte *)((long)&uStack_b0 + (ulong)uVar1) ^ bVar6 + 100;
    uVar7 = (ulong)(uVar9 + 0xaed8a821);
    *(byte *)((long)&uStack_b0 + (ulong)(uVar2 ^ 0x1e10006)) =
         *(byte *)((long)&uStack_b0 + (ulong)(uVar2 ^ 0x1e10006)) ^ (char)uVar9 + 0x79U;
    *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0xaed8a83e)) =
         (byte)uVar2 ^ *(byte *)((long)&uStack_b0 + (ulong)(uVar9 + 0xaed8a83e)) ^ 9;
    iStack_b8 = 0x10;
    bVar6 = *(byte *)((long)&uStack_b0 + uVar7) ^ (char)uVar9 + 0x7dU;
LAB_0016c098:
    *(byte *)((long)&uStack_b0 + uVar7) = bVar6;
    iVar5 = iStack_b8;
    goto switchD_0016b778_default;
  case 0x16:
    goto switchD_0016b778_caseD_16;
  case 0x18:
    goto switchD_0016b778_caseD_18;
  default:
    goto switchD_0016b778_default;
  }
  iStack_b8 = 0xd;
  iVar5 = 0xd;
  goto switchD_0016b778_default;
switchD_0016b778_caseD_16:
  uVar9 = uVar9 << 1;
  auVar10._8_4_ = uVar9 ^ 0x94931b91;
  auVar10._0_8_ = unaff_x25;
  auVar10._12_4_ = 0;
  do {
    CallSupervisor(0);
  } while (unaff_x25 == (ulong *)0xfffffffffffffffc);
  iStack_b8 = 0;
  iVar5 = 0;
  goto switchD_0016b778_default;
switchD_0016b778_caseD_18:
  if (___stack_chk_guard != lStack_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(auVar10._0_8_,auVar10._8_8_);
  }
  return;
}


/* EXPORT index=249 ELF_VA=0x6c1a8 size=444 source_sha256=3df64cff9c6213b261b99461038a3e4ef6db834b66e09d2dcf05fd74fdcdd037 */

void j___50SlI_IO5OO_IS05__5__5I_l5lO0l__l_S00II0IISIlS5S5_
               (undefined8 param_1,long *param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined4 uVar1;
  long unaff_x22;
  long unaff_x23;
  
  uVar1 = 8;
  do {
    switch(uVar1) {
    case 0:
      uVar1 = 10;
      if (unaff_x22 != 0) {
        uVar1 = 4;
      }
      break;
    case 1:
    case 2:
    case 6:
    case 9:
      uVar1 = 0;
      break;
    case 3:
      unaff_x22 = (**(code **)(*param_2 + 0x30))(param_2,*param_4);
      unaff_x23 = (**(code **)(*param_2 + 0x2f0))(param_2,unaff_x22,param_4[2],param_4[1]);
      uVar1 = 0;
      if (unaff_x23 != 0) {
        uVar1 = 2;
      }
      break;
    case 4:
      (**(code **)(*param_2 + 0xb8))(param_2,unaff_x22);
      uVar1 = 10;
      break;
    case 5:
      (**(code **)(*param_2 + 0x378))(param_1,param_2,param_3,unaff_x23);
      uVar1 = 1;
      break;
    case 7:
      unaff_x22 = (**(code **)(*param_2 + 0x30))(param_2,*param_4);
      unaff_x23 = (**(code **)(*param_2 + 0x2f0))(param_2,unaff_x22,param_4[2],param_4[1]);
      uVar1 = 3;
      if (unaff_x23 == 0) {
        uVar1 = 4;
      }
      break;
    case 8:
      unaff_x22 = (**(code **)(*param_2 + 0x30))(param_2,*param_4);
      unaff_x23 = (**(code **)(*param_2 + 0x2f0))(param_2,unaff_x22,param_4[2],param_4[1]);
      uVar1 = 5;
      if (unaff_x23 == 0) {
        uVar1 = 6;
      }
      break;
    case 10:
      return;
    }
  } while( true );
}


/* EXPORT index=250 ELF_VA=0x6c390 size=432 source_sha256=207a84452fd84843fcd301d479f68fe47a9a6851ee6ad84fe0b050d25f68c6b3 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0016c440) */

void j___Il_O__IIIIl_IIISO_S__Sl_l_II0_lllI0S__S_IOS0IO5S5_
               (long *param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  long unaff_x23;
  long unaff_x24;
  
  uVar1 = 6;
switchD_0016c418_default:
  switch(uVar1) {
  case 0:
    (**(code **)(*param_1 + 0xb8))(param_1,unaff_x23);
    break;
  case 1:
    uVar1 = 2;
    goto switchD_0016c418_default;
  case 2:
    (**(code **)(*param_1 + 0x370))(param_1,param_2,unaff_x24,param_4);
    uVar1 = 4;
    goto switchD_0016c418_default;
  case 3:
  case 4:
    uVar1 = 5;
    goto switchD_0016c418_default;
  case 5:
    if (unaff_x23 != 0) {
      uVar1 = 0;
      goto switchD_0016c418_default;
    }
    unaff_x23 = 0;
    break;
  case 6:
    goto switchD_0016c418_caseD_6;
  case 7:
    goto switchD_0016c418_caseD_7;
  default:
    goto switchD_0016c418_default;
  }
  uVar1 = 7;
  goto switchD_0016c418_default;
switchD_0016c418_caseD_6:
  unaff_x23 = (**(code **)(*param_1 + 0x30))(param_1,*param_3);
  unaff_x24 = (**(code **)(*param_1 + 0x2f0))(param_1,unaff_x23,param_3[2],param_3[1]);
  if (unaff_x24 == 0) {
    unaff_x24 = 0;
    uVar1 = 3;
  }
  else {
    uVar1 = 1;
  }
  goto switchD_0016c418_default;
switchD_0016c418_caseD_7:
  return;
}


/* EXPORT index=251 ELF_VA=0x6c560 size=1312 source_sha256=2d222e957ccc33efedbcfdcd4f23ebee3ed3fee36a88ce4e436f1af5cb55c9b1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___IIlII_IS0_I_O_III__ISII____5l550_lOOlIOII0S_O0IS5_
               (undefined8 param_1,long *param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  undefined4 uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  long unaff_x22;
  long unaff_x23;
  uint uVar10;
  undefined1 auVar11 [16];
  ulong uStack_a0;
  undefined1 uStack_98;
  byte bStack_97;
  undefined2 uStack_96;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined7 uStack_8c;
  byte bStack_85;
  long lStack_78;
  
  auVar11._8_8_ = param_3;
  auVar11._0_8_ = param_2;
  uVar6 = 7;
  uVar10 = 0x4c455b91;
  lStack_78 = ___stack_chk_guard;
  uStack_8c = 0x713030a74476a;
  bStack_85 = 0x77;
  uStack_90 = 0x5c0b3441;
  uStack_98 = 0xf;
  bStack_97 = 0x1c;
  uStack_96 = 0x7331;
  uStack_94 = 0xd0b3b13;
  uStack_a0 = 0x6c22206c1a441366;
  do {
    bVar4 = (byte)uVar10;
    switch(uVar6) {
    case 0:
      bStack_97 = bStack_97 ^ 0x21;
      bStack_85 = bStack_85 ^ 0x77;
      uVar6 = 0xd;
      uStack_a0 = uStack_a0 ^ 0xd00000000;
      uVar10 = 0x353b7f95;
      break;
    case 1:
      iVar1 = uVar10 * uVar10;
      uVar8 = (ulong)(uVar10 * uVar10 + 0x4ec37278);
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0x359e9b9e)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0x359e9b9e)) ^ bVar4 - 0xc;
      uVar9 = (ulong)(iVar1 * iVar1 + 0x36380f00);
      uVar7 = (ulong)(iVar1 * iVar1 + 0x36380f15);
      *(byte *)((long)&uStack_a0 + uVar8) =
           *(byte *)((long)&uStack_a0 + uVar8) ^ bVar4 * bVar4 - 0x1c;
      *(byte *)((long)&uStack_a0 + uVar7) =
           *(byte *)((long)&uStack_a0 + uVar7) ^ (char)iVar1 * (char)iVar1 + 0x54U;
      uVar10 = iVar1 * iVar1 + 0x70c22e67;
      *(byte *)((long)&uStack_a0 + uVar9) =
           (byte)uVar10 ^ *(byte *)((long)&uStack_a0 + uVar9) ^ 0x51;
      uVar6 = 0xc;
      break;
    case 2:
      uVar6 = 0xe;
      if (unaff_x22 != 0) {
        uVar6 = 6;
      }
      break;
    case 3:
    case 5:
      uVar6 = 2;
      break;
    case 4:
      iVar1 = uVar10 + 0xb74a4a92;
      uVar7 = (ulong)(iVar1 * iVar1 + 0x7db9cbd6);
      uVar8 = (ulong)(iVar1 * iVar1 + 0x7db9cbe6);
      cVar5 = (char)iVar1;
      uVar9 = (ulong)(iVar1 * iVar1 ^ 0x82463437);
      *(byte *)((long)&uStack_a0 + uVar8) =
           *(byte *)((long)&uStack_a0 + uVar8) ^ cVar5 * cVar5 - 0x10U;
      *(byte *)((long)&uStack_a0 + uVar9) =
           *(byte *)((long)&uStack_a0 + uVar9) ^ cVar5 * cVar5 + 0x39U;
      uVar10 = iVar1 * iVar1 & 0x41431256;
      *(byte *)((long)&uStack_a0 + uVar7) =
           *(byte *)((long)&uStack_a0 + uVar7) ^ cVar5 * cVar5 + 0x23U;
      uVar6 = 9;
      break;
    case 6:
      auVar11 = (**(code **)(*param_2 + 0xb8))(param_2,unaff_x22);
      uVar6 = 0xe;
      break;
    case 7:
      unaff_x22 = (**(code **)(*param_2 + 0x30))(param_2,*param_4);
      auVar11 = (**(code **)(*param_2 + 0x2f0))(param_2,unaff_x22,param_4[2],param_4[1]);
      unaff_x23 = auVar11._0_8_;
      uVar6 = 8;
      if (unaff_x23 != 0) {
        uVar6 = 0xb;
      }
      break;
    case 8:
      uVar6 = 5;
      break;
    case 9:
      uVar3 = uVar10 ^ 0x702f0baa;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar3 + 0x8f92e455)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar3 + 0x8f92e455)) ^ (char)uVar3 + 0x8aU;
      uVar2 = uVar10 ^ 0x421003;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar3 + 0x8f92e452)) =
           bVar4 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar3 + 0x8f92e452)) ^ 0x5e;
      uVar10 = uVar3 * 4;
      *(byte *)((long)&uStack_a0 + (ulong)uVar2) =
           bVar4 ^ *(byte *)((long)&uStack_a0 + (ulong)uVar2) ^ 0x3d;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0x3e4b911a)) =
           (byte)uVar10 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0x3e4b911a)) ^ 0x92;
      uVar6 = 10;
      break;
    case 10:
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 ^ 0xc1b46ee6)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar10 ^ 0xc1b46ee6)) ^ bVar4 + 0x4e;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0x3e4b9125)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0x3e4b9125)) ^ bVar4 + 0x8f;
      do {
        auVar11._8_8_ = 0x3c;
        auVar11._0_8_ = &uStack_a0;
        CallSupervisor(0);
      } while (&uStack_a0 == (ulong *)0xfffffffffffffffc);
      uVar6 = 8;
      break;
    case 0xb:
      auVar11 = (**(code **)(*param_2 + 0x380))(param_1,param_2,param_3,unaff_x23);
      uVar6 = 3;
      break;
    case 0xc:
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 ^ 0x3a8a1f7f)) =
           bVar4 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar10 ^ 0x3a8a1f7f)) ^ 7;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 ^ 0x3a8a1f64)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar10 ^ 0x3a8a1f64)) ^ bVar4 + 0xc;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0xc575e0a9)) =
           bVar4 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0xc575e0a9)) ^ 0x1d;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 ^ 0x3a8a1f6c)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar10 ^ 0x3a8a1f6c)) ^ bVar4 + 0xbd;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0xc575e09e)) =
           bVar4 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0xc575e09e)) ^ 0x4a;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0xc575e0b3)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0xc575e0b3)) ^ bVar4 - 0x19;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0xc575e0b2)) =
           bVar4 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0xc575e0b2)) ^ 0x43;
      uVar6 = 4;
      break;
    case 0xd:
      uVar3 = uVar10 << 1;
      uVar10 = uVar3 ^ 0xa0179b46;
      cVar5 = (char)uVar10;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar3 ^ 0x6a76ff2b)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar3 ^ 0x6a76ff2b)) ^ cVar5 - 0x28U;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0x359e9ba5)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0x359e9ba5)) ^ cVar5 + 7U;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar3 ^ 0x6a76ff3e)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar3 ^ 0x6a76ff3e)) ^ cVar5 - 2U;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar3 ^ 0x6a76ff38)) =
           (byte)uVar3 ^ *(byte *)((long)&uStack_a0 + (ulong)(uVar3 ^ 0x6a76ff38)) ^ 0x27;
      *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0x359e9baa)) =
           *(byte *)((long)&uStack_a0 + (ulong)(uVar10 + 0x359e9baa)) ^ cVar5 + 8U;
      uVar6 = 1;
      break;
    case 0xe:
      if (___stack_chk_guard == lStack_78) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(auVar11._0_8_,auVar11._8_8_);
    }
  } while( true );
}


/* EXPORT index=252 ELF_VA=0x6cabc size=748 source_sha256=08dd4fb8eff472f616dd1805d991f48a79ad60c63a5ecd0a29f76119d3bba93e */

/* WARNING: Exceeded maximum restarts with more pending */

undefined4 j___S_IIl_I5Ill_5_0ll_l0OI__l5550_IlI_5OSIll0Ol0I__S5_(long *param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 unaff_x21;
  undefined4 unaff_w23;
  
  iVar2 = 3;
  do {
    uVar3 = 3;
    switch(iVar2) {
    case 0:
      do {
        switch(uVar3) {
        case 0x16cc2c:
                    /* WARNING: This code block may not be properly labeled as switch case */
          uVar3 = 0;
          if (*(char *)param_2[1] != 'I') {
            uVar3 = 4;
          }
        }
      } while( true );
    case 1:
      lVar1 = FUN_0016cdf4(param_1,unaff_x21,param_2);
      iVar2 = (uint)(lVar1 == 0) << 2;
      break;
    case 2:
      uVar4 = 5;
      do {
        switch(uVar4) {
        case 0x16cd28:
                    /* WARNING: This code block may not be properly labeled as switch case */
          if (*(char *)param_2[1] == 'I') {
            uVar4 = 0;
          }
          else {
            uVar4 = 4;
          }
        }
      } while( true );
    case 3:
      unaff_x21 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
      lVar1 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x21,param_2[2],param_2[1]);
      iVar2 = 0x30;
      if (lVar1 != 0) {
        iVar2 = 0x31;
      }
      iVar2 = iVar2 + -0x2f;
      if (iVar2 == 5) {
        return unaff_w23;
      }
      break;
    case 4:
      j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
      return 0;
    }
  } while( true );
}


/* EXPORT index=253 ELF_VA=0x6cf28 size=804 source_sha256=482523c50dddf257a84f3ad2f3accc740c9c274166ef85fb2a157a8b364760ae */

/* WARNING: Exceeded maximum restarts with more pending */

uint j___OllI__OIII0_IIII__lI05___lSl5lIllOI50I0_ISO_l0OS5_(long *param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 unaff_x21;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0x4012;
  iVar2 = 4;
switchD_0016d0a8_default:
  uVar3 = 5;
  switch(iVar2) {
  case 0:
    goto switchD_0016d0a8_caseD_0;
  case 1:
    j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
    uVar4 = 0;
    break;
  case 2:
    goto switchD_0016d0a8_caseD_2;
  case 3:
    uVar4 = uVar5 % 0x4f;
    lVar1 = FUN_0016cdf4(param_1,unaff_x21,param_2);
    iVar2 = 0x38;
    if (lVar1 != 0) {
      iVar2 = 0x39;
    }
    iVar2 = iVar2 - uVar4;
    if (iVar2 != 5) goto switchD_0016d0a8_default;
    break;
  case 4:
    goto switchD_0016d0a8_caseD_4;
  default:
    goto switchD_0016d0a8_default;
  }
  return uVar4;
switchD_0016d0a8_caseD_4:
  unaff_x21 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
  lVar1 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x21,param_2[2],param_2[1]);
  iVar2 = 3;
  if (lVar1 != 0) {
    iVar2 = 0;
  }
  uVar5 = 0x7faa;
  goto switchD_0016d0a8_default;
switchD_0016d0a8_caseD_2:
  do {
    switch(uVar3) {
    case 0x16d070:
                    /* WARNING: This code block may not be properly labeled as switch case */
      uVar3 = 4;
      if (*(char *)param_2[1] != 'J') {
        uVar3 = 2;
      }
    }
  } while( true );
switchD_0016d0a8_caseD_0:
  uVar3 = 1;
  do {
    switch(uVar3) {
    case 0x16d14c:
                    /* WARNING: This code block may not be properly labeled as switch case */
      uVar3 = 5;
      if (*(char *)param_2[1] != 'J') {
        uVar3 = 2;
      }
    }
  } while( true );
}


/* EXPORT index=254 ELF_VA=0x6d2a0 size=488 source_sha256=98e61e11dd0f91c37eb3e264fbad76de324ccfd98b7cfa6d6776ac528b014496 */

long j___l0llO___II0_5l_ll_5Sl_5__SIO__l_IIOlS_SlOlIOl_IS5_(long *param_1,undefined8 *param_2)

{
  int iVar1;
  int iVar2;
  long *unaff_x21;
  long unaff_x22;
  long unaff_x24;
  uint uVar3;
  long lStack_78;
  long lStack_70;
  
  uVar3 = 0xbe0;
  iVar1 = 2;
  lStack_78 = 0;
  lStack_70 = lStack_78;
LAB_0016d350:
  iVar2 = 6;
  if (unaff_x24 != 0) {
    iVar2 = 3;
  }
LAB_0016d364:
switchD_0016d3ac_default:
  switch(iVar1) {
  case 0:
    goto switchD_0016d3ac_caseD_0;
  case 1:
    free(unaff_x21);
    unaff_x22 = lStack_70;
    break;
  case 2:
    unaff_x24 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
    lStack_78 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x24,param_2[2],param_2[1]);
    iVar1 = 0;
    if (lStack_78 != 0) {
      iVar1 = 9;
    }
    goto LAB_0016d350;
  case 3:
    (**(code **)(*param_1 + 0xb8))(param_1,unaff_x24);
    iVar1 = 6;
    goto switchD_0016d3ac_default;
  case 4:
    lStack_70 = (**(code **)(*param_1 + 0x488))(param_1,*unaff_x21,unaff_x21[1]);
    iVar1 = 1;
    if (*unaff_x21 != 0) {
      iVar1 = 5;
    }
    uVar3 = 0x476d;
    goto LAB_0016d364;
  case 5:
    (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x21);
    iVar1 = (8 - uVar3) + (uVar3 / 0x25) * 0x25;
    goto switchD_0016d3ac_default;
  case 7:
    j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
    unaff_x22 = 0;
    break;
  case 9:
    goto switchD_0016d3ac_caseD_9;
  default:
    goto switchD_0016d3ac_default;
  }
  return unaff_x22;
switchD_0016d3ac_caseD_9:
  unaff_x22 = (**(code **)(*param_1 + 0x488))(param_1,unaff_x24,lStack_78);
  iVar1 = iVar2;
  goto switchD_0016d3ac_default;
switchD_0016d3ac_caseD_0:
  unaff_x21 = (long *)FUN_0016cdf4(param_1,unaff_x24,param_2);
  iVar1 = 7;
  if (unaff_x21 != (long *)0x0) {
    iVar1 = 4;
  }
  goto LAB_0016d364;
}


/* EXPORT index=255 ELF_VA=0x6d4b4 size=588 source_sha256=7eb8af11051d0bb19347c95b7f720629b8499c40ce5e8e02f11028890fa9e141 */

uint j___llIO__0lIII_I_III_lII_0_IlIlIlII5II_II5SIO_ISO0S5_(long *param_1,undefined8 *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  long *unaff_x21;
  long unaff_x22;
  long unaff_x23;
  uint unaff_w24;
  int iVar4;
  uint uStack_68;
  
  uStack_68 = 0;
  iVar1 = 0x2073;
  iVar3 = 8;
  do {
    iVar4 = iVar1;
    iVar1 = iVar4;
    switch(iVar3) {
    case 0:
      (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x21);
      iVar3 = (0x87 - iVar4) + ((uint)(iVar4 * 0xdbec) >> 0x17) * 0x95;
      break;
    case 1:
      uVar2 = (**(code **)(*param_1 + 0x490))(param_1,unaff_x22,unaff_x23);
      unaff_w24 = uVar2 & 0xff;
      iVar3 = 3;
      if (unaff_x22 != 0) {
        iVar3 = 5;
      }
      iVar1 = 0x5674;
      if (unaff_x22 != 0) {
        iVar1 = iVar4;
      }
      break;
    case 2:
      uVar2 = (**(code **)(*param_1 + 0x490))(param_1,unaff_x22,unaff_x23);
      unaff_w24 = uVar2 & 0xff;
      iVar3 = 5;
      if (unaff_x22 != 0) {
        iVar3 = 8;
      }
      break;
    case 3:
      iVar4 = iVar4 + ((uint)(iVar4 * 0xdbec) >> 0x17) * -0x95;
      uStack_68 = (**(code **)(*param_1 + 0x490))(param_1,*unaff_x21,unaff_x21[1]);
      uStack_68 = uStack_68 & 0xff;
      iVar3 = 0x56;
      if (*unaff_x21 != 0) {
        iVar3 = 0x50;
      }
      iVar1 = 0x16ef - iVar4;
      iVar3 = iVar3 - iVar4;
      break;
    case 4:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x22);
      iVar3 = 9;
      break;
    case 5:
      j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
      unaff_w24 = 0;
switchD_0016d548_caseD_9:
      return unaff_w24;
    case 6:
      free(unaff_x21);
      return uStack_68;
    case 7:
      uVar2 = (**(code **)(*param_1 + 0x490))(param_1,unaff_x22,unaff_x23);
      unaff_w24 = uVar2 & 0xff;
      iVar3 = 9;
      if (unaff_x22 != 0) {
        iVar3 = 4;
      }
      break;
    case 8:
      unaff_x22 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
      unaff_x23 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x22,param_2[2],param_2[1]);
      iVar3 = 10;
      if (unaff_x23 != 0) {
        iVar3 = 7;
      }
      break;
    case 9:
    case 0xb:
      goto switchD_0016d548_caseD_9;
    case 10:
      unaff_x21 = (long *)FUN_0016cdf4(param_1,unaff_x22,param_2);
      iVar3 = 5;
      if (unaff_x21 != (long *)0x0) {
        iVar1 = 0x6d27;
        iVar3 = 3;
      }
    }
  } while( true );
}


/* EXPORT index=256 ELF_VA=0x6d730 size=572 source_sha256=4633bc7060c4bfbb38285fbac22fc54f433db8927ad61709d1123636dbd5aa29 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0016d8b8) */

uint j___l0I0I_0__OS_SOIS__ISS_S_0II_05_5lSIlI0SlOSlOIIlS5_(long *param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint unaff_w21;
  long *unaff_x22;
  long unaff_x23;
  long unaff_x24;
  uint unaff_w26;
  
  uVar2 = 9;
switchD_0016d798_default:
  switch(uVar2) {
  case 0:
    goto switchD_0016d798_caseD_0;
  case 1:
    unaff_x22 = (long *)FUN_0016cdf4(param_1,unaff_x23,param_2);
    if (unaff_x22 == (long *)0x0) {
      unaff_x22 = (long *)0x0;
      uVar2 = 2;
    }
    else {
      uVar2 = 4;
    }
    goto switchD_0016d798_default;
  case 2:
    j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
    return 0;
  case 3:
    uVar1 = (**(code **)(*param_1 + 0x4a0))(param_1,unaff_x23,unaff_x24);
    unaff_w21 = uVar1 & 0xffff;
    if (unaff_x23 != 0) {
      uVar2 = 10;
      goto switchD_0016d798_default;
    }
    unaff_x23 = 0;
    break;
  case 4:
    uVar1 = (**(code **)(*param_1 + 0x4a0))(param_1,*unaff_x22,unaff_x22[1]);
    unaff_w26 = uVar1 & 0xffff;
    if (*unaff_x22 == 0) goto LAB_0016d77c;
    uVar2 = 8;
    goto switchD_0016d798_default;
  case 5:
    (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x22);
    uVar2 = 5;
    goto switchD_0016d798_default;
  case 6:
  case 0xb:
    goto switchD_0016d798_caseD_6;
  case 7:
    (**(code **)(*param_1 + 0xb8))(param_1,unaff_x23);
    break;
  case 8:
    (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x22);
LAB_0016d77c:
    uVar2 = 0;
    goto switchD_0016d798_default;
  case 9:
    unaff_x23 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
    unaff_x24 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x23,param_2[2],param_2[1]);
    if (unaff_x24 == 0) {
      unaff_x24 = 0;
      uVar2 = 1;
    }
    else {
      uVar2 = 3;
    }
    goto switchD_0016d798_default;
  case 10:
    goto LAB_0016d8f0;
  default:
    goto switchD_0016d798_default;
  }
  uVar2 = 6;
  goto switchD_0016d798_default;
LAB_0016d8f0:
  uVar2 = 7;
  goto switchD_0016d798_default;
switchD_0016d798_caseD_0:
  free(unaff_x22);
  unaff_w21 = unaff_w26;
switchD_0016d798_caseD_6:
  return unaff_w21;
}


/* EXPORT index=257 ELF_VA=0x6d99c size=424 source_sha256=aec6bbc54bd5cb6ea2f152e6b1aa28ee682c345229ec9b3d00199bfd98e95f79 */

int j___SIlIl_O5III_5_SSI__lIlI_llOI____O_lI000_S5lO__lS5_(long *param_1,undefined8 *param_2)

{
  short sVar1;
  undefined4 uVar2;
  long *unaff_x21;
  int unaff_w22;
  long unaff_x23;
  long unaff_x24;
  undefined4 uVar3;
  int iStack_68;
  
  uVar2 = 6;
  iStack_68 = 0;
LAB_0016da2c:
  uVar3 = 1;
  if (unaff_x23 != 0) {
    uVar3 = 8;
  }
switchD_0016da6c_default:
  switch(uVar2) {
  case 0:
    free(unaff_x21);
    unaff_w22 = iStack_68;
    break;
  case 2:
    unaff_x21 = (long *)FUN_0016cdf4(param_1,unaff_x23,param_2);
    uVar2 = 3;
    if (unaff_x21 != (long *)0x0) {
      uVar2 = 7;
    }
    goto switchD_0016da6c_default;
  case 3:
    j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
    unaff_w22 = 0;
    break;
  case 4:
    (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x21);
    uVar2 = 0;
    goto switchD_0016da6c_default;
  case 5:
    sVar1 = (**(code **)(*param_1 + 0x4a8))(param_1,unaff_x23,unaff_x24);
    unaff_w22 = (int)sVar1;
    uVar2 = uVar3;
    goto switchD_0016da6c_default;
  case 6:
    goto switchD_0016da6c_caseD_6;
  case 7:
    sVar1 = (**(code **)(*param_1 + 0x4a8))(param_1,*unaff_x21,unaff_x21[1]);
    iStack_68 = (int)sVar1;
    uVar2 = 0;
    if (*unaff_x21 != 0) {
      uVar2 = 4;
    }
    goto switchD_0016da6c_default;
  case 8:
    goto switchD_0016da6c_caseD_8;
  default:
    goto switchD_0016da6c_default;
  }
  return unaff_w22;
switchD_0016da6c_caseD_8:
  (**(code **)(*param_1 + 0xb8))(param_1,unaff_x23);
  uVar2 = 1;
  goto switchD_0016da6c_default;
switchD_0016da6c_caseD_6:
  unaff_x23 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
  unaff_x24 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x23,param_2[2],param_2[1]);
  uVar2 = 2;
  if (unaff_x24 != 0) {
    uVar2 = 5;
  }
  goto LAB_0016da2c;
}


/* EXPORT index=258 ELF_VA=0x6db68 size=432 source_sha256=737adbf11d533473e9725c9d909388524d5faaa37f39c85113026a51a769f296 */

int j___S5III_lI5IS_l0IlI_OlI00_IlllI_0ISlII0_O0OSl_5O_S5_(long *param_1,undefined8 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  long *unaff_x21;
  int unaff_w22;
  long unaff_x23;
  undefined4 uVar3;
  long lStack_70;
  int iStack_68;
  
  uVar2 = 3;
  lStack_70 = 0;
  iStack_68 = 0;
LAB_0016dc00:
  uVar3 = 4;
  if (unaff_x23 != 0) {
    uVar3 = 6;
  }
LAB_0016dc24:
  switch(uVar2) {
  case 0:
    cVar1 = (**(code **)(*param_1 + 0x498))(param_1,*unaff_x21,unaff_x21[1]);
    iStack_68 = (int)cVar1;
    uVar2 = 8;
    if (*unaff_x21 != 0) {
      uVar2 = 2;
    }
    goto LAB_0016dc24;
  case 1:
    cVar1 = (**(code **)(*param_1 + 0x498))(param_1,unaff_x23,lStack_70);
    unaff_w22 = (int)cVar1;
    uVar2 = uVar3;
    goto LAB_0016dc24;
  case 2:
    (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x21);
    uVar2 = 8;
    goto LAB_0016dc24;
  case 3:
    goto switchD_0016dc38_caseD_3;
  case 4:
    break;
  case 5:
    unaff_x21 = (long *)FUN_0016cdf4(param_1,unaff_x23,param_2);
    uVar2 = 7;
    if (unaff_x21 != (long *)0x0) {
      uVar2 = 0;
    }
    goto LAB_0016dc24;
  case 6:
    goto switchD_0016dc38_caseD_6;
  case 7:
    j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
    unaff_w22 = 0;
    break;
  case 8:
    free(unaff_x21);
    unaff_w22 = iStack_68;
    break;
  default:
    goto switchD_0016dc38_default;
  }
  return unaff_w22;
switchD_0016dc38_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_0016dc38_caseD_6:
  (**(code **)(*param_1 + 0xb8))(param_1,unaff_x23);
  uVar2 = 4;
  goto LAB_0016dc24;
switchD_0016dc38_caseD_3:
  unaff_x23 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
  lStack_70 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x23,param_2[2],param_2[1]);
  uVar2 = 5;
  if (lStack_70 != 0) {
    uVar2 = 1;
  }
  goto LAB_0016dc00;
}


/* EXPORT index=259 ELF_VA=0x6dd3c size=760 source_sha256=912cb619b2887cafcb2a6ffae04e2bbf4fc0bab5aeae8599dc93b914f9696448 */

void j____I_l__I0_lI_OlIlO_IOlII_SIlO5llS_050S_I0___I0OlS5_
               (long *param_1,undefined8 *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long *unaff_x22;
  long unaff_x23;
  long unaff_x24;
  int iVar4;
  
  iVar4 = 0x3963;
  iVar3 = 0;
  do {
    iVar2 = 0xb;
    switch(iVar3) {
    case 0:
      iVar3 = iVar4 + ((uint)(iVar4 * 0xb217) >> 0x14) * -0x17;
      unaff_x23 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
      unaff_x24 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x23,param_2[2],param_2[1]);
      if (unaff_x24 == 0) {
        unaff_x24 = 0;
        iVar3 = 0x18 - iVar3;
      }
      else {
        iVar3 = 0x16 - iVar3;
      }
      break;
    case 1:
      j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
      return;
    case 2:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x23);
      iVar3 = (0xe - iVar4) + ((uint)(iVar4 * 0xfa24) >> 0x17) * 0x83;
      break;
    case 3:
      (**(code **)(*param_1 + 0x4d8))(param_1,*unaff_x22,unaff_x22[1],param_3);
      if (*unaff_x22 != 0) {
        iVar2 = 4;
      }
      iVar4 = 0x3cfe;
      iVar3 = iVar2;
      break;
    case 4:
      (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x22);
      iVar3 = 10;
      break;
    case 5:
      (**(code **)(*param_1 + 0x4d8))(param_1,unaff_x23,unaff_x24,param_3);
      iVar3 = 0xc;
      if (unaff_x23 != 0) {
        iVar3 = 2;
      }
      iVar4 = 0x47a6;
      break;
    case 6:
      iVar3 = iVar4 + ((uint)(iVar4 * 0xbe83) >> 0x15) * -0x2b;
      (**(code **)(*param_1 + 0x4d8))(param_1,*unaff_x22,unaff_x22[1],param_3);
      if (*unaff_x22 == 0) {
        iVar3 = 0x1a - iVar3;
      }
      else {
        iVar3 = 0x14 - iVar3;
      }
      break;
    case 7:
      cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
      iVar3 = 9;
      if (cVar1 != '\0') {
        iVar3 = iVar2;
      }
      iVar4 = 0x253b;
      break;
    case 8:
      (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x22);
      iVar4 = 0x7595;
      iVar3 = 0;
      break;
    case 9:
      iVar2 = iVar4 + ((uint)(iVar4 * 0xd902) >> 0x17) * -0x97;
      unaff_x22 = (long *)FUN_0016cdf4(param_1,unaff_x23,param_2);
      iVar3 = 0x13;
      if (unaff_x22 != (long *)0x0) {
        iVar3 = 0x18;
      }
      iVar4 = 0x18a8 - iVar2;
      iVar3 = iVar3 - iVar2;
      break;
    case 10:
      free(unaff_x22);
      return;
    case 0xb:
      iVar3 = iVar4 + ((uint)(iVar4 * 0xcf65) >> 0x16) * -0x4f;
      (**(code **)(*param_1 + 0x88))(param_1);
      iVar4 = 0x4fe6 - iVar3;
      iVar3 = 0x3c - iVar3;
      break;
    case 0xc:
      return;
    }
  } while( true );
}


/* EXPORT index=260 ELF_VA=0x6e068 size=512 source_sha256=65cfb55c1f100e2acad87e29591c1231ecdca0b47a46195b157f69ee949ac703 */

void j___IS0lI__Sl5___lIO___IIIl__I_I_lIIIIlIlS_I5III0l0S5_
               (long *param_1,undefined8 *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  long *unaff_x22;
  long unaff_x23;
  long unaff_x24;
  
  uVar2 = 1;
  do {
    switch(uVar2) {
    case 0:
      free(unaff_x22);
      return;
    case 1:
      unaff_x23 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
      unaff_x24 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x23,param_2[2],param_2[1]);
      uVar2 = 7;
      if (unaff_x24 != 0) {
        uVar2 = 3;
      }
      break;
    case 2:
      (**(code **)(*param_1 + 0x4e0))(param_1,*unaff_x22,unaff_x22[1],param_3);
      uVar2 = 0;
      if (*unaff_x22 != 0) {
        uVar2 = 6;
      }
      break;
    case 3:
      (**(code **)(*param_1 + 0x4e0))(param_1,unaff_x23,unaff_x24,param_3);
      uVar2 = 10;
      if (unaff_x23 != 0) {
        uVar2 = 5;
      }
      break;
    case 4:
      j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
      return;
    case 5:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x23);
      uVar2 = 10;
      break;
    case 6:
      (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x22);
      uVar2 = 0;
      break;
    case 7:
      cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
      uVar2 = 8;
      if (cVar1 != '\0') {
        uVar2 = 9;
      }
      break;
    case 8:
      unaff_x22 = (long *)FUN_0016cdf4(param_1,unaff_x23,param_2);
      uVar2 = 4;
      if (unaff_x22 != (long *)0x0) {
        uVar2 = 2;
      }
      break;
    case 9:
      (**(code **)(*param_1 + 0x88))(param_1);
      uVar2 = 8;
      break;
    case 10:
      return;
    }
  } while( true );
}


/* EXPORT index=261 ELF_VA=0x6e294 size=512 source_sha256=4d3661496339285bc1eae5975a8a30641fc149ec29b1178a58fd4d9b6f9119c7 */

void j___I__0I_I0S_l_S05lO_l_SI0_lI0Ol_0_OlISI_IOSIOlllIS5_
               (long *param_1,undefined8 *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  long *unaff_x22;
  long unaff_x23;
  long unaff_x24;
  
  uVar2 = 7;
  do {
    switch(uVar2) {
    case 0:
      (**(code **)(*param_1 + 0x4e8))(param_1,*unaff_x22,unaff_x22[1],param_3);
      uVar2 = 5;
      if (*unaff_x22 != 0) {
        uVar2 = 6;
      }
      break;
    case 1:
      unaff_x22 = (long *)FUN_0016cdf4(param_1,unaff_x23,param_2);
      uVar2 = 9;
      if (unaff_x22 != (long *)0x0) {
        uVar2 = 0;
      }
      break;
    case 2:
    case 9:
      j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
      return;
    case 3:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x23);
      uVar2 = 0xb;
      break;
    case 4:
      (**(code **)(*param_1 + 0x88))(param_1);
      uVar2 = 1;
      break;
    case 5:
      free(unaff_x22);
      return;
    case 6:
      (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x22);
      uVar2 = 5;
      break;
    case 7:
      unaff_x23 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
      unaff_x24 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x23,param_2[2],param_2[1]);
      uVar2 = 10;
      if (unaff_x24 != 0) {
        uVar2 = 8;
      }
      break;
    case 8:
      (**(code **)(*param_1 + 0x4e8))(param_1,unaff_x23,unaff_x24,param_3);
      uVar2 = 0xb;
      if (unaff_x23 != 0) {
        uVar2 = 3;
      }
      break;
    case 10:
      cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
      uVar2 = 1;
      if (cVar1 != '\0') {
        uVar2 = 4;
      }
      break;
    case 0xb:
      return;
    }
  } while( true );
}


/* EXPORT index=262 ELF_VA=0x6e4c4 size=784 source_sha256=79404d831758ae0411b0f569543947199fd77452489c7fa6c0672aa1d3a3e98b */

/* WARNING: Control flow encountered bad instruction data */

void j___IS5Il_S5_lI_I5IlO__IISI_IO__05I0II50_0_O_S_00OlS5_
               (long *param_1,undefined8 *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  long *unaff_x22;
  long unaff_x23;
  long unaff_x24;
  uint uVar3;
  int iStack_68;
  
  uVar3 = 0x73d9;
  iStack_68 = 5;
  iVar2 = 5;
  do {
    switch(iVar2) {
    case 0:
      j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
      return;
    case 1:
      (**(code **)(*param_1 + 0x88))(param_1);
      iStack_68 = (0x47 - uVar3) + (uVar3 / 0x67) * 0x67;
      iVar2 = iStack_68;
      break;
    case 2:
      cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
      iStack_68 = 8;
      if (cVar1 != '\0') {
        iStack_68 = 1;
      }
      uVar3 = 0x4cb1;
      iVar2 = iStack_68;
      break;
    case 3:
      (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x22);
      iStack_68 = (0xb - uVar3) + (uVar3 / 5) * 5;
      iVar2 = iStack_68;
      break;
    case 4:
      if (iStack_68 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      iStack_68 = 0xb;
      iVar2 = 0xb;
      break;
    case 5:
      iStack_68 = uVar3 - (uVar3 / 1 & 0x1fffe);
      unaff_x23 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
      unaff_x24 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x23,param_2[2],param_2[1]);
      if (unaff_x24 == 0) {
        unaff_x24 = 0;
        iStack_68 = 3 - iStack_68;
        iVar2 = iStack_68;
      }
      else {
        iStack_68 = 5 - iStack_68;
        iVar2 = iStack_68;
      }
      break;
    case 6:
      (**(code **)(*param_1 + 0x4f0))(param_1,*unaff_x22,unaff_x22[1],param_3);
      iStack_68 = 10;
      if (*unaff_x22 != 0) {
        iStack_68 = 3;
      }
      uVar3 = 0x2928;
      iVar2 = iStack_68;
      break;
    case 7:
      (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x22);
      iStack_68 = 10;
      iVar2 = 10;
      break;
    case 8:
      unaff_x22 = (long *)FUN_0016cdf4(param_1,unaff_x23,param_2);
      if (unaff_x22 == (long *)0x0) {
        unaff_x22 = (long *)0x0;
        iStack_68 = 0;
        iVar2 = 0;
      }
      else {
        iStack_68 = 6;
        iVar2 = 6;
      }
      break;
    case 9:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x23);
LAB_0016e524:
      iStack_68 = 0xc;
      iVar2 = 0xc;
      break;
    case 10:
      free(unaff_x22);
      return;
    case 0xb:
      (**(code **)(*param_1 + 0x4f0))(param_1,unaff_x23,unaff_x24,param_3);
      if (unaff_x23 == 0) {
        unaff_x23 = 0;
        goto LAB_0016e524;
      }
      iStack_68 = 9;
      iVar2 = 9;
      break;
    case 0xc:
      return;
    }
  } while( true );
}


/* EXPORT index=263 ELF_VA=0x6e808 size=744 source_sha256=6b9c8efa9af3295c3ea3d31ebe98ef4bc1a5f18f0c906a80bad8626a4816c52f */

/* WARNING: Control flow encountered bad instruction data */

void j___l50_I_0OISO_I_l_0_OSIS0_OO5lI5_IlI0I___S5I_l0IIS5_
               (long *param_1,undefined8 *param_2,undefined4 param_3)

{
  undefined8 uVar1;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 extraout_x1_01;
  undefined8 extraout_x1_02;
  undefined8 extraout_x1_03;
  undefined8 extraout_x1_04;
  int iVar2;
  long in_x11;
  long extraout_x11;
  long extraout_x11_00;
  long extraout_x11_01;
  long extraout_x11_02;
  long extraout_x11_03;
  long extraout_x11_04;
  long extraout_x11_05;
  long extraout_x11_06;
  long extraout_x11_07;
  long *unaff_x22;
  long unaff_x23;
  undefined8 unaff_x24;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  int iStack_68;
  
  auVar5._8_8_ = param_2;
  auVar5._0_8_ = unaff_x24;
  uVar4 = 0x59f9;
  iStack_68 = 0;
  iVar2 = 0;
switchD_0016e880_default:
  uVar3 = auVar5._0_8_;
  switch(iVar2) {
  case 0:
    unaff_x23 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
    auVar5 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x23,param_2[2],param_2[1]);
    in_x11 = extraout_x11;
    if (auVar5._0_8_ == 0) {
      auVar6._8_8_ = 0;
      auVar6._0_8_ = auVar5._8_8_;
      auVar5 = auVar6 << 0x40;
      iStack_68 = 6;
      iVar2 = 6;
    }
    else {
      iStack_68 = 5;
      iVar2 = 5;
    }
    goto switchD_0016e880_default;
  case 1:
    (**(code **)(*param_1 + 0x88))(param_1);
    auVar5._8_8_ = extraout_x1;
    auVar5._0_8_ = uVar3;
    iVar2 = 7;
    iStack_68 = 7;
    uVar4 = 0x7c8;
    in_x11 = extraout_x11_00;
    goto switchD_0016e880_default;
  case 2:
  case 4:
    goto switchD_0016e880_caseD_2;
  case 3:
    (**(code **)(*param_1 + 0xb8))(param_1,unaff_x23);
    uVar1 = extraout_x1_00;
    in_x11 = extraout_x11_01;
    break;
  case 5:
    if (iStack_68 < 0) {
      *(undefined8 *)(in_x11 + 0x4ac0) = uVar4;
      if ((auVar5._8_8_ >> 0x3d & 1) == 0) {
        func_0xfffffffff841b554();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    iVar2 = 10;
    iStack_68 = 10;
    goto switchD_0016e880_default;
  case 6:
    auVar6 = (**(code **)(*param_1 + 0x720))(param_1);
    auVar5._8_8_ = auVar6._8_8_;
    auVar5._0_8_ = uVar3;
    iStack_68 = 7;
    if ((auVar6._0_8_ & 0xff) != 0) {
      iStack_68 = 1;
    }
    uVar4 = 0x3144;
    in_x11 = extraout_x11_02;
    iVar2 = iStack_68;
    goto switchD_0016e880_default;
  case 7:
    auVar6 = FUN_0016cdf4(param_1,unaff_x23,param_2);
    auVar5._8_8_ = auVar6._8_8_;
    auVar5._0_8_ = uVar3;
    unaff_x22 = auVar6._0_8_;
    if (unaff_x22 == (long *)0x0) {
      unaff_x22 = (long *)0x0;
      iStack_68 = 0x39;
    }
    else {
      iStack_68 = 0x38;
    }
    iStack_68 = iStack_68 - (uint)uVar4 % 0x3b;
    in_x11 = extraout_x11_03;
    iVar2 = iStack_68;
    goto switchD_0016e880_default;
  case 8:
    (**(code **)(*param_1 + 0x4f8))(param_1,unaff_x23,uVar3,param_3);
    auVar5._8_8_ = extraout_x1_01;
    auVar5._0_8_ = uVar3;
    in_x11 = extraout_x11_04;
    if (unaff_x23 == 0) {
      unaff_x23 = 0;
      uVar1 = extraout_x1_01;
      goto LAB_0016e864;
    }
    iStack_68 = 0;
    iVar2 = 0;
    goto switchD_0016e880_default;
  case 9:
    (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x22);
    uVar1 = extraout_x1_02;
    in_x11 = extraout_x11_05;
LAB_0016e864:
    auVar5._8_8_ = uVar1;
    auVar5._0_8_ = uVar3;
    iStack_68 = 2;
    iVar2 = 2;
    goto switchD_0016e880_default;
  case 10:
    (**(code **)(*param_1 + 0x4f8))(param_1,unaff_x23,uVar3,param_3);
    auVar5._8_8_ = extraout_x1_03;
    auVar5._0_8_ = uVar3;
    in_x11 = extraout_x11_06;
    if (unaff_x23 != 0) {
      iStack_68 = 3;
      iVar2 = 3;
      goto switchD_0016e880_default;
    }
    unaff_x23 = 0;
    uVar1 = extraout_x1_03;
    break;
  case 0xb:
    (**(code **)(*param_1 + 0x4f8))(param_1,*unaff_x22,unaff_x22[1],param_3);
    auVar5._8_8_ = extraout_x1_04;
    auVar5._0_8_ = uVar3;
    uVar1 = extraout_x1_04;
    in_x11 = extraout_x11_07;
    if (*unaff_x22 == 0) goto LAB_0016e864;
    iStack_68 = 9;
    iVar2 = 9;
    goto switchD_0016e880_default;
  case 0xc:
    j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
    return;
  case 0xd:
    return;
  default:
    goto switchD_0016e880_default;
  }
  auVar5._8_8_ = uVar1;
  auVar5._0_8_ = uVar3;
  iStack_68 = 0xd;
  iVar2 = 0xd;
  goto switchD_0016e880_default;
switchD_0016e880_caseD_2:
  free(unaff_x22);
  return;
}


/* EXPORT index=264 ELF_VA=0x6eb28 size=2044 source_sha256=77fdb97a31bbf4f48d1349ca76e5dd7b415c4cba493044eea991cc2dfb3de6da */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___l_lll__II_S_I0I_O_lIII0_0I_II_5lI5IlOII__IOIII_S5_
               (undefined8 param_1,long *param_2,undefined8 *param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 extraout_x1_01;
  undefined8 extraout_x1_02;
  undefined8 extraout_x1_03;
  int iVar5;
  undefined8 unaff_x21;
  long *__ptr;
  long unaff_x22;
  long unaff_x23;
  uint uVar6;
  uint uVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  byte abStack_b0 [8];
  ulong uStack_a8;
  undefined8 uStack_a0;
  undefined2 uStack_98;
  undefined5 uStack_96;
  byte bStack_91;
  undefined2 uStack_90;
  byte bStack_8e;
  undefined7 uStack_8d;
  long lStack_78;
  
  auVar8._8_8_ = param_3;
  auVar8._0_8_ = unaff_x21;
  uVar6 = 0x5948;
  lStack_78 = ___stack_chk_guard;
  bStack_8e = 0x42;
  uStack_8d = 0x183914255d1417;
  uStack_90 = 0x1d04;
  uStack_a8 = 0x61320600070a6a65;
  abStack_b0[0] = 0x76;
  abStack_b0[1] = 0x60;
  abStack_b0[2] = 0x2a;
  abStack_b0[3] = 2;
  abStack_b0[4] = 0x44;
  abStack_b0[5] = 0x54;
  abStack_b0[6] = 0x3a;
  abStack_b0[7] = 0x6b;
  uStack_98 = 0x696e;
  uStack_96 = 0x2b5a1d7171;
  bStack_91 = 0x45;
  uStack_a0 = 0x461f4c2f4030137c;
  uVar7 = 0x927c614c;
  iVar5 = 0x11;
  do {
    __ptr = auVar8._0_8_;
    bVar3 = (byte)uVar7;
    switch(iVar5) {
    case 0:
      (**(code **)(*param_2 + 0x88))(param_2);
      auVar8._8_8_ = extraout_x1_00;
      auVar8._0_8_ = __ptr;
      iVar5 = 2;
      break;
    case 1:
      abStack_b0[uVar7 + 0xa340595b] = bVar3 ^ abStack_b0[uVar7 + 0xa340595b] ^ 0xfa;
      abStack_b0[uVar7 ^ 0x5cbfa6a6] = bVar3 ^ abStack_b0[uVar7 ^ 0x5cbfa6a6] ^ 0xed;
      abStack_b0[uVar7 + 0xa3405976] = abStack_b0[uVar7 + 0xa3405976] ^ bVar3 + 0x8b;
      uVar2 = uVar7 + 0xa340596f;
      abStack_b0[uVar7 + 0xa3405964] = abStack_b0[uVar7 + 0xa3405964] ^ bVar3 + 0xac;
      uVar7 = uVar7 & 0x1ff65ef2;
      abStack_b0[uVar2] = bVar3 ^ abStack_b0[uVar2] ^ 0xf0;
      abStack_b0[uVar7 + 0xe349f967] = (byte)uVar7 ^ abStack_b0[uVar7 + 0xe349f967] ^ 0xdd;
      iVar5 = 6;
      break;
    case 2:
      auVar8 = FUN_0016cdf4(param_2,unaff_x22,param_3);
      iVar5 = 9;
      if (auVar8._0_8_ != 0) {
        iVar5 = 5;
      }
      break;
    case 3:
      do {
        auVar8._8_8_ = 0x38;
        auVar8._0_8_ = __ptr;
        CallSupervisor(0);
      } while (&stack0x00000000 == (undefined1 *)0xac);
      iVar5 = 0x11;
      break;
    case 4:
      iVar5 = uVar7 * 4;
      abStack_b0[uVar7 ^ 0xe5b0351b] = bVar3 ^ abStack_b0[uVar7 ^ 0xe5b0351b] ^ 0x2d;
      abStack_b0[iVar5 + 0x693f2be9U] = abStack_b0[iVar5 + 0x693f2be9U] ^ (char)iVar5 - 0x28U;
      uVar7 = iVar5 + 0x7cf41ce6;
      abStack_b0[iVar5 + 0x693f2bd7U] = (byte)uVar7 ^ abStack_b0[iVar5 + 0x693f2bd7U] ^ 0x54;
      iVar5 = (0x33 - uVar6) + (uVar6 / 0x25) * 0x25;
      break;
    case 5:
      (**(code **)(*param_2 + 0x508))(param_1,param_2,*__ptr,__ptr[1]);
      auVar8._8_8_ = extraout_x1_01;
      auVar8._0_8_ = __ptr;
      iVar5 = 10;
      if (*__ptr != 0) {
        iVar5 = 0x10;
      }
      break;
    case 6:
      iVar5 = uVar7 * 4;
      abStack_b0[uVar7 + 0xe349f971] = bVar3 ^ abStack_b0[uVar7 + 0xe349f971] ^ 0xd8;
      uVar6 = iVar5 + 0x8d27e59c;
      uVar7 = uVar7 * 8;
      abStack_b0[uVar6] = (byte)iVar5 ^ abStack_b0[uVar6] ^ 0xdf;
      abStack_b0[uVar7 + 0x1a4fcb10] = abStack_b0[uVar7 + 0x1a4fcb10] ^ (char)uVar7 + 0x2dU;
      uVar6 = 0x15f2;
      abStack_b0[uVar7 + 0x1a4fcb18] = abStack_b0[uVar7 + 0x1a4fcb18] ^ (char)uVar7 + 0x6aU;
      iVar5 = 4;
      break;
    case 7:
      uVar6 = uVar7 + 0x33aea1da;
      uVar7 = uVar7 + 0xc5d2d48a ^ 0xde6aa379;
      iVar5 = uVar7 * uVar7 * 2;
      uVar7 = iVar5 + 0x12e8880b;
      abStack_b0[uVar6] = abStack_b0[uVar6] ^ bVar3 + 0x3b;
      uVar6 = 0x215d;
      abStack_b0[uVar7 ^ 0x9fd22988] = abStack_b0[uVar7 ^ 0x9fd22988] ^ (char)iVar5 + 0xbaU;
      iVar5 = 0x13;
      break;
    case 8:
      iVar5 = uVar7 * 2;
      abStack_b0[iVar5 + 0x812ae8b1U] = (byte)iVar5 ^ abStack_b0[iVar5 + 0x812ae8b1U] ^ 10;
      uVar7 = iVar5 * iVar5 * iVar5 * iVar5 * 2 + 0x5e315e44;
      abStack_b0[iVar5 + 0x812ae8c3U] = (byte)iVar5 ^ abStack_b0[iVar5 + 0x812ae8c3U] ^ 0x31;
      iVar5 = 7;
      break;
    case 9:
      j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_2,param_3[2]);
switchD_0016ebd8_caseD_17:
      if (___stack_chk_guard == lStack_78) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    case 10:
      iVar5 = 0xc;
      break;
    case 0xb:
      (**(code **)(*param_2 + 0x508))(param_1,param_2,unaff_x22,unaff_x23);
      auVar8._8_8_ = extraout_x1_02;
      auVar8._0_8_ = __ptr;
      iVar5 = 0x17;
      if (unaff_x22 != 0) {
        iVar5 = 0xe;
      }
      break;
    case 0xc:
      free(__ptr);
      goto switchD_0016ebd8_caseD_17;
    case 0xd:
      uVar2 = uVar7 + 0xbf0ba095;
      abStack_b0[uVar7 + 0xbf0ba0a1] = abStack_b0[uVar7 + 0xbf0ba0a1] ^ bVar3 - 0x13;
      abStack_b0[uVar7 + 0xbf0ba0ae] = bVar3 ^ abStack_b0[uVar7 + 0xbf0ba0ae] ^ 0x1d;
      uVar7 = uVar7 + 0x1b9f3485;
      abStack_b0[uVar2] = bVar3 + 0xb5 ^ abStack_b0[uVar2] ^ 0x5e;
      abStack_b0[uVar7 ^ 0x5c9393e6] = (byte)uVar7 ^ abStack_b0[uVar7 ^ 0x5c9393e6] ^ 0x90;
      iVar5 = 3;
      break;
    case 0xe:
      (**(code **)(*param_2 + 0xb8))(param_2,unaff_x22);
      auVar8._8_8_ = extraout_x1_03;
      auVar8._0_8_ = __ptr;
      iVar5 = 0x17;
      break;
    case 0xf:
      uStack_a8 = uStack_a8 ^ 0x3600000000;
      bStack_8e = bStack_8e ^ 0x46;
      uVar7 = 0x5cbfa6ab;
      bStack_91 = bStack_91 ^ 0x1e;
      iVar5 = 1;
      break;
    case 0x10:
      (**(code **)(*param_2 + 0xb8))(param_2,*__ptr);
      auVar8._8_8_ = extraout_x1;
      auVar8._0_8_ = __ptr;
      iVar5 = 0xc;
      break;
    case 0x11:
      unaff_x22 = (**(code **)(*param_2 + 0x30))(param_2,*param_3);
      auVar9 = (**(code **)(*param_2 + 0x480))(param_2,unaff_x22,param_3[2],param_3[1]);
      auVar8._8_8_ = auVar9._8_8_;
      auVar8._0_8_ = __ptr;
      unaff_x23 = auVar9._0_8_;
      iVar5 = 0x15;
      if (unaff_x23 != 0) {
        iVar5 = 0xb;
      }
      break;
    case 0x12:
      uVar1 = uVar7 + 0xcfc4d49f;
      abStack_b0[uVar1 ^ 0x9fb545dd] = abStack_b0[uVar1 ^ 0x9fb545dd] ^ bVar3 + 0x22;
      abStack_b0[uVar7 + 0x300f8ee2] = abStack_b0[uVar7 + 0x300f8ee2] ^ bVar3 + 0x18;
      abStack_b0[uVar7 + 0x300f8ee0] = (byte)uVar1 ^ abStack_b0[uVar7 + 0x300f8ee0] ^ 0xa2;
      uVar2 = uVar7 + 0x300f8ecf;
      abStack_b0[uVar7 + 0x300f8eee] = (byte)uVar1 ^ abStack_b0[uVar7 + 0x300f8eee] ^ 0xbc;
      uVar7 = uVar1 * 2;
      abStack_b0[uVar2] = abStack_b0[uVar2] ^ bVar3 + 0x39;
      iVar5 = 8;
      break;
    case 0x13:
      abStack_b0[uVar7 ^ 0x9fd229ad] = bVar3 ^ abStack_b0[uVar7 ^ 0x9fd229ad] ^ 0xbb;
      abStack_b0[uVar7 + 0x602dd65a] = bVar3 ^ abStack_b0[uVar7 + 0x602dd65a] ^ 0xde;
      abStack_b0[uVar7 + 0x602dd679] = bVar3 ^ abStack_b0[uVar7 + 0x602dd679] ^ 199;
      abStack_b0[uVar7 + 0x602dd654] = bVar3 ^ abStack_b0[uVar7 + 0x602dd654] ^ 0xe2;
      abStack_b0[uVar7 + 0x602dd667] = abStack_b0[uVar7 + 0x602dd667] ^ bVar3 + 0x6b;
      uVar2 = uVar7 + 0x602dd661;
      uVar7 = uVar7 + 0xa12235c2;
      abStack_b0[uVar2] = abStack_b0[uVar2] ^ bVar3 + 0xa4;
      iVar5 = (0x2c - uVar6) + (uVar6 / 0x25) * 0x25;
      break;
    case 0x14:
      uVar2 = uVar7 ^ 0x13b4f13e;
      uVar7 = uVar7 * 4 + 0xb2bbbab0 ^ 0x511cfb28;
      abStack_b0[uVar2] = abStack_b0[uVar2] ^ bVar3 + 2;
      iVar5 = 0x16;
      break;
    case 0x15:
      auVar9 = (**(code **)(*param_2 + 0x720))(param_2,auVar8._8_8_);
      auVar8._8_8_ = auVar9._8_8_;
      auVar8._0_8_ = __ptr;
      iVar5 = (uint)((auVar9._0_8_ & 0xff) == 0) << 1;
      break;
    case 0x16:
      uVar2 = uVar7 ^ 0x9f63f559;
      abStack_b0[uVar2 + 0x300f8edc] = bVar3 ^ abStack_b0[uVar2 + 0x300f8edc] ^ 0x76;
      cVar4 = (char)uVar2;
      abStack_b0[uVar2 + 0x300f8ed1] = abStack_b0[uVar2 + 0x300f8ed1] ^ cVar4 - 0x1bU;
      abStack_b0[uVar2 + 0x300f8ee3] = abStack_b0[uVar2 + 0x300f8ee3] ^ cVar4 + 0x3aU;
      abStack_b0[uVar2 + 0x300f8ec9] = abStack_b0[uVar2 + 0x300f8ec9] ^ cVar4 + 0x39U;
      abStack_b0[uVar7 ^ 0x50938463] = abStack_b0[uVar7 ^ 0x50938463] ^ cVar4 - 0x11U;
      abStack_b0[uVar2 + 0x300f8edd] = abStack_b0[uVar2 + 0x300f8edd] ^ cVar4 + 0x16U;
      uVar7 = uVar2;
      iVar5 = 0x12;
      break;
    case 0x17:
      goto switchD_0016ebd8_caseD_17;
    }
  } while( true );
}


/* EXPORT index=265 ELF_VA=0x6f384 size=652 source_sha256=1f6f3eb69ee61c222e8c9b9758a4d744783a7979797bfac854b7b0a3b205efa5 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0016f454) */

void j___SI0_O_O55OI_IlOS__5Ol_l_l__IIlII__O_lIO0IISlI_IS5_
               (long *param_1,undefined8 *param_2,undefined8 param_3)

{
  char cVar1;
  undefined8 uVar2;
  long *unaff_x22;
  long unaff_x23;
  long unaff_x24;
  
  uVar2 = 5;
switchD_0016f3f0_default:
  switch(uVar2) {
  case 0:
    (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x22);
    break;
  case 1:
    (**(code **)(*param_1 + 0xb8))(param_1,unaff_x23);
    goto LAB_0016f5a4;
  case 2:
    unaff_x22 = (long *)FUN_0016cdf4(param_1,unaff_x23,param_2);
    if (unaff_x22 == (long *)0x0) {
      unaff_x22 = (long *)0x0;
      uVar2 = 8;
    }
    else {
      uVar2 = 4;
    }
    goto switchD_0016f3f0_default;
  case 3:
    goto switchD_0016f3f0_caseD_3;
  case 4:
    uVar2 = 9;
    goto switchD_0016f3f0_default;
  case 5:
    unaff_x23 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
    unaff_x24 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x23,param_2[2],param_2[1]);
    if (unaff_x24 == 0) {
      unaff_x24 = 0;
      uVar2 = 7;
    }
    else {
      uVar2 = 6;
    }
    goto switchD_0016f3f0_default;
  case 6:
    (**(code **)(*param_1 + 0x500))(param_1,unaff_x23,unaff_x24,param_3);
    if (unaff_x23 == 0) {
      unaff_x23 = 0;
LAB_0016f5a4:
      uVar2 = 0xc;
    }
    else {
      uVar2 = 1;
    }
    goto switchD_0016f3f0_default;
  case 7:
    cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
    if (cVar1 == '\0') goto LAB_0016f568;
    uVar2 = 10;
    goto switchD_0016f3f0_default;
  case 8:
    j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
    return;
  case 9:
    (**(code **)(*param_1 + 0x500))(param_1,*unaff_x22,unaff_x22[1],param_3);
    if (*unaff_x22 != 0) {
      uVar2 = 0;
      goto switchD_0016f3f0_default;
    }
    break;
  case 10:
    (**(code **)(*param_1 + 0x88))(param_1);
LAB_0016f568:
    uVar2 = 2;
    goto switchD_0016f3f0_default;
  case 0xb:
    goto switchD_0016f3f0_caseD_b;
  case 0xc:
    return;
  default:
    goto switchD_0016f3f0_default;
  }
  uVar2 = 0xb;
  goto switchD_0016f3f0_default;
switchD_0016f3f0_caseD_b:
  uVar2 = 3;
  goto switchD_0016f3f0_default;
switchD_0016f3f0_caseD_3:
  free(unaff_x22);
  return;
}


/* EXPORT index=266 ELF_VA=0x6f644 size=608 source_sha256=e027e7daac41cedcbaa15b0188ddd95fe55ebb16ae61120722e9c6fccd38eef3 */

void j___ISlOI_lIlSl_SIIO__I05I0__OIII_I5IlSOlIlO5SOI_0lS5_
               (undefined8 param_1,long *param_2,undefined8 *param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  long *unaff_x21;
  long unaff_x22;
  long unaff_x23;
  int iVar4;
  
  iVar4 = 0x21f;
  iVar3 = 1;
  do {
    switch(iVar3) {
    case 0:
      (**(code **)(*param_2 + 0x510))(param_1,param_2,unaff_x22,unaff_x23);
      iVar3 = 9;
      if (unaff_x22 == 0) {
        iVar3 = 10;
      }
      break;
    case 1:
      unaff_x22 = (**(code **)(*param_2 + 0x30))(param_2,*param_3);
      unaff_x23 = (**(code **)(*param_2 + 0x480))(param_2,unaff_x22,param_3[2],param_3[1]);
      iVar3 = 6;
      if (unaff_x23 != 0) {
        iVar3 = 0;
      }
      iVar4 = 0x4729;
      break;
    case 2:
      j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_2,param_3[2]);
      return;
    case 3:
      unaff_x21 = (long *)FUN_0016cdf4(param_2,unaff_x22,param_3);
      iVar3 = 2;
      if (unaff_x21 != (long *)0x0) {
        iVar3 = 8;
      }
      break;
    case 4:
      free(unaff_x21);
      return;
    case 5:
      (**(code **)(*param_2 + 0xb8))(param_2,*unaff_x21);
      iVar3 = (9 - iVar4) + ((uint)(iVar4 * 0xc7cf) >> 0x15) * 0x29;
      break;
    case 6:
      iVar1 = iVar4 + ((uint)(iVar4 * 0xf48a) >> 0x16) * -0x43;
      cVar2 = (**(code **)(*param_2 + 0x720))(param_2);
      iVar3 = 0x3f;
      if (cVar2 != '\0') {
        iVar3 = 0x43;
      }
      iVar4 = 0x246a - iVar1;
      iVar3 = iVar3 - iVar1;
      break;
    case 7:
      (**(code **)(*param_2 + 0x88))(param_2);
      iVar3 = (0x3f - iVar4) + ((uint)(iVar4 * 0x9920) >> 0x16) * 0x6b;
      break;
    case 8:
      (**(code **)(*param_2 + 0x510))(param_1,param_2,*unaff_x21,unaff_x21[1]);
      iVar3 = 4;
      if (*unaff_x21 != 0) {
        iVar3 = 5;
      }
      iVar4 = 0x66ae;
      break;
    case 9:
      (**(code **)(*param_2 + 0xb8))(param_2,unaff_x22);
      iVar3 = 10;
      break;
    case 10:
      return;
    }
  } while( true );
}


/* EXPORT index=267 ELF_VA=0x6f8d0 size=696 source_sha256=eb4f0c62015aa1ecba0a0c591cc104fa8eb7987e61cebb1cb34d792f63c0e42a */

void j___lIII0_S0_05_IOIOI_SIIlI_5ISlIl__IOS_0SllOO_II5SS5_
               (long *param_1,undefined8 *param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  long *unaff_x22;
  long unaff_x23;
  long unaff_x24;
  int iVar3;
  
  iVar3 = 0x37ef;
  iVar2 = 8;
  do {
    switch(iVar2) {
    case 0:
      unaff_x22 = (long *)FUN_0016cdf4(param_1,unaff_x23,param_2);
      iVar2 = 5;
      if (unaff_x22 != (long *)0x0) {
        iVar2 = 3;
      }
      break;
    case 1:
      (**(code **)(*param_1 + 0x88))(param_1);
      iVar3 = 0x99c;
      iVar2 = 9;
      break;
    case 2:
      (**(code **)(*param_1 + 0x88))(param_1);
      iVar2 = 0;
      break;
    case 3:
      (**(code **)(*param_1 + 0x4d0))(param_1,*unaff_x22,unaff_x22[1],param_3);
      iVar2 = 4;
      if (*unaff_x22 != 0) {
        iVar2 = 10;
      }
      iVar3 = 0x14e2;
      break;
    case 4:
      free(unaff_x22);
      return;
    case 5:
      j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(param_1,param_2[2]);
      return;
    case 6:
      iVar2 = iVar3 + ((uint)(iVar3 * 0xa8e9) >> 0x16) * -0x61;
      cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
      if (cVar1 == '\0') {
        iVar2 = 0x35 - iVar2;
      }
      else {
        iVar2 = 0x37 - iVar2;
      }
      break;
    case 7:
      (**(code **)(*param_1 + 0xb8))(param_1,unaff_x23);
      iVar2 = (0x33 - iVar3) + ((uint)(iVar3 * 0x9920) >> 0x16) * 0x6b;
      break;
    case 8:
      iVar3 = iVar3 + ((uint)(iVar3 * 0xdbec) >> 0x17) * -0x95;
      unaff_x23 = (**(code **)(*param_1 + 0x30))(param_1,*param_2);
      unaff_x24 = (**(code **)(*param_1 + 0x480))(param_1,unaff_x23,param_2[2],param_2[1]);
      iVar2 = 0x15;
      if (unaff_x24 != 0) {
        iVar2 = 0x18;
      }
      iVar2 = iVar2 - iVar3;
      iVar3 = 0x582c - iVar3;
      break;
    case 9:
      iVar3 = ((uint)(iVar3 * 0x924a) >> 0x12) * -7 + iVar3;
      (**(code **)(*param_1 + 0x4d0))(param_1,unaff_x23,unaff_x24,param_3);
      iVar2 = 0xe;
      if (unaff_x23 != 0) {
        iVar2 = 10;
      }
      iVar2 = iVar2 - iVar3;
      iVar3 = 0x28b6 - iVar3;
      break;
    case 10:
      (**(code **)(*param_1 + 0xb8))(param_1,*unaff_x22);
      iVar2 = (((uint)(iVar3 * 0x924a) >> 0x12) * 7 + 9) - iVar3;
      break;
    case 0xb:
      return;
    }
  } while( true );
}


/* EXPORT index=268 ELF_VA=0x703e8 size=32 source_sha256=edc61b1d1fb1d435b3140da09c5a9fd1fd77e3497f87629f18194ec952397d3b */

void j___Il5l__lS0lI_I0____OSO_5_0S_l_Ol00_I5lISI_II_SIIS5_(long *param_1,undefined8 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00170404. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x70))(param_1,DAT_0018dcc8,param_2);
  return;
}


/* EXPORT index=269 ELF_VA=0x70408 size=32 source_sha256=637503f8a6f7c0bac83a47d542836203d0c8f38e5f4d658ae0386e18397368a0 */

void j___IOI___IlSS5_5lISI_OlI_5_5I_lI_5_lIII0IllSSS0_I_S5_(long *param_1,undefined8 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00170424. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x70))(param_1,DAT_0018dda8,param_2);
  return;
}


/* EXPORT index=270 ELF_VA=0x70428 size=140 source_sha256=b59c5a4640b370e4843a67b6c34f9b9bc36984aa586eb3dd76715769d06e7c6b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j____IlIO_S_lI__SISIl_Sl_II_S5IIS5_ISI_0SO_OI5S_5llS5_(long *param_1,ulong param_2)

{
  char acStack_238 [512];
  long lStack_38;
  
  lStack_38 = ___stack_chk_guard;
  sprintf(acStack_238,"%d",param_2 & 0xffffffff);
  (**(code **)(*param_1 + 0x70))(param_1,DAT_0018dd80,acStack_238);
  if (___stack_chk_guard == lStack_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* EXPORT index=271 ELF_VA=0x704b4 size=32 source_sha256=d09cd0f67c75818803dbe05999845a72058a78e62cbda609764172db173dbf48 */

void j___IIO_5_O_I_l_I__SS_lllS__lI0lll_5SllS0_OIlO_I_lIS5_(long *param_1,undefined8 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x001704d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x70))(param_1,DAT_0018dd68,param_2);
  return;
}


/* EXPORT index=272 ELF_VA=0x704d4 size=396 source_sha256=82f2104eb064bcf1e2f22548fdf233a4cfd1b2f5d3721a178b324793b7ad4dfa */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___I_l5I_0I__l_l0SI5_l_SlO_llIS05I__5_5S_lll_l0lIlS5_
               (long *param_1,uint param_2,ulong param_3)

{
  long lVar1;
  uint uStack_264;
  undefined1 uStack_260;
  byte abStack_25f [23];
  char acStack_248 [520];
  
  lVar1 = ___stack_chk_guard;
  uStack_260 = 0x59;
  abStack_25f[0] = 0x35;
  abStack_25f[1] = 0x3f;
  abStack_25f[2] = 0x35;
  abStack_25f[3] = 0x3b;
  abStack_25f[4] = 0x29;
  abStack_25f[5] = 0x36;
  abStack_25f[6] = 0x62;
  abStack_25f[7] = 0x45;
  abStack_25f[8] = 5;
  abStack_25f[9] = 0x59;
  abStack_25f[10] = 0x43;
  abStack_25f[0xb] = 0xd;
  abStack_25f[0xc] = 0xb;
  abStack_25f[0xd] = 2;
  abStack_25f[0xe] = 2;
  abStack_25f[0xf] = 0x10;
  abStack_25f[0x10] = 0x54;
  abStack_25f[0x11] = 0x4f;
  abStack_25f[0x12] = 0xf;
  uStack_264 = 0;
  do {
    abStack_25f[(int)uStack_264] = (char)uStack_264 + 0x59U ^ abStack_25f[(int)uStack_264];
    uStack_264 = uStack_264 + 1;
  } while (uStack_264 < 0x13);
  abStack_25f[0x13] = 0;
  sprintf(acStack_248,(char *)((ulong)&uStack_260 | 1),(ulong)param_2,param_3 & 0xffffffff);
  (**(code **)(*param_1 + 0x70))(param_1,DAT_0018dcd0,acStack_248);
  if (___stack_chk_guard != lVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* EXPORT index=273 ELF_VA=0x70660 size=32 source_sha256=3a458945deb4a221c567a71d91def5914264d0d163c798c2224d696cd6e76339 */

void j___I5lI0_IS_0I_l0O_O_lIISl_IIII_5_I_0l5I_I0IIOlll0S5_(long *param_1,undefined8 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0017067c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x70))(param_1,DAT_0018dd98,param_2);
  return;
}


/* EXPORT index=274 ELF_VA=0x70680 size=32 source_sha256=e8ceb138f10f94e87ae95d017a74a5379090e9837e8ed7005ca7428cc1fe0371 */

void j____llI__IS0IS_I_IO__IISII_IIISIOlS_I_5_lO_O5I0OISS5_(long *param_1,undefined8 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0017069c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x70))(param_1,DAT_0018ddb8,param_2);
  return;
}


/* EXPORT index=275 ELF_VA=0x706a0 size=16 source_sha256=f0000599f44af74982798fdc3f46bd3db9235f42a8603f881f96c7aefd68e85d */

void j___lOII0__5lO0_0SIIl_II00l_O____l_I_l5lII5SISIS_OlS5_(long param_1)

{
                    /* WARNING: Could not recover jumptable at 0x001706ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(long **)(param_1 + 0x30) + 0x88))();
  return;
}


/* EXPORT index=276 ELF_VA=0x706b0 size=24 source_sha256=2142c97fef3b6b148971a4984aec37a73b4c173ba7a83d3429b0b2a571fb76df */

void j___lOIII_5Il5I_IISS__lIl5l_l__IO5__IlO_5O0I55IISS5S5_(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x28) = param_2;
                    /* WARNING: Could not recover jumptable at 0x001706c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(long **)(param_1 + 0x30) + 0x68))(*(long **)(param_1 + 0x30));
  return;
}


/* EXPORT index=277 ELF_VA=0x706c8 size=232 source_sha256=559846932d80948c2f0663551dc7e590c00424fbf06a2bfa0f33911ba0f75abb */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void j___OI5IO_llI___I_05I_OOII__IS5ISl05ISI__IIlI_O0O5lS5_(long *param_1)

{
  uint uStack_44;
  undefined8 uStack_40;
  undefined8 uStack_38;
  uint uStack_30;
  long lStack_28;
  
  lStack_28 = ___stack_chk_guard;
  uStack_40 = 0x7876386365745714;
  uStack_38 = 0x4b40463f6a7e7971;
  uStack_30 = 0x41414f;
  uStack_44 = 0;
  do {
    *(byte *)((long)&uStack_40 + (long)(int)uStack_44 + 1) =
         (char)uStack_44 + 0x14U ^ *(byte *)((long)&uStack_40 + (long)(int)uStack_44 + 1);
    uStack_44 = uStack_44 + 1;
  } while (uStack_44 < 0x12);
  uStack_30 = uStack_30 & 0xffffff;
  (**(code **)(*param_1 + 0x70))(param_1,DAT_0018dce0,(ulong)&uStack_40 | 1);
  if (___stack_chk_guard != lStack_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* EXPORT index=278 ELF_VA=0x707b0 size=9040 source_sha256=c04ef911457d80d502d345960194456c81e2dfa04ebce86268f08f31c5405045 */

/* WARNING: Exceeded maximum restarts with more pending */

void j___l05II_l__l5__S0Il_0IISO_I_lIll_I55O_I5IlS_IlI5lS5_(long *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint uVar6;
  ulong in_x10;
  ulong extraout_x10;
  long in_x11;
  long extraout_x11;
  ulong in_x12;
  ulong extraout_x12;
  uint uVar7;
  ulong in_x13;
  ulong extraout_x13;
  uint uVar8;
  ulong in_x14;
  ulong extraout_x14;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iStack_64;
  
  uVar4 = 5;
switchD_00170894_default:
  do {
    switch(uVar4) {
    case 0x170944:
                    /* WARNING: This code block may not be properly labeled as switch case */
      iStack_64 = param_2;
      uVar6 = 0xffffffdb;
      pbVar5 = (byte *)0x0;
      iVar1 = 0x15;
      iVar2 = 0x344d;
switchD_00170994_default:
      iVar13 = iVar2;
      uVar8 = (uint)in_x14;
      uVar7 = (uint)in_x13;
      uVar9 = (uint)in_x12;
      iVar2 = iVar13;
      switch(iVar1) {
      case 0:
        iVar10 = 0x83;
        iVar1 = 0x72 - iVar13;
        uVar11 = (uint)(iVar13 * 0xfa24) >> 0x17;
        in_x14 = (ulong)(uVar8 + (uint)pbVar5[3] * 0x1000000);
        goto LAB_00170ea8;
      case 1:
        iVar10 = 0xa3;
        iVar1 = 0xbd - iVar13;
        uVar11 = (uint)(iVar13 * 0xc908) >> 0x17;
        in_x13 = (ulong)(uVar7 + (uint)pbVar5[9] * 0x10000);
        goto LAB_00170ea8;
      case 2:
        in_x12 = (ulong)(uVar9 + (uint)pbVar5[7] * 0x1000000);
        iVar1 = 0x16;
        goto switchD_00170994_default;
      case 3:
        goto switchD_00170994_caseD_3;
      case 4:
        iVar10 = 0xd0b7;
        iVar12 = -0x9d;
        iVar1 = 0xc2;
        iVar2 = 0x2b8b;
        goto LAB_00170de4;
      case 5:
switchD_00170994_caseD_5:
        iVar1 = 0x32;
        iVar2 = 0x619;
        goto switchD_00170994_default;
      case 6:
        iVar1 = 0x2b;
        if (**(int **)(in_x11 + 0x38) != param_2) {
          iVar1 = 10;
        }
        iVar2 = 0xeec;
        goto switchD_00170994_default;
      case 7:
        iVar13 = iVar13 + ((uint)(iVar13 * 0x9920) >> 0x16) * -0x6b;
        in_x14 = (ulong)(*pbVar5 + uVar8);
        iVar1 = 0x53 - iVar13;
        iVar2 = 0x64f5 - iVar13;
        goto switchD_00170994_default;
      case 8:
        iVar1 = 100 - iVar13;
        uVar9 = (uint)(iVar13 * 0xfa24) >> 0x17;
        iVar13 = 0x83;
        break;
      case 9:
        iVar1 = 0xf;
        if (in_x11 != 0) {
          iVar1 = 0x4b;
        }
        iVar2 = 0x4d8b;
        goto switchD_00170994_default;
      case 10:
        iVar13 = iVar13 + ((uint)(iVar13 * 0x9650) >> 0x16) * -0x6d;
        iVar1 = 0x42;
        if (*(long *)(in_x11 + 0x30) != 0) {
          iVar1 = 0x4a;
        }
        iVar1 = iVar1 - iVar13;
        iVar2 = 0x2c01 - iVar13;
        goto switchD_00170994_default;
      case 0xb:
        in_x11 = 0;
        iVar1 = 0x3b;
        goto switchD_00170994_default;
      case 0xc:
        pbVar5 = (byte *)&iStack_64;
        iVar1 = 0x3a;
        uVar6 = 4;
        in_x12 = 0x9e3779b9;
        in_x14 = 0x9e3779b9;
        in_x13 = 0xfeedbeef;
        goto switchD_00170994_default;
      case 0xd:
        iVar1 = 0x7a;
        goto LAB_00170d48;
      case 0xe:
        iVar1 = 6;
        goto switchD_00170994_default;
      case 0xf:
        iVar10 = 0xbd6a;
        iVar12 = -0xad;
        iVar1 = 0xad;
        iVar2 = 0x763e;
        goto LAB_00170de4;
      case 0x10:
      case 0x4c:
        goto switchD_00170994_caseD_10;
      case 0x11:
        iVar13 = iVar13 + ((uint)(iVar13 * 0xf0f1) >> 0x14) * -0x11;
        iVar1 = 0x54 - iVar13;
        iVar2 = 0x22f6 - iVar13;
        goto switchD_00170994_default;
      case 0x12:
        iVar1 = 0x1d;
        goto switchD_00170994_default;
      case 0x13:
switchD_00170994_caseD_13:
        iVar1 = 0x28;
        iVar2 = iVar13;
        goto switchD_00170994_default;
      case 0x14:
        uVar8 = (uVar8 - uVar9) - uVar7 ^ uVar7 >> 0xd;
        in_x14 = (ulong)uVar8;
        in_x12 = (ulong)((uVar9 - uVar7) - uVar8 ^ uVar8 << 8);
        iVar1 = 0x37;
        goto switchD_00170994_default;
      case 0x15:
        iVar1 = 0x27;
        goto switchD_00170994_default;
      case 0x16:
switchD_00170994_caseD_16:
        iVar1 = 0x19;
        iVar2 = 0x719f;
        goto switchD_00170994_default;
      case 0x17:
        in_x14 = (ulong)(uVar8 + (uint)pbVar5[2] * 0x10000);
        iVar1 = 0x36;
        goto switchD_00170994_default;
      case 0x18:
switchD_00170994_caseD_18:
        iVar1 = 2;
        iVar2 = iVar13;
        goto switchD_00170994_default;
      case 0x19:
        iVar10 = 0x6b;
        iVar1 = 0x5f - iVar13;
        uVar11 = (uint)(iVar13 * 0x9920) >> 0x16;
        in_x12 = (ulong)(uVar9 + (uint)pbVar5[6] * 0x10000);
        goto LAB_00170ea8;
      case 0x1a:
        in_x14 = (ulong)(*(int *)pbVar5 + uVar8);
        in_x12 = (ulong)(*(int *)(pbVar5 + 4) + uVar9);
        in_x13 = (ulong)(*(int *)(pbVar5 + 8) + uVar7);
        iVar1 = 0x14;
        goto switchD_00170994_default;
      case 0x1b:
        in_x13 = (ulong)(uVar7 + 4);
        iVar1 = 8;
        iVar2 = 0x3146;
        goto switchD_00170994_default;
      case 0x1c:
        iVar1 = 0x6b - iVar13;
        uVar9 = (uint)(iVar13 * 0xc566) >> 0x16;
        iVar13 = 0x53;
        break;
      case 0x1d:
        in_x10 = (ulong)(*(int *)(*(long *)(DAT_0018eb08 + 0x10) + 8) - 1U & uVar7);
        iVar1 = 0x11;
        iVar2 = 0x6541;
        goto switchD_00170994_default;
      case 0x1e:
        iVar1 = 0x49 - iVar13;
        uVar9 = (uint)(iVar13 * 0xebbe) >> 0x17;
        iVar13 = 0x8b;
        break;
      case 0x1f:
switchD_00170994_caseD_1f:
        iVar1 = 0x33;
        iVar2 = iVar13;
        goto switchD_00170994_default;
      case 0x20:
        uVar9 = uVar9 ^ uVar8 << 10;
        in_x12 = (ulong)uVar9;
        in_x13 = (ulong)((uVar7 - uVar8) - uVar9 ^ uVar9 >> 0xf);
        iVar1 = 0x41;
        goto switchD_00170994_default;
      case 0x21:
        iVar1 = 0x39;
        iVar2 = 0x582e;
        goto switchD_00170994_default;
      case 0x22:
        iVar1 = 0xb;
        if (*(long *)(**(long **)(DAT_0018eb08 + 0x10) + (in_x10 & 0xffffffff) * 0x10) != 0) {
          iVar1 = 0xd;
        }
        iVar2 = 0x6a65;
        goto switchD_00170994_default;
      case 0x23:
        iVar1 = 0x31;
        goto switchD_00170994_default;
      case 0x24:
        if ((*(uint *)(in_x11 + 0x44) != uVar7) || (iVar1 = 0x16, *(int *)(in_x11 + 0x40) != 4)) {
          iVar1 = 0x13;
        }
        goto switchD_00170994_default;
      case 0x25:
        iVar1 = 0x3f;
LAB_00170d48:
        iVar1 = iVar1 - iVar13;
        uVar9 = (uint)(iVar13 * 0xa8e9) >> 0x16;
        iVar13 = 0x61;
        break;
      case 0x26:
        in_x13 = (ulong)(uVar7 + (uint)pbVar5[8] * 0x100);
        iVar1 = 0x18;
        goto switchD_00170994_default;
      case 0x27:
        iVar1 = 0x25;
        iVar2 = 0x778e;
        goto switchD_00170994_default;
      case 0x28:
        in_x13 = (ulong)(uVar7 + (uint)pbVar5[10] * 0x1000000);
        iVar1 = 0x43;
        goto switchD_00170994_default;
      case 0x29:
        uVar8 = (uVar8 - uVar9) - uVar7 ^ uVar7 >> 0xc;
        in_x14 = (ulong)uVar8;
        in_x13 = (ulong)(uVar7 - uVar8);
        in_x12 = (ulong)((uVar9 - uVar7) - uVar8 ^ uVar8 << 0x10);
        iVar1 = 0x35;
        goto switchD_00170994_default;
      case 0x2a:
switchD_00170994_caseD_2a:
        iVar1 = 0x17;
        iVar2 = iVar13;
        goto switchD_00170994_default;
      case 0x2b:
        iVar12 = -0x47;
        iVar1 = 0x48;
        iVar2 = 0x444e;
        uVar9 = (uint)(iVar13 * 0xe6c3) >> 0x16;
        goto LAB_00171188;
      case 0x2c:
        iVar10 = 0xb50a;
        iVar12 = -0xb5;
        iVar1 = 0x7d;
        iVar2 = 0x16db;
LAB_00170de4:
        uVar9 = (uint)(iVar13 * iVar10) >> 0x17;
LAB_00171188:
        iVar13 = iVar13 + uVar9 * iVar12;
        iVar1 = iVar1 - iVar13;
        iVar2 = iVar2 - iVar13;
        goto switchD_00170994_default;
      case 0x2d:
        in_x11 = *(long *)(**(long **)(DAT_0018eb08 + 0x10) + (in_x10 & 0xffffffff) * 0x10) -
                 (*(long **)(DAT_0018eb08 + 0x10))[4];
        iVar1 = 0x38;
        iVar2 = 0x7b7c;
        goto switchD_00170994_default;
      case 0x2e:
        uVar9 = uVar9 - uVar8 ^ uVar8 << 0x10;
        in_x12 = (ulong)uVar9;
        uVar7 = (uVar7 - uVar8) - uVar9 ^ uVar9 >> 5;
        in_x13 = (ulong)uVar7;
        in_x14 = (ulong)((uVar8 - uVar9) - uVar7);
        iVar1 = 0x48;
        goto switchD_00170994_default;
      case 0x2f:
        in_x14 = (ulong)((uVar8 - uVar9) - uVar7);
        iVar1 = 0x49;
        iVar2 = 0x4418;
        goto switchD_00170994_default;
      case 0x30:
        in_x14 = (ulong)(uVar8 + (uint)pbVar5[1] * 0x100);
        iVar1 = 0x42;
        goto switchD_00170994_default;
      case 0x31:
        pbVar5 = pbVar5 + 0xc;
        uVar6 = uVar6 - 0xc;
        iVar1 = 0x3a;
        goto switchD_00170994_default;
      case 0x32:
        iVar10 = 0x97;
        iVar1 = 0x52 - iVar13;
        uVar11 = (uint)(iVar13 * 0xd902) >> 0x17;
        in_x12 = (ulong)(uVar9 + (uint)pbVar5[5] * 0x100);
LAB_00170ea8:
        iVar1 = iVar1 + uVar11 * iVar10;
        goto switchD_00170994_default;
      case 0x33:
        in_x12 = (ulong)(pbVar5[4] + uVar9);
        iVar1 = 3;
        goto switchD_00170994_default;
      case 0x34:
        iVar1 = 0x44;
        goto switchD_00170994_default;
      case 0x35:
        uVar7 = uVar7 - uVar9 ^ uVar9 >> 5;
        in_x13 = (ulong)uVar7;
        uVar8 = (uVar8 - uVar9) - uVar7 ^ uVar7 >> 3;
        in_x14 = (ulong)uVar8;
        in_x12 = (ulong)((uVar9 - uVar7) - uVar8);
        iVar1 = 0x20;
        goto switchD_00170994_default;
      case 0x36:
switchD_00170994_caseD_36:
        iVar1 = 0x30;
        iVar2 = iVar13;
        goto switchD_00170994_default;
      case 0x37:
        uVar7 = uVar7 - (uVar8 + uVar9) ^ uVar9 >> 0xd;
        in_x13 = (ulong)uVar7;
        in_x12 = (ulong)(uVar9 - uVar7);
        in_x14 = (ulong)((uVar8 - uVar9) - uVar7 ^ uVar7 >> 0xc);
        iVar1 = 0x2e;
        goto switchD_00170994_default;
      case 0x38:
        iVar1 = 0x4c - iVar13;
        uVar9 = (uint)(iVar13 * 0xe6c3) >> 0x16;
        iVar13 = 0x47;
        break;
      case 0x39:
        iVar10 = 0x8ad9;
        iVar12 = -0x3b;
        iVar1 = 0x58;
        iVar2 = 0x3b73;
        goto LAB_00171180;
      case 0x3a:
        iVar1 = 0x1a;
        if (uVar6 < 0xc) {
          iVar1 = 0x1b;
        }
        goto switchD_00170994_default;
      case 0x3b:
        iVar1 = 9;
        goto switchD_00170994_default;
      case 0x3c:
        in_x11 = *(long *)(in_x11 + 0x30) - *(long *)(*(long *)(DAT_0018eb08 + 0x10) + 0x20);
        iVar1 = 0x4a;
        iVar2 = 0x13ed;
        goto switchD_00170994_default;
      case 0x3d:
        in_x11 = 0;
        iVar1 = 0x16 - iVar13;
        uVar9 = (uint)(iVar13 * 0xb217) >> 0x14;
        iVar13 = 0x17;
        break;
      case 0x3e:
        iVar1 = 0x1c;
        iVar2 = 0x6087;
        switch(uVar6) {
        case 1:
          goto switchD_00170994_caseD_42;
        case 2:
          goto switchD_00170994_caseD_36;
        case 3:
          goto switchD_00170994_caseD_2a;
        case 4:
switchD_00170994_caseD_3:
          iVar1 = 0;
          iVar2 = 0x6411;
          break;
        case 5:
          goto switchD_00170994_caseD_1f;
        case 6:
          goto switchD_00170994_caseD_5;
        case 7:
          goto switchD_00170994_caseD_16;
        case 8:
          goto switchD_00170994_caseD_18;
        case 9:
          goto switchD_00170994_caseD_40;
        case 10:
          goto switchD_00170994_caseD_43;
        case 0xb:
          goto switchD_00170994_caseD_13;
        }
        goto switchD_00170994_default;
      case 0x3f:
        iVar1 = 0x33;
        if (**(int **)(in_x11 + 0x38) != param_2) {
          iVar1 = 0x39;
        }
        iVar2 = 0x4284;
        goto switchD_00170994_default;
      case 0x40:
switchD_00170994_caseD_40:
        iVar1 = 0x26;
        iVar2 = iVar13;
        goto switchD_00170994_default;
      case 0x41:
        iVar1 = 4;
        iVar2 = 0x1429;
        goto switchD_00170994_default;
      case 0x42:
switchD_00170994_caseD_42:
        iVar1 = 7;
        iVar2 = 0x7252;
        goto switchD_00170994_default;
      case 0x43:
switchD_00170994_caseD_43:
        iVar1 = 1;
        iVar2 = 0x3a6e;
        goto switchD_00170994_default;
      case 0x44:
        in_x11 = 0;
        iVar1 = 0x2c;
        if (DAT_0018eb08 != 0) {
          iVar1 = 0x12;
        }
        iVar2 = 0x5f1d;
        if (DAT_0018eb08 != 0) {
          iVar2 = iVar13;
        }
        goto switchD_00170994_default;
      case 0x45:
        iVar1 = 0x3c;
        goto switchD_00170994_default;
      case 0x46:
        iVar1 = 0x22;
        goto switchD_00170994_default;
      case 0x47:
        iVar10 = 0x9a91;
        iVar12 = -0x35;
        iVar1 = 0x67;
        iVar2 = 0x2325;
LAB_00171180:
        uVar9 = (uint)(iVar13 * iVar10) >> 0x15;
        goto LAB_00171188;
      case 0x48:
        uVar8 = uVar8 ^ uVar7 >> 3;
        in_x14 = (ulong)uVar8;
        uVar9 = (uVar9 - uVar7) - uVar8 ^ uVar8 << 10;
        in_x12 = (ulong)uVar9;
        in_x13 = (ulong)((uVar7 - uVar8) - uVar9 ^ uVar9 >> 0xf);
        iVar1 = 0x23;
        goto switchD_00170994_default;
      case 0x49:
        uVar8 = uVar8 ^ uVar7 >> 0xd;
        in_x14 = (ulong)uVar8;
        uVar9 = (uVar9 - uVar7) - uVar8 ^ uVar8 << 8;
        in_x12 = (ulong)uVar9;
        in_x13 = (ulong)((uVar7 - uVar8) - uVar9 ^ uVar9 >> 0xd);
        iVar1 = (((uint)(iVar13 * 0x924a) >> 0x12) * 7 + 0x2b) - iVar13;
        goto switchD_00170994_default;
      case 0x4a:
        iVar1 = 0x1a - iVar13;
        uVar9 = (uint)(iVar13 * 0xc7cf) >> 0x15;
        iVar13 = 0x29;
        break;
      case 0x4b:
        goto switchD_00170994_caseD_4b;
      default:
        goto switchD_00170994_default;
      }
      iVar1 = iVar1 + uVar9 * iVar13;
      goto switchD_00170994_default;
    }
  } while( true );
switchD_00170994_caseD_4b:
  iVar13 = iVar13 + ((uint)(iVar13 * 0xef2f) >> 0x17) * -0x89;
  if ((*(uint *)(in_x11 + 0x44) == uVar7) && (*(int *)(in_x11 + 0x40) == 4)) {
    iVar1 = 0x81;
  }
  else {
    iVar1 = 0x85;
  }
  iVar1 = iVar1 - iVar13;
  iVar2 = 0x1e4e - iVar13;
  goto switchD_00170994_default;
switchD_00170994_caseD_10:
  if ((in_x11 == 0) ||
     (lVar3 = (**(code **)(*param_1 + 200))(param_1,*(undefined8 *)(in_x11 + 8)),
     in_x10 = extraout_x10, in_x11 = extraout_x11, in_x12 = extraout_x12, in_x13 = extraout_x13,
     in_x14 = extraout_x14, lVar3 == 0)) {
    uVar4 = 6;
  }
  else {
    uVar4 = 3;
  }
  goto switchD_00170894_default;
}


/* EXPORT index=279 ELF_VA=0x7300c size=344 source_sha256=33e4b70b2f8d8522b51918633cfde9fb09c3c277381b7fa82dec13d351cdc0c7 */

undefined8 j___OI_l__ISOS___SlS5_I_S0I_IIlO_OI0S0IllS_II5IOllIS5_(long *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  void *__s;
  char *unaff_x20;
  undefined8 *unaff_x21;
  undefined4 uVar4;
  
  uVar4 = 4;
LAB_00173054:
  switch(uVar4) {
  case 0:
  case 5:
    uVar3 = FUN_0017317c(*unaff_x20);
    return uVar3;
  case 1:
    uVar4 = 2;
    if (*unaff_x20 == '[') {
      uVar4 = 3;
    }
    goto LAB_00173054;
  case 2:
    __s = malloc((long)*(int *)(unaff_x21 + 1));
    memset(__s,0,(long)*(int *)(unaff_x21 + 1));
    unaff_x20 = unaff_x20 + 1;
    iVar1 = *(int *)(unaff_x21 + 1) + -2;
    break;
  case 3:
    __s = malloc((long)(*(int *)(unaff_x21 + 1) + 1));
    memset(__s,0,(long)(*(int *)(unaff_x21 + 1) + 1));
    iVar1 = *(int *)(unaff_x21 + 1);
    break;
  case 4:
    goto switchD_00173068_caseD_4;
  default:
    goto switchD_00173068_default;
  }
  memcpy(__s,unaff_x20,(long)iVar1);
  uVar3 = (**(code **)(*param_1 + 0x30))(param_1,__s);
  free(__s);
  return uVar3;
switchD_00173068_default:
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
switchD_00173068_caseD_4:
  puVar2 = (undefined4 *)j___05III_lS55I__IlI5_SII0__S_l_I5OSI5ISSOOI5_O0lllS5_(param_2);
  unaff_x21 = (undefined8 *)j____l0_l_OIIlI_IS5ll_OO_Il_l5O05550O5l_IO_II_I5O55S5_(*puVar2);
  unaff_x20 = (char *)*unaff_x21;
  if ((*unaff_x20 == '\0') || (uVar4 = 0, unaff_x20[1] != '\0')) {
    uVar4 = 1;
  }
  goto LAB_00173054;
}


/* EXPORT index=280 ELF_VA=0x73380 size=12 source_sha256=197e55728617569743c9699f3d606991217ae44cd959703e7daf46ea34813d2a */

void j___000_I_05I5l_I050__50III_II__5ll0__I5S_OOll0II5_S5_(long *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00173388. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xd8))();
  return;
}


/* EXPORT index=281 ELF_VA=0x7338c size=2848 source_sha256=4e00b6ad5b195cda7eb5c7ee0363be5f8a19306fa6cc8a7a00b14790eeb548b9 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
j___5l5_I_l55I0_IlIlO_O_l_l_IlISI_5Sl5I0OOllI_Oll_SS5_
          (long *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  code *pcVar7;
  undefined8 *unaff_x22;
  byte *unaff_x24;
  uint uVar8;
  int iVar9;
  undefined8 unaff_x27;
  char *pcStack_d0;
  char *pcStack_c8;
  char *pcStack_b8;
  char *pcStack_b0;
  byte abStack_a0 [56];
  long lStack_68;
  
  iVar9 = 0x4f57;
  lStack_68 = ___stack_chk_guard;
  abStack_a0[0x11] = 0x67;
  abStack_a0[0x12] = 0x39;
  abStack_a0[0x13] = 0x6e;
  abStack_a0[0x14] = 0x5f;
  abStack_a0[0x15] = 0x1a;
  abStack_a0[0x16] = 0x45;
  abStack_a0[0x17] = 0x11;
  abStack_a0[0x18] = 0x78;
  abStack_a0[0x10] = 0x3d;
  iVar6 = 6;
  abStack_a0[8] = 99;
  abStack_a0[9] = 0x68;
  abStack_a0[10] = 0x75;
  abStack_a0[0xb] = 0x7b;
  abStack_a0[0xc] = 0xb;
  abStack_a0[0xd] = 0x1c;
  abStack_a0[0xe] = 0x5b;
  abStack_a0[0xf] = 0x14;
  abStack_a0[0] = 0x6b;
  abStack_a0[1] = 0x28;
  abStack_a0[2] = 6;
  abStack_a0[3] = 0x68;
  abStack_a0[4] = 0x13;
  abStack_a0[5] = 0x43;
  abStack_a0[6] = 0x25;
  abStack_a0[7] = 10;
  pcStack_d0 = (char *)0x0;
  bVar1 = 0;
  uVar8 = 0x5997b8ca;
  pcStack_c8 = pcStack_d0;
  pcStack_b8 = pcStack_d0;
  pcStack_b0 = pcStack_d0;
switchD_00173440_default:
  bVar3 = (byte)uVar8;
  switch(iVar6) {
  case 0:
  case 9:
  case 0xd:
  case 0x19:
  case 0x2d:
    goto switchD_00173440_caseD_0;
  case 1:
    uVar8 = uVar8 * 2 * uVar8 * 2;
    iVar6 = 0x1d;
    goto switchD_00173440_default;
  case 2:
    abStack_a0[uVar8 + 0x32f92564] = abStack_a0[uVar8 + 0x32f92564] ^ bVar3 + 0x76;
    abStack_a0[uVar8 ^ 0xcd06daaf] = bVar3 ^ abStack_a0[uVar8 ^ 0xcd06daaf] ^ 0xd1;
    abStack_a0[uVar8 + 0x32f92572] = abStack_a0[uVar8 + 0x32f92572] ^ bVar3 + 0x6a;
    uVar2 = uVar8 + 0x32f92576;
    abStack_a0[uVar8 + 0x32f92561] = abStack_a0[uVar8 + 0x32f92561] ^ bVar3 - 0x39;
    uVar8 = uVar8 + 0x4f7e6e78;
    abStack_a0[uVar2] = abStack_a0[uVar2] ^ bVar3 + 0x76;
    iVar6 = 8;
    goto switchD_00173440_default;
  case 3:
switchD_00173440_caseD_3:
    iVar6 = 0xe;
    goto switchD_00173440_default;
  case 4:
    uVar8 = ((uVar8 ^ 0x1363eb1e) * 0xcf983ab ^ 0xd36f7d54) + 0x4586d46a;
    (**(code **)(*param_1 + 0xb8))(param_1,pcStack_c8);
    iVar6 = 0xd;
    goto switchD_00173440_default;
  case 5:
    uVar8 = uVar8 << 1;
LAB_00173e30:
    iVar6 = 0x15;
    goto switchD_00173440_default;
  case 6:
    puVar4 = (undefined4 *)j___05III_lS55I__IlI5_SII0__S_l_I5OSI5ISSOOI5_O0lllS5_(param_2);
    unaff_x22 = (undefined8 *)j____l0_l_OIIlI_IS5ll_OO_Il_l5O05550O5l_IO_II_I5O55S5_(*puVar4);
    pcStack_b0 = (char *)*unaff_x22;
    if (pcStack_b0[1] != 'L') {
      unaff_x27 = 0;
      iVar9 = 0x1812;
      iVar6 = 0x2c;
      if (pcStack_b0[1] != '[') goto switchD_00173440_default;
    }
    unaff_x27 = 0;
    iVar9 = 0x1812;
    iVar6 = 0x11;
    goto switchD_00173440_default;
  case 7:
    uVar8 = uVar8 * 2 + 0xef6d9ae9;
switchD_0017393c_caseD_49:
    iVar6 = 0x1e;
    goto switchD_00173440_default;
  case 8:
    abStack_a0[uVar8 + 0xe37ab6fc] = bVar3 ^ abStack_a0[uVar8 + 0xe37ab6fc] ^ 0x54;
    abStack_a0[uVar8 + 0xe37ab6f1] = abStack_a0[uVar8 + 0xe37ab6f1] ^ bVar3 + 0x2b;
    uVar2 = uVar8 + 0x832a981d;
    abStack_a0[uVar8 + 0xe37ab6f0] = abStack_a0[uVar8 + 0xe37ab6f0] ^ bVar3 + 0x41;
    abStack_a0[uVar2 ^ 0x9fafe125] = abStack_a0[uVar2 ^ 0x9fafe125] ^ bVar3 - 0xb;
    abStack_a0[uVar8 + 0xe37ab6eb] = abStack_a0[uVar8 + 0xe37ab6eb] ^ bVar3 + 0x1b;
    abStack_a0[uVar8 + 0xe37ab6fb] = (byte)uVar2 ^ abStack_a0[uVar8 + 0xe37ab6fb] ^ 0x52;
    iVar6 = 0x2b;
    uVar8 = uVar2;
    goto switchD_00173440_default;
  case 10:
    pcVar7 = *(code **)(*param_1 + 0x5a8);
    uVar8 = uVar8 + 0xb3d9d1f4;
    break;
  case 0xb:
    abStack_a0[uVar8 + 0xc0a03dad] = abStack_a0[uVar8 + 0xc0a03dad] ^ bVar3 - 0x29;
    uVar2 = uVar8 + 0x86cf7d3b ^ 0xc62f3fae;
    abStack_a0[uVar8 + 0xc0a03d96] = abStack_a0[uVar8 + 0xc0a03d96] ^ bVar3 + 0xa0;
    uVar8 = (uVar8 + 0x86cf7d3b) * 2;
    abStack_a0[uVar2] = abStack_a0[uVar2] ^ bVar3 + 0xa5;
    abStack_a0[uVar8 ^ 0x8c5e7f48] = abStack_a0[uVar8 ^ 0x8c5e7f48] ^ (char)uVar8 + 2U;
    abStack_a0[uVar8 + 0x73a180c7] = abStack_a0[uVar8 + 0x73a180c7] ^ (char)uVar8 - 0x1aU;
    iVar6 = 0x1a;
    goto switchD_00173440_default;
  case 0xc:
    pvVar5 = malloc((long)*(int *)(unaff_x22 + 1));
    memset(pvVar5,0,(long)*(int *)(unaff_x22 + 1));
    memcpy(pvVar5,pcStack_b0 + 2,(long)(*(int *)(unaff_x22 + 1) + -1));
    pcStack_c8 = (char *)(**(code **)(*param_1 + 0x30))(param_1,pvVar5);
    unaff_x27 = (**(code **)(*param_1 + 0x560))(param_1,param_3,pcStack_c8,0);
    free(pvVar5);
    iVar6 = 0xd;
    if (pcStack_c8 != (char *)0x0) {
      iVar6 = 0xf;
    }
    goto switchD_00173440_default;
  case 0xe:
    pcVar7 = *(code **)(*param_1 + 0x580);
    uVar8 = uVar8 * 2 + 0xea004df7;
    break;
  case 0xf:
    iVar6 = 4;
    uVar8 = ((uVar8 ^ 0xae9548e2) * (uVar8 ^ 0xae9548e2) * 2 & 0x10bddfc8 ^ 0x2ceec08b) + 0x4d05f398
    ;
    goto switchD_00173440_default;
  case 0x10:
    pvVar5 = malloc((long)*(int *)(unaff_x22 + 1));
    memset(pvVar5,0,(long)*(int *)(unaff_x22 + 1));
    memcpy(pvVar5,pcStack_b0 + 1,(long)(*(int *)(unaff_x22 + 1) + -1));
    pcStack_b8 = (char *)(**(code **)(*param_1 + 0x30))(param_1,pvVar5);
    unaff_x27 = (**(code **)(*param_1 + 0x560))(param_1,param_3,pcStack_b8,0);
    free(pvVar5);
    iVar6 = 10;
    if (pcStack_b8 != (char *)0x0) {
      iVar6 = 0x1d;
    }
    goto switchD_00173440_default;
  case 0x11:
    iVar9 = iVar9 + ((uint)(iVar9 * 0xae4d) >> 0x15) * -0x2f;
    if ((*pcStack_b0 == '[') && (pcStack_b0[1] == 'L')) {
      iVar6 = 0x19;
    }
    else {
      iVar6 = 0x28;
    }
    iVar6 = iVar6 - iVar9;
    iVar9 = 0x478f - iVar9;
    goto switchD_00173440_default;
  case 0x12:
    do {
      CallSupervisor(0);
    } while (unaff_x24 == (byte *)0xfffffffffffffffc);
    iVar9 = 0x94a;
    iVar6 = 0x27;
    goto switchD_00173440_default;
  case 0x13:
    if (bVar1 < 0x5a) {
      if (0x52 < bVar1) {
        if (bVar1 == 0x53) goto LAB_00173a38;
        goto switchD_00173440_caseD_25;
      }
      iVar6 = 0x1d;
      switch(bVar1) {
      case 0x42:
        goto switchD_00173440_caseD_3;
      case 0x43:
        goto switchD_00173440_caseD_1b;
      case 0x44:
        goto switchD_0017393c_caseD_44;
      case 0x46:
        goto switchD_0017393c_caseD_46;
      case 0x49:
        goto switchD_0017393c_caseD_49;
      case 0x4a:
        goto switchD_00173440_default;
      }
    }
    else if (bVar1 == 0x5a) goto LAB_00173e30;
  case 0x25:
switchD_00173440_caseD_25:
    iVar6 = 0x24;
    goto switchD_00173440_default;
  case 0x14:
    iVar9 = iVar9 + ((uint)(iVar9 * 0xf0f1) >> 0x14) * -0x11;
    pvVar5 = malloc((long)*(int *)(unaff_x22 + 1));
    memset(pvVar5,0,(long)*(int *)(unaff_x22 + 1));
    memcpy(pvVar5,pcStack_b0 + 2,(long)(*(int *)(unaff_x22 + 1) + -3));
    pcStack_d0 = (char *)(**(code **)(*param_1 + 0x30))(param_1,pvVar5);
    unaff_x27 = (**(code **)(*param_1 + 0x560))(param_1,param_3,pcStack_d0,0);
    free(pvVar5);
    iVar6 = 0x1e;
    if (pcStack_d0 != (char *)0x0) {
      iVar6 = 0x2e;
    }
    iVar6 = iVar6 - iVar9;
    iVar9 = 0x6f4 - iVar9;
    goto switchD_00173440_default;
  case 0x15:
    pcVar7 = *(code **)(*param_1 + 0x578);
    break;
  case 0x16:
    iVar6 = 2;
    abStack_a0[10] = abStack_a0[10] ^ 0x31;
    uVar8 = 0xcd06daa0;
    goto switchD_00173440_default;
  case 0x17:
    uVar8 = uVar8 ^ 0x6057b638;
LAB_00173a38:
    iVar6 = 0x22;
    goto switchD_00173440_default;
  case 0x18:
    pcVar7 = *(code **)(*param_1 + 0x5b0);
    uVar8 = (uVar8 ^ 0xc0ab6a16) + 0x9706b4c ^ 0x8759aa84;
    break;
  case 0x1a:
    abStack_a0[uVar8 + 0x73a180c3] = abStack_a0[uVar8 + 0x73a180c3] ^ bVar3 - 0x32;
    abStack_a0[uVar8 + 0x73a180ce] = bVar3 ^ abStack_a0[uVar8 + 0x73a180ce] ^ 0x32;
    do {
      unaff_x24 = abStack_a0;
      CallSupervisor(0);
    } while (unaff_x24 == (byte *)0xfffffffffffffffc);
    do {
      CallSupervisor(0);
    } while (unaff_x24 == (byte *)0xfffffffffffffffc);
    iVar6 = 0x12;
    uVar8 = uVar8 * 4 + 0x2ba71426;
    goto switchD_00173440_default;
  case 0x1b:
switchD_00173440_caseD_1b:
    iVar9 = 0x1330;
    iVar6 = 0x1c;
    goto switchD_00173440_default;
  case 0x1c:
    unaff_x27 = (**(code **)(*param_1 + 0x588))(param_1,param_3);
    iVar6 = (7 - iVar9) + ((uint)(iVar9 * 0x9650) >> 0x16) * 0x6d;
    uVar8 = uVar8 * 2 + 0x13ccdbea;
    goto switchD_00173440_default;
  case 0x1d:
  case 0x26:
    pcVar7 = *(code **)(*param_1 + 0x5a0);
    break;
  case 0x1e:
    pcVar7 = *(code **)(*param_1 + 0x598);
    break;
  case 0x1f:
    uVar8 = (uVar8 & 0x9523c5ef) + 0xd30bd74d;
switchD_0017393c_caseD_46:
    iVar6 = 10;
    goto switchD_00173440_default;
  case 0x20:
    bVar1 = pcStack_b0[1];
    iVar6 = (0x2d - iVar9) + ((uint)(iVar9 * 0x864c) >> 0x15) * 0x3d;
    uVar8 = uVar8 * 0x339d3492;
    goto switchD_00173440_default;
  case 0x21:
    iVar6 = 0;
    uVar8 = uVar8 + 0x42f1032d;
    goto switchD_00173440_default;
  case 0x22:
    pcVar7 = *(code **)(*param_1 + 0x590);
    break;
  case 0x23:
    uVar8 = uVar8 * uVar8 + 0x513ca740;
    if (*pcStack_b0 == '[') {
      iVar9 = 0x6bf4;
      iVar6 = 0x27;
      if (pcStack_b0[1] == '[') goto switchD_00173440_default;
    }
    iVar9 = 0x6bf4;
    iVar6 = 0xc;
    goto switchD_00173440_default;
  case 0x24:
    iVar6 = 0;
    goto switchD_00173440_default;
  case 0x27:
    pvVar5 = malloc((long)*(int *)(unaff_x22 + 1));
    memset(pvVar5,0,(long)*(int *)(unaff_x22 + 1));
    memcpy(pvVar5,pcStack_b0 + 1,(long)(*(int *)(unaff_x22 + 1) + -1));
    pcStack_b8 = (char *)(**(code **)(*param_1 + 0x30))(param_1,pvVar5);
    unaff_x27 = (**(code **)(*param_1 + 0x560))(param_1,param_3,pcStack_b8,0);
    free(pvVar5);
    if (pcStack_b8 == (char *)0x0) {
      pcStack_b8 = (char *)0x0;
      iVar6 = 0x8a;
    }
    else {
      iVar6 = 0xa9;
    }
    iVar6 = iVar6 - (iVar9 + ((uint)(iVar9 * 0xbd6a) >> 0x17) * -0xad);
    goto switchD_00173440_default;
  case 0x28:
    (**(code **)(*param_1 + 0xb8))(param_1,pcStack_b8);
    iVar6 = 9;
    uVar8 = uVar8 * 2 * uVar8 * 2;
    goto switchD_00173440_default;
  case 0x29:
    (**(code **)(*param_1 + 0xb8))(param_1,pcStack_d0);
    iVar6 = (0x39 - iVar9) + ((uint)(iVar9 * 0xc566) >> 0x16) * 0x53;
    goto switchD_00173440_default;
  case 0x2a:
    uVar8 = uVar8 + 0xc862f4e9;
switchD_0017393c_caseD_44:
    iVar6 = 0x18;
    goto switchD_00173440_default;
  case 0x2b:
    uVar2 = uVar8 * 2;
    abStack_a0[uVar8 + 0x60501ee0] = abStack_a0[uVar8 + 0x60501ee0] ^ bVar3 - 2;
    bVar3 = (byte)uVar2;
    abStack_a0[uVar2 + 0xc0a03da2] = abStack_a0[uVar2 + 0xc0a03da2] ^ bVar3 + 0x9f;
    abStack_a0[uVar2 ^ 0x3f5fc264] = bVar3 ^ abStack_a0[uVar2 ^ 0x3f5fc264] ^ 0x74;
    abStack_a0[uVar2 + 0xc0a03d9d] = abStack_a0[uVar2 + 0xc0a03d9d] ^ bVar3 + 0x10;
    abStack_a0[uVar2 + 0xc0a03d9c] = abStack_a0[uVar2 + 0xc0a03d9c] ^ bVar3 + 0xe;
    abStack_a0[uVar2 + 0xc0a03d9b] = abStack_a0[uVar2 + 0xc0a03d9b] ^ bVar3 - 0x29;
    iVar6 = 0xb;
    uVar8 = uVar2;
    goto switchD_00173440_default;
  case 0x2c:
    goto switchD_00173440_caseD_2c;
  default:
    goto switchD_00173440_default;
  }
  unaff_x27 = (*pcVar7)(param_1,param_3);
  iVar6 = 0;
  goto switchD_00173440_default;
switchD_00173440_caseD_2c:
  iVar9 = 0x2f6;
  iVar6 = 0x20;
  goto switchD_00173440_default;
switchD_00173440_caseD_0:
  if (___stack_chk_guard != lStack_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return unaff_x27;
}


/* EXPORT index=282 ELF_VA=0x73f88 size=36 source_sha256=08bd2578da1f6f3994b355ef4ca4166ac3dfec3080c41dfbac786ccc79474bb8 */

undefined8
j___lSI0__II_SS_llI5I_II__O_IS5OIO0IOS5_IlI_ISIlIl_S5_(undefined8 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined4 *)j___05III_lS55I__IlI5_SII0__S_l_I5OSI5ISSOOI5_O0lllS5_(param_2);
  puVar2 = (undefined8 *)j____l0_l_OIIlI_IS5ll_OO_Il_l5O05550O5l_IO_II_I5O55S5_(*puVar1);
  return *puVar2;
}


/* EXPORT index=283 ELF_VA=0x73fac size=8 source_sha256=bac21b6c3b048e3e73f0272a1683f750b9935e99c38ebec194f85b1047af5eb6 */

void j___lIS0I_ll_OI_OSI_I__5II__S_SIlOIIl5llI0SI_O5I___S5_(undefined8 param_1,undefined4 param_2)

{
  j____Il0I_llI0l_SIIII_I_O_l_Ill_O5_IOI5I__S_I0IllOlS5_(param_2);
  return;
}


/* EXPORT index=284 ELF_VA=0x73fb4 size=8 source_sha256=f420ea570ad5b163f2e5d626738931386bdc65138e9f6970eb6baa7cf21dba7c */

void j___S_0SI_I0IlS_I_5I___S_O0_II5I_5I5l5__lIIIlOII__IS5_(undefined8 param_1,undefined4 param_2)

{
  j___5OISI_IIIII_IlSII_lIIll_lO_Il5II0_00I0IllOIS_5IS5_(param_2);
  return;
}

