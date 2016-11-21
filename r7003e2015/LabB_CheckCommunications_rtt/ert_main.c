/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "Arduino.h"
#include "io_wrappers.h"
#include <ext_work.h>                  /* External mode header files */
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>
#define STEP_SIZE                      (unsigned long) (10000)

int_T main(void)
{
  unsigned long oldtime = 0L;
  unsigned long actualtime;
  init();

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  LabB_CheckCommunications_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(LabB_CheckCommunications_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(LabB_CheckCommunications_M->extModeInfo, 1,
      &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(LabB_CheckCommunications_M, true);
    }
  }

  rtERTExtModeStartMsg();

#ifdef _RTT_USE_SERIAL1_

  Serial_begin(1, 9600);

#endif

#ifdef _RTT_USE_SERIAL2_

  Serial_begin(2, 9600);

#endif

#ifdef _RTT_USE_SERIAL3_

  Serial_begin(3, 9600);

#endif

  /* The main step loop */
  while ((rtmGetErrorStatus(LabB_CheckCommunications_M) == (NULL)) &&
         !rtmGetStopRequested(LabB_CheckCommunications_M)) {
    actualtime = micros();
    if ((unsigned long) (actualtime - oldtime) >= STEP_SIZE) {
      oldtime = actualtime;

      /* External mode */
      {
        boolean_T rtmStopReq = false;
        rtExtModeOneStep(LabB_CheckCommunications_M->extModeInfo, 1, &rtmStopReq);
        if (rtmStopReq) {
          rtmSetStopRequested(LabB_CheckCommunications_M, true);
        }
      }

      LabB_CheckCommunications_output();

      /* Get model outputs here */

      /* External mode */
      rtExtModeUploadCheckTrigger(1);

      {                                /* Sample time: [0.01s, 0.0s] */
        rtExtModeUpload(0, LabB_CheckCommunications_M->Timing.taskTime0);
      }

      LabB_CheckCommunications_update();
      rtExtModeCheckEndTrigger();
    }
  }

  rtExtModeShutdown(1);
  delay(1000);
  LabB_CheckCommunications_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
