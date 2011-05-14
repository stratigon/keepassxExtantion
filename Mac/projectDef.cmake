#/**********************************************************\ 
# Auto-generated Mac project definition file for the
# keepassx-extantion project
#\**********************************************************/

# Mac template platform definition CMake file
# Included from ../CMakeLists.txt

# remember that the current source dir is the project root; this file is in Mac/
file (GLOB PLATFORM RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    Mac/[^.]*.cpp
    Mac/[^.]*.h
    Mac/[^.]*.cmake
    )

# use this to add preprocessor definitions
add_definitions(
    
)


SOURCE_GROUP(Mac FILES ${PLATFORM})

set (SOURCES
    ${SOURCES}
    ${PLATFORM}
    )

set(PLIST "Mac/bundle_template/Info.plist")
set(STRINGS "Mac/bundle_template/InfoPlist.strings")
set(LOCALIZED "Mac/bundle_template/Localized.r")

add_mac_plugin(${PROJECT_NAME} ${PLIST} ${STRINGS} ${LOCALIZED} SOURCES)

# add library dependencies here; leave ${PLUGIN_INTERNAL_DEPS} there unless you know what you're doing!

# add QT moc generated
SET(MOC_HEADERS Kdb3Database.h)

# Include QT library (http://www.cmake.org/cmake/help/cmake2.6docs.html, http://qtnode.net/wiki/Qt4_with_cmake)
#FIND_PACKAGE(Qt4)
FIND_PACKAGE(Qt4 REQUIRED)
SET(QT_USE_QTCORE 1)
INCLUDE(${QT_USE_FILE})

# run moc
#QT4_WRAP_CPP(MOC_SRCS ${MOC_HEADERS} )

#INCLUDE_DIRECTORIES(../lib ../crypto)
#ADD_SUBDIRECTORY(lib crypto)

target_link_libraries(${PROJECT_NAME}
    ${PLUGIN_INTERNAL_DEPS}
    ${QT_LIBRARIES}
#    ${MOC_SRCS}
    )
