#ifndef PID_H
#define PID_H
#include <vector>


class PID {
 public: 

  
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(std::vector<double> p, std::vector<double> dp, double tol, double period);
  
  void Twiddle(double steer_value, double cte);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();
  
 private:
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;
  
  double prev_cte;
  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
  /*double dKp;
  double dKi;
  double dKd;*/
  
  // for twiddle
  double tol;
  double total_err;
  double best_err;
  bool is_initialized;
  int n_iter;
  int t_iter;
  double period;
  int index;
  bool index_pos;
};

#endif  // PID_H