#include"Sort.h"

void sortMethod::insertSort(vector<int>&nums)
{
	for (int i = 1; i < nums.size(); i++) {
		//将原本需要写到if中的条件放入for循环条件
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
			swap(nums[j], nums[j - 1]);
		}
	}
}

void sortMethod::BubbleSort(vector<int>& nums)
{
	int n = nums.size();
	bool sorted = false; //用以判断是否经历过排序的标志

	for (int i = n -1; i >= 0 && (!sorted); --i)
	{
		sorted = true;
		for (int j = 0; j < i; ++j)
		{
			if (nums[j + 1] < nums[j])
			{
				sorted = false;
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}



//合并两个有序数组
void merge(std::vector<int>& vi, int start, int mid, int end)
{
	//注意vi[start:mid] 和 vi[mid+1], end]已经是有序的了
	//将其拷贝出来到额外的空间
	std::vector<int> leftSubArray(vi.begin() + start, vi.begin() + mid + 1);
	std::vector<int> rightSubArray(vi.begin() + mid + 1, vi.begin() + end + 1);

	//双指针发对vi.[start, end]区域进行排序
	int leftIndex = 0;
	int rightIndex = 0;

	leftSubArray.insert(leftSubArray.end(), INT_MAX);
	rightSubArray.insert(rightSubArray.end(), INT_MAX);

	for (int i = start; i <= end; ++i)
	{
		if (leftSubArray[leftIndex] < rightSubArray[rightIndex])
		{
			vi[i] = leftSubArray[leftIndex];
			leftIndex++;
		}
		else
		{
			vi[i] = rightSubArray[rightIndex];
			rightIndex++;
		}
	}

}

//归并排序
void sortMethod::MergeSort(vector<int>& vi, int start, int end)
{
	//仅剩下一个数据时，递归结束
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	MergeSort(vi, start, mid);
	MergeSort(vi, mid + 1, end);
	merge(vi, start, mid, end);
}

void sortMethod::QuickSort(vector<int>& nums, int l, int r)
{
	if (l >= r) {
		return;
	}
	int i = l, j = r;
	int base = nums[l];  //基准值

	//从右向左搜索第一个比base小的值
	while (i < j) {
		while (nums[j] >= base && i < j) {
			--j;
		}
		//从左向右搜索第一个比base大的值
		while (nums[i] <= base && i < j) {
			++i;
		}
		swap(nums[i], nums[j]); //交换base与中间位置的数
	}

	swap(nums[l], nums[j]);    // 交换base与中间位置的数

	QuickSort(nums, l, i - 1);
	QuickSort(nums, i + 1, r);

}

void sortMethod::SelectSort(vector<int>& nums, int start)
{
	for (int i = 0; i < nums.size(); i++)
	{
		int minValueIndex = i;
		for (int j = i; j < nums.size(); ++j)
		{
			if (nums[j] < nums[minValueIndex])
				minValueIndex = j;
		}
		swap(nums[minValueIndex], nums[i]);
	}
	
}

void sortMethod::ShellSort(vector<int>& nums)
{
	int len = nums.size();
	if (len <= 1)
		return;

	// 声明一个参数gap, 一般初始值设置为len/2, 然后缩小方式为gap/2, 直到gap等于1转化为插入排序
	int gap = len / 2;
	while (gap >= 1) {
		//将数据分成gap组，然后每组内进行插入排序
		for (int i = gap; i < len; ++i)
		{
			int insertValue = nums[i];
			int j = i - gap;
			while (j >= 0 && nums[j] > insertValue)
			{
				nums[j + gap] = nums[j];
				j -= gap;
			}
			nums[j + gap] = insertValue;
		}
		gap /= 2;
	}

}

// 递归方式调整完全二叉树的根节点, 使其符合大根堆特性
// start和end描述了堆点在数组vi中的下标
void maxHeapify(std::vector<int>& vi, int start, int end)
{
	//求出左右子结点下标
	int left = 2 * start + 1;
	int right = left + 1;

	//求出{vi[start], vi[left], vi[right]}三者中最大值下标
	int maxIndex = start;
	if (left <= end && vi[left] > vi[maxIndex])
		maxIndex = left;
	if (right <= end && vi[right] > vi[maxIndex])
		maxIndex = right;

	//如果根节点不是最大堆，交换富子结点后则继续递归调整下一层
	if (maxIndex != start)
	{
		std::swap(vi[maxIndex], vi[start]);
		maxHeapify(vi, maxIndex, end);
	}

}
//堆排序
void sortMethod::HeapSort(vector<int>& vi)
{
	// 初始化建堆: 从最后一个叶子结点开始, 从右到左从下到上调整二叉树成大根堆
	for (int i = vi.size() / 2 - 1; i >= 0; --i)
	{
		maxHeapify(vi, i, vi.size() - 1);
	}

	//堆排序：减缓首位元素后调整根节点使其符合大根堆特性
	for (int i = vi.size() - 1; i >= 1; --i)
	{
		std::swap(vi[0], vi[i]);
		maxHeapify(vi, 0, i - 1);
	}
}

void sortMethod::CountSort(std::vector<int>& vi)
{
	if (vi.size() <= 1)
		return;

	//找到最大值和最小值
	int max = vi[0];
	int min = vi[0];

	for (int i : vi)
	{
		max = std::max(i, max);
		min = std::min(i, min);
	}
	if (max == min)
		return;

	//构造一个数组存储每个数字机器对应次数，下标0 的value表示民的出现次数
	const int sz = max - min + 1;  //数组长度
	vector<int> cnt(sz, 0);        //初始化vector全为0
	for (auto i : vi)
		cnt[i - min] += 1;

	//修改传入的数组
	int index = 0;
	for (int i = 0; i < cnt.size(); ++i)
	{
		int cnti = cnt[i];
		while (cnti)
		{
			vi[index] = i + min;
			index++;
			cnti--;
		}
	}
}
	

void printVector(const std::vector<int>& vi) {
	for (auto i : vi)
		std::cout << " " << i;
	std::cout << std::endl;
}

void sortMethod::SortTest()
{
	//打乱vector里的元素
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(test_arr), std::end(test_arr), rng);

	vector<int> t = this->test_arr;
	int size = t.size();
	cout << "Qrigin Array Before Sort: ";
	printVector(t);
	
	cout << "Insert Sort Test:";
	insertSort(t);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Bubble Sort Test: ";
	BubbleSort(t);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Merge Sort Test:";
	MergeSort(t, 0, size - 1);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Quick Sort Test:";
	QuickSort(t, 0, size - 1);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Select Sort Test:";
	SelectSort(t, 0);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Shell Sort Test:";
	ShellSort(t);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Heap Sort Test:";
	HeapSort(t);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Count Sort Test:";
	CountSort(t);
	printVector(t);
	cout << endl;

}



int main()
{
	sortMethod s;
	s.SortTest();
	return 0;
}






