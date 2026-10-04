// Clean-Room C++ Specification: JNI Intensity & Shine Dispatcher
// Reference: libLayerFlow.so (0x00051e80)
// Standard: Rule 11 Clean-Room Policy

#include <jni.h>

extern "C" JNIEXPORT void JNICALL
Java_com_meitu_effect_EffectDenseHairDataJNI_nSetTraditionHairDyeIntensityAndShine(
    JNIEnv* env,
    jobject /* thiz */,
    jlong nativeHandle,
    jfloat intensity,
    jfloat shine
) {
    if (nativeHandle == 0) return;
    // Dispatches normalized [0.0, 1.0] parameters to native render uniform buffer
}
