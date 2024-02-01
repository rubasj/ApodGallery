cmake_minimum_required(VERSION 3.16)

project(ApodGallery VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appApodGallery
    main.cpp
)

qt_add_qml_module(appApodGallery
    URI ApodGallery
    VERSION 1.0
    QML_FILES Main.qml
    RESOURCES app_icons/menu.png
              app_icons/settings.png
              app_icons/favourite.png
              app_icons/favourite_unfilled.png
              app_icons/rotate_left.png
              app_icons/rotate_rigth.png


              img/img0.jpg
              img/img1.jpg
              img/img3.jpg
              img/favourites/favourites.txt
              SOURCES imageelement.h imageelement.cpp
              SOURCES
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appApodGallery PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appApodGallery
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appApodGallery
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appApodGallery
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
