demo_src_dir = demo
demo_build_dir = ${build_dir}/demo

demo_c_sources = $(shell find ${demo_src_dir} -name '*.c')
demo_c_objects = ${demo_c_sources:%.c=${build_dir}/%.o}

polyc_LDLIBS := $(LDLIBS)
polyc_LDLIBS += -lpolyc

polyc_LDFLAGS := $(LDFLAGS)
polyc_LDFLAGS += -L${build_dir}

polyc_demo_target_output_name = polyc_demo
polyc_demo_target_output_path = ${demo_build_dir}/${polyc_demo_target_output_name}

demo: polyc
demo: ${demo_c_objects}
	mkdir -p ${demo_build_dir}
	$(CC) $(polyc_LDFLAGS) ${demo_c_objects} $(LOADLIBES) $(polyc_LDLIBS) -o ${polyc_demo_target_output_path}

${demo_c_objects}: ${build_dir}/%.o: %.c ${polyc_includes}
	$(dir_guard)
	${CC} ${CFLAGS} -o $@ -c $<
