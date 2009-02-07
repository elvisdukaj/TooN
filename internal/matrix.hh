template <int Rows=-1, int Cols=Rows, class Precision=double, template<int R, int C, class P> class Layout = RowMajor>
class Matrix : public Layout<Rows, Cols, Precision>
{
  private:
	using Layout<Rows, Cols, Precision>::my_data;
  public:
	//Use Tom's sneaky constructor hack...
		
	Matrix(){}

	Matrix(Precision* data, Slicing)
	:Layout<Rows, Cols, Precision>(data){}
	
	//The stride is always passed during a slice. If it is not
	//needed, it will be ignored later and not stored.
	Matrix(Precision* data, int stride, Slicing)
	:Layout<Rows, Cols, Precision>(data, stride){}

	Precision* data() {
	  return my_data;
	}

	const Precision* data() const {
	  return my_data;
	}
};
