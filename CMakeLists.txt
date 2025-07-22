cmake_minimum_required(VERSION 3.27)
project(CMakeSFMLProject LANGUAGES CXX)

# Ustawienie katalogu dla plików wykonywalnych
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Określenie wersji builda (Debug domyślnie)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 🟢 Ustawienie ścieżek do SFML (zmień na swoją lokalizację SFML)

set(SFML_ROOT "/opt/sfml-3")
set(CMAKE_PREFIX_PATH "/opt/sfml-3")
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIBRARY_DIR "${SFML_ROOT}/lib")

add_compile_definitions(IMGUI)
add_compile_definitions(DEBUG)

include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})

include_directories(${CMAKE_SOURCE_DIR}/lib/imgui)
include_directories(${CMAKE_SOURCE_DIR}/lib/imgui/backends)
include_directories(${CMAKE_SOURCE_DIR}/src/utils)
include_directories(${CMAKE_SOURCE_DIR}/src/game/interfaces)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/game/gameObjects)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/game/gameObjects/obj)

find_package(OpenGL REQUIRED)

set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/lib/imgui")
add_library(imgui
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui-SFML.cpp  # albo sfml, glfw, itd.
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
        src/utils/base.hpp
)

target_include_directories(imgui PUBLIC ${IMGUI_DIR} ${IMGUI_DIR}/backends)


find_package(SFML 3.0.0 COMPONENTS System Window Graphics Audio Network REQUIRED)


set(SFML_LIBS SFML::Graphics SFML::Window SFML::System SFML::Audio SFML::Network)


set(RESOURCES_DIR "${CMAKE_SOURCE_DIR}/resources")

file(COPY "${RESOURCES_DIR}" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# Tworzenie pliku wykonywalnego
add_executable(main 
    src/main.cpp 
    src/program.cpp
        src/game/gameObjects/towers/tower.cpp
        src/game/gameObjects/turrets/turret.cpp
        src/game/gameObjects/turrets/turret.hpp
        src/game/map.cpp
        src/game/map.hpp
        src/game/interfaces/towerFactoryInterface.hpp
        src/game/gameObjects/factories/singleCannonFactory.hpp
        src/utils/assetloader.hpp
        src/game/gameObjects/managers/towermanager.cpp
        src/game/gameObjects/managers/towermanager.hpp
        src/utils/pressed.hpp
        src/game/buildingui.cpp
        src/game/buildingui.hpp
        src/game/gameObjects/managers/towermanagerproxy.cpp
        src/game/gameObjects/managers/towermanagerproxy.hpp
        src/screens/states/screenstate.hpp
        src/screens/states/mainmenuscreen.cpp
        src/screens/states/mainmenuscreen.hpp
        src/screens/states/gamescreen.cpp
        src/screens/states/gamescreen.hpp
        src/screens/screenstatemachine.cpp
        src/screens/screenstatemachine.hpp
        src/buttons/button.hpp
        src/buttons/textbutton.cpp
        src/buttons/textbutton.hpp
        src/screens/screenstatemachineinterface.hpp
        src/screens/states/mapselectionscreen.cpp
        src/screens/states/mapselectionscreen.hpp
        src/buttons/mapbutton.cpp
        src/buttons/mapbutton.hpp
        src/game/buildingui/towerlist.cpp
        src/game/buildingui/towerlist.hpp
        src/game/buildingui/product.cpp
        src/game/buildingui/product.hpp
        src/buttons/playbutton.cpp
        src/buttons/playbutton.hpp
        src/game/gameObjects/managers/enemymanager.cpp
        src/game/gameObjects/managers/enemymanager.hpp
        src/game/gameObjects/enemies/enemy.cpp
        src/game/gameObjects/enemies/enemy.hpp
        src/game/interfaces/enemyfactoryinterface.hpp
        src/game/gameObjects/healthbar.cpp
        src/game/gameObjects/managers/wavemanager.cpp
        src/game/gameObjects/enemies/basicSoldier.cpp
        src/game/gameObjects/bullets/bullet.cpp
        src/game/gameObjects/bullets/basicBullet.cpp
        src/game/gameObjects/bullets/rocket.cpp
        src/game/gameObjects/enemies/eliteSoldier.cpp
        src/game/gameObjects/enemies/mechaSoldier.cpp
        src/game/gameObjects/enemies/superSoldier.cpp
        src/game/gameObjects/turrets/singleCannon.cpp
        src/game/gameObjects/turrets/doubleCannon.cpp
        src/game/gameObjects/turrets/machineGun.cpp
        src/game/gameObjects/turrets/rocketLauncher.cpp
)

if(NOT MSVC)
	target_compile_options(main PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(main PRIVATE -Wno-unused-parameter)
endif()

# Ustawienie wersji standardu C++
target_compile_features(main PRIVATE cxx_std_20)

# kolorki w terminalu
add_compile_options(-fdiagnostics-color=always)

# Linkowanie SFML
target_link_libraries(main PRIVATE ${SFML_LIBS} imgui OpenGL::GL)
