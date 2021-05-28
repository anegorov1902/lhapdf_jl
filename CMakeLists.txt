include_directories(/Users/anatolii/Programs/LHAPDF_623_for_python_380/LHAPDF_623/include)
project("lhapdf_jl")

cmake_minimum_required(VERSION 3.1)
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set(JlCxx_DIR "/Users/anatolii/Programs/cxxwrap-julia/libcxxwrap-julia-build")

list(APPEND CMAKE_MODULE_PATH "/Users/anatolii/Programs/cmaketools-master/modules")
set(LHAPDF_INCLUDE_DIR "/Users/anatolii/Programs/LHAPDF_630_for_julia_cxxwrap/LHAPDF_630/include")
set(LHAPDF_LIBRARY "/Users/anatolii/Programs/LHAPDF_630_for_julia_cxxwrap/LHAPDF_630/lib")

find_package(JlCxx)
find_package(LHAPDF REQUIRED)

get_target_property(JlCxx_location JlCxx::cxxwrap_julia LOCATION)
get_filename_component(JlCxx_location ${JlCxx_location} DIRECTORY)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib;${JlCxx_location}")

message(STATUS "Found JlCxx at ${JlCxx_location}")

add_library(lhapdf_jl SHARED lhapdf_jl.cpp)

target_link_libraries(lhapdf_jl JlCxx::cxxwrap_julia JlCxx::cxxwrap_julia_stl)
target_link_libraries(lhapdf_jl /Users/anatolii/Programs/LHAPDF_630_for_julia_cxxwrap/LHAPDF_630/lib/libLHAPDF.dylib)

install(TARGETS lhapdf_jl
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION lib)
