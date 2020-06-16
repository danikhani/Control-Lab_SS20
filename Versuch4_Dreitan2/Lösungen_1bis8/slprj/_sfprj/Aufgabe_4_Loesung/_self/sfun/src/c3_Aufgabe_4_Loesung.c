/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Aufgabe_4_Loesung_sfun.h"
#include "c3_Aufgabe_4_Loesung.h"
#include <string.h>
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Aufgabe_4_Loesung_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[10] = { "tx", "ty", "tz", "nargin",
  "nargout", "DataX", "DataY", "DataZ", "TnName", "UDPData" };

/* Function Declarations */
static void initialize_c3_Aufgabe_4_Loesung(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance);
static void initialize_params_c3_Aufgabe_4_Loesung
  (SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance);
static void enable_c3_Aufgabe_4_Loesung(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance);
static void disable_c3_Aufgabe_4_Loesung(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_Aufgabe_4_Loesung
  (SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_Aufgabe_4_Loesung
  (SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance);
static void set_sim_state_c3_Aufgabe_4_Loesung
  (SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance, const mxArray *c3_st);
static void finalize_c3_Aufgabe_4_Loesung(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance);
static void sf_gateway_c3_Aufgabe_4_Loesung(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance);
static void mdl_start_c3_Aufgabe_4_Loesung(SFc3_Aufgabe_4_LoesungInstanceStruct *
  chartInstance);
static void initSimStructsc3_Aufgabe_4_Loesung
  (SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_b_UDPData, const char_T *c3_identifier,
  uint8_T c3_y[17]);
static void c3_b_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint8_T c3_y[17]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint8_T c3_y[4]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_typecast(SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance,
  real32_T c3_x, uint8_T c3_y[4]);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_Aufgabe_4_Loesung, const
  char_T *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_Aufgabe_4_Loesung(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_Aufgabe_4_Loesung(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_Aufgabe_4_Loesung = 0U;
}

static void initialize_params_c3_Aufgabe_4_Loesung
  (SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_Aufgabe_4_Loesung(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_Aufgabe_4_Loesung(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_Aufgabe_4_Loesung
  (SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_Aufgabe_4_Loesung
  (SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_u;
  const mxArray *c3_c_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(2, 1), false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", *chartInstance->c3_UDPData, 3, 0U,
    1U, 0U, 1, 17), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_Aufgabe_4_Loesung;
  c3_u = c3_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_Aufgabe_4_Loesung
  (SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  uint8_T c3_uv0[17];
  int32_T c3_i0;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("UDPData", c3_u,
    0)), "UDPData", c3_uv0);
  for (c3_i0 = 0; c3_i0 < 17; c3_i0++) {
    (*chartInstance->c3_UDPData)[c3_i0] = c3_uv0[c3_i0];
  }

  chartInstance->c3_is_active_c3_Aufgabe_4_Loesung = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c3_Aufgabe_4_Loesung",
       c3_u, 1)), "is_active_c3_Aufgabe_4_Loesung");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_Aufgabe_4_Loesung(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_Aufgabe_4_Loesung(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_Aufgabe_4_Loesung(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance)
{
  int32_T c3_i1;
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_b_DataX;
  real_T c3_b_DataY;
  real_T c3_b_DataZ;
  int32_T c3_i2;
  uint8_T c3_b_TnName[5];
  uint32_T c3_debug_family_var_map[10];
  uint8_T c3_tx[4];
  uint8_T c3_ty[4];
  uint8_T c3_tz[4];
  real_T c3_nargin = 4.0;
  real_T c3_nargout = 1.0;
  uint8_T c3_b_UDPData[17];
  uint8_T c3_uv1[4];
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i1 = 0; c3_i1 < 5; c3_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c3_TnName)[c3_i1], 3U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_DataZ, 2U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_DataY, 1U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_DataX, 0U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *chartInstance->c3_DataX;
  c3_b_hoistedGlobal = *chartInstance->c3_DataY;
  c3_c_hoistedGlobal = *chartInstance->c3_DataZ;
  c3_b_DataX = c3_hoistedGlobal;
  c3_b_DataY = c3_b_hoistedGlobal;
  c3_b_DataZ = c3_c_hoistedGlobal;
  for (c3_i2 = 0; c3_i2 < 5; c3_i2++) {
    c3_b_TnName[c3_i2] = (*chartInstance->c3_TnName)[c3_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tx, 0U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_ty, 1U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tz, 2U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 3U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 4U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_DataX, 5U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_DataY, 6U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_DataZ, 7U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b_TnName, 8U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_UDPData, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 2);
  c3_typecast(chartInstance, (real32_T)c3_b_DataX, c3_uv1);
  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    c3_tx[c3_i3] = c3_uv1[c3_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_typecast(chartInstance, (real32_T)c3_b_DataY, c3_uv1);
  for (c3_i4 = 0; c3_i4 < 4; c3_i4++) {
    c3_ty[c3_i4] = c3_uv1[c3_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_typecast(chartInstance, (real32_T)c3_b_DataZ, c3_uv1);
  for (c3_i5 = 0; c3_i5 < 4; c3_i5++) {
    c3_tz[c3_i5] = c3_uv1[c3_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  for (c3_i6 = 0; c3_i6 < 17; c3_i6++) {
    c3_b_UDPData[c3_i6] = 0U;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i7 = 0; c3_i7 < 5; c3_i7++) {
    c3_b_UDPData[c3_i7] = c3_b_TnName[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 4; c3_i8++) {
    c3_b_UDPData[c3_i8 + 5] = c3_tx[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 4; c3_i9++) {
    c3_b_UDPData[c3_i9 + 9] = c3_ty[c3_i9];
  }

  for (c3_i10 = 0; c3_i10 < 4; c3_i10++) {
    c3_b_UDPData[c3_i10 + 13] = c3_tz[c3_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i11 = 0; c3_i11 < 17; c3_i11++) {
    (*chartInstance->c3_UDPData)[c3_i11] = c3_b_UDPData[c3_i11];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Aufgabe_4_LoesungMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c3_i12 = 0; c3_i12 < 17; c3_i12++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c3_UDPData)[c3_i12], 4U, 1U,
                          0U, chartInstance->c3_sfEvent, false);
  }
}

static void mdl_start_c3_Aufgabe_4_Loesung(SFc3_Aufgabe_4_LoesungInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc3_Aufgabe_4_Loesung
  (SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i13;
  uint8_T c3_u[17];
  const mxArray *c3_y = NULL;
  SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc3_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i13 = 0; c3_i13 < 17; c3_i13++) {
    c3_u[c3_i13] = (*(uint8_T (*)[17])c3_inData)[c3_i13];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 3, 0U, 1U, 0U, 1, 17), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_b_UDPData, const char_T *c3_identifier,
  uint8_T c3_y[17])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_UDPData), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_b_UDPData);
}

static void c3_b_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint8_T c3_y[17])
{
  uint8_T c3_uv2[17];
  int32_T c3_i14;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_uv2, 1, 3, 0U, 1, 0U, 1, 17);
  for (c3_i14 = 0; c3_i14 < 17; c3_i14++) {
    c3_y[c3_i14] = c3_uv2[c3_i14];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_UDPData;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y[17];
  int32_T c3_i15;
  SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc3_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c3_b_UDPData = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_UDPData), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_b_UDPData);
  for (c3_i15 = 0; c3_i15 < 17; c3_i15++) {
    (*(uint8_T (*)[17])c3_outData)[c3_i15] = c3_y[c3_i15];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i16;
  uint8_T c3_u[5];
  const mxArray *c3_y = NULL;
  SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc3_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i16 = 0; c3_i16 < 5; c3_i16++) {
    c3_u[c3_i16] = (*(uint8_T (*)[5])c3_inData)[c3_i16];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 3, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc3_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc3_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i17;
  uint8_T c3_u[4];
  const mxArray *c3_y = NULL;
  SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc3_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i17 = 0; c3_i17 < 4; c3_i17++) {
    c3_u[c3_i17] = (*(uint8_T (*)[4])c3_inData)[c3_i17];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 3, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint8_T c3_y[4])
{
  uint8_T c3_uv3[4];
  int32_T c3_i18;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_uv3, 1, 3, 0U, 1, 0U, 1, 4);
  for (c3_i18 = 0; c3_i18 < 4; c3_i18++) {
    c3_y[c3_i18] = c3_uv3[c3_i18];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_tz;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y[4];
  int32_T c3_i19;
  SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc3_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c3_tz = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_tz), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_tz);
  for (c3_i19 = 0; c3_i19 < 4; c3_i19++) {
    (*(uint8_T (*)[4])c3_outData)[c3_i19] = c3_y[c3_i19];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_Aufgabe_4_Loesung_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static void c3_typecast(SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance,
  real32_T c3_x, uint8_T c3_y[4])
{
  (void)chartInstance;
  memcpy(&c3_y[0], &c3_x, (size_t)4 * sizeof(uint8_T));
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc3_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i20;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i20, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i20;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc3_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_Aufgabe_4_Loesung, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_Aufgabe_4_Loesung), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_Aufgabe_4_Loesung);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_Aufgabe_4_LoesungInstanceStruct
  *chartInstance)
{
  chartInstance->c3_DataX = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_DataY = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_DataZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_UDPData = (uint8_T (*)[17])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_TnName = (uint8_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_Aufgabe_4_Loesung_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(303288308U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(392705999U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(269099881U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4198165681U);
}

mxArray* sf_c3_Aufgabe_4_Loesung_get_post_codegen_info(void);
mxArray *sf_c3_Aufgabe_4_Loesung_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("R8hs0hN1dHeMXBORWB8WiD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(17);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_Aufgabe_4_Loesung_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Aufgabe_4_Loesung_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_Aufgabe_4_Loesung_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("memcpy");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_Aufgabe_4_Loesung_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_Aufgabe_4_Loesung_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_Aufgabe_4_Loesung(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"UDPData\",},{M[8],M[0],T\"is_active_c3_Aufgabe_4_Loesung\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Aufgabe_4_Loesung_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance =
      (SFc3_Aufgabe_4_LoesungInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Aufgabe_4_LoesungMachineNumber_,
           3,
           1,
           1,
           0,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Aufgabe_4_LoesungMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Aufgabe_4_LoesungMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Aufgabe_4_LoesungMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"DataX");
          _SFD_SET_DATA_PROPS(1,1,1,0,"DataY");
          _SFD_SET_DATA_PROPS(2,1,1,0,"DataZ");
          _SFD_SET_DATA_PROPS(3,1,1,0,"TnName");
          _SFD_SET_DATA_PROPS(4,2,0,1,"UDPData");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,237);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 17U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Aufgabe_4_LoesungMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance =
      (SFc3_Aufgabe_4_LoesungInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_DataX);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c3_DataY);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_DataZ);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c3_UDPData);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c3_TnName);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s6nktavy32B5qO34MiW1XsD";
}

static void sf_opaque_initialize_c3_Aufgabe_4_Loesung(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_Aufgabe_4_Loesung((SFc3_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar);
  initialize_c3_Aufgabe_4_Loesung((SFc3_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_Aufgabe_4_Loesung(void *chartInstanceVar)
{
  enable_c3_Aufgabe_4_Loesung((SFc3_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_Aufgabe_4_Loesung(void *chartInstanceVar)
{
  disable_c3_Aufgabe_4_Loesung((SFc3_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_Aufgabe_4_Loesung(void *chartInstanceVar)
{
  sf_gateway_c3_Aufgabe_4_Loesung((SFc3_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_Aufgabe_4_Loesung(SimStruct* S)
{
  return get_sim_state_c3_Aufgabe_4_Loesung
    ((SFc3_Aufgabe_4_LoesungInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_Aufgabe_4_Loesung(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c3_Aufgabe_4_Loesung((SFc3_Aufgabe_4_LoesungInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_Aufgabe_4_Loesung(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_Aufgabe_4_LoesungInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Aufgabe_4_Loesung_optimization_info();
    }

    finalize_c3_Aufgabe_4_Loesung((SFc3_Aufgabe_4_LoesungInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Aufgabe_4_Loesung((SFc3_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Aufgabe_4_Loesung(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_Aufgabe_4_Loesung((SFc3_Aufgabe_4_LoesungInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_Aufgabe_4_Loesung(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Aufgabe_4_Loesung_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2394330270U));
  ssSetChecksum1(S,(930431429U));
  ssSetChecksum2(S,(1270256505U));
  ssSetChecksum3(S,(3981351446U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_Aufgabe_4_Loesung(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Aufgabe_4_Loesung(SimStruct *S)
{
  SFc3_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc3_Aufgabe_4_LoesungInstanceStruct *)utMalloc(sizeof
    (SFc3_Aufgabe_4_LoesungInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_Aufgabe_4_LoesungInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_Aufgabe_4_Loesung;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_Aufgabe_4_Loesung;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_Aufgabe_4_Loesung;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_Aufgabe_4_Loesung;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_Aufgabe_4_Loesung;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_Aufgabe_4_Loesung;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_Aufgabe_4_Loesung;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_Aufgabe_4_Loesung;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Aufgabe_4_Loesung;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Aufgabe_4_Loesung;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_Aufgabe_4_Loesung;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c3_Aufgabe_4_Loesung(chartInstance);
}

void c3_Aufgabe_4_Loesung_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Aufgabe_4_Loesung(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Aufgabe_4_Loesung(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Aufgabe_4_Loesung(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Aufgabe_4_Loesung_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
