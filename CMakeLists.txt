cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME Race)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("inc/")
include_directories("ext/SFML/include/")	# добавляем директории
link_directories("ext/SFML/lib/")	

add_executable("${PROJECT_NAME}" main.cpp  
						inc/Avto.hpp 
						inc/cars.hpp
						inc/menu.hpp
						inc/game.hpp					
						src/Avto.cpp
						src/cars.cpp
						src/menu.cpp
						src/game.cpp
						Textures/App.rc
)
											
target_link_libraries("${PROJECT_NAME}" sfml-graphics-s-d
						  sfml-window-s-d
						  sfml-system-s-d
						  opengl32
						  freetype
						  winmm
						  gdi32
						  sfml-audio-s-d
						  openal32
						  flac
						  vorbisenc
						  vorbisfile
						  vorbis
						  ogg)
file(COPY "Textures" DESTINATION "/")
file(COPY "fonts" DESTINATION "/")