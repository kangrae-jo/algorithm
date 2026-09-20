
class Solution {
public:
    string solveEquation(string equation) {
        int equalPos = equation.find('=');
        auto left = parse(equation.substr(0, equalPos));
        auto right = parse(equation.substr(equalPos + 1));

        int xCoeff = left.first - right.first;
        int constant = right.second - left.second;

        if (xCoeff == 0) {
            return constant == 0
                ? "Infinite solutions"
                : "No solution";
        }

        return "x=" + to_string(constant / xCoeff);
    }
private:
    // {x의 계수, 상수항}
    pair<int, int> parse(const string& expression) {
        int xCoeff = 0;
        int constant = 0;

        int i = 0;
        int n = expression.size();
        int sign = 1;
        while (i < n) {
            if (expression[i] == '+') {
                sign = 1;
                i++;
            } else if (expression[i] == '-') {
                sign = -1;
                i++;
            }

            int number = 0;
            bool hasNumber = false;
            while (i < n && isdigit(expression[i])) {
                number = number * 10 + (expression[i++] - '0');
                hasNumber = true;
            }

            if (i < n && expression[i] == 'x') {
                xCoeff += sign * (hasNumber ? number : 1);
                i++;
            } else {
                constant += sign * number;
            }
        }

        return {xCoeff, constant};
    }
};
