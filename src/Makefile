all:
	g++ -fno-elide-constructors -std=c++17 main.cc matrix.cc
	./a.out
leaks:
	leaks -atExit -- ./a.out
