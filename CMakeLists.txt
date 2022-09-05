cmake_minimum_required(VERSION 3.21)
project(diff)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)
#头文件
set(JAVA_JNI_H_DIR "/Library/Java/JavaVirtualMachines/jdk1.8.0_121.jdk/Contents/Home/include")
set(JAVA_JNI_MDH_DIR "/Library/Java/JavaVirtualMachines/jdk1.8.0_121.jdk/Contents/Home/include/darwin")
set(MODULE_HEADERS_DIR "${CMAKE_HOME_DIRECTORY}/src/module/")
set(BSDIFF_HEADERS_DIR "${CMAKE_HOME_DIRECTORY}/src/bsdiff/")
set(BZIP2_HEADERS_DIR "${CMAKE_HOME_DIRECTORY}/src/bzip2/")
include_directories(
        ${JAVA_JNI_H_DIR}
        ${JAVA_JNI_MDH_DIR}
        ${MODULE_HEADERS_DIR}
        ${BSDIFF_HEADERS_DIR}
        ${BZIP2_HEADERS_DIR}
)
#源文件
set(MODULE_SRC_DIR "${CMAKE_HOME_DIRECTORY}/src/module/")
set(BSDIFF_SRC_DIR "${CMAKE_HOME_DIRECTORY}/src/bsdiff/")
set(BZIP2_SRC_DIR "${CMAKE_HOME_DIRECTORY}/src/bzip2/")
aux_source_directory(${MODULE_SRC_DIR} MODULE_SRC)
aux_source_directory(${BSDIFF_SRC_DIR} BSDIFF_SRC)
aux_source_directory(${BZIP2_SRC_DIR} BZIP2_SRC)
add_library(
        diff

        SHARED

        ${MODULE_SRC}
        ${BSDIFF_SRC}
        ${BZIP2_SRC}
)
#add_executable(test main.c)

#find_package(BZip2 REQUIRED) #查找Package
#if (BZIP2_FOUND)
#    include_directories(${BZIP_INCLUDE_DIRS}) #引入头文件
#    #    target_link_libraries (bspatch ${BZIP2_LIBRARIES}) #链接 bspatch 这个target
#    target_link_libraries(diff ${BZIP2_LIBRARIES}) #链接 bsdiff 这个target
#endif (BZIP2_FOUND)
