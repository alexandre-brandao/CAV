cmake_minimum_required(VERSION 2.8)

# Name your project
project( DEVELOPMENT1 )

# Add FLAC, OGGS, VORBIS cmake files
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Search and verify OPENCV package
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Search and verify libsndfile
find_package(SndFile REQUIRED)

# Makefile commands g++ [optional commands: -Wall] -o {executable name} {Executable name}.cpp --Headers ahead
add_executable( DisplayImage DisplayImage.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )

add_executable( convert_to_txt convert_to_txt.cpp )
target_link_libraries(convert_to_txt PRIVATE SndFile::sndfile)

add_executable( Readfile Readfile.cpp)
target_link_libraries(Readfile PRIVATE SndFile::sndfile)