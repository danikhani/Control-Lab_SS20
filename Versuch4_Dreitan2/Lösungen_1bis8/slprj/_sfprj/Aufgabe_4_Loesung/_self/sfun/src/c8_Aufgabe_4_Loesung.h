#ifndef __c8_Aufgabe_4_Loesung_h__
#define __c8_Aufgabe_4_Loesung_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stddef.h>
#ifndef typedef_SFc8_Aufgabe_4_LoesungInstanceStruct
#define typedef_SFc8_Aufgabe_4_LoesungInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  boolean_T c8_isStable;
  boolean_T c8_doneDoubleBufferReInit;
  uint8_T c8_is_active_c8_Aufgabe_4_Loesung;
  real_T *c8_DataX;
  real_T *c8_DataY;
  real_T *c8_DataZ;
  uint8_T (*c8_UDPData)[17];
  uint8_T (*c8_TnName)[5];
} SFc8_Aufgabe_4_LoesungInstanceStruct;

#endif                                 /*typedef_SFc8_Aufgabe_4_LoesungInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_Aufgabe_4_Loesung_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c8_Aufgabe_4_Loesung_get_check_sum(mxArray *plhs[]);
extern void c8_Aufgabe_4_Loesung_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
