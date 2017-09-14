#include <iostream>;
#include <fstream>;
#include <string>;

using namespace std;

int main()
{
	cout << "Type a filename:";
	string fileName;
	cin >> fileName; //Takes user input for the filename
	fstream file;
	file.open(fileName); //Opens the file
	if (file.is_open()) //Checks to see if the file can be opened
	{
		double first;
		int count = 0;
		file >> first; //Inputs the first number into the variable first
		if (file.fail()) //Checks to see if there is a first number
		{
			cout << "Count: " + to_string(count) << endl; //prints out the number count
			cout << "There are no numbers in this file";
			return 0; //program is ended
		}
		count++; //Counter is incremented by 1 because there was a first number
		double second;
		file >> second; //Inputs the second number in the variable second
		if (file.fail()) //Checks to see if there is a second number
		{
			cout << "Count: " + to_string(count) << endl; //prints out the number count
			cout << "The only number in this file is " + to_string(first); //prints out the only number
			return 0; //program is ended
		}
		count++; //Counter is incremented by 1 because there was a second number
		double secondLast; 
		double last;
		double copy;
		while (!file.fail()) //Inputs the next number into "secondLast" and "last" until an error occurs
		{
			file >> secondLast;
			if (!file.fail()) //If there were no errors with the above input, increment the counter by 1
				count++;

			if (file.fail() && count>2)
			{
				copy = secondLast;
				secondLast = last;
				last = copy;
			}
			
			file >> last;
			if (!file.fail()) //If there were no errors with the above input, increment the counter by 1
				count++;
			
			if (file.fail() && count>3)
			{
				copy = secondLast;
				secondLast = last;
				last = copy;
			}
		}
		
		if (count == 2) //If there are only two numbers in the file
		{
			secondLast = first; //The first number would also be the second to last
			last = second; //The second number would also be the last number
		}

		if (count == 3) //If there are only three numbers in the file
		{
			last = secondLast; //The value that "secondLast" has is our actual last number so we set last to it
			secondLast = second; //The second number would also be the second to last number
		}

		//Printing out the information:
		cout << "Count: " + to_string(count) << endl;
		cout << "First Number: " + to_string(first) << endl;
		cout << "Second Number: " + to_string(second) << endl;
		cout << "Second to Last Number: " + to_string(secondLast) << endl;
		cout << "Last Number: " + to_string(last) << endl;
		
	}
	else //If the file is unable to be opened
	{
		cout << "Unable to open file";
	}
	file.close(); //Closing the file
	cin >> fileName;
	return 0;
}