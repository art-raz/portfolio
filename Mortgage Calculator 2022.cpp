#include <iostream>
#include <cmath>
#include <vector>
#include <cassert> 
using namespace std;
const vector <vector<int>> tested_set1 =
    {{12000000,1700000,10300000},{3400000,1300000,2100000}};
double test_program1(double stoimost, double vznos) {
        return stoimost-vznos;}
void testing_prog() {
    for (auto test_set1 : tested_set1)
    assert (test_program1(test_set1[0], test_set1[1]) == test_set1[2]);
    cout << "Тесты пройдены." << endl;}
int dolg (double stoimost, double vznos, int c) { // Сумма долга
    c=stoimost-vznos;
    cout << c;
    return 0;}
double platezh (double stoimost, double vznos, double stavka, int srok, double pl) { // Ежемесячный платёж
    pl=((stoimost-vznos)*stavka/12/100)/(1-(pow(1+stavka/12/100,-srok*12)));
    cout << pl;
    return 0;}
double dohod (double stoimost, double vznos, double stavka, int srok, int z, double d2){ // Рекомендуемый доход
    d2=((stoimost-vznos)*stavka/12/100)/(1-(pow(1+stavka/12/100,-srok*12)))*z;
    cout << d2;
    return 0;}
int main() {
    testing_prog();
    int z=2 ,srok=0, r=1, k=30, h=0, d=0, c=0;
    double stavka=0, p=0.1, vznos=0, stoimost=0, s=0.01, pl=0, d2=0;
    cout << "Ипотечный калькулятор" << endl << "Введите стоимость жилья (в рублях):" << endl;
    cin >> stoimost;
      while (stoimost<h || stoimost==h) {
      cout << "Некорректное значение!" << endl << "Стоимость жилья может быть только положительной." << endl;
      cin >> stoimost;
      }
    cout << "Введи первоначальный взнос (в рублях):" << endl;
    cin >> vznos; 
      while (vznos>stoimost || vznos<stoimost*p) {
      cout << "Некорректное значение!" << endl << "Первоначальный взнос должен составлять минимум 10% от стоимости жилья и не превышать её." << endl;
      cin >> vznos; 
      }
    cout << "Введите ипотечную годовую ставку (в процентах):" << endl;
    cin >> stavka;
      while (stavka<s) {
      cout << "Некорректное значение!" << endl << "Ставка не может быть ниже 0.01%." << endl;
      cin >> stavka;
      }
    cout << "Введите срок ипотеки (полных лет):" << endl;
    cin >> srok;
      while (srok<r || srok>k) {
      cout << "Некорректное значение!" << endl << "Срок ипотеки варьируется от 1 года до 30 лет." << endl;
      cin >> srok;
      }
    cout << "Сумма Вашего кредита равна:" << " "; // Начало вывода результата
    dolg (stoimost, vznos, c);
    cout <<endl << "Ежемесячный аннуитетный платёж по ипотеке равен:" << " ";
    platezh (stoimost, vznos, stavka, srok, pl);
    cout <<endl << "Рекомендуемый минимальный доход для взятия данной ипотеки:" << " ";
    dohod (stoimost, vznos, stavka, srok, z, d2);
return 0;}
