cmake_minimum_required(VERSION 3.10)
project(Ecommerce)

# Définit le standard C++
set(CMAKE_CXX_STANDARD 17)

# Ajoute les dossiers d'inclusion pour les headers
include_directories(${PROJECT_SOURCE_DIR}/include/Abstraction)
include_directories(${PROJECT_SOURCE_DIR}/include/Controller)
include_directories(${PROJECT_SOURCE_DIR}/include/Db)
include_directories(${PROJECT_SOURCE_DIR}/include/Model)
include_directories(${PROJECT_SOURCE_DIR}/include/Presenter)
include_directories(${PROJECT_SOURCE_DIR}/include/Exception)
include_directories(${PROJECT_SOURCE_DIR}/include/Message)
include_directories(${PROJECT_SOURCE_DIR}/include/Interface)

# Ajoute les dossiers où trouver les fichiers source
file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Abstraction/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Controller/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Db/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Model/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Presenter/*.cpp
)

# Crée l'exécutable à partir des fichiers sources
add_executable(E_commerce ${SOURCES})

# Si tu utilises Crow, assure-toi qu'il est trouvé
include_directories(/usr/local/include)

# Lier les librairies nécessaires, comme pthread pour Crow
target_link_libraries(E_commerce pthread)
