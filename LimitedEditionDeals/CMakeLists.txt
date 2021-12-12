cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp cmake-build-debug/deal.cpp cmake-build-debug/deal.h cmake-build-debug/deal_builder.cpp cmake-build-debug/deal_builder.h cmake-build-debug/user.cpp cmake-build-debug/user.h cmake-build-debug/product.cpp cmake-build-debug/product.h cmake-build-debug/deal_maintainer.cpp cmake-build-debug/deal_maintainer.h)
