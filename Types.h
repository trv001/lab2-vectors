class Int;
class Double;

class Complex {

	public:

		double re;
		double im;

        double Re() const{
            return re;
        }

        double Im() const{
            return im;
        }

        void SetRe(double re){
            this->re = re;
        }

        void SetIm(double im){
            this->im = im;
        }

		Complex(double re = 0, double im = 0) {
			this->re = re;
			this->im = im;
		}

		Complex(const Complex& src) {
			re = src.re;
			im = src.im;
		}

		Complex operator-() {
			Complex res(*this);
			res.re = -re;
			res.im = -im;
			return res;
		}

		Complex operator-(Complex a){
		    Complex res(*this);
		    res.re -= a.re;
		    res.im -= a.im;
		    return res;
		}

		Complex operator-(Int a);
		Complex operator-(Double a);

        Complex operator+(Complex a) {
			Complex res(*this);
			res.re += a.re;
			res.im += a.im;
			return res;
		}

		Complex operator+(Int a);
		Complex operator+(Double a);

		Complex operator*(Complex a) {
			Complex res;
			res.re = re * a.re - im * a.im;
			res.im = im * a.re + re * a.im;
			return res;
		}

		Complex operator*(Int a);
        Complex operator*(Double a);

		Complex operator/(Complex a) {
			Complex res;
			res.re = (re * a.re + im * a.im) / (a.re * a.re + a.im * a.im);
			res.im = (im * a.re - re * a.im) / (a.re * a.re + a.im *a.im);
			return res;
		}

		Complex operator/(Int a);
		Complex operator/(Double a);
};

#define A res.re
#define C a.re
#define B res.im
#define D a.im

class Double{

    public:

        double val;

        Double(double val = 0){
            this->val = val;
        }

        Double(const Double& src) {
			val = src.val;
		}

		Double operator-() {
			Double res(*this);
			res.val = -val;
			return res;
		}

		Double operator-(Double a){
		    Double res(*this);
		    res.val -= a.val;
		    return res;
		}

		Double operator-(Int a);

		Complex operator-(Complex a){
		    Complex res(val, 0);
		    A -= C;
		    B -= D;
		    return res;
		}

        Double operator+(Double a) {
			Double res(*this);
			res.val += a.val;
			return res;
		}

		Double operator+(Int a);

		Complex operator+(Complex a){
            Complex res(val, 0);
            A += C;
            B += D;
            return res;
		}

		Double operator*(Double a) {
			Double res(*this);
			res.val *= a.val;
			return res;
		}

		Double operator*(Int a);

		Complex operator*(Complex a){
		    Complex res(val, 0);
		    A *= C;
		    B = A * D;
		    return res;
		}

		Double operator/(Double a) {
			Double res(*this);
			res.val /= a.val;
			return res;
		}

		Double operator/(Int a);

		Complex operator/(Complex a){
		    Complex res(val, 0);
		    A = (A * C) / (C * C + D * D);
			B = -(A * D) / (C * C + D * D);
		    return res;
		}
};

class Int{

    public:

        int val;

        Int(int val = 0){
            this->val = val;
        }

        Int(const Int& src) {
			val = src.val;
		}

		Int operator-() {
			Int res(*this);
			res.val = -val;
			return res;
		}

		Int operator-(Int a){
		    Int res(*this);
		    res.val -= a.val;
		    return res;
		}

		Double operator-(Double a){
		    Double res(val);
		    res.val -= a.val;
		    return res;
		}

		Complex operator-(Complex a){
		    Complex res(val, 0);
		    A -= C;
		    B -= D;
		    return res;
		}

        Int operator+(Int a) {
			Int res(*this);
			res.val += a.val;
			return res;
		}

		Double operator+(Double a){
            Double res(val);
            res.val += a.val;
            return res;
		}

		Complex operator+(Complex a){
            Complex res(val, 0);
            A += C;
            B += D;
            return res;
		}

		Int operator*(Int a) {
			Int res(*this);
			res.val *= a.val;
			return res;
		}

		Double operator*(Double a){
		    Double res(val);
		    res.val *= a.val;
		    return res;
		}

		Complex operator*(Complex a){
		    Complex res(val, 0);
		    A *= C;
		    B = A * D;
		    return res;
		}

		Double operator/(Int a) {
			Double res(val);
			res.val /= a.val;
			return res;
		}

		Double operator/(Double a){
		    Double res(val);
		    res.val /= a.val;
		    return res;
		}

		Complex operator/(Complex a){
		    Complex res(val, 0);
		    A = (A * C) / (C * C + D * D);
			B = -(A * D) / (C * C + D * D);
		    return res;
		}
};


Complex Complex::operator-(Int a){
    Complex res(*this);
    res.re -= a.val;
    return res;
}

Complex Complex::operator-(Double a){
    Complex res(*this);
    res.re -= a.val;
    return res;
}

Complex Complex::operator+(Int a){
    Complex res(*this);
    res.re += a.val;
    return res;
}

Complex Complex::operator+(Double a){
    Complex res(*this);
    res.re += a.val;
    return res;
}

Complex Complex::operator*(Int a){
    Complex res;
    res.re = re * a.val;
    res.im = im * a.val;
    return res;
}

Complex Complex::operator*(Double a){
    Complex res;
    res.re = re * a.val;
    res.im = im * a.val;
    return res;
}

Complex Complex::operator/(Int a){
    Complex res;
    res.re = re / a.val;
    res.im = im / a.val;
    return res;
}

Complex Complex::operator/(Double a){
    Complex res;
    res.re = re / a.val;
    res.im = im / a.val;
    return res;
}

Double Double::operator-(Int a){
    Double res(*this);
    res.val -= a.val;
    return res;
}

Double Double::operator+(Int a){
    Double res(*this);
    res.val += a.val;
    return res;
}

Double Double::operator*(Int a){
    Double res(*this);
    res.val *= a.val;
    return res;
}

Double Double::operator/(Int a){
    Double res(*this);
    res.val /= a.val;
    return res;
}
