// Source decompiled: com.mt.mtxx.mtxx.database.AppDatabase.kt
package com.mt.mtxx.mtxx.database

import android.content.ContentValues
import android.content.Context
import android.database.Cursor
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper
import android.util.Log

/**
 * Trình quản lý cơ sở dữ liệu SQLite trung tâm toàn bộ ứng dụng Meitu Reborn.
 * Khởi tạo và bảo trì 92 bảng dữ liệu theo chuẩn kiến trúc lưu trữ Meitu.
 *
 * Central SQLite Database Manager of Meitu Reborn.
 * Initializes and maintains 92 standard tables according to Meitu storage architecture.
 */
class AppDatabase private constructor(context: Context) :
    SQLiteOpenHelper(context, DATABASE_NAME, null, DATABASE_VERSION) {

    override fun onCreate(db: SQLiteDatabase) {
        Log.i(TAG, "Creating 92 tables in Meitu AppDatabase...")
        // 1. Nhóm Bản nháp & Dự án biên tập (Tables 1 - 10)
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_draft_project (id TEXT PRIMARY KEY, title TEXT, cover_path TEXT, project_type TEXT, width INTEGER, height INTEGER, duration_ms INTEGER, data_json TEXT, create_time INTEGER, update_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_draft_layer (id TEXT PRIMARY KEY, project_id TEXT, layer_index INTEGER, layer_type TEXT, layer_data TEXT, is_visible INTEGER, opacity REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_draft_undo_history (id INTEGER PRIMARY KEY AUTOINCREMENT, project_id TEXT, step_index INTEGER, action_type TEXT, snapshot_data TEXT, timestamp INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_draft_media_asset (id TEXT PRIMARY KEY, project_id TEXT, file_path TEXT, mime_type TEXT, file_size INTEGER, create_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_draft_render_cache (id TEXT PRIMARY KEY, project_id TEXT, cache_key TEXT, cache_file TEXT, expire_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_draft_auto_save (id TEXT PRIMARY KEY, project_id TEXT, snapshot_json TEXT, saved_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_draft_cloud_sync (project_id TEXT PRIMARY KEY, cloud_id TEXT, sync_status INTEGER, sync_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_draft_trash (id TEXT PRIMARY KEY, project_id TEXT, deleted_time INTEGER, original_data TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_draft_tag (id TEXT PRIMARY KEY, project_id TEXT, tag_name TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_draft_meta (project_id TEXT PRIMARY KEY, app_version TEXT, extra_info TEXT);")

        // 2. Nhóm Tài nguyên & Vật liệu Material Center (Tables 11 - 30)
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_category (id TEXT PRIMARY KEY, parent_id TEXT, name TEXT, icon_url TEXT, sort_order INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_item (id TEXT PRIMARY KEY, category_id TEXT, title TEXT, thumb_url TEXT, download_url TEXT, file_size INTEGER, is_vip INTEGER, is_downloaded INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_favorite (material_id TEXT PRIMARY KEY, category_id TEXT, title TEXT, thumb_url TEXT, is_vip INTEGER, added_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_download (material_id TEXT PRIMARY KEY, local_path TEXT, download_time INTEGER, version INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_tag (id INTEGER PRIMARY KEY AUTOINCREMENT, material_id TEXT, tag TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_usage_stat (material_id TEXT PRIMARY KEY, use_count INTEGER, last_used_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_banner (id TEXT PRIMARY KEY, title TEXT, image_url TEXT, link_url TEXT, sort_order INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_topic (id TEXT PRIMARY KEY, topic_name TEXT, banner_url TEXT, description TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_topic_rel (topic_id TEXT, material_id TEXT, PRIMARY KEY (topic_id, material_id));")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_hot_search (keyword TEXT PRIMARY KEY, count INTEGER, update_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_search_history (keyword TEXT PRIMARY KEY, search_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_recommend (id TEXT PRIMARY KEY, material_id TEXT, position INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_offline_pack (pack_id TEXT PRIMARY KEY, name TEXT, file_path TEXT, version INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_preview_cache (material_id TEXT PRIMARY KEY, cache_path TEXT, expire_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_permission (material_id TEXT PRIMARY KEY, required_level INTEGER, price_coins INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_version (material_id TEXT PRIMARY KEY, current_version INTEGER, min_app_version TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_author (author_id TEXT PRIMARY KEY, name TEXT, avatar_url TEXT, bio TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_bundle (bundle_id TEXT PRIMARY KEY, name TEXT, description TEXT, count INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_bundle_item (bundle_id TEXT, material_id TEXT, PRIMARY KEY (bundle_id, material_id));")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_material_config (config_key TEXT PRIMARY KEY, config_val TEXT);")

        // 3. Nhóm Bộ lọc & Làm đẹp (Tables 31 - 50)
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_filter_preset (id TEXT PRIMARY KEY, name TEXT, lut_path TEXT, intensity REAL, is_vip INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_filter_category (id TEXT PRIMARY KEY, name TEXT, sort_order INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_filter_custom (id TEXT PRIMARY KEY, name TEXT, matrix_data TEXT, create_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_filter_recent (filter_id TEXT PRIMARY KEY, used_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_param (feature_key TEXT PRIMARY KEY, default_value REAL, min_val REAL, max_val REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_preset (id TEXT PRIMARY KEY, name TEXT, config_json TEXT, is_vip INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_skin (id TEXT PRIMARY KEY, tone_color TEXT, smoothness REAL, brightness REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_face_shape (id TEXT PRIMARY KEY, shape_type TEXT, intensity REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_makeup (id TEXT PRIMARY KEY, category TEXT, texture_path TEXT, alpha REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_body (id TEXT PRIMARY KEY, waist_ratio REAL, leg_stretch REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_hair (id TEXT PRIMARY KEY, color_hex TEXT, volume REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_teeth (id TEXT PRIMARY KEY, whiten_level REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_blemish (id TEXT PRIMARY KEY, x REAL, y REAL, radius REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_eye_bright (id TEXT PRIMARY KEY, brightness REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_nose_shape (id TEXT PRIMARY KEY, width REAL, height REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_lip_color (id TEXT PRIMARY KEY, hex_color TEXT, glossiness REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_contour (id TEXT PRIMARY KEY, mask_path TEXT, intensity REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_history (id INTEGER PRIMARY KEY AUTOINCREMENT, project_id TEXT, params_json TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_face_detect (id TEXT PRIMARY KEY, image_hash TEXT, landmarks_blob BLOB);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_beauty_mesh_cache (id TEXT PRIMARY KEY, mesh_data BLOB);")

        // 4. Nhóm Sticker, Text, Khung & Bút vẽ (Tables 51 - 70)
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_sticker_group (id TEXT PRIMARY KEY, name TEXT, icon_url TEXT, is_vip INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_sticker_item (id TEXT PRIMARY KEY, group_id TEXT, image_path TEXT, is_animated INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_sticker_recent (sticker_id TEXT PRIMARY KEY, used_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_text_style (id TEXT PRIMARY KEY, font_id TEXT, color_hex TEXT, shadow_color TEXT, bg_color TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_text_font (id TEXT PRIMARY KEY, font_name TEXT, ttf_path TEXT, is_vip INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_watermark (id TEXT PRIMARY KEY, name TEXT, asset_path TEXT, is_default INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_frame_item (id TEXT PRIMARY KEY, name TEXT, border_path TEXT, aspect_ratio TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_brush_pattern (id TEXT PRIMARY KEY, name TEXT, stroke_texture TEXT, default_size REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_mosaic_pattern (id TEXT PRIMARY KEY, name TEXT, pattern_type TEXT, blur_radius REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_magic_pen (id TEXT PRIMARY KEY, name TEXT, particle_emitter TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_cutout_template (id TEXT PRIMARY KEY, name TEXT, mask_url TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_background_preset (id TEXT PRIMARY KEY, bg_url TEXT, color_hex TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_doodle_history (id INTEGER PRIMARY KEY AUTOINCREMENT, project_id TEXT, path_data TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_text_bubble (id TEXT PRIMARY KEY, bubble_path TEXT, padding TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_sticker_layer (id TEXT PRIMARY KEY, project_id TEXT, sticker_id TEXT, x REAL, y REAL, scale REAL, rotate REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_text_layer (id TEXT PRIMARY KEY, project_id TEXT, content TEXT, x REAL, y REAL, font_id TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_filter_layer (id TEXT PRIMARY KEY, project_id TEXT, filter_id TEXT, alpha REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_border_layer (id TEXT PRIMARY KEY, project_id TEXT, frame_id TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_canvas_preset (id TEXT PRIMARY KEY, name TEXT, width INTEGER, height INTEGER, ratio TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_export_preset (id TEXT PRIMARY KEY, format TEXT, quality INTEGER, resolution TEXT);")

        // 5. Nhóm Video Engine & Âm thanh (Tables 71 - 85)
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_project (id TEXT PRIMARY KEY, title TEXT, duration_ms INTEGER, fps INTEGER, resolution TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_track (id TEXT PRIMARY KEY, video_id TEXT, track_index INTEGER, track_type TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_segment (id TEXT PRIMARY KEY, track_id TEXT, file_path TEXT, start_ms INTEGER, end_ms INTEGER, speed REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_transition (id TEXT PRIMARY KEY, from_seg TEXT, to_seg TEXT, effect_type TEXT, duration_ms INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_fx (id TEXT PRIMARY KEY, segment_id TEXT, fx_type TEXT, params_json TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_audio_track (id TEXT PRIMARY KEY, video_id TEXT, audio_path TEXT, volume REAL, is_muted INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_audio_effect (id TEXT PRIMARY KEY, track_id TEXT, fx_name TEXT, pitch REAL, echo REAL);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_keyframe (id TEXT PRIMARY KEY, segment_id TEXT, time_ms INTEGER, transform_matrix TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_subtitle (id TEXT PRIMARY KEY, video_id TEXT, start_time INTEGER, end_time INTEGER, content TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_music_lib (id TEXT PRIMARY KEY, title TEXT, artist TEXT, url TEXT, duration_ms INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_sound_fx (id TEXT PRIMARY KEY, category TEXT, name TEXT, path TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_speed_curve (id TEXT PRIMARY KEY, name TEXT, points_json TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_export_history (id TEXT PRIMARY KEY, output_path TEXT, size INTEGER, duration_ms INTEGER, timestamp INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_cache (cache_key TEXT PRIMARY KEY, file_path TEXT, size INTEGER, expire_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_video_transcode_task (id TEXT PRIMARY KEY, input_path TEXT, output_path TEXT, status INTEGER, progress REAL);")

        // 6. Nhóm Trợ lý RoboNeo AI, VIP Billing & Hệ thống (Tables 86 - 92)
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_roboneo_conversation (id TEXT PRIMARY KEY, session_name TEXT, create_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_roboneo_message (id TEXT PRIMARY KEY, conversation_id TEXT, role TEXT, content TEXT, timestamp INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_roboneo_ai_prompt (id TEXT PRIMARY KEY, title TEXT, prompt_text TEXT, category TEXT);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_ai_task_history (id TEXT PRIMARY KEY, task_type TEXT, input_url TEXT, output_url TEXT, status TEXT, timestamp INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_user_config (config_key TEXT PRIMARY KEY, config_value TEXT, update_time INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_vip_purchase_cache (order_id TEXT PRIMARY KEY, product_id TEXT, token TEXT, state INTEGER, timestamp INTEGER);")
        db.execSQL("CREATE TABLE IF NOT EXISTS tb_app_analytics (id INTEGER PRIMARY KEY AUTOINCREMENT, event_name TEXT, params_json TEXT, timestamp INTEGER);")

        Log.i(TAG, "All 92 tables successfully created in SQLite.")
    }

        override fun onUpgrade(db: SQLiteDatabase, oldVersion: Int, newVersion: Int) {
        android.util.Log.i(TAG, "Upgrading database from $oldVersion to $newVersion: Executing schema migration...")
        onCreate(db)
    }

    // -------------------------------------------------------------
    // DAO Helper Methods: Draft Projects
    // -------------------------------------------------------------
    fun insertDraft(id: String, title: String, projectType: String, coverPath: String = "", dataJson: String = "") {
        val db = writableDatabase
        val values = ContentValues().apply {
            put("id", id)
            put("title", title)
            put("project_type", projectType)
            put("cover_path", coverPath)
            put("data_json", dataJson)
            put("create_time", System.currentTimeMillis())
            put("update_time", System.currentTimeMillis())
        }
        db.insertWithOnConflict("tb_draft_project", null, values, SQLiteDatabase.CONFLICT_REPLACE)
    }

    fun getAllDrafts(): List<DraftItem> {
        val list = mutableListOf<DraftItem>()
        val db = readableDatabase
        val cursor: Cursor = db.rawQuery("SELECT id, title, project_type, cover_path, update_time FROM tb_draft_project ORDER BY update_time DESC", null)
        cursor.use { c ->
            while (c.moveToNext()) {
                list.add(
                    DraftItem(
                        id = c.getString(0),
                        title = c.getString(1),
                        projectType = c.getString(2),
                        coverPath = c.getString(3),
                        updateTime = c.getLong(4)
                    )
                )
            }
        }
        return list
    }

    fun insertAuditLog(action: String, detail: String) {
        insertCrashLog(action, detail, "")
    }

    fun insertCrashLog(tag: String, message: String, stackTrace: String) {
        try {
            val db = writableDatabase
            val values = ContentValues()
            values.put("event_name", tag)
            values.put("params_json", message)
            values.put("timestamp", System.currentTimeMillis())
            db.insert("tb_app_analytics", null, values)
        } catch (ignored: Throwable) {
        }
    }

    fun deleteDraft(id: String): Int {
        val db = writableDatabase
        return db.delete("tb_draft_project", "id = ?", arrayOf(id))
    }

    data class DraftItem(
        val id: String,
        val title: String,
        val projectType: String,
        val coverPath: String,
        val updateTime: Long
    )

    companion object {
        private const val TAG = "AppDatabase"
        private const val DATABASE_NAME = "mtxx_app_database.db"
        private const val DATABASE_VERSION = 1

        @Volatile
        private var instance: AppDatabase? = null

        fun getInstance(context: Context): AppDatabase {
            return instance ?: synchronized(this) {
                instance ?: AppDatabase(context.applicationContext).also { instance = it }
            }
        }
    }
}