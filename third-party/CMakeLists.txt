
find_package(Vulkan REQUIRED)
add_subdirectory(glfw)

# imgui
file(GLOB IMGUI_SOURCES imgui/*.cpp imgui/*.h)
set(GLOB_RECURSE IMGUI_BACKENDS imgui/backends/imgui_impl_glfw.* imgui/backends/vulkan.*)
add_library(imgui STATIC ${IMGUI_SOURCES} ${IMGUI_BACKENDS})
target_include_directories(imgui PUBLIC imgui imgui/backends)

set(THIRDPARTY_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "third-party directory")
set(THIRDPARTY_LIBRARIES ${Vulkan_LIBRARIES} glfw imgui CACHE STRING "third-party libraries")
set(THIRDPARTY_INCLUDE ${THIRDPARTY_DIRECTORY}/stb CACHE STRING "third-party include")