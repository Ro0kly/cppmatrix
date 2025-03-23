all:
	g++ -fno-elide-constructors -std=c++17 main.cc matrix.cc matrix_private.cc specials.cc operators.cc acc_mut.cc
	./a.out
leaks:
	leaks -atExit -- ./a.out
