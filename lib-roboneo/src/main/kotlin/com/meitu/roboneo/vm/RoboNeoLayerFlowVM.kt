package com.meitu.roboneo.vm

import com.meitu.roboneo.bean.LocalParameters
import com.meitu.roboneo.bean.LocalRenderCommonInfo
import com.meitu.roboneo.bean.RenderCustomData
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow

/**
 * RoboNeoLayerFlowVM: Điều khiển Canvas Đa Tầng tương tác LayerFlow và Sticker.
 * ViewModel controlling LayerFlow Multi-Layer Interactive Canvas & Sticker layout.
 */
class RoboNeoLayerFlowVM {

    private val _layers = MutableStateFlow<List<LayerItem>>(emptyList())
    val layers: StateFlow<List<LayerItem>> = _layers.asStateFlow()

    private val _selectedLayerId = MutableStateFlow<String?>(null)
    val selectedLayerId: StateFlow<String?> = _selectedLayerId.asStateFlow()

    private val _renderContext = MutableStateFlow(LocalRenderCommonInfo())
    val renderContext: StateFlow<LocalRenderCommonInfo> = _renderContext.asStateFlow()

    fun addStickerLayer(stickerAssetPath: String, initialX: Float = 0.5f, initialY: Float = 0.5f): String {
        val newLayer = LayerItem(
            layerId = "layer_sticker_" + System.currentTimeMillis(),
            type = LayerType.STICKER,
            assetPath = stickerAssetPath,
            posX = initialX,
            posY = initialY,
            scale = 1.0f,
            rotationDeg = 0.0f,
            alpha = 1.0f,
            blendMode = "NORMAL"
        )
        _layers.value = _layers.value + newLayer
        _selectedLayerId.value = newLayer.layerId
        return newLayer.layerId
    }

    fun addTextLayer(text: String, colorHex: String = "#FFFFFF"): String {
        val newLayer = LayerItem(
            layerId = "layer_text_" + System.currentTimeMillis(),
            type = LayerType.TEXT,
            text = text,
            textColorHex = colorHex,
            posX = 0.5f,
            posY = 0.5f,
            scale = 1.0f,
            rotationDeg = 0.0f,
            alpha = 1.0f,
            blendMode = "NORMAL"
        )
        _layers.value = _layers.value + newLayer
        _selectedLayerId.value = newLayer.layerId
        return newLayer.layerId
    }

    fun removeLayer(layerId: String) {
        _layers.value = _layers.value.filter { it.layerId != layerId }
        if (_selectedLayerId.value == layerId) {
            _selectedLayerId.value = _layers.value.lastOrNull()?.layerId
        }
    }

    fun updateLayerTransform(layerId: String, posX: Float, posY: Float, scale: Float, rotationDeg: Float) {
        _layers.value = _layers.value.map { layer ->
            if (layer.layerId == layerId) {
                layer.copy(posX = posX, posY = posY, scale = scale, rotationDeg = rotationDeg)
            } else layer
        }
    }

    fun selectLayer(layerId: String?) {
        _selectedLayerId.value = layerId
    }
}

data class LayerItem(
    val layerId: String,
    val type: LayerType,
    val assetPath: String = "",
    val text: String = "",
    val textColorHex: String = "#FFFFFF",
    val posX: Float = 0.5f,
    val posY: Float = 0.5f,
    val scale: Float = 1.0f,
    val rotationDeg: Float = 0.0f,
    val alpha: Float = 1.0f,
    val blendMode: String = "NORMAL"
)

enum class LayerType {
    BACKGROUND,
    IMAGE_FILTER,
    STICKER,
    TEXT,
    AI_AFFECT
}
