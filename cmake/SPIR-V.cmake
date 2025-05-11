find_program(GLSLANGVALIDATOR_CMD glslangValidator)
if(NOT GLSLANGVALIDATOR_CMD)
	message(FATAL_ERROR "Cannot find glslangValidator!")
endif()


function(spirv_shaders ret)
	set(options)
	set(oneValueArgs SPIRV_VERSION)
	set(multiValueArgs SOURCES)
	cmake_parse_arguments(_spirv_shaders "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	if(NOT _spirv_shaders_SPIRV_VERSION)
		set(_spirv_shaders_SPIRV_VERSION 1.0)
	endif()

	foreach(shader ${_spirv_shaders_SOURCES})
		string(MAKE_C_IDENTIFIER ${shader} IDENTIFIER)
		set(HEADER "${shader}.spv")
		set(COMMAND_STR "${GLSLANGVALIDATOR_CMD} -V --target-env spirv${_spirv_shaders_SPIRV_VERSION} ${shader} -o ${HEADER}")
		set(COMMAND ${GLSLANGVALIDATOR_CMD} -V --target-env spirv${_spirv_shaders_SPIRV_VERSION} ${shader} -o ${HEADER})
		message("glslangValidator command: ${COMMAND_STR}")
		add_custom_command(
			OUTPUT ${HEADER} 
			COMMAND ${COMMAND}
			DEPENDS ${shader}
		)
		list(APPEND HEADERS ${HEADER})
	endforeach()
	set(${ret} "${HEADERS}" PARENT_SCOPE)
endfunction()