#include <iostream>

#include "Triangle.h"

using namespace std;



// F U N C T I O N S /////////////////////////////////////////////////////////



//��������� ������������ �������
int Menu();
int GetNumber(int, int);
void ExitBack();
void Show(Triangle* [], int);
double GetDouble();
void Move(Triangle* [], int);
void FindMax(Triangle* [], int);
void IsIncluded(Triangle* [], int);



//������������� ���������� ����������

int Triangle::count = 0;

//����������� �������

//--------------------������� �������

int main()

{

    //����������� ��������� �����
    Point p1(0, 0); Point p2(0.5, 1);
    Point p3(1, 0); Point p4(0, 4.5);
    Point p5(2, 1); Point p6(2, 0);
    Point p7(2, 2); Point p8(3, 0);

    //����������� �������������

    Triangle triaA(p1, p2, p3, "triaA");
    Triangle triaB(p1, p4, p8, "triaB");
    Triangle triaC(p1, p5, p6, "triaC");
    Triangle triaD(p1, p7, p8, "triaD");
    //����������� ������� ���������� �� ������������
    Triangle* pTria[] = { &triaA,&triaB,&triaC,&triaD };
    int n = sizeof(pTria) / sizeof(pTria[0]);
    //������� ����

    bool done = false;

    while (!done) { //����������� ���� 
        switch (Menu()) {
        case 1:Show(pTria, n);  break;
        case 2:Move(pTria, n);  break;
        case 3:FindMax(pTria, n);       break;
        case 4:IsIncluded(pTria, n);    break;
        case 5:cout << "End." << endl;
            done = true; break;
        }

    }
    return 0;
}

//----------------------����� ����

int Menu()

{
    cout << "n============M A I N   M E N U==========" << endl;
    cout << "1 - Show all objectst 3 - Find max" << endl;
    cout << "2 - Movett 4 - Is included in" << endl;
    cout << "tt5 - Exit" << endl;
    return GetNumber(1, 5);
}

//-------------����� ������ ����� � �������� ���������

int GetNumber(int min, int max) {
    int number = min - 1;
    while (true) {
        cin >> number;
        if ((number >= min) && (number <= max) && (cin.peek() == '\n'))
            break;
        else {
            cout << "Retry (number must be from " << min << " till " << max << "):" << endl;
            cin.clear();//�������� ���� ������
            while (cin.get() != '\n') {}// cin.get ��������� ���� ������
        }

    }
    return number;
}

//-----------------������� � ������� � �������� ����

void ExitBack() {
    cout << "Push Enter." << endl;
    cin.get(); cin.get();
}

//-----------------����� ���� �������������

void Show(Triangle* p_tria[], int k) {
    cout << "==========Triangles==========" << endl;
    for (int i = 0; i < k; ++i) p_tria[i]->Show();//����� ������ Show() ��� ������� ������ Triangle
    ExitBack();
}

//-------------------���� ������������� �����

double GetDouble()

{
    double value;
    while (true) {
        cin >> value;
        if (cin.peek() == '\n') break;//cin.peek ������ ���� ������, �������� ��� � ������
        else {
            cout << "Retry (number must be ves4estvennoe):" << endl;
            cin.clear();
            while (cin.get() != '\n') {};
        }

    }
    return value;
}

//-----------------�����������

void Move(Triangle* p_tria[], int k) {
    cout << "==========Move============" << endl;
    cout << "Enter number of triangle (from 1 till " << k << "): ";
    int i = GetNumber(1, k) - 1;
    p_tria[i]->Show();//����� ������ Show() ��� ������� ������ Triangle
    Point dp;
    cout << "Enter smeschenie po x: ";
    dp.x = GetDouble();
    cout << "Enter smeschenie po y: ";
    dp.y = GetDouble();
    p_tria[i]->Move(dp);//����� ������ Move() ��� ������� ������ Triangle
    cout << "New place of triangle: " << endl;
    p_tria[i]->Show();//����� ������ Show() ��� ������� ������ Triangle
    ExitBack();
}

//-----------------����� ������������� ������������

void FindMax(Triangle* p_tria[], int k) {

    cout << "====Find max triangle====" << endl;
    /*������� ������ TriaMax, ������� �� ���������� ������ ����� ��������� ������������� �������

    �������������� ��� ��������� 1-�� ������� �� ������� ��������*/
    Triangle triaMax("triaMax");
    triaMax = *p_tria[0];
    //�����
    for (int i = 1; i < 4; ++i)
        if (*p_tria[i] > triaMax)
            triaMax = *p_tria[i];
    cout << "Max triangle is: " << triaMax.GetName() << endl;
    ExitBack();
}

//-----------------����������� ��������� ���������

void IsIncluded(Triangle* p_tria[], int k) {
    cout << "====Opredelit' otnoshenie vklu4enia====" << endl;
    cout << "Enter number of the first triangle (from 1 till " << k << "): ";
    int i1 = GetNumber(1, k) - 1;
    cout << "Enter number of the second triangle (from 1 till " << k << "): ";
    int i2 = GetNumber(1, k) - 1;
    if (TriaInTria(*p_tria[i1], *p_tria[i2]))//����� ������������� �������
            //�������� ����� GetName() ��� ������� ������ Triangle, �� ������� ��������� ���������,

            //���������� i1 � i2 ��������� �������������� ������� p_tria
        cout << p_tria[i1]->GetName() << " - is included in - " << p_tria[i2]->GetName() << endl;
    else
        cout << p_tria[i1]->GetName() << "is not included in - " << p_tria[i2]->GetName() << endl;
    ExitBack();
}