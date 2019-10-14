/**
 * @package clish
 * @file    ClishRaptor.h
 * @brief   
 */

#ifndef CLISH_RAPTOR_H_
#define CLISH_RAPTOR_H_

#include "lub/c_decl.h"
_BEGIN_C_DECL
#include "clish/shell.h"
#include "lub/string.h"
#include "lub/db.h"
_END_C_DECL

extern "C" int clish_show(void *clish_context,
                 const char *script,
                 char **out);

#endif /* CLISH_RAPTOR_H_*/
