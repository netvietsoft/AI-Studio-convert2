path = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\kotlin\com\mt\mtxx\mtxx\editor\PhotoEditorActivity.kt"
with open(path, "r", encoding="utf-8") as f:
    lines = f.readlines()

new_lines = []
in_cat_skin = False
for line in lines:
    if 'CategoryItem("cat_skin"' in line:
        in_cat_skin = True
        new_lines.append(line)
        continue
    if in_cat_skin:
        if 'CategoryItem("cat_teeth"' in line:
            in_cat_skin = False
            new_lines.append(line)
            continue
        
        # Replace 0 defaultVal and VIP in cat_skin tools
        if '"tool_skin_smooth"' in line:
            line = '            ToolItem("tool_skin_smooth", "Làm mịn lụa (Smooth)", "Realtime Bilateral C++", false, "libmeitu_reborn_native.so", 60, -100, 100, "%"),\n'
        elif '"tool_skin_bright"' in line:
            line = '            ToolItem("tool_skin_bright", "Nâng tông trắng sứ (Whiten)", "Porcelain Whiten C++", false, "libmeitu_reborn_native.so", 60, -100, 100, "%"),\n'
        elif '"tool_skin_acne"' in line:
            line = '            ToolItem("tool_skin_acne", "Xóa thâm mụn AI (Acne)", "Neural Inpaint Patch", false, "libmeitu_reborn_native.so", 70, -100, 100, "%"),\n'
        elif '"tool_skin_eyebags"' in line:
            line = '            ToolItem("tool_skin_eyebags", "Xóa bọng quầng thâm mắt", "Eye Bags Concealer C++", false, "libmeitu_reborn_native.so", 65, -100, 100, "%"),\n'
        elif '"tool_skin_smile_lines"' in line:
            line = '            ToolItem("tool_skin_smile_lines", "Xóa rãnh cười mũi má", "Nasolabial Laugh Lines", false, "libmeitu_reborn_native.so", 60, -100, 100, "%"),\n'
        elif '"tool_skin_neck_lines"' in line:
            line = '            ToolItem("tool_skin_neck_lines", "Xóa nếp nhăn cổ", "Neck Lines Remover C++", false, "libmeitu_reborn_native.so", 60, -100, 100, "%"),\n'
        elif '"tool_skin_clear"' in line:
            line = '            ToolItem("tool_skin_clear", "Xóa tàn nhang đốm nâu", "Freckle Clear C++", false, "libmeitu_reborn_native.so", 65, -100, 100, "%"),\n'
        elif '"tool_skin_detail"' in line:
            line = '            ToolItem("tool_skin_detail", "Chi tiết biểu bì tự nhiên", "Epidermis Pores Detail C++", false, "libmeitu_reborn_native.so", 60, -100, 100, "%"),\n'
        elif '"tool_skin_oil_control"' in line:
            line = '            ToolItem("tool_skin_oil_control", "Kiềm bóng dầu Matte", "Anti-Shine Matte Filter", false, "libmeitu_reborn_native.so", 60, -100, 100, "%"),\n'
        elif '"tool_skin_type_oily"' in line:
            line = '            ToolItem("tool_skin_type_oily", "Chế độ: Da Dầu (64804)", "Oily Skin Specular Defuse", false, "libmeitu_reborn_native.so", 60, -100, 100, "%"),\n'
        elif '"tool_skin_type_dry"' in line:
            line = '            ToolItem("tool_skin_type_dry", "Chế độ: Da Khô (64805)", "Dry Skin Dewy Radiance", false, "libmeitu_reborn_native.so", 60, -100, 100, "%"),\n'
        elif '"tool_skin_type_combined"' in line:
            line = '            ToolItem("tool_skin_type_combined", "Chế độ: Da Hỗn Hợp (64806)", "Combined Skin T-Zone", false, "libmeitu_reborn_native.so", 60, -100, 100, "%"),\n'
        elif '"tool_skin_type_sensitive"' in line:
            line = '            ToolItem("tool_skin_type_sensitive", "Chế độ: Da Nhạy Cảm (64807)", "Sensitive Anti-Redness", false, "libmeitu_reborn_native.so", 60, -100, 100, "%"),\n'
    new_lines.append(line)

with open(path, "w", encoding="utf-8") as f:
    f.writelines(new_lines)
print("SUCCESS: Updated PhotoEditorActivity.kt cat_skin items")
