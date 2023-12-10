cmake_minimum_required(VERSION 3.5)

project(password_manager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(OBJ_LIBS
    managers/asm/passwordCoder.o
    managers/asm/passwordGenerator.o
)

set(MANAGERS_SOURCE
    managers/managers/encryptManager.cpp
    managers/managers/encryptManager.h
    managers/managers/dataManager.h
    managers/managers/dataManager.cpp
    managers/managers/passwordManager.h
    managers/managers/passwordManager.cpp
)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        passwordaddwidget.cpp
        passwordaddwidget.h
        passwordaddwidget.ui
        passwordinfowidget.cpp
        passwordinfowidget.h
        passwordinfowidget.ui
        authwidget.cpp
        authwidget.h
        authwidget.ui
        ${MANAGERS_SOURCE}
        ${OBJ_LIBS}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(password_manager
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET password_manager APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(password_manager SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(password_manager
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(password_manager PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(password_manager PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS password_manager
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(password_manager)
endif()
