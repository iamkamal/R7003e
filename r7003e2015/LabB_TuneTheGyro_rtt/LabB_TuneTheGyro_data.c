/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_TuneTheGyro_data.c
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

#include "LabB_TuneTheGyro.h"
#include "LabB_TuneTheGyro_private.h"

/* Block parameters (auto storage) */
Parameters_LabB_TuneTheGyro LabB_TuneTheGyro_P = {
  3.0,                                 /* Mask Parameter: calibratethegyrobeforeXsecondss
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/compute a moving average of the gyro'
                                        */
  1.0                                  /* Expression: ones(1,1)/1
                                        * Referenced by: '<S2>/compute a moving average of the gyro'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
