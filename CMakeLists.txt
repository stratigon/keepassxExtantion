#/**********************************************************\ 
# 
# Auto-generated CMakeLists.txt for the keepassx-extantion project
#
#\**********************************************************/

# Written to work with cmake 2.6
cmake_minimum_required (VERSION 2.6)
set (CMAKE_BACKWARDS_COMPATIBILITY 2.6)

Project(${PLUGIN_NAME})

#file (GLOB GENERAL RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
#    [^.]*.cpp
#    [^.]*.h
#    [^.]*.cmake
#    )


file (GLOB_RECURSE GENERAL RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    [^.]*.cpp
    [^.]*.c
    [^.]*.h
    [^.]*.cmake
#    crypto *.cpp
#    crypto *.h
#    lib *.cpp
#    lib *.h
    )


include_directories(${PLUGIN_INCLUDE_DIRS})

# Generated files are stored in ${GENERATED} by the project configuration
SET_SOURCE_FILES_PROPERTIES(
    ${GENERATED}
    PROPERTIES
        GENERATED 1
    )

SOURCE_GROUP(Generated FILES
    ${GENERATED}
    )

SET( SOURCES
    ${GENERAL}
    ${GENERATED}
    )

# This will include Win/projectDef.cmake, X11/projectDef.cmake, Mac/projectDef 
# depending on the platform
include_platform()
