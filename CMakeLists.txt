cmake_minimum_required(VERSION 3.5)
project(SGL VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/build/debug")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/build/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "{PROJECT_SOURCE_DIR}/build/release")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/build/release")




include(FetchContent)
# for third-party libraries
find_package(Vulkan REQUIRED)
FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw SOURCE_DIR "${PROJECT_SOURCE_DIR}/third-party/glfw")
FetchContent_MakeAvailable(glfw)




set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS "${PROJECT_SOURCE_DIR}/inc/*.*")
file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "${PROJECT_SOURCE_DIR}/src/*.*")

message("---- Headers ----")
foreach(X ${${PROJECT_NAME}_HEADERS})
    message("\t${X}")
endforeach()

message("---- Sources ----")
foreach(X ${${PROJECT_NAME}_SOURCES})
    message("\t${X}")
endforeach()

include_directories("${PROJECT_SOURCE_DIR}/inc/")
add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_HEADERS})

# define version numbers
target_compile_definitions(${PROJECT_NAME}
    PUBLIC ${PROJECT_NAME}_BUILD
    PUBLIC ${PROJECT_NAME}_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
    PUBLIC ${PROJECT_NAME}_VERSION_MINOR=${PROJECT_VERSION_MINOR}
    PUBLIC ${PROJECT_NAME}_VERSION_PATCH=${PROJECT_VERSION_PATCH})
# link libraries
target_link_libraries(${PROJECT_NAME} glfw ${Vulkan_LIBRARIES})

if(EXISTS "${PROJECT_SOURCE_DIR}/test")
    add_subdirectory("${PROJECT_SOURCE_DIR}/test")
endif()