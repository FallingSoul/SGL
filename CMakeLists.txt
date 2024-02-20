cmake_minimum_required(VERSION 3.5)
project(SGL VERSION 0.0.1)


function(set_option opname opdesc opvalue)
    if(DEFINED ${opname})
        unset(${opname} CACHE)
    endif()
    option(${opname} ${opdesc} ${opvalue})
endfunction()



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
target_link_libraries(${PROJECT_NAME} glfw3 vulkan-1)





# test
if(${PROJECT_NAME}_BUILD_WITH_TEST)
    file(GLOB_RECURSE ${PROJECT_NAME}_TEST "${PROJECT_SOURCE_DIR}/test/*.*")
    message("---- Test ----")
    foreach(X ${${PROJECT_NAME}_TEST})
        message("\t${X}")
    endforeach()
    add_executable(test ${${PROJECT_NAME}_TEST})
    target_link_libraries(test ${PROJECT_NAME})
endif()
