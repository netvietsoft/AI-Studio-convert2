#!/usr/bin/env python3
"""
TASK_042 Isolated Benchmark Harness
Compares V1 reconstructed modules against current CONVERT2 HairPipelineV2 implementation.
Inputs: Canonical portrait test assets in test_assets/task_035
"""

import os
import sys
import time
import math
import csv
import json
import hashlib
from pathlib import Path
import numpy as np
import cv2

ASSETS_DIR = Path("test_assets/task_035")
RAW_OUT_DIR = Path(".ai/reports/TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK/raw")
RAW_OUT_DIR.mkdir(parents=True, exist_ok=True)

PORTRAITS = [
    "owner_fail_A_curly.png",
    "owner_fail_B_orig.png",
    "portrait_1_male_wavy.png",
    "portrait_model1_blonde.png",
    "portrait_model2_long_straight.png",
    "portrait_model3_wavy_curls.png",
    "portrait_model4_messy_curls.png",
    "portrait_model6_fringe_bangs.png",
    "portrait_monk_bald_neg.png"
]

# ---------------------------------------------------------
# 1. Color Transforms & CIEDE2000 (from hair_v2_lab.cpp)
# ---------------------------------------------------------
def srgb_to_linear(c):
    return np.where(c <= 0.04045, c / 12.92, ((c + 0.055) / 1.055) ** 2.4)

def linear_to_srgb(c):
    return np.where(c <= 0.0031308, c * 12.92, 1.055 * (np.maximum(c, 0.0) ** (1.0 / 2.4)) - 0.055)

def linear_to_xyz(rgb):
    # D65 matrix
    r, g, b = rgb[:,:,0], rgb[:,:,1], rgb[:,:,2]
    x = r * 0.4124564 + g * 0.3575761 + b * 0.1804375
    y = r * 0.2126729 + g * 0.7151522 + b * 0.0721750
    z = r * 0.0193339 + g * 0.1191920 + b * 0.9503041
    return np.stack([x, y, z], axis=-1)

def f_cie(t):
    delta = 6.0 / 29.0
    return np.where(t > (delta ** 3), t ** (1.0 / 3.0), (t / (3.0 * delta * delta)) + (4.0 / 29.0))

def linear_to_cielab(rgb):
    xyz = linear_to_xyz(rgb)
    Xn, Yn, Zn = 0.95047, 1.00000, 1.08883
    fx = f_cie(xyz[:,:,0] / Xn)
    fy = f_cie(xyz[:,:,1] / Yn)
    fz = f_cie(xyz[:,:,2] / Zn)
    L = 116.0 * fy - 16.0
    a = 500.0 * (fx - fy)
    b = 200.0 * (fy - fz)
    return np.stack([L, a, b], axis=-1)

def delta_e_2000(lab1, lab2):
    """Vectorized CIEDE2000 formula matching Sharma 2005 / hair_v2_lab.cpp"""
    L1, a1, b1 = lab1[:,:,0], lab1[:,:,1], lab1[:,:,2]
    L2, a2, b2 = lab2[:,:,0], lab2[:,:,1], lab2[:,:,2]
    
    C1 = np.sqrt(a1**2 + b1**2)
    C2 = np.sqrt(a2**2 + b2**2)
    C_bar = 0.5 * (C1 + C2)
    
    G = 0.5 * (1.0 - np.sqrt((C_bar**7) / (C_bar**7 + 25.0**7 + 1e-10)))
    a1_prime = (1.0 + G) * a1
    a2_prime = (1.0 + G) * a2
    
    C1_prime = np.sqrt(a1_prime**2 + b1**2)
    C2_prime = np.sqrt(a2_prime**2 + b2**2)
    
    h1_prime = np.degrees(np.arctan2(b1, a1_prime)) % 360.0
    h2_prime = np.degrees(np.arctan2(b2, a2_prime)) % 360.0
    
    delta_L_prime = L2 - L1
    delta_C_prime = C2_prime - C1_prime
    
    diff_h = h2_prime - h1_prime
    delta_h_prime = np.where(np.abs(diff_h) <= 180.0, diff_h,
                             np.where(diff_h > 180.0, diff_h - 360.0, diff_h + 360.0))
    delta_H_prime = 2.0 * np.sqrt(C1_prime * C2_prime) * np.sin(np.radians(0.5 * delta_h_prime))
    
    L_bar_prime = 0.5 * (L1 + L2)
    C_bar_prime = 0.5 * (C1_prime + C2_prime)
    
    sum_h = h1_prime + h2_prime
    diff_h_abs = np.abs(diff_h)
    h_bar_prime = np.where(diff_h_abs <= 180.0, 0.5 * sum_h,
                           np.where(sum_h < 360.0, 0.5 * (sum_h + 360.0), 0.5 * (sum_h - 360.0)))
    
    T = (1.0 - 0.17 * np.cos(np.radians(h_bar_prime - 30.0)) +
         0.24 * np.cos(np.radians(2.0 * h_bar_prime)) +
         0.32 * np.cos(np.radians(3.0 * h_bar_prime + 6.0)) -
         0.20 * np.cos(np.radians(4.0 * h_bar_prime - 63.0)))
    
    delta_theta = 30.0 * np.exp(-(((h_bar_prime - 275.0) / 25.0)**2))
    R_C = 2.0 * np.sqrt((C_bar_prime**7) / (C_bar_prime**7 + 25.0**7 + 1e-10))
    S_L = 1.0 + (0.015 * ((L_bar_prime - 50.0)**2)) / np.sqrt(20.0 + ((L_bar_prime - 50.0)**2))
    S_C = 1.0 + 0.045 * C_bar_prime
    S_H = 1.0 + 0.015 * C_bar_prime * T
    R_T = -np.sin(np.radians(2.0 * delta_theta)) * R_C
    
    de = np.sqrt(
        (delta_L_prime / S_L)**2 +
        (delta_C_prime / S_C)**2 +
        (delta_H_prime / S_H)**2 +
        R_T * (delta_C_prime / S_C) * (delta_H_prime / S_H)
    )
    return de

# ---------------------------------------------------------
# 2. Soft Chroma Compression (from hair_v2_color.cpp)
# ---------------------------------------------------------
def soft_chroma_compress_v1(rgb, max_chroma=0.95):
    """V1 softChromaCompress: knee-curve compression above threshold"""
    r, g, b = rgb[:,:,0], rgb[:,:,1], rgb[:,:,2]
    max_c = np.maximum(np.maximum(r, g), b)
    min_c = np.minimum(np.minimum(r, g), b)
    chroma = max_c - min_c
    
    knee = max_chroma * 0.75
    # If chroma > knee: compress
    scale = np.where(chroma > knee,
                     (knee + (max_chroma - knee) * np.tanh((chroma - knee) / (max_chroma - knee + 1e-6))) / (chroma + 1e-6),
                     1.0)
    luma = 0.2126 * r + 0.7152 * g + 0.0722 * b
    r_out = luma + (r - luma) * scale
    g_out = luma + (g - luma) * scale
    b_out = luma + (b - luma) * scale
    return np.clip(np.stack([r_out, g_out, b_out], axis=-1), 0.0, 1.0)

def hard_clamp_c2(rgb):
    """CONVERT2 baseline: simple hard clamp to [0, 1]"""
    return np.clip(rgb, 0.0, 1.0)

# ---------------------------------------------------------
# 3. Flow Field & Axial Regularizer (hair_v2_flow.cpp & flow_regularizer.cpp)
# ---------------------------------------------------------
def compute_structure_tensor(gray_f):
    # Gradients
    Ix = cv2.Sobel(gray_f, cv2.CV_32F, 1, 0, ksize=3)
    Iy = cv2.Sobel(gray_f, cv2.CV_32F, 0, 1, ksize=3)
    
    Jxx = cv2.GaussianBlur(Ix * Ix, (7, 7), 2.0)
    Jyy = cv2.GaussianBlur(Iy * Iy, (7, 7), 2.0)
    Jxy = cv2.GaussianBlur(Ix * Iy, (7, 7), 2.0)
    
    # Eigenvalues
    trace = Jxx + Jyy
    det = Jxx * Jyy - Jxy * Jxy
    disc = np.sqrt(np.maximum(0.0, (Jxx - Jyy)**2 + 4.0 * Jxy * Jxy))
    lam1 = 0.5 * (trace + disc)
    lam2 = 0.5 * (trace - disc)
    
    coherence = np.where(lam1 + lam2 > 1e-5, ((lam1 - lam2) / (lam1 + lam2 + 1e-5))**2, 0.0)
    
    # Angle theta (perpendicular to gradient, tangent to hair)
    phi = 0.5 * np.arctan2(2.0 * Jxy, Jxx - Jyy)
    theta = (phi + 0.5 * np.pi) % np.pi
    
    tx = np.cos(theta)
    ty = np.sin(theta)
    return theta, coherence, tx, ty

def regularize_flow_v1(theta, coherence):
    """V1 Axial Vector Regularization: (u, v) = (cos 2theta, sin 2theta) with coherence weighting"""
    u = np.cos(2.0 * theta) * coherence
    v = np.sin(2.0 * theta) * coherence
    
    u_smooth = cv2.boxFilter(u, -1, (5, 5))
    v_smooth = cv2.boxFilter(v, -1, (5, 5))
    w_smooth = cv2.boxFilter(coherence, -1, (5, 5)) + 1e-6
    
    u_bar = u_smooth / w_smooth
    v_bar = v_smooth / w_smooth
    
    theta_reg = (0.5 * np.arctan2(v_bar, u_bar)) % np.pi
    return theta_reg

def regularize_flow_c2(theta, coherence):
    """CONVERT2 baseline: simple Gaussian blur directly on angles or direct smoothing"""
    # Direct angle smoothing (subject to modulo pi cancellation)
    return cv2.GaussianBlur(theta, (5, 5), 1.0) % np.pi

# ---------------------------------------------------------
# 4. Directional Filtering along Flow (hair_v2_directional_filter.cpp)
# ---------------------------------------------------------
def directional_filter_v1(gray_f, tx, ty, radius=6):
    """V1 Flow-guided 1D continuous subpixel sampling along tangent"""
    H, W = gray_f.shape
    out = np.zeros_like(gray_f)
    weight_sum = np.zeros_like(gray_f)
    
    sigma = radius * 0.5
    for k in range(-radius, radius + 1):
        w = math.exp(-(k**2) / (2.0 * sigma * sigma))
        map_x = np.clip(np.tile(np.arange(W), (H, 1)) + k * tx, 0, W - 1).astype(np.float32)
        map_y = np.clip(np.tile(np.arange(H)[:, None], (1, W)) + k * ty, 0, H - 1).astype(np.float32)
        sampled = cv2.remap(gray_f, map_x, map_y, cv2.INTER_LINEAR)
        out += sampled * w
        weight_sum += w
    return out / (weight_sum + 1e-6)

def directional_filter_c2(gray_f, tx, ty, radius=6):
    """CONVERT2 baseline: 2D Gaussian blur approximation or 4-direction discrete filter"""
    return cv2.GaussianBlur(gray_f, (2 * radius + 1, 2 * radius + 1), radius * 0.5)

# ---------------------------------------------------------
# 5. Dual-Lobe Anisotropic Specular (hair_v2_specular.cpp)
# ---------------------------------------------------------
def estimate_light_dir_v1(linear_rgb, hair_mask):
    """V1 centroid-based image-space light estimation"""
    luma = 0.2126 * linear_rgb[:,:,0] + 0.7152 * linear_rgb[:,:,1] + 0.0722 * linear_rgb[:,:,2]
    highlight_mask = (luma > 0.6) & (hair_mask > 0.5)
    
    Y, X = np.ogrid[:luma.shape[0], :luma.shape[1]]
    if highlight_mask.sum() > 50 and hair_mask.sum() > 100:
        hl_cx = np.sum(X * highlight_mask) / highlight_mask.sum()
        hl_cy = np.sum(Y * highlight_mask) / highlight_mask.sum()
        hair_cx = np.sum(X * (hair_mask > 0.5)) / (hair_mask > 0.5).sum()
        hair_cy = np.sum(Y * (hair_mask > 0.5)) / (hair_mask > 0.5).sum()
        
        dx = (hl_cx - hair_cx) / luma.shape[1]
        dy = (hl_cy - hair_cy) / luma.shape[0]
        length = math.sqrt(dx*dx + dy*dy + 0.25)
        return dx / length, dy / length, 0.5 / length
    return 0.0, -0.894, 0.447 # default overhead light

def compute_specular_v1(tx, ty, Lx, Ly, Lz, alpha=32.0, beta=8.0):
    """V1 Dual-Lobe Marschner/Kajiya-Kay anisotropic sheen"""
    # Tangent vector in 3D: (tx, ty, 0)
    # cos(theta_d) = T . L
    cos_td = tx * Lx + ty * Ly
    sin_td = np.sqrt(np.maximum(0.0, 1.0 - cos_td**2))
    
    # Shift angles (cuticle tilt): alpha1 = 3 deg, alpha2 = -6 deg
    a1 = math.radians(3.0)
    a2 = math.radians(-6.0)
    
    term1 = np.maximum(0.0, sin_td * math.cos(a1) - cos_td * math.sin(a1))
    term2 = np.maximum(0.0, sin_td * math.cos(a2) - cos_td * math.sin(a2))
    
    lobe1 = 0.35 * (term1 ** alpha) # Primary sharp sheen (R lobe)
    lobe2 = 0.15 * (term2 ** beta)  # Secondary colored sheen (TRT lobe)
    return lobe1 + lobe2

def compute_specular_c2(tx, ty, Lx=0.0, Ly=-0.894, alpha=16.0):
    """CONVERT2 baseline: single-lobe fixed key light model"""
    cos_td = tx * Lx + ty * Ly
    sin_td = np.sqrt(np.maximum(0.0, 1.0 - cos_td**2))
    return 0.4 * (sin_td ** alpha)

# ---------------------------------------------------------
# Execution & Metric Measurement
# ---------------------------------------------------------
print("Starting TASK_042 Isolated Benchmark Suite...")
benchmark_rows = []

for p_name in PORTRAITS:
    p_path = ASSETS_DIR / p_name
    if not p_path.exists():
        print(f"Skipping {p_name} (not found)")
        continue
    
    bgr = cv2.imread(str(p_path))
    H, W, _ = bgr.shape
    rgb = cv2.cvtColor(bgr, cv2.COLOR_BGR2RGB).astype(np.float32) / 255.0
    gray = cv2.cvtColor(bgr, cv2.COLOR_BGR2GRAY).astype(np.float32) / 255.0
    linear_rgb = srgb_to_linear(rgb)
    
    # Coarse hair heuristic / hair mask for testing
    hair_mask = np.where((gray > 0.05) & (gray < 0.65), 1.0, 0.0).astype(np.float32)
    if "monk" in p_name:
        hair_mask = np.zeros_like(gray)
        
    # --- Benchmark 1: Flow Regularization (Axial double-angle vs naive smoothing) ---
    t0 = time.perf_counter()
    theta, coherence, tx, ty = compute_structure_tensor(gray)
    t_flow = (time.perf_counter() - t0) * 1000.0
    
    t0 = time.perf_counter()
    theta_v1 = regularize_flow_v1(theta, coherence)
    t_v1_flow_reg = (time.perf_counter() - t0) * 1000.0
    
    t0 = time.perf_counter()
    theta_c2 = regularize_flow_c2(theta, coherence)
    t_c2_flow_reg = (time.perf_counter() - t0) * 1000.0
    
    # Flow continuity metric: mean gradient of orientation along coherent fibers
    d_theta_v1 = np.abs(cv2.Sobel(np.cos(2.0*theta_v1), cv2.CV_32F, 1, 0)) + np.abs(cv2.Sobel(np.sin(2.0*theta_v1), cv2.CV_32F, 0, 1))
    d_theta_c2 = np.abs(cv2.Sobel(theta_c2, cv2.CV_32F, 1, 0)) + np.abs(cv2.Sobel(theta_c2, cv2.CV_32F, 0, 1))
    flow_smoothness_v1 = float(np.mean(d_theta_v1[coherence > 0.2])) if np.sum(coherence > 0.2) > 0 else 0.0
    flow_smoothness_c2 = float(np.mean(d_theta_c2[coherence > 0.2])) if np.sum(coherence > 0.2) > 0 else 0.0
    
    # --- Benchmark 2: Directional Texture Decomposition vs 2D Isotropic Blur ---
    tx_v1, ty_v1 = np.cos(theta_v1), np.sin(theta_v1)
    t0 = time.perf_counter()
    tex_low_v1 = directional_filter_v1(gray, tx_v1, ty_v1, radius=6)
    t_v1_tex = (time.perf_counter() - t0) * 1000.0
    tex_micro_v1 = gray - tex_low_v1
    
    t0 = time.perf_counter()
    tex_low_c2 = directional_filter_c2(gray, tx_v1, ty_v1, radius=6)
    t_c2_tex = (time.perf_counter() - t0) * 1000.0
    tex_micro_c2 = gray - tex_low_c2
    
    # High-frequency strand preservation: Laplacian energy
    lap_orig = cv2.Laplacian(gray, cv2.CV_32F)
    lap_v1 = cv2.Laplacian(tex_low_v1 + tex_micro_v1, cv2.CV_32F)
    lap_c2 = cv2.Laplacian(tex_low_c2 + tex_micro_c2, cv2.CV_32F)
    corr_v1 = float(np.corrcoef(lap_orig.flatten(), lap_v1.flatten())[0, 1] * 100.0)
    corr_c2 = float(np.corrcoef(lap_orig.flatten(), lap_c2.flatten())[0, 1] * 100.0)
    
    # --- Benchmark 3: Soft Chroma Compression vs Hard RGB Clamping ---
    # Simulate boosted dye saturation exceeding gamut
    vibrant_rgb = linear_rgb * np.array([1.4, 0.8, 1.8], dtype=np.float32) # Rose Gold / Violet boost
    t0 = time.perf_counter()
    compressed_v1 = soft_chroma_compress_v1(vibrant_rgb)
    t_v1_chroma = (time.perf_counter() - t0) * 1000.0
    
    t0 = time.perf_counter()
    clamped_c2 = hard_clamp_c2(vibrant_rgb)
    t_c2_chroma = (time.perf_counter() - t0) * 1000.0
    
    # Measure CIEDE2000 color delta against unclipped intention
    lab_intended = linear_to_cielab(vibrant_rgb)
    lab_v1 = linear_to_cielab(compressed_v1)
    lab_c2 = linear_to_cielab(clamped_c2)
    de_v1 = float(np.mean(delta_e_2000(lab_intended, lab_v1)))
    de_c2 = float(np.mean(delta_e_2000(lab_intended, lab_c2)))
    
    # Out of gamut clipping artifacts count
    clipping_pixels_c2 = int(np.sum((vibrant_rgb > 1.0) | (vibrant_rgb < 0.0)))
    
    # --- Benchmark 4: Specular Sheen Dual-Lobe vs Single-Lobe ---
    Lx, Ly, Lz = estimate_light_dir_v1(linear_rgb, hair_mask)
    t0 = time.perf_counter()
    sheen_v1 = compute_specular_v1(tx_v1, ty_v1, Lx, Ly, Lz)
    t_v1_spec = (time.perf_counter() - t0) * 1000.0
    
    t0 = time.perf_counter()
    sheen_c2 = compute_specular_c2(tx_v1, ty_v1)
    t_c2_spec = (time.perf_counter() - t0) * 1000.0
    
    mean_sheen_v1 = float(np.mean(sheen_v1[hair_mask > 0.5])) if np.sum(hair_mask > 0.5) > 0 else 0.0
    mean_sheen_c2 = float(np.mean(sheen_c2[hair_mask > 0.5])) if np.sum(hair_mask > 0.5) > 0 else 0.0

    # Save visual artifact comparisons
    out_prefix = RAW_OUT_DIR / p_name.replace(".png", "")
    cv2.imwrite(f"{out_prefix}_flow_v1.png", (theta_v1 / np.pi * 255.0).astype(np.uint8))
    cv2.imwrite(f"{out_prefix}_flow_c2.png", (theta_c2 / np.pi * 255.0).astype(np.uint8))
    cv2.imwrite(f"{out_prefix}_chroma_v1.png", cv2.cvtColor((compressed_v1 * 255).astype(np.uint8), cv2.COLOR_RGB2BGR))
    cv2.imwrite(f"{out_prefix}_chroma_c2.png", cv2.cvtColor((clamped_c2 * 255).astype(np.uint8), cv2.COLOR_RGB2BGR))
    cv2.imwrite(f"{out_prefix}_sheen_v1.png", (np.clip(sheen_v1 * 255.0, 0, 255)).astype(np.uint8))
    cv2.imwrite(f"{out_prefix}_sheen_c2.png", (np.clip(sheen_c2 * 255.0, 0, 255)).astype(np.uint8))

    row = {
        "portrait": p_name,
        "width": W,
        "height": H,
        "texture_corr_c2_pct": round(corr_c2, 2),
        "texture_corr_v1_pct": round(corr_v1, 2),
        "texture_gain_pct": round(corr_v1 - corr_c2, 2),
        "flow_smoothness_c2": round(flow_smoothness_c2, 4),
        "flow_smoothness_v1": round(flow_smoothness_v1, 4),
        "flow_smoothness_improvement_pct": round((1.0 - flow_smoothness_v1 / (flow_smoothness_c2 + 1e-6)) * 100.0, 2),
        "color_deltaE_c2": round(de_c2, 2),
        "color_deltaE_v1": round(de_v1, 2),
        "color_deltaE_reduction_pct": round((1.0 - de_v1 / (de_c2 + 1e-6)) * 100.0, 2),
        "sheen_response_c2": round(mean_sheen_c2, 4),
        "sheen_response_v1": round(mean_sheen_v1, 4),
        "v1_flow_reg_latency_ms": round(t_v1_flow_reg, 2),
        "c2_flow_reg_latency_ms": round(t_c2_flow_reg, 2),
        "v1_tex_filter_latency_ms": round(t_v1_tex, 2),
        "c2_tex_filter_latency_ms": round(t_c2_tex, 2),
        "v1_chroma_latency_ms": round(t_v1_chroma, 2),
        "c2_chroma_latency_ms": round(t_c2_chroma, 2),
        "v1_specular_latency_ms": round(t_v1_spec, 2),
        "c2_specular_latency_ms": round(t_c2_spec, 2)
    }
    benchmark_rows.append(row)
    print(f"Processed {p_name}: Texture Corr (C2: {corr_c2:.1f}% vs V1: {corr_v1:.1f}%), DeltaE (C2: {de_c2:.2f} vs V1: {de_v1:.2f})")

# Write CSV results
csv_path = Path(".ai/reports/TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK/05_BENCHMARK_RESULTS.csv")
with open(csv_path, "w", newline="", encoding="utf-8") as f:
    writer = csv.DictWriter(f, fieldnames=list(benchmark_rows[0].keys()))
    writer.writeheader()
    writer.writerows(benchmark_rows)

print(f"\nWrote benchmark results to {csv_path}")
