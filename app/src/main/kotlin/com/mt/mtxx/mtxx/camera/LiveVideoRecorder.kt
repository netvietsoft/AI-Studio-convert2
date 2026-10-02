package com.mt.mtxx.mtxx.camera

import android.graphics.Bitmap
import android.graphics.Canvas
import android.graphics.Paint
import android.graphics.Rect
import android.media.MediaCodec
import android.media.MediaCodecInfo
import android.media.MediaFormat
import android.media.MediaMuxer
import android.util.Log
import android.view.Surface
import java.io.File

/**
 * Trình ghi hình Video phần cứng thời gian thực (Hardware Live Video Recorder).
 * Mã hóa trực tiếp luồng khung hình đã qua bộ lọc C++ Beauty Engine thành video MP4 chuẩn (H.264/AVC).
 */
class LiveVideoRecorder(
    private val width: Int = 720,
    private val height: Int = 1280,
    private val frameRate: Int = 30,
    private val bitRate: Int = 5_000_000
) {
    private val TAG = "LiveVideoRecorder"
    private var mediaCodec: MediaCodec? = null
    private var mediaMuxer: MediaMuxer? = null
    private var inputSurface: Surface? = null
    private var trackIndex = -1
    private var isMuxerStarted = false
    private var isRecording = false
    private var frameCount = 0L
    private val bufferInfo = MediaCodec.BufferInfo()
    private var outputFile: File? = null

    val recordingActive: Boolean
        get() = isRecording

    fun startRecording(file: File): Boolean {
        try {
            outputFile = file
            frameCount = 0L
            trackIndex = -1
            isMuxerStarted = false

            val format = MediaFormat.createVideoFormat(MediaFormat.MIMETYPE_VIDEO_AVC, width, height).apply {
                setInteger(MediaFormat.KEY_COLOR_FORMAT, MediaCodecInfo.CodecCapabilities.COLOR_FormatSurface)
                setInteger(MediaFormat.KEY_BIT_RATE, bitRate)
                setInteger(MediaFormat.KEY_FRAME_RATE, frameRate)
                setInteger(MediaFormat.KEY_I_FRAME_INTERVAL, 1)
            }

            mediaCodec = MediaCodec.createEncoderByType(MediaFormat.MIMETYPE_VIDEO_AVC).apply {
                configure(format, null, null, MediaCodec.CONFIGURE_FLAG_ENCODE)
                inputSurface = createInputSurface()
                start()
            }

            mediaMuxer = MediaMuxer(file.absolutePath, MediaMuxer.OutputFormat.MUXER_OUTPUT_MPEG_4)
            isRecording = true
            Log.d(TAG, "Bắt đầu ghi video MP4 -> ${file.absolutePath}")
            return true
        } catch (e: Exception) {
            Log.e(TAG, "Lỗi khởi động ghi video: ${e.message}", e)
            release()
            return false
        }
    }

    fun encodeFrame(bitmap: Bitmap) {
        if (!isRecording) return
        val surface = inputSurface ?: return

        try {
            val canvas = surface.lockCanvas(null)
            val src = Rect(0, 0, bitmap.width, bitmap.height)
            val dst = Rect(0, 0, width, height)
            canvas.drawBitmap(bitmap, src, dst, Paint(Paint.FILTER_BITMAP_FLAG))
            surface.unlockCanvasAndPost(canvas)

            drainEncoder(false)
            frameCount++
        } catch (e: Exception) {
            Log.e(TAG, "Lỗi mã hóa frame video: ${e.message}")
        }
    }

    private fun drainEncoder(endOfStream: Boolean) {
        val codec = mediaCodec ?: return
        val muxer = mediaMuxer ?: return

        if (endOfStream) {
            try {
                codec.signalEndOfInputStream()
            } catch (e: Exception) {
                Log.e(TAG, "Lỗi gửi tín hiệu EOS: ${e.message}")
            }
        }

        val timeoutUs = 10000L
        while (true) {
            val outputBufferIndex = codec.dequeueOutputBuffer(bufferInfo, timeoutUs)
            if (outputBufferIndex == MediaCodec.INFO_TRY_AGAIN_LATER) {
                if (!endOfStream) break
            } else if (outputBufferIndex == MediaCodec.INFO_OUTPUT_FORMAT_CHANGED) {
                if (isMuxerStarted) {
                    Log.e(TAG, "Format thay đổi bất ngờ khi đã bắt đầu muxer")
                } else {
                    val newFormat = codec.outputFormat
                    trackIndex = muxer.addTrack(newFormat)
                    muxer.start()
                    isMuxerStarted = true
                }
            } else if (outputBufferIndex >= 0) {
                val encodedData = codec.getOutputBuffer(outputBufferIndex) ?: continue

                if ((bufferInfo.flags and MediaCodec.BUFFER_FLAG_CODEC_CONFIG) != 0) {
                    bufferInfo.size = 0
                }

                if (bufferInfo.size != 0) {
                    if (isMuxerStarted) {
                        encodedData.position(bufferInfo.offset)
                        encodedData.limit(bufferInfo.offset + bufferInfo.size)
                        muxer.writeSampleData(trackIndex, encodedData, bufferInfo)
                    }
                }

                codec.releaseOutputBuffer(outputBufferIndex, false)

                if ((bufferInfo.flags and MediaCodec.BUFFER_FLAG_END_OF_STREAM) != 0) {
                    break
                }
            }
        }
    }

    fun stopRecording(): File? {
        if (!isRecording) return null
        isRecording = false
        try {
            drainEncoder(true)
        } catch (e: Exception) {
            Log.e(TAG, "Lỗi xả bộ đệm EOS: ${e.message}")
        }
        val file = outputFile
        release()
        return file
    }

    private fun release() {
        try {
            mediaCodec?.stop()
            mediaCodec?.release()
        } catch (e: Exception) {
            Log.e(TAG, "Lỗi giải phóng mediaCodec: ${e.message}")
        }
        mediaCodec = null

        try {
            if (isMuxerStarted) {
                mediaMuxer?.stop()
            }
            mediaMuxer?.release()
        } catch (e: Exception) {
            Log.e(TAG, "Lỗi giải phóng mediaMuxer: ${e.message}")
        }
        mediaMuxer = null
        inputSurface?.release()
        inputSurface = null
        isMuxerStarted = false
        trackIndex = -1
    }
}
