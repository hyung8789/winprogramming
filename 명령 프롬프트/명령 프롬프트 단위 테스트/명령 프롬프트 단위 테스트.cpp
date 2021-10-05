﻿#include "pch.h"
#include "CppUnitTest.h"

#include "../main.cpp"
#include "../Utils.cpp"

#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace 명령프롬프트단위테스트
{
	TEST_CLASS(명령프롬프트단위테스트)
	{
	public:
		// https://docs.microsoft.com/ko-kr/visualstudio/test/unit-test-basics?view=vs-2019

		TEST_METHOD(소문자_변환_테스트)
		{
			// https://docs.microsoft.com/en-us/cpp/text/how-to-convert-between-various-string-types?view=msvc-160

			const TCHAR* expected = _T("test");
			TCHAR buffer[] = _T("TeST");
			const TCHAR* actual = StrLower(buffer);
			Assert::AreEqual(expected, actual);

			const TCHAR* actual2 = StrLower(NULL);
			Assert::IsNull(actual2); //NULL이어야 함
		}

		TEST_METHOD(selfProcessName_테스트)
		{
			const TCHAR* expected = _T("testhost.exe");
			const TCHAR* actual = GetSelfProcessNameWithExt();

			Assert::IsNotNull(actual);
			Assert::AreEqual(expected, actual);
		}
	};
}
