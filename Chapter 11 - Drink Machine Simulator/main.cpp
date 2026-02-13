//
#include <iostream>
using namespace std;

//Structure defining a purchasable drink type
struct Drink
{
	string name;	//Drink's name
	double cost;	//Drink's cost per unit
	int num;		//Drink's number of units
};

int main()
{	
	double profit = 0;				//Total profit made by the machine
	const int OPTIONS_SIZE = 5;		//Number of options available
	char selectionChar;				//
	int selection;					//
	double moneyInserted;			//
	
	//The preset array of options
	Drink options[OPTIONS_SIZE] = { {"Cola", 0.75, 20}, {"Root Beer", 0.75, 20},
		{"Lemon-Lime", 0.75, 20} , {"Grape Soda", 0.8, 20}, {"Cream Soda", 0.8, 20} };
	do
	{
		//Display the options
		for (int i = 0; i < OPTIONS_SIZE; i++)
		{
			Drink option = options[i];
			cout << i + 1 << ". " << option.name << " | $" << option.cost << " | " << option.num << " available\n";
		}

		//Prompt the user for input
		cout << "\nType a number to select the corresponding drink or type 'Q' to quit: ";
		cin >> selectionChar;

		//Check their inputted selection is usable
		while (!((selectionChar == 'Q' || selectionChar == 'q') || (selectionChar >= '1' && selectionChar <= '5')))
		{
			cout << "\nError: Invalid selection, please try again";
			cout << "\nType a number to select the corresponding drink or type 'Q' to quit: ";
			cin >> selectionChar;
		}

		//Convert their selection from a char to an index for the array
		selection = selectionChar - 49;
		
		//If the input was a number and in range we try to make a selection
		if (selection >= 0 && selection < OPTIONS_SIZE)
		{
			//Make sure their is a remaining quantity for that item
			if (options[selection].num <= 0)
				cout << "\nError: Stock empty, please try later";
			else
			{
				//Prompt the user for input
				cout << "\nHow much will you insert?: $";
				cin >> moneyInserted;
				//Check that it's valid
				while (moneyInserted < 0 || moneyInserted > 1)
				{
					if (moneyInserted < 0)
						cout << "\nError: Value cannot be negative, please try again";
					if (moneyInserted > 0)
						cout << "\nError: Too much money at once, please insert $1 or less";

					cout << "\nHow much will you insert?: $";
					cin >> moneyInserted;
				}
				//Let them return to the menu if too little cash was used
				if (moneyInserted < options[selection].cost)
					cout << "\nError: Insufficient value, item cannot be purchased\n";
				//Decrement the quantity if they successfully paid
				else
				{
					cout << "\n$" << moneyInserted - options[selection].cost << " returned\n";
					options[selection].num -= 1;
					//Increase the profit recorded
					profit += options[selection].cost;
				}
			}
		}
	}
	//Loop if they didn't quit
	while (!(selectionChar == 'Q' || selectionChar == 'q'));

	//Display the profit
	cout << "This machine made $" << profit << " with this operation."
		 << "\nA program by Spencer Curtis\n";
 	return 0;
}