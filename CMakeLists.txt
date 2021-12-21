cmake_minimum_required(VERSION 3.11)


project(videomatting)

add_subdirectory(3rdparty/opencv)
add_subdirectory(3rdparty/ncnn)

message(STATUS "==>> to get source")


if(ANDROID) 
message(STATUS "==>> is android")
add_definitions(-DANDROID)
file(GLOB nano_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/nanodet.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/nanodet.h
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/nanodetncnn.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/ndkcamera.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/ndkcamera.h)
else()
message(STATUS "==>> is not android")
file(GLOB nano_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/nanodet.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/nanodet.h
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/executor.cpp)
endif()

if(ANDROID)
add_library(videomatting SHARED nanodetncnn.cpp nanodet.cpp ndkcamera.cpp)
target_link_libraries(videomatting ncnn ${OpenCV_LIBS} camera2ndk mediandk)
else()
add_executable(videomatting ${nano_SRC})
target_link_libraries(videomatting PRIVATE ncnn opencv_core opencv_imgproc opencv_imgcodecs opencv_highgui)
endif()