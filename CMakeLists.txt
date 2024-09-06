cmake_minimum_required(VERSION 3.24)

project(Utopia VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_PATH C:/Qt6)
set(OPENSSL_ROOT_DIR c:/Qt6/Tools/OpenSSL/Win_x64/include/openssl/)

find_package(Qt6 6.2  COMPONENTS Core Quick Qml Xml Network NetworkAuth WebSockets REQUIRED)

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






#target_include_directories(encryption PUBLIC "C:/Qt6/Tools/OpenSSL/Win_x64/include")
#target_link_directories(encryption PUBLIC "C:/Qt6/Tools/OpenSSL/Win_x64/lib" "C:/Qt6/Tools/OpenSSL/Win_x64/bin")



#qt_add_qml_module(appUtopia
#    URI Utopia
#    VERSION 1.0
#    QML_FILES main.qml
#)

add_executable(appUtopia
    ${PROJECT_SOURCES}

)

set_target_properties(appUtopia PROPERTIES

    WIN32_EXECUTABLE TRUE
)

target_link_libraries(
    appUtopia
    PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::Qml
    Qt6::Xml
    Qt6::NetworkAuth
    Qt6::Network
    Qt6::WebSockets
)




install(TARGETS appUtopia
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
