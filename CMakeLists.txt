cmake_minimum_required(VERSION 3.10)

project(JogoECS)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.6 REQUIRED graphics window system)

add_executable(JogoECS
    src/coordenador/Mundo.hpp
    src/main.cpp
    src/entidades/Entidade.hpp
    src/componentes/TransformaComponente.hpp
    src/sistemas/MovimentoSistema.hpp
)

target_link_libraries(JogoECS sfml-graphics sfml-window sfml-system)