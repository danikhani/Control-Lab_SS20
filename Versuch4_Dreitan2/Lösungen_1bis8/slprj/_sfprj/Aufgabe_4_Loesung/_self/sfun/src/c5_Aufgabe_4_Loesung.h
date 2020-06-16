#ifndef __c5_Aufgabe_4_Loesung_h__
#define __c5_Aufgabe_4_Loesung_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stddef.h>
#ifndef typedef_SFc5_Aufgabe_4_LoesungInstanceStruct
#define typedef_SFc5_Aufgabe_4_LoesungInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_Aufgabe_4_Loesung;
  real_T *c5_DataX;
  real_T *c5_DataY;
  real_T *c5_DataZ;
  uint8_T (*c5_UDPData)[17];
  uint8_T (*c5_TnName)[5];
} SFc5_Aufgabe_4_LoesungInstanceStruct;

#endif                                 /*typedef_SFc5_Aufgabe_4_LoesungInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_Aufgabe_4_Loesung_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c5_Aufgabe_4_Loesung_get_check_sum(mxArray *plhs[]);
extern void c5_Aufgabe_4_Loesung_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
