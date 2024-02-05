#include <iostream>
#include <string>
using namespace std;

const int size = 30;

bool isValidWeight (float weight)
{
  if (weight >= 20 && weight <= 100)
	return true;
  return false;
}

int main ()
{
  string names[size];
  float weightsFirstDay[size];
  float weightsLastDay[size];
  float weightDifference[size];

  cout << "------FIRST DAY OF TERM-------" << endl;
  for (int i = 0; i < size; ++i)
	{
	  cout << "\nEnter name for pupil " << (i + 1) << ": ";
	  getline (cin, names[i]);

	  cout << "Enter weight for pupil " << names[i] << " (in kg): ";
	  cin >> weightsFirstDay[i];

	  // Validate and input weight
	  while (!isValidWeight (weightsFirstDay[i]))
		{
		  cout << "INVALID WEIGHT! ENTER AGAIN. (20-100kg)\n";
		  cout << "Enter weight for pupil " << names[i] << " (in kg): ";
		  cin >> weightsFirstDay[i];
		}
	  cin.ignore ();
	}

  cout << "\n------STUDENT'S INFORMATION-------" << endl;
  for (int i = 0; i < size; ++i)
	{
	  cout << "\n-PUPIL " << (i + 1) << endl;
	  cout << "Name: " << names[i] << endl;
	  cout << "Weight: " << weightsFirstDay[i] << "kg" << endl;
	}
  cout << "\n------LAST DAY OF TERM-------" << endl;
  cout << "Enter weights on the last day:\n";
  for (int i = 0; i < size; ++i)
	{
	  cout << "Enter weight for pupil " << names[i] << " (in kg): ";
	  cin >> weightsLastDay[i];

	  weightDifference[i] = weightsLastDay[i] - weightsFirstDay[i];
	}
  cout << "\n------WEIGHT DIFFERENCES MORE THAN 2.5-------" << endl;
  for (int i = 0; i < size; ++i)
	{
	  // Check if the difference is more than 2.5 kg
	  if (abs (weightDifference[i]) > 2.5)
		{
		  cout << "Name: " << names[i] << endl;
		  cout << ((weightDifference[i] > 0) ? "Rise of " : "Fall of ") <<
			abs (weightDifference[i]) << " kg\n" << endl;
		}
	}
  return 0;
}
