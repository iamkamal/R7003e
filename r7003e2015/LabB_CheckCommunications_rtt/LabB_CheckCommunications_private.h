/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_CheckCommunications_private.h
 *
 * Code generated for Simulink model 'LabB_CheckCommunications'.
 *
 * Model version                  : 1.465
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Mon Dec 14 13:41:55 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LabB_CheckCommunications_private_h_
#define RTW_HEADER_LabB_CheckCommunications_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void sf_HMC5883L_MPU6050_Outputs_wrapper(int16_T *x_mag,
  int16_T *y_mag,
  int16_T *z_mag,
  int16_T *x_vel,
  int16_T *y_vel,
  int16_T *z_vel,
  int16_T *x_acc,
  int16_T *y_acc,
  int16_T *z_acc,
  const real_T *xD);
extern void sf_HMC5883L_MPU6050_Update_wrapper(const int16_T *x_mag,
  const int16_T *y_mag,
  const int16_T *z_mag,
  const int16_T *x_vel,
  const int16_T *y_vel,
  const int16_T *z_vel,
  const int16_T *x_acc,
  const int16_T *y_acc,
  const int16_T *z_acc,
  real_T *xD);
extern void sf_QuadEncoder_18_19_15_62_Outputs_wrapper(int16_T *pos1,
  int16_T *pos2 ,
  const real_T *xD,
  const uint8_T *enc, const int_T p_width0,
  const uint8_T *pinA, const int_T p_width1,
  const uint8_T *pinB, const int_T p_width2);
extern void sf_QuadEncoder_18_19_15_62_Update_wrapper(const int16_T *pos1,
  const int16_T *pos2 ,
  real_T *xD,
  const uint8_T *enc, const int_T p_width0,
  const uint8_T *pinA, const int_T p_width1,
  const uint8_T *pinB, const int_T p_width2);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);

#endif                                 /* RTW_HEADER_LabB_CheckCommunications_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
