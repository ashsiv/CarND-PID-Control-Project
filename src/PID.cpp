#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp=Kp_;
  Ki=Ki_;
  Kd=Kd_;
  p_error=0.0;
  i_error=0.0;
  d_error=0.0;
  diff_cte =0.0;
  int_cte =0.0;
  prev_cte =0.0;
  
  
}

void PID::UpdateError(double cte,int reset_flag) {
  /**
   * TODO: Update PID errors based on cte.
   */
  if(reset_flag==1)
  {
    int_cte=0.0;
  }
  diff_cte = cte - prev_cte;
  int_cte += cte;
  prev_cte = cte;
  p_error = -Kp*cte;
  i_error = -Ki*int_cte;
  d_error = -Kd*diff_cte;
  

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double t_error=0.0;
  t_error = p_error + i_error + d_error;
  return t_error;  // TODO: Add your total error calc here!
}