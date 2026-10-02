package com.meitu.common.ui.components

import android.app.Dialog
import android.content.Context
import android.graphics.Color
import android.graphics.drawable.ColorDrawable
import android.os.Bundle
import android.view.Window
import android.widget.ProgressBar
import com.meitu.common.ui.theme.MeituColors

/**
 * Hộp thoại Loading hiển thị xoay tròn mượt mà cho các tác vụ nền.
 */
class LoadingDialog(context: Context) : Dialog(context) {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        requestWindowFeature(Window.FEATURE_NO_TITLE)
        window?.setBackgroundDrawable(ColorDrawable(Color.TRANSPARENT))
        setCancelable(false)

        val progressBar = ProgressBar(context).apply {
            indeterminateDrawable?.setTint(MeituColors.PrimaryPink)
        }
        setContentView(progressBar)
    }
}
