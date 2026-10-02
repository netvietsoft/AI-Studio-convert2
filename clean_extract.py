with open('lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp', 'r', encoding='utf-8') as f:
    lines = f.readlines()

# 1. Remove the broken hair_matting_mobile ensemble in extractHairMatte
start_del = -1
end_del = -1
for i, l in enumerate(lines):
    if 'ƯU TIÊN 2' in l:
        start_del = i
    if start_del != -1 and 'applySubpixelGuidedRefinement' in l:
        end_del = i
        break

if start_del != -1 and end_del != -1:
    print(f'Removing broken mobile matting from lines {start_del} to {end_del}')
    del lines[start_del:end_del]

# Write back
with open('lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp', 'w', encoding='utf-8', newline='') as f:
    f.writelines(lines)

print('Cleaned extractHairMatte. Total lines:', len(lines))
