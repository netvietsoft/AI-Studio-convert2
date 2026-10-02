// Source decompiled: com.meitu.vip.dialog.XXVipDialogHelper.kt
package com.meitu.vip.dialog

import android.app.Activity
import android.app.Dialog
import android.graphics.Color
import android.graphics.Typeface
import android.graphics.drawable.ColorDrawable
import android.graphics.drawable.GradientDrawable
import android.view.Gravity
import android.view.ViewGroup
import android.view.Window
import android.widget.LinearLayout
import android.widget.ScrollView
import android.widget.TextView
import android.widget.Toast
import com.meitu.common.ui.theme.MeituColors
import com.meitu.vip.bean.VipBenefitItem
import com.meitu.vip.bean.VipSku
import com.meitu.vip.billing.BillingManager
import com.meitu.vip.manager.VipStatusManager
import com.meitu.vip.manager.VipTriggerManager
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

/**
 * Trình hỗ trợ hiển thị Dialog Paywall nâng cấp VIP Meitu.
 * Meitu VIP Paywall dialog builder and presentation coordinator.
 */
object XXVipDialogHelper {

    /**
     * Hiển thị Paywall Dialog theo kịch bản kích hoạt cụ thể.
     * Present Paywall Dialog tailored for the trigger scenario.
     */
    fun showPaywall(
        activity: Activity,
        scenario: VipTriggerManager.Scenario,
        onDismiss: (() -> Unit)? = null
    ) {
        if (activity.isFinishing || activity.isDestroyed) return

        val dialog = Dialog(activity)
        dialog.requestWindowFeature(Window.FEATURE_NO_TITLE)

        val context = activity
        val billingManager = BillingManager.getInstance(context)
        val vipStatusManager = VipStatusManager.getInstance(context)

        // Root container (Dark modal card)
        val rootLayout = LinearLayout(context).apply {
            orientation = LinearLayout.VERTICAL
            val density = context.resources.displayMetrics.density
            val pad = (20 * density).toInt()
            setPadding(pad, pad, pad, pad)

            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 48f
                setColor(MeituColors.DarkBackground)
            }
            background = bg
        }

        // Title Header
        val headerTitle = TextView(context).apply {
            text = "✨ Meitu VIP ✨"
            textSize = 22f
            setTextColor(MeituColors.PrimaryPink)
            gravity = Gravity.CENTER
            setTypeface(typeface, Typeface.BOLD)
        }
        rootLayout.addView(headerTitle)

        // Subtitle / Scenario message
        val scenarioSubtitle = TextView(context).apply {
            text = scenario.title
            textSize = 14f
            setTextColor(MeituColors.TextPrimary)
            gravity = Gravity.CENTER
            setPadding(0, 12, 0, 24)
        }
        rootLayout.addView(scenarioSubtitle)

        // Scrollview chứa danh sách quyền lợi và các gói
        val scrollView = ScrollView(context).apply {
            layoutParams = LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                (240 * context.resources.displayMetrics.density).toInt()
            )
        }
        val contentBox = LinearLayout(context).apply {
            orientation = LinearLayout.VERTICAL
        }

        // Quyền lợi nổi bật
        VipBenefitItem.DEFAULT_BENEFITS.take(4).forEach { benefit ->
            val itemTv = TextView(context).apply {
                text = "✓  ${benefit.title} - ${benefit.description}"
                textSize = 12f
                setTextColor(MeituColors.TextSecondary)
                setPadding(0, 8, 0, 8)
            }
            contentBox.addView(itemTv)
        }

        scrollView.addView(contentBox)
        rootLayout.addView(scrollView)

        // SKU selection: Gói năm dùng thử 3 ngày (Best Value)
        val selectedSku = VipSku.DEFAULT_CATALOG.firstOrNull { it.isBestValue } ?: VipSku.DEFAULT_CATALOG.first()

        val skuCard = LinearLayout(context).apply {
            orientation = LinearLayout.VERTICAL
            val density = context.resources.displayMetrics.density
            val pad = (12 * density).toInt()
            setPadding(pad, pad, pad, pad)
            val cardBg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 24f
                setColor(0xFF26262B.toInt())
            }
            background = cardBg
            val lp = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT)
            lp.topMargin = (16 * density).toInt()
            layoutParams = lp
        }

        val skuTitle = TextView(context).apply {
            text = "${selectedSku.title} • ${selectedSku.priceFormatted}/năm"
            textSize = 15f
            setTextColor(MeituColors.TextPrimary)
            setTypeface(typeface, Typeface.BOLD)
        }
        val skuDesc = TextView(context).apply {
            text = selectedSku.description
            textSize = 12f
            setTextColor(MeituColors.TextSecondary)
            setPadding(0, 4, 0, 0)
        }
        skuCard.addView(skuTitle)
        skuCard.addView(skuDesc)
        rootLayout.addView(skuCard)

        // CTA Button (Dùng thử miễn phí & Nâng cấp VIP)
        val btnSubscribe = TextView(context).apply {
            val density = context.resources.displayMetrics.density
            val lp = LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                (48 * density).toInt()
            )
            lp.topMargin = (16 * density).toInt()
            layoutParams = lp
            text = if (selectedSku.isTrial) "DÙNG THỬ 3 NGÀY MIỄN PHÍ" else "NÂNG CẤP VIP NGAY"
            textSize = 15f
            setTextColor(Color.WHITE)
            gravity = Gravity.CENTER
            setTypeface(typeface, Typeface.BOLD)
            val btnBg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 48f
                colors = intArrayOf(MeituColors.PrimaryPink, MeituColors.PrimaryCoral)
                orientation = GradientDrawable.Orientation.LEFT_RIGHT
            }
            background = btnBg

            setOnClickListener {
                billingManager.launchBillingFlow(activity, selectedSku.productId)
                dialog.dismiss()
            }
        }
        rootLayout.addView(btnSubscribe)

        // Footer Action: Khôi phục giao dịch & Đóng
        val footerRow = LinearLayout(context).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER
            setPadding(0, 16, 0, 0)
        }

        val btnRestore = TextView(context).apply {
            text = "Khôi phục mua hàng"
            textSize = 12f
            setTextColor(MeituColors.TextSecondary)
            setPadding(16, 12, 16, 12)
            setOnClickListener {
                CoroutineScope(Dispatchers.Main).launch {
                    val restored = vipStatusManager.restorePurchases()
                    if (restored) {
                        Toast.makeText(context, "Khôi phục VIP thành công!", Toast.LENGTH_SHORT).show()
                        dialog.dismiss()
                    } else {
                        Toast.makeText(context, "Không tìm thấy gói VIP đang hoạt động", Toast.LENGTH_SHORT).show()
                    }
                }
            }
        }

        val btnClose = TextView(context).apply {
            text = "Đóng"
            textSize = 12f
            setTextColor(MeituColors.TextSecondary)
            setPadding(16, 12, 16, 12)
            setOnClickListener {
                dialog.dismiss()
            }
        }

        footerRow.addView(btnRestore)
        footerRow.addView(btnClose)
        rootLayout.addView(footerRow)

        dialog.setContentView(rootLayout)
        dialog.window?.setBackgroundDrawable(ColorDrawable(Color.TRANSPARENT))
        val width = (activity.resources.displayMetrics.widthPixels * 0.90).toInt()
        dialog.window?.setLayout(width, ViewGroup.LayoutParams.WRAP_CONTENT)

        dialog.setOnDismissListener {
            onDismiss?.invoke()
        }

        dialog.show()
    }
}
