include(GenerateExportHeader)
include(ECMPackageConfigHelpers)
include(ECMSetupVersion)
include(ECMGenerateHeaders)

ecm_setup_version(${PROJECT_VERSION} VARIABLE_PREFIX PAPYROS
                  VERSION_HEADER "${CMAKE_CURRENT_BINARY_DIR}/papyros_version.h"
                  PACKAGE_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/PapyrosConfigVersion.cmake"
                  SOVERSION ${PROJECT_SOVERSION})

include_directories(
    ${CMAKE_BINARY_DIR}/headers
    ${CMAKE_CURRENT_BINARY_DIR}
)

set(SOURCES
    config/kquickconfig.cpp
    qquicklist/qobjectlistmodel.cpp
    wallet/kquickwallet.cpp
)

add_library(Papyros SHARED ${SOURCES})
generate_export_header(Papyros EXPORT_FILE_NAME papyros/papyros_export.h)
add_library(Papyros::Core ALIAS Papyros)

target_link_libraries(Papyros
    PUBLIC
        Qt5::Core
        Qt5::Qml
        KF5::ConfigCore
        KF5::Wallet
)

set(PAPYROS_INCLUDEDIR "${CMAKE_INSTALL_INCLUDEDIR}/Papyros")

target_include_directories(Papyros INTERFACE "$<INSTALL_INTERFACE:${PAPYROS_INCLUDEDIR}>")

set_target_properties(Papyros PROPERTIES VERSION   ${PROJECT_VERSION}
                                         SOVERSION ${PROJECT_SOVERSION}
                                         EXPORT_NAME Core
)

ecm_generate_headers(Papyros_CamelCase_HEADERS
  HEADER_NAMES
    KQuickConfig
  PREFIX
    Papyros
  REQUIRED_HEADERS Papyros_HEADERS
  RELATIVE config
)
ecm_generate_headers(Papyros_CamelCase_HEADERS
  HEADER_NAMES
    QQuickList QObjectListModel
  PREFIX
    Papyros
  REQUIRED_HEADERS Papyros_HEADERS
  RELATIVE qquicklist
)
ecm_generate_headers(Papyros_CamelCase_HEADERS
  HEADER_NAMES
    KQuickWallet
  PREFIX
    Papyros
  REQUIRED_HEADERS Papyros_HEADERS
  RELATIVE wallet
)

install(FILES ${Papyros_CamelCase_HEADERS}
        DESTINATION ${PAPYROS_INCLUDEDIR}/Papyros
        COMPONENT Devel)

install(TARGETS Papyros EXPORT PapyrosTargets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

install(
    FILES
      ${CMAKE_CURRENT_BINARY_DIR}/papyros/papyros_export.h
      ${Papyros_HEADERS}
    DESTINATION
      ${PAPYROS_INCLUDEDIR}/papyros
    COMPONENT
      Devel
)

# Create a Config.cmake and a ConfigVersion.cmake file and install them
set(CMAKECONFIG_INSTALL_DIR "${CMAKECONFIG_INSTALL_PREFIX}/Papyros")

ecm_configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/PapyrosConfig.cmake.in"
                                  "${CMAKE_CURRENT_BINARY_DIR}/PapyrosConfig.cmake"
                                  INSTALL_DESTINATION  ${CMAKECONFIG_INSTALL_DIR})

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/PapyrosConfig.cmake"
              "${CMAKE_CURRENT_BINARY_DIR}/PapyrosConfigVersion.cmake"
        DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
        COMPONENT Devel)

install(EXPORT PapyrosTargets
        DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
        FILE PapyrosTargets.cmake NAMESPACE Papyros::)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/papyros_version.h
        DESTINATION ${PAPYROS_INCLUDEDIR}/papyros COMPONENT Devel)
