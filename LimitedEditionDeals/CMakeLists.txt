cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp deal.cpp deal.h deal_builder.cpp deal_builder.h user.cpp user.h product.cpp product.h deal_maintainer.cpp deal_maintainer.h)
