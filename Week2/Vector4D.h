#pragma once
// use template
template<class TT>
class Vector4D
{
public:
	TT x_, y_, z_, w_;

	Vector4D()
		:x_(0.0f), y_(0.0f), z_(0.0f), w_(0.0f)
	{}

	Vector4D(const TT& _x, const TT& _y, const TT& _z, const TT& _w)
		:x_(_x), y_(_y), z_(_z), w_(_w)
	{}


	// operator << 는 standard libray의 private 함수로 접근이 불가능하기 때문에 friend 키워드를 입력해서 접근이 가능하게 만들어야 한다.
	friend std::ostream& operator << (std::ostream& stream, const Vector4D<TT>& vec)
	{
		stream << vec.x_ << " " << vec.y_ << " " << vec.z_ << " " << vec.w_;
		return stream;
	}

	TT DotProduct(const Vector4D<TT>& vec)
	{
		return x_ * vec.x_ + y_ * vec.y_ + z_ * vec.z_ + w_ * vec.w_;
	}

};
