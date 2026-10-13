
/* WARNING: Type propagation algorithm not settling */
/* LayerFlowNS::CLFDenseHairProcessor::applyLayer() */

bool __thiscall LayerFlowNS::CLFDenseHairProcessor::applyLayer(CLFDenseHairProcessor *this)

{
  piecewise_construct_t *ppVar1;
  char *pcVar2;
  bool bVar3;
  char cVar4;
  basic_string bVar5;
  basic_string bVar6;
  byte bVar7;
  piecewise_construct_t pVar8;
  long lVar9;
  undefined2 uVar10;
  ushort uVar11;
  char *pcVar12;
  void *pvVar13;
  undefined8 *puVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  undefined1 uVar18;
  uint uVar19;
  int iVar20;
  undefined4 uVar21;
  long lVar22;
  CMTIKHairFilter *this_00;
  long *plVar23;
  piecewise_construct_t *ppVar24;
  ulong uVar25;
  void *pvVar26;
  piecewise_construct_t **pppVar27;
  char *pcVar28;
  detail *this_01;
  basic_json *pbVar29;
  undefined8 uVar30;
  basic_string *pbVar31;
  ushort *puVar32;
  char *pcVar33;
  string_t *psVar34;
  char *pcVar35;
  char *pcVar36;
  char *pcVar37;
  char *pcVar38;
  undefined8 *puVar39;
  undefined8 *puVar40;
  undefined8 uVar41;
  undefined8 uVar42;
  long lVar43;
  undefined8 *puVar44;
  piecewise_construct_t *ppVar45;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *this_02;
  piecewise_construct_t *ppVar46;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *local_4e0;
  piecewise_construct_t *ppStack_4d8;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *local_4d0;
  piecewise_construct_t *local_4c8;
  undefined1 auStack_4c0 [8];
  long *local_4b8;
  piecewise_construct_t *local_4b0;
  piecewise_construct_t *ppStack_4a8;
  char *local_4a0;
  undefined8 local_490;
  long *local_488;
  undefined8 local_480;
  long *local_478;
  undefined8 local_470;
  long lStack_468;
  long local_460;
  long lStack_458;
  undefined8 local_450;
  long *local_448;
  piecewise_construct_t *local_440;
  piecewise_construct_t *ppStack_438;
  char *local_430;
  piecewise_construct_t local_428 [8];
  piecewise_construct_t *local_420;
  byte local_418;
  undefined7 uStack_417;
  piecewise_construct_t *ppStack_410;
  char *local_408;
  CMTIKHairVolumeInfo aCStack_400 [112];
  piecewise_construct_t *local_390;
  piecewise_construct_t *ppStack_388;
  char *local_380;
  piecewise_construct_t *local_370;
  piecewise_construct_t *ppStack_368;
  char *local_360;
  undefined8 *local_358;
  undefined8 local_350;
  undefined8 local_348;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *local_340;
  piecewise_construct_t *local_338;
  ulong local_330;
  undefined8 uStack_328;
  void *local_320;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *local_318;
  piecewise_construct_t *local_310;
  byte local_308;
  char local_307 [8];
  undefined7 uStack_2ff;
  undefined4 uStack_2f8;
  uint uStack_2f4;
  long local_2f0;
  piecewise_construct_t *local_2e8;
  byte local_2d8;
  void *local_2c8;
  char *local_2c0;
  char *local_2b8;
  long local_2a8;
  long *local_2a0;
  piecewise_construct_t *local_298;
  piecewise_construct_t *local_290;
  char *local_288;
  void *local_280;
  void *local_278;
  undefined8 local_270;
  undefined4 local_268;
  undefined1 local_264;
  piecewise_construct_t *local_260;
  piecewise_construct_t *ppStack_258;
  char *local_250;
  undefined8 local_248;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *local_238;
  piecewise_construct_t *local_230;
  char *local_228;
  long local_220 [4];
  long *local_200;
  long local_1f0 [4];
  long *local_1d0;
  undefined8 local_1c0;
  undefined6 local_1b8;
  undefined2 uStack_1b2;
  piecewise_construct_t *local_1b0;
  piecewise_construct_t *ppStack_1a8;
  char *local_1a0;
  basic_string local_198;
  basic_string bStack_197;
  undefined6 uStack_196;
  undefined2 local_190;
  undefined6 uStack_18e;
  undefined8 local_188;
  ushort local_180;
  undefined6 local_17e;
  undefined2 uStack_178;
  undefined6 uStack_176;
  void *local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  basic_string abStack_150 [24];
  basic_string abStack_138 [24];
  basic_string abStack_120 [24];
  basic_string abStack_108 [24];
  basic_string abStack_f0 [24];
  basic_string abStack_d8 [24];
  basic_string abStack_c0 [24];
  undefined8 local_a8;
  undefined1 auStack_a0 [24];
  long local_88;
  
  lVar9 = tpidr_el0;
  local_88 = *(long *)(lVar9 + 0x28);
  if (*(long *)(this + 0x40) == 0) {
                    /* try { // try from 004f9584 to 005f9597 has its CatchHandler @ 004f99e8 */
    pcVar33 = "CLFDenseHairProcessor<%s:%d> layer is nullptr, return false.";
    uVar30 = 0x85;
LAB_004f95c8:
    MTImageKitNS::CMTIKLog::log("iklf",6,pcVar33,"applyLayer",uVar30);
    bVar17 = false;
  }
  else {
    if (*(long *)(this + 0x28) == 0) {
                    /* try { // try from 004f95a8 to 005f95af has its CatchHandler @ 004f99d0 */
      pcVar33 = "CLFDenseHairProcessor<%s:%d> mtikManager is nullptr, return false.";
      uVar30 = 0x89;
      goto LAB_004f95c8;
    }
                    /* catch() { ... } // from try @ 004f9848 with catch @ 004f9554 */
    local_2a8 = __dynamic_cast(*(long *)(this + 0x40),&CLFBaseLayer::typeinfo,
                               &CLFDenseHairLayer::typeinfo,0);
    if (local_2a8 == 0) {
                    /* try { // try from 004f95d4 to 005f95db has its CatchHandler @ 004f9870 */
      local_2a0 = (long *)0x0;
      local_2a8 = 0;
    }
    else {
      local_2a0 = *(long **)(this + 0x48);
      if (local_2a0 != (long *)0x0) {
        FUN_006263b0(1,local_2a0 + 1);
      }
    }
                    /* try { // try from 004f95e0 to 005f95fb has its CatchHandler @ 004f99c0 */
    CLFDenseHairLayer::getModular();
    lVar22 = CLFBaseProcessor::getFilterFromMgr((long)this);
                    /* try { // try from 004f9608 to 005f9617 has its CatchHandler @ 004f99ac */
    if ((lVar22 == 0) ||
       (this_00 = (CMTIKHairFilter *)
                  __dynamic_cast(lVar22,&MTImageKitNS::CMTIKFilter::typeinfo,
                                 &MTImageKitNS::CMTIKHairFilter::typeinfo,0),
       this_00 == (CMTIKHairFilter *)0x0)) {
                    /* try { // try from 004f962c to 005f9643 has its CatchHandler @ 004f99a0 */
      this_00 = operator_new(0xc80);
      MTImageKitNS::CMTIKHairFilter::CMTIKHairFilter(this_00);
      plVar23 = *(long **)(this + 0x38);
      if (plVar23 == (long *)0x0) {
        MTImageKitNS::CMTIKManager::addFilter(*(CMTIKFilter **)(this + 0x28),(long)this_00,true);
      }
      else {
        (**(code **)(*plVar23 + 0x538))(plVar23,this_00);
                    /* try { // try from 004f9654 to 005f9663 has its CatchHandler @ 004f998c */
      }
                    /* try { // try from 004f9678 to 005f968f has its CatchHandler @ 004f9918 */
      *(undefined8 *)(*(long *)(this + 0x40) + 0x4c8) = *(undefined8 *)(this_00 + 8);
LAB_004f967c:
      MTImageKitNS::CMTIKHairFilter::initFaceData();
      lVar22 = *(long *)(this + 0x20);
    }
    else {
      lVar22 = *(long *)(this + 0x20);
      if (*(char *)(lVar22 + 0x11d) != '\0') goto LAB_004f967c;
    }
    local_308 = 0x26;
                    /* try { // try from 004f96a0 to 005f96af has its CatchHandler @ 004f9908 */
    uStack_2f4 = uStack_2f4 & 0xffffff00;
    uStack_2ff = 0x6c507265646e65;
    uStack_2f8 = 0x6e696775;
    builtin_strncpy(local_307,"formulaR",8);
    CLFFormulaShop::findPlugin(&local_1b0,lVar22,&local_308);
                    /* try { // try from 004f96c4 to 005f96db has its CatchHandler @ 004f98e8 */
    if ((local_1b0 == (piecewise_construct_t *)0x0) ||
       (local_2f0 = __dynamic_cast(local_1b0,&CLFBasePlugin<LayerFlowNS::CLFFormulaShop>::typeinfo,
                                   &CLFFormulaRenderPlugin::typeinfo,0), local_2f0 == 0)) {
      local_2e8 = (piecewise_construct_t *)0x0;
      local_2f0 = 0;
    }
    else {
                    /* try { // try from 004f96ec to 005f96fb has its CatchHandler @ 004f98d8 */
      local_2e8 = ppStack_1a8;
      if (ppStack_1a8 != (piecewise_construct_t *)0x0) {
        FUN_006263b0(1,ppStack_1a8 + 8);
      }
    }
    ppVar24 = ppStack_1a8;
                    /* try { // try from 004f9714 to 005f972b has its CatchHandler @ 004f98b8 */
    if ((ppStack_1a8 != (piecewise_construct_t *)0x0) &&
       (lVar22 = FUN_006263e0(0xffffffffffffffff,ppStack_1a8 + 8), lVar22 == 0)) {
                    /* try { // try from 004f9730 to 005f974f has its CatchHandler @ 004f9884 */
      (**(code **)(*(long *)ppVar24 + 0x10))(ppVar24);
      std::__ndk1::__shared_weak_count::__release_weak();
    }
    if ((local_308 & 1) != 0) {
      operator_delete((void *)CONCAT44(uStack_2f4,uStack_2f8));
    }
    local_310 = (piecewise_construct_t *)0x0;
    local_318 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                0x0;
    if (local_2f0 == 0) {
      bVar15 = false;
    }
    else {
      lVar43 = *(long *)(local_2f0 + 0x50);
      bVar15 = lVar43 != 0;
                    /* try { // try from 004f9770 to 005f9777 has its CatchHandler @ 004f9880 */
      CLFFormulaRenderPlugin::getFreeToken();
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                (this_00 + 0x520),(basic_string *)&local_260);
      lVar22 = local_2f0;
                    /* try { // try from 004f9780 to 005f97bb has its CatchHandler @ 004f9a24 */
      if (lVar43 != 0) {
        if ((*(byte *)(local_2a8 + 8) & 1) == 0) {
          local_320 = *(void **)(local_2a8 + 0x18);
          uStack_328 = *(undefined8 *)(local_2a8 + 0x10);
          local_330 = *(ulong *)(local_2a8 + 8);
        }
        else {
          FUN_003bc260(&local_330,*(undefined8 *)(local_2a8 + 0x18),
                       *(undefined8 *)(local_2a8 + 0x10));
        }
        plVar23 = *(long **)(lVar22 + 0x50);
                    /* try { // try from 004f97c4 to 005f97d7 has its CatchHandler @ 004f9a20 */
        if (plVar23 == (long *)0x0) {
                    /* try { // try from 004fc344 to 005fc34b has its CatchHandler @ 004fc36c */
          if (*(long *)(lVar9 + 0x28) == local_88) {
                    /* WARNING: Subroutine does not return */
            FUN_003bc2f4();
          }
          goto LAB_004fc7ac;
        }
        (**(code **)(*plVar23 + 0x30))(&local_1b0,plVar23,&local_330);
                    /* try { // try from 004f97e0 to 005f97f3 has its CatchHandler @ 004f9a1c */
        if ((local_330 & 1) != 0) {
          operator_delete(local_320);
        }
        ppVar24 = operator_new(0x168);
                    /* try { // try from 004f97fc to 005f980f has its CatchHandler @ 004f9a18 */
        *(undefined8 *)(ppVar24 + 0x10) = 0;
        *(undefined8 *)(ppVar24 + 8) = 0;
                    /* try { // try from 004f9818 to 005f982b has its CatchHandler @ 004f9a14 */
        *(undefined ***)ppVar24 = &PTR____shared_ptr_emplace_006437a0;
        *(piecewise_construct_t **)(ppVar24 + 0x138) = ppVar24 + 0x140;
        *(undefined8 *)(ppVar24 + 0x140) = 0;
        this_02 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  (ppVar24 + 0x18);
        *(undefined8 *)(ppVar24 + 0x20) = 0;
        *(undefined8 *)this_02 = 0;
        *(undefined8 *)(ppVar24 + 0x30) = 0;
        *(undefined8 *)(ppVar24 + 0x28) = 0;
        *(undefined8 *)(ppVar24 + 0x40) = 0;
        *(undefined8 *)(ppVar24 + 0x38) = 0;
                    /* try { // try from 004f9834 to 005f9847 has its CatchHandler @ 004f9a10 */
        *(undefined8 *)(ppVar24 + 0x50) = 0;
        *(undefined8 *)(ppVar24 + 0x48) = 0;
        *(undefined8 *)(ppVar24 + 0x60) = 0;
        *(undefined8 *)(ppVar24 + 0x58) = 0;
        *(undefined8 *)(ppVar24 + 0x70) = 0;
        *(undefined8 *)(ppVar24 + 0x68) = 0;
        *(undefined8 *)(ppVar24 + 0x80) = 0;
        *(undefined8 *)(ppVar24 + 0x78) = 0;
        *(undefined8 *)(ppVar24 + 0x90) = 0;
        *(undefined8 *)(ppVar24 + 0x88) = 0;
                    /* try { // try from 004f9848 to 005f9a27 has its CatchHandler @ 004f9554 */
        *(undefined8 *)(ppVar24 + 0xa0) = 0;
        *(undefined8 *)(ppVar24 + 0x98) = 0;
        *(undefined8 *)(ppVar24 + 0xb0) = 0;
        *(undefined8 *)(ppVar24 + 0xa8) = 0;
        *(undefined8 *)(ppVar24 + 0xc0) = 0;
        *(undefined8 *)(ppVar24 + 0xb8) = 0;
        *(undefined8 *)(ppVar24 + 0xd0) = 0;
        *(undefined8 *)(ppVar24 + 200) = 0;
        *(undefined8 *)(ppVar24 + 0xe0) = 0;
        *(undefined8 *)(ppVar24 + 0xd8) = 0;
        *(undefined8 *)(ppVar24 + 0xf0) = 0;
        *(undefined8 *)(ppVar24 + 0xe8) = 0;
        *(undefined8 *)(ppVar24 + 0x100) = 0;
        *(undefined8 *)(ppVar24 + 0xf8) = 0;
        *(undefined8 *)(ppVar24 + 0x110) = 0;
        *(undefined8 *)(ppVar24 + 0x108) = 0;
        *(undefined8 *)(ppVar24 + 0x120) = 0;
        *(undefined8 *)(ppVar24 + 0x118) = 0;
        *(undefined8 *)(ppVar24 + 0x130) = 0;
        *(undefined8 *)(ppVar24 + 0x128) = 0;
        *(undefined8 *)(ppVar24 + 0x158) = 0;
        *(undefined8 *)(ppVar24 + 0x160) = 0;
                    /* catch() { ... } // from try @ 004f95d4 with catch @ 004f9870 */
        *(undefined8 *)(ppVar24 + 0x148) = 0;
        *(piecewise_construct_t **)(ppVar24 + 0x150) = ppVar24 + 0x158;
        local_238 = this_02;
        local_230 = ppVar24;
                    /* catch() { ... } // from try @ 004f9770 with catch @ 004f9880 */
                    /* catch() { ... } // from try @ 004f9730 with catch @ 004f9884 */
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::operator=(this_02,(basic_string *)&local_1b0);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)(ppVar24 + 0x30),&local_198);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)(ppVar24 + 0x48),(basic_string *)&local_180);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)(ppVar24 + 0x60),(basic_string *)&local_168);
                    /* catch() { ... } // from try @ 004f9714 with catch @ 004f98b8 */
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)(ppVar24 + 0x78),abStack_150);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)(ppVar24 + 0x90),abStack_138);
                    /* catch() { ... } // from try @ 004f96ec with catch @ 004f98d8 */
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)(ppVar24 + 0xa8),abStack_120);
                    /* catch() { ... } // from try @ 004f96c4 with catch @ 004f98e8 */
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)(ppVar24 + 0xc0),abStack_108);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)(ppVar24 + 0xd8),abStack_f0);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)(ppVar24 + 0xf0),abStack_d8);
                    /* catch() { ... } // from try @ 004f96a0 with catch @ 004f9908 */
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)(ppVar24 + 0x108),abStack_c0);
                    /* catch() { ... } // from try @ 004f9678 with catch @ 004f9918 */
        std::__ndk1::
        __tree<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::__map_value_compare<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::less<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,true>,std::__ndk1::allocator<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>>
        ::
        __assign_multi<std::__ndk1::__tree_const_iterator<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::__tree_node<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,void*>*,long>>
                  ((__tree<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::__map_value_compare<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,std::__ndk1::less<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>,true>,std::__ndk1::allocator<std::__ndk1::__value_type<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>>
                    *)(ppVar24 + 0x138),local_a8,auStack_a0);
        uVar25 = MTImageKitNS::CMTIKNetHeader::isVaild();
        if ((uVar25 & 1) == 0) {
          lVar22 = FUN_006263e0(0xffffffffffffffff,ppVar24 + 8);
          if (lVar22 == 0) {
            (**(code **)(*(long *)ppVar24 + 0x10))(ppVar24);
            std::__ndk1::__shared_weak_count::__release_weak();
          }
          ppVar24 = (piecewise_construct_t *)0x0;
          this_02 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)0x0;
        }
        ppVar46 = local_310;
        local_318 = this_02;
        if ((local_310 != (piecewise_construct_t *)0x0) &&
           (ppVar45 = local_310 + 8, local_310 = ppVar24,
           lVar22 = FUN_006263e0(0xffffffffffffffff,ppVar45), ppVar24 = local_310, lVar22 == 0)) {
                    /* catch() { ... } // from try @ 004f9654 with catch @ 004f998c */
          (**(code **)(*(long *)ppVar46 + 0x10))(ppVar46);
          std::__ndk1::__shared_weak_count::__release_weak();
          ppVar24 = local_310;
        }
        local_310 = ppVar24;
                    /* catch() { ... } // from try @ 004f962c with catch @ 004f99a0 */
        if (local_318 !=
            (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)0x0) {
                    /* catch() { ... } // from try @ 004f9608 with catch @ 004f99ac */
          ppVar24 = (piecewise_construct_t *)((ulong)local_260 >> 1 & 0x7f);
          if (((ulong)local_260 & 1) != 0) {
            ppVar24 = ppStack_258;
          }
          if (ppVar24 != (piecewise_construct_t *)0x0) {
                    /* catch() { ... } // from try @ 004f95e0 with catch @ 004f99c0 */
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            operator=(local_318 + 0x108,(basic_string *)&local_260);
          }
                    /* catch() { ... } // from try @ 004f95a8 with catch @ 004f99d0 */
          local_338 = local_310;
          local_340 = local_318;
          if (local_310 != (piecewise_construct_t *)0x0) {
            FUN_006263b0(1,local_310 + 8);
          }
                    /* catch() { ... } // from try @ 004f9584 with catch @ 004f99e8 */
          MTImageKitNS::CMTIKFilter::setNetHeader(this_00,&local_340);
          ppVar24 = local_338;
          if ((local_338 != (piecewise_construct_t *)0x0) &&
             (lVar22 = FUN_006263e0(0xffffffffffffffff,local_338 + 8), lVar22 == 0)) {
                    /* catch() { ... } // from try @ 004f9834 with catch @ 004f9a10 */
                    /* catch() { ... } // from try @ 004f9818 with catch @ 004f9a14 */
                    /* catch() { ... } // from try @ 004f97fc with catch @ 004f9a18 */
            (**(code **)(*(long *)ppVar24 + 0x10))(ppVar24);
                    /* catch() { ... } // from try @ 004f97e0 with catch @ 004f9a1c */
                    /* catch() { ... } // from try @ 004f97c4 with catch @ 004f9a20 */
            std::__ndk1::__shared_weak_count::__release_weak();
          }
        }
                    /* catch() { ... } // from try @ 004f9780 with catch @ 004f9a24 */
        CLFNetHeader::~CLFNetHeader((CLFNetHeader *)&local_1b0);
      }
      if (((ulong)local_260 & 1) != 0) {
                    /* try { // try from 004f9a34 to 005f9a37 has its CatchHandler @ 004f9a40 */
        operator_delete(local_250);
      }
    }
    pcVar35 = local_2b8;
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004f9a34 with catch @ 004f9a40
                        */
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004f9be4 with catch @ 004f9a44
                       catch(type#1 @ 00000000) { ... } // from try @ 004f9c74 with catch @ 004f9a44
                        */
    bVar17 = true;
    cVar4 = *(char *)(*(long *)(this + 0x20) + 0x11d);
    local_350 = 0;
    local_348 = 0;
    pcVar33 = local_2c0;
    local_358 = &local_350;
    if (local_2c0 != local_2b8) {
      do {
        iVar20 = *(int *)(pcVar33 + 4);
        if (iVar20 < 0x903) {
          if (iVar20 == 0x8fd) {
            local_1b0 = (piecewise_construct_t *)(pcVar33 + 8);
            std::__ndk1::
            __tree<std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>,std::__ndk1::__map_value_compare<int,std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>,std::__ndk1::less<int>,true>,std::__ndk1::allocator<std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>>>
            ::
            __emplace_unique_key_args<int,std::__ndk1::piecewise_construct_t_const&,std::__ndk1::tuple<int_const&>,std::__ndk1::tuple<>>
                      ((int *)&local_358,local_1b0,(tuple *)&std::__ndk1::piecewise_construct,
                       (tuple *)&local_1b0);
            MTImageKitNS::CMTIKHairVolumeInfo::setHairLine(*(float *)(pcVar33 + 0x18));
          }
          else if (iVar20 == 0x8ff) {
            local_1b0 = (piecewise_construct_t *)(pcVar33 + 8);
            std::__ndk1::
            __tree<std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>,std::__ndk1::__map_value_compare<int,std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>,std::__ndk1::less<int>,true>,std::__ndk1::allocator<std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>>>
            ::
            __emplace_unique_key_args<int,std::__ndk1::piecewise_construct_t_const&,std::__ndk1::tuple<int_const&>,std::__ndk1::tuple<>>
                      ((int *)&local_358,local_1b0,(tuple *)&std::__ndk1::piecewise_construct,
                       (tuple *)&local_1b0);
            MTImageKitNS::CMTIKHairVolumeInfo::setCalvarium(*(float *)(pcVar33 + 0x18));
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004f9bdc with catch @ 004f9c74
                       try { // try from 004f9c74 to 005f9cff has its CatchHandler @ 004f9a44 */
          }
          else if (iVar20 == 0x900) {
            local_1b0 = (piecewise_construct_t *)(pcVar33 + 8);
                    /* try { // try from 004f9ac0 to 005f9ac7 has its CatchHandler @ 004f9c8c */
            lVar22 = std::__ndk1::
                     __tree<std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>,std::__ndk1::__map_value_compare<int,std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>,std::__ndk1::less<int>,true>,std::__ndk1::allocator<std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>>>
                     ::
                     __emplace_unique_key_args<int,std::__ndk1::piecewise_construct_t_const&,std::__ndk1::tuple<int_const&>,std::__ndk1::tuple<>>
                               ((int *)&local_358,local_1b0,
                                (tuple *)&std::__ndk1::piecewise_construct,(tuple *)&local_1b0);
            MTImageKitNS::CMTIKHairVolumeInfo::setRepairingHair(*(float *)(pcVar33 + 0x18));
            CLFDenseHairLayer::getMaterialPathBy(local_2a8);
                    /* try { // try from 004f9af4 to 005f9afb has its CatchHandler @ 004f9c88 */
            ppVar24 = (piecewise_construct_t *)((ulong)local_1b0 >> 1 & 0x7f);
            if (((ulong)local_1b0 & 1) != 0) {
              ppVar24 = ppStack_1a8;
            }
            if (ppVar24 != (piecewise_construct_t *)0x0) {
              if (((ulong)local_1b0 & 1) == 0) {
                ppStack_368 = ppStack_1a8;
                local_370 = local_1b0;
                local_360 = local_1a0;
              }
              else {
                FUN_003bc260(&local_370,local_1a0);
              }
              MTImageKitNS::CMTIKHairVolumeInfo::setRepairHairMaterialDir(lVar22 + 0x28,&local_370);
              pcVar12 = local_360;
              ppVar24 = local_370;
              goto joined_r0x004f9d80;
            }
            goto LAB_004f9d8c;
          }
        }
        else {
                    /* try { // try from 004f9b28 to 005f9b2f has its CatchHandler @ 004f9c90 */
          if (iVar20 == 0x903) {
            local_1b0 = (piecewise_construct_t *)(pcVar33 + 8);
                    /* try { // try from 004f9c20 to 005f9c2f has its CatchHandler @ 004f9cd0 */
                    /* try { // try from 004f9c34 to 005f9c73 has its CatchHandler @ 004f9cac */
            iVar20 = std::__ndk1::
                     __tree<std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>,std::__ndk1::__map_value_compare<int,std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>,std::__ndk1::less<int>,true>,std::__ndk1::allocator<std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>>>
                     ::
                     __emplace_unique_key_args<int,std::__ndk1::piecewise_construct_t_const&,std::__ndk1::tuple<int_const&>,std::__ndk1::tuple<>>
                               ((int *)&local_358,local_1b0,
                                (tuple *)&std::__ndk1::piecewise_construct,(tuple *)&local_1b0);
            MTImageKitNS::CMTIKHairVolumeInfo::setFluffyHair(iVar20 + 0x28);
          }
          else if (iVar20 == 0x59e7) {
            local_1b0 = (piecewise_construct_t *)(pcVar33 + 8);
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004f9bac with catch @ 004f9c84
                        */
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004f9af4 with catch @ 004f9c88
                        */
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004f9ac0 with catch @ 004f9c8c
                        */
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004f9b28 with catch @ 004f9c90
                        */
            lVar22 = std::__ndk1::
                     __tree<std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>,std::__ndk1::__map_value_compare<int,std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>,std::__ndk1::less<int>,true>,std::__ndk1::allocator<std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>>>
                     ::
                     __emplace_unique_key_args<int,std::__ndk1::piecewise_construct_t_const&,std::__ndk1::tuple<int_const&>,std::__ndk1::tuple<>>
                               ((int *)&local_358,local_1b0,
                                (tuple *)&std::__ndk1::piecewise_construct,(tuple *)&local_1b0);
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004f9b54 with catch @ 004f9c98
                        */
            MTImageKitNS::CMTIKHairVolumeInfo::setFluffyHairPro((int)lVar22 + 0x28);
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004f9b64 with catch @ 004f9ca8
                        */
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004f9c34 with catch @ 004f9cac
                        */
            CLFDenseHairLayer::getMaterialPathBy(local_2a8);
            ppVar24 = (piecewise_construct_t *)((ulong)local_1b0 >> 1 & 0x7f);
            if (((ulong)local_1b0 & 1) != 0) {
              ppVar24 = ppStack_1a8;
            }
            if (ppVar24 == (piecewise_construct_t *)0x0) {
              if (0.0 < *(float *)(pcVar33 + 0x18)) {
                MTImageKitNS::CMTIKLog::log
                          ("iklf",5,
                           "CLFDenseHairProcessor<%s:%d> fluffy hair pro material path is empty, materialId=%lld"
                           ,"applyLayer",0xe5,*(undefined8 *)(pcVar33 + 0x10));
              }
            }
            else {
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004f9c20 with catch @ 004f9cd0
                        */
              if (((ulong)local_1b0 & 1) == 0) {
                ppStack_388 = ppStack_1a8;
                local_390 = local_1b0;
                local_380 = local_1a0;
              }
              else {
                FUN_003bc260(&local_390,local_1a0);
              }
              MTImageKitNS::CMTIKHairVolumeInfo::setFluffyHairMaterialDir(lVar22 + 0x28,&local_390);
              pcVar12 = local_380;
              ppVar24 = local_390;
joined_r0x004f9d80:
              if (((ulong)ppVar24 & 1) != 0) {
                operator_delete(pcVar12);
              }
            }
LAB_004f9d8c:
            if (((ulong)local_1b0 & 1) != 0) {
              operator_delete(local_1a0);
            }
          }
          else if (iVar20 == 0x59e9) {
            local_1b0 = (piecewise_construct_t *)(pcVar33 + 8);
                    /* try { // try from 004f9b54 to 005f9b5f has its CatchHandler @ 004f9c98 */
            lVar22 = std::__ndk1::
                     __tree<std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>,std::__ndk1::__map_value_compare<int,std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>,std::__ndk1::less<int>,true>,std::__ndk1::allocator<std::__ndk1::__value_type<int,MTImageKitNS::CMTIKHairVolumeInfo>>>
                     ::
                     __emplace_unique_key_args<int,std::__ndk1::piecewise_construct_t_const&,std::__ndk1::tuple<int_const&>,std::__ndk1::tuple<>>
                               ((int *)&local_358,local_1b0,
                                (tuple *)&std::__ndk1::piecewise_construct,(tuple *)&local_1b0);
                    /* try { // try from 004f9b64 to 005f9b6b has its CatchHandler @ 004f9ca8 */
            MTImageKitNS::CMTIKHairVolumeInfo::setCustomEffectParam
                      (lVar22 + 0x28,*(float *)(pcVar33 + 0x18));
            lVar22 = 0x59e9;
            if (*(long *)(pcVar33 + 0x10) != 0) {
              lVar22 = *(long *)(pcVar33 + 0x10);
            }
            CLFDenseHairLayer::getMaterialPathBy(local_2a8);
            ppVar24 = (piecewise_construct_t *)(ulong)((byte)local_260._0_1_ >> 1);
            if (((ulong)local_260 & 1) != 0) {
              ppVar24 = ppStack_258;
            }
            if (ppVar24 == (piecewise_construct_t *)0x0) {
              if (0.0 < *(float *)(pcVar33 + 0x18)) {
                MTImageKitNS::CMTIKLog::log
                          ("iklf",6,
                           "CLFDenseHairProcessor<%s:%d> all repair hair material path is empty, materialId=%lld"
                           ,"applyLayer",0xfd,lVar22);
                if (((ulong)local_260 & 1) != 0) {
                  operator_delete(local_250);
                }
                bVar17 = false;
                goto LAB_004fc1dc;
              }
            }
            else {
              ppStack_1a8 = (piecewise_construct_t *)((ulong)ppStack_1a8 & 0xffffffff00000000);
              local_198 = (basic_string)0x0;
              bStack_197 = (basic_string)0x0;
              uStack_196 = 0;
              local_190 = 0;
              uStack_18e = 0;
              local_1a0 = (char *)0x0;
                    /* try { // try from 004f9bac to 005f9bb3 has its CatchHandler @ 004f9c84 */
              local_188 = (void *)CONCAT53(local_188._3_5_,1);
              local_1b0 = (piecewise_construct_t *)0x59e9;
              std::__ndk1::
              basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
              operator=((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_1a0,(basic_string *)&local_260);
              local_188._0_3_ = CONCAT21(0x101,(undefined1)local_188);
              MTImageKitNS::CMTIKHairVolumeManager::registerHairVolumeEffect
                        ((CMTIKHairCustomEffect *)&local_1b0);
              if (((ulong)local_1a0 & 1) != 0) {
                    /* try { // try from 004f9bdc to 005f9be3 has its CatchHandler @ 004f9c74 */
                operator_delete((void *)CONCAT62(uStack_18e,local_190));
              }
                    /* try { // try from 004f9be4 to 005f9c1f has its CatchHandler @ 004f9a44 */
            }
            if (((byte)local_260._0_1_ & 1) != 0) {
              operator_delete(local_250);
                    /* catch() { ... } // from try @ 004f9e54 with catch @ 004f9d00 */
            }
          }
        }
        pcVar12 = local_2b8;
        pcVar33 = pcVar33 + 0x20;
      } while (pcVar33 != pcVar35);
      if (local_2c0 == local_2b8) {
        bVar17 = true;
      }
      else {
        bVar17 = false;
        pcVar35 = (char *)((ulong)&local_260 | 1);
        pcVar36 = (char *)((ulong)&local_238 | 1);
        pcVar37 = (char *)((ulong)&local_418 | 1);
                    /* try { // try from 004f9df0 to 005f9e17 has its CatchHandler @ 004fa0e4 */
        pcVar38 = (char *)((ulong)&local_298 | 1);
        puVar39 = (undefined8 *)((ulong)&local_1b0 | 2);
        pcVar33 = local_2c0;
        do {
          iVar20 = *(int *)(pcVar33 + 4);
          if (iVar20 < 0x904) {
                    /* try { // try from 004f9e54 to 005fa13b has its CatchHandler @ 004f9d00 */
            if (iVar20 < 0x901) {
              if ((iVar20 - 0x8ffU < 2) || (iVar20 == 0x8fd)) goto LAB_004f9f54;
              if (iVar20 != 0x8fe) {
LAB_004fc314:
                MTImageKitNS::CMTIKLog::log
                          ("iklf",5,"CLFDenseHairProcessor<%s:%d> Unknown hair operation type:%d",
                           "applyLayer",0x1d0);
                bVar17 = false;
                goto LAB_004fc1dc;
              }
              MTImageKitNS::CMTIKLog::log("iklf",6,&DAT_002d1049,"applyLayer",0x11f);
            }
            else if (iVar20 == 0x901) {
              MTImageKitNS::CMTIKHairFilter::setFunctionType(this_00,1);
              CLFDenseHairLayer::getMaterialPathBy(local_2a8);
              bVar7 = local_418;
              local_428[0] = (piecewise_construct_t)0x0;
              local_420 = (piecewise_construct_t *)0x0;
              if (*pcVar33 == '\0') {
                ppVar24 = (piecewise_construct_t *)(ulong)(local_418 >> 1);
                if ((local_418 & 1) != 0) {
                  ppVar24 = ppStack_410;
                }
                if (ppVar24 == (piecewise_construct_t *)0x0) {
                  MTImageKitNS::CMTIKLog::log("iklf",6,&DAT_002eae52,"loadHairDyeConfig",0x1e);
                  if (*pcVar33 != '\0') goto LAB_004fa024;
                  bVar16 = false;
                }
                else {
                  ppVar46 = ppVar24 + 0xc;
                  if ((piecewise_construct_t *)0xffffffffffffffef < ppVar46) {
                    if (*(long *)(lVar9 + 0x28) == local_88) {
                    /* WARNING: Subroutine does not return */
                      FUN_003bc2e0(&local_260);
                    }
                    goto LAB_004fc7ac;
                  }
                    /* try { // try from 004fa1c8 to 005fa1db has its CatchHandler @ 004fa2c0 */
                  if (ppVar46 < (piecewise_construct_t *)0x17) {
                    uVar19 = ((uint)ppVar46 & 0xff) << 1;
                    ppStack_258 = (piecewise_construct_t *)0x0;
                    /* try { // try from 004fa1e0 to 005fa21f has its CatchHandler @ 004fa2a4 */
                    local_250 = (char *)0x0;
                    local_260 = (piecewise_construct_t *)(ulong)(byte)uVar19;
                  }
                  else {
                    uVar25 = ((ulong)ppVar46 | 0xf) + 1;
                    local_250 = operator_new(uVar25);
                    local_260 = (piecewise_construct_t *)(uVar25 | 1);
                    uVar19 = (uint)local_260 & 0xff;
                    ppStack_258 = ppVar46;
                  }
                  pcVar28 = pcVar35;
                  if ((uVar19 & 1) != 0) {
                    pcVar28 = local_250;
                  }
                  pcVar2 = pcVar37;
                  if ((bVar7 & 1) != 0) {
                    pcVar2 = local_408;
                  }
                    /* try { // try from 004fa384 to 005fa45f has its CatchHandler @ 004fa384
                       catch() { ... } // from try @ 004fa384 with catch @ 004fa384
                       catch() { ... } // from try @ 004fa4b8 with catch @ 004fa384
                       catch() { ... } // from try @ 004fa534 with catch @ 004fa384 */
                  memmove(pcVar28,pcVar2,(size_t)ppVar24);
                  builtin_strncpy(pcVar28 + (long)ppVar24,"/config.json",0xd);
                  pcVar28 = pcVar35;
                  if (((ulong)local_260 & 1) != 0) {
                    pcVar28 = local_250;
                  }
                  uVar25 = MTImageKitNS::FileIO::CheckFileExist(pcVar28);
                  if ((uVar25 & 1) == 0) {
                    pcVar28 = pcVar37;
                    if ((local_418 & 1) != 0) {
                      pcVar28 = local_408;
                    }
                    psVar34 = (string_t *)&DAT_002e3fd1;
                    MTImageKitNS::CMTIKLog::log
                              ("iklf",6,&DAT_002e3fd1,"loadHairDyeConfig",0x25,pcVar28);
                    /* try { // try from 004fa460 to 005fa473 has its CatchHandler @ 004fa590 */
                    bVar16 = false;
                  }
                  else {
                    local_1c0._0_6_ = 0;
                    local_1c0._6_2_ = 0;
                    pcVar28 = pcVar35;
                    if (((ulong)local_260 & 1) != 0) {
                      pcVar28 = local_250;
                    }
                    pvVar26 = (void *)MTImageKitNS::FileIO::ReadFile2String
                                                (pcVar28,&local_1c0,false);
                    bVar16 = pvVar26 != (void *)0x0;
                    if (pvVar26 == (void *)0x0) {
                      pcVar28 = pcVar35;
                    /* catch() { ... } // from try @ 004fa708 with catch @ 004fa78c */
                      if (((ulong)local_260 & 1) != 0) {
                        pcVar28 = local_250;
                      }
                      psVar34 = (string_t *)&DAT_002e531f;
                    /* catch() { ... } // from try @ 004fa700 with catch @ 004fa7a4 */
                    /* catch() { ... } // from try @ 004fa6ac with catch @ 004fa7a8 */
                      MTImageKitNS::CMTIKLog::log
                                ("iklf",6,&DAT_002e531f,"loadHairDyeConfig",0x2c,pcVar28);
                    }
                    else {
                      ppVar24 = (piecewise_construct_t *)
                                CONCAT26(local_1c0._6_2_,(undefined6)local_1c0);
                      if ((piecewise_construct_t *)0xffffffffffffffef < ppVar24) {
                        if (*(long *)(lVar9 + 0x28) == local_88) {
                    /* WARNING: Subroutine does not return */
                          FUN_003bc2e0(&local_238);
                        }
                        goto LAB_004fc7ac;
                      }
                      if (ppVar24 < (piecewise_construct_t *)0x17) {
                        local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                     *)CONCAT71(local_238._1_7_,
                                                (char)((int)(undefined6)local_1c0 << 1));
                        pcVar28 = pcVar36;
                        if (ppVar24 != (piecewise_construct_t *)0x0) goto LAB_004fa9c8;
                      }
                      else {
                    /* catch() { ... } // from try @ 004fa95c with catch @ 004fa99c
                       try { // try from 004fa99c to 005faa1f has its CatchHandler @ 004fa7ec */
                        uVar25 = ((ulong)ppVar24 | 0xf) + 1;
                        pcVar28 = operator_new(uVar25);
                        local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                     *)(uVar25 | 1);
                    /* catch() { ... } // from try @ 004fa93c with catch @ 004fa9c0 */
                        local_230 = ppVar24;
                        local_228 = pcVar28;
LAB_004fa9c8:
                        memmove(pcVar28,pvVar26,(size_t)ppVar24);
                      }
                    /* catch() { ... } // from try @ 004fa934 with catch @ 004fa9d8 */
                    /* catch() { ... } // from try @ 004fa8e0 with catch @ 004fa9dc */
                      pcVar28[(long)ppVar24] = '\0';
                      free(pvVar26);
                      local_190 = 0;
                      uStack_18e = 0;
                      psVar34 = (string_t *)0x1;
                    /* catch() { ... } // from try @ 004fa8c8 with catch @ 004fa9f8 */
                      nlohmann::json_abi_v3_12_0::
                      basic_json<std::__ndk1::map,std::__ndk1::vector,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,bool,long,unsigned_long,double,std::__ndk1::allocator,nlohmann::json_abi_v3_12_0::adl_serializer,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>
                      ::
                      parse<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>const&>
                                ((basic_json<std::__ndk1::map,std::__ndk1::vector,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,bool,long,unsigned_long,double,std::__ndk1::allocator,nlohmann::json_abi_v3_12_0::adl_serializer,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>
                                  *)&local_298,&local_238,&local_1b0,1,0);
                      ppVar24 = local_420;
                      pVar8 = local_428[0];
                      local_428[0] = (piecewise_construct_t)local_298._0_1_;
                      local_298 = (piecewise_construct_t *)CONCAT71(local_298._1_7_,pVar8);
                      local_420 = local_290;
                      local_290 = ppVar24;
                    /* try { // try from 004faa20 to 005faafb has its CatchHandler @ 004faa20
                       catch() { ... } // from try @ 004faa20 with catch @ 004faa20
                       catch() { ... } // from try @ 004fab54 with catch @ 004faa20
                       catch() { ... } // from try @ 004fabd0 with catch @ 004faa20 */
                      nlohmann::json_abi_v3_12_0::
                      basic_json<std::__ndk1::map,std::__ndk1::vector,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,bool,long,unsigned_long,double,std::__ndk1::allocator,nlohmann::json_abi_v3_12_0::adl_serializer,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>
                      ::json_value::destroy((json_value *)&local_290);
                      pppVar27 = (piecewise_construct_t **)CONCAT62(uStack_18e,local_190);
                      if (pppVar27 == &local_1b0) {
                        pppVar27 = &local_1b0;
                        lVar22 = 4;
LAB_004faa68:
                        (**(code **)(*pppVar27 + lVar22 * 8))();
                      }
                      else if (pppVar27 != (piecewise_construct_t **)0x0) {
                        lVar22 = 5;
                        goto LAB_004faa68;
                      }
                      if (((ulong)local_238 & 1) != 0) {
                        operator_delete(local_228);
                      }
                    }
                  }
                  if (((ulong)local_260 & 1) != 0) {
                    operator_delete(local_250);
                  }
                  bVar3 = (bool)(bVar16 ^ 1);
                  if (*pcVar33 != '\0') {
                    bVar3 = true;
                  }
                  if (bVar3) {
                    if (*pcVar33 != '\0') goto LAB_004fa024;
                  }
                  else {
                    uVar25 = FUN_004fd7b4(local_428);
                    if ((uVar25 & 1) == 0) {
                      ppStack_1a8 = (piecewise_construct_t *)0x0;
                      local_1a0 = (char *)0x0;
                      local_1b0 = local_428;
                      local_198 = (basic_string)0x0;
                      bStack_197 = (basic_string)0x0;
                      uStack_196 = 0x800000000000;
                      if (local_428[0] == (piecewise_construct_t)0x1) {
                        ppVar45 = local_420 + 8;
                        ppVar24 = *(piecewise_construct_t **)ppVar45;
                    /* try { // try from 004fab14 to 005fab53 has its CatchHandler @ 004fac10 */
                        ppVar46 = ppVar45;
                        if (ppVar24 != (piecewise_construct_t *)0x0) {
                          do {
                            uVar25 = std::__ndk1::
                                     basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                     ::compare((char *)(ppVar24 + 0x20));
                            ppVar1 = ppVar24;
                            if ((uVar25 & 0x80000000) != 0) {
                              ppVar1 = ppVar46;
                              ppVar24 = ppVar24 + 8;
                            }
                            ppVar24 = *(piecewise_construct_t **)ppVar24;
                            ppVar46 = ppVar1;
                          } while (ppVar24 != (piecewise_construct_t *)0x0);
                    /* try { // try from 004fab54 to 005fab67 has its CatchHandler @ 004faa20 */
                    /* try { // try from 004fab68 to 005fab6f has its CatchHandler @ 004fac0c */
                          if ((ppVar1 != ppVar45) &&
                             (iVar20 = std::__ndk1::
                                       basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                       ::compare((char *)(ppVar1 + 0x20)), iVar20 < 1)) {
                            ppVar45 = ppVar1;
                          }
                        }
LAB_004fab84:
                        ppStack_1a8 = ppVar45;
                        ppStack_258 = (piecewise_construct_t *)0x0;
                        local_250 = (char *)0x0;
                    /* try { // try from 004fab90 to 005fabcf has its CatchHandler @ 004fabd0 */
                        local_248 = 0x8000000000000000;
                        if (local_428[0] == (piecewise_construct_t)0x1) {
                          ppStack_258 = local_420 + 8;
                        }
                        else {
                          if (local_428[0] == (piecewise_construct_t)0x2) goto LAB_004fabb0;
                    /* catch() { ... } // from try @ 004fab90 with catch @ 004fabd0
                       try { // try from 004fabd0 to 005fac53 has its CatchHandler @ 004faa20 */
                          local_248 = 1;
                        }
                      }
                      else {
                        if (local_428[0] != (piecewise_construct_t)0x2) {
                          local_198 = (basic_string)0x1;
                          bStack_197 = (basic_string)0x0;
                          uStack_196 = 0;
                          ppVar45 = ppStack_1a8;
                          goto LAB_004fab84;
                        }
                        local_1a0 = *(char **)(local_420 + 8);
                    /* try { // try from 004faafc to 005fab0f has its CatchHandler @ 004fac2c */
LAB_004fabb0:
                        local_248 = 0x8000000000000000;
                        ppStack_258 = (piecewise_construct_t *)0x0;
                        local_250 = *(char **)(local_420 + 8);
                      }
                      local_260 = local_428;
                      uVar25 = _ZNK8nlohmann16json_abi_v3_12_06detail9iter_implIKNS0_10basic_jsonINSt6__ndk13mapENS4_6vectorENS4_12basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEblmdSA_NS0_14adl_serializerENS6_IhNSA_IhEEEEvEEEeqISI_TnNS4_9enable_ifIXoosr3std7is_sameIT_SI_EE5valuesr3std7is_sameISL_NS2_ISG_EEEE5valueEDnE4typeELDn0EEEbRKSL_
                                         (&local_1b0,&local_260);
                    /* catch() { ... } // from try @ 004fab70 with catch @ 004fabf4 */
                      if (((uVar25 & 1) == 0) &&
                         (pcVar28 = (char *)nlohmann::json_abi_v3_12_0::detail::
                                            iter_impl<nlohmann::json_abi_v3_12_0::basic_json<std::__ndk1::map,std::__ndk1::vector,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,bool,long,unsigned_long,double,std::__ndk1::allocator,nlohmann::json_abi_v3_12_0::adl_serializer,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>const>
                                            ::operator->((
                                                  iter_impl<nlohmann::json_abi_v3_12_0::basic_json<std::__ndk1::map,std::__ndk1::vector,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,bool,long,unsigned_long,double,std::__ndk1::allocator,nlohmann::json_abi_v3_12_0::adl_serializer,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>const>
                                                  *)&local_1b0), *pcVar28 == '\x03')) {
                        this_01 = (detail *)
                                  nlohmann::json_abi_v3_12_0::detail::
                                  iter_impl<nlohmann::json_abi_v3_12_0::basic_json<std::__ndk1::map,std::__ndk1::vector,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,bool,long,unsigned_long,double,std::__ndk1::allocator,nlohmann::json_abi_v3_12_0::adl_serializer,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>const>
                                  ::operator->((iter_impl<nlohmann::json_abi_v3_12_0::basic_json<std::__ndk1::map,std::__ndk1::vector,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,bool,long,unsigned_long,double,std::__ndk1::allocator,nlohmann::json_abi_v3_12_0::adl_serializer,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>const>
                                                *)&local_1b0);
                        local_230 = (piecewise_construct_t *)0x0;
                        local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                     *)0x0;
                        local_228 = (char *)0x0;
                    /* catch() { ... } // from try @ 004fab68 with catch @ 004fac0c */
                    /* catch() { ... } // from try @ 004fab14 with catch @ 004fac10 */
                        nlohmann::json_abi_v3_12_0::detail::
                        from_json<nlohmann::json_abi_v3_12_0::basic_json<std::__ndk1::map,std::__ndk1::vector,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,bool,long,unsigned_long,double,std::__ndk1::allocator,nlohmann::json_abi_v3_12_0::adl_serializer,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>>
                                  (this_01,(basic_json *)&local_238,psVar34);
                        ppVar24 = (piecewise_construct_t *)((ulong)local_238 >> 1 & 0x7f);
                        if (((ulong)local_238 & 1) != 0) {
                          ppVar24 = local_230;
                        }
                        if (((ulong)local_238 & 1) != 0) {
                    /* catch() { ... } // from try @ 004faafc with catch @ 004fac2c */
                          operator_delete(local_228);
                        }
                        if (ppVar24 != (piecewise_construct_t *)0x0) {
                    /* try { // try from 004fac60 to 005fac63 has its CatchHandler @ 004fac6c */
                          if ((*pcVar33 != '\0') ||
                             (MTImageKitNS::CMTIKLog::log
                                        ("iklf",4,&DAT_002d330a,"applyLayer",0x136,
                                         *(undefined8 *)(pcVar33 + 0x10)), *pcVar33 != '\0'))
                          goto LAB_004fa024;
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004fac60 with catch @ 004fac6c
                        */
                    /* try { // try from 004fac70 to 005face3 has its CatchHandler @ 004fac70
                       catch() { ... } // from try @ 004fac70 with catch @ 004fac70
                       catch() { ... } // from try @ 004facec with catch @ 004fac70
                       catch() { ... } // from try @ 004fad30 with catch @ 004fac70 */
                          if ((local_418 & 1) != 0) {
                            FUN_003bc260(&local_1b0,local_408,ppStack_410);
                            goto LAB_004fa034;
                          }
                          ppStack_1a8 = ppStack_410;
                          local_1b0 = (piecewise_construct_t *)CONCAT71(uStack_417,local_418);
                          local_1a0 = local_408;
                          uVar21 = *(undefined4 *)(pcVar33 + 8);
                          if ((local_418 & 1) != 0) goto LAB_004fac94;
                          goto LAB_004fa040;
                        }
                      }
                    }
                    bVar16 = true;
                  }
                }
                MTImageKitNS::CMTIKHairFilter::setMaskCachePath((basic_string *)this_00);
                if (bVar16) {
                  ppStack_258 = (piecewise_construct_t *)0x0;
                  local_160 = 0xffffffff;
                  local_260 = (piecewise_construct_t *)0x0;
                  local_250 = (char *)0x0;
                  local_248 = CONCAT35(local_248._5_3_,0x3f800000);
                  local_1b0 = (piecewise_construct_t *)((ulong)local_1b0 & 0xffffffffffff0000);
                  local_198 = (basic_string)0x0;
                  bStack_197 = (basic_string)0x0;
                  local_180 = 0;
                  local_168 = 0xffffffffffffffff;
                    /* try { // try from 004fadb8 to 005fadbf has its CatchHandler @ 004fae04 */
                  local_158 = 0x3f80000000000000;
                    /* try { // try from 004fadc0 to 005fadfb has its CatchHandler @ 004fad44 */
                  uVar25 = FUN_004fd7b4(local_428);
                  bVar7 = local_418;
                  if ((uVar25 & 1) == 0) {
                    ppVar24 = (piecewise_construct_t *)(ulong)(local_418 >> 1);
                    if ((local_418 & 1) != 0) {
                      ppVar24 = ppStack_410;
                    }
                    ppVar46 = ppVar24 + 1;
                    if ((piecewise_construct_t *)0xffffffffffffffef < ppVar46) {
                      if (*(long *)(lVar9 + 0x28) == local_88) {
                    /* WARNING: Subroutine does not return */
                        FUN_003bc2e0(&local_238);
                      }
                      goto LAB_004fc7ac;
                    }
                    if (ppVar46 < (piecewise_construct_t *)0x17) {
                      local_230 = (piecewise_construct_t *)0x0;
                      local_228 = (char *)0x0;
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(ulong)(byte)((int)ppVar46 << 1);
                      pcVar28 = pcVar36;
                      if (ppVar24 != (piecewise_construct_t *)0x0) goto LAB_004faebc;
                    }
                    else {
                    /* try { // try from 004fae94 to 005faecf has its CatchHandler @ 004fae18 */
                      uVar25 = ((ulong)ppVar46 | 0xf) + 1;
                      pcVar28 = operator_new(uVar25);
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(uVar25 | 1);
                      local_230 = ppVar46;
                      local_228 = pcVar28;
LAB_004faebc:
                      pcVar2 = pcVar37;
                    /* try { // try from 004faed0 to 005faed7 has its CatchHandler @ 004faed8 */
                      if ((bVar7 & 1) != 0) {
                        pcVar2 = local_408;
                      }
                      memmove(pcVar28,pcVar2,(size_t)ppVar24);
                    }
                    /* catch() { ... } // from try @ 004fae8c with catch @ 004faed8
                       catch() { ... } // from try @ 004faed0 with catch @ 004faed8
                       try { // try from 004faed8 to 005faeeb has its CatchHandler @ 004fae18 */
                    (pcVar28 + (long)ppVar24)[0] = '/';
                    (pcVar28 + (long)ppVar24)[1] = '\0';
                    /* try { // try from 004faeec to 005faf5f has its CatchHandler @ 004faeec
                       catch() { ... } // from try @ 004faeec with catch @ 004faeec
                       catch() { ... } // from try @ 004faf68 with catch @ 004faeec
                       catch() { ... } // from try @ 004fafac with catch @ 004faeec */
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA8_KcSI_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISM_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESN_OSM_OSS_
                              (&local_298,local_428,"lutPath","lut.png");
                    ppVar24 = (piecewise_construct_t *)((ulong)local_298 >> 1 & 0x7f);
                    pcVar28 = pcVar38;
                    if (((ulong)local_298 & 1) != 0) {
                      ppVar24 = local_290;
                      pcVar28 = local_288;
                    }
                    puVar40 = (undefined8 *)FUN_005f4134(&local_238,pcVar28,ppVar24);
                    uVar30 = puVar40[1];
                    pcVar28 = (char *)puVar40[2];
                    uVar10 = *(undefined2 *)puVar40;
                    puVar40[1] = 0;
                    puVar40[2] = 0;
                    *puVar40 = 0;
                    local_1c0._0_6_ = (undefined6)*(undefined8 *)((long)puVar40 + 2);
                    local_1c0._6_2_ = (undefined2)uVar30;
                    local_1b8 = (undefined6)((ulong)uVar30 >> 0x10);
                    if (((ulong)local_1b0 & 1) != 0) {
                      operator_delete(local_1a0);
                    }
                    /* try { // try from 004faf60 to 005faf67 has its CatchHandler @ 004fafac */
                    /* try { // try from 004faf68 to 005fafa3 has its CatchHandler @ 004faeec */
                    local_1b0 = (piecewise_construct_t *)CONCAT62(local_1b0._2_6_,uVar10);
                    *puVar39 = CONCAT26(local_1c0._6_2_,(undefined6)local_1c0);
                    *(ulong *)((long)puVar39 + 6) = CONCAT62(local_1b8,local_1c0._6_2_);
                    local_1a0 = pcVar28;
                    if (((ulong)local_298 & 1) != 0) {
                      operator_delete(local_288);
                    }
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    bVar7 = local_418;
                    /* try { // try from 004fafa4 to 005fafab has its CatchHandler @ 004fafac */
                    ppVar24 = (piecewise_construct_t *)(ulong)(local_418 >> 1);
                    /* catch() { ... } // from try @ 004faf60 with catch @ 004fafac
                       catch() { ... } // from try @ 004fafa4 with catch @ 004fafac
                       try { // try from 004fafac to 005fafbf has its CatchHandler @ 004faeec */
                    if ((local_418 & 1) != 0) {
                      ppVar24 = ppStack_410;
                    }
                    ppVar46 = ppVar24 + 1;
                    if ((piecewise_construct_t *)0xffffffffffffffef < ppVar46) {
                      if (*(long *)(lVar9 + 0x28) == local_88) {
                    /* WARNING: Subroutine does not return */
                        FUN_003bc2e0(&local_238);
                      }
                      goto LAB_004fc7ac;
                    }
                    /* try { // try from 004fafc0 to 005fb033 has its CatchHandler @ 004fafc0
                       catch() { ... } // from try @ 004fafc0 with catch @ 004fafc0
                       catch() { ... } // from try @ 004fb03c with catch @ 004fafc0
                       catch() { ... } // from try @ 004fb080 with catch @ 004fafc0 */
                    if (ppVar46 < (piecewise_construct_t *)0x17) {
                      local_230 = (piecewise_construct_t *)0x0;
                      local_228 = (char *)0x0;
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(ulong)(byte)((int)ppVar46 << 1);
                      pcVar28 = pcVar36;
                      if (ppVar24 != (piecewise_construct_t *)0x0) goto LAB_004fb164;
                    }
                    else {
                      uVar25 = ((ulong)ppVar46 | 0xf) + 1;
                      pcVar28 = operator_new(uVar25);
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(uVar25 | 1);
                      local_230 = ppVar46;
                      local_228 = pcVar28;
LAB_004fb164:
                      pcVar2 = pcVar37;
                      if ((bVar7 & 1) != 0) {
                        pcVar2 = local_408;
                      }
                      memmove(pcVar28,pcVar2,(size_t)ppVar24);
                    }
                    (pcVar28 + (long)ppVar24)[0] = '/';
                    (pcVar28 + (long)ppVar24)[1] = '\0';
                    /* try { // try from 004fb18c to 005fb193 has its CatchHandler @ 004fb1fc */
                    /* try { // try from 004fb194 to 005fb283 has its CatchHandler @ 004fb094 */
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA13_KcSI_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISM_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESN_OSM_OSS_
                              (&local_298,local_428,"materialPath","material.png");
                    ppVar24 = (piecewise_construct_t *)((ulong)local_298 >> 1 & 0x7f);
                    pcVar28 = pcVar38;
                    if (((ulong)local_298 & 1) != 0) {
                      ppVar24 = local_290;
                      pcVar28 = local_288;
                    }
                    pbVar31 = (basic_string *)FUN_005f4134(&local_238,pcVar28,ppVar24);
                    bVar5 = *pbVar31;
                    uVar30 = *(undefined8 *)(pbVar31 + 8);
                    pvVar26 = *(void **)(pbVar31 + 0x10);
                    bVar6 = pbVar31[1];
                    *(undefined8 *)(pbVar31 + 8) = 0;
                    *(undefined8 *)(pbVar31 + 0x10) = 0;
                    *(undefined8 *)pbVar31 = 0;
                    local_1c0._0_6_ = (undefined6)*(undefined8 *)(pbVar31 + 2);
                    local_1c0._6_2_ = (undefined2)uVar30;
                    local_1b8 = (undefined6)((ulong)uVar30 >> 0x10);
                    if (((byte)local_198 & 1) != 0) {
                    /* catch() { ... } // from try @ 004fb18c with catch @ 004fb1fc */
                      operator_delete(local_188);
                    }
                    /* catch() { ... } // from try @ 004fb12c with catch @ 004fb218 */
                    uStack_196 = (undefined6)local_1c0;
                    local_190 = local_1c0._6_2_;
                    uStack_18e = local_1b8;
                    local_198 = bVar5;
                    bStack_197 = bVar6;
                    local_188 = pvVar26;
                    if (((ulong)local_298 & 1) != 0) {
                      operator_delete(local_288);
                    }
                    if (((ulong)local_238 & 1) != 0) {
                    /* catch() { ... } // from try @ 004fb0f4 with catch @ 004fb23c */
                      operator_delete(local_228);
                    }
                    bVar7 = local_418;
                    ppVar24 = (piecewise_construct_t *)(ulong)(local_418 >> 1);
                    /* catch() { ... } // from try @ 004fb0ec with catch @ 004fb254 */
                    if ((local_418 & 1) != 0) {
                      ppVar24 = ppStack_410;
                    }
                    ppVar46 = ppVar24 + 1;
                    if ((piecewise_construct_t *)0xffffffffffffffef < ppVar46) {
                      if (*(long *)(lVar9 + 0x28) == local_88) {
                    /* WARNING: Subroutine does not return */
                        FUN_003bc2e0(&local_238);
                      }
                      goto LAB_004fc7ac;
                    }
                    if (ppVar46 < (piecewise_construct_t *)0x17) {
                      local_230 = (piecewise_construct_t *)0x0;
                      local_228 = (char *)0x0;
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(ulong)(byte)((int)ppVar46 << 1);
                    /* try { // try from 004fb284 to 005fb2ff has its CatchHandler @ 004fb284
                       catch() { ... } // from try @ 004fb284 with catch @ 004fb284
                       catch() { ... } // from try @ 004fb358 with catch @ 004fb284 */
                      pcVar28 = pcVar36;
                      if (ppVar24 != (piecewise_construct_t *)0x0) goto LAB_004fb40c;
                    }
                    else {
                      uVar25 = ((ulong)ppVar46 | 0xf) + 1;
                      pcVar28 = operator_new(uVar25);
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(uVar25 | 1);
                    /* try { // try from 004fb3fc to 005fb403 has its CatchHandler @ 004fb564 */
                    /* try { // try from 004fb404 to 005fb427 has its CatchHandler @ 004fb54c */
                      local_230 = ppVar46;
                      local_228 = pcVar28;
LAB_004fb40c:
                      pcVar2 = pcVar37;
                      if ((bVar7 & 1) != 0) {
                        pcVar2 = local_408;
                      }
                      memmove(pcVar28,pcVar2,(size_t)ppVar24);
                    }
                    (pcVar28 + (long)ppVar24)[0] = '/';
                    (pcVar28 + (long)ppVar24)[1] = '\0';
                    /* try { // try from 004fb43c to 005fb44f has its CatchHandler @ 004fb528 */
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA7_KcSI_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISM_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESN_OSM_OSS_
                              (&local_298,local_428,"psPath","ps.png");
                    ppVar24 = (piecewise_construct_t *)((ulong)local_298 >> 1 & 0x7f);
                    pcVar28 = pcVar38;
                    if (((ulong)local_298 & 1) != 0) {
                      ppVar24 = local_290;
                      pcVar28 = local_288;
                    }
                    puVar32 = (ushort *)FUN_005f4134(&local_238,pcVar28,ppVar24);
                    uVar30 = *(undefined8 *)(puVar32 + 4);
                    pvVar26 = *(void **)(puVar32 + 8);
                    uVar11 = *puVar32;
                    uVar41 = *(undefined8 *)(puVar32 + 1);
                    puVar32[4] = 0;
                    puVar32[5] = 0;
                    puVar32[6] = 0;
                    puVar32[7] = 0;
                    puVar32[8] = 0;
                    puVar32[9] = 0;
                    puVar32[10] = 0;
                    puVar32[0xb] = 0;
                    puVar32[0] = 0;
                    puVar32[1] = 0;
                    puVar32[2] = 0;
                    puVar32[3] = 0;
                    local_1c0._0_6_ = (undefined6)uVar41;
                    /* try { // try from 004fb49c to 005fb4a3 has its CatchHandler @ 004fb50c */
                    local_1c0._6_2_ = (undefined2)uVar30;
                    local_1b8 = (undefined6)((ulong)uVar30 >> 0x10);
                    if ((local_180 & 1) != 0) {
                    /* try { // try from 004fb4a4 to 005fb593 has its CatchHandler @ 004fb3a4 */
                      operator_delete(local_170);
                    }
                    local_17e = (undefined6)local_1c0;
                    uStack_178 = local_1c0._6_2_;
                    uStack_176 = local_1b8;
                    local_180 = uVar11;
                    local_170 = pvVar26;
                    if (((ulong)local_298 & 1) != 0) {
                      operator_delete(local_288);
                    }
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA10_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,local_428,"blendType",&DAT_002de4fa);
                    /* catch() { ... } // from try @ 004fb49c with catch @ 004fb50c */
                    uVar21 = std::__ndk1::stoi((basic_string *)&local_238,(ulong *)0x0,10);
                    local_158 = CONCAT44(local_158._4_4_,uVar21);
                    if (((ulong)local_238 & 1) != 0) {
                    /* catch() { ... } // from try @ 004fb43c with catch @ 004fb528 */
                      operator_delete(local_228);
                    }
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA13_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,local_428,"sharpenAlpha",&DAT_002e7480);
                    /* catch() { ... } // from try @ 004fb404 with catch @ 004fb54c */
                    uVar21 = std::__ndk1::stof((basic_string *)&local_238,(ulong *)0x0);
                    local_160 = CONCAT44(uVar21,(undefined4)local_160);
                    if (((ulong)local_238 & 1) != 0) {
                    /* catch() { ... } // from try @ 004fb3fc with catch @ 004fb564 */
                      operator_delete(local_228);
                    }
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA11_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,local_428,"blendAlpha",&DAT_002e075b);
                    uVar21 = std::__ndk1::stof((basic_string *)&local_238,(ulong *)0x0);
                    /* catch() { ... } // from try @ 004fb5f4 with catch @ 004fb594 */
                    local_158 = CONCAT44(uVar21,(undefined4)local_158);
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    /* try { // try from 004fb5b8 to 005fb5f3 has its CatchHandler @ 004fb604 */
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA4_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,local_428,&DAT_002da263,&DAT_002e7480);
                    uVar21 = std::__ndk1::stoi((basic_string *)&local_238,(ulong *)0x0,10);
                    local_168 = CONCAT44(local_168._4_4_,uVar21);
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    /* try { // try from 004fb5f4 to 005fb61f has its CatchHandler @ 004fb594 */
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA6_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,local_428,"blend",&DAT_002e075b);
                    /* catch() { ... } // from try @ 004fb5b8 with catch @ 004fb604 */
                    uVar21 = std::__ndk1::stoi((basic_string *)&local_238,(ulong *)0x0,10);
                    local_168 = CONCAT44(uVar21,(undefined4)local_168);
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA8_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,local_428,"sharpen",&DAT_002d1e5b);
                    /* catch() { ... } // from try @ 004fb720 with catch @ 004fb64c */
                    uVar21 = std::__ndk1::stoi((basic_string *)&local_238,(ulong *)0x0,10);
                    local_160 = CONCAT44(local_160._4_4_,uVar21);
                  }
                  else {
                    pbVar29 = nlohmann::json_abi_v3_12_0::
                              basic_json<std::__ndk1::map,std::__ndk1::vector,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,bool,long,unsigned_long,double,std::__ndk1::allocator,nlohmann::json_abi_v3_12_0::adl_serializer,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>
                              ::operator[]<char_const>
                                        ((basic_json<std::__ndk1::map,std::__ndk1::vector,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,bool,long,unsigned_long,double,std::__ndk1::allocator,nlohmann::json_abi_v3_12_0::adl_serializer,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>
                                          *)local_428,"MaterialData");
                    uVar30 = nlohmann::json_abi_v3_12_0::
                             basic_json<std::__ndk1::map,std::__ndk1::vector,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,bool,long,unsigned_long,double,std::__ndk1::allocator,nlohmann::json_abi_v3_12_0::adl_serializer,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>
                             ::operator[]((ulong)pbVar29);
                    bVar7 = local_418;
                    ppVar24 = (piecewise_construct_t *)(ulong)(local_418 >> 1);
                    if ((local_418 & 1) != 0) {
                      ppVar24 = ppStack_410;
                    }
                    ppVar46 = ppVar24 + 1;
                    /* try { // try from 004fadfc to 005fae03 has its CatchHandler @ 004fae04 */
                    if ((piecewise_construct_t *)0xffffffffffffffef < ppVar46) {
                      if (*(long *)(lVar9 + 0x28) == local_88) {
                    /* WARNING: Subroutine does not return */
                        FUN_003bc2e0(&local_238);
                      }
                      goto LAB_004fc7ac;
                    }
                    /* catch() { ... } // from try @ 004fadb8 with catch @ 004fae04
                       catch() { ... } // from try @ 004fadfc with catch @ 004fae04
                       try { // try from 004fae04 to 005fae17 has its CatchHandler @ 004fad44 */
                    if (ppVar46 < (piecewise_construct_t *)0x17) {
                    /* try { // try from 004fae18 to 005fae8b has its CatchHandler @ 004fae18
                       catch() { ... } // from try @ 004fae18 with catch @ 004fae18
                       catch() { ... } // from try @ 004fae94 with catch @ 004fae18
                       catch() { ... } // from try @ 004faed8 with catch @ 004fae18 */
                      local_230 = (piecewise_construct_t *)0x0;
                      local_228 = (char *)0x0;
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(ulong)(byte)((int)ppVar46 << 1);
                      pcVar28 = pcVar36;
                      if (ppVar24 != (piecewise_construct_t *)0x0) goto LAB_004fb010;
                    }
                    else {
                      uVar25 = ((ulong)ppVar46 | 0xf) + 1;
                      pcVar28 = operator_new(uVar25);
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(uVar25 | 1);
                      local_230 = ppVar46;
                      local_228 = pcVar28;
LAB_004fb010:
                      pcVar2 = pcVar37;
                      if ((bVar7 & 1) != 0) {
                        pcVar2 = local_408;
                      }
                      memmove(pcVar28,pcVar2,(size_t)ppVar24);
                    }
                    (pcVar28 + (long)ppVar24)[0] = '/';
                    (pcVar28 + (long)ppVar24)[1] = '\0';
                    /* try { // try from 004fb034 to 005fb03b has its CatchHandler @ 004fb080 */
                    /* try { // try from 004fb03c to 005fb077 has its CatchHandler @ 004fafc0 */
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA8_KcSI_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISM_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESN_OSM_OSS_
                              (&local_298,uVar30,"lutPath","lut.png");
                    ppVar24 = (piecewise_construct_t *)((ulong)local_298 >> 1 & 0x7f);
                    pcVar28 = pcVar38;
                    if (((ulong)local_298 & 1) != 0) {
                      ppVar24 = local_290;
                      pcVar28 = local_288;
                    }
                    puVar40 = (undefined8 *)FUN_005f4134(&local_238,pcVar28,ppVar24);
                    /* try { // try from 004fb078 to 005fb07f has its CatchHandler @ 004fb080 */
                    uVar41 = puVar40[1];
                    pcVar28 = (char *)puVar40[2];
                    /* catch() { ... } // from try @ 004fb034 with catch @ 004fb080
                       catch() { ... } // from try @ 004fb078 with catch @ 004fb080
                       try { // try from 004fb080 to 005fb093 has its CatchHandler @ 004fafc0 */
                    uVar10 = *(undefined2 *)puVar40;
                    puVar40[1] = 0;
                    puVar40[2] = 0;
                    *puVar40 = 0;
                    /* catch() { ... } // from try @ 004fb194 with catch @ 004fb094 */
                    local_1c0._0_6_ = (undefined6)*(undefined8 *)((long)puVar40 + 2);
                    local_1c0._6_2_ = (undefined2)uVar41;
                    local_1b8 = (undefined6)((ulong)uVar41 >> 0x10);
                    if (((ulong)local_1b0 & 1) != 0) {
                      operator_delete(local_1a0);
                    }
                    local_1b0 = (piecewise_construct_t *)CONCAT62(local_1b0._2_6_,uVar10);
                    *puVar39 = CONCAT26(local_1c0._6_2_,(undefined6)local_1c0);
                    *(ulong *)((long)puVar39 + 6) = CONCAT62(local_1b8,local_1c0._6_2_);
                    local_1a0 = pcVar28;
                    if (((ulong)local_298 & 1) != 0) {
                      operator_delete(local_288);
                    }
                    if (((ulong)local_238 & 1) != 0) {
                    /* try { // try from 004fb0ec to 005fb0f3 has its CatchHandler @ 004fb254 */
                      operator_delete(local_228);
                    }
                    bVar7 = local_418;
                    /* try { // try from 004fb0f4 to 005fb117 has its CatchHandler @ 004fb23c */
                    ppVar24 = (piecewise_construct_t *)(ulong)(local_418 >> 1);
                    if ((local_418 & 1) != 0) {
                      ppVar24 = ppStack_410;
                    }
                    ppVar46 = ppVar24 + 1;
                    if ((piecewise_construct_t *)0xffffffffffffffef < ppVar46) {
                      if (*(long *)(lVar9 + 0x28) == local_88) {
                    /* WARNING: Subroutine does not return */
                        FUN_003bc2e0(&local_238);
                      }
                      goto LAB_004fc7ac;
                    }
                    if (ppVar46 < (piecewise_construct_t *)0x17) {
                      local_230 = (piecewise_construct_t *)0x0;
                      local_228 = (char *)0x0;
                    /* try { // try from 004fb12c to 005fb13f has its CatchHandler @ 004fb218 */
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(ulong)(byte)((int)ppVar46 << 1);
                      pcVar28 = pcVar36;
                      if (ppVar24 != (piecewise_construct_t *)0x0) goto LAB_004fb2b8;
                    }
                    else {
                      uVar25 = ((ulong)ppVar46 | 0xf) + 1;
                      pcVar28 = operator_new(uVar25);
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(uVar25 | 1);
                      local_230 = ppVar46;
                      local_228 = pcVar28;
LAB_004fb2b8:
                      pcVar2 = pcVar37;
                      if ((bVar7 & 1) != 0) {
                        pcVar2 = local_408;
                      }
                      memmove(pcVar28,pcVar2,(size_t)ppVar24);
                    }
                    (pcVar28 + (long)ppVar24)[0] = '/';
                    (pcVar28 + (long)ppVar24)[1] = '\0';
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA13_KcSI_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISM_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESN_OSM_OSS_
                              (&local_298,uVar30,"materialPath","material.png");
                    /* try { // try from 004fb300 to 005fb313 has its CatchHandler @ 004fb37c */
                    ppVar24 = (piecewise_construct_t *)((ulong)local_298 >> 1 & 0x7f);
                    pcVar28 = pcVar38;
                    if (((ulong)local_298 & 1) != 0) {
                      ppVar24 = local_290;
                      pcVar28 = local_288;
                    }
                    /* try { // try from 004fb318 to 005fb357 has its CatchHandler @ 004fb358 */
                    pbVar31 = (basic_string *)FUN_005f4134(&local_238,pcVar28,ppVar24);
                    bVar5 = *pbVar31;
                    uVar41 = *(undefined8 *)(pbVar31 + 8);
                    pvVar26 = *(void **)(pbVar31 + 0x10);
                    bVar6 = pbVar31[1];
                    *(undefined8 *)(pbVar31 + 8) = 0;
                    *(undefined8 *)(pbVar31 + 0x10) = 0;
                    *(undefined8 *)pbVar31 = 0;
                    local_1c0._0_6_ = (undefined6)*(undefined8 *)(pbVar31 + 2);
                    local_1c0._6_2_ = (undefined2)uVar41;
                    local_1b8 = (undefined6)((ulong)uVar41 >> 0x10);
                    if (((byte)local_198 & 1) != 0) {
                      operator_delete(local_188);
                    }
                    /* catch() { ... } // from try @ 004fb318 with catch @ 004fb358
                       try { // try from 004fb358 to 005fb3a3 has its CatchHandler @ 004fb284 */
                    uStack_196 = (undefined6)local_1c0;
                    local_190 = local_1c0._6_2_;
                    uStack_18e = local_1b8;
                    /* catch() { ... } // from try @ 004fb300 with catch @ 004fb37c */
                    local_198 = bVar5;
                    bStack_197 = bVar6;
                    local_188 = pvVar26;
                    if (((ulong)local_298 & 1) != 0) {
                      operator_delete(local_288);
                    }
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    bVar7 = local_418;
                    /* catch() { ... } // from try @ 004fb4a4 with catch @ 004fb3a4 */
                    ppVar24 = (piecewise_construct_t *)(ulong)(local_418 >> 1);
                    if ((local_418 & 1) != 0) {
                      ppVar24 = ppStack_410;
                    }
                    ppVar46 = ppVar24 + 1;
                    if ((piecewise_construct_t *)0xffffffffffffffef < ppVar46) {
                      if (*(long *)(lVar9 + 0x28) == local_88) {
                    /* WARNING: Subroutine does not return */
                        FUN_003bc2e0(&local_238);
                      }
                      goto LAB_004fc7ac;
                    }
                    if (ppVar46 < (piecewise_construct_t *)0x17) {
                      local_230 = (piecewise_construct_t *)0x0;
                      local_228 = (char *)0x0;
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(ulong)(byte)((int)ppVar46 << 1);
                      pcVar28 = pcVar36;
                      if (ppVar24 != (piecewise_construct_t *)0x0) goto LAB_004fba94;
                    }
                    else {
                      uVar25 = ((ulong)ppVar46 | 0xf) + 1;
                      pcVar28 = operator_new(uVar25);
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(uVar25 | 1);
                    /* try { // try from 004fba8c to 005fba93 has its CatchHandler @ 004fbb94 */
                      local_230 = ppVar46;
                      local_228 = pcVar28;
LAB_004fba94:
                      pcVar2 = pcVar37;
                      if ((bVar7 & 1) != 0) {
                        pcVar2 = local_408;
                      }
                      memmove(pcVar28,pcVar2,(size_t)ppVar24);
                    }
                    (pcVar28 + (long)ppVar24)[0] = '/';
                    (pcVar28 + (long)ppVar24)[1] = '\0';
                    /* try { // try from 004fbac4 to 005fbad7 has its CatchHandler @ 004fbc00 */
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA7_KcSI_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISM_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESN_OSM_OSS_
                              (&local_298,uVar30,"psPath","ps.png");
                    ppVar24 = (piecewise_construct_t *)((ulong)local_298 >> 1 & 0x7f);
                    pcVar28 = pcVar38;
                    if (((ulong)local_298 & 1) != 0) {
                      ppVar24 = local_290;
                      pcVar28 = local_288;
                    }
                    puVar32 = (ushort *)FUN_005f4134(&local_238,pcVar28,ppVar24);
                    uVar41 = *(undefined8 *)(puVar32 + 4);
                    pvVar26 = *(void **)(puVar32 + 8);
                    uVar11 = *puVar32;
                    /* try { // try from 004fbb0c to 005fbb13 has its CatchHandler @ 004fbb80 */
                    uVar42 = *(undefined8 *)(puVar32 + 1);
                    puVar32[4] = 0;
                    puVar32[5] = 0;
                    puVar32[6] = 0;
                    puVar32[7] = 0;
                    puVar32[8] = 0;
                    puVar32[9] = 0;
                    puVar32[10] = 0;
                    puVar32[0xb] = 0;
                    puVar32[0] = 0;
                    puVar32[1] = 0;
                    puVar32[2] = 0;
                    puVar32[3] = 0;
                    local_1c0._0_6_ = (undefined6)uVar42;
                    local_1c0._6_2_ = (undefined2)uVar41;
                    local_1b8 = (undefined6)((ulong)uVar41 >> 0x10);
                    if ((local_180 & 1) != 0) {
                      operator_delete(local_170);
                    }
                    /* try { // try from 004fbb4c to 005fbb53 has its CatchHandler @ 004fbb60 */
                    local_17e = (undefined6)local_1c0;
                    uStack_178 = local_1c0._6_2_;
                    uStack_176 = local_1b8;
                    /* try { // try from 004fbb58 to 005fbb5f has its CatchHandler @ 004fbbd0 */
                    local_180 = uVar11;
                    local_170 = pvVar26;
                    if (((ulong)local_298 & 1) != 0) {
                    /* catch() { ... } // from try @ 004fbb4c with catch @ 004fbb60
                       try { // try from 004fbb60 to 005fbc27 has its CatchHandler @ 004fb908 */
                    /* catch() { ... } // from try @ 004fb970 with catch @ 004fbb64 */
                      operator_delete(local_288);
                    }
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    /* catch() { ... } // from try @ 004fbb0c with catch @ 004fbb80 */
                    /* catch() { ... } // from try @ 004fba8c with catch @ 004fbb94 */
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA10_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,uVar30,"blendType",&DAT_002de4fa);
                    /* catch() { ... } // from try @ 004fb9e8 with catch @ 004fbba8 */
                    uVar21 = std::__ndk1::stoi((basic_string *)&local_238,(ulong *)0x0,10);
                    local_158 = CONCAT44(local_158._4_4_,uVar21);
                    if (((ulong)local_238 & 1) != 0) {
                    /* catch() { ... } // from try @ 004fb950 with catch @ 004fbbbc */
                      operator_delete(local_228);
                    }
                    /* catch() { ... } // from try @ 004fba0c with catch @ 004fbbd0
                       catch() { ... } // from try @ 004fbb58 with catch @ 004fbbd0 */
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA13_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,uVar30,"sharpenAlpha",&DAT_002e7480);
                    uVar21 = std::__ndk1::stof((basic_string *)&local_238,(ulong *)0x0);
                    local_160 = CONCAT44(uVar21,(undefined4)local_160);
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    /* catch() { ... } // from try @ 004fbac4 with catch @ 004fbc00 */
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA11_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,uVar30,"blendAlpha",&DAT_002e075b);
                    uVar21 = std::__ndk1::stof((basic_string *)&local_238,(ulong *)0x0);
                    /* try { // try from 004fbc28 to 005fbcbf has its CatchHandler @ 004fbc28
                       catch() { ... } // from try @ 004fbc28 with catch @ 004fbc28
                       catch() { ... } // from try @ 004fbcd4 with catch @ 004fbc28 */
                    local_158 = CONCAT44(uVar21,(undefined4)local_158);
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA4_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,uVar30,&DAT_002da263,&DAT_002e7480);
                    uVar21 = std::__ndk1::stoi((basic_string *)&local_238,(ulong *)0x0,10);
                    local_168 = CONCAT44(local_168._4_4_,uVar21);
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA6_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,uVar30,"blend",&DAT_002e075b);
                    uVar21 = std::__ndk1::stoi((basic_string *)&local_238,(ulong *)0x0,10);
                    local_168 = CONCAT44(uVar21,(undefined4)local_168);
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    /* try { // try from 004fbcc0 to 005fbcc7 has its CatchHandler @ 004fbd40 */
                    /* try { // try from 004fbcc8 to 005fbcd3 has its CatchHandler @ 004fbd48 */
                    /* try { // try from 004fbcd4 to 005fbd7f has its CatchHandler @ 004fbc28 */
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA8_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,uVar30,"sharpen",&DAT_002d1e5b);
                    uVar21 = std::__ndk1::stoi((basic_string *)&local_238,(ulong *)0x0,10);
                    local_160 = CONCAT44(local_160._4_4_,uVar21);
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA5_KcRA14_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,local_428,"maxAlphaRatio",&DAT_002dd783);
                    uVar21 = std::__ndk1::stof((basic_string *)&local_238,(ulong *)0x0);
                    local_248 = CONCAT44(local_248._4_4_,uVar21);
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    /* catch() { ... } // from try @ 004fbcc0 with catch @ 004fbd40 */
                    /* catch() { ... } // from try @ 004fbcc8 with catch @ 004fbd48 */
                    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE5valueIRA2_KcRA16_SG_SA_TnNS2_9enable_ifIXaaaaaaaaL_ZNS2_17integral_constantIbLb1EE5valueEEntsr6detail15is_json_pointerIT0_EE5valuesr29is_comparable_with_object_keyISO_EE5valuesr6detail10is_getableISE_T1_EE5valuentsr3std7is_sameINS0_6detail7value_tENS2_9remove_cvINS2_16remove_referenceIT_E4typeEE4typeEEE5valueEiE4typeELi0EEESP_OSO_OSU_
                              (&local_238,local_428,"whitenColorHair",&DAT_002e075b);
                    iVar20 = std::__ndk1::stoi((basic_string *)&local_238,(ulong *)0x0,10);
                    local_248._0_5_ = CONCAT14(iVar20 != 0,(undefined4)local_248);
                  }
                  if (((ulong)local_238 & 1) != 0) {
                    operator_delete(local_228);
                  }
                  ppStack_258 = (piecewise_construct_t *)
                                std::__ndk1::
                                vector<MTImageKitNS::DyeHairMaterialData,std::__ndk1::allocator<MTImageKitNS::DyeHairMaterialData>>
                                ::__push_back_slow_path<MTImageKitNS::DyeHairMaterialData_const&>
                                          ((vector<MTImageKitNS::DyeHairMaterialData,std::__ndk1::allocator<MTImageKitNS::DyeHairMaterialData>>
                                            *)&local_260,(DyeHairMaterialData *)&local_1b0);
                  if ((local_180 & 1) != 0) {
                    operator_delete(local_170);
                  }
                  if (((byte)local_198 & 1) != 0) {
                    operator_delete(local_188);
                  }
                  if (((ulong)local_1b0 & 1) != 0) {
                    /* try { // try from 004fb6b4 to 005fb71f has its CatchHandler @ 004fb730 */
                    operator_delete(local_1a0);
                  }
                }
                else {
                  ppStack_258 = (piecewise_construct_t *)0x0;
                  local_260 = (piecewise_construct_t *)0x0;
                  local_250 = (char *)0x0;
                  local_248 = CONCAT35(local_248._5_3_,0x3f800000);
                }
                if (local_260 == ppStack_258) {
LAB_004fb9c4:
                  if (cVar4 == '\0') {
                    MTImageKitNS::CMTIKManager::setDoubleBufferReRender
                              (SUB81(*(undefined8 *)(this + 0x28),0));
                  }
                  else {
                    MTImageKitNS::CMTIKManager::processRender(SUB81(*(undefined8 *)(this + 0x28),0))
                    ;
                  }
                  iVar20 = 7;
                }
                else {
                  if (local_248._4_1_ == '\0') {
LAB_004fb8ec:
                    local_278 = (void *)0x0;
                    local_280 = (void *)0x0;
                    local_270 = 0;
                    /* catch() { ... } // from try @ 004fba14 with catch @ 004fb908
                       catch() { ... } // from try @ 004fbb60 with catch @ 004fb908 */
                    std::__ndk1::
                    vector<MTImageKitNS::DyeHairMaterialData,std::__ndk1::allocator<MTImageKitNS::DyeHairMaterialData>>
                    ::
                    __init_with_size_abi_ne180000_<MTImageKitNS::DyeHairMaterialData*,MTImageKitNS::DyeHairMaterialData*>
                              ((vector<MTImageKitNS::DyeHairMaterialData,std::__ndk1::allocator<MTImageKitNS::DyeHairMaterialData>>
                                *)&local_280,(DyeHairMaterialData *)local_260,
                               (DyeHairMaterialData *)ppStack_258,
                               ((long)ppStack_258 - (long)local_260 >> 5) * -0x5555555555555555);
                    local_268 = (undefined4)local_248;
                    local_264 = local_248._4_1_;
                    MTImageKitNS::CMTIKHairFilter::setDyeHairMaterialInfo(this_00,&local_280,1);
                    pvVar13 = local_280;
                    pvVar26 = local_278;
                    if (local_280 != (void *)0x0) {
                    /* try { // try from 004fb950 to 005fb957 has its CatchHandler @ 004fbbbc */
                      for (; pvVar26 != pvVar13; pvVar26 = (void *)((long)pvVar26 + -0x60)) {
                        if ((*(byte *)((long)pvVar26 + -0x30) & 1) == 0) {
                    /* try { // try from 004fb970 to 005fb973 has its CatchHandler @ 004fbb64 */
                          if ((*(byte *)((long)pvVar26 + -0x48) & 1) != 0) goto LAB_004fb990;
LAB_004fb974:
                          bVar7 = *(byte *)((long)pvVar26 + -0x60);
                        }
                        else {
                          operator_delete(*(void **)((long)pvVar26 + -0x20));
                          if ((*(byte *)((long)pvVar26 + -0x48) & 1) == 0) goto LAB_004fb974;
LAB_004fb990:
                          operator_delete(*(void **)((long)pvVar26 + -0x38));
                          bVar7 = *(byte *)((long)pvVar26 + -0x60);
                        }
                        if ((bVar7 & 1) != 0) {
                          operator_delete(*(void **)((long)pvVar26 + -0x50));
                        }
                      }
                      local_278 = pvVar13;
                      operator_delete(local_280);
                    }
                    MTImageKitNS::CMTIKHairFilter::setDyeHairRenderAlpha(*(float *)(pcVar33 + 0x18))
                    ;
                    goto LAB_004fb9c4;
                  }
                  MTImageKitNS::CMTIKHairFilter::getSrcImage();
                  if (local_1b0 == (piecewise_construct_t *)0x0) {
LAB_004fb8ac:
                    iVar20 = 0;
                  }
                  else {
                    local_298 = (piecewise_construct_t *)CONCAT44(local_298._4_4_,30000);
                    FUN_005001c4(&local_238,&local_1c0,&local_1b0,&local_298);
                    local_450 = 0;
                    local_448 = (long *)0x0;
                    (**(code **)(*(long *)local_238 + 0x10))(&local_1c0,local_238,&local_450);
                    /* try { // try from 004fb720 to 005fb74b has its CatchHandler @ 004fb64c */
                    local_298 = (piecewise_construct_t *)
                                CONCAT26(local_1c0._6_2_,(undefined6)local_1c0);
                    local_290 = (piecewise_construct_t *)CONCAT26(uStack_1b2,local_1b8);
                    /* catch() { ... } // from try @ 004fb6b4 with catch @ 004fb730 */
                    if (local_290 != (piecewise_construct_t *)0x0) {
                      FUN_006263b0(1,local_290 + 8);
                      plVar23 = (long *)CONCAT26(uStack_1b2,local_1b8);
                    /* catch() { ... } // from try @ 004fb84c with catch @ 004fb74c */
                      if ((plVar23 != (long *)0x0) &&
                         (lVar22 = FUN_006263e0(0xffffffffffffffff,plVar23 + 1), lVar22 == 0)) {
                        (**(code **)(*plVar23 + 0x10))(plVar23);
                        std::__ndk1::__shared_weak_count::__release_weak();
                      }
                    }
                    plVar23 = local_448;
                    if ((local_448 != (long *)0x0) &&
                       (lVar22 = FUN_006263e0(0xffffffffffffffff,local_448 + 1), lVar22 == 0)) {
                    /* try { // try from 004fb78c to 005fb84b has its CatchHandler @ 004fb86c */
                      (**(code **)(*plVar23 + 0x10))(plVar23);
                      std::__ndk1::__shared_weak_count::__release_weak();
                    }
                    if ((*(long *)(local_298 + 0x68) == 0) ||
                       (lVar22 = *(long *)(local_298 + 0x58), lVar22 == 0)) {
                      iVar20 = 6;
                      MTImageKitNS::CMTIKLog::log
                                ("iklf",6,"CLFDenseHairProcessor<%s:%d> aigc error.","applyLayer",
                                 0x155);
                      bVar16 = false;
                    }
                    else {
                      lStack_458 = *(long *)(local_298 + 0x60);
                      local_460 = lVar22;
                      if (lStack_458 != 0) {
                        FUN_006263b0(1,lStack_458 + 8);
                      }
                      MTImageKitNS::CMTIKHairFilter::setHairMaskImage(this_00,&local_460,0);
                      FUN_003bbdb4(&local_460);
                      local_470 = *(undefined8 *)(local_298 + 0x68);
                      lStack_468 = *(long *)(local_298 + 0x70);
                      if (lStack_468 != 0) {
                        FUN_006263b0(1,lStack_468 + 8);
                      }
                      MTImageKitNS::CMTIKHairFilter::setWhitenHairImage(this_00,&local_470);
                      FUN_003bbdb4(&local_470);
                      iVar20 = 0;
                      bVar16 = true;
                    }
                    ppVar24 = local_290;
                    /* try { // try from 004fb84c to 005fb887 has its CatchHandler @ 004fb74c */
                    if ((local_290 != (piecewise_construct_t *)0x0) &&
                       (lVar22 = FUN_006263e0(0xffffffffffffffff,local_290 + 8), lVar22 == 0)) {
                    /* catch() { ... } // from try @ 004fb78c with catch @ 004fb86c */
                      (**(code **)(*(long *)ppVar24 + 0x10))(ppVar24);
                      std::__ndk1::__shared_weak_count::__release_weak();
                    }
                    ppVar24 = local_230;
                    if ((local_230 != (piecewise_construct_t *)0x0) &&
                       (lVar22 = FUN_006263e0(0xffffffffffffffff,local_230 + 8), lVar22 == 0)) {
                      (**(code **)(*(long *)ppVar24 + 0x10))(ppVar24);
                      std::__ndk1::__shared_weak_count::__release_weak();
                    }
                    if (bVar16) goto LAB_004fb8ac;
                  }
                  ppVar24 = ppStack_1a8;
                  if ((ppStack_1a8 != (piecewise_construct_t *)0x0) &&
                     (lVar22 = FUN_006263e0(0xffffffffffffffff,ppStack_1a8 + 8), lVar22 == 0)) {
                    (**(code **)(*(long *)ppVar24 + 0x10))(ppVar24);
                    std::__ndk1::__shared_weak_count::__release_weak();
                  }
                  if (iVar20 == 0) goto LAB_004fb8ec;
                }
                    /* try { // try from 004fb9e8 to 005fb9ef has its CatchHandler @ 004fbba8 */
                ppVar46 = local_260;
                ppVar24 = ppStack_258;
                if (local_260 != (piecewise_construct_t *)0x0) {
                  for (; ppVar24 != ppVar46; ppVar24 = ppVar24 + -0x60) {
                    /* try { // try from 004fba14 to 005fba8b has its CatchHandler @ 004fb908 */
                    if (((byte)ppVar24[-0x30] & 1) == 0) {
                      if (((byte)ppVar24[-0x48] & 1) != 0) goto LAB_004fba3c;
LAB_004fba20:
                      pVar8 = ppVar24[-0x60];
                    }
                    else {
                      operator_delete(*(void **)(ppVar24 + -0x20));
                      if (((byte)ppVar24[-0x48] & 1) == 0) goto LAB_004fba20;
LAB_004fba3c:
                      operator_delete(*(void **)(ppVar24 + -0x38));
                      pVar8 = ppVar24[-0x60];
                    }
                    if (((byte)pVar8 & 1) != 0) {
                      operator_delete(*(void **)(ppVar24 + -0x50));
                    }
                    /* try { // try from 004fba0c to 005fba13 has its CatchHandler @ 004fbbd0 */
                  }
                  ppStack_258 = ppVar46;
                  operator_delete(local_260);
                }
              }
              else {
LAB_004fa024:
                CLFDenseHairLayer::getMaterialPathBy(local_2a8);
LAB_004fa034:
                uVar21 = *(undefined4 *)(pcVar33 + 8);
                if (((ulong)local_1b0 & 1) == 0) {
LAB_004fa040:
                  ppStack_438 = ppStack_1a8;
                  local_440 = local_1b0;
                  local_430 = local_1a0;
                }
                else {
LAB_004fac94:
                  FUN_003bc260(&local_440,local_1a0,ppStack_1a8);
                }
                iVar20 = MTImageKitNS::CMTIKHairFilter::hairColorAIRequest
                                   (this_00,uVar21,&local_440);
                if (((ulong)local_440 & 1) != 0) {
                  operator_delete(local_430);
                }
                if (iVar20 == 0) {
                  MTImageKitNS::CMTIKHairFilter::setDyeHairRenderAlpha(*(float *)(pcVar33 + 0x18));
                  if (cVar4 == '\0') {
                    MTImageKitNS::CMTIKManager::setDoubleBufferReRender
                              (SUB81(*(undefined8 *)(this + 0x28),0));
                  }
                  else {
                    MTImageKitNS::CMTIKManager::processRender(SUB81(*(undefined8 *)(this + 0x28),0))
                    ;
                  }
                }
                else {
                    /* try { // try from 004face4 to 005faceb has its CatchHandler @ 004fad30 */
                  MTImageKitNS::CMTIKLog::log
                            ("iklf",6,"CLFDenseHairProcessor<%s:%d> hairColorAIRequest error.",
                             "applyLayer",0x13d);
                    /* try { // try from 004facec to 005fad27 has its CatchHandler @ 004fac70 */
                }
                if (((ulong)local_1b0 & 1) != 0) {
                    /* try { // try from 004fad28 to 005fad2f has its CatchHandler @ 004fad30 */
                  operator_delete(local_1a0);
                }
                iVar20 = 7;
              }
                    /* catch() { ... } // from try @ 004face4 with catch @ 004fad30
                       catch() { ... } // from try @ 004fad28 with catch @ 004fad30
                       try { // try from 004fad30 to 005fad43 has its CatchHandler @ 004fac70 */
              nlohmann::json_abi_v3_12_0::
              basic_json<std::__ndk1::map,std::__ndk1::vector,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,bool,long,unsigned_long,double,std::__ndk1::allocator,nlohmann::json_abi_v3_12_0::adl_serializer,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,void>
              ::json_value::destroy((json_value *)&local_420,local_428[0]);
                    /* try { // try from 004fad44 to 005fadb7 has its CatchHandler @ 004fad44
                       catch() { ... } // from try @ 004fad44 with catch @ 004fad44
                       catch() { ... } // from try @ 004fadc0 with catch @ 004fad44
                       catch() { ... } // from try @ 004fae04 with catch @ 004fad44 */
              if ((local_418 & 1) != 0) {
                operator_delete(local_408);
              }
              if (iVar20 != 7) {
LAB_004fad58:
                if ((iVar20 != 6) && (iVar20 != 0)) goto LAB_004fc1c4;
              }
            }
            else {
              if (iVar20 != 0x902) {
                if (iVar20 != 0x903) goto LAB_004fc314;
                goto LAB_004f9f54;
              }
              MTImageKitNS::CMTIKHairFilter::setFunctionType(this_00,6);
              bVar16 = 0 < (int)(*(float *)(pcVar33 + 0x18) + -1.0);
                    /* catch() { ... } // from try @ 004f9e40 with catch @ 004fa0e0 */
                    /* catch() { ... } // from try @ 004f9df0 with catch @ 004fa0e4 */
              MTImageKitNS::CMTIKLog::log
                        ("iklf",4,
                         "CLFDenseHairProcessor<%s:%d> apply straight hair, faceId=%d, alpha=%.2f, softSwitch=%d"
                         ,(double)*(float *)(pcVar33 + 0x18),"applyLayer",0x170,
                         (ulong)*(uint *)(pcVar33 + 8),(ulong)bVar16 << 1);
              local_480 = 0;
              local_478 = (long *)0x0;
              MTImageKitNS::CMTIKHairFilter::applyStraightHairEffect
                        (this_00,*(undefined4 *)(pcVar33 + 8),(ulong)bVar16 << 1,&local_480);
              plVar23 = local_478;
              if ((local_478 == (long *)0x0) ||
                 (lVar22 = FUN_006263e0(0xffffffffffffffff,local_478 + 1), lVar22 != 0)) {
                uVar18 = (undefined1)*(undefined8 *)(this + 0x28);
              }
              else {
                (**(code **)(*plVar23 + 0x10))(plVar23);
                std::__ndk1::__shared_weak_count::__release_weak();
                    /* try { // try from 004fa250 to 005fa28f has its CatchHandler @ 004fa290 */
                uVar18 = (undefined1)*(undefined8 *)(this + 0x28);
              }
              if (cVar4 == '\0') {
                MTImageKitNS::CMTIKManager::setDoubleBufferReRender((bool)uVar18);
              }
              else {
                MTImageKitNS::CMTIKManager::processRender((bool)uVar18);
                    /* try { // try from 004fa13c to 005fa1c7 has its CatchHandler @ 004fa13c
                       catch() { ... } // from try @ 004fa13c with catch @ 004fa13c
                       catch() { ... } // from try @ 004fa220 with catch @ 004fa13c
                       catch() { ... } // from try @ 004fa290 with catch @ 004fa13c */
              }
            }
          }
          else {
            if (0x59e6 < iVar20) {
              if (iVar20 != 0x59e7) {
                if (iVar20 == 0x15f41ea) {
                  MTImageKitNS::CMTIKHairFilter::setFunctionType(this_00,10);
                  MTImageKitNS::CMTIKHairFilter::applySmoothHairEffect
                            ((int)this_00,*(float *)(pcVar33 + 0x18));
                  goto LAB_004fa17c;
                }
                if (iVar20 != 0x59e9) goto LAB_004fc314;
              }
LAB_004f9f54:
              if (!bVar17) {
                MTImageKitNS::CMTIKHairFilter::setFunctionType(this_00,0x13);
                puVar40 = local_358;
                while (puVar40 != &local_350) {
                  uVar21 = *(undefined4 *)(puVar40 + 4);
                  MTImageKitNS::CMTIKHairVolumeInfo::CMTIKHairVolumeInfo
                            (aCStack_400,(CMTIKHairVolumeInfo *)(puVar40 + 5));
                  MTImageKitNS::CMTIKHairFilter::applyVolumeInfoEffect(this_00,uVar21,aCStack_400);
                  MTImageKitNS::CMTIKHairVolumeInfo::~CMTIKHairVolumeInfo(aCStack_400);
                  puVar14 = (undefined8 *)puVar40[1];
                  puVar44 = puVar40;
                  if ((undefined8 *)puVar40[1] == (undefined8 *)0x0) {
                    do {
                      puVar40 = (undefined8 *)puVar44[2];
                      bVar17 = (undefined8 *)*puVar40 != puVar44;
                      puVar44 = puVar40;
                    } while (bVar17);
                  }
                  else {
                    do {
                      puVar40 = puVar14;
                      puVar14 = (undefined8 *)*puVar40;
                    } while ((undefined8 *)*puVar40 != (undefined8 *)0x0);
                  }
                }
                if (cVar4 != '\0') {
                  bVar17 = true;
                  MTImageKitNS::CMTIKManager::processRender(SUB81(*(undefined8 *)(this + 0x28),0));
                  goto LAB_004f9e3c;
                }
                MTImageKitNS::CMTIKManager::setDoubleBufferReRender
                          (SUB81(*(undefined8 *)(this + 0x28),0));
              }
              bVar17 = true;
              goto LAB_004f9e3c;
            }
            if (iVar20 == 0x904) {
              MTImageKitNS::CMTIKHairFilter::setFunctionType(this_00,8);
              local_490 = 0;
              local_488 = (long *)0x0;
              MTImageKitNS::CMTIKHairFilter::applyCurlyHairEffect
                        (this_00,*(undefined4 *)(pcVar33 + 8),&local_490);
              plVar23 = local_488;
              if ((local_488 != (long *)0x0) &&
                 (lVar22 = FUN_006263e0(0xffffffffffffffff,local_488 + 1), lVar22 == 0)) {
                (**(code **)(*plVar23 + 0x10))(plVar23);
                std::__ndk1::__shared_weak_count::__release_weak();
              }
            }
            else {
              if (iVar20 != 0x905) {
                if (iVar20 != 0x906) goto LAB_004fc314;
                MTImageKitNS::CMTIKHairFilter::setFunctionType(this_00,0x15);
                CLFDenseHairLayer::getMaterialPathBy(local_2a8);
                ppVar24 = (piecewise_construct_t *)((ulong)local_1b0 >> 1 & 0x7f);
                if (((ulong)local_1b0 & 1) != 0) {
                  ppVar24 = ppStack_1a8;
                }
                if (ppVar24 == (piecewise_construct_t *)0x0) {
                  MTImageKitNS::CMTIKLog::log
                            ("iklf",6,
                             "CLFDenseHairProcessor<%s:%d> hair style material path is empty, materialId=%lld"
                             ,"applyLayer",0x18d,*(undefined8 *)(pcVar33 + 0x10));
LAB_004fa930:
                  bVar16 = false;
                    /* try { // try from 004fa934 to 005fa93b has its CatchHandler @ 004fa9d8 */
                  iVar20 = 1;
                }
                else {
                  if (!bVar15) {
                    /* try { // try from 004fa220 to 005fa233 has its CatchHandler @ 004fa13c */
                    MTImageKitNS::CMTIKLog::log
                              ("iklf",6,
                               "CLFDenseHairProcessor<%s:%d> renderPlugin->cbSetNetHeader is nullptr."
                               ,"applyLayer",0x1c1);
                    /* try { // try from 004fa234 to 005fa24b has its CatchHandler @ 004fa2a0 */
                    goto LAB_004fa930;
                  }
                  if (((ulong)local_1b0 & 1) == 0) {
                    ppStack_258 = ppStack_1a8;
                    local_260 = local_1b0;
                    local_250 = local_1a0;
                  }
                  else {
                    FUN_003bc260(&local_260,local_1a0);
                  }
                  ppVar24 = (piecewise_construct_t *)((ulong)local_260 >> 1 & 0x7f);
                  pcVar28 = pcVar35;
                  if (((ulong)local_260 & 1) != 0) {
                    ppVar24 = ppStack_258;
                    pcVar28 = local_250;
                  }
                    /* catch() { ... } // from try @ 004fa250 with catch @ 004fa290
                       try { // try from 004fa290 to 005fa2e7 has its CatchHandler @ 004fa13c */
                    /* catch() { ... } // from try @ 004fa234 with catch @ 004fa2a0 */
                  if ((pcVar28 + (long)ppVar24)[-1] != '/') {
                    /* catch() { ... } // from try @ 004fa1e0 with catch @ 004fa2a4 */
                    std::__ndk1::
                    basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
                    push_back((char)&local_260);
                  }
                  ppVar24 = local_260;
                    /* catch() { ... } // from try @ 004fa1c8 with catch @ 004fa2c0 */
                  if (*(long *)(pcVar33 + 0x10) == 0x15f4200) {
LAB_004fa514:
                    local_290 = operator_new(0x40);
                    *(undefined8 *)(local_290 + 8) = 0;
                    *(undefined8 *)(local_290 + 0x10) = 0;
                    *(undefined8 *)(local_290 + 0x30) = 0;
                    *(undefined8 *)(local_290 + 0x38) = 0;
                    *(undefined ***)local_290 = &PTR____shared_ptr_emplace_00644470;
                    ppVar24 = local_290 + 0x18;
                    *(undefined ***)ppVar24 = &PTR__CMTIKHairFlowAIGCRequest_006444c0;
                    /* catch() { ... } // from try @ 004fa4f4 with catch @ 004fa534
                       try { // try from 004fa534 to 005fa5b7 has its CatchHandler @ 004fa384 */
                    *(undefined8 *)(local_290 + 0x20) = 0;
                    *(undefined8 *)(local_290 + 0x28) = 0;
                    local_290[0x30] = (piecewise_construct_t)0x0;
                    local_298 = ppVar24;
                    MTImageKitNS::CMTIKHairFilter::getSrcImage();
                    /* catch() { ... } // from try @ 004fa4d4 with catch @ 004fa558 */
                    local_4d0 = local_318;
                    local_4c8 = local_310;
                    if (local_310 != (piecewise_construct_t *)0x0) {
                      FUN_006263b0(1,local_310 + 8);
                    }
                    local_1d0 = (long *)0x0;
                    /* catch() { ... } // from try @ 004fa4cc with catch @ 004fa570 */
                    local_200 = (long *)0x0;
                    /* catch() { ... } // from try @ 004fa478 with catch @ 004fa574 */
                    /* catch() { ... } // from try @ 004fa460 with catch @ 004fa590 */
                    MTImageKitNS::CMTIKHairFlowAIGCRequest::requestWithImage
                              (&local_238,ppVar24,auStack_4c0,&local_4d0,&local_1b0,local_1f0,
                               local_220);
                    if (local_200 == local_220) {
                      plVar23 = local_220;
                      lVar22 = 4;
LAB_004fa5b8:
                    /* try { // try from 004fa5b8 to 005fa693 has its CatchHandler @ 004fa5b8
                       catch() { ... } // from try @ 004fa5b8 with catch @ 004fa5b8
                       catch() { ... } // from try @ 004fa6ec with catch @ 004fa5b8
                       catch() { ... } // from try @ 004fa768 with catch @ 004fa5b8 */
                      (**(code **)(*plVar23 + lVar22 * 8))();
                    }
                    else if (local_200 != (long *)0x0) {
                      lVar22 = 5;
                      plVar23 = local_200;
                      goto LAB_004fa5b8;
                    }
                    if (local_1d0 == local_1f0) {
                      plVar23 = local_1f0;
                      lVar22 = 4;
LAB_004fa5e8:
                      (**(code **)(*plVar23 + lVar22 * 8))();
                    }
                    else if (local_1d0 != (long *)0x0) {
                      lVar22 = 5;
                      plVar23 = local_1d0;
                      goto LAB_004fa5e8;
                    }
                    ppVar24 = local_4c8;
                    if ((local_4c8 != (piecewise_construct_t *)0x0) &&
                       (lVar22 = FUN_006263e0(0xffffffffffffffff,local_4c8 + 8), lVar22 == 0)) {
                      (**(code **)(*(long *)ppVar24 + 0x10))(ppVar24);
                      std::__ndk1::__shared_weak_count::__release_weak();
                    }
                    plVar23 = local_4b8;
                    if ((local_4b8 != (long *)0x0) &&
                       (lVar22 = FUN_006263e0(0xffffffffffffffff,local_4b8 + 1), lVar22 == 0)) {
                      (**(code **)(*plVar23 + 0x10))(plVar23);
                      std::__ndk1::__shared_weak_count::__release_weak();
                    }
                    if (((int)local_228 != 0) ||
                       (local_238 ==
                        (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)0x0)) {
                      MTImageKitNS::CMTIKLog::log
                                ("iklf",6,
                                 "CLFDenseHairProcessor<%s:%d> hair flow AIGC request failed, materialId=%lld, result=%d"
                                 ,"applyLayer",0x1bb,*(undefined8 *)(pcVar33 + 0x10));
                      ppVar24 = local_230;
                    /* try { // try from 004fa694 to 005fa6a7 has its CatchHandler @ 004fa7c4 */
                      if ((local_230 != (piecewise_construct_t *)0x0) &&
                         (lVar22 = FUN_006263e0(0xffffffffffffffff,local_230 + 8), lVar22 == 0)) {
                        (**(code **)(*(long *)ppVar24 + 0x10))(ppVar24);
                    /* try { // try from 004fa6ac to 005fa6eb has its CatchHandler @ 004fa7a8 */
                        std::__ndk1::__shared_weak_count::__release_weak();
                      }
                      ppVar24 = local_290;
                      if ((local_290 != (piecewise_construct_t *)0x0) &&
                         (lVar22 = FUN_006263e0(0xffffffffffffffff,local_290 + 8), lVar22 == 0)) {
                        (**(code **)(*(long *)ppVar24 + 0x10))(ppVar24);
                        std::__ndk1::__shared_weak_count::__release_weak();
                      }
LAB_004fa920:
                    /* try { // try from 004fa920 to 005fa933 has its CatchHandler @ 004fa7ec */
                      if (((ulong)local_260 & 1) != 0) {
                        operator_delete(local_250);
                      }
                      goto LAB_004fa930;
                    }
                    /* try { // try from 004fa6ec to 005fa6ff has its CatchHandler @ 004fa5b8 */
                    uVar21 = *(undefined4 *)(pcVar33 + 8);
                    local_4e0 = local_238;
                    ppStack_4d8 = local_230;
                    if (local_230 != (piecewise_construct_t *)0x0) {
                    /* try { // try from 004fa700 to 005fa707 has its CatchHandler @ 004fa7a4 */
                      FUN_006263b0(1,local_230 + 8);
                    }
                    /* try { // try from 004fa708 to 005fa723 has its CatchHandler @ 004fa78c */
                    MTImageKitNS::CMTIKHairFilter::applyHairEffect(this_00,uVar21,&local_4e0);
                    FUN_003bbdb4(&local_4e0);
                    std::__ndk1::pair<std::__ndk1::shared_ptr<MTImageKitNS::Image>,int>::~pair
                              ((pair<std::__ndk1::shared_ptr<MTImageKitNS::Image>,int> *)&local_238)
                    ;
                    /* try { // try from 004fa728 to 005fa767 has its CatchHandler @ 004fa768 */
                    FUN_004fcac0(&local_298);
                  }
                  else {
                    ppVar46 = (piecewise_construct_t *)((ulong)local_260 >> 1 & 0x7f);
                    if (((ulong)local_260 & 1) != 0) {
                      ppVar46 = ppStack_258;
                    }
                    ppVar45 = ppVar46 + 0xb;
                    if ((piecewise_construct_t *)0xffffffffffffffef < ppVar45) {
                      if (*(long *)(lVar9 + 0x28) == local_88) {
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004fc344 with catch @ 004fc36c
                        */
                    /* WARNING: Subroutine does not return */
                        FUN_003bc2e0(&local_238);
                      }
                      goto LAB_004fc7ac;
                    }
                    if (ppVar45 < (piecewise_construct_t *)0x17) {
                      local_230 = (piecewise_construct_t *)0x0;
                      local_228 = (char *)0x0;
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(ulong)(byte)((int)ppVar45 << 1);
                      pcVar28 = pcVar36;
                      if (ppVar46 != (piecewise_construct_t *)0x0) goto LAB_004fa48c;
                    }
                    else {
                      uVar25 = ((ulong)ppVar45 | 0xf) + 1;
                      pcVar28 = operator_new(uVar25);
                    /* try { // try from 004fa478 to 005fa4b7 has its CatchHandler @ 004fa574 */
                      local_238 = (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                                   *)(uVar25 | 1);
                      local_230 = ppVar45;
                      local_228 = pcVar28;
LAB_004fa48c:
                      pcVar2 = pcVar35;
                      if (((ulong)ppVar24 & 1) != 0) {
                        pcVar2 = local_250;
                      }
                      memmove(pcVar28,pcVar2,(size_t)ppVar46);
                    }
                    /* try { // try from 004fa4b8 to 005fa4cb has its CatchHandler @ 004fa384 */
                    builtin_strncpy(pcVar28 + (long)ppVar46,"config.json",0xc);
                    /* try { // try from 004fa4cc to 005fa4d3 has its CatchHandler @ 004fa570 */
                    /* try { // try from 004fa4d4 to 005fa4ef has its CatchHandler @ 004fa558 */
                    pcVar28 = pcVar36;
                    if (((ulong)local_238 & 1) != 0) {
                      pcVar28 = local_228;
                    }
                    uVar25 = MTImageKitNS::FileIO::CheckFileExist(pcVar28);
                    ppVar24 = local_260;
                    if ((uVar25 & 1) == 0) {
                      ppVar46 = (piecewise_construct_t *)((ulong)local_260 >> 1 & 0x7f);
                      if (((ulong)local_260 & 1) != 0) {
                        ppVar46 = ppStack_258;
                      }
                      ppVar45 = ppVar46 + 0x13;
                      if ((piecewise_construct_t *)0xffffffffffffffef < ppVar45) {
                        if (*(long *)(lVar9 + 0x28) == local_88) {
                    /* WARNING: Subroutine does not return */
                          FUN_003bc2e0(&local_298);
                        }
                        goto LAB_004fc7ac;
                      }
                      if (ppVar45 < (piecewise_construct_t *)0x17) {
                    /* catch() { ... } // from try @ 004fa728 with catch @ 004fa768
                       try { // try from 004fa768 to 005fa7eb has its CatchHandler @ 004fa5b8 */
                        local_290 = (piecewise_construct_t *)0x0;
                        local_288 = (char *)0x0;
                        local_298 = (piecewise_construct_t *)(ulong)(byte)((int)ppVar45 << 1);
                        pcVar28 = pcVar38;
                        if (ppVar46 != (piecewise_construct_t *)0x0) goto LAB_004fa7d8;
                      }
                      else {
                        uVar25 = ((ulong)ppVar45 | 0xf) + 1;
                        pcVar28 = operator_new(uVar25);
                    /* catch() { ... } // from try @ 004fa694 with catch @ 004fa7c4 */
                        local_298 = (piecewise_construct_t *)(uVar25 | 1);
                        local_290 = ppVar45;
                        local_288 = pcVar28;
LAB_004fa7d8:
                        pcVar2 = pcVar35;
                    /* try { // try from 004fa7ec to 005fa8c7 has its CatchHandler @ 004fa7ec
                       catch() { ... } // from try @ 004fa7ec with catch @ 004fa7ec
                       catch() { ... } // from try @ 004fa920 with catch @ 004fa7ec
                       catch() { ... } // from try @ 004fa99c with catch @ 004fa7ec */
                        if (((ulong)ppVar24 & 1) != 0) {
                          pcVar2 = local_250;
                        }
                        memmove(pcVar28,pcVar2,(size_t)ppVar46);
                      }
                      builtin_strncpy(pcVar28 + (long)ppVar46,"configuration.plist",0x14);
                      pcVar28 = pcVar38;
                      if (((ulong)local_298 & 1) != 0) {
                        pcVar28 = local_288;
                      }
                      uVar25 = MTImageKitNS::FileIO::CheckFileExist(pcVar28);
                      uVar25 = uVar25 & 0xffffffff;
                      if (((ulong)local_298 & 1) != 0) {
                        operator_delete(local_288);
                      }
                    }
                    else {
                      uVar25 = 1;
                    /* try { // try from 004fa4f4 to 005fa533 has its CatchHandler @ 004fa534 */
                    }
                    if (((ulong)local_238 & 1) != 0) {
                      operator_delete(local_228);
                    }
                    if ((uVar25 & 1) == 0) goto LAB_004fa514;
                    pcVar28 = (char *)((ulong)&local_1b0 | 1);
                    if (((ulong)local_1b0 & 1) != 0) {
                      pcVar28 = local_1a0;
                    }
                    MTImageKitNS::CMTIKLog::log
                              ("iklf",4,
                               "CLFDenseHairProcessor<%s:%d> apply configurable hair style effect, materialId=%lld, path=%s, alpha=%.2f"
                               ,(double)*(float *)(pcVar33 + 0x18),"applyLayer",0x1a3,
                               *(undefined8 *)(pcVar33 + 0x10),pcVar28);
                    uVar21 = *(undefined4 *)(pcVar33 + 8);
                    if (((ulong)local_1b0 & 1) == 0) {
                      ppStack_4a8 = ppStack_1a8;
                      local_4b0 = local_1b0;
                      local_4a0 = local_1a0;
                    }
                    else {
                    /* try { // try from 004fa8c8 to 005fa8db has its CatchHandler @ 004fa9f8 */
                      FUN_003bc260(&local_4b0,local_1a0,ppStack_1a8);
                    }
                    uVar19 = MTImageKitNS::CMTIKHairFilter::applyHairStyleEffect
                                       (*(undefined4 *)(pcVar33 + 0x18),this_00,uVar21,&local_4b0);
                    /* try { // try from 004fa8e0 to 005fa91f has its CatchHandler @ 004fa9dc */
                    if (((ulong)local_4b0 & 1) != 0) {
                      operator_delete(local_4a0);
                    }
                    if (uVar19 != 0) {
                      MTImageKitNS::CMTIKLog::log
                                ("iklf",6,
                                 "CLFDenseHairProcessor<%s:%d> applyHairStyleEffect failed, materialId=%lld, result=%d"
                                 ,"applyLayer",0x1aa,*(undefined8 *)(pcVar33 + 0x10),(ulong)uVar19);
                      goto LAB_004fa920;
                    }
                  }
                  if (((ulong)local_260 & 1) != 0) {
                    /* try { // try from 004fa95c to 005fa99b has its CatchHandler @ 004fa99c */
                    operator_delete(local_250);
                  }
                  if (cVar4 == '\0') {
                    MTImageKitNS::CMTIKManager::setDoubleBufferReRender
                              (SUB81(*(undefined8 *)(this + 0x28),0));
                    iVar20 = 7;
                    bVar16 = true;
                  }
                  else {
                    bVar16 = true;
                    MTImageKitNS::CMTIKManager::processRender(SUB81(*(undefined8 *)(this + 0x28),0))
                    ;
                    iVar20 = 7;
                  }
                }
                    /* try { // try from 004fa93c to 005fa957 has its CatchHandler @ 004fa9c0 */
                if (((ulong)local_1b0 & 1) != 0) {
                  operator_delete(local_1a0);
                }
                if (bVar16) goto LAB_004f9e3c;
                goto LAB_004fad58;
              }
              MTImageKitNS::CMTIKHairFilter::setFunctionType(this_00,9);
              MTImageKitNS::CMTIKHairFilter::applyShinyHairEffect
                        ((int)this_00,*(float *)(pcVar33 + 0x18));
            }
LAB_004fa17c:
            if (cVar4 == '\0') {
              MTImageKitNS::CMTIKManager::setDoubleBufferReRender
                        (SUB81(*(undefined8 *)(this + 0x28),0));
            }
            else {
              MTImageKitNS::CMTIKManager::processRender(SUB81(*(undefined8 *)(this + 0x28),0));
            }
          }
LAB_004f9e3c:
          pcVar33 = pcVar33 + 0x20;
                    /* try { // try from 004f9e40 to 005f9e53 has its CatchHandler @ 004fa0e0 */
        } while (pcVar33 != pcVar12);
        iVar20 = 5;
LAB_004fc1c4:
        bVar17 = iVar20 == 5;
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004fc194 with catch @ 004fc1c8
                        */
      }
    }
LAB_004fc1dc:
    FUN_004fffe0(&local_358,local_350);
    ppVar24 = local_310;
    if ((local_310 != (piecewise_construct_t *)0x0) &&
       (lVar22 = FUN_006263e0(0xffffffffffffffff,local_310 + 8), lVar22 == 0)) {
      (**(code **)(*(long *)ppVar24 + 0x10))(ppVar24);
      std::__ndk1::__shared_weak_count::__release_weak();
    }
                    /* try { // try from 004fc218 to 005fc21b has its CatchHandler @ 004fc2c0 */
    ppVar24 = local_2e8;
    if ((local_2e8 != (piecewise_construct_t *)0x0) &&
       (lVar22 = FUN_006263e0(0xffffffffffffffff,local_2e8 + 8), lVar22 == 0)) {
      (**(code **)(*(long *)ppVar24 + 0x10))(ppVar24);
      std::__ndk1::__shared_weak_count::__release_weak();
    }
    if (local_2c0 != (char *)0x0) {
      local_2b8 = local_2c0;
                    /* try { // try from 004fc254 to 005fc25b has its CatchHandler @ 004fc2c8 */
      operator_delete(local_2c0);
    }
    if ((local_2d8 & 1) != 0) {
      operator_delete(local_2c8);
    }
    plVar23 = local_2a0;
    if ((local_2a0 != (long *)0x0) &&
       (lVar22 = FUN_006263e0(0xffffffffffffffff,local_2a0 + 1), lVar22 == 0)) {
      (**(code **)(*plVar23 + 0x10))(plVar23);
      std::__ndk1::__shared_weak_count::__release_weak();
    }
  }
  if (*(long *)(lVar9 + 0x28) == local_88) {
                    /* try { // try from 004fc2b8 to 005fc2bf has its CatchHandler @ 004fc2c0 */
                    /* catch() { ... } // from try @ 004fc218 with catch @ 004fc2c0
                       catch() { ... } // from try @ 004fc2b8 with catch @ 004fc2c0
                       try { // try from 004fc2c0 to 005fc2fb has its CatchHandler @ 004fc1cc */
                    /* catch() { ... } // from try @ 004fc254 with catch @ 004fc2c8 */
    return bVar17;
  }
LAB_004fc7ac:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

