// ============================================================================
// MEITU REBORN - CONVERT BUILD SKELETON (CONVERT2)
// Cấu trúc dự án đa module chuẩn công nghiệp phục vụ đổ mã convert
// ============================================================================
pluginManagement {
    repositories {
        google()
        mavenCentral()
        gradlePluginPortal()
    }
}
dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS)
    repositories {
        google()
        mavenCentral()
        maven { url = java.net.URI("https://jitpack.io") }
    }
}

rootProject.name = "meitu-convert"

// 7 Modules Thư Viện Chuyên Biệt Chứa Mã Convert
include(":lib-common-ui")
include(":lib-core-graphics")
include(":lib-ai-engine")
include(":lib-photo-editor")
include(":lib-roboneo")
include(":lib-video-engine")
include(":lib-billing")

// Module App Khung Chạy Thử Nghiệm
include(":app")
