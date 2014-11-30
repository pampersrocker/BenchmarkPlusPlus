#pragma once
#ifndef bpp_h__
#define bpp_h__

#include <Windows.h>

#include "Factory/BPPDummyScenario.hpp"

namespace bpp
{
#ifdef BPP_CUSTOM_SCENARIO
	typedef BPP_CUSTOM_SCENARIO BenchmarkScenario;
#else
	typedef ::bpp::BenchmarkDummyScenario BenchmarkScenario;
#endif // BPP_CUSTOM_SCENARIO
}

#include "Factory/BPPFactoryItem.hpp"
#include "Factory/BPPBenchmarkableItem.hpp"
#include "Factory/BPPFactoryContainer.hpp"
#include "Factory/BPPScope.hpp"
#include "Chrono/BPPTimeSpan.hpp"
#include "Chrono/BPPTimePoint.hpp"
#include "Result/BPPResult.hpp"
#include "Result/BPPResultContainer.hpp"
#include "Result/BPPIResultFilter.hpp"
#include "Result/BPPResultScope.hpp"
#include "Result/BPPResultScenario.hpp"
#include "Logging/BPPILogger.hpp"
#include "BPPBenchmarker.hpp"
#include "BPPMacros.hpp"

#endif // bpp_h__
