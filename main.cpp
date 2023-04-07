
/* ------------------------
 Nicholas Chen       
 ICS3U1-01        
 Assignment #4: Functions   
---------------------------*/


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Question 1 

int gcf (int a, int b) {
   if (b == 0) // if b becomes 0 return a   
        return a;  
    return gcf(b, a % b); //divides a by b to get smaller number
  }
 //End of Question 1

//Question 2



double calculateHypoteneuse(int c, int d) {
  int hypoteneuse= sqrt(c*c + d*d); //calculates the hypoteneuse 
  return hypoteneuse;
}

 //End of Question 2


//Question 3

double calculateRetail(double wholesaleCost, double markupPercentage) {

  double markupValue = markupPercentage/100;
  double priceAfterMarkup = (wholesaleCost * markupValue);

  double retailPrice = priceAfterMarkup + wholesaleCost;

  return retailPrice;
  }

 //End of Question 3

  //Question 4

  double fahrenheitToCelsius(int temp) {

  return (temp-32)*5.0/9; //formula to calculate for the conversion from fahrenheit to celsius
  
}

 //End of Question 4

//Question 5

  double premiumPhoneBill(int daytime, int nighttime) {

double totalCost;
    daytime = daytime - 75; //daytime: no additional fee for first 75 min
    nighttime = nighttime - 100; //nighttime: no additional fee for first 100 min
  totalCost = daytime * 0.1 + nighttime * 0.05 + 25; //calculates total cost (daytime + nighttime)

    return totalCost;
    }

  double regularPhoneBill(double minutes) {
    
    double cost;
    if (minutes >= 50) {
      int minutesOver = minutes - 50;
      cost = (0.20 * minutesOver) + 10.00; //total cost for over 50 min
        
    }
    else {
     cost = 10.00; //cost for under 50 min
      }

   return cost;
      }
 //End of Question 5

int main() {
  int input; // menu to select questions //
  do {
    cout << "Question 1 - 1\n";
    cout << "Question 2 - 2\n";
    cout << "Question 3 - 3\n";
    cout << "Question 4 - 4\n";
    cout << "Question 5 - 5\n";
  

    cin >> input;
    switch (input) {

  //Question 1

      case 1: {
        
int x, y;
        cout << "Question 1: ";
  cout << "enter two integers: ";
  cin >> x >> y;
 cout << "the gcf is " << gcf (x, y) << endl;

        }
      break;
       //End of Question 1
        
//Question 2

      case 2: {
        
  int c, d;
         cout << "Question 2: ";
  cout << "enter two integers: ";
  cin >> c >> d;
  cout << "the value for the hypoteneuse is " << calculateHypoteneuse(c, d) << endl;
  
        }
      break;
       //End of Question 2
        
//Question 3

      case 3: {

         cout << "Question 3: ";
        
double costOfWholesale, percentageOfMarkup;
  cout << "enter the wholesale cost and the markup percentage: ";
  cin >> costOfWholesale >> percentageOfMarkup;
 //uses set precision to make the output have 2 decimals 
  cout << "$" << fixed << setprecision(2) << calculateRetail(costOfWholesale, percentageOfMarkup) << endl; 
  }
      break;
       //End of Question 3

      //Question 4

      case 4: {
        int fahrenheit;
      cout << "Question 4: ";
        cout << "The table for 0 - 20 fahrenheit converted to celsius: " << endl;
        for (int i = 0; i <= 20; i++) //loops through the cases from 0 - 20
           //uses set precision to make the output have 2 decimals 
          cout << "A fahrenheit of " << i << " is " << setprecision(4) << fahrenheitToCelsius(i) << " celsius" << endl;
        cout << "Enter a fahrenheit to be converted to celsius: ";
        cin >> fahrenheit;
        cout << "A fahrenheit of " << fahrenheit << " is equal to " << fahrenheitToCelsius(fahrenheit) << " celsius " << endl;
        
      } 
        break;
    
    //End of Question 4
    
//Question 5
      
    case 5: {
      
      int minutes, accountNum, daytimeMinutes, nighttimeMinutes, totalMinutes;
      char serviceCode;
cout << "Question 5: ";
      cout << "enter account number: ";
      cin >> accountNum;
      do {
      cout << "enter the service code: ";
      cin >> serviceCode;
        //prevents user from entering the wrong service code
       } while(serviceCode != 'p' && serviceCode != 'P' && serviceCode != 'r' && serviceCode !='R'); 
     
      //have both lowercase and uppercase cases
      if (serviceCode == 'r' || serviceCode == 'R') {
        cout << "enter the number of minutes used: ";
         cin >> minutes;
         cout << "Your account number is " << accountNum << ", your service code is regular" << ", your minutes used was " << minutes << " and your amount due is $" << fixed << setprecision(2) << regularPhoneBill(minutes) << endl;
      }
//have both lowercase and uppercase cases
      else if (serviceCode == 'p' || serviceCode == 'P') {
      cout << "enter the number of minutes used in the daytime: ";
        cin >> daytimeMinutes;
      cout << "enter the number of minutes used in the nighttime: ";
        cin >> nighttimeMinutes;
        totalMinutes = daytimeMinutes + nighttimeMinutes;
        cout << "Your account number is " << accountNum << ", your service code is premium" << ", your minutes used was " << totalMinutes << " and your amount due is $" << fixed << setprecision(2) << premiumPhoneBill(daytimeMinutes, nighttimeMinutes) << endl;
        }
      
        
      
      }
      }
    }  while (input < 6); // while loop condition for the menu //
    
    }
//End of Question 5