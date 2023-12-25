#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

const int NUM_CHARITIES = 3;

void displayCharities(const std::string charities[]) {
    std::cout << "Charities:\n";
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        std::cout << i + 1 << ". " << charities[i] << "\n";
    }
}

int getValidChoice() {
    int choice;
    while (true) {
            std::cout << "*********************************************************\n";
        std::cout << "Enter your choice (1, 2, 3, or -1 to show totals): ";
        std::cin >> choice;
        if (choice >= -1 && choice <= NUM_CHARITIES) {
            return choice;
        } else {
            std::cout << "Invalid choice. Please enter 1, 2, 3, or -1.\n";
        }
    }
}

double getShoppingBill() {
    double bill;
    std::cout << "*********************************************************\n";
    std::cout << "Enter the shopping bill: $";
    std::cin >> bill;
    return bill;
}

void recordDonation(const std::string charities[], double totals[]) {
    int choice = getValidChoice();

    if (choice == -1) {
        return; // exit the function if user chooses to show totals
    }

    double bill = getShoppingBill();
    double donation = bill * 0.01;

    // Update totals
    totals[choice - 1] += donation;

    // Output donation details
    std::cout << "Donated $" << std::fixed << std::setprecision(2) << donation
              << " to " << charities[choice - 1] << ".\n";
}

void showTotals(const std::string charities[], const double totals[]) {
    std::cout << "*********************************************************\n";
    std::cout << "*********************************************************\n";
    std::cout << "Charity Totals (in descending order):\n";

    // Create a copy of indices for sorting
    int indices[NUM_CHARITIES];
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        indices[i] = i;
    }

    // Sort indices based on totals
    std::sort(indices, indices + NUM_CHARITIES, [&](int a, int b) {
        return totals[a] > totals[b];
    });

    for (int i = 0; i < NUM_CHARITIES; ++i) {
        int index = indices[i];
        std::cout << charities[index] << ": $" << std::fixed << std::setprecision(2) << totals[index] << "\n";
    }
}

void showGrandTotal(const double totals[]) {
    double grandTotal = 0;
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        grandTotal += totals[i];
    }

    std::cout << "GRAND TOTAL DONATED TO CHARITY: $" << std::fixed << std::setprecision(2) << grandTotal << "\n";
    std::cout << "*********************************************************\n";

}

int main() {
    std::string charities[NUM_CHARITIES];
    double totals[NUM_CHARITIES] = {0};

    // Task 1: Set up the donation system
    for (int i = 0; i < NUM_CHARITIES; ++i) {
            std::cout << "*********************************************************\n";
        std::cout << "Enter the name of Charity " << i + 1 << ": ";
        std::cin >> charities[i];
    }

    // Task 2 and Task 3: Record and total each donation
    int customerCount = 0;
    while (true) {
        std::cout << "Customer " << customerCount + 1 << ":\n";
        recordDonation(charities, totals);

        // Allow user to enter -1 to show totals
        int choice = getValidChoice();
        if (choice == -1) {
            showTotals(charities, totals);
            showGrandTotal(totals);
            break;
        }
        std::cout << "*********************************************************\n";
        customerCount++;
    }

    return 0;
}
