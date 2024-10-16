using namespace std;


void reset_NEWTON() {
    ofstream ofs1;
    ofs1.open("NEWTON.txt", ofstream::out | ofstream::trunc);
    ofs1.close();
}


void NEW_TON(double x, double eps) {
    ofstream out;
    out.open("NEWTON.txt", ios::app);
    double value = x;
    int counter = 0;
    for (int i = 0; i < 100; ++i) {
        counter += 1;
        double next_value = value - equation(value) / ((equation(value + eps) - equation(value)) / eps);
        if (abs(next_value - value) < eps) {
            break;
        }
        value = next_value;
        if (out.is_open())
        {
            out.precision(20);
            out << "x(" << counter << "): " << value << "\t\t\tФункция: " << equation(value) << "\n";
        }
    }
    cout << "Метод Ньютона: \n" << "Количество итераций: " << counter-1 << "\n" << "Ответ: " << value << "\n\n";
    out.close();
}
