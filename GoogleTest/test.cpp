#include "pch.h"
#include <functional>
#include "..\Dependencies\Include\tk_utilities\tk_events\EventDispatcher.h"
#include "..\Dependencies\Include\tk_utilities\tk_events\Delegate.h"

class ComplexKeyDispatcher : public tk_events::EventDispatcher<tk_events::Delegate<void, int, const char*>, const char*, int, const char*>
{
protected:
	const char* assembleKey(int x, const char* c) override
	{
		return c;
	}
};

class TestDispatcher : public tk_events::EventDispatcher<tk_events::Delegate<void>, const char*>
{
public:
	static constexpr const char* TEST_EVENT = "testEvent";
};

bool func_test = false;

void foo()
{
	func_test = true;
}

void bar(int x, const char* c)
{
	EXPECT_EQ(x, 100);
}

struct EventDispatcherTest : testing::Test
{
	class EventListener
	{
	public:
		bool success = false;

		void foo_method()
		{
			success = true;
		}

		void bar_method(int x, const char*)
		{
			EXPECT_EQ(x, 100);
		}
	};

	std::unique_ptr<ComplexKeyDispatcher> ckd;
	std::unique_ptr<TestDispatcher> td;
	std::unique_ptr<EventListener> el;

	EventDispatcherTest()
	{
		ckd = std::make_unique<ComplexKeyDispatcher>();
		td = std::make_unique<TestDispatcher>();
		el = std::make_unique<EventListener>();
		func_test = false;
	}
};

TEST_F(EventDispatcherTest, addEventListener_Function_Simple_Key_OK)
{
	td.get()->addEventListener(tk_events::Delegate<void>(&foo), TestDispatcher::TEST_EVENT);
}

TEST_F(EventDispatcherTest, addEventListener_Function_Complex_Key_OK)
{
	ckd.get()->addEventListener(tk_events::Delegate<void, int, const char*>(&bar), 0, "key");
}

TEST_F(EventDispatcherTest, addEventListener_Method_Simple_Key_OK)
{
	td.get()->addEventListener(tk_events::Delegate<void>(&EventListener::foo_method, el.get()), TestDispatcher::TEST_EVENT);
}

TEST_F(EventDispatcherTest, addEventListener_Method_Complex_Key_OK)
{
	ckd.get()->addEventListener(tk_events::Delegate<void, int, const char*>(&EventListener::bar_method, el.get()), 0, "key");
}

TEST_F(EventDispatcherTest, dispatchEvent_Function_No_Values_OK)
{
	td.get()->addEventListener(tk_events::Delegate<void>(&foo), TestDispatcher::TEST_EVENT);
	td.get()->dispatchEvent({}, TestDispatcher::TEST_EVENT);
	EXPECT_TRUE(func_test);
}

TEST_F(EventDispatcherTest, dispatchEvent_Function_Several_Values_OK)
{
	ckd.get()->addEventListener(tk_events::Delegate<void, int, const char*>(&bar), 0, "key");
	ckd.get()->dispatchEvent({ 100, "arg" }, 0, "key");
}

TEST_F(EventDispatcherTest, dispatchEvent_Method_No_Values_OK)
{
	td.get()->addEventListener(tk_events::Delegate<void>(&EventListener::foo_method, el.get()), TestDispatcher::TEST_EVENT);
	td.get()->dispatchEvent({}, TestDispatcher::TEST_EVENT);
	EXPECT_TRUE(el.get()->success);
}

TEST_F(EventDispatcherTest, dispatchEvent_Method_Several_Values_OK)
{
	ckd.get()->addEventListener(tk_events::Delegate<void, int, const char*>(&EventListener::bar_method, el.get()), 0, "key");
	ckd.get()->dispatchEvent({ 100, "arg" }, 0, "key");
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}