#include <iostream>
#include <vector>

int reverse(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

bool is_palindrome(int n) {
    return n > 9 && n == reverse(n);
}

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

std::vector<int> find_palindromic_primes(int n) {
    int i, index = 0;
    std::vector<int> palindromes(0);
    std::vector<int> palindromic_primes(0);
    if (n < 2) return palindromic_primes;
    for (i = 2; i < n; i++) {
        if (is_palindrome(i)) palindromes.push_back(i);
    }
    index = 0;
    for (i = 0; i < palindromes.size(); i++) {
        if (is_prime(palindromes[i])) palindromic_primes.push_back(palindromes[i]);
    }
    return palindromic_primes;
}

std::string get_algorithm_for_s_to_t_(const char* s, const char* t) {
    int i, j;
    std::string output = "";
    output.append()
    for (i = 0; s[i] != '\0'; i++) {
        
    }
    t[j] = '\0';
    return t;
}


int main() {
    int choice;
    while (true) {
        std::cout << "\nPlease, select an algorithm:";
        std::cout << "\n[1] COUNT NUMBER & IT's MIRROR OCCURRENCES IN PI";
        std::cout << "\n[2] FIND PALINDROMIC PRIMES LESS THAN n";
        std::cout << "\n[3] CHANGE s TO t ALGORITHM STEPS";
        std::cout << "\n[4] ...\n";
        std::cin >> choice;
        //choice.erase(0, choice.find_first_not_of(" \n\r\t"));
        switch (choice)
        {
        case 1:
            /* code */
            break;
        case 2: {
            std::cout << "Enter n: ";
            std::cin >> choice;
            std::cout << "Output: ";
            std::vector<int> output = find_palindromic_primes(choice);
            for (int i = 0; i < output.size(); i++) {
                std::cout << output[i] << ", ";
            }
            break;
        }
            
        default:
            std::cout << "Invalid choice! Please, enter 1, 2, 3 or 4." << std::endl;
            break;
        }
    }

    return 0;
}