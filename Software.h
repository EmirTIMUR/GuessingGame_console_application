#ifndef SOFTWARE_H
#define SOFTWARE_H

#include"GuessingGame.h"
#include<string>
#include<deque>

class Software : public GuessingGame 
{
public:
	Software();
	std::string makeGuess(void);
	std::string answerToGuess(const std::string &) const;
	void editSet(const std::string &, const std::string &);
	void isTheSetEmpty(void) const;
	static std::string getHiddenNumber(void);

private:
	void createHiddenNumber(void);
	void fillSet(void);
	void pruneTheSet(const std::string &, const std::string &);

	std::deque< std::string > set; // kullanıcın aklında tuttuğu muhtemel sayılar için bir 'havuz/küme'
	static std::string hiddenNumber; // yazılımın sakladığı sayı
};

#endif