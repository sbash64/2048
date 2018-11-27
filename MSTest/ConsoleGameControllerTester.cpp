#include <ConsoleGameControl/ConsoleGameController.h>
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

class LogString {
	std::string s;
public:
	LogString(std::string s = "") : s{ s } {}
	bool isEmpty() const {
		return s.empty();
	}
	bool beginsWith(std::string const &beginning) {
		if (s.length() >= beginning.length())
			return 0 == s.compare(0, beginning.length(), beginning);
		else
			return false;
	}
	bool contains(std::string const &s2) {
		return s.find(s2) != std::string::npos;
	}
	LogString &operator+=(const LogString &appended) {
		s += appended.s;
		return *this;
	}
};

class MockIODevice : public IODevice {
	std::string _lastOutput{};
	LogString _keyControllerLog{};
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
		_keyControllerLog += std::string{ "rightArrowKeyPressed " };
		return _rightArrowKey;
	}
	void setDownArrowKeyTrue() {
		_downArrowKey = true;
	}
	bool downArrowKeyPressed() override {
		_keyControllerLog += std::string{ "downArrowKeyPressed " };
		return _downArrowKey;
	}
	void setLeftArrowKeyTrue() {
		_leftArrowKey = true;
	}
	bool leftArrowKeyPressed() override {
		_keyControllerLog += std::string{ "leftArrowKeyPressed " };
		return _leftArrowKey;
	}
	void setUpArrowKeyTrue() {
		_upArrowKey = true;
	}
	void setUpArrowKeyFalse() {
		_upArrowKey = false;
	}
	bool upArrowKeyPressed() override {
		_keyControllerLog += std::string{ "upArrowKeyPressed " };
		return _upArrowKey;
	}
	void getKeyPress() override {
		_keyControllerLog += std::string{ "getKeyPress " };
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
	LogString keyControllerLog() const {
		return _keyControllerLog;
	}
};

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

		TEST_METHOD(nextPrintsRightMoveResult) {
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller{
				std::make_shared<MockModel>(),
				device };
			device->setRightArrowKeyTrue();
			controller.next();
			Assert::AreEqual(std::string{ "right" }, device->lastOutput());
		}

		TEST_METHOD(nextPrintsLeftMoveResult) {
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller{
				std::make_shared<MockModel>(),
				device };
			device->setLeftArrowKeyTrue();
			controller.next();
			Assert::AreEqual(std::string{ "left" }, device->lastOutput());
		}

		TEST_METHOD(nextPrintsUpMoveResult) {
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller{
				std::make_shared<MockModel>(),
				device };
			device->setUpArrowKeyTrue();
			controller.next();
			Assert::AreEqual(std::string{ "up" }, device->lastOutput());
		}

		TEST_METHOD(nextPrintsDownMoveResult) {
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller{
				std::make_shared<MockModel>(),
				device };
			device->setDownArrowKeyTrue();
			controller.next();
			Assert::AreEqual(std::string{ "down" }, device->lastOutput());
		}

		TEST_METHOD(noMoveDoesNotPrintAnythingSinceNewGame) {
			const auto device = std::make_shared<MockIODevice>();
			ConsoleGameController controller{
				std::make_shared<MockModel>(),
				device };
			controller.next();
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
				device->keyControllerLog().beginsWith("getKeyPress"));
			Assert::IsTrue(
				device->keyControllerLog().contains("leftArrowKeyPressed"));
			Assert::IsTrue(
				device->keyControllerLog().contains("rightArrowKeyPressed"));
			Assert::IsTrue(
				device->keyControllerLog().contains("upArrowKeyPressed"));
			Assert::IsTrue(
				device->keyControllerLog().contains("downArrowKeyPressed"));
		}
	};
}