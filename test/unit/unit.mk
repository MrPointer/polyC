relative_dir := ${CURDIR}/test/unit

unit_src_dir := ${relative_dir}/src
unit_include_dir := ${relative_dir}/include
unit_build_dir := ${CURDIR}/build-make/test

unit_target_includes += -I${unit_include_dir} -I${relative_dir}/../dependencies -I${CURDIR}/include
CPPFLAGS += ${unit_target_includes}

unit_sources = action/MultiImplementationActionTests.cpp \
	action/SingleImplementationActionTests.cpp \
	composite/MultiImplementationCompositeTests.cpp \
	composite/SingleImplementationCompositeTests.cpp \
	func/MultiImplementationFuncTests.cpp func/SingleImplementationFuncTests.cpp

unit_cxx_main_srcs = $(foreach src,${unit_sources},${unit_src_dir}/${src})
unit_cxx_main_objs = $(unit_cxx_main_srcs:${unit_src_dir}/%.cpp=${unit_build_dir}/%.o)

unit_cxx_alt_srcs = $(wildcard ${relative_dir}/*.c?*)
unit_cxx_alt_objs = $(unit_cxx_alt_srcs:${relative_dir}/%.cpp=${unit_build_dir}/%.o)

unit_include_files := $(wilcard ${unit_include_dir}/*.h) $(wilcard ${unit_include_dir}/*.hpp)

# Append the current target to the parent variable containing rules for 'all'
targets += polyc_unit_tests

polyc_unit_tests: ${unit_cxx_main_objs} ${unit_cxx_alt_objs}
	$(CXX) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) \
	-lpolyc -L/home/timor.g/dev/projects/takpit/polyC/build-make \
	-o ${unit_build_dir}/polyc_unit

${unit_cxx_main_objs}: ${unit_build_dir}/%.o: ${unit_src_dir}/%.cpp ${unit_include_files}
	$(dir_guard)
	$(CXX) ${CPPFLAGS} ${CXXFLAGS} -c $< -o $@

${unit_cxx_alt_objs}: ${unit_build_dir}/%.o: ${relative_dir}/%.cpp
	$(dir_guard)
	$(CXX) ${CPPFLAGS} ${CXXFLAGS} -c $< -o $@

clean::
	-rm ${unit_cxx_main_objs} ${unit_cxx_alt_objs}
