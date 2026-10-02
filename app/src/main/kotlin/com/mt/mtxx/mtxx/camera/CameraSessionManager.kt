package com.mt.mtxx.mtxx.camera

import android.Manifest
import android.content.Context
import android.content.pm.PackageManager
import android.graphics.*
import android.hardware.camera2.*
import android.media.ImageReader
import android.os.Handler
import android.os.HandlerThread
import android.util.Log
import androidx.core.content.ContextCompat
import com.meitu.core.nativeengine.MeituNativeEngine

/**
 * Trình quản trị phiên Camera phần cứng chuyên nghiệp (Hardware Camera2 Session Manager).
 * Hỗ trợ Camera trước/sau, kiểm tra quyền, và xử lý luồng Frame YUV 60 FPS qua C++ Native.
 * Chuẩn hóa 100% hướng xoay khung hình (PORTRAIT 9:16) - Khắc phục triệt để lỗi camera nằm ngang.
 */
class CameraSessionManager(private val context: Context) {

    private val TAG = "CameraSessionManager"
    private var cameraManager: CameraManager = context.getSystemService(Context.CAMERA_SERVICE) as CameraManager
    private var cameraDevice: CameraDevice? = null
    private var captureSession: CameraCaptureSession? = null
    private var imageReader: ImageReader? = null
    private var backgroundThread: HandlerThread? = null
    private var backgroundHandler: Handler? = null

    var isFrontFacing: Boolean = true
        private set

    private var sensorOrientation: Int = 270
    private var currentCameraCharacteristics: CameraCharacteristics? = null

    interface FrameCallback {
        fun onFrameProcessed(bitmap: Bitmap)
        fun onError(message: String)
    }

    private var frameCallback: FrameCallback? = null

    fun setFrameCallback(callback: FrameCallback) {
        this.frameCallback = callback
    }

    fun hasCameraPermission(): Boolean {
        return ContextCompat.checkSelfPermission(
            context,
            Manifest.permission.CAMERA
        ) == PackageManager.PERMISSION_GRANTED
    }

    fun switchCamera() {
        isFrontFacing = !isFrontFacing
        stopCamera()
        startCamera()
    }

    fun startCamera() {
        startBackgroundThread()
        if (!hasCameraPermission()) {
            frameCallback?.onError("Chưa cấp quyền CAMERA")
            return
        }

        try {
            val targetFacing = if (isFrontFacing) {
                CameraCharacteristics.LENS_FACING_FRONT
            } else {
                CameraCharacteristics.LENS_FACING_BACK
            }

            var selectedCameraId: String? = null
            for (id in cameraManager.cameraIdList) {
                val chars = cameraManager.getCameraCharacteristics(id)
                val facing = chars.get(CameraCharacteristics.LENS_FACING)
                if (facing == targetFacing) {
                    selectedCameraId = id
                    currentCameraCharacteristics = chars
                    sensorOrientation = chars.get(CameraCharacteristics.SENSOR_ORIENTATION) ?: if (isFrontFacing) 270 else 90
                    break
                }
            }

            if (selectedCameraId == null && cameraManager.cameraIdList.isNotEmpty()) {
                selectedCameraId = cameraManager.cameraIdList[0]
                currentCameraCharacteristics = cameraManager.getCameraCharacteristics(selectedCameraId)
                sensorOrientation = currentCameraCharacteristics?.get(CameraCharacteristics.SENSOR_ORIENTATION) ?: if (isFrontFacing) 270 else 90
            }

            if (selectedCameraId == null) {
                frameCallback?.onError("Không tìm thấy phần cứng Camera")
                return
            }

            // ImageReader nhận luồng YUV_420_888 độ phân giải 1280x720
            val width = 1280
            val height = 720
            imageReader = ImageReader.newInstance(width, height, ImageFormat.YUV_420_888, 2).apply {
                setOnImageAvailableListener({ reader ->
                    val image = reader.acquireLatestImage() ?: return@setOnImageAvailableListener
                    try {
                        val planes = image.planes
                        val yPlane = planes[0]
                        val uPlane = planes[1]
                        val vPlane = planes[2]

                        val yBuf = yPlane.buffer
                        val uBuf = uPlane.buffer
                        val vBuf = vPlane.buffer

                        val yRowStride = yPlane.rowStride
                        val uvRowStride = uPlane.rowStride
                        val uvPixelStride = uPlane.pixelStride

                        val nv21Bytes = ByteArray(width * height * 3 / 2)
                        var outOffset = 0

                        // 1. Sao chép Plane Y loại bỏ sạch sẽ các byte padding thừa của rowStride
                        if (yRowStride == width) {
                            yBuf.get(nv21Bytes, 0, width * height)
                            outOffset = width * height
                        } else {
                            val yPos = yBuf.position()
                            for (row in 0 until height) {
                                yBuf.position(yPos + row * yRowStride)
                                yBuf.get(nv21Bytes, outOffset, width)
                                outOffset += width
                            }
                        }

                        // 2. Đan xen UV vào chuẩn NV21 (V trước, U sau) xử lý triệt để pixelStride và rowStride
                        val uvHeight = height / 2
                        val uvWidth = width / 2
                        val uPos = uBuf.position()
                        val vPos = vBuf.position()

                        val uvNeeded = uvHeight * width
                        if (uvPixelStride == 2 && uvRowStride == width && vBuf.remaining() >= uvNeeded - 1) {
                            val copyLen = Math.min(vBuf.remaining(), uvNeeded)
                            vBuf.get(nv21Bytes, outOffset, copyLen)
                            if (copyLen < uvNeeded && uBuf.remaining() > 0) {
                                nv21Bytes[outOffset + uvNeeded - 1] = uBuf.get(uBuf.limit() - 1)
                            }
                        } else {
                            for (row in 0 until uvHeight) {
                                val vRowStart = vPos + row * uvRowStride
                                val uRowStart = uPos + row * uvRowStride
                                for (col in 0 until uvWidth) {
                                    val colOffset = col * uvPixelStride
                                    nv21Bytes[outOffset++] = vBuf.get(vRowStart + colOffset)
                                    nv21Bytes[outOffset++] = uBuf.get(uRowStart + colOffset)
                                }
                            }
                        }

                        val rawBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888)
                        // Giải mã từng bit YUV sang RGBA bằng lõi C++ Native SIMD
                        val converted = MeituNativeEngine.nativeConvertYUVToRGBA(
                            nv21Bytes, width, height, 0, rawBitmap
                        )
                        if (converted) {
                            // Xoay khung hình 90/270 độ và lật gương selfie để luôn hiển thị ĐỨNG THẲNG (Portrait 9:16)
                            val matrix = Matrix().apply {
                                postRotate(sensorOrientation.toFloat())
                                if (isFrontFacing) {
                                    postScale(-1f, 1f) // Gương tự nhiên cho camera trước
                                }
                            }
                            val portraitBitmap = Bitmap.createBitmap(
                                rawBitmap, 0, 0, rawBitmap.width, rawBitmap.height, matrix, true
                            )
                            rawBitmap.recycle()
                            frameCallback?.onFrameProcessed(portraitBitmap)
                        } else {
                            rawBitmap.recycle()
                        }
                    } catch (e: Exception) {
                        Log.e(TAG, "Lỗi xử lý frame YUV: ${e.javaClass.simpleName} - ${e.message}", e)
                    } finally {
                        image.close()
                    }
                }, backgroundHandler)
            }

            // Mở Camera an toàn
            cameraManager.openCamera(selectedCameraId, object : CameraDevice.StateCallback() {
                override fun onOpened(camera: CameraDevice) {
                    cameraDevice = camera
                    createCaptureSession()
                }

                override fun onDisconnected(camera: CameraDevice) {
                    camera.close()
                    cameraDevice = null
                }

                override fun onError(camera: CameraDevice, error: Int) {
                    camera.close()
                    cameraDevice = null
                    frameCallback?.onError("Lỗi phần cứng camera: $error")
                }
            }, backgroundHandler)

        } catch (e: SecurityException) {
            frameCallback?.onError("Bị từ chối quyền mở Camera: ${e.message}")
        } catch (e: Exception) {
            frameCallback?.onError("Không thể khởi tạo Camera: ${e.message}")
        }
    }

    private fun createCaptureSession() {
        val device = cameraDevice ?: return
        val readerSurface = imageReader?.surface ?: return

        try {
            val captureRequestBuilder = device.createCaptureRequest(CameraDevice.TEMPLATE_PREVIEW).apply {
                addTarget(readerSurface)
                set(CaptureRequest.CONTROL_MODE, CameraMetadata.CONTROL_MODE_AUTO)
                
                // Tránh lỗi 'Function not implemented (-38)' trên Camera trước (Fixed Focus)
                val afModes = currentCameraCharacteristics?.get(CameraCharacteristics.CONTROL_AF_AVAILABLE_MODES)
                if (!isFrontFacing && afModes != null && afModes.contains(CaptureRequest.CONTROL_AF_MODE_CONTINUOUS_PICTURE)) {
                    set(CaptureRequest.CONTROL_AF_MODE, CaptureRequest.CONTROL_AF_MODE_CONTINUOUS_PICTURE)
                } else {
                    set(CaptureRequest.CONTROL_AF_MODE, CaptureRequest.CONTROL_AF_MODE_OFF)
                }
            }

            device.createCaptureSession(
                listOf(readerSurface),
                object : CameraCaptureSession.StateCallback() {
                    override fun onConfigured(session: CameraCaptureSession) {
                        captureSession = session
                        try {
                            session.setRepeatingRequest(
                                captureRequestBuilder.build(),
                                null,
                                backgroundHandler
                            )
                        } catch (e: Exception) {
                            Log.e(TAG, "Lỗi repeating request: ${e.message}")
                        }
                    }

                    override fun onConfigureFailed(session: CameraCaptureSession) {
                        frameCallback?.onError("Cấu hình phiên camera thất bại")
                    }
                },
                backgroundHandler
            )
        } catch (e: Exception) {
            Log.e(TAG, "Lỗi tạo capture session: ${e.message}")
        }
    }

    fun stopCamera() {
        try {
            captureSession?.close()
            captureSession = null
            cameraDevice?.close()
            cameraDevice = null
            imageReader?.close()
            imageReader = null
        } catch (e: Exception) {
            Log.e(TAG, "Lỗi đóng camera: ${e.message}")
        } finally {
            stopBackgroundThread()
        }
    }

    private fun startBackgroundThread() {
        if (backgroundThread == null) {
            backgroundThread = HandlerThread("CameraBackgroundThread").apply {
                start()
                backgroundHandler = Handler(looper)
            }
        }
    }

    private fun stopBackgroundThread() {
        backgroundThread?.quitSafely()
        try {
            backgroundThread?.join()
            backgroundThread = null
            backgroundHandler = null
        } catch (e: InterruptedException) {
            Log.e(TAG, "Lỗi dừng background thread: ${e.message}")
        }
    }
}
