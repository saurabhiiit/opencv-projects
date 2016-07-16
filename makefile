CC = g++
std = -std=c++11
opencv = `pkg-config --cflags --libs opencv`

disp_img:display_img.cpp
	$(CC) $(std) -o disp_img display_img.cpp $(opencv)
