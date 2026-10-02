// Source decompiled: jadx_src/sources/com/layer/flow/LayerFlow.java
package com.layer.flow

import androidx.annotation.Keep
import com.meitu.core.MeituNativeLoader

@Keep
open class LayerFlow {
    companion object {
        const val BLKID_DOWNLOAD_PREPARE_RESULT: Byte = 1
        const val BLKID_EXEC_THEN_WAIT: Byte = 2
        const val BLKID_RENDER_CREATIVE_AR_IDX: Byte = 4
        const val BLKID_RENDER_CREATIVE_DO_AIGC: Byte = 3
        const val BLKID_TYPE_START: Byte = 0
        const val BLKID_TYPE_STEP: Byte = 1

        const val CATEGORY__MEIRONG_MAKEUP_LIP: Long = 4001L
        const val CATEGORY__MEIRONG_MAKEUP_LIP_LIP: Long = 4001000L

        const val CREATIVE_AIGC_RESULT_TYPE_NORMAL: Int = 0
        const val CREATIVE_AIGC_RESULT_TYPE_PRE_CUTOUT: Int = 2
        const val CREATIVE_AIGC_RESULT_TYPE_STICKER: Int = 1

        const val LAYER_AKNE: String = "203"
        const val LAYER_AUTOMOSAIC: String = "automosaic"
        const val LAYER_AUTO_COLOR_CORRECT: String = "auto_color_correct"
        const val LAYER_AUTO_DERMABRASION: String = "99211"
        const val LAYER_AUTO_SLIM: String = "99204"
        const val LAYER_AUTO_WRINKLE_CLEAN: String = "99207"
        const val LAYER_Auto: String = "auto"
        const val LAYER_Auto_Brush: String = "autobrush"
        const val LAYER_BODY_SHAPE: String = "215"
        const val LAYER_BORDERLESS_PUZZLE: String = "borderlessPuzzle"
        const val LAYER_Background: String = "background"
        const val LAYER_Blur: String = "blur"
        const val LAYER_Compare: String = "compare"
        const val LAYER_Creative: String = "creative"
        const val LAYER_DENSE_HAIR: String = "230"
        const val LAYER_DERMABRASION: String = "211"
        const val LAYER_EYE: String = "223"
        const val LAYER_Edit: String = "edit"
        const val LAYER_Enhance: String = "enhance"
        const val LAYER_FACE_FULL: String = "220"
        const val LAYER_FACE_REMOLD: String = "213"
        const val LAYER_FIX_TEETH: String = "218"
        const val LAYER_Frame: String = "frame"
        const val LAYER_HEAD_SCALE: String = "217"
        const val LAYER_Live_Sticker: String = "live_sticker"
        const val LAYER_MAKEUP: String = "400"
        const val LAYER_MAKEUP_BAG: String = "makeupbag"
        const val LAYER_MATT: String = "224"
        const val LAYER_Mark: String = "mark"
        const val LAYER_ONE_CLICK_BEAUTY: String = "201"
        const val LAYER_Origin: String = "origin"
        const val LAYER_Realtime: String = "filter"
        const val LAYER_SKIN_WHITEN: String = "212"
        const val LAYER_SLIMMING: String = "204"
        const val LAYER_SPECIAL_EFFECT: String = "special_effect"
        const val LAYER_Sticker: String = "sticker"
        const val LAYER_Text: String = "text"
        const val LAYER_WAKE_SKIN: String = "222"
        const val LAYER_WRINKLE_CLEAN: String = "207"

        init {
            try {
                MeituNativeLoader.loadLibrary("LayerFlow")
            } catch (t: Throwable) {
                t.printStackTrace()
            }
        }
    }

    object ErrorCodes {
        const val GenericPlugin: Int = 50001
        const val JSON: Int = 10001
        const val MaterialDownloader: Int = 30001
        const val OK: Int = 1
        const val OutputImage: Int = 60001
        const val PrepareManager: Int = 20001
        const val Render: Int = 40001
        const val UNKNOWN: Int = 0
        const val UserCancel: Int = 10000
    }
}
