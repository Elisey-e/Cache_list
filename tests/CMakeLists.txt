add_executable(test_lfu ./src/test_lfu.cpp)
add_executable(test_perfect ./src/test_perfect.cpp)


target_include_directories(test_lfu
                           PRIVATE ${INCLUDE_DIR})

target_include_directories(test_perfect
                           PRIVATE ${INCLUDE_DIR})


install(TARGETS test_lfu
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT test_lfu)

install(TARGETS test_perfect
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT test_perfect)
