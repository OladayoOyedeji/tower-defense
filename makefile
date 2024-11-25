m exe:	main.cpp
	g++ *.cpp My_DataStructures/*.cpp Game_Classes/*.cpp src/*.cpp src/*.c `sdl-config --cflags --libs` -lSDL_image -lSDL_mixer -lSDL_ttf -Iincludes -IMy_DataStructures -IGame_Classes

a asan:	main.cpp
	g++ -g -fsanitize=address *.cpp My_DataStructures/*.cpp Game_Classes/*.cpp src/*.cpp src/*.c `sdl-config --cflags --libs` -lSDL_image -lSDL_mixer -lSDL_ttf -Iincludes -IMy_DataStructures -IGame_Classes

run:
	./a.out

r:
	./a.out

g git:
	git add .; git commit -m 'i am awesome'; git push

clean:
	rm a.out

c:
	rm a.out
