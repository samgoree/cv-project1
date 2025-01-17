# CMakeList.txt : CMake project for TestOpenCV, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 2.8)                            
PROJECT( project1)                                         

FIND_PACKAGE( OpenCV REQUIRED )                              
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )

add_executable (project1 "testWebcam.cpp" "testWebcam.h")                      
TARGET_LINK_LIBRARIES (project1 ${OpenCV_LIBS})         
# Add source to this project's executable.


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET project1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
