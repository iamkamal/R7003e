/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_TuneTheGyro.c
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
#include "LabB_TuneTheGyro_dt.h"

/* Block signals (auto storage) */
BlockIO_LabB_TuneTheGyro LabB_TuneTheGyro_B;

/* Block states (auto storage) */
D_Work_LabB_TuneTheGyro LabB_TuneTheGyro_DWork;

/* Real-time model */
RT_MODEL_LabB_TuneTheGyro LabB_TuneTheGyro_M_;
RT_MODEL_LabB_TuneTheGyro *const LabB_TuneTheGyro_M = &LabB_TuneTheGyro_M_;

/* Model output function */
void LabB_TuneTheGyro_output(void)
{
  /* local block i/o variables */
  real_T rtb_Clock;

  /* Reset subsysRan breadcrumbs */
  srClearBC(LabB_TuneTheGyro_DWork.gyrocalibrationprocedure_Subsys);

  /* Reset subsysRan breadcrumbs */
  srClearBC(LabB_TuneTheGyro_DWork.measurementfilter_SubsysRanBC);

  /* S-Function (sf_MPU6050_Driver_GxAyz): '<Root>/Gyro and Accelerometer' */
  sf_MPU6050_Driver_GxAyz_Outputs_wrapper
    ( &LabB_TuneTheGyro_B.GyroandAccelerometer_o1,
     &LabB_TuneTheGyro_B.GyroandAccelerometer_o2,
     &LabB_TuneTheGyro_B.GyroandAccelerometer_o3,
     &LabB_TuneTheGyro_DWork.GyroandAccelerometer_DSTATE);

  /* DataTypeConversion: '<Root>/Data Type  Conversion1' */
  LabB_TuneTheGyro_B.DataTypeConversion1 =
    LabB_TuneTheGyro_B.GyroandAccelerometer_o1;

  /* Clock: '<Root>/Clock' */
  rtb_Clock = LabB_TuneTheGyro_M->Timing.t[0];

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  LabB_TuneTheGyro_B.Compare = (rtb_Clock >
    LabB_TuneTheGyro_P.calibratethegyrobeforeXsecondss);

  /* Logic: '<Root>/Logical Operator' */
  LabB_TuneTheGyro_B.LogicalOperator = !LabB_TuneTheGyro_B.Compare;

  /* Outputs for Enabled SubSystem: '<Root>/gyro calibration procedure' incorporates:
   *  EnablePort: '<S2>/enable the code below only when the external boolean input is true'
   */
  if (LabB_TuneTheGyro_B.LogicalOperator) {
    /* DiscreteFir: '<S2>/compute a moving average of the gyro' */
    LabB_TuneTheGyro_B.computeamovingaverageofthegyro =
      LabB_TuneTheGyro_B.DataTypeConversion1 *
      LabB_TuneTheGyro_P.computeamovingaverageofthegyr_m;
    srUpdateBC(LabB_TuneTheGyro_DWork.gyrocalibrationprocedure_Subsys);
  }

  /* End of Outputs for SubSystem: '<Root>/gyro calibration procedure' */

  /* Outputs for Enabled SubSystem: '<Root>/measurement filter' incorporates:
   *  EnablePort: '<S3>/enable the code below only when the external boolean input is true '
   */
  if (LabB_TuneTheGyro_B.Compare) {
    srUpdateBC(LabB_TuneTheGyro_DWork.measurementfilter_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<Root>/measurement filter' */
}

/* Model update function */
void LabB_TuneTheGyro_update(void)
{
  /* S-Function "sf_MPU6050_Driver_GxAyz_wrapper" Block: <Root>/Gyro and Accelerometer */
  sf_MPU6050_Driver_GxAyz_Update_wrapper
    ( &LabB_TuneTheGyro_B.GyroandAccelerometer_o1,
     &LabB_TuneTheGyro_B.GyroandAccelerometer_o2,
     &LabB_TuneTheGyro_B.GyroandAccelerometer_o3,
     &LabB_TuneTheGyro_DWork.GyroandAccelerometer_DSTATE);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(LabB_TuneTheGyro_M)!=-1) &&
        !((rtmGetTFinal(LabB_TuneTheGyro_M)-LabB_TuneTheGyro_M->Timing.t[0]) >
          LabB_TuneTheGyro_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(LabB_TuneTheGyro_M, "Simulation finished");
    }

    if (rtmGetStopRequested(LabB_TuneTheGyro_M)) {
      rtmSetErrorStatus(LabB_TuneTheGyro_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  LabB_TuneTheGyro_M->Timing.t[0] =
    (++LabB_TuneTheGyro_M->Timing.clockTick0) *
    LabB_TuneTheGyro_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    LabB_TuneTheGyro_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void LabB_TuneTheGyro_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)LabB_TuneTheGyro_M, 0,
                sizeof(RT_MODEL_LabB_TuneTheGyro));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LabB_TuneTheGyro_M->solverInfo,
                          &LabB_TuneTheGyro_M->Timing.simTimeStep);
    rtsiSetTPtr(&LabB_TuneTheGyro_M->solverInfo, &rtmGetTPtr(LabB_TuneTheGyro_M));
    rtsiSetStepSizePtr(&LabB_TuneTheGyro_M->solverInfo,
                       &LabB_TuneTheGyro_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&LabB_TuneTheGyro_M->solverInfo, (&rtmGetErrorStatus
      (LabB_TuneTheGyro_M)));
    rtsiSetRTModelPtr(&LabB_TuneTheGyro_M->solverInfo, LabB_TuneTheGyro_M);
  }

  rtsiSetSimTimeStep(&LabB_TuneTheGyro_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&LabB_TuneTheGyro_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(LabB_TuneTheGyro_M, &LabB_TuneTheGyro_M->Timing.tArray[0]);
  rtmSetTFinal(LabB_TuneTheGyro_M, -1);
  LabB_TuneTheGyro_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  LabB_TuneTheGyro_M->Sizes.checksums[0] = (1458141944U);
  LabB_TuneTheGyro_M->Sizes.checksums[1] = (3724249049U);
  LabB_TuneTheGyro_M->Sizes.checksums[2] = (3265835079U);
  LabB_TuneTheGyro_M->Sizes.checksums[3] = (745369445U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    LabB_TuneTheGyro_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &LabB_TuneTheGyro_DWork.gyrocalibrationprocedure_Subsys;
    systemRan[2] = (sysRanDType *)
      &LabB_TuneTheGyro_DWork.measurementfilter_SubsysRanBC;
    rteiSetModelMappingInfoPtr(LabB_TuneTheGyro_M->extModeInfo,
      &LabB_TuneTheGyro_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LabB_TuneTheGyro_M->extModeInfo,
                        LabB_TuneTheGyro_M->Sizes.checksums);
    rteiSetTPtr(LabB_TuneTheGyro_M->extModeInfo, rtmGetTPtr(LabB_TuneTheGyro_M));
  }

  /* block I/O */
  (void) memset(((void *) &LabB_TuneTheGyro_B), 0,
                sizeof(BlockIO_LabB_TuneTheGyro));

  /* states (dwork) */
  (void) memset((void *)&LabB_TuneTheGyro_DWork, 0,
                sizeof(D_Work_LabB_TuneTheGyro));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LabB_TuneTheGyro_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* S-Function Block: <Root>/Gyro and Accelerometer */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        LabB_TuneTheGyro_DWork.GyroandAccelerometer_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void LabB_TuneTheGyro_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
