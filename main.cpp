#include <iostream>
#include <vector>
#include <time.h>
#include <unordered_map>

template <typename T>
void print(const std::vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << "  ";
    }
    std::cout << std::endl;
}

void bubble_sort(std::vector<int>& v) {
    for (size_t i = 0; i < v.size() - 1; ++i) {
        for (size_t j = 0; j < v.size() - 1 - i; ++j) {
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
    for (size_t i = 0; i < v.size() - 1; ++i) {
        min_ind = i;
        for (size_t j = i; j < v.size(); ++j) {
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
		size_t resl = 0; // Ћева€ граница неотсортированной последовательности в res
		size_t resr = res.size() - 1; // ѕрава€ граница неотсортированной последовательности в res
		bool left = true;
		size_t vecl = 0; // »ндекс левой границы неотсортированной последовательности в vec
		size_t vecr = vec.size() - 1; // »ндекс правой границы неотсортированной последовательности в vec
		while (vecl <= vecr) {
			size_t i = vecl;
			size_t j = vecr;
			size_t podsize = 2;
			compare_count++;
			while (vecl <= vecr && !less(vec[vecl + 1], vec[vecl])) {
				if (vecl == vecr && vec[vecl + 1] == vec[vecl]) {
					vecl++;
					break;
				}
				compare_count++;
				vecl++;
				podsize++;
				if (vecl == vec.size() - 1) return ;
			}
			compare_count++;
			while (vecl <= vecr && !less(vec[vecr - 1], vec[vecr])) {
				if (vecl == vecr && vec[vecr - 1] == vec[vecr]) {
					vecr++;
					break;
				}
				compare_count++;
				vecr--; // ”меньшает vecr пока находитс€ увеличивающа€с€ подпоследовательность справа налево от правой границы
				podsize++;
			}
			for (size_t p = 0; p < podsize; ++p) {
				if (i <= vecl) {
					if (j < vecr) { // ≈сли вс€ права€ подпоследовательность уже перебрана, то поочередно записываем левую последовательность
						if (left) {
							//std::cout << "126:" << std::endl;
							//print(res);
							res[resl] = vec[i];
							//print(res);
							copy_count++;
							resl++;
						}
						else {
							//std::cout << "134:" << std::endl;
							//print(res);
							res[resr] = vec[i];
							copy_count++;
							resr--;
						}
						i++; //ћб не всегда делать инкремент
						continue;
					}
					else if (vec[i] == vec[j] && i!=j) {
						res[resl] = vec[i];
						copy_count++;
						resl++;
						i++;
						continue;
					}
					else if (less(vec[i], vec[j])) { //≈сли права€ подпоследовательность не целиком рассмотрена, то нужно сравнивать
						compare_count++;
						if (left) {
							//std::cout << "148:" << std::endl;
							//print(res);
							res[resl] = vec[i];
							//print(res);
							copy_count++;
							resl++;
						}
						else {
							//std::cout << "154:" << std::endl;
							//print(res);
							res[resr] = vec[i];
							//print(res);
							copy_count++;
							resr--;
						}
						i++; //ћб не всегда делать инкремент
						continue;
					}
					else if (i == j) {
						//std::cout << "165:" << std::endl;
						//print(res);
						res[resl] = vec[i];
						//print(res);
						copy_count++;
						break;
					}
				}
				if (j >= vecr) {
					if (i > vecl) { // ¬с€ лева€ подпоследовательность рассмотрена
						if (left) {
							//std::cout << "176:" << std::endl;
							//print(res);
							res[resl] = vec[j];
							//print(res);
							copy_count++;
							resl++;
						}
						else {
							//std::cout << "184:" << std::endl;
							//print(res);
							res[resr] = vec[j];
							//print(res);
							copy_count++;
							resr--;
						}
						j--; //ћб не всегда делать декремент
						continue;
					}
					else if (less(vec[j], vec[i])) { //≈сли лева€ подпоследовательность не целиком рассмотрена, то нужно сравнивать
						compare_count++;
						if (left) {
							//std::cout << "197:" << std::endl;
							//print(res);
							res[resl] = vec[j];
							//print(res);
							copy_count++;
							resl++;
						}
						else {
							//std::cout << "205:" << std::endl;
							//print(res);
							res[resr] = vec[j];
							//print(res);
							copy_count++;
							resr--;
						}
						j--; //ћб не всегда делать декремент
						continue;
					}
				}
			}
			left = !left;
			vecl++;
			vecr--;
		}
		vec = res;
		//std::cout << std::endl << "222 vec:" << std::endl;
		copy_count += res.size();
		//print(res);
		std::vector<T> res2(vec.size());
		res = res2;
	}
}  

template <typename T>
bool check(const std::vector<T>& vec, const std::unordered_map<int,int>& ch) {
	std::unordered_map<int, int> temp;
	for (size_t i = 0; i < vec.size(); ++i) {
		temp[vec[i]] += 1;
	}
	if (temp != ch) return false;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        if (vec[i + 1] < vec[i]) return false;
    }
    return true;
}

int main() {
    std::vector<int> array;
	std::unordered_map<int, int> ch;
    srand(time(NULL));
	for (int i = 0; i < 100; ++i) {
		for (int k = 0; k < 18000; ++k) {
			array.push_back(rand() % 10000);
			ch[array[k]] += 1;
		}
		twm_sort(array);
		if (!check(array, ch)) {
			std::cout << "bad_hand" << std::endl;
			print(array);
		}
		array.clear();
		ch.clear();
	}
     /*array.push_back(139);
     array.push_back(565);
     array.push_back(490);
     array.push_back(874);
     array.push_back(651);
     array.push_back(4);
	 array.push_back(390);
	 array.push_back(643);
	 array.push_back(269);
	 array.push_back(601);
	 array.push_back(565);
	 array.push_back(575);
	 array.push_back(660);
	 array.push_back(607);
	 array.push_back(663);
	 array.push_back(833);
	 array.push_back(451);
	 array.push_back(236);*/

  //  print(array);
 //   quick_sort(array);
    //twm_sort(array);
	//print(array);
 //   std::cout << "___________________________________-" << std::endl;
 //   print(tmp);
 //   print(array);
   // if (!check(array,ch)) std::cout << "bad_hand" << std::endl;
	//std::cout << "_____" << std::endl << "Copy_c = " << copy_count << std::endl << "Comp_c = " << compare_count;
    //bubble_sort(array);
    //insertion_sort(array);
    //selection_sort(array);
    // merge_sort(array);
    //quick_sort(array);
    //print(array);
}