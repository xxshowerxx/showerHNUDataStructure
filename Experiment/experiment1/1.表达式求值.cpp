#include <bits/stdc++.h>
#include<stack> 
using namespace std;

// �ж��ַ�����
int judge(char c) {
    if (c <= '9' && c >= '0')
        return 1;
    else if (string("+-*/()#").find(c) != string::npos)
        return 2;
    else
        return 3;
}

// ��ȡ��������ȼ�
int valueSignal(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

// �Ƚ���������ȼ�
bool comSignal(char left, char right) {
    if (valueSignal(left) < valueSignal(right))
        return 1;
    else
        return 0;
}

// ���������������
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

// ����ջ�е������������
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
    stack<int> nums; // �洢���ֵ�ջ
    stack<char> signal; // �洢�������ջ
    string s, tmp;
    cin >> s;
    for (int i = 0; i < (int) s.length(); i++) {
        if (judge(s[i]) == 3) { // ����ַ��������ֻ�����������"NO"���˳�
            cout << "NO" << endl;
            return 0;
        } else if (judge(s[i]) == 1) 
            tmp += s[i]; // ����ַ������֣�������ӵ���ʱ�ַ�����
        else {
            if (!tmp.empty()) { // �����ʱ�ַ�����Ϊ�գ�����ת��Ϊ������ѹ������ջ��
                nums.push(atoi(tmp.c_str()));
                tmp = "";
            }
            if (s[i] == '#') { // �������������������ʣ��������������
                while (!signal.empty())
                    handle(nums, signal);
                break;
            } else if (signal.empty() || s[i] == '(' || comSignal(signal.top(), s[i])) 
                signal.push(s[i]); // ��������ջΪ�գ����ߵ�ǰ�����Ϊ�����ţ����ߵ�ǰ��������ȼ�����ջ�������������ǰ�����ѹ��ջ��
            else if (s[i] == ')') { // ������������ţ����������ڵ������������
                while (signal.top() != '(') {
                    handle(nums, signal);
                }
                signal.pop(); // ����������
            } else { // �����ǰ��������ȼ�������ջ��������Ҳ��������ţ�����ջ������������֣�Ȼ�󽫵�ǰ�����ѹ��ջ��
                while (!signal.empty() && s[i] != '(' && !comSignal(signal.top(), s[i]))
                    handle(nums, signal);
                signal.push(s[i]);
            }
        }
    }
    cout << nums.top() << endl; // ������ս��
    return 0;
}

