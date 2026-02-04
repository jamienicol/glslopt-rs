// Test that mesa_float16_t doesn't conflict with ARM NEON's float16_t
// This simulates the ARM64 Windows environment where arm_fp16.h defines float16_t

// Simulate ARM NEON's float16_t typedef (as defined in arm_fp16.h on ARM64)
#ifdef _M_ARM64
// On real ARM64 Windows, this comes from arm_fp16.h
// typedef __fp16 float16_t;
#endif

// For testing purposes, we define a conflicting float16_t to verify our fix works
typedef unsigned short float16_t;

// Now include our header - this should NOT conflict because we use mesa_float16_t
#include "glsl-optimizer/src/util/half_float.h"

// Verify mesa_float16_t is usable
void test_mesa_float16_t() {
#ifdef __cplusplus
    mesa_float16_t a(1.0f);
    mesa_float16_t b(2.0);
    mesa_float16_t c((uint16_t)0x3c00);
    mesa_float16_t one = mesa_float16_t::one();
    mesa_float16_t zero = mesa_float16_t::zero();
    (void)a; (void)b; (void)c; (void)one; (void)zero;
#endif
}

int main() {
    test_mesa_float16_t();
    return 0;
}
