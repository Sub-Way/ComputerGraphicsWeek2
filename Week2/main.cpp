#include <iostream>
#include "Vector4D.h"
#include "Matrix4x4.h"
using namespace std;

int main()
{
	cout << "���� 1. Vector4D�� �����϶�." << endl;
	Vector4D<float> my_vec1(1, 0, 0, 1);
	Vector4D<float> my_vec2(0, 1, 0, 2);

	cout << my_vec1.DotProduct(my_vec2) << endl << endl;

	cout << "���� 2. Matrix4x4�� �����϶�." << endl;
	Matrix4x4<float> mat1;
	Matrix4x4<float> mat2;

	int count = 0;
	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++) {
			mat1.values_[row][col] = (float)count++;
		}

	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++) {
			mat2.values_[row][col] = (float)count++;
		}

	cout << "A.Matrix4x4�� Matrix4x4�� ��(multiplication) �Լ��� �����϶�." << endl;
	cout << mat1.multiply_mat(mat2) << endl << endl;

	cout << "B.Matrix4x4�� Vector4D�� ��(multiplication) �Լ��� �����϶�." << endl;
	cout << mat1.multiply_vec(my_vec1) << endl;

	cout << "���� 3." << endl;
	Matrix4x4<float> m_30;
	Matrix4x4<float> m_45;
	Matrix4x4<float> m_60;
	Matrix4x4<float> m_90;
	Vector4D<float> v(1, 0, 0, 0);
	
	cout << "1. theta = 30" << endl;
	m_30.theta(30.0);
	cout << m_30.multiply_vec(v) << endl << endl;

	cout << "2. theta = 45" << endl;
	m_45.theta(45.0);
	cout << m_45.multiply_vec(v) << endl << endl;

	cout << "3. theta = 60" << endl;
	m_60.theta(60.0);
	cout << m_60.multiply_vec(v) << endl << endl;

	cout << "4. theta = 90" << endl;
	m_90.theta(90.0);
	cout << m_90.multiply_vec(v) << endl << endl;
	
	cout << "���� 4. �ϳ� �̻��� ��(Multiplication)�� m(30��)*m(60��)*v �� ���϶�. " << endl;
	/*m_30.print();
	cout << endl << endl;

	m_60.print();
	cout << endl << endl;*/
	
	cout << m_30.multiply_theta(m_60,my_vec1) << endl;

	return 0;
}