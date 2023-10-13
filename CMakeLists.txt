cmake_minimum_required(VERSION 2.8.12)

project(TSiSa_RK_1)

add_executable(TSiSa_RK_1
    main.cpp
    metods_lab1.cpp
    random_lab2.cpp

    func.h
    )

#
# CHANGE METOD:
#
# passive search, method dichotomy, golden ratio, Fibonacci (lab 1)
# OR..
# random (lab 2)
#

#target_compile_definitions(TSiSa_RK_1 PRIVATE RANDOM)

#target_compile_definitions(TSiSa_RK_1 PRIVATE PASSIVE_SEARCH)
#target_compile_definitions(TSiSa_RK_1 PRIVATE DICHOTOMY)
#target_compile_definitions(TSiSa_RK_1 PRIVATE GOLDEN_RATIO)
target_compile_definitions(TSiSa_RK_1 PRIVATE FIBONACCI)
