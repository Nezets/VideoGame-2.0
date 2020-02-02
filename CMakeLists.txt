cmake_minimum_required(VERSION 3.15)
project(RougeGame)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/APIs/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

set(CMAKE_CXX_STANDARD 11)

add_executable(RougeGame main.cpp TextureManager.cpp Room.cpp Room.h Door.cpp Door.h DungeonFloor.cpp DungeonFloor.h Bullet.cpp Bullet.h BulletManager.cpp BulletManager.h ProgressBar.cpp ProgressBar.h
        PC.cpp PC.h Character.cpp Character.h Enemy.cpp Enemy.h EnemyList.cpp EnemyList.h SnakeBoss.cpp SnakeBoss.h)
target_link_libraries(RougeGame sfml-graphics sfml-audio)