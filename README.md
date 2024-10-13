# Closest-pair-

1 .Brute Force:

Time Complexity: 
𝑂(𝑛2)
O(n2)
Description: This method checks the distance between every pair of points and keeps track of the minimum distance found. It's simple but inefficient for large datasets.

2.Divide and Conquer:

Time Complexity: 
𝑂(𝑛log𝑛)
O(nlogn)
Description: This method involves recursively dividing the set of points into two halves, finding the closest pair in each half, and then checking if there is a closer pair that crosses the division line. The steps are as follows:
Sort the points based on their x-coordinates.
Recursively find the closest pair in the left and right halves.
Find the closest pair across the division by checking points within a certain distance from the dividing line.
