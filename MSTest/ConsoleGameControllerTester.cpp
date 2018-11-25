#include <ConsoleGameController.h>
#include <CppUnitTest.h>

class MockModel : public GameModel {
	std::string newGame() override {
		return "newGame";
	}
	std::string down() override {
		return "down";
	}
	std::string up() override {
		return "up";
	}
	std::string left() override {
		return "left";
	}
	std::string right() override {
		return "right";
	}
};

class MockIODevice : public IODevice {
	std::string _lastOutput{};
	std::string _keyControllerLog{};
	bool _rightArrowKey = false;
	bool _downArrowKey = false;
	bool _leftArrowKey = false;
	bool _upArrowKey = false;
	bool _getKeyPressCalled = false;
public:
	void setRightArrowKeyTrue() {
		_rightArrowKey = true;
	}
	bool rightArrowKeyPressed() override {
		_keyControllerLog += "rightArrowKeyPressed ";
		return _rightArrowKey;
	}
	void setDownArrowKeyTrue() {
		_downArrowKey = true;
	}
	bool downArrowKeyPressed() override {
		_keyControllerLog += "downArrowKeyPressed ";
		return _downArrowKey;
	}
	void setLeftArrowKeyTrue() {
		_leftArrowKey = true;
	}
	bool leftArrowKeyPressed() override {
		_keyControllerLog += "leftArrowKeyPressed ";
		return _leftArrowKey;
	}
	void setUpArrowKeyTrue() {
		_upArrowKey = true;
	}
	void setUpArrowKeyFalse() {
		_upArrowKey = false;
	}
	bool upArrowKeyPressed() override {
		_keyControllerLog += "upArrowKeyPressed ";
		return _upArrowKey;
	}
	void getKeyPress() override {
		_keyControllerLog += "getKeyPress ";
		_getKeyPressCalled = true;
	}
	bool getKeyPressCalled() const {
		return _getKeyPressCalled;
	}
	std::string lastOutput() const {
		return _lastOutput;
	}
	void print(std::string output) override {
		_lastOutput = output;
	}
	std::string keyControllerLog() const {
		return _keyControllerLog;
	}
};

static bool beginsWith(std::string const &beginning, std::string const &s) {
	if (s.length() >= beginning.length())
		return (0 == s.compare(0, beginning.length(), beginning));
	else
		return false;
}

static bool contains(std::string const &s1, std::string const &s2) {
	return s2.find(s1) != std::string::npos;
}

namespace MSTest
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(ConsoleGameControllerTester) {
	public:
		TEST_METHOD(constructorPrintsNewGame) {
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller{
				std::make_shared<MockModel>(),
				device };
			Assert::AreEqual(std::string{ "newGame" }, device->lastOutput());
		}

		TEST_METHOD(nextCallsGetKeyPress) {
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller{
				std::make_shared<MockModel>(),
				device};
			controller.next();
			Assert::IsTrue(device->getKeyPressCalled());
		}

		TEST_METHOD(nextCallsGetKeyPressBeforeQueryingKeys) {
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller{
				std::make_shared<MockModel>(),
				device };
			controller.next();
			Assert::IsTrue(
				beginsWith("getKeyPress", device->keyControllerLog()));
			Assert::IsTrue(
				contains("leftArrowKeyPressed", device->keyControllerLog()));
			Assert::IsTrue(
				contains("rightArrowKeyPressed", device->keyControllerLog()));
			Assert::IsTrue(
				contains("upArrowKeyPressed", device->keyControllerLog()));
			Assert::IsTrue(
				contains("downArrowKeyPressed", device->keyControllerLog()));
		}
	};
}