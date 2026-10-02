package com.meitu.core.types

import android.opengl.EGL14
import android.opengl.EGLConfig
import android.opengl.EGLContext
import android.opengl.EGLDisplay
import android.opengl.EGLSurface
import android.util.Log
import androidx.annotation.Keep
import java.lang.ref.WeakReference
import java.util.LinkedList

/**
 * Trình dựng đồ hoạ OpenGL Headless (Offscreen PBuffer Surface Context).
 * Cho phép chạy các Shader C++ Native và Texture Render không cần UI SurfaceView.
 * Nguồn: com.meitu.core.types.MTGLOffscreenRenderer.java
 */
@Keep
class MTGLOffscreenRenderer {

    private var mGLThread: GLThread? = null
    private val mRunnable: MutableList<Runnable> = LinkedList()
    private val mObject = Any()
    private val mRunnableWeakRef = WeakReference(mRunnable)
    private val mObjectWeakRef = WeakReference(mObject)

    companion object {
        private const val TAG = "MTGLOffscreenRenderer"
    }

    class GLThread(
        weakRunnable: WeakReference<MutableList<Runnable>>,
        weakLock: WeakReference<Any>
    ) : Thread("MTGLOffscreenRenderer_GLThread") {

        companion object {
            private const val DEFAULT_SURFACE_WIDTH = 720
            private const val DEFAULT_SURFACE_HEIGHT = 1280
        }

        private var mEGLDisplay: EGLDisplay = EGL14.EGL_NO_DISPLAY
        private var mEGLContext: EGLContext = EGL14.EGL_NO_CONTEXT
        private var mEGLSurface: EGLSurface = EGL14.EGL_NO_SURFACE
        private var mIsExit = false
        private var mIsValid = false
        private var mReleaseRunnable: Runnable? = null
        private val mRunOnDraw: MutableList<Runnable>? = weakRunnable.get()
        private val mLock: Any? = weakLock.get()

        private fun createEGLContext(width: Int, height: Int) {
            val display = EGL14.eglGetDisplay(EGL14.EGL_DEFAULT_DISPLAY)
            this.mEGLDisplay = display
            if (display == EGL14.EGL_NO_DISPLAY) {
                Log.e(TAG, "unable to get EGL14 display")
                return
            }

            val version = IntArray(2)
            if (!EGL14.eglInitialize(display, version, 0, version, 1)) {
                this.mEGLDisplay = EGL14.EGL_NO_DISPLAY
                Log.e(TAG, "unable to initialize EGL14")
                return
            }

            val configs = arrayOfNulls<EGLConfig>(1)
            val numConfigs = IntArray(1)
            val configAttribs = intArrayOf(
                EGL14.EGL_RED_SIZE, 8,
                EGL14.EGL_GREEN_SIZE, 8,
                EGL14.EGL_BLUE_SIZE, 8,
                EGL14.EGL_ALPHA_SIZE, 8,
                EGL14.EGL_RENDERABLE_TYPE, EGL14.EGL_OPENGL_ES2_BIT,
                EGL14.EGL_SURFACE_TYPE, EGL14.EGL_PBUFFER_BIT,
                EGL14.EGL_NONE
            )

            if (!EGL14.eglChooseConfig(this.mEGLDisplay, configAttribs, 0, configs, 0, 1, numConfigs, 0) || numConfigs[0] == 0) {
                Log.e(TAG, "unable to find RGB888 ES2 EGL config")
                return
            }

            val contextAttribs = intArrayOf(
                EGL14.EGL_CONTEXT_CLIENT_VERSION, 2,
                EGL14.EGL_NONE
            )
            val context = EGL14.eglCreateContext(this.mEGLDisplay, configs[0], EGL14.EGL_NO_CONTEXT, contextAttribs, 0)
            this.mEGLContext = context
            if (context == EGL14.EGL_NO_CONTEXT) {
                Log.e(TAG, "EGL error " + EGL14.eglGetError())
                return
            }

            val pbufferAttribs = intArrayOf(
                EGL14.EGL_WIDTH, width,
                EGL14.EGL_HEIGHT, height,
                EGL14.EGL_NONE
            )
            val surface = EGL14.eglCreatePbufferSurface(this.mEGLDisplay, configs[0], pbufferAttribs, 0)
            this.mEGLSurface = surface
            if (surface == EGL14.EGL_NO_SURFACE) {
                Log.e(TAG, "pbuffer surface was null")
                return
            }

            if (!EGL14.eglMakeCurrent(this.mEGLDisplay, surface, surface, this.mEGLContext)) {
                Log.e(TAG, "eglMakeCurrent failed")
                return
            }

            this.mIsValid = true
            Log.d(TAG, "createEGLContext success, thread: ${id}")
        }

        private fun guardedRun() {
            while (true) {
                if (!this.mIsValid) {
                    createEGLContext(DEFAULT_SURFACE_WIDTH, DEFAULT_SURFACE_HEIGHT)
                }
                if (this.mIsExit) {
                    break
                }

                val lock = this.mLock ?: break
                synchronized(lock) {
                    while (mRunOnDraw?.isNotEmpty() == true) {
                        try {
                            mRunOnDraw.removeAt(0).run()
                        } catch (t: Throwable) {
                            Log.e(TAG, "Error executing offscreen draw task", t)
                        }
                    }
                    try {
                        (lock as java.lang.Object).wait()
                    } catch (e: InterruptedException) {
                        // interrupted
                    }
                }
            }

            if (this.mIsValid) {
                mReleaseRunnable?.let {
                    try {
                        it.run()
                    } catch (t: Throwable) {
                        Log.e(TAG, "Error executing release runnable", t)
                    }
                    mReleaseRunnable = null
                }
                terminateEGL()
            }
        }

        private fun terminateEGL() {
            if (mEGLDisplay != EGL14.EGL_NO_DISPLAY) {
                if (mEGLContext != EGL14.EGL_NO_CONTEXT) {
                    EGL14.eglDestroyContext(mEGLDisplay, mEGLContext)
                }
                if (mEGLSurface != EGL14.EGL_NO_SURFACE) {
                    EGL14.eglDestroySurface(mEGLDisplay, mEGLSurface)
                }
                EGL14.eglMakeCurrent(mEGLDisplay, EGL14.EGL_NO_SURFACE, EGL14.EGL_NO_SURFACE, EGL14.EGL_NO_CONTEXT)
                EGL14.eglReleaseThread()
                EGL14.eglTerminate(mEGLDisplay)
            }
            mEGLDisplay = EGL14.EGL_NO_DISPLAY
            mEGLContext = EGL14.EGL_NO_CONTEXT
            mEGLSurface = EGL14.EGL_NO_SURFACE
            mIsValid = false
        }

        fun requestRender() {
            val lock = this.mLock ?: return
            synchronized(lock) {
                (lock as java.lang.Object).notify()
            }
        }

        fun stopGL(runnable: Runnable?) {
            val lock = this.mLock ?: return
            synchronized(lock) {
                this.mReleaseRunnable = runnable
                this.mIsExit = true
                (lock as java.lang.Object).notify()
            }
        }

        override fun run() {
            try {
                guardedRun()
            } catch (t: Throwable) {
                Log.e(TAG, "Unhandled exception in MTGLOffscreenRenderer GLThread", t)
            }
        }
    }

    init {
        beginGLThread()
    }

    private fun beginGLThread() {
        val thread = GLThread(mRunnableWeakRef, mObjectWeakRef)
        this.mGLThread = thread
        thread.start()
    }

    fun addDrawRun(runnable: Runnable) {
        synchronized(mObject) {
            mRunnable.add(runnable)
        }
    }

    fun releaseGL(runnable: Runnable?) {
        mGLThread?.stopGL(runnable)
        mGLThread = null
    }

    fun requestRender() {
        mGLThread?.requestRender()
    }
}
