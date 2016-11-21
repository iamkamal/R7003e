/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_TuneTheGyro.h
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

#ifndef RTW_HEADER_LabB_TuneTheGyro_h_
#define RTW_HEADER_LabB_TuneTheGyro_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef LabB_TuneTheGyro_COMMON_INCLUDES_
# define LabB_TuneTheGyro_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* LabB_TuneTheGyro_COMMON_INCLUDES_ */

#include "LabB_TuneTheGyro_types.h"

/* Shared type includes */
#include "multiword_types.h"

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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T DataTypeConversion1;          /* '<Root>/Data Type  Conversion1' */
  real_T computeamovingaverageofthegyro;/* '<S2>/compute a moving average of the gyro' */
  int16_T GyroandAccelerometer_o1;     /* '<Root>/Gyro and Accelerometer' */
  int16_T GyroandAccelerometer_o2;     /* '<Root>/Gyro and Accelerometer' */
  int16_T GyroandAccelerometer_o3;     /* '<Root>/Gyro and Accelerometer' */
  boolean_T Compare;                   /* '<S1>/Compare' */
  boolean_T LogicalOperator;           /* '<Root>/Logical Operator' */
} BlockIO_LabB_TuneTheGyro;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T GyroandAccelerometer_DSTATE;  /* '<Root>/Gyro and Accelerometer' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S3>/Scope' */

  int8_T gyrocalibrationprocedure_Subsys;/* '<Root>/gyro calibration procedure' */
  int8_T measurementfilter_SubsysRanBC;/* '<Root>/measurement filter' */
} D_Work_LabB_TuneTheGyro;

/* Parameters (auto storage) */
struct Parameters_LabB_TuneTheGyro_ {
  real_T calibratethegyrobeforeXsecondss;/* Mask Parameter: calibratethegyrobeforeXsecondss
                                          * Referenced by: '<S1>/Constant'
                                          */
  real_T computeamovingaverageofthegyro_;/* Expression: 0
                                          * Referenced by: '<S2>/compute a moving average of the gyro'
                                          */
  real_T computeamovingaverageofthegyr_m;/* Expression: ones(1,1)/1
                                          * Referenced by: '<S2>/compute a moving average of the gyro'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_LabB_TuneTheGyro {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_LabB_TuneTheGyro LabB_TuneTheGyro_P;

/* Block signals (auto storage) */
extern BlockIO_LabB_TuneTheGyro LabB_TuneTheGyro_B;

/* Block states (auto storage) */
extern D_Work_LabB_TuneTheGyro LabB_TuneTheGyro_DWork;

/* Model entry point functions */
extern void LabB_TuneTheGyro_initialize(void);
extern void LabB_TuneTheGyro_output(void);
extern void LabB_TuneTheGyro_update(void);
extern void LabB_TuneTheGyro_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LabB_TuneTheGyro *const LabB_TuneTheGyro_M;

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
 * '<Root>' : 'LabB_TuneTheGyro'
 * '<S1>'   : 'LabB_TuneTheGyro/calibrate the gyro before X seconds, start controlling after X seconds'
 * '<S2>'   : 'LabB_TuneTheGyro/gyro calibration procedure'
 * '<S3>'   : 'LabB_TuneTheGyro/measurement filter'
 */
#endif                                 /* RTW_HEADER_LabB_TuneTheGyro_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
