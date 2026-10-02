// Source decompiled: com.meitu.vip.ModuleInitializer.kt
package com.meitu.vip

import android.content.Context
import com.meitu.vip.billing.BillingManager
import com.meitu.vip.manager.VipStatusManager
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

/**
 * Module Initializer & Entry Point for lib-billing
 * Khởi tạo hệ thống thanh toán Google Play Billing và trạng thái VIP.
 */
object BillingInitializer {
    @Volatile
    private var initialized = false

    fun init(context: Context) {
        if (initialized) return
        synchronized(this) {
            if (initialized) return
            val appContext = context.applicationContext
            // Khởi tạo BillingManager & VipStatusManager
            val billingManager = BillingManager.getInstance(appContext)
            VipStatusManager.getInstance(appContext)

            // Bắt đầu kết nối ngầm với Google Play Services
            CoroutineScope(Dispatchers.IO).launch {
                billingManager.startConnection()
            }
            initialized = true
        }
    }

    fun isReady(): Boolean = initialized
}

