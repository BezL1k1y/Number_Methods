using namespace std;


void reset_BISEC() {
    ofstream ofs1;
    ofs1.open("BISEC.txt", ofstream::out | ofstream::trunc);
    ofs1.close();
}


void BISECT(double a, double b, double eps, int counter) {
    counter += 1;
    ofstream out;
    out.open("BISEC.txt", ios::app);
    if (abs(equation((a + b) / 2)) < eps) {
        cout << "Метод Бисекций:\n" << "Количество итераций: " << counter << "\n" << "Ответ: " << (a + b) / 2 << "\n\n";
        return;
    }
    else {
        if (equation(a) * equation((a + b) / 2) < 0) {
            a = a;
            b = (a + b) / 2;
        }
        else {
            a = (a + b) / 2;
            b = b;
        }
    }
    if (out.is_open())
    {
        out.precision(20);
        out << "x(" << counter-1 << "): " << (a + b) / 2 << "\t\t\tФункция: " << equation((a + b) / 2) << "\n";
    }
    BISECT(a, b, eps, counter);
    out.close();
}