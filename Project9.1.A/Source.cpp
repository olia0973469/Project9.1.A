#pragma execution_character_set("utf-8")

#include <iostream> 
#include <iomanip> 
#include <string> 
#include <Windows.h>
using namespace std;

enum Special { CS, INF, MATH, PHYS, HAND };

string specialStr[] = { "��������� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

struct Student
{
    string   prizv;
    unsigned kurs;
    Special   special;
    int phys;
    int math;
    int inf;
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double Math(Student* p, const int N);
double Physics(Student* p, const int N);
double Inform(Student* p, const int N);
int Count(Student* p, const int N);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int N;
    cout << "������ N: "; cin >> N;

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);

    double ser = Math(p, N);
    cout << ser << endl;
    double ser1 = Physics(p, N);
    cout << ser1 << endl;
    double ser2 = Inform(p, N);
    cout << ser2 << endl;
    int c = Count(p, N);
    cout << c << endl;
    return 0;
}
void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "������� � " << i + 1 << ":" << endl;

        cin.get();
        cin.sync();

        cout << "    �������: "; getline(cin, p[i].prizv);
        cout << "    ����: "; cin >> p[i].kurs;
        cout << "    ������ � ����������(0-5): "; cin >> p[i].math;
        cout << "    ������ � ������(0-5): "; cin >> p[i].phys;
        cout << "    ������ � �����������(0-5): "; cin >> p[i].inf;
        cout << "    ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
        cin >> spec;
        p[i].special = (Special)spec;
        cout << endl;
    }
}
void Print(Student* p, const int N)
{
    cout << "==================================================================================================" << endl;
    cout << "|  �  |   �������   |   ����   |  ������������  |   ����������   |   Գ����   |   �����������   |" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << p[i].prizv
            << "|    " << setw(1) << right << p[i].kurs << "   "
            << "| " << setw(20) << left << specialStr[p[i].special] << "  "
            << "|   " << setw(5) << right << p[i].math << "   |   " << setw(5) << right << p[i].phys << "   | " << setw(7) << right << p[i].inf << "     |" << endl;
    }
    cout <<
        "==================================================================================================" << endl;
    cout << endl;
}
double Math(Student* p, const int N)
{
    cout << "������� ��� � ����������:" << endl;
    double b = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        b = ((p[i].math) * 1.0) + b;
    }
    return b/N;
}
double Physics(Student* p, const int N)
{
    cout << "������� ��� � ������:" << endl;
    double b = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        b = ((p[i].phys) * 1.0) + b;
    }
    return b / N;
}
double Inform(Student* p, const int N)
{
    cout << "������� ��� � �����������:" << endl;
    double b = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        b = ((p[i].inf) * 1.0) + b;
    }
    return b / N;
}
int Count(Student* p, const int N) 
{
    cout << "ʳ������ �������� \"5 ��� 4 � ������\" (4, 5):" << endl;
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if ((p[i].phys == 4) || 
           (p[i].phys == 5))
            k++;
    }
    return k;
}