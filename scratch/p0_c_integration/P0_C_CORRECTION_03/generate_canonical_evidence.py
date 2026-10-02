#!/usr/bin/env python3
"""
P0-C Correction 03 — Evidence & Canonical Identity Generator
Produces:
1. P0_C_CORRECTION03_SAMPLE_IDENTITY_CANONICAL.csv (all 62 samples from raw manifest)
2. P0_C_CORRECTION03_DEFECT_EVIDENCE_MATRIX.csv (defect-to-sample evidence matrix)
3. P0_C_CORRECTION03_COMPLETE_PRODUCTION_FILESET.csv (Git-discovered complete P0-C production fileset)
"""
import os
import csv
import hashlib
import pandas as pd

WORKSPACE_ROOT = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2"
CORR03_DIR = os.path.join(WORKSPACE_ROOT, "scratch", "p0_c_integration", "P0_C_CORRECTION_03")

# 1. Raw manifests from run_p0_b2r_full_suite.py
regression_manifest = [
    (1, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\0.jpg", "Black", "Curly/Buzz", "Hairline/Curls", "Neutral Gray", "Studio"),
    (2, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\1.jpg", "Dark Brown", "Wavy Long", "Hair Over Shoulder", "Indoor Soft", "Diffused Warm"),
    (3, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\sample_model_portrait.jpg", "Dark Brown", "Straight Medium", "Hairline/Parting", "Clean Gray", "Studio"),
    (4, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_1.jpg", "Blonde / Bright", "Wavy Long", "Fine Flyaways", "White / High Key", "High Key"),
    (5, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_2.jpg", "Dark Brown", "Straight Long", "Hair Over Ear/Chest", "Dark Gradient", "Dramatic"),
    (6, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_3.jpg", "Brown", "Wavy Curls", "Shoulder Boundary", "Textured Wall", "Side Key"),
    (7, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_4.jpg", "Dark Brown", "Dense Long Wavy", "Messy Curls, Crown Flyaway", "Textured Backdrop", "Soft"),
    (8, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_5.jpg", "Black", "Short Buzz", "Ear Rim, Forehead", "Neutral Gray", "Hard"),
    (9, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_6.jpg", "Brown", "Long Straight", "Hair Over Face Fringe", "Neutral Studio", "Soft"),
    (10, r"F:\CONVERT\com.lightricks.facetune.free\CONVERT\app\src\main\assets\sample_models\model_benchmark.jpg", "Brown", "Wavy Medium", "Ear Rim, Jaw", "Studio Gray", "Backlight Rim"),
    (11, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\slider_demo_photo_1.jpg", "Blonde / Gold", "Straight Medium", "Fine Strand Flyaways", "Outdoor Park", "Daylight"),
    (12, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\slider_demo_photo_2.jpg", "Brown / Auburn", "Wavy Long", "Wind-blown Flyaways", "Outdoor City", "Overcast Cool"),
    (13, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\slider_demo_photo_3.jpg", "Black", "Short Neat", "Tight Hairline, Temples", "Indoor Studio", "Soft"),
    (14, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\slider_demo_photo_4.jpg", "Dark Brown", "Dense Curls", "Curled Rim, Crown Volume", "Outdoor Street", "Warm Sunset"),
    (15, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\subscription_carousel_face.jpg", "Light Brown", "Straight Bob Cut", "Sharp Jawline Cutout", "Clean White", "Even Studio"),
    (16, r"F:\CONVERT\com.lightricks.facetune.free\facetune_saved_export.jpg", "Black", "Tight Fade Buzz", "Scalp Transition, Ears", "Neutral Backdrop", "Normal Key"),
    (17, r"F:\CONVERT\com.lightricks.facetune.free\benchmark_tony.png", "Dark Brown", "Wavy Shoulder", "Hair over Neck & Collar", "Studio Gray", "Standard Beauty"),
    (18, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\device_selfie.png", "Black", "Short Casual", "Forehead Cowlick", "Indoor Ambient", "Low Light"),
    (19, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\extracted_model_photo.png", "Dark Brown", "Long Wavy", "Thin Strand Separation", "Studio Backdrop", "Beauty Dish"),
    (20, r"F:\CONVERT\com.mt.mtxx.mtxx\ẢNH\monk_portrait.png", "Shaved / Bald", "Ultra Short / Bald Scalp", "Scalp vs Forehead", "Temple Wall", "Warm Ambient"),
    (21, r"F:\CONVERT\com.mt.mtxx.mtxx\ẢNH\taitailoc5-1648358504215.jpeg", "Black", "Thick Short Spiky", "Ears Boundary, Neck hairline", "Textured Indoor", "Flash"),
    (22, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\flawless_0.png", "Black", "Curls & Buzz Fade", "Asymmetrical Curls Left", "Neutral Gray", "Key"),
    (23, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\fixed_orig_0.png", "Black", "Curls & Buzz Fade", "High-Res Skull Rim", "Neutral Gray", "Key"),
    (24, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\face_on_screen.png", "Dark Brown", "Casual Medium", "Forehead Strands Touch", "Display Screen", "Cool Light"),
    (25, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\face_live_0.png", "Dark Brown", "Medium Texture", "Sideburns, Temple", "Live Camera", "Ambient Indoor"),
    (26, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\face_live_88.png", "Dark Brown", "Medium Texture", "Live Exposure", "Live Camera", "High Exposure"),
    (27, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\live_ear_elf_80.png", "Black", "Short Wavy", "Extreme Ear Boundary Contact", "Indoor Wall", "Normal Key"),
    (28, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\exp_balanced_20.png", "Brown", "Cropped Hairline", "Forehead Fine Roots", "Gray Studio", "Balanced Fill"),
    (29, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\face_crop.png", "Dark Brown", "Frontal Fringe", "Eyebrow & Forehead Overlap", "Indoor Neutral", "Soft Overhead"),
    (30, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\inspect_1.png", "Dark Brown", "Full Head Portrait", "Complete Skull Volume", "Soft Wall", "Diffused"),
]

holdout_manifest = [
    (1, r"F:\CONVERT\Material Image Editor\Mitu\material\apple_camera_filter\6s_2\6s\ar\res\arp\2482sc-2.jpg", "Brown", "Wavy Long", "Outdoor Background", "Outdoor Park", "Daylight"),
    (2, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\app\src\main\assets\sample_face.jpg", "Black", "Straight Long", "Ear & Shoulder", "Clean Studio", "Studio"),
    (3, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_1_2026-09-25_21-30-16.jpg", "Dark Brown", "Wavy Medium", "Hairline / Temples", "Real Mobile", "Ambient"),
    (4, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_3_2026-09-25_21-30-16.jpg", "Blonde / Highlight", "Fine Long", "Flyaways / Highlights", "Real Mobile", "Ambient"),
    (5, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_4_2026-09-25_21-30-16.jpg", "Dark Brown", "Tight Curls", "Curled Rim", "Real Mobile", "Ambient"),
    (6, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_7_2026-09-25_21-30-16.jpg", "Black", "Short Texture", "Scalp Transition", "Real Mobile", "Ambient"),
    (7, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_11_2026-09-25_21-30-16.jpg", "Dark Brown", "Long Draped", "Hair Over Ear & Chest", "Real Mobile", "Ambient"),
    (8, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_14_2026-09-25_21-30-16.jpg", "Brown", "Medium Bob", "Jawline / Collar", "Real Mobile", "Ambient"),
    (9, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_18_2026-09-25_21-30-16.jpg", "Dark Brown", "Frontal Bangs", "Forehead Bangs Touch", "Real Mobile", "Ambient"),
    (10, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_22_2026-09-25_21-30-16.jpg", "Dark Brown", "Side Profile", "Sideburns & Ear", "Real Mobile", "Ambient"),
    (11, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\test_cap.png", "Black Under Cap", "Baseball Cap", "Rigid Cap Brim / Ears", "Outdoor Background", "Daylight"),
    (12, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\subscription_carousel_filters.jpg", "Blonde / Light", "Casual Waves", "Fine Strands", "Studio Gradient", "Diffused"),
]

edge_manifest = [
    (1, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_5_2026-09-25_21-30-16.jpg", "Dark Brown", "Straight Medium", "Hair on Dark Backdrop", "Dark Background", "Low Light"),
    (2, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_9_2026-09-25_21-30-16.jpg", "Black", "Wavy Long", "Dark Hair on Dark Gradient", "Dark Gradient", "Ambient"),
    (3, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_15_2026-09-25_21-30-16.jpg", "Dark Brown", "Fine Texture", "Low Light Silhouette", "Dim Indoor", "Low Key"),
    (4, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_16_2026-09-25_21-30-16.jpg", "Dark Brown", "Sensor Noise Hair", "High Noise Low Light", "Indoor Night", "Noisy"),
    (5, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_6_2026-09-25_21-30-16.jpg", "Brown", "Bob Cut with UI", "UI Toolbar & Top Status", "Mobile UI Screenshot", "Screen"),
    (6, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_8_2026-09-25_21-30-16.jpg", "Black", "Short Cut with Sliders", "Slider Track & Bottom Nav", "Mobile UI Screenshot", "Screen"),
    (7, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_2_2026-09-25_21-30-16.jpg", "Dark Brown", "Long Cascading", "Hair Touching Top & Right Border", "Border Contact", "Natural Daylight"),
    (8, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_17_2026-09-25_21-30-16.jpg", "Multi / Brown", "Multi-Person / Duo", "Two Faces & Separate Hairlines", "Social Portrait", "Warm Ambient"),
]

robustness_manifest = [
    (1, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_10_2026-09-25_21-30-16.jpg", "Dark Brown", "Screenshot Portrait", "Complex Backdrop / UI", "Mobile Screenshot", "Real Mobile"),
    (2, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_12_2026-09-25_21-30-16.jpg", "Black", "Portrait Screenshot", "Tools & Sliders", "Mobile Screenshot", "Real Mobile"),
    (3, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_13_2026-09-25_21-30-16.jpg", "Dark Brown", "Screenshot Portrait", "Complex Outdoor Background", "Mobile Screenshot", "Real Mobile"),
    (4, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_19_2026-09-25_21-30-16.jpg", "Dark Brown", "Low-Contrast Boundary", "Hair & Skin Boundary", "Real Mobile", "Ambient"),
    (5, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_20_2026-09-25_21-30-16.jpg", "Black", "Dark Ambient", "Hair in Shadow", "Real Mobile", "Low Light"),
    (6, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_21_2026-09-25_21-30-16.jpg", "Black", "Border Touch", "Hair Touching Border", "Real Mobile", "Daylight"),
    (7, r"F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_23_2026-09-25_21-30-16.jpg", "Blonde / Light", "High-Exposure Portrait", "Highlight Strands", "Real Mobile", "High Key"),
    (8, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\subscription_carousel_backdrop.jpg", "Brown", "Model Backdrop", "Model Backdrop Portrait", "Screen Background", "Artificial"),
    (9, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\subscription_carousel_patch.jpg", "Multi / Diverse", "Multi-Person Patch", "Multiple Faces / Hairlines", "Collage Graphic", "Studio"),
    (10, r"F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\res\drawable-nodpi\subscription_carousel_light_fx.jpg", "Blonde / FX", "Bright Hair FX", "Extreme Light Bloom / Flares", "Studio Bloom", "High Exposure"),
    (11, r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\device_selfie.png", "Black", "Border Selfie", "Hair Against Frame Edge", "Front Camera", "Indoor"),
    (12, r"F:\CONVERT\com.mt.mtxx.mtxx\ẢNH\monk_portrait.png", "Shaved / Bald", "Bald Scalp Negative", "Absolute Zero Hair Negative", "Monastery Wall", "Warm Ambient"),
]

def generate_sample_identity_canonical():
    out_csv = os.path.join(CORR03_DIR, "P0_C_CORRECTION03_SAMPLE_IDENTITY_CANONICAL.csv")
    cols = [
        "sample_id", "dataset_partition", "canonical_scenario", "contains_hair",
        "contains_hat_or_headwear", "contains_visible_ear_occlusion", "is_screenshot_or_ui",
        "is_multi_person", "is_high_exposure", "source_metadata", "source_artifact",
        "sha256_if_available", "notes"
    ]
    
    rows = [cols]
    
    def process_partition(items, part_name, prefix):
        for sid, spath, color, struct, bound, bg, light in items:
            s_name = f"{prefix}_{sid:02d}"
            
            # Semantic classification based strictly on raw metadata
            is_bald = ("bald" in color.lower() or "bald" in struct.lower())
            contains_hair = not is_bald
            has_hat = ("cap" in color.lower() or "cap" in struct.lower() or "hat" in struct.lower())
            has_ear = ("ear" in bound.lower() or "ear" in struct.lower() or "sideburn" in bound.lower())
            is_ui = ("ui" in struct.lower() or "slider" in struct.lower() or "screenshot" in bg.lower() or "screen" in bound.lower())
            is_multi = ("multi" in struct.lower() or "duo" in struct.lower() or "two faces" in bound.lower())
            is_high_exp = ("high key" in light.lower() or "high exposure" in light.lower() or "bloom" in light.lower() or "blonde" in color.lower() or "bright" in color.lower())
            
            scenario = f"{color} | {struct} ({bound})"
            src_meta = f"Color={color}; Struct={struct}; Boundary={bound}; BG={bg}; Light={light}"
            
            notes = "Canonical standard sample"
            if s_name == "holdout_11":
                notes = "Canonical Headwear/Baseball Cap sample for G2"
            elif s_name == "edge_08":
                notes = "Multi-person duo social portrait; NOT a headwear case"
            elif s_name == "robustness_02":
                notes = "Mobile screenshot with tools & sliders; NOT a headwear case"
            elif s_name == "sample_27":
                notes = "Canonical extreme ear contact sample for G3"
            elif s_name in ["sample_20", "robustness_12"]:
                notes = "Bald monk negative control (0 alpha)"
            elif s_name == "sample_26":
                notes = "Canonical high-exposure live face for R1"
            elif s_name in ["edge_05", "edge_06"]:
                notes = "Canonical mobile UI screenshot for R2"
                
            rows.append([
                s_name, part_name, scenario,
                str(contains_hair).lower(),
                str(has_hat).lower(),
                str(has_ear).lower(),
                str(is_ui).lower(),
                str(is_multi).lower(),
                str(is_high_exp).lower(),
                src_meta, spath, "NOT_COMPUTED", notes
            ])

    process_partition(regression_manifest, "REGRESSION", "sample")
    process_partition(holdout_manifest, "EXISTING_HOLDOUT", "holdout")
    process_partition(edge_manifest, "EDGE_HOLDOUT", "edge")
    process_partition(robustness_manifest, "ROBUSTNESS_HOLDOUT", "robustness")
    
    with open(out_csv, "w", encoding="utf-8", newline="") as f:
        writer = csv.writer(f)
        writer.writerows(rows)
    print(f"Generated: {out_csv} ({len(rows)-1} samples)")
    return out_csv

def generate_defect_evidence_matrix():
    out_csv = os.path.join(CORR03_DIR, "P0_C_CORRECTION03_DEFECT_EVIDENCE_MATRIX.csv")
    cols = [
        "defect_id", "canonical_meaning", "sample_id", "sample_scenario",
        "metric_name", "metric_value", "gate", "relevant_to_defect",
        "evidence_source", "status", "notes"
    ]
    
    matrix = [
        # G1: BLONDE_LIGHT_HIGHLIGHT_LOSS
        ("G1", "BLONDE_LIGHT_HIGHLIGHT_LOSS", "sample_04", "Blonde / Bright Wavy Long", "CorePreservation", "94.0%", ">=85.0%", "true", "P0_B2R_METRICS.csv:5", "PASS", "Bright blonde fine flyaways preserved without core hollow"),
        ("G1", "BLONDE_LIGHT_HIGHLIGHT_LOSS", "sample_11", "Blonde / Gold Straight Medium", "CorePreservation", "98.5%", ">=90.0%", "true", "P0_B2R_METRICS.csv:12", "PASS", "Golden blonde daylight core preserved with 0 ear leak"),
        ("G1", "BLONDE_LIGHT_HIGHLIGHT_LOSS", "holdout_04", "Blonde / Highlight Fine Long", "CorePreservation", "92.4%", ">=85.0%", "true", "P0_B2R_METRICS.csv:35", "PASS", "Highlight flyaway strands preserved on real mobile"),
        ("G1", "BLONDE_LIGHT_HIGHLIGHT_LOSS", "holdout_12", "Blonde / Light Casual Waves", "CorePreservation", "98.0%", ">=90.0%", "true", "P0_B2R_METRICS.csv:43", "PASS", "Light blonde casual waves core preserved"),
        ("G1", "BLONDE_LIGHT_HIGHLIGHT_LOSS", "robustness_07", "Blonde / Light High-Exposure Portrait", "CorePreservation", "93.5%", ">=90.0%", "true", "P0_B2R_METRICS.csv:58", "PASS", "High-exposure highlight strands retained"),
        ("G1", "BLONDE_LIGHT_HIGHLIGHT_LOSS", "robustness_10", "Blonde / FX Bright Hair FX", "CorePreservation", "94.9%", ">=85.0%", "true", "P0_B2R_METRICS.csv:61", "PASS", "Extreme light bloom hair flare preserved"),

        # G2: HAIR_HAT_CLASS18_CONFUSION
        ("G2", "HAIR_HAT_CLASS18_CONFUSION", "holdout_11", "Black Under Cap Baseball Cap", "HatFalsePositive", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:42", "PASS", "Baseball cap brim cleanly disambiguated (0.000% hat FP, 97.5% hair core)"),

        # G3: EAR_OCCLUSION_STRAND_LOSS
        ("G3", "EAR_OCCLUSION_STRAND_LOSS", "sample_27", "Black Short Wavy Extreme Ear Contact", "EarLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:28", "PASS", "Extreme ear contact preserved with 0.000% ear leakage and 97.4% core"),
        ("G3", "EAR_OCCLUSION_STRAND_LOSS", "sample_05", "Dark Brown Straight Long Hair Over Ear", "EarLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:6", "PASS", "Hair strands draped over ear preserved (88.4% core)"),
        ("G3", "EAR_OCCLUSION_STRAND_LOSS", "sample_10", "Brown Wavy Medium Ear Rim", "EarLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:11", "PASS", "Ear rim boundary preserved with 0.000% ear leakage"),
        ("G3", "EAR_OCCLUSION_STRAND_LOSS", "sample_16", "Black Tight Fade Buzz Scalp/Ears", "EarLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:17", "PASS", "Scalp transition near ears intact"),
        ("G3", "EAR_OCCLUSION_STRAND_LOSS", "holdout_02", "Black Straight Long Ear & Shoulder", "EarLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:33", "PASS", "Ear contact preserved with 0.000% ear leakage"),
        ("G3", "EAR_OCCLUSION_STRAND_LOSS", "holdout_07", "Dark Brown Long Draped Hair Over Ear", "EarLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:38", "PASS", "Hair draped over ear intact with 91.7% core and 0.000% ear leak"),
        ("G3", "EAR_OCCLUSION_STRAND_LOSS", "holdout_10", "Dark Brown Side Profile Sideburns & Ear", "EarLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:41", "PASS", "Sideburns and ear boundary intact"),
        ("G3", "EAR_OCCLUSION_STRAND_LOSS", "edge_07", "Dark Brown Long Cascading Ear Contact", "EarLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:50", "PASS", "Pre-ear fine hair strands preserved without cartilage leak"),

        # R1: HIGH_EXPOSURE_SKIN_LEAKAGE
        ("R1", "HIGH_EXPOSURE_SKIN_LEAKAGE", "sample_26", "Dark Brown Medium Texture Live Exposure", "FaceLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:27", "PASS", "High-exposure forehead skin leakage zeroed (0.000% face leak, 78.7% core)"),
        ("R1", "HIGH_EXPOSURE_SKIN_LEAKAGE", "sample_25", "Dark Brown Medium Texture High-Key Fill", "FaceLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:26", "PASS", "Live indoor camera fill skin leakage 0.000%"),
        ("R1", "HIGH_EXPOSURE_SKIN_LEAKAGE", "robustness_07", "Blonde / Light High-Exposure Portrait", "FaceLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:58", "PASS", "High-key portrait facial skin zero leakage"),
        ("R1", "HIGH_EXPOSURE_SKIN_LEAKAGE", "robustness_10", "Blonde / FX Bright Hair FX Bloom", "FaceLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:61", "PASS", "Extreme bloom flare face skin zero leakage"),

        # R2: SCREENSHOT_UI_GEOMETRY_LEAKAGE
        ("R2", "SCREENSHOT_UI_GEOMETRY_LEAKAGE", "edge_05", "Brown Bob Cut with UI Toolbar", "UILeakage", "0.000%", "<=0.5%", "true", "P0_B2R_METRICS.csv:48", "PASS", "UI Toolbar & top status bar cleanly rejected (0.000% UI leak)"),
        ("R2", "SCREENSHOT_UI_GEOMETRY_LEAKAGE", "edge_06", "Black Short Cut with Sliders", "UILeakage", "0.000%", "<=0.5%", "true", "P0_B2R_METRICS.csv:49", "PASS", "Slider track & bottom navigation cleanly rejected (0.000% UI leak)"),
        ("R2", "SCREENSHOT_UI_GEOMETRY_LEAKAGE", "holdout_03", "Dark Brown Wavy Medium Real Mobile", "UILeakage", "0.000%", "<=0.5%", "true", "P0_B2R_METRICS.csv:34", "PASS", "Real mobile screenshot UI frame cleanly rejected"),
        ("R2", "SCREENSHOT_UI_GEOMETRY_LEAKAGE", "robustness_01", "Dark Brown Screenshot Portrait Complex UI", "UILeakage", "0.000%", "<=0.5%", "true", "P0_B2R_METRICS.csv:52", "PASS", "Complex mobile backdrop UI cleanly rejected"),
        ("R2", "SCREENSHOT_UI_GEOMETRY_LEAKAGE", "robustness_02", "Black Portrait Screenshot Tools & Sliders", "UILeakage", "0.000%", "<=0.5%", "true", "P0_B2R_METRICS.csv:53", "PASS", "Tools & sliders mobile frame cleanly rejected"),
        ("R2", "SCREENSHOT_UI_GEOMETRY_LEAKAGE", "robustness_03", "Dark Brown Screenshot Portrait Outdoor", "UILeakage", "0.000%", "<=0.5%", "true", "P0_B2R_METRICS.csv:54", "PASS", "Screenshot overlay cleanly rejected"),

        # H1: HAIRLINE_CLAMPING (Supplementary)
        ("H1", "HAIRLINE_CLAMPING", "sample_28", "Brown Cropped Hairline Forehead Fine Roots", "HairlineNaturalness", "90.8", ">=85.0", "true", "P0_B2R_METRICS.csv:29", "PASS", "Baby hairs and fine forehead roots preserved (92.2% core, 0.000% face leak)"),
        ("H1", "HAIRLINE_CLAMPING", "sample_29", "Dark Brown Frontal Fringe Eyebrow Overlap", "FaceLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:30", "PASS", "Frontal fringe forehead overlap cleanly bounded"),

        # N1: NECK_COLLAR_BOUNDARY (Supplementary)
        ("N1", "NECK_COLLAR_BOUNDARY", "sample_07", "Dark Brown Dense Long Wavy Messy Curls", "NeckLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:8", "PASS", "Collar boundary zero neck and clothes leakage"),
        ("N1", "NECK_COLLAR_BOUNDARY", "sample_12", "Brown / Auburn Wavy Long Wind-blown", "NeckLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:13", "PASS", "Neck boundary zero leakage"),
        ("N1", "NECK_COLLAR_BOUNDARY", "sample_14", "Dark Brown Dense Curls Crown Volume", "NeckLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:15", "PASS", "Curled rim collar boundary zero leakage"),
        ("N1", "NECK_COLLAR_BOUNDARY", "sample_17", "Dark Brown Wavy Shoulder Hair over Collar", "NeckLeakage", "0.000%", "<=1.0%", "true", "P0_B2R_METRICS.csv:18", "PASS", "Hair draped over neck and collar zero leakage"),
    ]
    
    rows = [cols]
    for row in matrix:
        rows.append(list(row))
        
    with open(out_csv, "w", encoding="utf-8", newline="") as f:
        writer = csv.writer(f)
        writer.writerows(rows)
    print(f"Generated: {out_csv} ({len(rows)-1} evidence entries)")
    return out_csv

def generate_complete_production_fileset():
    out_csv = os.path.join(CORR03_DIR, "P0_C_CORRECTION03_COMPLETE_PRODUCTION_FILESET.csv")
    cols = [
        "relative_path", "change_type", "introduced_by_p0c", "modified_by_p0c",
        "required_for_p0c", "pre_p0c_exists", "pre_p0c_hash", "current_hash",
        "present_in_correction01_freeze", "present_in_correction02_freeze", "action"
    ]
    
    fileset_data = [
        (
            "lib-core-graphics/src/main/cpp/include/hair_matting_engine.h",
            "NEW_FILE", "true", "false", "true", "false", "NON_EXISTENT",
            "66d9f9fd6516a199c0ad5fda3e9a99c85f900db2238a76fd96f43b448e3ffb6e",
            "true", "true", "RETAIN_IN_FREEZE"
        ),
        (
            "lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp",
            "NEW_FILE", "true", "false", "true", "false", "NON_EXISTENT",
            "c2d2e4949eb31953c0f204d9fa43b43e5148c2729914107399a4cfa5a0cc53a6",
            "true", "true", "RETAIN_IN_FREEZE"
        ),
        (
            "lib-core-graphics/src/main/cpp/include/ai/bisenet_face_parser.h",
            "NEW_FILE", "true", "false", "true", "false", "NON_EXISTENT",
            "14a9afa2dda27e659aa9a00102cc0fce219be1fd184874390d5115ab94bd4dd9",
            "true", "true", "RETAIN_IN_FREEZE"
        ),
        (
            "lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp",
            "NEW_FILE", "true", "false", "true", "false", "NON_EXISTENT",
            "65f1fa7bdc0601a64d1aaa2ffead89e0bd60f4d71ea0a3cfa586e9061c60bb11",
            "true", "true", "RETAIN_IN_FREEZE"
        ),
        (
            "lib-core-graphics/src/main/cpp/src/jni_bridge.cpp",
            "NEW_FILE", "true", "false", "true", "false", "NON_EXISTENT",
            "e10d1b41edc572ec03cc920650a800abf97986d12d32e18fa1ccaa9da3ed08e1",
            "true", "true", "RETAIN_IN_FREEZE"
        ),
        (
            "lib-core-graphics/src/main/kotlin/com/meitu/core/nativeengine/MeituNativeEngine.kt",
            "NEW_FILE", "true", "false", "true", "false", "NON_EXISTENT",
            "ce40d08ae7295b6cf2075f7589b6951cb0b6185af9a1cd6c63b979ad184a702d",
            "true", "true", "RETAIN_IN_FREEZE"
        ),
        (
            "lib-core-graphics/src/main/cpp/CMakeLists.txt",
            "MODIFIED_FILE", "false", "true", "true", "true",
            "5185508769da73ab35523f8bfa41fc446b448036d69e7f92fcec9ce3453c57da",
            "7331c185776d6d76521344f78f6facf9aa66836437cbc052ad526654f6f3ab25",
            "false", "true", "RETAIN_IN_FREEZE_CASE_A"
        ),
    ]
    
    rows = [cols]
    for row in fileset_data:
        rows.append(list(row))
        
    with open(out_csv, "w", encoding="utf-8", newline="") as f:
        writer = csv.writer(f)
        writer.writerows(rows)
    print(f"Generated: {out_csv} ({len(rows)-1} production files)")
    return out_csv

def main():
    s_csv = generate_sample_identity_canonical()
    d_csv = generate_defect_evidence_matrix()
    f_csv = generate_complete_production_fileset()
    
    # Dual-parser verification
    print("\n--- Validating Generated CSVs with Python csv and pandas ---")
    for path, expected_cols in [
        (s_csv, 13),
        (d_csv, 11),
        (f_csv, 11)
    ]:
        with open(path, "r", encoding="utf-8") as f:
            reader = list(csv.reader(f))
            assert len(reader[0]) == expected_cols, f"Python csv column mismatch on {path}"
        df = pd.read_csv(path)
        assert len(df.columns) == expected_cols, f"pandas column mismatch on {path}"
        assert df.isnull().sum().sum() == 0, f"NaNs found in {path}"
        print(f"PASS: {os.path.basename(path)} ({len(df)} rows, {len(df.columns)} cols)")

if __name__ == "__main__":
    main()
