package com.meitu.photoeditor.viewmodel

import android.content.Context
import android.graphics.Bitmap
import androidx.lifecycle.viewModelScope
import com.meitu.common.ui.base.BaseViewModel
import com.meitu.common.ui.base.UiEffect
import com.meitu.common.ui.base.UiState
import com.meitu.photoeditor.pipeline.BeautyPipeline
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import java.util.Stack

/**
 * ViewModel điều phối màn hình Chỉnh ảnh chuyên nghiệp (Photo Editor).
 * Kế thừa BaseViewModel từ :lib-common-ui, hỗ trợ Undo/Redo stack và so sánh Trước/Sau.
 */
class PhotoEditorViewModel(
    context: Context
) : BaseViewModel<PhotoEditorViewModel.EditorState, PhotoEditorViewModel.EditorEffect>(EditorState()) {

    private val pipeline = BeautyPipeline(context.applicationContext)

    data class EditorState(
        val isProcessing: Boolean = false,
        val originalBitmap: Bitmap? = null,
        val currentBitmap: Bitmap? = null,
        val canUndo: Boolean = false,
        val canRedo: Boolean = false,
        val currentParams: BeautyPipeline.BeautyParams = BeautyPipeline.BeautyParams()
    ) : UiState

    sealed interface EditorEffect : UiEffect {
        data class ShowToast(val message: String) : EditorEffect
        data class ExportSuccess(val filePath: String) : EditorEffect
    }

    private val undoStack = Stack<Bitmap>()
    private val redoStack = Stack<Bitmap>()

    fun setSourceImage(bitmap: Bitmap) {
        undoStack.clear()
        redoStack.clear()
        setState {
            copy(
                originalBitmap = bitmap,
                currentBitmap = bitmap,
                canUndo = false,
                canRedo = false
            )
        }
    }

    fun applyBeautyAdjustment(params: BeautyPipeline.BeautyParams) {
        val orig = currentState.originalBitmap ?: return
        viewModelScope.launch(Dispatchers.Default) {
            setState { copy(isProcessing = true) }

            val processed = pipeline.processImage(orig, params)

            currentState.currentBitmap?.let { undoStack.push(it) }
            redoStack.clear()

            setState {
                copy(
                    isProcessing = false,
                    currentBitmap = processed,
                    canUndo = true,
                    canRedo = false,
                    currentParams = params
                )
            }
        }
    }

    fun undo() {
        if (undoStack.isNotEmpty()) {
            val prev = undoStack.pop()
            currentState.currentBitmap?.let { redoStack.push(it) }
            setState {
                copy(
                    currentBitmap = prev,
                    canUndo = undoStack.isNotEmpty(),
                    canRedo = true
                )
            }
        }
    }

    fun redo() {
        if (redoStack.isNotEmpty()) {
            val next = redoStack.pop()
            currentState.currentBitmap?.let { undoStack.push(it) }
            setState {
                copy(
                    currentBitmap = next,
                    canUndo = true,
                    canRedo = redoStack.isNotEmpty()
                )
            }
        }
    }
}
