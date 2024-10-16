using namespace std;


void reset_NEWTON_CHORD() {
    ofstream ofs4;
    ofs4.open("NEWTON_CHORD.txt", ofstream::out | ofstream::trunc);
    ofs4.close();
}

void NEWTON_CHORD(double a, double b, double eps) {
    ofstream out;
    out.open("NEWTON_CHORD.txt", ios::app);
    double answer = 0;
    double value = a;
    double value_n = b;
    int counter = 0;
    for (int i = 0; i < 100; ++i) {
        counter += 1;
        //NEWTON
        double next_value_n = value_n - equation(value_n) / ((equation(value_n + eps) - equation(value_n)) / eps);
        value_n = next_value_n;
        //CHORD
        double next_value = value_n - (equation(value_n) * (value - value_n)) / (equation(value) - equation(value_n));

        if ((abs(value - next_value) < eps)) {
            break;
        }
        value = next_value;
        if (out.is_open())
        {
            out.precision(20);
            out << "x(" << counter << "): " << value_n << "\t" << value << "\t\t\tФункция: " << equation(value_n) << "\n";
        }
    }
    cout << "Метод Ньютона и Хорд: \n" << "Количество итераций: " << counter-1 << "\n" << "Ответ: " << value_n << "\n\n";
    out.close();
}