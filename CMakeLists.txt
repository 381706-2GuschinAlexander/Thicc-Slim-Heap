﻿cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME Heap) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(heap_main heap_main)
set(heap_lib heap_lib)
set(link_lib link_lib)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(
 ${CMAKE_CURRENT_SOURCE_DIR}/heap_lib
 ${CMAKE_CURRENT_SOURCE_DIR}/link_lib)

add_subdirectory(heap_main)
add_subdirectory(heap_lib)
add_subdirectory(link_lib)



