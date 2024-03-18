#include <bits/stdc++.h>
using namespace std;

int KiTu(string s){
    int count = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '^' || s[i] == '&' || s[i] == '*' || s[i] == '?' || s[i] == '_' || s[i] == '~')
            count++;
    }
    return count;
}

int ChuHoa(string s){
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            count++;
        }
    }
    return count;
}

int ChuSo(string s){
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            count++;
        }
    }
    return count;
}

int ChuThuong(string s){
    int count = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] >= 'a' && s[i] <= 'a') {
            count++;
        }
    }
    return count;
}

int DemDau(string s){
    for (int i = 0; i < s.length(); i++){ // [ . , \ ,  / ,  ‘  ‘, ’,’ ]
        if (s[i] == char(46) || s[i] == char(47) || s[i] == char(92) || s[i] == char(34) || s[i] == char(39) || s[i] == char(44)){
            return 1;
        }
    }
    return 0;
}


int main()
{
    string s;
    getline(cin, s);

    int Number_Symbols = KiTu(s);
    int Number_Upper = ChuHoa(s);
    int Number_Numbers = ChuSo(s);
    int Number_Excess = s.length() - 8;
//-----------
    int Bonus_Combo;
    if (Number_Symbols && Number_Upper && Number_Numbers){
        Bonus_Combo = 25;
    }
    else if ((Number_Symbols && Number_Upper) || (Number_Symbols && Number_Numbers) || (Number_Upper && Number_Numbers)){
        Bonus_Combo = 15;
    }
    else {
        Bonus_Combo = 0;
    }
//----------
    int Bonus_FlatLower;
    if (ChuThuong(s) == s.length()){
        Bonus_FlatLower = -15;
    }
    else {
        Bonus_FlatLower = 0;
    }
//-----------
    int Bonus_FlatNumber;
    if (ChuSo(s) == s.length()){
        Bonus_FlatNumber = -35;
    }
    else {
        Bonus_FlatNumber = 0;
    }
//------------
    int score;
    score = 40 + (Number_Excess * 3) + (Number_Upper * 4) + (Number_Numbers * 5) + (Number_Symbols * 5) + Bonus_Combo + Bonus_FlatLower + Bonus_FlatNumber;

    if (s.length() < 8 || DemDau(s)){
        cout << "KhongHopLe";
    }
    else {
        if (score < 50) cout << "Yeu";
        else if (score >= 50 && score < 75) cout << "Vua";
        else if (score >= 75 && score < 100) cout << "Manh";
        else cout << "RatManh";
    }


    return 0;
}

