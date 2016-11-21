/*
 * LabB_TuneTheGyro_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LabB_TuneTheGyro".
 *
 * Model version              : 1.565
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Dec 14 14:46:26 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&LabB_TuneTheGyro_B.DataTypeConversion1), 0, 0, 2 },

  { (char_T *)(&LabB_TuneTheGyro_B.GyroandAccelerometer_o1), 4, 0, 3 },

  { (char_T *)(&LabB_TuneTheGyro_B.Compare), 8, 0, 2 }
  ,

  { (char_T *)(&LabB_TuneTheGyro_DWork.GyroandAccelerometer_DSTATE), 0, 0, 1 },

  { (char_T *)(&LabB_TuneTheGyro_DWork.Scope_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&LabB_TuneTheGyro_DWork.gyrocalibrationprocedure_Subsys), 2, 0, 2
  }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&LabB_TuneTheGyro_P.calibratethegyrobeforeXsecondss), 0, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] LabB_TuneTheGyro_dt.h */
