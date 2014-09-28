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

		void AddResult( const ResultContainer& result );

		const std::vector<ResultContainer>& Results( void ) const;

		const std::string& ScopeName() const;

	private:

		std::string m_ScopeName;
		
		std::vector<ResultContainer> m_Results;
	};


}

#include "BPPResultScope.inl"

#endif // BPPResultScope_h__
