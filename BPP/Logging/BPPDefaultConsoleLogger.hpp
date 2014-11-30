#pragma once
#ifndef BPPDefaultConsoleLogger_h__
#define BPPDefaultConsoleLogger_h__
#include "BPPILogger.hpp"
namespace bpp
{
	class ResultScenario;

	class DefaultConsoleLogger : public ILogger
	{
	public:

		DefaultConsoleLogger();

		virtual void Log( const std::vector< ResultScenario* >& scopes ) override;

		inline bool UseColor() const { return m_UseColor; }
		inline void UseColor(bool val) { m_UseColor = val; }


	private:

		enum LogColors
		{
			Normal,
			Fastest,
			Slowest,
			NUM
		};

		HANDLE hstdout;
		std::vector<WORD> m_Colors;
		bool m_UseColor;
	};
}

#include "BPPDefaultConsoleLogger.inl"

#endif // BPPDefaultConsoleLogger_h__
