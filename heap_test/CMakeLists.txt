file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${heap_main} ${srcs} ${hdrs}) 
target_link_libraries(${heap_main} ${heap_lib} ${link_lib})


