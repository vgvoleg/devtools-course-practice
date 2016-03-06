set(target ${APPLICATION})

file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs})
target_link_libraries(${target} ${LIBRARY})
if (UNIX)
  target_link_libraries(${target} ${CMAKE_THREAD_LIBS_INIT})
endif (UNIX)
