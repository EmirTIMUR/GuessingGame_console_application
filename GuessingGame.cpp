
#include<string>
#include<algorithm> //for count()
#include"GuessingGame.h"

using namespace std;

const size_t GuessingGame::LEN = 4;

//kullanıcının yaptığı tahmine karşı cevabın(+x,-y) elde edilmesini sağlayan fonksiyon.
//ilk paremetre kullanıcın tahmini, ikinci paremetre bilgisayarın sakladığı sayı
string GuessingGame::getScore(const string &guess, const string &number) const
{
	unsigned int plus = 0;
	unsigned int minus = 0; 

	for (size_t i = 0; i < LEN; ++i)
	{
		if (guess[i] == number[i])
			plus++;
		else
		{
			for (size_t k = 0; k < LEN; ++k)
			{
				if (guess[i] == number[k])
					minus++;
			}
		}
	}

	return "+" + to_string(plus) + ",-" + to_string(minus);
}

//kullanıcının yaptığı tahminde bir rakamın tekrar edip etmediğini kontrol eden fonksiyon.
bool GuessingGame::check(const string &guess) const
{
	for (string::const_iterator itr = guess.cbegin();
		itr != guess.cend(); ++itr)
	{
		if (count(guess.cbegin(), guess.cend(), *itr) > 1)
			return false;
	}
	return true;
}

//x. el sonunda herhangi bir kazananın olup olmadığı kontrol eden fonksiyon.
pair<bool, bool> GuessingGame::whoWon(
	const string &userAnswer, const string &softwareAnswer) 
{
	pair<bool, bool> winners;
	if (userAnswer[1] == '4')
		winners.first = true;
	if (softwareAnswer[1] == '4')
		winners.second = true;

	return winners;
}