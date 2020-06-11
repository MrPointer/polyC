demo_src_dir = ${CURDIR}/demo
demo_build_dir = ${CURDIR}/build-make/demo

demo_objs = ${demo_build_dir}/polyc_demo.o

polyc_lib_path = ${demo_build_dir}/..
polyc_lib_include_dir = ${CURDIR}/../include

polyc_demo_target_output_name = polyc_demo
polyc_demo_target_output_path = ${demo_build_dir}/${polyc_demo_target_output_name}

demo: polyc
demo: ${demo_objs}
	$(dir_guard)
	$(CC) $(LDFLAGS) $< $(LOADLIBES) $(LDLIBS) \
	-lpolyc -L${demo_build_dir}/.. \
	-o ${polyc_demo_target_output_path}

${demo_objs}: ${demo_build_dir}/%.o: ${demo_src_dir}/%.c
	$(dir_guard)
	${CC} ${CFLAGS} -o $@ -c $< -I${polyc_lib_include_dir}

clean::
	-rm -rf ${demo_build_dir}
	#-@rm ${demo_objs} ${polyc_demo_target_output_path}
