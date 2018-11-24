#include "ConsoleIODevice.h"
#include "MersenneTwisterGenerator.h"
#include <GameBoardFormatter.h>
#include <ConsoleGameController.h>
#include <Game2048Model.h>

int main() {
	ConsoleGameController controller{
		std::make_shared<Game2048Model>(
			GameBoard<int>{
				{
					{ 2, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }
				}
			},
			std::make_shared<GameBoardFormatter>(),
			std::make_shared<MersenneTwisterGenerator>()),
		std::make_shared<ConsoleIODevice>()
	};
	while (1)
		controller.next();
}
