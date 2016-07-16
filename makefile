CC = g++
std = -std=c++11
opencv = `pkg-config --cflags --libs opencv`

read_vid:read_video.cpp
	$(CC) $(std) -o read_vid read_video.cpp $(opencv)
