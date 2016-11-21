/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_PIDOverRobot.c
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

/* Block signals (auto storage) */
BlockIO_LabB_PIDOverRobot LabB_PIDOverRobot_B;

/* Block states (auto storage) */
D_Work_LabB_PIDOverRobot LabB_PIDOverRobot_DWork;

/* Real-time model */
RT_MODEL_LabB_PIDOverRobot LabB_PIDOverRobot_M_;
RT_MODEL_LabB_PIDOverRobot *const LabB_PIDOverRobot_M = &LabB_PIDOverRobot_M_;

/* Model output function */
void LabB_PIDOverRobot_output(void)
{
  real_T rtb_Sum_d;
  real_T rtb_Add2;
  uint16_T rtb_DataTypeConversion6;
  uint8_T rtb_ExtractDesiredBits;
  uint8_T rtb_ExtractDesiredBits_a5;
  int16_T rtb_Abs;
  uint8_T rtb_ExtractDesiredBits_kf;
  uint8_T rtb_ExtractDesiredBits_j;
  uint8_T tmp[15];
  real_T tmp_0;

  /* Gain: '<S4>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  DiscreteIntegrator: '<S4>/Filter'
   *  Gain: '<S4>/Derivative Gain'
   *  Sum: '<S4>/SumD'
   */
  LabB_PIDOverRobot_B.FilterCoefficient = (-LabB_PIDOverRobot_P.kD *
    LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr -
    LabB_PIDOverRobot_DWork.Filter_DSTATE) * LabB_PIDOverRobot_P.PIDController_N;

  /* Sum: '<S4>/Sum' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  DiscreteIntegrator: '<S4>/Integrator'
   *  Gain: '<S4>/Proportional Gain'
   */
  rtb_Sum_d = (-LabB_PIDOverRobot_P.kP *
               LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr +
               LabB_PIDOverRobot_DWork.Integrator_DSTATE) +
    LabB_PIDOverRobot_B.FilterCoefficient;

  /* Saturate: '<S4>/Saturate' */
  if (rtb_Sum_d > LabB_PIDOverRobot_P.PIDController_UpperSaturationLi) {
    rtb_Add2 = LabB_PIDOverRobot_P.PIDController_UpperSaturationLi;
  } else if (rtb_Sum_d < LabB_PIDOverRobot_P.PIDController_LowerSaturationLi) {
    rtb_Add2 = LabB_PIDOverRobot_P.PIDController_LowerSaturationLi;
  } else {
    rtb_Add2 = rtb_Sum_d;
  }

  /* End of Saturate: '<S4>/Saturate' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Fcn: '<S5>/Fcn'
   */
  tmp_0 = floor((rtb_Add2 + 10.0) * 3276.8);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 65536.0);
  }

  rtb_DataTypeConversion6 = tmp_0 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp_0 :
    (uint16_T)tmp_0;

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* DataTypeConversion: '<S6>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_kf = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S7>/Extract Desired Bits' */
  rtb_ExtractDesiredBits = (uint8_T)rtb_DataTypeConversion6;

  /* S-Function (sf_QuadEncoder_18_19_15_62): '<S3>/Encoder ' */
  sf_QuadEncoder_18_19_15_62_Outputs_wrapper( &LabB_PIDOverRobot_B.Encoder_o1,
    &LabB_PIDOverRobot_B.Encoder_o2, &LabB_PIDOverRobot_DWork.Encoder_DSTATE,
    LabB_PIDOverRobot_P.Encoder_P1, 2, LabB_PIDOverRobot_P.Encoder_P2, 2,
    LabB_PIDOverRobot_P.Encoder_P3, 2);

  /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type  Conversion2'
   *  Fcn: '<S5>/Fcn1'
   *  Gain: '<S2>/convert to  radians'
   *  Gain: '<S2>/convert to meters'
   */
  tmp_0 = floor((-6.2831853071795862 / LabB_PIDOverRobot_P.iNumberOfEncoderSteps
                 * (real_T)LabB_PIDOverRobot_B.Encoder_o1 *
                 LabB_PIDOverRobot_P.fWheelRadius + 10.0) * 3276.8);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 65536.0);
  }

  rtb_DataTypeConversion6 = tmp_0 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp_0 :
    (uint16_T)tmp_0;

  /* End of DataTypeConversion: '<S5>/Data Type Conversion1' */

  /* DataTypeConversion: '<S12>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_j = (uint8_T)(rtb_DataTypeConversion6 >> 8);

  /* DataTypeConversion: '<S13>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_a5 = (uint8_T)rtb_DataTypeConversion6;

  /* DataTypeConversion: '<S5>/Data Type Conversion2' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Fcn: '<S5>/Fcn2'
   */
  tmp_0 = floor((LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr + 10.0)
                * 3276.8);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 65536.0);
  }

  rtb_DataTypeConversion6 = tmp_0 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp_0 :
    (uint16_T)tmp_0;

  /* End of DataTypeConversion: '<S5>/Data Type Conversion2' */

  /* S-Function (arduinoserialwrite_sfcn): '<S5>/Serial Transmit' incorporates:
   *  Constant: '<S5>/Constant'
   *  DataTypeConversion: '<S10>/Extract Desired Bits'
   *  DataTypeConversion: '<S11>/Extract Desired Bits'
   *  DataTypeConversion: '<S14>/Extract Desired Bits'
   *  DataTypeConversion: '<S15>/Extract Desired Bits'
   *  SignalConversion: '<S5>/TmpSignal ConversionAtSerial TransmitInport1'
   */
  tmp[0] = LabB_PIDOverRobot_P.Constant_Value;
  tmp[1] = rtb_ExtractDesiredBits_kf;
  tmp[2] = rtb_ExtractDesiredBits;
  tmp[3] = rtb_ExtractDesiredBits_j;
  tmp[4] = rtb_ExtractDesiredBits_a5;
  tmp[5] = (uint8_T)(rtb_DataTypeConversion6 >> 8);
  tmp[6] = (uint8_T)rtb_DataTypeConversion6;
  tmp[7] = 128U;
  tmp[8] = 0U;
  tmp[9] = 128U;
  tmp[10] = 0U;
  tmp[11] = 128U;
  tmp[12] = 0U;
  tmp[13] = 128U;
  tmp[14] = 0U;
  Serial_write(LabB_PIDOverRobot_P.SerialTransmit_portNumber, tmp, 15UL);

  /* Sum: '<S4>/SumI1' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Gain: '<S4>/Integral Gain'
   *  Gain: '<S4>/Kb'
   *  Sum: '<S4>/SumI2'
   */
  LabB_PIDOverRobot_B.SumI1 = (rtb_Add2 - rtb_Sum_d) *
    LabB_PIDOverRobot_P.PIDController_Kb + -LabB_PIDOverRobot_P.kI *
    LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr;

  /* Product: '<S1>/Product1' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Fcn: '<S1>/turn off the motor if the measured angle is greater than X degrees'
   */
  rtb_Add2 *= (real_T)(fabs
                       (LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr)
                       < 0.75);

  /* S-Function (sf_MPU6050_Driver_GxAyz): '<S3>/Gyro and Accelerometer' */
  sf_MPU6050_Driver_GxAyz_Outputs_wrapper
    ( &LabB_PIDOverRobot_B.GyroandAccelerometer_o1,
     &LabB_PIDOverRobot_B.GyroandAccelerometer_o2,
     &LabB_PIDOverRobot_B.GyroandAccelerometer_o3,
     &LabB_PIDOverRobot_DWork.GyroandAccelerometer_DSTATE);

  /* Gain: '<S2>/convert to radians//sec' incorporates:
   *  Constant: '<S2>/gyro bias'
   *  DataTypeConversion: '<S3>/Data Type  Conversion1'
   *  Sum: '<S2>/Sum'
   */
  LabB_PIDOverRobot_B.converttoradianssec =
    LabB_PIDOverRobot_P.fGyroConversionFactor * 3.1415926535897931 / 180.0 *
    ((real_T)LabB_PIDOverRobot_B.GyroandAccelerometer_o1 -
     LabB_PIDOverRobot_P.fGyroBias);

  /* Gain: '<S20>/conversion to duty cycle (convert to int)' */
  tmp_0 = floor(LabB_PIDOverRobot_P.conversiontodutycycleconverttoi * rtb_Add2);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 65536.0);
  }

  rtb_Abs = tmp_0 < 0.0 ? -(int16_T)(uint16_T)-tmp_0 : (int16_T)(uint16_T)tmp_0;

  /* End of Gain: '<S20>/conversion to duty cycle (convert to int)' */

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Constant1'
   *  Constant: '<S20>/Constant2'
   */
  if (rtb_Abs >= LabB_PIDOverRobot_P.Switch_Threshold) {
    rtb_Sum_d = LabB_PIDOverRobot_P.Constant2_Value;
  } else {
    rtb_Sum_d = LabB_PIDOverRobot_P.Constant1_Value;
  }

  /* End of Switch: '<S20>/Switch' */

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  if (rtb_Sum_d < 256.0) {
    if (rtb_Sum_d >= 0.0) {
      rtb_ExtractDesiredBits_kf = (uint8_T)rtb_Sum_d;
    } else {
      rtb_ExtractDesiredBits_kf = 0U;
    }
  } else {
    rtb_ExtractDesiredBits_kf = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S21>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S21>/Digital Output' */
  MW_digitalWrite(LabB_PIDOverRobot_P.DigitalOutput_pinNumber,
                  rtb_ExtractDesiredBits_kf);

  /* Abs: '<S20>/Abs' */
  if (rtb_Abs < 0) {
    rtb_Abs = -rtb_Abs;
  }

  /* End of Abs: '<S20>/Abs' */

  /* Sum: '<S20>/Add2' incorporates:
   *  Constant: '<S20>/Constant3'
   */
  rtb_Add2 = LabB_PIDOverRobot_P.Constant3_Value + (real_T)rtb_Abs;

  /* Saturate: '<S20>/Saturation 0 to 255' */
  if (rtb_Add2 > LabB_PIDOverRobot_P.Saturation0to255_UpperSat) {
    rtb_Add2 = LabB_PIDOverRobot_P.Saturation0to255_UpperSat;
  } else {
    if (rtb_Add2 < LabB_PIDOverRobot_P.Saturation0to255_LowerSat) {
      rtb_Add2 = LabB_PIDOverRobot_P.Saturation0to255_LowerSat;
    }
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
   *  Abs: '<S20>/Abs3'
   *  Gain: '<S20>/Gain1'
   *  Saturate: '<S20>/Saturation 0 to 255'
   *  Sum: '<S20>/Add1'
   */
  tmp_0 = fabs(LabB_PIDOverRobot_P.Gain1_Gain * rtb_Sum_d - rtb_Add2);
  if (tmp_0 < 256.0) {
    rtb_ExtractDesiredBits_kf = (uint8_T)tmp_0;
  } else {
    rtb_ExtractDesiredBits_kf = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S22>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S22>/PWM' */
  MW_analogWrite(LabB_PIDOverRobot_P.PWM_pinNumber, rtb_ExtractDesiredBits_kf);
}

/* Model update function */
void LabB_PIDOverRobot_update(void)
{
  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr +=
    LabB_PIDOverRobot_P.DiscreteTimeIntegratorconvertfr *
    LabB_PIDOverRobot_B.converttoradianssec;

  /* Update for DiscreteIntegrator: '<S4>/Integrator' */
  LabB_PIDOverRobot_DWork.Integrator_DSTATE +=
    LabB_PIDOverRobot_P.Integrator_gainval * LabB_PIDOverRobot_B.SumI1;

  /* Update for DiscreteIntegrator: '<S4>/Filter' */
  LabB_PIDOverRobot_DWork.Filter_DSTATE += LabB_PIDOverRobot_P.Filter_gainval *
    LabB_PIDOverRobot_B.FilterCoefficient;

  /* S-Function "sf_QuadEncoder_18_19_15_62_wrapper" Block: <S3>/Encoder  */
  sf_QuadEncoder_18_19_15_62_Update_wrapper( &LabB_PIDOverRobot_B.Encoder_o1,
    &LabB_PIDOverRobot_B.Encoder_o2, &LabB_PIDOverRobot_DWork.Encoder_DSTATE,
    LabB_PIDOverRobot_P.Encoder_P1, 2, LabB_PIDOverRobot_P.Encoder_P2, 2,
    LabB_PIDOverRobot_P.Encoder_P3, 2);

  /* S-Function "sf_MPU6050_Driver_GxAyz_wrapper" Block: <S3>/Gyro and Accelerometer */
  sf_MPU6050_Driver_GxAyz_Update_wrapper
    ( &LabB_PIDOverRobot_B.GyroandAccelerometer_o1,
     &LabB_PIDOverRobot_B.GyroandAccelerometer_o2,
     &LabB_PIDOverRobot_B.GyroandAccelerometer_o3,
     &LabB_PIDOverRobot_DWork.GyroandAccelerometer_DSTATE);
}

/* Model initialize function */
void LabB_PIDOverRobot_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(LabB_PIDOverRobot_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &LabB_PIDOverRobot_B), 0,
                sizeof(BlockIO_LabB_PIDOverRobot));

  /* states (dwork) */
  (void) memset((void *)&LabB_PIDOverRobot_DWork, 0,
                sizeof(D_Work_LabB_PIDOverRobot));

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S21>/Digital Output' */
  MW_pinModeOutput(LabB_PIDOverRobot_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S22>/PWM' */
  MW_pinModeOutput(LabB_PIDOverRobot_P.PWM_pinNumber);

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr =
    LabB_PIDOverRobot_P.DiscreteTimeIntegratorconvert_e;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Integrator' */
  LabB_PIDOverRobot_DWork.Integrator_DSTATE = LabB_PIDOverRobot_P.Integrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Filter' */
  LabB_PIDOverRobot_DWork.Filter_DSTATE = LabB_PIDOverRobot_P.Filter_IC;

  /* S-Function Block: <S3>/Encoder  */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        LabB_PIDOverRobot_DWork.Encoder_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <S3>/Gyro and Accelerometer */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        LabB_PIDOverRobot_DWork.GyroandAccelerometer_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void LabB_PIDOverRobot_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
