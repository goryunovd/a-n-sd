#include "pch.h"
#include "CppUnitTest.h"
#include "..\laba1a'n'sd\Listclass.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		TEST_METHOD(Test_empty)
		{
			List list;
			Assert::IsTrue(list.isEmpty());
		}
		TEST_METHOD(Test_not_empty)
		{
			List list(1);
			Assert::IsFalse(list.isEmpty());
		}
		TEST_METHOD(Test_remove_empty)
		{
			List list(1);
			list.remove(0);
			Assert::IsTrue(list.isEmpty());
		}
		TEST_METHOD(Test_emptyreverse)
		{
			List list;
			list.reverse();
			Assert::IsTrue(list.isEmpty());
		}
		TEST_METHOD(Test_pushback)
		{
			List list(2);//2 0 1 2 3
			for (int i = 0; i < 4; i++)
			{
				list.push_back(i);
			}
			Assert::AreEqual(list.at(0), 2);
			Assert::AreEqual(list.at(1), 0);
			Assert::AreEqual(list.at(2), 1);
			Assert::AreEqual(list.at(3), 2);
			Assert::AreEqual(list.at(4), 3);
			List list2;
			list2.push_back(1);
			Assert::AreEqual(list2.at(0), 1);
		}
		TEST_METHOD(Test_pushfront)
		{
			List list(2);//3 2 1 0 2
			for (int i = 0; i < 4; i++)
			{
				list.push_front(i);
			}
			Assert::AreEqual(list.at(0), 3);
			Assert::AreEqual(list.at(1), 2);
			Assert::AreEqual(list.at(2), 1);
			Assert::AreEqual(list.at(3), 0);
			Assert::AreEqual(list.at(4), 2);
			List list2;
			list2.push_front(1);
			Assert::AreEqual(list2.at(0), 1);
		}
		TEST_METHOD(Test_popfront)
		{
			List list(1);
			list.pop_front();
			Assert::IsTrue(list.isEmpty());
			List list2;
			int size;
			for (int i = 0; i < 5; i++) { list2.push_back(i); } //0-1-2-3-4
			list2.pop_front();//1-2-3-4
			size = list2.get_size();
			Assert::AreEqual(size, 4);
			List list3;
			bool check = 1;
			try
			{
				list3.pop_front();
			}
			catch (std::runtime_error)
			{
				check = true;
			}
			Assert::IsTrue(check);
		}
		TEST_METHOD(Test_popback)
		{
			List list(1);
			list.pop_back();
			Assert::IsTrue(list.isEmpty());
			List list2; int size;
			for (int i = 0; i < 5; i++) { list2.push_back(i); } //0-1-2-3-4
			list2.pop_back();//0-1-2-3
			size = list2.get_size();
			Assert::AreEqual(size, 4);
			List list3;
			bool check = 1;
			try
			{
				list3.pop_back();
			}
			catch (std::runtime_error)
			{
				check = true;
			}
			Assert::IsTrue(check);
		}
		TEST_METHOD(Test_insert)
		{
			List list;
			list.insert(1, 0);
			Assert::AreEqual(list.at(0), 1);
			List list2;
			for (int i = 0; i < 4; i++) { list2.push_back(i + 1); }//1-2-3-4
			list2.insert(0, 0);
			Assert::AreEqual(list2.at(0), 0);
			Assert::AreEqual(list2.at(1), 1);
			Assert::AreEqual(list2.at(2), 2);
			Assert::AreEqual(list2.at(3), 3);
			Assert::AreEqual(list2.at(4), 4);
			List list3;
			for (int i = 0; i < 4; i++) { list3.push_back(i + 1); }//1-2-3-4
			list3.clear(); bool check = 1;
			try
			{
				list3.insert(3, 3);
			}
			catch (std::invalid_argument)
			{
				check = true;
			}
			Assert::IsTrue(check);
			list3.insert(54, 0);
			Assert::AreEqual(list3.at(0), 54);
		}
		TEST_METHOD(Test_at)
		{
			List list; bool check = 1;
			try
			{
				list.at(1);
			}
			catch (std::invalid_argument)
			{
				check = true;
			}
			Assert::IsTrue(check);
		}
		TEST_METHOD(Test_remove)
		{
			List list;
			bool check = 1;
			try
			{
				list.remove(1);
			}
			catch (std::invalid_argument)
			{
				check = true;
			}
			Assert::IsTrue(check);
			List list2;
			for (int i = 0; i < 5; i++) { list2.push_back(i + 1); }//1-2-3-4-5
			list2.remove(0);//2-3-4-5
			Assert::AreEqual(list2.at(0), 2);
			Assert::AreEqual(list2.at(1), 3);
			Assert::AreEqual(list2.at(2), 4);
			Assert::AreEqual(list2.at(3), 5);
			List list3;
			for (int i = 0; i < 5; i++) { list3.push_back(i + 1); }//1-2-3-4-5
			list3.remove(0);/*2-3-4-5*/ list3.remove(2);/*2-3-5*/
			Assert::AreEqual(list3.at(0), 2);
			Assert::AreEqual(list3.at(1), 3);
			Assert::AreEqual(list3.at(2), 5);
		}
		TEST_METHOD(Test_getsize)
		{
			List list;
			int size;
			size = list.get_size();
			Assert::AreEqual(size, 0);
			List list2;
			for (int i = 0; i < 5; i++) { list2.push_back(i + 1); }//1-2-3-4-5
			size = list2.get_size();
			Assert::AreEqual(size, 5);
		}
		TEST_METHOD(Test_clear)
		{
			List list;
			list.clear();
			Assert::IsTrue(list.isEmpty());
			List list2(1);
			list2.clear();
			Assert::IsTrue(list2.isEmpty());
			List list3;
			for (int i = 0; i < 5; i++) { list3.push_back(i + 1); }//1-2-3-4-5
			list3.clear();
			Assert::IsTrue(list3.isEmpty());

		}
		TEST_METHOD(Test_set)
		{
			List list;
			bool check = 1;
			try
			{
				list.set(2, 2);
			}
			catch (std::invalid_argument)
			{
				check = true;
			}
			Assert::IsTrue(check);
			List list2;
			for (int i = 0; i < 5; i++) { list2.push_back(i + 1); }//1-2-3-4-5
			list2.set(2, 666);
			Assert::AreEqual(list2.at(0), 1);
			Assert::AreEqual(list2.at(1), 2);
			Assert::AreEqual(list2.at(2), 666);
			Assert::AreEqual(list2.at(3), 4);
			Assert::AreEqual(list2.at(4), 5);
		}
		TEST_METHOD(Test_inverse)
		{
			List list;
			for (int i = 0; i < 5; i++) { list.push_back(i ); }//0-1-2-3-4
			list.reverse();
			Assert::AreEqual(list.at(0), 4);
			Assert::AreEqual(list.at(1), 3);
			Assert::AreEqual(list.at(2), 2);
			Assert::AreEqual(list.at(3), 1);
			Assert::AreEqual(list.at(4), 0);
		}
	};
}
