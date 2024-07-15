#include <iostream>
#include <vector>
#include <string>
#include <cmath>

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

std::string get_algorithm_for_s_to_t_(std::string s, std::string t) {
    int i, cost = 0;
    std::string output = "";
    
    for (i = 0; i < std::min(s.size(), t.size()); i++) {
        if (s[i] == t[i]) continue;
        output.append("replace ");
        output.push_back(s[i]);
        output.append(" -> ");
        output.push_back(t[i]);
        output.append("\n");
        cost++;
    }
    if (s.size() < t.size()) {
        for (; i < t.size(); i++) {
            output.append("insert ");
            output.push_back(t[i]);
            output.append("\n");
            cost += 2;
        }
    } else {
        for (; i < s.size(); i++) {
            output.append("delete ");
            output.push_back(s[i]);
            output.append("\n");
            cost += 3;
        }
    }
    output.append("cost: ");
    output.append(std::to_string(cost));
    return output;
}

int sum_of_all_formulas(std::string s, int acc) {
    int i, sum = 0;
    if (s.size() == 0) return acc;
    for (i = 1; i <= s.size(); i++) {
        sum += sum_of_all_formulas(s.substr(i), acc + std::stoi(s.substr(0, i)));
    }
    
    return sum;
}


int main() {
    int choice;
    while (true) {
        std::cout << "\nPlease, select an algorithm:";
        std::cout << "\n[1] COUNT NUMBER & IT's MIRROR OCCURRENCES IN PI";
        std::cout << "\n[2] FIND PALINDROMIC PRIMES LESS THAN n";
        std::cout << "\n[3] CHANGE s TO t ALGORITHM STEPS";
        std::cout << "\n[4] SUM OF THE RESULTS OF ALL FORMULAS WHEN + IS INSERTED IN THIS STRING IN ALL PATTERNS\n";
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
        case 3: {
            std::string s, t;
            std::cout << "Enter s: ";
            std::cin >> s;
            std::cout << "Enter t: ";
            std::cin >> t;
            std::cout << get_algorithm_for_s_to_t_(s, t);
            break;
        }
        case 4: {
            std::string s;
            std::cout << "Enter s: ";
            std::cin >> s;
            std::cout << "Output: " << sum_of_all_formulas(s, 0);
            break;
        }
            
        default:
            std::cout << "Invalid choice! Please, enter 1, 2, 3 or 4." << std::endl;
            break;
        }
    }

    return 0;
}