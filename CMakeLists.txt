cmake_minimum_required(VERSION 3.27)
project(A10H)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.7.1/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Charts
        REQUIRED)

add_executable(A10H main.cpp
        includes/domain/domain.h
        includes/domain/dynamicVector.h
        includes/exceptions/Exceptions.h
        includes/repository/CSVRepository.h
        includes/repository/FileRepository.h
        includes/repository/HTMLRepository.h
        includes/repository/repository.h
        includes/service/service.h
        includes/ui/ui.h
        includes/UndoRedoService/UndoRedoService.h
        includes/utils/Utils.h
        includes/validators/MovieValidator.h
        src/domain/domain.cpp
        src/Exceptions/Exceptions.cpp
        src/repository/CSVRepository.cpp
        src/repository/FileRepository.cpp
        src/repository/HTMLRepository.cpp
        src/repository/repository.cpp
        src/service/service.cpp
        src/ui/ui.cpp
        src/UndoRedoService/UndoRedoService.cpp
        src/utils/Utils.cpp
        src/validators/MovieValidator.cpp
        src/gui/adminwidget.h
        src/gui/barchartwidget.h
        src/gui/chooseconnectionmodewidget.h
        src/gui/choosemodewidget.h
        src/gui/Connecter.h
        src/gui/databasewidget.h
        src/gui/mainwindow.h
        src/gui/tableView.h
        src/gui/userwidget.h
        src/gui/watchlistwidget.h
        src/gui/adminwidget.cpp
        src/gui/barchartwidget.cpp
        src/gui/chooseconnectionmodewidget.cpp
        src/gui/choosemodewidget.cpp
        src/gui/Connecter.cpp
        src/gui/databasewidget.cpp
        src/gui/mainwindow.cpp
        src/gui/tableView.cpp
        src/gui/userwidget.cpp
        src/gui/watchlistwidget.cpp)
target_link_libraries(A10H
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Charts
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets Charts)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
