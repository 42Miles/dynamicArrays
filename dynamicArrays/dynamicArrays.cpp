#include <iostream>

void sorting(std::string array[], int length)
{
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		// В переменной smallestIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации.
		// Начинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
		int smallestIndex = startIndex;

		// Затем ищем элемент поменьше в остальной части массива
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// Если мы нашли элемент, который меньше нашего наименьшего элемента,
			if (array[currentIndex] < array[smallestIndex])
				// то запоминаем его
				smallestIndex = currentIndex;
		}

		// smallestIndex теперь наименьший элемент. 
				// Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
		std::swap(array[startIndex], array[smallestIndex]);
	}
}

int main()
{
	std::cout << "How many names you want to enter? ";
    int numberOfNames;
    std::cin >> numberOfNames;
	std::cout << "\n";

    std::string* names = new std::string[numberOfNames]{};

    std::string name;
    for (int i = 0; i < numberOfNames; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::cin >> names[i];
    }

	std::cout << "\n";

	sorting(names, numberOfNames);
	std::cout << "Here is your sorted list:" << std::endl;

	for (int i = 0; i < numberOfNames; ++i)
	{
		std::cout << "Name #" << i + 1 << ": " << names[i] << std::endl;
	}

	delete[] names;
	names = nullptr;

    return 0;
}