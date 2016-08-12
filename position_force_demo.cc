#include <iostream>
#include <memory>
#include <unistd.h>

#include "position_force_control.h"
#include "wsg.h"


using namespace schunk_driver;

int main(int argc, char** argv) {
  schunk_driver::PositionForceControl pf_control(
      std::unique_ptr<Wsg>(new Wsg()));
  pf_control.DoCalibrationSteps();
  while(true) {
    std::cout << "Grapsing force " << pf_control.force() << " Newtons; "
              << "Width " << pf_control.position_mm() << "mm" << std::endl;
    pf_control.Task();
    usleep(1000);
  }

  return 0;
}
