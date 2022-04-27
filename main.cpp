#include <iostream>
#include <vector>
#include <time.h>

void print(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << "  ";
    }
    std::cout << std::endl;
}

void bubble_sort(std::vector<int>& v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        for (int j = 0; j < v.size() - 1 - i; ++j) {
            if (v[j] > v[j + 1]) {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
}

template <typename T>
void insertion_sort(std::vector<T>& v) {
    //int copy_count = 0;
    //int compare_count = 0;
    int j;
    T tmp;
    for (int i = 1; i < v.size(); ++i) {
        //copy_count++;
        tmp = v[i];
        for (j = i; j > 0 && (v[j - 1] > tmp); --j) {
            //compare_count += 2;
            v[j] = v[j - 1];
            //copy_count++;
        }
        v[j] = tmp;
        //copy_count++;
    }
    // std::cout << "Insertion_sort: Copy_count: " << copy_count << std::endl;
    //  std::cout << "              : Compare_count: " << compare_count << std::endl;
}

void selection_sort(std::vector<int>& v) {
    int min_ind;
    for (int i = 0; i < v.size() - 1; ++i) {
        min_ind = i;
        for (int j = i; j < v.size(); ++j) {
            if (v[min_ind] > v[j]) min_ind = j;
        }
        std::swap(v[min_ind], v[i]);
    }
}
template <typename T>
void swap(T& x1, T& x2) {
    T tmp = x1;
    x1 = x2;
    x2 = tmp;
}

int copy_count = 0;
int compare_count = 0;

template <typename T, typename TCompare = std::less<T>>
void quick_sort(std::vector<T>& vec, size_t start, size_t end) {
    if (end - start < 2) return;
    TCompare less;
    size_t pivot = end - 1;
    size_t wall = start;
    size_t i = start;
    while (i <= pivot) {
        //compare_count++;
       // compare_count++;
        if (less(vec[i], vec[pivot])) {
            //copy_count++;
            std::swap(vec[i], vec[wall]);
            wall++;
        }
        i++;
    }
    //copy_count++;
    swap(vec[wall], vec[pivot]);
    quick_sort(vec, start, wall);
    quick_sort(vec, wall + 1, end);
    return;
}

void quick_sort(std::vector<int>& v) {
    quick_sort(v, 0, v.size());
    // std::cout << "Copy_count: " << copy_count << std::endl;
     //std::cout << "Compare count: " << compare_count << std::endl;
}
 
template <typename T, typename TCompare = std::less<T>>
void twm_sort(std::vector<T>& vec) {
	TCompare less;
	std::vector<T> res(vec.size());
	while (true) {
		size_t resl = 0; // ����� ������� ����������������� ������������������ � res
		size_t resr = res.size() - 1; // ������ ������� ����������������� ������������������ � res
		bool left = true;
		size_t vecl = 0; // ������ ����� ������� ����������������� ������������������ � vec
		size_t vecr = vec.size() - 1; // ������ ������ ������� ����������������� ������������������ � vec
		while (vecl <= vecr) {
			size_t i = vecl;
			size_t j = vecr;
			size_t podsize = 2;
			compare_count++;
			while (vecl <= vecr && !less(vec[vecl + 1], vec[vecl])) {
				compare_count++;
				vecl++;
				podsize++;
				if (vecl == vec.size() - 1) return ;
			}
			compare_count++;
			while (vecl <= vecr && !less(vec[vecr - 1], vec[vecr])) {
				compare_count++;
				vecr--; // ��������� vecr ���� ��������� ��������������� ��������������������� ������ ������ �� ������ �������
				podsize++;
			}
			for (size_t p = 0; p < podsize; ++p) {
				if (i <= vecl) {
					if (j < vecr) { // ���� ��� ������ ��������������������� ��� ���������, �� ���������� ���������� ����� ������������������
						if (left) {
							std::cout << "126:" << std::endl;
							print(res);
							res[resl] = vec[i];
							print(res);
							copy_count++;
							resl++;
						}
						else {
							std::cout << "134:" << std::endl;
							print(res);
							res[resr] = vec[i];
							copy_count++;
							resr--;
						}
						i++; //�� �� ������ ������ ���������
						continue;
					}
					else if (less(vec[i], vec[j])) { //���� ������ ��������������������� �� ������� �����������, �� ����� ����������
						compare_count++;
						if (left) {
							std::cout << "148:" << std::endl;
							print(res);
							res[resl] = vec[i];
							print(res);
							copy_count++;
							resl++;
						}
						else {
							std::cout << "154:" << std::endl;
							print(res);
							res[resr] = vec[i];
							print(res);
							copy_count++;
							resr--;
						}
						i++; //�� �� ������ ������ ���������
						continue;
					}
					else if (i == j) {
						std::cout << "165:" << std::endl;
						print(res);
						res[resl] = vec[i];
						print(res);
						copy_count++;
						break;
					}
				}
				if (j >= vecr) {
					if (i > vecl) { // ��� ����� ��������������������� �����������
						if (left) {
							std::cout << "176:" << std::endl;
							print(res);
							res[resl] = vec[j];
							print(res);
							copy_count++;
							resl++;
						}
						else {
							std::cout << "184:" << std::endl;
							print(res);
							res[resr] = vec[j];
							print(res);
							copy_count++;
							resr--;
						}
						j--; //�� �� ������ ������ ���������
						continue;
					}
					else if (less(vec[j], vec[i])) { //���� ����� ��������������������� �� ������� �����������, �� ����� ����������
						compare_count++;
						if (left) {
							std::cout << "197:" << std::endl;
							print(res);
							res[resl] = vec[j];
							print(res);
							copy_count++;
							resl++;
						}
						else {
							std::cout << "205:" << std::endl;
							print(res);
							res[resr] = vec[j];
							print(res);
							copy_count++;
							resr--;
						}
						j--; //�� �� ������ ������ ���������
						continue;
					}
				}
			}
			left = !left;
			vecl++;
			vecr--;
		}
		vec = res;
		copy_count += res.size();
	}
}  

bool check(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i + 1] < vec[i]) return false;
    }
    return true;
}

int main() {
    std::vector<int> array;
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
         /*int temp = 0;
         std::cin >> temp;
         array.push_back(temp);*/
        array.push_back(rand() % 1000 - 500);
    }
    std::vector<int> tmp(array);
    /* array.push_back(75);
     array.push_back(-487);
     array.push_back(-355);
     array.push_back(463);
     array.push_back(81);
     array.push_back(-497);
	 array.push_back(-303);
	 array.push_back(-277);
	 array.push_back(111);
	 array.push_back(64);*/

    print(array);
    // quick_sort(array);
    twm_sort(array);
    std::cout << "___________________________________-" << std::endl;
    print(tmp);
    print(array);
    if (check(array)) std::cout << "ok_hand" << std::endl;
    else std::cout << "bad_hand" << std::endl;
    //bubble_sort(array);
    //insertion_sort(array);
    //selection_sort(array);
    // merge_sort(array);
    //quick_sort(array);
    //print(array);
}