/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Aufgabe_4_Loesung_sfun.h"
#include "c10_Aufgabe_4_Loesung.h"
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
static const char * c10_debug_family_names[10] = { "tx", "ty", "tz", "nargin",
  "nargout", "DataX", "DataY", "DataZ", "TnName", "UDPData" };

/* Function Declarations */
static void initialize_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance);
static void initialize_params_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance);
static void enable_c10_Aufgabe_4_Loesung(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance);
static void disable_c10_Aufgabe_4_Loesung(SFc10_Aufgabe_4_LoesungInstanceStruct *
  chartInstance);
static void c10_update_debugger_state_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance);
static void set_sim_state_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance, const mxArray *c10_st);
static void finalize_c10_Aufgabe_4_Loesung(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance);
static void sf_gateway_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance);
static void mdl_start_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance);
static void initSimStructsc10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_b_UDPData, const char_T *c10_identifier,
  uint8_T c10_y[17]);
static void c10_b_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  uint8_T c10_y[17]);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_c_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_d_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  uint8_T c10_y[4]);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_typecast(SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance,
  real32_T c10_x, uint8_T c10_y[4]);
static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_e_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_f_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_Aufgabe_4_Loesung, const
  char_T *c10_identifier);
static uint8_T c10_g_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void init_dsm_address_info(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc10_Aufgabe_4_Loesung(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_is_active_c10_Aufgabe_4_Loesung = 0U;
}

static void initialize_params_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c10_Aufgabe_4_Loesung(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c10_Aufgabe_4_Loesung(SFc10_Aufgabe_4_LoesungInstanceStruct *
  chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c10_update_debugger_state_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  const mxArray *c10_b_y = NULL;
  uint8_T c10_hoistedGlobal;
  uint8_T c10_u;
  const mxArray *c10_c_y = NULL;
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(2, 1), false);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", *chartInstance->c10_UDPData, 3, 0U,
    1U, 0U, 1, 17), false);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_hoistedGlobal = chartInstance->c10_is_active_c10_Aufgabe_4_Loesung;
  c10_u = c10_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  uint8_T c10_uv0[17];
  int32_T c10_i0;
  chartInstance->c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("UDPData", c10_u,
    0)), "UDPData", c10_uv0);
  for (c10_i0 = 0; c10_i0 < 17; c10_i0++) {
    (*chartInstance->c10_UDPData)[c10_i0] = c10_uv0[c10_i0];
  }

  chartInstance->c10_is_active_c10_Aufgabe_4_Loesung = c10_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c10_Aufgabe_4_Loesung",
       c10_u, 1)), "is_active_c10_Aufgabe_4_Loesung");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_Aufgabe_4_Loesung(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_Aufgabe_4_Loesung(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance)
{
  int32_T c10_i1;
  real_T c10_hoistedGlobal;
  real_T c10_b_hoistedGlobal;
  real_T c10_c_hoistedGlobal;
  real_T c10_b_DataX;
  real_T c10_b_DataY;
  real_T c10_b_DataZ;
  int32_T c10_i2;
  uint8_T c10_b_TnName[5];
  uint32_T c10_debug_family_var_map[10];
  uint8_T c10_tx[4];
  uint8_T c10_ty[4];
  uint8_T c10_tz[4];
  real_T c10_nargin = 4.0;
  real_T c10_nargout = 1.0;
  uint8_T c10_b_UDPData[17];
  uint8_T c10_uv1[4];
  int32_T c10_i3;
  int32_T c10_i4;
  int32_T c10_i5;
  int32_T c10_i6;
  int32_T c10_i7;
  int32_T c10_i8;
  int32_T c10_i9;
  int32_T c10_i10;
  int32_T c10_i11;
  int32_T c10_i12;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  for (c10_i1 = 0; c10_i1 < 5; c10_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c10_TnName)[c10_i1], 3U, 1U,
                          0U, chartInstance->c10_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c10_DataZ, 2U, 1U, 0U,
                        chartInstance->c10_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c10_DataY, 1U, 1U, 0U,
                        chartInstance->c10_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c10_DataX, 0U, 1U, 0U,
                        chartInstance->c10_sfEvent, false);
  chartInstance->c10_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  c10_hoistedGlobal = *chartInstance->c10_DataX;
  c10_b_hoistedGlobal = *chartInstance->c10_DataY;
  c10_c_hoistedGlobal = *chartInstance->c10_DataZ;
  c10_b_DataX = c10_hoistedGlobal;
  c10_b_DataY = c10_b_hoistedGlobal;
  c10_b_DataZ = c10_c_hoistedGlobal;
  for (c10_i2 = 0; c10_i2 < 5; c10_i2++) {
    c10_b_TnName[c10_i2] = (*chartInstance->c10_TnName)[c10_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tx, 0U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_ty, 1U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tz, 2U, c10_d_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 3U, c10_c_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 4U, c10_c_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_DataX, 5U, c10_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_DataY, 6U, c10_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_DataZ, 7U, c10_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_b_TnName, 8U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_b_UDPData, 9U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 2);
  c10_typecast(chartInstance, (real32_T)c10_b_DataX, c10_uv1);
  for (c10_i3 = 0; c10_i3 < 4; c10_i3++) {
    c10_tx[c10_i3] = c10_uv1[c10_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 3);
  c10_typecast(chartInstance, (real32_T)c10_b_DataY, c10_uv1);
  for (c10_i4 = 0; c10_i4 < 4; c10_i4++) {
    c10_ty[c10_i4] = c10_uv1[c10_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_typecast(chartInstance, (real32_T)c10_b_DataZ, c10_uv1);
  for (c10_i5 = 0; c10_i5 < 4; c10_i5++) {
    c10_tz[c10_i5] = c10_uv1[c10_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 5);
  for (c10_i6 = 0; c10_i6 < 17; c10_i6++) {
    c10_b_UDPData[c10_i6] = 0U;
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i7 = 0; c10_i7 < 5; c10_i7++) {
    c10_b_UDPData[c10_i7] = c10_b_TnName[c10_i7];
  }

  for (c10_i8 = 0; c10_i8 < 4; c10_i8++) {
    c10_b_UDPData[c10_i8 + 5] = c10_tx[c10_i8];
  }

  for (c10_i9 = 0; c10_i9 < 4; c10_i9++) {
    c10_b_UDPData[c10_i9 + 9] = c10_ty[c10_i9];
  }

  for (c10_i10 = 0; c10_i10 < 4; c10_i10++) {
    c10_b_UDPData[c10_i10 + 13] = c10_tz[c10_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c10_i11 = 0; c10_i11 < 17; c10_i11++) {
    (*chartInstance->c10_UDPData)[c10_i11] = c10_b_UDPData[c10_i11];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Aufgabe_4_LoesungMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c10_i12 = 0; c10_i12 < 17; c10_i12++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c10_UDPData)[c10_i12], 4U, 1U,
                          0U, chartInstance->c10_sfEvent, false);
  }
}

static void mdl_start_c10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc10_Aufgabe_4_Loesung
  (SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber)
{
  (void)c10_machineNumber;
  (void)c10_chartNumber;
  (void)c10_instanceNumber;
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i13;
  uint8_T c10_u[17];
  const mxArray *c10_y = NULL;
  SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc10_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i13 = 0; c10_i13 < 17; c10_i13++) {
    c10_u[c10_i13] = (*(uint8_T (*)[17])c10_inData)[c10_i13];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 3, 0U, 1U, 0U, 1, 17), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_b_UDPData, const char_T *c10_identifier,
  uint8_T c10_y[17])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_thisId.bParentIsCell = false;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_UDPData), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_b_UDPData);
}

static void c10_b_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  uint8_T c10_y[17])
{
  uint8_T c10_uv2[17];
  int32_T c10_i14;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_uv2, 1, 3, 0U, 1, 0U, 1, 17);
  for (c10_i14 = 0; c10_i14 < 17; c10_i14++) {
    c10_y[c10_i14] = c10_uv2[c10_i14];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_UDPData;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  uint8_T c10_y[17];
  int32_T c10_i15;
  SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc10_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c10_b_UDPData = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_thisId.bParentIsCell = false;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_UDPData), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_b_UDPData);
  for (c10_i15 = 0; c10_i15 < 17; c10_i15++) {
    (*(uint8_T (*)[17])c10_outData)[c10_i15] = c10_y[c10_i15];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i16;
  uint8_T c10_u[5];
  const mxArray *c10_y = NULL;
  SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc10_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i16 = 0; c10_i16 < 5; c10_i16++) {
    c10_u[c10_i16] = (*(uint8_T (*)[5])c10_inData)[c10_i16];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 3, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc10_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static real_T c10_c_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_nargout;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc10_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c10_nargout = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_thisId.bParentIsCell = false;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nargout),
    &c10_thisId);
  sf_mex_destroy(&c10_nargout);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i17;
  uint8_T c10_u[4];
  const mxArray *c10_y = NULL;
  SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc10_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i17 = 0; c10_i17 < 4; c10_i17++) {
    c10_u[c10_i17] = (*(uint8_T (*)[4])c10_inData)[c10_i17];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 3, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_d_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  uint8_T c10_y[4])
{
  uint8_T c10_uv3[4];
  int32_T c10_i18;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_uv3, 1, 3, 0U, 1, 0U, 1, 4);
  for (c10_i18 = 0; c10_i18 < 4; c10_i18++) {
    c10_y[c10_i18] = c10_uv3[c10_i18];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_tz;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  uint8_T c10_y[4];
  int32_T c10_i19;
  SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc10_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c10_tz = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_thisId.bParentIsCell = false;
  c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_tz), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_tz);
  for (c10_i19 = 0; c10_i19 < 4; c10_i19++) {
    (*(uint8_T (*)[4])c10_outData)[c10_i19] = c10_y[c10_i19];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_Aufgabe_4_Loesung_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c10_nameCaptureInfo;
}

static void c10_typecast(SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance,
  real32_T c10_x, uint8_T c10_y[4])
{
  (void)chartInstance;
  memcpy(&c10_y[0], &c10_x, (size_t)4 * sizeof(uint8_T));
}

static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc10_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int32_T c10_e_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i20;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i20, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i20;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc10_Aufgabe_4_LoesungInstanceStruct *)chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_thisId.bParentIsCell = false;
  c10_y = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_f_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_Aufgabe_4_Loesung, const
  char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_thisId.bParentIsCell = false;
  c10_y = c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_Aufgabe_4_Loesung), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_Aufgabe_4_Loesung);
  return c10_y;
}

static uint8_T c10_g_emlrt_marshallIn(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void init_dsm_address_info(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc10_Aufgabe_4_LoesungInstanceStruct
  *chartInstance)
{
  chartInstance->c10_DataX = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c10_DataY = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c10_DataZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c10_UDPData = (uint8_T (*)[17])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c10_TnName = (uint8_T (*)[5])ssGetInputPortSignal_wrapper
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

void sf_c10_Aufgabe_4_Loesung_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(303288308U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(392705999U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(269099881U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4198165681U);
}

mxArray* sf_c10_Aufgabe_4_Loesung_get_post_codegen_info(void);
mxArray *sf_c10_Aufgabe_4_Loesung_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c10_Aufgabe_4_Loesung_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c10_Aufgabe_4_Loesung_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_Aufgabe_4_Loesung_jit_fallback_info(void)
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

mxArray *sf_c10_Aufgabe_4_Loesung_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c10_Aufgabe_4_Loesung_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c10_Aufgabe_4_Loesung(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"UDPData\",},{M[8],M[0],T\"is_active_c10_Aufgabe_4_Loesung\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_Aufgabe_4_Loesung_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance =
      (SFc10_Aufgabe_4_LoesungInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Aufgabe_4_LoesungMachineNumber_,
           10,
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
          (MexFcnForType)c10_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 17U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
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
    SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance =
      (SFc10_Aufgabe_4_LoesungInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c10_DataX);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c10_DataY);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c10_DataZ);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c10_UDPData);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c10_TnName);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s6nktavy32B5qO34MiW1XsD";
}

static void sf_opaque_initialize_c10_Aufgabe_4_Loesung(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_Aufgabe_4_Loesung((SFc10_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar);
  initialize_c10_Aufgabe_4_Loesung((SFc10_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c10_Aufgabe_4_Loesung(void *chartInstanceVar)
{
  enable_c10_Aufgabe_4_Loesung((SFc10_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c10_Aufgabe_4_Loesung(void *chartInstanceVar)
{
  disable_c10_Aufgabe_4_Loesung((SFc10_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c10_Aufgabe_4_Loesung(void *chartInstanceVar)
{
  sf_gateway_c10_Aufgabe_4_Loesung((SFc10_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c10_Aufgabe_4_Loesung(SimStruct* S)
{
  return get_sim_state_c10_Aufgabe_4_Loesung
    ((SFc10_Aufgabe_4_LoesungInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c10_Aufgabe_4_Loesung(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c10_Aufgabe_4_Loesung((SFc10_Aufgabe_4_LoesungInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c10_Aufgabe_4_Loesung(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_Aufgabe_4_LoesungInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Aufgabe_4_Loesung_optimization_info();
    }

    finalize_c10_Aufgabe_4_Loesung((SFc10_Aufgabe_4_LoesungInstanceStruct*)
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
  initSimStructsc10_Aufgabe_4_Loesung((SFc10_Aufgabe_4_LoesungInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_Aufgabe_4_Loesung(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_Aufgabe_4_Loesung
      ((SFc10_Aufgabe_4_LoesungInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c10_Aufgabe_4_Loesung(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Aufgabe_4_Loesung_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,10,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 10);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
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

static void mdlRTW_c10_Aufgabe_4_Loesung(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_Aufgabe_4_Loesung(SimStruct *S)
{
  SFc10_Aufgabe_4_LoesungInstanceStruct *chartInstance;
  chartInstance = (SFc10_Aufgabe_4_LoesungInstanceStruct *)utMalloc(sizeof
    (SFc10_Aufgabe_4_LoesungInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc10_Aufgabe_4_LoesungInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_Aufgabe_4_Loesung;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_Aufgabe_4_Loesung;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_Aufgabe_4_Loesung;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_Aufgabe_4_Loesung;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_Aufgabe_4_Loesung;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_Aufgabe_4_Loesung;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_Aufgabe_4_Loesung;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_Aufgabe_4_Loesung;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_Aufgabe_4_Loesung;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_Aufgabe_4_Loesung;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_Aufgabe_4_Loesung;
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
  mdl_start_c10_Aufgabe_4_Loesung(chartInstance);
}

void c10_Aufgabe_4_Loesung_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_Aufgabe_4_Loesung(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_Aufgabe_4_Loesung(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_Aufgabe_4_Loesung(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_Aufgabe_4_Loesung_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
