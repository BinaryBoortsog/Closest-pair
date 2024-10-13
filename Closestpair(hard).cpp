#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

// Function to calculate distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to compare points based on x coordinate
bool compareX(Point p1, Point p2) {
    return p1.x < p2.x;
}

// Function to compare points based on y coordinate
bool compareY(Point p1, Point p2) {
    return p1.y < p2.y;
}

// Brute force method to find the minimum distance in a small set of points
double bruteForce(vector<Point>& points, int left, int right) {
    double minDist = numeric_limits<double>::max();
    for (int i = left; i < right; i++) {
        for (int j = i + 1; j < right; j++) {
            minDist = min(minDist, distance(points[i], points[j]));
        }
    }
    return minDist;
}

// Function to find the closest pair of points
double closestUtil(vector<Point>& pointsX, vector<Point>& pointsY, int left, int right) {
    if (right - left <= 3) {
        return bruteForce(pointsX, left, right);
    }

    int mid = (left + right) / 2;
    Point midPoint = pointsX[mid];

    // Divide points into left and right
    vector<Point> pointsYL; // Points in left of mid
    vector<Point> pointsYR; // Points in right of mid

    for (int i = 0; i < pointsY.size(); i++) {
        if (pointsY[i].x <= midPoint.x) {
            pointsYL.push_back(pointsY[i]);
        } else {
            pointsYR.push_back(pointsY[i]);
        }
    }

    double dl = closestUtil(pointsX, pointsYL, left, mid);
    double dr = closestUtil(pointsX, pointsYR, mid, right);

    // Find the minimum distance from left and right
    double d = min(dl, dr);

    // Build a strip array to check points within d distance from midPoint
    vector<Point> strip;
    for (int i = 0; i < pointsY.size(); i++) {
        if (abs(pointsY[i].x - midPoint.x) < d) {
            strip.push_back(pointsY[i]);
        }
    }

    // Check the strip for potential closest pairs
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++) {
            d = min(d, distance(strip[i], strip[j]));
        }
    }

    return d;
}

// Main function to find the closest pair of points
double closest(vector<Point>& points) {
    int n = points.size();
    vector<Point> pointsX = points;
    vector<Point> pointsY = points;

    sort(pointsX.begin(), pointsX.end(), compareX);
    sort(pointsY.begin(), pointsY.end(), compareY);

    return closestUtil(pointsX, pointsY, 0, n);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    
    // Input handling (use getline to read the full line if necessary)
    for (int i = 0; i < n; i++) {
        char comma; // to read the comma
        cin >> points[i].x >> comma >> points[i].y; // read "x, y"
    }

    double minDistance = closest(points);

    // Output formatted to six decimal places
    cout << fixed << setprecision(6) << minDistance << endl;

    return 0;
}
