#include "ConsoleIODevice.h"
#include <GameBoardFormatter.h>
#include <ConsoleGameController.h>

int main() {
	ConsoleGameController controller(
		GameBoard(
			{
				{ 2, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			}
		),
		std::make_shared<GameBoardFormatter>(),
		std::make_shared<ConsoleIODevice>()
	);
	while (1)
		controller.next();
}
