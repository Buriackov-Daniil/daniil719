#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
// ������� "�����������" ����� ���� - ������������ ����
void siftDown(vector<int>& numbers, int root, int bottom)
{
  int maxChild; // ������ ������������� �������
  int done = 0; // ���� ����, ��� ���� ������������
  // ���� �� ����� �� ���������� ����
  while ((root * 2 <= bottom) && (!done)) 
  {
    if (root * 2 == bottom)    // ���� �� � ��������� ����,
      maxChild = root * 2;    // ���������� ����� �������
    // ����� ���������� ������� ������� �� ����
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // ���� ������� ������� ������ ������������� �������
    if (numbers[root] < numbers[maxChild]) 
    {
      int temp = numbers[root]; // ������ �� �������
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else // �����
      done = 1; // �������� ������������
  }
}
// ������� ���������� �� ����
void heapSort(vector<int>& numbers, int array_size) 
{
  // ��������� ������ ��� ��������
  for (int i = (array_size / 2); i >= 0; i--)
    siftDown(numbers, i, array_size - 1);
  // ���������� ����� �������� ��������� ��������
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i - 1);
  }
}
int main()
{int p;
cout<<"\n vvedite kolichestvo elementov matrici   ";
cin>>p;
std::vector<int> a(p);
for(int i = 0; i<p; i++){
	cout<<"\n vvedite element matrici nomer"<<i<<"     ";
	cin>>a[i];
}
  for (int i = 0; i<p; i++)
    printf("%d ", a[i]);
  printf("\n");

  heapSort(a, p); // ����� ������� ����������
  // ����� ��������� ������� ����� ����������
  for (int i = 0; i<p; i++)
    printf("%d ", a[i]);
  printf("\n");
  getchar();

  return 0;
  
}

