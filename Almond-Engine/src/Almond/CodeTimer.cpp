#include "aepch.h"

namespace Almond
{
	struct Timer
	{
		std::chrono::time_point < std::chrono::steady_clock > start, end;
		std::chrono::duration< double > duration;

		Timer()
		{
			start = std::chrono::high_resolution_clock::now();
		}

		~Timer()
		{
			end = std::chrono::high_resolution_clock::now();
			duration = end - start;
			std::cout << duration.count() << " s struct###" << std::endl;
		}
	};

	void printFor()
	{
		Timer timer;
		for (int i = 0; i < 100; i++)
		{
			std::cout << "hello world" << std::endl;
		}
	}

	void testLoop(int n)
	{
		omp_set_num_threads(4);
		double *arr = new double[1000000];
		std::fill_n(arr, 1000000, 123);
		Timer timer;

		//#pragma omp parallel for
		for (int i = 0; i < 1000000; i++)
		{
			arr[i] = arr[i] / arr[i] + arr[i] / 5 - 14;
		}
	}

	void countTimeee()
	{
		int n = 5;
		//auto start = std::chrono::high_resolution_clock::now();

		//printFor();
		testLoop(n);

		//auto end = std::chrono::high_resolution_clock::now();
		//std::chrono::duration<double> duration = end - start;
		//std::cout << duration.count() << " s " << std::endl;

	}
}