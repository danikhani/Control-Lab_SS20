#ifndef __c10_Aufgabe_4_Loesung_h__
#define __c10_Aufgabe_4_Loesung_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stddef.h>
#ifndef typedef_SFc10_Aufgabe_4_LoesungInstanceStruct
#define typedef_SFc10_Aufgabe_4_LoesungInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c10_sfEvent;
  boolean_T c10_isStable;
  boolean_T c10_doneDoubleBufferReInit;
  uint8_T c10_is_active_c10_Aufgabe_4_Loesung;
  real_T *c10_DataX;
  real_T *c10_DataY;
  real_T *c10_DataZ;
  uint8_T (*c10_UDPData)[17];
  uint8_T (*c10_TnName)[5];
} SFc10_Aufgabe_4_LoesungInstanceStruct;

#endif                                 /*typedef_SFc10_Aufgabe_4_LoesungInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c10_Aufgabe_4_Loesung_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c10_Aufgabe_4_Loesung_get_check_sum(mxArray *plhs[]);
extern void c10_Aufgabe_4_Loesung_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
