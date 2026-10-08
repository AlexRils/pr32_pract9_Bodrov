// Pr32_pract9_Bodroff.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

//практика 9


void applyProcessing(double* data,int size,void (*processor)(double*, int)) {
	
	if (processor != nullptr)
	{
		processor(data, size);
	}
}

void operation1(double* data, int size) {

	std::cout << "введите коэффицент" << std::endl;

	double koefficent;

	std::cin >> koefficent;

	for (int i = 0; i < size; i++) {

		data[i] = data[i] + koefficent;

	}

	std::cout << "значение приведены к коэффеценту!" << std::endl;

}

void operation2(double* data, int size) {

	std::cout << "введите минимум \n";

	int min;

	std::cin >> min;


	std::cout << "введите максимум \n";

	int max;

	std::cin >> max;

	for (int i = 0; i < size; i++)
	{

		if (data[i] > max) {
			data[i] = max;
		}

		if (data[i] < min) {

			data[i] = min;
		}

    }

	std::cout << "Границы посталвены массив изменен!" << std::endl;


}

void operation3(double* data, int size) {

	for (int i = 0; i < size; i++) {

		if (data[i] < 0) {

			data[i] = 0;

		}

	}

	std::cout << "отрицательные значения заменены на 0!";



}

void operation4(double* data, int size) {


	std::cout << "введите минимум значение" << std::endl;

	double min;

	std::cin >> min;

	std::cout << "введите максимальное значение" << std::endl;

	double max;

	std::cin >> max;

 
	for (int i = 0; i < size; i++) {

		data[i] = (data[i] - min) / (max - min);

	}

	std::cout << "массив изменен до диапозона 0...1";

}




void PrintMassiv(double* data, int size)
{

	std::cout << "\nДанные:" << std::endl;

	for (int i = 0; i < size; i++)
	{

		std::cout << data[i] << " ";

	}

}



int main()
{

	setlocale(LC_ALL, "Russian");

	int size =0;

	double data[100];

	double copydata[100];

	void (*processor)(double*, int) = nullptr;

	void (*processors[])(double*, int) = {
       operation1,
       operation2,
       operation3,
       operation4
	};




	while (true) {

		std::cout << "\nМЕНЮ;" << std::endl;
		std::cout << "1. Ввести данные" << std::endl;
		std::cout << "2. Показать данные" << std::endl;
		std::cout << "3. Выбрать и выполнить обработку" << std::endl;
		std::cout << "4. Восстановить исходные данные" << std::endl;
		std::cout << "5. Выход" << std::endl;

		int vibor = 0;
		std::cin >> vibor;


		if (vibor == 1) {

			std::cout << "Введите количество температур" << std::endl;

			 size = 0;

			std::cin >> size;

			if (size > 0 && size < 100) {

				std::cout << "вводите значение темпиратуры: \n" << std::endl;

				for (int i = 0; i < size; i++) {

					std::cin >> data[i];

					copydata[i] = data[i];

				}

				std::cout << "Данные введены !";

			}
			else {

				std::cout << "вышли за диапозон!" << std::endl;
				size = 0;
			}

		


		}
		else 
		{

			if (vibor == 2) 
			{

				if (size > 0) {

					PrintMassiv(data, size);
					
				}
				else {

					std::cout << "сначала заполните массив" << std::endl;

				}
				

			}
			else {


				if (vibor == 3) {

					if (size < 0) {

						std::cout << "сначала заполните массив\n";

					}
					else {

				    	std::cout << "1. добавить ко всем значениям поправочный коэффициент;" << std::endl;
				    	std::cout << "2. ограничить значения заданным диапазоном;" << std::endl;
					    std::cout << "3. заменить отрицательные значения на 0 ;" << std::endl;
					    std::cout << "4. привести значения к диапазону от 0 до 1 ." << std::endl;

					    int vibortwo = 0;

					    std::cin >> vibortwo;

					    if (vibor < 4 && vibor > 1) {

                       
						  processor = processors[vibortwo - 1];

						  applyProcessing(data, size, processor);


					    }
					    else {

					   	  std::cout << "вышли за грани " << std::endl;

				     	}



					}



				}
				else {

					if (vibor == 4) {


						if (size == 0) {

							std::cout << "Сначала заполните данные" << std::endl;



						}
						else {

							std::cout << "первоначальынй массив = " << std::endl;

							for (int i = 0; i < size; i++) {


								std::cout << copydata[i] << " ";

							}
							

						}



					}
					else {


						if (vibor == 5) {


							std::cout << "Выход из программы" << std::endl;

							break;

						}


					}


				}



			}

		}



	}


	int(*ukaz)(double*, float, int*) = add;

}



int add(double* t, float c, int* a);