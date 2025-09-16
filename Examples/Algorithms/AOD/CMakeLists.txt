add_library(
    ActsExamplesAOD
    SHARED
    src/ActsToAo2d.cpp
)

find_package(O2 REQUIRED ReconstructionDataFormats)

target_include_directories(
    ActsExamplesAOD
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${O2_INCLUDE_DIRS}
)

target_link_libraries(
    ActsExamplesAOD
    PUBLIC ActsCore ActsExamplesFramework
    PRIVATE O2::ReconstructionDataFormats
)

install(
    TARGETS ActsExamplesAOD
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
