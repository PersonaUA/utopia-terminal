cmake_minimum_required(VERSION 3.24)

project(utopia-terminal VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_PATH C:/Qt6)
set(OPENSSL_ROOT_DIR c:/Qt6/Tools/OpenSSL/Win_x64/include/openssl/)

find_package(Qt6 6.7 REQUIRED COMPONENTS Core Quick Qml Xml Network NetworkAuth WebSockets QmlImportScanner)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE Q_QML qtqml/*.*)
file(GLOB_RECURSE Q_NET api/net/*.*)
file(GLOB_RECURSE Q_CRP api/crp/*.*)
file(GLOB_RECURSE Q_DOM api/dom/*.*)



set(PROJECT_SOURCES
    WIN32
    ${Q_QML}
    ${Q_NET}
    ${Q_CRP}
    ${Q_DOM}
    main.cpp
    qml.qrc

)

add_executable(utopia-terminal
    ${PROJECT_SOURCES}

)

set_target_properties(utopia-terminal PROPERTIES

    WIN32_EXECUTABLE TRUE
)

target_link_libraries(
    utopia-terminal
    PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::QWindowsIntegrationPlugin
    Qt6::Qml
    Qt6::Xml
    Qt6::NetworkAuth
    Qt6::Network
    Qt6::WebSockets
)


qt_import_qml_plugins(utopia-terminal)

install(TARGETS utopia-terminal
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
