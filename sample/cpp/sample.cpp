//sample1
#include <iostream>

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


#include "lua_tinker.h"

int cpp_func(int arg1, int arg2)
{
	return arg1 + arg2;
}

int main()
{
	lua_State* L = lua_open();

	luaopen_base(L);

	lua_tinker::def(L, "cpp_func", cpp_func);

	lua_tinker::dofile(L, "../lua/sample1.lua");

	int result = lua_tinker::call<int>(L, "lua_func", 3, 4);

	printf("lua_func(3,4) = %d\n", result);

	lua_close(L);

	system("pause");

	return 0;
}

//sample2
//#include <iostream>
//
//extern "C" 
//{
//#include "lua.h"
//#include "lualib.h"
//#include "lauxlib.h"
//};
//
//#include "lua_tinker.h"
//
//static int cpp_int = 100;
//
//int main()
//{
//	lua_State* L = lua_open();
//
//	luaopen_base(L);
//
//	lua_tinker::set(L, "cpp_int", cpp_int);
//
//	lua_tinker::set(L, "cpp_int_ptr", &cpp_int);
//
//	int * abc = &cpp_int;
//	int * def= lua_tinker::get<int *>(L, "cpp_int_ptr");
//	printf("abc = %d,def=%d \n",*abc ,*def);
//
//	lua_tinker::dofile(L, "../lua/sample2.lua");
//
//	int lua_int = lua_tinker::get<int>(L, "lua_int");
//
//	printf("lua_int = %d\n", lua_int);
//
//	printf("cpp_int = %d\n", cpp_int);
//
//	lua_close(L);
//
//	system("pause");
//
//	return 0;
//}

//sample3
//extern "C"
//{
//#include "lua.h"
//#include "lualib.h"
//#include "lauxlib.h"
//};
//
//#include "lua_tinker.h"
//
//
//struct TestA
//{
//	int a = 0;
//};
//
//struct A
//{
//	A(int v) :
//value(v) 
//{
//}
//int value;
//};
//
//struct base
//{
//	base() {}
//
//	const char *is_base()
//	{
//		return "this is base";
//	}
//};
//
//class test : public base
//{
//public:
//	test(int val) : _test(val) {}
//	~test() {}
//
//	const char *is_test()
//	{
//		return "this is test";
//	}
//
//	void ret_void() 
//	{
//	}
//
//	int ret_int()
//	{
//		return _test;
//	}
//	int ret_mul(int m) const
//	{
//		return _test * m;
//	}
//	A get()
//	{
//		return A(_test);
//	}
//	void set(A a)
//	{
//		_test = a.value;
//	}
//
//	int _test;
//
//	TestA _testa;
//};
//
//test g_test(11);
//
//int main()
//{
//	lua_State *L = lua_open();
//
//	luaopen_base(L);
//
//	luaopen_string(L);
//
//	lua_tinker::class_add<TestA>(L, "TestA");
//	lua_tinker::class_con<TestA>(L, lua_tinker::constructor<TestA>);
//
//	TestA *ptr_a = new TestA();
//
//	lua_tinker::set(L, "ptr_a", ptr_a);
//
//	lua_tinker::class_add<base>(L, "base");
//
//	lua_tinker::class_def<base>(L, "is_base", &base::is_base);
//
//	lua_tinker::class_add<test>(L, "test");
//
//	lua_tinker::class_inh<test, base>(L);
//
//	lua_tinker::class_con<test>(L, lua_tinker::constructor<test, int>);
//
//	lua_tinker::class_def<test>(L, "is_test", &test::is_test);
//	lua_tinker::class_def<test>(L, "ret_void", &test::ret_void);
//	lua_tinker::class_def<test>(L, "ret_int", &test::ret_int);
//	lua_tinker::class_def<test>(L, "ret_mul", &test::ret_mul);
//	lua_tinker::class_def<test>(L, "get", &test::get);
//	lua_tinker::class_def<test>(L, "set", &test::set);
//	lua_tinker::class_mem<test>(L, "_test", &test::_test);
//	lua_tinker::class_mem<test>(L, "_testa", &test::_testa);
//
//	lua_tinker::set(L, "g_test", &g_test);
//
//	lua_tinker::dofile(L, "sample3.lua");
//
//	lua_close(L);
//
//	return 0;
//}

//sample4
//extern "C" 
//{
//#include "lua.h"
//#include "lualib.h"
//#include "lauxlib.h"
//};
//
//#include "lua_tinker.h"
//
//int main()
//{
//	lua_State* L = lua_open();
//
//	luaopen_base(L);
//
//	lua_tinker::table haha(L, "haha");
//
//	haha.set("value", 1);
//
//	haha.set("inside", lua_tinker::table(L));
//
//	lua_tinker::table inside = haha.get<lua_tinker::table>("inside");
//
//	inside.set("value", 2);
//
//	lua_tinker::dofile(L, "sample4.lua");
//
//	const char* test = haha.get<const char*>("test");
//	printf("haha.test = %s\n", test);
//
//	lua_tinker::table temp(L);
//
//	temp.set("name", "local table !!");
//
//	lua_tinker::call<void>(L, "print_table", temp);
//
//	lua_tinker::table ret = lua_tinker::call<lua_tinker::table>(L, "return_table", "give me a table !!");
//	printf("ret.name =\t%s\n", ret.get<const char*>("name"));
//
//	lua_close(L);
//
//	return 0;
//}

// sample5.cpp : Defines the entry point for the console application.
//extern "C" 
//{
//#include "lua.h"
//#include "lualib.h"
//#include "lauxlib.h"
//};
//
//#include "lua_tinker.h"
//
//void show_error(const char* error)
//{
//	printf("_ALERT -> %s\n", error);
//}
//
//int main()
//{
//	lua_State* L = lua_open();
//
//	luaopen_base(L);
//
//	printf("%s\n","-------------------------- current stack");
//	lua_tinker::enum_stack(L);
//
//	lua_pushnumber(L, 1);
//
//	printf("%s\n","-------------------------- stack after push '1'");
//	lua_tinker::enum_stack(L);
//
//	lua_tinker::dofile(L, "sample5.lua");
//
//	printf("%s\n","-------------------------- calling test_error()");
//	lua_tinker::call<void>(L, "test_error");
//
//	printf("%s\n","-------------------------- calling test_error_3()");
//	lua_tinker::call<void>(L, "test_error_3");
//
//	lua_tinker::def(L, "_ALERT", show_error);
//
//	lua_tinker::call<void>(L, "_ALERT", "test !!!");
//
//	printf("%s\n","-------------------------- calling test_error()");
//	lua_tinker::call<void>(L, "test_error");
//
//	lua_close(L);
//
//	return 0;
//}
//

// sample6.cpp
//extern "C"
//{
//#include "lua.h"
//#include "lualib.h"
//#include "lauxlib.h"
//};
//
//#include "lua_tinker.h"
//int TestFunc(lua_State *L)
//{
//	printf("# TestFunc is invoke.\n");
//	return lua_yield(L, 0);
//}
//
//int TestFunc2(lua_State *L, float a)
//{
//	printf("# TestFunc2(L,%f) is invoke.\n", a);
//	return lua_yield(L, 0);
//}
//
//class TestClass
//{
//public:
//	int TestFunc(lua_State *L)
//	{
//		printf("# TestClass::TestFunc is invoke.\n");
//		return lua_yield(L, 0);
//	}
//
//	int TestFunc2(lua_State *L, float a)
//	{
//		printf("# TestClass::TestFunc2(L,%f) is invoke.\n", a);
//		return lua_yield(L, 0);
//	}
//};
//
//int main()
//{
//	lua_State *L = lua_open();
//
//	luaopen_base(L);
//
//	luaopen_string(L);
//
//	lua_tinker::def(L, "TestFunc", &TestFunc);
//	lua_tinker::def(L, "TestFunc2", &TestFunc2);
//
//	lua_tinker::class_add<TestClass>(L, "TestClass");
//
//	lua_tinker::class_def<TestClass>(L, "TestFunc", &TestClass::TestFunc);
//	lua_tinker::class_def<TestClass>(L, "TestFunc2", &TestClass::TestFunc2);
//
//	TestClass g_test;
//	lua_tinker::set(L, "g_test", &g_test);
//
//	lua_tinker::dofile(L, "sample6.lua");
//
//	lua_State *L1 = lua_newthread(L);
//	lua_pushstring(L1, "ThreadTest");
//	lua_gettable(L1, LUA_GLOBALSINDEX);
//
//	printf("L stack ========================================\n");
//	lua_tinker::enum_stack(L);
//	printf("L1 stack ========================================\n");
//	lua_tinker::enum_stack(L1);
//	printf("========================================\n");
//
//	printf("* lua_resume() to.. \n");
//	lua_resume(L1, 0);
//
//	printf("* lua_resume() to.. \n");
//	lua_resume(L1, 0);
//
//	printf("* lua_resume() to.. \n");
//	lua_resume(L1, 0);
//
//	printf("* lua_resume() to.. \n");
//	lua_resume(L1, 0);
//
//	printf("* lua_resume() to.. \n");
//	lua_resume(L1, 0);
//
//	lua_close(L);
//
//	return 0;
//}
//

// sample7.cpp 
//extern "C"
//{
//#include "lua.h"
//#include "lualib.h"
//#include "lauxlib.h"
//};
//
//#include "lua_tinker.h"
//
//struct TestA
//{
//	TestA(int a) :a_(a)
//	{
//	}
//
//	int set(int a)
//	{
//		a_ = a;
//		return a_;
//	}
//	int a_;
//};
//
//int main()
//{
//	lua_State *L = lua_open();
//
//	luaopen_base(L);
//
//	luaopen_string(L);
//
//	lua_tinker::class_add<TestA>(L, "TestA");
//	lua_tinker::class_def<TestA>(L, "set", &TestA::set);
//	lua_tinker::class_con<TestA>(L, lua_tinker::constructor<TestA, int>);
//	lua_tinker::class_mem<TestA>(L, "a_",&TestA::a_);
//
//
//	TestA *ptr_a = new TestA(100);
//	lua_tinker::set(L, "ptr_a", ptr_a);
//
//	TestA val_a(200);
//	lua_tinker::set(L, "val_a", val_a);
//
//	TestA temp_a(300);
//	TestA &ref_a = temp_a;
//
//	lua_tinker::set<TestA &>(L, "ref_a", ref_a);
//
//	lua_tinker::dofile(L, "sample7.lua");
//
//	printf("ptr_a->a_ = %d\n", ptr_a->a_);
//	printf("val_a.a_ = %d\n", val_a.a_);
//	printf("ref_a.a_ = %d\n", ref_a.a_);
//
//	lua_close(L);
//
//	return 0;
//}
//

// sample8.cpp
//extern "C"
//{
//#include "lua.h"
//#include "lualib.h"
//#include "lauxlib.h"
//};
//
//#include "lua_tinker.h"
//
//
//struct TestA
//{
//	int a = 0;
//};
//
//struct A
//{
//	A(int v) :
//value(v) 
//{
//}
//int value;
//};
//
//struct base
//{
//	base() {}
//
//	const char *is_base()
//	{
//		return "this is base";
//	}
//};
//
//class test : public base
//{
//public:
//	test(int val) : _test(val) {}
//	~test() {}
//
//	const char *is_test()
//	{
//		return "this is test";
//	}
//
//	void ret_void()
//	{
//	}
//
//	int ret_int()
//	{
//		return _test;
//	}
//	int ret_mul(int m) const
//	{
//		return _test * m;
//	}
//	A get()
//	{
//		return A(_test);
//	}
//	void set(A a)
//	{
//		_test = a.value;
//	}
//
//	int _test;
//
//	TestA _testa;
//};
//
//test g_test(11);
//
//int main()
//{
//	lua_State *L = lua_open();
//	luaopen_base(L);
//	luaopen_string(L);
//
//	lua_tinker::class_add<TestA>(L, "TestA");
//	lua_tinker::class_con<TestA>(L, lua_tinker::constructor<TestA>);
//
//	lua_tinker::class_add<base>(L, "base");
//
//	lua_tinker::class_def<base>(L, "is_base", &base::is_base);
//
//	lua_tinker::class_add<test>(L, "test");
//
//	lua_tinker::class_inh<test, base>(L);
//
//	lua_tinker::class_con<test>(L, lua_tinker::constructor<test, int>);
//
//	lua_tinker::class_def<test>(L, "is_test", &test::is_test);
//	lua_tinker::class_def<test>(L, "ret_void", &test::ret_void);
//	lua_tinker::class_def<test>(L, "ret_int", &test::ret_int);
//	lua_tinker::class_def<test>(L, "ret_mul", &test::ret_mul);
//	lua_tinker::class_def<test>(L, "get", &test::get);
//	lua_tinker::class_def<test>(L, "set", &test::set);
//	lua_tinker::class_mem<test>(L, "_test", &test::_test);
//	lua_tinker::class_mem<test>(L, "_testa", &test::_testa);
//
//	lua_tinker::set(L, "g_test", &g_test);
//
//	lua_tinker::dofile(L, "sample3.lua");
//
//	lua_close(L);
//
//	return 0;
//}


