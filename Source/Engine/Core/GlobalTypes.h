#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

typedef unsigned int uint;

struct NullPointer
{
	template<class T>
	inline operator boost::weak_ptr<T>() const { return boost::weak_ptr<T>(); }

	template<class T>
	inline operator boost::shared_ptr<T>() const { return boost::shared_ptr<T>(); }

	template<class T>
	inline operator T* () const { return 0; }
};
static NullPointer nullPtr;