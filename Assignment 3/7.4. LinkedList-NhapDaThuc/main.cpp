#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;

	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}

	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};

struct Node{
	DONTHUC* data;
	Node* next;

	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}

};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};


//----------------------------------------------------------------------

void Nhap(DATHUC &B, double heso, int somu){
    DONTHUC *temp = new DONTHUC(heso, somu);
    Node *p = new Node(temp);
    if (B.head == NULL){
        B.head = p;
    }
    else {
        B.tail->next = p;
    }
    B.tail = p;
}

void Xuat(DATHUC B){
    Node* p = B.head;
    int flag = 1;
    while (p != NULL){
        double heso = p->data->heso;
        int somu = p->data->somu;

        if (heso > 0 && flag == 0) cout << "+";

        if (heso != 1 && heso != -1){
            if (heso == 0){}
            else cout << heso;
        }

        if (heso == -1) cout << "-";
        if (somu > 0){
            if (heso == 0){}
            else if (somu == 1){
                cout << "x";
            }
            else {
                cout << "x^" << somu;
            }
        }
        else if (somu == 0){
            if (heso == 1 || heso == -1){
                cout << "1";
            }
        }
        if (heso != 0) flag = 0;
        p = p->next;
    }
    if (flag == 1) cout << 0;
}

double TinhDaThuc(DATHUC B, double x){
    Node *p = B.head;
    double res = 0;
    while (p != NULL){
        double Heso = p->data->heso;
        int Somu = p->data->somu;
        res += Heso * pow(x, Somu);
        p = p->next;
    }
    return res;
}


//----------------------------------------------------------------------


int main() {
    DATHUC B;
    int N;

    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }


    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}

