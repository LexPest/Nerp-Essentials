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
        source/ness/interface/IObservable.h source/ness/data/Property.h source/ness/interface/IHasMember.h source/ness/defines/IHasMember_Def.h)


add_library(Nerp-Essentials STATIC ${SRC_FILES})

# Including Boost
add_definitions(-DBOOST_LOG_DYN_LINK=1)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost REQUIRED COMPONENTS log filesystem system exception REQUIRED)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
include_directories(${Boost_INCLUDE_DIRS})