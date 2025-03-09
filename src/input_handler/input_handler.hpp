#ifndef __INPUT_HANDLER_HPP__
#define __INPUT_HANDLER_HPP__

#include "../cam/cam.hpp"
#include "../grid/grid.hpp"

class Input_handler {
public:
  void camera_input(Cam &camera, const int limit);
  void grid_input(Grid &g, const Cam &camera);

private:
};

#endif
