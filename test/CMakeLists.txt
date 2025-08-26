# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(executableTests LANGUAGES CXX)

# ---- Fetch Google Test ----

include(FetchContent)

# Fix uninitialized variables for MSVC/Windows
if(MSVC)
    if(NOT DEFINED cxx_strict_flags)
        set(cxx_strict_flags "")
    endif()
    if(NOT DEFINED CMAKE_THREAD_LIBS_INIT)
        set(CMAKE_THREAD_LIBS_INIT "")
    endif()
endif()

find_package(Threads REQUIRED)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(gtest_build_tests OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
set(_gtest_like_targets gtest gtest_main gmock gmock_main)

foreach(_t IN ITEMS ${_gtest_like_targets})
  if(TARGET ${_t})
    if(MSVC)
      target_compile_options(${_t} PRIVATE /WX- /wd4365 /wd4389 /wd5045)
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
     target_compile_options(${_t} PRIVATE
        -Wno-error
        -Wno-sign-conversion
        -Wno-conversion
        -Wno-sign-compare
      )
    endif()
  endif()
endforeach()
# ---- Tests ----

add_executable(vec2_test source/vec2_test.cpp)
target_link_libraries(vec2_test PRIVATE ComputerGraphics gtest_main)
target_compile_features(vec2_test PRIVATE cxx_std_20)

add_test(NAME vec2_test COMMAND vec2_test)

add_executable(vec3_test source/vec3_test.cpp)
target_link_libraries(vec3_test PRIVATE ComputerGraphics gtest_main)
target_compile_features(vec3_test PRIVATE cxx_std_20)

add_test(NAME vec3_test COMMAND vec3_test)

add_executable(mat4_test source/mat4_test.cpp)
target_link_libraries(mat4_test PRIVATE ComputerGraphics gtest_main)
target_compile_features(mat4_test PRIVATE cxx_std_20)

add_test(NAME mat4_test COMMAND mat4_test)

# ---- End-of-file commands ----

add_folders(Test)