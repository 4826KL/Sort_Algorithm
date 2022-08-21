# 排序算法

本周根据教材第七章系统性地学习了排序算法，基于c++11实现了插入排序、冒泡排序、归并排序、快速排序、选择排序、希尔排序、堆排序和计数排序并进行封装用以测试。同时结合leetcode经行深入学习和巩固。

---

## 插入排序InsertSort

插入排序步骤如下：

1. 初始时将第一个元素当做有序序列，第二个元素到最后一个元素当做是未排序序列
2. 从头到尾遍历未排序序列，将每个元素插入到有序序列的适当位置（如果遇到相等的元素则插入到相等元素后面，保证算法稳定性）

插入排序（Insertion-Sort）的算法描述是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。

## 冒泡排序BubbleSort

1. 从数组左侧开始两两比较相邻的数字，如果右侧的数字小于左侧的数字则交换两个数字的位置，如此一轮后**最右侧肯定是最大的数字**。
2. 第二轮我们重新从数组右侧开始两两比较元素，此轮结束后倒数第二个数字肯定是第二大的数字。
3. 如此循环一直到n-1轮时我们仅需要比较最左侧的两个数字就可以得到排序后的数组。

冒泡排序（Bubble Sort），顾名思义，就是指越小的元素会经由交换慢慢“浮”到数列的顶端。

## 归并排序

思想：“大事化小，小事化了”，即分治思想

平均时间复杂度：O(nlogn)

归并排序算法递归将序列划分为长度相同的两个子序列，当无法继续划分时（子序列中只有一个数据时）就开始对子序列进行有序合并，后续的问题就转化成合并两个有序序列的问题。

归并排序是使用分治法的典型应用，有两种实现方式：

1. 自上而下的递归（递归都可以写成迭代）
2. 自上而下的迭代

## 快速排序

快速排序算法使用分治法将一个序列划分为两个子序列，它会在序列中随机选择一个基准值，然后按照元素的大小将除了基准值之外的数分为“小于基准值的数”和“大于基准值的数”，对于两个子序列的排序依然应用快速排序，直到序列有序。

## 选择排序

1. 第一轮：在未排序数组中找到最小值，和数组最左侧元素交换
2. 第二轮：从剩余未排序元素中找到最小值，然后和数组第二个元素交换
3. 重复第二轮操作直到第n-1轮结束

选择排序（Selection Sort）是一种简单直观的排序算法。
它的基本思想就是，每一趟n-i+1(i=1,2,…,n-1)个记录中
选取值最小的索引作为有序序列的第 i 个索引。

## 希尔排序

希尔排序也被称为递减增量排序算法，它将整个序列划分为若干个子序列进行插入排序，当整个序列基本有序时插入排序的效率可以趋近于 O(n) 

## 堆排序

基于数据结构中的堆实现

1. 将无序数组组织成一个大根堆
2. 取出堆首元素（数组最大值）放在数组末尾，然后重建前面n-1个元素的大根堆
3. 重复第二步，直到大根堆中所有元素都被取出

## 计数排序

1. 找到数组中最大值和最小值
2. 统计数组中每个值出现的次数，存入数组中
3. 填充目标数组

---

## LeetCode

### [剑指offer 45.把数组成最小的数]([剑指 Offer 45. 把数组排成最小的数 - 力扣（LeetCode）](https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/))

```c++
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> s;
        string result;
        for (auto num : nums)      //for (int i = 0; i < nums.size(); i++)
        {
            s.push_back(to_string(num));
        }
        sort(s.begin(), s.end(), compare);
        for (auto str : s){
            result += str;
        }
        return result;

    }
private:
    static bool compare(const string &a, const string &b)
    {
        return a + b < b + a;      //排序判断规则 若 a+b > b+a,则a“大于”b，反之，小于
    }
};
```

### [147.对链表进行插入排序](https://leetcode.cn/problems/insertion-sort-list/ )

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) 
            return head;

        ListNode* dummyHead = new ListNode(0); // 定一个虚拟头结点
        ListNode* cur = head;
        ListNode* pre = dummyHead;

        while (cur != nullptr) {
            while (pre->next != nullptr && pre->next->val < cur->val) {
                pre = pre->next;
            }
            // 在pre和prenext之间插入数据
            ListNode* next = cur->next; // 步骤一：保存curnext
            cur->next = pre->next;      // 步骤二
            pre->next = cur;            // 步骤三
            pre = dummyHead;            // 步骤四：pre重新指向虚拟头结点来找下一个插入位置
            cur = next;                 // 步骤五：cur的前一个节点的下一个节点指向保存的next
        }
        return dummyHead->next;
    }

}
```

