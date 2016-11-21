/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_TuneTheGyro_private.h
 *
 * Code generated for Simulink model 'LabB_TuneTheGyro'.
 *
 * Model version                  : 1.565
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Mon Dec 14 14:46:26 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LabB_TuneTheGyro_private_h_
#define RTW_HEADER_LabB_TuneTheGyro_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern void sf_MPU6050_Driver_GxAyz_Outputs_wrapper(int16_T *x_vel,
  int16_T *y_acc,
  int16_T *z_acc,
  const real_T *xD);
extern void sf_MPU6050_Driver_GxAyz_Update_wrapper(const int16_T *x_vel,
  const int16_T *y_acc,
  const int16_T *z_acc,
  real_T *xD);

#endif                                 /* RTW_HEADER_LabB_TuneTheGyro_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
