cmake_minimum_required(VERSION 3.15)
project(Ass1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Ass1 src/main.cpp src/Movie.cpp src/Episode.cpp src/Watchable.cpp src/Action.cpp src/Session.cpp src/User.cpp include/Session.h include/Watchable.h include/Action.h include/User.h)