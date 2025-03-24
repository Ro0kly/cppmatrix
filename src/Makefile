all: s21_matrix_oop.a
	g++ -fno-elide-constructors -std=c++17 -L. -ls21_matrix_oop main.cc  -lgtest -o program.out
	./program.out
	@make clean
clean:
	@rm *.o *.a *.out
test:
	./program.out
s21_matrix_oop.a:
	g++ -fno-elide-constructors -std=c++17 -c lib/*.cc
	ar rcs libs21_matrix_oop.a *.o
check_style:
	@clang-format -n main.cc
	@clang-format -n lib/*.cc
	@clang-format -n lib/*.h
format:
	@clang-format -i main.cc
	@clang-format -i lib/*.cc
	@clang-format -i lib/*.h
leaks:
	leaks -atExit -- ./program.out
