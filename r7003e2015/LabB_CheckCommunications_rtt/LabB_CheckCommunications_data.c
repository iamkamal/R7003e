/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_CheckCommunications_data.c
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

#include "LabB_CheckCommunications.h"
#include "LabB_CheckCommunications_private.h"

/* Block parameters (auto storage) */
Parameters_LabB_CheckCommunicat LabB_CheckCommunications_P = {
  6U,                                  /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S5>/Digital Output'
                                        */
  8U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S6>/PWM'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  1.5707963267948966,                  /* Expression: pi/2
                                        * Referenced by: '<S1>/angle offset'
                                        */
  0.00048828125,                       /* Expression: 1 / 2048
                                        * Referenced by: '<S1>/raw y acceleration to g_y'
                                        */
  0.00048828125,                       /* Expression: 1 / 2048
                                        * Referenced by: '<S1>/raw z acceleration to g_z'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/accelerometer angle bias'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain'
                                        */
  0.01,                                /* Computed Parameter: angularvelocitytoangle_gainval
                                        * Referenced by: '<S1>/angular velocity to angle'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/angular velocity to angle'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S3>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.049979169270678331,                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.99875026039496628,                 /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  -0.049979169270678331,               /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.99875026039496628,                 /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0076335877862595417,               /* Expression: 1 / 131
                                        * Referenced by: '<S1>/raw x velocity to deg. // sec.'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S4>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/gyro velocity bias'
                                        */
  51.0,                                /* Expression: 255/5
                                        * Referenced by: '<S1>/conversion to duty cycle (convert to int)'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S1>/Constant3'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S1>/Saturation 0 to 255'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Saturation 0 to 255'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S1>/Gain1'
                                        */
  0,                                   /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S1>/Switch'
                                        */

  /*  Expression: uint8([0 1])
   * Referenced by: '<S1>/Dual Encoder Reading 18:19, A8(62):15  (MinSegShield M2V3.2) '
   */
  { 0U, 1U },

  /*  Expression: uint8([18 62])
   * Referenced by: '<S1>/Dual Encoder Reading 18:19, A8(62):15  (MinSegShield M2V3.2) '
   */
  { 18U, 62U },

  /*  Expression: uint8([19 15])
   * Referenced by: '<S1>/Dual Encoder Reading 18:19, A8(62):15  (MinSegShield M2V3.2) '
   */
  { 19U, 15U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
