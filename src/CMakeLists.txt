set(project_NAME fix-validator)

add_executable(${project_NAME}
  main.cpp
)

target_link_libraries(${project_NAME}
  quickfix
)

install(
  TARGETS ${project_NAME}
  DESTINATION bin
)
