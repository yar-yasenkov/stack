#include <Stack.h>
#include <catch.hpp>


SCENARIO("Stack init", "[init"){
	bool mark=false;
	stack<int> st;
	if ((st.count()==0))
	{
		mark=true;
	}
	REQUIRE(mark);
}

SCENARIO("Stack push", "[push]"){
	bool mark=false;
	stack<int> st;
	st.push(1);
	st.push(2);
	if ((st.count()==2)&&(st.pop()==2)&&(st.pop()==1))
	{
		mark=true;
	}
	REQUIRE(mark);
}

SCENARIO("Stack pop", "[pop]"){
	bool mark=false;
	stack<int> st;
	st.push(123);
	if (st.pop()==123)
	{
		mark=true;
	}
}
