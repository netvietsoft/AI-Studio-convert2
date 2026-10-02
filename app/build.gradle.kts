plugins {
    id("com.android.application")
    id("org.jetbrains.kotlin.android")
}

android {
    namespace = "com.mt.mtxx.mtxx"
    compileSdk = 35

    defaultConfig {
        applicationId = "com.mt.mtxx.mtxx"
        minSdk = 26
        targetSdk = 35
        versionCode = 121708
        versionName = "12.17.8"
        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
        ndk {
            abiFilters.addAll(listOf("arm64-v8a"))
        }
    }

    buildTypes {
        debug {
            isMinifyEnabled = false
            applicationIdSuffix = ".convert"
        }
        release {
            isMinifyEnabled = false
        }
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17
    }

    kotlinOptions {
        jvmTarget = "17"
    }
}

dependencies {
    implementation(project(":lib-common-ui"))
    implementation(project(":lib-core-graphics"))
    implementation(project(":lib-ai-engine"))
    implementation(project(":lib-photo-editor"))
    implementation(project(":lib-roboneo"))
    implementation(project(":lib-video-engine"))
    implementation(project(":lib-billing"))

    implementation("androidx.core:core-ktx:1.13.1")
    implementation("androidx.appcompat:appcompat:1.7.0")
    implementation("com.google.android.material:material:1.12.0")
    testImplementation(libs.junit)
}
