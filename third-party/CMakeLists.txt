
# include
set(INCLUDE_HEADERS_T)
# source
set(INCLUDE_SOURCES_T)
# libaray
set(THIRDPARTY_LIBRARIES_T)

# vulkan
find_package(Vulkan REQUIRED)
set(INCLUDE_HEADERS_T ${Vulkan_INCLUDE_DIRS} ${INCLUDE_HEADERS_T})
set(THIRDPARTY_LIBRARIES_T ${Vulkan_LIBRARIES} ${THIRDPARTY_LIBRARIES_T})
# opengl
find_package(OpenGL REQUIRED)

# glad
add_subdirectory(glad/cmake)
glad_add_library("glad_gl_core"
        LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/glad-lib"
        MERGE
        STATIC
        REPRODUCIBLE
        API gl:core=4.6
        LANGUAGE C
        EXTENSIONS NONE)
set(THIRDPARTY_LIBRARIES_T "glad_gl_core" ${THIRDPARTY_LIBRARIES_T})


# glfw
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_INSTALL OFF)
add_subdirectory(glfw)
set(THIRDPARTY_LIBRARIES_T glfw ${THIRDPARTY_LIBRARIES_T})

# glm
add_subdirectory(glm)
set(THIRDPARTY_LIBRARIES_T glm ${THIRDPARTY_LIBRARIES_T})

# spdlog
add_subdirectory(spdlog)
set(THIRDPARTY_LIBRARIES_T spdlog ${THIRDPARTY_LIBRARIES_T})

# imgui
set(INCLUDE_HEADERS_T ${CMAKE_CURRENT_SOURCE_DIR}/imgui ${INCLUDE_HEADERS_T})


# stb
set(INCLUDE_HEADERS_T third-party/stb ${INCLUDE_HEADERS_T})




message("----   Third-party Libraries  ----")
foreach(X ${THIRDPARTY_LIBRARIES_T})
    message("\t${X}")
endforeach()
message("----   Third-party Headers  ----")
foreach(X ${INCLUDE_HEADERS_T})
    message("\t${X}")
endforeach()

set(THIRDPARTY_LIBRARIES ${THIRDPARTY_LIBRARIES_T} CACHE STRING "Third-party Libraries")
set(THIRDPARTY_INCLUDE ${INCLUDE_HEADERS_T} CACHE STRING "Third-party Include")