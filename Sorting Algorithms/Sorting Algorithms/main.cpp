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

	iom.displayMessage("파일 읽기 시작");
	iom.FileReader<int>("int - 1000.txt", intArr, stoi);
	iom.FileReader<double>("double - 1000.txt", doubleArr, stod);
	iom.FileReader<std::string>("string - 1000.txt", strArr);
	iom.FileReader<Rectangle>("rectangle - 1000.txt", recArr);
	iom.displayMessage("파일 읽기 완료");

	iom.displayMessage("버블 정렬 시작");
	timer(stopwatch, "sorts::bubbleSort(intArr)", sorts::bubbleSort<int>, intArr);
	timer(stopwatch, "sorts::bubbleSort(doubleArr)", sorts::bubbleSort<double>, doubleArr);
	timer(stopwatch, "sorts::bubbleSort(strArr)", sorts::bubbleSort<std::string>, strArr);
	timer(stopwatch, "sorts::bubbleSort(recArr)", sorts::bubbleSort<Rectangle>, recArr);
	iom.displayMessage("버블 정렬 완료");

	iom.displayMessage("선택 정렬 시작");
	timer(stopwatch, "sorts::selectionSort(intArr)", sorts::selectionSort<std::vector<int>>, intArr);
	timer(stopwatch, "sorts::selectionSort(doubleArr)", sorts::selectionSort<std::vector<double>>, doubleArr);
	timer(stopwatch, "sorts::selectionSort(strArr)", sorts::selectionSort<std::vector<std::string>>, strArr);
	timer(stopwatch, "sorts::selectionSort(recArr)", sorts::selectionSort<std::vector<Rectangle>>, recArr);
	iom.displayMessage("선택 정렬 완료");

	iom.displayMessage("삽입 정렬 시작");
	timer(stopwatch, "sorts::insertionSort(intArr)", sorts::insertionSort<int>, intArr);
	timer(stopwatch, "sorts::insertionSort(doubleArr)", sorts::insertionSort<double>, doubleArr);
	timer(stopwatch, "sorts::insertionSort(strArr)", sorts::insertionSort<std::string>, strArr);
	timer(stopwatch, "sorts::insertionSort(recArr)", sorts::insertionSort<Rectangle>, recArr);
	iom.displayMessage("삽입 정렬 완료");

	iom.displayMessage("삽입 정렬(리스트) 시작");
	timer(stopwatch, "sorts::insertionSort_list(intArr)", sorts::insertionSort_list<int>, intArr);
	timer(stopwatch, "sorts::insertionSort_list(doubleArr)", sorts::insertionSort_list<double>, doubleArr);
	timer(stopwatch, "sorts::insertionSort_list(strArr)", sorts::insertionSort_list<std::string>, strArr);
	timer(stopwatch, "sorts::insertionSort_list(recArr)", sorts::insertionSort_list<Rectangle>, recArr);
	iom.displayMessage("삽입 정렬(리스트) 완료");

	iom.displayMessage("재귀 병합 정렬 시작");
	timer(stopwatch, "sorts::mergeSort(intArr)", sorts::mergeSort<std::vector <int>>, intArr);
	timer(stopwatch, "sorts::mergeSort(doubleArr)", sorts::mergeSort<std::vector <double>>, doubleArr);
	timer(stopwatch, "sorts::mergeSort(strArr)", sorts::mergeSort<std::vector <std::string>>, strArr);
	timer(stopwatch, "sorts::mergeSort(recArr)", sorts::mergeSort<std::vector <Rectangle>>, recArr);
	iom.displayMessage("재귀 병합 정렬 완료");

	iom.displayMessage("비재귀 병합 정렬 시작");
	timer(stopwatch, "sorts::nonRecursiveMergeSort(intArr)", sorts::nonRecursiveMergeSort<int>, intArr);
	timer(stopwatch, "sorts::nonRecursiveMergeSort(doubleArr)", sorts::nonRecursiveMergeSort<double>, doubleArr);
	timer(stopwatch, "sorts::nonRecursiveMergeSort(strArr)", sorts::nonRecursiveMergeSort<std::string>, strArr);
	timer(stopwatch, "sorts::nonRecursiveMergeSort(recArr)", sorts::nonRecursiveMergeSort<Rectangle>, recArr);
	iom.displayMessage("비재귀 병합 정렬 완료");

	iom.displayMessage("자연 병합 정렬 시작");
	timer(stopwatch, "sorts::naturalMergeSort(intArr)", sorts::naturalMergeSort<int>, intArr);
	timer(stopwatch, "sorts::naturalMergeSort(doubleArr)", sorts::naturalMergeSort<double>, doubleArr);
	timer(stopwatch, "sorts::naturalMergeSort(strArr)", sorts::naturalMergeSort<std::string>, strArr);
	timer(stopwatch, "sorts::naturalMergeSort(recArr)", sorts::naturalMergeSort<Rectangle>, recArr);
	iom.displayMessage("자연 병합 정렬 완료");

	iom.displayMessage("쉘 정렬 시작");
	timer(stopwatch, "sorts::shellSort(intArr)", sorts::shellSort<int>, intArr);
	timer(stopwatch, "sorts::shellSort(doubleArr)", sorts::shellSort<double>, doubleArr);
	timer(stopwatch, "sorts::shellSort(strArr)", sorts::shellSort<std::string>, strArr);
	timer(stopwatch, "sorts::shellSort(recArr)", sorts::shellSort<Rectangle>, recArr);
	iom.displayMessage("쉘 정렬 완료");

	iom.displayMessage("힙 정렬 시작");
	timer(stopwatch, "sorts::heapSort(intArr)", sorts::heapSort<int>, intArr);
	timer(stopwatch, "sorts::heapSort(doubleArr)", sorts::heapSort<double>, doubleArr);
	timer(stopwatch, "sorts::heapSort(strArr)", sorts::heapSort<std::string>, strArr);
	timer(stopwatch, "sorts::heapSort(recArr)", sorts::heapSort<Rectangle>, recArr);
	iom.displayMessage("힙 정렬 완료");

	iom.displayMessage("재귀 퀵 정렬 시작");
	timer(stopwatch, "sorts::recursiveQuickSort(intArr)", sorts::recursiveQuickSort<int>, intArr);
	timer(stopwatch, "sorts::recursiveQuickSort(doubleArr)", sorts::recursiveQuickSort<double>, doubleArr);
	timer(stopwatch, "sorts::recursiveQuickSort(strArr)", sorts::recursiveQuickSort<std::string>, strArr);
	timer(stopwatch, "sorts::recursiveQuickSort(recArr)", sorts::recursiveQuickSort<Rectangle>, recArr);
	iom.displayMessage("재귀 퀵 정렬 완료");

	iom.displayMessage("재귀 퀵 정렬(median_of_three) 시작");
	timer(stopwatch, "sorts::recursiveQuickSort_median(intArr)", sorts::recursiveQuickSort_median<int>, intArr);
	timer(stopwatch, "sorts::recursiveQuickSort_median(doubleArr)", sorts::recursiveQuickSort_median<double>, doubleArr);
	timer(stopwatch, "sorts::recursiveQuickSort_median(strArr)", sorts::recursiveQuickSort_median<std::string>, strArr);
	timer(stopwatch, "sorts::recursiveQuickSort_median(recArr)", sorts::recursiveQuickSort_median<Rectangle>, recArr);
	iom.displayMessage("재귀 퀵 정렬(median_of_three) 완료");

	iom.displayMessage("비재귀 퀵 정렬 시작");
	timer(stopwatch, "sorts::nonRecursiveQuickSort(intArr)", sorts::nonRecursiveQuickSort<int>, intArr);
	timer(stopwatch, "sorts::nonRecursiveQuickSort(doubleArr)", sorts::nonRecursiveQuickSort<double>, doubleArr);
	timer(stopwatch, "sorts::nonRecursiveQuickSort(strArr)", sorts::nonRecursiveQuickSort<std::string>, strArr);
	timer(stopwatch, "sorts::nonRecursiveQuickSort(recArr)", sorts::nonRecursiveQuickSort<Rectangle>, recArr);
	iom.displayMessage("비재귀 퀵 정렬 완료");

	iom.displayMessage("기수 정렬 시작");
	timer(stopwatch, "sorts::radixSort10(intArr)", sorts::radixSort10, intArr);
	timer(stopwatch, "sorts::radixSort16(intArr)", sorts::radixSort16, intArr);
	timer(stopwatch, "sorts::radixSortMasking(intArr)", sorts::radixSortMasking, intArr);
	iom.displayMessage("기수 정렬 완료");

	iom.displayMessage("\n경과 : ");
	for (auto i : stopwatch)
		std::cout << i.first << '\t' << i.second << " ms" << std::endl;

	return 0;
}

template<typename T, typename fn>
void timer(std::vector<std::pair<std::string, clock_t>>& stopwatch, std::string function_name, fn function, const T& input)
{
	T temp(input);
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
