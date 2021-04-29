#include "PID.h"

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(//double Kp_, double Ki_, double Kd_,
              vector<double> p, vector<double> dp, double tol_, double period_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */

  Kp = p[0];
  Ki = p[1];
  Kd = p[2];
  
  p_error = i_error = d_error = prev_cte = 0.0;
  
  tol = tol_;
  period = period_;
  total_err = 0.0;
  best_err = 0.0;
  is_initialized = false;
  
  n_iter = 0;
  t_iter = 0;
  index = 0;
  index_pos = true;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;
  i_error += cte;
  d_error = cte - prev_cte;
  prev_cte = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double steer = -Kp*p_error - Ki*i_error - Kd*d_error;
  return steer;
}

void PID::Twiddle(double steer_value, double cte) {
  
  vector<double> p = {Kp, Ki, Kd};
  vector<double> dp = {Kp*0.1, Ki*0.1, Kd*0.1};
  double sum_dp = dp[0] + dp[1] + dp[2];
  
  t_iter += 1;
  
  if (n_iter < period) 
  {
    total_err += cte*cte;
    n_iter += 1;
  } 
  else if (sum_dp > tol) 
  {
    if (!is_initialized) {
      best_err = total_err / period;
      is_initialized = true;
    } 
    else 
    {
      if (steer_value < best_err) 
      {
        best_err = steer_value;
        dp[index] *= 1.1;
        index = (index + 1)%3;
        index_pos = true;
      } 
      else 
      {
        if (index_pos == true) 
        {
          p[index] -= 2*dp[index];
          index_pos = false;
        } 
        else 
        {
          p[index] += dp[index];
          dp[index] *= 0.9;
          index = (index+1)%3;
          index_pos = true;
        }
      }
    }
    n_iter = 0;
  }  
  
  Kp = p[0];
  Ki = p[1];
  Kd = p[2];
}