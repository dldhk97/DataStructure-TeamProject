#include <iostream>
#include <fstream>
#include <ctime>
#include "IOManager.h"
#include "Sort.h"
#include "Rectangle.h"

template<typename T, typename fn> void timer(std::vector<std::pair<std::string, clock_t>>& stopwatch, std::string function_name, fn function, const T& input);

int main()
{
	IOManager iom;
	std::vector<std::pair<std::string, clock_t>> stopwatch;
	std::vector<int> intArr;
	std::vector<double> doubleArr;
	std::vector<std::string> strArr;
	std::vector<Rectangle> recArr;

	auto stoi = [](std::string input)->int {return std::stoi(input); };
	auto stod = [](std::string input)->double {return std::stod(input); };

	iom.FileReader<int>("int - 10000.txt", intArr, stoi);
	iom.FileReader<double>("double - 10000.txt", doubleArr, stod);
	iom.FileReader<std::string>("string - 10000.txt", strArr);
	iom.FileReader<Rectangle>("rectangle - 10000.txt", recArr);

	timer(stopwatch, "sorts::bubbleSort(intArr)", sorts::bubbleSort<int>, intArr);
	timer(stopwatch, "sorts::bubbleSort(doubleArr)", sorts::bubbleSort<double>, doubleArr);
	timer(stopwatch, "sorts::bubbleSort(strArr)", sorts::bubbleSort<std::string>, strArr);
	timer(stopwatch, "sorts::bubbleSort(recArr)", sorts::bubbleSort<Rectangle>, recArr);

	timer(stopwatch, "sorts::selectionSort(intArr)", sorts::selectionSort<std::vector<int>>, intArr);
	timer(stopwatch, "sorts::selectionSort(doubleArr)", sorts::selectionSort<std::vector<double>>, doubleArr);
	timer(stopwatch, "sorts::selectionSort(strArr)", sorts::selectionSort<std::vector<std::string>>, strArr);
	timer(stopwatch, "sorts::selectionSort(recArr)", sorts::selectionSort<std::vector<Rectangle>>, recArr);

	timer(stopwatch, "sorts::insertionSort(intArr)", sorts::insertionSort<int>, intArr);
	timer(stopwatch, "sorts::insertionSort(doubleArr)", sorts::insertionSort<double>, doubleArr);
	timer(stopwatch, "sorts::insertionSort(strArr)", sorts::insertionSort<std::string>, strArr);
	timer(stopwatch, "sorts::insertionSort(recArr)", sorts::insertionSort<Rectangle>, recArr);

	timer(stopwatch, "sorts::insertionSort_list(intArr)", sorts::insertionSort_list<int>, intArr);
	timer(stopwatch, "sorts::insertionSort_list(doubleArr)", sorts::insertionSort_list<double>, doubleArr);
	timer(stopwatch, "sorts::insertionSort_list(strArr)", sorts::insertionSort_list<std::string>, strArr);
	timer(stopwatch, "sorts::insertionSort_list(recArr)", sorts::insertionSort_list<Rectangle>, recArr);

	timer(stopwatch, "sorts::mergeSort(intArr)", sorts::mergeSort<std::vector <int>>, intArr);
	timer(stopwatch, "sorts::mergeSort(doubleArr)", sorts::mergeSort<std::vector <double>>, doubleArr);
	timer(stopwatch, "sorts::mergeSort(strArr)", sorts::mergeSort<std::vector <std::string>>, strArr);
	timer(stopwatch, "sorts::mergeSort(recArr)", sorts::mergeSort<std::vector <Rectangle>>, recArr);

	timer(stopwatch, "sorts::nonRecursiveMergeSort(intArr)", sorts::nonRecursiveMergeSort<int>, intArr);
	timer(stopwatch, "sorts::nonRecursiveMergeSort(doubleArr)", sorts::nonRecursiveMergeSort<double>, doubleArr);
	timer(stopwatch, "sorts::nonRecursiveMergeSort(strArr)", sorts::nonRecursiveMergeSort<std::string>, strArr);
	timer(stopwatch, "sorts::nonRecursiveMergeSort(recArr)", sorts::nonRecursiveMergeSort<Rectangle>, recArr);

	//sorts::mergeSort_natural(intArr);
	//sorts::mergeSort_natural(doubleArr);
	//sorts::mergeSort_natural(strArr);
	//sorts::mergeSort_natural(recArr);

	timer(stopwatch, "sorts::shellSort(intArr)", sorts::shellSort<int>, intArr);
	timer(stopwatch, "sorts::shellSort(doubleArr)", sorts::shellSort<double>, doubleArr);
	timer(stopwatch, "sorts::shellSort(strArr)", sorts::shellSort<std::string>, strArr);
	timer(stopwatch, "sorts::shellSort(recArr)", sorts::shellSort<Rectangle>, recArr);

	timer(stopwatch, "sorts::heapSort(intArr)", sorts::heapSort<int>, intArr);
	timer(stopwatch, "sorts::heapSort(doubleArr)", sorts::heapSort<double>, doubleArr);
	timer(stopwatch, "sorts::heapSort(strArr)", sorts::heapSort<std::string>, strArr);
	timer(stopwatch, "sorts::heapSort(recArr)", sorts::heapSort<Rectangle>, recArr);

	timer(stopwatch, "sorts::recursiveQuickSort(intArr)", sorts::recursiveQuickSort<int>, intArr);
	timer(stopwatch, "sorts::recursiveQuickSort(doubleArr)", sorts::recursiveQuickSort<double>, doubleArr);
	timer(stopwatch, "sorts::recursiveQuickSort(strArr)", sorts::recursiveQuickSort<std::string>, strArr);
	timer(stopwatch, "sorts::recursiveQuickSort(recArr)", sorts::recursiveQuickSort<Rectangle>, recArr);

	timer(stopwatch, "sorts::recursiveQuickSort_median(intArr)", sorts::recursiveQuickSort_median<int>, intArr);
	timer(stopwatch, "sorts::recursiveQuickSort_median(doubleArr)", sorts::recursiveQuickSort_median<double>, doubleArr);
	timer(stopwatch, "sorts::recursiveQuickSort_median(strArr)", sorts::recursiveQuickSort_median<std::string>, strArr);
	timer(stopwatch, "sorts::recursiveQuickSort_median(recArr)", sorts::recursiveQuickSort_median<Rectangle>, recArr);

	timer(stopwatch, "sorts::nonRecursiveQuickSort(intArr)", sorts::nonRecursiveQuickSort<int>, intArr);
	timer(stopwatch, "sorts::nonRecursiveQuickSort(doubleArr)", sorts::nonRecursiveQuickSort<double>, doubleArr);
	timer(stopwatch, "sorts::nonRecursiveQuickSort(strArr)", sorts::nonRecursiveQuickSort<std::string>, strArr);
	timer(stopwatch, "sorts::nonRecursiveQuickSort(recArr)", sorts::nonRecursiveQuickSort<Rectangle>, recArr);

	timer(stopwatch, "sorts::radixSort10(intArr)", sorts::radixSort10, intArr);
	timer(stopwatch, "sorts::radixSort16(intArr)", sorts::radixSort16, intArr);
	timer(stopwatch, "sorts::radixSortMasking(intArr)", sorts::radixSortMasking, intArr);

	for (auto i : stopwatch)
		std::cout << i.first << '\t' << i.second << " ms" << std::endl;

	return 0;
}

template<typename T, typename fn>
void timer(std::vector<std::pair<std::string, clock_t>>& stopwatch, std::string function_name, fn function, const T& input)
{
	T temp(input);
	//std::copy(std::begin(input), std::end(input), temp);
	auto start = clock();
	function(temp);
	auto stop = clock();
	stopwatch.push_back(std::make_pair(function_name, stop - start));

	// DEBUG
	std::string path = function_name.substr(7, function_name.size()) + "__sorted.txt";
	std::ofstream result;
	result.open(path);
	for (auto i : temp)
		result << i << std::endl;
	result.close();
}
