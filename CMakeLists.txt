cmake_minimum_required(VERSION 3.16)

project(QtSliderSpinBox VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Test)

add_executable(QtSliderSpinBox
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
)

target_link_libraries(QtSliderSpinBox PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
)

enable_testing()

add_executable(QtSliderSpinBox_tests
    tests/main.cpp
    tests/testsuite.cpp
    tests/testsuite.h
    src/mainwindow.cpp
    src/mainwindow.h
)

target_include_directories(QtSliderSpinBox_tests PRIVATE src tests)

target_link_libraries(QtSliderSpinBox_tests PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Test
)

add_test(NAME QtSliderSpinBox_tests COMMAND QtSliderSpinBox_tests)
set_tests_properties(QtSliderSpinBox_tests PROPERTIES
    ENVIRONMENT "QT_QPA_PLATFORM=offscreen"
)
