#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include<random>

using namespace std;


class sortMethod
{
public:
	void insertSort(vector<int>&nums);
	void BubbleSort(vector<int>& nums);
	void MergeSort(vector<int>& vi, int start, int end);
	void QuickSort(vector<int>& nums, int l, int r);
	void SelectSort(vector<int>& nums, int start);
	void ShellSort(vector<int>& nums);
	void HeapSort(vector<int>& vi);
	void CountSort(std::vector<int>& vi);

	void SortTest();
	
private:
	vector<int> test_arr = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
};

