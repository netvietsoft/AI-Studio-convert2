package com.meitu.core

import android.util.Log

/**
 * Lớp cơ sở đảm bảo nạp thư viện nền tảng trước khi gọi các struct/class C++.
 * Nguồn: com.meitu.core.TypesBaseClass.java
 */
open class TypesBaseClass {

    companion object {
        private const val TAG = "TypesBaseClass"

        init {
            loadTypesLibrary()
        }

        @JvmStatic
        fun loadTypesLibrary() {
            try {
                MteApplication.loadLibrary()
                Log.i(TAG, "TypesBaseClass loaded native runtime successfully.")
            } catch (e: Exception) {
                Log.e(TAG, "Load types library error: ${e.message}", e)
            }
        }
    }
}
