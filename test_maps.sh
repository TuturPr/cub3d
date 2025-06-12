#!/bin/bash

CUB3D_EXEC=./cub3d
MAP_DIR=maps
FILES_TO_TEST=(
    map_with_empty_lines.cub
    empty.cub
    invalid_characters.cub
    map_not_closed.cub
    map.txt
    missing_texture.cub
    no_spawn.cub
    random_prder.cub
    textures_not_found.cub
    two_spawns.cub
	map_with_spaces.cub
)
GOOD_MAPS=(
    test.cub
)

echo "=== Testing invalid maps ==="

for file in "${FILES_TO_TEST[@]}"; do
    echo -n "Testing $file... "
    $CUB3D_EXEC "$MAP_DIR/$file" > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo "✅ Error correctly detected"
    else
        echo "❌ No error detected (should have failed)"
    fi
done

echo "=== Testing valid maps ==="
for file in "${GOOD_MAPS[@]}"; do
    echo -n "Testing $file... "
    $CUB3D_EXEC "$MAP_DIR/$file" > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo "✅ Map loaded successfully"
    else
        echo "❌ Error detected (should have passed)"
    fi
done
