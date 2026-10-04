# 03 — NON-BRANCHING PEGTOP SOFTLIGHT BLENDING
**Authority:** Chủ tịch Tony  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Mục tiêu:** Hòa trộn màu nhuộm tóc mượt mà, không bệt màu, không rỗng pixel.

## 1. Công thức Hòa trộn Pegtop
Cho $B$ là màu nền (base luminance), $S$ là màu nhuộm (blend color):
- Nếu $S > 0.5$:
  $$f_{above}(B, S) = \sqrt{B}(2S - 1) + 2B(1 - S)$$
- Nếu $S \le 0.5$:
  $$f_{below}(B, S) = 2BS + B^2(1 - 2S)$$
- Biểu thức phi phân nhánh GPU:
  $$f(B, S) = \operatorname{mix}(f_{below}, f_{above}, \operatorname{step}(0.5, S))$$
