add_executable(test_lfu ./src/test_lfu.cpp)
add_executable(test_perfect ./src/test_perfect.cpp)
add_executable(time_test_perfect ./src/time_test_perfect.cpp)
add_executable(time_test_lfu ./src/time_test_lfu.cpp)


target_include_directories(test_lfu
                           PRIVATE ${INCLUDE_DIR})

target_include_directories(test_perfect
                           PRIVATE ${INCLUDE_DIR})

target_include_directories(time_test_perfect
                           PRIVATE ${INCLUDE_DIR})

target_include_directories(time_test_lfu
                           PRIVATE ${INCLUDE_DIR})


install(TARGETS test_lfu
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT test_lfu)

install(TARGETS test_perfect
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT test_perfect)

install(TARGETS time_test_perfect
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT time_test_perfect)

install(TARGETS time_test_lfu
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT time_test_lfu)