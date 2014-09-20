#pragma once
#ifndef BPPDefaultConsoleLogger_h__
#define BPPDefaultConsoleLogger_h__
#include "BPPILogger.hpp"
namespace bpp
{
	class ResultScope;

	class DefaultConsoleLogger : public ILogger
	{
	public:

		virtual void Log( const std::vector< ResultScope* >& scopes ) override;

	private:

	};
}

#include "BPPDefaultConsoleLogger.inl"

#endif // BPPDefaultConsoleLogger_h__
