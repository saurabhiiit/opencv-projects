CC = g++
std = -std=c++11
opencv = `pkg-config --cflags --libs opencv`

vid_syn:video_synopsis.cpp
	$(CC) $(std) -o vid_syn video_synopsis.cpp $(opencv)
