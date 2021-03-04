cmake_minimum_required(VERSION 3.0)

# Project Name
set(PROJ_NAME wrap)
project(${PROJ_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FILE(GLOB HEADER_LIST "${CMAKE_SOURCE_DIR}/src/*.h")
FILE(GLOB SOURCE_LIST "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJ_NAME} ${SOURCE_LIST} ${HEADER_LIST})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJ_NAME})

# OpenCV 
# 更改此路径为OpenCVConfig.cmake的路径（库目录）
find_package(OpenCV REQUIRED)

if(OpenCV_FOUND)
  include_directories(${OpenCV_INCLUDE_DIRS})
  target_link_libraries(${PROJ_NAME} ${OpenCV_LIBS})
endif()


# 识别为c++代码
set_target_properties(${PROJ_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Administrator
#set_target_properties(${PROJ_NAME} PROPERTIES LINK_FLAGS "/level='requireAdministrator'") 

# Unicode编码
Add_Definitions(-DUNICODE -D_UNICODE) 
