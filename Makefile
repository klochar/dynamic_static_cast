exec = exec

$(exec):Animal.o main.o Chat.o
	g++ -std=c++20 -o $(exec) main.o Animal.o Chat.o
	
main.o:main.cpp
	g++ -std=c++20 -c main.cpp

Animal.o:Animal.cpp
	g++ -std=c++20 -c Animal.cpp

Chat.o:Chat.cpp
	g++ -std=c++20 -c $^


clean:
	del -rf *.o exec.exe
	

run: exec 
	./exec.exe

