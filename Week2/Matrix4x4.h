#include "Vector4D.h"
#pragma once
using namespace std;

template<class TT>
class Matrix4x4
{
public:
	TT values_[4][4], x_;

	void print() {
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				cout << values_[row][col] << " ";
			}
			cout << endl;
		}
	}

	friend ostream& operator << (ostream& stream, const Matrix4x4<TT>& mat)
	{
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				stream << mat.values_[row][col] << " ";
			}
			cout << endl;
		}
		return stream;
	}

	Matrix4x4<TT> multiply_mat(const Matrix4x4<TT>& mat) {
		Matrix4x4<TT> mat_ans;
		float store = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					store += values_[j][k] * mat.values_[k][i];
				}
				mat_ans.values_[j][i] = store;
				store = 0;
			}
		}
		return mat_ans;
	}

	Vector4D<TT> multiply_vec(const Vector4D<TT>& vec) {
		Vector4D<TT> vec_ans;
		vec_ans.x_ = values_[0][0] * vec.x_ + values_[0][1] * vec.y_ + values_[0][2] * vec.z_ + values_[0][3] * vec.w_;
		vec_ans.y_ = values_[1][0] * vec.x_ + values_[1][1] * vec.y_ + values_[1][2] * vec.z_ + values_[1][3] * vec.w_;
		vec_ans.z_ = values_[2][0] * vec.x_ + values_[2][1] * vec.y_ + values_[2][2] * vec.z_ + values_[2][3] * vec.w_;
		vec_ans.w_ = values_[3][0] * vec.x_ + values_[3][1] * vec.y_ + values_[3][2] * vec.z_ + values_[3][3] * vec.w_;

		return vec_ans;
	}

	void theta(const TT& _x) {
		const float PI = 3.141592;
		const float theta_radian = _x / 180.0 * PI;
		float cos_theta = cos(theta_radian);
		float sin_theta = sin(theta_radian);

		for (int row = 0; row < 4; row++)
			for (int col = 0; col < 4; col++) {
				if (row == 0 && col == 0 || row == 1 && col == 1) {
					values_[row][col] = cos_theta;
				}
				else if (row == 1 && col == 0) {
					values_[row][col] = sin_theta;
				}
				else if (row == 0 && col == 1) {
					values_[row][col] = -sin_theta;
				}
				else if (row == 2 && col == 2 || row == 3 && col == 3) {
					values_[row][col] = 1;
				}
				else
					values_[row][col] = 0;
			}
	}
	
	Vector4D<TT> multiply_theta(const Matrix4x4<TT>& mat_theta, const Vector4D<TT>& vec_theta) {
		Matrix4x4<TT> mat_plus;
		Vector4D<TT> vec_plus;
		
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				if (row == 0 && col == 0 || row == 1 && col == 1 || row == 1 && col == 0 || row == 0 && col == 1)
					mat_plus.values_[row][col] = values_[row][col] + mat_theta.values_[row][col];
				else if (row == 2 && col == 2 || row == 3 && col == 3) {
					mat_plus.values_[row][col] = 1;
				}
				else
					mat_plus.values_[row][col] = 0;
			}
		}

		vec_plus.x_ = mat_plus.values_[0][0] * vec_theta.x_ + mat_plus.values_[0][1] * vec_theta.y_ + mat_plus.values_[0][2] * vec_theta.z_ + mat_plus.values_[0][3] * vec_theta.w_;
		vec_plus.y_ = mat_plus.values_[1][0] * vec_theta.x_ + mat_plus.values_[1][1] * vec_theta.y_ + mat_plus.values_[1][2] * vec_theta.z_ + mat_plus.values_[1][3] * vec_theta.w_;
		vec_plus.z_ = mat_plus.values_[2][0] * vec_theta.x_ + mat_plus.values_[2][1] * vec_theta.y_ + mat_plus.values_[2][2] * vec_theta.z_ + mat_plus.values_[2][3] * vec_theta.w_;
		vec_plus.w_ = mat_plus.values_[3][0] * vec_theta.x_ + mat_plus.values_[3][1] * vec_theta.y_ + mat_plus.values_[3][2] * vec_theta.z_ + mat_plus.values_[3][3] * vec_theta.w_;

		return vec_plus;
	}
};