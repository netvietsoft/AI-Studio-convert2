package com.meitu.labdeviceinfo

import androidx.annotation.Keep
import java.io.Serializable

// SOURCE: com/meitu/labdeviceinfo/LabDeviceModel.java (jadx · v1.5.0 · classes15.dex)
@Keep
class LabDeviceModel : Serializable {
    var apuVersion: String? = null
    var clDeviceName: String? = null
    var clDeviceVersion: String? = null
    var clDriverVersion: String? = null
    var clSupportFp16: Boolean = false
    var cpuFrequency: Long = 0L
    var cpuGrade: Int = 0
    var cpuPolitic: Int = 0
    var cpuRender: String? = null
    var cpuSoftwareVersion: String? = null
    var cpuUarchName: String? = null
    var cpuVendor: String? = null
    var deviceInfoVersion: String? = null
    var gpuGetVersion: String? = null
    var gpuGrade: Int = 0
    var gpuRender: String? = null
    var gpuShadingLanguageVersion: String? = null
    var gpuSupportBit: Int = 0
    var gpuVendor: String? = null
    var isSupportDotprod: Boolean = false
    var isSupportFp16: Boolean = false
    var isSupportNpu: Boolean = false
    var memAvailable: Long = 0L
    var memTotal: Long = 0L
    var mobileExtensions: String? = null
    var mobile_type: String? = null
    var mobile_vendor: String? = null
    var npuDeviceVersion: String? = null

    companion object {
        init {
            try {
                System.loadLibrary("labdeviceinfo")
            } catch (e: Throwable) {}
        }

        @JvmStatic
        fun createDeviceModel(): LabDeviceModel {
            return try {
                nativeCreateDeviceModel()
            } catch (e: Throwable) {
                LabDeviceModel()
            }
        }

        @JvmStatic
        external fun nativeCreateDeviceModel(): LabDeviceModel
    }
}
