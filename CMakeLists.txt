cmake_minimum_required (VERSION 2.6)

project (LifeSim)

add_definitions(-std=gnu++11)
add_definitions(-DUSE_OPENCV2)

file (GLOB LIFESIM_CORE ${PROJECT_SOURCE_DIR}/*.cpp)
file (GLOB LIFESIM_WORKERS ${PROJECT_SOURCE_DIR}/Workers/*.cpp)
file (GLOB LIFESIM_FACTORIES ${PROJECT_SOURCE_DIR}/Factories/*.cpp)
file (GLOB LIFESIM_ACTIONS ${PROJECT_SOURCE_DIR}/Actions/*.cpp)
file (GLOB LIFESIM_LOGICS ${PROJECT_SOURCE_DIR}/Logics/*.cpp)


include_directories(${PROJECT_SOURCE_DIR}
${PROJECT_SOURCE_DIR}/Workers/
${PROJECT_SOURCE_DIR}/Factories/
${PROJECT_SOURCE_DIR}/Actions/
${PROJECT_SOURCE_DIR}/Logics/
)

set (SOURCE "${LIFESIM_CORE};${LIFESIM_WORKERS};${LIFESIM_FACTORIES};${LIFESIM_ACTIONS};${LIFESIM_LOGICS};")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O5")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O5")

add_executable(LifeSim ${SOURCE})
target_link_libraries(LifeSim opencv_core opencv_highgui opencv_video opencv_imgproc boost_program_options)