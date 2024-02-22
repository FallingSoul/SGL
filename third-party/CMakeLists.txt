
find_package(Vulkan REQUIRED)
add_subdirectory(glfw)

# imgui
file(GLOB IMGUI_SOURCES imgui/*.cpp imgui/*.h)
set(GLOB_RECURSE IMGUI_BACKENDS imgui/backends/imgui_impl_glfw.* imgui/backends/vulkan.*)
add_library(imgui STATIC ${IMGUI_SOURCES} ${IMGUI_BACKENDS})
target_include_directories(imgui PUBLIC imgui imgui/backends)
