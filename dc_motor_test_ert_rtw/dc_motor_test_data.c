/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dc_motor_test_data.c
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

/* Block parameters (default storage) */
P_dc_motor_test_T dc_motor_test_P = {
  /* Expression: -1
   * Referenced by: '<Root>/Encoder'
   */
  -1.0,

  /* Expression: -255
   * Referenced by: '<S2>/Constant2'
   */
  -255.0,

  /* Expression: -255
   * Referenced by: '<S2>/Constant6'
   */
  -255.0,

  /* Expression: -255
   * Referenced by: '<S2>/Constant8'
   */
  -255.0,

  /* Expression: -255
   * Referenced by: '<S2>/Constant10'
   */
  -255.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: 200
   * Referenced by: '<Root>/target_rpm'
   */
  200.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<Root>/Constant6'
   */
  0.01,

  /* Expression: 0.1
   * Referenced by: '<Root>/Constant7'
   */
  0.1,

  /* Expression: 1/44
   * Referenced by: '<Root>/1//PPR'
   */
  0.022727272727272728,

  /* Expression: 1/21.3
   * Referenced by: '<Root>/gear_ratio'
   */
  0.046948356807511735,

  /* Expression: 255
   * Referenced by: '<S2>/Constant5'
   */
  255.0,

  /* Expression: 255
   * Referenced by: '<S2>/Constant11'
   */
  255.0,

  /* Expression: 18.0397211502912
   * Referenced by: '<S2>/Kp'
   */
  18.0397211502912,

  /* Expression: 255
   * Referenced by: '<S2>/Constant9'
   */
  255.0,

  /* Expression: 2.36635693787993
   * Referenced by: '<S2>/Ki'
   */
  2.36635693787993,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<S2>/Constant7'
   */
  255.0,

  /* Expression: 12.4354459869947
   * Referenced by: '<S2>/Kd'
   */
  12.4354459869947,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay1'
   */
  0.0,

  /* Computed Parameter: umin_Gain
   * Referenced by: '<Root>/1min'
   */
  { { 0UL, 0x78000000UL } },

  /* Computed Parameter: Delay_InitialCondition_b
   * Referenced by: '<Root>/Delay'
   */
  0,

  /* Computed Parameter: usec_Gain
   * Referenced by: '<Root>/1sec'
   */
  1677721600,

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S2>/Constant'
   */
  0U,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S2>/Constant1'
   */
  1U,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S2>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S2>/Constant4'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
