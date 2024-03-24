
# vulkan
find_package(Vulkan REQUIRED)

# glfw
add_subdirectory(glfw)

# glm
add_subdirectory(glm)

# imgui
file(GLOB IMGUI_SOURCES imgui/*.cpp imgui/*.h imgui/backends/imgui_impl_glfw.* imgui/backends/vulkan.*)
set(IMGUI_INCLUDE imgui imgui/backends glfw/include)

# stb
file(GLOB STB_SOURCES stb/*.h)
set(STB_INCLUDE stb)

# third-party (for libraries without cmake)
add_library(third-party STATIC third-party.cpp ${STB_SOURCES} ${IMGUI_SOURCES})
target_include_directories(third-party PUBLIC  ${STB_INCLUDE} ${IMGUI_INCLUDE} ${Vulkan_INCLUDE_DIRS})

set(THIRDPARTY_LIBRARIES ${Vulkan_LIBRARIES} glfw glm third-party CACHE STRING "Third-party libraries")
