all:
	g++ -std=c++17 main.cc matrix.cc
	./a.out
leaks:
	leaks -atExit -- ./a.out
