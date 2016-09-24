#include <Stack.h>
#include <catch.hpp>


SCENARIO("Stack count", "[count]"){
	bool mark=false;
	stack<int> st;
	if ((st.count()==0))
	{
		mark=true;
	}
	st.push(1);
	if ((st.count()==1))
	{
		mark=true;
	}
	REQUIRE(mark);
}

SCENARIO("Stack push", "[push]"){
	bool mark=false;
	stack<int> st;
	st.push(1);
	if ((st.count()==1)&&(st.top()==1))
	{
		mark=true;
	}
	REQUIRE(mark);
}

SCENARIO("Stack pop", "[pop]"){
	bool mark=false;
	stack<int> st;
	st.push(123);
	st.pop();
	if (st.count()==0)
	{
		mark=true;
	}
	REQUIRE(mark);
}

SCENARIO("Stack top", "[top]"){
	bool mark=false;
	stack<int> st;
	st.push(11);
	st.push(22);
	int v=st.top();
	if (v==22)
	{
		mark=true;
	}
	REQUIRE(mark);
}

SCENARIO("Assign", "[assign]"){
	bool mark=false;
	stack<int> st;
	st.push(10);
	stack<int> st_;
	st_=st;
	if ((st_.count()==1)&(st_.top()==10))
	{
		mark=true;
	}
	REQUIRE(mark);
}

SCENARIO("Copy","[copy]"){
	bool mark=false;
	stack<int> st;
	st.push(10);
	stack<int> st_=st;
	if ((st_.count()==1)&(st_.top()==10))
	{
		mark=true;
	}
	REQUIRE(mark);
}
