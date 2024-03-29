cmake_minimum_required (VERSION 2.6)

project (LifeSim)

add_definitions(-std=gnu++11)
add_definitions(-DUSE_OPENCV2)

file (GLOB LIFESIM_CORE ${PROJECT_SOURCE_DIR}/*.cpp)
file (GLOB LIFESIM_WORKERS ${PROJECT_SOURCE_DIR}/Workers/*.cpp)
file (GLOB LIFESIM_FACTORIES ${PROJECT_SOURCE_DIR}/Factories/*.cpp)
file (GLOB LIFESIM_ACTIONS ${PROJECT_SOURCE_DIR}/Actions/*.cpp)
file (GLOB LIFESIM_LOGICS ${PROJECT_SOURCE_DIR}/Logics/*.cpp)
file (GLOB LIFESIM_VISUALIZATION ${PROJECT_SOURCE_DIR}/Visualization/*.cpp)
file (GLOB LIFESIM_GENETICS ${PROJECT_SOURCE_DIR}/Genetics/*.cpp)
file (GLOB LIFESIM_MAP ${PROJECT_SOURCE_DIR}/Map/*.cpp)
file (GLOB LIFESIM_OPENGL ${PROJECT_SOURCE_DIR}/OpenGL/*.cpp)


include_directories(${PROJECT_SOURCE_DIR}
${PROJECT_SOURCE_DIR}/Workers/
${PROJECT_SOURCE_DIR}/Factories/
${PROJECT_SOURCE_DIR}/Actions/
${PROJECT_SOURCE_DIR}/Logics/
${PROJECT_SOURCE_DIR}/Genetics/
${PROJECT_SOURCE_DIR}/Visualization/
${PROJECT_SOURCE_DIR}/Map/
${PROJECT_SOURCE_DIR}/OpenGL/
)


set (SOURCE "${LIFESIM_CORE};${LIFESIM_WORKERS};${LIFESIM_FACTORIES};${LIFESIM_ACTIONS};${LIFESIM_LOGICS};${LIFESIM_GENETICS};${LIFESIM_VISUALIZATION};${LIFESIM_MAP};${LIFESIM_OPENGL};")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g3")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g3")


add_executable(LifeSim ${SOURCE})
target_link_libraries(LifeSim opencv_core opencv_highgui opencv_video opencv_imgproc boost_program_options glut GL  glfw GLU GLEW tinyxml SOIL)

