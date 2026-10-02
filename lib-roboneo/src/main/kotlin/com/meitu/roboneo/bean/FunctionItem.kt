package com.meitu.roboneo.bean

/**
 * FunctionItem: Định nghĩa tính năng trong thanh công cụ tương tác của RoboNeo.
 * Defines an interactive feature entry in the RoboNeo bottom toolbar.
 */
data class FunctionItem(
    val functionId: String,
    val name: String,
    val category: String,
    val iconUrl: String = "",
    val isVipOnly: Boolean = false,
    val orderWeight: Int = 0
)
