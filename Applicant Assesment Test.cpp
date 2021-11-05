//Dervi� �otuk
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;

int *randomNumberGenerator(){

    int base1,base2,base3,base4;
    do {
    //Burada rand function kullan�larak birbirinden farkl� 4 say� �retiyoruz.	
    base1 = rand()%10 ;      
    base2 = rand()%10 ;      
    base3 = rand()%10 ;
    base4 = rand()%9 + 1;    
    } // B�t�n rakamlar farkl� olana kadar loop devam ediyor.
    while(base1 == base2 || base1 == base3 || base1 == base4 || base2 == base3 || base2 == base4 || base3 == base4);
    
    int *bases = new int[4];
    // New kullanarak memory allocation yapt�m. ��nk� array olarak return etmek i�in memory allocate etmemiz gerekiyor.
    bases[0] = base1;
    bases[1] = base2;
    bases[2] = base3;
    bases[3] = base4;
    // Array olarak b�t�n rakamlar� return ediyoruz function call i�in.
	return bases;
}

int menu(){
	int menuSelection;
	// Burada giri�in temel g�vdesini yazd�m. Oyun ilk ba�lad���nda ��kan ekran.
	cout << "Welcome, this is a guessing game." << endl;
	cout << "In this game you will be competing with the computer to guess a number." << endl;
	cout << "Firstly, computer will try to guess the number you think, you will not enter the number you think." << endl;
	cout << "Secondly, you will try to guess the number which computer created, this number also will not be shown in the screen"<<endl;
	cout << "After each guess, either computer or player will give clues to the guess number"<<endl;
	cout << "For the correct number in correct digits + clues and for the same numbers in different digits - clues will be given"<<endl;
	cout << "For example, if 3468 guess is done for 5483 number then, clues are +1 and -2 since, 4 is in correct digit and 8 and 3 is not"<<endl;
	cout << "The one who guesses the number first will win." << endl;
	cout << "Good luck!!!"<<endl;
	cout<<"Press enter to continue or press ESC to quit the game. "<<endl;
	
	bool loop = false;
    while(loop == false)
    {  
       //ESC girildi�inde menuden c�k�yoruz, bunun i�in getch function kulland�m cin ile sorun ��k�yor.
       char ch = getch();
       if(ch == 27)
        break;
       
       system("cls");
       // Menu options
	   cout<<"1. Start the game"<<endl; 
	   cout<<"2. Rules"<<endl; 
	   cout<<"3. Credits"<<endl; 
	   cout<<"4. Exit the game "<<endl; 
	   cin>> menuSelection;
	   //Menu seceneklerini if kullanarak d�zenledim.
	   if(menuSelection == 1)
	    return menuSelection;
	   else if(menuSelection == 2)
	   {
	   	system("cls");
	   	cout << "Welcome, this is a guessing game." << endl;
        cout << "In this game you will be competing with the computer to guess a 4 digit number." << endl;
	    cout << "Firstly, computer will try to guess the number you think, you will not enter the number you think." << endl;
	    cout << "Secondly, you will try to guess the 4 digit number which computer created, this number also will not be shown in the screen"<<endl;
	    cout << "After each guess, either computer or player will give clues to the guess number"<<endl;
	    cout << "For the correct number in correct digits + clues and for the same numbers in different digits - clues will be given"<<endl;
        cout << "For example, if 3468 guess is done for 5483 number then, clues are +1 and -2 since, 4 is in correct digit and 8 and 3 is not"<<endl;
	    cout << "The one who guesses the number first will win." << endl;
	    cout << "Good luck!!!"<<endl;
	   }
	   else if(menuSelection == 3)
	   {
	   	system("cls");
	   	cout << "Made by Dervis Cotuk"<<endl;
	   }
	   else if(menuSelection == 4)
	    break;
	   else 
	   cout << "Enter a correct number.";
	   
    }
    
    return menuSelection;
}

int *guessingClues(int guessBase1, int guessBase2, int guessBase3, int guessBase4,int randomBase1,int randomBase2,int randomBase3,int randomBase4){
	// computerClues variable memory allocate ederek olusturdum. Yine bir array return etmemiz gerekti�i i�in.
	int *computerClues = new int[2]; 
	computerClues[0] = 0;
	computerClues[1] = 0;
	//+ ipucular� i�in yani ayn� basamak de�erindeki ayn� say�lar i�in ipucu de�erlerini ayarlad�m.
	if (randomBase1 == guessBase1)
	 computerClues[0] += 1;
	if (randomBase2 == guessBase2)
	 computerClues[0] += 1;
	if (randomBase3 == guessBase3)
	 computerClues[0] += 1;
	if (randomBase4 == guessBase4)
	 computerClues[0] += 1;
	 //- ipucular� i�in yani farkl� basamak de�erindeki ayn� say�lar i�in ipucu de�erlerini ayarlad�m.
	if (randomBase1 == guessBase2)
	 computerClues[1] += 1; 
	if (randomBase1 == guessBase3)
	 computerClues[1] += 1; 
	if (randomBase1 == guessBase4)
	 computerClues[1] += 1; 
    if (randomBase2 == guessBase1)
	 computerClues[1] += 1; 
    if (randomBase2 == guessBase3)
	 computerClues[1] += 1; 
	if (randomBase2 == guessBase4)
	 computerClues[1] += 1;  
    if (randomBase3 == guessBase1)
	 computerClues[1] += 1;  
	if (randomBase3 == guessBase2)
	 computerClues[1] += 1;  
	if (randomBase3 == guessBase4)
	 computerClues[1] += 1;   
	if (randomBase4 == guessBase1)
	 computerClues[1] += 1;  
	if (randomBase4 == guessBase2)
	 computerClues[1] += 1;  
	if (randomBase4 == guessBase3)
	 computerClues[1] += 1;   
	else 
	{
		
	computerClues[0] += 0;
	computerClues[1] += 0; 
    }
	// ipucu de�erlerini (+ ve -) array olarak return ediyoruz.
	return computerClues;
}

int *computerGuess(int guess1, int guess2, int guess3, int guess4,int playerClues0, int playerClues1){
	//Bilgisayar�n tahminini array olarak return edee�imiz i�in, memory allocate ederek bir array olu�turuyorum.
    int *computerGuesses = new int[4]; 
    // Tekrar random say� �a��rca��m zaman i�in bir pointer olu�turuyorum.
    int *randomGuess;
    //main functionda bu function'� call ederken girdi�imiz de�erleri yeni tahmin de�erlerine e�itliyorum.
    computerGuesses[0] = guess1;
	computerGuesses[1] = guess2;
	computerGuesses[2] = guess3;
	computerGuesses[3] = guess4;
    //4 tane (1 2 3 4) random say� olu�turuyorum. Tahmin edece�imiz yeni de�erler i�in kullan�ca��m.
	int i = rand()%4;
	int k = rand()%4;
	int j = rand()%4;
	int l = rand()%4;
	//Oyuncudan ald���m�z ipucu de�erlerini (+ ve -  yani ayn� basamakta ayn� de�erler ve farkl� basamakta ayn� de�erler)
	//kullan�p bu ipucu de�erlerine g�re yeni tahmin say�lar� olu�turuyorum.
	if(playerClues0 == 0 && playerClues1 == 0)
	{
	    //B�t�n rakamlar farkl� oldu�u i�in o rakamlardan farkl� yeni bir say� olu�turuyorum.
	    while(computerGuesses[0] == guess1 || computerGuesses[0] == guess2 || computerGuesses[0] == guess3 || computerGuesses[0] == guess4)
		computerGuesses[0] = rand()%10;
		while(computerGuesses[1] == guess1 || computerGuesses[1] == guess2 || computerGuesses[1] == guess3 || computerGuesses[1] == guess4)
		computerGuesses[1] = rand()%10;
		while(computerGuesses[2] == guess1 || computerGuesses[2] == guess2 || computerGuesses[2] == guess3 || computerGuesses[2] == guess4)
		computerGuesses[2] = rand()%10;
		while(computerGuesses[3] == guess1 || computerGuesses[3] == guess2 || computerGuesses[3] == guess3 || computerGuesses[3] == guess4)
		computerGuesses[3] = rand()%9 + 1;
	}
	//E�er ipucu say�s� (+) azsa random kullanarak daha fazla say�y� yeniden tahmin etmeye �al���yorum. 
	else if(playerClues0 == 1 && playerClues1 ==0)
	{
		if (i == 1 )
		{
		computerGuesses[0] = rand()%10;
		while(computerGuesses[1] == guess1 || computerGuesses[1] == guess2 || computerGuesses[1] == guess3 || computerGuesses[1] == guess4)
		computerGuesses[1] = rand()%10;
		while(computerGuesses[2] == guess1 || computerGuesses[2] == guess2 || computerGuesses[2] == guess3 || computerGuesses[2] == guess4)
		computerGuesses[2] = rand()%10;
		while(computerGuesses[3] == guess1 || computerGuesses[3] == guess2 || computerGuesses[3] == guess3 || computerGuesses[3] == guess4)
		computerGuesses[3] = rand()%9 + 1;
		}
		if (i == 2 )
		{
		while(computerGuesses[0] == guess1 || computerGuesses[0] == guess2 || computerGuesses[0] == guess3 || computerGuesses[0] == guess4)
		computerGuesses[0] = rand()%10;
		while(computerGuesses[1] == guess1 || computerGuesses[1] == guess2 || computerGuesses[1] == guess3 || computerGuesses[1] == guess4)
		computerGuesses[1] = rand()%10;
		while(computerGuesses[2] == guess1 || computerGuesses[2] == guess2 || computerGuesses[2] == guess3 || computerGuesses[2] == guess4)
		computerGuesses[2] = rand()%10;
		computerGuesses[3] = rand()%9 + 1;
		}
		if (i == 3 )
		{
		computerGuesses[1] = rand()%10;
		while(computerGuesses[0] == guess1 || computerGuesses[0] == guess2 || computerGuesses[0] == guess3 || computerGuesses[0] == guess4)
		computerGuesses[0] = rand()%10;
		while(computerGuesses[2] == guess1 || computerGuesses[2] == guess2 || computerGuesses[2] == guess3 || computerGuesses[2] == guess4)
		computerGuesses[2] = rand()%10;
		while(computerGuesses[3] == guess1 || computerGuesses[3] == guess2 || computerGuesses[3] == guess3 || computerGuesses[3] == guess4)
		computerGuesses[3] = rand()%9 + 1;
		}
	} //E�er ipucu say�s� (+) fazlaysa random kullanarak sadece 1 say�y� tahmin etmeye �al���yorum.
	else if(playerClues0 == 2 && playerClues1 == 0)
	{
		computerGuesses[i] = rand()%9 + 1;
	}
	//E�er ipucu say�s� (+) fazlaysa random kullanarak sadece 1 say�y� tahmin etmeye �al���yorum.
	else if(playerClues0 == 3 && playerClues1 == 0)
	{
		computerGuesses[i] = rand()%9 + 1;
	}
	//E�er ipucu say�s� (-) azsa random kullanarak daha fazla say�y� yeniden tahmin etmeye �al���yorum. 
	else if(playerClues0 == 0 && playerClues1 == 1)
	{
		computerGuesses[i] = guess3;
		computerGuesses[k] = rand()%9 + 1;
		computerGuesses[j] = rand()%9 + 1;
		computerGuesses[l] = rand()%9 + 1;
	}
	else if(playerClues0 == 0 && playerClues1 == 2)
	{
		if(i == 1)
		{
		computerGuesses[0] = rand()%9 + 1 ;
		computerGuesses[1] = guess3;
		computerGuesses[2] = guess2;
		computerGuesses[3] = rand()%9 + 1;
		}
		if(i == 2)
		{
		computerGuesses[0] = guess4 ;
		computerGuesses[1] = rand()%9 + 1;
		computerGuesses[2] = rand()%9 + 1;
		computerGuesses[3] = guess1;
		}
		if(i == 3)
		{
		computerGuesses[0] = rand()%9 + 1;
		computerGuesses[1] = rand()%9 + 1;
		computerGuesses[2] = guess4;
		computerGuesses[3] = guess3;
		}
		if(i == 4)
		{
		computerGuesses[0] = guess2;
		computerGuesses[1] = guess1;
		computerGuesses[2] = rand()%9 + 1;
		computerGuesses[3] = rand()%9 + 1;
		}
	}
	//E�er ipucu say�s� (-) fazlaysa rakamlar� birbiryleriyle de�i�tirip do�ru say�y� tahmin etmeye �al���yorum. 
	else if(playerClues0 == 0 && playerClues1 == 3)
	{
		if(i == 1)
		{
		computerGuesses[0] = guess3;
		computerGuesses[1] = rand()%9 + 1;
		computerGuesses[2] = guess2;
		computerGuesses[3] = guess1;
		}
		if(i == 2)
		{
		computerGuesses[0] = guess4;
		computerGuesses[1] = guess3;
		computerGuesses[2] = rand()%9 + 1;
		computerGuesses[3] = guess2;
		}
		if(i == 3)
		{
		computerGuesses[0] = guess4;
		computerGuesses[1] = guess1;
		computerGuesses[2] = guess2;
		computerGuesses[3] = rand()%9 + 1;
		}
		if(i == 4)
		{
		computerGuesses[0] = rand()%9 + 1;
		computerGuesses[1] = guess1;
		computerGuesses[2] = guess2;
		computerGuesses[3] = guess3;
		}
	}
	//T�m rakamlar� birbiriyle de�i�tirip do�ru say�y� bulmaya �al���yorum b�t�n rakamlar do�ru ama yerleri yanl�� oldu�u i�in.
	else if(playerClues0 == 0 && playerClues1 == 4)
	{
		if(i == 1)
		{
		computerGuesses[0] = guess3;
		computerGuesses[1] = guess4;
		computerGuesses[2] = guess2;
		computerGuesses[3] = guess1;
		}
		if(i == 2)
		{
		computerGuesses[0] = guess4;
		computerGuesses[1] = guess3;
		computerGuesses[2] = guess1;
		computerGuesses[3] = guess2;
		}
		if(i == 1)
		{
		computerGuesses[0] = guess4;
		computerGuesses[1] = guess1;
		computerGuesses[2] = guess2;
		computerGuesses[3] = guess3;
		}
		if(i == 0)
		{
		computerGuesses[0] = guess3;
		computerGuesses[1] = guess4;
		computerGuesses[2] = guess1;
		computerGuesses[3] = guess2;
		}
	}
	// Yukar�daki tekniklerin ayn�lar�n� kullanarak a����daki durumlar� da ��z�yorum.
	else if(playerClues0 == 1 && playerClues1 == 1)
	{
			if(i == 1)
		{
		computerGuesses[0] = rand()%9 + 1 ;
		computerGuesses[1] = guess3;
		computerGuesses[2] = guess2;
		computerGuesses[3] = rand()%9 + 1;
		}
		if(i == 2)
		{
		computerGuesses[0] = guess4 ;
		computerGuesses[1] = rand()%9 + 1;
		computerGuesses[2] = rand()%9 + 1;
		computerGuesses[3] = guess1;
		}
		if(i == 3)
		{
		computerGuesses[0] = rand()%9 + 1;
		computerGuesses[1] = rand()%9 + 1;
		computerGuesses[2] = guess4;
		computerGuesses[3] = guess3;
		}
		if(i == 4)
		{
		computerGuesses[0] = guess2;
		computerGuesses[1] = guess1;
		computerGuesses[2] = rand()%9 + 1;
		computerGuesses[3] = rand()%9 + 1;
		}
	}
	else if(playerClues0 == 1 && playerClues1 == 2)
	{
		if(i == 1)
		{
		computerGuesses[0] = guess3;
		computerGuesses[1] = rand()%9 + 1;
		computerGuesses[2] = guess2;
		computerGuesses[3] = guess1;
		}
		if(i == 2)
		{
		computerGuesses[0] = guess4;
		computerGuesses[1] = guess3;
		computerGuesses[2] = rand()%9 + 1;
		computerGuesses[3] = guess2;
		}
		if(i == 3)
		{
		computerGuesses[0] = guess4;
		computerGuesses[1] = guess1;
		computerGuesses[2] = guess2;
		computerGuesses[3] = rand()%9 + 1;
		}
		if(i == 4)
		{
		computerGuesses[0] = rand()%9 + 1;
		computerGuesses[1] = guess1;
		computerGuesses[2] = guess2;
		computerGuesses[3] = guess3;
		}
	}
	else if(playerClues0 == 1 && playerClues1 == 3)
	{
		if(i == 1)
		{
		computerGuesses[0] = guess3;
		computerGuesses[1] = guess2;
		computerGuesses[2] = guess4;
		computerGuesses[3] = guess1;
		}
		if(i == 2)
		{
		computerGuesses[0] = guess4;
		computerGuesses[1] = guess1;
		computerGuesses[2] = guess3;
		computerGuesses[3] = guess2;
		}
		if(i == 3)
		{
		computerGuesses[0] = guess3;
		computerGuesses[1] = guess1;
		computerGuesses[2] = guess2;
		computerGuesses[3] = guess4;
		}
		if(i == 4)
		{
		computerGuesses[0] = guess1;
		computerGuesses[1] = guess4;
		computerGuesses[2] = guess2;
		computerGuesses[3] = guess3;
		}
	}
	else if(playerClues0 == 2 && playerClues1 == 1)
	{
		computerGuesses[i] = rand()%9 + 1 ;
	}
	else if(playerClues0 == 2 && playerClues1 == 2)
	{
		if(i == 1)
		{
		computerGuesses[0] = guess3;
		computerGuesses[1] = guess2;
		computerGuesses[2] = guess4;
		computerGuesses[3] = guess1;
		}
		if(i == 2)
		{
		computerGuesses[0] = guess4;
		computerGuesses[1] = guess1;
		computerGuesses[2] = guess3;
		computerGuesses[3] = guess2;
		}
		if(i == 3)
		{
		computerGuesses[0] = guess3;
		computerGuesses[1] = guess1;
		computerGuesses[2] = guess2;
		computerGuesses[3] = guess4;
		}
		if(i == 4)
		{
		computerGuesses[0] = guess1;
		computerGuesses[1] = guess4;
		computerGuesses[2] = guess2;
		computerGuesses[3] = guess3;
		}
	}
	else 
	{
		computerGuesses[i] = rand()%9 + 1 ;
	}	
	//Bu k�s�mda olu�turdu�um tahminlerin rakmlar�n�n birbiriyle ayn� olmamas�n� sa�l�yorum.
	while(computerGuesses[0] == computerGuesses[1] || computerGuesses[0] == computerGuesses[2] || computerGuesses[0] == computerGuesses[3] )
    computerGuesses[0] ++;
    while(computerGuesses[1] == computerGuesses[0] || computerGuesses[1] == computerGuesses[2] || computerGuesses[1] == computerGuesses[3] )
    computerGuesses[1] ++;
    while(computerGuesses[2] == computerGuesses[0] || computerGuesses[2] == computerGuesses[1] || computerGuesses[2] == computerGuesses[3] )
    computerGuesses[2] ++;
    while(computerGuesses[3] == computerGuesses[0] || computerGuesses[3] == computerGuesses[1] || computerGuesses[3] == computerGuesses[2] )
    computerGuesses[3] ++;
	//Tamamlad���m yeni tahmin de�erini array olarak return ediyorum.
	return computerGuesses;
}

int main()
{
	
	srand(time(0)); //rand function i�in her �a��rd�g�m�zda farkl� say�lar �retmesi i�in kullan�lan bir function
	//Memeory allocation kullanarak return etti�imiz arraylerin functionlar� i�in pointer at�yorum.
	int *randomNumber1;
	int *randomNumber2;
	int *computerClues;
	//Functionlara g�nderece�im arrayler i�in memeory allocation kullan�yorum.
	int *playerClues = new int[2]; 
	int *computerGuesses = new int[4]; 
	int clueDigit1 ,clueDigit2, clueDigit3;
	int playerGuess, playerGuessBase1, playerGuessBase2, playerGuessBase3, playerGuessBase4;
	int round;	
	
	//Menu function �a��r�p kullan�c� aray�z�n� ba�lat�yorum.
	int menuSelection =	menu();
	if(menuSelection == 1)
	{
	//Konsolu menu yaz�lar�ndan temizleyip iki tane random say� �a��r�yorum.
	//Bu say�lar� yukardaki 2 tane function i�in ayr� ayr� kullanaca��m.	
    system("cls");
    randomNumber1 = randomNumberGenerator();	
    randomNumber2 = randomNumberGenerator();
    
    //Bilgisayar�n turu. Consolu temizleyip olu�turdugum randomNumber� yazd�r�yorum.
    //Oyuncudan bu say� i�in ipucu isteyip bu say�y� ve ipucuyu computerGuess function� call ediyorum.
    system("cls");
	round++;
	cout<< "                                       Round: " << round << endl;
	cout << "Computer's turn to guess!"<< endl;
    cout << endl <<  "Computer's guess is : " <<  1000*randomNumber2[3] + 100*randomNumber2[2] + 10*randomNumber2[1] + randomNumber2[0] << endl;
	cout << "Give your clues to this guess now. "<< endl;
	cout << "Same numbers in same digits are: + ";
	cin >> playerClues[0];
    cout << "Same numbers in different digits are: - ";
	cin >> playerClues[1];
	//Oyuncudan ald�g��m�z ipucu de�erleri ve yukar�da olu�turdu�um random say� ile function'� call ediyorum.
	computerGuesses = computerGuess(randomNumber2[0], randomNumber2[1], randomNumber2[2], randomNumber2[3], playerClues[0], playerClues[1]);
	
	do
	{
	//Oyuncunun turu.
	cout << endl << "Player's turn to guess!"<< endl;
	cout << endl << "Write your(4 digit) guess: "<< endl;
	cin >> playerGuess;
	cout << "Your guess is: " << playerGuess << endl ;
	//Oyuncununtahminini rakamlara ay�rarak yukar�daki functiona yolluyorum.
	playerGuessBase1 = (playerGuess) % 10 ;
	playerGuessBase2 = (playerGuess/10) % 10 ,
	playerGuessBase3 = (playerGuess/100) % 10 ;
	playerGuessBase4 = (playerGuess/1000) % 10 ;
		
	computerClues = guessingClues(playerGuessBase1, playerGuessBase2, playerGuessBase3, playerGuessBase4,randomNumber1[0],randomNumber1[1],randomNumber1[2],randomNumber1[3]);
    if(computerClues[0]==4)
	 break; //break kullanarak direkt loopdan c�k�lmas�n� sa�l�yorum. Di�er i�lemler gereksiz oldu�u i�in.
	cout <<"Clues for your guess are: + "<< computerClues[0] << " and - " << computerClues[1] << endl ;
	cout <<"Second round will begin in 4 seconds.";
	Sleep(4000); // Sleep function'� kullanarak iki tur aras�nda yaz�lar�n g�z�kmesi i�in 4 saniye bir ara b�rak�yorum.
	
	//Bilgisayar�n turu. ilk turdaki i�lemleri ayn� �ekilde yap�yoruz farkl� olarak yeni computerGueess de�erini yolluyoruz functiona.
	//Bu iki i�lemi(oyuncunun turu - bilgisayar�n turu) birle�tirip bir do-while loopuna koydum.
	//Bu loop oyuncu ya da bilgisayar kazand�g�nda yani playerClues ya da computerClues de�erlerinden biri 4 oldu�unda sonlanacak.
	system("cls");
	round++;
	cout << "                                       Round: " << round << endl;
	cout << "Computer's turn to guess!"<< endl;
	cout << endl << "Computer's guess is : " << 1000*computerGuesses[3] + 100*computerGuesses[2] + 10*computerGuesses[1] + computerGuesses[0] << endl;
	cout << "Give your clues to this guess now. "<< endl;
	cout << "Same numbers in same digits are: + ";
	cin >> playerClues[0];
	cout << "Same numbers in different digits are: - ";
	cin >> playerClues[1];	
	if(playerClues[0]==4)
	 break; //break kullanarak direkt loopdan c�k�lmas�n� sa�l�yorum. Di�er i�lemler gereksiz oldu�u i�in.
	//Oyuncudan ald�g��m�z ipucu de�erleri ve bilgisayar�n son olu�turdu�u say� ile function'� call ediyorum.
	computerGuesses = computerGuess(computerGuesses[0], computerGuesses[1], computerGuesses[2], computerGuesses[3], playerClues[0], playerClues[1]);
	
   }while(computerClues[0] != 4 || playerClues[0]!= 4);
   
    system("cls");
   // computerClues ya da playerClues de�erlerinin hangisinin 4 oldu�una bakarak kazanan� belirleyip oyunu sonland�r�yorum.
	if(computerClues[0] == 4)
	{
	cout << "                                 Congrutulations, YOU WON!!"<< endl ;
	cout << "Your correct guess: "<<  playerGuess << endl ;
	cout << "Computer's number is: "<< 1000*randomNumber1[3] + 100*randomNumber1[2] + 10*randomNumber1[1] + randomNumber1[0] << endl;
	cout << "Game ended in " << round <<" rounds."<< endl ;
	
   }
   // computerClues ya da playerClues de�erlerinin hangisinin 4 oldu�una bakarak kazanan� belirleyip oyunu sonland�r�yorum.
   if(playerClues[0] == 4)
	{
	cout << "                                 YOU LOST!! Try again."<< endl ;
	cout << "computer's correct guess is: "<< 1000*computerGuesses[3] + 100*computerGuesses[2] + 10*computerGuesses[1] + computerGuesses[0] << endl;
    cout << "Game ended in " << round <<" rounds."<< endl ;
   }
	//En sonda kullanmay� b�rakt���m�z memory allocate etti�imiz de�erleri delete kullanarak serbest b�rak�yoruz.
	delete computerClues;
	delete playerClues;
	delete computerGuesses;
	delete randomNumber1; 
	}	
	
	if(menuSelection == 4)
    cout << "Game ended.";
	return 0;
}

