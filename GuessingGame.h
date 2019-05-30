
#ifndef GGAME_H
#define GGAME_H

#include<string>

class GuessingGame
{
public:
	virtual std::string getScore(const std::string &, const std::string &) const final;
	static std::pair<bool, bool> whoWon(const std::string &, const std::string &);
	bool check(const std::string &) const;
	
	static const size_t LEN; // 4 basamaklı tahmin için bir sabit
};

#endif // !GGAME_H