cmake_minimum_required(VERSION 3.20)

project(back)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    asio
    GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
    GIT_TAG asio-1-36-0
)

FetchContent_MakeAvailable(asio)

set(ASIO_INCLUDE_DIR
    ${asio_SOURCE_DIR}/asio/include
)

FetchContent_Declare(
    Crow
    GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
    GIT_TAG v1.3.1
)

FetchContent_MakeAvailable(Crow)

add_library(core
    src/User.cpp
    src/UserService.cpp
    src/InMemoryUserRepository.cpp
)

target_include_directories(core PUBLIC
    include
)

add_executable(back
    src/main.cpp
)

target_link_libraries(back PRIVATE
    core
    Crow::Crow
)


add_executable(tests
    src/tests.cpp
    src/TestUtils.cpp
)

target_link_libraries(tests PRIVATE
    core
)