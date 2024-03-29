#include <iostream>
#include <string.h>

using namespace std;

int main() {
    const int maximum= 11;
    char newUsername[maximum], newPassword[maximum];
    char savedUsername[maximum], savedPassword[maximum];
    int choice2;
    int maxCategories;
    int NumofIncome;
    double* AmountofEachIncome = nullptr;
    string* incomeSources = nullptr;
    string* categories = nullptr;
    double* budgets = nullptr;
    double* expenses = nullptr;
    int NumofBills;
    string *billName = nullptr;
    double *billAmount = nullptr;
    string *Due_date = nullptr;
    double TotalAmountofIncome = 0;
    double TotalAmountofexpense = 0;
    double CurrentBalance = 0;

    while (true) {
        cout << "\nOptions:"<< endl;
        cout << "1. SignUp" << endl;
        cout << "2. SignIn" << endl;
        cout << "3. Exit" << endl;
        cout << "\nEnter your choice " << endl;
        int choice1;
        cin >> choice1;
        cin.ignore();

        switch (choice1) {
            case 1:
               // Set the username and password
               cout << "Set your username: ";
               cin.getline(newUsername, 11);

               cout << "Set your password: ";
               cin.getline(newPassword, 11);

               cout << "Successfully created an account" << endl;
               break;
            case 2:
               // Ask the user to enter their credentials to log in
               cout << "Enter your username: ";
               cin.getline(savedUsername, 11);

               cout << "Enter your password: ";
               cin.getline(savedPassword, 11);

               // Check if the entered username and password match the stored values
               if (strcmp(savedUsername, newUsername) == 0 && strcmp(savedPassword, newPassword) == 0) {
               // Welcome message
                cout << "\nWelcome to personal finance manager!" << endl;
               cout << "\nLogin successful! Welcome, " << savedUsername << "!" << endl;
               while (true) {
        cout << "\nMenu:\n";
        cout << "1. Income tracking\n";
        cout << "2. Setting Budget\n";
        cout << "3. Expense tracker\n";
        cout << "4. Add a reminder\n";
        cout << "5. Expense analysis \n";
        cout << "6. Current Balance and Summary\n";
        cout << "7. LogOut\n";
        cout << "Enter your choice: ";
        cin>> choice2;

        switch (choice2) {
            case 1: 
                int NumofIncome;
                cout << "Enter the number of your monthly sources of incomes: ";
                cin >> NumofIncome;

                //  Input Income 
                 AmountofEachIncome = new double[NumofIncome];
                 incomeSources= new string[NumofIncome];
                
            for (int i = 0; i < NumofIncome; i++) {
                cout << "Income Source " << i + 1 << ": ";
                cin >> incomeSources[i];}
            for (int i = 0; i < NumofIncome; i++) {
                cout << "Enter income for " << incomeSources[i] << ": Birr";
                cin >> AmountofEachIncome[i];
                
            }

                 
                break;
            
              // set budget
            case 2: 
                cout << "Enter the number of your monthly expense categories: "; 
                cin >> maxCategories;

                categories = new string[maxCategories];
                budgets = new double[maxCategories];
                expenses = new double[maxCategories];

                // Get expense categories
                for (int i = 0; i < maxCategories; i++) {
                    cout << "Enter the Expense category " << i + 1 << ": ";
                    cin >> categories[i];
                    
                }

                // Set budget amount for each expense category
                for (int i = 0; i < maxCategories; i++) {
                    cout << "Enter your budget for " << categories[i] << " expenses: Birr";
                    cin >> budgets[i];}
                
                
                break;

            // Expense tracker
            case 3: 
                expenses= new double[maxCategories];
                
               for (int i = 0; i < maxCategories; i++) {
                   cout << "Enter your monthly expenses for " << categories[i] << ": Birr";
                   cin >> expenses[i];
                  if (expenses[i] > budgets[i]) {
                   cout << "WARNING: Expenses for " << categories[i] << " exceed the budget!" << endl;
        }  
                   }
                
               
                    
                break;
            

            // Add a reminder
            case 4: 
                int NumofBills;
                cout << "Enter the number of bills to be paid: ";
                cin >> NumofBills;
                 billName= new string[NumofBills];
                 billAmount= new double[NumofBills];
                 Due_date= new string[NumofBills];
                for(int i=0; i<NumofBills; i++){
                   cout << "Enter the name of bill " << i+1 <<" : " ;
                   cin>> billName[i];}
                for(int i=0; i<NumofBills; i++){
                   cout <<"Enter the amount for " << billName[i] << "bill: Birr" ;
                   cin>> billAmount[i];}
                for(int i=0; i<NumofBills; i++){
                   cout << "Enter the due date (dd/mm/yyyy) for "<< billName[i] << "bill: ";
                   cin>> Due_date[i];}
                
              break;
            
            // expense analysis
             case 5:  
               cout << "\n Expense Analysis" << endl;
                for (int i = 0; i < maxCategories; i++) {
                    if (expenses[i] > budgets[i]) {
                        cout << "You have exceeded your budget for " << categories[i] << " expenses!" << endl;
                    } else if (expenses[i] < budgets[i]) {
                        cout << "You have spent less than your budget for " << categories[i] << " expenses." << endl;
                    } else {
                        cout << "You have spent exactly your budget for " << categories[i] << " expenses." << endl;
                    }}

                
                    break;
            
           
               
            // current balance
            case 6: 

            // Display budget, expenses, and income summary
            cout << "\nBudget, Expense, and Income Summary:" << endl;
            cout << "--------------------------------------" << endl;
            cout << "Budget Categories:" << endl;
            for (int i = 0; i < maxCategories; i++) {
                cout << "Category: " << categories[i] << "\tBudget: Birr" << budgets[i] << "\tExpenses: Birr" << expenses[i] << endl;
            }

            cout << "\nIncome Sources:" << endl;
            for (int i = 0; i < NumofIncome; i++) {
                cout << "Source: " << incomeSources[i] << "\tIncome: Birr" << AmountofEachIncome[i] << endl;
            }
            // show reminders
            cout << "Bills to be paid" << endl;
                for(int i=0; i<NumofBills; i++){
                cout << i+1 <<". " << billName[i]<< ": Birr" << billAmount[i] <<"\t";
                cout << "Due Date: " << Due_date[i] << endl;}

            // overall balance
                for (int i = 0; i < NumofIncome; i++) {
                     TotalAmountofIncome += AmountofEachIncome[i];}
                for (int i = 0; i < maxCategories; i++) {
                      TotalAmountofexpense += expenses[i];}

                CurrentBalance = TotalAmountofIncome - TotalAmountofexpense;
                cout << "Total monthly income: Birr" << TotalAmountofIncome << endl;
                cout << "Total monthly expense: Birr" << TotalAmountofexpense << endl;
                cout << "Your Current balance: Birr" << CurrentBalance << endl;
                delete[] AmountofEachIncome;
                delete[] incomeSources;
                delete[] budgets;
                delete[] categories; 
                delete[] expenses;
                delete[] billName;
                delete[] billAmount;
                delete[] Due_date;

                break;
                
            
            // log out
             case 7:  
                        cout << "\nyou are logged out. \n";
                      goto logout; 
            default: 
                        cout << "Invalid option. Please try again.\n";}}
               
               
               
               } else {
               cout << "Invalid username or password. Try Again." << endl;
               }
               break;
            case 3:
                cout << "\nExiting program.\n";
                
                return 0;

            default:
                cout << "Invalid option. Please try again.\n";
                continue;
                }
                logout : continue;
    }
    return 0;
}
