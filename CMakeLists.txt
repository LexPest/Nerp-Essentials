cmake_minimum_required(VERSION 3.14)
project(Nerp-Essentials)

set(CMAKE_CXX_STANDARD 14)

# Set version
SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 2)
SET(VERSION_PATCH 0)
SET(PROJECT_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

include_directories(source)
include_directories(source/data)
include_directories(source/extensions)
include_directories(source/interface)

add_definitions(-DNESSLIB_EXPORTS)

set(SRC_FILES
        source/data/IterVersion.cpp
        source/data/IterVersion.h
        source/data/Version.cpp
        source/data/Version.h
        source/interface/ILinkedObserver.cpp
        source/interface/ILinkedObserver.h
        source/interface/IObservable.cpp
        source/interface/IObservable.h)


add_library(Nerp-Essentials STATIC ${SRC_FILES})