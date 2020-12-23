#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{

	TEST_CLASS(DelegateTestClass)
	{
	public:

		class test_class
		{
		public:
			int test_res;

			static void test_func(test_class test, int a)
			{
				test.test_res += a;
			}

			void test_method(int a)
			{
				test_res += a;
			}
		};

		TEST_METHOD(call_Function_Delegate_OK)
		{
			test_class test;
			tk_events::Delegate test_delegate(&test_class::test_func);
			test_delegate({ test, 1 });
			Assert::AreEqual(test.test_res, 1);
		}

		TEST_METHOD(call_Method_Delegate_OK)
		{
			test_class test;
			tk_events::Delegate test_delegate(&test_class::test_method, &test);
			test_delegate({ 1 });
			Assert::AreEqual(test.test_res, 1);
		}
	};

	TEST_CLASS(EventDispatcherUnitTest)
	{
	public:
		
		TEST_METHOD(addEventListener_Function_Delegate_OK)
		{

		}

		TEST_METHOD(addEventListener_Method_Delegate_OK)
		{
		}

		TEST_METHOD(removeEventListener_Function_Delegate_OK)
		{
		}

		TEST_METHOD(removeEventListener_Method_Delegate_OK)
		{
		}

		TEST_METHOD(removeEventListener_Function_Delegate_Delegate_Does_Not_Exist)
		{
		}

		TEST_METHOD(removeEventListener_Method_Delegate_Delegate_Does_Not_Exist)
		{
		}
	};
}
