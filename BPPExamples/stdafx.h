// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <string>

class DummyScenario
{
public:
	inline DummyScenario( const std::string& name ) : m_Name( name )
	{
	}

	inline std::string ToString() const
	{
		return m_Name;
	}


private:

	std::string m_Name;

};
#define BPP_CUSTOM_SCENARIO ::DummyScenario
#include "bpp.hpp"



// TODO: reference additional headers your program requires here
