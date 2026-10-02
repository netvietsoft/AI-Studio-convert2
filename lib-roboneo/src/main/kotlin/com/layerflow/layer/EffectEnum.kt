// Source decompiled: jadx_src/sources/com/layerflow/layer/EffectEnum.java
package com.layerflow.layer

import androidx.annotation.Keep
import com.layer.flow.LayerFlow

@Keep
enum class EffectEnum(
    val modular: String,
    val subModule: Long
) {
    AUTO_EMBELLISH(LayerFlow.LAYER_Auto, 120L);
}
