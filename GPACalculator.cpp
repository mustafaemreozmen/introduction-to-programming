#include <iostream>
using namespace std;

bool controlFunction(double sayi) 
{
	if (sayi < 0 || sayi > 100)
		return false;
	return true;
}

void wrongInputError() 
{
	cout << "Gecersiz deger." << endl;
	system("PAUSE");
}

int main()
{
	//Note from the future: Now I know the array. Hurray! But If you're not learned yet, this is the best way :P
	double scoreFirstHomework;
	double scoreSecondHomework;
	double scoreFirstQuiz;
	double scoreSecondQuiz;
	double scoreFinal;
	double scoreVisa;
	double homeworkOnePercent;
	double homeworkTwoPercent;
	double visaPercent;
	double finalPercent;
	double quizOnePercent;
	double quizTwoPercent;
	double totalScore;				

	cout << "Yilsonu Gecme Notunun Harf Karsiligini Bulan Program:" << endl << endl;
	cout << "Vize Notunuzu Giriniz:";
	cin >> scoreVisa;
	if (controlFunction(scoreVisa) != true)  
	{
		wrongInputError();
		return 0;
	}	
	cout << "1.Homework:";
	cin >> scoreFirstHomework;
	if (controlFunction(scoreFirstHomework) != true) 
	{
		wrongInputError();
		return 0;
	}	
	cout << "2.Homework:";
	cin >> scoreSecondHomework;
	if (controlFunction(scoreSecondHomework) != true) 
	{
		wrongInputError();
		return 0;
	}	
	cout << "1.Quiz:";
	cin >> scoreFirstQuiz;
	if (controlFunction(scoreFirstQuiz) != true) 
	{
		wrongInputError();
		return 0;
	}
	cout << "2.Quiz:";
	cin >> scoreSecondQuiz;
	if (controlFunction(scoreSecondQuiz) != true) 
	{
		wrongInputError();
		return 0;
	}	
	cout << "Final:";
	cin >> scoreFinal;
	if (controlFunction(scoreFinal) != true) 
	{
		wrongInputError();
		return 0;
	}
	system("@cls||clear");
	cout << "Visa Percent?:";
	cin >> visaPercent;
	if (controlFunction(visaPercent) != true) 
	{
		wrongInputError();
		return 0;
	}
	visaPercent /= 100;	
	cout << "1. Homework Percent?:";
	cin >> homeworkOnePercent;
	if (controlFunction(homeworkOnePercent) != true) 
	{
		wrongInputError();
		return 0;
	}
	homeworkOnePercent /= 100;
	cout << "2. Homework Percent?:";
	cin >> homeworkTwoPercent;
	if (controlFunction(homeworkTwoPercent) != true) 
	{
		wrongInputError();
		return 0;
	}
	homeworkTwoPercent /= 100;
	cout << "1. Quiz Percent?:";
	cin >> quizOnePercent;
	if (controlFunction(quizOnePercent) != true) 
	{
		wrongInputError();
		return 0;
	}
	quizOnePercent /= 100;
	cout << "2. Quiz Percent?:";
	cin >> quizTwoPercent;
	if (controlFunction(quizTwoPercent) != true)
	{
		wrongInputError();
		return 0;
	}
	quizTwoPercent /= 100;
	cout << "Final Percent?:";
	cin >> finalPercent;
	if (controlFunction(finalPercent) != true)
	{
		wrongInputError();
		return 0;
	}
	finalPercent /= 100;
	

	system("@cls||clear");
	cout << "Visa:";
	scoreVisa = (scoreVisa * visaPercent); 
	cout << scoreVisa << endl;
	cout << "Homework:";
	scoreFirstHomework = ((scoreFirstHomework*homeworkOnePercent)+(scoreSecondHomework*homeworkTwoPercent));
	cout << scoreFirstHomework << endl;
	cout << "Quiz:";
	scoreFirstQuiz = ((scoreFirstQuiz*quizOnePercent) + (scoreSecondQuiz*quizTwoPercent));
	cout << scoreFirstQuiz << endl;
	cout << "Final:";
	scoreFinal = (scoreFinal*finalPercent);
	cout << scoreFinal << endl;
	cout << "Total Year-End Score:";
	totalScore = scoreFinal + scoreFirstHomework + scoreFirstQuiz + scoreVisa;
	cout << totalScore << endl;

	if (totalScore <= 100 && totalScore >= 90) 
		cout << "AA." << endl;
	else if (totalScore <=89 && totalScore >= 85)
		cout << "BA." << endl;
	else if (totalScore <= 84 && totalScore >= 80)
		cout << "BB." << endl;
	else if (totalScore <= 79 && totalScore >= 75)
		cout << "CB." << endl;
	else if (totalScore <= 74 && totalScore >= 65)
		cout << "CC." << endl;
	else if (totalScore <= 64 && totalScore >= 58)
		cout << "DC." << endl;
	else if (totalScore <= 57 && totalScore >= 50)
		cout << "DD."<< endl;
	else
		cout << "FF." << endl;
	
	system("PAUSE");
    return 0;
}

