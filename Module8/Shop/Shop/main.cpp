#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

enum Sale
{
	None = 0,
	Max = 50,
	MilkProduct = 33,
	FlourProduct = 24
};

struct Product
{
	std::string nameProduct;
	double price;
	Sale sale;
};

struct Basket
{
	std::string nameProduct;
	int count;
	double price;
	Sale sale;
};

char ContinuedFilling();
void AvailableProduct(const std::vector<Product>&);
void CountBasket(std::vector<Basket>&, const std::vector<Product>&);

bool FindMaxElement(const Basket& lv, const Basket& rv)
{
	return lv.price < rv.price;
};

int main() {
	std::vector<Product> GroceryList =
	{
		{"Bread", 0.9, Sale::FlourProduct},
		{"White_bread", 0.9, Sale::FlourProduct},
		{"Milk", 1.3, Sale::MilkProduct},
		{"Butter", 3.6, Sale::MilkProduct},
		{"Sour_Cream", 1.8, Sale::MilkProduct},
		{"Meat", 16.0, Sale::None},
		{"Orange", 3.0, Sale::None},
		{"Apple", 2.5, Sale::None},
		{"Sugar", 2.05, Sale::None},
		{"Pasta", 1.29, Sale::None}
	};

	std::vector<Basket> BasketList = { };
	char chSymbol = ' ';
	std::string productName = " ";
	int count = 0;

	std::cout << "Let's start filling the basket? y/n" << std::endl;
	std::cin >> chSymbol;
	AvailableProduct(GroceryList);
	while (chSymbol == 'y')
	{

		std::cout << "Enter product name: " << "\n";
		std::cin >> productName;
		std::cout << "Enter count buy product: " << "\n";
		std::cin >> count;

		auto FindProductInBasket = [productName](const Basket& item) {
			return item.nameProduct == productName;
		};

		//заполнение корзины
		std::vector<Basket>::iterator it;
		it = find_if(BasketList.begin(), BasketList.end(), FindProductInBasket);
		if (it != BasketList.end())
		{
			it->count += count;
		}
		else
		{
			BasketList.push_back({ productName, count, 0, Sale::None });
		}

		chSymbol = ContinuedFilling();
	}

	CountBasket(BasketList, GroceryList);

	return 0;
}

void AvailableProduct(const std::vector<Product>& GroceryList)
{
	for (auto&& itemGroceryList : GroceryList)
	{
		std::cout << "Product name " << " " << itemGroceryList.nameProduct << " ";
		std::cout << "price " << itemGroceryList.price << " ";
		std::cout << "sale " << itemGroceryList.sale << "\n";
	}
}

char ContinuedFilling() {
	char answer = ' ';
	std::cout << "Want to count more? y/n" << std::endl;
	std::cin >> answer;
	return answer;
}

void CountBasket(std::vector<Basket>& BasketList, const std::vector<Product>& GroceryList)
{
	std::vector<int> maxElementsBasket;
	for (auto&& itemBasketList : BasketList)
	{
		for (auto&& itemGroceryList : GroceryList)
		{
			if (itemBasketList.nameProduct == itemGroceryList.nameProduct)
			{
				itemBasketList.price = (itemBasketList.count * itemGroceryList.price);
				itemBasketList.sale = itemGroceryList.sale;
			}
		}
		std::cout << itemBasketList.nameProduct << ":" << itemBasketList.count << "\n";
	}

	std::vector<Basket>::iterator it2;
	it2 = std::max_element(BasketList.begin(), BasketList.end(), FindMaxElement);
	maxElementsBasket.push_back(std::distance(BasketList.begin(), it2));

	for (size_t i = 0; i < BasketList.size(); ++i)
	{
		if (BasketList[i].nameProduct == it2->nameProduct)
			continue;

		if (it2->price == BasketList[i].price)
		{
			maxElementsBasket.push_back(i);

		}
	}

	std::cout << "maximum elements found: " << maxElementsBasket.size() << "\n";
	std::cout << "Choose a product for maximum discount: " << "\n";

	for (size_t i = 0; i < maxElementsBasket.size(); ++i)
	{

		std::cout << i << " " << BasketList[maxElementsBasket[i]].nameProduct << " ";
		std::cout << "count " << BasketList[maxElementsBasket[i]].count << " ";
		std::cout << "price " << BasketList[maxElementsBasket[i]].price << " ";
		std::cout << "sale " << static_cast<double>(BasketList[maxElementsBasket[i]].price * static_cast<double>(Sale::Max) / 100) << "\n";

	}
	std::cout << "Enter index: " << "\n";
	int selectedElementIndex = 0;
	std::cin >> selectedElementIndex;
	double allProductPrice = 0;
	std::cout << "Check: " << "\n";
	for (size_t i = 0; i < BasketList.size(); ++i)
	{
		double sale = 0;
		if (selectedElementIndex == i)
		{
			sale = static_cast<double>(Sale::Max) / 100;
		}
		else if (BasketList[i].sale == Sale::None)
		{
			sale = 1;
		}
		else
		{
			sale = static_cast<double>(BasketList[i].sale) / 100;
		}
		double currentProductPrice = BasketList[i].price;
		allProductPrice += BasketList[i].price - (BasketList[i].price * sale);

		std::cout << i + 1 << " " << BasketList[i].nameProduct << " ";
		std::cout << "count " << BasketList[i].count << " ";
		std::cout << "price " << BasketList[i].price << " ";
		std::cout << "sale " << BasketList[i].price * sale << "\n";

	}
	std::cout << "	final purchase price: " << allProductPrice << "\n";

}
