# PID Controller - Car Manuever
In this project a PID controller has been implemented in C++ to control the position of the car with the respect to the center of the lane. Speed and Cross-track error are available for the PID.

![PID Car Manuever Implementation](https://github.com/ashsiv/PID-Controller---Car-Manuever/blob/master/images/Cover%20Image.JPG)
---
## Implementation
The key algorithm is implemented in 'PID.cpp' (Under UpdateError and TotalError functions). The P,I,D parameters are defined in Main.cpp

```
PID.cpp
==========
void PID::UpdateError(double cte,int reset_flag) {
...
}

double PID::TotalError() {
...
}

Main.cpp
========
double set_speed =100.0;
double kp   = 0.1;
double ki   = 0.0001;
double kd   = 2.0;
```
---
## Discussion

Tuning: All the parameters have been tuned manually. 

* First the 'P' value (Proportional gain) is set to a constant. 'I' and 'D' values set to zero.
* Next for the given 'P' value, 'D' value or differential gain is carefully set until the vehicle avoids oscillations / overshooting the setpoint (lane center or set speed)
* Finally 'I' component (or Integrat gain) value is set to allow vehicle to correct / fine tune minor lane center error over time.

Effect of P, I and D components of PID algorithm

* Having a high 'P' value  leads to a oscillations - thereby taking a lot time for the car to settle from a disturbance (turn) -eventually crash!
* A good 'D' value for the above set 'P' value not only allows the car to correct for an error quickly but also avoids overshooting the setpoint (lane center or set speed)
* 'I' component played an important role in correcting for minor offset error in lane center position over center (lane center self correction will be evident when the car is moving in a straight track).

---
---
## Results
Using the PID controller, car can safely manuever around the track at upto 50mph! Further higher speeds are possible with additional parameter tuning or twiddle factor implementation.

* [25-30 mph](https://youtu.be/hAdpto5F2Kw)
* [50 mph](https://youtu.be/x2NVFSPnP-M)
---
## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
---  
## Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 




