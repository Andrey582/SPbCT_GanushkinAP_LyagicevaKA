#ifndef POINT_H
#define POINT_H
//объявление перечислимой константы ORIENT
enum ORIENT { LEFT, RIGHT, AHEAD, BEHIND, BETWEEN };
//класс Point ссылается на класс Triangle, значит Triangle должен быть объявлен до Point
class Triangle;
//создание класса Point

class Point {
public:
    //конструктор с двумя аргументами
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}// x=_x; y=_y;
    Point operator +(Point&);//оператор-функция перегрузки оператора сложения
    Point operator -(Point&);//оператор-функция перегрузки оператора вычитания
    //определяет длину вектора точки в полярной системе координат
    double Length() const;
    //определяет положение точки относительно вектора, заданного двумя точками
    ORIENT Classify(Point&, Point&) const;
    //определяет, находится ли точка внутри треугольника

    bool InTriangle(Triangle&) const;//объяснить зачем параметр - ссылка???????????????
    void Show() const;
    void operator +=(Point&);//оператор-функция перегрузки оператора сложения с присваиванием
//public:
    double x, y;
};

#endif /*POINT_H*/