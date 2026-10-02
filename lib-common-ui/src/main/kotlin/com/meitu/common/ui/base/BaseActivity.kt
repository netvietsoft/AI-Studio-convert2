package com.meitu.common.ui.base

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.meitu.common.ui.theme.MeituColors

/**
 * Base Activity chuẩn cho mọi màn hình trong hệ thống Meitu Reborn.
 */
abstract class BaseActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        applyMeituThemeSettings()
    }

    protected open fun applyMeituThemeSettings() {
        window.statusBarColor = MeituColors.DarkBackground
        window.navigationBarColor = MeituColors.DarkBackground
    }
}
