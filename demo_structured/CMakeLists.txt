add_executable (AvaStructuredDemo main.cpp AvaInterface.cpp AvaInterface.h ${CMAKE_SOURCE_DIR}/src/include/portaudio.h )

target_link_libraries (AvaStructuredDemo LINK_PUBLIC Ava)