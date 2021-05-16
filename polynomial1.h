
#include <iostream>
using namespace std;

#define MAX_TERMS 10 /*size of terms array*/

class PolynomialTerm {
public:
	int coef;
	int expo;
};

class ArrayPolynomial {
public:
	PolynomialTerm terms[MAX_TERMS];

	void clear() /////
	{
		for (int i = 0; i < MAX_TERMS; i++) {
			terms[i].coef = 0;
			terms[i].expo = 0;
		}

		return;
	}

	void inputArrayBasedTerms(int coef, int expo)
	{
		// modify the following code and add your code here
		int i = 0;

		for (; terms[i].coef != 0 && i < MAX_TERMS; i++);

		terms[i].coef = coef;
		terms[i].expo = expo;


		// add your code here 
		for (int a = 0; terms[a].coef!=0&&terms[a].expo!=0; a++) {
			for (int j = a+1; terms[j].coef != 0 && terms[j].expo != 0; j++) {
				if (terms[a].expo > terms[j].expo) {
					PolynomialTerm temp = terms[a];
					terms[a] = terms[j];
					terms[j] = temp;
				}
			}
		}

		return;
	}

	void printArrayBasedPoly()
	{
		if (terms[0].coef == 0)
			return;

		if (terms[0].expo == 0)
			cout << terms[0].coef;
		else
			cout << terms[0].coef << "X^" << terms[0].expo;

		for (int i = 1; i < MAX_TERMS; i++) {
			if (terms[i].coef == 0)
				return;

			if (terms[i].expo == 0)
				cout << " + " << terms[i].coef;
			else
				cout << " + " << terms[i].coef << "X^" << terms[i].expo;
		}

		return;
	}

	void printArrayBasedPolyRecursively()
	{
		if (terms[0].coef == 0)
			return;

		if (terms[0].expo == 0)
			cout << terms[0].coef;
		else
			cout << terms[0].coef << "X^" << terms[0].expo;

		printArrayBasedPolyRecursively(1);
	}

	void printArrayBasedPolyRecursively(int i)
	{


		// add yor code here
		if (i == MAX_TERMS) {
			return;
		}
		if (terms[i].coef == 0 && terms[i].expo == 0) {
			return;
		}
		if (terms[i].coef == 0) {
			printArrayBasedPolyRecursively(i + 1);
		}
		else {
			if (i == 0) {
				if (terms[i].expo != 0) {
					cout << terms[i].coef << "X^" << terms[i].expo;
				}
				else {
					cout << terms[i].coef;
				}
			}
			else {
				if (terms[i].expo != 0) {
					
						cout << " + " << terms[i].coef << "X^" << terms[i].expo;
					
				}
				else {
					
						cout << " + " << terms[i].coef ;
					
				}
			}
			printArrayBasedPolyRecursively(i + 1);
		}

	}

	void ArrayBasedReverse()
	{


		// add yor code here
		int count = 0;
		while (count<MAX_TERMS) {
			if (terms[count].coef == 0 && terms[count].expo == 0) {
				break;
			}
			count++;
		}
		for (int i = 0; i < count / 2; i++) {
			PolynomialTerm temp = terms[i];
			terms[i] = terms[count -1-i];
			terms[count - 1 - i] = temp;
		}
		/*if (terms[0].expo <= terms[1].expo) {
			for (int i = 0; i < MAX_TERMS; i++) {
				for (int j = i + 1; j < MAX_TERMS; j++) {
					if (terms[i].expo <= terms[j].expo) {
						PolynomialTerm temp = terms[i];
						terms[i] = terms[j];
						terms[j] = temp;
					}
				}
			}
		}
		else {
			for (int i = 0; i < MAX_TERMS; i++) {
				for (int j = i + 1; j < MAX_TERMS; j++) {
					if (terms[i].expo > terms[j].expo) {
						PolynomialTerm temp = terms[i];
						terms[i] = terms[j];
						terms[j] = temp;
					}
				}
			}
		}*/

	}

	void ArrayBasedIncPower(int expo)
	{


		// add yor code here
		for (int i = 0; i<MAX_TERMS; i++) {
			if (terms[i].coef == 0 && terms[i].expo == 0) {
				break;
			}
			if (terms[i].expo == expo) {
				terms[i].expo++;
				for (int j = i + 1; j < MAX_TERMS; j++) {
					if (terms[j].coef == 0 && terms[j].expo == 0) {
						break;
					}
					if (terms[j].expo == terms[i].expo) {
						terms[i].coef = terms[i].coef + terms[j].coef;
						for (int k = j; k < MAX_TERMS; k++) {
							terms[k] = terms[k + 1];
						}
						terms[MAX_TERMS - 1].coef = 0;
						terms[MAX_TERMS - 1].expo = 0;
						j--;
					}
				}
				
			}
		}
		for (int i = 0; i < MAX_TERMS; i++) {
			if (terms[i].coef == 0 && terms[i].expo == 0) {
				break;
			}
			if (terms[i].coef == 0) {
				for (int j = i; j < MAX_TERMS; j++) {
					terms[j] = terms[j + 1];
				}
				terms[MAX_TERMS - 1].coef = 0;
				terms[MAX_TERMS - 1].expo = 0;
			}
		}

	}
};

class LinkedPolynomialTerm {
public:
	int coef;
	int expo;
	LinkedPolynomialTerm *nextTermPtr;
};

class LinkedPolynomial {
public:
	LinkedPolynomialTerm *polynomialTermPtr = nullptr;

	void clear()
	{
		LinkedPolynomialTerm *tmpPtr;

		while (polynomialTermPtr != nullptr) {
			tmpPtr = polynomialTermPtr;
			polynomialTermPtr = polynomialTermPtr->nextTermPtr;
			delete tmpPtr;
		}

		return;
	}
	//1 1 2 2 3 3 4 4 5 5 0 0
	void inputLinkBasedTerms(int coef, int expo)
	{
		LinkedPolynomialTerm *tmpPtr;

		tmpPtr = new LinkedPolynomialTerm;
		tmpPtr->coef = coef;
		tmpPtr->expo = expo;
		tmpPtr->nextTermPtr = polynomialTermPtr;

		polynomialTermPtr = tmpPtr;


		// add your code here 
		LinkedPolynomialTerm *current = polynomialTermPtr;
		bool isTurn = false;
		while (current->nextTermPtr != nullptr) {
			if (current->expo > current->nextTermPtr->expo) {
				int tempC = current->coef;
				int tempE = current->expo;
				current->coef = current->nextTermPtr->coef;
				current->expo = current->nextTermPtr->expo;
				current->nextTermPtr->coef = tempC;
				current->nextTermPtr->expo = tempE;
			}
			current = current->nextTermPtr;
		}
		
		
		return;
	}

	void printLinkBasedPoly()
	{
		LinkedPolynomialTerm *termPtr = polynomialTermPtr;

		if (termPtr == nullptr)
			return;

		if (termPtr->expo == 0)
			cout << termPtr->coef;
		else
			cout << termPtr->coef << "X^" << termPtr->expo;

		termPtr = termPtr->nextTermPtr;

		while (termPtr != nullptr) {
			if (termPtr->coef == 0)
				return;

			if (termPtr->expo == 0)
				cout << " + " << termPtr->coef;
			else
				cout << " + " << termPtr->coef << "X^" << termPtr->expo;

			termPtr = termPtr->nextTermPtr;
		}

		return;
	}

	void printLinkBasedPolyRecursively()
	{
		if (polynomialTermPtr == nullptr)
			return;

		if (polynomialTermPtr->expo == 0)
			cout << polynomialTermPtr->coef;
		else
			cout << polynomialTermPtr->coef << "X^" << polynomialTermPtr->expo;

		printLinkBasedPolyRecursively(polynomialTermPtr->nextTermPtr);
	}

	void printLinkBasedPolyRecursively(LinkedPolynomialTerm *currPtr)
	{


		// add yor code here
		if (currPtr == nullptr) {

			return;
		}
		else {
			if (currPtr->coef == polynomialTermPtr->coef&&currPtr->expo == polynomialTermPtr->expo) {
				cout << currPtr->coef << "X^" << currPtr->expo;
			}
			else {
				if (polynomialTermPtr->expo != 0) {
					
						cout << " + " << currPtr->coef << "X^" << currPtr->expo;
					
					
				}
				else {
					
						cout << " + " << currPtr->coef;
					
				}
			}
		}
		printLinkBasedPolyRecursively(currPtr->nextTermPtr);

	}

	void LinkBasedReverse()
	{


		// add yor code here
		LinkedPolynomialTerm* current = polynomialTermPtr;
		LinkedPolynomialTerm* tmpPtr = nullptr;
		LinkedPolynomialTerm* currTmp = nullptr;
		int count = 0;
		
		while (current != nullptr) {
			tmpPtr = new LinkedPolynomialTerm;
			tmpPtr->coef = current->coef;
			tmpPtr->expo = current->expo;
			
			if (count == 0) {
				tmpPtr->nextTermPtr = nullptr;
				currTmp = tmpPtr;
			}
			else {
				tmpPtr->nextTermPtr = currTmp;
				currTmp = tmpPtr;
			}
			current = current->nextTermPtr;
			count++;
		}
		polynomialTermPtr = tmpPtr;
	}

	void LinkBasedIncPower(int expo)
	{


		// add yor code here
		LinkedPolynomialTerm *current = polynomialTermPtr;
		while (current != nullptr) {
			if (current->expo == expo) {
				current->expo++;
				LinkedPolynomialTerm *runPtr = current;
				while (runPtr->nextTermPtr != nullptr) {
					if (runPtr->nextTermPtr->expo == current->expo) {
						current->coef = current->coef + runPtr->nextTermPtr->coef;
						runPtr->nextTermPtr = runPtr->nextTermPtr->nextTermPtr;
					}
					else {
						runPtr = runPtr->nextTermPtr;
					}
				}
			}
			current = current->nextTermPtr;
		}

	}
};
