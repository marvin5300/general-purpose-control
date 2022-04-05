cmake_minimum_required(VERSION 3.10)

project(MeasurementControl VERSION 0.1 LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(PROJECT_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(PROJECT_UI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(PROJECT_RES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/res")
set(PROJECT_HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(PROJECT_CONFIG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/config")
set(CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_UI_DIR}")
#set(APP_ICON_RESOURCE "${CMAKE_CURRENT_SOURCE_DIR}/res/ProgramIcon.png")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#list(APPEND CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/Qt5")
#list(APPEND CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake\\Qt5")
#list(APPEND CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake\\Qt5Widgets")
#list(APPEND CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake\\Qt5Gui")
set(Qt5_DIR "/usr/lib/x86_64-linux-gnu/cmake/Qt5/")

find_package(QT NAMES Qt5 COMPONENTS  Network Widgets Svg SerialPort Gui LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR}  COMPONENTS Svg SerialPort  Widgets Gui LinguistTools REQUIRED)

set(TS_FILES MeasurementControl_en_150.ts)

set(PROJECT_SOURCES_FILES

        "${PROJECT_SRC_DIR}/main.cpp"
        "${PROJECT_SRC_DIR}/mainwindow.cpp"
        "${PROJECT_SRC_DIR}/CLogger.cpp"
        "${PROJECT_SRC_DIR}/chighlighter.cpp"
        "${PROJECT_SRC_DIR}/cprobersystem.cpp"
        "${PROJECT_SRC_DIR}/CPosition.cpp"
        "${PROJECT_SRC_DIR}/cdevice.cpp"
        "${PROJECT_SRC_DIR}/cprobervisu.cpp"
        "${PROJECT_SRC_DIR}/cmeasurementdevice.cpp"
        "${PROJECT_SRC_DIR}/cmeasurementcontrol.cpp"
        "${PROJECT_SRC_DIR}/CSynchcommConsumer.cpp"
        "${PROJECT_SRC_DIR}/CSynchcommProducer.cpp"
        "${PROJECT_SRC_DIR}/CPositionVisuXYZ.cpp"
        "${PROJECT_SRC_DIR}/CPositionVisuXY.cpp"
        "${PROJECT_SRC_DIR}/measurementdevice.cpp"
        "${PROJECT_SRC_DIR}/devicemanager.cpp"
        "${PROJECT_SRC_DIR}/serial.cpp"
        "${PROJECT_SRC_DIR}/serialconsole.cpp"
        "${PROJECT_SRC_DIR}/settings.cpp"
        "${PROJECT_SRC_DIR}/scanparameterselection.cpp"
        "${PROJECT_SRC_DIR}/filehandler.cpp"
        "${PROJECT_SRC_DIR}/devices/scpidevice.cpp"
        "${PROJECT_SRC_DIR}/devices/dummy.cpp"
        "${PROJECT_SRC_DIR}/devices/sourcetronic_st2819a.cpp"
        "${PROJECT_SRC_DIR}/devices/keithley_2410.cpp"
        "${PROJECT_SRC_DIR}/devices/keithley_2000.cpp"
        "${PROJECT_SRC_DIR}/devices/gw_instek_gpd4303s.cpp"
        "${PROJECT_SRC_DIR}/devices/hameg_hm8143.cpp"
        "${PROJECT_SRC_DIR}/devices/hp_34401a.cpp"
        "${PROJECT_SRC_DIR}/devices/rigol_dsa1030a.cpp"
        "${PROJECT_SRC_DIR}/devices/sourcetronic_st2826.cpp"
        "${PROJECT_SRC_DIR}/devices/tektronix_dmm4020.cpp"
        "${PROJECT_SRC_DIR}/devices/voltcraft_psp1803.cpp"

        "${PROJECT_RES_DIR}/resources.qrc"
        ${TS_FILES}
    )

set(PROJECT_HEADER_FILES
        "${PROJECT_HEADER_DIR}/mainwindow.h"
        "${PROJECT_HEADER_DIR}/EnumHelper.h"
        "${PROJECT_HEADER_DIR}/CLogger.h"
        "${PROJECT_HEADER_DIR}/chighlighter.h"
        "${PROJECT_HEADER_DIR}/cprobersystem.h"
        "${PROJECT_HEADER_DIR}/CPosition.h"
        "${PROJECT_HEADER_DIR}/cdevice.h"
        "${PROJECT_HEADER_DIR}/cprobervisu.h"
        "${PROJECT_HEADER_DIR}/cmeasurementdevice.h"
        "${PROJECT_HEADER_DIR}/cmeasurementcontrol.h"
        "${PROJECT_HEADER_DIR}/CSynchcommConsumer.h"
        "${PROJECT_HEADER_DIR}/CSynchcommProducer.h"
        "${PROJECT_HEADER_DIR}/GlobalConsts.h"
        "${PROJECT_HEADER_DIR}/CPositionVisuXYZ.h"
        "${PROJECT_HEADER_DIR}/CPositionVisuXY.h"
        "${PROJECT_HEADER_DIR}/measurementparameter.h"
        "${PROJECT_HEADER_DIR}/measurementdevice.h"
        "${PROJECT_HEADER_DIR}/devicemanager.h"
        "${PROJECT_HEADER_DIR}/serial.h"
        "${PROJECT_HEADER_DIR}/serialconsole.h"
        "${PROJECT_HEADER_DIR}/settings.h"
        "${PROJECT_HEADER_DIR}/scanparameterselection.h"
        "${PROJECT_HEADER_DIR}/filehandler.h"
        "${PROJECT_HEADER_DIR}/devices/scpidevice.h"
        "${PROJECT_HEADER_DIR}/devices/dummy.h"
        "${PROJECT_HEADER_DIR}/devices/sourcetronic_st2819a.h"
        "${PROJECT_HEADER_DIR}/devices/keithley_2410.h"
        "${PROJECT_HEADER_DIR}/devices/keithley_2000.h"
        "${PROJECT_HEADER_DIR}/devices/gw_instek_gpd4303s.h"
        "${PROJECT_HEADER_DIR}/devices/hameg_hm8143.h"
        "${PROJECT_HEADER_DIR}/devices/hp_34401a.h"
        "${PROJECT_HEADER_DIR}/devices/rigol_dsa1030a.h"
        "${PROJECT_HEADER_DIR}/devices/sourcetronic_st2826.h"
        "${PROJECT_HEADER_DIR}/devices/tektronix_dmm4020.h"
        "${PROJECT_HEADER_DIR}/devices/voltcraft_psp1803.h"
)
 
set(PROJECT_RESOURCE_FILES 
        ""
)
        

set(PROJECT_UI_FILES
    "${PROJECT_UI_DIR}/mainwindow.ui"
    "${PROJECT_UI_DIR}/adjustedvalue.ui"
    "${PROJECT_UI_DIR}/measurementdevice.ui"
    "${PROJECT_UI_DIR}/scanparameterselection.ui"
    "${PROJECT_UI_DIR}/serialconsole.ui"
    "${PROJECT_UI_DIR}/settings.ui"
)

find_package(Qt5QuickCompiler)
#if(Qt5QuickCompiler_FOUND)

#qtquick_compiler_add_resources(qml_QRC "${PROJECT_RES_DIR}/resources.qrc")

#else()

#qt5_add_resources(qml_QRC "${PROJECT_RES_DIR}/resources.qrc")
#endif()

find_package(Qt5 COMPONENTS Network SerialPort Svg Widgets Gui REQUIRED)

if(NOT WIN32) # added to make program editable in qt-creator on windows

find_library(RT rt REQUIRED)
find_library(PTHREAD pthread REQUIRED)

endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MeasurementControl
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${PROJECT_RESOURCE_FILES}
        ${PROJECT_RES_DIR}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MeasurementControl APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(MeasurementControl SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MeasurementControl
            ${PROJECT_SOURCES_FILES}
            ${PROJECT_HEADER_FILES}
            ${PROJECT_UI_FILES}
            ${PROJECT_RESOURCE_FILES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_include_directories(MeasurementControl PUBLIC
    $<BUILD_INTERFACE:${PROJECT_HEADER_DIR}>
    ${Qt5Svg_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5QuickWidgets_INCLUDE_DIRS}
)

target_link_libraries(MeasurementControl Qt5::SerialPort Qt5::Widgets Qt5::Gui Qt5::Svg)






set_target_properties(MeasurementControl PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MeasurementControl)
endif()


