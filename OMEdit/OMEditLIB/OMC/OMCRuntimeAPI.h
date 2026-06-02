/*
 * Declarations for symbols implemented in libOpenModelicaCompiler (omcruntime).
 * On MSVC these must be imported from the DLL, not linked via OpenModelicaRuntimeC.lib.
 */
#ifndef OMEDIT_OMC_RUNTIME_API_H
#define OMEDIT_OMC_RUNTIME_API_H

#if defined(_MSC_VER)
#include <openmodelica.h>
#define OMEDIT_OMC_API DLLImport
#else
#define OMEDIT_OMC_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

OMEDIT_OMC_API const char* System_openModelicaPlatform(void);

#ifdef __cplusplus
}
#endif

#endif /* OMEDIT_OMC_RUNTIME_API_H */
