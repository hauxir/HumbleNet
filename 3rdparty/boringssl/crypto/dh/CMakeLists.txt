include_directories(../../include)

add_library(
  dh

  OBJECT

  dh.c
  params.c
  check.c
  dh_asn1.c
)

if(BUILD_TESTS)
add_executable(
  dh_test

  dh_test.cc

  $<TARGET_OBJECTS:test_support>
)

target_link_libraries(dh_test crypto)
add_dependencies(all_tests dh_test)
endif()