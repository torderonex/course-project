cmake_minimum_required(VERSION 3.0.0)
project(websrv VERSION 0.1.0)


find_package(Crow CONFIG REQUIRED)

add_executable(
    app
    main.cpp
)

target_link_libraries(app PRIVATE Crow::Crow)

