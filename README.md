# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

I implemented a PID controller in C++ to maneuver the vehicle around the track.

## Tuning

I did the manual tuning for this project.

Proportional (P):
This parameter proportionally controls the error. This makes sense because P has the most obvious effect on turning the car.

Integral (I):
This parameter controls the cumulative error. This makes sense because P has the most obvious effect on turning the car. If there is a bias in the system, the integrator builds and builds up to increase the control signal and reduce the error.

Differentiation (D):
This parameter controls the rate of change of error. It is important to tune. Controls the degree to which the car vibrates. It tends to reduce overshoot by adding damping to the system. It is difficult to get rid of this completely.

# Twiddle implementation
Set the gain to {0.225, 0.0004, 4.0}, and dp multiplies these values by 0.1 to implement a twiddle.
Increase the P gain until the response to the disturbance is steady oscillation.
Increase the D gain until the vibration disappears
I picked one of the middle values and then manually adjusted it later, resulting in a final value of {0.2,0.004,2.0}.

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
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.


