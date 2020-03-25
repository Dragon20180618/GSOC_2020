main.exe : main.cpp
	g++ -o main.exe main.cpp
clean : 
	remove main.exe