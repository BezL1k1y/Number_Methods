using namespace std;


void reset_SITER() {
    ofstream ofs5;
    ofs5.open("SITER.txt", ofstream::out | ofstream::trunc);
    ofs5.close();
}


void SITER(double a, double eps) {
    int counter = 0;
    double value = 2;
    double next_value = 2;
    ofstream out;
    out.open("SITER.txt", ios::app);
    for (int i = 0; i < 100; ++i) {
        counter += 1;
        next_value = sqrt((1 / ln(value)) - 1);
        if (abs(value - next_value) < eps) {
            break;
        }
        value = next_value;
        if (out.is_open())
        {
            out.precision(20);
            out << "x(" << counter << "): " << value << "\t" << value << "\t\t\tФункция: " << equation(value) << "\n";
        }
    }
    cout << "Метод Простых Итераций: \n" << "Количество итераций: " << counter << "\n" << "Ответ: " << value << "\n\n";
    out.close();
}