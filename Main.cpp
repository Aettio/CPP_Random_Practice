#include <iostream>
#include <ctime> // Для рандомайзера основанного на времени 

using namespace std; // Для устранения конфликта имён (Вынесен за пределы мейн для удобства)

class Node // Создание основы дерева и ветвей
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void insert(Node *root, int data)// Метод добавления чисел в корни и их сортировки
{
	if (root == NULL) 
	{
		Node* root = new Node(data);
	}
	else if(data <= root -> data)
	{
		if (root->left != NULL)
		{
			insert(root->left, data);
		}
		else
		{
			root->left = new Node(data);
		}
	}
	else if (data > root->data)
	{
		if (root->right != NULL)
		{
			insert(root->right, data);
			
		}
		else
		{
			root->right = new Node(data);
		}
	}
}

void display(Node* root, int sorted[])//Заполнение нового массива сортированными числами
{
	static int pos = 0;

	if (root == NULL)
	{
		return;
	}

	display(root->left, sorted);
	sorted[pos++] = root->data;
	display(root->right, sorted);

}

int main()
{
	srand(time(NULL));// Для более рандомной генерации чисел
	const int SIZE = 18;// Для размера массива
	const int RANGE = 100;// Для диапазона рандомайзера
	int a, i, j;// Для каунтеров
	bool alreadythere;// Для проверки на уникальность 
	int array[SIZE];// Одномерный массив для хранения рандомных чисел
	int sorted[SIZE];// Сортированный массив


	cout << "Random Matrix" << endl << endl;

	for (i = 0; i < SIZE;)// Рандомайзер
	{
		alreadythere = false;
		a = rand() % RANGE; // Генерация чисел и проверка на уникальность

		for (j = 0; j < i; j++)
		{
			if (array[j] == a)
			{
				alreadythere = true; 
				break;
			}
		}
		if (!alreadythere)// Если число уникально, добавление в массив и вывод на экран в виде матрицы
		{
			array[i] = a;
			cout << a << "\t";
			i++;
			if (i == 6)
			{
				cout << endl;
			}
			if (i == 12)
			{
				cout << endl;
			}
		}
	}

	cout << endl << endl << "Tree sort" << endl << endl;

	Node* root = new Node(array[0]);

	for (i = 1; i < SIZE; i++) // Отправка чисел матрицы на сортировку деревом
	{
		insert(root, array[i]);
	}

	display(root, sorted); // Заполнение нового массива сортированными числами

	for (int i = 0; i < SIZE; i++)// Вывод сортированной матрицы на экран
	{
		cout << sorted[i] << "\t";
		if (i == 5)
		{
			cout << endl;
		}
		if (i == 11)
		{
			cout << endl;
		}
	}

	cout << endl << endl;

	delete[] root; // Удаление дерева

	system("pause");
}

