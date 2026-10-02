package com.mt.mtxx.mtxx.beauty

import org.junit.Assert.*
import org.junit.Test
import java.io.File

/**
 * TASK_010: Machine-Verifiable Regression Guards & Provenance Tests.
 * Enforces strict anti-fake-green rules, state schema invariants, and command bus freshness.
 */
class TaskProvenanceAndEvidenceGuardTest {

    @Test
    fun testReadyMustNeverCountAsExecuted() {
        val registryFeatures = FaceBeautyTestabilityRegistry.ALL_104_FEATURES
        assertEquals("Total feature denominator must be exactly 104", 104, registryFeatures.size)

        for (feat in registryFeatures) {
            // Guard: If a feature is host-unsupported and requires device, it must not claim LEVEL_D on host JVM
            if (!feat.hostLoadable) {
                assertNotEquals(
                    "Feature ${feat.featureId} cannot claim LEVEL_D on host JVM without native loading",
                    Gate5EvidenceLevel.LEVEL_D_REAL_NATIVE_ENGINE,
                    feat.achievedLevel
                )
            }
        }
    }

    private fun getProjectRoot(): File {
        var dir: File? = File(".").canonicalFile
        while (dir != null && !File(dir, ".ai").exists()) {
            dir = dir.parentFile
        }
        return dir ?: File(".")
    }

    @Test
    fun testNextCommandFreshnessAndFormat() {
        val root = getProjectRoot()
        val nextCmdFile = File(root, ".ai/commands/NEXT_COMMAND.json")
        assertTrue("NEXT_COMMAND.json must exist at ${nextCmdFile.absolutePath}", nextCmdFile.exists())

        val content = nextCmdFile.readText(Charsets.UTF_8)
        assertFalse("NEXT_COMMAND must not remain frozen on TASK_003", content.contains("TASK_003_HCE_V1_GPU_EVIDENCE"))
        assertTrue("NEXT_COMMAND must have valid protocol", content.contains("\"protocol\": \"CONVERT2_COMMAND_V1\""))
        assertTrue("NEXT_COMMAND must have dispatch_command_id", content.contains("\"command_id\":") || content.contains("\"dispatch_command_id\":"))
        assertTrue("NEXT_COMMAND must contain task_id", content.contains("\"task_id\":"))
    }

    @Test
    fun testProvenanceSchemaIntegrity() {
        val root = getProjectRoot()
        val nextCmdFile = File(root, ".ai/commands/NEXT_COMMAND.json")
        if (nextCmdFile.exists()) {
            val content = nextCmdFile.readText(Charsets.UTF_8)
            val hasSha = Regex("\"(dispatch_commit_sha|issued_for_sha)\":\\s*\"([0-9a-fA-F]{40})\"").containsMatchIn(content)
            assertTrue("Command Bus command must contain valid 40-character dispatch SHA", hasSha)
        }
    }

    @Test
    fun testReportDriveMirrorNeverClaimsSuccessWithoutDriveId() {
        val root = getProjectRoot()
        val manifestFiles = listOf(
            File(root, ".ai/reports/TASK_010_TASK009_EVIDENCE_PROVENANCE_AND_DISPATCH_HARDENING/05_REPORT_DRIVE_MIRROR_MANIFEST.csv"),
            File(root, ".ai/reports/TASK_009_FACE_BEAUTY_GATE5_REAL_ENGINE_TEST_CORRECTION/05_REPORT_DRIVE_MIRROR_MANIFEST.csv")
        )

        for (mFile in manifestFiles) {
            if (mFile.exists()) {
                val lines = mFile.readLines()
                for ((idx, line) in lines.withIndex()) {
                    if (idx == 0 || line.isBlank()) continue
                    val parts = line.split(",")
                    if (parts.size >= 4) {
                        val status = parts[parts.size - 2].trim().uppercase()
                        val remoteId = parts[parts.size - 3].trim()
                        if (status in listOf("MIRRORED", "VERIFIED", "PASS", "SUCCESS")) {
                            assertTrue(
                                "Line $idx: Cannot claim $status without real Drive file ID (found: '$remoteId')",
                                remoteId.length >= 25 && !remoteId.contains("BLOCKED")
                            )
                        }
                    }
                }
            }
        }
    }

    @Test
    fun testDualMetricsHonestyInRegistry() {
        val metrics = FaceBeautyTestabilityRegistry.calculateGate5Metrics()
        assertEquals("Total denominator must be 104", 104, metrics.totalFeaturesDenominator)
        assertEquals("Host real C++ engine must be honestly 0.0%", 0.0f, metrics.hostRealEngineExecutionPct, 0.001f)
        assertEquals("Contract metadata must be 100.0%", 100.0f, metrics.contractMetadataCoveragePct, 0.001f)
        assertEquals("Kotlin dispatch coverage must be 102/104 (98.08%)", 98.08f, metrics.kotlinDispatchCoveragePct, 0.01f)
        assertEquals("Device readiness must be 100.0%", 100.0f, metrics.deviceReadinessCoveragePct, 0.001f)
    }
}
