#pragma once

class lessThan
{
public:
	lessThan() {}

	template< class T >
	static bool compare(T a, T b)
	{
		return a < b;
	}
};

class lessThanDeref
{
public:
	lessThanDeref() {}
	template<class T>
	static bool compare(T a, T b)
	{
		return *a < *b;
	}
};

class greaterThan
{
public:
	greaterThan() {}

	template < class T >
	static bool compare(T a, T b)
	{
		return a > b;
	}
};

class greaterThanDeref
{
public:
	greaterThanDeref() {}

	template<class T>
	static bool compare(T a, T b)
	{
		return *a > *b;
	}
};

class equalTo
{
public:
	equalTo() {}

	template <class T>
	static bool compare(T a, T b)
	{
		return a == b;
	}
};