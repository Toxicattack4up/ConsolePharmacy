cmake_minimum_required(VERSION 3.10)
project(pharmacy_management_system)

set(CMAKE_CXX_STANDARD 17)

# Для использования функций времени
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

# Подавление предупреждений о устаревших функциях codecvt
add_definitions(-D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING)

add_executable(pharmacy_management_system
    main.cpp
    Medicine.h Medicine.cpp
    Customer.h Customer.cpp
    Prescription.h Prescription.cpp
    Employee.h Employee.cpp
    Administrator.h Administrator.cpp
    Sale.h Sale.cpp
    User.h User.cpp
    utils.h utils.cpp
    logger.h logger.cpp
    medicine_storage.h medicine_storage.cpp
)