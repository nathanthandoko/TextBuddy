#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class TextBuddy;

namespace LibraryTest{		
	TEST_CLASS(TextBuddyTest){
	public:
		

		TEST_METHOD(fileNameTest){
			TextBuddy textTest;
			string TEST_FILENAME = "mytextfile";
			textTest.setName("mytextfile");
			string textTestFileName = textTest.getFileName();
			Assert::AreEqual(TEST_FILENAME, textTestFileName);
		}

		TEST_METHOD(addTest){
			TextBuddy textTest;
			
			vector<string> expectedText;
			expectedText.push_back("Hello there");
			vector<string> actualText;
			textTest.add("Hello there", actualText);

			Assert::AreEqual(expectedText[0], actualText[0]);
		}

		TEST_METHOD(deleteSententenceTest){
			TextBuddy textTest;
			string expectedText = "Hi here";
			vector<string> actualText;
			textTest.add("Hello there", actualText);
			textTest.add("Hi here", actualText);
			textTest.deleteSentence(actualText, 1);

			Assert::AreEqual(expectedText, actualText[0]);

		}
	};
}