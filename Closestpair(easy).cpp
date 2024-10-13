#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate distance between two points
double calculateDistance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

int main() {
    int n; // Number of points
    cin >> n; // Read the number of points
    cin.ignore(); // Ignore the newline character after the number

    vector<pair<double, double>> points(n); // Vector to store points

    // Read points from input
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        size_t commaPos = line.find(", ");
        double x = stod(line.substr(0, commaPos));
        double y = stod(line.substr(commaPos + 2));
        points[i] = make_pair(x, y);
    }

    double minDistance = INFINITY; //  minimum distance

    // Calculate distances between every pair of points
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double distance = calculateDistance(points[i], points[j]);
            if (distance < minDistance) {
                minDistance = distance; // Update minimum distance
            }
        }
    }

    // Output the minimum distance formatted to six decimal places
    cout << fixed << setprecision(6) << minDistance << endl;

    return 0;
}
