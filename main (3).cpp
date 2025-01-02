/*
Name: Priyanjali Rudra
Date: Nov 1, 2023
Prof: Mitchell D. Theys
Environment used: Replitt

*/
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip> 
#include <string>
#include <cctype>
using namespace std;

//Restaurant Class -> contains constructor,setter(mutator) methods,accessor(getter) methods, public variables and private variables

class Restaurant {
  public:
    //constructor
    Restaurant(string name,string address, string inspDate, string risk,string inspResult, string neighborhood) {
      this->name = name;
      this->address = address;
      this->inspDate = inspDate;
      this->risk = risk;
      this->inspResult= inspResult;
      this->neighborhood = neighborhood;
    }
    //setter Methods declaration
    void setName(string name);
    void setAddress(string address);
    void setInspDate(string inspDate);
    void setRisk(string risk);
    void setInspResult(string inspResult);
    void setNeighborhood(string neighborhood);

    //getter Methods declaration
    string getName();
    string getAddress();
    string getInspDate();
    string getRisk();
    string getInspResult();
    string getNeighborhood();

  //user cannot access these w/o getter methods
  private:
    string name;
    string address;
    string inspDate;
    string risk;
    string inspResult;
    string neighborhood;
};

//Definitions:

//getName() --> outputs name of restaurant to user
//setName() --> allows user to change the name of a restaurant
string Restaurant::getName(){
  return this->name;
}

void Restaurant::setName(string name){
  this->name = name;
}
//---------------------------------------------
//getAddress() --> outputs address of restaurant to user
//setAddress() --> allows user to change the address of a restaurant
string Restaurant::getAddress(){
  return this->address;
}

void Restaurant::setAddress(string address){
  this->address = address;
}
//---------------------------------------------
//getInspDate() --> outputs inspection date of restaurant to user
//setInspDate() --> allows user to change the inspection date of a restaurant
string Restaurant::getInspDate(){
  return this->inspDate;
}

void Restaurant::setInspDate(string inspDate){
  this->inspDate = inspDate;
}
//----------------------------------------------
//getRisk() --> outputs risk of restaurant to user
//setRisk() --> allows user to change the risk of a restaurant
string Restaurant::getRisk(){
  return this->risk;
}

void Restaurant::setRisk(string risk){
  this->risk = risk;
}
//----------------------------------------------
//getInspResult() --> outputs inspection result of restaurant to user
//setInspResult() --> allows user to change the inspection result of a restaurant
string Restaurant::getInspResult(){
  return this->inspResult;
}

void Restaurant::setInspResult(string inspResult){
  this->inspResult = inspResult;
}
//----------------------------------------------------
//getNeighborhood() --> outputs neighborhood of restaurant to user
//setNeighborhood() --> allows user to change the neighborhood of a restaurant
string Restaurant::getNeighborhood(){
  return this->neighborhood;
}

void Restaurant::setNeighborhood(string neighborhood){
  this->neighborhood = neighborhood;
}
//------------------------------------------------------

//Function summary: Displays the number of restaurants, the number that passed, and the most recent passing inspection (the name of the restaurant and the date of the inspection) 
void InspectionInfo(vector<Restaurant> restaurants){

  int monthMax = 0; 
  int dateMax = 0;
  int yearMax = 0;
  string restaurantMax; 
  string numberDate;

  cout << "Your choice:" << endl;
  cout << endl;
  cout << "Number of restaurants: " << restaurants.size() << endl;
  int passing = 0;

  for (unsigned i = 0; i < restaurants.size(); i++){
    if (restaurants.at(i).getInspResult() == "Pass" || restaurants.at(i).getInspResult() == "Conditional" ){
      passing++;

      int month1 = std::stoi(restaurants.at(i).getInspDate().substr(0, 2)); 
      int date1 = std::stoi(restaurants.at(i).getInspDate().substr(3, 2));
      int year1 = std::stoi(restaurants.at(i).getInspDate().substr(6,4));

      if((year1 > yearMax) || ((year1 == yearMax) && (month1>monthMax)) || ((year1==yearMax) && (month1 == monthMax) && (date1 > dateMax))) {
        monthMax = month1; //stores greater month,day,year until largest date is stored
        dateMax = date1;
        yearMax = year1;
        restaurantMax = restaurants.at(i).getName();
        numberDate= restaurants.at(i).getInspDate();
      }
    }
  }
  cout << "Number that pass: " << passing << endl;
  cout << "Most recent passing inspection was of " <<restaurantMax << " on " << numberDate << endl;
}

//Problem: Works but cannot output risk percentages with only one digit after decimal
//Function summary: displays the percentage of high, medium, and low risk inspections, with each number shown with one decimal place. 
void RiskInfo(vector<Restaurant> restaurants){
  cout << "Your choice: 2" << endl;
  int highRisk=0;
  int midRisk=0;
  int lowRisk=0;

  for (unsigned i = 0; i < restaurants.size(); i++){
    if (restaurants.at(i).getRisk() == "H"){
      highRisk++;
    }
    else if (restaurants.at(i).getRisk() == "M"){
      midRisk++;
    }
    else if (restaurants.at(i).getRisk() == "L"){
      lowRisk++;
    }
  }

  cout << endl;

  double HighRiskPercent = (double) highRisk / restaurants.size() * 100;
  cout << "High risk: "<< HighRiskPercent << "%" << endl;

  double MidRiskPercent = (double) midRisk / restaurants.size() * 100;
  cout << "Medium risk: "<< MidRiskPercent << "%" << endl;

  double LowRiskPercent = (double) lowRisk / restaurants.size() * 100;
  cout << "Low risk: " << LowRiskPercent << "%" << endl;
}

//Function summary: The program should list each neighborhood in the file once, along with the number of restaurants which passed, conditional passed, and failed in separate columns.
void PassingNumbers(vector<Restaurant> (restaurants)){
  vector <Restaurant> neighborhoods;
  //loop finds all neighborhoods and stores them in an vector
  for (unsigned i = 0; i < restaurants.size(); i++){
    bool notFound = true;
    for (unsigned j = 0; j < neighborhoods.size(); j++){
      if (restaurants.at(i).getNeighborhood() == neighborhoods.at(j).getNeighborhood()){
        notFound = false;
        break;
      }
    }
    if (notFound){
      neighborhoods.push_back(restaurants.at(i));
    }
  }

  cout << "Your choice: 3" << endl;
  cout << "Neighborhood" << "               " << "Passed" << " " << "Cond. Pass" << "     " << "Failed" << endl;
  cout << "============" << "               " << "=======" << " " << "==========" << "     " << "=======" << endl;

  for (unsigned j = 0; j < neighborhoods.size(); j++){
    int passing = 0;
    int conditional = 0;
    int failed = 0;

    cout << neighborhoods.at(j).getNeighborhood() << setw(34-(neighborhoods.at(j).getNeighborhood().length()));
    for (unsigned i = 0; i < restaurants.size(); i++) {
      if (neighborhoods.at(j).getNeighborhood() == restaurants.at(i).getNeighborhood()){ //why
        if (restaurants.at(i).getInspResult() == "Pass") {
          passing++;
        }
        else if (restaurants.at(i).getInspResult() == "Conditional") {
          conditional++;
        }
        else if (restaurants.at(i).getInspResult() == "Fail") {
          failed++;
        }
      }
    }
    cout << passing << setw(11) << conditional << setw(12) << failed << endl;
  }
}

//Function summary: Makes any strings uppercase
string toUpperCase(string restName){
  int curNameLength; 
  int index; 

  string upperCase; 
  curNameLength = restName.length();

  for(int i = 0; i < curNameLength; i++){
    index = restName.at(i); 
    upperCase.push_back(toupper(index));
  }
  return upperCase;

}

//Function summary: Prompts the user for a name and then looks through all restaurants and display any whose name contains what the user entered (ignoring case).
void Search(vector<Restaurant> restaurants){
  cout << "Your choice: 4" << endl;

  string restaurantSearch;
  cout << "Enter restaurant to search for: ";
  cin.ignore(); //stops infinite loop
  getline(cin,restaurantSearch);  
  string temp = "";
  temp = toUpperCase(restaurantSearch); // function toUpperCase 

  for(unsigned i = 0; i < restaurants.size();i++) {
    string restCurr = restaurants.at(i).getName();
    temp = toUpperCase(restaurantSearch); // function toUpperCase 

    if(restCurr.find(temp) != string::npos) {
      cout << "Restaurant: " << restaurants.at(i).getName() << endl;
      cout << "Address: " << restaurants.at(i).getAddress() << endl;
      cout << "Inspection Date: " << restaurants.at(i).getInspDate() << endl;
      cout << "Inspection Result: " << restaurants.at(i).getInspResult() << endl;
      cout << endl;
    }
  }
}


//Function summary: Checks whether file is valid 
bool isFileValid(string locationFile) { //Checks whether file is valid and opens without error
  ifstream restaurantFile;
  restaurantFile.open(locationFile);
  if (restaurantFile.is_open()) {
    return true;
  }
  else {
    return false;
  }
  restaurantFile.close();
}

//Function summary: Leaves program
void Exit() { //Allows user to continue playing until they quit
  cout << "Your choice: 5" << endl;
}

int main() {
  string fileName;
  vector<Restaurant> restaurants;
  cout << "Enter fileName"<<endl;
  cin >> fileName;

  ifstream restaurantFile;
  restaurantFile.open(fileName);
  // to do: Create a vector of all restaurants from the file
  // hint: getline(infile, name, ',');

  while (!restaurantFile.eof()) {
  string name, address, date, risk, inspResult, neighborhood /*...*/;
    getline(restaurantFile,name,',');
    getline(restaurantFile,address,',');
    getline(restaurantFile,date,',');
    getline(restaurantFile,risk,',');
    getline(restaurantFile,inspResult,',');
    getline(restaurantFile,neighborhood);
    Restaurant restaurant1(name, address, date, risk, inspResult, neighborhood);
    restaurants.push_back(restaurant1);
  }
  int userInput;

  if (isFileValid(fileName)) { //Checks if file exists and opens without error
    cout << "Select a menu option: " << endl;
    cout << "   1. Display overall inspection information" << endl;
    cout << "   2. Display risk percentages" << endl;
    cout << "   3. Display passing numbers by neighborhood" << endl;
    cout << "   4. Search for restaurant by name" << endl;
    cout << "   5. Exit" << endl;
    cin >> userInput;

    if (userInput == 1) {
      InspectionInfo(vector<Restaurant>(restaurants));
    }
    else if (userInput == 2) {
      RiskInfo(vector<Restaurant>(restaurants));
    }
    else if (userInput == 3) {
      PassingNumbers(vector<Restaurant> (restaurants));
    }
    else if (userInput == 4){
      Search(vector<Restaurant> (restaurants));
    }
    else if (userInput == 5) {
      Exit();
    }
  }
}