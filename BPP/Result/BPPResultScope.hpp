#pragma once
#ifndef BPPResultScope_h__
#define BPPResultScope_h__
#include <vector>
namespace bpp
{
	class ResultScope
	{
	public:
		ResultScope(const std::string& scopeName);
		~ResultScope();

		void AddResult( const Result& result );

		const std::vector<Result>& Results( void ) const;

		const std::string& ScopeName() const;

	private:

		std::string m_ScopeName;
		
		std::vector<Result> m_Results;
	};


}

#include "BPPResultScope.inl"

#endif // BPPResultScope_h__
