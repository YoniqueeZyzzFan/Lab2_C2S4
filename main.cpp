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
	for (int i = 0; i < v.size()-1; ++i) {
		for (int j = 0; j < v.size() - 1 - i; ++j) {
			if (v[j] > v[j + 1]) {
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
		}
	}
}

void insertion_sort(std::vector<int>& v) {
    int copy_count = 0;
    int compare_count = 0;
	int j;
	int tmp;
	for (int i = 1; i < v.size(); ++i) {
        copy_count++;
		tmp = v[i];
		for (j = i; j > 0 && (v[j-1] > tmp); --j) {
            compare_count += 2;
            v[j] = v[j-1];
            copy_count++;
		}
		v[j] = tmp;
        copy_count++;
	}
    std::cout << "Insertion_sort: Copy_count: " << copy_count << std::endl;
    std::cout << "              : Compare_count: " << compare_count << std::endl;
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

void swap(int& x1, int& x2) {
	int tmp = x1;
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
        compare_count++;
        compare_count++;
        if (less(vec[i], vec[pivot])) {
            copy_count++;
            std::swap(vec[i], vec[wall]);
            wall++;
        }
        i++;
    }
    copy_count++;
    std::swap(vec[wall], vec[pivot]);
    quick_sort(vec, start, wall);
    quick_sort(vec, wall + 1, end);
    return;
}

void quick_sort(std::vector<int>& v) {
	quick_sort(v, 0, v.size());
    std::cout << "Copy_count: " << copy_count << std::endl;
    std::cout << "Compare count: " << compare_count << std::endl;
}

void twm_sort(std::vector<int>& data)
{
    std::vector<int> res(data.size());
    size_t resl = 0;
    size_t resr = res.size() - 1;
    size_t podsize = 2;
    while (true)
    {
        size_t resl = 0; // Ћева€ граница неотсортированной последовательности в res
        size_t resr = res.size() - 1; // ѕрава€ граница неотсортированной последовательности в res
        bool left = true;
        size_t vecl = 0; // »ндекс левой границы неотсортированной последовательности в data
        size_t vecr = data.size() - 1; // »ндекс правой границы неотсортированной последовательности в data
        while (vecl < vecr)
        {
            size_t i = vecl;
            size_t j = vecr;
            while (vecl <= vecr && data[vecl] <= data[vecl + 1])
            {
                vecl++;
                podsize++;
                if (vecl == res.size() - 1) return;
            }
            while (vecl <= vecr && data[vecr] <= data[vecr - 1])
            {
                vecr--;
                podsize++;
            }
            if (left)
            {
                for (size_t p = 0; p < podsize; ++p)
                {
                    if (i <= vecl)
                    {
                        if (j < vecr) // ≈сли вс€ права€ подпоследовательность уже перебрана, то поочередно записываем левую последовательность
                        {
                            res[resl] = data[i];
                            resl++;
                            i++;
                            continue;
                        }
                        else if (data[i] < data[j]) //≈сли права€ подпоследовательность не целиком рассмотрена, то нужно сравнивать
                        {
                            res[resl] = data[i];
                            resl++;
                            i++;
                            continue;
                        }
                        else if (i == j)
                        {
                            res[resl] = data[i];
                            break;
                        }
                    }
                    if (j >= vecr)
                    {
                        if (i > vecl) // ¬с€ лева€ подпоследовательность рассмотрена
                        {
                            res[resl] = data[j];
                            resl++;
                            j--;
                            continue;
                        }
                        else if (data[j] < data[i]) //≈сли лева€ подпоследовательность не целиком рассмотрена, то нужно сравнивать
                        {
                            res[resl] = data[j];
                            resl++;
                            j--;
                            continue;
                        }
                        else if (i == j)
                        {
                            res[resl] = data[i];
                            break;
                        }
                    }
                }
                left = !left;
            }
            else {
                for (size_t p = 0; p < podsize; ++p)
                {
                    if (i <= vecl)
                    {
                        if (j < vecr) // ≈сли вс€ права€ подпоследовательность уже перебрана, то поочередно записываем левую последовательность
                        {
                            res[resr] = data[i];
                            resr--;
                            i++;
                            continue;
                        }
                        else if (data[i] < data[j]) //≈сли права€ подпоследовательность не целиком рассмотрена, то нужно сравнивать
                        {
                            res[resr] = data[i];
                            resr--;
                            i++;
                            continue;
                        }
                        else if (i == j)
                        {
                            res[resl] = data[i];
                            break;
                        }
                    }
                    if (j >= vecr && data[j] < data[i])
                    {
                        if (i > vecl) // ¬с€ лева€ подпоследовательность рассмотрена
                        {
                            res[resr] = data[j];
                            resr--;
                            j--;
                            continue;
                        }
                        else if (data[j] < data[i]) //≈сли лева€ подпоследовательность не целиком рассмотрена, то нужно сравнивать
                        {
                            res[resr] = data[j];
                            resr--;
                            j--;
                            continue;
                        }
                        else if (i == j)
                        {
                            res[resl] = data[i];
                            break;
                        }
                    }
                }
                left = !left;
            }
            vecl++;
            vecr--;
        }
        data = res;
        for (size_t k = 0; k < res.size(); k++) res[k] = 0;
    }
    return;
}

int main() {
    std::vector<int> array;
	srand(time(NULL));
    //for (int i = 0; i < 10 ; ++i) {
    //    array.push_back(rand()%1000);
    //}
    array.push_back(2);
    array.push_back(3);
    array.push_back(1);
    array.push_back(4);
    array.push_back(7);
    array.push_back(5);

    print(array);
    twm_sort(array);
    print(array);
	//bubble_sort(array);
	//insertion_sort(array);
	//selection_sort(array);
    // merge_sort(array);
	//quick_sort(array);
	//print(array);
}