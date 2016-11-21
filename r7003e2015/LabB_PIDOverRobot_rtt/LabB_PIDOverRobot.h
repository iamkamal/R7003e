/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_PIDOverRobot.h
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

#ifndef RTW_HEADER_LabB_PIDOverRobot_h_
#define RTW_HEADER_LabB_PIDOverRobot_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef LabB_PIDOverRobot_COMMON_INCLUDES_
# define LabB_PIDOverRobot_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_serialwrite_lct.h"
#include "arduino_digitaloutput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* LabB_PIDOverRobot_COMMON_INCLUDES_ */

#include "LabB_PIDOverRobot_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T FilterCoefficient;            /* '<S4>/Filter Coefficient' */
  real_T SumI1;                        /* '<S4>/SumI1' */
  real_T converttoradianssec;          /* '<S2>/convert to radians//sec' */
  int16_T Encoder_o1;                  /* '<S3>/Encoder ' */
  int16_T Encoder_o2;                  /* '<S3>/Encoder ' */
  int16_T GyroandAccelerometer_o1;     /* '<S3>/Gyro and Accelerometer' */
  int16_T GyroandAccelerometer_o2;     /* '<S3>/Gyro and Accelerometer' */
  int16_T GyroandAccelerometer_o3;     /* '<S3>/Gyro and Accelerometer' */
} BlockIO_LabB_PIDOverRobot;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegratorconvertfr;/* '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  real_T Integrator_DSTATE;            /* '<S4>/Integrator' */
  real_T Filter_DSTATE;                /* '<S4>/Filter' */
  real_T Encoder_DSTATE;               /* '<S3>/Encoder ' */
  real_T GyroandAccelerometer_DSTATE;  /* '<S3>/Gyro and Accelerometer' */
} D_Work_LabB_PIDOverRobot;

/* Parameters (auto storage) */
struct Parameters_LabB_PIDOverRobot_ {
  real_T fGyroBias;                    /* Variable: fGyroBias
                                        * Referenced by: '<S2>/gyro bias'
                                        */
  real_T fGyroConversionFactor;        /* Variable: fGyroConversionFactor
                                        * Referenced by: '<S2>/convert to radians//sec'
                                        */
  real_T fWheelRadius;                 /* Variable: fWheelRadius
                                        * Referenced by: '<S2>/convert to meters'
                                        */
  real_T iNumberOfEncoderSteps;        /* Variable: iNumberOfEncoderSteps
                                        * Referenced by: '<S2>/convert to  radians'
                                        */
  real_T kD;                           /* Variable: kD
                                        * Referenced by: '<S4>/Derivative Gain'
                                        */
  real_T kI;                           /* Variable: kI
                                        * Referenced by: '<S4>/Integral Gain'
                                        */
  real_T kP;                           /* Variable: kP
                                        * Referenced by: '<S4>/Proportional Gain'
                                        */
  real_T PIDController_Kb;             /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S4>/Kb'
                                        */
  real_T PIDController_LowerSaturationLi;/* Mask Parameter: PIDController_LowerSaturationLi
                                          * Referenced by: '<S4>/Saturate'
                                          */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S4>/Filter Coefficient'
                                        */
  real_T PIDController_UpperSaturationLi;/* Mask Parameter: PIDController_UpperSaturationLi
                                          * Referenced by: '<S4>/Saturate'
                                          */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S21>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S22>/PWM'
                                        */
  uint32_T SerialTransmit_portNumber;  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S5>/Serial Transmit'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S20>/Constant2'
                                        */
  real_T DiscreteTimeIntegratorconvertfr;/* Computed Parameter: DiscreteTimeIntegratorconvertfr
                                          * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                          */
  real_T DiscreteTimeIntegratorconvert_e;/* Expression: 0
                                          * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
                                          */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S4>/Filter'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S4>/Filter'
                                        */
  real_T conversiontodutycycleconverttoi;/* Expression: -255/6
                                          * Referenced by: '<S20>/conversion to duty cycle (convert to int)'
                                          */
  real_T Constant3_Value;              /* Expression: 10
                                        * Referenced by: '<S20>/Constant3'
                                        */
  real_T Saturation0to255_UpperSat;    /* Expression: 255
                                        * Referenced by: '<S20>/Saturation 0 to 255'
                                        */
  real_T Saturation0to255_LowerSat;    /* Expression: 0
                                        * Referenced by: '<S20>/Saturation 0 to 255'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255
                                        * Referenced by: '<S20>/Gain1'
                                        */
  int16_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S20>/Switch'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S5>/Constant'
                                        */
  uint8_T Encoder_P1[2];               /* Expression: uint8([0 1])
                                        * Referenced by: '<S3>/Encoder '
                                        */
  uint8_T Encoder_P2[2];               /* Expression: uint8([18 62])
                                        * Referenced by: '<S3>/Encoder '
                                        */
  uint8_T Encoder_P3[2];               /* Expression: uint8([19 15])
                                        * Referenced by: '<S3>/Encoder '
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_LabB_PIDOverRobot {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_LabB_PIDOverRobot LabB_PIDOverRobot_P;

/* Block signals (auto storage) */
extern BlockIO_LabB_PIDOverRobot LabB_PIDOverRobot_B;

/* Block states (auto storage) */
extern D_Work_LabB_PIDOverRobot LabB_PIDOverRobot_DWork;

/* Model entry point functions */
extern void LabB_PIDOverRobot_initialize(void);
extern void LabB_PIDOverRobot_output(void);
extern void LabB_PIDOverRobot_update(void);
extern void LabB_PIDOverRobot_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LabB_PIDOverRobot *const LabB_PIDOverRobot_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LabB_PIDOverRobot'
 * '<S1>'   : 'LabB_PIDOverRobot/controller'
 * '<S2>'   : 'LabB_PIDOverRobot/measurement filter'
 * '<S3>'   : 'LabB_PIDOverRobot/plant'
 * '<S4>'   : 'LabB_PIDOverRobot/controller/PID Controller'
 * '<S5>'   : 'LabB_PIDOverRobot/controller/send through the serial port'
 * '<S6>'   : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits'
 * '<S7>'   : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits1'
 * '<S8>'   : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits10'
 * '<S9>'   : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits11'
 * '<S10>'  : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits12'
 * '<S11>'  : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits13'
 * '<S12>'  : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits2'
 * '<S13>'  : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits3'
 * '<S14>'  : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits4'
 * '<S15>'  : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits5'
 * '<S16>'  : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits6'
 * '<S17>'  : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits7'
 * '<S18>'  : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits8'
 * '<S19>'  : 'LabB_PIDOverRobot/controller/send through the serial port/Extract Bits9'
 * '<S20>'  : 'LabB_PIDOverRobot/plant/Volts to the motor'
 * '<S21>'  : 'LabB_PIDOverRobot/plant/Volts to the motor/Digital Output1'
 * '<S22>'  : 'LabB_PIDOverRobot/plant/Volts to the motor/PWM'
 */
#endif                                 /* RTW_HEADER_LabB_PIDOverRobot_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
