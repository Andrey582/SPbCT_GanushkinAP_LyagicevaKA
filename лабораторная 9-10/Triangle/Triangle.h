#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
//создание класса Triangle

class Triangle {
public:
    bool operator>(const Triangle&) const;//оператор-функци€ перегрузки оператора сравнени€
    Triangle(const Triangle&);// конструктор копировани€
    Triangle& operator=(const Triangle&);//оператор-функци€ перегрузки оператора присваивани€
    //дружественна€ функци€, котора€ определ€ет, входит ли один треугольник во второй
    friend bool TriaInTria(Triangle, Triangle);
    Triangle(Point, Point, Point, const char*);//конструктор
    Triangle(const char*);//конструктор пустого(нулевого) треугольника:использует значение по умолчанию
    ~Triangle(); //деструктор
    Point Get_v1() const { return v1; } //получить значение v1
    Point Get_v2() const { return v2; } //получить значение v2
    Point Get_v3() const { return v3; } //получить значение v3
    char* GetName() const { return name; } //получить им€ объекта
    void Show() const; //показать объект
    void Move(Point);
    //public:
    static int count;//кол-во созданных объектов класса
private:
    char* objID;//идентификатор объекта
    char* name;//наименование треугольника
    Point v1, v2, v3;//вершины
    double a;//сторона, соедин€юща€ v1 и v2
    double b;//сторона, соедин€юща€ v2 и v3
    double c;//сторона, соедин€юща€ v1 и v3
};

#endif /*TRIANGLE_H*/