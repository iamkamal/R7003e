/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_CheckCommunications.c
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
#include "LabB_CheckCommunications_dt.h"

/* Block signals (auto storage) */
BlockIO_LabB_CheckCommunication LabB_CheckCommunications_B;

/* Block states (auto storage) */
D_Work_LabB_CheckCommunications LabB_CheckCommunications_DWork;

/* Real-time model */
RT_MODEL_LabB_CheckCommunicatio LabB_CheckCommunications_M_;
RT_MODEL_LabB_CheckCommunicatio *const LabB_CheckCommunications_M =
  &LabB_CheckCommunications_M_;
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T u0_0;
  int16_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void LabB_CheckCommunications_output(void)
{
  real_T rtb_Switch;
  int16_T rtb_Abs;
  real_T u0;
  uint8_T rtb_Switch_0;

  /* S-Function (sf_HMC5883L_MPU6050): '<S1>/HMC5883L & MPU6050  Driver SFunction' */
  sf_HMC5883L_MPU6050_Outputs_wrapper
    ( &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunction_,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_e,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_i,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_p,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFuncti_pc,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_j,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_c,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFuncti_im,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_g,
     &LabB_CheckCommunications_DWork.HMC5883LMPU6050DriverSFunction_);

  /* Gain: '<S2>/Gain' incorporates:
   *  Constant: '<S1>/accelerometer angle bias'
   *  Constant: '<S1>/angle offset'
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  Gain: '<S1>/raw y acceleration to g_y'
   *  Gain: '<S1>/raw z acceleration to g_z'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S1>/Sum3'
   *  Trigonometry: '<S1>/g_y and g_z to angle in radians'
   */
  LabB_CheckCommunications_B.Gain = ((rt_atan2d_snf
    (LabB_CheckCommunications_P.rawyaccelerationtog_y_Gain * (real_T)
     LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFuncti_im,
     LabB_CheckCommunications_P.rawzaccelerationtog_z_Gain * (real_T)
     LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_g) +
    LabB_CheckCommunications_P.accelerometeranglebias_Value) +
    LabB_CheckCommunications_P.angleoffset_Value) *
    LabB_CheckCommunications_P.Gain_Gain;

  /* S-Function (sf_QuadEncoder_18_19_15_62): '<S1>/Dual Encoder Reading 18:19, A8(62):15  (MinSegShield M2V3.2) ' */
  sf_QuadEncoder_18_19_15_62_Outputs_wrapper
    ( &LabB_CheckCommunications_B.DualEncoderReading1819A86215Min,
     &LabB_CheckCommunications_B.DualEncoderReading1819A86215M_f,
     &LabB_CheckCommunications_DWork.DualEncoderReading1819A86215Min,
     LabB_CheckCommunications_P.DualEncoderReading1819A86215Min, 2,
     LabB_CheckCommunications_P.DualEncoderReading1819A86215M_h, 2,
     LabB_CheckCommunications_P.DualEncoderReading1819A86215M_c, 2);

  /* Gain: '<S3>/Gain' incorporates:
   *  Constant: '<S1>/angle offset'
   *  DiscreteIntegrator: '<S1>/angular velocity to angle'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S1>/Sum4'
   */
  LabB_CheckCommunications_B.Gain_j =
    ((LabB_CheckCommunications_P.angleoffset_Value +
      LabB_CheckCommunications_DWork.angularvelocitytoangle_DSTATE) +
     LabB_CheckCommunications_P.angleoffset_Value) *
    LabB_CheckCommunications_P.Gain_Gain_o;

  /* Sin: '<Root>/Sine Wave' */
  if (LabB_CheckCommunications_DWork.systemEnable != 0L) {
    LabB_CheckCommunications_DWork.lastSin = sin
      (LabB_CheckCommunications_P.SineWave_Freq *
       LabB_CheckCommunications_M->Timing.taskTime0);
    LabB_CheckCommunications_DWork.lastCos = cos
      (LabB_CheckCommunications_P.SineWave_Freq *
       LabB_CheckCommunications_M->Timing.taskTime0);
    LabB_CheckCommunications_DWork.systemEnable = 0L;
  }

  LabB_CheckCommunications_B.SineWave = ((LabB_CheckCommunications_DWork.lastSin
    * LabB_CheckCommunications_P.SineWave_PCos +
    LabB_CheckCommunications_DWork.lastCos *
    LabB_CheckCommunications_P.SineWave_PSin) *
    LabB_CheckCommunications_P.SineWave_HCos +
    (LabB_CheckCommunications_DWork.lastCos *
     LabB_CheckCommunications_P.SineWave_PCos -
     LabB_CheckCommunications_DWork.lastSin *
     LabB_CheckCommunications_P.SineWave_PSin) *
    LabB_CheckCommunications_P.SineWave_Hsin) *
    LabB_CheckCommunications_P.SineWave_Amp +
    LabB_CheckCommunications_P.SineWave_Bias;

  /* End of Sin: '<Root>/Sine Wave' */

  /* Sum: '<S1>/Sum2' incorporates:
   *  Constant: '<S1>/gyro velocity bias'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Gain: '<S1>/raw x velocity to deg. // sec.'
   *  Gain: '<S4>/Gain1'
   */
  LabB_CheckCommunications_B.Sum2 =
    LabB_CheckCommunications_P.rawxvelocitytodegsec_Gain * (real_T)
    LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_p *
    LabB_CheckCommunications_P.Gain1_Gain +
    LabB_CheckCommunications_P.gyrovelocitybias_Value;

  /* Gain: '<S1>/conversion to duty cycle (convert to int)' */
  rtb_Switch = floor(LabB_CheckCommunications_P.conversiontodutycycleconverttoi *
                     LabB_CheckCommunications_B.SineWave);
  if (rtIsNaN(rtb_Switch) || rtIsInf(rtb_Switch)) {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch = fmod(rtb_Switch, 65536.0);
  }

  rtb_Abs = rtb_Switch < 0.0 ? -(int16_T)(uint16_T)-rtb_Switch : (int16_T)
    (uint16_T)rtb_Switch;

  /* End of Gain: '<S1>/conversion to duty cycle (convert to int)' */

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   */
  if (rtb_Abs >= LabB_CheckCommunications_P.Switch_Threshold) {
    rtb_Switch = LabB_CheckCommunications_P.Constant2_Value;
  } else {
    rtb_Switch = LabB_CheckCommunications_P.Constant1_Value;
  }

  /* End of Switch: '<S1>/Switch' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  if (rtb_Switch < 256.0) {
    if (rtb_Switch >= 0.0) {
      rtb_Switch_0 = (uint8_T)rtb_Switch;
    } else {
      rtb_Switch_0 = 0U;
    }
  } else {
    rtb_Switch_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S5>/Digital Output' */
  MW_digitalWrite(LabB_CheckCommunications_P.DigitalOutput_pinNumber,
                  rtb_Switch_0);

  /* Abs: '<S1>/Abs' */
  if (rtb_Abs < 0) {
    rtb_Abs = -rtb_Abs;
  }

  /* End of Abs: '<S1>/Abs' */

  /* Sum: '<S1>/Add2' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  u0 = LabB_CheckCommunications_P.Constant3_Value + (real_T)rtb_Abs;

  /* Saturate: '<S1>/Saturation 0 to 255' */
  if (u0 > LabB_CheckCommunications_P.Saturation0to255_UpperSat) {
    u0 = LabB_CheckCommunications_P.Saturation0to255_UpperSat;
  } else {
    if (u0 < LabB_CheckCommunications_P.Saturation0to255_LowerSat) {
      u0 = LabB_CheckCommunications_P.Saturation0to255_LowerSat;
    }
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Abs: '<S1>/Abs3'
   *  Gain: '<S1>/Gain1'
   *  Saturate: '<S1>/Saturation 0 to 255'
   *  Sum: '<S1>/Add1'
   */
  rtb_Switch = fabs(LabB_CheckCommunications_P.Gain1_Gain_b * rtb_Switch - u0);
  if (rtb_Switch < 256.0) {
    rtb_Switch_0 = (uint8_T)rtb_Switch;
  } else {
    rtb_Switch_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
  MW_analogWrite(LabB_CheckCommunications_P.PWM_pinNumber, rtb_Switch_0);
}

/* Model update function */
void LabB_CheckCommunications_update(void)
{
  real_T HoldSine;

  /* S-Function "sf_HMC5883L_MPU6050_wrapper" Block: <S1>/HMC5883L & MPU6050  Driver SFunction */
  sf_HMC5883L_MPU6050_Update_wrapper
    ( &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunction_,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_e,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_i,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_p,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFuncti_pc,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_j,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_c,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFuncti_im,
     &LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_g,
     &LabB_CheckCommunications_DWork.HMC5883LMPU6050DriverSFunction_);

  /* S-Function "sf_QuadEncoder_18_19_15_62_wrapper" Block: <S1>/Dual Encoder Reading 18:19, A8(62):15  (MinSegShield M2V3.2)  */
  sf_QuadEncoder_18_19_15_62_Update_wrapper
    ( &LabB_CheckCommunications_B.DualEncoderReading1819A86215Min,
     &LabB_CheckCommunications_B.DualEncoderReading1819A86215M_f,
     &LabB_CheckCommunications_DWork.DualEncoderReading1819A86215Min,
     LabB_CheckCommunications_P.DualEncoderReading1819A86215Min, 2,
     LabB_CheckCommunications_P.DualEncoderReading1819A86215M_h, 2,
     LabB_CheckCommunications_P.DualEncoderReading1819A86215M_c, 2);

  /* Update for DiscreteIntegrator: '<S1>/angular velocity to angle' */
  LabB_CheckCommunications_DWork.angularvelocitytoangle_DSTATE +=
    LabB_CheckCommunications_P.angularvelocitytoangle_gainval *
    LabB_CheckCommunications_B.Sum2;

  /* Update for Sin: '<Root>/Sine Wave' */
  HoldSine = LabB_CheckCommunications_DWork.lastSin;
  LabB_CheckCommunications_DWork.lastSin =
    LabB_CheckCommunications_DWork.lastSin *
    LabB_CheckCommunications_P.SineWave_HCos +
    LabB_CheckCommunications_DWork.lastCos *
    LabB_CheckCommunications_P.SineWave_Hsin;
  LabB_CheckCommunications_DWork.lastCos =
    LabB_CheckCommunications_DWork.lastCos *
    LabB_CheckCommunications_P.SineWave_HCos - HoldSine *
    LabB_CheckCommunications_P.SineWave_Hsin;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(LabB_CheckCommunications_M)!=-1) &&
        !((rtmGetTFinal(LabB_CheckCommunications_M)-
           LabB_CheckCommunications_M->Timing.taskTime0) >
          LabB_CheckCommunications_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(LabB_CheckCommunications_M, "Simulation finished");
    }

    if (rtmGetStopRequested(LabB_CheckCommunications_M)) {
      rtmSetErrorStatus(LabB_CheckCommunications_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  LabB_CheckCommunications_M->Timing.taskTime0 =
    (++LabB_CheckCommunications_M->Timing.clockTick0) *
    LabB_CheckCommunications_M->Timing.stepSize0;
}

/* Model initialize function */
void LabB_CheckCommunications_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)LabB_CheckCommunications_M, 0,
                sizeof(RT_MODEL_LabB_CheckCommunicatio));
  rtmSetTFinal(LabB_CheckCommunications_M, -1);
  LabB_CheckCommunications_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  LabB_CheckCommunications_M->Sizes.checksums[0] = (828292839U);
  LabB_CheckCommunications_M->Sizes.checksums[1] = (561445509U);
  LabB_CheckCommunications_M->Sizes.checksums[2] = (3139536426U);
  LabB_CheckCommunications_M->Sizes.checksums[3] = (3243436275U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    LabB_CheckCommunications_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LabB_CheckCommunications_M->extModeInfo,
      &LabB_CheckCommunications_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LabB_CheckCommunications_M->extModeInfo,
                        LabB_CheckCommunications_M->Sizes.checksums);
    rteiSetTPtr(LabB_CheckCommunications_M->extModeInfo, rtmGetTPtr
                (LabB_CheckCommunications_M));
  }

  /* block I/O */
  (void) memset(((void *) &LabB_CheckCommunications_B), 0,
                sizeof(BlockIO_LabB_CheckCommunication));

  /* states (dwork) */
  (void) memset((void *)&LabB_CheckCommunications_DWork, 0,
                sizeof(D_Work_LabB_CheckCommunications));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LabB_CheckCommunications_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S5>/Digital Output' */
  MW_pinModeOutput(LabB_CheckCommunications_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
  MW_pinModeOutput(LabB_CheckCommunications_P.PWM_pinNumber);

  /* S-Function Block: <S1>/HMC5883L & MPU6050  Driver SFunction */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        LabB_CheckCommunications_DWork.HMC5883LMPU6050DriverSFunction_ =
          initVector[0];
      }
    }
  }

  /* S-Function Block: <S1>/Dual Encoder Reading 18:19, A8(62):15  (MinSegShield M2V3.2)  */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        LabB_CheckCommunications_DWork.DualEncoderReading1819A86215Min =
          initVector[0];
      }
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<S1>/angular velocity to angle' */
  LabB_CheckCommunications_DWork.angularvelocitytoangle_DSTATE =
    LabB_CheckCommunications_P.angularvelocitytoangle_IC;

  /* Enable for Sin: '<Root>/Sine Wave' */
  LabB_CheckCommunications_DWork.systemEnable = 1L;
}

/* Model terminate function */
void LabB_CheckCommunications_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
