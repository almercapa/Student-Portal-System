#include "GetValid.h"
#include <array>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctype.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  string fname, lname, guidance, dummy, cname, pnumber2, emergency2, f3, s3, t4, dash = "-", pnumber3, emergency3,psat,pconfirm;
  int grade, enroll, cnumber, assign = 0, enter, agrade, iclass, student = 0, ccount = 0, allclass = 0, classloop = 0, numreset = 1,date;
  double cred, pnumber, emergency;
  bool cellcheck = false;
  // variables
  vector<string> fnames;
  vector<string> lnames;
  vector<string> phones;
  vector<string> emergencies;
  vector<string> guidances;
  vector<string> classes;
  vector<string> psatdate;
  vector<double> credits;
  vector<double> gpas;
  vector<int> gradelvls;
  vector<int> classnums; 
  vector<int> years;
  vector <int> allclasses;
  vector<int> agrades;
  vector<int> averages;
  //vectors

  //MAIN MENU
  cout << "Welcome to the Parent Portal of MCSG (Morris County School of "
          "Griddy)\n";

  //4 options
  cout << "1. Enter student\n";
  cout << "2. View all students\n";
  cout << "3. End program";
  do {
    cout << "\nWhat would you like to do? ";
  } while ((!(getValidInt(enter)) || (enter > 3) || (enter < 0)));

  // NAME
  while (enter != 3) {
    if (enter == 1) {
      
    
    cout << "\nHello student " << (student + 1) << "!";
    
    cout << "\nWhat is your first name? ";
    cin >> fname;
    fnames.push_back(fname);//gets first name, puts into vector

    cout << "\nWhat is your last name? ";
    cin >> lname;
    lnames.push_back(lname);//gets last name, puts into vector

    // GRADE
    getline(cin, dummy);
    do {
      cout << "\nWhat grade are you (9-12)? ";
    } while ((!(getValidInt(grade)) || (grade > 12) || (grade < 9)));
    gradelvls.push_back(grade);//gets grade, puts into vector
      
    
    // YEAR OF ENROLLMENT
    do{
      cout << "\nWhat year did you enroll? ";
    } while ((!(getValidInt(enroll)) || (enroll < 2000) || (enroll > 2019)));
    years.push_back(enroll);//gets enrollment year, puts into vector
    
    // PHONE NUMBER
    do {
      cout << "\nWhat is your phone number (enter with no dashes)? ";
    } while ((!(getValidDouble(pnumber))) || pnumber > 10000000000 || pnumber < 1000000000);
    pnumber2 = to_string(pnumber);
    f3 = pnumber2.substr(0,3);
    s3 = pnumber2.substr(3,3);
    t4 = pnumber2.substr(6,4);
    pnumber3 = f3 + dash + s3 + dash + t4;
    phones.push_back(pnumber3);//error traping for phone number + gets phone number and puts into vector

    // EMERGENCY PHONE NUMBER
    do {
      cout << "\nWhat is your emergency phone number (enter with no dashes)? ";
    } while ((!(getValidDouble(emergency))) || emergency > 10000000000 || emergency < 1000000000);
    emergency2 = to_string(emergency);
      f3 = emergency2.substr(0,3);
    s3 = emergency2.substr(3,3);
    t4 = emergency2.substr(6,4);
    emergency3 = f3 + dash + s3 + dash + t4;
    emergencies.push_back(emergency3);//error traping for emergency phone number + gets emergency phone number and puts into vector

    // CLASSES & CREDITS
    do {
      cout << "\nHow many classes are you taking this year? ";
    } while (!(getValidInt(cnumber)) || cnumber > 5);
    allclass += cnumber;
    allclasses.push_back(allclass);
    classnums.push_back(cnumber);//gets amount of classes, puts into two different vectors

    for (int i = 1; i <= cnumber; i++) {
      cout << "\nWhat is the name of class " << i << "? ";
      getline(cin, cname);
      classes.push_back(cname);//gets name of class, puts into vector
      do {
        cout << "\nHow many credits is " << cname << "? ";
      } while ((!(getValidDouble(cred))) || cred > 5 || cred < 0);
      credits.push_back(cred);//gets amount of credits, puts into vector
    }

    // ASSIGNMENTS
    int allassign;
    double average;
    for (int i = 0; i < cnumber; i++) {
      do {
        cout << "\nHow many assignments do you have in " << classes[i] << "? ";
      } while (!(getValidInt(assign)) || assign <= 0);//amount of assignments

      for (int i = 0; i < assign; i++) {
        do {
          cout << "\nWhat was the grade for assignment #" << i+1 << "? ";
        } while (!(getValidInt(agrade)) || agrade < 0 || agrade > 100);
        agrades.push_back(agrade);//grade for each assignment, puts into vector
      }
      for (int i = 1; i <= assign; i++) {
        allassign += agrades[i];
      }
      average = allassign / assign;
      averages.push_back(average);//gets the average, puts into vector
    }

    //GPA
    int allgrades, scale;
    double gpa;
    for (int i = 0; i <= assign; i++) {
      if (averages[i] >= 90) {//if average is above 90
        scale = 4;
      }
      else if (averages[i] >= 80 && averages[i] < 90) {//if average is above 80 + below 90
        scale = 3;
      }
      else if (averages[i] >= 70 && averages[i] < 80) {//if average is above 70 + below 80
        scale = 2;
      }
      else if (averages[i] >= 60 && averages[i] < 70) {//if average is above 60 + below 70
        scale = 1;
      }
      else if (averages[i] < 60) {//if average is below 60
        scale = 0;
      }
      allgrades += scale;
    }
    gpa = allgrades/cnumber;
    gpas.push_back(gpa);//calculates the gpa, puts into vector


    // GUIDANCE COUNSLER
    cout << "\nWho is your guidance counselor? ";
    getline(cin, guidance);
    guidances.push_back(guidance);//gets guidance counselor, puts into vector


    //EXTRA: PSAT
    cout << "\nAre you taking the PSAT this year? (y/n) ";
    cin >> psat;//user input

    if(psat == "y" || psat == "Y"){//if they are taking it
      cout << "\nPlease pick one of the available testing dates: (pick a number)";
      cout << "\n1. April 1st, 2022; 2. May 6th, 2022; 3. June 11th, 2022; 4. June 16th, 2022\n";

      cin >> date;//user input for when they are taking it

      if(date == 1){
        cout << "\nCongrats! You are officially taking the PSAT on April 1st, 2022. Good luck!";
        pconfirm = "April 1st, 2022";//if user picks 1st option
        psatdate.push_back(pconfirm);
      }
      else if(date == 2){
        cout << "\nCongrats! You are officially taking the PSAT on May 6th, 2022. Good luck!";
        pconfirm = "May 6th, 2022";//if user picks 2nd option
        psatdate.push_back(pconfirm);
      }
      else if(date == 3){
        cout << "\nCongrats! You are officially taking the PSAT on June 11th, 2022. Good luck!";
        pconfirm = "June 11th, 2022";//if user picks 3rd option
        psatdate.push_back(pconfirm);
      }
      else if(date == 4){
        cout << "\nCongrats! You are officially taking the PSAT on June 16th, 2022. Good luck!";
        pconfirm = "June 16th, 2022";//if user picks 4th option
        psatdate.push_back(pconfirm);
      }
      else{
        cout << "\nYou did not enter a valid input. Guess your not taking the PSAT.";
        pconfirm = "N/A";//if the user didnt pick any of the options
        psatdate.push_back(pconfirm);
      }
    }
      else{
        cout << "\nOh well! I was really hoping you would take it this year.";
        pconfirm = "N/A";//if the user isnt taking the PSAT
        psatdate.push_back(pconfirm);
      }
      
      student++;
    }
    
    if (enter == 2) {
      if (student == 0) {
        cout << "\nYou have not inputted any students yet.\n";
      }
      else {
        for (int i = 0; i < student; i++) {
          cout << "\nStudent " << (i + 1) << ": " << fnames[i] << " " << lnames[i];
          cout << "\nGrade: " << gradelvls[i];
          cout << "\nYear of enrollment: " << years[i] << endl;
          for (int i = ccount; i < allclasses[classloop]; i++) {
            cout << "\nClass " << numreset << ": " << classes[i] << endl;
            numreset++;
            ccount++;
          }//prints student name, grade, year of enrollment, and the classes 
          classloop++;
          numreset = 1;
          cout << "\nPhone number: " << phones[i];
          cout << "\nEmergency contact: " << emergencies[i];
          cout << "\nGuidance counselors: " << guidances[i];
          cout << "\nGPA: " << gpas[i] << endl;
          cout << "\nPSAT Date: " << psatdate[i] << endl;
        }//prints phone Number, emergency contact, guidance counselor, gpa, and psat date (extra)
        classloop = 0;
        ccount = 0;
      }
    }
    
    cout << "\n1. Enter student\n";
    cout << "2. View all students\n";
    cout << "3. End program\n";
    do {
      cout << "What would you like to do? ";
    } while ((!(getValidInt(enter)) || (enter > 3) || (enter < 0)));//to redo the program
  }
}
