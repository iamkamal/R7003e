/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_CheckCommunications.h
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

#ifndef RTW_HEADER_LabB_CheckCommunications_h_
#define RTW_HEADER_LabB_CheckCommunications_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef LabB_CheckCommunications_COMMON_INCLUDES_
# define LabB_CheckCommunications_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_digitaloutput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* LabB_CheckCommunications_COMMON_INCLUDES_ */

#include "LabB_CheckCommunications_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Gain;                         /* '<S2>/Gain' */
  real_T Gain_j;                       /* '<S3>/Gain' */
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T Sum2;                         /* '<S1>/Sum2' */
  int16_T HMC5883LMPU6050DriverSFunction_;/* '<S1>/HMC5883L & MPU6050  Driver SFunction' */
  int16_T HMC5883LMPU6050DriverSFunctio_e;/* '<S1>/HMC5883L & MPU6050  Driver SFunction' */
  int16_T HMC5883LMPU6050DriverSFunctio_i;/* '<S1>/HMC5883L & MPU6050  Driver SFunction' */
  int16_T HMC5883LMPU6050DriverSFunctio_p;/* '<S1>/HMC5883L & MPU6050  Driver SFunction' */
  int16_T HMC5883LMPU6050DriverSFuncti_pc;/* '<S1>/HMC5883L & MPU6050  Driver SFunction' */
  int16_T HMC5883LMPU6050DriverSFunctio_j;/* '<S1>/HMC5883L & MPU6050  Driver SFunction' */
  int16_T HMC5883LMPU6050DriverSFunctio_c;/* '<S1>/HMC5883L & MPU6050  Driver SFunction' */
  int16_T HMC5883LMPU6050DriverSFuncti_im;/* '<S1>/HMC5883L & MPU6050  Driver SFunction' */
  int16_T HMC5883LMPU6050DriverSFunctio_g;/* '<S1>/HMC5883L & MPU6050  Driver SFunction' */
  int16_T DualEncoderReading1819A86215Min;/* '<S1>/Dual Encoder Reading 18:19, A8(62):15  (MinSegShield M2V3.2) ' */
  int16_T DualEncoderReading1819A86215M_f;/* '<S1>/Dual Encoder Reading 18:19, A8(62):15  (MinSegShield M2V3.2) ' */
} BlockIO_LabB_CheckCommunication;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T HMC5883LMPU6050DriverSFunction_;/* '<S1>/HMC5883L & MPU6050  Driver SFunction' */
  real_T DualEncoderReading1819A86215Min;/* '<S1>/Dual Encoder Reading 18:19, A8(62):15  (MinSegShield M2V3.2) ' */
  real_T angularvelocitytoangle_DSTATE;/* '<S1>/angular velocity to angle' */
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  struct {
    void *LoggedData;
  } accelerometer_PWORK;               /* '<Root>/accelerometer' */

  struct {
    void *LoggedData;
  } encoder_PWORK;                     /* '<Root>/encoder' */

  struct {
    void *LoggedData;
  } gyro_PWORK;                        /* '<Root>/gyro' */

  struct {
    void *LoggedData;
  } motor_PWORK;                       /* '<Root>/motor' */

  int32_T systemEnable;                /* '<Root>/Sine Wave' */
} D_Work_LabB_CheckCommunications;

/* Parameters (auto storage) */
struct Parameters_LabB_CheckCommunicat_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S5>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S6>/PWM'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T angleoffset_Value;            /* Expression: pi/2
                                        * Referenced by: '<S1>/angle offset'
                                        */
  real_T rawyaccelerationtog_y_Gain;   /* Expression: 1 / 2048
                                        * Referenced by: '<S1>/raw y acceleration to g_y'
                                        */
  real_T rawzaccelerationtog_z_Gain;   /* Expression: 1 / 2048
                                        * Referenced by: '<S1>/raw z acceleration to g_z'
                                        */
  real_T accelerometeranglebias_Value; /* Expression: 0
                                        * Referenced by: '<S1>/accelerometer angle bias'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T angularvelocitytoangle_gainval;/* Computed Parameter: angularvelocitytoangle_gainval
                                         * Referenced by: '<S1>/angular velocity to angle'
                                         */
  real_T angularvelocitytoangle_IC;    /* Expression: 0
                                        * Referenced by: '<S1>/angular velocity to angle'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180/pi
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T rawxvelocitytodegsec_Gain;    /* Expression: 1 / 131
                                        * Referenced by: '<S1>/raw x velocity to deg. // sec.'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T gyrovelocitybias_Value;       /* Expression: 0
                                        * Referenced by: '<S1>/gyro velocity bias'
                                        */
  real_T conversiontodutycycleconverttoi;/* Expression: 255/5
                                          * Referenced by: '<S1>/conversion to duty cycle (convert to int)'
                                          */
  real_T Constant3_Value;              /* Expression: 10
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Saturation0to255_UpperSat;    /* Expression: 255
                                        * Referenced by: '<S1>/Saturation 0 to 255'
                                        */
  real_T Saturation0to255_LowerSat;    /* Expression: 0
                                        * Referenced by: '<S1>/Saturation 0 to 255'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 255
                                        * Referenced by: '<S1>/Gain1'
                                        */
  int16_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S1>/Switch'
                                        */
  uint8_T DualEncoderReading1819A86215Min[2];/* Expression: uint8([0 1])
                                              * Referenced by: '<S1>/Dual Encoder Reading 18:19, A8(62):15  (MinSegShield M2V3.2) '
                                              */
  uint8_T DualEncoderReading1819A86215M_h[2];/* Expression: uint8([18 62])
                                              * Referenced by: '<S1>/Dual Encoder Reading 18:19, A8(62):15  (MinSegShield M2V3.2) '
                                              */
  uint8_T DualEncoderReading1819A86215M_c[2];/* Expression: uint8([19 15])
                                              * Referenced by: '<S1>/Dual Encoder Reading 18:19, A8(62):15  (MinSegShield M2V3.2) '
                                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_LabB_CheckCommunication {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_LabB_CheckCommunicat LabB_CheckCommunications_P;

/* Block signals (auto storage) */
extern BlockIO_LabB_CheckCommunication LabB_CheckCommunications_B;

/* Block states (auto storage) */
extern D_Work_LabB_CheckCommunications LabB_CheckCommunications_DWork;

/* Model entry point functions */
extern void LabB_CheckCommunications_initialize(void);
extern void LabB_CheckCommunications_output(void);
extern void LabB_CheckCommunications_update(void);
extern void LabB_CheckCommunications_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LabB_CheckCommunicatio *const LabB_CheckCommunications_M;

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
 * '<Root>' : 'LabB_CheckCommunications'
 * '<S1>'   : 'LabB_CheckCommunications/Balancing Robot'
 * '<S2>'   : 'LabB_CheckCommunications/Radians to Degrees'
 * '<S3>'   : 'LabB_CheckCommunications/Radians to Degrees1'
 * '<S4>'   : 'LabB_CheckCommunications/Balancing Robot/Degrees to Radians'
 * '<S5>'   : 'LabB_CheckCommunications/Balancing Robot/Digital Output1'
 * '<S6>'   : 'LabB_CheckCommunications/Balancing Robot/PWM'
 */
#endif                                 /* RTW_HEADER_LabB_CheckCommunications_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
