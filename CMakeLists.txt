cmake_minimum_required(VERSION 3.5)

project(Project1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Project1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        file_parser.h
        file_parser.cpp
        vector.h
        vector.cpp

        shape_resources.qrc
        file_parser.cpp file_parser.h mainwindow.cpp mainwindow.h mainwindow.ui shape_list.txt shape_resources.qrc vector.cpp vector.h
        shape.cpp shape.h shape.ui
        line.h line.cpp
        polyline.h polyline.cpp
        rectangle.h rectangle.cpp
        polygon.h polygon.cpp
        text.h text.cpp
        circle.h circle.cpp
        ellipse.h ellipse.cpp
        square.h square.cpp
        contact_us.cpp
        contact_us.h
        canvas.h canvas.cpp
        canvas.cpp
        canvas.h
        sort.h sort.cpp

        shape_editor.h shape_editor.cpp shape_editor.ui




        add_polygon.h add_polygon.cpp add_polygon.ui
        add_linepoly.h add_linepoly.cpp add_linepoly.ui
        add_circelip.h add_circelip.cpp add_circelip.ui
        add_squrec.h add_squrec.cpp add_squrec.ui
        add_text.h add_text.cpp add_text.ui
        serializer.h
        serializer.cpp



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Project1 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Project1 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Project1
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Project1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Project1)
endif()
set_target_properties(Project1 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Project1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Project1)
endif()
