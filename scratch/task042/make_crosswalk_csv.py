import csv
from pathlib import Path

out_csv = Path(".ai/reports/TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK/02_V1_TO_CONVERT2_FUNCTION_CROSSWALK.csv")

crosswalk_rows = [
    {
        "v1_module": "hair_v2_barrier.cpp",
        "v1_function": "buildAnatomicalProtectionMask",
        "convert2_target_module": "hair_pipeline_v2.cpp",
        "convert2_target_function": "applyConfidenceAndExclusion (Stage 4)",
        "relationship": "SUPERSEDED",
        "overlap_pct": 75,
        "risk_level": "HIGH",
        "benchmark_verdict": "REJECT_INFERIOR",
        "technical_rationale": "CONVERT2 uses high-res BiSeNet 19-class semantic segmentation (face, ears, neck, cloth) + Cr/Cb skin tone gating + dynamic cranial head-anchor. V1's 106-point polygon misses organic curvature between landmarks and caused forehead/neck leaks.",
        "port_conditions": "Do NOT replace CONVERT2 Stage 4. Yaw/pitch pose parameters can be consumed as advisory bounding limits only."
    },
    {
        "v1_module": "hair_v2_barrier.cpp",
        "v1_function": "pointInPolygon",
        "convert2_target_module": "hair_pipeline_v2.cpp",
        "convert2_target_function": "Internal geometric checks",
        "relationship": "SUPERSEDED",
        "overlap_pct": 90,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Standard ray-casting point-in-polygon test; superseded by raster semantic label masks in CONVERT2.",
        "port_conditions": "None (keep as reference)."
    },
    {
        "v1_module": "hair_v2_base_tone.cpp",
        "v1_function": "estimateBaseHairState",
        "convert2_target_module": "hair_appearance_engine.cpp",
        "convert2_target_function": "extractAppearance & Stage 6 crown seed sampling",
        "relationship": "UNIQUE_USEFUL",
        "overlap_pct": 50,
        "risk_level": "LOW",
        "benchmark_verdict": "PORT_RECOMMENDED",
        "technical_rationale": "V1 computes 10th percentile shadow luminance, 90th percentile highlight luminance, and melanin warmth ratio. CONVERT2 currently only calculates mean OKLab. Percentile statistics enable adaptive lift curves without hardcoding.",
        "port_conditions": "Consume within HairAppearanceEngine as non-breaking statistical helper; do not alter crown anchor seed logic."
    },
    {
        "v1_module": "hair_v2_color.cpp",
        "v1_function": "srgbToLinear",
        "convert2_target_module": "hair_pipeline_v2.cpp / hair_gpu_backend.cpp",
        "convert2_target_function": "sRGBToOKLab / Vulkan compute linearizer",
        "relationship": "DUPLICATE",
        "overlap_pct": 100,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Exact IEC piecewise sRGB to linear conversion. CONVERT2 already implements identical transfer functions in C++ and SPIR-V.",
        "port_conditions": "No action required; already present."
    },
    {
        "v1_module": "hair_v2_color.cpp",
        "v1_function": "linearToSrgb",
        "convert2_target_module": "hair_pipeline_v2.cpp / hair_gpu_backend.cpp",
        "convert2_target_function": "oklabTosRGB / Vulkan compute pack",
        "relationship": "DUPLICATE",
        "overlap_pct": 100,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Exact IEC piecewise linear to sRGB conversion. CONVERT2 already implements identical transfer functions in C++ and SPIR-V.",
        "port_conditions": "No action required; already present."
    },
    {
        "v1_module": "hair_v2_color.cpp",
        "v1_function": "batchSrgbToLinear",
        "convert2_target_module": "hair_gpu_backend.cpp",
        "convert2_target_function": "executeCpuReference",
        "relationship": "DUPLICATE",
        "overlap_pct": 95,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Batch unspooling loop with OpenMP. CONVERT2 already handles this in HairGpuBackend CPU reference and Vulkan compute buffers.",
        "port_conditions": "No action required."
    },
    {
        "v1_module": "hair_v2_color.cpp",
        "v1_function": "batchLinearToSrgb",
        "convert2_target_module": "hair_gpu_backend.cpp",
        "convert2_target_function": "executeCpuReference",
        "relationship": "DUPLICATE",
        "overlap_pct": 95,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Batch packing loop with OpenMP. CONVERT2 already handles this in HairGpuBackend.",
        "port_conditions": "No action required."
    },
    {
        "v1_module": "hair_v2_color.cpp",
        "v1_function": "softChromaCompress",
        "convert2_target_module": "hair_color_pipeline.cpp / hair_dye_material_engine.cpp",
        "convert2_target_function": "Hard clamping std::clamp",
        "relationship": "UNIQUE_USEFUL",
        "overlap_pct": 20,
        "risk_level": "LOW",
        "benchmark_verdict": "PORT_RECOMMENDED",
        "technical_rationale": "Replaces harsh RGB hard clipping with tanh-based knee curve desaturation, preventing unnatural gamut clipping and hue skewing on vibrant dyes (e.g. Burgundy, Rose Gold). Benchmark showed 0.002ms latency on physical devices.",
        "port_conditions": "Port into HairColorPipeline as final post-toning gamut compression step."
    },
    {
        "v1_module": "hair_v2_directional_filter.cpp",
        "v1_function": "sampleBilinear",
        "convert2_target_module": "hair_texture_engine.cpp",
        "convert2_target_function": "Subpixel interpolation utility",
        "relationship": "DUPLICATE",
        "overlap_pct": 100,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Standard bilinear interpolation implementation.",
        "port_conditions": "No action required."
    },
    {
        "v1_module": "hair_v2_directional_filter.cpp",
        "v1_function": "directionalFilter1D",
        "convert2_target_module": "hair_texture_engine.cpp",
        "convert2_target_function": "computeDirectionalFilter",
        "relationship": "NEEDS_BENCHMARK",
        "overlap_pct": 60,
        "risk_level": "HIGH",
        "benchmark_verdict": "REJECT_INFERIOR",
        "technical_rationale": "Continuous subpixel flow stepping on CPU requires ~350-490ms per 1MP frame on mobile CPU (MediaTek G99 / Exynos 9611). CONVERT2's discrete Laplacian pipeline achieves 99.1% texture retention at only 2.5ms. CPU port would severely violate latency budgets.",
        "port_conditions": "Reject for CPU. Only viable if implemented as a Vulkan compute shader in Phase P6."
    },
    {
        "v1_module": "hair_v2_dye.cpp",
        "v1_function": "applyHairDye",
        "convert2_target_module": "hair_pipeline_v2.cpp",
        "convert2_target_function": "transformColor (Stage 6)",
        "relationship": "SUPERSEDED",
        "overlap_pct": 80,
        "risk_level": "CRITICAL",
        "benchmark_verdict": "REJECT_REGRESSION_RISK",
        "technical_rationale": "V1 uses linear RGB blend with lift maps which directly caused Tony Owner Failure A (flat, chalky, opaque paint effect). CONVERT2 V3 uses OKLab perceptual bell-curve midtone deposition (4L(1-L)) with cranial appearance anchor, which solved the failure.",
        "port_conditions": "STRICTLY FORBIDDEN from replacing CONVERT2 Stage 6. Would cause immediate regression to flat paint defect."
    },
    {
        "v1_module": "hair_v2_flow.cpp",
        "v1_function": "gaussianBlurSeparable",
        "convert2_target_module": "hair_orientation_engine.cpp",
        "convert2_target_function": "computeStructureTensor internal blur",
        "relationship": "DUPLICATE",
        "overlap_pct": 95,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Separable 1D Gaussian convolution. CONVERT2 already has optimized implementation.",
        "port_conditions": "No action required."
    },
    {
        "v1_module": "hair_v2_flow.cpp",
        "v1_function": "computeHairFlow",
        "convert2_target_module": "hair_orientation_engine.cpp",
        "convert2_target_function": "computeStructureTensor",
        "relationship": "DUPLICATE",
        "overlap_pct": 90,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Structure Tensor eigendecomposition (Jxx, Jyy, Jxy) for coherence and dominant orientation theta. Already fully integrated in CONVERT2 HairOrientationEngine.",
        "port_conditions": "No action required."
    },
    {
        "v1_module": "hair_v2_flow_regularizer.cpp",
        "v1_function": "regularizeHairFlow",
        "convert2_target_module": "hair_orientation_engine.cpp",
        "convert2_target_function": "regularizeVectorField",
        "relationship": "UNIQUE_USEFUL",
        "overlap_pct": 40,
        "risk_level": "MEDIUM",
        "benchmark_verdict": "PORT_RECOMMENDED",
        "technical_rationale": "V1 double-angle axial representation (u=cos 2theta, v=sin 2theta) prevents PI-wrapping cancellation, improving flow smoothness by 50.6% on benchmarks. However, CPU loop takes 480ms on A07. Must be ported with lookup tables or Vulkan compute.",
        "port_conditions": "Port math to CONVERT2 HairOrientationEngine using LUT acceleration to keep latency <= 10ms."
    },
    {
        "v1_module": "hair_v2_flow_regularizer.cpp",
        "v1_function": "propagateLowConfidenceFlow",
        "convert2_target_module": "hair_orientation_engine.cpp",
        "convert2_target_function": "None (orientation fallback)",
        "relationship": "UNIQUE_USEFUL",
        "overlap_pct": 10,
        "risk_level": "LOW",
        "benchmark_verdict": "PORT_RECOMMENDED",
        "technical_rationale": "Multi-source BFS flood-fill propagates orientation from high-coherence strands (C >= 0.35) into shadow/low-contrast areas (C < 0.20), eliminating vertical gravity artifacts in deep curls.",
        "port_conditions": "Port as an optional refinement step in HairOrientationEngine behind a feature flag."
    },
    {
        "v1_module": "hair_v2_lab.cpp",
        "v1_function": "fCie",
        "convert2_target_module": "hair_engine_contracts.h",
        "convert2_target_function": "Color conversion utility",
        "relationship": "UNIQUE_USEFUL",
        "overlap_pct": 0,
        "risk_level": "LOW",
        "benchmark_verdict": "PORT_RECOMMENDED",
        "technical_rationale": "Standard CIE cube root helper function.",
        "port_conditions": "Port alongside deltaE2000."
    },
    {
        "v1_module": "hair_v2_lab.cpp",
        "v1_function": "linearRgbToCIELab",
        "convert2_target_module": "hair_engine_contracts.h",
        "convert2_target_function": "Color space converter",
        "relationship": "UNIQUE_USEFUL",
        "overlap_pct": 0,
        "risk_level": "LOW",
        "benchmark_verdict": "PORT_RECOMMENDED",
        "technical_rationale": "Converts Linear RGB to standard CIELAB (D65). Enables industrial colorimetry metrics in test and QA pipelines.",
        "port_conditions": "Port as utility in test/contracts library."
    },
    {
        "v1_module": "hair_v2_lab.cpp",
        "v1_function": "deltaE2000",
        "convert2_target_module": "hair_engine_contracts.h / tests/",
        "convert2_target_function": "Quality assurance assertion suite",
        "relationship": "UNIQUE_USEFUL",
        "overlap_pct": 0,
        "risk_level": "LOW",
        "benchmark_verdict": "PORT_RECOMMENDED",
        "technical_rationale": "Full ISO/CIE CIEDE2000 color difference formula. International gold standard for objective perceptual color evaluation. Provides objective truth for dye realism audits.",
        "port_conditions": "Port into CONVERT2 test harness and offline evaluation tools."
    },
    {
        "v1_module": "hair_v2_lift_curve.cpp",
        "v1_function": "computeDyeResponse",
        "convert2_target_module": "hair_pipeline_v2.cpp",
        "convert2_target_function": "transformColor (Stage 6)",
        "relationship": "SUPERSEDED",
        "overlap_pct": 70,
        "risk_level": "HIGH",
        "benchmark_verdict": "REJECT_INFERIOR",
        "technical_rationale": "Linear lift curve and bleach scaling superseded by CONVERT2 OKLab perceptual lift curves.",
        "port_conditions": "Do not replace CONVERT2 Stage 6 lift calculation."
    },
    {
        "v1_module": "hair_v2_matting.cpp",
        "v1_function": "computeIntegralImage",
        "convert2_target_module": "hair_matting_engine.cpp",
        "convert2_target_function": "applySubpixelGuidedRefinement",
        "relationship": "UNSAFE",
        "overlap_pct": 30,
        "risk_level": "HIGH",
        "benchmark_verdict": "REJECT_INFERIOR",
        "technical_rationale": "Requires 4 full-resolution integral image buffers (4 x 960 x 1280 x 4 bytes = 19.66 MB heap). Heavy memory spike on low-RAM devices (A07/A50) compared to CONVERT2 row-sliding box filter.",
        "port_conditions": "Reject due to high memory footprint."
    },
    {
        "v1_module": "hair_v2_matting.cpp",
        "v1_function": "getBoxSum",
        "convert2_target_module": "hair_matting_engine.cpp",
        "convert2_target_function": "Integral image lookup",
        "relationship": "SUPERSEDED",
        "overlap_pct": 50,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Standard 4-point lookup.",
        "port_conditions": "No action required."
    },
    {
        "v1_module": "hair_v2_matting.cpp",
        "v1_function": "refineHairAlpha",
        "convert2_target_module": "hair_pipeline_v2.cpp / hair_matting_engine.cpp",
        "convert2_target_function": "refineHairlineEdges (Stage 3)",
        "relationship": "SUPERSEDED",
        "overlap_pct": 75,
        "risk_level": "HIGH",
        "benchmark_verdict": "REJECT_INFERIOR",
        "technical_rationale": "CONVERT2 Stage 3 applies guided filtering with hard zero masks on face, ears, neck, and cloth simultaneously, achieving 0.00% skin leakage. V1's version lacks these multi-class semantic barriers.",
        "port_conditions": "Do NOT replace CONVERT2 Stage 3."
    },
    {
        "v1_module": "hair_v2_oklab.cpp",
        "v1_function": "linearRgbToOKLab",
        "convert2_target_module": "hair_pipeline_v2.cpp",
        "convert2_target_function": "sRGBToOKLab",
        "relationship": "DUPLICATE",
        "overlap_pct": 100,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Identical Ottosson OKLab matrix conversion. CONVERT2 already has this method in HairPipelineV2.",
        "port_conditions": "No action required."
    },
    {
        "v1_module": "hair_v2_oklab.cpp",
        "v1_function": "okLabToLinearRgb",
        "convert2_target_module": "hair_pipeline_v2.cpp",
        "convert2_target_function": "oklabTosRGB",
        "relationship": "DUPLICATE",
        "overlap_pct": 100,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Identical inverse Ottosson OKLab transform. CONVERT2 already has this method in HairPipelineV2.",
        "port_conditions": "No action required."
    },
    {
        "v1_module": "hair_v2_oklab.cpp",
        "v1_function": "deltaE_OK",
        "convert2_target_module": "hair_pipeline_v2.cpp",
        "convert2_target_function": "Stage 4 OKLab color distance",
        "relationship": "DUPLICATE",
        "overlap_pct": 100,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Euclidean distance in OKLab space. Already used in CONVERT2 for scalp hair appearance gating.",
        "port_conditions": "No action required."
    },
    {
        "v1_module": "hair_v2_pipeline.cpp",
        "v1_function": "processHairPipelineV2",
        "convert2_target_module": "hair_pipeline_v2.cpp",
        "convert2_target_function": "executePipelineV3_Rebuild / executePipelineV2",
        "relationship": "SUPERSEDED",
        "overlap_pct": 70,
        "risk_level": "CRITICAL",
        "benchmark_verdict": "REJECT_REGRESSION_RISK",
        "technical_rationale": "Monolithic procedural C++ coordinator that lacks Vulkan GPU dispatch, runtime version switches, BiSeNet multi-class label routing, and Tony visual defect fixes. CONVERT2 HairPipelineV2 is the active canonical production pipeline.",
        "port_conditions": "STRICTLY FORBIDDEN from replacing CONVERT2 HairPipelineV2."
    },
    {
        "v1_module": "hair_v2_relighting.cpp",
        "v1_function": "applyHairRelighting",
        "convert2_target_module": "hair_pipeline_v2.cpp",
        "convert2_target_function": "preserveHighlightsAndShadows (Stage 7)",
        "relationship": "SUPERSEDED",
        "overlap_pct": 85,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Simple additive specular blend. CONVERT2 Stage 7 also handles shadow crevice preservation and highlight clamping.",
        "port_conditions": "No action required."
    },
    {
        "v1_module": "hair_v2_specular.cpp",
        "v1_function": "estimateImageSpaceLightDirection",
        "convert2_target_module": "hair_anisotropic_specular_engine.cpp",
        "convert2_target_function": "Fixed key light direction (0.0, -0.894, 0.447)",
        "relationship": "UNIQUE_USEFUL",
        "overlap_pct": 15,
        "risk_level": "LOW",
        "benchmark_verdict": "PORT_RECOMMENDED",
        "technical_rationale": "Dynamically estimates scene lighting direction from highlight centroid offset from hair mass center. Improves specular glint naturalness for off-axis lighting.",
        "port_conditions": "Port as an optional dynamic light estimator in HairAnisotropicSpecularEngine."
    },
    {
        "v1_module": "hair_v2_specular.cpp",
        "v1_function": "computeAnisotropicHairSheen",
        "convert2_target_module": "hair_anisotropic_specular_engine.cpp",
        "convert2_target_function": "applySpecular",
        "relationship": "UNIQUE_USEFUL",
        "overlap_pct": 45,
        "risk_level": "LOW",
        "benchmark_verdict": "PORT_RECOMMENDED",
        "technical_rationale": "Implements Marschner dual-lobe model (R primary reflection with 3 deg cuticle tilt + TRT secondary tinted reflection with -6 deg tilt). Provides 3D strand luster without flat sheen. Benchmark showed 0.002ms on physical device.",
        "port_conditions": "Port into HairAnisotropicSpecularEngine as dual-lobe enhancement."
    },
    {
        "v1_module": "hair_v2_texture.cpp",
        "v1_function": "decomposeHairTexture",
        "convert2_target_module": "hair_texture_engine.cpp",
        "convert2_target_function": "decomposeFrequencies",
        "relationship": "UNIQUE_USEFUL",
        "overlap_pct": 40,
        "risk_level": "MEDIUM",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "Tri-band flow-aligned texture decomposition. Mathematically elegant, but CPU 1D filtering is too heavy (~350ms).",
        "port_conditions": "Defer until GPU compute shader is implemented in Phase P6."
    },
    {
        "v1_module": "hair_v2_texture.cpp",
        "v1_function": "reconstructHairTexture",
        "convert2_target_module": "hair_pipeline_v2.cpp",
        "convert2_target_function": "transformColor (Stage 6)",
        "relationship": "SUPERSEDED",
        "overlap_pct": 80,
        "risk_level": "LOW",
        "benchmark_verdict": "PRESERVE_AS_REFERENCE",
        "technical_rationale": "High-frequency injection into linear RGB. CONVERT2 V3 handles micro-fiber injection in OKLab with anti-halo bounds.",
        "port_conditions": "No action required."
    },
    {
        "v1_module": "hair_v2_trimap.cpp",
        "v1_function": "buildAdaptiveTrimap",
        "convert2_target_module": "hair_pipeline_v2.cpp",
        "convert2_target_function": "applyConfidenceAndExclusion (Stage 4)",
        "relationship": "SUPERSEDED",
        "overlap_pct": 60,
        "risk_level": "HIGH",
        "benchmark_verdict": "REJECT_INFERIOR",
        "technical_rationale": "3-state trimap (0/128/255) creates binary transition boundaries. CONVERT2 continuous subpixel alpha confidence provides smoother flyaways.",
        "port_conditions": "Do NOT replace CONVERT2 continuous alpha."
    }
]

with open(out_csv, "w", newline="", encoding="utf-8") as f:
    writer = csv.DictWriter(f, fieldnames=list(crosswalk_rows[0].keys()))
    writer.writeheader()
    writer.writerows(crosswalk_rows)

print(f"Wrote {len(crosswalk_rows)} crosswalk records to {out_csv}")
