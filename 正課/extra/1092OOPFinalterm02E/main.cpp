#include "Train.h"

void printTrain(const Train& train)
{
	Carriage* cur = train.root;
	while (cur != nullptr)
	{
		std::cout << "Carriage name: " << cur->getName() << " \tPassenger num: " << cur->getPassengerNum() << std::endl;
		cur = cur->next;
	}
}


void CreateTrain(Train& train)
{
	int num;
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		std::string name;
		int passengerNum;
		std::cin >> name >> passengerNum;

		std::string* passengerName = new std::string[passengerNum];
		for (int j = 0; j < passengerNum; j++)
		{
			std::cin >> passengerName[j];
		}
		train.pushCarriage(name, passengerNum, passengerName);
	}
}

int main()
{
	Train train;
	CreateTrain(train);
	printTrain(train);

	std::string checkName = "Hospitality";
	std::cout << "The passenger in Hospitality:" << std::endl;
	train.checkPassenger(checkName);

	std::string deleteName = "Third_class";
	std::cout << "Delete Carriage Third_class." << std::endl;
	train.deleteCarriage(deleteName);


	deleteName = "Second_class";
	std::cout << "Delete Carriage Second_class." << std::endl;
	train.deleteCarriage(deleteName);


	std::string getName = "Second_class";
	std::cout << "get Carriage Second_class." << std::endl;
	train.getCarriage(getName);

	printTrain(train);

	return 0;
}
