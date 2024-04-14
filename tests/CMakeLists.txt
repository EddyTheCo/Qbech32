
foreach(app  tests)
	add_executable(${app} ${app}.cpp)
	target_link_libraries(${app} PRIVATE qbech32)
	add_test(NAME ${app} COMMAND ${app})
endforeach()

