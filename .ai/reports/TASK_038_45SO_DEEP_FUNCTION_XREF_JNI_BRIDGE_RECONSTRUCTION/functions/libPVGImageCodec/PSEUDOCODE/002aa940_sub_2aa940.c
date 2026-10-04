// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x2aa940
// Recovered Name: sub_2aa940
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2aa940 | Size: 4396 bytes | SHA256: f9288abc9adbf5c27b3e30b16feebe8209340ce85a1001d77f39479799a2d6ab
// Callers: 1 | Callees: 15 | Imports: 11

// Calls external APIs: _ZN10rayon_core19current_num_threads17h650aefbb84434260E, _ZN10rayon_core8registry8Registry26notify_worker_latch_is_set17h1d40d5f9658ef587E, _ZN3std3sys4unix5locks11futex_mutex5Mutex14lock_contended17hecdef02271eb1c4dE, _ZN3std3sys4unix5locks11futex_mutex5Mutex4wake17hfb9e1997a40c73cdE, _ZN3std4sync7condvar7Condvar10notify_all17h03fffde6c6d65f26E, _ZN3std9panicking11panic_count17is_zero_slow_path17had639ca7e151444dE, _ZN3std9panicking3try7cleanup17h8c569baa2145594dE, _ZN4core6result13unwrap_failed17h991d2f44e0c0e2b1E, _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE, _ZN4core9panicking5panic17haac685927c8c1edbE, __rust_dealloc
// Strings referenced:
//   "called `Result::unwrap()` on an `Err` value/Users/lyc/.cargo/registry/src/github.com-1ecc6299db9ec823/rayon-core-1.11.0/src/latch.rs/Users/lyc/.cargo/registry/src/github.com-1ecc6299db9ec823/imagequant-4.2.0/src/blur.rs"
//   "cannot access a Thread Local Storage value during or after destruction/rustc/d5a82bbd26e1ad8b7401f6a718a9c57c96905483/library/std/src/thread/local.rs"

void sub_2aa940(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 1099 instructions
    /* 0x2aa940 */ sub sp, sp, #0x30;
    /* 0x2aa944 */ stp x30, x21, [sp, #0x10];
    /* 0x2aa948 */ stp x20, x19, [sp, #0x20];
    /* 0x2aa94c */ mov x19, x0;
    /* 0x2aa950 */ mov w8, #1;
    /* 0x2aa954 */ ldaxr w9, [x19];
    /* 0x2aa958 */ cbnz w9, #0x2aa9c8;
    /* 0x2aa95c */ stxr w9, w8, [x19];
    /* 0x2aa960 */ cbnz w9, #0x2aa954;
    /* 0x2aa964 */ adrp x21, #0x4e5000;
    /* 0x2aa968 */ ldr x21, [x21, #0xbb8];
    _ZN3std4sync7condvar7Condvar10notify_all17h03fffde6c6d65f26E();
    return x0;
    _ZN3std3sys4unix5locks11futex_mutex5Mutex14lock_contended17hecdef02271eb1c4dE();
    _ZN3std9panicking11panic_count17is_zero_slow_path17had639ca7e151444dE();
    _ZN4core6result13unwrap_failed17h991d2f44e0c0e2b1E();
    _ZN3std9panicking11panic_count17is_zero_slow_path17had639ca7e151444dE();
    sub_2aa70c();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2aa7fc();
    sub_4bebfc();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2a8dc8();
    sub_2afd70();
    __rust_dealloc();
    sub_2aa940();
    return x0;
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    _ZN4core6result13unwrap_failed17h991d2f44e0c0e2b1E();
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    sub_2aa868();
    _ZN3std9panicking3try7cleanup17h8c569baa2145594dE();
    sub_2aa708();
    sub_4bebfc();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2a8dc8();
    sub_2afd70();
    __rust_dealloc();
    _ZN10rayon_core8registry8Registry26notify_worker_latch_is_set17h1d40d5f9658ef587E();
    sub_2bd458();
    return x0;
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    _ZN4core6result13unwrap_failed17h991d2f44e0c0e2b1E();
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    sub_2aa76c();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2aa868();
    _ZN3std9panicking3try7cleanup17h8c569baa2145594dE();
    sub_2aa708();
    sub_4bebfc();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2a8dc8();
    sub_2b02e0();
    __rust_dealloc();
    _ZN10rayon_core8registry8Registry26notify_worker_latch_is_set17h1d40d5f9658ef587E();
    sub_2bd458();
    return x0;
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    _ZN4core6result13unwrap_failed17h991d2f44e0c0e2b1E();
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    sub_2aa76c();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2aa868();
    _ZN3std9panicking3try7cleanup17h8c569baa2145594dE();
    sub_2aa708();
    sub_4bebfc();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    _ZN10rayon_core19current_num_threads17h650aefbb84434260E();
    sub_2a61e0();
    sub_2a8978();
    __rust_dealloc();
    _ZN10rayon_core8registry8Registry26notify_worker_latch_is_set17h1d40d5f9658ef587E();
    sub_2bd458();
    return x0;
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    sub_2aa76c();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2aa868();
    _ZN3std9panicking3try7cleanup17h8c569baa2145594dE();
    sub_2aa708();
    sub_4bebfc();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2bd8ec();
    __rust_dealloc();
    _ZN10rayon_core8registry8Registry26notify_worker_latch_is_set17h1d40d5f9658ef587E();
    sub_2bd458();
    return x0;
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    sub_2aa76c();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2aa868();
    _ZN3std9panicking3try7cleanup17h8c569baa2145594dE();
    sub_2aa708();
    sub_4bebfc();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2a8dc8();
    sub_2b0030();
    __rust_dealloc();
    sub_2aa940();
    return x0;
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    _ZN4core6result13unwrap_failed17h991d2f44e0c0e2b1E();
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    sub_2aa868();
    _ZN3std9panicking3try7cleanup17h8c569baa2145594dE();
    sub_2aa708();
    sub_4bebfc();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2a8dc8();
    sub_2b0030();
    __rust_dealloc();
    _ZN10rayon_core8registry8Registry26notify_worker_latch_is_set17h1d40d5f9658ef587E();
    sub_2bd458();
    return x0;
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    _ZN4core6result13unwrap_failed17h991d2f44e0c0e2b1E();
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    sub_2aa76c();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2aa868();
    _ZN3std9panicking3try7cleanup17h8c569baa2145594dE();
    sub_2aa708();
    sub_4bebfc();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
    sub_2a8dc8();
    sub_2b02e0();
    __rust_dealloc();
    sub_2aa940();
    return x0;
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    _ZN4core6result13unwrap_failed17h991d2f44e0c0e2b1E();
    _ZN4core9panicking5panic17haac685927c8c1edbE();
    sub_2aa868();
    _ZN3std9panicking3try7cleanup17h8c569baa2145594dE();
    sub_2aa708();
    sub_4bebfc();
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE();
}
