cmake_minimum_required(VERSION 3.10)
project(rogue-sfml)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configuração de diretórios
set(SOURCE_DIR src)
set(BIN_DIR bin)

# Definição dos arquivos fonte
set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/Jogo.cpp
    ${SOURCE_DIR}/Jogador.cpp
    ${SOURCE_DIR}/Inimigo.cpp
    ${SOURCE_DIR}/Projetil.cpp
    ${SOURCE_DIR}/Mundo.cpp
)

# Definição do executável
add_executable(${PROJECT_NAME} ${SOURCES})

# Configuração do SFML... caso for usar outra versão mude o número de 2 para 3 ou 1. E também tome cuidado com a localização do arquivo no Windows.
if (WIN32)
    set(SFML_DIR "C:/SFML") # Modifique para onde instalou a SFML no Windows
    find_package(SFML 2 COMPONENTS graphics window system REQUIRED)
elseif (UNIX)
    find_package(SFML 2 COMPONENTS graphics window system REQUIRED)
endif()

# Vinculação com SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

# Definir saída para o diretório bin
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BIN_DIR})

# Copiar a pasta assets para o diretório bin
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/bin)