#include <bits/stdc++.h>
#include<stack> 
using namespace std;

// 判断字符类型
int judge(char c) {
    if (c <= '9' && c >= '0')
        return 1;
    else if (string("+-*/()#").find(c) != string::npos)
        return 2;
    else
        return 3;
}

// 获取运算符优先级
int valueSignal(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

// 比较运算符优先级
bool comSignal(char left, char right) {
    if (valueSignal(left) < valueSignal(right))
        return 1;
    else
        return 0;
}

// 根据运算符计算结果
int solve(int left, int right, char signal) {
    switch (signal) {
        case '+':
            return left + right;
            break;
        case '-':
            return left - right;
            break;
        case '*':
            return left * right;
            break;
        case '/':
            return left / right;
    }
    return 0;
}

// 处理栈中的运算符和数字
void handle(stack<int> &nums, stack<char> &signal) {
    int right = nums.top();
    nums.pop();
    int left = nums.top();
    nums.pop();
    char c = signal.top();
    signal.pop();
    nums.push(solve(left, right, c));
}

int main() {
    stack<int> nums; // 存储数字的栈
    stack<char> signal; // 存储运算符的栈
    string s, tmp;
    cin >> s;
    for (int i = 0; i < (int) s.length(); i++) {
        if (judge(s[i]) == 3) { // 如果字符不是数字或运算符，输出"NO"并退出
            cout << "NO" << endl;
            return 0;
        } else if (judge(s[i]) == 1) 
            tmp += s[i]; // 如果字符是数字，将其添加到临时字符串中
        else {
            if (!tmp.empty()) { // 如果临时字符串不为空，将其转换为整数并压入数字栈中
                nums.push(atoi(tmp.c_str()));
                tmp = "";
            }
            if (s[i] == '#') { // 如果遇到结束符，处理剩余的运算符和数字
                while (!signal.empty())
                    handle(nums, signal);
                break;
            } else if (signal.empty() || s[i] == '(' || comSignal(signal.top(), s[i])) 
                signal.push(s[i]); // 如果运算符栈为空，或者当前运算符为左括号，或者当前运算符优先级高于栈顶运算符，将当前运算符压入栈中
            else if (s[i] == ')') { // 如果遇到右括号，处理括号内的运算符和数字
                while (signal.top() != '(') {
                    handle(nums, signal);
                }
                signal.pop(); // 弹出左括号
            } else { // 如果当前运算符优先级不高于栈顶运算符且不是左括号，处理栈顶运算符和数字，然后将当前运算符压入栈中
                while (!signal.empty() && s[i] != '(' && !comSignal(signal.top(), s[i]))
                    handle(nums, signal);
                signal.push(s[i]);
            }
        }
    }
    cout << nums.top() << endl; // 输出最终结果
    return 0;
}

