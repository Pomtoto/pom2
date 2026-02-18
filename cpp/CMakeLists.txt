cmake_minimum_required(VERSION 3.10)
project("NativeProject")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB CONFIG_SOURCES "Config/*.cpp")
file(GLOB ESP_SOURCES "ESP/*.cpp")
file(GLOB HOOK_SOURCES "Hooks/*.cpp")
file(GLOB SDK_SOURCES "SDK/*.cpp")
file(GLOB INCLUDE_SOURCES "Includes/*.cpp")

add_library(NativeProject SHARED
    Main.cpp
    ${CONFIG_SOURCES}
    ${ESP_SOURCES}
    ${HOOK_SOURCES}
    ${SDK_SOURCES}
    ${INCLUDE_SOURCES}
)

find_library(log-lib log)
find_library(android-lib android)
find_library(EGL-lib EGL)
find_library(GLESv3-lib GLESv3)
find_library(dl-lib dl)

target_link_libraries(NativeProject
    ${log-lib}
    ${android-lib}
    ${EGL-lib}
    ${GLESv3-lib}
    ${dl-lib}
)

target_compile_options(NativeProject PRIVATE
    -Wno-error=format-security
    -Wno-unused-variable
    -Wno-unused-function
    -fvisibility=hidden
)
