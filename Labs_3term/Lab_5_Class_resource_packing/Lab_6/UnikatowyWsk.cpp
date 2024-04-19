#pragma once

#include <iostream>

template <typename T>
class UnikatowyWsk
{
	T* ptr;

public:

	UnikatowyWsk(T* p) : ptr(p) {}

	UnikatowyWsk() = default;

	~UnikatowyWsk()
	{
		delete ptr;
	}

	UnikatowyWsk(UnikatowyWsk&& other) noexcept : ptr(other.ptr)
	{
		other.ptr = nullptr;
	}

	UnikatowyWsk& operator =(UnikatowyWsk&& other) noexcept
	{
		if (this != &other)
		{
			delete ptr;
			ptr = other.ptr;
			other.ptr = nullptr;
		}
		return *this;
	}

	T& operator*() const
	{
		return *ptr;
	}

};