set(project_NAME fix-validator)

add_executable(${project_NAME}
  main.cpp
  ${applink_SOURCE}
)

target_link_libraries(fix-validator
  quickfix
)
