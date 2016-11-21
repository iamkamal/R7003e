/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_PIDOverRobot_data.c
 *
 * Code generated for Simulink model 'LabB_PIDOverRobot'.
 *
 * Model version                  : 1.554
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Mon Dec 14 14:59:01 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LabB_PIDOverRobot.h"
#include "LabB_PIDOverRobot_private.h"

/* Block parameters (auto storage) */
Parameters_LabB_PIDOverRobot LabB_PIDOverRobot_P = {
  -386.0,                              /* Variable: fGyroBias
                                        * Referenced by: '<S2>/gyro bias'
                                        */
  -0.0076335877862595417,              /* Variable: fGyroConversionFactor
                                        * Referenced by: '<S2>/convert to radians//sec'
                                        */
  0.0216,                              /* Variable: fWheelRadius
                                        * Referenced by: '<S2>/convert to meters'
                                        */
  720.0,                               /* Variable: iNumberOfEncoderSteps
                                        * Referenced by: '<S2>/convert to  radians'
                                        */
  -0.1413,                             /* Variable: kD
                                        * Referenced by: '<S4>/Derivative Gain'
                                        */
  -375.9749,                           /* Variable: kI
                                        * Referenced by: '<S4>/Integral Gain'
                                        */
  -67.2266,                            /* Variable: kP
                                        * Referenced by: '<S4>/Proportional Gain'
                                        */
  1.0,                                 /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S4>/Kb'
                                        */
  -6.0,                                /* Mask Parameter: PIDController_LowerSaturationLi
                                        * Referenced by: '<S4>/Saturate'
                                        */
  100.0,                               /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S4>/Filter Coefficient'
                                        */
  6.0,                                 /* Mask Parameter: PIDController_UpperSaturationLi
                                        * Referenced by: '<S4>/Saturate'
                                        */
  6U,                                  /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S21>/Digital Output'
                                        */
  8U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S22>/PWM'
                                        */
  0U,                                  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S5>/Serial Transmit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S20>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Constant2'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegratorconvertfr
                                        * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                        */
  0.005,                               /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S4>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S4>/Integrator'
                                        */
  0.005,                               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S4>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S4>/Filter'
                                        */
  -42.5,                               /* Expression: -255/6
                                        * Referenced by: '<S20>/conversion to duty cycle (convert to int)'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S20>/Constant3'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S20>/Saturation 0 to 255'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Saturation 0 to 255'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S20>/Gain1'
                                        */
  0,                                   /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S20>/Switch'
                                        */
  1U,                                  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S5>/Constant'
                                        */

  /*  Expression: uint8([0 1])
   * Referenced by: '<S3>/Encoder '
   */
  { 0U, 1U },

  /*  Expression: uint8([18 62])
   * Referenced by: '<S3>/Encoder '
   */
  { 18U, 62U },

  /*  Expression: uint8([19 15])
   * Referenced by: '<S3>/Encoder '
   */
  { 19U, 15U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
