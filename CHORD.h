using namespace std;


void reset_CHORD() {
    ofstream ofs1;
    ofs1.open("CHORD.txt", ofstream::out | ofstream::trunc);
    ofs1.close();
}


void CHORD(double a, double b, double eps) {
    ofstream out;
    out.open("CHORD.txt", ios::app);
    int counter = 0;
    double value = a;
    for (int i = 0; i < 100; i++) {
        counter += 1;
        double next_value = b - (equation(b) * (value - b)) / (equation(value) - equation(b));
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
    cout << "Метод Хорд: \n" << "Количество итераций: " << counter-1 << "\n" << "Ответ: " << value << "\n\n";
    out.close();
}