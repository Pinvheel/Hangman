all:
	g++ main.cpp -o main
lint:
	cpplint *.cpp *.hpp