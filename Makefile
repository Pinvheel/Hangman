all:
	g++ main.cpp gallow.cpp -o main
lint:
	cpplint *.cpp *.hpp