CC = g++
std = -std=c++11
opencv = `pkg-config --cflags --libs opencv`

vid_con:video_contour.cpp
	$(CC) $(std) -o vid_con video_contour.cpp $(opencv)
