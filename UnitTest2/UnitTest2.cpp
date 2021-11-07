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
		TEST_METHOD(Test_remove)
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
				for (int i=0; i < 5; i++) { list2.push_back(i); } //0-1-2-3-4
				list2.pop_front();//1-2-3-4
				size = list2.get_size();
				Assert::AreEqual(size, 4);
			List list3;
			bool check=1;
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
		
	};
}
