cmake_minimum_required(VERSION 3.10)
project(general-purpose-control LANGUAGES CXX C)

option(BUILD_DOCS "Build doxygen files" ON)

string(TIMESTAMP PROJECT_DATE_STRING "%b %d, %Y")

set(PROJECT_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(PROJECT_UI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(PROJECT_RES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/res")
set(PROJECT_HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(PROJECT_CONFIG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/config")

set(CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_UI_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/version.cmake")

configure_file(
    "${PROJECT_CONFIG_DIR}/version.h"
    "${PROJECT_HEADER_DIR}/version.h"
)

# check if Doxygen is installed (from https://vicrucann.github.io/tutorials/quick-cmake-doxygen/)
find_package(Doxygen)
if (DOXYGEN_FOUND AND BUILD_DOCS)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doxygen/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/doxygen/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
    )
elseif (BUILD_DOCS)
    message("doxygen need to be installed to generate the doxygen documentation. for generating tree views graphviz is needed.")
else ()
    message("Selected option doxygen build OFF. Doxygen will not be build.")
endif ()

if(${BUILD_TIDY})
  set(CMAKE_CXX_CLANG_TIDY
      clang-tidy;
      -header-filter=^global;
      -checks=-*,readability-*,bugprone-*,performace-*,clang-analyzer-*,modernize-*,hicpp-*;
      )
endif(${BUILD_TIDY})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)

list(APPEND CMAKE_PREFIX_PATH "C:/Qt/5.15.1/msvc2019_64/lib/cmake/Qt5QuickCompiler")
list(APPEND CMAKE_PREFIX_PATH "C:/Qt/5.15.1/msvc2019_64/lib/cmake/Qt5")

else()

set(Qt5_DIR "/usr/lib/x86_64-linux-gnu/cmake/Qt5/")

endif()

#if (MSVC)
#    if("${MSVC_RUNTIME}" STREQUAL "")
#        set(MSVC_RUNTIME "static")
#    endif()
#        # Set compiler options.
#    set(variables
#      CMAKE_C_FLAGS_DEBUG
#      CMAKE_C_FLAGS_MINSIZEREL
#      CMAKE_C_FLAGS_RELEASE
#      CMAKE_C_FLAGS_RELWITHDEBINFO
#      CMAKE_CXX_FLAGS_DEBUG
#      CMAKE_CXX_FLAGS_MINSIZEREL
#      CMAKE_CXX_FLAGS_RELEASE
#      CMAKE_CXX_FLAGS_RELWITHDEBINFO
#    )
#    if(${MSVC_RUNTIME} STREQUAL "static")
#      message(STATUS
#        "MSVC -> forcing use of statically-linked runtime."
#      )
#      foreach(variable ${variables})
#        if(${variable} MATCHES "/MD")
#          string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
#        endif()
#      endforeach()
#    else()
#      message(STATUS
#        "MSVC -> forcing use of dynamically-linked runtime."
#      )
#      foreach(variable ${variables})
#        if(${variable} MATCHES "/MT")
#          string(REGEX REPLACE "/MT" "/MD" ${variable} "${${variable}}")
#        endif()
#      endforeach()
#    endif()
#endif()

find_package(Qt5 COMPONENTS Network SerialPort Svg Widgets Gui REQUIRED)

if(NOT WIN32) # added to make program editable in qt-creator on windows

find_library(RT rt REQUIRED)
find_library(PTHREAD pthread REQUIRED)

endif()

add_compile_options(
    -Wall
    -O3
    )
if (MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
else()

add_compile_options(
    -Wextra
    -Wshadow
    -Wpedantic
    )

endif()

if (${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "armv7l")
add_compile_options(
    -mthumb
    -mthumb-interwork
    -march=armv7-a
    )
endif (${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "armv7l")

set(PROJECT_SOURCE_FILES
    "${PROJECT_SRC_DIR}/devicemanager.cpp"
    "${PROJECT_SRC_DIR}/devices/dummy.cpp"
    "${PROJECT_SRC_DIR}/filehandler.cpp"
    "${PROJECT_SRC_DIR}/scanparameterselection.cpp"
    "${PROJECT_SRC_DIR}/serialconsole.cpp"
    "${PROJECT_SRC_DIR}/devices/keithley_2000.cpp"
    "${PROJECT_SRC_DIR}/devices/keithley_2410.cpp"
    "${PROJECT_SRC_DIR}/main.cpp"
    "${PROJECT_SRC_DIR}/mainwindow.cpp"
    "${PROJECT_SRC_DIR}/measurementdevice.cpp"
    "${PROJECT_SRC_DIR}/settings.cpp"
    "${PROJECT_SRC_DIR}/devices/scpidevice.cpp"
    "${PROJECT_SRC_DIR}/devices/sourcetronic_st2819a.cpp"
    "${PROJECT_SRC_DIR}/devices/sourcetronic_st2826.cpp"
    "${PROJECT_SRC_DIR}/devices/rigol_dsa1030a.cpp"
    "${PROJECT_SRC_DIR}/devices/hameg_hm8143.cpp"
    "${PROJECT_SRC_DIR}/devices/gw_instek_gpd4303s.cpp"
    "${PROJECT_SRC_DIR}/devices/hp_34401a.cpp"
    "${PROJECT_SRC_DIR}/devices/tektronix_dmm4020.cpp"
    "${PROJECT_SRC_DIR}/devices/voltcraft_psp1803.cpp"
    "${PROJECT_SRC_DIR}/serial.cpp"
    #"${PROJECT_SRC_DIR}/devices/i2c/i2cdevices/lm75/lm75.cpp"
    #"${PROJECT_SRC_DIR}/devices/i2c/i2cdevices/sht21/sht21.cpp"
    #"${PROJECT_SRC_DIR}/devices/i2c/i2cdevices/ads1115/ads1115.cpp"
    #"${PROJECT_SRC_DIR}/devices/i2c/i2cdevices/x9119/x9119.cpp"
    #"${PROJECT_SRC_DIR}/devices/i2c/i2cdevices/i2cdevice.cpp"
    #"${PROJECT_SRC_DIR}/devices/spi/serialadapter/serialadapter.cpp"
    #"${PROJECT_SRC_DIR}/devices/spi/serialadapter/spi.cpp"
)

set(PROJECT_HEADER_FILES
    "${PROJECT_HEADER_DIR}/devicemanager.h"
    "${PROJECT_HEADER_DIR}/devices/dummy.h"
    "${PROJECT_HEADER_DIR}/filehandler.h"
    "${PROJECT_HEADER_DIR}/scanparameterselection.h"
    "${PROJECT_HEADER_DIR}/serialconsole.h"
    "${PROJECT_HEADER_DIR}/devices/keithley_2000.h"
    "${PROJECT_HEADER_DIR}/devices/keithley_2410.h"
    "${PROJECT_HEADER_DIR}/mainwindow.h"
    "${PROJECT_HEADER_DIR}/measurementdevice.h"
    "${PROJECT_HEADER_DIR}/settings.h"
    "${PROJECT_HEADER_DIR}/devices/scpidevice.h"
    "${PROJECT_HEADER_DIR}/devices/sourcetronic_st2819a.h"
    "${PROJECT_HEADER_DIR}/devices/sourcetronic_st2826.h"
    "${PROJECT_HEADER_DIR}/devices/rigol_dsa1030a.h"
    "${PROJECT_HEADER_DIR}/devices/hameg_hm8143.h"
    "${PROJECT_HEADER_DIR}/devices/gw_instek_gpd4303s.h"
    "${PROJECT_HEADER_DIR}/devices/hp_34401a.h"
    "${PROJECT_HEADER_DIR}/devices/tektronix_dmm4020.h"
    "${PROJECT_HEADER_DIR}/devices/voltcraft_psp1803.h"
    "${PROJECT_HEADER_DIR}/serial.h"
    #"${PROJECT_HEADER_DIR}/devices/i2c/i2cdevices/lm75/lm75.h"
    #"${PROJECT_HEADER_DIR}/devices/i2c/i2cdevices/sht21/sht21.h"
    #"${PROJECT_HEADER_DIR}/devices/i2c/i2cdevices/ads1115/ads1115.h"
    #"${PROJECT_HEADER_DIR}/devices/i2c/i2cdevices/x9119/x9119.h"
    #"${PROJECT_HEADER_DIR}/devices/i2c/i2cdevices/i2cdevice.h"
    #"${PROJECT_HEADER_DIR}/devices/spi/serialadapter/serialadapter.h"
    #"${PROJECT_HEADER_DIR}/devices/spi/serialadapter/spi.h"
)


set(PROJECT_UI_FILES
    "${PROJECT_UI_DIR}/mainwindow.ui"
    "${PROJECT_UI_DIR}/adjustedvalue.ui"
    "${PROJECT_UI_DIR}/measurementdevice.ui"
    "${PROJECT_UI_DIR}/scanparameterselection.ui"
    "${PROJECT_UI_DIR}/serialconsole.ui"
    "${PROJECT_UI_DIR}/settings.ui"
)

set(PROJECT_RESOURCE_FILES "")

find_package(Qt5QuickCompiler)

if(Qt5QuickCompiler_FOUND)

qtquick_compiler_add_resources(qml_QRC "${PROJECT_RES_DIR}/resources.qrc")

else()

qt5_add_resources(qml_QRC "${PROJECT_RES_DIR}/resources.qrc")

endif()


#configure_file(
#    "${PROJECT_CONFIG_DIR}/general-purpose-control.1"
#    "${CMAKE_CURRENT_BINARY_DIR}/general-purpose-control.1"
#    )

add_executable(general-purpose-control ${PROJECT_SOURCE_FILES} ${PROJECT_HEADER_FILES} ${PROJECT_UI_FILES} ${PROJECT_RESOURCE_FILES} ${qml_QRC})

set_property(TARGET general-purpose-control PROPERTY POSITION_INDEPENDENT_CODE 1)

if(WIN32)

target_link_libraries(general-purpose-control
    Qt5::SerialPort Qt5::Widgets Qt5::Gui Qt5::Svg
)

else()

target_link_libraries(general-purpose-control
    Qt5::SerialPort Qt5::Widgets Qt5::Gui Qt5::Svg
    rt
    pthread
)

endif()


target_include_directories(general-purpose-control PUBLIC
    $<BUILD_INTERFACE:${PROJECT_HEADER_DIR}>
    ${Qt5Svg_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5QuickWidgets_INCLUDE_DIRS}
)
#if (CMAKE_BUILD_TYPE STREQUAL Release)
#    add_custom_command(TARGET general-purpose-control POST_BUILD
#            COMMAND ${CMAKE_STRIP} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/general-purpose-control")
#endif ()

if(WIN32)

include("${PROJECT_SOURCE_DIR}/cmake/Windeployqt.cmake")
set(windeploy_options
    #--qmldir "${PROJECT_QML_DIR}"
    -opengl
    -printsupport
) # additional options for windeployqt.exe


windeployqt(general-purpose-control "${PROJECT_BINARY_DIR}/bin" "${windeploy_options}")
# create a list of files to copy
#set( THIRD_PARTY_DLLS
#   "${OPENSSL_DIR}/bin/libcrypto-1_1-x64.dll"
#   "${OPENSSL_DIR}/bin/libssl-1_1-x64.dll"
#   "${QWT_DIR}/lib/qwt.dll"
#   "${MQTT_CPP_DIR}/lib/paho-mqttpp3.dll"
#   "${MQTT_C_DIR}/lib/paho-mqtt3a.dll"
#   "${MQTT_C_DIR}/lib/paho-mqtt3as.dll"
#   "${MQTT_C_DIR}/lib/paho-mqtt3c.dll"
#   "${MQTT_C_DIR}/lib/paho-mqtt3cs.dll"
#)

# do the copying
#foreach( file_i ${THIRD_PARTY_DLLS})
#    add_custom_command(
#            TARGET general-purpose-control POST_BUILD
#            COMMAND ${CMAKE_COMMAND} -E copy
#                    "${file_i}"
#                    "${PROJECT_BINARY_DIR}/../bin/"
#    )
#    install(FILES "${file_i}" DESTINATION "bin" COMPONENT gui)
#endforeach( file_i )


set(CPACK_GENERATOR "NSIS")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${PROJECT_CONFIG_DIR}/description.txt")
set(CPACK_NSIS_MODIFY_PATH ON)
include(InstallRequiredSystemLibraries)

#set(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")

# There is a bug in NSI that does not handle full UNIX paths properly.
# Make sure there is at least one set of four backlashes.
#set(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\muondetector-gui.exe")
set(CPACK_NSIS_DISPLAY_NAME "General-Purpose-Control")
set(CPACK_NSIS_HELP_LINK "https://github.com/marvin5300/generalpurposecontrol")
set(CPACK_NSIS_URL_INFO_ABOUT "https://github.com/marvin5300/generalpurposecontrol")
set(CPACK_NSIS_CONTACT "Marvin Peter <marvin.peter@physik.uni-giessen.de>")
#set(CPACK_NSIS_MUI_ICON "${PROJECT_RES_DIR}/res/muon.ico")
#set(CPACK_NSIS_MUI_UNIICON "${PROJECT_RES_DIR}/res/muon.ico")
set(CPACK_PACKAGE_EXECUTABLES "general-purpose-control" "general-purpose-control")

else()

include(GNUInstallDirs)

add_custom_target(changelog ALL COMMAND gzip -cn9 "${PROJECT_CONFIG_DIR}/changelog" > "${CMAKE_CURRENT_BINARY_DIR}/changelog.gz")
#add_custom_target(manpage ALL COMMAND gzip -cn9 "${CMAKE_CURRENT_BINARY_DIR}/muondetector-daemon.1" > "${CMAKE_CURRENT_BINARY_DIR}/muondetector-daemon.1.gz")
#add_custom_target(manpage-login ALL COMMAND gzip -cn9 "${CMAKE_CURRENT_BINARY_DIR}/muondetector-login.1" > "${CMAKE_CURRENT_BINARY_DIR}/muondetector-login.1.gz")

install(TARGETS general-purpose-control DESTINATION bin COMPONENT general-purpose-control)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/changelog.gz" DESTINATION "${CMAKE_INSTALL_DOCDIR}" COMPONENT general-purpose-control)
#install(FILES "${CMAKE_CURRENT_BINARY_DIR}/general-purpose-control.1.gz" DESTINATION "share/man/man1/" COMPONENT general-purpose-control)#
install(FILES "${PROJECT_CONFIG_DIR}/copyright" DESTINATION "${CMAKE_INSTALL_DOCDIR}" COMPONENT general-purpose-control)
#install(FILES ${DAEMON_INSTALL_FILES} DESTINATION "/etc/muondetector/" COMPONENT general-purpose-control)
#install(FILES "${PROJECT_CONFIG_DIR}/daemon.service" DESTINATION "/lib/systemd/system" COMPONENT general-purpose-control)



set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
#set(CPACK_DEBIAN_PACKAGE_DEPENDS "")
#set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${PROJECT_CONFIG_DIR}/preinst;${PROJECT_CONFIG_DIR}/postinst;${PROJECT_CONFIG_DIR}/prerm;${PROJECT_CONFIG_DIR}/conffiles")
set(CPACK_PACKAGE_VENDOR "Marvin Peter <marvin.peter@physik.uni-giessen.de>")
set(CPACK_DEBIAN_PACKAGE_SECTION "net")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Graphical control program for tabletop lab devices")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION " Select devices and ports for read and set parameters.
 Loop / ramp over parameters and read a set of parameters independent of device.
 It is licensed under the GNU Lesser General Public License version 3 (LGPL v3).")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://github.com/marvin5300/generalpurposecontrol")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "MuonPi <developer@muonpi.org>")

endif()

set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_CONFIG_DIR}/license")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/../packages/")

include(CPack)
