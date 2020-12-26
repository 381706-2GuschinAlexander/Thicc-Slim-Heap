file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${link_lib} STATIC ${srcs} ${hdrs}) 