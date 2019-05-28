#include <iostream>
#include <ctime>
#include "IOManager.h"
#include "Sort.h"
#include "Rectangle.h"

int main()
{
	IOManager iom;

	std::vector<int> intArr;
	std::vector<double> doubleArr;
	std::vector<std::string> strArr;
	std::vector<Rectangle> recArr;
	
	auto stoi = [](std::string input)->int {return std::stoi(input); };
	auto stod = [](std::string input)->double {return std::stod(input); };

	iom.FileReader<int>("C:\\Users\\Administrator\\source\\repos\\RandomDataCreator\\Debug\\int - 10.txt", intArr, stoi);
	iom.FileReader<double>("C:\\Users\\Administrator\\source\\repos\\RandomDataCreator\\Debug\\double - 10.txt", doubleArr, stod);
	iom.FileReader<std::string>("C:\\Users\\Administrator\\source\\repos\\RandomDataCreator\\Debug\\string - 10.txt", strArr);
	iom.FileReader<Rectangle>("C:\\Users\\Administrator\\source\\repos\\RandomDataCreator\\Debug\\rectangle - 10.txt", recArr);

	sorts::bubbleSort(intArr);
	sorts::bubbleSort(doubleArr);
	sorts::bubbleSort(strArr);
	sorts::bubbleSort(recArr);

	sorts::selectionSort(intArr);
	sorts::selectionSort(doubleArr);
	sorts::selectionSort(strArr);
	sorts::selectionSort(recArr);

	sorts::insertionSort(intArr);
	sorts::insertionSort(doubleArr);
	sorts::insertionSort(strArr);
	sorts::insertionSort(recArr);

	sorts::insertionSort_list(intArr);
	sorts::insertionSort_list(doubleArr);
	sorts::insertionSort_list(strArr);
	sorts::insertionSort_list(recArr);

	sorts::mergeSort(intArr);
	sorts::mergeSort(doubleArr);
	sorts::mergeSort(strArr);
	sorts::mergeSort(recArr);

	sorts::nonRecursiveMergeSort(intArr, intArr.size());
	sorts::nonRecursiveMergeSort(doubleArr, doubleArr.size());
	sorts::nonRecursiveMergeSort(strArr, strArr.size());
	sorts::nonRecursiveMergeSort(recArr, recArr.size());

	//sorts::mergeSort_natural(intArr);
	//sorts::mergeSort_natural(doubleArr);
	//sorts::mergeSort_natural(strArr);
	//sorts::mergeSort_natural(recArr);

	sorts::shellSort(intArr);
	sorts::shellSort(doubleArr);
	sorts::shellSort(strArr);
	sorts::shellSort(recArr);

	sorts::heapSort(intArr);
	sorts::heapSort(doubleArr);
	sorts::heapSort(strArr);
	sorts::heapSort(recArr);

	sorts::recursiveQuickSort(intArr, 0, intArr.size() - 1);
	sorts::recursiveQuickSort(doubleArr, 0, doubleArr.size() - 1);
	sorts::recursiveQuickSort(strArr, 0, strArr.size() - 1);
	sorts::recursiveQuickSort(recArr, 0, recArr.size() - 1);

	sorts::recursiveQuickSort_median(intArr, 0, intArr.size() - 1);
	sorts::recursiveQuickSort_median(doubleArr, 0, doubleArr.size() - 1);
	sorts::recursiveQuickSort_median(strArr, 0, strArr.size() - 1);
	sorts::recursiveQuickSort_median(recArr, 0, recArr.size() - 1);

	sorts::nonRecursiveQuickSort(intArr, intArr.size());
	sorts::nonRecursiveQuickSort(doubleArr, doubleArr.size());
	sorts::nonRecursiveQuickSort(strArr, strArr.size());
	sorts::nonRecursiveQuickSort(recArr, recArr.size());

	sorts::radixSort10(intArr);
	sorts::radixSort16(intArr);
	sorts::radixSortMasking(intArr);

	return 0;
}