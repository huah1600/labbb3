// Example program
#include <iostream>
#include <string>
#include <vector>
#include <time.h> 
#include <algorithm> 
#include <windows.h>
#include <random>
#include <functional>
#include "prio_que.h"

using namespace std;


struct order {

	std::string name;

	int price; //prioritet

};
// this is an strucure which implements the 
// operator overlading 
struct  comp {
	bool operator()(order& p1, order& p2)
	{
		// return "true" if "p1" is ordered  
		// before "p2", for example: 
		return p1.price < p2.price;
	}
};




int main()
{
	std::random_device device;

	std::mt19937 generator(device());

	std::uniform_int_distribution<int> dist(15, 30);
	UINT oldcodepage = GetConsoleOutputCP();
	SetConsoleOutputCP(28591);


	system("chcp 1252");

	p_queue<order, comp > buyers, sellers;////////////////////

	constexpr int n = 7;



	for (int i = 0; i < n; i++)

	{

		buyers.push({ "Erik Pendel", dist(generator) });

		buyers.push({ "Jarl Wallenburg", dist(generator) });

		buyers.push({ "Joakim von Anka", dist(generator) });

		sellers.push({ "Erik Pendel", dist(generator) });

		sellers.push({ "Jarl Wallenburg", dist(generator) });

		sellers.push({ "Joakim von Anka", dist(generator) });


	}


	while (!buyers.empty() && !sellers.empty())

	{

		auto buyer = buyers.pop();

		auto seller = sellers.pop();



		if (buyer.price >= seller.price)

		{

			std::cout << buyer.name << " köpte av " << seller.name << " för " << buyer.price << "kr." << seller.name << " sålde för " << seller.price << std::endl;

		}

		else

			sellers.push(seller);

	}
	
	system("pause");

	return 0;

}
