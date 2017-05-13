draw_shape: draw_shape.o draw_shape_main.o
	g++ -std=c++11 -o draw_shape draw_shape_main.o draw_shape.o
draw_shape_main.o: draw_shape.hpp draw_shape_main.cpp
	g++ -c draw_shape_main.cpp
draw_shape.o: draw_shape.hpp draw_shape.cpp
	g++ -c draw_shape.cpp
