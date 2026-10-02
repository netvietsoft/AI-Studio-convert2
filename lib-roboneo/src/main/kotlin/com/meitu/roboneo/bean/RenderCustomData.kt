package com.meitu.roboneo.bean

/**
 * RenderCustomData: Tham số tùy biến kết xuất đồ họa phục vụ layer render.
 * Custom rendering parameters passed to native LayerFlow engine.
 */
data class RenderCustomData(
    val customKey: String,
    val floatParams: FloatArray = floatArrayOf(),
    val intParams: IntArray = intArrayOf(),
    val stringParams: Array<String> = emptyArray()
) {
    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false
        other as RenderCustomData
        return customKey == other.customKey
    }

    override fun hashCode(): Int {
        return customKey.hashCode()
    }
}
