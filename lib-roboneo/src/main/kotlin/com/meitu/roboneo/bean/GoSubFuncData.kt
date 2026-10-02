package com.meitu.roboneo.bean

/**
 * GoSubFuncData: Dữ liệu điều hướng chức năng phụ trợ trong RoboNeo.
 * Sub-function routing data model for RoboNeo navigation actions.
 */
data class GoSubFuncData(
    val subFuncId: String,
    val parentFuncId: String,
    val title: String,
    val extraParams: Map<String, String> = emptyMap()
)
