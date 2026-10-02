package com.meitu.common.ui.base

import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.channels.Channel
import kotlinx.coroutines.flow.MutableSharedFlow
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.SharedFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asSharedFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.receiveAsFlow
import kotlinx.coroutines.launch

/**
 * Base ViewModel chuẩn kiến trúc Unidirectional Data Flow (UDF / MVI).
 */
abstract class BaseViewModel<S : UiState, E : UiEffect>(initialState: S) : ViewModel() {

    private val _uiState = MutableStateFlow(initialState)
    val uiState: StateFlow<S> = _uiState.asStateFlow()

    private val _effectChannel = Channel<E>(Channel.BUFFERED)
    val effect = _effectChannel.receiveAsFlow()

    protected val currentState: S
        get() = _uiState.value

    protected fun setState(reduce: S.() -> S) {
        val newState = currentState.reduce()
        _uiState.value = newState
    }

    protected fun sendEffect(effect: E) {
        viewModelScope.launch {
            _effectChannel.send(effect)
        }
    }
}
