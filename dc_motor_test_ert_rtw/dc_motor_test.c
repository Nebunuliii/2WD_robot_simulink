/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dc_motor_test.c
 *
 * Code generated for Simulink model 'dc_motor_test'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu May  8 12:46:07 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "dc_motor_test.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "dc_motor_test_private.h"

/* Block signals (default storage) */
B_dc_motor_test_T dc_motor_test_B;

/* Block states (default storage) */
DW_dc_motor_test_T dc_motor_test_DW;

/* Real-time model */
static RT_MODEL_dc_motor_test_T dc_motor_test_M_;
RT_MODEL_dc_motor_test_T *const dc_motor_test_M = &dc_motor_test_M_;
real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T exp_0;
  int32_T i;
  uint32_T cb;
  uint32_T u1i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T ni;
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

/* Model step function */
void dc_motor_test_step(void)
{
  int128m_T tmp;
  int64m_T tmp_0;
  real_T rtb_Product_d;
  real_T rtb_Switch2_e;
  real_T tmp_3;
  int32_T rtb_Encoder_0;
  uint32_T tmp_1;
  uint32_T tmp_2;
  uint8_T rtb_Switch_f_idx_0;
  uint8_T rtb_Switch_f_idx_1;

  /* Constant: '<Root>/target_rpm' */
  dc_motor_test_B.target_rpm = dc_motor_test_P.target_rpm_Value;

  /* MATLABSystem: '<Root>/Encoder' */
  if (dc_motor_test_DW.obj.SampleTime != dc_motor_test_P.Encoder_SampleTime) {
    dc_motor_test_DW.obj.SampleTime = dc_motor_test_P.Encoder_SampleTime;
  }

  if (dc_motor_test_DW.obj.TunablePropsChanged) {
    dc_motor_test_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(dc_motor_test_DW.obj.Index, &rtb_Encoder_0);

  /* Gain: '<Root>/1sec' incorporates:
   *  Delay: '<Root>/Delay'
   *  MATLABSystem: '<Root>/Encoder'
   *  Sum: '<Root>/Subtract'
   */
  tmp_1 = (uint32_T)dc_motor_test_P.usec_Gain;
  tmp_2 = (uint32_T)(rtb_Encoder_0 - dc_motor_test_DW.Delay_DSTATE_j);
  sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_0.chunks[0U], 2);

  /* Gain: '<Root>/1min' */
  sMultiWordMul(&dc_motor_test_P.umin_Gain.chunks[0U], 2, &tmp_0.chunks[0U], 2,
                &tmp.chunks[0U], 4);

  /* Sum: '<S1>/Add1' incorporates:
   *  Constant: '<Root>/1//PPR'
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   *  Delay: '<S1>/Delay'
   *  Gain: '<Root>/gear_ratio'
   *  Product: '<Root>/Product'
   *  Product: '<S1>/Divide'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Add'
   */
  dc_motor_test_B.Add1 += (sMultiWord2Double(&tmp.chunks[0U], 4, 0) *
    4.1359030627651384E-25 * dc_motor_test_P.uPPR_Value *
    dc_motor_test_P.gear_ratio_Gain - dc_motor_test_B.Add1) *
    (dc_motor_test_P.Constant6_Value_g / dc_motor_test_P.Constant7_Value);

  /* SignalConversion generated from: '<Root>/Mux' */
  dc_motor_test_B.TmpSignalConversionAtTAQSigLogg[0] =
    dc_motor_test_B.target_rpm;
  dc_motor_test_B.TmpSignalConversionAtTAQSigLogg[1] = dc_motor_test_B.Add1;

  /* Sum: '<S2>/Subtract' */
  rtb_Switch2_e = dc_motor_test_B.target_rpm - dc_motor_test_B.Add1;

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S2>/Kp'
   */
  rtb_Product_d = rtb_Switch2_e * dc_motor_test_P.Kp_Value;

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Ki'
   *  Delay: '<S2>/Delay'
   *  Product: '<S2>/Product1'
   */
  dc_motor_test_DW.Delay_DSTATE_n += rtb_Switch2_e * dc_motor_test_P.Ki_Value;

  /* Sum: '<S2>/Add1' incorporates:
   *  Constant: '<S2>/Kd'
   *  Delay: '<S2>/Delay1'
   *  Product: '<S2>/Product2'
   */
  dc_motor_test_DW.Delay1_DSTATE = rtb_Switch2_e * dc_motor_test_P.Kd_Value -
    dc_motor_test_DW.Delay1_DSTATE;

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant11'
   *  RelationalOperator: '<S7>/LowerRelop1'
   *  RelationalOperator: '<S7>/UpperRelop'
   *  Switch: '<S7>/Switch'
   */
  if (rtb_Product_d > dc_motor_test_P.Constant11_Value) {
    rtb_Product_d = dc_motor_test_P.Constant11_Value;
  } else if (rtb_Product_d < dc_motor_test_P.Constant10_Value) {
    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S2>/Constant10'
     */
    rtb_Product_d = dc_motor_test_P.Constant10_Value;
  }

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S2>/Constant8'
   *  Constant: '<S2>/Constant9'
   *  Delay: '<S2>/Delay'
   *  RelationalOperator: '<S6>/LowerRelop1'
   *  RelationalOperator: '<S6>/UpperRelop'
   *  Switch: '<S6>/Switch'
   */
  if (dc_motor_test_DW.Delay_DSTATE_n > dc_motor_test_P.Constant9_Value) {
    rtb_Switch2_e = dc_motor_test_P.Constant9_Value;
  } else if (dc_motor_test_DW.Delay_DSTATE_n < dc_motor_test_P.Constant8_Value)
  {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S2>/Constant8'
     */
    rtb_Switch2_e = dc_motor_test_P.Constant8_Value;
  } else {
    rtb_Switch2_e = dc_motor_test_DW.Delay_DSTATE_n;
  }

  /* Switch: '<S5>/Switch2' incorporates:
   *  Constant: '<S2>/Constant6'
   *  Constant: '<S2>/Constant7'
   *  Delay: '<S2>/Delay1'
   *  RelationalOperator: '<S5>/LowerRelop1'
   *  RelationalOperator: '<S5>/UpperRelop'
   *  Switch: '<S5>/Switch'
   */
  if (dc_motor_test_DW.Delay1_DSTATE > dc_motor_test_P.Constant7_Value_j) {
    tmp_3 = dc_motor_test_P.Constant7_Value_j;
  } else if (dc_motor_test_DW.Delay1_DSTATE < dc_motor_test_P.Constant6_Value) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S2>/Constant6'
     */
    tmp_3 = dc_motor_test_P.Constant6_Value;
  } else {
    tmp_3 = dc_motor_test_DW.Delay1_DSTATE;
  }

  /* Sum: '<S2>/Add2' incorporates:
   *  Switch: '<S5>/Switch2'
   *  Switch: '<S6>/Switch2'
   *  Switch: '<S7>/Switch2'
   */
  dc_motor_test_B.Switch2 = (rtb_Product_d + rtb_Switch2_e) + tmp_3;

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant5'
   *  RelationalOperator: '<S4>/LowerRelop1'
   *  RelationalOperator: '<S4>/UpperRelop'
   *  Switch: '<S4>/Switch'
   */
  if (dc_motor_test_B.Switch2 > dc_motor_test_P.Constant5_Value) {
    /* Sum: '<S2>/Add2' incorporates:
     *  Switch: '<S4>/Switch2'
     */
    dc_motor_test_B.Switch2 = dc_motor_test_P.Constant5_Value;
  } else if (dc_motor_test_B.Switch2 < dc_motor_test_P.Constant2_Value) {
    /* Sum: '<S2>/Add2' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Switch: '<S4>/Switch'
     *  Switch: '<S4>/Switch2'
     */
    dc_motor_test_B.Switch2 = dc_motor_test_P.Constant2_Value;
  }

  /* End of Switch: '<S4>/Switch2' */
  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   */
  if (dc_motor_test_B.Switch2 >= dc_motor_test_P.Constant_Value) {
    rtb_Switch_f_idx_0 = dc_motor_test_P.Constant_Value_e;
    rtb_Switch_f_idx_1 = dc_motor_test_P.Constant1_Value;
  } else {
    rtb_Switch_f_idx_0 = dc_motor_test_P.Constant3_Value;
    rtb_Switch_f_idx_1 = dc_motor_test_P.Constant4_Value;
  }

  /* End of Switch: '<S2>/Switch' */

  /* MATLABSystem: '<S2>/IN1' */
  writeDigitalPin(12, rtb_Switch_f_idx_0);

  /* MATLABSystem: '<S2>/IN2' */
  writeDigitalPin(13, rtb_Switch_f_idx_1);

  /* MATLABSystem: '<S2>/PWM' */
  dc_motor_test_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(14U);

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Abs: '<S2>/Abs'
   */
  rtb_Switch2_e = floor(fabs(dc_motor_test_B.Switch2));
  if (rtIsNaN(rtb_Switch2_e) || rtIsInf(rtb_Switch2_e)) {
    rtb_Switch2_e = 0.0;
  } else {
    rtb_Switch2_e = fmod(rtb_Switch2_e, 256.0);
  }

  /* MATLABSystem: '<S2>/PWM' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  MW_PWM_SetDutyCycle(dc_motor_test_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                      (uint8_T)rtb_Switch2_e);

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  MATLABSystem: '<Root>/Encoder'
   */
  dc_motor_test_DW.Delay_DSTATE_j = rtb_Encoder_0;

  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  dc_motor_test_M->Timing.taskTime0 =
    ((time_T)(++dc_motor_test_M->Timing.clockTick0)) *
    dc_motor_test_M->Timing.stepSize0;
}

/* Model initialize function */
void dc_motor_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(dc_motor_test_M, -1);
  dc_motor_test_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  dc_motor_test_M->Sizes.checksums[0] = (853165210U);
  dc_motor_test_M->Sizes.checksums[1] = (783913223U);
  dc_motor_test_M->Sizes.checksums[2] = (842597734U);
  dc_motor_test_M->Sizes.checksums[3] = (2532240721U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    dc_motor_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(dc_motor_test_M->extModeInfo,
      &dc_motor_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(dc_motor_test_M->extModeInfo,
                        dc_motor_test_M->Sizes.checksums);
    rteiSetTPtr(dc_motor_test_M->extModeInfo, rtmGetTPtr(dc_motor_test_M));
  }

  /* InitializeConditions for Delay: '<S1>/Delay' */
  dc_motor_test_B.Add1 = dc_motor_test_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  dc_motor_test_DW.Delay_DSTATE_j = dc_motor_test_P.Delay_InitialCondition_b;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  dc_motor_test_DW.Delay_DSTATE_n = dc_motor_test_P.Delay_InitialCondition_p;

  /* InitializeConditions for Delay: '<S2>/Delay1' */
  dc_motor_test_DW.Delay1_DSTATE = dc_motor_test_P.Delay1_InitialCondition;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  dc_motor_test_DW.obj.Index = 0U;
  dc_motor_test_DW.obj.matlabCodegenIsDeleted = false;
  dc_motor_test_DW.obj.SampleTime = dc_motor_test_P.Encoder_SampleTime;
  dc_motor_test_DW.obj.isInitialized = 1;
  MW_EncoderSetup(26U, 27U, &dc_motor_test_DW.obj.Index);
  dc_motor_test_DW.obj.isSetupComplete = true;
  dc_motor_test_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
  MW_EncoderReset(dc_motor_test_DW.obj.Index);

  /* Start for MATLABSystem: '<S2>/IN1' */
  dc_motor_test_DW.obj_hy.matlabCodegenIsDeleted = false;
  dc_motor_test_DW.obj_hy.isInitialized = 1;
  digitalIOSetup(12, 1);
  dc_motor_test_DW.obj_hy.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/IN2' */
  dc_motor_test_DW.obj_h.matlabCodegenIsDeleted = false;
  dc_motor_test_DW.obj_h.isInitialized = 1;
  digitalIOSetup(13, 1);
  dc_motor_test_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM' */
  dc_motor_test_DW.obj_g.matlabCodegenIsDeleted = false;
  dc_motor_test_DW.obj_g.isInitialized = 1;
  dc_motor_test_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(14U, 0.0, 0.0);
  dc_motor_test_DW.obj_g.isSetupComplete = true;
}

/* Model terminate function */
void dc_motor_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!dc_motor_test_DW.obj.matlabCodegenIsDeleted) {
    dc_motor_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((dc_motor_test_DW.obj.isInitialized == 1) &&
        dc_motor_test_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<S2>/IN1' */
  if (!dc_motor_test_DW.obj_hy.matlabCodegenIsDeleted) {
    dc_motor_test_DW.obj_hy.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/IN1' */

  /* Terminate for MATLABSystem: '<S2>/IN2' */
  if (!dc_motor_test_DW.obj_h.matlabCodegenIsDeleted) {
    dc_motor_test_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/IN2' */
  /* Terminate for MATLABSystem: '<S2>/PWM' */
  if (!dc_motor_test_DW.obj_g.matlabCodegenIsDeleted) {
    dc_motor_test_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((dc_motor_test_DW.obj_g.isInitialized == 1) &&
        dc_motor_test_DW.obj_g.isSetupComplete) {
      dc_motor_test_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(14U);
      MW_PWM_SetDutyCycle(dc_motor_test_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      dc_motor_test_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(14U);
      MW_PWM_Close(dc_motor_test_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
