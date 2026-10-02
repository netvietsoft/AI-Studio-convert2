// Source decompiled & fortified: com.mt.mtxx.mtxx.MtxxApplication.kt
package com.mt.mtxx.mtxx

import android.app.Application
import android.util.Log
import com.meitu.common.network.MeituNetworkGateway
import com.meitu.core.MeituNativeLoader
import com.meitu.common.ui.CommonUiInitializer
import com.meitu.manis.AiEngineInitializer
import com.meitu.edit.PhotoEditorInitializer
import com.meitu.roboneo.RoboneoInitializer
import com.meitu.videoedit.VideoEngineInitializer
import com.meitu.vip.BillingInitializer
import com.mt.mtxx.mtxx.database.AppDatabase
import java.io.PrintWriter
import java.io.StringWriter

/**
 * Lớp ứng dụng trung tâm (Application Shell) của Meitu Reborn.
 * Điều phối khởi tạo 8 modules kiến trúc, native libraries và cơ sở dữ liệu.
 * Tích hợp hệ thống bảo vệ Crash-Guard toàn diện và Safe Native Lazy-Loading.
 *
 * Central Application Shell of Meitu Reborn with Crash-Guard Protection.
 */
class MtxxApplication : Application() {

    override fun onCreate() {
        super.onCreate()
        Log.i(TAG, "MtxxApplication initializing with Crash-Guard protection...")

        // 0. Khởi tạo cơ sở dữ liệu SQLite AppDatabase trước tiên
        try {
            appDb = AppDatabase.getInstance(this)
            Log.i(TAG, "Module 8 (:app): SQLite database ready.")
        } catch (t: Throwable) {
            Log.e(TAG, "Failed initializing AppDatabase: ${t.message}")
        }

        // 1. Cài đặt bộ giám sát ngoại lệ toàn cục (Global Crash Handler)
        setupGlobalCrashHandler()

        // 2. Khởi tạo Tầng Mạng Trung Tâm kết nối Backend Cổng 9999 (Dynamic Host Detection)
        try {
            val prefs = getSharedPreferences("meitu_config", android.content.Context.MODE_PRIVATE)
            val customHost = prefs.getString("backend_host", null)
            val isEmulator = android.os.Build.FINGERPRINT.contains("generic") ||
                             android.os.Build.HARDWARE.contains("goldfish") ||
                             android.os.Build.HARDWARE.contains("ranchu")
            val host = when {
                !customHost.isNullOrBlank() -> customHost
                isEmulator -> "10.0.2.2"
                else -> "127.0.0.1"
            }
            MeituNetworkGateway.init(customHost = host, customPort = 9999)
            Log.i(TAG, "Network Gateway active -> Host: $host:9999, BaseURL: ${MeituNetworkGateway.baseUrl}")
        } catch (t: Throwable) {
            Log.e(TAG, "Failed initializing Network Gateway: ${t.message}")
        }

        // 3. Module 1: Safe Native Bootstrap (Chỉ nạp c++_shared, các lib khác Lazy Load khi dùng)
        try {
            MeituNativeLoader.loadBootstrapLibraries()
            Log.i(TAG, "Module 1 (:lib-core-graphics): Safe Native bootstrap ready.")
        } catch (t: Throwable) {
            Log.e(TAG, "Failed loading safe native bootstrap: ${t.message}")
        }

        // 4. Module 2: Common UI
        try {
            CommonUiInitializer.isReady()
            Log.i(TAG, "Module 2 (:lib-common-ui): Initialized.")
        } catch (t: Throwable) {
            Log.e(TAG, "Module 2 error: ${t.message}")
        }

        // 5. Module 3: AI Engine
        try {
            AiEngineInitializer.isReady()
            Log.i(TAG, "Module 3 (:lib-ai-engine): Initialized.")
        } catch (t: Throwable) {
            Log.e(TAG, "Module 3 error: ${t.message}")
        }

        // 6. Module 4: Photo Editor
        try {
            PhotoEditorInitializer.isReady()
            Log.i(TAG, "Module 4 (:lib-photo-editor): Initialized.")
        } catch (t: Throwable) {
            Log.e(TAG, "Module 4 error: ${t.message}")
        }

        // 7. Module 5: RoboNeo LayerFlow Engine
        try {
            RoboneoInitializer.isReady()
            Log.i(TAG, "Module 5 (:lib-roboneo): Initialized.")
        } catch (t: Throwable) {
            Log.e(TAG, "Module 5 error: ${t.message}")
        }

        // 8. Module 6: Video Engine & FFmpeg PVGCodec
        try {
            VideoEngineInitializer.isReady()
            Log.i(TAG, "Module 6 (:lib-video-engine): Initialized.")
        } catch (t: Throwable) {
            Log.e(TAG, "Module 6 error: ${t.message}")
        }

        // 9. Module 7: Google Play Billing & VIP Manager
        try {
            BillingInitializer.init(this)
            Log.i(TAG, "Module 7 (:lib-billing): Initialized.")
        } catch (t: Throwable) {
            Log.e(TAG, "Module 7 error: ${t.message}")
        }

        // 10. Module 8: App SQLite Database 92 Tables
        try {
            AppDatabase.getInstance(this)
            Log.i(TAG, "Module 8 (:app): SQLite database ready.")
        } catch (t: Throwable) {
            Log.e(TAG, "Module 8 error: ${t.message}")
        }

        Log.i(TAG, "MtxxApplication successfully initialized all 8 modules safely.")
    }

    private fun setupGlobalCrashHandler() {
        val defaultHandler = Thread.getDefaultUncaughtExceptionHandler()
        Thread.setDefaultUncaughtExceptionHandler { thread, throwable ->
            val sw = StringWriter()
            throwable.printStackTrace(PrintWriter(sw))
            val stackTrace = sw.toString()
            Log.e(TAG, "FATAL UNCAUGHT EXCEPTION in Thread [${thread.name}]: $stackTrace")

            try {
                appDb?.insertCrashLog(
                        tag = "FATAL_${thread.name}",
                        message = throwable.message ?: "Unknown crash",
                        stackTrace = stackTrace
                    )
            } catch (t: Throwable) {
                Log.e(TAG, "Failed to persist crash to SQLite: ${t.message}")
            }

            defaultHandler?.uncaughtException(thread, throwable)
        }
    }

    companion object {
        private const val TAG = "MtxxApplication"
        @JvmStatic
        var appDb: AppDatabase? = null
            internal set
    }
}
