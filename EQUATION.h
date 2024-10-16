using namespace std;


double ln(double x) {
    double value = x;
    for (int i = 0; i < 1000; ++i) {
        double next_value = value - (exp(value) - x) / exp(value);
        if (abs(next_value - value) < 1e-10) {
            break;
        }
        value = next_value;
    }
    return value;
}


double equation(double x) {
    return log(x) - (1 / (1 + x * x));
}