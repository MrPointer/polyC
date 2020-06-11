dir_guard = @mkdir -p $(@D)
targets := polyc

include demo/demo.mk
ifdef UNIT_TEST
	include test/test.mk
endif

.DEFAULT_GOAL := all
.PHONY: all
all: ${targets}

src_dir := src
build_dir := build-make

SOURCES = Interface.c

c_main_sources := $(foreach src,${SOURCES},${src_dir}/${src})
c_main_objs := $(c_main_sources:${src_dir}/%.c=${build_dir}/%.o)

include_dir := ${CURDIR}/include
include_files := $(wilcard ${include_dir}/*.h) $(wilcard ${include_dir}/*.hpp)

CFLAGS += -I${include_dir}

polyc_target_output = libpolyc
polyc_target_suffix = a
polyc_target_output_path = ${build_dir}/${polyc_target_output}.${polyc_target_suffix}

polyc: ${c_main_objs}
	mkdir -p ${build_dir}
	ar rcs ${polyc_target_output_path} $<

${c_main_objs}: ${build_dir}/%.o: ${src_dir}/%.c ${include_files}
	$(dir_guard)
	${CC} ${CFLAGS} -c $< -o $@

.PHONY: clean
clean::
	-rm -rf ${build_dir}
	#-rm ${OBJS} ${polyc_target_output_path}
