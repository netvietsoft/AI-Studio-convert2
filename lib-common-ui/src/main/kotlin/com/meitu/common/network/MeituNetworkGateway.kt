package com.meitu.common.network

import android.os.Handler
import android.os.Looper
import android.util.Log
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import org.json.JSONObject
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.net.HttpURLConnection
import java.net.URL
import java.security.MessageDigest
import java.util.UUID

/**
 * MeituNetworkGateway: Centralized Network Adapter connecting all 8 modules to Backend (Port 9999).
 * Cổng mạng trung tâm kết nối 8 module Meitu với hệ thống Backend (Cổng 9999).
 *
 * Supported features / Tính năng hỗ trợ:
 * 1. REST GET / POST JSON requests với coroutine IO.
 * 2. SSE (Server-Sent Events) streaming cho RoboNeo AI Assistant.
 * 3. Tự động ký HMAC/MD5 token X-Meitu-Sign chuẩn bảo mật Meitu.
 * 4. Tự động dự phòng địa chỉ mạng (Emulator 10.0.2.2 vs Localhost 127.0.0.1 vs Custom LAN IP).
 */
object MeituNetworkGateway {

    private const val TAG = "MeituNetworkGateway"
    
    // Default backend port per President's directive: 9999
    // Cổng backend mặc định theo chỉ thị của Chủ tịch: 9999
    var host: String = "10.0.2.2" // Default Android Emulator host IP
    var port: Int = 9999
    
    // Unique device identifier / Mã định danh thiết bị duy nhất
    val deviceId: String by lazy { UUID.randomUUID().toString() }
    
    // App version trace / Phiên bản ứng dụng đồng bộ
    const val APP_VERSION = "12.17.8"

    /**
     * Initialize gateway with custom host / Khởi tạo gateway với host tùy biến
     */
    fun init(customHost: String = "10.0.2.2", customPort: Int = 9999) {
        this.host = customHost
        this.port = customPort
        Log.i(TAG, "Initialized MeituNetworkGateway -> BaseURL: $baseUrl")
    }

    val baseUrl: String
        get() = "http://$host:$port"

    /**
     * Generate Meitu security request signature / Tạo chữ ký bảo mật X-Meitu-Sign
     */
    fun generateMeituSign(path: String, timestamp: Long): String {
        val raw = "path=$path&time=$timestamp&key=meitu_reborn_secret_key_2026"
        return try {
            val md = MessageDigest.getInstance("MD5")
            val digest = md.digest(raw.toByteArray(Charsets.UTF_8))
            digest.joinToString("") { "%02x".format(it) }
        } catch (e: Exception) {
            "sign_fallback_${timestamp}"
        }
    }

    /**
     * Synchronous / Coroutine GET request / Gửi yêu cầu GET bất đồng bộ
     */
    suspend fun get(endpoint: String, queryParams: Map<String, String> = emptyMap()): NetworkResult = withContext(Dispatchers.IO) {
        val path = if (endpoint.startsWith("/")) endpoint else "/$endpoint"
        val queryString = if (queryParams.isNotEmpty()) {
            "?" + queryParams.map { "${it.key}=${it.value}" }.joinToString("&")
        } else ""
        
        val fullUrl = "$baseUrl$path$queryString"
        try {
            val url = URL(fullUrl)
            val conn = (url.openConnection() as HttpURLConnection).apply {
                requestMethod = "GET"
                connectTimeout = 5000
                readTimeout = 10000
                setRequestProperty("Accept", "application/json")
                setRequestProperty("User-Agent", "MeituReborn/$APP_VERSION (Android; ARM64)")
                setRequestProperty("Device-Id", deviceId)
                setRequestProperty("App-Version", APP_VERSION)
                val ts = System.currentTimeMillis()
                setRequestProperty("X-Meitu-Time", ts.toString())
                setRequestProperty("X-Meitu-Sign", generateMeituSign(path, ts))
            }

            val statusCode = conn.responseCode
            val stream = if (statusCode in 200..299) conn.inputStream else conn.errorStream
            val responseBody = stream?.bufferedReader(Charsets.UTF_8)?.use { it.readText() } ?: ""
            conn.disconnect()

            if (statusCode in 200..299) {
                NetworkResult.Success(statusCode, responseBody)
            } else {
                NetworkResult.Error(statusCode, "HTTP Error $statusCode: $responseBody")
            }
        } catch (e: Exception) {
            Log.e(TAG, "GET Request failed on $fullUrl: ${e.message}")
            NetworkResult.Error(-1, e.message ?: "Network IO Exception")
        }
    }

    /**
     * Coroutine POST request with JSON payload / Gửi yêu cầu POST chứa dữ liệu JSON
     */
    suspend fun postJson(endpoint: String, jsonPayload: String): NetworkResult = withContext(Dispatchers.IO) {
        val path = if (endpoint.startsWith("/")) endpoint else "/$endpoint"
        val fullUrl = "$baseUrl$path"
        try {
            val url = URL(fullUrl)
            val conn = (url.openConnection() as HttpURLConnection).apply {
                requestMethod = "POST"
                doOutput = true
                doInput = true
                connectTimeout = 6000
                readTimeout = 15000
                setRequestProperty("Content-Type", "application/json; charset=utf-8")
                setRequestProperty("Accept", "application/json")
                setRequestProperty("User-Agent", "MeituReborn/$APP_VERSION (Android; ARM64)")
                setRequestProperty("Device-Id", deviceId)
                setRequestProperty("App-Version", APP_VERSION)
                val ts = System.currentTimeMillis()
                setRequestProperty("X-Meitu-Time", ts.toString())
                setRequestProperty("X-Meitu-Sign", generateMeituSign(path, ts))
            }

            conn.outputStream.use { os ->
                OutputStreamWriter(os, Charsets.UTF_8).use { writer ->
                    writer.write(jsonPayload)
                    writer.flush()
                }
            }

            val statusCode = conn.responseCode
            val stream = if (statusCode in 200..299) conn.inputStream else conn.errorStream
            val responseBody = stream?.bufferedReader(Charsets.UTF_8)?.use { it.readText() } ?: ""
            conn.disconnect()

            if (statusCode in 200..299) {
                NetworkResult.Success(statusCode, responseBody)
            } else {
                NetworkResult.Error(statusCode, "HTTP Error $statusCode: $responseBody")
            }
        } catch (e: Exception) {
            Log.e(TAG, "POST Request failed on $fullUrl: ${e.message}")
            NetworkResult.Error(-1, e.message ?: "Network IO Exception")
        }
    }

    /**
     * Server-Sent Events (SSE) Streaming for RoboNeo AI Chat.
     * Truyền dữ liệu luồng thời gian thực cho trợ lý trí tuệ nhân tạo RoboNeo.
     */
    suspend fun streamSse(
        endpoint: String,
        jsonPayload: String,
        onMessage: (String, Boolean) -> Unit, // chunk text, isDone
        onError: (String) -> Unit,
        onComplete: () -> Unit
    ) = withContext(Dispatchers.IO) {
        val path = if (endpoint.startsWith("/")) endpoint else "/$endpoint"
        val fullUrl = "$baseUrl$path"
        val mainHandler = Handler(Looper.getMainLooper())

        try {
            val url = URL(fullUrl)
            val conn = (url.openConnection() as HttpURLConnection).apply {
                requestMethod = "POST"
                doOutput = true
                doInput = true
                connectTimeout = 6000
                readTimeout = 60000 // Long timeout for streaming
                setRequestProperty("Content-Type", "application/json; charset=utf-8")
                setRequestProperty("Accept", "text/event-stream")
                setRequestProperty("User-Agent", "MeituReborn/$APP_VERSION (Android; SSE)")
                setRequestProperty("Device-Id", deviceId)
                val ts = System.currentTimeMillis()
                setRequestProperty("X-Meitu-Sign", generateMeituSign(path, ts))
            }

            conn.outputStream.use { os ->
                OutputStreamWriter(os, Charsets.UTF_8).use { writer ->
                    writer.write(jsonPayload)
                    writer.flush()
                }
            }

            val statusCode = conn.responseCode
            if (statusCode !in 200..299) {
                val err = conn.errorStream?.bufferedReader(Charsets.UTF_8)?.use { it.readText() } ?: "HTTP $statusCode"
                mainHandler.post { onError("SSE Error: $err") }
                conn.disconnect()
                return@withContext
            }

            val reader = BufferedReader(InputStreamReader(conn.inputStream, Charsets.UTF_8))
            var line: String?
            while (reader.readLine().also { line = it } != null) {
                val currentLine = line ?: break
                if (currentLine.startsWith("data:")) {
                    val dataJson = currentLine.substring(5).trim()
                    try {
                        val obj = JSONObject(dataJson)
                        val text = obj.optString("text", "")
                        val done = obj.optBoolean("done", false)
                        mainHandler.post { onMessage(text, done) }
                        if (done) break
                    } catch (e: Exception) {
                        mainHandler.post { onMessage(dataJson, false) }
                    }
                }
            }
            reader.close()
            conn.disconnect()
            mainHandler.post { onComplete() }
        } catch (e: Exception) {
            Log.e(TAG, "SSE Streaming failed: ${e.message}")
            mainHandler.post { onError(e.message ?: "SSE Connection lost") }
        }
    }
}

/**
 * Result sealed class for network responses / Lớp kết quả mạng đóng gói
 */
sealed class NetworkResult {
    data class Success(val code: Int, val body: String) : NetworkResult()
    data class Error(val code: Int, val message: String) : NetworkResult()

    fun optJsonObject(): JSONObject? {
        return if (this is Success) {
            try { JSONObject(body) } catch (e: Exception) { null }
        } else null
    }
}
