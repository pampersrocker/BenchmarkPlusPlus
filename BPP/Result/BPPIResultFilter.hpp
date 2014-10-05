#pragma once
#ifndef BPPIResultFilter_h__
#define BPPIResultFilter_h__

namespace bpp
{

	class IResultFilter
	{
	public:

		inline virtual void PrepareFilter( const ResultContainer& container ) {};

		virtual bool FilterResult( const Result& result ) = 0;

	private:

	};

}
#endif // BPPIResultFilter_h__
