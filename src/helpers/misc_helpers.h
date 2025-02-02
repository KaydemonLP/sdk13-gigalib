#ifndef MISC_HELPERS_H
#define MISC_HELPERS_H

#ifdef _WIN32
#pragma once
#endif

#include <cbase.h>

// If you use $QUOTE in VPCs, linux needs stringified to get the value as a string, windows does not
#ifdef _WIN32
	#define VPC_QUOTE_STRINGIFY(x) x

#else
	#define VPC_QUOTE_STRINGIFY(x) V_STRINGIFY(x)
#endif


#include <inc_cpp_stdlib.h>

#include <obfuscate.h>
#include <vtf/vtf.h>
#include <netadr.h>
#include <inetchannelinfo.h>
#include <inetchannel.h>
#include <eiface.h>
#include <cdll_int.h>

#ifdef CLIENT_DLL
#include <cdll_client_int.h>
#include <icommandline.h>
#include <filesystem.h>

bool UTIL_CheckRealRemoteAddr(netadr_t netaddr);
bool UTIL_GetRealRemoteAddr(char* ipadr);
#endif // clientdll
bool UTIL_IsFakePlayer(CBasePlayer* inplayer);
bool UTIL_IsVTFValid(const char* fileloc);
void UTIL_AddrToString(void* inAddr, char outAddrStr[11]);


// https://stackoverflow.com/a/57346888
//
std::vector<std::string> UTIL_SplitSTDString(const std::string& i_str, const std::string& i_delim);
std::string UTIL_StripCharsFromSTDString(std::string i_str, char char_to_strip);
std::string& UTIL_ReplaceAll(std::string& context, std::string const& from, std::string const& to);

// https://stackoverflow.com/a/49066369
// Get time stamp in milliseconds.
uint64_t millis();
// Get time stamp in microseconds.
uint64_t micros();
// Get time stamp in nanoseconds.
uint64_t nanos();

#ifdef CLIENT_DLL
void UTIL_GetMap(char mapname[128]);
#endif
#endif

#ifdef GNUC
#undef offsetof
//#define offsetof( type, var ) __builtin_offsetof( type, var )
#define offsetof(s,m)	(size_t)&(((s *)0)->m)
#else
#undef offsetof
#define offsetof(s,m)	(size_t)&(((s *)0)->m)
#endif
