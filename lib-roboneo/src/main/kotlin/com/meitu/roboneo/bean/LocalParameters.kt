// Source decompiled: jadx_src/sources/com/meitu/roboneo/bean/LocalParameters.java
package com.meitu.roboneo.bean

import androidx.annotation.Keep
import com.google.gson.annotations.SerializedName

@Keep
data class LocalParameters(
    @SerializedName("image_url")
    val imageUrl: String = "",
    @SerializedName("face_id")
    val faceId: Int = 0
)
