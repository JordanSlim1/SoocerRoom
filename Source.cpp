#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<time.h>

using namespace std;

int main()
{
	string seniors[] = { "Lauren Mercuri","Camille Bassatt","Autum Shwartz","Kelsey Quick","Kristen Ricks" , "Sav Tidd" };
	string juniors[] = { "Jordan Slim","Connie Awuku","Bria Williams","Bridget Mansour" };
	string others[] = { "Mia Graff","Mo Hurd","Morgan Rollow","Reagan McCombs","Taylor Webb","Gracie Hair", "Ani Sultan", "Lily Sultan", "Dawson Depperschmidt","Hadley Dickinson","Haylee Hulse", "Kirsten Rumbold", "Lauren Hargus" };
	string rooms[26];
	char repeat;
	int index;
	srand((unsigned)time(NULL));

	do {
		int counter = 0;
		bool check;
		int svalue[6];
		string temp[6];
		int jvalue[4];
		string temp1[4];
		int ovalue[13];
		string temp2[13];

		for (int i = 0; i < 6; i++)
		{
			int n; //variable to store the number in
			do
			{
				n = rand() % 6;
				//check or number is already used:
				check = true;
				for (int j = 0; j < i; j++)
					if (n == svalue[j]) //if number is already used
					{
						check = false; //set check to false
						break; //no need to check the other elements of value[]
					}
			} while (!check); //loop until new, unique number is found
			svalue[i] = n; //store the generated number in the array
			temp[n] = seniors[i];
		}
		for (int i = 0; i < 6; i++)
		{
			seniors[i] = temp[i];
		}
		for (int i = 0; i < 4; i++)
		{
			int n; //variable to store the number in
			do
			{
				n = rand() % 4;
				//check or number is already used:
				check = true;
				for (int j = 0; j < i; j++)
					if (n == jvalue[j]) //if number is already used
					{
						check = false; //set check to false
						break; //no need to check the other elements of value[]
					}
			} while (!check); //loop until new, unique number is found
			jvalue[i] = n; //store the generated number in the array
			temp1[n] = juniors[i];
		}
		for (int i = 0; i < 4; i++)
		{
			juniors[i] = temp1[i];
		}
		for (int i = 0; i < 13; i++)
		{
			int n; //variable to store the number in
			do
			{
				n = rand() % 13;
				//check or number is already used:
				check = true;
				for (int j = 0; j < i; j++)
					if (n == ovalue[j]) //if number is already used
					{
						check = false; //set check to false
						break; //no need to check the other elements of value[]
					}
			} while (!check); //loop until new, unique number is found
			ovalue[i] = n; //store the generated number in the array
			temp2[n] = others[i];
		}
		for (int i = 0; i < 13; i++)
		{
			others[i] = temp2[i];
		}
		for (int i = 0; i < 6; i++)
		{
			index = 3 * i;
			rooms[index] = seniors[i];
			counter++;
		}

		for (int i = 0; i < 4; i++)
		{
			if (counter >= 8)
			{
				index = 3 * (counter % 8) + 1;
				rooms[index] = juniors[i];
				counter++;
			}
			else
			{
				index = 3 * counter;
				rooms[index] = juniors[i];
				counter++;
			}
		}
		for (int i = 0; i < 13; i++)
		{
			if (counter >= 16)
			{
				index = 3 * (counter % 8) + 2;
				rooms[index] = others[i];
				counter++;
			}
			else 
			{
				index = 3 * (counter % 8) +1;
				rooms[index] = others[i];
				counter++;
			}
		} 
		
		for (int i = 0; i < 24; i++)
		{
			if (i % 3 == 0)
			{
				cout << "----------------- Room " << (i + 3) / 3 << " -----------------" << endl;
			}
			cout << rooms[i] << endl;
		}
		cout << "\nWould you like to repeat the program?(y/n)" << endl;
		cin >> repeat;
	} while (repeat == 'y');
}