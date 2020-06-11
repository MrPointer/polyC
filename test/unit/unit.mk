relative_dir := test/unit
dependencies_dir := test/dependencies

unit_src_dir := ${relative_dir}/src
unit_build_dir := ${build_dir}/test/unit

unit_include_dirs := ${polyc_include_dirs}
unit_include_dirs += ${relative_dir}/include ${dependencies_dir}
unit_include_dirs += /usr/local/include/catch2

CPPFLAGS += $(addprefix -I,${unit_include_dirs})

unit_cxx_sources := $(shell find ${unit_src_dir} -name '*.c??')
${info "Sources: " ${unit_cxx_sources}}
unit_cxx_objects := $(unit_cxx_sources:%.cpp=${build_dir}/%.o)

unit_includes := $(shell find ${unit_include_dirs} -name '.h??')

unit_LDLIBS := $(LDLIBS)
unit_LDLIBS += -lpolyc

unit_LDFLAGS := $(LDFLAGS)
unit_LDFLAGS += -L${build_dir}

unit_target_output_name := polyc_unit
unit_target_output_path := ${unit_build_dir}/${unit_target_output_name}

# Append the current target to the parent variable containing rules for 'all'
targets += polyc_unit_tests

polyc_unit_tests: polyc
polyc_unit_tests: ${unit_cxx_objects}
	$(CXX) $(unit_LDFLAGS) ${unit_cxx_objects} $(LOADLIBES) $(unit_LDLIBS) -o ${unit_target_output_path}

${unit_cxx_objects}: ${build_dir}/%.o: %.cpp ${unit_includes}
	$(dir_guard)
	$(CXX) ${CPPFLAGS} ${CXXFLAGS} -c $< -o $@
