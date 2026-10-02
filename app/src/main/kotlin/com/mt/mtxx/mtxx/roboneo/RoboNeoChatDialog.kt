package com.mt.mtxx.mtxx.roboneo

import android.app.Dialog
import android.content.Context
import android.graphics.Color
import android.graphics.Typeface
import android.graphics.drawable.GradientDrawable
import android.view.Gravity
import android.view.ViewGroup
import android.widget.Button
import android.widget.EditText
import android.widget.HorizontalScrollView
import android.widget.LinearLayout
import android.widget.ScrollView
import android.widget.TextView
import android.widget.Toast
import com.meitu.common.ui.theme.MeituColors
import com.meitu.roboneo.bean.ChatMessage
import com.meitu.roboneo.bean.MessageSender
import com.meitu.roboneo.vm.RoboNeoHomeVM
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

/**
 * RoboNeoChatDialog: Hộp thoại trò chuyện thời gian thực với trợ lý RoboNeo AI qua SSE Stream từ Backend Port 9999.
 * Real-time conversation dialog with RoboNeo AI Assistant streaming from Backend (Port 9999).
 */
class RoboNeoChatDialog(context: Context) : Dialog(context, android.R.style.Theme_Black_NoTitleBar_Fullscreen) {

    private val viewModel = RoboNeoHomeVM()
    private val scope = CoroutineScope(Dispatchers.Main)
    private lateinit var messagesContainer: LinearLayout
    private lateinit var scrollView: ScrollView
    private lateinit var commandBar: LinearLayout
    private lateinit var etInput: EditText

    init {
        val density = context.resources.displayMetrics.density

        val root = LinearLayout(context).apply {
            orientation = LinearLayout.VERTICAL
            setBackgroundColor(MeituColors.DarkBackground)
            layoutParams = ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }

        // 1. Header
        val header = LinearLayout(context).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            val pad = (16 * density).toInt()
            setPadding(pad, pad, pad, pad)
            setBackgroundColor(MeituColors.DarkSurface)
        }

        val btnBack = TextView(context).apply {
            text = "←"
            textSize = 24f
            setTextColor(Color.WHITE)
            setPadding(0, 0, (16 * density).toInt(), 0)
            setOnClickListener { dismiss() }
        }

        val headerTextLayout = LinearLayout(context).apply {
            orientation = LinearLayout.VERTICAL
            layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
        }

        val tvTitle = TextView(context).apply {
            text = "🤖 RoboNeo AI Assistant"
            textSize = 17f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
        }

        val tvSub = TextView(context).apply {
            text = "SSE Live Stream • Backend Port 9999"
            textSize = 11f
            setTextColor(MeituColors.SuccessGreen)
        }
        headerTextLayout.addView(tvTitle)
        headerTextLayout.addView(tvSub)

        header.addView(btnBack)
        header.addView(headerTextLayout)
        root.addView(header)

        // 2. Chat Scroll Area
        scrollView = ScrollView(context).apply {
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 0, 1f)
        }
        messagesContainer = LinearLayout(context).apply {
            orientation = LinearLayout.VERTICAL
            val pad = (16 * density).toInt()
            setPadding(pad, pad, pad, pad)
        }
        scrollView.addView(messagesContainer)
        root.addView(scrollView)

        // 3. Command suggestions horizontal bar
        val commandScrollView = HorizontalScrollView(context).apply {
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT)
            val pad = (8 * density).toInt()
            setPadding(pad, pad, pad, pad)
            setBackgroundColor(MeituColors.DarkCard)
        }
        commandBar = LinearLayout(context).apply {
            orientation = LinearLayout.HORIZONTAL
        }
        commandScrollView.addView(commandBar)
        root.addView(commandScrollView)

        // 4. Input Area
        val inputArea = LinearLayout(context).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            val pad = (12 * density).toInt()
            setPadding(pad, pad, pad, pad)
            setBackgroundColor(MeituColors.DarkSurface)
        }

        etInput = EditText(context).apply {
            hint = "Nhập yêu cầu làm đẹp, đổi màu, sticker..."
            setHintTextColor(MeituColors.TextMuted)
            setTextColor(Color.WHITE)
            textSize = 14f
            val pad = (10 * density).toInt()
            setPadding(pad, pad, pad, pad)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 20f
                setColor(MeituColors.DarkCard)
            }
            background = bg
            layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
        }

        val btnSend = Button(context).apply {
            text = "Gửi"
            textSize = 13f
            setTextColor(Color.WHITE)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 20f
                setColor(MeituColors.PrimaryPink)
            }
            background = bg
            val lp = LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                leftMargin = (8 * density).toInt()
            }
            layoutParams = lp
            setOnClickListener {
                val txt = etInput.text.toString().trim()
                if (txt.isNotEmpty()) {
                    viewModel.sendUserPrompt(txt)
                    etInput.setText("")
                }
            }
        }

        inputArea.addView(etInput)
        inputArea.addView(btnSend)
        root.addView(inputArea)

        setContentView(root)

        observeViewModel()
    }

    private fun observeViewModel() {
        val density = context.resources.displayMetrics.density

        scope.launch {
            viewModel.messages.collect { messages ->
                renderMessages(messages, density)
            }
        }
    }

    private fun renderMessages(messages: List<ChatMessage>, density: Float) {
        messagesContainer.removeAllViews()
        commandBar.removeAllViews()

        messages.forEach { msg ->
            val bubble = LinearLayout(context).apply {
                orientation = LinearLayout.VERTICAL
                val pad = (12 * density).toInt()
                setPadding(pad, pad, pad, pad)
                val lp = LinearLayout.LayoutParams(
                    ViewGroup.LayoutParams.WRAP_CONTENT,
                    ViewGroup.LayoutParams.WRAP_CONTENT
                ).apply {
                    topMargin = (8 * density).toInt()
                    gravity = if (msg.sender == MessageSender.USER) Gravity.END else Gravity.START
                }
                layoutParams = lp

                val bg = GradientDrawable().apply {
                    shape = GradientDrawable.RECTANGLE
                    cornerRadius = 24f
                    if (msg.sender == MessageSender.USER) {
                        setColor(MeituColors.PrimaryPink)
                    } else if (msg.sender == MessageSender.ROBONEO) {
                        setColor(MeituColors.DarkCard)
                    } else {
                        setColor(0x33FFB300)
                    }
                }
                background = bg
            }

            val tvContent = TextView(context).apply {
                text = msg.content
                textSize = 14f
                setTextColor(Color.WHITE)
            }
            bubble.addView(tvContent)
            messagesContainer.addView(bubble)

            // Render suggested commands from latest AI message
            if (msg.suggestedCommands.isNotEmpty()) {
                msg.suggestedCommands.forEach { cmd ->
                    val btnCmd = TextView(context).apply {
                        text = cmd.title
                        textSize = 12f
                        setTextColor(MeituColors.PrimaryPink)
                        val padH = (12 * density).toInt()
                        val padV = (6 * density).toInt()
                        setPadding(padH, padV, padH, padV)
                        val bg = GradientDrawable().apply {
                            shape = GradientDrawable.RECTANGLE
                            cornerRadius = 16f
                            setColor(0x22FF2465)
                        }
                        background = bg
                        val lp = LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                            rightMargin = (8 * density).toInt()
                        }
                        layoutParams = lp
                        setOnClickListener {
                            viewModel.onCommandClicked(cmd)
                            Toast.makeText(context, "Đã kích hoạt: ${cmd.title}", Toast.LENGTH_SHORT).show()
                        }
                    }
                    commandBar.addView(btnCmd)
                }
            }
        }

        scrollView.post { scrollView.fullScroll(ScrollView.FOCUS_DOWN) }
    }
}
