add_executable(josephus2 josephus2.c ll/ll.c)
add_subdirectory(ll)
target_include_directories(josephus2 PRIVATE ll)