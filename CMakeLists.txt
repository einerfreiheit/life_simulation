cmake_minimum_required (VERSION 2.6)

project (LifeSim)

add_definitions(-std=gnu++11)
add_definitions(-DUSE_OPENCV2)

file (GLOB LIFESIM_CORE ${PROJECT_SOURCE_DIR}/*.cpp)

include_directories(${PROJECT_SOURCE_DIR})

set (SOURCE "${LIFESIM_CORE};")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

add_executable(LifeSim ${SOURCE})
target_link_libraries(LifeSim opencv_core opencv_highgui opencv_video opencv_imgproc)
