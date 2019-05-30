
#include<iostream> // for standart input/output stream function
#include<string>
#include<cstdlib> // for rand() and srand()
#include<ctime> // for time()
#include<stdexcept>

#include"User.h"
#include"Software.h"

using namespace std;

int main(void)
{
	srand(static_cast<unsigned int> (time(nullptr)));

	Software s1;
	User u1;
	unsigned int turn = 1;

	// kullanıcının 'tahmin' ve 'cevap' girişlerini kontrol için bir pair nesnesi
	// 'first', kullanıcının tahmin girişi için.
	// 'second', kullanıcının cevap girişi için
	pair<bool, bool> userInputControl;
	pair<bool, bool> winners;

	string userGuess;
	string userAnswer;
	string softwareGuess;
	string softwareAnswer;

	cout << "\n\t==================    !!!   LUFTEN AKLINIZDA BIR SAYI TUTUN   !!!   =================\n";
	cout << "\t============   !!!   LUFTEN IPUCULARIZ \"+x,-y\" FORMATINDA OLSUN   !!!   =============\n\n";
	// herhangi bir kazanan olmadığı sürece oyun sürüyor.
	while (!winners.first && !winners.second)
	{
		cout << "---------- " << turn << ".EL ----------" << endl;
		
		do
		{
			cout << "Kullanicinin tahmini: ";
			getline(cin, userGuess);
			userInputControl.first = u1.checkGuess(userGuess);

			if (!userInputControl.first)
				cout << "\n\t-----HATALI TAHMIN-----\n" << endl;
		} while (!userInputControl.first); // kullanıcı doğru formatta tahmin girene kadar yeni tahmin isteniyor.
	
		//kullanıcının doğru formattaki tahminine karşılık cevap üretiliyor.
		softwareAnswer = s1.answerToGuess(userGuess);
		cout << "Ipucular: " << softwareAnswer;

		cout << "\n\n";
		//yazılım bir tahmin yapıyor.
		softwareGuess = s1.makeGuess();
		cout << "Bilgisayarin tahmini: " << softwareGuess << endl;
		
		do
		{
			cout << "Ipucular: ";
			getline(cin, userAnswer);
			userInputControl.second = u1.checkAnswer(userAnswer);

			if (!userInputControl.second)
				cout << "\n\t-----HATALI IPUCU-----\n" << endl;

		} while (!userInputControl.second); // kullanıcı doğru formatta cevap girene kadar yeni cevap isteniyor.
		
		//kullanıcının doğru formattaki cevabına karşılık havuz budanıyor.
		s1.editSet(softwareGuess, userAnswer);

		//havuzun, yanlış puanlama sonucu tamamen boşalıp boşalmadığını kontrol ediyor.
		try
		{
			s1.isTheSetEmpty();
		}
		catch(const exception &e)
		{
			cout << "\n\t" << e.what() << endl;
			break;
		}
	
		winners = GuessingGame::whoWon(userAnswer, softwareAnswer);
		++turn;
		cout << endl;
	}

	if (winners.first == true &&  winners.second == true)
		cout << "\n\tOyun berabere bitti.\n" << endl;
	else if (winners.first)
	{
		cout << "\n\tBilgisayar kazandi :)" << endl;
		cout << "\tBilgisayarin sakladigi sayi: " << Software::getHiddenNumber() << "\n\n";
	}	
	else if (winners.second)
		cout << "\n\tKullanici kazandi :(\n" << endl;
}