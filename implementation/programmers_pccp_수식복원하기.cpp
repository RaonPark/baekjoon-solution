#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct exp {
    int x, y;
    int r;
    char op;
    int form;
} exp;

exp get_expression(string expression) {
    int x = 0, y = 0, r = 0;
    int max_form = -1;
    char op;
    bool find_x = false, find_y = false, find_r = false;
    for(int i=0; i<expression.length(); i++) {
        if(expression[i] == 'X') {
            r = -1;
        }
        
        if(expression[i] == '=') {
            find_y = true;
        }
        if(expression[i] == '+' || expression[i] == '-') {
            find_x = true;
            op = expression[i];
        }
        
        if(expression[i] >= '0' && expression[i] <= '9') {
            int num = (expression[i] - '0');
            max_form = max(max_form, num);
            if(!find_x) {
                x = x * 10 + num;
            } else if(find_x && !find_y) {
                y = y * 10 + num;
            } else if(find_y) {
                r = r * 10 + num;
            }
        }
    }
    
    exp result;
    result.x = x;
    result.y = y;
    result.r = r;
    result.op = op;
    result.form = max_form + 1;
    
    return result;
}

int convert(int x, int y, char op, int form) {
    int trans_x = (x / 10) * form + (x % 10);
    int trans_y = (y / 10) * form + (y % 10);

    int exp_res = (op == '+') ? trans_x + trans_y : trans_x - trans_y;

    // (진수)^2 자리
    int hundreds = exp_res / (form * form);
    exp_res %= (form * form);

    // (진수) 자리
    int tens = exp_res / form;
    exp_res %= form;

    // 일의 자리
    int ones = exp_res;

    int trans_r = hundreds * 100 + tens * 10 + ones;
    return trans_r;
}

int can_resolve(int x, int y, char op, int form) {
    bool flag = true;
    int result = convert(x, y, op, form);
    for(int f = form + 1; f <= 9; f++) {
        int conv_res = convert(x, y, op, f);
        if(conv_res != result) {
            flag = false;
        }
    }
    return flag;
}

int determine_form(int x, int y, int r, int op, int form) {
    int ret_form = form, available = 1;
    for(int f = form; f <= 9; f++) {
        int conv = convert(x, y, op, f);
        if(conv != r) {
            available = 0;
        } else ret_form = f;
    }
    
    return available == 0 ? ret_form : -1;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;

    int len = (int)expressions.size();
    vector<string> x_expr;
    bool find_form = false;
    int form = -1;
    
    for(int i=0; i<len; i++) {
        exp expr = get_expression(expressions[i]);
        if(expr.r == -1)
            x_expr.emplace_back(expressions[i]);
    }
    
    for(int i=0; i<len; i++) {
        exp expr = get_expression(expressions[i]);
        
        // 일단 수식의 자릿수마다 중 최고 숫자를 찾는다. 적어도 그 이상의 진법을 가진 숫자이다.
        form = max(form, expr.form);
        int x = expr.x, y = expr.y, r = expr.r;
        int ones_x = x % 10, ones_y = y % 10, ones_r = r % 10;
        
        if(form == 9) find_form = true;
        
        // 먼저 만약 수식이 X인 경우는 저장해둔다. 그리고 계속한다.
        if(expr.r == -1) {
            continue;
        }
        
        if(find_form) break;
        
        int get_form = determine_form(expr.x, expr.y, expr.r, expr.op, form);
        if(get_form != -1) {
            form = get_form;
            find_form = true;
        }
    }
    
    for(int i=0; i<x_expr.size(); i++) {
        if(!find_form) {
            exp expr = get_expression(x_expr[i]);
            if(can_resolve(expr.x, expr.y, expr.op, form)) {
                int conv = convert(expr.x, expr.y, expr.op, form);
                x_expr[i].replace(x_expr[i].find("X"), 1, to_string(conv));
            } 
            else {
                x_expr[i].replace(x_expr[i].find("X"), 1, "?");            
            }
            answer.emplace_back(x_expr[i]);
        } else {
            exp expr = get_expression(x_expr[i]);
            
            int trans_r = convert(expr.x, expr.y, expr.op, form);

            x_expr[i].replace(x_expr[i].find("X"), 1, to_string(trans_r));

            answer.emplace_back(x_expr[i]);
        }
    }
    
    return answer;
}
