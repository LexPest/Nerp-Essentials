cmake_minimum_required(VERSION 3.14)
project(Nerp-Essentials)

set(CMAKE_CXX_STANDARD 14)

# Set version
SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 2)
SET(VERSION_PATCH 0)
SET(PROJECT_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

include_directories(source)

add_definitions(-DNESSLIB_EXPORTS)

set(SRC_FILES
        source/ness/data/IterVersion.cpp
        source/ness/data/IterVersion.h
        source/ness/data/Version.cpp
        source/ness/data/Version.h
        source/ness/interface/ILinkedObserver.h
        source/ness/interface/IObservable.h)


add_library(Nerp-Essentials STATIC ${SRC_FILES})