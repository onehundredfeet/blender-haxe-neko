cmake_minimum_required(VERSION 3.10)
project (blender C CXX )




add_library(blender.ndll SHARED
source/BlenderHaxe.cpp
)

set_target_properties(blender.ndll
PROPERTIES
PREFIX ""
OUTPUT_NAME blender
SUFFIX .ndll
)

set_property(TARGET blender.ndll PROPERTY CXX_STANDARD 17)

cmake_policy(SET CMP0015 NEW)

target_include_directories(blender.ndll
PRIVATE
"/opt/homebrew/include"
"include"
)

find_library( NEKO_LIB NAMES neko HINTS /opt/homebrew/lib )

target_link_libraries(blender.ndll ${NEKO_LIB})

install(TARGETS blender.ndll )



add_executable(embedtest source/NekoEmbed.cpp)
set_property(TARGET embedtest PROPERTY CXX_STANDARD 17)
target_include_directories(embedtest
PRIVATE
"/opt/homebrew/include"
"include"
)
target_link_libraries(embedtest ${NEKO_LIB})
