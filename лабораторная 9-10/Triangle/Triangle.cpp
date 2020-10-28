#pragma warning(disable : 4996)
#include <math.h> //для sqrt
#include <iostream>
#include <iomanip> 
#include <cstring>//для strlen, strcat, strcpy
#include "Triangle.h"
using namespace std;
// F U N C T I O N S /////////////////////////////////////////////////////////
//конструктор копирования

Triangle::Triangle(const Triangle& tria) :v1(tria.v1), v2(tria.v2), v3(tria.v3) {
    cout << "Copy constructor for: " << tria.objID << endl; //отладочный вывод
    objID = new char[strlen(tria.objID) + strlen("kopia") + 1];//выделяем динамическую память
    strcpy(objID, tria.objID); //копирует строку objID в строку tria.objID
    name = new char[strlen(tria.name) + 1];//функция strlen возвращает длину строки 
    strcpy(name, tria.name);
    a = tria.a;
    b = tria.b;
    c = tria.c;
}



//оператор-функция, присвоить значение объекта tria

Triangle& Triangle::operator=(const Triangle& tria) {
    cout << "Assign operator: " << objID << "=" << tria.objID << endl; //отладочныйы вывод
    if (&tria == this) return *this;
    delete[] name;
    name = new char[strlen(tria.name) + 1];
    strcpy(name, tria.name);
    a = tria.a;      b = tria.b;    c = tria.c;//запуск перегружаемого =
    return *this;
}



//конструктор

Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* ident) : v1(_v1), v2(_v2), v3(_v3)

{
    char buf[16];
    objID = new char[strlen(ident) + 1];
    strcpy(objID, ident);
    count++;//добавить объект
    sprintf(buf, "Треугольник %d", count);
    name = new char[strlen(buf) + 1];
    strcpy(name, buf);
    a = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
    b = sqrt((v2.x - v3.x) * (v2.x - v3.x) + (v2.y - v3.y) * (v2.y - v3.y));
    c = sqrt((v1.x - v3.x) * (v1.x - v3.x) + (v1.y - v3.y) * (v1.y - v3.y));
    cout << "Constructor_1 for: " << objID << " (" << name << ")" << endl;//отладочный вывод
}



//Конструктор пустого (нулевого) треугольника

Triangle::Triangle(const char* ident) {
    char buf[16];
    objID = new char[strlen(ident) + 1];
    strcpy(objID, ident);
    count++;//добавить объект
    sprintf(buf, "Triangle %d", count);//выполняет форматированный вывод в строку
    name = new char[strlen(buf) + 1];
    strcpy(name, buf);
    a = b = c = 0;
    cout << "Constructor_2 for: " << objID << " (" << name << ")" << endl; //отладочный вывод
}



//оператор-функция, сравнить объект (по площади) с объектом tria

bool Triangle::operator > (const Triangle& tria) const {
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    double p1 = (tria.a + tria.b + tria.c) / 2;
    double s1 = sqrt(p1 * (p1 - tria.a) * (p1 - tria.b) * (p1 - tria.c));
    if (s > s1) return true;//запуск перегружаемого >
    else    return false;
}

//Деструктор

Triangle::~Triangle() {
    cout << "Destructor for: " << objID << endl;
    delete[] name;
    delete[] objID;// очистка динамической памяти 
   
}



//показать треугольник

void Triangle::Show() const {
    cout << name << ":";
    v1.Show(); v2.Show(); v3.Show();
    cout << endl;
}



//показать стороны и площадь треугольника

void Triangle::Move(Point dp) {
    v1 += dp;        v2 += dp;        v3 += dp;
}



//определить, входит ли треугольник tria1 в треугольник tria2

bool TriaInTria(Triangle tria1, Triangle tria2) {
    Point v1 = tria1.Get_v1();
    Point v2 = tria1.Get_v2();
    Point v3 = tria1.Get_v3();
    return (v1.InTriangle(tria2) && v2.InTriangle(tria2) && v3.InTriangle(tria2));
    
}
