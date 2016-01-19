include_directories(${CMAKE_BINARY_DIR}/src)

set(SOURCES plugin.cpp)

add_library(papyroscore SHARED ${SOURCES})
target_link_libraries(papyroscore
                      Qt5::Core
                      Qt5::Gui
                      Qt5::Qml
                      Qt5::Quick
                      Papyros::Core)

install(TARGETS papyroscore
        LIBRARY DESTINATION ${QML_INSTALL_DIR}/Papyros/Core)
install(FILES qmldir
        DESTINATION ${QML_INSTALL_DIR}/Papyros/Core)
