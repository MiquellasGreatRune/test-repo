all:	Main_Menu.hpp Main_Menu.cpp main.cpp Scoreboard.cpp Scoreboard.hpp Game.cpp Game.hpp Tetramino.cpp Tetramino.hpp Cube.cpp Cube.hpp
	g++ -I/mingw64/include/ncurses -o HelloWorld Tetramino.cpp Tetramino.hpp Cube.cpp Cube.hpp Game.cpp Game.hpp Main_Menu.hpp Main_Menu.cpp main.cpp Scoreboard.cpp Scoreboard.hpp -lncurses -L/mingw64/bin -static
clean:
	$(RM) HelloWorld

