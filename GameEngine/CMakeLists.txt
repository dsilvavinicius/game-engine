cmake_minimum_required (VERSION 2.6)
project (Game_Engine)

# Set include dirs.
set (INCLUDE_DIR ${INCLUDE_DIR} "libraries/include")
set (HEADER_DIR ${HEADER_DIR} "source/headers")
include_directories (${INCLUDE_DIR})
include_directories (${HEADER_DIR})

# Set source directories.
set (CPP_DIR ${CPP_DIR} "source/src")

# Add the executable
add_executable (Game_Engine
	${HEADER_DIR}/Entity.h			${CPP_DIR}/Entity.cpp
	${HEADER_DIR}/EntityManager.h	${CPP_DIR}/EntityManager.cpp
	${HEADER_DIR}/Application.h		${CPP_DIR}/Application.cpp
	${CPP_DIR}/main.cpp)
	
#Add libraries
# TODO: set options for platform and build type.
set (LIBS_WIN64_DIR ${LIBS_WIN64_DIR} "${PROJECT_SOURCE_DIR}/libraries/lib/Win64")
set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/gtest.lib")
set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/freeglut.lib")
cmake_policy(SET CMP0015 NEW) # Use new policy in link_directories(): output absolute paths.
target_link_libraries (Game_Engine ${LIBS_DIR})

# add the install targets
install (TARGETS Game_Engine DESTINATION bin)