cmake_minimum_required(VERSION 3.30)

# Nombre del proyecto
project(sonarqube_unit_test VERSION 1.0.0 LANGUAGES C CXX)

# Configuración global de CMake
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Incluir los archivos de cabecera
include_directories(${CMAKE_SOURCE_DIR})

# Archivos fuente comunes (implementación)
set(SOURCES_COMMON
        Episodio.cpp
        Video.cpp
        Serie.cpp
        Pelicula.cpp
)

# Crear el ejecutable principal
add_executable(main
        streaming_main.cpp
        ${SOURCES_COMMON}
)

# Opciones
option(ENABLE_TESTING "Enable a Unit Testing build." ON)
option(ENABLE_COVERAGE "Enable coverage reporting" ON)

# Si se habilita la cobertura, establecer flags
if (ENABLE_COVERAGE)
    message(STATUS "Enabling coverage flags for GCC/Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Descarga GoogleTest usando FetchContent
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Si se habilitan las pruebas, agrega GoogleTest y las pruebas unitarias
if(ENABLE_TESTING)
    enable_testing()

    function(add_test_executable name test_source)
        add_executable(${name} ${test_source} ${SOURCES_COMMON})
        target_link_libraries(${name} PRIVATE gtest gtest_main)
        if (ENABLE_COVERAGE)
            target_link_libraries(${name} PRIVATE gcov)
            target_compile_options(${name} PRIVATE --coverage -fprofile-arcs -ftest-coverage)
            target_link_options(${name} PRIVATE --coverage)
        endif()
        add_test(NAME ${name} COMMAND ${name})
    endfunction()

    # Archivos de pruebas
    add_test_executable(test_pelicula test/test_pelicula.cpp)
    add_test_executable(test_serie test/test_serie.cpp)
    add_test_executable(test_episodio test/test_episodio.cpp)
    add_test_executable(test_video test/test_video.cpp)
    add_test_executable(test_main test/test_main.cpp)
    # Generar reportes de cobertura
    if (ENABLE_COVERAGE)
        find_program(LCOV lcov)
        if (LCOV)
            add_custom_target(coverage
                    COMMAND lcov --capture --directory . --output-file build/coverage.info
                    COMMAND genhtml build/coverage.info --output-directory build/coverage_html
                    COMMENT "Generating code coverage report"
                    VERBATIM
            )
        else()
            message(WARNING "LCOV not found, coverage reporting will not be available")
        endif()
    endif()
endif()
