dir_guard = @mkdir -p $(@D)

build_dir := build-make

polyc_include_dirs := include
polyc_includes := $(shell find ${polyc_include_dirs} -name '*.h*')

CFLAGS += -I${polyc_include_dirs}

targets := polyc

include demo/demo.mk

ifdef UNIT_TEST
	include test/test.mk
endif

.DEFAULT_GOAL := all
.PHONY: all
all: ${targets}

polyc_src_dirs := src

polyc_sources := $(shell find ${polyc_src_dirs} -name '*.c')
polyc_objects := ${polyc_sources:%.c=${build_dir}/%.o}

polyc_target_output = libpolyc
polyc_target_suffix = a
polyc_target_output_path = ${build_dir}/${polyc_target_output}.${polyc_target_suffix}

polyc: ${polyc_objects}
	mkdir -p ${build_dir}
	ar rcs ${polyc_target_output_path} ${polyc_objects}

${polyc_objects}: ${build_dir}/%.o: %.c ${polyc_includes}
	$(dir_guard)
	${CC} ${CFLAGS} -c $< -o $@

.PHONY: clean
clean:
	${RM} -r ${build_dir}
