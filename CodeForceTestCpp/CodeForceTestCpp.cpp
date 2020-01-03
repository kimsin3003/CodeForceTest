#include <iostream>
#include <string>
#include <vector>

bool IsSameVector(std::vector<int> v1, std::vector<int> v2)
{
	if (v1.size() != v2.size())
		return false;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}
int main()
{
	int n, k1, k2;
	std::vector<int> player1FirstDeck;
	std::vector<int> player2FirstDeck;
	std::cin >> n;
	std::cin >> k1;
	for (int i = 0; i < k1; i++)
	{
		int cardNum;
		std::cin >> cardNum;
		player1FirstDeck.push_back(cardNum);
	}
	std::cin >> k2;
	for (int i = 0; i < k2; i++)
	{
		int cardNum;
		std::cin >> cardNum;
		player2FirstDeck.push_back(cardNum);
	}

	std::vector<int> player1Deck(player1FirstDeck);
	std::vector<int> player2Deck(player2FirstDeck);

	int fightNum = 0;
	while (true)
	{
		if (player1Deck.size() == 0)
		{
			std::cout << fightNum << " " << 2;
			break;
		}
		if (player2Deck.size() == 0)
		{
			std::cout << fightNum << " " << 1;
			break;
		}
		if (fightNum > 0 && (IsSameVector(player1Deck, player1FirstDeck) && IsSameVector(player2Deck, player2FirstDeck)))
		{
			std::cout << -1;
			break;
		}
		fightNum++;

		//fight
		if (player1Deck[0] > player2Deck[0])
		{
			player1Deck.push_back(player2Deck[0]);
			player1Deck.push_back(player1Deck[0]);
		}
		if (player1Deck[0] < player2Deck[0])
		{
			player2Deck.push_back(player1Deck[0]);
			player2Deck.push_back(player2Deck[0]);
		}
		player1Deck.erase(player1Deck.begin());
		player2Deck.erase(player2Deck.begin());
	}
	getchar();
}