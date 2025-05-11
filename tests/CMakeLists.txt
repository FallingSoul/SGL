


file(GLOB_RECURSE VERTEX_SHADERS "${PROJECT_SOURCE_DIR}/res/shader/*.vert")
file(GLOB_RECURSE FRAGMENT_SHADERS "${PROJECT_SOURCE_DIR}/res/shader/*.frag")
set(SHADERS ${VERTEX_SHADERS} ${FRAGMENT_SHADERS})

message("---- Shaders ----")
foreach(X ${SHADERS})
    file(RELATIVE_PATH Y ${PROJECT_SOURCE_DIR} ${X})
    message("\t${Y}")
endforeach()
spirv_shaders(
    SHADER_HEADERS
    SPIRV_VERSION 1.0
    SOURCES ${SHADERS}
)
set(TEST_SOURCE main.cpp ${SHADER_HEADERS})

message("---- T_SOUCES ----")
foreach(X ${TEST_SOURCE})
    message("\t${X}")
endforeach()

add_executable(${PROJECT_NAME}_TEST ${TEST_SOURCE})
target_link_libraries(${PROJECT_NAME}_TEST  ${SGL_LIBRARY})
target_include_directories(${PROJECT_NAME}_TEST PUBLIC "../third-party/stb")