CC = g++
std = -std=c++11
opencv = `pkg-config --cflags --libs opencv`

salt_img:salt_pepper.cpp
	$(CC) $(std) -o salt_img salt_pepper.cpp $(opencv)
